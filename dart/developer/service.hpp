#ifndef DART_DEVELOPER_SERVICE
#define DART_DEVELOPER_SERVICE
#include <base.hpp>

#include <dart/core/core.hpp>


class ServiceProtocolInfoCls : public ObjectCls {
public:
    int majorVersion;

    int minorVersion;

    Uri serverUri;


    virtual Uri serverWebSocketUri();

     ServiceProtocolInfoCls(Uri serverUri);
    virtual String toString();

private:

};
using ServiceProtocolInfo = std::shared_ptr<ServiceProtocolInfoCls>;

class ServiceCls : public ObjectCls {
public:

    static Future<ServiceProtocolInfo> getInfo();

    static Future<ServiceProtocolInfo> controlWebServer(bool enable, bool silenceOutput);

    static String getIsolateID(Isolate isolate);

private:

};
using Service = std::shared_ptr<ServiceCls>;
void _getServerInfo(SendPort sendPort);
void _webServerControl(SendPort sendPort, bool enable, bool silenceOutput);
int _getServiceMajorVersion();
int _getServiceMinorVersion();
String _getIsolateIDFromSendPort(SendPort sendPort);


#endif