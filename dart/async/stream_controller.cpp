#include "stream_controller.hpp"
template<typename T> StreamControllerCls<T>::StreamControllerCls(FutureOr<void> onCancel() , void onListen() , void onPause() , void onResume() , bool sync) {
    {
        return sync? <T>make<_SyncStreamControllerCls>(onListen, onPause, onResume, onCancel) : <T>make<_AsyncStreamControllerCls>(onListen, onPause, onResume, onCancel);
    }
}

template<typename T> void StreamControllerCls<T>::broadcast(void onCancel() , void onListen() , bool sync) {
    return sync? <T>make<_SyncBroadcastStreamControllerCls>(onListen, onCancel) : <T>make<_AsyncBroadcastStreamControllerCls>(onListen, onCancel);
}

template<typename T> void _StreamControllerLifecycleCls<T>::_recordPause(StreamSubscription<T> subscription) {
}

template<typename T> void _StreamControllerLifecycleCls<T>::_recordResume(StreamSubscription<T> subscription) {
}

template<typename T> Future<void> _StreamControllerLifecycleCls<T>::_recordCancel(StreamSubscription<T> subscription) {
    return nullptr;
}

template<typename T> Stream<T> _StreamControllerCls<T>::stream() {
    return <T>make<_ControllerStreamCls>(this);
}

template<typename T> StreamSink<T> _StreamControllerCls<T>::sink() {
    return <T>make<_StreamSinkWrapperCls>(this);
}

template<typename T> bool _StreamControllerCls<T>::hasListener() {
    return (_state & _STATE_SUBSCRIBEDCls) != 0;
}

template<typename T> bool _StreamControllerCls<T>::isClosed() {
    return (_state & _STATE_CLOSEDCls) != 0;
}

template<typename T> bool _StreamControllerCls<T>::isPaused() {
    return hasListener? _subscription->_isInputPaused : !_isCanceled;
}

template<typename T> Future _StreamControllerCls<T>::addStream(bool cancelOnError, Stream<T> source) {
    if (!_mayAddEvent)     {
        ;
    }
    if (_isCanceled)     {
        return _FutureCls->immediate(nullptr);
    }
    _StreamControllerAddStreamState<T> addState = <T>make<_StreamControllerAddStreamStateCls>(this, _varData, source, cancelOnError ?? false);
    _varData = addState;
    _state = _STATE_ADDSTREAMCls;
    return addState->addStreamFuture;
}

template<typename T> Future<void> _StreamControllerCls<T>::done() {
    return _ensureDoneFuture();
}

template<typename T> void _StreamControllerCls<T>::add(T value) {
    if (!_mayAddEvent)     {
        ;
    }
    _add(value);
}

template<typename T> void _StreamControllerCls<T>::addError(Object error, StackTrace stackTrace) {
    checkNotNullable(error, "error");
    if (!_mayAddEvent)     {
        ;
    }
    AsyncError replacement = ZoneCls::current->errorCallback(error, stackTrace);
    if (replacement != nullptr) {
        error = replacement->error;
        stackTrace = replacement->stackTrace;
    } else {
        stackTrace = AsyncErrorCls->defaultStackTrace(error);
    }
    _addError(error, stackTrace);
}

template<typename T> Future _StreamControllerCls<T>::close() {
    if (isClosed) {
        return _ensureDoneFuture();
    }
    if (!_mayAddEvent)     {
        ;
    }
    _closeUnchecked();
    return _ensureDoneFuture();
}

template<typename T> bool _StreamControllerCls<T>::_isCanceled() {
    return (_state & _STATE_CANCELEDCls) != 0;
}

template<typename T> bool _StreamControllerCls<T>::_isInitialState() {
    return (_state & _STATE_SUBSCRIPTION_MASKCls) == _STATE_INITIALCls;
}

template<typename T> bool _StreamControllerCls<T>::_isAddingStream() {
    return (_state & _STATE_ADDSTREAMCls) != 0;
}

template<typename T> bool _StreamControllerCls<T>::_mayAddEvent() {
    return ( < _STATE_CLOSEDCls);
}

template<typename T> _PendingEvents<T> _StreamControllerCls<T>::_pendingEvents() {
    assert(_isInitialState);
    if (!_isAddingStream) {
        return ((dynamic)_varData);
    }
    _StreamControllerAddStreamState<T> state = ((dynamic)_varData);
    return state->varData;
}

