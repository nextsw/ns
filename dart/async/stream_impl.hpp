#ifndef STREAM_IMPL_H
#define STREAM_IMPL_H
#include <memory>




class _EventSink<T> {
public:

private:

    void _add(T data);

    void _addError(Object error, StackTrace stackTrace);

    void _close();

};

class _EventDispatch<T> {
public:

private:

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

};

class _BufferingStreamSubscription<T> {
public:

    void  zoned(Zone _zone, bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void onData(FunctionType handleData);

    void onError(FunctionType handleError);

    void onDone(FunctionType handleDone);

    void pause(Future<void> resumeSignal);

    void resume();

    Future cancel();

    Future<E> asFuture<E>(E futureValue);

    bool isPaused();

private:
    static const int _STATE_CANCEL_ON_ERROR;

    static const int _STATE_CLOSED;

    static const int _STATE_INPUT_PAUSED;

    static const int _STATE_CANCELED;

    static const int _STATE_WAIT_FOR_CANCEL;

    static const int _STATE_IN_CALLBACK;

    static const int _STATE_HAS_PENDING;

    static const int _STATE_PAUSE_COUNT;

    FunctionType _onData;

    FunctionType _onError;

    FunctionType _onDone;

    Zone _zone;

    int _state;

    Future _cancelFuture;

    _PendingEvents<T> _pending;


     _BufferingStreamSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _setPendingEvents(_PendingEvents<T> pendingEvents);

    static FunctionType _registerDataHandler<T>(FunctionType handleData, Zone zone);

    static FunctionType _registerErrorHandler(FunctionType handleError, Zone zone);

    static FunctionType _registerDoneHandler(FunctionType handleDone, Zone zone);

    bool _isInputPaused();

    bool _isClosed();

    bool _isCanceled();

    bool _waitsForCancel();

    bool _inCallback();

    bool _hasPending();

    bool _isPaused();

    bool _canFire();

    bool _mayResumeInput();

    bool _cancelOnError();

    void _cancel();

    void _decrementPauseCount();

    void _add(T data);

    void _addError(Object error, StackTrace stackTrace);

    void _close();

    void _onPause();

    void _onResume();

    Future<void> _onCancel();

    void _addPending(_DelayedEvent event);

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

    void _guardCallback(FunctionType callback);

    void _checkState(bool wasInputPaused);

};

class _StreamImpl<T> : Stream<T> {
public:

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:

    StreamSubscription<T> _createSubscription(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void _onListen(StreamSubscription subscription);

};
void _nullDataHandler(dynamic value);

void _nullErrorHandler(Object error, StackTrace stackTrace);

void _nullDoneHandler();


class _DelayedEvent<T> {
public:
    _DelayedEvent next;


    void perform(_EventDispatch<T> dispatch);

private:

};

class _DelayedData<T> : _DelayedEvent<T> {
public:
    T value;


    void perform(_EventDispatch<T> dispatch);

private:

     _DelayedData(T value);

};

class _DelayedError : _DelayedEvent {
public:
    Object error;

    StackTrace stackTrace;


    void perform(_EventDispatch dispatch);

private:

     _DelayedError(Object error, StackTrace stackTrace);

};

class _DelayedDone {
public:

    void perform(_EventDispatch dispatch);

    _DelayedEvent next();

    void next(_DelayedEvent _);

private:

     _DelayedDone();

};

class _PendingEvents<T> {
public:
    static const int stateUnscheduled;

    static const int stateScheduled;

    static const int stateCanceled;

    _DelayedEvent firstPendingEvent;

    _DelayedEvent lastPendingEvent;


    bool isScheduled();

    void schedule(_EventDispatch<T> dispatch);

    void cancelSchedule();

    bool isEmpty();

    void add(_DelayedEvent event);

    void handleNext(_EventDispatch<T> dispatch);

    void clear();

private:
    int _state;


    bool _eventScheduled();

};

class _DoneStreamSubscription<T> {
public:

    bool isPaused();

    void onData(FunctionType handleData);

    void onError(FunctionType handleError);

    void onDone(FunctionType handleDone);

    void pause(Future<void> resumeSignal);

    void resume();

    Future cancel();

    Future<E> asFuture<E>(E futureValue);

private:
    static const int _DONE_SENT;

    static const int _SCHEDULED;

    static const int _PAUSED;

    Zone _zone;

    int _state;

    FunctionType _onDone;


     _DoneStreamSubscription(FunctionType _onDone);

    bool _isSent();

    bool _isScheduled();

    void _schedule();

    void _sendDone();

};

class _AsBroadcastStream<T> : Stream<T> {
public:

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    Stream<T> _source;

    _BroadcastCallback<T> _onListenHandler;

    _BroadcastCallback<T> _onCancelHandler;

    Zone _zone;

    _AsBroadcastStreamController<T> _controller;

    StreamSubscription<T> _subscription;


     _AsBroadcastStream(Stream<T> _source, FunctionType onCancelHandler, FunctionType onListenHandler);

    void _onCancel();

    void _onListen();

    void _cancelSubscription();

    void _pauseSubscription(Future<void> resumeSignal);

    void _resumeSubscription();

    bool _isSubscriptionPaused();

};

class _BroadcastSubscriptionWrapper<T> {
public:

    void onData(FunctionType handleData);

    void onError(FunctionType handleError);

    void onDone(FunctionType handleDone);

    void pause(Future<void> resumeSignal);

    void resume();

    Future cancel();

    bool isPaused();

    Future<E> asFuture<E>(E futureValue);

private:
    _AsBroadcastStream _stream;


     _BroadcastSubscriptionWrapper(_AsBroadcastStream _stream);

};

class _StreamIterator<T> {
public:

    T current();

    Future<bool> moveNext();

    Future cancel();

private:
    StreamSubscription<T> _subscription;

    Object _stateData;

    bool _hasValue;


     _StreamIterator(Stream<T> stream);

    Future<bool> _initializeOrDone();

    void _onData(T data);

    void _onError(Object error, StackTrace stackTrace);

    void _onDone();

};

class _EmptyStream<T> : Stream<T> {
public:

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:

     _EmptyStream();

};

class _MultiStream<T> : Stream<T> {
public:
    bool isBroadcast;


    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

private:
    FunctionType _onListen;


     _MultiStream(FunctionType _onListen, bool isBroadcast);

};

class _MultiStreamController<T> : _AsyncStreamController<T> {
public:

    void addSync(T data);

    void addErrorSync(Object error, StackTrace stackTrace);

    void closeSync();

    Stream<T> stream();

private:

     _MultiStreamController();

};

#endif