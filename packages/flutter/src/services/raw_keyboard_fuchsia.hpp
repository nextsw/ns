#ifndef RAW_KEYBOARD_FUCHSIA_H
#define RAW_KEYBOARD_FUCHSIA_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"



class RawKeyEventDataFuchsia : RawKeyEventData {
public:
    int hidUsage;

    int codePoint;

    int modifiers;

    static const int modifierNone;

    static const int modifierCapsLock;

    static const int modifierLeftShift;

    static const int modifierRightShift;

    static const int modifierShift;

    static const int modifierLeftControl;

    static const int modifierRightControl;

    static const int modifierControl;

    static const int modifierLeftAlt;

    static const int modifierRightAlt;

    static const int modifierAlt;

    static const int modifierLeftMeta;

    static const int modifierRightMeta;

    static const int modifierMeta;


     RawKeyEventDataFuchsia(int codePoint, int hidUsage, int modifiers);

    String keyLabel();

    LogicalKeyboardKey logicalKey();

    PhysicalKeyboardKey physicalKey();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:

    bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

};

#endif