#ifndef DART_ASYNC_FUTURE_IMPL
#define DART_ASYNC_FUTURE_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class _CompleterCls : public ObjectCls {
public:
    _Future<T> future;


    virtual void complete(FutureOr<T> value);
    virtual void completeError(Object error, StackTrace stackTrace);

    virtual bool isCompleted();

private:

    virtual void _completeError(Object error, StackTrace stackTrace);
};
template<typename T>
using _Completer = std::shared_ptr<_CompleterCls<T>>;

template<typename T>
class _AsyncCompleterCls : public _CompleterCls<T> {
public:

    virtual void complete(FutureOr<T> value);

private:

    virtual void _completeError(Object error, StackTrace stackTrace);

};
template<typename T>
using _AsyncCompleter = std::shared_ptr<_AsyncCompleterCls<T>>;

template<typename T>
class _SyncCompleterCls : public _CompleterCls<T> {
public:

    virtual void complete(FutureOr<T> value);

private:

    virtual void _completeError(Object error, StackTrace stackTrace);

};
template<typename T>
using _SyncCompleter = std::shared_ptr<_SyncCompleterCls<T>>;

template<typename S, typename T>
class _FutureListenerCls : public ObjectCls {
public:
    static int maskValue;

    static int maskError;

    static int maskTestError;

    static int maskWhenComplete;

    static int stateChain;

    static int stateThen;

    static int stateThenOnerror;

    static int stateCatchError;

    static int stateCatchErrorTest;

    static int stateWhenComplete;

    static int maskType;

    _Future<T> result;

    int state;

    std::function<void ()> callback;

    std::function<void ()> errorCallback;


    virtual void  then(std::function<void ()> errorCallback, std::function<FutureOr<T>(S )> onValue, _Future<T> result);

    virtual void  thenAwait(std::function<void ()> errorCallback, std::function<FutureOr<T>(S )> onValue, _Future<T> result);

    virtual void  catchError(std::function<void ()> callback, std::function<void ()> errorCallback, _Future<T> result);

    virtual void  whenComplete(std::function<void ()> callback, _Future<T> result);

    virtual bool handlesValue();

    virtual bool handlesError();

    virtual bool hasErrorTest();

    virtual bool handlesComplete();

    virtual bool hasErrorCallback();

    virtual FutureOr<T> handleValue(S sourceResult);

    virtual bool matchesErrorTest(AsyncError asyncError);

    virtual FutureOr<T> handleError(AsyncError asyncError);

    virtual dynamic handleWhenComplete();

    virtual bool shouldChain(Future<dynamic> value);

private:
    _FutureListener _nextListener;


    virtual _Zone _zone();

    virtual std::function<FutureOr<T>(S )> _onValue();

    virtual std::function<void ()> _onError();

    virtual std::function<bool(Object )> _errorTest();

    virtual std::function<dynamic()> _whenCompleteAction();

};
template<typename S, typename T>
using _FutureListener = std::shared_ptr<_FutureListenerCls<S, T>>;


#endif