#include "binding.hpp"
DateTime SamplingClock::now() {
    return DateTime.now();
}

Stopwatch SamplingClock::stopwatch() {
    return Stopwatch();
}

void _Resampler::addOrDispatch(PointerEvent event) {
    SchedulerBinding scheduler = SchedulerBinding.instance;
    assert(scheduler != nullptr);
    if (event.kind == PointerDeviceKind.touch) {
        _lastEventTime = event.timeStamp;
        PointerEventResampler resampler = _resamplers.putIfAbsent(event.device, );
        resampler.addEvent(event);
    } else {
        _handlePointerEvent(event);
    }
}

void _Resampler::sample(SamplingClock clock, Duration samplingOffset) {
    SchedulerBinding scheduler = SchedulerBinding.instance;
    assert(scheduler != nullptr);
    if (_frameTime == Duration.zero) {
        _frameTime = Duration(clock.now().millisecondsSinceEpoch);
        _frameTimeAge = ;
    }
    if (_timer?.isActive != true) {
        _timer = Timer.periodic(_samplingInterval, );
    }
    int samplingIntervalUs = _samplingInterval.inMicroseconds;
    int elapsedIntervals = _frameTimeAge.elapsedMicroseconds ~/ samplingIntervalUs;
    int elapsedUs = elapsedIntervals * samplingIntervalUs;
    Duration frameTime = _frameTime + Duration(elapsedUs);
    Duration sampleTime = frameTime + samplingOffset;
    Duration nextSampleTime = sampleTime + _samplingInterval;
    for (PointerEventResampler resampler : _resamplers.values) {
        resampler.sample(sampleTime, nextSampleTime, _handlePointerEvent);
    }
    _resamplers.removeWhere();
    _lastSampleTime = sampleTime;
    if (_resamplers.isEmpty) {
        _timer!.cancel();
        return;
    }
    if (!_frameCallbackScheduled) {
        _frameCallbackScheduled = true;
        scheduler.addPostFrameCallback();
    }
}

void _Resampler::stop() {
    for (PointerEventResampler resampler : _resamplers.values) {
        resampler.stop(_handlePointerEvent);
    }
    _resamplers.clear();
    _frameTime = Duration.zero;
    _timer?.cancel();
}

void _Resampler::_onSampleTimeChanged() {
    assert(());
    _handleSampleTimeChanged();
}

void GestureBinding::initInstances() {
    super.initInstances();
    _instance = this;
    platformDispatcher.onPointerDataPacket = _handlePointerDataPacket;
}

GestureBinding GestureBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

void GestureBinding::unlocked() {
    super.unlocked();
    _flushPointerEventQueue();
}

void GestureBinding::cancelPointer(int pointer) {
    if (_pendingPointerEvents.isEmpty && !locked) {
        scheduleMicrotask(_flushPointerEventQueue);
    }
    _pendingPointerEvents.addFirst(PointerCancelEvent(pointer));
}

void GestureBinding::handlePointerEvent(PointerEvent event) {
    assert(!locked);
    if (resamplingEnabled) {
        _resampler.addOrDispatch(event);
        _resampler.sample(samplingOffset, _samplingClock);
        return;
    }
    _resampler.stop();
    _handlePointerEventImmediately(event);
}

void GestureBinding::hitTest(Offset position, HitTestResult result) {
    result.add(HitTestEntry(this));
}

void GestureBinding::dispatchEvent(PointerEvent event, HitTestResult hitTestResult) {
    assert(!locked);
    if (hitTestResult == nullptr) {
        assert(event is PointerAddedEvent || event is PointerRemovedEvent);
        ;
        return;
    }
    for (HitTestEntry entry : hitTestResult.path) {
        ;
    }
}

void GestureBinding::handleEvent(HitTestEntry entry, PointerEvent event) {
    pointerRouter.route(event);
    if (event is PointerDownEvent || event is PointerPanZoomStartEvent) {
        gestureArena.close(event.pointer);
    } else     {
        if (event is PointerUpEvent || event is PointerPanZoomEndEvent) {
        gestureArena.sweep(event.pointer);
    } else     {
        if (event is PointerSignalEvent) {
        pointerSignalResolver.resolve(event);
    }
;
    };
    }}

void GestureBinding::resetGestureBinding() {
    _hitTests.clear();
}

SamplingClock GestureBinding::debugSamplingClock() {
    return nullptr;
}

void GestureBinding::_handlePointerDataPacket(PointerDataPacket packet) {
    _pendingPointerEvents.addAll(PointerEventConverter.expand(packet.data, window.devicePixelRatio));
    if (!locked) {
        _flushPointerEventQueue();
    }
}

void GestureBinding::_flushPointerEventQueue() {
    assert(!locked);
    while (_pendingPointerEvents.isNotEmpty) {
        handlePointerEvent(_pendingPointerEvents.removeFirst());
    }
}

void GestureBinding::_handlePointerEventImmediately(PointerEvent event) {
    HitTestResult hitTestResult;
    if (event is PointerDownEvent || event is PointerSignalEvent || event is PointerHoverEvent || event is PointerPanZoomStartEvent) {
        assert(!_hitTests.containsKey(event.pointer));
        hitTestResult = HitTestResult();
        hitTest(hitTestResult, event.position);
        if (event is PointerDownEvent || event is PointerPanZoomStartEvent) {
            _hitTests[event.pointer] = hitTestResult;
        }
        assert(());
    } else     {
        if (event is PointerUpEvent || event is PointerCancelEvent || event is PointerPanZoomEndEvent) {
        hitTestResult = _hitTests.remove(event.pointer);
    } else     {
        if (event.down || event is PointerPanZoomUpdateEvent) {
        hitTestResult = _hitTests[event.pointer];
    }
;
    };
    }    assert(());
    if (hitTestResult != nullptr || event is PointerAddedEvent || event is PointerRemovedEvent) {
        assert(event.position != nullptr);
        dispatchEvent(event, hitTestResult);
    }
}

void GestureBinding::_handleSampleTimeChanged() {
    if (!locked) {
        if (resamplingEnabled) {
            _resampler.sample(samplingOffset, _samplingClock);
        } else {
            _resampler.stop();
        }
    }
}

SamplingClock GestureBinding::_samplingClock() {
    SamplingClock value = SamplingClock();
    assert(());
    return value;
}
