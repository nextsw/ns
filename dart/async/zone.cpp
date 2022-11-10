#include "zone.hpp"
void ZoneSpecificationCls::from(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, ZoneSpecification other, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask) {
    return make<ZoneSpecificationCls>(handleUncaughtError() or other->handleUncaughtError, run() or other->run, runUnary() or other->runUnary, runBinary() or other->runBinary, registerCallback() or other->registerCallback, registerUnaryCallback() or other->registerUnaryCallback, registerBinaryCallback() or other->registerBinaryCallback, errorCallback() or other->errorCallback, scheduleMicrotask() or other->scheduleMicrotask, createTimer() or other->createTimer, createPeriodicTimer() or other->createPeriodicTimer, print() or other->print, fork() or other->fork);
}

Zone ZoneCls::current() {
    return _current;
}

_Zone ZoneCls::_enter(_Zone zone) {
    assert(!identical(zone, _current));
    _Zone previous = _current;
    _current = zone;
    return previous;
}

void ZoneCls::_leave(_Zone previous) {
    assert(previous != nullptr);
    ZoneCls::_current = previous;
}

void _ZoneDelegateCls::handleUncaughtError(Object error, StackTrace stackTrace, Zone zone) {
    _delegationTarget->_processUncaughtError(zone, error, stackTrace);
}

R _ZoneDelegateCls::runtemplate<typename R> (R f() , Zone zone) {
    auto implementation = _delegationTarget->_run();
    _Zone implZone = implementation->zone;
    auto handler = as<RunHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f);
}

R _ZoneDelegateCls::runUnarytemplate<typename R, typename T> (T arg, R f(T arg) , Zone zone) {
    auto implementation = _delegationTarget->_runUnary();
    _Zone implZone = implementation->zone;
    auto handler = as<RunUnaryHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f, arg);
}

R _ZoneDelegateCls::runBinarytemplate<typename R, typename T1, typename T2> (T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) , Zone zone) {
    auto implementation = _delegationTarget->_runBinary();
    _Zone implZone = implementation->zone;
    auto handler = as<RunBinaryHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f, arg1, arg2);
}

ZoneCallback<R> _ZoneDelegateCls::registerCallbacktemplate<typename R> (R f() , Zone zone) {
    auto implementation = _delegationTarget->_registerCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f);
}

ZoneUnaryCallback<R, T> _ZoneDelegateCls::registerUnaryCallbacktemplate<typename R, typename T> (R f(T arg) , Zone zone) {
    auto implementation = _delegationTarget->_registerUnaryCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterUnaryCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f);
}

ZoneBinaryCallback<R, T1, T2> _ZoneDelegateCls::registerBinaryCallbacktemplate<typename R, typename T1, typename T2> (R f(T1 arg1, T2 arg2) , Zone zone) {
    auto implementation = _delegationTarget->_registerBinaryCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterBinaryCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate, zone, f);
}

AsyncError _ZoneDelegateCls::errorCallback(Object error, StackTrace stackTrace, Zone zone) {
    checkNotNullable(error, __s("error"));
    auto implementation = _delegationTarget->_errorCallback();
    _Zone implZone = implementation->zone;
    if (identical(implZone, _rootZone))     {
        return nullptr;
    }
    ErrorCallbackHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate, zone, error, stackTrace);
}

void _ZoneDelegateCls::scheduleMicrotask(f , Zone zone) {
    auto implementation = _delegationTarget->_scheduleMicrotask();
    _Zone implZone = implementation->zone;
    ScheduleMicrotaskHandler handler = implementation->function;
    handler(implZone, implZone->_parentDelegate, zone, f);
}

Timer _ZoneDelegateCls::createTimer(Duration duration, void f() , Zone zone) {
    auto implementation = _delegationTarget->_createTimer();
    _Zone implZone = implementation->zone;
    CreateTimerHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate, zone, duration, f);
}

