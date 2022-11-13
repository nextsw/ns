#ifndef DART_ASYNC_ZONE
#define DART_ASYNC_ZONE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class _ZoneFunctionCls : public ObjectCls {
public:
    _Zone zone;

    T function;


private:

     _ZoneFunctionCls(_Zone zone, T function);
};
template<typename T>
using _ZoneFunction = std::shared_ptr<_ZoneFunctionCls<T>>;

class ZoneSpecificationCls : public ObjectCls {
public:

     ZoneSpecificationCls(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);
    virtual void  from(ZoneSpecification other, CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);

    virtual HandleUncaughtErrorHandler handleUncaughtError();
    virtual RunHandler run();
    virtual RunUnaryHandler runUnary();
    virtual RunBinaryHandler runBinary();
    virtual RegisterCallbackHandler registerCallback();
    virtual RegisterUnaryCallbackHandler registerUnaryCallback();
    virtual RegisterBinaryCallbackHandler registerBinaryCallback();
    virtual ErrorCallbackHandler errorCallback();
    virtual ScheduleMicrotaskHandler scheduleMicrotask();
    virtual CreateTimerHandler createTimer();
    virtual CreatePeriodicTimerHandler createPeriodicTimer();
    virtual PrintHandler print();
    virtual ForkHandler fork();
private:

};
using ZoneSpecification = std::shared_ptr<ZoneSpecificationCls>;

class _ZoneSpecificationCls : public ObjectCls {
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

     _ZoneSpecificationCls(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);
};
using _ZoneSpecification = std::shared_ptr<_ZoneSpecificationCls>;

class ZoneDelegateCls : public ObjectCls {
public:

    virtual void handleUncaughtError(Zone zone, Object error, StackTrace stackTrace);
    template<typename R>
 virtual R run(Zone zone, std::function<R()> f);
    template<typename R, typename T>
 virtual R runUnary(Zone zone, std::function<R(T arg)> f, T arg);
    template<typename R, typename T1, typename T2>
 virtual R runBinary(Zone zone, std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);
    template<typename R>
 virtual ZoneCallback<R> registerCallback(Zone zone, std::function<R()> f);
    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> registerUnaryCallback(Zone zone, std::function<R(T arg)> f);
    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(Zone zone, std::function<R(T1 arg1, T2 arg2)> f);
    virtual AsyncError errorCallback(Zone zone, Object error, StackTrace stackTrace);
    virtual void scheduleMicrotask(Zone zone, std::function<void()> f);
    virtual Timer createTimer(Zone zone, Duration duration, std::function<void()> f);
    virtual Timer createPeriodicTimer(Zone zone, Duration period, std::function<void(Timer timer)> f);
    virtual void print(Zone zone, String line);
    virtual Zone fork(Zone zone, ZoneSpecification specification, Map<any, any> zoneValues);
private:

};
using ZoneDelegate = std::shared_ptr<ZoneDelegateCls>;

class ZoneCls : public ObjectCls {
public:
    static Zone root;


    static Zone current();

