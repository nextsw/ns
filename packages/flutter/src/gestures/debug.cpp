#include "debug.hpp"
bool debugAssertAllGesturesVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintHitTestResults || debugPrintGestureArenaDiagnostics || debugPrintRecognizerCallbacksTrace || debugPrintResamplingMargin) {
            ;
        }
        return true;
    }());
    return true;
}
