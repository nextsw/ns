#ifndef DART_ASYNC_ZONE
#define DART_ASYNC_ZONE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T : void  Function()> class _ZoneFunctionCls : public ObjectCls {
public:
    _Zone zone;

    T function;


private:

     _ZoneFunctionCls(T function, _Zone zone);
};
template<typename T : void  Function()> using _ZoneFunction = std::shared_ptr<_ZoneFunctionCls<T : void  Function()>>;

class ZoneSpecificationCls : public ObjectCls {
public:

     ZoneSpecificationCls(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);
    virtual void  from(CreatePeriodicTimerHandler createPeriodicTimer, CreateTimerHandler createTimer, ErrorCallbackHandler errorCallback, ForkHandler fork, HandleUncaughtErrorHandler handleUncaughtError, ZoneSpecification other, PrintHandler print, RegisterBinaryCallbackHandler registerBinaryCallback, RegisterCallbackHandler registerCallback, RegisterUnaryCallbackHandler registerUnaryCallback, RunHandler run, RunBinaryHandler runBinary, RunUnaryHandler runUnary, ScheduleMicrotaskHandler scheduleMicrotask);

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

    virtual void handleUncaughtError(Object error, StackTrace stackTrace, Zone zone);
    template<typename R>  virtual R run(R f() , Zone zone);
    template<typename R, typename T>  virtual R runUnary(T arg, R f(T arg) , Zone zone);
    template<typename R, typename T1, typename T2>  virtual R runBinary(T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) , Zone zone);
    template<typename R>  virtual ZoneCallback<R> registerCallback(R f() , Zone zone);
    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> registerUnaryCallback(R f(T arg) , Zone zone);
    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(R f(T1 arg1, T2 arg2) , Zone zone);
    virtual AsyncError errorCallback(Object error, StackTrace stackTrace, Zone zone);
    virtual void scheduleMicrotask(void f() , Zone zone);
    virtual Timer createTimer(Duration duration, void f() , Zone zone);
    virtual Timer createPeriodicTimer(void f(Timer timer) , Duration period, Zone zone);
    virtual void print(String line, Zone zone);
    virtual Zone fork(ZoneSpecification specification, Zone zone, Map zoneValues);
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
    template<typename R>  virtual R run(R action() );
    template<typename R, typename T>  virtual R runUnary(R action(T argument) , T argument);
    template<typename R, typename T1, typename T2>  virtual R runBinary(R action(T1 argument1, T2 argument2) , T1 argument1, T2 argument2);
    virtual void runGuarded(void action() );
    template<typename T>  virtual void runUnaryGuarded(void action(T argument) , T argument);
    template<typename T1, typename T2>  virtual void runBinaryGuarded(void action(T1 argument1, T2 argument2) , T1 argument1, T2 argument2);
    template<typename R>  virtual ZoneCallback<R> registerCallback(R callback() );
    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> registerUnaryCallback(R callback(T arg) );
    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(R callback(T1 arg1, T2 arg2) );
    template<typename R>  virtual ZoneCallback<R> bindCallback(R callback() );
    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> bindUnaryCallback(R callback(T argument) );
    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(R callback(T1 argument1, T2 argument2) );
    virtual void Function() bindCallbackGuarded(void callback() );
    template<typename T>  virtual void Function(T ) bindUnaryCallbackGuarded(void callback(T argument) );
    template<typename T1, typename T2>  virtual void Function(T1 , T2 ) bindBinaryCallbackGuarded(void callback(T1 argument1, T2 argument2) );
    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);
    virtual void scheduleMicrotask(void callback() );
    virtual Timer createTimer(void callback() , Duration duration);
    virtual Timer createPeriodicTimer(void callback(Timer timer) , Duration period);
    virtual void print(String line);
    virtual dynamic operator[](Object key);
private:
    static _Zone _current;


    virtual void  _();
    static _Zone _enter(_Zone zone);

    static void _leave(_Zone previous);

};
using Zone = std::shared_ptr<ZoneCls>;

class _ZoneDelegateCls : public ObjectCls {
public:

    virtual void handleUncaughtError(Object error, StackTrace stackTrace, Zone zone);

    template<typename R>  virtual R run(R f() , Zone zone);

    template<typename R, typename T>  virtual R runUnary(T arg, R f(T arg) , Zone zone);

    template<typename R, typename T1, typename T2>  virtual R runBinary(T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) , Zone zone);

    template<typename R>  virtual ZoneCallback<R> registerCallback(R f() , Zone zone);

    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> registerUnaryCallback(R f(T arg) , Zone zone);

    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(R f(T1 arg1, T2 arg2) , Zone zone);

    virtual AsyncError errorCallback(Object error, StackTrace stackTrace, Zone zone);

    virtual void scheduleMicrotask(f , Zone zone);

    virtual Timer createTimer(Duration duration, void f() , Zone zone);

    virtual Timer createPeriodicTimer(void f(Timer timer) , Duration period, Zone zone);

    virtual void print(String line, Zone zone);

    virtual Zone fork(ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues);

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
    virtual void _processUncaughtError(Object error, StackTrace stackTrace, Zone zone);

};
using _Zone = std::shared_ptr<_ZoneCls>;

class _CustomZoneCls : public _ZoneCls {
public:
    _Zone parent;


    virtual Zone errorZone();

    virtual void runGuarded(void f() );

    template<typename T>  virtual void runUnaryGuarded(T arg, void f(T arg) );

    template<typename T1, typename T2>  virtual void runBinaryGuarded(T1 arg1, T2 arg2, void f(T1 arg1, T2 arg2) );

