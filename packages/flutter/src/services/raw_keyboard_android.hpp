#ifndef RAW_KEYBOARD_ANDROID_H
#define RAW_KEYBOARD_ANDROID_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


const int _kCombiningCharacterMask;


class RawKeyEventDataAndroid : RawKeyEventData {
public:
    int flags;

    int codePoint;

    int plainCodePoint;

    int keyCode;

    int scanCode;

    int metaState;

    int eventSource;

    int vendorId;

    int productId;

    int deviceId;

    int repeatCount;

    static const int modifierNone;

    static const int modifierAlt;

    static const int modifierLeftAlt;

    static const int modifierRightAlt;

    static const int modifierShift;

    static const int modifierLeftShift;

    static const int modifierRightShift;

    static const int modifierSym;

    static const int modifierFunction;

    static const int modifierControl;

    static const int modifierLeftControl;

    static const int modifierRightControl;

    static const int modifierMeta;

    static const int modifierLeftMeta;

    static const int modifierRightMeta;

    static const int modifierCapsLock;

    static const int modifierNumLock;

    static const int modifierScrollLock;


     RawKeyEventDataAndroid(int codePoint, int deviceId, int eventSource, int flags, int keyCode, int metaState, int plainCodePoint, int productId, int repeatCount, int scanCode, int vendorId);

    String keyLabel();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:
    static const int _sourceJoystick;


    bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

};

#endif