Timer _ZoneDelegateCls::createPeriodicTimer(void f(Timer timer) , Duration period, Zone zone) {
    auto implementation = _delegationTarget->_createPeriodicTimer();
    _Zone implZone = implementation->zone;
    CreatePeriodicTimerHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate, zone, period, f);
}

void _ZoneDelegateCls::print(String line, Zone zone) {
    auto implementation = _delegationTarget->_print();
    _Zone implZone = implementation->zone;
    PrintHandler handler = implementation->function;
    handler(implZone, implZone->_parentDelegate, zone, line);
}

Zone _ZoneDelegateCls::fork(ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues) {
    auto implementation = _delegationTarget->_fork();
    _Zone implZone = implementation->zone;
    ForkHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate, zone, specification, zoneValues);
}

bool _ZoneCls::inSameErrorZone(Zone otherZone) {
    return identical(this, otherZone) || identical(errorZone, otherZone->errorZone);
}

void _ZoneCls::_processUncaughtError(Object error, StackTrace stackTrace, Zone zone) {
    auto implementation = _handleUncaughtError();
    _Zone implZone = implementation->zone;
    if (identical(implZone, _rootZone)) {
        _rootHandleError(error, stackTrace);
        return;
    }
    HandleUncaughtErrorHandler handler = implementation->function;
    ZoneDelegate parentDelegate = implZone->_parentDelegate;
    _Zone parentZone = implZone->parent!;
    _Zone currentZone = ZoneCls::_current;
    try {
        ZoneCls::_current = parentZone;
        handler(implZone, parentDelegate, zone, error, stackTrace);
        ZoneCls::_current = currentZone;
    } catch (Unknown e) {
        ZoneCls::_current = currentZone;
        parentZone->_processUncaughtError(implZone, e, identical(error, e)? stackTrace : s);
    };
}

Zone _CustomZoneCls::errorZone() {
    return _handleUncaughtError->zone;
}

void _CustomZoneCls::runGuarded(void f() ) {
    try {
        run(f);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

void _CustomZoneCls::runUnaryGuardedtemplate<typename T> (T arg, void f(T arg) ) {
    try {
        runUnary(f, arg);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

void _CustomZoneCls::runBinaryGuardedtemplate<typename T1, typename T2> (T1 arg1, T2 arg2, void f(T1 arg1, T2 arg2) ) {
    try {
        runBinary(f, arg1, arg2);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

ZoneCallback<R> _CustomZoneCls::bindCallbacktemplate<typename R> (R f() ) {
    auto registered = registerCallback(f);
    return [=] ()     {
        this->run(registered);
    };
}

ZoneUnaryCallback<R, T> _CustomZoneCls::bindUnaryCallbacktemplate<typename R, typename T> (R f(T arg) ) {
    auto registered = registerUnaryCallback(f);
    return [=] (Unknown  arg)     {
        this->runUnary(registered, arg);
    };
}

ZoneBinaryCallback<R, T1, T2> _CustomZoneCls::bindBinaryCallbacktemplate<typename R, typename T1, typename T2> (R f(T1 arg1, T2 arg2) ) {
    auto registered = registerBinaryCallback(f);
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this->runBinary(registered, arg1, arg2);
    };
}

void Function() _CustomZoneCls::bindCallbackGuarded(void f() ) {
    auto registered = registerCallback(f);
    return [=] ()     {
        this->runGuarded(registered);
    };
}

void Function(T ) _CustomZoneCls::bindUnaryCallbackGuardedtemplate<typename T> (void f(T arg) ) {
    auto registered = registerUnaryCallback(f);
    return [=] (Unknown  arg)     {
        this->runUnaryGuarded(registered, arg);
    };
}

void Function(T1 , T2 ) _CustomZoneCls::bindBinaryCallbackGuardedtemplate<typename T1, typename T2> (void f(T1 arg1, T2 arg2) ) {
    auto registered = registerBinaryCallback(f);
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this->runBinaryGuarded(registered, arg1, arg2);
    };
}

dynamic _CustomZoneCls::[](Object key) {
    auto result = _map[key];
    if (result != nullptr || _map->containsKey(key))     {
        return result;
    }
    if (parent != nullptr) {
        auto value = parent[key];
        if (value != nullptr) {
            _map[key] = value;
        }
        return value;
    }
    assert(this == _rootZone);
    return nullptr;
}

void _CustomZoneCls::handleUncaughtError(Object error, StackTrace stackTrace) {
    _processUncaughtError(this, error, stackTrace);
}

Zone _CustomZoneCls::fork(ZoneSpecification specification, Map<Object, Object> zoneValues) {
    auto implementation = this->_fork;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    ForkHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, specification, zoneValues);
}

R _CustomZoneCls::runtemplate<typename R> (R f() ) {
    auto implementation = this->_run;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f);
}

R _CustomZoneCls::runUnarytemplate<typename R, typename T> (T arg, R f(T arg) ) {
    auto implementation = this->_runUnary;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunUnaryHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f, arg);
}

R _CustomZoneCls::runBinarytemplate<typename R, typename T1, typename T2> (T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) ) {
    auto implementation = this->_runBinary;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunBinaryHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f, arg1, arg2);
}

