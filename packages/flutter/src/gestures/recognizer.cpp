#include "recognizer.hpp"
GestureRecognizer::GestureRecognizer(Object debugOwner, PointerDeviceKind kind, Set<PointerDeviceKind> supportedDevices) {
    {
        assert(kind == nullptr || supportedDevices == nullptr);
        _supportedDevices = kind == nullptr? supportedDevices : ;
    }
}

void GestureRecognizer::addPointerPanZoom(PointerPanZoomStartEvent event) {
    _pointerToKind[event.pointer] = event.kind;
    if (isPointerPanZoomAllowed(event)) {
        addAllowedPointerPanZoom(event);
    } else {
        handleNonAllowedPointerPanZoom(event);
    }
}

void GestureRecognizer::addAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
}

void GestureRecognizer::addPointer(PointerDownEvent event) {
    _pointerToKind[event.pointer] = event.kind;
    if (isPointerAllowed(event)) {
        addAllowedPointer(event);
    } else {
        handleNonAllowedPointer(event);
    }
}

void GestureRecognizer::addAllowedPointer(PointerDownEvent event) {
}

void GestureRecognizer::handleNonAllowedPointer(PointerDownEvent event) {
}

bool GestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    return _supportedDevices == nullptr || _supportedDevices!.contains(event.kind);
}

void GestureRecognizer::handleNonAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
}

bool GestureRecognizer::isPointerPanZoomAllowed(PointerPanZoomStartEvent event) {
    return _supportedDevices == nullptr || _supportedDevices!.contains(event.kind);
}

PointerDeviceKind GestureRecognizer::getKindForPointer(int pointer) {
    assert(_pointerToKind.containsKey(pointer));
    return _pointerToKind[pointer]!;
}

void GestureRecognizer::dispose() {
}

T GestureRecognizer::invokeCallback<T>(RecognizerCallback<T> callback, FunctionType debugReport, String name) {
    assert(callback != nullptr);
    T result;
    ;
    return result;
}

void GestureRecognizer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Object>DiagnosticsProperty("debugOwner", debugOwnernullptr));
}

void OneSequenceGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    startTrackingPointer(event.pointer, event.transform);
}

void OneSequenceGestureRecognizer::handleNonAllowedPointer(PointerDownEvent event) {
    resolve(GestureDisposition.rejected);
}

void OneSequenceGestureRecognizer::acceptGesture(int pointer) {
}

void OneSequenceGestureRecognizer::rejectGesture(int pointer) {
}

void OneSequenceGestureRecognizer::resolve(GestureDisposition disposition) {
    List<GestureArenaEntry> localEntries = <GestureArenaEntry>of(_entries.values);
    _entries.clear();
    for (GestureArenaEntry entry : localEntries) {
        entry.resolve(disposition);
    }
}

void OneSequenceGestureRecognizer::resolvePointer(GestureDisposition disposition, int pointer) {
    GestureArenaEntry entry = _entries[pointer];
    if (entry != nullptr) {
        _entries.remove(pointer);
        entry.resolve(disposition);
    }
}

void OneSequenceGestureRecognizer::dispose() {
    resolve(GestureDisposition.rejected);
    for (int pointer : _trackedPointers) {
        GestureBinding.instance.pointerRouter.removeRoute(pointer, handleEvent);
    }
    _trackedPointers.clear();
    assert(_entries.isEmpty);
    super.dispose();
}

GestureArenaTeam OneSequenceGestureRecognizer::team() {
    return _team;
}

void OneSequenceGestureRecognizer::team(GestureArenaTeam value) {
    assert(value != nullptr);
    assert(_entries.isEmpty);
    assert(_trackedPointers.isEmpty);
    assert(_team == nullptr);
    _team = value;
}

void OneSequenceGestureRecognizer::startTrackingPointer(int pointer, Matrix4 transform) {
    GestureBinding.instance.pointerRouter.addRoute(pointer, handleEvent, transform);
    _trackedPointers.add(pointer);
    assert(!_entries.containsValue(pointer));
    _entries[pointer] = _addPointerToArena(pointer);
}

void OneSequenceGestureRecognizer::stopTrackingPointer(int pointer) {
    if (_trackedPointers.contains(pointer)) {
        GestureBinding.instance.pointerRouter.removeRoute(pointer, handleEvent);
        _trackedPointers.remove(pointer);
        if (_trackedPointers.isEmpty) {
            didStopTrackingLastPointer(pointer);
        }
    }
}

void OneSequenceGestureRecognizer::stopTrackingIfPointerNoLongerDown(PointerEvent event) {
    if (event is PointerUpEvent || event is PointerCancelEvent || event is PointerPanZoomEndEvent) {
        stopTrackingPointer(event.pointer);
    }
}

