#include "timeline.hpp"
Flow FlowCls::begin(int id) {
    return FlowCls->_(_begin, id or _getNextAsyncId());
}

Flow FlowCls::step(int id) {
    return FlowCls->_(_step, id);
}

Flow FlowCls::end(int id) {
    return FlowCls->_(_end, id);
}

void TimelineCls::startSync(Map arguments, Flow flow, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        _stack->add(nullptr);
        return;
    }
    auto block = _SyncBlockCls->_(namearguments, flow);
    _stack->add(block);
    block->_startSync();
}

void TimelineCls::finishSync() {
    if (!_hasTimeline) {
        return;
    }
    if (_stack->isEmpty) {
        ;
    }
    auto block = _stack->removeLast();
    if (block == nullptr) {
        return;
    }
    block->finish();
}

void TimelineCls::instantSync(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map instantArguments;
    if (arguments != nullptr) {
        instantArguments = MapCls->from(arguments);
    }
    _reportInstantEvent(__s("Dart"), name, _argumentsAsJson(instantArguments));
}

T TimelineCls::timeSynctemplate<typename T> (Map arguments, Flow flow, TimelineSyncFunction<T> function, String name) {
    startSync(namearguments, flow);
    try {
        return function();
    } finally {
        finishSync();
    };
}

int TimelineCls::now() {
    return _getTraceClock();
}

TimelineTaskCls::TimelineTaskCls(String filterKey, TimelineTask parent) {
    {
        _parent = parent;
        _filterKey = filterKey;
        _taskId = _getNextAsyncId();
    }
    {
    }
}

void TimelineTaskCls::withTaskId(String filterKey, int taskId) {
    ArgumentErrorCls->checkNotNull(taskId, __s("taskId"));
}

void TimelineTaskCls::start(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        _stack->add(nullptr);
        return;
    }
    auto block = _AsyncBlockCls->_(name, _taskId);
    _stack->add(block);
    auto map = makeMap(makeList(), makeList();
    if (arguments != nullptr) {
        for (auto key : arguments->keys) {
            map[key] = arguments[key];
        }
    }
    if (_parent != nullptr)     {
        map[__s("parentId")] = _parent!->_taskId->toRadixString(16);
    }
    if (_filterKey != nullptr)     {
        map[_kFilterKey] = _filterKey;
    }
    block->_start(map);
}

void TimelineTaskCls::instant(Map arguments, String name) {
    if (!_hasTimeline)     {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map instantArguments;
    if (arguments != nullptr) {
        instantArguments = MapCls->from(arguments);
    }
    if (_filterKey != nullptr) {
        instantArguments = makeMap(makeList(), makeList();
        instantArguments[_kFilterKey] = _filterKey;
    }
    _reportTaskEvent(_taskId, __s("n"), __s("Dart"), name, _argumentsAsJson(instantArguments));
}

void TimelineTaskCls::finish(Map arguments) {
    if (!_hasTimeline) {
        return;
    }
    if (_stack->length == 0) {
        ;
    }
    if (_filterKey != nullptr) {
        arguments = makeMap(makeList(), makeList();
        arguments[_kFilterKey] = _filterKey;
    }
    auto block = _stack->removeLast();
    if (block == nullptr) {
        return;
    }
    block->_finish(arguments);
}

int TimelineTaskCls::pass() {
    if (_stack->length > 0) {
        ;
    }
    int r = _taskId;
    return r;
}

void _AsyncBlockCls::_start(Map arguments) {
    _reportTaskEvent(_taskId, __s("b"), category, name, _argumentsAsJson(arguments));
}

void _AsyncBlockCls::_finish(Map arguments) {
    _reportTaskEvent(_taskId, __s("e"), category, name, _argumentsAsJson(arguments));
}

void _SyncBlockCls::finish() {
    _reportTaskEvent(0, __s("E"), category, name, _jsonArguments);
    Flow tempFlow = flow;
    if (tempFlow != nullptr) {
        _reportFlowEvent(category, __s("${tempFlow.id}"), tempFlow->_type, tempFlow->id, _argumentsAsJson(nullptr));
    }
}

void _SyncBlockCls::_startSync() {
    _reportTaskEvent(0, __s("B"), category, name, _jsonArguments);
}

String _argumentsAsJson(Map arguments) {
    if ((arguments == nullptr) || (arguments->length == 0)) {
        return __s("{}");
    }
    return json->encode(arguments);
}
