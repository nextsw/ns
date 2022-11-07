#include "binding.hpp"
double timeDilation() {
    return _timeDilation;
}

void timeDilation(double value) {
    assert(value > 0.0);
    if (_timeDilation == value) {
        return;
    }
    SchedulerBinding._instance?.resetEpoch();
    _timeDilation = value;
}

void _TaskEntry::run() {
    if (!kReleaseMode) {
        Timeline.timeSync(debugLabel ?? "Scheduled Task", flow != nullptr? Flow.step(flow!.id) : nullptr);
    } else {
        completer.complete(task());
    }
}

_TaskEntry::_TaskEntry(String debugLabel, Flow flow, int priority, TaskCallback<T> task) {
    {
        assert(());
    }
}

_FrameCallbackEntry::_FrameCallbackEntry(FrameCallback callback, bool rescheduling) {
    {
        assert(());
    }
}

void SchedulerBinding::initInstances() {
    super.initInstances();
    _instance = this;
    if (!kReleaseMode) {
        addTimingsCallback();
    }
}

SchedulerBinding SchedulerBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

void SchedulerBinding::addTimingsCallback(TimingsCallback callback) {
    _timingsCallbacks.add(callback);
    if (_timingsCallbacks.length == 1) {
        assert(platformDispatcher.onReportTimings == nullptr);
        platformDispatcher.onReportTimings = _executeTimingsCallbacks;
    }
    assert(platformDispatcher.onReportTimings == _executeTimingsCallbacks);
}

void SchedulerBinding::removeTimingsCallback(TimingsCallback callback) {
    assert(_timingsCallbacks.contains(callback));
    _timingsCallbacks.remove(callback);
    if (_timingsCallbacks.isEmpty) {
        platformDispatcher.onReportTimings = nullptr;
    }
}

void SchedulerBinding::initServiceExtensions() {
    super.initServiceExtensions();
    if (!kReleaseMode) {
        registerNumericServiceExtension("timeDilation", , );
    }
}

AppLifecycleState SchedulerBinding::lifecycleState() {
    return _lifecycleState;
}

void SchedulerBinding::handleAppLifecycleStateChanged(AppLifecycleState state) {
    assert(state != nullptr);
    _lifecycleState = state;
    ;
}

Future<T> SchedulerBinding::scheduleTask<T>(String debugLabel, Flow flow, Priority priority, TaskCallback<T> task) {
    bool isFirstTask = _taskQueue.isEmpty;
    _TaskEntry<T> entry = <T>_TaskEntry(task, priority.value, debugLabel, flow);
    _taskQueue.add(entry);
    if (isFirstTask && !locked) {
        _ensureEventLoopCallback();
    }
    return entry.completer.future;
}

void SchedulerBinding::unlocked() {
    super.unlocked();
    if (_taskQueue.isNotEmpty) {
        _ensureEventLoopCallback();
    }
}

bool SchedulerBinding::handleEventLoopCallback() {
    if (_taskQueue.isEmpty || locked) {
        return false;
    }
    _TaskEntry<dynamic> entry = _taskQueue.first;
    if (schedulingStrategy(entry.priority, this)) {
        ;
        return _taskQueue.isNotEmpty;
    }
    return false;
}

int SchedulerBinding::transientCallbackCount() {
    return _transientCallbacks.length;
}

int SchedulerBinding::scheduleFrameCallback(FrameCallback callback, bool rescheduling) {
    scheduleFrame();
    _nextFrameCallbackId = 1;
    _transientCallbacks[_nextFrameCallbackId] = _FrameCallbackEntry(callbackrescheduling);
    return _nextFrameCallbackId;
}

void SchedulerBinding::cancelFrameCallbackWithId(int id) {
    assert(id > 0);
    _transientCallbacks.remove(id);
    _removedIds.add(id);
}

bool SchedulerBinding::debugAssertNoTransientCallbacks(String reason) {
    assert(());
    return true;
}

void SchedulerBinding::debugPrintTransientCallbackRegistrationStack() {
    assert(());
}

void SchedulerBinding::addPersistentFrameCallback(FrameCallback callback) {
    _persistentCallbacks.add(callback);
}

void SchedulerBinding::addPostFrameCallback(FrameCallback callback) {
    _postFrameCallbacks.add(callback);
}

Future<void> SchedulerBinding::endOfFrame() {
    if (_nextFrameCompleter == nullptr) {
        if (schedulerPhase == SchedulerPhase.idle) {
            scheduleFrame();
        }
        _nextFrameCompleter = <void>Completer();
        addPostFrameCallback();
    }
    return _nextFrameCompleter!.future;
}

bool SchedulerBinding::hasScheduledFrame() {
    return _hasScheduledFrame;
}

SchedulerPhase SchedulerBinding::schedulerPhase() {
    return _schedulerPhase;
}

bool SchedulerBinding::framesEnabled() {
    return _framesEnabled;
}

void SchedulerBinding::ensureFrameCallbacksRegistered() {
    platformDispatcher.onBeginFrame = _handleBeginFrame;
    platformDispatcher.onDrawFrame = _handleDrawFrame;
}

void SchedulerBinding::ensureVisualUpdate() {
    ;
}

void SchedulerBinding::scheduleFrame() {
    if (_hasScheduledFrame || !framesEnabled) {
        return;
    }
    assert(());
    ensureFrameCallbacksRegistered();
    platformDispatcher.scheduleFrame();
    _hasScheduledFrame = true;
}

void SchedulerBinding::scheduleForcedFrame() {
    if (_hasScheduledFrame) {
        return;
    }
    assert(());
    ensureFrameCallbacksRegistered();
    platformDispatcher.scheduleFrame();
    _hasScheduledFrame = true;
}

