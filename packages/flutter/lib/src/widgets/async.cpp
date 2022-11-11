#include "async.hpp"
template<typename T, typename S>
S StreamBuilderBaseCls<T, S>::afterConnected(S current) {
    return current;
}

template<typename T, typename S>
S StreamBuilderBaseCls<T, S>::afterError(S current, Object error, StackTrace stackTrace) {
    return current;
}

template<typename T, typename S>
S StreamBuilderBaseCls<T, S>::afterDone(S current) {
    return current;
}

template<typename T, typename S>
S StreamBuilderBaseCls<T, S>::afterDisconnected(S current) {
    return current;
}

template<typename T, typename S>
State<StreamBuilderBase<T, S>> StreamBuilderBaseCls<T, S>::createState() {
    return <T, S>make<_StreamBuilderBaseStateCls>();
}

template<typename T, typename S>
void _StreamBuilderBaseStateCls<T, S>::initState() {
    super->initState();
    _summary = widget->initial();
    _subscribe();
}

template<typename T, typename S>
void _StreamBuilderBaseStateCls<T, S>::didUpdateWidget(StreamBuilderBase<T, S> oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->stream != widget->stream) {
        if (_subscription != nullptr) {
            _unsubscribe();
            _summary = widget->afterDisconnected(_summary);
        }
        _subscribe();
    }
}

template<typename T, typename S>
Widget _StreamBuilderBaseStateCls<T, S>::build(BuildContext context) {
    return widget->build(context, _summary);
}

template<typename T, typename S>
void _StreamBuilderBaseStateCls<T, S>::dispose() {
    _unsubscribe();
    super->dispose();
}

template<typename T, typename S>
void _StreamBuilderBaseStateCls<T, S>::_subscribe() {
    if (widget->stream != nullptr) {
        _subscription = widget->stream!->listen([=] (T data) {
            setState([=] () {
                _summary = widget->afterData(_summary, data);
            });
        }[=] (Object error,StackTrace stackTrace) {
            setState([=] () {
                _summary = widget->afterError(_summary, error, stackTrace);
            });
        }, [=] () {
            setState([=] () {
                _summary = widget->afterDone(_summary);
            });
        });
        _summary = widget->afterConnected(_summary);
    }
}

template<typename T, typename S>
void _StreamBuilderBaseStateCls<T, S>::_unsubscribe() {
    if (_subscription != nullptr) {
        _subscription!->cancel();
        _subscription = nullptr;
    }
}

template<typename T>
void AsyncSnapshotCls<T>::nothing()

template<typename T>
void AsyncSnapshotCls<T>::waiting()

template<typename T>
void AsyncSnapshotCls<T>::withData(ConnectionState state, T data)

template<typename T>
void AsyncSnapshotCls<T>::withError(ConnectionState state, Object error, StackTrace stackTrace)

template<typename T>
T AsyncSnapshotCls<T>::requireData() {
    if (hasData()) {
        return data!;
    }
    if (hasError()) {
        ErrorCls->throwWithStackTrace(error!, stackTrace!);
    }
    throw make<StateErrorCls>(__s("Snapshot has neither data nor error"));
}

template<typename T>
AsyncSnapshot<T> AsyncSnapshotCls<T>::inState(ConnectionState state) {
    return <T>_(state, data, error, stackTrace);
}

template<typename T>
bool AsyncSnapshotCls<T>::hasData() {
    return data != nullptr;
}

template<typename T>
bool AsyncSnapshotCls<T>::hasError() {
    return error != nullptr;
}

template<typename T>
String AsyncSnapshotCls<T>::toString() {
    return __s("${objectRuntimeType(this, 'AsyncSnapshot')}($connectionState, $data, $error, $stackTrace)");
}

template<typename T>
bool AsyncSnapshotCls<T>::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<AsyncSnapshot<T>>(other) && other->connectionState == connectionState && other->data == data && other->error == error && other->stackTrace == stackTrace;
}