ZoneCallback<R> _CustomZoneCls::registerCallbacktemplate<typename R> (R callback() ) {
    auto implementation = this->_registerCallback;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RegisterCallbackHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, callback);
}

ZoneUnaryCallback<R, T> _CustomZoneCls::registerUnaryCallbacktemplate<typename R, typename T> (R callback(T arg) ) {
    auto implementation = this->_registerUnaryCallback;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RegisterUnaryCallbackHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, callback);
}

ZoneBinaryCallback<R, T1, T2> _CustomZoneCls::registerBinaryCallbacktemplate<typename R, typename T1, typename T2> (R callback(T1 arg1, T2 arg2) ) {
    auto implementation = this->_registerBinaryCallback;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RegisterBinaryCallbackHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, callback);
}

AsyncError _CustomZoneCls::errorCallback(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    auto implementation = this->_errorCallback;
    _Zone implementationZone = implementation->zone;
    if (identical(implementationZone, _rootZone))     {
        return nullptr;
    }
    ZoneDelegate parentDelegate = implementationZone->_parentDelegate;
    ErrorCallbackHandler handler = implementation->function;
    return handler(implementationZone, parentDelegate, this, error, stackTrace);
}

void _CustomZoneCls::scheduleMicrotask(void f() ) {
    auto implementation = this->_scheduleMicrotask;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    ScheduleMicrotaskHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, f);
}

Timer _CustomZoneCls::createTimer(Duration duration, void f() ) {
    auto implementation = this->_createTimer;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    CreateTimerHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, duration, f);
}

Timer _CustomZoneCls::createPeriodicTimer(Duration duration, void f(Timer timer) ) {
    auto implementation = this->_createPeriodicTimer;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    CreatePeriodicTimerHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, duration, f);
}

void _CustomZoneCls::print(String line) {
    auto implementation = this->_print;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    PrintHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, line);
}

ZoneDelegate _CustomZoneCls::_delegate() {
    return _delegateCache ??= make<_ZoneDelegateCls>(this);
}

ZoneDelegate _CustomZoneCls::_parentDelegate() {
    return parent->_delegate();
}

