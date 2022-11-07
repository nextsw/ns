#include "process.hpp"
Never exit(int code) {
    ArgumentError.checkNotNull(code, "code");
    if (!_EmbedderConfig._mayExit) {
        ;
    }
    _ProcessUtils._exit(code);
}

void exitCode(int code) {
    ArgumentError.checkNotNull(code, "code");
    _ProcessUtils._setExitCode(code);
}

int exitCode() {
    return _ProcessUtils._getExitCode();
}

void sleep(Duration duration) {
    int milliseconds = duration.inMilliseconds;
    if ( < 0) {
        ;
    }
    if (!_EmbedderConfig._maySleep) {
        ;
    }
    _ProcessUtils._sleep(milliseconds);
}

int pid() {
    return _ProcessUtils._pid(nullptr);
}

List<ProcessStartMode> ProcessStartMode::values() {
    return const ;
}

String ProcessStartMode::toString() {
    return const [_mode];
}

String ProcessSignal::toString() {
    return _name;
}

Stream<ProcessSignal> ProcessSignal::watch() {
    return _ProcessUtils._watchSignal(this);
}

String SignalException::toString() {
    auto msg = "";
    if (osError != nullptr) {
        msg = ", osError: $osError";
    }
    return "SignalException: $message$msg";
}

String ProcessException::toString() {
    auto args = arguments.join(" ");
    return "ProcessException: $message\n  Command: $executable $args";
}
