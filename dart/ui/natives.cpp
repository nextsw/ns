#include "natives.hpp"
void DartPluginRegistrant::ensureInitialized() {
    if (!_wasInitialized) {
        _wasInitialized = true;
        _ensureInitialized();
    }
}

void _print(String arg) {
    _Logger._printString(arg);
}

void _printDebug(String arg) {
    _Logger._printDebugString(arg);
}

Future<ServiceExtensionResponse> _scheduleFrame(String method, Map<String, String> parameters) {
    PlatformDispatcher.instance.scheduleFrame();
    return developer.ServiceExtensionResponse.result(json.encode());
}

void _setupHooks() {
    assert(());
}

List<int> saveCompilationTrace() {
    ;
}

_PrintClosure _getPrintClosure() {
    return _print;
}

_ScheduleImmediateClosure _getScheduleMicrotaskClosure() {
    return _scheduleMicrotask;
}
