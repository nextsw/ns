#include "multidrag.hpp"
MultiDragPointerState::MultiDragPointerState(DeviceGestureSettings gestureSettings, Offset initialPosition, PointerDeviceKind kind) {
    {
        assert(initialPosition != nullptr);
        _velocityTracker = VelocityTracker.withKind(kind);
    }
}

Offset MultiDragPointerState::pendingDelta() {
    return _pendingDelta;
}

void MultiDragPointerState::resolve(GestureDisposition disposition) {
    _arenaEntry!.resolve(disposition);
}

void MultiDragPointerState::checkForResolutionAfterMove() {
}

void MultiDragPointerState::rejected() {
    assert(_arenaEntry != nullptr);
    assert(_client == nullptr);
    assert(pendingDelta != nullptr);
    _pendingDelta = nullptr;
    _lastPendingEventTimestamp = nullptr;
    _arenaEntry = nullptr;
}

void MultiDragPointerState::dispose() {
    _arenaEntry?.resolve(GestureDisposition.rejected);
    _arenaEntry = nullptr;
    assert(());
}

void MultiDragPointerState::_setArenaEntry(GestureArenaEntry entry) {
    assert(_arenaEntry == nullptr);
    assert(pendingDelta != nullptr);
    assert(_client == nullptr);
    _arenaEntry = entry;
}

void MultiDragPointerState::_move(PointerMoveEvent event) {
    assert(_arenaEntry != nullptr);
    if (!event.synthesized) {
        _velocityTracker.addPosition(event.timeStamp, event.position);
    }
    if (_client != nullptr) {
        assert(pendingDelta == nullptr);
        _client!.update(DragUpdateDetails(event.timeStamp, event.delta, event.position));
    } else {
        assert(pendingDelta != nullptr);
        _pendingDelta = _pendingDelta! + event.delta;
        _lastPendingEventTimestamp = event.timeStamp;
        checkForResolutionAfterMove();
    }
}

void MultiDragPointerState::_startDrag(Drag client) {
    assert(_arenaEntry != nullptr);
    assert(_client == nullptr);
    assert(client != nullptr);
    assert(pendingDelta != nullptr);
    _client = client;
    DragUpdateDetails details = DragUpdateDetails(_lastPendingEventTimestamp, pendingDelta!, initialPosition);
    _pendingDelta = nullptr;
    _lastPendingEventTimestamp = nullptr;
    _client!.update(details);
}

void MultiDragPointerState::_up() {
    assert(_arenaEntry != nullptr);
    if (_client != nullptr) {
        assert(pendingDelta == nullptr);
        DragEndDetails details = DragEndDetails(_velocityTracker.getVelocity());
        Drag client = _client!;
        _client = nullptr;
        client.end(details);
    } else {
        assert(pendingDelta != nullptr);
        _pendingDelta = nullptr;
        _lastPendingEventTimestamp = nullptr;
    }
}

void MultiDragPointerState::_cancel() {
    assert(_arenaEntry != nullptr);
    if (_client != nullptr) {
        assert(pendingDelta == nullptr);
        Drag client = _client!;
        _client = nullptr;
        client.cancel();
    } else {
        assert(pendingDelta != nullptr);
        _pendingDelta = nullptr;
        _lastPendingEventTimestamp = nullptr;
    }
}

void MultiDragGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    assert(_pointers != nullptr);
    assert(event.pointer != nullptr);
    assert(event.position != nullptr);
    assert(!_pointers!.containsKey(event.pointer));
    MultiDragPointerState state = createNewPointerState(event);
    _pointers![event.pointer] = state;
    GestureBinding.instance.pointerRouter.addRoute(event.pointer, _handleEvent);
    state._setArenaEntry(GestureBinding.instance.gestureArena.add(event.pointer, this));
}

void MultiDragGestureRecognizer::acceptGesture(int pointer) {
    assert(_pointers != nullptr);
    MultiDragPointerState state = _pointers![pointer];
    if (state == nullptr) {
        return;
    }
    state.accepted();
}

void MultiDragGestureRecognizer::rejectGesture(int pointer) {
    assert(_pointers != nullptr);
    if (_pointers!.containsKey(pointer)) {
        MultiDragPointerState state = _pointers![pointer]!;
        assert(state != nullptr);
        state.rejected();
        _removeState(pointer);
    }
}

void MultiDragGestureRecognizer::dispose() {
    _pointers!.keys.toList().forEach(_removeState);
    assert(_pointers!.isEmpty);
    _pointers = nullptr;
    super.dispose();
}

