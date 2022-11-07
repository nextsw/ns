#include "multitap.hpp"
bool _CountdownZoned::timeout() {
    return _timeout;
}

_CountdownZoned::_CountdownZoned(Duration duration) {
    {
        assert(duration != nullptr);
    }
    {
        Timer(duration, _onTimeout);
    }
}

void _CountdownZoned::_onTimeout() {
    _timeout = true;
}

void _TapTracker::startTrackingPointer(PointerRoute route, Matrix4 transform) {
    if (!_isTrackingPointer) {
        _isTrackingPointer = true;
        GestureBinding.instance.pointerRouter.addRoute(pointer, route, transform);
    }
}

void _TapTracker::stopTrackingPointer(PointerRoute route) {
    if (_isTrackingPointer) {
        _isTrackingPointer = false;
        GestureBinding.instance.pointerRouter.removeRoute(pointer, route);
    }
}

bool _TapTracker::isWithinGlobalTolerance(PointerEvent event, double tolerance) {
    Offset offset = event.position - _initialGlobalPosition;
    return offset.distance <= tolerance;
}

bool _TapTracker::hasElapsedMinTime() {
    return _doubleTapMinTimeCountdown.timeout;
}

bool _TapTracker::hasSameButton(PointerDownEvent event) {
    return event.buttons == initialButtons;
}

_TapTracker::_TapTracker(Duration doubleTapMinTime, GestureArenaEntry entry, PointerDownEvent event, DeviceGestureSettings gestureSettings) {
    {
        assert(doubleTapMinTime != nullptr);
        assert(event != nullptr);
        assert(event.buttons != nullptr);
        pointer = event.pointer;
        _initialGlobalPosition = event.position;
        initialButtons = event.buttons;
        _doubleTapMinTimeCountdown = _CountdownZoned(doubleTapMinTime);
    }
}

bool DoubleTapGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    if (_firstTap == nullptr) {
        ;
    }
    return super.isPointerAllowed(event);
}

void DoubleTapGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    if (_firstTap != nullptr) {
        if (!_firstTap!.isWithinGlobalTolerance(event, kDoubleTapSlop)) {
            return;
        } else         {
            if (!_firstTap!.hasElapsedMinTime() || !_firstTap!.hasSameButton(event)) {
            _reset();
            return _trackTap(event);
        } else         {
            if (onDoubleTapDown != nullptr) {
            TapDownDetails details = TapDownDetails(event.position, event.localPosition, getKindForPointer(event.pointer));
            <void>invokeCallback("onDoubleTapDown", );
        }
;
        };
        }    }
    _trackTap(event);
}

void DoubleTapGestureRecognizer::acceptGesture(int pointer) {
}

void DoubleTapGestureRecognizer::rejectGesture(int pointer) {
    _TapTracker tracker = _trackers[pointer];
    if (tracker == nullptr && _firstTap != nullptr && _firstTap!.pointer == pointer) {
        tracker = _firstTap;
    }
    if (tracker != nullptr) {
        _reject(tracker);
    }
}

void DoubleTapGestureRecognizer::dispose() {
    _reset();
    super.dispose();
}

String DoubleTapGestureRecognizer::debugDescription() {
    return "double tap";
}

void DoubleTapGestureRecognizer::_trackTap(PointerDownEvent event) {
    _stopDoubleTapTimer();
    _TapTracker tracker = _TapTracker(event, GestureBinding.instance.gestureArena.add(event.pointer, this), kDoubleTapMinTime, gestureSettings);
    _trackers[event.pointer] = tracker;
    tracker.startTrackingPointer(_handleEvent, event.transform);
}

void DoubleTapGestureRecognizer::_handleEvent(PointerEvent event) {
    _TapTracker tracker = _trackers[event.pointer]!;
    if (event is PointerUpEvent) {
        if (_firstTap == nullptr) {
            _registerFirstTap(tracker);
        } else {
            _registerSecondTap(tracker);
        }
    } else     {
        if (event is PointerMoveEvent) {
        if (!tracker.isWithinGlobalTolerance(event, kDoubleTapTouchSlop)) {
            _reject(tracker);
        }
    } else     {
        if (event is PointerCancelEvent) {
        _reject(tracker);
    }
;
    };
    }}

