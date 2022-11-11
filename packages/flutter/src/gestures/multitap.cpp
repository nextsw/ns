#include "multitap.hpp"
bool _CountdownZonedCls::timeout() {
    return _timeout;
}

_CountdownZonedCls::_CountdownZonedCls(Duration duration) {
    {
        assert(duration != nullptr);
    }
    {
        make<TimerCls>(duration, _onTimeout);
    }
}

void _CountdownZonedCls::_onTimeout() {
    _timeout = true;
}

void _TapTrackerCls::startTrackingPointer(PointerRoute route, Matrix4 transform) {
    if (!_isTrackingPointer) {
        _isTrackingPointer = true;
        GestureBindingCls::instance->pointerRouter->addRoute(pointer, route, transform);
    }
}

void _TapTrackerCls::stopTrackingPointer(PointerRoute route) {
    if (_isTrackingPointer) {
        _isTrackingPointer = false;
        GestureBindingCls::instance->pointerRouter->removeRoute(pointer, route);
    }
}

bool _TapTrackerCls::isWithinGlobalTolerance(PointerEvent event, double tolerance) {
    Offset offset = event->position - _initialGlobalPosition;
    return offset->distance() <= tolerance;
}

bool _TapTrackerCls::hasElapsedMinTime() {
    return _doubleTapMinTimeCountdown->timeout();
}

bool _TapTrackerCls::hasSameButton(PointerDownEvent event) {
    return event->buttons == initialButtons;
}

_TapTrackerCls::_TapTrackerCls(Duration doubleTapMinTime, GestureArenaEntry entry, PointerDownEvent event, DeviceGestureSettings gestureSettings) {
    {
        assert(doubleTapMinTime != nullptr);
        assert(event != nullptr);
        assert(event->buttons != nullptr);
        pointer = event->pointer;
        _initialGlobalPosition = event->position;
        initialButtons = event->buttons;
        _doubleTapMinTimeCountdown = make<_CountdownZonedCls>(doubleTapMinTime);
    }
}

bool DoubleTapGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    if (_firstTap == nullptr) {
        ;
    }
    return super->isPointerAllowed(event);
}

void DoubleTapGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    if (_firstTap != nullptr) {
        if (!_firstTap!->isWithinGlobalTolerance(event, kDoubleTapSlop)) {
            return;
        } else         {
            if (!_firstTap!->hasElapsedMinTime() || !_firstTap!->hasSameButton(event)) {
            _reset();
            return _trackTap(event);
        } else         {
            if (onDoubleTapDown != nullptr) {
            TapDownDetails details = make<TapDownDetailsCls>(event->position, event->localPosition, getKindForPointer(event->pointer));
            <void>invokeCallback(__s("onDoubleTapDown"), [=] ()             {
                onDoubleTapDown!(details);
            });
        }
;
        };
        }    }
    _trackTap(event);
}

void DoubleTapGestureRecognizerCls::acceptGesture(int pointer) {
}

void DoubleTapGestureRecognizerCls::rejectGesture(int pointer) {
    _TapTracker tracker = _trackers[pointer];
    if (tracker == nullptr && _firstTap != nullptr && _firstTap!->pointer == pointer) {
        tracker = _firstTap;
    }
    if (tracker != nullptr) {
        _reject(tracker);
    }
}

void DoubleTapGestureRecognizerCls::dispose() {
    _reset();
    super->dispose();
}

String DoubleTapGestureRecognizerCls::debugDescription() {
    return __s("double tap");
}

void DoubleTapGestureRecognizerCls::_trackTap(PointerDownEvent event) {
    _stopDoubleTapTimer();
    _TapTracker tracker = make<_TapTrackerCls>(event, GestureBindingCls::instance->gestureArena->add(event->pointer, this), kDoubleTapMinTime, gestureSettings);
    _trackers[event->pointer] = tracker;
    tracker->startTrackingPointer(_handleEvent, event->transform);
}

void DoubleTapGestureRecognizerCls::_handleEvent(PointerEvent event) {
    _TapTracker tracker = _trackers[event->pointer]!;
    if (is<PointerUpEvent>(event)) {
        if (_firstTap == nullptr) {
            _registerFirstTap(tracker);
        } else {
            _registerSecondTap(tracker);
        }
    } else     {
        if (is<PointerMoveEvent>(event)) {
        if (!tracker->isWithinGlobalTolerance(as<PointerMoveEventCls>(event), kDoubleTapTouchSlop)) {
            _reject(tracker);
        }
    } else     {
        if (is<PointerCancelEvent>(event)) {
        _reject(tracker);
    }
;
    };
    }}

