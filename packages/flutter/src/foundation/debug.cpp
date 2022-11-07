#include "debug.hpp"
bool debugAssertAllFoundationVarsUnset(DebugPrintCallback debugPrintOverride, String reason) {
    assert(());
    return true;
}

Future<T> debugInstrumentAction<T>(FunctionType action, String description) {
    bool instrument = false;
    assert(());
    if (instrument) {
        Stopwatch stopwatch = ;
        ;
    } else {
        return action();
    }
}

String debugFormatDouble(double value) {
    if (value == nullptr) {
        return "null";
    }
    if (debugDoublePrecision != nullptr) {
        return value.toStringAsPrecision(debugDoublePrecision!);
    }
    return value.toStringAsFixed(1);
}
