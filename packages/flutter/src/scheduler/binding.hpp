#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <developer.hpp>
#include <ui.hpp>
#include "priority.hpp"

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include "debug.hpp"
#include "priority.hpp"


double timeDilation();

double _timeDilation;

void  timeDilation(double value);


class _TaskEntry<T> {
public:
    TaskCallback<T> task;

    int priority;

    String debugLabel;

    Flow flow;

    StackTrace debugStack;

    Completer<T> completer;


    void run();

private:

     _TaskEntry(String debugLabel, Flow flow, int priority, TaskCallback<T> task);

};

class _FrameCallbackEntry {
public:
    FrameCallback callback;

    static StackTrace debugCurrentCallbackStack;

    StackTrace debugStack;


private:

     _FrameCallbackEntry(FrameCallback callback, bool rescheduling);

};

enum SchedulerPhase{
    idle,
    transientCallbacks,
    midFrameMicrotasks,
    persistentCallbacks,
    postFrameCallbacks,
} // end SchedulerPhase

class SchedulerBinding {
public:
    SchedulingStrategy schedulingStrategy;


    void initInstances();

    static SchedulerBinding instance();

    void addTimingsCallback(TimingsCallback callback);

    void removeTimingsCallback(TimingsCallback callback);

    void initServiceExtensions();

    AppLifecycleState lifecycleState();

    void handleAppLifecycleStateChanged(AppLifecycleState state);

    Future<T> scheduleTask<T>(String debugLabel, Flow flow, Priority priority, TaskCallback<T> task);

    void unlocked();

    bool handleEventLoopCallback();

    int transientCallbackCount();

    int scheduleFrameCallback(FrameCallback callback, bool rescheduling);

    void cancelFrameCallbackWithId(int id);

    bool debugAssertNoTransientCallbacks(String reason);

    static void debugPrintTransientCallbackRegistrationStack();

    void addPersistentFrameCallback(FrameCallback callback);

    void addPostFrameCallback(FrameCallback callback);

    Future<void> endOfFrame();

    bool hasScheduledFrame();

    SchedulerPhase schedulerPhase();

    bool framesEnabled();

    void ensureFrameCallbacksRegistered();

    void ensureVisualUpdate();

    void scheduleFrame();

    void scheduleForcedFrame();

    void scheduleWarmUpFrame();

    void resetEpoch();

    Duration currentFrameTimeStamp();

    Duration currentSystemFrameTimeStamp();

    void handleBeginFrame(Duration rawTimeStamp);

    void handleDrawFrame();

private:
    static SchedulerBinding _instance;

    List<TimingsCallback> _timingsCallbacks;

    AppLifecycleState _lifecycleState;

    PriorityQueue<_TaskEntry<dynamic>> _taskQueue;

    bool _hasRequestedAnEventLoopCallback;

    int _nextFrameCallbackId;

    Map<int, _FrameCallbackEntry> _transientCallbacks;

    Set<int> _removedIds;

    List<FrameCallback> _persistentCallbacks;

    List<FrameCallback> _postFrameCallbacks;

    Completer<void> _nextFrameCompleter;

    bool _hasScheduledFrame;

    SchedulerPhase _schedulerPhase;

    bool _framesEnabled;

    bool _warmUpFrame;

    Duration _firstRawTimeStampInEpoch;

    Duration _epochStart;

    Duration _lastRawTimeStamp;

    Duration _currentFrameTimeStamp;

    int _debugFrameNumber;

    String _debugBanner;

    bool _rescheduleAfterWarmUpFrame;

    TimelineTask _frameTimelineTask;


    void _executeTimingsCallbacks(List<FrameTiming> timings);

    static int _taskSorter(_TaskEntry<dynamic> e1, _TaskEntry<dynamic> e2);

    void _ensureEventLoopCallback();

    void _runTasks();

    void _setFramesEnabledState(bool enabled);

    Duration _adjustForEpoch(Duration rawTimeStamp);

    void _handleBeginFrame(Duration rawTimeStamp);

    void _handleDrawFrame();

    void _profileFramePostEvent(FrameTiming frameTiming);

    static void _debugDescribeTimeStamp(StringBuffer buffer, Duration timeStamp);

    void _invokeFrameCallback(FrameCallback callback, StackTrace callbackStack, Duration timeStamp);

};
bool defaultSchedulingStrategy(int priority, SchedulerBinding scheduler);


#endif