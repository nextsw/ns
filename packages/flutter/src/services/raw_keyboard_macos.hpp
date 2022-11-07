#ifndef RAW_KEYBOARD_MACOS_H
#define RAW_KEYBOARD_MACOS_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


int runeToLowerCase(int rune);


class RawKeyEventDataMacOs : RawKeyEventData {
public:
    String characters;

    String charactersIgnoringModifiers;

    int keyCode;

    int modifiers;

    int specifiedLogicalKey;

    static const int modifierCapsLock;

    static const int modifierShift;

    static const int modifierLeftShift;

    static const int modifierRightShift;

    static const int modifierControl;

    static const int modifierLeftControl;

    static const int modifierRightControl;

    static const int modifierOption;

    static const int modifierLeftOption;

    static const int modifierRightOption;

    static const int modifierCommand;

    static const int modifierLeftCommand;

    static const int modifierRightCommand;

    static const int modifierNumericPad;

    static const int modifierHelp;

    static const int modifierFunction;

    static const int deviceIndependentMask;


     RawKeyEventDataMacOs(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers, int specifiedLogicalKey);

    String keyLabel();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    bool shouldDispatchEvent();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:

    bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

    static bool _isUnprintableKey(String label);

};

#endif