template<typename T> _PendingEvents<T> _StreamControllerCls<T>::_ensurePendingEvents() {
    assert(_isInitialState);
    if (!_isAddingStream) {
        Object events = _varData;
        if (events == nullptr) {
            _varData = events = <T>make<_PendingEventsCls>();
        }
        return ((dynamic)events);
    }
    _StreamControllerAddStreamState<T> state = ((dynamic)_varData);
    Object events = state->varData;
    if (events == nullptr) {
        state->varData = events = <T>make<_PendingEventsCls>();
    }
    return ((dynamic)events);
}

template<typename T> _ControllerSubscription<T> _StreamControllerCls<T>::_subscription() {
    assert(hasListener);
    Object varData = _varData;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<Object> streamState = ((dynamic)varData);
        varData = streamState->varData;
    }
    return ((dynamic)varData);
}

template<typename T> Error _StreamControllerCls<T>::_badEventState() {
    if (isClosed) {
        return make<StateErrorCls>("Cannot add event after closing");
    }
    assert(_isAddingStream);
    return make<StateErrorCls>("Cannot add event while adding a stream");
}

template<typename T> Future<void> _StreamControllerCls<T>::_ensureDoneFuture() {
    return _doneFuture ??= _isCanceled? FutureCls::_nullFuture : <void>make<_FutureCls>();
}

template<typename T> void _StreamControllerCls<T>::_closeUnchecked() {
    _state = _STATE_CLOSEDCls;
    if (hasListener) {
        _sendDone();
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents()->add(make<_DelayedDoneCls>());
    }
;
    }}

template<typename T> void _StreamControllerCls<T>::_add(T value) {
    if (hasListener) {
        _sendData(value);
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents()->add(<T>make<_DelayedDataCls>(value));
    }
;
    }}

template<typename T> void _StreamControllerCls<T>::_addError(Object error, StackTrace stackTrace) {
    if (hasListener) {
        _sendError(error, stackTrace);
    } else     {
        if (_isInitialState) {
        _ensurePendingEvents()->add(make<_DelayedErrorCls>(error, stackTrace));
    }
;
    }}

template<typename T> void _StreamControllerCls<T>::_close() {
    assert(_isAddingStream);
    _StreamControllerAddStreamState<T> addState = ((dynamic)_varData);
    _varData = addState->varData;
    _state = ~_STATE_ADDSTREAMCls;
    addState->complete();
}

template<typename T> StreamSubscription<T> _StreamControllerCls<T>::_subscribe(bool cancelOnError, void onData(T data) , void onDone() , void  onError() ) {
    if (!_isInitialState) {
        ;
    }
    _ControllerSubscription<T> subscription = <T>make<_ControllerSubscriptionCls>(this, onData, onError, onDone, cancelOnError);
    _PendingEvents<T> pendingEvents = _pendingEvents;
    _state = _STATE_SUBSCRIBEDCls;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = ((dynamic)_varData);
        addState->varData = subscription;
        addState->resume();
    } else {
        _varData = subscription;
    }
    subscription->_setPendingEvents(pendingEvents);
    subscription->_guardCallback([=] () {
        _runGuarded(onListen);
    });
    return subscription;
}

template<typename T> Future<void> _StreamControllerCls<T>::_recordCancel(StreamSubscription<T> subscription) {
    Future<void> result;
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = ((dynamic)_varData);
        result = addState->cancel();
    }
    _varData = nullptr;
    _state = (_state & ~(_STATE_SUBSCRIBEDCls | _STATE_ADDSTREAMCls)) | _STATE_CANCELEDCls;
    auto onCancel = this->onCancel;
    if (onCancel != nullptr) {
        if (result == nullptr) {
            try {
                auto cancelResult = onCancel();
                if (cancelResult is Future<void>) {
                    result = cancelResult;
                }
            } catch (Unknown e) {
                            auto _c1 = make<_FutureCls>();            _c1._asyncCompleteError(e, s);result = _c1;
            };
        } else {
            result = result->whenComplete(onCancel);
        }
    }
    InlineMethod;
    if (result != nullptr) {
        result = result->whenComplete(complete);
    } else {
        complete();
    }
    return result;
}

template<typename T> void _StreamControllerCls<T>::_recordPause(StreamSubscription<T> subscription) {
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = ((dynamic)_varData);
        addState->pause();
    }
    _runGuarded(onPause);
}

template<typename T> void _StreamControllerCls<T>::_recordResume(StreamSubscription<T> subscription) {
    if (_isAddingStream) {
        _StreamControllerAddStreamState<T> addState = ((dynamic)_varData);
        addState->resume();
    }
    _runGuarded(onResume);
}

