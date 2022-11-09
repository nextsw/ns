#include "_isolates_io.hpp"
Future<R> computetemplate<typename Q, typename R> (ComputeCallback<Q, R> callback, String debugLabel, Q message) {
    debugLabel = kReleaseMode? "compute" : callback->toString();
    Flow flow = FlowCls->begin();
    TimelineCls->startSync("$debugLabel: start"flow);
    RawReceivePort port = make<RawReceivePortCls>();
    TimelineCls->finishSync();
    InlineMethod;
    Completer<dynamic> completer = <dynamic>make<CompleterCls>();
    port->handler = [=] (dynamic msg) {
        timeEndAndCleanup();
        completer->complete(msg);
    };
    try {
        await await IsolateCls-><_IsolateConfiguration<Q, R>>spawn(_spawn, <Q, R>make<_IsolateConfigurationCls>(callback, message, port->sendPort, debugLabel, flow->id)port->sendPort, port->sendPort, debugLabel);
    } catch (Object null) {
        timeEndAndCleanup();
        throw;
    };
    dynamic response = await completer->future;
    if (response == nullptr) {
        ;
    }
    assert(response is List<dynamic>);
    ((List<dynamic>)response);
    int type = response->length;
    assert(1 <= type && type <= 3);
    ;
}

template<typename Q, typename R> FutureOr<R> _IsolateConfigurationCls<Q, R>::applyAndTime() {
    return TimelineCls->timeSync(debugLabel, [=] ()     {
        callback(message);
    }FlowCls->step(flowId));
}

Future<void> _spawntemplate<typename Q, typename R> (_IsolateConfiguration<Q, R> configuration) {
    List<dynamic> computationResult;
    try {
        computationResult = _buildSuccessResponse(await configuration->applyAndTime());
    } catch (Unknown e) {
        computationResult = _buildErrorResponse(e, s);
    };
    IsolateCls->exit(configuration->resultPort, computationResult);
}

List<R> _buildSuccessResponsetemplate<typename R> (R result) {
    return <R>filled(1, result);
}

List<dynamic> _buildErrorResponse(Object error, StackTrace stack) {
    auto _c1 = <dynamic>filled(3, nullptr);_c1[0] =auto _c2 = error;_c2[1] =stack;_c2;return _c1;
}
