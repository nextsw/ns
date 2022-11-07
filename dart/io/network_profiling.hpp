#ifndef NETWORK_PROFILING_H
#define NETWORK_PROFILING_H
#include <memory>



const int _versionMajor;

const int _versionMinor;

const String _tcpSocket;

const String _udpSocket;


class _NetworkProfiling {
public:

    static String getVersion();

private:
    static const auto  _kGetHttpEnableTimelineLogging;

    static const auto  _kSetHttpEnableTimelineLogging;

    static const auto  _kHttpEnableTimelineLogging;

    static const auto  _kGetHttpProfileRPC;

    static const auto  _kGetHttpProfileRequestRPC;

    static const auto  _kClearHttpProfileRPC;

    static const auto  _kClearSocketProfileRPC;

    static const auto  _kGetSocketProfileRPC;

    static const auto  _kSocketProfilingEnabledRPC;

    static const auto  _kPauseSocketProfilingRPC;

    static const auto  _kStartSocketProfilingRPC;

    static const auto  _kGetVersionRPC;


    static void _registerServiceExtension();

    static Future<ServiceExtensionResponse> _serviceExtensionHandler(String method, Map<String, String> parameters);

};
String _success();

String _invalidArgument(String argument, dynamic value);

String _missingArgument(String argument);

String _getHttpEnableTimelineLogging();

String _setHttpEnableTimelineLogging(Map<String, String> parameters);

String _getHttpProfileRequest(Map<String, String> parameters);

String _socketProfilingEnabled(Map<String, String> parameters);


class _SocketProfile {
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
    static const auto  _kType;

    static bool _enableSocketProfiling;

    static Map<int, _SocketStatistic> _idToSocketStatistic;


};

enum _SocketProfileType{
    startTime,
    endTime,
    address,
    port,
    socketType,
    readBytes,
    writeBytes,
} // end _SocketProfileType

class _SocketStatistic {
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


    Map<String, dynamic> toMap();

private:

     _SocketStatistic(int id);

    void _setIfNotNull(Map<String, dynamic> json, String key, Object value);

};

#endif