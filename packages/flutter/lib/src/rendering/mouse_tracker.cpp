#include "mouse_tracker.hpp"
LinkedHashMap<MouseTrackerAnnotation, Matrix4> _MouseStateCls::annotations() {
    return _annotations;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> _MouseStateCls::replaceAnnotations(LinkedHashMap<MouseTrackerAnnotation, Matrix4> value) {
    assert(value != nullptr);
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> previous = _annotations;
    _annotations = value;
    return previous;
}

PointerEvent _MouseStateCls::latestEvent() {
    return _latestEvent;
}

PointerEvent _MouseStateCls::replaceLatestEvent(PointerEvent value) {
    assert(value != nullptr);
    assert(value->device == _latestEvent->device);
    PointerEvent previous = _latestEvent;
    _latestEvent = value;
    return previous;
}

int _MouseStateCls::device() {
    return latestEvent()->device;
}

String _MouseStateCls::toString() {
    String describeLatestEvent = __s("latestEvent: ${describeIdentity(latestEvent)}");
    String describeAnnotations = __s("annotations: [list of ${annotations.length}]");
    return __s("${describeIdentity(this)}($describeLatestEvent, $describeAnnotations)");
}

_MouseStateCls::_MouseStateCls(PointerEvent initialEvent) {
    {
        assert(initialEvent != nullptr);
        _latestEvent = initialEvent;
    }
}

void _MouseTrackerUpdateDetailsCls::byNewFrame(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent)

void _MouseTrackerUpdateDetailsCls::byPointerEvent(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent, PointerEvent triggeringEvent)

int _MouseTrackerUpdateDetailsCls::device() {
    int result = (previousEvent or triggeringEvent)!->device;
    assert(result != nullptr);
    return result;
}

PointerEvent _MouseTrackerUpdateDetailsCls::latestEvent() {
    PointerEvent result = triggeringEvent or previousEvent!;
    assert(result != nullptr);
    return result;
}

void _MouseTrackerUpdateDetailsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("device"), device));
    properties->add(<PointerEvent>make<DiagnosticsPropertyCls>(__s("previousEvent"), previousEvent));
    properties->add(<PointerEvent>make<DiagnosticsPropertyCls>(__s("triggeringEvent"), triggeringEvent));
    properties->add(<Map<MouseTrackerAnnotation, Matrix4>>make<DiagnosticsPropertyCls>(__s("lastAnnotations"), lastAnnotations));
    properties->add(<Map<MouseTrackerAnnotation, Matrix4>>make<DiagnosticsPropertyCls>(__s("nextAnnotations"), nextAnnotations));
}

bool MouseTrackerCls::mouseIsConnected() {
    return _mouseStates->isNotEmpty();
}

void MouseTrackerCls::updateWithEvent(PointerEvent event, ValueGetter<HitTestResult> getResult) {
    if (event->kind != PointerDeviceKindCls::mouse) {
        return;
    }
    if (is<PointerSignalEvent>(event)) {
        return;
    }
    HitTestResult result = is<PointerRemovedEvent>(event)? make<HitTestResultCls>() : getResult();
    int device = event->device;
    _MouseState existingState = _mouseStates[device];
    if (!_shouldMarkStateDirty(existingState, event)) {
        return;
    }
    _monitorMouseConnection([=] () {
        _deviceUpdatePhase([=] () {
            if (existingState == nullptr) {
                if (is<PointerRemovedEvent>(event)) {
                    return;
                }
                _mouseStates[device] = make<_MouseStateCls>(event);
            } else {
                assert(!is<PointerAddedEvent>(event));
                if (is<PointerRemovedEvent>(event)) {
                    _mouseStates->remove(as<PointerRemovedEventCls>(event)->device);
                }
            }
            _MouseState targetState = _mouseStates[device] or existingState!;
            PointerEvent lastEvent = targetState->replaceLatestEvent(event);
            LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations = is<PointerRemovedEvent>(event)? <MouseTrackerAnnotation, Matrix4>make<LinkedHashMapCls>() : _hitTestResultToAnnotations(result);
            LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations = targetState->replaceAnnotations(nextAnnotations);
            _handleDeviceUpdate(_MouseTrackerUpdateDetailsCls->byPointerEvent(lastAnnotations, nextAnnotations, lastEvent, event));
        });
    });
}

