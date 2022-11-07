#include "zone.hpp"
void ZoneSpecification::from(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, ZoneSpecification other, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask) {
    return ZoneSpecification(handleUncaughtError ?? other.handleUncaughtError, run ?? other.run, runUnary ?? other.runUnary, runBinary ?? other.runBinary, registerCallback ?? other.registerCallback, registerUnaryCallback ?? other.registerUnaryCallback, registerBinaryCallback ?? other.registerBinaryCallback, errorCallback ?? other.errorCallback, scheduleMicrotask ?? other.scheduleMicrotask, createTimer ?? other.createTimer, createPeriodicTimer ?? other.createPeriodicTimer, print ?? other.print, fork ?? other.fork);
}

Zone Zone::current() {
    return _current;
}

_Zone Zone::_enter(_Zone zone) {
    assert(!identical(zone, _current));
    _Zone previous = _current;
    _current = zone;
    return previous;
}

void Zone::_leave(_Zone previous) {
    assert(previous != nullptr);
    Zone._current = previous;
}

void _ZoneDelegate::handleUncaughtError(Object error, StackTrace stackTrace, Zone zone) {
    _delegationTarget._processUncaughtError(zone, error, stackTrace);
}

R _ZoneDelegate::run<R>(FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._run;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f);
}

R _ZoneDelegate::runUnary<R, T>(T arg, FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._runUnary;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f, arg);
}

R _ZoneDelegate::runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._runBinary;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f, arg1, arg2);
}

ZoneCallback<R> _ZoneDelegate::registerCallback<R>(FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._registerCallback;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f);
}

ZoneUnaryCallback<R, T> _ZoneDelegate::registerUnaryCallback<R, T>(FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._registerUnaryCallback;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f);
}

ZoneBinaryCallback<R, T1, T2> _ZoneDelegate::registerBinaryCallback<R, T1, T2>(FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._registerBinaryCallback;
    _Zone implZone = implementation.zone;
    auto handler = (;
    return handler(implZone, implZone._parentDelegate, zone, f);
}

AsyncError _ZoneDelegate::errorCallback(Object error, StackTrace stackTrace, Zone zone) {
    checkNotNullable(error, "error");
    auto implementation = _delegationTarget._errorCallback;
    _Zone implZone = implementation.zone;
    if (identical(implZone, _rootZone))     {
        return nullptr;
    }
    ErrorCallbackHandler handler = implementation.function;
    return handler(implZone, implZone._parentDelegate, zone, error, stackTrace);
}

void _ZoneDelegate::scheduleMicrotask(f , Zone zone) {
    auto implementation = _delegationTarget._scheduleMicrotask;
    _Zone implZone = implementation.zone;
    ScheduleMicrotaskHandler handler = implementation.function;
    handler(implZone, implZone._parentDelegate, zone, f);
}

Timer _ZoneDelegate::createTimer(Duration duration, FunctionType f, Zone zone) {
    auto implementation = _delegationTarget._createTimer;
    _Zone implZone = implementation.zone;
    CreateTimerHandler handler = implementation.function;
    return handler(implZone, implZone._parentDelegate, zone, duration, f);
}

Timer _ZoneDelegate::createPeriodicTimer(FunctionType f, Duration period, Zone zone) {
    auto implementation = _delegationTarget._createPeriodicTimer;
    _Zone implZone = implementation.zone;
    CreatePeriodicTimerHandler handler = implementation.function;
    return handler(implZone, implZone._parentDelegate, zone, period, f);
}

void _ZoneDelegate::print(String line, Zone zone) {
    auto implementation = _delegationTarget._print;
    _Zone implZone = implementation.zone;
    PrintHandler handler = implementation.function;
    handler(implZone, implZone._parentDelegate, zone, line);
}

Zone _ZoneDelegate::fork(ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues) {
    auto implementation = _delegationTarget._fork;
    _Zone implZone = implementation.zone;
    ForkHandler handler = implementation.function;
    return handler(implZone, implZone._parentDelegate, zone, specification, zoneValues);
}

bool _Zone::inSameErrorZone(Zone otherZone) {
    return identical(this, otherZone) || identical(errorZone, otherZone.errorZone);
}

void _Zone::_processUncaughtError(Object error, StackTrace stackTrace, Zone zone) {
    auto implementation = _handleUncaughtError;
    _Zone implZone = implementation.zone;
    if (identical(implZone, _rootZone)) {
        _rootHandleError(error, stackTrace);
        return;
    }
    HandleUncaughtErrorHandler handler = implementation.function;
    ZoneDelegate parentDelegate = implZone._parentDelegate;
    _Zone parentZone = implZone.parent!;
    _Zone currentZone = Zone._current;
    ;
}

Zone _CustomZone::errorZone() {
    return _handleUncaughtError.zone;
}

void _CustomZone::runGuarded(FunctionType f) {
    ;
}

void _CustomZone::runUnaryGuarded<T>(T arg, FunctionType f) {
    ;
}

void _CustomZone::runBinaryGuarded<T1, T2>(T1 arg1, T2 arg2, FunctionType f) {
    ;
}

ZoneCallback<R> _CustomZone::bindCallback<R>(FunctionType f) {
    auto registered = registerCallback(f);
    return ;
}

ZoneUnaryCallback<R, T> _CustomZone::bindUnaryCallback<R, T>(FunctionType f) {
    auto registered = registerUnaryCallback(f);
    return ;
}

ZoneBinaryCallback<R, T1, T2> _CustomZone::bindBinaryCallback<R, T1, T2>(FunctionType f) {
    auto registered = registerBinaryCallback(f);
    return ;
}

FunctionType _CustomZone::bindCallbackGuarded(FunctionType f) {
    auto registered = registerCallback(f);
    return ;
}

FunctionType _CustomZone::bindUnaryCallbackGuarded<T>(FunctionType f) {
    auto registered = registerUnaryCallback(f);
    return ;
}

FunctionType _CustomZone::bindBinaryCallbackGuarded<T1, T2>(FunctionType f) {
    auto registered = registerBinaryCallback(f);
    return ;
}

dynamic _CustomZone::[](Object key) {
    auto result = _map[key];
    if (result != nullptr || _map.containsKey(key))     {
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

void _CustomZone::handleUncaughtError(Object error, StackTrace stackTrace) {
    _processUncaughtError(this, error, stackTrace);
}

Zone _CustomZone::fork(ZoneSpecification specification, Map<Object, Object> zoneValues) {
    auto implementation = this._fork;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    ForkHandler handler = implementation.function;
    return handler(implementation.zone, parentDelegate, this, specification, zoneValues);
}

R _CustomZone::run<R>(FunctionType f) {
    auto implementation = this._run;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, f);
}

R _CustomZone::runUnary<R, T>(T arg, FunctionType f) {
    auto implementation = this._runUnary;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, f, arg);
}

R _CustomZone::runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f) {
    auto implementation = this._runBinary;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, f, arg1, arg2);
}

