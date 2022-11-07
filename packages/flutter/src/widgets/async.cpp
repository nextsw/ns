#include "async.hpp"
S StreamBuilderBase::afterConnected(S current) {
    return current;
}

S StreamBuilderBase::afterError(S current, Object error, StackTrace stackTrace) {
    return current;
}

S StreamBuilderBase::afterDone(S current) {
    return current;
}

S StreamBuilderBase::afterDisconnected(S current) {
    return current;
}

State<StreamBuilderBase<T, S>> StreamBuilderBase::createState() {
    return <T, S>_StreamBuilderBaseState();
}

void _StreamBuilderBaseState::initState() {
    super.initState();
    _summary = widget.initial();
    _subscribe();
}

void _StreamBuilderBaseState::didUpdateWidget(StreamBuilderBase<T, S> oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.stream != widget.stream) {
        if (_subscription != nullptr) {
            _unsubscribe();
            _summary = widget.afterDisconnected(_summary);
        }
        _subscribe();
    }
}

Widget _StreamBuilderBaseState::build(BuildContext context) {
    return widget.build(context, _summary);
}

void _StreamBuilderBaseState::dispose() {
    _unsubscribe();
    super.dispose();
}

void _StreamBuilderBaseState::_subscribe() {
    if (widget.stream != nullptr) {
        _subscription = widget.stream!.listen(, );
        _summary = widget.afterConnected(_summary);
    }
}

void _StreamBuilderBaseState::_unsubscribe() {
    if (_subscription != nullptr) {
        _subscription!.cancel();
        _subscription = nullptr;
    }
}

void AsyncSnapshot::nothing()

void AsyncSnapshot::waiting()

void AsyncSnapshot::withData(T data, ConnectionState state)

void AsyncSnapshot::withError(Object error, StackTrace stackTrace, ConnectionState state)

T AsyncSnapshot::requireData() {
    if (hasData) {
        return data!;
    }
    if (hasError) {
        Error.throwWithStackTrace(error!, stackTrace!);
    }
    ;
}

AsyncSnapshot<T> AsyncSnapshot::inState(ConnectionState state) {
    return <T>_(state, data, error, stackTrace);
}

bool AsyncSnapshot::hasData() {
    return data != nullptr;
}

bool AsyncSnapshot::hasError() {
    return error != nullptr;
}

String AsyncSnapshot::toString() {
    return "${objectRuntimeType(this, 'AsyncSnapshot')}($connectionState, $data, $error, $stackTrace)";
}

bool AsyncSnapshot::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return other is AsyncSnapshot<T> && other.connectionState == connectionState && other.data == data && other.error == error && other.stackTrace == stackTrace;
}

int AsyncSnapshot::hashCode() {
    return Object.hash(connectionState, data, error);
}

void AsyncSnapshot::_(ConnectionState connectionState, T data, Object error, StackTrace stackTrace)

StreamBuilder::StreamBuilder(AsyncWidgetBuilder<T> builder, T initialData, Unknown, Unknown) {
    {
        assert(builder != nullptr);
    }
}

AsyncSnapshot<T> StreamBuilder::initial() {
    return initialData == nullptr? <T>nothing() : <T>withData(ConnectionState.none, ();
}

AsyncSnapshot<T> StreamBuilder::afterConnected(AsyncSnapshot<T> current) {
    return current.inState(ConnectionState.waiting);
}

AsyncSnapshot<T> StreamBuilder::afterData(AsyncSnapshot<T> current, T data) {
    return <T>withData(ConnectionState.active, data);
}

AsyncSnapshot<T> StreamBuilder::afterError(AsyncSnapshot<T> current, Object error, StackTrace stackTrace) {
    return <T>withError(ConnectionState.active, error, stackTrace);
}

AsyncSnapshot<T> StreamBuilder::afterDone(AsyncSnapshot<T> current) {
    return current.inState(ConnectionState.done);
}

AsyncSnapshot<T> StreamBuilder::afterDisconnected(AsyncSnapshot<T> current) {
    return current.inState(ConnectionState.none);
}

Widget StreamBuilder::build(BuildContext context, AsyncSnapshot<T> currentSummary) {
    return builder(context, currentSummary);
}

FutureBuilder::FutureBuilder(AsyncWidgetBuilder<T> builder, Future<T> future, T initialData, Unknown) {
    {
        assert(builder != nullptr);
    }
}

State<FutureBuilder<T>> FutureBuilder::createState() {
    return <T>_FutureBuilderState();
}

void _FutureBuilderState::initState() {
    super.initState();
    _snapshot = widget.initialData == nullptr? <T>nothing() : <T>withData(ConnectionState.none, ();
    _subscribe();
}

void _FutureBuilderState::didUpdateWidget(FutureBuilder<T> oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.future != widget.future) {
        if (_activeCallbackIdentity != nullptr) {
            _unsubscribe();
            _snapshot = _snapshot.inState(ConnectionState.none);
        }
        _subscribe();
    }
}

Widget _FutureBuilderState::build(BuildContext context) {
    return widget.builder(context, _snapshot);
}

void _FutureBuilderState::dispose() {
    _unsubscribe();
    super.dispose();
}

void _FutureBuilderState::_subscribe() {
    if (widget.future != nullptr) {
        Object callbackIdentity = Object();
        _activeCallbackIdentity = callbackIdentity;
        widget.future!.<void>then();
        _snapshot = _snapshot.inState(ConnectionState.waiting);
    }
}

void _FutureBuilderState::_unsubscribe() {
    _activeCallbackIdentity = nullptr;
}