GestureArenaEntry OneSequenceGestureRecognizer::_addPointerToArena(int pointer) {
    if (_team != nullptr) {
        return _team!.add(pointer, this);
    }
    return GestureBinding.instance.gestureArena.add(pointer, this);
}

PrimaryPointerGestureRecognizer::PrimaryPointerGestureRecognizer(Duration deadline, Unknown, Unknown, double postAcceptSlopTolerance, double preAcceptSlopTolerance, Unknown) {
    {
        assert(preAcceptSlopTolerance == nullptr || preAcceptSlopTolerance >= 0, "The preAcceptSlopTolerance must be positive or null");
        assert(postAcceptSlopTolerance == nullptr || postAcceptSlopTolerance >= 0, "The postAcceptSlopTolerance must be positive or null");
    }
}

GestureRecognizerState PrimaryPointerGestureRecognizer::state() {
    return _state;
}

int PrimaryPointerGestureRecognizer::primaryPointer() {
    return _primaryPointer;
}

OffsetPair PrimaryPointerGestureRecognizer::initialPosition() {
    return _initialPosition;
}

void PrimaryPointerGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    super.addAllowedPointer(event);
    if (state == GestureRecognizerState.ready) {
        _state = GestureRecognizerState.possible;
        _primaryPointer = event.pointer;
        _initialPosition = OffsetPair(event.localPosition, event.position);
        if (deadline != nullptr) {
            _timer = Timer(deadline!, );
        }
    }
}

void PrimaryPointerGestureRecognizer::handleNonAllowedPointer(PointerDownEvent event) {
    if (!_gestureAccepted) {
        super.handleNonAllowedPointer(event);
    }
}

void PrimaryPointerGestureRecognizer::handleEvent(PointerEvent event) {
    assert(state != GestureRecognizerState.ready);
    if (state == GestureRecognizerState.possible && event.pointer == primaryPointer) {
        bool isPreAcceptSlopPastTolerance = !_gestureAccepted && preAcceptSlopTolerance != nullptr && _getGlobalDistance(event) > preAcceptSlopTolerance!;
        bool isPostAcceptSlopPastTolerance = _gestureAccepted && postAcceptSlopTolerance != nullptr && _getGlobalDistance(event) > postAcceptSlopTolerance!;
        if (event is PointerMoveEvent && (isPreAcceptSlopPastTolerance || isPostAcceptSlopPastTolerance)) {
            resolve(GestureDisposition.rejected);
            stopTrackingPointer(primaryPointer!);
        } else {
            handlePrimaryPointer(event);
        }
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void PrimaryPointerGestureRecognizer::didExceedDeadline() {
    assert(deadline == nullptr);
}

void PrimaryPointerGestureRecognizer::didExceedDeadlineWithEvent(PointerDownEvent event) {
    didExceedDeadline();
}

void PrimaryPointerGestureRecognizer::acceptGesture(int pointer) {
    if (pointer == primaryPointer) {
        _stopTimer();
        _gestureAccepted = true;
    }
}

void PrimaryPointerGestureRecognizer::rejectGesture(int pointer) {
    if (pointer == primaryPointer && state == GestureRecognizerState.possible) {
        _stopTimer();
        _state = GestureRecognizerState.defunct;
    }
}

void PrimaryPointerGestureRecognizer::didStopTrackingLastPointer(int pointer) {
    assert(state != GestureRecognizerState.ready);
    _stopTimer();
    _state = GestureRecognizerState.ready;
    _initialPosition = nullptr;
    _gestureAccepted = false;
}

void PrimaryPointerGestureRecognizer::dispose() {
    _stopTimer();
    super.dispose();
}

void PrimaryPointerGestureRecognizer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<GestureRecognizerState>EnumProperty("state", state));
}

void PrimaryPointerGestureRecognizer::_stopTimer() {
    if (_timer != nullptr) {
        _timer!.cancel();
        _timer = nullptr;
    }
}

double PrimaryPointerGestureRecognizer::_getGlobalDistance(PointerEvent event) {
    Offset offset = event.position - initialPosition!.global;
    return offset.distance;
}

void OffsetPair::fromEventPosition(PointerEvent event) {
    return OffsetPair(event.localPosition, event.position);
}

void OffsetPair::fromEventDelta(PointerEvent event) {
    return OffsetPair(event.localDelta, event.delta);
}

OffsetPair OffsetPair::+(OffsetPair other) {
    return OffsetPair(local + other.local, global + other.global);
}

OffsetPair OffsetPair::-(OffsetPair other) {
    return OffsetPair(local - other.local, global - other.global);
}

String OffsetPair::toString() {
    return "${objectRuntimeType(this, 'OffsetPair')}(local: $local, global: $global)";
}
