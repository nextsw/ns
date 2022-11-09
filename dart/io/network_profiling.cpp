#include "network_profiling.hpp"
String _NetworkProfilingCls::getVersion() {
    return json->encode(list1);
}

void _NetworkProfilingCls::_registerServiceExtension() {
    map1.set("type", "Version");map1.set("major", _versionMajor);map1.set("minor", _versionMinor);registerExtension(_kGetHttpEnableTimelineLogging, _serviceExtensionHandler);
    registerExtension(_kSetHttpEnableTimelineLogging, _serviceExtensionHandler);
    registerExtension(_kHttpEnableTimelineLogging, _serviceExtensionHandler);
    registerExtension(_kGetSocketProfileRPC, _serviceExtensionHandler);
    registerExtension(_kStartSocketProfilingRPC, _serviceExtensionHandler);
    registerExtension(_kPauseSocketProfilingRPC, _serviceExtensionHandler);
    registerExtension(_kSocketProfilingEnabledRPC, _serviceExtensionHandler);
    registerExtension(_kClearSocketProfileRPC, _serviceExtensionHandler);
    registerExtension(_kGetVersionRPC, _serviceExtensionHandler);
    registerExtension(_kGetHttpProfileRPC, _serviceExtensionHandler);
    registerExtension(_kGetHttpProfileRequestRPC, _serviceExtensionHandler);
    registerExtension(_kClearHttpProfileRPC, _serviceExtensionHandler);
}

Future<ServiceExtensionResponse> _NetworkProfilingCls::_serviceExtensionHandler(String method, Map<String, String> parameters) {
    try {
        String responseJson;
        ;
        return FutureCls->value(ServiceExtensionResponseCls->result(responseJson));
    } catch (Unknown errorMessage) {
        return FutureCls->value(ServiceExtensionResponseCls->error(ServiceExtensionResponseCls::invalidParams, errorMessage->toString()));
    };
}

String _success() {
    return json->encode(list1);
}

String _invalidArgument(String argument, dynamic value) {
    return "Value for parameter '$argument' is not valid: $value";
}

String _missingArgument(String argument) {
    return "Parameter '$argument' is required";
}

String _getHttpEnableTimelineLogging() {
    return json->encode(list1);
}

String _setHttpEnableTimelineLogging(Map<String, String> parameters) {
    map1.set("type", "Success");map1.set("type", "HttpTimelineLoggingState");map1.set("enabled", HttpClientCls::enableTimelineLogging);String kEnable = "enable";
    if (!parameters->containsKey(kEnable)) {
        ;
    }
    Unknown enable = parameters[kEnable]!->toLowerCase();
    if (enable != "true" && enable != "false") {
        ;
    }
    HttpClientCls::enableTimelineLogging = enable == "true";
    return _success();
}

String _getHttpProfileRequest(Map<String, String> parameters) {
    if (!parameters->containsKey("id")) {
        ;
    }
    Unknown id = intValue->tryParse(parameters["id"]!);
    if (id == nullptr) {
        ;
    }
    Unknown request = HttpProfilerCls->getHttpProfileRequest(id);
    if (request == nullptr) {
        ;
    }
    return json->encode(request->toJson(false));
}

String _socketProfilingEnabled(Map<String, String> parameters) {
    String kEnabled = "enabled";
    if (parameters->containsKey(kEnabled)) {
        Unknown enable = parameters[kEnabled]!->toLowerCase();
        if (enable != "true" && enable != "false") {
            ;
        }
        enable == "true"? _SocketProfileCls->start() : _SocketProfileCls->pause();
    }
    map1.set("type", "SocketProfilingState");map1.set("enabled", _SocketProfileCls::enableSocketProfiling);return json->encode(list1);
}

void _SocketProfileCls::enableSocketProfiling(bool enabled) {
    if (enabled != _enableSocketProfiling) {
            map1.set("isolateId", ServiceCls->getIsolateID(IsolateCls::current));    map1.set("enabled", enabled);postEvent("SocketProfilingStateChange", list1);
        _enableSocketProfiling = enabled;
    }
}

bool _SocketProfileCls::enableSocketProfiling() {
    return _enableSocketProfiling;
}

String _SocketProfileCls::toJson() {
    return json->encode(list1);
}

void _SocketProfileCls::collectNewSocket(InternetAddress addr, int id, int port, String type) {
    map1.set("type", _kType);map1.set("sockets", _idToSocketStatistic->values->map([=] (Unknown  f)     {        f->toMap();    })->toList());_SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::startTime);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::socketType, type);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::address, addr);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::port, port);
}

void _SocketProfileCls::collectStatistic(int id, dynamic object, _SocketProfileType type) {
    if (!_enableSocketProfiling) {
        return;
    }
    if (!_idToSocketStatistic->containsKey(id) && type != _SocketProfileTypeCls::startTime)     {
        return;
    }
    _SocketStatistic stats = _idToSocketStatistic[id] ??= make<_SocketStatisticCls>(id);
    ;
}

String _SocketProfileCls::start() {
    enableSocketProfiling = true;
    return _success();
}

String _SocketProfileCls::pause() {
    enableSocketProfiling = false;
    return _success();
}

String _SocketProfileCls::clear() {
    _idToSocketStatistic->clear();
    return _success();
}

Map<String, dynamic> _SocketStatisticCls::toMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("id", id);Unknown map = list1;
    _setIfNotNull(map, "startTime", startTime);
    _setIfNotNull(map, "endTime", endTime);
    _setIfNotNull(map, "address", address);
    _setIfNotNull(map, "port", port);
    _setIfNotNull(map, "socketType", socketType);
    _setIfNotNull(map, "readBytes", readBytes);
    _setIfNotNull(map, "writeBytes", writeBytes);
    _setIfNotNull(map, "lastWriteTime", lastWriteTime);
    _setIfNotNull(map, "lastReadTime", lastReadTime);
    return map;
}

void _SocketStatisticCls::_setIfNotNull(Map<String, dynamic> json, String key, Object value) {
    if (value == nullptr)     {
        return;
    }
    json[key] = value;
}
