#ifndef RAW_KEYBOARD_LINUX_H
#define RAW_KEYBOARD_LINUX_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"



class RawKeyEventDataLinux : RawKeyEventData {
public:
    KeyHelper keyHelper;

    int unicodeScalarValues;

    int scanCode;

    int keyCode;

    int modifiers;

    bool isDown;

    int specifiedLogicalKey;


     RawKeyEventDataLinux(bool isDown, int keyCode, KeyHelper keyHelper, int modifiers, int scanCode, int specifiedLogicalKey, int unicodeScalarValues);

    String keyLabel();

    PhysicalKeyboardKey physicalKey();

    LogicalKeyboardKey logicalKey();

    bool isModifierPressed(ModifierKey key, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:

};

class KeyHelper {
public:

     KeyHelper(String toolkit);

    String debugToolkit();

    KeyboardSide getModifierSide(ModifierKey key);

    bool isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side);

    LogicalKeyboardKey numpadKey(int keyCode);

    LogicalKeyboardKey logicalKey(int keyCode);

    int platformPlane();

private:

};

class GLFWKeyHelper {
public:
    static const int modifierCapsLock;

    static const int modifierShift;

    static const int modifierControl;

    static const int modifierAlt;

    static const int modifierMeta;

    static const int modifierNumericPad;


    String debugToolkit();

    bool isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    LogicalKeyboardKey numpadKey(int keyCode);

    LogicalKeyboardKey logicalKey(int keyCode);

    int platformPlane();

private:

    int _mergeModifiers(bool isDown, int keyCode, int modifiers);

};

class GtkKeyHelper {
public:
    static const int modifierShift;

    static const int modifierCapsLock;

    static const int modifierControl;

    static const int modifierMod1;

    static const int modifierMod2;

    static const int modifierMeta;


    String debugToolkit();

    bool isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side);

    KeyboardSide getModifierSide(ModifierKey key);

    LogicalKeyboardKey numpadKey(int keyCode);

    LogicalKeyboardKey logicalKey(int keyCode);

    int platformPlane();

private:

    int _mergeModifiers(bool isDown, int keyCode, int modifiers);

};

#endif