void DoubleTapGestureRecognizerCls::_reject(_TapTracker tracker) {
    _trackers->remove(tracker->pointer);
    tracker->entry->resolve(GestureDispositionCls::rejected);
    _freezeTracker(tracker);
    if (_firstTap != nullptr) {
        if (tracker == _firstTap) {
            _reset();
        } else {
            _checkCancel();
            if (_trackers->isEmpty()) {
                _reset();
            }
        }
    }
}

void DoubleTapGestureRecognizerCls::_reset() {
    _stopDoubleTapTimer();
    if (_firstTap != nullptr) {
        if (_trackers->isNotEmpty()) {
            _checkCancel();
        }
        _TapTracker tracker = _firstTap!;
        _firstTap = nullptr;
        _reject(tracker);
        GestureBindingCls::instance->gestureArena->release(tracker->pointer);
    }
    _clearTrackers();
}

void DoubleTapGestureRecognizerCls::_registerFirstTap(_TapTracker tracker) {
    _startDoubleTapTimer();
    GestureBindingCls::instance->gestureArena->hold(tracker->pointer);
    _freezeTracker(tracker);
    _trackers->remove(tracker->pointer);
    _clearTrackers();
    _firstTap = tracker;
}

void DoubleTapGestureRecognizerCls::_registerSecondTap(_TapTracker tracker) {
    _firstTap!->entry->resolve(GestureDispositionCls::accepted);
    tracker->entry->resolve(GestureDispositionCls::accepted);
    _freezeTracker(tracker);
    _trackers->remove(tracker->pointer);
    _checkUp(tracker->initialButtons);
    _reset();
}

void DoubleTapGestureRecognizerCls::_clearTrackers() {
    _trackers->values()->toList()->forEach(_reject);
    assert(_trackers->isEmpty());
}

void DoubleTapGestureRecognizerCls::_freezeTracker(_TapTracker tracker) {
    tracker->stopTrackingPointer(_handleEvent);
}

void DoubleTapGestureRecognizerCls::_startDoubleTapTimer() {
    _doubleTapTimer |= make<TimerCls>(kDoubleTapTimeout, _reset);
}

void DoubleTapGestureRecognizerCls::_stopDoubleTapTimer() {
    if (_doubleTapTimer != nullptr) {
        _doubleTapTimer!->cancel();
        _doubleTapTimer = nullptr;
    }
}

void DoubleTapGestureRecognizerCls::_checkUp(int buttons) {
    assert(buttons == kPrimaryButton);
    if (onDoubleTap != nullptr) {
        <void>invokeCallback(__s("onDoubleTap"), onDoubleTap!);
    }
}

void DoubleTapGestureRecognizerCls::_checkCancel() {
    if (onDoubleTapCancel != nullptr) {
        <void>invokeCallback(__s("onDoubleTapCancel"), onDoubleTapCancel!);
    }
}

void _TapGestureCls::handleEvent(PointerEvent event) {
    assert(event->pointer == pointer);
    if (is<PointerMoveEvent>(event)) {
        if (!isWithinGlobalTolerance(as<PointerMoveEventCls>(event), computeHitSlop(as<PointerMoveEventCls>(event)->kind, gestureSettings))) {
            cancel();
        } else {
            _lastPosition = OffsetPairCls->fromEventPosition(event);
        }
    } else     {
        if (is<PointerCancelEvent>(event)) {
        cancel();
    } else     {
        if (is<PointerUpEvent>(event)) {
        stopTrackingPointer(handleEvent);
        _finalPosition = OffsetPairCls->fromEventPosition(as<PointerUpEventCls>(event));
        _check();
    }
;
    };
    }}

void _TapGestureCls::stopTrackingPointer(PointerRoute route) {
    _timer?->cancel();
    _timer = nullptr;
    super->stopTrackingPointer(route);
}

void _TapGestureCls::accept() {
    _wonArena = true;
    _check();
}

void _TapGestureCls::reject() {
    stopTrackingPointer(handleEvent);
    gestureRecognizer->_dispatchCancel(pointer);
}

void _TapGestureCls::cancel() {
    if (_wonArena) {
        reject();
    } else {
        entry->resolve(GestureDispositionCls::rejected);
    }
}

_TapGestureCls::_TapGestureCls(PointerEvent event, MultiTapGestureRecognizer gestureRecognizer, Unknown gestureSettings, Duration longTapDelay) : _TapTracker(as<PointerDownEvent>(event), GestureBindingCls::instance->gestureArena->add(event->pointer, gestureRecognizer), kDoubleTapMinTime) {
    {
        _lastPosition = OffsetPairCls->fromEventPosition(event);
    }
    {
        startTrackingPointer(handleEvent, event->transform);
        if (longTapDelay > DurationCls::zero) {
            _timer = make<TimerCls>(longTapDelay, [=] () {
                _timer = nullptr;
                gestureRecognizer->_dispatchLongTap(event->pointer, _lastPosition);
            });
        }
    }
}