ZoneCallback<R> _CustomZone::registerCallback<R>(FunctionType callback) {
    auto implementation = this._registerCallback;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, callback);
}

ZoneUnaryCallback<R, T> _CustomZone::registerUnaryCallback<R, T>(FunctionType callback) {
    auto implementation = this._registerUnaryCallback;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, callback);
}

ZoneBinaryCallback<R, T1, T2> _CustomZone::registerBinaryCallback<R, T1, T2>(FunctionType callback) {
    auto implementation = this._registerBinaryCallback;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    auto handler = (;
    return handler(implementation.zone, parentDelegate, this, callback);
}

AsyncError _CustomZone::errorCallback(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    auto implementation = this._errorCallback;
    _Zone implementationZone = implementation.zone;
    if (identical(implementationZone, _rootZone))     {
        return nullptr;
    }
    ZoneDelegate parentDelegate = implementationZone._parentDelegate;
    ErrorCallbackHandler handler = implementation.function;
    return handler(implementationZone, parentDelegate, this, error, stackTrace);
}

void _CustomZone::scheduleMicrotask(FunctionType f) {
    auto implementation = this._scheduleMicrotask;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    ScheduleMicrotaskHandler handler = implementation.function;
    return handler(implementation.zone, parentDelegate, this, f);
}

Timer _CustomZone::createTimer(Duration duration, FunctionType f) {
    auto implementation = this._createTimer;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    CreateTimerHandler handler = implementation.function;
    return handler(implementation.zone, parentDelegate, this, duration, f);
}

Timer _CustomZone::createPeriodicTimer(Duration duration, FunctionType f) {
    auto implementation = this._createPeriodicTimer;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    CreatePeriodicTimerHandler handler = implementation.function;
    return handler(implementation.zone, parentDelegate, this, duration, f);
}

void _CustomZone::print(String line) {
    auto implementation = this._print;
    ZoneDelegate parentDelegate = implementation.zone._parentDelegate;
    PrintHandler handler = implementation.function;
    return handler(implementation.zone, parentDelegate, this, line);
}

ZoneDelegate _CustomZone::_delegate() {
    return _delegateCache ??= _ZoneDelegate(this);
}

ZoneDelegate _CustomZone::_parentDelegate() {
    return parent._delegate;
}

_CustomZone::_CustomZone(Map<Object, Object> _map, _Zone parent, ZoneSpecification specification) {
    {
        _run = parent._run;
        _runUnary = parent._runUnary;
        _runBinary = parent._runBinary;
        _registerCallback = parent._registerCallback;
        _registerUnaryCallback = parent._registerUnaryCallback;
        _registerBinaryCallback = parent._registerBinaryCallback;
        _errorCallback = parent._errorCallback;
        _scheduleMicrotask = parent._scheduleMicrotask;
        _createTimer = parent._createTimer;
        _createPeriodicTimer = parent._createPeriodicTimer;
        _print = parent._print;
        _fork = parent._fork;
        _handleUncaughtError = parent._handleUncaughtError;
    }
    {
        auto run = specification.run;
        if (run != nullptr) {
            _run = <RunHandler>_ZoneFunction(this, run);
        }
        auto runUnary = specification.runUnary;
        if (runUnary != nullptr) {
            _runUnary = <RunUnaryHandler>_ZoneFunction(this, runUnary);
        }
        auto runBinary = specification.runBinary;
        if (runBinary != nullptr) {
            _runBinary = <RunBinaryHandler>_ZoneFunction(this, runBinary);
        }
        auto registerCallback = specification.registerCallback;
        if (registerCallback != nullptr) {
            _registerCallback = <RegisterCallbackHandler>_ZoneFunction(this, registerCallback);
        }
        auto registerUnaryCallback = specification.registerUnaryCallback;
        if (registerUnaryCallback != nullptr) {
            _registerUnaryCallback = <RegisterUnaryCallbackHandler>_ZoneFunction(this, registerUnaryCallback);
        }
        auto registerBinaryCallback = specification.registerBinaryCallback;
        if (registerBinaryCallback != nullptr) {
            _registerBinaryCallback = <RegisterBinaryCallbackHandler>_ZoneFunction(this, registerBinaryCallback);
        }
        auto errorCallback = specification.errorCallback;
        if (errorCallback != nullptr) {
            _errorCallback = <ErrorCallbackHandler>_ZoneFunction(this, errorCallback);
        }
        auto scheduleMicrotask = specification.scheduleMicrotask;
        if (scheduleMicrotask != nullptr) {
            _scheduleMicrotask = <ScheduleMicrotaskHandler>_ZoneFunction(this, scheduleMicrotask);
        }
        auto createTimer = specification.createTimer;
        if (createTimer != nullptr) {
            _createTimer = <CreateTimerHandler>_ZoneFunction(this, createTimer);
        }
        auto createPeriodicTimer = specification.createPeriodicTimer;
        if (createPeriodicTimer != nullptr) {
            _createPeriodicTimer = <CreatePeriodicTimerHandler>_ZoneFunction(this, createPeriodicTimer);
        }
        auto print = specification.print;
        if (print != nullptr) {
            _print = <PrintHandler>_ZoneFunction(this, print);
        }
        auto fork = specification.fork;
        if (fork != nullptr) {
            _fork = <ForkHandler>_ZoneFunction(this, fork);
        }
        auto handleUncaughtError = specification.handleUncaughtError;
        if (handleUncaughtError != nullptr) {
            _handleUncaughtError = <HandleUncaughtErrorHandler>_ZoneFunction(this, handleUncaughtError);
        }
    }
}

void _rootHandleUncaughtError(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone) {
    _rootHandleError(error, stackTrace);
}

void _rootHandleError(Object error, StackTrace stackTrace) {
    _schedulePriorityAsyncCallback();
}

R _rootRun<R>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(Zone._current, zone))     {
        return f();
    }
    if (zone is! _Zone) {
        ;
    }
    _Zone old = Zone._enter(zone);
    ;
}

