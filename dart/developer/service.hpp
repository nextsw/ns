#ifndef SERVICE_H
#define SERVICE_H
#include <memory>




class ServiceProtocolInfo {
public:
    int majorVersion;

    int minorVersion;

    Uri serverUri;


    Uri serverWebSocketUri();

     ServiceProtocolInfo(Uri serverUri);

    String toString();

private:

};

class Service {
public:

    static Future<ServiceProtocolInfo> getInfo();

    static Future<ServiceProtocolInfo> controlWebServer(bool enable, bool silenceOutput);

    static String getIsolateID(Isolate isolate);

private:

};
external void _getServerInfo(SendPort sendPort);

external void _webServerControl(bool enable, SendPort sendPort, bool silenceOutput);

external int _getServiceMajorVersion();

external int _getServiceMinorVersion();

external String _getIsolateIDFromSendPort(SendPort sendPort);


#endif