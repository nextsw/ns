#ifndef DEBUG_H
#define DEBUG_H
#include <memory>
#include "hardware_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "hardware_keyboard.hpp"


KeyDataTransitMode debugKeyEventSimulatorTransitModeOverride;

bool debugProfilePlatformChannels;

bool debugAssertAllServicesVarsUnset(String reason);


#endif