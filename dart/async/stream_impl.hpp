#ifndef DART_ASYNC_STREAM_IMPL
#define DART_ASYNC_STREAM_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class _EventSinkCls : public ObjectCls {
public:

private:

    virtual void _add(T data);
    virtual void _addError(Object error, StackTrace stackTrace);
    virtual void _close();
};
template<typename T>
using _EventSink = std::shared_ptr<_EventSinkCls<T>>;

template<typename T>
class _EventDispatchCls : public ObjectCls {
public:

private:

    virtual void _sendData(T data);
    virtual void _sendError(Object error, StackTrace stackTrace);
    virtual void _sendDone();
};
template<typename T>
using _EventDispatch = std::shared_ptr<_EventDispatchCls<T>>;

template<typename T>
class _BufferingStreamSubscriptionCls : public ObjectCls {
public:

    virtual void  zoned(Zone _zone, std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError);

    virtual void onData(std::function<void(T event)> handleData);

    virtual void onError(std::function<void ()> handleError);

    virtual void onDone(std::function<void()> handleDone);

    virtual void pause(Future<void> resumeSignal);

    virtual void resume();

    virtual Future cancel();

    template<typename E>
 virtual Future<E> asFuture(E futureValue);

    virtual bool isPaused();

private:
    static int _STATE_CANCEL_ON_ERROR;

    static int _STATE_CLOSED;

    static int _STATE_INPUT_PAUSED;

    static int _STATE_CANCELED;

    static int _STATE_WAIT_FOR_CANCEL;

    static int _STATE_IN_CALLBACK;

    static int _STATE_HAS_PENDING;

    static int _STATE_PAUSE_COUNT;

    std::function<void(T )> _onData;

    std::function<void ()> _onError;

    std::function<void()> _onDone;

    Zone _zone;

    int _state;

    Future _cancelFuture;

    _PendingEvents<T> _pending;


     _BufferingStreamSubscriptionCls(std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError);

    virtual void _setPendingEvents(_PendingEvents<T> pendingEvents);

    template<typename T>
 static std::function<void(T )> _registerDataHandler(Zone zone, std::function<void(T )> handleData);

    static std::function<void ()> _registerErrorHandler(Zone zone, std::function<void ()> handleError);

    static std::function<void()> _registerDoneHandler(Zone zone, std::function<void()> handleDone);

    virtual bool _isInputPaused();

    virtual bool _isClosed();

    virtual bool _isCanceled();

    virtual bool _waitsForCancel();

    virtual bool _inCallback();

    virtual bool _hasPending();

    virtual bool _isPaused();

    virtual bool _canFire();

    virtual bool _mayResumeInput();

    virtual bool _cancelOnError();

    virtual void _cancel();

    virtual void _decrementPauseCount();

    virtual void _add(T data);

    virtual void _addError(Object error, StackTrace stackTrace);

    virtual void _close();

    virtual void _onPause();

    virtual void _onResume();

    virtual Future<void> _onCancel();

    virtual void _addPending(_DelayedEvent event);

    virtual void _sendData(T data);

    virtual void _sendError(Object error, StackTrace stackTrace);

    virtual void _sendDone();

    virtual void _guardCallback(std::function<void()> callback);

    virtual void _checkState(bool wasInputPaused);

};
template<typename T>
using _BufferingStreamSubscription = std::shared_ptr<_BufferingStreamSubscriptionCls<T>>;

template<typename T>
class _StreamImplCls : public StreamCls<T> {
public:

    virtual StreamSubscription<T> listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:

    virtual StreamSubscription<T> _createSubscription(std::function<void(T data)> onData, std::function<void ()> onError, std::function<void()> onDone, bool cancelOnError);

    virtual void _onListen(StreamSubscription subscription);

};
template<typename T>
using _StreamImpl = std::shared_ptr<_StreamImplCls<T>>;
void _nullDataHandler(dynamic value);

void _nullErrorHandler(Object error, StackTrace stackTrace);

void _nullDoneHandler();


template<typename T>
class _DelayedEventCls : public ObjectCls {
public:
    _DelayedEvent next;


    virtual void perform(_EventDispatch<T> dispatch);
private:

};
template<typename T>
using _DelayedEvent = std::shared_ptr<_DelayedEventCls<T>>;

template<typename T>
class _DelayedDataCls : public _DelayedEventCls<T> {
public:
    T value;


    virtual void perform(_EventDispatch<T> dispatch);

private:

     _DelayedDataCls(T value);
};
template<typename T>
using _DelayedData = std::shared_ptr<_DelayedDataCls<T>>;

class _DelayedErrorCls : public _DelayedEventCls {
public:
    Object error;

    StackTrace stackTrace;


    virtual void perform(_EventDispatch dispatch);

private:

     _DelayedErrorCls(Object error, StackTrace stackTrace);
};
using _DelayedError = std::shared_ptr<_DelayedErrorCls>;

class _DelayedDoneCls : public ObjectCls {
public:

    virtual void perform(_EventDispatch dispatch);

    virtual _DelayedEvent next();

    virtual void next(_DelayedEvent _);

private:

     _DelayedDoneCls();
};
using _DelayedDone = std::shared_ptr<_DelayedDoneCls>;

