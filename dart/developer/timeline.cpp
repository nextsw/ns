#include "timeline.hpp"
Flow FlowCls::begin(int id) {
    return FlowCls->_(_begin, id | _getNextAsyncId());
}

Flow FlowCls::step(int id) {
    return FlowCls->_(_step, id);
}

Flow FlowCls::end(int id) {
    return FlowCls->_(_end, id);
}

void TimelineCls::startSync(String name, Map<any, any> arguments, Flow flow) {
    if (!_hasTimeline) {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        _stack->add(nullptr);
        return;
    }
    auto block = _SyncBlockCls->_(name, arguments, flow);
    _stack->add(block);
    block->_startSync();
}

void TimelineCls::finishSync() {
    if (!_hasTimeline) {
        return;
    }
    if (_stack->isEmpty) {
        throw make<StateErrorCls>(__s("Uneven calls to startSync and finishSync"));
    }
    auto block = _stack->removeLast();
    if (block == nullptr) {
        return;
    }
    block->finish();
}

void TimelineCls::instantSync(String name, Map<any, any> arguments) {
    if (!_hasTimeline) {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map<any, any> instantArguments;
    if (arguments != nullptr) {
        instantArguments = MapCls->from(arguments);
    }
    _reportInstantEvent(__s("Dart"), name, _argumentsAsJson(instantArguments));
}

template<typename T>
T TimelineCls::timeSync(String name, TimelineSyncFunction<T> function, Map<any, any> arguments, Flow flow) {
    startSync(name, arguments, flow);
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

void TimelineTaskCls::withTaskId(int taskId, String filterKey) {
    ArgumentErrorCls->checkNotNull(taskId, __s("taskId"));
}

void TimelineTaskCls::start(String name, Map<any, any> arguments) {
    if (!_hasTimeline) {
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
        for (auto key : arguments->keys()) {
            map[key] = arguments[key];
        }
    }
    if (_parent != nullptr) {
        map[__s("parentId")] = _parent!->_taskId->toRadixString(16);
    }
    if (_filterKey != nullptr) {
        map[_kFilterKey] = _filterKey;
    }
    block->_start(map);
}

void TimelineTaskCls::instant(String name, Map<any, any> arguments) {
    if (!_hasTimeline) {
        return;
    }
    ArgumentErrorCls->checkNotNull(name, __s("name"));
    if (!_isDartStreamEnabled()) {
        return;
    }
    Map<any, any> instantArguments;
    if (arguments != nullptr) {
        instantArguments = MapCls->from(arguments);
    }
    if (_filterKey != nullptr) {
        instantArguments |= makeMap(makeList(), makeList();
        instantArguments[_kFilterKey] = _filterKey;
    }
    _reportTaskEvent(_taskId, __s("n"), __s("Dart"), name, _argumentsAsJson(instantArguments));
}

void TimelineTaskCls::finish(Map<any, any> arguments) {
    if (!_hasTimeline) {
        return;
    }
    if (_stack->length() == 0) {
        throw make<StateErrorCls>(__s("Uneven calls to start and finish"));
    }
    if (_filterKey != nullptr) {
        arguments |= makeMap(makeList(), makeList();
        arguments[_kFilterKey] = _filterKey;
    }
    auto block = _stack->removeLast();
    if (block == nullptr) {
        return;
    }
    block->_finish(arguments);
}

int TimelineTaskCls::pass() {
    if (_stack->length() > 0) {
        throw make<StateErrorCls>(__s("You cannot pass a TimelineTask without finishing all started operations"));
    }
    int r = _taskId;
    return r;
}

void _AsyncBlockCls::_start(Map<any, any> arguments) {
    _reportTaskEvent(_taskId, __s("b"), category, name, _argumentsAsJson(arguments));
}

void _AsyncBlockCls::_finish(Map<any, any> arguments) {
    _reportTaskEvent(_taskId, __s("e"), category, name, _argumentsAsJson(arguments));
}

void _SyncBlockCls::finish() {
    _reportTaskEvent(0, __s("E"), category, name, _jsonArguments);
    Flow tempFlow = flow;
    if (tempFlow != nullptr) {
        _reportFlowEvent(category, __sf("%s", tempFlow->id), tempFlow->_type, tempFlow->id, _argumentsAsJson(nullptr));
    }
}

void _SyncBlockCls::_startSync() {
    _reportTaskEvent(0, __s("B"), category, name, _jsonArguments);
}

String _argumentsAsJson(Map<any, any> arguments) {
    if ((arguments == nullptr) || (arguments->length() == 0)) {
        return __s("{}");
    }
    return json->encode(arguments);
}
