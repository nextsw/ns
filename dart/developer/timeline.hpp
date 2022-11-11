#ifndef DART_DEVELOPER_TIMELINE
#define DART_DEVELOPER_TIMELINE
#include <base.hpp>

#include <dart/core/core.hpp>

bool _hasTimeline;


class FlowCls : public ObjectCls {
public:
    int id;


    static Flow begin(int id);

    static Flow step(int id);

    static Flow end(int id);

private:
    static int _begin;

    static int _step;

    static int _end;

    int _type;


    virtual void  _(int _type, int id);
};
using Flow = std::shared_ptr<FlowCls>;

class TimelineCls : public ObjectCls {
public:

    static void startSync(String name, Map<any, any> arguments, Flow flow);

    static void finishSync();

    static void instantSync(String name, Map<any, any> arguments);

    template<typename T>
 static T timeSync(String name, TimelineSyncFunction<T> function, Map<any, any> arguments, Flow flow);

    static int now();

private:
    static List<_SyncBlock> _stack;


};
using Timeline = std::shared_ptr<TimelineCls>;

class TimelineTaskCls : public ObjectCls {
public:

     TimelineTaskCls(String filterKey, TimelineTask parent);

    virtual void  withTaskId(int taskId, String filterKey);

    virtual void start(String name, Map<any, any> arguments);

    virtual void instant(String name, Map<any, any> arguments);

    virtual void finish(Map<any, any> arguments);

    virtual int pass();

private:
    static String _kFilterKey;

    TimelineTask _parent;

    String _filterKey;

    int _taskId;

    List<_AsyncBlock> _stack;


};
using TimelineTask = std::shared_ptr<TimelineTaskCls>;

class _AsyncBlockCls : public ObjectCls {
public:
    String category;

    String name;


private:
    int _taskId;


    virtual void  _(String name, int _taskId);
    virtual void _start(Map<any, any> arguments);

    virtual void _finish(Map<any, any> arguments);

};
using _AsyncBlock = std::shared_ptr<_AsyncBlockCls>;

class _SyncBlockCls : public ObjectCls {
public:
    String category;

    String name;

    Map<any, any> arguments;

    Flow flow;


    virtual void finish();

private:
    String _jsonArguments;


    virtual void  _(String name, Map<any, any> arguments, Flow flow);
    virtual void _startSync();

};
using _SyncBlock = std::shared_ptr<_SyncBlockCls>;
String _argumentsAsJson(Map<any, any> arguments);

bool _isDartStreamEnabled();
int _getNextAsyncId();
int _getTraceClock();
void _reportTaskEvent(int taskId, String phase, String category, String name, String argumentsAsJson);
void _reportFlowEvent(String category, String name, int type, int id, String argumentsAsJson);
void _reportInstantEvent(String category, String name, String argumentsAsJson);


#endif