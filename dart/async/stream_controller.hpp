#ifndef DART_ASYNC_STREAM_CONTROLLER
#define DART_ASYNC_STREAM_CONTROLLER
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T> class StreamControllerCls : public ObjectCls {
public:
    void Function() onListen;

    void Function() onPause;

    void Function() onResume;

    FutureOr<void> Function() onCancel;


    virtual Stream<T> stream();
     StreamControllerCls(FutureOr<void> onCancel() , void onListen() , void onPause() , void onResume() , bool sync);

    virtual void  broadcast(void onCancel() , void onListen() , bool sync);

    virtual StreamSink<T> sink();
    virtual bool isClosed();
    virtual bool isPaused();
    virtual bool hasListener();
    virtual void add(T event);
    virtual void addError(Object error, StackTrace stackTrace);
    virtual Future close();
    virtual Future done();
    virtual Future addStream(bool cancelOnError, Stream<T> source);
private:

};
template<typename T> using StreamController = std::shared_ptr<StreamControllerCls<T>>;

template<typename T> class SynchronousStreamControllerCls : public ObjectCls {
public:

    virtual void add(T data);
    virtual void addError(Object error, StackTrace stackTrace);
    virtual Future close();
private:

};
template<typename T> using SynchronousStreamController = std::shared_ptr<SynchronousStreamControllerCls<T>>;

template<typename T> class _StreamControllerLifecycleCls : public ObjectCls {
public:

private:

    virtual StreamSubscription<T> _subscribe(bool cancelOnError, void onData(T data) , void onDone() , void  onError() );
    virtual void _recordPause(StreamSubscription<T> subscription);

    virtual void _recordResume(StreamSubscription<T> subscription);

    virtual Future<void> _recordCancel(StreamSubscription<T> subscription);

};
template<typename T> using _StreamControllerLifecycle = std::shared_ptr<_StreamControllerLifecycleCls<T>>;

template<typename T> class _StreamControllerBaseCls : public ObjectCls {
public:

private:

};
template<typename T> using _StreamControllerBase = std::shared_ptr<_StreamControllerBaseCls<T>>;

template<typename T> class _StreamControllerCls : public ObjectCls {
public:
    void Function() onListen;

    void Function() onPause;

    void Function() onResume;

    FutureOr<void> Function() onCancel;


    virtual Stream<T> stream();

    virtual StreamSink<T> sink();

    virtual bool hasListener();

    virtual bool isClosed();

    virtual bool isPaused();

    virtual Future addStream(bool cancelOnError, Stream<T> source);

    virtual Future<void> done();

    virtual void add(T value);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual Future close();

private:
    static int _STATE_INITIAL;

    static int _STATE_SUBSCRIBED;

    static int _STATE_CANCELED;

    static int _STATE_SUBSCRIPTION_MASK;

    static int _STATE_CLOSED;

    static int _STATE_ADDSTREAM;

    Object _varData;

    int _state;

    _Future<void> _doneFuture;


     _StreamControllerCls(FutureOr<void> Function() onCancel, void Function() onListen, void Function() onPause, void Function() onResume);
    virtual bool _isCanceled();

    virtual bool _isInitialState();

    virtual bool _isAddingStream();

    virtual bool _mayAddEvent();

    virtual _PendingEvents<T> _pendingEvents();

    virtual _PendingEvents<T> _ensurePendingEvents();

    virtual _ControllerSubscription<T> _subscription();

    virtual Error _badEventState();

    virtual Future<void> _ensureDoneFuture();

    virtual void _closeUnchecked();

    virtual void _add(T value);

    virtual void _addError(Object error, StackTrace stackTrace);

    virtual void _close();

    virtual StreamSubscription<T> _subscribe(bool cancelOnError, void onData(T data) , void onDone() , void  onError() );

    virtual Future<void> _recordCancel(StreamSubscription<T> subscription);

    virtual void _recordPause(StreamSubscription<T> subscription);

    virtual void _recordResume(StreamSubscription<T> subscription);

};
template<typename T> using _StreamController = std::shared_ptr<_StreamControllerCls<T>>;

