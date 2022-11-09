#include "natives.hpp"
void DartPluginRegistrantCls::ensureInitialized() {
    if (!_wasInitialized) {
        _wasInitialized = true;
        _ensureInitialized();
    }
}

void _print(String arg) {
    _LoggerCls->_printString(arg);
}

void _printDebug(String arg) {
    _LoggerCls->_printDebugString(arg);
}

Future<ServiceExtensionResponse> _scheduleFrame(String method, Map<String, String> parameters) {
    PlatformDispatcherCls::instance->scheduleFrame();
    Map<String, String> map1 = make<MapCls<>>();map1.set("type", "Success");return developer->ServiceExtensionResponseCls->result(json->encode(list1));
}

void _setupHooks() {
    assert([=] () {
        developer->registerExtension("ext.ui.window.scheduleFrame", _scheduleFrame);
        return true;
    }());
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