    virtual void handleUncaughtError(Object error, StackTrace stackTrace);
    virtual Zone parent();
    virtual Zone errorZone();
    virtual bool inSameErrorZone(Zone otherZone);
    virtual Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);
    template<typename R>
 virtual R run(std::function<R()> action);
    template<typename R, typename T>
 virtual R runUnary(std::function<R(T argument)> action, T argument);
    template<typename R, typename T1, typename T2>
 virtual R runBinary(std::function<R(T1 argument1, T2 argument2)> action, T1 argument1, T2 argument2);
    virtual void runGuarded(std::function<void()> action);
    template<typename T>
 virtual void runUnaryGuarded(std::function<void(T argument)> action, T argument);
    template<typename T1, typename T2>
 virtual void runBinaryGuarded(std::function<void(T1 argument1, T2 argument2)> action, T1 argument1, T2 argument2);
    template<typename R>
 virtual ZoneCallback<R> registerCallback(std::function<R()> callback);
    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> registerUnaryCallback(std::function<R(T arg)> callback);
    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(std::function<R(T1 arg1, T2 arg2)> callback);
    template<typename R>
 virtual ZoneCallback<R> bindCallback(std::function<R()> callback);
    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> bindUnaryCallback(std::function<R(T argument)> callback);
    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(std::function<R(T1 argument1, T2 argument2)> callback);
    virtual std::function<void()> bindCallbackGuarded(std::function<void()> callback);
    template<typename T>
 virtual std::function<void(T )> bindUnaryCallbackGuarded(std::function<void(T argument)> callback);
    template<typename T1, typename T2>
 virtual std::function<void(T1 , T2 )> bindBinaryCallbackGuarded(std::function<void(T1 argument1, T2 argument2)> callback);
    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);
    virtual void scheduleMicrotask(std::function<void()> callback);
    virtual Timer createTimer(Duration duration, std::function<void()> callback);
    virtual Timer createPeriodicTimer(Duration period, std::function<void(Timer timer)> callback);
    virtual void print(String line);
    virtual Object operator[](Object key);
private:
    static _Zone _current;


    virtual void  _();
    static _Zone _enter(_Zone zone);

    static void _leave(_Zone previous);

};
using Zone = std::shared_ptr<ZoneCls>;

class _ZoneDelegateCls : public ObjectCls {
public:

    virtual void handleUncaughtError(Zone zone, Object error, StackTrace stackTrace);

    template<typename R>
 virtual R run(Zone zone, std::function<R()> f);

    template<typename R, typename T>
 virtual R runUnary(Zone zone, std::function<R(T arg)> f, T arg);

    template<typename R, typename T1, typename T2>
 virtual R runBinary(Zone zone, std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

    template<typename R>
 virtual ZoneCallback<R> registerCallback(Zone zone, std::function<R()> f);

    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> registerUnaryCallback(Zone zone, std::function<R(T arg)> f);

    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(Zone zone, std::function<R(T1 arg1, T2 arg2)> f);

    virtual AsyncError errorCallback(Zone zone, Object error, StackTrace stackTrace);

    virtual void scheduleMicrotask(Zone zone, f );

    virtual Timer createTimer(Zone zone, Duration duration, std::function<void()> f);

    virtual Timer createPeriodicTimer(Zone zone, Duration period, std::function<void(Timer timer)> f);

    virtual void print(Zone zone, String line);

    virtual Zone fork(Zone zone, ZoneSpecification specification, Map<Object, Object> zoneValues);

private:
    _Zone _delegationTarget;


     _ZoneDelegateCls(_Zone _delegationTarget);
};
using _ZoneDelegate = std::shared_ptr<_ZoneDelegateCls>;

class _ZoneCls : public ObjectCls {
public:

    virtual _Zone parent();
    virtual bool inSameErrorZone(Zone otherZone);

private:

     _ZoneCls();
    virtual _ZoneFunction<RunHandler> _run();
    virtual _ZoneFunction<RunUnaryHandler> _runUnary();
    virtual _ZoneFunction<RunBinaryHandler> _runBinary();
    virtual _ZoneFunction<RegisterCallbackHandler> _registerCallback();
    virtual _ZoneFunction<RegisterUnaryCallbackHandler> _registerUnaryCallback();
    virtual _ZoneFunction<RegisterBinaryCallbackHandler> _registerBinaryCallback();
    virtual _ZoneFunction<ErrorCallbackHandler> _errorCallback();
    virtual _ZoneFunction<ScheduleMicrotaskHandler> _scheduleMicrotask();
    virtual _ZoneFunction<CreateTimerHandler> _createTimer();
    virtual _ZoneFunction<CreatePeriodicTimerHandler> _createPeriodicTimer();
    virtual _ZoneFunction<PrintHandler> _print();
    virtual _ZoneFunction<ForkHandler> _fork();
    virtual _ZoneFunction<HandleUncaughtErrorHandler> _handleUncaughtError();
    virtual ZoneDelegate _delegate();
    virtual ZoneDelegate _parentDelegate();
    virtual Map<Object, Object> _map();
    virtual void _processUncaughtError(Zone zone, Object error, StackTrace stackTrace);

};
using _Zone = std::shared_ptr<_ZoneCls>;

class _CustomZoneCls : public _ZoneCls {
public:
    _Zone parent;