void _TapGestureCls::_check() {
    if (_wonArena && _finalPosition != nullptr) {
        gestureRecognizer->_dispatchTap(pointer, _finalPosition!);
    }
}

void MultiTapGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    assert(!_gestureMap->containsKey(event->pointer));
    _gestureMap[event->pointer] = make<_TapGestureCls>(this, event, longTapDelay, gestureSettings);
    if (onTapDown != nullptr) {
        <void>invokeCallback(__s("onTapDown"), [=] () {
            onTapDown!(event->pointer, make<TapDownDetailsCls>(event->position, event->localPosition, event->kind));
        });
    }
}

void MultiTapGestureRecognizerCls::acceptGesture(int pointer) {
    assert(_gestureMap->containsKey(pointer));
    _gestureMap[pointer]!->accept();
}

void MultiTapGestureRecognizerCls::rejectGesture(int pointer) {
    assert(_gestureMap->containsKey(pointer));
    _gestureMap[pointer]!->reject();
    assert(!_gestureMap->containsKey(pointer));
}

void MultiTapGestureRecognizerCls::dispose() {
    List<_TapGesture> localGestures = <_TapGesture>of(_gestureMap->values());
    for (_TapGesture gesture : localGestures) {
        gesture->cancel();
    }
    assert(_gestureMap->isEmpty());
    super->dispose();
}

String MultiTapGestureRecognizerCls::debugDescription() {
    return __s("multitap");
}

void MultiTapGestureRecognizerCls::_dispatchCancel(int pointer) {
    assert(_gestureMap->containsKey(pointer));
    _gestureMap->remove(pointer);
    if (onTapCancel != nullptr) {
        <void>invokeCallback(__s("onTapCancel"), [=] ()         {
            onTapCancel!(pointer);
        });
    }
}

void MultiTapGestureRecognizerCls::_dispatchTap(int pointer, OffsetPair position) {
    assert(_gestureMap->containsKey(pointer));
    _gestureMap->remove(pointer);
    if (onTapUp != nullptr) {
        <void>invokeCallback(__s("onTapUp"), [=] () {
            onTapUp!(pointer, make<TapUpDetailsCls>(getKindForPointer(pointer), position->local, position->global));
        });
    }
    if (onTap != nullptr) {
        <void>invokeCallback(__s("onTap"), [=] ()         {
            onTap!(pointer);
        });
    }
}

void MultiTapGestureRecognizerCls::_dispatchLongTap(int pointer, OffsetPair lastPosition) {
    assert(_gestureMap->containsKey(pointer));
    if (onLongTapDown != nullptr) {
        <void>invokeCallback(__s("onLongTapDown"), [=] () {
            onLongTapDown!(pointer, make<TapDownDetailsCls>(lastPosition->global, lastPosition->local, getKindForPointer(pointer)));
        });
    }
}

SerialTapDownDetailsCls::SerialTapDownDetailsCls(int buttons, int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(count > 0);
        localPosition = localPosition | globalPosition;
    }
}

SerialTapCancelDetailsCls::SerialTapCancelDetailsCls(int count) {
    {
        assert(count != nullptr);
        assert(count > 0);
    }
}

SerialTapUpDetailsCls::SerialTapUpDetailsCls(int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(count > 0);
        localPosition = localPosition | globalPosition;
    }
}

bool SerialTapGestureRecognizerCls::isTrackingPointer() {
    return _pendingTap != nullptr;
}

bool SerialTapGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    if (onSerialTapDown == nullptr && onSerialTapCancel == nullptr && onSerialTapUp == nullptr) {
        return false;
    }
    return super->isPointerAllowed(event);
}

void SerialTapGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    if ((_completedTaps->isNotEmpty && !_representsSameSeries(_completedTaps->last, event)) || _pendingTap != nullptr) {
        _reset();
    }
    _trackTap(event);
}

void SerialTapGestureRecognizerCls::acceptGesture(int pointer) {
    assert(_pendingTap != nullptr);
    assert(_pendingTap!->pointer == pointer);
    _gestureResolutions[pointer] = GestureDispositionCls::accepted;
}

void SerialTapGestureRecognizerCls::rejectGesture(int pointer) {
    _gestureResolutions[pointer] = GestureDispositionCls::rejected;
    _reset();
}

void SerialTapGestureRecognizerCls::dispose() {
    _reset();
    super->dispose();
}

String SerialTapGestureRecognizerCls::debugDescription() {
    return __s("serial tap");
}

