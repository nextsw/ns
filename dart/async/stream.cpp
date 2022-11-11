#include "stream.hpp"
template<typename T>
void StreamCls<T>::value(T value) {
    return (_c3)->stream;
}

template<typename T>
void StreamCls<T>::error(Object error, StackTrace stackTrace) {
    auto _c1 = <T>make<_AsyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);_c1.auto _c2 = _add(value);_c2._closeUnchecked();_c2;auto _c3 = <T>make<_AsyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);_c3.auto _c4 = _add(value);_c4._closeUnchecked();_c4;checkNotNullable(error, __s("error"));
    auto _c1 = <T>make<_AsyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);_c1.auto _c2 = _addError(error, stackTrace | AsyncErrorCls->defaultStackTrace(error));_c2._closeUnchecked();_c2;auto _c3 = <T>make<_AsyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);_c3.auto _c4 = _addError(error, stackTrace | AsyncErrorCls->defaultStackTrace(error));_c4._closeUnchecked();_c4;return (_c3)->stream;
}

template<typename T>
void StreamCls<T>::fromFuture(Future<T> future) {
    _StreamController<T> controller = <T>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    future->then([=] (Unknown  value) {
        controller->_add(value);
        controller->_closeUnchecked();
    }, [=] (Unknown  error,Unknown  stackTrace) {
        controller->_addError(error, stackTrace);
        controller->_closeUnchecked();
    });
    return controller->stream();
}

template<typename T>
void StreamCls<T>::fromFutures(Iterable<Future<T>> futures) {
    _StreamController<T> controller = <T>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    int count = 0;
    InlineMethod;
    InlineMethod;
    for (auto future : futures) {
        count++;
        future->then(onValue, onError);
    }
    if (count == 0) {
        scheduleMicrotask(controller->close);
    }
    return controller->stream();
}

template<typename T>
void StreamCls<T>::fromIterable(Iterable<T> elements) {
    return <T>multi([=] (Unknown  controller) {
        Iterator<T> iterator;
        try {
            iterator = elements->iterator;
        } catch (Unknown e) {
            controller->addError(e, s);
            controller->close();
            return;
        };
        auto zone = ZoneCls::current;
        auto isScheduled = true;
        InlineMethod;
        controller->onResume = [=] () {
            if (!isScheduled) {
                isScheduled = true;
                zone->scheduleMicrotask(next);
            }
        };
        zone->scheduleMicrotask(next);
    });
}

template<typename T>
void StreamCls<T>::multi(std::function<void(MultiStreamController<T> )> onListen, bool isBroadcast) {
    return <T>make<_MultiStreamCls>(onListen, isBroadcast);
}

template<typename T>
void StreamCls<T>::periodic(Duration period, std::function<T(int computationCount)> computation) {
    if (computation == nullptr && !<T>typeAcceptsNull()) {
        throw ArgumentErrorCls->value(nullptr, __s("computation"), __s("Must not be omitted when the event type is non-nullable"));
    }
    auto controller = <T>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    Stopwatch watch = make<StopwatchCls>();
    controller->onListen = [=] () {
        int computationCount = 0;
        InlineMethod;
        Timer timer = TimerCls->periodic(period, sendEvent);
                    };    _c3;    _c2;        auto _c1 = controller;        _c1.onCancel = auto _c2 = [=] () {                    timer->cancel();                    return FutureCls::_nullFuture;                };        _c2.onPause = auto _c3 = [=] () {                    watch->stop();                    timer->cancel();                };        _c3.onResume = [=] () {                    Duration elapsed = watch->elapsed();                    watch->start();                    });                        timer = make<TimerCls>(period - elapsed, [=] () {                            timer = TimerCls->periodic(period, sendEvent);                            sendEvent(nullptr);_c1;
    };
    return controller->stream;
}

template<typename T>
void StreamCls<T>::eventTransformed(Stream<dynamic> source, std::function<EventSink<dynamic>(EventSink<T> sink)> mapSink) {
    return make<_BoundSinkStreamCls>(source, mapSink);
}

