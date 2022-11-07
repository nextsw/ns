#include "timeline.hpp"
Flow Flow::begin(int id) {
    return Flow._(_begin, id ?? _getNextAsyncId());
}

Flow Flow::step(int id) {
    return Flow._(_step, id);
}

Flow Flow::end(int id) {
    return Flow._(_end, id);
}

void Timeline::startSync(Map arguments, Flow flow, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentError.checkNotNull(name, "name");
    if (!_isDartStreamEnabled()) {
        _stack.add(nullptr);
        return;
    }
    auto block = _SyncBlock._(namearguments, flow);
    _stack.add(block);
    block._startSync();
}

void Timeline::finishSync() {
    if (!_hasTimeline) {
        return;
    }
    if (_stack.isEmpty) {
        ;
    }
    auto block = _stack.removeLast();
    if (block == nullptr) {
        return;
    }
    block.finish();
}

void Timeline::instantSync(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentError.checkNotNull(name, "name");
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map instantArguments;
    if (arguments != nullptr) {
        instantArguments = Map.from(arguments);
    }
    _reportInstantEvent("Dart", name, _argumentsAsJson(instantArguments));
}

T Timeline::timeSync<T>(Map arguments, Flow flow, TimelineSyncFunction<T> function, String name) {
    startSync(namearguments, flow);
    ;
}

int Timeline::now() {
    return _getTraceClock();
}

TimelineTask::TimelineTask(String filterKey, TimelineTask parent) {
    {
        _parent = parent;
        _filterKey = filterKey;
        _taskId = _getNextAsyncId();
    }
    {
    }
}

void TimelineTask::withTaskId(String filterKey, int taskId) {
    ArgumentError.checkNotNull(taskId, "taskId");
}

void TimelineTask::start(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentError.checkNotNull(name, "name");
    if (!_isDartStreamEnabled()) {
        _stack.add(nullptr);
        return;
    }
    auto block = _AsyncBlock._(name, _taskId);
    _stack.add(block);
    auto map = ;
    if (arguments != nullptr) {
        for (auto key : arguments.keys) {
            map[key] = arguments[key];
        }
    }
    if (_parent != nullptr)     {
        map["parentId"] = _parent!._taskId.toRadixString(16);
    }
    if (_filterKey != nullptr)     {
        map[_kFilterKey] = _filterKey;
    }
    block._start(map);
}

void TimelineTask::instant(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentError.checkNotNull(name, "name");
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map instantArguments;
    if (arguments != nullptr) {
        instantArguments = Map.from(arguments);
    }
    if (_filterKey != nullptr) {
        instantArguments = ;
        instantArguments[_kFilterKey] = _filterKey;
    }
    _reportTaskEvent(_taskId, "n", "Dart", name, _argumentsAsJson(instantArguments));
}

void TimelineTask::finish(Map arguments) {
    if (!_hasTimeline) {
        return;
    }
    if (_stack.length == 0) {
        ;
    }
    if (_filterKey != nullptr) {
        arguments = ;
        arguments[_kFilterKey] = _filterKey;
    }
    auto block = _stack.removeLast();
    if (block == nullptr) {
        return;
    }
    block._finish(arguments);
}

int TimelineTask::pass() {
    if (_stack.length > 0) {
        ;
    }
    int r = _taskId;
    return r;
}

void _AsyncBlock::_start(Map arguments) {
    _reportTaskEvent(_taskId, "b", category, name, _argumentsAsJson(arguments));
}

void _AsyncBlock::_finish(Map arguments) {
    _reportTaskEvent(_taskId, "e", category, name, _argumentsAsJson(arguments));
}

void _SyncBlock::finish() {
    _reportTaskEvent(0, "E", category, name, _jsonArguments);
    Flow tempFlow = flow;
    if (tempFlow != nullptr) {
        _reportFlowEvent(category, "${tempFlow.id}", tempFlow._type, tempFlow.id, _argumentsAsJson(nullptr));
    }
}

void _SyncBlock::_startSync() {
    _reportTaskEvent(0, "B", category, name, _jsonArguments);
}

String _argumentsAsJson(Map arguments) {
    if ((arguments == nullptr) || (arguments.length == 0)) {
        return "{}";
    }
    return json.encode(arguments);
}