_CustomZoneCls::_CustomZoneCls(Map<Object, Object> _map, _Zone parent, ZoneSpecification specification) {
    {
        _run = parent->_run;
        _runUnary = parent->_runUnary;
        _runBinary = parent->_runBinary;
        _registerCallback = parent->_registerCallback;
        _registerUnaryCallback = parent->_registerUnaryCallback;
        _registerBinaryCallback = parent->_registerBinaryCallback;
        _errorCallback = parent->_errorCallback;
        _scheduleMicrotask = parent->_scheduleMicrotask;
        _createTimer = parent->_createTimer;
        _createPeriodicTimer = parent->_createPeriodicTimer;
        _print = parent->_print;
        _fork = parent->_fork;
        _handleUncaughtError = parent->_handleUncaughtError;
    }
    {
        auto run = specification->run;
        if (run != nullptr) {
            _run = <RunHandler>make<_ZoneFunctionCls>(this, run);
        }
        auto runUnary = specification->runUnary;
        if (runUnary != nullptr) {
            _runUnary = <RunUnaryHandler>make<_ZoneFunctionCls>(this, runUnary);
        }
        auto runBinary = specification->runBinary;
        if (runBinary != nullptr) {
            _runBinary = <RunBinaryHandler>make<_ZoneFunctionCls>(this, runBinary);
        }
        auto registerCallback = specification->registerCallback;
        if (registerCallback != nullptr) {
            _registerCallback = <RegisterCallbackHandler>make<_ZoneFunctionCls>(this, registerCallback);
        }
        auto registerUnaryCallback = specification->registerUnaryCallback;
        if (registerUnaryCallback != nullptr) {
            _registerUnaryCallback = <RegisterUnaryCallbackHandler>make<_ZoneFunctionCls>(this, registerUnaryCallback);
        }
        auto registerBinaryCallback = specification->registerBinaryCallback;
        if (registerBinaryCallback != nullptr) {
            _registerBinaryCallback = <RegisterBinaryCallbackHandler>make<_ZoneFunctionCls>(this, registerBinaryCallback);
        }
        auto errorCallback = specification->errorCallback;
        if (errorCallback != nullptr) {
            _errorCallback = <ErrorCallbackHandler>make<_ZoneFunctionCls>(this, errorCallback);
        }
        auto scheduleMicrotask = specification->scheduleMicrotask;
        if (scheduleMicrotask != nullptr) {
            _scheduleMicrotask = <ScheduleMicrotaskHandler>make<_ZoneFunctionCls>(this, scheduleMicrotask);
        }
        auto createTimer = specification->createTimer;
        if (createTimer != nullptr) {
            _createTimer = <CreateTimerHandler>make<_ZoneFunctionCls>(this, createTimer);
        }
        auto createPeriodicTimer = specification->createPeriodicTimer;
        if (createPeriodicTimer != nullptr) {
            _createPeriodicTimer = <CreatePeriodicTimerHandler>make<_ZoneFunctionCls>(this, createPeriodicTimer);
        }
        auto print = specification->print;
        if (print != nullptr) {
            _print = <PrintHandler>make<_ZoneFunctionCls>(this, print);
        }
        auto fork = specification->fork;
        if (fork != nullptr) {
            _fork = <ForkHandler>make<_ZoneFunctionCls>(this, fork);
        }
        auto handleUncaughtError = specification->handleUncaughtError;
        if (handleUncaughtError != nullptr) {
            _handleUncaughtError = <HandleUncaughtErrorHandler>make<_ZoneFunctionCls>(this, handleUncaughtError);
        }
    }
}

void _rootHandleUncaughtError(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone) {
    _rootHandleError(error, stackTrace);
}

void _rootHandleError(Object error, StackTrace stackTrace) {
    _schedulePriorityAsyncCallback([=] () {
        ErrorCls->throwWithStackTrace(error, stackTrace);
    });
}

R _rootRuntemplate<typename R> (R f() , ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(ZoneCls::_current, zone))     {
        return f();
    }
    if (!is<_Zone>(zone)) {
        ;
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f();
    } finally {
        ZoneCls->_leave(old);
    };
}

R _rootRunUnarytemplate<typename R, typename T> (T arg, R f(T arg) , ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(ZoneCls::_current, zone))     {
        return f(arg);
    }
    if (!is<_Zone>(zone)) {
        ;
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f(arg);
    } finally {
        ZoneCls->_leave(old);
    };
}

R _rootRunBinarytemplate<typename R, typename T1, typename T2> (T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) , ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(ZoneCls::_current, zone))     {
        return f(arg1, arg2);
    }
    if (!is<_Zone>(zone)) {
        ;
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f(arg1, arg2);
    } finally {
        ZoneCls->_leave(old);
    };
}