template<typename T> void _SyncStreamControllerDispatchCls<T>::_sendData(T data) {
    _subscription->_add(data);
}

template<typename T> void _SyncStreamControllerDispatchCls<T>::_sendError(Object error, StackTrace stackTrace) {
    _subscription->_addError(error, stackTrace);
}

template<typename T> void _SyncStreamControllerDispatchCls<T>::_sendDone() {
    _subscription->_close();
}

template<typename T> void _AsyncStreamControllerDispatchCls<T>::_sendData(T data) {
    _subscription->_addPending(<T>make<_DelayedDataCls>(data));
}

template<typename T> void _AsyncStreamControllerDispatchCls<T>::_sendError(Object error, StackTrace stackTrace) {
    _subscription->_addPending(make<_DelayedErrorCls>(error, stackTrace));
}

template<typename T> void _AsyncStreamControllerDispatchCls<T>::_sendDone() {
    _subscription->_addPending(make<_DelayedDoneCls>());
}

void _runGuarded(void notificationHandler() ) {
    if (notificationHandler == nullptr)     {
        return;
    }
    try {
        notificationHandler();
    } catch (Unknown e) {
        ZoneCls::current->handleUncaughtError(e, s);
    };
}

template<typename T> int _ControllerStreamCls<T>::hashCode() {
    return _controller->hashCode ^ 0x35323532;
}

template<typename T> bool _ControllerStreamCls<T>::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return other is _ControllerStream && identical(other->_controller, this->_controller);
}

template<typename T> StreamSubscription<T> _ControllerStreamCls<T>::_createSubscription(bool cancelOnError, void onData(T data) , void onDone() , void  onError() ) {
    return _controller->_subscribe(onData, onError, onDone, cancelOnError);
}

template<typename T> _ControllerSubscriptionCls<T>::_ControllerSubscriptionCls(_StreamControllerLifecycle<T> _controller, bool cancelOnError, void onData(T data) , void onDone() , void  onError() ) {
}

template<typename T> Future<void> _ControllerSubscriptionCls<T>::_onCancel() {
    return _controller->_recordCancel(this);
}

template<typename T> void _ControllerSubscriptionCls<T>::_onPause() {
    _controller->_recordPause(this);
}

template<typename T> void _ControllerSubscriptionCls<T>::_onResume() {
    _controller->_recordResume(this);
}

template<typename T> void _StreamSinkWrapperCls<T>::add(T data) {
    _target->add(data);
}

template<typename T> void _StreamSinkWrapperCls<T>::addError(Object error, StackTrace stackTrace) {
    _target->addError(error, stackTrace);
}

template<typename T> Future _StreamSinkWrapperCls<T>::close() {
    return _target->close();
}

template<typename T> Future _StreamSinkWrapperCls<T>::addStream(Stream<T> source) {
    return _target->addStream(source);
}

template<typename T> Future _StreamSinkWrapperCls<T>::done() {
    return _target->done;
}

template<typename T> void _AddStreamStateCls<T>::makeErrorHandler(_EventSink controller) {
    return [=] (Object e,StackTrace s) {
        controller->_addError(e, s);
        controller->_close();
    };
}

template<typename T> void _AddStreamStateCls<T>::pause() {
    addSubscription->pause();
}

template<typename T> void _AddStreamStateCls<T>::resume() {
    addSubscription->resume();
}

template<typename T> Future<void> _AddStreamStateCls<T>::cancel() {
    auto cancel = addSubscription->cancel();
    if (cancel == nullptr) {
        addStreamFuture->_asyncComplete(nullptr);
        return FutureCls::_nullFuture;
    }
    return cancel->whenComplete([=] () {
        addStreamFuture->_asyncComplete(nullptr);
    });
}

template<typename T> void _AddStreamStateCls<T>::complete() {
    addStreamFuture->_asyncComplete(nullptr);
}

template<typename T> _AddStreamStateCls<T>::_AddStreamStateCls(bool cancelOnError, _EventSink<T> controller, Stream<T> source) {
    {
        addStreamFuture = make<_FutureCls>();
        addSubscription = source->listen(controller->_addcancelOnError? makeErrorHandler(controller) : controller->_addError, controller->_close, cancelOnError);
    }
}

template<typename T> _StreamControllerAddStreamStateCls<T>::_StreamControllerAddStreamStateCls(bool cancelOnError, _StreamController<T> controller, Stream<T> source, auto varData) {
    {
        if (controller->isPaused) {
            addSubscription->pause();
        }
    }
}