template<typename T>
template<typename S, typename T>
Stream<T> StreamCls<T>::castFrom(Stream<S> source) {
    return <S, T>make<CastStreamCls>(source);
}

template<typename T>
bool StreamCls<T>::isBroadcast() {
    return false;
}

template<typename T>
Stream<T> StreamCls<T>::asBroadcastStream(std::function<void(StreamSubscription<T> subscription)> onCancel, std::function<void(StreamSubscription<T> subscription)> onListen) {
    return <T>make<_AsBroadcastStreamCls>(this, onListen, onCancel);
}

template<typename T>
Stream<T> StreamCls<T>::where(std::function<bool(T event)> test) {
    return <T>make<_WhereStreamCls>(this, test);
}

template<typename T>
template<typename S>
Stream<S> StreamCls<T>::map(std::function<S(T event)> convert) {
    return <T, S>make<_MapStreamCls>(this, convert);
}

template<typename T>
template<typename E>
Stream<E> StreamCls<T>::asyncMap(std::function<FutureOr<E>(T event)> convert) {
    _StreamControllerBase<E> controller;
    if (isBroadcast()) {
        controller = <E>make<_SyncBroadcastStreamControllerCls>(nullptr, nullptr);
    } else {
        controller = <E>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    }
    controller->onListen = [=] () {
        StreamSubscription<T> subscription = this->listen(nullptr, controller->_addError, controller->close);
        InlineMethod;
        Unknown addError = controller->_addError;
        Unknown resume = subscription->resume;
        subscription->onData([=] (T event) {
            FutureOr<E> newValue;
            try {
                newValue = convert(event);
            } catch (Unknown e) {
                controller->addError(e, s);
                return;
            };
            if (is<Future<E>>(newValue)) {
                subscription->pause();
                as<FutureCls>(newValue)->then(add, addError)->whenComplete(resume);
            } else {
                controller->add(as<dynamic>(newValue));
            }
        });
        controller->onCancel = subscription->cancel;
        if (!isBroadcast()) {
                    auto _c1 = controller;        _c1.onPause = auto _c2 = subscription->pause;        _c2.onResume = resume;        _c2;_c1;
        }
    };
    return controller->stream();
}

template<typename T>
template<typename E>
Stream<E> StreamCls<T>::asyncExpand(std::function<Stream<E>(T event)> convert) {
    _StreamControllerBase<E> controller;
    if (isBroadcast()) {
        controller = <E>make<_SyncBroadcastStreamControllerCls>(nullptr, nullptr);
    } else {
        controller = <E>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    }
    controller->onListen = [=] () {
        StreamSubscription<T> subscription = this->listen(nullptr, controller->_addError, controller->close);
        subscription->onData([=] (T event) {
            Stream<E> newStream;
            try {
                newStream = convert(event);
            } catch (Unknown e) {
                controller->addError(e, s);
                return;
            };
            if (newStream != nullptr) {
                subscription->pause();
                controller->addStream(newStream)->whenComplete(subscription->resume);
            }
        });
        controller->onCancel = subscription->cancel;
        if (!isBroadcast()) {
                    auto _c1 = controller;        _c1.onPause = auto _c2 = subscription->pause;        _c2.onResume = subscription->resume;        _c2;_c1;
        }
    };
    return controller->stream();
}

template<typename T>
Stream<T> StreamCls<T>::handleError(std::function<void ()> onError, std::function<bool(error )> test) {
    std::function<void(Object , StackTrace )> callback;
    if (is<std::function<void(Object , StackTrace )>>(onError)) {
        callback = onError;
    } else {
        if (is<std::function<void(Object )>>(onError)) {
        callback = [=] (Object error,StackTrace _) {
            onError(error);
        };
    } else {
        throw ArgumentErrorCls->value(onError, __s("onError"), __s("Error handler must accept one Object or one Object and a StackTrace as arguments."));
    }
;
    }    return <T>make<_HandleErrorStreamCls>(this, callback, test);
}

