#include "binding.hpp"
double timeDilation() {
    return _timeDilation;
}

void timeDilation(double value) {
    assert(value > 0.0);
    if (_timeDilation == value) {
        return;
    }
    SchedulerBindingCls::_instance?->resetEpoch();
    _timeDilation = value;
}

template<typename T>
void _TaskEntryCls<T>::run() {
    if (!kReleaseMode) {
        TimelineCls->timeSync(debugLabel | __s("Scheduled Task"), [=] () {
            completer->complete(task());
        }, flow != nullptr? FlowCls->step(flow!->id) : nullptr);
    } else {
        completer->complete(task());
    }
}

template<typename T>
_TaskEntryCls<T>::_TaskEntryCls(TaskCallback<T> task, int priority, String debugLabel, Flow flow) {
    {
        assert([=] () {
            debugStack = StackTraceCls::current;
            return true;
        }());
    }
}

_FrameCallbackEntryCls::_FrameCallbackEntryCls(FrameCallback callback, bool rescheduling) {
    {
        assert([=] () {
            if (rescheduling) {
                assert([=] () {
                    if (debugCurrentCallbackStack == nullptr) {
                        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
                    }
                    return true;
                }());
                debugStack = debugCurrentCallbackStack;
            } else {
                debugStack = StackTraceCls::current;
            }
            return true;
        }());
    }
}

void SchedulerBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    if (!kReleaseMode) {
        addTimingsCallback([=] (List<FrameTiming> timings) {
            timings->forEach(_profileFramePostEvent);
        });
    }
}

SchedulerBinding SchedulerBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

void SchedulerBindingCls::addTimingsCallback(TimingsCallback callback) {
    _timingsCallbacks->add(callback);
    if (_timingsCallbacks->length() == 1) {
        assert(platformDispatcher->onReportTimings == nullptr);
        platformDispatcher->onReportTimings = _executeTimingsCallbacks;
    }
    assert(platformDispatcher->onReportTimings == _executeTimingsCallbacks);
}

void SchedulerBindingCls::removeTimingsCallback(TimingsCallback callback) {
    assert(_timingsCallbacks->contains(callback));
    _timingsCallbacks->remove(callback);
    if (_timingsCallbacks->isEmpty()) {
        platformDispatcher->onReportTimings = nullptr;
    }
}

void SchedulerBindingCls::initServiceExtensions() {
    super->initServiceExtensions();
    if (!kReleaseMode) {
        registerNumericServiceExtension(__s("timeDilation"), [=] () {
            timeDilation;
        }, [=] (double value) {
            timeDilation = value;
        });
    }
}

AppLifecycleState SchedulerBindingCls::lifecycleState() {
    return _lifecycleState;
}

void SchedulerBindingCls::handleAppLifecycleStateChanged(AppLifecycleState state) {
    assert(state != nullptr);
    _lifecycleState = state;
    ;
}

template<typename T>
Future<T> SchedulerBindingCls::scheduleTask(TaskCallback<T> task, Priority priority, String debugLabel, Flow flow) {
    bool isFirstTask = _taskQueue->isEmpty();
    _TaskEntry<T> entry = <T>make<_TaskEntryCls>(task, priority->value(), debugLabel, flow);
    _taskQueue->add(entry);
    if (isFirstTask && !locked) {
        _ensureEventLoopCallback();
    }
    return entry->completer->future();
}

void SchedulerBindingCls::unlocked() {
    super->unlocked();
    if (_taskQueue->isNotEmpty()) {
        _ensureEventLoopCallback();
    }
}

bool SchedulerBindingCls::handleEventLoopCallback() {
    if (_taskQueue->isEmpty() || locked) {
        return false;
    }
    _TaskEntry<Object> entry = _taskQueue->first();
    if (schedulingStrategy(entry->priority, this)) {
        try {
            _taskQueue->removeFirst();
            entry->run();
        } catch (Unknown exception) {
            StackTrace callbackStack;
            assert([=] () {
                callbackStack = entry->debugStack;
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, exceptionStack, __s("scheduler library"), make<ErrorDescriptionCls>(__s("during a task callback")), (callbackStack == nullptr)? nullptr : [=] () {
                return makeList(ArrayItem);
            }));
        };
        return _taskQueue->isNotEmpty();
    }
    return false;
}

int SchedulerBindingCls::transientCallbackCount() {
    return _transientCallbacks->length();
}

int SchedulerBindingCls::scheduleFrameCallback(FrameCallback callback, bool rescheduling) {
    scheduleFrame();
    _nextFrameCallbackId += 1;
    _transientCallbacks[_nextFrameCallbackId] = make<_FrameCallbackEntryCls>(callback, rescheduling);
    return _nextFrameCallbackId;
}