template<typename T>
class _PendingEventsCls : public ObjectCls {
public:
    static int stateUnscheduled;

    static int stateScheduled;

    static int stateCanceled;

    _DelayedEvent firstPendingEvent;

    _DelayedEvent lastPendingEvent;


    virtual bool isScheduled();

    virtual void schedule(_EventDispatch<T> dispatch);

    virtual void cancelSchedule();

    virtual bool isEmpty();

    virtual void add(_DelayedEvent event);

    virtual void handleNext(_EventDispatch<T> dispatch);

    virtual void clear();

private:
    int _state;


    virtual bool _eventScheduled();

};
template<typename T>
using _PendingEvents = std::shared_ptr<_PendingEventsCls<T>>;

template<typename T>
class _DoneStreamSubscriptionCls : public ObjectCls {
public:

    virtual bool isPaused();

    virtual void onData(std::function<void(T data)> handleData);

    virtual void onError(std::function<void ()> handleError);

    virtual void onDone(std::function<void()> handleDone);

    virtual void pause(Future<void> resumeSignal);

    virtual void resume();

    virtual Future cancel();

    template<typename E>
 virtual Future<E> asFuture(E futureValue);

private:
    static int _DONE_SENT;

    static int _SCHEDULED;

    static int _PAUSED;

    Zone _zone;

    int _state;

    std::function<void()> _onDone;


     _DoneStreamSubscriptionCls(std::function<void()> _onDone);

    virtual bool _isSent();

    virtual bool _isScheduled();

    virtual void _schedule();

    virtual void _sendDone();

};
template<typename T>
using _DoneStreamSubscription = std::shared_ptr<_DoneStreamSubscriptionCls<T>>;

template<typename T>
class _AsBroadcastStreamCls : public StreamCls<T> {
public:

    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:
    Stream<T> _source;

    _BroadcastCallback<T> _onListenHandler;

    _BroadcastCallback<T> _onCancelHandler;

    Zone _zone;

    _AsBroadcastStreamController<T> _controller;

    StreamSubscription<T> _subscription;


     _AsBroadcastStreamCls(Stream<T> _source, std::function<void(StreamSubscription<T> subscription)> onListenHandler, std::function<void(StreamSubscription<T> subscription)> onCancelHandler);

    virtual void _onCancel();

    virtual void _onListen();

    virtual void _cancelSubscription();

    virtual void _pauseSubscription(Future<void> resumeSignal);

    virtual void _resumeSubscription();

    virtual bool _isSubscriptionPaused();

};
template<typename T>
using _AsBroadcastStream = std::shared_ptr<_AsBroadcastStreamCls<T>>;

template<typename T>
class _BroadcastSubscriptionWrapperCls : public ObjectCls {
public:

    virtual void onData(std::function<void(T data)> handleData);

    virtual void onError(std::function<void ()> handleError);

    virtual void onDone(std::function<void()> handleDone);

    virtual void pause(Future<void> resumeSignal);

    virtual void resume();

    virtual Future cancel();

    virtual bool isPaused();

    template<typename E>
 virtual Future<E> asFuture(E futureValue);

private:
    _AsBroadcastStream _stream;


     _BroadcastSubscriptionWrapperCls(_AsBroadcastStream _stream);
};
template<typename T>
using _BroadcastSubscriptionWrapper = std::shared_ptr<_BroadcastSubscriptionWrapperCls<T>>;

template<typename T>
class _StreamIteratorCls : public ObjectCls {
public:

    virtual T current();

    virtual Future<bool> moveNext();

    virtual Future cancel();

private:
    StreamSubscription<T> _subscription;

    Object _stateData;

    bool _hasValue;


     _StreamIteratorCls(Stream<T> stream);

    virtual Future<bool> _initializeOrDone();

    virtual void _onData(T data);

    virtual void _onError(Object error, StackTrace stackTrace);

    virtual void _onDone();

};
template<typename T>
using _StreamIterator = std::shared_ptr<_StreamIteratorCls<T>>;

template<typename T>
class _EmptyStreamCls : public StreamCls<T> {
public:

    virtual bool isBroadcast();

    virtual StreamSubscription<T> listen(std::function<void(T data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:

     _EmptyStreamCls();

};
template<typename T>
using _EmptyStream = std::shared_ptr<_EmptyStreamCls<T>>;

template<typename T>
class _MultiStreamCls : public StreamCls<T> {
public:
    bool isBroadcast;


    virtual StreamSubscription<T> listen(std::function<void(T event)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

private:
    std::function<void(MultiStreamController<T> )> _onListen;


     _MultiStreamCls(std::function<void(MultiStreamController<T> )> _onListen, bool isBroadcast);
};
template<typename T>
using _MultiStream = std::shared_ptr<_MultiStreamCls<T>>;

template<typename T>
class _MultiStreamControllerCls : public _AsyncStreamControllerCls<T> {
public:

    virtual void addSync(T data);

    virtual void addErrorSync(Object error, StackTrace stackTrace);

    virtual void closeSync();

    virtual Stream<T> stream();

private:

     _MultiStreamControllerCls();

};
template<typename T>
using _MultiStreamController = std::shared_ptr<_MultiStreamControllerCls<T>>;


#endif