bool SerialTapGestureRecognizerCls::_representsSameSeries(_TapTracker tap, PointerDownEvent event) {
    return tap->hasElapsedMinTime() && tap->hasSameButton(event) && tap->isWithinGlobalTolerance(event, kDoubleTapSlop);
}

void SerialTapGestureRecognizerCls::_trackTap(PointerDownEvent event) {
    _stopSerialTapTimer();
    if (onSerialTapDown != nullptr) {
        SerialTapDownDetails details = make<SerialTapDownDetailsCls>(event->position, event->localPosition, getKindForPointer(event->pointer), event->buttons, _completedTaps->length() + 1);
        <void>invokeCallback(__s("onSerialTapDown"), [=] ()         {
            onSerialTapDown!(details);
        });
    }
    _TapTracker tracker = make<_TapTrackerCls>(gestureSettings, event, GestureBindingCls::instance->gestureArena->add(event->pointer, this), kDoubleTapMinTime);
    assert(_pendingTap == nullptr);
    _pendingTap = tracker;
    tracker->startTrackingPointer(_handleEvent, event->transform);
}

void SerialTapGestureRecognizerCls::_handleEvent(PointerEvent event) {
    assert(_pendingTap != nullptr);
    assert(_pendingTap!->pointer == event->pointer);
    _TapTracker tracker = _pendingTap!;
    if (is<PointerUpEvent>(event)) {
        _registerTap(as<PointerUpEventCls>(event), tracker);
    } else     {
        if (is<PointerMoveEvent>(event)) {
        if (!tracker->isWithinGlobalTolerance(as<PointerMoveEventCls>(event), kDoubleTapTouchSlop)) {
            _reset();
        }
    } else     {
        if (is<PointerCancelEvent>(event)) {
        _reset();
    }
;
    };
    }}

void SerialTapGestureRecognizerCls::_rejectPendingTap() {
    assert(_pendingTap != nullptr);
    _TapTracker tracker = _pendingTap!;
    _pendingTap = nullptr;
    _checkCancel(_completedTaps->length() + 1);
    if (!_gestureResolutions->containsKey(tracker->pointer)) {
        tracker->entry->resolve(GestureDispositionCls::rejected);
    }
    _stopTrackingPointer(tracker);
}

void SerialTapGestureRecognizerCls::_reset() {
    if (_pendingTap != nullptr) {
        _rejectPendingTap();
    }
    _pendingTap = nullptr;
    _completedTaps->clear();
    _gestureResolutions->clear();
    _stopSerialTapTimer();
}

void SerialTapGestureRecognizerCls::_registerTap(PointerUpEvent event, _TapTracker tracker) {
    assert(tracker == _pendingTap);
    assert(tracker->pointer == event->pointer);
    _startSerialTapTimer();
    assert(_gestureResolutions[event->pointer] != GestureDispositionCls::rejected);
    if (!_gestureResolutions->containsKey(event->pointer)) {
        tracker->entry->resolve(GestureDispositionCls::accepted);
    }
    assert(_gestureResolutions[event->pointer] == GestureDispositionCls::accepted);
    _stopTrackingPointer(tracker);
    _pendingTap = nullptr;
    _checkUp(event, tracker);
    _completedTaps->add(tracker);
}

void SerialTapGestureRecognizerCls::_stopTrackingPointer(_TapTracker tracker) {
    tracker->stopTrackingPointer(_handleEvent);
}

void SerialTapGestureRecognizerCls::_startSerialTapTimer() {
    _serialTapTimer |= make<TimerCls>(kDoubleTapTimeout, _reset);
}

void SerialTapGestureRecognizerCls::_stopSerialTapTimer() {
    if (_serialTapTimer != nullptr) {
        _serialTapTimer!->cancel();
        _serialTapTimer = nullptr;
    }
}

void SerialTapGestureRecognizerCls::_checkUp(PointerUpEvent event, _TapTracker tracker) {
    if (onSerialTapUp != nullptr) {
        SerialTapUpDetails details = make<SerialTapUpDetailsCls>(event->position, event->localPosition, getKindForPointer(tracker->pointer), _completedTaps->length() + 1);
        <void>invokeCallback(__s("onSerialTapUp"), [=] ()         {
            onSerialTapUp!(details);
        });
    }
}

void SerialTapGestureRecognizerCls::_checkCancel(int count) {
    if (onSerialTapCancel != nullptr) {
        SerialTapCancelDetails details = make<SerialTapCancelDetailsCls>(count);
        <void>invokeCallback(__s("onSerialTapCancel"), [=] ()         {
            onSerialTapCancel!(details);
        });
    }
}