R _rootRunUnary<R, T>(T arg, FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(Zone._current, zone))     {
        return f(arg);
    }
    if (zone is! _Zone) {
        ;
    }
    _Zone old = Zone._enter(zone);
    ;
}

R _rootRunBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    if (identical(Zone._current, zone))     {
        return f(arg1, arg2);
    }
    if (zone is! _Zone) {
        ;
    }
    _Zone old = Zone._enter(zone);
    ;
}

ZoneCallback<R> _rootRegisterCallback<R>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

ZoneUnaryCallback<R, T> _rootRegisterUnaryCallback<R, T>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallback<R, T1, T2>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    return f;
}

AsyncError _rootErrorCallback(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone) {
    return nullptr;
}

void _rootScheduleMicrotask(FunctionType f, ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        bool hasErrorHandler = !_rootZone.inSameErrorZone(zone);
        if (hasErrorHandler) {
            f = zone.bindCallbackGuarded(f);
        } else {
            f = zone.bindCallback(f);
        }
    }
    _scheduleAsyncCallback(f);
}

Timer _rootCreateTimer(FunctionType callback, Duration duration, ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        callback = zone.bindCallback(callback);
    }
    return Timer._createTimer(duration, callback);
}

Timer _rootCreatePeriodicTimer(FunctionType callback, Duration duration, ZoneDelegate parent, Zone self, Zone zone) {
    if (!identical(_rootZone, zone)) {
        callback = zone.<void, Timer>bindUnaryCallback(callback);
    }
    return Timer._createPeriodicTimer(duration, callback);
}

