#ifndef DART_ASYNC_STREAM_PIPE
#define DART_ASYNC_STREAM_PIPE
#include <base.hpp>

#include <dart/core/core.hpp>

template<typename T>
 void  _runUserCode(onSuccess , onError , std::function<T()> userCode);

void _cancelAndError(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription);

void _cancelAndErrorWithReplacement(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription);

std::function<void(Object error, StackTrace stackTrace)> _cancelAndErrorClosure(_Future future, StreamSubscription subscription);

void _cancelAndValue(value , _Future future, StreamSubscription subscription);


template<typename S, typename T>
class _ForwardingStreamCls : public StreamCls<T> {
public:

    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(bool cancelOnError, std::function<void(T value)> onData, std::function<void()> onDone, std::function<void ()> onError);

private:
    Stream<S> _source;


     _ForwardingStreamCls(Stream<S> _source);
    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _handleData(S data, _EventSink<T> sink);
    virtual void _handleError(Object error, _EventSink<T> sink, StackTrace stackTrace);

    virtual void _handleDone(_EventSink<T> sink);

};
template<typename S, typename T>
using _ForwardingStream = std::shared_ptr<_ForwardingStreamCls<S, T>>;

template<typename S, typename T>
class _ForwardingStreamSubscriptionCls : public _BufferingStreamSubscriptionCls<T> {
public:

private:
    _ForwardingStream<S, T> _stream;

    StreamSubscription<S> _subscription;


     _ForwardingStreamSubscriptionCls(_ForwardingStream<S, T> _stream, bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _add(T data);

    virtual void _addError(Object error, StackTrace stackTrace);

    virtual void _onPause();

    virtual void _onResume();

    virtual Future<void> _onCancel();

    virtual void _handleData(S data);

    virtual void _handleError(error , StackTrace stackTrace);

    virtual void _handleDone();

};
template<typename S, typename T>
using _ForwardingStreamSubscription = std::shared_ptr<_ForwardingStreamSubscriptionCls<S, T>>;
void _addErrorWithReplacement(Object error, _EventSink sink, StackTrace stackTrace);


template<typename T>
class _WhereStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    std::function<bool(T )> _test;


     _WhereStreamCls(Stream<T> source, std::function<bool(T value)> test);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _WhereStream = std::shared_ptr<_WhereStreamCls<T>>;

template<typename S, typename T>
class _MapStreamCls : public _ForwardingStreamCls<S, T> {
public:

private:
    _Transformation<S, T> _transform;


     _MapStreamCls(Stream<S> source, std::function<T(S event)> transform);

    virtual void _handleData(S inputEvent, _EventSink<T> sink);

};
template<typename S, typename T>
using _MapStream = std::shared_ptr<_MapStreamCls<S, T>>;

template<typename S, typename T>
class _ExpandStreamCls : public _ForwardingStreamCls<S, T> {
public:

private:
    _Transformation<S, Iterable<T>> _expand;


     _ExpandStreamCls(std::function<Iterable<T>(S event)> expand, Stream<S> source);

    virtual void _handleData(S inputEvent, _EventSink<T> sink);

};
template<typename S, typename T>
using _ExpandStream = std::shared_ptr<_ExpandStreamCls<S, T>>;

template<typename T>
class _HandleErrorStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    std::function<void(Object , StackTrace )> _onError;

    std::function<bool(Object )> _test;


     _HandleErrorStreamCls(std::function<void(Object , StackTrace )> _onError, std::function<bool(Object )> _test, Stream<T> source);

    virtual void _handleData(T data, _EventSink<T> sink);

    virtual void _handleError(Object error, _EventSink<T> sink, StackTrace stackTrace);

};
template<typename T>
using _HandleErrorStream = std::shared_ptr<_HandleErrorStreamCls<T>>;

template<typename T>
class _TakeStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    int _count;


     _TakeStreamCls(int count, Stream<T> source);

    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _TakeStream = std::shared_ptr<_TakeStreamCls<T>>;

template<typename S, typename T>
class _StateStreamSubscriptionCls : public _ForwardingStreamSubscriptionCls<T, T> {
public:

private:
    S _subState;


     _StateStreamSubscriptionCls(S _subState, bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError, _ForwardingStream<T, T> stream);

};
template<typename S, typename T>
using _StateStreamSubscription = std::shared_ptr<_StateStreamSubscriptionCls<S, T>>;

template<typename T>
class _TakeWhileStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    std::function<bool(T )> _test;


     _TakeWhileStreamCls(Stream<T> source, std::function<bool(T value)> test);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _TakeWhileStream = std::shared_ptr<_TakeWhileStreamCls<T>>;

template<typename T>
class _SkipStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    int _count;


     _SkipStreamCls(int count, Stream<T> source);

    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _SkipStream = std::shared_ptr<_SkipStreamCls<T>>;

template<typename T>
class _SkipWhileStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    std::function<bool(T )> _test;


     _SkipWhileStreamCls(Stream<T> source, std::function<bool(T value)> test);

    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _SkipWhileStream = std::shared_ptr<_SkipWhileStreamCls<T>>;

template<typename T>
class _DistinctStreamCls : public _ForwardingStreamCls<T, T> {
public:

private:
    static auto  _SENTINEL;

    std::function<bool(T , T )> _equals;


     _DistinctStreamCls(std::function<bool(T a, T b)> equals, Stream<T> source);

    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual void _handleData(T inputEvent, _EventSink<T> sink);

};
template<typename T>
using _DistinctStream = std::shared_ptr<_DistinctStreamCls<T>>;


#endif