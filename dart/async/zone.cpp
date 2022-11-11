#include "zone.hpp"
void ZoneSpecificationCls::from(ZoneSpecification other, CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask) {
    return make<ZoneSpecificationCls>(handleUncaughtError | other->handleUncaughtError, run | other->run, runUnary | other->runUnary, runBinary | other->runBinary, registerCallback | other->registerCallback, registerUnaryCallback | other->registerUnaryCallback, registerBinaryCallback | other->registerBinaryCallback, errorCallback | other->errorCallback, scheduleMicrotask | other->scheduleMicrotask, createTimer | other->createTimer, createPeriodicTimer | other->createPeriodicTimer, print | other->print, fork | other->fork);
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

void _ZoneDelegateCls::handleUncaughtError(Zone zone, Object error, StackTrace stackTrace) {
    _delegationTarget->_processUncaughtError(zone, error, stackTrace);
}

template<typename R>
R _ZoneDelegateCls::run(Zone zone, std::function<R()> f) {
    auto implementation = _delegationTarget->_run();
    _Zone implZone = implementation->zone;
    auto handler = as<RunHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f);
}

template<typename R, typename T>
R _ZoneDelegateCls::runUnary(Zone zone, std::function<R(T arg)> f, T arg) {
    auto implementation = _delegationTarget->_runUnary();
    _Zone implZone = implementation->zone;
    auto handler = as<RunUnaryHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f, arg);
}

template<typename R, typename T1, typename T2>
R _ZoneDelegateCls::runBinary(Zone zone, std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
    auto implementation = _delegationTarget->_runBinary();
    _Zone implZone = implementation->zone;
    auto handler = as<RunBinaryHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f, arg1, arg2);
}

template<typename R>
ZoneCallback<R> _ZoneDelegateCls::registerCallback(Zone zone, std::function<R()> f) {
    auto implementation = _delegationTarget->_registerCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f);
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _ZoneDelegateCls::registerUnaryCallback(Zone zone, std::function<R(T arg)> f) {
    auto implementation = _delegationTarget->_registerUnaryCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterUnaryCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f);
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _ZoneDelegateCls::registerBinaryCallback(Zone zone, std::function<R(T1 arg1, T2 arg2)> f) {
    auto implementation = _delegationTarget->_registerBinaryCallback();
    _Zone implZone = implementation->zone;
    auto handler = as<RegisterBinaryCallbackHandler>(implementation->function);
    return handler(implZone, implZone->_parentDelegate(), zone, f);
}

AsyncError _ZoneDelegateCls::errorCallback(Zone zone, Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    auto implementation = _delegationTarget->_errorCallback();
    _Zone implZone = implementation->zone;
    if (identical(implZone, _rootZone))     {
        return nullptr;
    }
    ErrorCallbackHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate(), zone, error, stackTrace);
}

void _ZoneDelegateCls::scheduleMicrotask(Zone zone, f ) {
    auto implementation = _delegationTarget->_scheduleMicrotask();
    _Zone implZone = implementation->zone;
    ScheduleMicrotaskHandler handler = implementation->function;
    handler(implZone, implZone->_parentDelegate(), zone, f);
}

Timer _ZoneDelegateCls::createTimer(Zone zone, Duration duration, std::function<void()> f) {
    auto implementation = _delegationTarget->_createTimer();
    _Zone implZone = implementation->zone;
    CreateTimerHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate(), zone, duration, f);
}

Timer _ZoneDelegateCls::createPeriodicTimer(Zone zone, Duration period, std::function<void(Timer timer)> f) {
    auto implementation = _delegationTarget->_createPeriodicTimer();
    _Zone implZone = implementation->zone;
    CreatePeriodicTimerHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate(), zone, period, f);
}

void _ZoneDelegateCls::print(Zone zone, String line) {
    auto implementation = _delegationTarget->_print();
    _Zone implZone = implementation->zone;
    PrintHandler handler = implementation->function;
    handler(implZone, implZone->_parentDelegate(), zone, line);
}

