#ifndef DART_ASYNC_STREAM_TRANSFORMERS
#define DART_ASYNC_STREAM_TRANSFORMERS
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class _EventSinkWrapperCls : public ObjectCls {
public:

    virtual void add(T data);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual void close();

private:
    _EventSink<T> _sink;


     _EventSinkWrapperCls(_EventSink<T> _sink);
};
template<typename T>
using _EventSinkWrapper = std::shared_ptr<_EventSinkWrapperCls<T>>;

template<typename S, typename T>
class _SinkTransformerStreamSubscriptionCls : public _BufferingStreamSubscriptionCls<T> {
public:

private:
    EventSink<S> _transformerSink;

    StreamSubscription<S> _subscription;


     _SinkTransformerStreamSubscriptionCls(bool cancelOnError, _SinkMapper<S, T> mapper, void onData(T data) , void onDone() , void  onError() , Stream<S> source);

    virtual void _add(T data);

    virtual void _addError(Object error, StackTrace stackTrace);

    virtual void _close();

    virtual void _onPause();

    virtual void _onResume();

    virtual Future<void> _onCancel();

    virtual void _handleData(S data);

    virtual void _handleError(Object error, StackTrace stackTrace);

    virtual void _handleDone();

};
template<typename S, typename T>
using _SinkTransformerStreamSubscription = std::shared_ptr<_SinkTransformerStreamSubscriptionCls<S, T>>;

template<typename S, typename T>
class _StreamSinkTransformerCls : public StreamTransformerBaseCls<S, T> {
public:

    virtual Stream<T> bind(Stream<S> stream);

private:
    _SinkMapper<S, T> _sinkMapper;


     _StreamSinkTransformerCls(_SinkMapper<S, T> _sinkMapper);
};
template<typename S, typename T>
using _StreamSinkTransformer = std::shared_ptr<_StreamSinkTransformerCls<S, T>>;

template<typename S, typename T>
class _BoundSinkStreamCls : public StreamCls<T> {
public:

    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(bool cancelOnError, void onData(T event) , void onDone() , void  onError() );

private:
    _SinkMapper<S, T> _sinkMapper;

    Stream<S> _stream;


     _BoundSinkStreamCls(_SinkMapper<S, T> _sinkMapper, Stream<S> _stream);
};
template<typename S, typename T>
using _BoundSinkStream = std::shared_ptr<_BoundSinkStreamCls<S, T>>;

template<typename S, typename T>
class _HandlerEventSinkCls : public ObjectCls {
public:

    virtual void add(S data);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual void close();

private:
    _TransformDataHandler<S, T> _handleData;

    _TransformErrorHandler<T> _handleError;

    _TransformDoneHandler<T> _handleDone;

    EventSink<T> _sink;


     _HandlerEventSinkCls(_TransformDataHandler<S, T> _handleData, _TransformDoneHandler<T> _handleDone, _TransformErrorHandler<T> _handleError, EventSink<T> _sink);
};
template<typename S, typename T>
using _HandlerEventSink = std::shared_ptr<_HandlerEventSinkCls<S, T>>;

template<typename S, typename T>
class _StreamHandlerTransformerCls : public _StreamSinkTransformerCls<S, T> {
public:

    virtual Stream<T> bind(Stream<S> stream);

private:

     _StreamHandlerTransformerCls(void handleData(S data, EventSink<T> sink) , void handleDone(EventSink<T> sink) , void handleError(Object error, EventSink<T> sink, StackTrace stackTrace) );

};
template<typename S, typename T>
using _StreamHandlerTransformer = std::shared_ptr<_StreamHandlerTransformerCls<S, T>>;

template<typename S, typename T>
class _StreamBindTransformerCls : public StreamTransformerBaseCls<S, T> {
public:

    virtual Stream<T> bind(Stream<S> stream);

private:
    Stream<T> Function(Stream<S> ) _bind;


     _StreamBindTransformerCls(Stream<T> Function(Stream<S> ) _bind);
};
template<typename S, typename T>
using _StreamBindTransformer = std::shared_ptr<_StreamBindTransformerCls<S, T>>;

template<typename S, typename T>
class _StreamSubscriptionTransformerCls : public StreamTransformerBaseCls<S, T> {
public:

    virtual Stream<T> bind(Stream<S> stream);

private:
    _SubscriptionTransformer<S, T> _onListen;


     _StreamSubscriptionTransformerCls(_SubscriptionTransformer<S, T> _onListen);
};
template<typename S, typename T>
using _StreamSubscriptionTransformer = std::shared_ptr<_StreamSubscriptionTransformerCls<S, T>>;

template<typename S, typename T>
class _BoundSubscriptionStreamCls : public StreamCls<T> {
public:

    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(bool cancelOnError, void onData(T event) , void onDone() , void  onError() );

private:
    _SubscriptionTransformer<S, T> _onListen;

    Stream<S> _stream;


     _BoundSubscriptionStreamCls(_SubscriptionTransformer<S, T> _onListen, Stream<S> _stream);
};
template<typename S, typename T>
using _BoundSubscriptionStream = std::shared_ptr<_BoundSubscriptionStreamCls<S, T>>;


#endif