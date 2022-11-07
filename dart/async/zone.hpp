#ifndef ZONE_H
#define ZONE_H
#include <memory>




class _ZoneFunction<T extends FunctionType> {
public:
    _Zone zone;

    T function;


private:

     _ZoneFunction(T function, _Zone zone);

};

class ZoneSpecification {
public:

     ZoneSpecification(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);

    void  from(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, ZoneSpecification other, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);

    HandleUncaughtErrorHandler handleUncaughtError();

    RunHandler run();

    RunUnaryHandler runUnary();

    RunBinaryHandler runBinary();

    RegisterCallbackHandler registerCallback();

    RegisterUnaryCallbackHandler registerUnaryCallback();

    RegisterBinaryCallbackHandler registerBinaryCallback();

    ErrorCallbackHandler errorCallback();

    ScheduleMicrotaskHandler scheduleMicrotask();

    CreateTimerHandler createTimer();

    CreatePeriodicTimerHandler createPeriodicTimer();

    PrintHandler print();

    ForkHandler fork();

private:

};

class _ZoneSpecification {
public:
    HandleUncaughtErrorHandler handleUncaughtError;

    RunHandler run;

    RunUnaryHandler runUnary;

    RunBinaryHandler runBinary;

    RegisterCallbackHandler registerCallback;

    RegisterUnaryCallbackHandler registerUnaryCallback;

    RegisterBinaryCallbackHandler registerBinaryCallback;

    ErrorCallbackHandler errorCallback;

    ScheduleMicrotaskHandler scheduleMicrotask;

    CreateTimerHandler createTimer;

    CreatePeriodicTimerHandler createPeriodicTimer;

    PrintHandler print;

    ForkHandler fork;


private:

     _ZoneSpecification(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);

};

class ZoneDelegate {
public:

    void handleUncaughtError(Object error, StackTrace stackTrace, Zone zone);

    R run<R>(FunctionType f, Zone zone);

    R runUnary<R, T>(T arg, FunctionType f, Zone zone);

    R runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f, Zone zone);

    ZoneCallback<R> registerCallback<R>(FunctionType f, Zone zone);

    ZoneUnaryCallback<R, T> registerUnaryCallback<R, T>(FunctionType f, Zone zone);

    ZoneBinaryCallback<R, T1, T2> registerBinaryCallback<R, T1, T2>(FunctionType f, Zone zone);

    AsyncError errorCallback(Object error, StackTrace stackTrace, Zone zone);

    void scheduleMicrotask(FunctionType f, Zone zone);

    Timer createTimer(Duration duration, FunctionType f, Zone zone);

    Timer createPeriodicTimer(FunctionType f, Duration period, Zone zone);

    void print(String line, Zone zone);

    Zone fork(ZoneSpecification specification, Zone zone, Map zoneValues);

private:

};

class Zone {
public:
    static const Zone root;


    static Zone current();

    void handleUncaughtError(Object error, StackTrace stackTrace);

    Zone parent();

    Zone errorZone();

    bool inSameErrorZone(Zone otherZone);

    Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    R run<R>(FunctionType action);

    R runUnary<R, T>(FunctionType action, T argument);

    R runBinary<R, T1, T2>(FunctionType action, T1 argument1, T2 argument2);

    void runGuarded(FunctionType action);

    void runUnaryGuarded<T>(FunctionType action, T argument);

    void runBinaryGuarded<T1, T2>(FunctionType action, T1 argument1, T2 argument2);

    ZoneCallback<R> registerCallback<R>(FunctionType callback);

    ZoneUnaryCallback<R, T> registerUnaryCallback<R, T>(FunctionType callback);

    ZoneBinaryCallback<R, T1, T2> registerBinaryCallback<R, T1, T2>(FunctionType callback);

    ZoneCallback<R> bindCallback<R>(FunctionType callback);

    ZoneUnaryCallback<R, T> bindUnaryCallback<R, T>(FunctionType callback);

    ZoneBinaryCallback<R, T1, T2> bindBinaryCallback<R, T1, T2>(FunctionType callback);

    FunctionType bindCallbackGuarded(FunctionType callback);

    FunctionType bindUnaryCallbackGuarded<T>(FunctionType callback);

    FunctionType bindBinaryCallbackGuarded<T1, T2>(FunctionType callback);

    AsyncError errorCallback(Object error, StackTrace stackTrace);

    void scheduleMicrotask(FunctionType callback);

    Timer createTimer(FunctionType callback, Duration duration);

    Timer createPeriodicTimer(FunctionType callback, Duration period);

    void print(String line);

    dynamic [](Object key);

private:
    static _Zone _current;


    void  _();

    static _Zone _enter(_Zone zone);

    static void _leave(_Zone previous);

};

