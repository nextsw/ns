#include "isolate.hpp"
String IsolateSpawnExceptionCls::toString() {
    return __s("IsolateSpawnException: $message");
}

Capability IsolateCls::pause(Capability resumeCapability) {
    resumeCapability = make<CapabilityCls>();
    _pause(resumeCapability);
    return resumeCapability;
}

Stream IsolateCls::errors() {
    StreamController controller = StreamControllerCls->broadcast(true);
    RawReceivePort port;
    InlineMethod;
    controller->onListen = [=] () {
        RawReceivePort receivePort = make<RawReceivePortCls>(handleError);
        port = receivePort;
        this->addErrorListener(receivePort->sendPort());
    };
    controller->onCancel = [=] () {
        auto listenPort = port!;
        port = nullptr;
        this->removeErrorListener(listenPort->sendPort());
        listenPort->close();
    };
    return controller->stream();
}

RemoteErrorCls::RemoteErrorCls(String description, String stackDescription) {
    {
        _description = description;
        stackTrace = StackTraceCls->fromString(stackDescription);
    }
}

String RemoteErrorCls::toString() {
    return _description;
}