    virtual Zone errorZone();

    virtual void runGuarded(std::function<void()> f);

    template<typename T>
 virtual void runUnaryGuarded(std::function<void(T arg)> f, T arg);

    template<typename T1, typename T2>
 virtual void runBinaryGuarded(std::function<void(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

    template<typename R>
 virtual ZoneCallback<R> bindCallback(std::function<R()> f);

    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> bindUnaryCallback(std::function<R(T arg)> f);

    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f);

    virtual std::function<void()> bindCallbackGuarded(std::function<void()> f);

    template<typename T>
 virtual std::function<void(T )> bindUnaryCallbackGuarded(std::function<void(T arg)> f);

    template<typename T1, typename T2>
 virtual std::function<void(T1 , T2 )> bindBinaryCallbackGuarded(std::function<void(T1 arg1, T2 arg2)> f);

    virtual Object operator[](Object key);

    virtual void handleUncaughtError(Object error, StackTrace stackTrace);

    virtual Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    template<typename R>
 virtual R run(std::function<R()> f);

    template<typename R, typename T>
 virtual R runUnary(std::function<R(T arg)> f, T arg);

    template<typename R, typename T1, typename T2>
 virtual R runBinary(std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

    template<typename R>
 virtual ZoneCallback<R> registerCallback(std::function<R()> callback);

    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> registerUnaryCallback(std::function<R(T arg)> callback);

    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(std::function<R(T1 arg1, T2 arg2)> callback);

    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);

    virtual void scheduleMicrotask(std::function<void()> f);

    virtual Timer createTimer(Duration duration, std::function<void()> f);

    virtual Timer createPeriodicTimer(Duration duration, std::function<void(Timer timer)> f);

    virtual void print(String line);

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


    virtual ZoneDelegate _delegate();

    virtual ZoneDelegate _parentDelegate();

     _CustomZoneCls(_Zone parent, ZoneSpecification specification, Map<Object, Object> _map);

};
using _CustomZone = std::shared_ptr<_CustomZoneCls>;
void _rootHandleUncaughtError(Zone self, ZoneDelegate parent, Zone zone, Object error, StackTrace stackTrace);

void _rootHandleError(Object error, StackTrace stackTrace);

template<typename R>
 R _rootRun(Zone self, ZoneDelegate parent, Zone zone, std::function<R()> f);

template<typename R, typename T>
 R _rootRunUnary(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T arg)> f, T arg);

template<typename R, typename T1, typename T2>
 R _rootRunBinary(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

template<typename R>
 ZoneCallback<R> _rootRegisterCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R()> f);

template<typename R, typename T>
 ZoneUnaryCallback<R, T> _rootRegisterUnaryCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T arg)> f);

template<typename R, typename T1, typename T2>
 ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallback(Zone self, ZoneDelegate parent, Zone zone, std::function<R(T1 arg1, T2 arg2)> f);

AsyncError _rootErrorCallback(Zone self, ZoneDelegate parent, Zone zone, Object error, StackTrace stackTrace);

void _rootScheduleMicrotask(Zone self, ZoneDelegate parent, Zone zone, std::function<void()> f);

Timer _rootCreateTimer(Zone self, ZoneDelegate parent, Zone zone, Duration duration, std::function<void()> callback);

Timer _rootCreatePeriodicTimer(Zone self, ZoneDelegate parent, Zone zone, Duration duration, std::function<void(Timer timer)> callback);

void _rootPrint(Zone self, ZoneDelegate parent, Zone zone, String line);

void _printToZone(String line);

