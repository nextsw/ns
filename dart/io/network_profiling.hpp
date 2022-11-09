#ifndef DART_IO_NETWORK_PROFILING
#define DART_IO_NETWORK_PROFILING
#include <base.hpp>

#include <dart/core/core.hpp>

int _versionMajor;

int _versionMinor;

String _tcpSocket;

String _udpSocket;


class _NetworkProfilingCls : public ObjectCls {
public:

    static String getVersion();

private:
    static auto  _kGetHttpEnableTimelineLogging;

    static auto  _kSetHttpEnableTimelineLogging;

    static auto  _kHttpEnableTimelineLogging;

    static auto  _kGetHttpProfileRPC;

    static auto  _kGetHttpProfileRequestRPC;

    static auto  _kClearHttpProfileRPC;

    static auto  _kClearSocketProfileRPC;

    static auto  _kGetSocketProfileRPC;

    static auto  _kSocketProfilingEnabledRPC;

    static auto  _kPauseSocketProfilingRPC;

    static auto  _kStartSocketProfilingRPC;

    static auto  _kGetVersionRPC;


    static void _registerServiceExtension();

    static Future<ServiceExtensionResponse> _serviceExtensionHandler(String method, Map<String, String> parameters);

};
using _NetworkProfiling = std::shared_ptr<_NetworkProfilingCls>;
String _success();

String _invalidArgument(String argument, dynamic value);

String _missingArgument(String argument);

String _getHttpEnableTimelineLogging();

String _setHttpEnableTimelineLogging(Map<String, String> parameters);

String _getHttpProfileRequest(Map<String, String> parameters);

String _socketProfilingEnabled(Map<String, String> parameters);


class _SocketProfileCls : public ObjectCls {
public:

    static void  enableSocketProfiling(bool enabled);

    static bool enableSocketProfiling();

    static String toJson();

    static void collectNewSocket(InternetAddress addr, int id, int port, String type);

    static void collectStatistic(int id, dynamic object, _SocketProfileType type);

    static String start();

    static String pause();

    static String clear();

private:
    static auto  _kType;

    static bool _enableSocketProfiling;

    static Map<int, _SocketStatistic> _idToSocketStatistic;


};
using _SocketProfile = std::shared_ptr<_SocketProfileCls>;

enum _SocketProfileType{
    startTime,
    endTime,
    address,
    port,
    socketType,
    readBytes,
    writeBytes,
} // end _SocketProfileType

class _SocketStatisticCls : public ObjectCls {
public:
    int id;

    int startTime;

    int endTime;

    String address;

    int port;

    String socketType;

    int readBytes;

    int writeBytes;

    int lastWriteTime;

    int lastReadTime;


    virtual Map<String, dynamic> toMap();

private:

     _SocketStatisticCls(int id);
    virtual void _setIfNotNull(Map<String, dynamic> json, String key, Object value);

};
using _SocketStatistic = std::shared_ptr<_SocketStatisticCls>;


#endif