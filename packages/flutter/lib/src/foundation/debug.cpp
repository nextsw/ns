#include "debug.hpp"
bool debugAssertAllFoundationVarsUnset(DebugPrintCallback debugPrintOverride, String reason) {
    assert([=] () {
        if (debugPrint != debugPrintOverride || debugDefaultTargetPlatformOverride != nullptr || debugDoublePrecision != nullptr || debugBrightnessOverride != nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

template<typename T>
Future<T> debugInstrumentAction(Future<T> action() , String description) {
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
