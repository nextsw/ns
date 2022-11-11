#include "multidrag.hpp"
MultiDragPointerStateCls::MultiDragPointerStateCls(DeviceGestureSettings gestureSettings, Offset initialPosition, PointerDeviceKind kind) {
    {
        assert(initialPosition != nullptr);
        _velocityTracker = VelocityTrackerCls->withKind(kind);
    }
}

Offset MultiDragPointerStateCls::pendingDelta() {
    return _pendingDelta;
}

void MultiDragPointerStateCls::resolve(GestureDisposition disposition) {
    _arenaEntry!->resolve(disposition);
}

void MultiDragPointerStateCls::checkForResolutionAfterMove() {
}

void MultiDragPointerStateCls::rejected() {
    assert(_arenaEntry != nullptr);
    assert(_client == nullptr);
    assert(pendingDelta() != nullptr);
    _pendingDelta = nullptr;
    _lastPendingEventTimestamp = nullptr;
    _arenaEntry = nullptr;
}

void MultiDragPointerStateCls::dispose() {
    _arenaEntry?->resolve(GestureDispositionCls::rejected);
    _arenaEntry = nullptr;
    assert([=] () {
        _pendingDelta = nullptr;
        return true;
    }());
}

void MultiDragPointerStateCls::_setArenaEntry(GestureArenaEntry entry) {
    assert(_arenaEntry == nullptr);
    assert(pendingDelta() != nullptr);
    assert(_client == nullptr);
    _arenaEntry = entry;
}

void MultiDragPointerStateCls::_move(PointerMoveEvent event) {
    assert(_arenaEntry != nullptr);
    if (!event->synthesized) {
        _velocityTracker->addPosition(event->timeStamp, event->position);
    }
    if (_client != nullptr) {
        assert(pendingDelta() == nullptr);
        _client!->update(make<DragUpdateDetailsCls>(event->timeStamp, event->delta, event->position));
    } else {
        assert(pendingDelta() != nullptr);
        _pendingDelta = _pendingDelta! + event->delta;
        _lastPendingEventTimestamp = event->timeStamp;
        checkForResolutionAfterMove();
    }
}

void MultiDragPointerStateCls::_startDrag(Drag client) {
    assert(_arenaEntry != nullptr);
    assert(_client == nullptr);
    assert(client != nullptr);
    assert(pendingDelta() != nullptr);
    _client = client;
    DragUpdateDetails details = make<DragUpdateDetailsCls>(_lastPendingEventTimestamp, pendingDelta()!, initialPosition);
    _pendingDelta = nullptr;
    _lastPendingEventTimestamp = nullptr;
    _client!->update(details);
}

void MultiDragPointerStateCls::_up() {
    assert(_arenaEntry != nullptr);
    if (_client != nullptr) {
        assert(pendingDelta() == nullptr);
        DragEndDetails details = make<DragEndDetailsCls>(_velocityTracker->getVelocity());
        Drag client = _client!;
        _client = nullptr;
        client->end(details);
    } else {
        assert(pendingDelta() != nullptr);
        _pendingDelta = nullptr;
        _lastPendingEventTimestamp = nullptr;
    }
}

void MultiDragPointerStateCls::_cancel() {
    assert(_arenaEntry != nullptr);
    if (_client != nullptr) {
        assert(pendingDelta() == nullptr);
        Drag client = _client!;
        _client = nullptr;
        client->cancel();
    } else {
        assert(pendingDelta() != nullptr);
        _pendingDelta = nullptr;
        _lastPendingEventTimestamp = nullptr;
    }
}

void MultiDragGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    assert(_pointers != nullptr);
    assert(event->pointer != nullptr);
    assert(event->position != nullptr);
    assert(!_pointers!->containsKey(event->pointer));
    MultiDragPointerState state = createNewPointerState(event);
    _pointers![event->pointer] = state;
    GestureBindingCls::instance->pointerRouter->addRoute(event->pointer, _handleEvent);
    state->_setArenaEntry(GestureBindingCls::instance->gestureArena->add(event->pointer, this));
}

void MultiDragGestureRecognizerCls::acceptGesture(int pointer) {
    assert(_pointers != nullptr);
    MultiDragPointerState state = _pointers![pointer];
    if (state == nullptr) {
        return;
    }
    state->accepted([=] (Offset initialPosition)     {
        _startDrag(initialPosition, pointer);
    });
}

void MultiDragGestureRecognizerCls::rejectGesture(int pointer) {
    assert(_pointers != nullptr);
    if (_pointers!->containsKey(pointer)) {
        MultiDragPointerState state = _pointers![pointer]!;
        assert(state != nullptr);
        state->rejected();
        _removeState(pointer);
    }
}

void MultiDragGestureRecognizerCls::dispose() {
    _pointers!->keys()->toList()->forEach(_removeState);
    assert(_pointers!->isEmpty());
    _pointers = nullptr;
    super->dispose();
}