ZoneCallback<R> _rootRegisterCallbacktemplate<typename R> (R f() , ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

ZoneUnaryCallback<R, T> _rootRegisterUnaryCallbacktemplate<typename R, typename T> (R f(T arg) , ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallbacktemplate<typename R, typename T1, typename T2> (R f(T1 arg1, T2 arg2) , ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

AsyncError _rootErrorCallback(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone) {
    return nullptr;
}

void _rootScheduleMicrotask(void f() , ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        bool hasErrorHandler = !_rootZone->inSameErrorZone(zone);
        if (hasErrorHandler) {
            f = zone->bindCallbackGuarded(f);
        } else {
            f = zone->bindCallback(f);
        }
    }
    _scheduleAsyncCallback(f);
}

Timer _rootCreateTimer(void callback() , Duration duration, ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        callback = zone->bindCallback(callback);
    }
    return TimerCls->_createTimer(duration, callback);
}

Timer _rootCreatePeriodicTimer(void callback(Timer timer) , Duration duration, ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        callback = zone-><void, Timer>bindUnaryCallback(callback);
    }
    return TimerCls->_createPeriodicTimer(duration, callback);
}

void _rootPrint(String line, ZoneDelegate parent, Zone self, Zone zone) {
    printToConsole(line);
}

void _printToZone(String line) {
    ZoneCls::current->print(line);
}

Zone _rootFork(ZoneDelegate parent, Zone self, ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues) {
    if (!is<_Zone>(zone)) {
        ;
    }
    printToZone = _printToZone;
    if (specification == nullptr) {
        specification = make<ZoneSpecificationCls>();
    } else     {
        if (!is<_ZoneSpecification>(specification)) {
        specification = ZoneSpecificationCls->from(specification);
    }
;
    }    Map<Object, Object> valueMap;
    if (zoneValues == nullptr) {
        valueMap = zone->_map;
    } else {
        valueMap = <Object, Object>from(zoneValues);
    }
    if (specification == nullptr)     {
        ;
    }
    return make<_CustomZoneCls>(zone, specification, valueMap);
}

_Zone _RootZoneCls::parent() {
    return nullptr;
}

Zone _RootZoneCls::errorZone() {
    return this;
}

void _RootZoneCls::runGuarded(void f() ) {
    try {
        if (identical(_rootZone, ZoneCls::_current)) {
            f();
            return;
        }
        _rootRun(nullptr, nullptr, this, f);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

void _RootZoneCls::runUnaryGuardedtemplate<typename T> (T arg, void f(T arg) ) {
    try {
        if (identical(_rootZone, ZoneCls::_current)) {
            f(arg);
            return;
        }
        _rootRunUnary(nullptr, nullptr, this, f, arg);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

void _RootZoneCls::runBinaryGuardedtemplate<typename T1, typename T2> (T1 arg1, T2 arg2, void f(T1 arg1, T2 arg2) ) {
    try {
        if (identical(_rootZone, ZoneCls::_current)) {
            f(arg1, arg2);
            return;
        }
        _rootRunBinary(nullptr, nullptr, this, f, arg1, arg2);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

ZoneCallback<R> _RootZoneCls::bindCallbacktemplate<typename R> (R f() ) {
    return [=] ()     {
        this-><R>run(f);
    };
}

ZoneUnaryCallback<R, T> _RootZoneCls::bindUnaryCallbacktemplate<typename R, typename T> (R f(T arg) ) {
    return [=] (Unknown  arg)     {
        this-><R, T>runUnary(f, arg);
    };
}

ZoneBinaryCallback<R, T1, T2> _RootZoneCls::bindBinaryCallbacktemplate<typename R, typename T1, typename T2> (R f(T1 arg1, T2 arg2) ) {
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this-><R, T1, T2>runBinary(f, arg1, arg2);
    };
}

void Function() _RootZoneCls::bindCallbackGuarded(void f() ) {
    return [=] ()     {
        this->runGuarded(f);
    };
}

void Function(T ) _RootZoneCls::bindUnaryCallbackGuardedtemplate<typename T> (void f(T arg) ) {
    return [=] (Unknown  arg)     {
        this->runUnaryGuarded(f, arg);
    };
}

void Function(T1 , T2 ) _RootZoneCls::bindBinaryCallbackGuardedtemplate<typename T1, typename T2> (void f(T1 arg1, T2 arg2) ) {
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this->runBinaryGuarded(f, arg1, arg2);
    };
}

dynamic _RootZoneCls::[](Object key) {
    return nullptr;
}

void _RootZoneCls::handleUncaughtError(Object error, StackTrace stackTrace) {
    _rootHandleError(error, stackTrace);
}

Zone _RootZoneCls::fork(ZoneSpecification specification, Map<Object, Object> zoneValues) {
    return _rootFork(nullptr, nullptr, this, specification, zoneValues);
}

R _RootZoneCls::runtemplate<typename R> (R f() ) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f();
    }
    return _rootRun(nullptr, nullptr, this, f);
}

R _RootZoneCls::runUnarytemplate<typename R, typename T> (T arg, R f(T arg) ) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f(arg);
    }
    return _rootRunUnary(nullptr, nullptr, this, f, arg);
}

