#include "process.hpp"
Never exit(int code) {
    ArgumentErrorCls->checkNotNull(code, __s("code"));
    if (!_EmbedderConfigCls->_mayExit) {
        throw make<UnsupportedErrorCls>(__s("This embedder disallows calling dart:io's exit()"));
    }
    _ProcessUtilsCls->_exit(code);
}

void exitCode(int code) {
    ArgumentErrorCls->checkNotNull(code, __s("code"));
    _ProcessUtilsCls->_setExitCode(code);
}

int exitCode() {
    return _ProcessUtilsCls->_getExitCode();
}

void sleep(Duration duration) {
    int milliseconds = duration->inMilliseconds();
    if ( < 0) {
        throw make<ArgumentErrorCls>(__s("sleep: duration cannot be negative"));
    }
    if (!_EmbedderConfigCls->_maySleep) {
        throw make<UnsupportedErrorCls>(__s("This embedder disallows calling dart:io's sleep()"));
    }
    _ProcessUtilsCls->_sleep(milliseconds);
}

int pid() {
    return _ProcessUtilsCls->_pid(nullptr);
}

List<ProcessStartMode> ProcessStartModeCls::values() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
}

String ProcessStartModeCls::toString() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_mode];
}

String ProcessSignalCls::toString() {
    return _name;
}

Stream<ProcessSignal> ProcessSignalCls::watch() {
    return _ProcessUtilsCls->_watchSignal(this);
}

String SignalExceptionCls::toString() {
    auto msg = __s("");
    if (osError != nullptr) {
        msg = __s(", osError: %s;");
    }
    return __s("SignalException: %s$%s;");
}

String ProcessExceptionCls::toString() {
    auto args = arguments->join(__s(" "));
    return __s("ProcessException: %s$%s$%s;");
}
