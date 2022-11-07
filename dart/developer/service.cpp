#include "service.hpp"
Uri ServiceProtocolInfo::serverWebSocketUri() {
    Uri uri = serverUri;
    if (uri != nullptr) {
        Unknown pathSegments = ;
        if (uri.pathSegments.isNotEmpty) {
            pathSegments.addAll(uri.pathSegments.where());
        }
        pathSegments.add("ws");
        uri = uri.replace("ws", pathSegments);
    }
    return uri;
}

String ServiceProtocolInfo::toString() {
    if (serverUri != nullptr) {
        return "Dart VM Service Protocol v$majorVersion.$minorVersion listening on $serverUri";
    } else {
        return "Dart VM Service Protocol v$majorVersion.$minorVersion";
    }
}

Future<ServiceProtocolInfo> Service::getInfo() {
    RawReceivePort receivePort = RawReceivePort(nullptr, "Service.getInfo");
    Completer<String> completer = <String>Completer();
    receivePort.handler = ;
    _getServerInfo(receivePort.sendPort);
    String uriString = await completer.future;
    Uri uri = uriString == nullptr? nullptr : Uri.parse(uriString);
    receivePort.close();
    return ServiceProtocolInfo(uri);
}

Future<ServiceProtocolInfo> Service::controlWebServer(bool enable, bool silenceOutput) {
    ArgumentError.checkNotNull(enable, "enable");
    RawReceivePort receivePort = RawReceivePort(nullptr, "Service.controlWebServer");
    Completer<String> completer = <String>Completer();
    receivePort.handler = ;
    _webServerControl(receivePort.sendPort, enable, silenceOutput);
    String uriString = await completer.future;
    Uri uri = uriString == nullptr? nullptr : Uri.parse(uriString);
    receivePort.close();
    return ServiceProtocolInfo(uri);
}

String Service::getIsolateID(Isolate isolate) {
    ArgumentError.checkNotNull(isolate, "isolate");
    return _getIsolateIDFromSendPort(isolate.controlPort);
}