Zone _ZoneDelegateCls::fork(Zone zone, ZoneSpecification specification, Map<Object, Object> zoneValues) {
    auto implementation = _delegationTarget->_fork();
    _Zone implZone = implementation->zone;
    ForkHandler handler = implementation->function;
    return handler(implZone, implZone->_parentDelegate(), zone, specification, zoneValues);
}

bool _ZoneCls::inSameErrorZone(Zone otherZone) {
    return identical(this, otherZone) || identical(errorZone, otherZone->errorZone());
}

void _ZoneCls::_processUncaughtError(Zone zone, Object error, StackTrace stackTrace) {
    auto implementation = _handleUncaughtError();
    _Zone implZone = implementation->zone;
    if (identical(implZone, _rootZone)) {
        _rootHandleError(error, stackTrace);
        return;
    }
    HandleUncaughtErrorHandler handler = implementation->function;
    ZoneDelegate parentDelegate = implZone->_parentDelegate();
    _Zone parentZone = implZone->parent()!;
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

void _CustomZoneCls::runGuarded(std::function<void()> f) {
    try {
        run(f);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

template<typename T>
void _CustomZoneCls::runUnaryGuarded(std::function<void(T arg)> f, T arg) {
    try {
        runUnary(f, arg);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

template<typename T1, typename T2>
void _CustomZoneCls::runBinaryGuarded(std::function<void(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
    try {
        runBinary(f, arg1, arg2);
    } catch (Unknown e) {
        handleUncaughtError(e, s);
    };
}

template<typename R>
ZoneCallback<R> _CustomZoneCls::bindCallback(std::function<R()> f) {
    auto registered = registerCallback(f);
    return [=] ()     {
        this->run(registered);
    };
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _CustomZoneCls::bindUnaryCallback(std::function<R(T arg)> f) {
    auto registered = registerUnaryCallback(f);
    return [=] (Unknown  arg)     {
        this->runUnary(registered, arg);
    };
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _CustomZoneCls::bindBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f) {
    auto registered = registerBinaryCallback(f);
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this->runBinary(registered, arg1, arg2);
    };
}

std::function<void()> _CustomZoneCls::bindCallbackGuarded(std::function<void()> f) {
    auto registered = registerCallback(f);
    return [=] ()     {
        this->runGuarded(registered);
    };
}

template<typename T>
std::function<void(T )> _CustomZoneCls::bindUnaryCallbackGuarded(std::function<void(T arg)> f) {
    auto registered = registerUnaryCallback(f);
    return [=] (Unknown  arg)     {
        this->runUnaryGuarded(registered, arg);
    };
}

template<typename T1, typename T2>
std::function<void(T1 , T2 )> _CustomZoneCls::bindBinaryCallbackGuarded(std::function<void(T1 arg1, T2 arg2)> f) {
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

template<typename R>
R _CustomZoneCls::run(std::function<R()> f) {
    auto implementation = this->_run;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f);
}

template<typename R, typename T>
R _CustomZoneCls::runUnary(std::function<R(T arg)> f, T arg) {
    auto implementation = this->_runUnary;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunUnaryHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f, arg);
}

template<typename R, typename T1, typename T2>
R _CustomZoneCls::runBinary(std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
    auto implementation = this->_runBinary;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RunBinaryHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, f, arg1, arg2);
}

template<typename R>
ZoneCallback<R> _CustomZoneCls::registerCallback(std::function<R()> callback) {
    auto implementation = this->_registerCallback;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RegisterCallbackHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, callback);
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _CustomZoneCls::registerUnaryCallback(std::function<R(T arg)> callback) {
    auto implementation = this->_registerUnaryCallback;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    auto handler = as<RegisterUnaryCallbackHandler>(implementation->function);
    return handler(implementation->zone, parentDelegate, this, callback);
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _CustomZoneCls::registerBinaryCallback(std::function<R(T1 arg1, T2 arg2)> callback) {
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
    ZoneDelegate parentDelegate = implementationZone->_parentDelegate();
    ErrorCallbackHandler handler = implementation->function;
    return handler(implementationZone, parentDelegate, this, error, stackTrace);
}

void _CustomZoneCls::scheduleMicrotask(std::function<void()> f) {
    auto implementation = this->_scheduleMicrotask;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    ScheduleMicrotaskHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, f);
}

Timer _CustomZoneCls::createTimer(Duration duration, std::function<void()> f) {
    auto implementation = this->_createTimer;
    ZoneDelegate parentDelegate = implementation->zone->_parentDelegate();
    CreateTimerHandler handler = implementation->function;
    return handler(implementation->zone, parentDelegate, this, duration, f);
}

Timer _CustomZoneCls::createPeriodicTimer(Duration duration, std::function<void(Timer timer)> f) {
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

_CustomZoneCls::_CustomZoneCls(_Zone parent, ZoneSpecification specification, Map<Object, Object> _map) {
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
        auto run = specification->run();
        if (run != nullptr) {
            _run = <RunHandler>make<_ZoneFunctionCls>(this, run);
        }
        auto runUnary = specification->runUnary();
        if (runUnary != nullptr) {
            _runUnary = <RunUnaryHandler>make<_ZoneFunctionCls>(this, runUnary);
        }
        auto runBinary = specification->runBinary();
        if (runBinary != nullptr) {
            _runBinary = <RunBinaryHandler>make<_ZoneFunctionCls>(this, runBinary);
        }
        auto registerCallback = specification->registerCallback();
        if (registerCallback != nullptr) {
            _registerCallback = <RegisterCallbackHandler>make<_ZoneFunctionCls>(this, registerCallback);
        }
        auto registerUnaryCallback = specification->registerUnaryCallback();
        if (registerUnaryCallback != nullptr) {
            _registerUnaryCallback = <RegisterUnaryCallbackHandler>make<_ZoneFunctionCls>(this, registerUnaryCallback);
        }
        auto registerBinaryCallback = specification->registerBinaryCallback();
        if (registerBinaryCallback != nullptr) {
            _registerBinaryCallback = <RegisterBinaryCallbackHandler>make<_ZoneFunctionCls>(this, registerBinaryCallback);
        }
        auto errorCallback = specification->errorCallback();
        if (errorCallback != nullptr) {
            _errorCallback = <ErrorCallbackHandler>make<_ZoneFunctionCls>(this, errorCallback);
        }
        auto scheduleMicrotask = specification->scheduleMicrotask();
        if (scheduleMicrotask != nullptr) {
            _scheduleMicrotask = <ScheduleMicrotaskHandler>make<_ZoneFunctionCls>(this, scheduleMicrotask);
        }
        auto createTimer = specification->createTimer();
        if (createTimer != nullptr) {
            _createTimer = <CreateTimerHandler>make<_ZoneFunctionCls>(this, createTimer);
        }
        auto createPeriodicTimer = specification->createPeriodicTimer();
        if (createPeriodicTimer != nullptr) {
            _createPeriodicTimer = <CreatePeriodicTimerHandler>make<_ZoneFunctionCls>(this, createPeriodicTimer);
        }
        auto print = specification->print();
        if (print != nullptr) {
            _print = <PrintHandler>make<_ZoneFunctionCls>(this, print);
        }
        auto fork = specification->fork();
        if (fork != nullptr) {
            _fork = <ForkHandler>make<_ZoneFunctionCls>(this, fork);
        }
        auto handleUncaughtError = specification->handleUncaughtError();
        if (handleUncaughtError != nullptr) {
            _handleUncaughtError = <HandleUncaughtErrorHandler>make<_ZoneFunctionCls>(this, handleUncaughtError);
        }
    }
}

void _rootHandleUncaughtError(Zone self, ZoneDelegate parent, Zone zone, Object error, StackTrace stackTrace) {
    _rootHandleError(error, stackTrace);
}

void _rootHandleError(Object error, StackTrace stackTrace) {
    _schedulePriorityAsyncCallback([=] () {
        ErrorCls->throwWithStackTrace(error, stackTrace);
    });
}

template<typename R>
R _rootRun(Zone self, ZoneDelegate parent, Zone zone, std::function<R()> f) {
    if (identical(ZoneCls::_current, zone))     {
        return f();
    }
    if (!is<_Zone>(zone)) {
        throw ArgumentErrorCls->value(as<_ZoneCls>(zone), __s("zone"), __s("Can only run in platform zones"));
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f();
    } finally {
        ZoneCls->_leave(old);
    };
}

template<typename R, typename T>
R _rootRunUnary(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T arg)> f, T arg) {
    if (identical(ZoneCls::_current, zone))     {
        return f(arg);
    }
    if (!is<_Zone>(zone)) {
        throw ArgumentErrorCls->value(as<_ZoneCls>(zone), __s("zone"), __s("Can only run in platform zones"));
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f(arg);
    } finally {
        ZoneCls->_leave(old);
    };
}

template<typename R, typename T1, typename T2>
R _rootRunBinary(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
    if (identical(ZoneCls::_current, zone))     {
        return f(arg1, arg2);
    }
    if (!is<_Zone>(zone)) {
        throw ArgumentErrorCls->value(as<_ZoneCls>(zone), __s("zone"), __s("Can only run in platform zones"));
    }
    _Zone old = ZoneCls->_enter(zone);
    try {
        return f(arg1, arg2);
    } finally {
        ZoneCls->_leave(old);
    };
}

template<typename R>
ZoneCallback<R> _rootRegisterCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R()> f) {
    return f;
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _rootRegisterUnaryCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T arg)> f) {
    return f;
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T1 arg1, T2 arg2)> f) {
    return f;
}

