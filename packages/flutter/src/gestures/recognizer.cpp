#include "recognizer.hpp"
GestureRecognizerCls::GestureRecognizerCls(Object debugOwner, PointerDeviceKind kind, Set<PointerDeviceKind> supportedDevices) {
    {
        assert(kind == nullptr || supportedDevices == nullptr);
        _supportedDevices = kind == nullptr? supportedDevices : makeSet(ArrayItem);
    }
}

void GestureRecognizerCls::addPointerPanZoom(PointerPanZoomStartEvent event) {
    _pointerToKind[event->pointer] = event->kind;
    if (isPointerPanZoomAllowed(event)) {
        addAllowedPointerPanZoom(event);
    } else {
        handleNonAllowedPointerPanZoom(event);
    }
}

void GestureRecognizerCls::addAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
}

void GestureRecognizerCls::addPointer(PointerDownEvent event) {
    _pointerToKind[event->pointer] = event->kind;
    if (isPointerAllowed(event)) {
        addAllowedPointer(event);
    } else {
        handleNonAllowedPointer(event);
    }
}

void GestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
}

void GestureRecognizerCls::handleNonAllowedPointer(PointerDownEvent event) {
}

bool GestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    return _supportedDevices == nullptr || _supportedDevices!->contains(event->kind);
}

void GestureRecognizerCls::handleNonAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
}

bool GestureRecognizerCls::isPointerPanZoomAllowed(PointerPanZoomStartEvent event) {
    return _supportedDevices == nullptr || _supportedDevices!->contains(event->kind);
}

PointerDeviceKind GestureRecognizerCls::getKindForPointer(int pointer) {
    assert(_pointerToKind->containsKey(pointer));
    return _pointerToKind[pointer]!;
}

void GestureRecognizerCls::dispose() {
}

template<typename T>
T GestureRecognizerCls::invokeCallback(String name, RecognizerCallback<T> callback, std::function<String()> debugReport) {
    assert(callback != nullptr);
    T result;
    try {
        assert([=] () {
            if (debugPrintRecognizerCallbacksTrace) {
                String report = debugReport != nullptr? debugReport() : nullptr;
                String prefix = debugPrintGestureArenaDiagnostics? __s("${' ' * 19}❙ ") : __s("");
                debugPrint(__s("$prefix$this calling $name callback.${ (report?.isNotEmpty ?? false) ? " $report" : "" }"));
            }
            return true;
        }());
        result = callback();
    } catch (Unknown exception) {
        InformationCollector collector;
        assert([=] () {
            collector = [=] () {
                makeList(ArrayItem, ArrayItem);
            };
            return true;
        }());
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("gesture"), make<ErrorDescriptionCls>(__s("while handling a gesture")), collector));
    };
    return result;
}

void GestureRecognizerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("debugOwner"), debugOwner, nullptr));
}

void OneSequenceGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    startTrackingPointer(event->pointer, event->transform);
}

void OneSequenceGestureRecognizerCls::handleNonAllowedPointer(PointerDownEvent event) {
    resolve(GestureDispositionCls::rejected);
}

void OneSequenceGestureRecognizerCls::acceptGesture(int pointer) {
}

void OneSequenceGestureRecognizerCls::rejectGesture(int pointer) {
}

void OneSequenceGestureRecognizerCls::resolve(GestureDisposition disposition) {
    List<GestureArenaEntry> localEntries = <GestureArenaEntry>of(_entries->values());
    _entries->clear();
    for (GestureArenaEntry entry : localEntries) {
        entry->resolve(disposition);
    }
}

void OneSequenceGestureRecognizerCls::resolvePointer(int pointer, GestureDisposition disposition) {
    GestureArenaEntry entry = _entries[pointer];
    if (entry != nullptr) {
        _entries->remove(pointer);
        entry->resolve(disposition);
    }
}

void OneSequenceGestureRecognizerCls::dispose() {
    resolve(GestureDispositionCls::rejected);
    for (int pointer : _trackedPointers) {
        GestureBindingCls::instance->pointerRouter->removeRoute(pointer, handleEvent);
    }
    _trackedPointers->clear();
    assert(_entries->isEmpty());
    super->dispose();
}

GestureArenaTeam OneSequenceGestureRecognizerCls::team() {
    return _team;
}

void OneSequenceGestureRecognizerCls::team(GestureArenaTeam value) {
    assert(value != nullptr);
    assert(_entries->isEmpty());
    assert(_trackedPointers->isEmpty());
    assert(_team == nullptr);
    _team = value;
}

void OneSequenceGestureRecognizerCls::startTrackingPointer(int pointer, Matrix4 transform) {
    GestureBindingCls::instance->pointerRouter->addRoute(pointer, handleEvent, transform);
    _trackedPointers->add(pointer);
    assert(!_entries->containsValue(pointer));
    _entries[pointer] = _addPointerToArena(pointer);
}

void OneSequenceGestureRecognizerCls::stopTrackingPointer(int pointer) {
    if (_trackedPointers->contains(pointer)) {
        GestureBindingCls::instance->pointerRouter->removeRoute(pointer, handleEvent);
        _trackedPointers->remove(pointer);
        if (_trackedPointers->isEmpty()) {
            didStopTrackingLastPointer(pointer);
        }
    }
}

