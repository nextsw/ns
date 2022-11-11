#include "debug.hpp"
bool debugAssertAllFoundationVarsUnset(String reason, DebugPrintCallback debugPrintOverride) {
    assert([=] () {
        if (debugPrint != debugPrintOverride || debugDefaultTargetPlatformOverride != nullptr || debugDoublePrecision != nullptr || debugBrightnessOverride != nullptr) {
            throw make<FlutterErrorCls>(reason);
        }
        return true;
    }());
    return true;
}

template<typename T>
Future<T> debugInstrumentAction(String description, std::function<Future<T>()> action) {
    bool instrument = false;
    assert([=] () {
        instrument = debugInstrumentationEnabled;
        return true;
    }());
    if (instrument) {
            auto _c1 = make<StopwatchCls>();    _c1.start();Stopwatch stopwatch = _c1;
        try {
            return await action();
        } finally {
            stopwatch->stop();
            debugPrint(__s("Action "$description" took ${stopwatch.elapsed}"));
        };
    } else {
        return action();
    }
}

String debugFormatDouble(double value) {
    if (value == nullptr) {
        return __s("null");
    }
    if (debugDoublePrecision != nullptr) {
        return value->toStringAsPrecision(debugDoublePrecision!);
    }
    return value->toStringAsFixed(1);
}
