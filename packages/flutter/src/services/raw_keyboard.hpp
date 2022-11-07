#ifndef RAW_KEYBOARD_H
#define RAW_KEYBOARD_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"

#include <io/io.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"
#include "hardware_keyboard.hpp"
#include "keyboard_key.g.hpp"
#include "raw_keyboard_android.hpp"
#include "raw_keyboard_fuchsia.hpp"
#include "raw_keyboard_ios.hpp"
#include "raw_keyboard_linux.hpp"
#include "raw_keyboard_macos.hpp"
#include "raw_keyboard_web.hpp"
#include "raw_keyboard_windows.hpp"
#include "system_channels.hpp"



enum KeyboardSide{
    any,
    left,
    right,
    all,
} // end KeyboardSide

enum ModifierKey{
    controlModifier,
    shiftModifier,
    altModifier,
    metaModifier,
    capsLockModifier,
    numLockModifier,
    scrollLockModifier,
    functionModifier,
    symbolModifier,
} // end ModifierKey

class RawKeyEventData {
public:

     RawKeyEventData();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    bool isControlPressed();

    bool isShiftPressed();

    bool isAltPressed();

    bool isMetaPressed();

    Map<ModifierKey, KeyboardSide> modifiersPressed();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    String keyLabel();

    bool shouldDispatchEvent();

private:

};

class RawKeyEvent {
public:
    String character;

    bool repeat;

    RawKeyEventData data;


     RawKeyEvent(String character, RawKeyEventData data, bool repeat);

    void  fromMessage(Map<String, Object> message);

    bool isKeyPressed(LogicalKeyboardKey key);

    bool isControlPressed();

    bool isShiftPressed();

    bool isAltPressed();

    bool isMetaPressed();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RawKeyDownEvent : RawKeyEvent {
public:

     RawKeyDownEvent(Unknown, Unknown, Unknown);

private:

};

class RawKeyUpEvent : RawKeyEvent {
public:

     RawKeyUpEvent(Unknown, Unknown);

private:

};

class RawKeyboard {
public:
    static RawKeyboard instance;


    void addListener(ValueChanged<RawKeyEvent> listener);

    void removeListener(ValueChanged<RawKeyEvent> listener);

    RawKeyEventHandler keyEventHandler();

    void  keyEventHandler(RawKeyEventHandler handler);

    bool handleRawKeyEvent(RawKeyEvent event);

    Set<LogicalKeyboardKey> keysPressed();

    Set<PhysicalKeyboardKey> physicalKeysPressed();

    LogicalKeyboardKey lookUpLayout(PhysicalKeyboardKey physicalKey);

    void clearKeysPressed();

private:
    List<ValueChanged<RawKeyEvent>> _listeners;

    RawKeyEventHandler _cachedKeyEventHandler;

    KeyMessageHandler _cachedKeyMessageHandler;

    static Map<_ModifierSidePair, Set<PhysicalKeyboardKey>> _modifierKeyMap;

    static Map<PhysicalKeyboardKey, LogicalKeyboardKey> _allModifiersExceptFn;

    static Map<PhysicalKeyboardKey, LogicalKeyboardKey> _allModifiers;

    Map<PhysicalKeyboardKey, LogicalKeyboardKey> _keysPressed;


    void  _();

    void _synchronizeModifiers(RawKeyEvent event);

};

class _ModifierSidePair {
public:
    ModifierKey modifier;

    KeyboardSide side;


    bool ==(Object other);

    int hashCode();

private:

     _ModifierSidePair(ModifierKey modifier, KeyboardSide side);

};

#endif