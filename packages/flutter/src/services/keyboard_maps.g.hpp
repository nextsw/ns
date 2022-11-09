#ifndef PACKAGES_FLUTTER_SRC_SERVICES_KEYBOARD_MAPS.G
#define PACKAGES_FLUTTER_SRC_SERVICES_KEYBOARD_MAPS.G
#include <base.hpp>
#include "keyboard_key.g.hpp"

#include <dart/core/core.hpp>
#include "keyboard_key.g.hpp"

Map<int, LogicalKeyboardKey> kAndroidToLogicalKey;

Map<int, PhysicalKeyboardKey> kAndroidToPhysicalKey;

Map<int, LogicalKeyboardKey> kAndroidNumPadMap;

Map<int, LogicalKeyboardKey> kFuchsiaToLogicalKey;

Map<int, PhysicalKeyboardKey> kFuchsiaToPhysicalKey;

Map<int, PhysicalKeyboardKey> kMacOsToPhysicalKey;

Map<int, LogicalKeyboardKey> kMacOsNumPadMap;

Map<int, LogicalKeyboardKey> kMacOsFunctionKeyMap;

Map<int, LogicalKeyboardKey> kMacOsToLogicalKey;

Map<int, PhysicalKeyboardKey> kIosToPhysicalKey;

Map<int, LogicalKeyboardKey> kIosNumPadMap;

Map<int, LogicalKeyboardKey> kIosToLogicalKey;

Map<int, LogicalKeyboardKey> kGlfwToLogicalKey;

Map<int, LogicalKeyboardKey> kGlfwNumpadMap;

Map<int, LogicalKeyboardKey> kGtkToLogicalKey;

Map<int, LogicalKeyboardKey> kGtkNumpadMap;

Map<int, PhysicalKeyboardKey> kLinuxToPhysicalKey;

Map<String, LogicalKeyboardKey> kWebToLogicalKey;

Map<String, PhysicalKeyboardKey> kWebToPhysicalKey;

Map<String, LogicalKeyboardKey> kWebNumPadMap;

Map<String, List<LogicalKeyboardKey>> kWebLocationMap;

Map<int, LogicalKeyboardKey> kWindowsToLogicalKey;

Map<int, PhysicalKeyboardKey> kWindowsToPhysicalKey;

Map<int, LogicalKeyboardKey> kWindowsNumPadMap;



#endif