void _rootPrint(String line, ZoneDelegate parent, Zone self, Zone zone) {
    printToConsole(line);
}

void _printToZone(String line) {
    Zone.current.print(line);
}

Zone _rootFork(ZoneDelegate parent, Zone self, ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues) {
    if (zone is! _Zone) {
        ;
    }
    printToZone = _printToZone;
    if (specification == nullptr) {
        specification = const ZoneSpecification();
    } else     {
        if (specification is! _ZoneSpecification) {
        specification = ZoneSpecification.from(specification);
    }
;
    }    Map<Object, Object> valueMap;
    if (zoneValues == nullptr) {
        valueMap = zone._map;
    } else {
        valueMap = <Object, Object>from(zoneValues);
    }
    if (specification == nullptr)     {
        ;
    }
    return _CustomZone(zone, specification, valueMap);
}

_Zone _RootZone::parent() {
    return nullptr;
}

Zone _RootZone::errorZone() {
    return this;
}

void _RootZone::runGuarded(FunctionType f) {
    ;
}

void _RootZone::runUnaryGuarded<T>(T arg, FunctionType f) {
    ;
}

void _RootZone::runBinaryGuarded<T1, T2>(T1 arg1, T2 arg2, FunctionType f) {
    ;
}

ZoneCallback<R> _RootZone::bindCallback<R>(FunctionType f) {
    return ;
}

ZoneUnaryCallback<R, T> _RootZone::bindUnaryCallback<R, T>(FunctionType f) {
    return ;
}

ZoneBinaryCallback<R, T1, T2> _RootZone::bindBinaryCallback<R, T1, T2>(FunctionType f) {
    return ;
}

FunctionType _RootZone::bindCallbackGuarded(FunctionType f) {
    return ;
}

FunctionType _RootZone::bindUnaryCallbackGuarded<T>(FunctionType f) {
    return ;
}

FunctionType _RootZone::bindBinaryCallbackGuarded<T1, T2>(FunctionType f) {
    return ;
}

dynamic _RootZone::[](Object key) {
    return nullptr;
}

void _RootZone::handleUncaughtError(Object error, StackTrace stackTrace) {
    _rootHandleError(error, stackTrace);
}

Zone _RootZone::fork(ZoneSpecification specification, Map<Object, Object> zoneValues) {
    return _rootFork(nullptr, nullptr, this, specification, zoneValues);
}

R _RootZone::run<R>(FunctionType f) {
    if (identical(Zone._current, _rootZone))     {
        return f();
    }
    return _rootRun(nullptr, nullptr, this, f);
}

R _RootZone::runUnary<R, T>(T arg, FunctionType f) {
    if (identical(Zone._current, _rootZone))     {
        return f(arg);
    }
    return _rootRunUnary(nullptr, nullptr, this, f, arg);
}

R _RootZone::runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f) {
    if (identical(Zone._current, _rootZone))     {
        return f(arg1, arg2);
    }
    return _rootRunBinary(nullptr, nullptr, this, f, arg1, arg2);
}

ZoneCallback<R> _RootZone::registerCallback<R>(FunctionType f) {
    return f;
}

ZoneUnaryCallback<R, T> _RootZone::registerUnaryCallback<R, T>(FunctionType f) {
    return f;
}

ZoneBinaryCallback<R, T1, T2> _RootZone::registerBinaryCallback<R, T1, T2>(FunctionType f) {
    return f;
}

AsyncError _RootZone::errorCallback(Object error, StackTrace stackTrace) {
    return nullptr;
}