class _ZoneDelegate {
public:

    void handleUncaughtError(Object error, StackTrace stackTrace, Zone zone);

    R run<R>(FunctionType f, Zone zone);

    R runUnary<R, T>(T arg, FunctionType f, Zone zone);

    R runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f, Zone zone);

    ZoneCallback<R> registerCallback<R>(FunctionType f, Zone zone);

    ZoneUnaryCallback<R, T> registerUnaryCallback<R, T>(FunctionType f, Zone zone);

    ZoneBinaryCallback<R, T1, T2> registerBinaryCallback<R, T1, T2>(FunctionType f, Zone zone);

    AsyncError errorCallback(Object error, StackTrace stackTrace, Zone zone);

    void scheduleMicrotask(f , Zone zone);

    Timer createTimer(Duration duration, FunctionType f, Zone zone);

    Timer createPeriodicTimer(FunctionType f, Duration period, Zone zone);

    void print(String line, Zone zone);

    Zone fork(ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues);

private:
    _Zone _delegationTarget;


     _ZoneDelegate(_Zone _delegationTarget);

};

class _Zone {
public:

    _Zone parent();

    bool inSameErrorZone(Zone otherZone);

private:

     _Zone();

    _ZoneFunction<RunHandler> _run();

    _ZoneFunction<RunUnaryHandler> _runUnary();

    _ZoneFunction<RunBinaryHandler> _runBinary();

    _ZoneFunction<RegisterCallbackHandler> _registerCallback();

    _ZoneFunction<RegisterUnaryCallbackHandler> _registerUnaryCallback();

    _ZoneFunction<RegisterBinaryCallbackHandler> _registerBinaryCallback();

    _ZoneFunction<ErrorCallbackHandler> _errorCallback();

    _ZoneFunction<ScheduleMicrotaskHandler> _scheduleMicrotask();

    _ZoneFunction<CreateTimerHandler> _createTimer();

    _ZoneFunction<CreatePeriodicTimerHandler> _createPeriodicTimer();

    _ZoneFunction<PrintHandler> _print();

    _ZoneFunction<ForkHandler> _fork();

    _ZoneFunction<HandleUncaughtErrorHandler> _handleUncaughtError();

    ZoneDelegate _delegate();

    ZoneDelegate _parentDelegate();

    Map<Object, Object> _map();

    void _processUncaughtError(Object error, StackTrace stackTrace, Zone zone);

};

class _CustomZone : _Zone {
public:
    _Zone parent;


    Zone errorZone();

    void runGuarded(FunctionType f);

    void runUnaryGuarded<T>(T arg, FunctionType f);

    void runBinaryGuarded<T1, T2>(T1 arg1, T2 arg2, FunctionType f);

    ZoneCallback<R> bindCallback<R>(FunctionType f);

    ZoneUnaryCallback<R, T> bindUnaryCallback<R, T>(FunctionType f);

    ZoneBinaryCallback<R, T1, T2> bindBinaryCallback<R, T1, T2>(FunctionType f);

    FunctionType bindCallbackGuarded(FunctionType f);

    FunctionType bindUnaryCallbackGuarded<T>(FunctionType f);

    FunctionType bindBinaryCallbackGuarded<T1, T2>(FunctionType f);

    dynamic [](Object key);

    void handleUncaughtError(Object error, StackTrace stackTrace);

    Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    R run<R>(FunctionType f);

    R runUnary<R, T>(T arg, FunctionType f);

    R runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f);

    ZoneCallback<R> registerCallback<R>(FunctionType callback);

    ZoneUnaryCallback<R, T> registerUnaryCallback<R, T>(FunctionType callback);

    ZoneBinaryCallback<R, T1, T2> registerBinaryCallback<R, T1, T2>(FunctionType callback);

    AsyncError errorCallback(Object error, StackTrace stackTrace);

    void scheduleMicrotask(FunctionType f);

    Timer createTimer(Duration duration, FunctionType f);

    Timer createPeriodicTimer(Duration duration, FunctionType f);

    void print(String line);

private:
    _ZoneFunction<RunHandler> _run;

    _ZoneFunction<RunUnaryHandler> _runUnary;

    _ZoneFunction<RunBinaryHandler> _runBinary;

    _ZoneFunction<RegisterCallbackHandler> _registerCallback;

    _ZoneFunction<RegisterUnaryCallbackHandler> _registerUnaryCallback;

    _ZoneFunction<RegisterBinaryCallbackHandler> _registerBinaryCallback;

    _ZoneFunction<ErrorCallbackHandler> _errorCallback;

    _ZoneFunction<ScheduleMicrotaskHandler> _scheduleMicrotask;

    _ZoneFunction<CreateTimerHandler> _createTimer;

    _ZoneFunction<CreatePeriodicTimerHandler> _createPeriodicTimer;

    _ZoneFunction<PrintHandler> _print;

    _ZoneFunction<ForkHandler> _fork;

    _ZoneFunction<HandleUncaughtErrorHandler> _handleUncaughtError;

    ZoneDelegate _delegateCache;

    Map<Object, Object> _map;


    ZoneDelegate _delegate();

    ZoneDelegate _parentDelegate();

     _CustomZone(Map<Object, Object> _map, _Zone parent, ZoneSpecification specification);

};
void _rootHandleUncaughtError(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone);

