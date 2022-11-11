#include "stream_pipe.hpp"
template<typename T>
void _runUserCode(onSuccess , onError , std::function<T()> userCode) {
    try {
        onSuccess(userCode());
    } catch (Unknown e) {
        AsyncError replacement = ZoneCls::current->errorCallback(e, s);
        if (replacement == nullptr) {
            onError(e, s);
        } else {
            auto error = replacement->error;
            auto stackTrace = replacement->stackTrace;
            onError(error, stackTrace);
        }
    };
}

void _cancelAndError(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription) {
    auto cancelFuture = subscription->cancel();
    if (cancelFuture != nullptr && !identical(cancelFuture, FutureCls::_nullFuture)) {
        cancelFuture->whenComplete([=] ()         {
            future->_completeError(error, stackTrace);
        });
    } else {
        future->_completeError(error, stackTrace);
    }
}

void _cancelAndErrorWithReplacement(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription) {
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    }
    _cancelAndError(subscription, future, error, stackTrace);
}

std::function<void(Object error, StackTrace stackTrace)> _cancelAndErrorClosure(_Future future, StreamSubscription subscription) {
    return [=] (Object error,StackTrace stackTrace) {
        _cancelAndError(subscription, future, error, stackTrace);
    };
}

void _cancelAndValue(value , _Future future, StreamSubscription subscription) {
    auto cancelFuture = subscription->cancel();
    if (cancelFuture != nullptr && !identical(cancelFuture, FutureCls::_nullFuture)) {
        cancelFuture->whenComplete([=] ()         {
            future->_complete(value);
        });
    } else {
        future->_complete(value);
    }
}

template<typename S, typename T>
bool _ForwardingStreamCls<S, T>::isBroadcast() {
    return _source->isBroadcast();
}

template<typename S, typename T>
StreamSubscription<T> _ForwardingStreamCls<S, T>::listen(bool cancelOnError, std::function<void(T value)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return _createSubscription(onData, onError, onDone, cancelOnError or false);
}

template<typename S, typename T>
StreamSubscription<T> _ForwardingStreamCls<S, T>::_createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return <S, T>make<_ForwardingStreamSubscriptionCls>(this, onData, onError, onDone, cancelOnError);
}

template<typename S, typename T>
void _ForwardingStreamCls<S, T>::_handleError(Object error, _EventSink<T> sink, StackTrace stackTrace) {
    sink->_addError(error, stackTrace);
}

template<typename S, typename T>
void _ForwardingStreamCls<S, T>::_handleDone(_EventSink<T> sink) {
    sink->_close();
}

template<typename S, typename T>
_ForwardingStreamSubscriptionCls<S, T>::_ForwardingStreamSubscriptionCls(_ForwardingStream<S, T> _stream, bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) : _BufferingStreamSubscription<T>(onData, onError, onDone, cancelOnError) {
    {
        _subscription = _stream->_source->listen(_handleData_handleError, _handleDone);
    }
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_add(T data) {
    if (_isClosed)     {
        return;
    }
    super->_add(data);
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_addError(Object error, StackTrace stackTrace) {
    if (_isClosed)     {
        return;
    }
    super->_addError(error, stackTrace);
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_onPause() {
    _subscription?->pause();
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_onResume() {
    _subscription?->resume();
}

template<typename S, typename T>
Future<void> _ForwardingStreamSubscriptionCls<S, T>::_onCancel() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        return subscription->cancel();
    }
    return nullptr;
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_handleData(S data) {
    _stream->_handleData(data, this);
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_handleError(error , StackTrace stackTrace) {
    _stream->_handleError(error, stackTrace, this);
}

template<typename S, typename T>
void _ForwardingStreamSubscriptionCls<S, T>::_handleDone() {
    _stream->_handleDone(this);
}

void _addErrorWithReplacement(Object error, _EventSink sink, StackTrace stackTrace) {
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    }
    sink->_addError(error, stackTrace);
}

template<typename T>
_WhereStreamCls<T>::_WhereStreamCls(Stream<T> source, std::function<bool(T value)> test) : _ForwardingStream<T, T>(source) {
    {
        _test = test;
    }
}

template<typename T>
void _WhereStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    bool satisfies;
    try {
        satisfies = _test(inputEvent);
    } catch (Unknown e) {
        _addErrorWithReplacement(sink, e, s);
        return;
    };
    if (satisfies) {
        sink->_add(inputEvent);
    }
}

template<typename S, typename T>
_MapStreamCls<S, T>::_MapStreamCls(Stream<S> source, std::function<T(S event)> transform) : _ForwardingStream<S, T>(source) {
    {
        this->_transform = transform;
    }
}

template<typename S, typename T>
void _MapStreamCls<S, T>::_handleData(S inputEvent, _EventSink<T> sink) {
    T outputEvent;
    try {
        outputEvent = _transform(inputEvent);
    } catch (Unknown e) {
        _addErrorWithReplacement(sink, e, s);
        return;
    };
    sink->_add(outputEvent);
}

template<typename S, typename T>
_ExpandStreamCls<S, T>::_ExpandStreamCls(std::function<Iterable<T>(S event)> expand, Stream<S> source) : _ForwardingStream<S, T>(source) {
    {
        this->_expand = expand;
    }
}

template<typename S, typename T>
void _ExpandStreamCls<S, T>::_handleData(S inputEvent, _EventSink<T> sink) {
    try {
        for (T value : _expand(inputEvent)) {
            sink->_add(value);
        }
    } catch (Unknown e) {
        _addErrorWithReplacement(sink, e, s);
    };
}

template<typename T>
_HandleErrorStreamCls<T>::_HandleErrorStreamCls(std::function<void(Object , StackTrace )> _onError, std::function<bool(Object )> _test, Stream<T> source) : _ForwardingStream<T, T>(source) {
}

template<typename T>
void _HandleErrorStreamCls<T>::_handleData(T data, _EventSink<T> sink) {
    sink->_add(data);
}

template<typename T>
void _HandleErrorStreamCls<T>::_handleError(Object error, _EventSink<T> sink, StackTrace stackTrace) {
    bool matches = true;
    auto test = _test;
    if (test != nullptr) {
        try {
            matches = test(error);
        } catch (Unknown e) {
            _addErrorWithReplacement(sink, e, s);
            return;
        };
    }
    if (matches) {
        try {
            _onError(error, stackTrace);
        } catch (Unknown e) {
            if (identical(e, error)) {
                sink->_addError(error, stackTrace);
            } else {
                _addErrorWithReplacement(sink, e, s);
            }
            return;
        };
    } else {
        sink->_addError(error, stackTrace);
    }
}

template<typename T>
_TakeStreamCls<T>::_TakeStreamCls(int count, Stream<T> source) : _ForwardingStream<T, T>(source) {
    {
        this->_count = count;
    }
}

template<typename T>
StreamSubscription<T> _TakeStreamCls<T>::_createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    if (_count == 0) {
        _source->listen(nullptr)->cancel();
        return <T>make<_DoneStreamSubscriptionCls>(onDone);
    }
    return <int, T>make<_StateStreamSubscriptionCls>(this, onData, onError, onDone, cancelOnError, _count);
}

template<typename T>
void _TakeStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = as<_StateStreamSubscription<int, T>>(sink);
    int count = subscription->_subState;
    if (count > 0) {
        sink->_add(inputEvent);
        count = 1;
        subscription->_subState = count;
        if (count == 0) {
            sink->_close();
        }
    }
}

