#ifndef STREAM_CONTROLLER_H
#define STREAM_CONTROLLER_H
#include <memory>




class StreamController<T> {
public:
    FunctionType onListen;

    FunctionType onPause;

    FunctionType onResume;

    FunctionType onCancel;


    Stream<T> stream();

     StreamController(FunctionType onCancel, FunctionType onListen, FunctionType onPause, FunctionType onResume, bool sync);

    void  broadcast(FunctionType onCancel, FunctionType onListen, bool sync);

    StreamSink<T> sink();

    bool isClosed();

    bool isPaused();

    bool hasListener();

    void add(T event);

    void addError(Object error, StackTrace stackTrace);

    Future close();

    Future done();

    Future addStream(bool cancelOnError, Stream<T> source);

private:

};

class SynchronousStreamController<T> {
public:

    void add(T data);

    void addError(Object error, StackTrace stackTrace);

    Future close();

private:

};

class _StreamControllerLifecycle<T> {
public:

private:

    StreamSubscription<T> _subscribe(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _recordPause(StreamSubscription<T> subscription);

    void _recordResume(StreamSubscription<T> subscription);

    Future<void> _recordCancel(StreamSubscription<T> subscription);

};

class _StreamControllerBase<T> {
public:

private:

};

class _StreamController<T> {
public:
    FunctionType onListen;

    FunctionType onPause;

    FunctionType onResume;

    FunctionType onCancel;


    Stream<T> stream();

    StreamSink<T> sink();

    bool hasListener();

    bool isClosed();

    bool isPaused();

    Future addStream(bool cancelOnError, Stream<T> source);

    Future<void> done();

    void add(T value);

    void addError(Object error, StackTrace stackTrace);

    Future close();

private:
    static const int _STATE_INITIAL;

    static const int _STATE_SUBSCRIBED;

    static const int _STATE_CANCELED;

    static const int _STATE_SUBSCRIPTION_MASK;

    static const int _STATE_CLOSED;

    static const int _STATE_ADDSTREAM;

    Object _varData;

    int _state;

    _Future<void> _doneFuture;


     _StreamController(FunctionType onCancel, FunctionType onListen, FunctionType onPause, FunctionType onResume);

    bool _isCanceled();

    bool _isInitialState();

    bool _isAddingStream();

    bool _mayAddEvent();

    _PendingEvents<T> _pendingEvents();

    _PendingEvents<T> _ensurePendingEvents();

    _ControllerSubscription<T> _subscription();

    Error _badEventState();

    Future<void> _ensureDoneFuture();

    void _closeUnchecked();

    void _add(T value);

    void _addError(Object error, StackTrace stackTrace);

    void _close();

    StreamSubscription<T> _subscribe(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    Future<void> _recordCancel(StreamSubscription<T> subscription);

    void _recordPause(StreamSubscription<T> subscription);

    void _recordResume(StreamSubscription<T> subscription);

};

class _SyncStreamControllerDispatch<T> {
public:

private:

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

};

class _AsyncStreamControllerDispatch<T> {
public:

private:

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

};

class _AsyncStreamController<T> {
public:

private:

};

class _SyncStreamController<T> {
public:

private:

};
void _runGuarded(FunctionType notificationHandler);


class _ControllerStream<T> : _StreamImpl<T> {
public:

    int hashCode();

    bool ==(Object other);

private:
    _StreamControllerLifecycle<T> _controller;


     _ControllerStream(_StreamControllerLifecycle<T> _controller);

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

};

class _ControllerSubscription<T> : _BufferingStreamSubscription<T> {
public:

private:
    _StreamControllerLifecycle<T> _controller;


     _ControllerSubscription(_StreamControllerLifecycle<T> _controller, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    Future<void> _onCancel();

    void _onPause();

    void _onResume();

};

class _StreamSinkWrapper<T> {
public:

    void add(T data);

    void addError(Object error, StackTrace stackTrace);

    Future close();

    Future addStream(Stream<T> source);

    Future done();

private:
    StreamController _target;


     _StreamSinkWrapper(StreamController _target);

};

class _AddStreamState<T> {
public:
    _Future addStreamFuture;

    StreamSubscription addSubscription;


    static void  makeErrorHandler(_EventSink controller);

    void pause();

    void resume();

    Future<void> cancel();

    void complete();

private:

     _AddStreamState(bool cancelOnError, _EventSink<T> controller, Stream<T> source);

};

class _StreamControllerAddStreamState<T> : _AddStreamState<T> {
public:
    auto varData;


private:

     _StreamControllerAddStreamState(bool cancelOnError, _StreamController<T> controller, Stream<T> source, auto varData);

};

#endif