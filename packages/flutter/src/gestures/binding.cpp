#include "binding.hpp"
DateTime SamplingClockCls::now() {
    return DateTimeCls->now();
}

Stopwatch SamplingClockCls::stopwatch() {
    return make<StopwatchCls>();
}

void _ResamplerCls::addOrDispatch(PointerEvent event) {
    SchedulerBinding scheduler = SchedulerBindingCls::instance;
    assert(scheduler != nullptr);
    if (event->kind == PointerDeviceKindCls::touch) {
        _lastEventTime = event->timeStamp;
        PointerEventResampler resampler = _resamplers->putIfAbsent(event->device, [=] () {
    make<PointerEventResamplerCls>();
});
        resampler->addEvent(event);
    } else {
        _handlePointerEvent(event);
    }
}

void _ResamplerCls::sample(Duration samplingOffset, SamplingClock clock) {
    SchedulerBinding scheduler = SchedulerBindingCls::instance;
    assert(scheduler != nullptr);
    if (_frameTime == DurationCls::zero) {
        _frameTime = make<DurationCls>(clock->now()->millisecondsSinceEpoch);
            auto _c1 = clock->stopwatch();    _c1.start();_frameTimeAge = _c1;
    }
    if (_timer?->isActive() != true) {
        _timer = TimerCls->periodic(_samplingInterval, [=] () {
            _onSampleTimeChanged();
        });
    }
    int samplingIntervalUs = _samplingInterval->inMicroseconds();
    int elapsedIntervals = _frameTimeAge->elapsedMicroseconds() ~/ samplingIntervalUs;
    int elapsedUs = elapsedIntervals * samplingIntervalUs;
    Duration frameTime = _frameTime + make<DurationCls>(elapsedUs);
    Duration sampleTime = frameTime + samplingOffset;
    Duration nextSampleTime = sampleTime + _samplingInterval;
    for (PointerEventResampler resampler : _resamplers->values()) {
        resampler->sample(sampleTime, nextSampleTime, _handlePointerEvent);
    }
    _resamplers->removeWhere([=] (int key,PointerEventResampler resampler) {
        return !resampler->hasPendingEvents && !resampler->isDown;
    });
    _lastSampleTime = sampleTime;
    if (_resamplers->isEmpty()) {
        _timer!->cancel();
        return;
    }
    if (!_frameCallbackScheduled) {
        _frameCallbackScheduled = true;
        scheduler->addPostFrameCallback([=] () {
            _frameCallbackScheduled = false;
            _frameTime = scheduler->currentSystemFrameTimeStamp();
            _frameTimeAge->reset();
            _timer?->cancel();
            _timer = TimerCls->periodic(_samplingInterval, [=] () {
                _onSampleTimeChanged();
            });
            _onSampleTimeChanged();
        });
    }
}

void _ResamplerCls::stop() {
    for (PointerEventResampler resampler : _resamplers->values()) {
        resampler->stop(_handlePointerEvent);
    }
    _resamplers->clear();
    _frameTime = DurationCls::zero;
    _timer?->cancel();
}

void _ResamplerCls::_onSampleTimeChanged() {
    assert([=] () {
        if (debugPrintResamplingMargin) {
            Duration resamplingMargin = _lastEventTime - _lastSampleTime;
            debugPrint(__s("$resamplingMargin"));
        }
        return true;
    }());
    _handleSampleTimeChanged();
}

void GestureBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    platformDispatcher->onPointerDataPacket = _handlePointerDataPacket;
}

GestureBinding GestureBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

void GestureBindingCls::unlocked() {
    super->unlocked();
    _flushPointerEventQueue();
}

void GestureBindingCls::cancelPointer(int pointer) {
    if (_pendingPointerEvents->isEmpty() && !locked) {
        scheduleMicrotask(_flushPointerEventQueue);
    }
    _pendingPointerEvents->addFirst(make<PointerCancelEventCls>(pointer));
}

void GestureBindingCls::handlePointerEvent(PointerEvent event) {
    assert(!locked);
    if (resamplingEnabled) {
        _resampler->addOrDispatch(event);
        _resampler->sample(samplingOffset, _samplingClock());
        return;
    }
    _resampler->stop();
    _handlePointerEventImmediately(event);
}

void GestureBindingCls::hitTest(HitTestResult result, Offset position) {
    result->add(make<HitTestEntryCls>(this));
}

