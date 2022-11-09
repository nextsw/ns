#ifndef PACKAGES_FLUTTER_SRC_SERVICES_DEBUG
#define PACKAGES_FLUTTER_SRC_SERVICES_DEBUG
#include <base.hpp>
#include "hardware_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "hardware_keyboard.hpp"

KeyDataTransitMode debugKeyEventSimulatorTransitModeOverride;

bool debugProfilePlatformChannels;

bool debugAssertAllServicesVarsUnset(String reason);



#endif