void MultiDragGestureRecognizerCls::_handleEvent(PointerEvent event) {
    assert(_pointers != nullptr);
    assert(event->pointer != nullptr);
    assert(event->timeStamp != nullptr);
    assert(event->position != nullptr);
    assert(_pointers!->containsKey(event->pointer));
    MultiDragPointerState state = _pointers![event->pointer]!;
    if (is<PointerMoveEvent>(event)) {
        state->_move(as<PointerMoveEventCls>(event));
    } else     {
        if (is<PointerUpEvent>(event)) {
        assert(as<PointerUpEventCls>(event)->delta == OffsetCls::zero);
        state->_up();
        _removeState(as<PointerUpEventCls>(event)->pointer);
    } else     {
        if (is<PointerCancelEvent>(event)) {
        assert(as<PointerCancelEventCls>(event)->delta == OffsetCls::zero);
        state->_cancel();
        _removeState(as<PointerCancelEventCls>(event)->pointer);
    } else     {
        if (!is<PointerDownEvent>(event)) {
        assert(false);
    }
;
    };
    };
    }}

Drag MultiDragGestureRecognizerCls::_startDrag(Offset initialPosition, int pointer) {
    assert(_pointers != nullptr);
    MultiDragPointerState state = _pointers![pointer]!;
    assert(state != nullptr);
    assert(state->_pendingDelta != nullptr);
    Drag drag;
    if (onStart != nullptr) {
        drag = <Drag>invokeCallback(__s("onStart"), [=] ()         {
            onStart!(initialPosition);
        });
    }
    if (drag != nullptr) {
        state->_startDrag(drag);
    } else {
        _removeState(pointer);
    }
    return drag;
}

void MultiDragGestureRecognizerCls::_removeState(int pointer) {
    if (_pointers == nullptr) {
        return;
    }
    assert(_pointers!->containsKey(pointer));
    GestureBindingCls::instance->pointerRouter->removeRoute(pointer, _handleEvent);
    _pointers!->remove(pointer)!->dispose();
}

void _ImmediatePointerStateCls::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!->distance > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDispositionCls::accepted);
    }
}

void _ImmediatePointerStateCls::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState ImmediateMultiDragGestureRecognizerCls::createNewPointerState(PointerDownEvent event) {
    return make<_ImmediatePointerStateCls>(event->position, event->kind, gestureSettings);
}

String ImmediateMultiDragGestureRecognizerCls::debugDescription() {
    return __s("multidrag");
}

void _HorizontalPointerStateCls::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!->dx->abs() > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDispositionCls::accepted);
    }
}

void _HorizontalPointerStateCls::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState HorizontalMultiDragGestureRecognizerCls::createNewPointerState(PointerDownEvent event) {
    return make<_HorizontalPointerStateCls>(event->position, event->kind, gestureSettings);
}

String HorizontalMultiDragGestureRecognizerCls::debugDescription() {
    return __s("horizontal multidrag");
}

void _VerticalPointerStateCls::checkForResolutionAfterMove() {
    assert(pendingDelta != nullptr);
    if (pendingDelta!->dy->abs() > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDispositionCls::accepted);
    }
}

void _VerticalPointerStateCls::accepted(GestureMultiDragStartCallback starter) {
    starter(initialPosition);
}

MultiDragPointerState VerticalMultiDragGestureRecognizerCls::createNewPointerState(PointerDownEvent event) {
    return make<_VerticalPointerStateCls>(event->position, event->kind, gestureSettings);
}

String VerticalMultiDragGestureRecognizerCls::debugDescription() {
    return __s("vertical multidrag");
}

void _DelayedPointerStateCls::accepted(GestureMultiDragStartCallback starter) {
    assert(_starter == nullptr);
    if (_timer == nullptr) {
        starter(initialPosition);
    } else {
        _starter = starter;
    }
}

void _DelayedPointerStateCls::checkForResolutionAfterMove() {
    if (_timer == nullptr) {
        assert(_starter != nullptr);
        return;
    }
    assert(pendingDelta != nullptr);
    if (pendingDelta!->distance > computeHitSlop(kind, gestureSettings)) {
        resolve(GestureDispositionCls::rejected);
        _ensureTimerStopped();
    }
}

void _DelayedPointerStateCls::dispose() {
    _ensureTimerStopped();
    super->dispose();
}

_DelayedPointerStateCls::_DelayedPointerStateCls(Duration delay, DeviceGestureSettings deviceGestureSettings, Offset initialPosition, PointerDeviceKind kind) : MultiDragPointerState(initialPosition, kind, deviceGestureSettings) {
    {
        assert(delay != nullptr);
    }
    {
        _timer = make<TimerCls>(delay, _delayPassed);
    }
}

void _DelayedPointerStateCls::_delayPassed() {
    assert(_timer != nullptr);
    assert(pendingDelta != nullptr);
    assert(pendingDelta!->distance <= computeHitSlop(kind, gestureSettings));
    _timer = nullptr;
    if (_starter != nullptr) {
        _starter!(initialPosition);
        _starter = nullptr;
    } else {
        resolve(GestureDispositionCls::accepted);
    }
    assert(_starter == nullptr);
}

void _DelayedPointerStateCls::_ensureTimerStopped() {
    _timer?->cancel();
    _timer = nullptr;
}

DelayedMultiDragGestureRecognizerCls::DelayedMultiDragGestureRecognizerCls(Unknown debugOwner, Duration delay, Unknown kind, Unknown supportedDevices) {
    {
        assert(delay != nullptr);
    }
}

MultiDragPointerState DelayedMultiDragGestureRecognizerCls::createNewPointerState(PointerDownEvent event) {
    return make<_DelayedPointerStateCls>(event->position, delay, event->kind, gestureSettings);
}

String DelayedMultiDragGestureRecognizerCls::debugDescription() {
    return __s("long multidrag");
}
