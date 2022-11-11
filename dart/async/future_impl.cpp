#include "future_impl.hpp"
template<typename T>
void _CompleterCls<T>::completeError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    if (!future->_mayComplete()) {
        throw make<StateErrorCls>(__s("Future already completed"));
    }
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    }
    _completeError(error, stackTrace);
}

template<typename T>
bool _CompleterCls<T>::isCompleted() {
    return !future->_mayComplete();
}

template<typename T>
void _AsyncCompleterCls<T>::complete(FutureOr<T> value) {
    if (!future->_mayComplete()) {
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
    if (!future->_mayComplete()) {
        throw make<StateErrorCls>(__s("Future already completed"));
    }
    future->_complete(value == nullptr? as<dynamic>(value) : value);
}

template<typename T>
void _SyncCompleterCls<T>::_completeError(Object error, StackTrace stackTrace) {
    future->_completeError(error, stackTrace);
}

template<typename S, typename T>
void _FutureListenerCls<S, T>::then(_Future<T> result, std::function<FutureOr<T>(S )> onValue, std::function<void ()> errorCallback){

}

template<typename S, typename T>
void _FutureListenerCls<S, T>::thenAwait(_Future<T> result, std::function<FutureOr<T>(S )> onValue, std::function<void ()> errorCallback){

}

template<typename S, typename T>
void _FutureListenerCls<S, T>::catchError(_Future<T> result, std::function<void ()> errorCallback, std::function<void ()> callback){

}

template<typename S, typename T>
void _FutureListenerCls<S, T>::whenComplete(_Future<T> result, std::function<void ()> callback){
    
}

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
    if (!hasErrorTest()) {
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
    return result->_zone;
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

template<typename T>
void _FutureCls<T>::immediate(FutureOr<T> result) {
    _asyncComplete(result);
}

template<typename T>
void _FutureCls<T>::zoneValue(T value, _Zone _zone) {
    _setValue(value);
}

template<typename T>
void _FutureCls<T>::immediateError(auto error, StackTrace stackTrace) {
    _asyncCompleteError(error, stackTrace);
}

template<typename T>
void _FutureCls<T>::value(T value)

template<typename T>
template<typename R>
Future<R> _FutureCls<T>::then(std::function<FutureOr<R>(T value)> f, std::function<void ()> onError) {
    Zone currentZone = ZoneCls::current;
    if (identical(currentZone, _rootZone)) {
        if (onError != nullptr && !is<std::function<void (Object , StackTrace )>>(onError) && !is<std::function<void (Object )>>(onError)) {
            throw ArgumentErrorCls->value(onError, __s("onError"), __s("Error handler must accept one Object or one Object and a StackTrace as arguments, and return a value of the returned future's type"));
        }
    } else {
        f = currentZone-><FutureOr<R>, T>registerUnaryCallback(f);
        if (onError != nullptr) {
            onError = _registerErrorHandler(onError, currentZone);
        }
    }
    _Future<R> result = <R>make<_FutureCls>();
    _addListener(<T, R>then(result, f, onError));
    return result;
}

template<typename T>
Future<T> _FutureCls<T>::catchError(std::function<void ()> onError, std::function<bool(Object error)> test) {
    _Future<T> result = <T>make<_FutureCls>();
    if (!identical(result->_zone, _rootZone)) {
        onError = _registerErrorHandler(onError, result->_zone);
        if (test != nullptr) {
            test = result->_zone->registerUnaryCallback(test);
        }
    }
    _addListener(<T, T>catchError(result, onError, test));
    return result;
}

template<typename T>
Future<T> _FutureCls<T>::whenComplete(std::function<dynamic()> action) {
    _Future<T> result = <T>make<_FutureCls>();
    if (!identical(result->_zone, _rootZone)) {
        action = result->_zone-><dynamic>registerCallback(action);
    }
    _addListener(<T, T>whenComplete(result, action));
    return result;
}

template<typename T>
Stream<T> _FutureCls<T>::asStream() {
    return <T>fromFuture(this);
}

template<typename T>
Future<T> _FutureCls<T>::timeout(Duration timeLimit, std::function<FutureOr<T>()> onTimeout) {
    if (_isComplete()) {
        return _FutureCls->immediate(this);
    }
    _Future<T> _future = <T>make<_FutureCls>();
    Timer timer;
    if (onTimeout == nullptr) {
        timer = make<TimerCls>(timeLimit, [=] () {
            _future->_completeError(make<TimeoutExceptionCls>(__s("Future not completed"), timeLimit), StackTraceCls::empty);
        });
    } else {
        Zone zone = ZoneCls::current;
        std::function<FutureOr<T>()> onTimeoutHandler = zone->registerCallback(onTimeout);
        timer = make<TimerCls>(timeLimit, [=] () {
            try {
                _future->_complete(zone->run(onTimeoutHandler));
            } catch (Unknown e) {
                _future->_completeError(e, s);
            };
        });
    }
    this->then([=] (T v) {
        if (timer->isActive()) {
            timer->cancel();
            _future->_completeWithValue(v);
        }
    }, [=] (Object e,StackTrace s) {
        if (timer->isActive()) {
            timer->cancel();
            _future->_completeError(e, s);
        }
    });
    return _future;
}

template<typename T>
_FutureCls<T>::_FutureCls() {
    {
        _zone = ZoneCls::_current;
    }
}

template<typename T>
bool _FutureCls<T>::_mayComplete() {
    return (_state & _completionStateMask) == _stateIncomplete;
}

template<typename T>
bool _FutureCls<T>::_isPendingComplete() {
    return (_state & _statePendingComplete) != 0;
}

template<typename T>
bool _FutureCls<T>::_mayAddListener() {
    return _state <= (_statePendingComplete | _stateIgnoreError);
}

template<typename T>
bool _FutureCls<T>::_isChained() {
    return (_state & _stateChained) != 0;
}

template<typename T>
bool _FutureCls<T>::_isComplete() {
    return (_state & (_stateValue | _stateError)) != 0;
}

template<typename T>
bool _FutureCls<T>::_hasError() {
    return (_state & _stateError) != 0;
}

template<typename T>
bool _FutureCls<T>::_ignoreError() {
    return (_state & _stateIgnoreError) != 0;
}

template<typename T>
void _FutureCls<T>::_setChained(_Future<any> source) {
    assert(_mayAddListener());
    _state = _stateChained | (_state & _stateIgnoreError);
    _resultOrListeners = source;
}

template<typename T>
template<typename E>
Future<E> _FutureCls<T>::_thenAwait(std::function<FutureOr<E>(T value)> f, std::function<void ()> onError) {
    _Future<E> result = <E>make<_FutureCls>();
    _addListener(<T, E>thenAwait(result, f, onError));
    return result;
}

template<typename T>
void _FutureCls<T>::_ignore() {
    _state |= _stateIgnoreError;
}

template<typename T>
void _FutureCls<T>::_setPendingComplete() {
    assert(_mayComplete());
    _state ^= _stateIncomplete ^ _statePendingComplete;
}

template<typename T>
void _FutureCls<T>::_clearPendingComplete() {
    assert(_isPendingComplete());
    _state ^= _statePendingComplete ^ _stateIncomplete;
}

template<typename T>
AsyncError _FutureCls<T>::_error() {
    assert(_hasError());
    return _resultOrListeners;
}

template<typename T>
_Future<any> _FutureCls<T>::_chainSource() {
    assert(_isChained());
    return _resultOrListeners;
}

template<typename T>
void _FutureCls<T>::_setValue(T value) {
    assert(!_isComplete());
    _state = _stateValue;
    _resultOrListeners = value;
}

template<typename T>
void _FutureCls<T>::_setErrorObject(AsyncError error) {
    assert(!_isComplete());
    _state = _stateError | (_state & _stateIgnoreError);
    _resultOrListeners = error;
}

template<typename T>
void _FutureCls<T>::_setError(Object error, StackTrace stackTrace) {
    _setErrorObject(make<AsyncErrorCls>(error, stackTrace));
}

template<typename T>
void _FutureCls<T>::_cloneResult(_Future<any> source) {
    assert(!_isComplete());
    assert(source->_isComplete());
    _state = (source->_state & _completionStateMask) | (_state & _stateIgnoreError);
    _resultOrListeners = source->_resultOrListeners;
}

template<typename T>
void _FutureCls<T>::_addListener(_FutureListener<any, any> listener) {
    assert(listener->_nextListener == nullptr);
    if (_mayAddListener()) {
        listener->_nextListener = _resultOrListeners;
        _resultOrListeners = listener;
    } else {
        if (_isChained()) {
            _Future<any> source = _chainSource();
            if (!source->_isComplete()) {
                source->_addListener(listener);
                return;
            }
            _cloneResult(source);
        }
        assert(_isComplete());
        _zone->scheduleMicrotask([=] () {
            _propagateToListeners(this, listener);
        });
    }
}

template<typename T>
void _FutureCls<T>::_prependListeners(_FutureListener<any, any> listeners) {
    if (listeners == nullptr) {
        return;
    }
    if (_mayAddListener()) {
        _FutureListener<any, any> existingListeners = _resultOrListeners;
        _resultOrListeners = listeners;
        if (existingListeners != nullptr) {
            _FutureListener<any, any> cursor = listeners;
            _FutureListener<any, any> next = cursor->_nextListener;
            while (next != nullptr) {
                cursor = next;
                next = cursor->_nextListener;
            }
            cursor->_nextListener = existingListeners;
        }
    } else {
        if (_isChained()) {
            _Future<any> source = _chainSource();
            if (!source->_isComplete()) {
                source->_prependListeners(listeners);
                return;
            }
            _cloneResult(source);
        }
        assert(_isComplete());
        listeners = _reverseListeners(listeners);
        _zone->scheduleMicrotask([=] () {
            _propagateToListeners(this, listeners);
        });
    }
}

template<typename T>
_FutureListener<any, any> _FutureCls<T>::_removeListeners() {
    assert(!_isComplete());
    _FutureListener<any, any> current = _resultOrListeners;
    _resultOrListeners = nullptr;
    return _reverseListeners(current);
}

template<typename T>
_FutureListener<any, any> _FutureCls<T>::_reverseListeners(_FutureListener<any, any> listeners) {
    _FutureListener<any, any> prev = nullptr;
    _FutureListener<any, any> current = listeners;
    while (current != nullptr) {
        _FutureListener<any, any> next = current->_nextListener;
        current->_nextListener = prev;
        prev = current;
        current = next;
    }
    return prev;
}

template<typename T>
void _FutureCls<T>::_chainForeignFuture(Future<any> source) {
    assert(!_isComplete());
    assert(!is<_Future<any>>(source));
    _setPendingComplete();
    try {
        source->then([=] (Unknown  value) {
            assert(_isPendingComplete());
            _clearPendingComplete();
            try {
                _completeWithValue(as<T>(value));
            } catch (Unknown error) {
                _completeError(error, stackTrace);
            };
        }, [=] (Object error,StackTrace stackTrace) {
            assert(_isPendingComplete());
            _completeError(error, stackTrace);
        });
    } catch (Unknown e) {
        scheduleMicrotask([=] () {
            _completeError(e, s);
        });
    };
}

template<typename T>
void _FutureCls<T>::_chainCoreFuture(_Future<any> source, _Future<any> target) {
    assert(target->_mayAddListener());
    while (source->_isChained()) {
        source = source->_chainSource();
    }
    if (source->_isComplete()) {
        _FutureListener<any, any> listeners = target->_removeListeners();
        target->_cloneResult(source);
        _propagateToListeners(target, listeners);
    } else {
        _FutureListener<any, any> listeners = target->_resultOrListeners;
        target->_setChained(source);
        source->_prependListeners(listeners);
    }
}

template<typename T>
void _FutureCls<T>::_complete(FutureOr<T> value) {
    assert(!_isComplete());
    if (is<Future<T>>(value)) {
        if (is<_Future<T>>(as<FutureCls>(value))) {
            _chainCoreFuture(as<_FutureCls>(value), this);
        } else {
            _chainForeignFuture(value);
        }
    } else {
        _FutureListener<any, any> listeners = _removeListeners();
        _setValue(as<dynamic>(value));
        _propagateToListeners(this, listeners);
    }
}

template<typename T>
void _FutureCls<T>::_completeWithValue(T value) {
    assert(!_isComplete());
    _FutureListener<any, any> listeners = _removeListeners();
    _setValue(value);
    _propagateToListeners(this, listeners);
}

template<typename T>
void _FutureCls<T>::_completeError(Object error, StackTrace stackTrace) {
    assert(!_isComplete());
    _FutureListener<any, any> listeners = _removeListeners();
    _setError(error, stackTrace);
    _propagateToListeners(this, listeners);
}

template<typename T>
void _FutureCls<T>::_asyncComplete(FutureOr<T> value) {
    assert(!_isComplete());
    if (is<Future<T>>(value)) {
        _chainFuture(as<FutureCls>(value));
        return;
    }
    _asyncCompleteWithValue(as<dynamic>(value));
}

template<typename T>
void _FutureCls<T>::_asyncCompleteUnchecked(dynamic value) {
    assert(identical(as<FutureOr<T>>(value), value));
    Unknown typedValue = <FutureOr<T>>unsafeCast(value);
    if (is<Future<T>>(typedValue)) {
        _chainFuture(as<FutureCls>(typedValue));
        return;
    }
    _asyncCompleteWithValue(<T>unsafeCast(typedValue));
}

template<typename T>
void _FutureCls<T>::_asyncCompleteUncheckedNoFuture(dynamic value) {
    assert(identical(as<T>(value), value));
    _asyncCompleteWithValue(<T>unsafeCast(value));
}

template<typename T>
void _FutureCls<T>::_asyncCompleteWithValue(T value) {
    _setPendingComplete();
    _zone->scheduleMicrotask([=] () {
        _completeWithValue(value);
    });
}

template<typename T>
void _FutureCls<T>::_chainFuture(Future<T> value) {
    if (is<_Future<T>>(value)) {
        if (as<_FutureCls>(value)->_hasError()) {
            _setPendingComplete();
            _zone->scheduleMicrotask([=] () {
                _chainCoreFuture(value, this);
            });
        } else {
            _chainCoreFuture(value, this);
        }
        return;
    }
    _chainForeignFuture(value);
}

template<typename T>
void _FutureCls<T>::_asyncCompleteError(Object error, StackTrace stackTrace) {
    assert(!_isComplete());
    _setPendingComplete();
    _zone->scheduleMicrotask([=] () {
        _completeError(error, stackTrace);
    });
}

template<typename T>
void _FutureCls<T>::_propagateToListeners(_Future<any> source, _FutureListener<any, any> listeners) {
    while (true) {
        assert(source->_isComplete());
        bool hasError = source->_hasError();
        if (listeners == nullptr) {
            if (hasError && !source->_ignoreError()) {
                AsyncError asyncError = source->_error();
                source->_zone->handleUncaughtError(asyncError->error, asyncError->stackTrace);
            }
            return;
        }
        _FutureListener<any, any> listener = listeners;
        _FutureListener<any, any> nextListener = listener->_nextListener;
        while (nextListener != nullptr) {
            listener->_nextListener = nullptr;
            _propagateToListeners(source, listener);
            listener = nextListener;
            nextListener = listener->_nextListener;
        }
        dynamic sourceResult = source->_resultOrListeners;
        bool listenerHasError = hasError;
        auto listenerValueOrError = sourceResult;
        if (hasError || listener->handlesValue() || listener->handlesComplete()) {
            _Zone zone = listener->_zone();
            if (hasError && !source->_zone->inSameErrorZone(zone)) {
                AsyncError asyncError = source->_error();
                source->_zone->handleUncaughtError(asyncError->error, asyncError->stackTrace);
                return;
            }
            _Zone oldZone;
            if (!identical(ZoneCls::_current, zone)) {
                oldZone = ZoneCls->_enter(zone);
            }
            InlineMethod;
            InlineMethod;
            InlineMethod;
            if (listener->handlesComplete()) {
                handleWhenCompleteCallback();
            } else {
                if (!hasError) {
                if (listener->handlesValue()) {
                    handleValueCallback();
                }
            } else {
                if (listener->handlesError()) {
                    handleError();
                }
            }
;
            }            if (oldZone != nullptr) {
                ZoneCls->_leave(oldZone);
            }
            if (is<Future<any>>(listenerValueOrError) && listener->shouldChain(listenerValueOrError)) {
                Future<any> chainSource = listenerValueOrError;
                _Future<any> result = listener->result;
                if (is<_Future<any>>(chainSource)) {
                    if (as<_FutureCls>(chainSource)->_isComplete()) {
                        listeners = result->_removeListeners();
                        result->_cloneResult(chainSource);
                        source = chainSource;
                        continue;
                    } else {
                        _chainCoreFuture(chainSource, result);
                    }
                } else {
                    result->_chainForeignFuture(chainSource);
                }
                return;
            }
        }
        _Future<any> result = listener->result;
        listeners = result->_removeListeners();
        if (!listenerHasError) {
            result->_setValue(listenerValueOrError);
        } else {
            AsyncError asyncError = listenerValueOrError;
            result->_setErrorObject(asyncError);
        }
        source = result;
    }
}

std::function<void ()> _registerErrorHandler(std::function<void ()> errorHandler, Zone zone) {
    if (is<std::function<dynamic(Object , StackTrace )>>(errorHandler)) {
        return zone-><dynamic, Object, StackTrace>registerBinaryCallback(errorHandler);
    }
    if (is<std::function<dynamic(Object )>>(errorHandler)) {
        return zone-><dynamic, Object>registerUnaryCallback(errorHandler);
    }
    throw ArgumentErrorCls->value(errorHandler, __s("onError"), __s("Error handler must accept one Object or one Object and a StackTrace as arguments, and return a value of the returned future's type"));
}