void DoubleTapGestureRecognizer::_reject(_TapTracker tracker) {
    _trackers.remove(tracker.pointer);
    tracker.entry.resolve(GestureDisposition.rejected);
    _freezeTracker(tracker);
    if (_firstTap != nullptr) {
        if (tracker == _firstTap) {
            _reset();
        } else {
            _checkCancel();
            if (_trackers.isEmpty) {
                _reset();
            }
        }
    }
}

void DoubleTapGestureRecognizer::_reset() {
    _stopDoubleTapTimer();
    if (_firstTap != nullptr) {
        if (_trackers.isNotEmpty) {
            _checkCancel();
        }
        _TapTracker tracker = _firstTap!;
        _firstTap = nullptr;
        _reject(tracker);
        GestureBinding.instance.gestureArena.release(tracker.pointer);
    }
    _clearTrackers();
}

void DoubleTapGestureRecognizer::_registerFirstTap(_TapTracker tracker) {
    _startDoubleTapTimer();
    GestureBinding.instance.gestureArena.hold(tracker.pointer);
    _freezeTracker(tracker);
    _trackers.remove(tracker.pointer);
    _clearTrackers();
    _firstTap = tracker;
}

void DoubleTapGestureRecognizer::_registerSecondTap(_TapTracker tracker) {
    _firstTap!.entry.resolve(GestureDisposition.accepted);
    tracker.entry.resolve(GestureDisposition.accepted);
    _freezeTracker(tracker);
    _trackers.remove(tracker.pointer);
    _checkUp(tracker.initialButtons);
    _reset();
}

void DoubleTapGestureRecognizer::_clearTrackers() {
    _trackers.values.toList().forEach(_reject);
    assert(_trackers.isEmpty);
}

void DoubleTapGestureRecognizer::_freezeTracker(_TapTracker tracker) {
    tracker.stopTrackingPointer(_handleEvent);
}

void DoubleTapGestureRecognizer::_startDoubleTapTimer() {
    _doubleTapTimer = Timer(kDoubleTapTimeout, _reset);
}

void DoubleTapGestureRecognizer::_stopDoubleTapTimer() {
    if (_doubleTapTimer != nullptr) {
        _doubleTapTimer!.cancel();
        _doubleTapTimer = nullptr;
    }
}

void DoubleTapGestureRecognizer::_checkUp(int buttons) {
    assert(buttons == kPrimaryButton);
    if (onDoubleTap != nullptr) {
        <void>invokeCallback("onDoubleTap", onDoubleTap!);
    }
}

void DoubleTapGestureRecognizer::_checkCancel() {
    if (onDoubleTapCancel != nullptr) {
        <void>invokeCallback("onDoubleTapCancel", onDoubleTapCancel!);
    }
}

void _TapGesture::handleEvent(PointerEvent event) {
    assert(event.pointer == pointer);
    if (event is PointerMoveEvent) {
        if (!isWithinGlobalTolerance(event, computeHitSlop(event.kind, gestureSettings))) {
            cancel();
        } else {
            _lastPosition = OffsetPair.fromEventPosition(event);
        }
    } else     {
        if (event is PointerCancelEvent) {
        cancel();
    } else     {
        if (event is PointerUpEvent) {
        stopTrackingPointer(handleEvent);
        _finalPosition = OffsetPair.fromEventPosition(event);
        _check();
    }
;
    };
    }}

void _TapGesture::stopTrackingPointer(PointerRoute route) {
    _timer?.cancel();
    _timer = nullptr;
    super.stopTrackingPointer(route);
}

void _TapGesture::accept() {
    _wonArena = true;
    _check();
}

void _TapGesture::reject() {
    stopTrackingPointer(handleEvent);
    gestureRecognizer._dispatchCancel(pointer);
}

void _TapGesture::cancel() {
    if (_wonArena) {
        reject();
    } else {
        entry.resolve(GestureDisposition.rejected);
    }
}

