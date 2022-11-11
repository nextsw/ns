#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_IOS
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_IOS
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"

Map<String, LogicalKeyboardKey> _kIosToLogicalMap;


class RawKeyEventDataIosCls : public RawKeyEventDataCls {
public:
    String characters;

    String charactersIgnoringModifiers;

    int keyCode;

    int modifiers;

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


     RawKeyEventDataIosCls(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers);

    virtual String keyLabel();

    virtual PhysicalKeyboardKey physicalKey();

    virtual LogicalKeyboardKey logicalKey();

    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    static bool _isUnprintableKey(String label);

    virtual bool _isLeftRightModifierPressed(KeyboardSide side, int anyMask, int leftMask, int rightMask);

};
using RawKeyEventDataIos = std::shared_ptr<RawKeyEventDataIosCls>;


#endif