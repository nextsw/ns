#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_LINUX
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD_LINUX
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


class RawKeyEventDataLinuxCls : public RawKeyEventDataCls {
public:
    KeyHelper keyHelper;

    int unicodeScalarValues;

    int scanCode;

    int keyCode;

    int modifiers;

    bool isDown;

    int specifiedLogicalKey;


     RawKeyEventDataLinuxCls(bool isDown, int keyCode, KeyHelper keyHelper, int modifiers, int scanCode, int specifiedLogicalKey, int unicodeScalarValues);

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
using RawKeyEventDataLinux = std::shared_ptr<RawKeyEventDataLinuxCls>;

class KeyHelperCls : public ObjectCls {
public:

     KeyHelperCls(String toolkit);

    virtual String debugToolkit();
    virtual KeyboardSide getModifierSide(ModifierKey key);
    virtual bool isModifierPressed(ModifierKey key, int modifiers, bool isDown, int keyCode, KeyboardSide side);
    virtual LogicalKeyboardKey numpadKey(int keyCode);
    virtual LogicalKeyboardKey logicalKey(int keyCode);
    virtual int platformPlane();
private:

};
using KeyHelper = std::shared_ptr<KeyHelperCls>;

class GLFWKeyHelperCls : public ObjectCls {
public:
    static int modifierCapsLock;

    static int modifierShift;

    static int modifierControl;

    static int modifierAlt;

    static int modifierMeta;

    static int modifierNumericPad;


    virtual String debugToolkit();

    virtual bool isModifierPressed(ModifierKey key, int modifiers, bool isDown, int keyCode, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual LogicalKeyboardKey numpadKey(int keyCode);

    virtual LogicalKeyboardKey logicalKey(int keyCode);

    virtual int platformPlane();

private:

    virtual int _mergeModifiers(bool isDown, int keyCode, int modifiers);

};
using GLFWKeyHelper = std::shared_ptr<GLFWKeyHelperCls>;

class GtkKeyHelperCls : public ObjectCls {
public:
    static int modifierShift;

    static int modifierCapsLock;

    static int modifierControl;

    static int modifierMod1;

    static int modifierMod2;

    static int modifierMeta;


    virtual String debugToolkit();

    virtual bool isModifierPressed(ModifierKey key, int modifiers, bool isDown, int keyCode, KeyboardSide side);

    virtual KeyboardSide getModifierSide(ModifierKey key);

    virtual LogicalKeyboardKey numpadKey(int keyCode);

    virtual LogicalKeyboardKey logicalKey(int keyCode);

    virtual int platformPlane();

private:

    virtual int _mergeModifiers(bool isDown, int keyCode, int modifiers);

};
using GtkKeyHelper = std::shared_ptr<GtkKeyHelperCls>;


#endif