void SchedulerBindingCls::cancelFrameCallbackWithId(int id) {
    assert(id > 0);
    _transientCallbacks->remove(id);
    _removedIds->add(id);
}

bool SchedulerBindingCls::debugAssertNoTransientCallbacks(String reason) {
    assert([=] () {
        if (transientCallbackCount() > 0) {
            int count = transientCallbackCount();
            Map<int, _FrameCallbackEntry> callbacks = <int, _FrameCallbackEntry>of(_transientCallbacks);
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        if (count == 1) {            list1.add(ArrayItem);        } else {            list1.add(ArrayItem);        }for (int id : callbacks->keys()) {                        ;                    }        {            list1.add(ArrayItem);        }FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(reason, __s("scheduler library"), [=] () {
                list1;
            }));
        }
        return true;
    }());
    return true;
}

void SchedulerBindingCls::debugPrintTransientCallbackRegistrationStack() {
    assert([=] () {
        if (_FrameCallbackEntryCls::debugCurrentCallbackStack != nullptr) {
            debugPrint(__s("When the current transient callback was registered, this was the stack:"));
            debugPrint(FlutterErrorCls->defaultStackFilter(FlutterErrorCls->demangleStackTrace(_FrameCallbackEntryCls::debugCurrentCallbackStack!)->toString()->trimRight()->split(__s("\n")))->join(__s("\n")));
        } else {
            debugPrint(__s("No transient callback is currently executing."));
        }
        return true;
    }());
}

void SchedulerBindingCls::addPersistentFrameCallback(FrameCallback callback) {
    _persistentCallbacks->add(callback);
}

void SchedulerBindingCls::addPostFrameCallback(FrameCallback callback) {
    _postFrameCallbacks->add(callback);
}

Future<void> SchedulerBindingCls::endOfFrame() {
    if (_nextFrameCompleter == nullptr) {
        if (schedulerPhase() == SchedulerPhaseCls::idle) {
            scheduleFrame();
        }
        _nextFrameCompleter = <void>make<CompleterCls>();
        addPostFrameCallback([=] (Duration timeStamp) {
            _nextFrameCompleter!->complete();
            _nextFrameCompleter = nullptr;
        });
    }
    return _nextFrameCompleter!->future();
}

bool SchedulerBindingCls::hasScheduledFrame() {
    return _hasScheduledFrame;
}

SchedulerPhase SchedulerBindingCls::schedulerPhase() {
    return _schedulerPhase;
}

bool SchedulerBindingCls::framesEnabled() {
    return _framesEnabled;
}

void SchedulerBindingCls::ensureFrameCallbacksRegistered() {
    platformDispatcher->onBeginFrame |= _handleBeginFrame;
    platformDispatcher->onDrawFrame |= _handleDrawFrame;
}

void SchedulerBindingCls::ensureVisualUpdate() {
    ;
}

void SchedulerBindingCls::scheduleFrame() {
    if (_hasScheduledFrame || !framesEnabled()) {
        return;
    }
    assert([=] () {
        if (debugPrintScheduleFrameStacks) {
            debugPrintStack(__sf("scheduleFrame() called. Current phase is %s.", schedulerPhase()));
        }
        return true;
    }());
    ensureFrameCallbacksRegistered();
    platformDispatcher->scheduleFrame();
    _hasScheduledFrame = true;
}

void SchedulerBindingCls::scheduleForcedFrame() {
    if (_hasScheduledFrame) {
        return;
    }
    assert([=] () {
        if (debugPrintScheduleFrameStacks) {
            debugPrintStack(__sf("scheduleForcedFrame() called. Current phase is %s.", schedulerPhase()));
        }
        return true;
    }());
    ensureFrameCallbacksRegistered();
    platformDispatcher->scheduleFrame();
    _hasScheduledFrame = true;
}

void SchedulerBindingCls::scheduleWarmUpFrame() {
    if (_warmUpFrame || schedulerPhase() != SchedulerPhaseCls::idle) {
        return;
    }
    _warmUpFrame = true;
    auto _c1 = make<TimelineTaskCls>();_c1.start(__s("Warm-up frame"));TimelineTask timelineTask = _c1;
    bool hadScheduledFrame = _hasScheduledFrame;
    TimerCls->run([=] () {
        assert(_warmUpFrame);
        handleBeginFrame(nullptr);
    });
    TimerCls->run([=] () {
        assert(_warmUpFrame);
        handleDrawFrame();
        resetEpoch();
        _warmUpFrame = false;
        if (hadScheduledFrame) {
            scheduleFrame();
        }
    });
    lockEvents([=] () {
        await endOfFrame();
        timelineTask->finish();
    });
}