template<typename T>
template<typename S>
Stream<S> StreamCls<T>::expand(std::function<Iterable<S>(T element)> convert) {
    return <T, S>make<_ExpandStreamCls>(this, convert);
}

template<typename T>
Future<any> StreamCls<T>::pipe(StreamConsumer<T> streamConsumer) {
    return streamConsumer->addStream(this)->then([=] () {
        streamConsumer->close();
    });
}

template<typename T>
template<typename S>
Stream<S> StreamCls<T>::transform(StreamTransformer<T, S> streamTransformer) {
    return streamTransformer->bind(this);
}

template<typename T>
Future<T> StreamCls<T>::reduce(std::function<T(T previous, T element)> combine) {
    _Future<T> result = <T>make<_FutureCls>();
    bool seenFirst = false;
    T value;
    StreamSubscription<T> subscription = this->listen(nullptr, result->_completeError, [=] () {
    if (!seenFirst) {
        try {
            throw IterableElementErrorCls->noElement();
        } catch (Unknown e) {
            _completeWithErrorCallback(result, e, s);
        };
    } else {
        result->_complete(value);
    }
}, true);
    subscription->onData([=] (T element) {
        if (seenFirst) {
            _runUserCode([=] () {
                combine(value, element);
            }, [=] (T newValue) {
                value = newValue;
            }, _cancelAndErrorClosure(subscription, result));
        } else {
            value = element;
            seenFirst = true;
        }
    });
    return result;
}

template<typename T>
template<typename S>
Future<S> StreamCls<T>::fold(S initialValue, std::function<S(S previous, T element)> combine) {
    _Future<S> result = <S>make<_FutureCls>();
    S value = initialValue;
    StreamSubscription<T> subscription = this->listen(nullptr, result->_completeError, [=] () {
    result->_complete(value);
}, true);
    subscription->onData([=] (T element) {
        _runUserCode([=] () {
            combine(value, element);
        }, [=] (S newValue) {
            value = newValue;
        }, _cancelAndErrorClosure(subscription, result));
    });
    return result;
}

template<typename T>
Future<String> StreamCls<T>::join(String separator) {
    _Future<String> result = <String>make<_FutureCls>();
    StringBuffer buffer = make<StringBufferCls>();
    bool first = true;
    StreamSubscription<T> subscription = this->listen(nullptr, result->_completeError, [=] () {
    result->_complete(buffer->toString());
}, true);
    subscription->onData(separator->isEmpty()? [=] (T element) {
        try {
            buffer->write(element);
        } catch (Unknown e) {
            _cancelAndErrorWithReplacement(subscription, result, e, s);
        };
    } : [=] (T element) {
        if (!first) {
            buffer->write(separator);
        }
        first = false;
        try {
            buffer->write(element);
        } catch (Unknown e) {
            _cancelAndErrorWithReplacement(subscription, result, e, s);
        };
    });
    return result;
}