void _rootHandleError(Object error, StackTrace stackTrace);

R _rootRun<R>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

R _rootRunUnary<R, T>(T arg, FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

R _rootRunBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

ZoneCallback<R> _rootRegisterCallback<R>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

ZoneUnaryCallback<R, T> _rootRegisterUnaryCallback<R, T>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallback<R, T1, T2>(FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

AsyncError _rootErrorCallback(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone);

void _rootScheduleMicrotask(FunctionType f, ZoneDelegate parent, Zone self, Zone zone);

Timer _rootCreateTimer(FunctionType callback, Duration duration, ZoneDelegate parent, Zone self, Zone zone);

Timer _rootCreatePeriodicTimer(FunctionType callback, Duration duration, ZoneDelegate parent, Zone self, Zone zone);

void _rootPrint(String line, ZoneDelegate parent, Zone self, Zone zone);

void _printToZone(String line);

Zone _rootFork(ZoneDelegate parent, Zone self, ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues);


class _RootZone : _Zone {
public:

    _Zone parent();

    Zone errorZone();

    void runGuarded(FunctionType f);

    void runUnaryGuarded<T>(T arg, FunctionType f);

    void runBinaryGuarded<T1, T2>(T1 arg1, T2 arg2, FunctionType f);

    ZoneCallback<R> bindCallback<R>(FunctionType f);

    ZoneUnaryCallback<R, T> bindUnaryCallback<R, T>(FunctionType f);

    ZoneBinaryCallback<R, T1, T2> bindBinaryCallback<R, T1, T2>(FunctionType f);

    FunctionType bindCallbackGuarded(FunctionType f);

    FunctionType bindUnaryCallbackGuarded<T>(FunctionType f);

    FunctionType bindBinaryCallbackGuarded<T1, T2>(FunctionType f);

    dynamic [](Object key);

    void handleUncaughtError(Object error, StackTrace stackTrace);

    Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    R run<R>(FunctionType f);

    R runUnary<R, T>(T arg, FunctionType f);

    R runBinary<R, T1, T2>(T1 arg1, T2 arg2, FunctionType f);

    ZoneCallback<R> registerCallback<R>(FunctionType f);

    ZoneUnaryCallback<R, T> registerUnaryCallback<R, T>(FunctionType f);

    ZoneBinaryCallback<R, T1, T2> registerBinaryCallback<R, T1, T2>(FunctionType f);

    AsyncError errorCallback(Object error, StackTrace stackTrace);

    void scheduleMicrotask(FunctionType f);

    Timer createTimer(Duration duration, FunctionType f);

    Timer createPeriodicTimer(Duration duration, FunctionType f);

    void print(String line);

private:
    static auto  _rootMap;

    static ZoneDelegate _rootDelegate;


     _RootZone();

    _ZoneFunction<RunHandler> _run();

    _ZoneFunction<RunUnaryHandler> _runUnary();

    _ZoneFunction<RunBinaryHandler> _runBinary();

    _ZoneFunction<RegisterCallbackHandler> _registerCallback();

    _ZoneFunction<RegisterUnaryCallbackHandler> _registerUnaryCallback();

    _ZoneFunction<RegisterBinaryCallbackHandler> _registerBinaryCallback();

    _ZoneFunction<ErrorCallbackHandler> _errorCallback();

    _ZoneFunction<ScheduleMicrotaskHandler> _scheduleMicrotask();

    _ZoneFunction<CreateTimerHandler> _createTimer();

    _ZoneFunction<CreatePeriodicTimerHandler> _createPeriodicTimer();

    _ZoneFunction<PrintHandler> _print();

    _ZoneFunction<ForkHandler> _fork();

    _ZoneFunction<HandleUncaughtErrorHandler> _handleUncaughtError();

    Map<Object, Object> _map();

    ZoneDelegate _delegate();

    ZoneDelegate _parentDelegate();

};
const _Zone _rootZone;

R runZoned<R>(FunctionType body, FunctionType onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

R runZonedGuarded<R>(FunctionType body, FunctionType onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

R _runZoned<R>(FunctionType body, ZoneSpecification specification, Map<Object, Object> zoneValues);


#endif