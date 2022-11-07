#ifndef STREAM_PIPE_H
#define STREAM_PIPE_H
#include <memory>



void  _runUserCode<T>(onSuccess , onError , FunctionType userCode);

void _cancelAndError(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription);

void _cancelAndErrorWithReplacement(Object error, _Future future, StackTrace stackTrace, StreamSubscription subscription);

FunctionType _cancelAndErrorClosure(_Future future, StreamSubscription subscription);

void _cancelAndValue(value , _Future future, StreamSubscription subscription);


class _ForwardingStream<S, T> : Stream<T> {
public:

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    Stream<S> _source;


     _ForwardingStream(Stream<S> _source);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _handleData(S data, _EventSink<T> sink);

    void _handleError(Object error, _EventSink<T> sink, StackTrace stackTrace);

    void _handleDone(_EventSink<T> sink);

};

class _ForwardingStreamSubscription<S, T> : _BufferingStreamSubscription<T> {
public:

private:
    _ForwardingStream<S, T> _stream;

    StreamSubscription<S> _subscription;


     _ForwardingStreamSubscription(_ForwardingStream<S, T> _stream, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _add(T data);

    void _addError(Object error, StackTrace stackTrace);

    void _onPause();

    void _onResume();

    Future<void> _onCancel();

    void _handleData(S data);

    void _handleError(error , StackTrace stackTrace);

    void _handleDone();

};
void _addErrorWithReplacement(Object error, _EventSink sink, StackTrace stackTrace);


class _WhereStream<T> : _ForwardingStream<T, T> {
public:

private:
    FunctionType _test;


     _WhereStream(Stream<T> source, FunctionType test);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

class _MapStream<S, T> : _ForwardingStream<S, T> {
public:

private:
    _Transformation<S, T> _transform;


     _MapStream(Stream<S> source, FunctionType transform);

    void _handleData(S inputEvent, _EventSink<T> sink);

};

class _ExpandStream<S, T> : _ForwardingStream<S, T> {
public:

private:
    _Transformation<S, Iterable<T>> _expand;


     _ExpandStream(FunctionType expand, Stream<S> source);

    void _handleData(S inputEvent, _EventSink<T> sink);

};

class _HandleErrorStream<T> : _ForwardingStream<T, T> {
public:

private:
    FunctionType _onError;

    FunctionType _test;


     _HandleErrorStream(FunctionType _onError, FunctionType _test, Stream<T> source);

    void _handleData(T data, _EventSink<T> sink);

    void _handleError(Object error, _EventSink<T> sink, StackTrace stackTrace);

};

class _TakeStream<T> : _ForwardingStream<T, T> {
public:

private:
    int _count;


     _TakeStream(int count, Stream<T> source);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

class _StateStreamSubscription<S, T> : _ForwardingStreamSubscription<T, T> {
public:

private:
    S _subState;


     _StateStreamSubscription(S _subState, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError, _ForwardingStream<T, T> stream);

};

class _TakeWhileStream<T> : _ForwardingStream<T, T> {
public:

private:
    FunctionType _test;


     _TakeWhileStream(Stream<T> source, FunctionType test);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

class _SkipStream<T> : _ForwardingStream<T, T> {
public:

private:
    int _count;


     _SkipStream(int count, Stream<T> source);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

class _SkipWhileStream<T> : _ForwardingStream<T, T> {
public:

private:
    FunctionType _test;


     _SkipWhileStream(Stream<T> source, FunctionType test);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

class _DistinctStream<T> : _ForwardingStream<T, T> {
public:

private:
    static auto  _SENTINEL;

    FunctionType _equals;


     _DistinctStream(FunctionType equals, Stream<T> source);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _handleData(T inputEvent, _EventSink<T> sink);

};

#endif