void SchedulerBinding::scheduleWarmUpFrame() {
    if (_warmUpFrame || schedulerPhase != SchedulerPhase.idle) {
        return;
    }
    _warmUpFrame = true;
    TimelineTask timelineTask = ;
    bool hadScheduledFrame = _hasScheduledFrame;
    Timer.run();
    Timer.run();
    lockEvents();
}

void SchedulerBinding::resetEpoch() {
    _epochStart = _adjustForEpoch(_lastRawTimeStamp);
    _firstRawTimeStampInEpoch = nullptr;
}

Duration SchedulerBinding::currentFrameTimeStamp() {
    assert(_currentFrameTimeStamp != nullptr);
    return _currentFrameTimeStamp!;
}

Duration SchedulerBinding::currentSystemFrameTimeStamp() {
    assert(_lastRawTimeStamp != nullptr);
    return _lastRawTimeStamp;
}

void SchedulerBinding::handleBeginFrame(Duration rawTimeStamp) {
    _frameTimelineTask?.start("Frame");
    _firstRawTimeStampInEpoch = rawTimeStamp;
    _currentFrameTimeStamp = _adjustForEpoch(rawTimeStamp ?? _lastRawTimeStamp);
    if (rawTimeStamp != nullptr) {
        _lastRawTimeStamp = rawTimeStamp;
    }
    assert(());
    assert(schedulerPhase == SchedulerPhase.idle);
    _hasScheduledFrame = false;
    ;
}

void SchedulerBinding::handleDrawFrame() {
    assert(_schedulerPhase == SchedulerPhase.midFrameMicrotasks);
    _frameTimelineTask?.finish();
    ;
}

void SchedulerBinding::_executeTimingsCallbacks(List<FrameTiming> timings) {
    List<TimingsCallback> clonedCallbacks = <TimingsCallback>of(_timingsCallbacks);
    for (TimingsCallback callback : clonedCallbacks) {
        ;
    }
}

int SchedulerBinding::_taskSorter(_TaskEntry<dynamic> e1, _TaskEntry<dynamic> e2) {
    return -e1.priority.compareTo(e2.priority);
}

void SchedulerBinding::_ensureEventLoopCallback() {
    assert(!locked);
    assert(_taskQueue.isNotEmpty);
    if (_hasRequestedAnEventLoopCallback) {
        return;
    }
    _hasRequestedAnEventLoopCallback = true;
    Timer.run(_runTasks);
}

void SchedulerBinding::_runTasks() {
    _hasRequestedAnEventLoopCallback = false;
    if (handleEventLoopCallback()) {
        _ensureEventLoopCallback();
    }
}

void SchedulerBinding::_setFramesEnabledState(bool enabled) {
    if (_framesEnabled == enabled) {
        return;
    }
    _framesEnabled = enabled;
    if (enabled) {
        scheduleFrame();
    }
}

Duration SchedulerBinding::_adjustForEpoch(Duration rawTimeStamp) {
    Duration rawDurationSinceEpoch = _firstRawTimeStampInEpoch == nullptr? Duration.zero : rawTimeStamp - _firstRawTimeStampInEpoch!;
    return Duration((rawDurationSinceEpoch.inMicroseconds / timeDilation).round() + _epochStart.inMicroseconds);
}

void SchedulerBinding::_handleBeginFrame(Duration rawTimeStamp) {
    if (_warmUpFrame) {
        assert(!_rescheduleAfterWarmUpFrame);
        _rescheduleAfterWarmUpFrame = true;
        return;
    }
    handleBeginFrame(rawTimeStamp);
}

void SchedulerBinding::_handleDrawFrame() {
    if (_rescheduleAfterWarmUpFrame) {
        _rescheduleAfterWarmUpFrame = false;
        addPostFrameCallback();
        return;
    }
    handleDrawFrame();
}

void SchedulerBinding::_profileFramePostEvent(FrameTiming frameTiming) {
    postEvent("Flutter.Frame", );
}

void SchedulerBinding::_debugDescribeTimeStamp(StringBuffer buffer, Duration timeStamp) {
    if (timeStamp.inDays > 0) {
        buffer.write("${timeStamp.inDays}d ");
    }
    if (timeStamp.inHours > 0) {
        buffer.write("${timeStamp.inHours - timeStamp.inDays * Duration.hoursPerDay}h ");
    }
    if (timeStamp.inMinutes > 0) {
        buffer.write("${timeStamp.inMinutes - timeStamp.inHours * Duration.minutesPerHour}m ");
    }
    if (timeStamp.inSeconds > 0) {
        buffer.write("${timeStamp.inSeconds - timeStamp.inMinutes * Duration.secondsPerMinute}s ");
    }
    buffer.write("${timeStamp.inMilliseconds - timeStamp.inSeconds * Duration.millisecondsPerSecond}");
    int microseconds = timeStamp.inMicroseconds - timeStamp.inMilliseconds * Duration.microsecondsPerMillisecond;
    if (microseconds > 0) {
        buffer.write(".${microseconds.toString().padLeft(3, "0")}");
    }
    buffer.write("ms");
}

void SchedulerBinding::_invokeFrameCallback(FrameCallback callback, StackTrace callbackStack, Duration timeStamp) {
    assert(callback != nullptr);
    assert(_FrameCallbackEntry.debugCurrentCallbackStack == nullptr);
    assert(());
    ;
    assert(());
}

bool defaultSchedulingStrategy(int priority, SchedulerBinding scheduler) {
    if (scheduler.transientCallbackCount > 0) {
        return priority >= Priority.animation.value;
    }
    return true;
}
