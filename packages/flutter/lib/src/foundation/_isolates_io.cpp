#include "_isolates_io.hpp"
template<typename Q, typename R>
Future<R> compute(ComputeCallback<Q, R> callback, String debugLabel, Q message) {
    debugLabel = kReleaseMode? __s("compute") : callback->toString();
    Flow flow = FlowCls->begin();
    TimelineCls->startSync(__s("$debugLabel: start")flow);
    RawReceivePort port = make<RawReceivePortCls>();
    TimelineCls->finishSync();
    InlineMethod;
    Completer<dynamic> completer = <dynamic>make<CompleterCls>();
    port->handler = [=] (dynamic msg) {
        timeEndAndCleanup();
        completer->complete(msg);
    };
    try {
        await await IsolateCls-><_IsolateConfiguration<Q, R>>spawn(_spawn, <Q, R>make<_IsolateConfigurationCls>(callback, message, port->sendPort(), debugLabel, flow->id)port->sendPort(), port->sendPort(), debugLabel);
    } catch (Object null) {
        timeEndAndCleanup();
        throw;
    };
    dynamic response = await completer->future;
    if (response == nullptr) {
        ;
    }
    assert(is<List<dynamic>>(response));
    as<List<dynamic>>(response);
    int type = response->length;
    assert(1 <= type && type <= 3);
    ;
}

template<typename Q, typename R>
FutureOr<R> _IsolateConfigurationCls<Q, R>::applyAndTime() {
    return TimelineCls->timeSync(debugLabel, [=] ()     {
        callback(message);
    }FlowCls->step(flowId));
}

template<typename Q, typename R>
Future<void> _spawn(_IsolateConfiguration<Q, R> configuration) {
    List<dynamic> computationResult;
    try {
        computationResult = _buildSuccessResponse(await configuration->applyAndTime());
    } catch (Unknown e) {
        computationResult = _buildErrorResponse(e, s);
    };
    IsolateCls->exit(configuration->resultPort, computationResult);
}

template<typename R>
List<R> _buildSuccessResponse(R result) {
    return <R>filled(1, result);
}

List<dynamic> _buildErrorResponse(Object error, StackTrace stack) {
    auto _c1 = <dynamic>filled(3, nullptr);_c1[0] =auto _c2 = error;_c2[1] =stack;_c2;return _c1;
}
