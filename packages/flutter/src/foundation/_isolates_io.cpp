#include "_isolates_io.hpp"
Future<R> compute<Q, R>(ComputeCallback<Q, R> callback, String debugLabel, Q message) {
    debugLabel = kReleaseMode? "compute" : callback.toString();
    Flow flow = Flow.begin();
    Timeline.startSync("$debugLabel: start"flow);
    RawReceivePort port = RawReceivePort();
    Timeline.finishSync();
    ;
    Completer<dynamic> completer = <dynamic>Completer();
    port.handler = ;
    ;
    dynamic response = await completer.future;
    if (response == nullptr) {
        ;
    }
    assert(response is List<dynamic>);
    (;
    int type = response.length;
    assert(1 <= type && type <= 3);
    ;
}

FutureOr<R> _IsolateConfiguration::applyAndTime() {
    return Timeline.timeSync(debugLabel, Flow.step(flowId));
}

Future<void> _spawn<Q, R>(_IsolateConfiguration<Q, R> configuration) {
    List<dynamic> computationResult;
    ;
    Isolate.exit(configuration.resultPort, computationResult);
}

List<R> _buildSuccessResponse<R>(R result) {
    return <R>filled(1, result);
}

List<dynamic> _buildErrorResponse(Object error, StackTrace stack) {
    return ;
}