void MultiDragGestureRecognizer::_handleEvent(PointerEvent event) {
    assert(_pointers != nullptr);
    assert(event.pointer != nullptr);
    assert(event.timeStamp != nullptr);
    assert(event.position != nullptr);
    assert(_pointers!.containsKey(event.pointer));
    MultiDragPointerState state = _pointers![event.pointer]!;
    if (event is PointerMoveEvent) {
        state._move(event);
    } else     {
        if (event is PointerUpEvent) {
        assert(event.delta == Offset.zero);
        state._up();
        _removeState(event.pointer);
    } else     {
        if (event is PointerCancelEvent) {
        assert(event.delta == Offset.zero);
        state._cancel();
        _removeState(event.pointer);
    } else     {
        if (event is! PointerDownEvent) {
        assert(false);
    }
;
    };
    };
    }}

Drag MultiDragGestureRecognizer::_startDrag(Offset initialPosition, int pointer) {
    assert(_pointers != nullptr);
    MultiDragPointerState state = _pointers![pointer]!;
    assert(state != nullptr);
    assert(state._pendingDelta != nullptr);
    Drag drag;
    if (onStart != nullptr) {
        drag = <Drag>invokeCallback("onStart", );
    }
    if (drag != nullptr) {
        state._startDrag(drag);
    } else {
        _removeState(pointer);
    }
    return drag;
}

void MultiDragGestureRecognizer::_removeState(int pointer) {
    if (_pointers == nullptr) {
        return;
    }
    assert(_pointers!.containsKey(pointer));
    GestureBinding.instance.pointerRouter.removeRoute(pointer, _handleEvent);
    _pointers!.remove(pointer)!.dispose();
}

void _ImmediatePointerState::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!.distance > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDisposition.accepted);
    }
}

void _ImmediatePointerState::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState ImmediateMultiDragGestureRecognizer::createNewPointerState(PointerDownEvent event) {
    return _ImmediatePointerState(event.position, event.kind, gestureSettings);
}

String ImmediateMultiDragGestureRecognizer::debugDescription() {
    return "multidrag";
}

void _HorizontalPointerState::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!.dx.abs() > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDisposition.accepted);
    }
}

void _HorizontalPointerState::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState HorizontalMultiDragGestureRecognizer::createNewPointerState(PointerDownEvent event) {
    return _HorizontalPointerState(event.position, event.kind, gestureSettings);
}

String HorizontalMultiDragGestureRecognizer::debugDescription() {
    return "horizontal multidrag";
}

void _VerticalPointerState::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!.dy.abs() > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDisposition.accepted);
    }
}

void _VerticalPointerState::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState VerticalMultiDragGestureRecognizer::createNewPointerState(PointerDownEvent event) {
    return _VerticalPointerState(event.position, event.kind, gestureSettings);
}

String VerticalMultiDragGestureRecognizer::debugDescription() {
    return "vertical multidrag";
}

void _DelayedPointerState::accepted(GestureMultiDragStartCallback starter) {
    assert(_starter == nullptr);
    if (_timer == nullptr) {
        starter(initialPosition);
    } else {
        _starter = starter;
    }
}

void _DelayedPointerState::checkForResolutionAfterMove() {
    if (_timer == nullptr) {
        assert(_starter != nullptr);
        return;
    }
    assert(pendingDelta != nullptr);
    if (pendingDelta!.distance > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDisposition.rejected);
        _ensureTimerStopped();
    }
}

void _DelayedPointerState::dispose() {
    _ensureTimerStopped();
    super.dispose();
}

_DelayedPointerState::_DelayedPointerState(Duration delay, DeviceGestureSettings deviceGestureSettings, Offset initialPosition, PointerDeviceKind kind) {
    {
        assert(delay != nullptr);
        super(initialPosition, kind, deviceGestureSettings);
    }
    {
        _timer = Timer(delay, _delayPassed);
    }
}

void _DelayedPointerState::_delayPassed() {
    assert(_timer != nullptr);
    assert(pendingDelta != nullptr);
    assert(pendingDelta!.distance <= computeHitSlop(kind, gestureSettings));
    _timer = nullptr;
    if (_starter != nullptr) {
        _starter!(initialPosition);
        _starter = nullptr;
    } else {
        resolve(GestureDisposition.accepted);
    }
    assert(_starter == nullptr);
}

void _DelayedPointerState::_ensureTimerStopped() {
    _timer?.cancel();
    _timer = nullptr;
}

DelayedMultiDragGestureRecognizer::DelayedMultiDragGestureRecognizer(Unknown, Duration delay, Unknown, Unknown) {
    {
        assert(delay != nullptr);
    }
}

MultiDragPointerState DelayedMultiDragGestureRecognizer::createNewPointerState(PointerDownEvent event) {
    return _DelayedPointerState(event.position, delay, event.kind, gestureSettings);
}

String DelayedMultiDragGestureRecognizer::debugDescription() {
    return "long multidrag";
}
