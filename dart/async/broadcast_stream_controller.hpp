#ifndef BROADCAST_STREAM_CONTROLLER_H
#define BROADCAST_STREAM_CONTROLLER_H
#include <memory>




class _BroadcastStream<T> : _ControllerStream<T> {
public:

    bool isBroadcast();

private:

     _BroadcastStream(_StreamControllerLifecycle<T> controller);

};

class _BroadcastSubscription<T> : _ControllerSubscription<T> {
public:

private:
    static const int _STATE_EVENT_ID;

    static const int _STATE_FIRING;

    static const int _STATE_REMOVE_AFTER_FIRING;

    int _eventState;

    _BroadcastSubscription<T> _next;

    _BroadcastSubscription<T> _previous;


     _BroadcastSubscription(bool cancelOnError, _StreamControllerLifecycle<T> controller, FunctionType onData, FunctionType onDone, FunctionType onError);

    bool _expectsEvent(int eventId);

    void _toggleEventId();

    bool _isFiring();

    void _setRemoveAfterFiring();

    bool _removeAfterFiring();

    void _onPause();

    void _onResume();

};

class _BroadcastStreamController<T> {
public:
    FunctionType onListen;

    FunctionType onCancel;


    FunctionType onPause();

    void onPause(FunctionType onPauseHandler);

    FunctionType onResume();

    void onResume(FunctionType onResumeHandler);

    Stream<T> stream();

    StreamSink<T> sink();

    bool isClosed();

    bool isPaused();

    bool hasListener();

    void add(T data);

    void addError(Object error, StackTrace stackTrace);

    Future close();

    Future<void> done();

    Future addStream(bool cancelOnError, Stream<T> stream);

private:
    static const int _STATE_INITIAL;

    static const int _STATE_EVENT_ID;

    static const int _STATE_FIRING;

    static const int _STATE_CLOSED;

    static const int _STATE_ADDSTREAM;

    int _state;

    _BroadcastSubscription<T> _firstSubscription;

    _BroadcastSubscription<T> _lastSubscription;

    _AddStreamState<T> _addStreamState;

    _Future<void> _doneFuture;


     _BroadcastStreamController(FunctionType onCancel, FunctionType onListen);

    bool _hasOneListener();

    bool _isFiring();

    bool _isAddingStream();

    bool _mayAddEvent();

    _Future<void> _ensureDoneFuture();

    bool _isEmpty();

    void _addListener(_BroadcastSubscription<T> subscription);

    void _removeListener(_BroadcastSubscription<T> subscription);

    StreamSubscription<T> _subscribe(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    Future<void> _recordCancel(StreamSubscription<T> sub);

    void _recordPause(StreamSubscription<T> subscription);

    void _recordResume(StreamSubscription<T> subscription);

    Error _addEventError();

    void _add(T data);

    void _addError(Object error, StackTrace stackTrace);

    void _close();

    void _forEachListener(FunctionType action);

    void _callOnCancel();

};

class _SyncBroadcastStreamController<T> : _BroadcastStreamController<T> {
public:

private:

     _SyncBroadcastStreamController(FunctionType onCancel, FunctionType onListen);

    bool _mayAddEvent();

    void  _addEventError();

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

};

class _AsyncBroadcastStreamController<T> : _BroadcastStreamController<T> {
public:

private:

     _AsyncBroadcastStreamController(FunctionType onCancel, FunctionType onListen);

    void _sendData(T data);

    void _sendError(Object error, StackTrace stackTrace);

    void _sendDone();

};

class _AsBroadcastStreamController<T> : _SyncBroadcastStreamController<T> {
public:

    void add(T data);

    void addError(Object error, StackTrace stackTrace);

    Future close();

private:
    _PendingEvents<T> _pending;


     _AsBroadcastStreamController(FunctionType onCancel, FunctionType onListen);

    bool _hasPending();

    void _addPendingEvent(_DelayedEvent event);

    void _flushPending();

    void _callOnCancel();

};

#endif