template<typename T>
int AsyncSnapshotCls<T>::hashCode() {
    return ObjectCls->hash(connectionState, data, error);
}

template<typename T>
void AsyncSnapshotCls<T>::_(ConnectionState connectionState, T data, Object error, StackTrace stackTrace)

template<typename T>
StreamBuilderCls<T>::StreamBuilderCls(AsyncWidgetBuilder<T> builder, T initialData, Unknown key, Unknown stream) {
    {
        assert(builder != nullptr);
    }
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::initial() {
    return initialData == nullptr? <T>nothing() : <T>withData(ConnectionStateCls::none, as<T>(initialData));
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::afterConnected(AsyncSnapshot<T> current) {
    return current->inState(ConnectionStateCls::waiting);
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::afterData(AsyncSnapshot<T> current, T data) {
    return <T>withData(ConnectionStateCls::active, data);
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::afterError(AsyncSnapshot<T> current, Object error, StackTrace stackTrace) {
    return <T>withError(ConnectionStateCls::active, error, stackTrace);
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::afterDone(AsyncSnapshot<T> current) {
    return current->inState(ConnectionStateCls::done);
}

template<typename T>
AsyncSnapshot<T> StreamBuilderCls<T>::afterDisconnected(AsyncSnapshot<T> current) {
    return current->inState(ConnectionStateCls::none);
}

template<typename T>
Widget StreamBuilderCls<T>::build(BuildContext context, AsyncSnapshot<T> currentSummary) {
    return builder(context, currentSummary);
}

template<typename T>
FutureBuilderCls<T>::FutureBuilderCls(AsyncWidgetBuilder<T> builder, Future<T> future, T initialData, Unknown key) {
    {
        assert(builder != nullptr);
    }
}

template<typename T>
State<FutureBuilder<T>> FutureBuilderCls<T>::createState() {
    return <T>make<_FutureBuilderStateCls>();
}

template<typename T>
void _FutureBuilderStateCls<T>::initState() {
    super->initState();
    _snapshot = widget->initialData == nullptr? <T>nothing() : <T>withData(ConnectionStateCls::none, as<T>(widget->initialData));
    _subscribe();
}

template<typename T>
void _FutureBuilderStateCls<T>::didUpdateWidget(FutureBuilder<T> oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->future != widget->future) {
        if (_activeCallbackIdentity != nullptr) {
            _unsubscribe();
            _snapshot = _snapshot->inState(ConnectionStateCls::none);
        }
        _subscribe();
    }
}

template<typename T>
Widget _FutureBuilderStateCls<T>::build(BuildContext context) {
    return widget->builder(context, _snapshot);
}

template<typename T>
void _FutureBuilderStateCls<T>::dispose() {
    _unsubscribe();
    super->dispose();
}

template<typename T>
void _FutureBuilderStateCls<T>::_subscribe() {
    if (widget->future != nullptr) {
        Object callbackIdentity = make<ObjectCls>();
        _activeCallbackIdentity = callbackIdentity;
        widget->future!-><void>then([=] (T data) {
            if (_activeCallbackIdentity == callbackIdentity) {
                setState([=] () {
                    _snapshot = <T>withData(ConnectionStateCls::done, data);
                });
            }
        }[=] (Object error,StackTrace stackTrace) {
            if (_activeCallbackIdentity == callbackIdentity) {
                setState([=] () {
                    _snapshot = <T>withError(ConnectionStateCls::done, error, stackTrace);
                });
            }
            assert([=] () {
                if (FutureBuilderCls::debugRethrowError) {
                    <Object>error(error, stackTrace);
                }
                return true;
            }());
        });
        _snapshot = _snapshot->inState(ConnectionStateCls::waiting);
    }
}

template<typename T>
void _FutureBuilderStateCls<T>::_unsubscribe() {
    _activeCallbackIdentity = nullptr;
}
