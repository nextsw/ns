#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_WINDOWS
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_WINDOWS
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"

int _vkProcessKey;


class RawKeyEventDataWindowsCls : public RawKeyEventDataCls {
public:
    int keyCode;

    int scanCode;

    int characterCodePoint;

    int modifiers;

    static int modifierShift;

    static int modifierLeftShift;

    static int modifierRightShift;

    static int modifierControl;

    static int modifierLeftControl;

    static int modifierRightControl;

    static int modifierAlt;

    static int modifierLeftAlt;

    static int modifierRightAlt;

    static int modifierLeftMeta;

    static int modifierRightMeta;

    static int modifierCaps;

    static int modifierNumLock;

    static int modifierScrollLock;


     RawKeyEventDataWindowsCls(int characterCodePoint, int keyCode, int modifiers, int scanCode);

    virtual String keyLabel();

    virtual PhysicalKeyboardKey physicalKey();

    virtual LogicalKeyboardKey logicalKey();

    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual bool shouldDispatchEvent();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual bool _isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side);

};
using RawKeyEventDataWindows = std::shared_ptr<RawKeyEventDataWindowsCls>;


#endif