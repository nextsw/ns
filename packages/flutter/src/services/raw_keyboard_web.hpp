#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_WEB
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_WEB
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"

String _unicodeChar(String key);


class RawKeyEventDataWebCls : public RawKeyEventDataCls {
public:
    String code;

    String key;

    int location;

    int metaState;

    int keyCode;

    static int modifierNone;

    static int modifierShift;

    static int modifierAlt;

    static int modifierControl;

    static int modifierMeta;

    static int modifierNumLock;

    static int modifierCapsLock;

    static int modifierScrollLock;


     RawKeyEventDataWebCls(String code, String key, int keyCode, int location, int metaState);

    virtual String keyLabel();

    virtual PhysicalKeyboardKey physicalKey();

    virtual LogicalKeyboardKey logicalKey();

    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

};
using RawKeyEventDataWeb = std::shared_ptr<RawKeyEventDataWebCls>;


#endif