R _RootZoneCls::runBinarytemplate<typename R, typename T1, typename T2> (T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) ) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f(arg1, arg2);
    }
    return _rootRunBinary(nullptr, nullptr, this, f, arg1, arg2);
}

ZoneCallback<R> _RootZoneCls::registerCallbacktemplate<typename R> (R f() ) {
    return f;
}

ZoneUnaryCallback<R, T> _RootZoneCls::registerUnaryCallbacktemplate<typename R, typename T> (R f(T arg) ) {
    return f;
}

ZoneBinaryCallback<R, T1, T2> _RootZoneCls::registerBinaryCallbacktemplate<typename R, typename T1, typename T2> (R f(T1 arg1, T2 arg2) ) {
    return f;
}

AsyncError _RootZoneCls::errorCallback(Object error, StackTrace stackTrace) {
    return nullptr;
}

void _RootZoneCls::scheduleMicrotask(void f() ) {
    _rootScheduleMicrotask(nullptr, nullptr, this, f);
}

Timer _RootZoneCls::createTimer(Duration duration, void f() ) {
    return TimerCls->_createTimer(duration, f);
}

Timer _RootZoneCls::createPeriodicTimer(Duration duration, void f(Timer timer) ) {
    return TimerCls->_createPeriodicTimer(duration, f);
}

void _RootZoneCls::print(String line) {
    printToConsole(line);
}

_ZoneFunction<RunHandler> _RootZoneCls::_run() {
    return <RunHandler>make<_ZoneFunctionCls>(_rootZone, _rootRun);
}

_ZoneFunction<RunUnaryHandler> _RootZoneCls::_runUnary() {
    return <RunUnaryHandler>make<_ZoneFunctionCls>(_rootZone, _rootRunUnary);
}

_ZoneFunction<RunBinaryHandler> _RootZoneCls::_runBinary() {
    return <RunBinaryHandler>make<_ZoneFunctionCls>(_rootZone, _rootRunBinary);
}

_ZoneFunction<RegisterCallbackHandler> _RootZoneCls::_registerCallback() {
    return <RegisterCallbackHandler>make<_ZoneFunctionCls>(_rootZone, _rootRegisterCallback);
}

_ZoneFunction<RegisterUnaryCallbackHandler> _RootZoneCls::_registerUnaryCallback() {
    return <RegisterUnaryCallbackHandler>make<_ZoneFunctionCls>(_rootZone, _rootRegisterUnaryCallback);
}

