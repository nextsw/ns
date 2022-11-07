#ifndef RAW_KEYBOARD_WINDOWS_H
#define RAW_KEYBOARD_WINDOWS_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


const int _vkProcessKey;


class RawKeyEventDataWindows : RawKeyEventData {
public:
    int keyCode;

    int scanCode;

    int characterCodePoint;

    int modifiers;

    static const int modifierShift;

    static const int modifierLeftShift;

    static const int modifierRightShift;

    static const int modifierControl;

    static const int modifierLeftControl;

    static const int modifierRightControl;

    static const int modifierAlt;

    static const int modifierLeftAlt;

    static const int modifierRightAlt;

    static const int modifierLeftMeta;

    static const int modifierRightMeta;

    static const int modifierCaps;

    static const int modifierNumLock;

    static const int modifierScrollLock;


     RawKeyEventDataWindows(int characterCodePoint, int keyCode, int modifiers, int scanCode);

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

};

#endif