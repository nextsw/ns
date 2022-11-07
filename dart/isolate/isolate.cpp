#include "isolate.hpp"
String IsolateSpawnException::toString() {
    return "IsolateSpawnException: $message";
}

Capability Isolate::pause(Capability resumeCapability) {
    resumeCapability = Capability();
    _pause(resumeCapability);
    return resumeCapability;
}

Stream Isolate::errors() {
    StreamController controller = StreamController.broadcast(true);
    RawReceivePort port;
    ;
    controller.onListen = ;
    controller.onCancel = ;
    return controller.stream;
}

RemoteError::RemoteError(String description, String stackDescription) {
    {
        _description = description;
        stackTrace = StackTrace.fromString(stackDescription);
    }
}

String RemoteError::toString() {
    return _description;
}