void OneSequenceGestureRecognizerCls::stopTrackingIfPointerNoLongerDown(PointerEvent event) {
    if (is<PointerUpEvent>(event) || is<PointerCancelEvent>(event) || is<PointerPanZoomEndEvent>(event)) {
        stopTrackingPointer(event->pointer);
    }
}

GestureArenaEntry OneSequenceGestureRecognizerCls::_addPointerToArena(int pointer) {
    if (_team != nullptr) {
        return _team!->add(pointer, this);
    }
    return GestureBindingCls::instance->gestureArena->add(pointer, this);
}

PrimaryPointerGestureRecognizerCls::PrimaryPointerGestureRecognizerCls(Duration deadline, Object debugOwner, Unknown kind, double postAcceptSlopTolerance, double preAcceptSlopTolerance, Unknown supportedDevices) {
    {
        assert(preAcceptSlopTolerance == nullptr || preAcceptSlopTolerance >= 0, __s("The preAcceptSlopTolerance must be positive or null"));
        assert(postAcceptSlopTolerance == nullptr || postAcceptSlopTolerance >= 0, __s("The postAcceptSlopTolerance must be positive or null"));
    }
}

GestureRecognizerState PrimaryPointerGestureRecognizerCls::state() {
    return _state;
}

int PrimaryPointerGestureRecognizerCls::primaryPointer() {
    return _primaryPointer;
}

OffsetPair PrimaryPointerGestureRecognizerCls::initialPosition() {
    return _initialPosition;
}

void PrimaryPointerGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    if (state() == GestureRecognizerStateCls::ready) {
        _state = GestureRecognizerStateCls::possible;
        _primaryPointer = event->pointer;
        _initialPosition = make<OffsetPairCls>(event->localPosition(), event->position);
        if (deadline != nullptr) {
            _timer = make<TimerCls>(deadline!, [=] () {
                didExceedDeadlineWithEvent(event);
            });
        }
    }
}

void PrimaryPointerGestureRecognizerCls::handleNonAllowedPointer(PointerDownEvent event) {
    if (!_gestureAccepted) {
        super->handleNonAllowedPointer(event);
    }
}

void PrimaryPointerGestureRecognizerCls::handleEvent(PointerEvent event) {
    assert(state() != GestureRecognizerStateCls::ready);
    if (state() == GestureRecognizerStateCls::possible && event->pointer == primaryPointer()) {
        bool isPreAcceptSlopPastTolerance = !_gestureAccepted && preAcceptSlopTolerance != nullptr && _getGlobalDistance(event) > preAcceptSlopTolerance!;
        bool isPostAcceptSlopPastTolerance = _gestureAccepted && postAcceptSlopTolerance != nullptr && _getGlobalDistance(event) > postAcceptSlopTolerance!;
        if (is<PointerMoveEvent>(event) && (isPreAcceptSlopPastTolerance || isPostAcceptSlopPastTolerance)) {
            resolve(GestureDispositionCls::rejected);
            stopTrackingPointer(primaryPointer()!);
        } else {
            handlePrimaryPointer(event);
        }
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void PrimaryPointerGestureRecognizerCls::didExceedDeadline() {
    assert(deadline == nullptr);
}

void PrimaryPointerGestureRecognizerCls::didExceedDeadlineWithEvent(PointerDownEvent event) {
    didExceedDeadline();
}

void PrimaryPointerGestureRecognizerCls::acceptGesture(int pointer) {
    if (pointer == primaryPointer()) {
        _stopTimer();
        _gestureAccepted = true;
    }
}

void PrimaryPointerGestureRecognizerCls::rejectGesture(int pointer) {
    if (pointer == primaryPointer() && state() == GestureRecognizerStateCls::possible) {
        _stopTimer();
        _state = GestureRecognizerStateCls::defunct;
    }
}

void PrimaryPointerGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
    assert(state() != GestureRecognizerStateCls::ready);
    _stopTimer();
    _state = GestureRecognizerStateCls::ready;
    _initialPosition = nullptr;
    _gestureAccepted = false;
}

void PrimaryPointerGestureRecognizerCls::dispose() {
    _stopTimer();
    super->dispose();
}

void PrimaryPointerGestureRecognizerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<GestureRecognizerState>make<EnumPropertyCls>(__s("state"), state()));
}

void PrimaryPointerGestureRecognizerCls::_stopTimer() {
    if (_timer != nullptr) {
        _timer!->cancel();
        _timer = nullptr;
    }
}

double PrimaryPointerGestureRecognizerCls::_getGlobalDistance(PointerEvent event) {
    Offset offset = event->position - initialPosition()!->global;
    return offset->distance();
}

void OffsetPairCls::fromEventPosition(PointerEvent event) {
    return make<OffsetPairCls>(event->localPosition(), event->position);
}

void OffsetPairCls::fromEventDelta(PointerEvent event) {
    return make<OffsetPairCls>(event->localDelta(), event->delta);
}

OffsetPair OffsetPairCls::+(OffsetPair other) {
    return make<OffsetPairCls>(local + other->local, global + other->global);
}

OffsetPair OffsetPairCls::-(OffsetPair other) {
    return make<OffsetPairCls>(local - other->local, global - other->global);
}

String OffsetPairCls::toString() {
    return __s("${objectRuntimeType(this, 'OffsetPair')}(local: $local, global: $global)");
}
