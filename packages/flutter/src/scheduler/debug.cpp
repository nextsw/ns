#include "debug.hpp"
bool debugAssertAllSchedulerVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintBeginFrameBanner || debugPrintEndFrameBanner) {
            throw make<FlutterErrorCls>(reason);
        }
        return true;
    }());
    return true;
}
