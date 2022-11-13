#include "future.hpp"
template<typename T>
void FutureOrCls<T>::_() {
    throw make<UnsupportedErrorCls>(__s("FutureOr can't be instantiated"));
}

template<typename T>
FutureCls<T>::FutureCls(std::function<FutureOr<T>()> computation) {
    {
        _Future<T> result = <T>make<_FutureCls>();
        TimerCls->run([=] () {
            try {
                result->_complete(computation());
            } catch (Unknown e) {
                _completeWithErrorCallback(result, e, s);
            };
        });
        return result;
    }
}

template<typename T>
void FutureCls<T>::microtask(std::function<FutureOr<T>()> computation) {
    _Future<T> result = <T>make<_FutureCls>();
    scheduleMicrotask([=] () {
        try {
            result->_complete(computation());
        } catch (Unknown e) {
            _completeWithErrorCallback(result, e, s);
        };
    });
    return result;
}

template<typename T>
void FutureCls<T>::sync(std::function<FutureOr<T>()> computation) {
    try {
        auto result = computation();
        if (is<Future<T>>(result)) {
            return as<FutureCls>(result);
        } else {
            return <T>value(as<Object>(result));
        }
    } catch (Unknown error) {
        auto future = <T>make<_FutureCls>();
        AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
        if (replacement != nullptr) {
            future->_asyncCompleteError(replacement->error, replacement->stackTrace);
        } else {
            future->_asyncCompleteError(error, stackTrace);
        }
        return future;
    };
}

template<typename T>
void FutureCls<T>::value(FutureOr<T> value) {
    return <T>immediate(value == nullptr? as<T>(value) : value);
}

template<typename T>
void FutureCls<T>::error(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    if (!identical(ZoneCls::current, _rootZone)) {
        AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
        if (replacement != nullptr) {
            error = replacement->error;
            stackTrace = replacement->stackTrace;
        }
    }
    stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    return <T>immediateError(error, stackTrace);
}

template<typename T>
void FutureCls<T>::delayed(Duration duration, std::function<FutureOr<T>()> computation) {
    if (computation == nullptr && !<T>typeAcceptsNull()) {
        throw ArgumentErrorCls->value(nullptr, __s("computation"), __s("The type parameter is not nullable"));
    }
    _Future<T> result = <T>make<_FutureCls>();
    make<TimerCls>(duration, [=] () {
        if (computation == nullptr) {
            result->_complete(as<T>(nullptr));
        } else {
            try {
                result->_complete(computation());
            } catch (Unknown e) {
                _completeWithErrorCallback(result, e, s);
            };
        }
    });
    return result;
}

template<typename T>
template<typename T>
Future<List<T>> FutureCls<T>::wait(Iterable<Future<T>> futures, std::function<void(T successValue)> cleanUp, bool eagerError) {
    _Future<List<T>> _future = <List<T>>make<_FutureCls>();
    List<T> values;
    int remaining = 0;
    Object error;
    StackTrace stackTrace;
    InlineMethod;
    try {
        for (auto future : futures) {
            int pos = remaining;
            future->then([=] (T value) {
                remaining--;
                List<T> valueList = values;
                if (valueList != nullptr) {
                    valueList[pos] = value;
                    if (remaining == 0) {
                        _future->_completeWithValue(<T>from(valueList));
                    }
                } else {
                    if (cleanUp != nullptr && value != nullptr) {
                        FutureCls->sync([=] () {
                            cleanUp(value);
                        });
                    }
                    if (remaining == 0 && !eagerError) {
                        _future->_completeError(error, stackTrace);
                    }
                }
            }, handleError);
            remaining++;
        }
        if (remaining == 0) {
                    auto _c1 = _future;        _c1._completeWithValue(makeList());return _c1;
        }
        values = <T>filled(remaining, nullptr);
    } catch (Unknown e) {
        if (remaining == 0 || eagerError) {
            return FutureCls->error(e, st);
        } else {
            error = e;
            stackTrace = st;
        }
    };
    return _future;
}

template<typename T>
template<typename T>
Future<T> FutureCls<T>::any(Iterable<Future<T>> futures) {
    auto completer = <T>sync();
    InlineMethod;
    InlineMethod;
    for (auto future : futures) {
        future->then(onValue, onError);
    }
    return completer->future;
}

template<typename T>
template<typename T>
Future<any> FutureCls<T>::forEach(Iterable<T> elements, std::function<FutureOr<any>(T element)> action) {
    auto iterator = elements->iterator();
    return doWhile([=] () {
        if (!iterator->moveNext()) {
            return false;
        }
        auto result = action(iterator->current());
        if (is<Future<any>>(result)) {
            return as<FutureCls>(result)->then(_kTrue);
        }
        return true;
    });
}

template<typename T>
Future<any> FutureCls<T>::doWhile(std::function<FutureOr<bool>()> action) {
    _Future<void> doneSignal = <void>make<_FutureCls>();
    std::function<void(bool )> nextIteration;
    nextIteration = ZoneCls::current->bindUnaryCallbackGuarded([=] (bool keepGoing) {
        while (keepGoing) {
            FutureOr<bool> result;
            try {
                result = action();
            } catch (Unknown error) {
                _asyncCompleteWithErrorCallback(doneSignal, error, stackTrace);
                return;
            };
            if (is<Future<bool>>(result)) {
                as<FutureCls>(result)->then(nextIteration, doneSignal->_completeError);
                return;
            }
            keepGoing = as<bool>(result);
        }
        doneSignal->_complete(nullptr);
    });
    nextIteration(true);
    return doneSignal;
}

template<typename T>
bool FutureCls<T>::_kTrue(Object _) {
    return true;
}

void unawaited(Future<void> future) {
}

template<typename T>
template<typename E>
Future<T> FutureExtensionsCls<T>::onError(std::function<FutureOr<T>(E error, StackTrace stackTrace)> handleError, std::function<bool(E error)> test) {
    return this->catchError([=] (Object error,StackTrace stackTrace) {
        handleError(as<E>(error), stackTrace);
    }, [=] (Object error) {
        is<E>(error) && (test == nullptr || test(error));
    });
}

template<typename T>
void FutureExtensionsCls<T>::ignore() {
    auto self = this;
    if (is<_Future<T>>(self)) {
        as<_FutureCls>(self)->_ignore();
    } else {
        self-><void>then(_ignore, _ignore);
    }
}

template<typename T>
void FutureExtensionsCls<T>::_ignore(Object _, Object __) {
}

String TimeoutExceptionCls::toString() {
    String result = __s("TimeoutException");
    if (duration != nullptr) {
        result = __sf("TimeoutException after %s", duration);
    }
    if (message != nullptr) {
        result = __sf("%s: %s", result, message);
    }
    return result;
}

template<typename T>
CompleterCls<T>::CompleterCls() {
}

template<typename T>
void CompleterCls<T>::sync() {
    return <T>make<_SyncCompleterCls>();
}

void _completeWithErrorCallback(_Future<any> result, Object error, StackTrace stackTrace) {
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    }
    result->_completeError(error, stackTrace);
}

void _asyncCompleteWithErrorCallback(_Future<any> result, Object error, StackTrace stackTrace) {
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    }
    if (stackTrace == nullptr) {
        throw __s("unreachable");
    }
    result->_asyncCompleteError(error, stackTrace);
}
