#ifndef DART_ASYNC_BROADCAST_STREAM_CONTROLLER
#define DART_ASYNC_BROADCAST_STREAM_CONTROLLER
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class _BroadcastStreamCls : public _ControllerStreamCls<T> {
public:

    virtual bool isBroadcast();

private:

     _BroadcastStreamCls(_StreamControllerLifecycle<T> controller);

};
template<typename T>
using _BroadcastStream = std::shared_ptr<_BroadcastStreamCls<T>>;

template<typename T>
class _BroadcastSubscriptionCls : public _ControllerSubscriptionCls<T> {
public:

private:
    static int _STATE_EVENT_ID;

    static int _STATE_FIRING;

    static int _STATE_REMOVE_AFTER_FIRING;

    int _eventState;

    _BroadcastSubscription<T> _next;

    _BroadcastSubscription<T> _previous;


     _BroadcastSubscriptionCls(bool cancelOnError, _StreamControllerLifecycle<T> controller, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual bool _expectsEvent(int eventId);

    virtual void _toggleEventId();

    virtual bool _isFiring();

    virtual void _setRemoveAfterFiring();

    virtual bool _removeAfterFiring();

    virtual void _onPause();

    virtual void _onResume();

};
template<typename T>
using _BroadcastSubscription = std::shared_ptr<_BroadcastSubscriptionCls<T>>;

template<typename T>
class _BroadcastStreamControllerCls : public ObjectCls {
public:
    std::function<void()> onListen;

    std::function<FutureOr<void>()> onCancel;


    virtual std::function<void()> onPause();

    virtual void onPause(std::function<void()> onPauseHandler);

    virtual std::function<void()> onResume();

    virtual void onResume(std::function<void()> onResumeHandler);

    virtual Stream<T> stream();

    virtual StreamSink<T> sink();

    virtual bool isClosed();

    virtual bool isPaused();

    virtual bool hasListener();

    virtual void add(T data);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual Future close();

    virtual Future<void> done();

    virtual Future addStream(bool cancelOnError, Stream<T> stream);

private:
    static int _STATE_INITIAL;

    static int _STATE_EVENT_ID;

    static int _STATE_FIRING;

    static int _STATE_CLOSED;

    static int _STATE_ADDSTREAM;

    int _state;

    _BroadcastSubscription<T> _firstSubscription;

    _BroadcastSubscription<T> _lastSubscription;

    _AddStreamState<T> _addStreamState;

    _Future<void> _doneFuture;


     _BroadcastStreamControllerCls(std::function<FutureOr<void>()> onCancel, std::function<void()> onListen);

    virtual bool _hasOneListener();

    virtual bool _isFiring();

    virtual bool _isAddingStream();

    virtual bool _mayAddEvent();

    virtual _Future<void> _ensureDoneFuture();

    virtual bool _isEmpty();

    virtual void _addListener(_BroadcastSubscription<T> subscription);

    virtual void _removeListener(_BroadcastSubscription<T> subscription);

    virtual StreamSubscription<T> _subscribe(bool cancelOnError, std::function<void(T data)> onData, std::function<void()> onDone, std::function<void ()> onError);

    virtual Future<void> _recordCancel(StreamSubscription<T> sub);

    virtual void _recordPause(StreamSubscription<T> subscription);

    virtual void _recordResume(StreamSubscription<T> subscription);

    virtual Error _addEventError();

    virtual void _add(T data);

    virtual void _addError(Object error, StackTrace stackTrace);

    virtual void _close();

    virtual void _forEachListener(std::function<void(_BufferingStreamSubscription<T> subscription)> action);

    virtual void _callOnCancel();

};
template<typename T>
using _BroadcastStreamController = std::shared_ptr<_BroadcastStreamControllerCls<T>>;

template<typename T>
class _SyncBroadcastStreamControllerCls : public _BroadcastStreamControllerCls<T> {
public:

private:

     _SyncBroadcastStreamControllerCls(std::function<void()> onCancel, std::function<void()> onListen);

    virtual bool _mayAddEvent();

    virtual void  _addEventError();

    virtual void _sendData(T data);

    virtual void _sendError(Object error, StackTrace stackTrace);

    virtual void _sendDone();

};
template<typename T>
using _SyncBroadcastStreamController = std::shared_ptr<_SyncBroadcastStreamControllerCls<T>>;

template<typename T>
class _AsyncBroadcastStreamControllerCls : public _BroadcastStreamControllerCls<T> {
public:

private:

     _AsyncBroadcastStreamControllerCls(std::function<void()> onCancel, std::function<void()> onListen);

    virtual void _sendData(T data);

    virtual void _sendError(Object error, StackTrace stackTrace);

    virtual void _sendDone();

};
template<typename T>
using _AsyncBroadcastStreamController = std::shared_ptr<_AsyncBroadcastStreamControllerCls<T>>;

template<typename T>
class _AsBroadcastStreamControllerCls : public _SyncBroadcastStreamControllerCls<T> {
public:

    virtual void add(T data);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual Future close();

private:
    _PendingEvents<T> _pending;


     _AsBroadcastStreamControllerCls(std::function<void()> onCancel, std::function<void()> onListen);

    virtual bool _hasPending();

    virtual void _addPendingEvent(_DelayedEvent event);

    virtual void _flushPending();

    virtual void _callOnCancel();

};
template<typename T>
using _AsBroadcastStreamController = std::shared_ptr<_AsBroadcastStreamControllerCls<T>>;


#endif