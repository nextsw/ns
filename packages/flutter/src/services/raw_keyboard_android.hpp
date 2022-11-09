#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_ANDROID
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_ANDROID
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"

int _kCombiningCharacterMask;


class RawKeyEventDataAndroidCls : public RawKeyEventDataCls {
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

    static int modifierNone;

    static int modifierAlt;

    static int modifierLeftAlt;

    static int modifierRightAlt;

    static int modifierShift;

    static int modifierLeftShift;

    static int modifierRightShift;

    static int modifierSym;

    static int modifierFunction;

    static int modifierControl;

    static int modifierLeftControl;

    static int modifierRightControl;

    static int modifierMeta;

    static int modifierLeftMeta;

    static int modifierRightMeta;

    static int modifierCapsLock;

    static int modifierNumLock;

    static int modifierScrollLock;


     RawKeyEventDataAndroidCls(int codePoint, int deviceId, int eventSource, int flags, int keyCode, int metaState, int plainCodePoint, int productId, int repeatCount, int scanCode, int vendorId);

    virtual String keyLabel();

    virtual PhysicalKeyboardKey physicalKey();

    virtual LogicalKeyboardKey logicalKey();

    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    static int _sourceJoystick;


    virtual bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

};
using RawKeyEventDataAndroid = std::shared_ptr<RawKeyEventDataAndroidCls>;


#endif