#include "mouse_tracker.hpp"
LinkedHashMap<MouseTrackerAnnotation, Matrix4> _MouseState::annotations() {
    return _annotations;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> _MouseState::replaceAnnotations(LinkedHashMap<MouseTrackerAnnotation, Matrix4> value) {
    assert(value != nullptr);
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> previous = _annotations;
    _annotations = value;
    return previous;
}

PointerEvent _MouseState::latestEvent() {
    return _latestEvent;
}

PointerEvent _MouseState::replaceLatestEvent(PointerEvent value) {
    assert(value != nullptr);
    assert(value.device == _latestEvent.device);
    PointerEvent previous = _latestEvent;
    _latestEvent = value;
    return previous;
}

int _MouseState::device() {
    return latestEvent.device;
}

String _MouseState::toString() {
    String describeLatestEvent = "latestEvent: ${describeIdentity(latestEvent)}";
    String describeAnnotations = "annotations: [list of ${annotations.length}]";
    return "${describeIdentity(this)}($describeLatestEvent, $describeAnnotations)";
}

_MouseState::_MouseState(PointerEvent initialEvent) {
    {
        assert(initialEvent != nullptr);
        _latestEvent = initialEvent;
    }
}

void _MouseTrackerUpdateDetails::byNewFrame(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent)

void _MouseTrackerUpdateDetails::byPointerEvent(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent, PointerEvent triggeringEvent)

int _MouseTrackerUpdateDetails::device() {
    int result = (previousEvent ?? triggeringEvent)!.device;
    assert(result != nullptr);
    return result;
}

PointerEvent _MouseTrackerUpdateDetails::latestEvent() {
    PointerEvent result = triggeringEvent ?? previousEvent!;
    assert(result != nullptr);
    return result;
}

void _MouseTrackerUpdateDetails::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("device", device));
    properties.add(<PointerEvent>DiagnosticsProperty("previousEvent", previousEvent));
    properties.add(<PointerEvent>DiagnosticsProperty("triggeringEvent", triggeringEvent));
    properties.add(<Map<MouseTrackerAnnotation, Matrix4>>DiagnosticsProperty("lastAnnotations", lastAnnotations));
    properties.add(<Map<MouseTrackerAnnotation, Matrix4>>DiagnosticsProperty("nextAnnotations", nextAnnotations));
}

bool MouseTracker::mouseIsConnected() {
    return _mouseStates.isNotEmpty;
}

void MouseTracker::updateWithEvent(PointerEvent event, ValueGetter<HitTestResult> getResult) {
    if (event.kind != PointerDeviceKind.mouse) {
        return;
    }
    if (event is PointerSignalEvent) {
        return;
    }
    HitTestResult result = event is PointerRemovedEvent? HitTestResult() : getResult();
    int device = event.device;
    _MouseState existingState = _mouseStates[device];
    if (!_shouldMarkStateDirty(existingState, event)) {
        return;
    }
    _monitorMouseConnection();
}

void MouseTracker::updateAllDevices(MouseDetectorAnnotationFinder hitTest) {
    _deviceUpdatePhase();
}

MouseCursor MouseTracker::debugDeviceActiveCursor(int device) {
    return _mouseCursorMixin.debugDeviceActiveCursor(device);
}

void MouseTracker::_monitorMouseConnection(VoidCallback task) {
    bool mouseWasConnected = mouseIsConnected;
    task();
    if (mouseWasConnected != mouseIsConnected) {
        notifyListeners();
    }
}

void MouseTracker::_deviceUpdatePhase(VoidCallback task) {
    assert(!_debugDuringDeviceUpdate);
    assert(());
    task();
    assert(());
}

bool MouseTracker::_shouldMarkStateDirty(PointerEvent event, _MouseState state) {
    if (state == nullptr) {
        return true;
    }
    assert(event != nullptr);
    PointerEvent lastEvent = state.latestEvent;
    assert(event.device == lastEvent.device);
    assert((event is PointerAddedEvent) == (lastEvent is PointerRemovedEvent));
    if (event is PointerSignalEvent) {
        return false;
    }
    return lastEvent is PointerAddedEvent || event is PointerRemovedEvent || lastEvent.position != event.position;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> MouseTracker::_hitTestResultToAnnotations(HitTestResult result) {
    assert(result != nullptr);
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> annotations = <MouseTrackerAnnotation, Matrix4>LinkedHashMap();
    for (HitTestEntry entry : result.path) {
        Object target = entry.target;
        if (target is MouseTrackerAnnotation) {
            annotations[target] = entry.transform!;
        }
    }
    return annotations;
}

LinkedHashMap<MouseTrackerAnnotation, Matrix4> MouseTracker::_findAnnotations(MouseDetectorAnnotationFinder hitTest, _MouseState state) {
    assert(state != nullptr);
    assert(hitTest != nullptr);
    Offset globalPosition = state.latestEvent.position;
    int device = state.device;
    if (!_mouseStates.containsKey(device)) {
        return <MouseTrackerAnnotation, Matrix4>LinkedHashMap();
    }
    return _hitTestResultToAnnotations(hitTest(globalPosition));
}

void MouseTracker::_handleDeviceUpdate(_MouseTrackerUpdateDetails details) {
    assert(_debugDuringDeviceUpdate);
    _handleDeviceUpdateMouseEvents(details);
    _mouseCursorMixin.handleDeviceCursorUpdate(details.device, details.triggeringEvent, details.nextAnnotations.keys.map());
}

void MouseTracker::_handleDeviceUpdateMouseEvents(_MouseTrackerUpdateDetails details) {
    PointerEvent latestEvent = details.latestEvent;
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations = details.lastAnnotations;
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations = details.nextAnnotations;
    PointerExitEvent baseExitEvent = PointerExitEvent.fromMouseEvent(latestEvent);
    lastAnnotations.forEach();
    List<MouseTrackerAnnotation> enteringAnnotations = nextAnnotations.keys.where().toList();
    PointerEnterEvent baseEnterEvent = PointerEnterEvent.fromMouseEvent(latestEvent);
    for (MouseTrackerAnnotation annotation : enteringAnnotations.reversed) {
        if (annotation.validForMouseTracker && annotation.onEnter != nullptr) {
            annotation.onEnter!(baseEnterEvent.transformed(nextAnnotations[annotation]));
        }
    }
}
