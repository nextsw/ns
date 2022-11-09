#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_MACOS
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_MACOS
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"

int runeToLowerCase(int rune);


class RawKeyEventDataMacOsCls : public RawKeyEventDataCls {
public:
    String characters;

    String charactersIgnoringModifiers;

    int keyCode;

    int modifiers;

    int specifiedLogicalKey;

    static int modifierCapsLock;

    static int modifierShift;

    static int modifierLeftShift;

    static int modifierRightShift;

    static int modifierControl;

    static int modifierLeftControl;

    static int modifierRightControl;

    static int modifierOption;

    static int modifierLeftOption;

    static int modifierRightOption;

    static int modifierCommand;

    static int modifierLeftCommand;

    static int modifierRightCommand;

    static int modifierNumericPad;

    static int modifierHelp;

    static int modifierFunction;

    static int deviceIndependentMask;


     RawKeyEventDataMacOsCls(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers, int specifiedLogicalKey);

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

    static bool _isUnprintableKey(String label);

};
using RawKeyEventDataMacOs = std::shared_ptr<RawKeyEventDataMacOsCls>;


#endif