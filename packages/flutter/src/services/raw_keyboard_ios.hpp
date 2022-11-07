#ifndef RAW_KEYBOARD_IOS_H
#define RAW_KEYBOARD_IOS_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


const Map<String, LogicalKeyboardKey> _kIosToLogicalMap;


class RawKeyEventDataIos : RawKeyEventData {
public:
    String characters;

    String charactersIgnoringModifiers;

    int keyCode;

    int modifiers;

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


     RawKeyEventDataIos(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers);

    String keyLabel();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:

    static bool _isUnprintableKey(String label);

    bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

};

#endif