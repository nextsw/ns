#ifndef KEYBOARD_MAPS.G_H
#define KEYBOARD_MAPS.G_H
#include <memory>
#include "keyboard_key.g.hpp"

#include "keyboard_key.g.hpp"


const Map<int, LogicalKeyboardKey> kAndroidToLogicalKey;

const Map<int, PhysicalKeyboardKey> kAndroidToPhysicalKey;

const Map<int, LogicalKeyboardKey> kAndroidNumPadMap;

const Map<int, LogicalKeyboardKey> kFuchsiaToLogicalKey;

const Map<int, PhysicalKeyboardKey> kFuchsiaToPhysicalKey;

const Map<int, PhysicalKeyboardKey> kMacOsToPhysicalKey;

const Map<int, LogicalKeyboardKey> kMacOsNumPadMap;

const Map<int, LogicalKeyboardKey> kMacOsFunctionKeyMap;

const Map<int, LogicalKeyboardKey> kMacOsToLogicalKey;

const Map<int, PhysicalKeyboardKey> kIosToPhysicalKey;

const Map<int, LogicalKeyboardKey> kIosNumPadMap;

const Map<int, LogicalKeyboardKey> kIosToLogicalKey;

const Map<int, LogicalKeyboardKey> kGlfwToLogicalKey;

const Map<int, LogicalKeyboardKey> kGlfwNumpadMap;

const Map<int, LogicalKeyboardKey> kGtkToLogicalKey;

const Map<int, LogicalKeyboardKey> kGtkNumpadMap;

const Map<int, PhysicalKeyboardKey> kLinuxToPhysicalKey;

const Map<String, LogicalKeyboardKey> kWebToLogicalKey;

const Map<String, PhysicalKeyboardKey> kWebToPhysicalKey;

const Map<String, LogicalKeyboardKey> kWebNumPadMap;

const Map<String, List<LogicalKeyboardKey>> kWebLocationMap;

const Map<int, LogicalKeyboardKey> kWindowsToLogicalKey;

const Map<int, PhysicalKeyboardKey> kWindowsToPhysicalKey;

const Map<int, LogicalKeyboardKey> kWindowsNumPadMap;


#endif