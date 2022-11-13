#include "service.hpp"
Uri ServiceProtocolInfoCls::serverWebSocketUri() {
    Uri uri = serverUri;
    if (uri != nullptr) {
        Unknown pathSegments = makeList();
        if (uri->pathSegments->isNotEmpty()) {
            pathSegments->addAll(uri->pathSegments->where([=] (Unknown  s) {
                s->isNotEmpty;
            }));
        }
        pathSegments->add(__s("ws"));
        uri = uri->replace(__s("ws"), pathSegments);
    }
    return uri;
}

String ServiceProtocolInfoCls::toString() {
    if (serverUri != nullptr) {
        return __sf("Dart VM Service Protocol v%s.%s listening on %s", majorVersion, minorVersion, serverUri);
    } else {
        return __sf("Dart VM Service Protocol v%s.%s", majorVersion, minorVersion);
    }
}

Future<ServiceProtocolInfo> ServiceCls::getInfo() {
    RawReceivePort receivePort = make<RawReceivePortCls>(nullptr, __s("Service.getInfo"));
    Completer<String> completer = <String>make<CompleterCls>();
    receivePort->handler = [=] (String uriString) {
        completer->complete(uriString);
    };
    _getServerInfo(receivePort->sendPort());
    String uriString = await completer->future();
    Uri uri = uriString == nullptr? nullptr : UriCls->parse(uriString);
    receivePort->close();
    return make<ServiceProtocolInfoCls>(uri);
}

Future<ServiceProtocolInfo> ServiceCls::controlWebServer(bool enable, bool silenceOutput) {
    ArgumentErrorCls->checkNotNull(enable, __s("enable"));
    RawReceivePort receivePort = make<RawReceivePortCls>(nullptr, __s("Service.controlWebServer"));
    Completer<String> completer = <String>make<CompleterCls>();
    receivePort->handler = [=] (String uriString) {
        completer->complete(uriString);
    };
    _webServerControl(receivePort->sendPort(), enable, silenceOutput);
    String uriString = await completer->future();
    Uri uri = uriString == nullptr? nullptr : UriCls->parse(uriString);
    receivePort->close();
    return make<ServiceProtocolInfoCls>(uri);
}

String ServiceCls::getIsolateID(Isolate isolate) {
    ArgumentErrorCls->checkNotNull(isolate, __s("isolate"));
    return _getIsolateIDFromSendPort(isolate->controlPort);
}