void _RootZone::scheduleMicrotask(FunctionType f) {
    _rootScheduleMicrotask(nullptr, nullptr, this, f);
}

Timer _RootZone::createTimer(Duration duration, FunctionType f) {
    return Timer._createTimer(duration, f);
}

Timer _RootZone::createPeriodicTimer(Duration duration, FunctionType f) {
    return Timer._createPeriodicTimer(duration, f);
}

void _RootZone::print(String line) {
    printToConsole(line);
}

_ZoneFunction<RunHandler> _RootZone::_run() {
    return const <RunHandler>_ZoneFunction(_rootZone, _rootRun);
}

_ZoneFunction<RunUnaryHandler> _RootZone::_runUnary() {
    return const <RunUnaryHandler>_ZoneFunction(_rootZone, _rootRunUnary);
}

_ZoneFunction<RunBinaryHandler> _RootZone::_runBinary() {
    return const <RunBinaryHandler>_ZoneFunction(_rootZone, _rootRunBinary);
}

_ZoneFunction<RegisterCallbackHandler> _RootZone::_registerCallback() {
    return const <RegisterCallbackHandler>_ZoneFunction(_rootZone, _rootRegisterCallback);
}

_ZoneFunction<RegisterUnaryCallbackHandler> _RootZone::_registerUnaryCallback() {
    return const <RegisterUnaryCallbackHandler>_ZoneFunction(_rootZone, _rootRegisterUnaryCallback);
}

_ZoneFunction<RegisterBinaryCallbackHandler> _RootZone::_registerBinaryCallback() {
    return const <RegisterBinaryCallbackHandler>_ZoneFunction(_rootZone, _rootRegisterBinaryCallback);
}

_ZoneFunction<ErrorCallbackHandler> _RootZone::_errorCallback() {
    return const <ErrorCallbackHandler>_ZoneFunction(_rootZone, _rootErrorCallback);
}

_ZoneFunction<ScheduleMicrotaskHandler> _RootZone::_scheduleMicrotask() {
    return const <ScheduleMicrotaskHandler>_ZoneFunction(_rootZone, _rootScheduleMicrotask);
}

_ZoneFunction<CreateTimerHandler> _RootZone::_createTimer() {
    return const <CreateTimerHandler>_ZoneFunction(_rootZone, _rootCreateTimer);
}

_ZoneFunction<CreatePeriodicTimerHandler> _RootZone::_createPeriodicTimer() {
    return const <CreatePeriodicTimerHandler>_ZoneFunction(_rootZone, _rootCreatePeriodicTimer);
}

_ZoneFunction<PrintHandler> _RootZone::_print() {
    return const <PrintHandler>_ZoneFunction(_rootZone, _rootPrint);
}

_ZoneFunction<ForkHandler> _RootZone::_fork() {
    return const <ForkHandler>_ZoneFunction(_rootZone, _rootFork);
}

_ZoneFunction<HandleUncaughtErrorHandler> _RootZone::_handleUncaughtError() {
    return const <HandleUncaughtErrorHandler>_ZoneFunction(_rootZone, _rootHandleUncaughtError);
}

Map<Object, Object> _RootZone::_map() {
    return _rootMap;
}

ZoneDelegate _RootZone::_delegate() {
    return _rootDelegate ??= _ZoneDelegate(this);
}

ZoneDelegate _RootZone::_parentDelegate() {
    return _delegate;
}

R runZoned<R>(FunctionType body, FunctionType onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
    checkNotNullable(body, "body");
    if (onError != nullptr) {
        if (onError is! FunctionType) {
            if (onError is FunctionType) {
                auto originalOnError = onError;
                onError = ;
            } else {
                ;
            }
        }
        return (;
    }
    return <R>_runZoned(body, zoneValues, zoneSpecification);
}

R runZonedGuarded<R>(FunctionType body, FunctionType onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues) {
    checkNotNullable(body, "body");
    checkNotNullable(onError, "onError");
    _Zone parentZone = Zone._current;
    HandleUncaughtErrorHandler errorHandler = ;
    if (zoneSpecification == nullptr) {
        zoneSpecification = ZoneSpecification(errorHandler);
    } else {
        zoneSpecification = ZoneSpecification.from(zoneSpecificationerrorHandler);
    }
    ;
    return nullptr;
}

R _runZoned<R>(FunctionType body, ZoneSpecification specification, Map<Object, Object> zoneValues) {
    return Zone.current.fork(specification, zoneValues).<R>run(body);
}
