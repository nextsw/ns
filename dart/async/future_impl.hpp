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


    virtual void  then(_Future<T> result, std::function<FutureOr<T>(S )> onValue, std::function<void ()> errorCallback);

    virtual void  thenAwait(_Future<T> result, std::function<FutureOr<T>(S )> onValue, std::function<void ()> errorCallback);

    virtual void  catchError(_Future<T> result, std::function<void ()> errorCallback, std::function<void ()> callback);

    virtual void  whenComplete(_Future<T> result, std::function<void ()> callback);

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
    _FutureListener<any, any> _nextListener;


    virtual _Zone _zone();

    virtual std::function<FutureOr<T>(S )> _onValue();

    virtual std::function<void ()> _onError();

    virtual std::function<bool(Object )> _errorTest();

    virtual std::function<dynamic()> _whenCompleteAction();

};
template<typename S, typename T>
using _FutureListener = std::shared_ptr<_FutureListenerCls<S, T>>;

template<typename T>
class _FutureCls : public ObjectCls {
public:

    virtual void  immediate(FutureOr<T> result);

    virtual void  zoneValue(T value, _Zone _zone);

    virtual void  immediateError(auto error, StackTrace stackTrace);

    virtual void  value(T value);

    template<typename R>
 virtual Future<R> then(std::function<FutureOr<R>(T value)> f, std::function<void ()> onError);

    virtual Future<T> catchError(std::function<void ()> onError, std::function<bool(Object error)> test);

    virtual Future<T> whenComplete(std::function<dynamic()> action);

    virtual Stream<T> asStream();

    virtual Future<T> timeout(Duration timeLimit, std::function<FutureOr<T>()> onTimeout);

private:
    static int _stateIncomplete;

    static int _stateIgnoreError;

    static int _statePendingComplete;

    static int _stateChained;

    static int _stateValue;

    static int _stateError;

    static int _completionStateMask;

    int _state;

    _Zone _zone;

    auto _resultOrListeners;


     _FutureCls();

    virtual bool _mayComplete();

    virtual bool _isPendingComplete();

    virtual bool _mayAddListener();

    virtual bool _isChained();

    virtual bool _isComplete();

    virtual bool _hasError();

    virtual bool _ignoreError();

    virtual void _setChained(_Future<any> source);

    template<typename E>
 virtual Future<E> _thenAwait(std::function<FutureOr<E>(T value)> f, std::function<void ()> onError);

    virtual void _ignore();

    virtual void _setPendingComplete();

    virtual void _clearPendingComplete();

    virtual AsyncError _error();

    virtual _Future<any> _chainSource();

    virtual void _setValue(T value);

    virtual void _setErrorObject(AsyncError error);

    virtual void _setError(Object error, StackTrace stackTrace);

    virtual void _cloneResult(_Future<any> source);

    virtual void _addListener(_FutureListener<any, any> listener);

    virtual void _prependListeners(_FutureListener<any, any> listeners);

    virtual _FutureListener<any, any> _removeListeners();

    virtual _FutureListener<any, any> _reverseListeners(_FutureListener<any, any> listeners);

    virtual void _chainForeignFuture(Future<any> source);

    static void _chainCoreFuture(_Future<any> source, _Future<any> target);

    virtual void _complete(FutureOr<T> value);

    virtual void _completeWithValue(T value);

    virtual void _completeError(Object error, StackTrace stackTrace);

    virtual void _asyncComplete(FutureOr<T> value);

    virtual void _asyncCompleteUnchecked(dynamic value);

    virtual void _asyncCompleteUncheckedNoFuture(dynamic value);

    virtual void _asyncCompleteWithValue(T value);

    virtual void _chainFuture(Future<T> value);

    virtual void _asyncCompleteError(Object error, StackTrace stackTrace);

    static void _propagateToListeners(_Future<any> source, _FutureListener<any, any> listeners);

};
template<typename T>
using _Future = std::shared_ptr<_FutureCls<T>>;
std::function<void ()> _registerErrorHandler(std::function<void ()> errorHandler, Zone zone);



#endif