template<typename T> class _SyncStreamControllerDispatchCls : public ObjectCls {
public:

private:

    virtual void _sendData(T data);

    virtual void _sendError(Object error, StackTrace stackTrace);

    virtual void _sendDone();

};
template<typename T> using _SyncStreamControllerDispatch = std::shared_ptr<_SyncStreamControllerDispatchCls<T>>;

template<typename T> class _AsyncStreamControllerDispatchCls : public ObjectCls {
public:

private:

    virtual void _sendData(T data);

    virtual void _sendError(Object error, StackTrace stackTrace);

    virtual void _sendDone();

};
template<typename T> using _AsyncStreamControllerDispatch = std::shared_ptr<_AsyncStreamControllerDispatchCls<T>>;

template<typename T> class _AsyncStreamControllerCls : public ObjectCls {
public:

private:

};
template<typename T> using _AsyncStreamController = std::shared_ptr<_AsyncStreamControllerCls<T>>;

template<typename T> class _SyncStreamControllerCls : public ObjectCls {
public:

private:

};
template<typename T> using _SyncStreamController = std::shared_ptr<_SyncStreamControllerCls<T>>;
void _runGuarded(void notificationHandler() );


template<typename T> class _ControllerStreamCls : public _StreamImplCls<T> {
public:

    virtual int hashCode();

    virtual bool operator==(Object other);

private:
    _StreamControllerLifecycle<T> _controller;


     _ControllerStreamCls(_StreamControllerLifecycle<T> _controller);
    virtual StreamSubscription<T> _createSubscription(bool cancelOnError, void onData(T data) , void onDone() , void  onError() );

};
template<typename T> using _ControllerStream = std::shared_ptr<_ControllerStreamCls<T>>;

template<typename T> class _ControllerSubscriptionCls : public _BufferingStreamSubscriptionCls<T> {
public:

private:
    _StreamControllerLifecycle<T> _controller;


     _ControllerSubscriptionCls(_StreamControllerLifecycle<T> _controller, bool cancelOnError, void onData(T data) , void onDone() , void  onError() );

    virtual Future<void> _onCancel();

    virtual void _onPause();

    virtual void _onResume();

};
template<typename T> using _ControllerSubscription = std::shared_ptr<_ControllerSubscriptionCls<T>>;

template<typename T> class _StreamSinkWrapperCls : public ObjectCls {
public:

    virtual void add(T data);

    virtual void addError(Object error, StackTrace stackTrace);

    virtual Future close();

    virtual Future addStream(Stream<T> source);

    virtual Future done();

private:
    StreamController _target;


     _StreamSinkWrapperCls(StreamController _target);
};
template<typename T> using _StreamSinkWrapper = std::shared_ptr<_StreamSinkWrapperCls<T>>;

template<typename T> class _AddStreamStateCls : public ObjectCls {
public:
    _Future addStreamFuture;

    StreamSubscription addSubscription;


    static void  makeErrorHandler(_EventSink controller);

    virtual void pause();

    virtual void resume();

    virtual Future<void> cancel();

    virtual void complete();

private:

     _AddStreamStateCls(bool cancelOnError, _EventSink<T> controller, Stream<T> source);

};
template<typename T> using _AddStreamState = std::shared_ptr<_AddStreamStateCls<T>>;

template<typename T> class _StreamControllerAddStreamStateCls : public _AddStreamStateCls<T> {
public:
    auto varData;


private:

     _StreamControllerAddStreamStateCls(bool cancelOnError, _StreamController<T> controller, Stream<T> source, auto varData);

};
template<typename T> using _StreamControllerAddStreamState = std::shared_ptr<_StreamControllerAddStreamStateCls<T>>;


#endif