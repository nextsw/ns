#include "service.hpp"
Uri ServiceProtocolInfoCls::serverWebSocketUri() {
    Uri uri = serverUri;
    if (uri != nullptr) {
        Unknown pathSegments = makeList();
        if (uri->pathSegments->isNotEmpty) {
            pathSegments->addAll(uri->pathSegments->where([=] (Unknown  s)             {
                s->isNotEmpty;
            }));
        }
        pathSegments->add("ws");
        uri = uri->replace("ws", pathSegments);
    }
    return uri;
}

String ServiceProtocolInfoCls::toString() {
    if (serverUri != nullptr) {
        return "Dart VM Service Protocol v$majorVersion.$minorVersion listening on $serverUri";
    } else {
        return "Dart VM Service Protocol v$majorVersion.$minorVersion";
    }
}

Future<ServiceProtocolInfo> ServiceCls::getInfo() {
    RawReceivePort receivePort = make<RawReceivePortCls>(nullptr, "Service.getInfo");
    Completer<String> completer = <String>make<CompleterCls>();
    receivePort->handler = [=] (String uriString)     {
        completer->complete(uriString);
    };
    _getServerInfo(receivePort->sendPort);
    String uriString = await completer->future;
    Uri uri = uriString == nullptr? nullptr : UriCls->parse(uriString);
    receivePort->close();
    return make<ServiceProtocolInfoCls>(uri);
}

Future<ServiceProtocolInfo> ServiceCls::controlWebServer(bool enable, bool silenceOutput) {
    ArgumentErrorCls->checkNotNull(enable, "enable");
    RawReceivePort receivePort = make<RawReceivePortCls>(nullptr, "Service.controlWebServer");
    Completer<String> completer = <String>make<CompleterCls>();
    receivePort->handler = [=] (String uriString)     {
        completer->complete(uriString);
    };
    _webServerControl(receivePort->sendPort, enable, silenceOutput);
    String uriString = await completer->future;
    Uri uri = uriString == nullptr? nullptr : UriCls->parse(uriString);
    receivePort->close();
    return make<ServiceProtocolInfoCls>(uri);
}

String ServiceCls::getIsolateID(Isolate isolate) {
    ArgumentErrorCls->checkNotNull(isolate, "isolate");
    return _getIsolateIDFromSendPort(isolate->controlPort);
}