template<typename S, typename T>
_StateStreamSubscriptionCls<S, T>::_StateStreamSubscriptionCls(S _subState, bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError, _ForwardingStream<T, T> stream) : _ForwardingStreamSubscription<T, T>(stream, onData, onError, onDone, cancelOnError) {
}

template<typename T>
_TakeWhileStreamCls<T>::_TakeWhileStreamCls(Stream<T> source, std::function<bool(T value)> test) : _ForwardingStream<T, T>(source) {
    {
        this->_test = test;
    }
}

template<typename T>
void _TakeWhileStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    bool satisfies;
    try {
        satisfies = _test(inputEvent);
    } catch (Unknown e) {
        _addErrorWithReplacement(sink, e, s);
        sink->_close();
        return;
    };
    if (satisfies) {
        sink->_add(inputEvent);
    } else {
        sink->_close();
    }
}

template<typename T>
_SkipStreamCls<T>::_SkipStreamCls(int count, Stream<T> source) : _ForwardingStream<T, T>(source) {
    {
        this->_count = count;
    }
    {
        RangeErrorCls->checkNotNegative(count, __s("count"));
    }
}

template<typename T>
StreamSubscription<T> _SkipStreamCls<T>::_createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return <int, T>make<_StateStreamSubscriptionCls>(this, onData, onError, onDone, cancelOnError, _count);
}

template<typename T>
void _SkipStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = as<_StateStreamSubscription<int, T>>(sink);
    int count = subscription->_subState;
    if (count > 0) {
        subscription->_subState = count - 1;
        return;
    }
    sink->_add(inputEvent);
}

template<typename T>
_SkipWhileStreamCls<T>::_SkipWhileStreamCls(Stream<T> source, std::function<bool(T value)> test) : _ForwardingStream<T, T>(source) {
    {
        this->_test = test;
    }
}

template<typename T>
StreamSubscription<T> _SkipWhileStreamCls<T>::_createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return <bool, T>make<_StateStreamSubscriptionCls>(this, onData, onError, onDone, cancelOnError, false);
}

template<typename T>
void _SkipWhileStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = as<_StateStreamSubscription<bool, T>>(sink);
    bool hasFailed = subscription->_subState;
    if (hasFailed) {
        sink->_add(inputEvent);
        return;
    }
    bool satisfies;
    try {
        satisfies = _test(inputEvent);
    } catch (Unknown e) {
        _addErrorWithReplacement(sink, e, s);
        subscription->_subState = true;
        return;
    };
    if (!satisfies) {
        subscription->_subState = true;
        sink->_add(inputEvent);
    }
}

template<typename T>
_DistinctStreamCls<T>::_DistinctStreamCls(std::function<bool(T a, T b)> equals, Stream<T> source) : _ForwardingStream<T, T>(source) {
    {
        _equals = equals;
    }
}

template<typename T>
StreamSubscription<T> _DistinctStreamCls<T>::_createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError) {
    return <Object, T>make<_StateStreamSubscriptionCls>(this, onData, onError, onDone, cancelOnError, _SENTINEL);
}

template<typename T>
void _DistinctStreamCls<T>::_handleData(T inputEvent, _EventSink<T> sink) {
    auto subscription = as<_StateStreamSubscription<Object, T>>(sink);
    auto previous = subscription->_subState;
    if (identical(previous, _SENTINEL)) {
        subscription->_subState = inputEvent;
        sink->_add(inputEvent);
    } else {
        T previousEvent = as<T>(previous);
        auto equals = _equals;
        bool isEqual;
        try {
            if (equals == nullptr) {
                isEqual = (previousEvent == inputEvent);
            } else {
                isEqual = equals(previousEvent, inputEvent);
            }
        } catch (Unknown e) {
            _addErrorWithReplacement(sink, e, s);
            return;
        };
        if (!isEqual) {
            sink->_add(inputEvent);
            subscription->_subState = inputEvent;
        }
    }
}