void MouseTrackerCls::updateAllDevices(MouseDetectorAnnotationFinder hitTest) {
    _deviceUpdatePhase([=] () {
        for (_MouseState dirtyState : _mouseStates->values) {
            PointerEvent lastEvent = dirtyState->latestEvent;
            LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations = _findAnnotations(dirtyState, hitTest);
            LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations = dirtyState->replaceAnnotations(nextAnnotations);
            _handleDeviceUpdate(_MouseTrackerUpdateDetailsCls->byNewFrame(lastAnnotations, nextAnnotations, lastEvent));
        }
    });
}

MouseCursor MouseTrackerCls::debugDeviceActiveCursor(int device) {
    return _mouseCursorMixin->debugDeviceActiveCursor(device);
}

void MouseTrackerCls::_monitorMouseConnection(VoidCallback task) {
    bool mouseWasConnected = mouseIsConnected();
    task();
    if (mouseWasConnected != mouseIsConnected()) {
        notifyListeners();
    }
}

void MouseTrackerCls::_deviceUpdatePhase(VoidCallback task) {
    assert(!_debugDuringDeviceUpdate);
    assert([=] () {
        _debugDuringDeviceUpdate = true;
        return true;
    }());
    task();
    assert([=] () {
        _debugDuringDeviceUpdate = false;
        return true;
    }());
}

bool MouseTrackerCls::_shouldMarkStateDirty(PointerEvent event, _MouseState state) {
    if (state == nullptr) {
        return true;
    }
    assert(event != nullptr);
    PointerEvent lastEvent = state->latestEvent();
    assert(event->device == lastEvent->device);
    assert((is<PointerAddedEvent>(event)) == (is<PointerRemovedEvent>(lastEvent)));
    if (is<PointerSignalEvent>(event)) {
        return false;
    }
    return is<PointerAddedEvent>(lastEvent) || is<PointerRemovedEvent>(event) || lastEvent->position != event->position;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> MouseTrackerCls::_hitTestResultToAnnotations(HitTestResult result) {
    assert(result != nullptr);
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> annotations = <MouseTrackerAnnotation, Matrix4>make<LinkedHashMapCls>();
    for (HitTestEntry entry : result->path) {
        Object target = entry->target;
        if (is<MouseTrackerAnnotation>(target)) {
            annotations[as<MouseTrackerAnnotationCls>(target)] = entry->transform!;
        }
    }
    return annotations;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> MouseTrackerCls::_findAnnotations(MouseDetectorAnnotationFinder hitTest, _MouseState state) {
    assert(state != nullptr);
    assert(hitTest != nullptr);
    Offset globalPosition = state->latestEvent()->position;
    int device = state->device;
    if (!_mouseStates->containsKey(device)) {
        return <MouseTrackerAnnotation, Matrix4>make<LinkedHashMapCls>();
    }
    return _hitTestResultToAnnotations(hitTest(globalPosition));
}

void MouseTrackerCls::_handleDeviceUpdate(_MouseTrackerUpdateDetails details) {
    assert(_debugDuringDeviceUpdate);
    _handleDeviceUpdateMouseEvents(details);
    _mouseCursorMixin->handleDeviceCursorUpdate(details->device, details->triggeringEvent, details->nextAnnotations->keys->map([=] (MouseTrackerAnnotation annotation)     {
        annotation->cursor;
    }));
}

void MouseTrackerCls::_handleDeviceUpdateMouseEvents(_MouseTrackerUpdateDetails details) {
    PointerEvent latestEvent = details->latestEvent();
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations = details->lastAnnotations;
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations = details->nextAnnotations;
    PointerExitEvent baseExitEvent = PointerExitEventCls->fromMouseEvent(latestEvent);
    lastAnnotations->forEach([=] (MouseTrackerAnnotation annotation,Matrix4 transform) {
        if (!nextAnnotations->containsKey(annotation)) {
            if (annotation->validForMouseTracker && annotation->onExit != nullptr) {
                annotation->onExit!(baseExitEvent->transformed(lastAnnotations[annotation]));
            }
        }
    });
    List<MouseTrackerAnnotation> enteringAnnotations = nextAnnotations->keys->where([=] (MouseTrackerAnnotation annotation) {
    !lastAnnotations->containsKey(annotation);
})->toList();
    PointerEnterEvent baseEnterEvent = PointerEnterEventCls->fromMouseEvent(latestEvent);
    for (MouseTrackerAnnotation annotation : enteringAnnotations->reversed) {
        if (annotation->validForMouseTracker && annotation->onEnter != nullptr) {
            annotation->onEnter!(baseEnterEvent->transformed(nextAnnotations[annotation]));
        }
    }
}