void SchedulerBindingCls::resetEpoch() {
    _epochStart = _adjustForEpoch(_lastRawTimeStamp);
    _firstRawTimeStampInEpoch = nullptr;
}

Duration SchedulerBindingCls::currentFrameTimeStamp() {
    assert(_currentFrameTimeStamp != nullptr);
    return _currentFrameTimeStamp!;
}

Duration SchedulerBindingCls::currentSystemFrameTimeStamp() {
    assert(_lastRawTimeStamp != nullptr);
    return _lastRawTimeStamp;
}

void SchedulerBindingCls::handleBeginFrame(Duration rawTimeStamp) {
    _frameTimelineTask?->start(__s("Frame"));
    _firstRawTimeStampInEpoch |= rawTimeStamp;
    _currentFrameTimeStamp = _adjustForEpoch(rawTimeStamp | _lastRawTimeStamp);
    if (rawTimeStamp != nullptr) {
        _lastRawTimeStamp = rawTimeStamp;
    }
    assert([=] () {
        _debugFrameNumber += 1;
        if (debugPrintBeginFrameBanner || debugPrintEndFrameBanner) {
            StringBuffer frameTimeStampDescription = make<StringBufferCls>();
            if (rawTimeStamp != nullptr) {
                _debugDescribeTimeStamp(_currentFrameTimeStamp!, frameTimeStampDescription);
            } else {
                frameTimeStampDescription->write(__s("(warm-up frame)"));
            }
            _debugBanner = __sf("???????????????????????? Frame %s   %s ????????????????????????", _debugFrameNumber->toString()->padRight(7), frameTimeStampDescription->toString()->padLeft(18));
            if (debugPrintBeginFrameBanner) {
                debugPrint(_debugBanner);
            }
        }
        return true;
    }());
    assert(schedulerPhase() == SchedulerPhaseCls::idle);
    _hasScheduledFrame = false;
    try {
        _frameTimelineTask?->start(__s("Animate"));
        _schedulerPhase = SchedulerPhaseCls::transientCallbacks;
        Map<int, _FrameCallbackEntry> callbacks = _transientCallbacks;
        _transientCallbacks = makeMap(makeList(), makeList();
        callbacks->forEach([=] (int id,_FrameCallbackEntry callbackEntry) {
            if (!_removedIds->contains(id)) {
                _invokeFrameCallback(callbackEntry->callback, _currentFrameTimeStamp!, callbackEntry->debugStack);
            }
        });
        _removedIds->clear();
    } finally {
        _schedulerPhase = SchedulerPhaseCls::midFrameMicrotasks;
    };
}

void SchedulerBindingCls::handleDrawFrame() {
    assert(_schedulerPhase == SchedulerPhaseCls::midFrameMicrotasks);
    _frameTimelineTask?->finish();
    try {
        _schedulerPhase = SchedulerPhaseCls::persistentCallbacks;
        for (FrameCallback callback : _persistentCallbacks) {
            _invokeFrameCallback(callback, _currentFrameTimeStamp!);
        }
        _schedulerPhase = SchedulerPhaseCls::postFrameCallbacks;
        List<FrameCallback> localPostFrameCallbacks = <FrameCallback>of(_postFrameCallbacks);
        _postFrameCallbacks->clear();
        for (FrameCallback callback : localPostFrameCallbacks) {
            _invokeFrameCallback(callback, _currentFrameTimeStamp!);
        }
    } finally {
        _schedulerPhase = SchedulerPhaseCls::idle;
        _frameTimelineTask?->finish();
        assert([=] () {
            if (debugPrintEndFrameBanner) {
                debugPrint(__s("???") * _debugBanner!->length());
            }
            _debugBanner = nullptr;
            return true;
        }());
        _currentFrameTimeStamp = nullptr;
    };
}

void SchedulerBindingCls::_executeTimingsCallbacks(List<FrameTiming> timings) {
    List<TimingsCallback> clonedCallbacks = <TimingsCallback>of(_timingsCallbacks);
    for (TimingsCallback callback : clonedCallbacks) {
        try {
            if (_timingsCallbacks->contains(callback)) {
                callback(timings);
            }
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] () {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, make<ErrorDescriptionCls>(__s("while executing callbacks for FrameTiming")), collector));
        };
    }
}

int SchedulerBindingCls::_taskSorter(_TaskEntry<Object> e1, _TaskEntry<Object> e2) {
    return -e1->priority->compareTo(e2->priority);
}

void SchedulerBindingCls::_ensureEventLoopCallback() {
    assert(!locked);
    assert(_taskQueue->isNotEmpty());
    if (_hasRequestedAnEventLoopCallback) {
        return;
    }
    _hasRequestedAnEventLoopCallback = true;
    TimerCls->run(_runTasks);
}

