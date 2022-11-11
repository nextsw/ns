#include "debug.hpp"
bool debugAssertAllServicesVarsUnset(String reason) {
    assert([=] () {
        if (debugKeyEventSimulatorTransitModeOverride != nullptr) {
            throw make<FlutterErrorCls>(reason);
        }
        if (debugProfilePlatformChannels) {
            throw make<FlutterErrorCls>(reason);
        }
        return true;
    }());
    return true;
}
