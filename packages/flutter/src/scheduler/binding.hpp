#ifndef PACKAGES_FLUTTER_SRC_SCHEDULER_BINDING
#define PACKAGES_FLUTTER_SRC_SCHEDULER_BINDING
#include <base.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include "priority.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "debug.hpp"
#include "priority.hpp"

double timeDilation();

double _timeDilation;

void  timeDilation(double value);


template<typename T>
class _TaskEntryCls : public ObjectCls {
public:
    TaskCallback<T> task;

    int priority;

    String debugLabel;

    Flow flow;

    StackTrace debugStack;

    Completer<T> completer;


    virtual void run();

private:

     _TaskEntryCls(String debugLabel, Flow flow, int priority, TaskCallback<T> task);

};
template<typename T>
using _TaskEntry = std::shared_ptr<_TaskEntryCls<T>>;

class _FrameCallbackEntryCls : public ObjectCls {
public:
    FrameCallback callback;

    static StackTrace debugCurrentCallbackStack;

    StackTrace debugStack;


private:

     _FrameCallbackEntryCls(FrameCallback callback, bool rescheduling);

};
using _FrameCallbackEntry = std::shared_ptr<_FrameCallbackEntryCls>;

enum SchedulerPhase{
    idle,
    transientCallbacks,
    midFrameMicrotasks,
    persistentCallbacks,
    postFrameCallbacks,
} // end SchedulerPhase

class SchedulerBindingCls : public ObjectCls {
public:
    SchedulingStrategy schedulingStrategy;


    virtual void initInstances();

    static SchedulerBinding instance();

    virtual void addTimingsCallback(TimingsCallback callback);

    virtual void removeTimingsCallback(TimingsCallback callback);

    virtual void initServiceExtensions();

    virtual AppLifecycleState lifecycleState();

    virtual void handleAppLifecycleStateChanged(AppLifecycleState state);

    template<typename T>
 virtual Future<T> scheduleTask(String debugLabel, Flow flow, Priority priority, TaskCallback<T> task);

    virtual void unlocked();

    virtual bool handleEventLoopCallback();

    virtual int transientCallbackCount();

    virtual int scheduleFrameCallback(FrameCallback callback, bool rescheduling);

    virtual void cancelFrameCallbackWithId(int id);

    virtual bool debugAssertNoTransientCallbacks(String reason);

    static void debugPrintTransientCallbackRegistrationStack();

    virtual void addPersistentFrameCallback(FrameCallback callback);

    virtual void addPostFrameCallback(FrameCallback callback);

    virtual Future<void> endOfFrame();

    virtual bool hasScheduledFrame();

    virtual SchedulerPhase schedulerPhase();

    virtual bool framesEnabled();

    virtual void ensureFrameCallbacksRegistered();

    virtual void ensureVisualUpdate();

    virtual void scheduleFrame();

    virtual void scheduleForcedFrame();

    virtual void scheduleWarmUpFrame();

    virtual void resetEpoch();

    virtual Duration currentFrameTimeStamp();

    virtual Duration currentSystemFrameTimeStamp();

    virtual void handleBeginFrame(Duration rawTimeStamp);

    virtual void handleDrawFrame();

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


    virtual void _executeTimingsCallbacks(List<FrameTiming> timings);

    static int _taskSorter(_TaskEntry<dynamic> e1, _TaskEntry<dynamic> e2);

    virtual void _ensureEventLoopCallback();

    virtual void _runTasks();

    virtual void _setFramesEnabledState(bool enabled);

    virtual Duration _adjustForEpoch(Duration rawTimeStamp);

    virtual void _handleBeginFrame(Duration rawTimeStamp);

    virtual void _handleDrawFrame();

    virtual void _profileFramePostEvent(FrameTiming frameTiming);

    static void _debugDescribeTimeStamp(StringBuffer buffer, Duration timeStamp);

    virtual void _invokeFrameCallback(FrameCallback callback, StackTrace callbackStack, Duration timeStamp);

};
using SchedulerBinding = std::shared_ptr<SchedulerBindingCls>;
bool defaultSchedulingStrategy(int priority, SchedulerBinding scheduler);



#endif