#ifndef TIMELINE_H
#define TIMELINE_H
#include <memory>



const bool _hasTimeline;


class Flow {
public:
    int id;


    static Flow begin(int id);

    static Flow step(int id);

    static Flow end(int id);

private:
    static const int _begin;

    static const int _step;

    static const int _end;

    int _type;


    void  _(int _type, int id);

};

class Timeline {
public:

    static void startSync(Map arguments, Flow flow, String name);

    static void finishSync();

    static void instantSync(Map arguments, String name);

    static T timeSync<T>(Map arguments, Flow flow, TimelineSyncFunction<T> function, String name);

    static int now();

private:
    static List<_SyncBlock> _stack;


};

class TimelineTask {
public:

     TimelineTask(String filterKey, TimelineTask parent);

    void  withTaskId(String filterKey, int taskId);

    void start(Map arguments, String name);

    void instant(Map arguments, String name);

    void finish(Map arguments);

    int pass();

private:
    static const String _kFilterKey;

    TimelineTask _parent;

    String _filterKey;

    int _taskId;

    List<_AsyncBlock> _stack;


};

class _AsyncBlock {
public:
    String category;

    String name;


private:
    int _taskId;


    void  _(int _taskId, String name);

    void _start(Map arguments);

    void _finish(Map arguments);

};

class _SyncBlock {
public:
    String category;

    String name;

    Map arguments;

    Flow flow;


    void finish();

private:
    String _jsonArguments;


    void  _(Map arguments, Flow flow, String name);

    void _startSync();

};
String _argumentsAsJson(Map arguments);

external bool _isDartStreamEnabled();

external int _getNextAsyncId();

external int _getTraceClock();

external void _reportTaskEvent(String argumentsAsJson, String category, String name, String phase, int taskId);

external void _reportFlowEvent(String argumentsAsJson, String category, int id, String name, int type);

external void _reportInstantEvent(String argumentsAsJson, String category, String name);


#endif