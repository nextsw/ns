#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_FUCHSIA
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_FUCHSIA
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


class RawKeyEventDataFuchsiaCls : public RawKeyEventDataCls {
public:
    int hidUsage;

    int codePoint;

    int modifiers;

    static int modifierNone;

    static int modifierCapsLock;

    static int modifierLeftShift;

    static int modifierRightShift;

    static int modifierShift;

    static int modifierLeftControl;

    static int modifierRightControl;

    static int modifierControl;

    static int modifierLeftAlt;

    static int modifierRightAlt;

    static int modifierAlt;

    static int modifierLeftMeta;

    static int modifierRightMeta;

    static int modifierMeta;


     RawKeyEventDataFuchsiaCls(int codePoint, int hidUsage, int modifiers);

    virtual String keyLabel();

    virtual LogicalKeyboardKey logicalKey();

    virtual PhysicalKeyboardKey physicalKey();

    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual bool _isLeftRightModifierPressed(KeyboardSide side, int anyMask, int leftMask, int rightMask);

};
using RawKeyEventDataFuchsia = std::shared_ptr<RawKeyEventDataFuchsiaCls>;


#endif