AsyncError _rootErrorCallback(Zone self, ZoneDelegate parent, Zone zone, Object error, StackTrace stackTrace) {
    return nullptr;
}

void _rootScheduleMicrotask(Zone self, ZoneDelegate parent, Zone zone, std::function<void()> f) {
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

Timer _rootCreateTimer(Zone self, ZoneDelegate parent, Zone zone, Duration duration, std::function<void()> callback) {
    if (!identical(_rootZone, zone)) {
        callback = zone->bindCallback(callback);
    }
    return TimerCls->_createTimer(duration, callback);
}

Timer _rootCreatePeriodicTimer(Zone self, ZoneDelegate parent, Zone zone, Duration duration, std::function<void(Timer timer)> callback) {
    if (!identical(_rootZone, zone)) {
        callback = zone-><void, Timer>bindUnaryCallback(callback);
    }
    return TimerCls->_createPeriodicTimer(duration, callback);
}

void _rootPrint(Zone self, ZoneDelegate parent, Zone zone, String line) {
    printToConsole(line);
}

void _printToZone(String line) {
    ZoneCls::current->print(line);
}

Zone _rootFork(Zone self, ZoneDelegate parent, Zone zone, ZoneSpecification specification, Map<Object, Object> zoneValues) {
    if (!is<_Zone>(zone)) {
        throw ArgumentErrorCls->value(as<_ZoneCls>(zone), __s("zone"), __s("Can only fork a platform zone"));
    }
    printToZone = _printToZone;
    if (specification == nullptr) {
        specification = make<ZoneSpecificationCls>();
    } else     {
        if (!is<_ZoneSpecification>(specification)) {
        as<_ZoneSpecificationCls>(specification) = ZoneSpecificationCls->from(as<_ZoneSpecificationCls>(specification));
    }
;
    }    Map<Object, Object> valueMap;
    if (zoneValues == nullptr) {
        valueMap = zone->_map;
    } else {
        valueMap = <Object, Object>from(zoneValues);
    }
    if (specification == nullptr)     {
        throw __s("unreachable");
    }
    return make<_CustomZoneCls>(zone, specification, valueMap);
}

_Zone _RootZoneCls::parent() {
    return nullptr;
}

Zone _RootZoneCls::errorZone() {
    return this;
}

void _RootZoneCls::runGuarded(std::function<void()> f) {
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

template<typename T>
void _RootZoneCls::runUnaryGuarded(std::function<void(T arg)> f, T arg) {
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

template<typename T1, typename T2>
void _RootZoneCls::runBinaryGuarded(std::function<void(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
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

template<typename R>
ZoneCallback<R> _RootZoneCls::bindCallback(std::function<R()> f) {
    return [=] ()     {
        this-><R>run(f);
    };
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _RootZoneCls::bindUnaryCallback(std::function<R(T arg)> f) {
    return [=] (Unknown  arg)     {
        this-><R, T>runUnary(f, arg);
    };
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _RootZoneCls::bindBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f) {
    return [=] (Unknown  arg1,Unknown  arg2)     {
        this-><R, T1, T2>runBinary(f, arg1, arg2);
    };
}

std::function<void()> _RootZoneCls::bindCallbackGuarded(std::function<void()> f) {
    return [=] ()     {
        this->runGuarded(f);
    };
}

template<typename T>
std::function<void(T )> _RootZoneCls::bindUnaryCallbackGuarded(std::function<void(T arg)> f) {
    return [=] (Unknown  arg)     {
        this->runUnaryGuarded(f, arg);
    };
}

template<typename T1, typename T2>
std::function<void(T1 , T2 )> _RootZoneCls::bindBinaryCallbackGuarded(std::function<void(T1 arg1, T2 arg2)> f) {
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

template<typename R>
R _RootZoneCls::run(std::function<R()> f) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f();
    }
    return _rootRun(nullptr, nullptr, this, f);
}

template<typename R, typename T>
R _RootZoneCls::runUnary(std::function<R(T arg)> f, T arg) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f(arg);
    }
    return _rootRunUnary(nullptr, nullptr, this, f, arg);
}

template<typename R, typename T1, typename T2>
R _RootZoneCls::runBinary(std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2) {
    if (identical(ZoneCls::_current, _rootZone))     {
        return f(arg1, arg2);
    }
    return _rootRunBinary(nullptr, nullptr, this, f, arg1, arg2);
}

template<typename R>
ZoneCallback<R> _RootZoneCls::registerCallback(std::function<R()> f) {
    return f;
}

template<typename R, typename T>
ZoneUnaryCallback<R, T> _RootZoneCls::registerUnaryCallback(std::function<R(T arg)> f) {
    return f;
}

template<typename R, typename T1, typename T2>
ZoneBinaryCallback<R, T1, T2> _RootZoneCls::registerBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f) {
    return f;
}

AsyncError _RootZoneCls::errorCallback(Object error, StackTrace stackTrace) {
    return nullptr;
}

void _RootZoneCls::scheduleMicrotask(std::function<void()> f) {
    _rootScheduleMicrotask(nullptr, nullptr, this, f);
}

Timer _RootZoneCls::createTimer(Duration duration, std::function<void()> f) {
    return TimerCls->_createTimer(duration, f);
}

Timer _RootZoneCls::createPeriodicTimer(Duration duration, std::function<void(Timer timer)> f) {
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

template<typename R>
R runZoned(std::function<R()> body, std::function<void ()> onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
    checkNotNullable(body, __s("body"));
    if (onError != nullptr) {
        if (!is<std::function<void(Object , StackTrace )>>(onError)) {
            if (is<std::function<void(Object )>>(onError)) {
                auto originalOnError = onError;
                onError = [=] (Object error,StackTrace stack)                 {
                    originalOnError(error);
                };
            } else {
                throw ArgumentErrorCls->value(onError, __s("onError"), __s("Must be Function(Object) or Function(Object, StackTrace)"));
            }
        }
        return as<R>(runZonedGuarded(body, onError, zoneSpecification, zoneValues));
    }
    return <R>_runZoned(body, zoneValues, zoneSpecification);
}

template<typename R>
R runZonedGuarded(std::function<R()> body, std::function<void(Object error, StackTrace stack)> onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
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
        zoneSpecification = ZoneSpecificationCls->from(zoneSpecification, errorHandler);
    }
    try {
        return <R>_runZoned(body, zoneValues, zoneSpecification);
    } catch (Unknown error) {
        onError(error, stackTrace);
    };
    return nullptr;
}

template<typename R>
R _runZoned(std::function<R()> body, Map<Object, Object> zoneValues, ZoneSpecification specification) {
    return ZoneCls::current->fork(specification, zoneValues)-><R>run(body);
}