_ZoneFunction<RegisterBinaryCallbackHandler> _RootZoneCls::_registerBinaryCallback() {
    return <RegisterBinaryCallbackHandler>make<_ZoneFunctionCls>(_rootZone, _rootRegisterBinaryCallback);
}

_ZoneFunction<ErrorCallbackHandler> _RootZoneCls::_errorCallback() {
    return <ErrorCallbackHandler>make<_ZoneFunctionCls>(_rootZone, _rootErrorCallback);
}

_ZoneFunction<ScheduleMicrotaskHandler> _RootZoneCls::_scheduleMicrotask() {
    return <ScheduleMicrotaskHandler>make<_ZoneFunctionCls>(_rootZone, _rootScheduleMicrotask);
}

_ZoneFunction<CreateTimerHandler> _RootZoneCls::_createTimer() {
    return <CreateTimerHandler>make<_ZoneFunctionCls>(_rootZone, _rootCreateTimer);
}

_ZoneFunction<CreatePeriodicTimerHandler> _RootZoneCls::_createPeriodicTimer() {
    return <CreatePeriodicTimerHandler>make<_ZoneFunctionCls>(_rootZone, _rootCreatePeriodicTimer);
}

_ZoneFunction<PrintHandler> _RootZoneCls::_print() {
    return <PrintHandler>make<_ZoneFunctionCls>(_rootZone, _rootPrint);
}

_ZoneFunction<ForkHandler> _RootZoneCls::_fork() {
    return <ForkHandler>make<_ZoneFunctionCls>(_rootZone, _rootFork);
}

_ZoneFunction<HandleUncaughtErrorHandler> _RootZoneCls::_handleUncaughtError() {
    return <HandleUncaughtErrorHandler>make<_ZoneFunctionCls>(_rootZone, _rootHandleUncaughtError);
}

Map<Object, Object> _RootZoneCls::_map() {
    return _rootMap;
}

ZoneDelegate _RootZoneCls::_delegate() {
    return _rootDelegate ??= make<_ZoneDelegateCls>(this);
}

ZoneDelegate _RootZoneCls::_parentDelegate() {
    return _delegate();
}

R runZonedtemplate<typename R> (R body() , void  onError() , ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
    checkNotNullable(body, __s("body"));
    if (onError != nullptr) {
        if (!is<void Function(Object , StackTrace )>(onError)) {
            if (is<void Function(Object )>(onError)) {
                auto originalOnError = onError;
                onError = [=] (Object error,StackTrace stack)                 {
                    originalOnError(error);
                };
            } else {
                ;
            }
        }
        return as<R>(runZonedGuarded(body, onErrorzoneSpecification, zoneValues));
    }
    return <R>_runZoned(body, zoneValues, zoneSpecification);
}

R runZonedGuardedtemplate<typename R> (R body() , void onError(Object error, StackTrace stack) , ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
    checkNotNullable(body, __s("body"));
    checkNotNullable(onError, __s("onError"));
    _Zone parentZone = ZoneCls::_current;
    HandleUncaughtErrorHandler errorHandler = [=] (Zone self,ZoneDelegate parent,Zone zone,Object error,StackTrace stackTrace) {
    try {
        parentZone->runBinary(onError, error, stackTrace);
    } catch (Unknown e) {
        if (identical(e, error)) {
            parent->handleUncaughtError(zone, error, stackTrace);
        } else {
            parent->handleUncaughtError(zone, e, s);
        }
    };
};
    if (zoneSpecification == nullptr) {
        zoneSpecification = make<ZoneSpecificationCls>(errorHandler);
    } else {
        zoneSpecification = ZoneSpecificationCls->from(zoneSpecificationerrorHandler);
    }
    try {
        return <R>_runZoned(body, zoneValues, zoneSpecification);
    } catch (Unknown error) {
        onError(error, stackTrace);
    };
    return nullptr;
}

R _runZonedtemplate<typename R> (R body() , ZoneSpecification specification, Map<Object, Object> zoneValues) {
    return ZoneCls::current->fork(specification, zoneValues)-><R>run(body);
}
