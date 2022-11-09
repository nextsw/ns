#include "future_impl.hpp"
template<typename T> void _CompleterCls<T>::completeError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    if (!future->_mayComplete)     {
        ;
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

template<typename T> bool _CompleterCls<T>::isCompleted() {
    return !future->_mayComplete;
}

template<typename T> void _AsyncCompleterCls<T>::complete(FutureOr<T> value) {
    if (!future->_mayComplete)     {
        ;
    }
    future->_asyncComplete(value == nullptr? ((dynamic)value) : value);
}

template<typename T> void _AsyncCompleterCls<T>::_completeError(Object error, StackTrace stackTrace) {
    future->_asyncCompleteError(error, stackTrace);
}

template<typename T> void _SyncCompleterCls<T>::complete(FutureOr<T> value) {
    if (!future->_mayComplete)     {
        ;
    }
    future->_complete(value == nullptr? ((dynamic)value) : value);
}

template<typename T> void _SyncCompleterCls<T>::_completeError(Object error, StackTrace stackTrace) {
    future->_completeError(error, stackTrace);
}

template<typename S, typename T> void _FutureListenerCls<S, T>::then(void  errorCallback() , FutureOr<T> onValue(S ) , _Future<T> result)

template<typename S, typename T> void _FutureListenerCls<S, T>::thenAwait(void  errorCallback() , FutureOr<T> onValue(S ) , _Future<T> result)

template<typename S, typename T> void _FutureListenerCls<S, T>::catchError(void  Function() callback, void  Function() errorCallback, _Future<T> result)

template<typename S, typename T> void _FutureListenerCls<S, T>::whenComplete(void  Function() callback, _Future<T> result)

template<typename S, typename T> bool _FutureListenerCls<S, T>::handlesValue() {
    return (state & maskValue != 0);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::handlesError() {
    return (state & maskError != 0);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::hasErrorTest() {
    return (state & maskType == stateCatchErrorTest);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::handlesComplete() {
    return (state & maskType == stateWhenComplete);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::hasErrorCallback() {
    assert(handlesError);
    return _onError != nullptr;
}

template<typename S, typename T> FutureOr<T> _FutureListenerCls<S, T>::handleValue(S sourceResult) {
    return _zone-><FutureOr<T>, S>runUnary(_onValue, sourceResult);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::matchesErrorTest(AsyncError asyncError) {
    if (!hasErrorTest)     {
        return true;
    }
    return _zone-><bool, Object>runUnary(_errorTest, asyncError->error);
}

template<typename S, typename T> FutureOr<T> _FutureListenerCls<S, T>::handleError(AsyncError asyncError) {
    assert(handlesError && hasErrorCallback);
    auto errorCallback = this->errorCallback;
    dynamic result;
    if (errorCallback is dynamic Function(Object , StackTrace )) {
        result = _zone-><dynamic, Object, StackTrace>runBinary(errorCallback, asyncError->error, asyncError->stackTrace);
    } else {
        result = _zone-><dynamic, Object>runUnary(((dynamic)errorCallback), asyncError->error);
    }
    try {
        return result;
    } catch (TypeError null) {
        if (handlesValue) {
            ;
        }
        ;
    };
}

template<typename S, typename T> dynamic _FutureListenerCls<S, T>::handleWhenComplete() {
    assert(!handlesError);
    return _zone->run(_whenCompleteAction);
}

template<typename S, typename T> bool _FutureListenerCls<S, T>::shouldChain(Future<dynamic> value) {
    return value is Future<T> || value is! T;
}

template<typename S, typename T> _Zone _FutureListenerCls<S, T>::_zone() {
    return result->_zone;
}

template<typename S, typename T> FutureOr<T> Function(S ) _FutureListenerCls<S, T>::_onValue() {
    assert(handlesValue);
    return <FutureOr<T> Function(S )>unsafeCast(callback);
}

template<typename S, typename T> void  Function() _FutureListenerCls<S, T>::_onError() {
    return errorCallback;
}

template<typename S, typename T> bool Function(Object ) _FutureListenerCls<S, T>::_errorTest() {
    assert(hasErrorTest);
    return <bool Function(Object )>unsafeCast(callback);
}

template<typename S, typename T> dynamic Function() _FutureListenerCls<S, T>::_whenCompleteAction() {
    assert(handlesComplete);
    return <dynamic Function()>unsafeCast(callback);
}
