#ifndef STREAM_TRANSFORMERS_H
#define STREAM_TRANSFORMERS_H
#include <memory>




class _EventSinkWrapper<T> {
public:

    void add(T data);

    void addError(Object error, StackTrace stackTrace);

    void close();

private:
    _EventSink<T> _sink;


     _EventSinkWrapper(_EventSink<T> _sink);

};

class _SinkTransformerStreamSubscription<S, T> : _BufferingStreamSubscription<T> {
public:

private:
    EventSink<S> _transformerSink;

    StreamSubscription<S> _subscription;


     _SinkTransformerStreamSubscription(bool cancelOnError, _SinkMapper<S, T> mapper, FunctionType onData, FunctionType onDone, FunctionType onError, Stream<S> source);

    void _add(T data);

    void _addError(Object error, StackTrace stackTrace);

    void _close();

    void _onPause();

    void _onResume();

    Future<void> _onCancel();

    void _handleData(S data);

    void _handleError(Object error, StackTrace stackTrace);

    void _handleDone();

};

class _StreamSinkTransformer<S, T> : StreamTransformerBase<S, T> {
public:

    Stream<T> bind(Stream<S> stream);

private:
    _SinkMapper<S, T> _sinkMapper;


     _StreamSinkTransformer(_SinkMapper<S, T> _sinkMapper);

};

class _BoundSinkStream<S, T> : Stream<T> {
public:

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    _SinkMapper<S, T> _sinkMapper;

    Stream<S> _stream;


     _BoundSinkStream(_SinkMapper<S, T> _sinkMapper, Stream<S> _stream);

};

class _HandlerEventSink<S, T> {
public:

    void add(S data);

    void addError(Object error, StackTrace stackTrace);

    void close();

private:
    _TransformDataHandler<S, T> _handleData;

    _TransformErrorHandler<T> _handleError;

    _TransformDoneHandler<T> _handleDone;

    EventSink<T> _sink;


     _HandlerEventSink(_TransformDataHandler<S, T> _handleData, _TransformDoneHandler<T> _handleDone, _TransformErrorHandler<T> _handleError, EventSink<T> _sink);

};

class _StreamHandlerTransformer<S, T> : _StreamSinkTransformer<S, T> {
public:

    Stream<T> bind(Stream<S> stream);

private:

     _StreamHandlerTransformer(FunctionType handleData, FunctionType handleDone, FunctionType handleError);

};

class _StreamBindTransformer<S, T> : StreamTransformerBase<S, T> {
public:

    Stream<T> bind(Stream<S> stream);

private:
    FunctionType _bind;


     _StreamBindTransformer(FunctionType _bind);

};

class _StreamSubscriptionTransformer<S, T> : StreamTransformerBase<S, T> {
public:

    Stream<T> bind(Stream<S> stream);

private:
    _SubscriptionTransformer<S, T> _onListen;


     _StreamSubscriptionTransformer(_SubscriptionTransformer<S, T> _onListen);

};

class _BoundSubscriptionStream<S, T> : Stream<T> {
public:

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    _SubscriptionTransformer<S, T> _onListen;

    Stream<S> _stream;


     _BoundSubscriptionStream(_SubscriptionTransformer<S, T> _onListen, Stream<S> _stream);

};

#endif