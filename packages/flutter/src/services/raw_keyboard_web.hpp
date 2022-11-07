#ifndef RAW_KEYBOARD_WEB_H
#define RAW_KEYBOARD_WEB_H
#include <memory>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <flutter/foundation.hpp>
#include "keyboard_maps.g.hpp"
#include "raw_keyboard.hpp"


String _unicodeChar(String key);


class RawKeyEventDataWeb : RawKeyEventData {
public:
    String code;

    String key;

    int location;

    int metaState;

    int keyCode;

    static const int modifierNone;

    static const int modifierShift;

    static const int modifierAlt;

    static const int modifierControl;

    static const int modifierMeta;

    static const int modifierNumLock;

    static const int modifierCapsLock;

    static const int modifierScrollLock;


     RawKeyEventDataWeb(String code, String key, int keyCode, int location, int metaState);

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

#endif