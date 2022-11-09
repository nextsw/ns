#include "debug.hpp"
bool debugAssertAllSchedulerVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintBeginFrameBanner || debugPrintEndFrameBanner) {
            ;
        }
        return true;
    }());
    return true;
}