_TapGesture::_TapGesture(PointerEvent event, MultiTapGestureRecognizer gestureRecognizer, Unknown, Duration longTapDelay) {
    {
        _lastPosition = OffsetPair.fromEventPosition(event);
        super((, GestureBinding.instance.gestureArena.add(event.pointer, gestureRecognizer), kDoubleTapMinTime);
    }
    {
        startTrackingPointer(handleEvent, event.transform);
        if (longTapDelay > Duration.zero) {
            _timer = Timer(longTapDelay, );
        }
    }
}

void _TapGesture::_check() {
    if (_wonArena && _finalPosition != nullptr) {
        gestureRecognizer._dispatchTap(pointer, _finalPosition!);
    }
}

void MultiTapGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    assert(!_gestureMap.containsKey(event.pointer));
    _gestureMap[event.pointer] = _TapGesture(this, event, longTapDelay, gestureSettings);
    if (onTapDown != nullptr) {
        <void>invokeCallback("onTapDown", );
    }
}

void MultiTapGestureRecognizer::acceptGesture(int pointer) {
    assert(_gestureMap.containsKey(pointer));
    _gestureMap[pointer]!.accept();
}

void MultiTapGestureRecognizer::rejectGesture(int pointer) {
    assert(_gestureMap.containsKey(pointer));
    _gestureMap[pointer]!.reject();
    assert(!_gestureMap.containsKey(pointer));
}

void MultiTapGestureRecognizer::dispose() {
    List<_TapGesture> localGestures = <_TapGesture>of(_gestureMap.values);
    for (_TapGesture gesture : localGestures) {
        gesture.cancel();
    }
    assert(_gestureMap.isEmpty);
    super.dispose();
}

String MultiTapGestureRecognizer::debugDescription() {
    return "multitap";
}

void MultiTapGestureRecognizer::_dispatchCancel(int pointer) {
    assert(_gestureMap.containsKey(pointer));
    _gestureMap.remove(pointer);
    if (onTapCancel != nullptr) {
        <void>invokeCallback("onTapCancel", );
    }
}

void MultiTapGestureRecognizer::_dispatchTap(int pointer, OffsetPair position) {
    assert(_gestureMap.containsKey(pointer));
    _gestureMap.remove(pointer);
    if (onTapUp != nullptr) {
        <void>invokeCallback("onTapUp", );
    }
    if (onTap != nullptr) {
        <void>invokeCallback("onTap", );
    }
}

void MultiTapGestureRecognizer::_dispatchLongTap(OffsetPair lastPosition, int pointer) {
    assert(_gestureMap.containsKey(pointer));
    if (onLongTapDown != nullptr) {
        <void>invokeCallback("onLongTapDown", );
    }
}

SerialTapDownDetails::SerialTapDownDetails(int buttons, int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(count > 0);
        localPosition = localPosition ?? globalPosition;
    }
}

SerialTapCancelDetails::SerialTapCancelDetails(int count) {
    {
        assert(count != nullptr);
        assert(count > 0);
    }
}

SerialTapUpDetails::SerialTapUpDetails(int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(count > 0);
        localPosition = localPosition ?? globalPosition;
    }
}

bool SerialTapGestureRecognizer::isTrackingPointer() {
    return _pendingTap != nullptr;
}

bool SerialTapGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    if (onSerialTapDown == nullptr && onSerialTapCancel == nullptr && onSerialTapUp == nullptr) {
        return false;
    }
    return super.isPointerAllowed(event);
}

void SerialTapGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    if ((_completedTaps.isNotEmpty && !_representsSameSeries(_completedTaps.last, event)) || _pendingTap != nullptr) {
        _reset();
    }
    _trackTap(event);
}

void SerialTapGestureRecognizer::acceptGesture(int pointer) {
    assert(_pendingTap != nullptr);
    assert(_pendingTap!.pointer == pointer);
    _gestureResolutions[pointer] = GestureDisposition.accepted;
}

void SerialTapGestureRecognizer::rejectGesture(int pointer) {
    _gestureResolutions[pointer] = GestureDisposition.rejected;
    _reset();
}

void SerialTapGestureRecognizer::dispose() {
    _reset();
    super.dispose();
}

String SerialTapGestureRecognizer::debugDescription() {
    return "serial tap";
}

