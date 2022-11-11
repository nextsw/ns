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

    static void startSync(Map arguments, Flow flow, String name);

    static void finishSync();

    static void instantSync(Map arguments, String name);

    template<typename T>
 static T timeSync(Map arguments, Flow flow, TimelineSyncFunction<T> function, String name);

    static int now();

private:
    static List<_SyncBlock> _stack;


};
using Timeline = std::shared_ptr<TimelineCls>;

class TimelineTaskCls : public ObjectCls {
public:

     TimelineTaskCls(String filterKey, TimelineTask parent);

    virtual void  withTaskId(String filterKey, int taskId);

    virtual void start(Map arguments, String name);

    virtual void instant(Map arguments, String name);

    virtual void finish(Map arguments);

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


    virtual void  _(int _taskId, String name);
    virtual void _start(Map arguments);

    virtual void _finish(Map arguments);

};
using _AsyncBlock = std::shared_ptr<_AsyncBlockCls>;

class _SyncBlockCls : public ObjectCls {
public:
    String category;

    String name;

    Map arguments;

    Flow flow;


    virtual void finish();

private:
    String _jsonArguments;


    virtual void  _(Map arguments, Flow flow, String name);
    virtual void _startSync();

};
using _SyncBlock = std::shared_ptr<_SyncBlockCls>;
String _argumentsAsJson(Map arguments);

bool _isDartStreamEnabled();
int _getNextAsyncId();
int _getTraceClock();
void _reportTaskEvent(String argumentsAsJson, String category, String name, String phase, int taskId);
void _reportFlowEvent(String argumentsAsJson, String category, int id, String name, int type);
void _reportInstantEvent(String argumentsAsJson, String category, String name);


#endif