void SchedulerBindingCls::_runTasks() {
    _hasRequestedAnEventLoopCallback = false;
    if (handleEventLoopCallback()) {
        _ensureEventLoopCallback();
    }
}

void SchedulerBindingCls::_setFramesEnabledState(bool enabled) {
    if (_framesEnabled == enabled) {
        return;
    }
    _framesEnabled = enabled;
    if (enabled) {
        scheduleFrame();
    }
}

Duration SchedulerBindingCls::_adjustForEpoch(Duration rawTimeStamp) {
    Duration rawDurationSinceEpoch = _firstRawTimeStampInEpoch == nullptr? DurationCls::zero : rawTimeStamp - _firstRawTimeStampInEpoch!;
    return make<DurationCls>((rawDurationSinceEpoch->inMicroseconds() / timeDilation)->round() + _epochStart->inMicroseconds());
}

void SchedulerBindingCls::_handleBeginFrame(Duration rawTimeStamp) {
    if (_warmUpFrame) {
        assert(!_rescheduleAfterWarmUpFrame);
        _rescheduleAfterWarmUpFrame = true;
        return;
    }
    handleBeginFrame(rawTimeStamp);
}

void SchedulerBindingCls::_handleDrawFrame() {
    if (_rescheduleAfterWarmUpFrame) {
        _rescheduleAfterWarmUpFrame = false;
        addPostFrameCallback([=] (Duration timeStamp) {
            _hasScheduledFrame = false;
            scheduleFrame();
        });
        return;
    }
    handleDrawFrame();
}

void SchedulerBindingCls::_profileFramePostEvent(FrameTiming frameTiming) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("number"), frameTiming->frameNumber());map1.set(__s("startTime"), frameTiming->timestampInMicroseconds(FramePhaseCls::buildStart));map1.set(__s("elapsed"), frameTiming->totalSpan()->inMicroseconds());map1.set(__s("build"), frameTiming->buildDuration()->inMicroseconds());map1.set(__s("raster"), frameTiming->rasterDuration()->inMicroseconds());map1.set(__s("vsyncOverhead"), frameTiming->vsyncOverhead()->inMicroseconds());postEvent(__s("Flutter.Frame"), list1);
}

void SchedulerBindingCls::_debugDescribeTimeStamp(Duration timeStamp, StringBuffer buffer) {
    if (timeStamp->inDays() > 0) {
        buffer->write(__sf("%sd ", timeStamp->inDays()));
    }
    if (timeStamp->inHours() > 0) {
        buffer->write(__sf("%sh ", timeStamp->inHours() - timeStamp->inDays() * DurationCls::hoursPerDay));
    }
    if (timeStamp->inMinutes() > 0) {
        buffer->write(__sf("%sm ", timeStamp->inMinutes() - timeStamp->inHours() * DurationCls::minutesPerHour));
    }
    if (timeStamp->inSeconds() > 0) {
        buffer->write(__sf("%ss ", timeStamp->inSeconds() - timeStamp->inMinutes() * DurationCls::secondsPerMinute));
    }
    buffer->write(__sf("%s", timeStamp->inMilliseconds() - timeStamp->inSeconds() * DurationCls::millisecondsPerSecond));
    int microseconds = timeStamp->inMicroseconds() - timeStamp->inMilliseconds() * DurationCls::microsecondsPerMillisecond;
    if (microseconds > 0) {
        buffer->write(__sf(".%s", microseconds->toString()->padLeft(3, __s("0"))));
    }
    buffer->write(__s("ms"));
}

void SchedulerBindingCls::_invokeFrameCallback(FrameCallback callback, Duration timeStamp, StackTrace callbackStack) {
    assert(callback != nullptr);
    assert(_FrameCallbackEntryCls::debugCurrentCallbackStack == nullptr);
    assert([=] () {
        _FrameCallbackEntryCls::debugCurrentCallbackStack = callbackStack;
        return true;
    }());
    try {
        callback(timeStamp);
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, exceptionStack, __s("scheduler library"), make<ErrorDescriptionCls>(__s("during a scheduler callback")), (callbackStack == nullptr)? nullptr : [=] () {
            return makeList(ArrayItem);
        }));
    };
    assert([=] () {
        _FrameCallbackEntryCls::debugCurrentCallbackStack = nullptr;
        return true;
    }());
}

bool defaultSchedulingStrategy(int priority, SchedulerBinding scheduler) {
    if (scheduler->transientCallbackCount() > 0) {
        return priority >= PriorityCls::animation->value;
    }
    return true;
}
