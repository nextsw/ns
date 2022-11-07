#include "stream_transformers.hpp"
void _EventSinkWrapper::add(T data) {
    _sink._add(data);
}

void _EventSinkWrapper::addError(Object error, StackTrace stackTrace) {
    _sink._addError(error, stackTrace ?? AsyncError.defaultStackTrace(error));
}

void _EventSinkWrapper::close() {
    _sink._close();
}

_SinkTransformerStreamSubscription::_SinkTransformerStreamSubscription(bool cancelOnError, _SinkMapper<S, T> mapper, FunctionType onData, FunctionType onDone, FunctionType onError, Stream<S> source) {
    {
        super(onData, onError, onDone, cancelOnError);
    }
    {
        _transformerSink = mapper(<T>_EventSinkWrapper(this));
        _subscription = source.listen(_handleData_handleError, _handleDone);
    }
}

void _SinkTransformerStreamSubscription::_add(T data) {
    if (_isClosed) {
        ;
    }
    super._add(data);
}

void _SinkTransformerStreamSubscription::_addError(Object error, StackTrace stackTrace) {
    if (_isClosed) {
        ;
    }
    super._addError(error, stackTrace);
}

void _SinkTransformerStreamSubscription::_close() {
    if (_isClosed) {
        ;
    }
    super._close();
}

void _SinkTransformerStreamSubscription::_onPause() {
    _subscription?.pause();
}

void _SinkTransformerStreamSubscription::_onResume() {
    _subscription?.resume();
}

Future<void> _SinkTransformerStreamSubscription::_onCancel() {
    auto subscription = _subscription;
    if (subscription != nullptr) {
        _subscription = nullptr;
        return subscription.cancel();
    }
    return nullptr;
}

void _SinkTransformerStreamSubscription::_handleData(S data) {
    ;
}

void _SinkTransformerStreamSubscription::_handleError(Object error, StackTrace stackTrace) {
    ;
}

void _SinkTransformerStreamSubscription::_handleDone() {
    ;
}

Stream<T> _StreamSinkTransformer::bind(Stream<S> stream) {
    return <S, T>_BoundSinkStream(stream, _sinkMapper);
}

bool _BoundSinkStream::isBroadcast() {
    return _stream.isBroadcast;
}

StreamSubscription<T> _BoundSinkStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    StreamSubscription<T> subscription = <S, T>_SinkTransformerStreamSubscription(_stream, _sinkMapper, onData, onError, onDone, cancelOnError ?? false);
    return subscription;
}

void _HandlerEventSink::add(S data) {
    auto sink = _sink;
    if (sink == nullptr) {
        ;
    }
    auto handleData = _handleData;
    if (handleData != nullptr) {
        handleData(data, sink);
    } else {
        sink.add(();
    }
}

void _HandlerEventSink::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    auto sink = _sink;
    if (sink == nullptr) {
        ;
    }
    auto handleError = _handleError;
    stackTrace = AsyncError.defaultStackTrace(error);
    if (handleError != nullptr) {
        handleError(error, stackTrace, sink);
    } else {
        sink.addError(error, stackTrace);
    }
}

void _HandlerEventSink::close() {
    auto sink = _sink;
    if (sink == nullptr)     {
        return;
    }
    _sink = nullptr;
    auto handleDone = _handleDone;
    if (handleDone != nullptr) {
        handleDone(sink);
    } else {
        sink.close();
    }
}

Stream<T> _StreamHandlerTransformer::bind(Stream<S> stream) {
    return super.bind(stream);
}

_StreamHandlerTransformer::_StreamHandlerTransformer(FunctionType handleData, FunctionType handleDone, FunctionType handleError) {
    {
        super();
    }
}

Stream<T> _StreamBindTransformer::bind(Stream<S> stream) {
    return _bind(stream);
}

Stream<T> _StreamSubscriptionTransformer::bind(Stream<S> stream) {
    return <S, T>_BoundSubscriptionStream(stream, _onListen);
}

bool _BoundSubscriptionStream::isBroadcast() {
    return _stream.isBroadcast;
}

StreamSubscription<T> _BoundSubscriptionStream::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    StreamSubscription<T> result = _onListen(_stream, cancelOnError ?? false);
    result.onData(onData);
    result.onError(onError);
    result.onDone(onDone);
    return result;
}
