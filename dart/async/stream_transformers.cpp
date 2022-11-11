#include "stream_transformers.hpp"
template<typename T>
void _EventSinkWrapperCls<T>::add(T data) {
    _sink->_add(data);
}

template<typename T>
void _EventSinkWrapperCls<T>::addError(Object error, StackTrace stackTrace) {
    _sink->_addError(error, stackTrace | AsyncErrorCls->defaultStackTrace(error));
}

template<typename T>
void _EventSinkWrapperCls<T>::close() {
    _sink->_close();
}

template<typename S, typename T>
_SinkTransformerStreamSubscriptionCls<S, T>::_SinkTransformerStreamSubscriptionCls(Stream<S> source, _SinkMapper<S, T> mapper, std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError) : _BufferingStreamSubscription<T>(onData, onError, onDone, cancelOnError) {
    {
        _transformerSink = mapper(<T>make<_EventSinkWrapperCls>(this));
        _subscription = source->listen(_handleData_handleError, _handleDone);
    }
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_add(T data) {
    if (_isClosed) {
        throw make<StateErrorCls>(__s("Stream is already closed"));
    }
    super->_add(data);
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_addError(Object error, StackTrace stackTrace) {
    if (_isClosed) {
        throw make<StateErrorCls>(__s("Stream is already closed"));
    }
    super->_addError(error, stackTrace);
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_close() {
    if (_isClosed) {
        throw make<StateErrorCls>(__s("Stream is already closed"));
    }
    super->_close();
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_onPause() {
    _subscription?->pause();
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_onResume() {
    _subscription?->resume();
}

template<typename S, typename T>
Future<void> _SinkTransformerStreamSubscriptionCls<S, T>::_onCancel() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        return subscription->cancel();
    }
    return nullptr;
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_handleData(S data) {
    try {
        _transformerSink->add(data);
    } catch (Unknown e) {
        _addError(e, s);
    };
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_handleError(Object error, StackTrace stackTrace) {
    try {
        _transformerSink->addError(error, stackTrace);
    } catch (Unknown e) {
        if (identical(e, error)) {
            _addError(error, stackTrace);
        } else {
            _addError(e, s);
        }
    };
}

template<typename S, typename T>
void _SinkTransformerStreamSubscriptionCls<S, T>::_handleDone() {
    try {
        _subscription = nullptr;
        _transformerSink->close();
    } catch (Unknown e) {
        _addError(e, s);
    };
}

template<typename S, typename T>
Stream<T> _StreamSinkTransformerCls<S, T>::bind(Stream<S> stream) {
    return <S, T>make<_BoundSinkStreamCls>(stream, _sinkMapper);
}

template<typename S, typename T>
bool _BoundSinkStreamCls<S, T>::isBroadcast() {
    return _stream->isBroadcast();
}

template<typename S, typename T>
StreamSubscription<T> _BoundSinkStreamCls<S, T>::listen(std::function<void(T event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    StreamSubscription<T> subscription = <S, T>make<_SinkTransformerStreamSubscriptionCls>(_stream, _sinkMapper, onData, onError, onDone, cancelOnError | false);
    return subscription;
}

template<typename S, typename T>
void _HandlerEventSinkCls<S, T>::add(S data) {
    auto sink = _sink;
    if (sink == nullptr) {
        throw make<StateErrorCls>(__s("Sink is closed"));
    }
    auto handleData = _handleData;
    if (handleData != nullptr) {
        handleData(data, sink);
    } else {
        sink->add(as<T>(data));
    }
}

template<typename S, typename T>
void _HandlerEventSinkCls<S, T>::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, __s("error"));
    auto sink = _sink;
    if (sink == nullptr) {
        throw make<StateErrorCls>(__s("Sink is closed"));
    }
    auto handleError = _handleError;
    stackTrace |= AsyncErrorCls->defaultStackTrace(error);
    if (handleError != nullptr) {
        handleError(error, stackTrace, sink);
    } else {
        sink->addError(error, stackTrace);
    }
}

template<typename S, typename T>
void _HandlerEventSinkCls<S, T>::close() {
    auto sink = _sink;
    if (sink == nullptr)     {
        return;
    }
    _sink = nullptr;
    auto handleDone = _handleDone;
    if (handleDone != nullptr) {
        handleDone(sink);
    } else {
        sink->close();
    }
}

template<typename S, typename T>
Stream<T> _StreamHandlerTransformerCls<S, T>::bind(Stream<S> stream) {
    return super->bind(stream);
}

template<typename S, typename T>
_StreamHandlerTransformerCls<S, T>::_StreamHandlerTransformerCls(std::function<void(S data, EventSink<T> sink)> handleData, std::function<void(EventSink<T> sink)> handleDone, std::function<void(Object error, StackTrace stackTrace, EventSink<T> sink)> handleError) : _StreamSinkTransformer<S, T>([=] (EventSink<T> outputSink) {
    return <S, T>make<_HandlerEventSinkCls>(handleData, handleError, handleDone, outputSink);
}) {
}

template<typename S, typename T>
Stream<T> _StreamBindTransformerCls<S, T>::bind(Stream<S> stream) {
    return _bind(stream);
}

template<typename S, typename T>
Stream<T> _StreamSubscriptionTransformerCls<S, T>::bind(Stream<S> stream) {
    return <S, T>make<_BoundSubscriptionStreamCls>(stream, _onListen);
}

template<typename S, typename T>
bool _BoundSubscriptionStreamCls<S, T>::isBroadcast() {
    return _stream->isBroadcast();
}

template<typename S, typename T>
StreamSubscription<T> _BoundSubscriptionStreamCls<S, T>::listen(std::function<void(T event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError) {
    StreamSubscription<T> result = _onListen(_stream, cancelOnError | false);
    result->onData(onData);
    result->onError(onError);
    result->onDone(onDone);
    return result;
}