bool SerialTapGestureRecognizer::_representsSameSeries(PointerDownEvent event, _TapTracker tap) {
    return tap.hasElapsedMinTime() && tap.hasSameButton(event) && tap.isWithinGlobalTolerance(event, kDoubleTapSlop);
}

void SerialTapGestureRecognizer::_trackTap(PointerDownEvent event) {
    _stopSerialTapTimer();
    if (onSerialTapDown != nullptr) {
        SerialTapDownDetails details = SerialTapDownDetails(event.position, event.localPosition, getKindForPointer(event.pointer), event.buttons, _completedTaps.length + 1);
        <void>invokeCallback("onSerialTapDown", );
    }
    _TapTracker tracker = _TapTracker(gestureSettings, event, GestureBinding.instance.gestureArena.add(event.pointer, this), kDoubleTapMinTime);
    assert(_pendingTap == nullptr);
    _pendingTap = tracker;
    tracker.startTrackingPointer(_handleEvent, event.transform);
}

void SerialTapGestureRecognizer::_handleEvent(PointerEvent event) {
    assert(_pendingTap != nullptr);
    assert(_pendingTap!.pointer == event.pointer);
    _TapTracker tracker = _pendingTap!;
    if (event is PointerUpEvent) {
        _registerTap(event, tracker);
    } else     {
        if (event is PointerMoveEvent) {
        if (!tracker.isWithinGlobalTolerance(event, kDoubleTapTouchSlop)) {
            _reset();
        }
    } else     {
        if (event is PointerCancelEvent) {
        _reset();
    }
;
    };
    }}

void SerialTapGestureRecognizer::_rejectPendingTap() {
    assert(_pendingTap != nullptr);
    _TapTracker tracker = _pendingTap!;
    _pendingTap = nullptr;
    _checkCancel(_completedTaps.length + 1);
    if (!_gestureResolutions.containsKey(tracker.pointer)) {
        tracker.entry.resolve(GestureDisposition.rejected);
    }
    _stopTrackingPointer(tracker);
}

void SerialTapGestureRecognizer::_reset() {
    if (_pendingTap != nullptr) {
        _rejectPendingTap();
    }
    _pendingTap = nullptr;
    _completedTaps.clear();
    _gestureResolutions.clear();
    _stopSerialTapTimer();
}

void SerialTapGestureRecognizer::_registerTap(PointerUpEvent event, _TapTracker tracker) {
    assert(tracker == _pendingTap);
    assert(tracker.pointer == event.pointer);
    _startSerialTapTimer();
    assert(_gestureResolutions[event.pointer] != GestureDisposition.rejected);
    if (!_gestureResolutions.containsKey(event.pointer)) {
        tracker.entry.resolve(GestureDisposition.accepted);
    }
    assert(_gestureResolutions[event.pointer] == GestureDisposition.accepted);
    _stopTrackingPointer(tracker);
    _pendingTap = nullptr;
    _checkUp(event, tracker);
    _completedTaps.add(tracker);
}

void SerialTapGestureRecognizer::_stopTrackingPointer(_TapTracker tracker) {
    tracker.stopTrackingPointer(_handleEvent);
}

void SerialTapGestureRecognizer::_startSerialTapTimer() {
    _serialTapTimer = Timer(kDoubleTapTimeout, _reset);
}

void SerialTapGestureRecognizer::_stopSerialTapTimer() {
    if (_serialTapTimer != nullptr) {
        _serialTapTimer!.cancel();
        _serialTapTimer = nullptr;
    }
}

void SerialTapGestureRecognizer::_checkUp(PointerUpEvent event, _TapTracker tracker) {
    if (onSerialTapUp != nullptr) {
        SerialTapUpDetails details = SerialTapUpDetails(event.position, event.localPosition, getKindForPointer(tracker.pointer), _completedTaps.length + 1);
        <void>invokeCallback("onSerialTapUp", );
    }
}

void SerialTapGestureRecognizer::_checkCancel(int count) {
    if (onSerialTapCancel != nullptr) {
        SerialTapCancelDetails details = SerialTapCancelDetails(count);
        <void>invokeCallback("onSerialTapCancel", );
    }
}