template<typename T>
Future<bool> StreamCls<T>::contains(Object needle) {
    _Future<bool> future = <bool>make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    future->_complete(false);
}, true);
    subscription->onData([=] (T element) {
        _runUserCode([=] () {
            (element == needle);
        }, [=] (bool isMatch) {
            if (isMatch) {
                _cancelAndValue(subscription, future, true);
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<any> StreamCls<T>::forEach(std::function<void(T element)> action) {
    _Future<any> future = make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    future->_complete(nullptr);
}, true);
    subscription->onData([=] (T element) {
        <void>_runUserCode([=] () {
            action(element);
        }, [=] () {
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<bool> StreamCls<T>::every(std::function<bool(T element)> test) {
    _Future<bool> future = <bool>make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    future->_complete(true);
}, true);
    subscription->onData([=] (T element) {
        _runUserCode([=] () {
            test(element);
        }, [=] (bool isMatch) {
            if (!isMatch) {
                _cancelAndValue(subscription, future, false);
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<bool> StreamCls<T>::any(std::function<bool(T element)> test) {
    _Future<bool> future = <bool>make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    future->_complete(false);
}, true);
    subscription->onData([=] (T element) {
        _runUserCode([=] () {
            test(element);
        }, [=] (bool isMatch) {
            if (isMatch) {
                _cancelAndValue(subscription, future, true);
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<int> StreamCls<T>::length() {
    _Future<int> future = <int>make<_FutureCls>();
    int count = 0;
    this->listen([=] () {
        count++;
    }, future->_completeError, [=] () {
        future->_complete(count);
    }, true);
    return future;
}

template<typename T>
Future<bool> StreamCls<T>::isEmpty() {
    _Future<bool> future = <bool>make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    future->_complete(true);
}, true);
    subscription->onData([=] () {
        _cancelAndValue(subscription, future, false);
    });
    return future;
}

template<typename T>
template<typename R>
Stream<R> StreamCls<T>::cast() {
    return StreamCls-><T, R>castFrom(this);
}

template<typename T>
Future<List<T>> StreamCls<T>::toList() {
    List<T> result = makeList();
    _Future<List<T>> future = <List<T>>make<_FutureCls>();
    this->listen([=] (T data) {
        result->add(data);
    }, future->_completeError, [=] () {
        future->_complete(result);
    }, true);
    return future;
}

template<typename T>
Future<Set<T>> StreamCls<T>::toSet() {
    Set<T> result = <T>make<SetCls>();
    _Future<Set<T>> future = <Set<T>>make<_FutureCls>();
    this->listen([=] (T data) {
        result->add(data);
    }, future->_completeError, [=] () {
        future->_complete(result);
    }, true);
    return future;
}

template<typename T>
template<typename E>
Future<E> StreamCls<T>::drain(E futureValue) {
    if (futureValue == nullptr) {
        futureValue = as<E>(futureValue);
    }
    return listen(nullptr, true)-><E>asFuture(futureValue);
}

template<typename T>
Stream<T> StreamCls<T>::take(int count) {
    return <T>make<_TakeStreamCls>(this, count);
}

template<typename T>
Stream<T> StreamCls<T>::takeWhile(std::function<bool(T element)> test) {
    return <T>make<_TakeWhileStreamCls>(this, test);
}

template<typename T>
Stream<T> StreamCls<T>::skip(int count) {
    return <T>make<_SkipStreamCls>(this, count);
}

template<typename T>
Stream<T> StreamCls<T>::skipWhile(std::function<bool(T element)> test) {
    return <T>make<_SkipWhileStreamCls>(this, test);
}

template<typename T>
Stream<T> StreamCls<T>::distinct(std::function<bool(T previous, T next)> equals) {
    return <T>make<_DistinctStreamCls>(this, equals);
}

template<typename T>
Future<T> StreamCls<T>::first() {
    _Future<T> future = <T>make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    try {
        throw IterableElementErrorCls->noElement();
    } catch (Unknown e) {
        _completeWithErrorCallback(future, e, s);
    };
}, true);
    subscription->onData([=] (T value) {
        _cancelAndValue(subscription, future, value);
    });
    return future;
}

template<typename T>
Future<T> StreamCls<T>::last() {
    _Future<T> future = <T>make<_FutureCls>();
    T result;
    bool foundResult = false;
    listen([=] (T value) {
        foundResult = true;
        result = value;
    }, future->_completeError, [=] () {
        if (foundResult) {
            future->_complete(result);
            return;
        }
        try {
            throw IterableElementErrorCls->noElement();
        } catch (Unknown e) {
            _completeWithErrorCallback(future, e, s);
        };
    }, true);
    return future;
}

template<typename T>
Future<T> StreamCls<T>::single() {
    _Future<T> future = <T>make<_FutureCls>();
    T result;
    bool foundResult = false;
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    if (foundResult) {
        future->_complete(result);
        return;
    }
    try {
        throw IterableElementErrorCls->noElement();
    } catch (Unknown e) {
        _completeWithErrorCallback(future, e, s);
    };
}, true);
    subscription->onData([=] (T value) {
        if (foundResult) {
            try {
                throw IterableElementErrorCls->tooMany();
            } catch (Unknown e) {
                _cancelAndErrorWithReplacement(subscription, future, e, s);
            };
            return;
        }
        foundResult = true;
        result = value;
    });
    return future;
}

template<typename T>
Future<T> StreamCls<T>::firstWhere(std::function<bool(T element)> test, std::function<T()> orElse) {
    _Future<T> future = make<_FutureCls>();
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    if (orElse != nullptr) {
        _runUserCode(orElse, future->_complete, future->_completeError);
        return;
    }
    try {
        throw IterableElementErrorCls->noElement();
    } catch (Unknown e) {
        _completeWithErrorCallback(future, e, s);
    };
}, true);
    subscription->onData([=] (T value) {
        _runUserCode([=] () {
            test(value);
        }, [=] (bool isMatch) {
            if (isMatch) {
                _cancelAndValue(subscription, future, value);
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<T> StreamCls<T>::lastWhere(std::function<bool(T element)> test, std::function<T()> orElse) {
    _Future<T> future = make<_FutureCls>();
    T result;
    bool foundResult = false;
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    if (foundResult) {
        future->_complete(result);
        return;
    }
    if (orElse != nullptr) {
        _runUserCode(orElse, future->_complete, future->_completeError);
        return;
    }
    try {
        throw IterableElementErrorCls->noElement();
    } catch (Unknown e) {
        _completeWithErrorCallback(future, e, s);
    };
}, true);
    subscription->onData([=] (T value) {
        _runUserCode([=] () {
            test(value);
        }, [=] (bool isMatch) {
            if (isMatch) {
                foundResult = true;
                result = value;
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<T> StreamCls<T>::singleWhere(std::function<bool(T element)> test, std::function<T()> orElse) {
    _Future<T> future = <T>make<_FutureCls>();
    T result;
    bool foundResult = false;
    StreamSubscription<T> subscription = this->listen(nullptr, future->_completeError, [=] () {
    if (foundResult) {
        future->_complete(result);
        return;
    }
    if (orElse != nullptr) {
        _runUserCode(orElse, future->_complete, future->_completeError);
        return;
    }
    try {
        throw IterableElementErrorCls->noElement();
    } catch (Unknown e) {
        _completeWithErrorCallback(future, e, s);
    };
}, true);
    subscription->onData([=] (T value) {
        _runUserCode([=] () {
            test(value);
        }, [=] (bool isMatch) {
            if (isMatch) {
                if (foundResult) {
                    try {
                        throw IterableElementErrorCls->tooMany();
                    } catch (Unknown e) {
                        _cancelAndErrorWithReplacement(subscription, future, e, s);
                    };
                    return;
                }
                foundResult = true;
                result = value;
            }
        }, _cancelAndErrorClosure(subscription, future));
    });
    return future;
}

template<typename T>
Future<T> StreamCls<T>::elementAt(int index) {
    RangeErrorCls->checkNotNegative(index, __s("index"));
    _Future<T> result = <T>make<_FutureCls>();
    int elementIndex = 0;
    StreamSubscription<T> subscription;
    subscription = this->listen(nullptr, result->_completeError, [=] () {
        result->_completeError(RangeErrorCls->index(index, this, __s("index"), nullptr, elementIndex), StackTraceCls::empty);
    }, true);
    subscription->onData([=] (T value) {
        if (index == elementIndex) {
            _cancelAndValue(subscription, result, value);
            return;
        }
        elementIndex += 1;
    });
    return result;
}

template<typename T>
Stream<T> StreamCls<T>::timeout(Duration timeLimit, std::function<void(EventSink<T> sink)> onTimeout) {
    _StreamControllerBase<T> controller;
    if (isBroadcast()) {
        controller = <T>make<_SyncBroadcastStreamControllerCls>(nullptr, nullptr);
    } else {
        controller = <T>make<_SyncStreamControllerCls>(nullptr, nullptr, nullptr, nullptr);
    }
    Zone zone = ZoneCls::current;
    _TimerCallback timeoutCallback;
    if (onTimeout == nullptr) {
        timeoutCallback = [=] () {
            controller->addError(make<TimeoutExceptionCls>(__s("No stream event"), timeLimit), nullptr);
        };
    } else {
        auto registeredOnTimeout = zone-><void, EventSink<T>>registerUnaryCallback(onTimeout);
        auto wrapper = <T>make<_ControllerEventSinkWrapperCls>(nullptr);
        timeoutCallback = [=] () {
            wrapper->_sink = controller;
            zone->runUnaryGuarded(registeredOnTimeout, wrapper);
            wrapper->_sink = nullptr;
        };
    }
    controller->onListen = [=] () {
        Timer timer = zone->createTimer(timeLimit, timeoutCallback);
        auto subscription = this->listen(nullptr);
                    });    _c3;    _c2;        auto _c1 = subscription;        _c1.auto _c2 = onData([=] (T event) {                    timer->cancel();                    timer = zone->createTimer(timeLimit, timeoutCallback);                    controller->add(event);                });        _c2.auto _c3 = onError([=] (Object error,StackTrace stackTrace) {                    timer->cancel();                    timer = zone->createTimer(timeLimit, timeoutCallback);                    controller->_addError(error, stackTrace);                });        _c3.onDone([=] () {                    timer->cancel();                    controller->close();_c1;
        controller->onCancel = [=] () {
            timer->cancel();
            return subscription->cancel();
        };
        if (!isBroadcast()) {
                                };        _c5;            auto _c4 = controller;            _c4.onPause = auto _c5 = [=] () {                            timer->cancel();                            subscription->pause();                        };            _c5.onResume = [=] () {                            subscription->resume();                            timer = zone->createTimer(timeLimit, timeoutCallback);_c4;
        }
    };
    return controller->stream();
}

template<typename T>
StreamViewCls<T>::StreamViewCls(Stream<T> stream) {
    {
        _stream = stream;
        super->_internal();
    }
}

template<typename T>
bool StreamViewCls<T>::isBroadcast() {
    return _stream->isBroadcast();
}

template<typename T>
Stream<T> StreamViewCls<T>::asBroadcastStream(std::function<void(StreamSubscription<T> subscription)> onCancel, std::function<void(StreamSubscription<T> subscription)> onListen) {
    return _stream->asBroadcastStream(onListen, onCancel);
}

template<typename T>
StreamSubscription<T> StreamViewCls<T>::listen(std::function<void(T value)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    return _stream->listen(onData, onError, onDone, cancelOnError);
}

template<typename S, typename T>
template<typename SS, typename ST, typename TS, typename TT>
StreamTransformer<TS, TT> StreamTransformerCls<S, T>::castFrom(StreamTransformer<SS, ST> source) {
    return <SS, ST, TS, TT>make<CastStreamTransformerCls>(source);
}

template<typename S, typename T>
template<typename RS, typename RT>
StreamTransformer<RS, RT> StreamTransformerBaseCls<S, T>::cast() {
    return StreamTransformerCls-><S, T, RS, RT>castFrom(this);
}

template<typename T>
StreamIteratorCls<T>::StreamIteratorCls(Stream<T> stream) {
}

template<typename T>
void _ControllerEventSinkWrapperCls<T>::add(T data) {
    _ensureSink()->add(data);
}

template<typename T>
void _ControllerEventSinkWrapperCls<T>::addError(error , StackTrace stackTrace) {
    _ensureSink()->addError(error, stackTrace);
}

template<typename T>
void _ControllerEventSinkWrapperCls<T>::close() {
    _ensureSink()->close();
}

template<typename T>
EventSink<any> _ControllerEventSinkWrapperCls<T>::_ensureSink() {
    auto sink = _sink;
    if (sink == nullptr) {
        throw make<StateErrorCls>(__s("Sink not available"));
    }
    return sink;
}
