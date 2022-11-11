#include "future_impl.hpp"
template<typename T>
void _CompleterCls<T>::completeError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    if (!future->_mayComplete)     {
        throw make<StateErrorCls>(__s("Future already completed"));
    }
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace = AsyncErrorCls->defaultStackTrace(error);
    }
    _completeError(error, stackTrace);
}

template<typename T>
bool _CompleterCls<T>::isCompleted() {
    return !future->_mayComplete;
}

template<typename T>
void _AsyncCompleterCls<T>::complete(FutureOr<T> value) {
    if (!future->_mayComplete)     {
        throw make<StateErrorCls>(__s("Future already completed"));
    }
    future->_asyncComplete(value == nullptr? as<dynamic>(value) : value);
}

template<typename T>
void _AsyncCompleterCls<T>::_completeError(Object error, StackTrace stackTrace) {
    future->_asyncCompleteError(error, stackTrace);
}

template<typename T>
void _SyncCompleterCls<T>::complete(FutureOr<T> value) {
    if (!future->_mayComplete)     {
        throw make<StateErrorCls>(__s("Future already completed"));
    }
    future->_complete(value == nullptr? as<dynamic>(value) : value);
}

template<typename T>
void _SyncCompleterCls<T>::_completeError(Object error, StackTrace stackTrace) {
    future->_completeError(error, stackTrace);
}

template<typename S, typename T>
void _FutureListenerCls<S, T>::then(std::function<void ()> errorCallback, std::function<FutureOr<T>(S )> onValue, _Future<T> result)

template<typename S, typename T>
void _FutureListenerCls<S, T>::thenAwait(std::function<void ()> errorCallback, std::function<FutureOr<T>(S )> onValue, _Future<T> result)

template<typename S, typename T>
void _FutureListenerCls<S, T>::catchError(std::function<void ()> callback, std::function<void ()> errorCallback, _Future<T> result)

template<typename S, typename T>
void _FutureListenerCls<S, T>::whenComplete(std::function<void ()> callback, _Future<T> result)

template<typename S, typename T>
bool _FutureListenerCls<S, T>::handlesValue() {
    return (state & maskValue != 0);
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::handlesError() {
    return (state & maskError != 0);
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::hasErrorTest() {
    return (state & maskType == stateCatchErrorTest);
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::handlesComplete() {
    return (state & maskType == stateWhenComplete);
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::hasErrorCallback() {
    assert(handlesError());
    return _onError() != nullptr;
}

template<typename S, typename T>
FutureOr<T> _FutureListenerCls<S, T>::handleValue(S sourceResult) {
    return _zone()-><FutureOr<T>, S>runUnary(_onValue(), sourceResult);
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::matchesErrorTest(AsyncError asyncError) {
    if (!hasErrorTest())     {
        return true;
    }
    return _zone()-><bool, Object>runUnary(_errorTest(), asyncError->error);
}

template<typename S, typename T>
FutureOr<T> _FutureListenerCls<S, T>::handleError(AsyncError asyncError) {
    assert(handlesError() && hasErrorCallback());
    auto errorCallback = this->errorCallback;
    dynamic result;
    if (is<std::function<dynamic(Object , StackTrace )>>(errorCallback)) {
        result = _zone()-><dynamic, Object, StackTrace>runBinary(errorCallback, asyncError->error, asyncError->stackTrace);
    } else {
        result = _zone()-><dynamic, Object>runUnary(as<dynamic>(errorCallback), asyncError->error);
    }
    try {
        return result;
    } catch (TypeError null) {
        if (handlesValue()) {
            throw make<ArgumentErrorCls>(__s("The error handler of Future.then must return a value of the returned future's type"), __s("onError"));
        }
        throw make<ArgumentErrorCls>(__s("The error handler of Future.catchError must return a value of the future's type"), __s("onError"));
    };
}

template<typename S, typename T>
dynamic _FutureListenerCls<S, T>::handleWhenComplete() {
    assert(!handlesError());
    return _zone()->run(_whenCompleteAction());
}

template<typename S, typename T>
bool _FutureListenerCls<S, T>::shouldChain(Future<dynamic> value) {
    return is<Future<T>>(value) || !is<T>(value);
}

template<typename S, typename T>
_Zone _FutureListenerCls<S, T>::_zone() {
    return result->_zone();
}

template<typename S, typename T>
std::function<FutureOr<T>(S )> _FutureListenerCls<S, T>::_onValue() {
    assert(handlesValue());
    return <std::function<FutureOr<T>(S )>>unsafeCast(callback);
}

template<typename S, typename T>
std::function<void ()> _FutureListenerCls<S, T>::_onError() {
    return errorCallback;
}

template<typename S, typename T>
std::function<bool(Object )> _FutureListenerCls<S, T>::_errorTest() {
    assert(hasErrorTest());
    return <std::function<bool(Object )>>unsafeCast(callback);
}

template<typename S, typename T>
std::function<dynamic()> _FutureListenerCls<S, T>::_whenCompleteAction() {
    assert(handlesComplete());
    return <std::function<dynamic()>>unsafeCast(callback);
}
