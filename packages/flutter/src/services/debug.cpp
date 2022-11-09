#include "debug.hpp"
bool debugAssertAllServicesVarsUnset(String reason) {
    assert([=] () {
        if (debugKeyEventSimulatorTransitModeOverride != nullptr) {
            ;
        }
        if (debugProfilePlatformChannels) {
            ;
        }
        return true;
    }());
    return true;
}
