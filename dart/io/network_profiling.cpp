#include "network_profiling.hpp"
String _NetworkProfiling::getVersion() {
    return json.encode();
}

void _NetworkProfiling::_registerServiceExtension() {
    registerExtension(_kGetHttpEnableTimelineLogging, _serviceExtensionHandler);
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

Future<ServiceExtensionResponse> _NetworkProfiling::_serviceExtensionHandler(String method, Map<String, String> parameters) {
    ;
}

String _success() {
    return json.encode();
}

String _invalidArgument(String argument, dynamic value) {
    return "Value for parameter '$argument' is not valid: $value";
}

String _missingArgument(String argument) {
    return "Parameter '$argument' is required";
}

String _getHttpEnableTimelineLogging() {
    return json.encode();
}

String _setHttpEnableTimelineLogging(Map<String, String> parameters) {
    String kEnable = "enable";
    if (!parameters.containsKey(kEnable)) {
        ;
    }
    Unknown enable = parameters[kEnable]!.toLowerCase();
    if (enable != "true" && enable != "false") {
        ;
    }
    HttpClient.enableTimelineLogging = enable == "true";
    return _success();
}

String _getHttpProfileRequest(Map<String, String> parameters) {
    if (!parameters.containsKey("id")) {
        ;
    }
    Unknown id = int.tryParse(parameters["id"]!);
    if (id == nullptr) {
        ;
    }
    Unknown request = HttpProfiler.getHttpProfileRequest(id);
    if (request == nullptr) {
        ;
    }
    return json.encode(request.toJson(false));
}

String _socketProfilingEnabled(Map<String, String> parameters) {
    String kEnabled = "enabled";
    if (parameters.containsKey(kEnabled)) {
        Unknown enable = parameters[kEnabled]!.toLowerCase();
        if (enable != "true" && enable != "false") {
            ;
        }
        enable == "true"? _SocketProfile.start() : _SocketProfile.pause();
    }
    return json.encode();
}

void _SocketProfile::enableSocketProfiling(bool enabled) {
    if (enabled != _enableSocketProfiling) {
        postEvent("SocketProfilingStateChange", );
        _enableSocketProfiling = enabled;
    }
}

bool _SocketProfile::enableSocketProfiling() {
    return _enableSocketProfiling;
}

String _SocketProfile::toJson() {
    return json.encode();
}

void _SocketProfile::collectNewSocket(InternetAddress addr, int id, int port, String type) {
    _SocketProfile.collectStatistic(id, _SocketProfileType.startTime);
    _SocketProfile.collectStatistic(id, _SocketProfileType.socketType, type);
    _SocketProfile.collectStatistic(id, _SocketProfileType.address, addr);
    _SocketProfile.collectStatistic(id, _SocketProfileType.port, port);
}

void _SocketProfile::collectStatistic(int id, dynamic object, _SocketProfileType type) {
    if (!_enableSocketProfiling) {
        return;
    }
    if (!_idToSocketStatistic.containsKey(id) && type != _SocketProfileType.startTime)     {
        return;
    }
    _SocketStatistic stats = _idToSocketStatistic[id] ??= _SocketStatistic(id);
    ;
}

String _SocketProfile::start() {
    enableSocketProfiling = true;
    return _success();
}

String _SocketProfile::pause() {
    enableSocketProfiling = false;
    return _success();
}

String _SocketProfile::clear() {
    _idToSocketStatistic.clear();
    return _success();
}

Map<String, dynamic> _SocketStatistic::toMap() {
    Unknown map = ;
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

void _SocketStatistic::_setIfNotNull(Map<String, dynamic> json, String key, Object value) {
    if (value == nullptr)     {
        return;
    }
    json[key] = value;
}