Zone _rootFork(Zone self, ZoneDelegate parent, Zone zone, ZoneSpecification specification, Map<Object, Object> zoneValues);


class _RootZoneCls : public _ZoneCls {
public:

    virtual _Zone parent();

    virtual Zone errorZone();

    virtual void runGuarded(std::function<void()> f);

    template<typename T>
 virtual void runUnaryGuarded(std::function<void(T arg)> f, T arg);

    template<typename T1, typename T2>
 virtual void runBinaryGuarded(std::function<void(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

    template<typename R>
 virtual ZoneCallback<R> bindCallback(std::function<R()> f);

    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> bindUnaryCallback(std::function<R(T arg)> f);

    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f);

    virtual std::function<void()> bindCallbackGuarded(std::function<void()> f);

    template<typename T>
 virtual std::function<void(T )> bindUnaryCallbackGuarded(std::function<void(T arg)> f);

    template<typename T1, typename T2>
 virtual std::function<void(T1 , T2 )> bindBinaryCallbackGuarded(std::function<void(T1 arg1, T2 arg2)> f);

    virtual Object operator[](Object key);

    virtual void handleUncaughtError(Object error, StackTrace stackTrace);

    virtual Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    template<typename R>
 virtual R run(std::function<R()> f);

    template<typename R, typename T>
 virtual R runUnary(std::function<R(T arg)> f, T arg);

    template<typename R, typename T1, typename T2>
 virtual R runBinary(std::function<R(T1 arg1, T2 arg2)> f, T1 arg1, T2 arg2);

    template<typename R>
 virtual ZoneCallback<R> registerCallback(std::function<R()> f);

    template<typename R, typename T>
 virtual ZoneUnaryCallback<R, T> registerUnaryCallback(std::function<R(T arg)> f);

    template<typename R, typename T1, typename T2>
 virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(std::function<R(T1 arg1, T2 arg2)> f);

    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);

    virtual void scheduleMicrotask(std::function<void()> f);

    virtual Timer createTimer(Duration duration, std::function<void()> f);

    virtual Timer createPeriodicTimer(Duration duration, std::function<void(Timer timer)> f);

    virtual void print(String line);

private:
    static auto  _rootMap;

    static ZoneDelegate _rootDelegate;


     _RootZoneCls();
    virtual _ZoneFunction<RunHandler> _run();

    virtual _ZoneFunction<RunUnaryHandler> _runUnary();

    virtual _ZoneFunction<RunBinaryHandler> _runBinary();

    virtual _ZoneFunction<RegisterCallbackHandler> _registerCallback();

    virtual _ZoneFunction<RegisterUnaryCallbackHandler> _registerUnaryCallback();

    virtual _ZoneFunction<RegisterBinaryCallbackHandler> _registerBinaryCallback();

    virtual _ZoneFunction<ErrorCallbackHandler> _errorCallback();

    virtual _ZoneFunction<ScheduleMicrotaskHandler> _scheduleMicrotask();

    virtual _ZoneFunction<CreateTimerHandler> _createTimer();

    virtual _ZoneFunction<CreatePeriodicTimerHandler> _createPeriodicTimer();

    virtual _ZoneFunction<PrintHandler> _print();

    virtual _ZoneFunction<ForkHandler> _fork();

    virtual _ZoneFunction<HandleUncaughtErrorHandler> _handleUncaughtError();

    virtual Map<Object, Object> _map();

    virtual ZoneDelegate _delegate();

    virtual ZoneDelegate _parentDelegate();

};
using _RootZone = std::shared_ptr<_RootZoneCls>;
_Zone _rootZone;

template<typename R>
 R runZoned(std::function<R()> body, std::function<void ()> onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

template<typename R>
 R runZonedGuarded(std::function<R()> body, std::function<void(Object error, StackTrace stack)> onError, ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

template<typename R>
 R _runZoned(std::function<R()> body, Map<Object, Object> zoneValues, ZoneSpecification specification);



#endif