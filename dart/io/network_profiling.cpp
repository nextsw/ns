#include "network_profiling.hpp"
String _NetworkProfilingCls::getVersion() {
    return json->encode(list1);
}

void _NetworkProfilingCls::_registerServiceExtension() {
    map1.set(__s("type"), __s("Version"));map1.set(__s("major"), _versionMajor);map1.set(__s("minor"), _versionMinor);registerExtension(_kGetHttpEnableTimelineLogging, _serviceExtensionHandler);
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

String _invalidArgument(String argument, Object value) {
    return __sf("Value for parameter '%s' is not valid: %s", argument, value);
}

String _missingArgument(String argument) {
    return __sf("Parameter '%s' is required", argument);
}

String _getHttpEnableTimelineLogging() {
    return json->encode(list1);
}

String _setHttpEnableTimelineLogging(Map<String, String> parameters) {
    map1.set(__s("type"), __s("Success"));map1.set(__s("type"), __s("HttpTimelineLoggingState"));map1.set(__s("enabled"), HttpClientCls::enableTimelineLogging);String kEnable = __s("enable");
    if (!parameters->containsKey(kEnable)) {
        throw _missingArgument(kEnable);
    }
    auto enable = parameters[kEnable]!->toLowerCase();
    if (enable != __s("true") && enable != __s("false")) {
        throw _invalidArgument(kEnable, enable);
    }
    HttpClientCls::enableTimelineLogging = enable == __s("true");
    return _success();
}

String _getHttpProfileRequest(Map<String, String> parameters) {
    if (!parameters->containsKey(__s("id"))) {
        throw _missingArgument(__s("id"));
    }
    auto id = intValue->tryParse(parameters[__s("id")]!);
    if (id == nullptr) {
        throw _invalidArgument(__s("id"), parameters[__s("id")]!);
    }
    auto request = HttpProfilerCls->getHttpProfileRequest(id);
    if (request == nullptr) {
        throw __sf("Unable to find request with id: '%s'", id);
    }
    return json->encode(request->toJson(false));
}

String _socketProfilingEnabled(Map<String, String> parameters) {
    String kEnabled = __s("enabled");
    if (parameters->containsKey(kEnabled)) {
        auto enable = parameters[kEnabled]!->toLowerCase();
        if (enable != __s("true") && enable != __s("false")) {
            throw _invalidArgument(kEnabled, enable);
        }
        enable == __s("true")? _SocketProfileCls->start() : _SocketProfileCls->pause();
    }
    map1.set(__s("type"), __s("SocketProfilingState"));map1.set(__s("enabled"), _SocketProfileCls::enableSocketProfiling);return json->encode(list1);
}

void _SocketProfileCls::enableSocketProfiling(bool enabled) {
    if (enabled != _enableSocketProfiling) {
            map1.set(__s("isolateId"), ServiceCls->getIsolateID(IsolateCls::current));    map1.set(__s("enabled"), enabled);postEvent(__s("SocketProfilingStateChange"), list1);
        _enableSocketProfiling = enabled;
    }
}

bool _SocketProfileCls::enableSocketProfiling() {
    return _enableSocketProfiling;
}

String _SocketProfileCls::toJson() {
    return json->encode(list1);
}

void _SocketProfileCls::collectNewSocket(int id, String type, InternetAddress addr, int port) {
    map1.set(__s("type"), _kType);map1.set(__s("sockets"), _idToSocketStatistic->values->map([=] (Unknown  f) {        f->toMap();    })->toList());_SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::startTime);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::socketType, type);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::address, addr);
    _SocketProfileCls->collectStatistic(id, _SocketProfileTypeCls::port, port);
}

void _SocketProfileCls::collectStatistic(int id, _SocketProfileType type, Object object) {
    if (!_enableSocketProfiling) {
        return;
    }
    if (!_idToSocketStatistic->containsKey(id) && type != _SocketProfileTypeCls::startTime) {
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

Map<String, Object> _SocketStatisticCls::toMap() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("id"), id);auto map = list1;
    _setIfNotNull(map, __s("startTime"), startTime);
    _setIfNotNull(map, __s("endTime"), endTime);
    _setIfNotNull(map, __s("address"), address);
    _setIfNotNull(map, __s("port"), port);
    _setIfNotNull(map, __s("socketType"), socketType);
    _setIfNotNull(map, __s("readBytes"), readBytes);
    _setIfNotNull(map, __s("writeBytes"), writeBytes);
    _setIfNotNull(map, __s("lastWriteTime"), lastWriteTime);
    _setIfNotNull(map, __s("lastReadTime"), lastReadTime);
    return map;
}

void _SocketStatisticCls::_setIfNotNull(Map<String, Object> json, String key, Object value) {
    if (value == nullptr) {
        return;
    }
    json[key] = value;
}
