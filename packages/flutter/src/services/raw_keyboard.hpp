#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD
#define PACKAGES_FLUTTER_SRC_SERVICES_RAW_KEYBOARD
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"

#include <dart/core/core.hpp>
#include <dart/io/io.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"
#include "hardware_keyboard.hpp"
#include "keyboard_key.g.hpp"
#include "raw_keyboard_android.hpp"
#include "raw_keyboard_fuchsia.hpp"
#include "raw_keyboard_ios.hpp"
#include "raw_keyboard_linux.hpp"
#include "raw_keyboard_macos.hpp"
#include "raw_keyboard_web.hpp"
#include "raw_keyboard_windows.hpp"
#include "system_channels.hpp"


enum KeyboardSide{
    any,
    left,
    right,
    all,
} // end KeyboardSide

enum ModifierKey{
    controlModifier,
    shiftModifier,
    altModifier,
    metaModifier,
    capsLockModifier,
    numLockModifier,
    scrollLockModifier,
    functionModifier,
    symbolModifier,
} // end ModifierKey

class RawKeyEventDataCls : public ObjectCls {
public:

     RawKeyEventDataCls();
    virtual bool isModifierPressed(ModifierKey key, KeyboardSide side);
    virtual KeyboardSide getModifierSide(ModifierKey key);
    virtual bool isControlPressed();

    virtual bool isShiftPressed();

    virtual bool isAltPressed();

    virtual bool isMetaPressed();

    virtual Map<ModifierKey, KeyboardSide> modifiersPressed();

    virtual PhysicalKeyboardKey physicalKey();
    virtual LogicalKeyboardKey logicalKey();
    virtual String keyLabel();
    virtual bool shouldDispatchEvent();

private:

};
using RawKeyEventData = std::shared_ptr<RawKeyEventDataCls>;

class RawKeyEventCls : public ObjectCls {
public:
    String character;

    bool repeat;

    RawKeyEventData data;


     RawKeyEventCls(String character, RawKeyEventData data, bool repeat);
    virtual void  fromMessage(Map<String, Object> message);

    virtual bool isKeyPressed(LogicalKeyboardKey key);

    virtual bool isControlPressed();

    virtual bool isShiftPressed();

    virtual bool isAltPressed();

    virtual bool isMetaPressed();

    virtual PhysicalKeyboardKey physicalKey();

    virtual LogicalKeyboardKey logicalKey();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RawKeyEvent = std::shared_ptr<RawKeyEventCls>;

class RawKeyDownEventCls : public RawKeyEventCls {
public:

     RawKeyDownEventCls(Unknown character, Unknown data, Unknown repeat);
private:

};
using RawKeyDownEvent = std::shared_ptr<RawKeyDownEventCls>;

class RawKeyUpEventCls : public RawKeyEventCls {
public:

     RawKeyUpEventCls(Unknown character, Unknown data);

private:

};
using RawKeyUpEvent = std::shared_ptr<RawKeyUpEventCls>;

class RawKeyboardCls : public ObjectCls {
public:
    static RawKeyboard instance;


    virtual void addListener(ValueChanged<RawKeyEvent> listener);

    virtual void removeListener(ValueChanged<RawKeyEvent> listener);

    virtual RawKeyEventHandler keyEventHandler();

    virtual void  keyEventHandler(RawKeyEventHandler handler);

    virtual bool handleRawKeyEvent(RawKeyEvent event);

    virtual Set<LogicalKeyboardKey> keysPressed();

    virtual Set<PhysicalKeyboardKey> physicalKeysPressed();

    virtual LogicalKeyboardKey lookUpLayout(PhysicalKeyboardKey physicalKey);

    virtual void clearKeysPressed();

private:
    List<ValueChanged<RawKeyEvent>> _listeners;

    RawKeyEventHandler _cachedKeyEventHandler;

    KeyMessageHandler _cachedKeyMessageHandler;

    static Map<_ModifierSidePair, Set<PhysicalKeyboardKey>> _modifierKeyMap;

    static Map<PhysicalKeyboardKey, LogicalKeyboardKey> _allModifiersExceptFn;

    static Map<PhysicalKeyboardKey, LogicalKeyboardKey> _allModifiers;

    Map<PhysicalKeyboardKey, LogicalKeyboardKey> _keysPressed;


    virtual void  _();
    virtual void _synchronizeModifiers(RawKeyEvent event);

};
using RawKeyboard = std::shared_ptr<RawKeyboardCls>;

class _ModifierSidePairCls : public ObjectCls {
public:
    ModifierKey modifier;

    KeyboardSide side;


    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _ModifierSidePairCls(ModifierKey modifier, KeyboardSide side);
};
using _ModifierSidePair = std::shared_ptr<_ModifierSidePairCls>;


#endif