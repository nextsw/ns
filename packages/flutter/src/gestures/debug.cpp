#include "debug.hpp"
bool debugAssertAllGesturesVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintHitTestResults || debugPrintGestureArenaDiagnostics || debugPrintRecognizerCallbacksTrace || debugPrintResamplingMargin) {
            throw make<FlutterErrorCls>(reason);
        }
        return true;
    }());
    return true;
}