    template<typename R>  virtual ZoneCallback<R> bindCallback(R f() );

    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> bindUnaryCallback(R f(T arg) );

    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(R f(T1 arg1, T2 arg2) );

    virtual void Function() bindCallbackGuarded(void f() );

    template<typename T>  virtual void Function(T ) bindUnaryCallbackGuarded(void f(T arg) );

    template<typename T1, typename T2>  virtual void Function(T1 , T2 ) bindBinaryCallbackGuarded(void f(T1 arg1, T2 arg2) );

    virtual dynamic operator[](Object key);

    virtual void handleUncaughtError(Object error, StackTrace stackTrace);

    virtual Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    template<typename R>  virtual R run(R f() );

    template<typename R, typename T>  virtual R runUnary(T arg, R f(T arg) );

    template<typename R, typename T1, typename T2>  virtual R runBinary(T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) );

    template<typename R>  virtual ZoneCallback<R> registerCallback(R callback() );

    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> registerUnaryCallback(R callback(T arg) );

    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(R callback(T1 arg1, T2 arg2) );

    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);

    virtual void scheduleMicrotask(void f() );

    virtual Timer createTimer(Duration duration, void f() );

    virtual Timer createPeriodicTimer(Duration duration, void f(Timer timer) );

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

     _CustomZoneCls(Map<Object, Object> _map, _Zone parent, ZoneSpecification specification);

};
using _CustomZone = std::shared_ptr<_CustomZoneCls>;
void _rootHandleUncaughtError(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone);

void _rootHandleError(Object error, StackTrace stackTrace);

template<typename R>  R _rootRun(R f() , ZoneDelegate parent, Zone self, Zone zone);

template<typename R, typename T>  R _rootRunUnary(T arg, R f(T arg) , ZoneDelegate parent, Zone self, Zone zone);

template<typename R, typename T1, typename T2>  R _rootRunBinary(T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) , ZoneDelegate parent, Zone self, Zone zone);

template<typename R>  ZoneCallback<R> _rootRegisterCallback(R f() , ZoneDelegate parent, Zone self, Zone zone);

template<typename R, typename T>  ZoneUnaryCallback<R, T> _rootRegisterUnaryCallback(R f(T arg) , ZoneDelegate parent, Zone self, Zone zone);

template<typename R, typename T1, typename T2>  ZoneBinaryCallback<R, T1, T2> _rootRegisterBinaryCallback(R f(T1 arg1, T2 arg2) , ZoneDelegate parent, Zone self, Zone zone);

AsyncError _rootErrorCallback(Object error, ZoneDelegate parent, Zone self, StackTrace stackTrace, Zone zone);

void _rootScheduleMicrotask(void f() , ZoneDelegate parent, Zone self, Zone zone);

Timer _rootCreateTimer(void callback() , Duration duration, ZoneDelegate parent, Zone self, Zone zone);

Timer _rootCreatePeriodicTimer(void callback(Timer timer) , Duration duration, ZoneDelegate parent, Zone self, Zone zone);

void _rootPrint(String line, ZoneDelegate parent, Zone self, Zone zone);

void _printToZone(String line);

Zone _rootFork(ZoneDelegate parent, Zone self, ZoneSpecification specification, Zone zone, Map<Object, Object> zoneValues);


class _RootZoneCls : public _ZoneCls {
public:

    virtual _Zone parent();

    virtual Zone errorZone();

    virtual void runGuarded(void f() );

    template<typename T>  virtual void runUnaryGuarded(T arg, void f(T arg) );

    template<typename T1, typename T2>  virtual void runBinaryGuarded(T1 arg1, T2 arg2, void f(T1 arg1, T2 arg2) );

    template<typename R>  virtual ZoneCallback<R> bindCallback(R f() );

    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> bindUnaryCallback(R f(T arg) );

    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> bindBinaryCallback(R f(T1 arg1, T2 arg2) );

    virtual void Function() bindCallbackGuarded(void f() );

    template<typename T>  virtual void Function(T ) bindUnaryCallbackGuarded(void f(T arg) );

    template<typename T1, typename T2>  virtual void Function(T1 , T2 ) bindBinaryCallbackGuarded(void f(T1 arg1, T2 arg2) );

    virtual dynamic operator[](Object key);

    virtual void handleUncaughtError(Object error, StackTrace stackTrace);

    virtual Zone fork(ZoneSpecification specification, Map<Object, Object> zoneValues);

    template<typename R>  virtual R run(R f() );

    template<typename R, typename T>  virtual R runUnary(T arg, R f(T arg) );

    template<typename R, typename T1, typename T2>  virtual R runBinary(T1 arg1, T2 arg2, R f(T1 arg1, T2 arg2) );

    template<typename R>  virtual ZoneCallback<R> registerCallback(R f() );

    template<typename R, typename T>  virtual ZoneUnaryCallback<R, T> registerUnaryCallback(R f(T arg) );

    template<typename R, typename T1, typename T2>  virtual ZoneBinaryCallback<R, T1, T2> registerBinaryCallback(R f(T1 arg1, T2 arg2) );

    virtual AsyncError errorCallback(Object error, StackTrace stackTrace);

    virtual void scheduleMicrotask(void f() );

    virtual Timer createTimer(Duration duration, void f() );

    virtual Timer createPeriodicTimer(Duration duration, void f(Timer timer) );

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

template<typename R>  R runZoned(R body() , void  onError() , ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

template<typename R>  R runZonedGuarded(R body() , void onError(Object error, StackTrace stack) , ZoneSpecification zoneSpecification, Map<Object, Object> zoneValues);

template<typename R>  R _runZoned(R body() , ZoneSpecification specification, Map<Object, Object> zoneValues);



#endif