void GestureBindingCls::dispatchEvent(PointerEvent event, HitTestResult hitTestResult) {
    assert(!locked);
    if (hitTestResult == nullptr) {
        assert(is<PointerAddedEvent>(event) || is<PointerRemovedEvent>(event));
        try {
            pointerRouter->route(event);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsForPointerEventDispatcherCls>(exception, stack, __s("gesture library"), make<ErrorDescriptionCls>(__s("while dispatching a non-hit-tested pointer event")), event, [=] () {
                makeList(ArrayItem);
            }));
        };
        return;
    }
    for (HitTestEntry entry : hitTestResult->path()) {
        try {
            entry->target->handleEvent(event->transformed(entry->transform), entry);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsForPointerEventDispatcherCls>(exception, stack, __s("gesture library"), make<ErrorDescriptionCls>(__s("while dispatching a pointer event")), event, entry, [=] () {
                makeList(ArrayItem, ArrayItem);
            }));
        };
    }
}

void GestureBindingCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    pointerRouter->route(event);
    if (is<PointerDownEvent>(event) || is<PointerPanZoomStartEvent>(event)) {
        gestureArena->close(event->pointer);
    } else {
        if (is<PointerUpEvent>(event) || is<PointerPanZoomEndEvent>(event)) {
        gestureArena->sweep(event->pointer);
    } else {
        if (is<PointerSignalEvent>(event)) {
        pointerSignalResolver->resolve(as<PointerSignalEventCls>(event));
    }
;
    };
    }}

void GestureBindingCls::resetGestureBinding() {
    _hitTests->clear();
}

SamplingClock GestureBindingCls::debugSamplingClock() {
    return nullptr;
}

void GestureBindingCls::_handlePointerDataPacket(PointerDataPacket packet) {
    _pendingPointerEvents->addAll(PointerEventConverterCls->expand(packet->data, window->devicePixelRatio));
    if (!locked) {
        _flushPointerEventQueue();
    }
}

void GestureBindingCls::_flushPointerEventQueue() {
    assert(!locked);
    while (_pendingPointerEvents->isNotEmpty()) {
        handlePointerEvent(_pendingPointerEvents->removeFirst());
    }
}

void GestureBindingCls::_handlePointerEventImmediately(PointerEvent event) {
    HitTestResult hitTestResult;
    if (is<PointerDownEvent>(event) || is<PointerSignalEvent>(event) || is<PointerHoverEvent>(event) || is<PointerPanZoomStartEvent>(event)) {
        assert(!_hitTests->containsKey(event->pointer));
        hitTestResult = make<HitTestResultCls>();
        hitTest(hitTestResult, event->position);
        if (is<PointerDownEvent>(event) || is<PointerPanZoomStartEvent>(event)) {
            _hitTests[event->pointer] = hitTestResult;
        }
        assert([=] () {
            if (debugPrintHitTestResults) {
                debugPrint(__s("$event: $hitTestResult"));
            }
            return true;
        }());
    } else {
        if (is<PointerUpEvent>(event) || is<PointerCancelEvent>(event) || is<PointerPanZoomEndEvent>(event)) {
        hitTestResult = _hitTests->remove(event->pointer);
    } else {
        if (event->down || is<PointerPanZoomUpdateEvent>(event)) {
        hitTestResult = _hitTests[event->pointer];
    }
;
    };
    }    assert([=] () {
        if (debugPrintMouseHoverEvents && is<PointerHoverEvent>(event)) {
            debugPrint(__s("$event"));
        }
        return true;
    }());
    if (hitTestResult != nullptr || is<PointerAddedEvent>(event) || is<PointerRemovedEvent>(event)) {
        assert(event->position != nullptr);
        dispatchEvent(event, hitTestResult);
    }
}

void GestureBindingCls::_handleSampleTimeChanged() {
    if (!locked) {
        if (resamplingEnabled) {
            _resampler->sample(samplingOffset, _samplingClock());
        } else {
            _resampler->stop();
        }
    }
}

SamplingClock GestureBindingCls::_samplingClock() {
    SamplingClock value = make<SamplingClockCls>();
    assert([=] () {
        SamplingClock debugValue = debugSamplingClock();
        if (debugValue != nullptr) {
            value = debugValue;
        }
        return true;
    }());
    return value;
}
