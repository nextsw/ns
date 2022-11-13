#ifndef PACKAGES_FLUTTER_SRC_SERVICES_HARDWARE_KEYBOARD
#define PACKAGES_FLUTTER_SRC_SERVICES_HARDWARE_KEYBOARD
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"
#include "raw_keyboard.hpp"


class KeyboardLockModeCls : public ObjectCls {
public:
    LogicalKeyboardKey logicalKey;

    static KeyboardLockMode numLock;

    static KeyboardLockMode scrollLock;

    static KeyboardLockMode capsLock;


    static KeyboardLockMode findLockByLogicalKey(LogicalKeyboardKey logicalKey);

private:
    static Map<int, KeyboardLockMode> _knownLockModes;


    virtual void  _(LogicalKeyboardKey logicalKey);
};
using KeyboardLockMode = std::shared_ptr<KeyboardLockModeCls>;

class KeyEventCls : public ObjectCls {
public:
    PhysicalKeyboardKey physicalKey;

    LogicalKeyboardKey logicalKey;

    String character;

    Duration timeStamp;

    bool synthesized;


     KeyEventCls(String character, LogicalKeyboardKey logicalKey, PhysicalKeyboardKey physicalKey, bool synthesized, Duration timeStamp);
    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using KeyEvent = std::shared_ptr<KeyEventCls>;

class KeyDownEventCls : public KeyEventCls {
public:

     KeyDownEventCls(String character, LogicalKeyboardKey logicalKey, PhysicalKeyboardKey physicalKey, bool synthesized, Duration timeStamp);
private:

};
using KeyDownEvent = std::shared_ptr<KeyDownEventCls>;

class KeyUpEventCls : public KeyEventCls {
public:

     KeyUpEventCls(LogicalKeyboardKey logicalKey, PhysicalKeyboardKey physicalKey, bool synthesized, Duration timeStamp);
private:

};
using KeyUpEvent = std::shared_ptr<KeyUpEventCls>;

class KeyRepeatEventCls : public KeyEventCls {
public:

     KeyRepeatEventCls(String character, LogicalKeyboardKey logicalKey, PhysicalKeyboardKey physicalKey, Duration timeStamp);
private:

};
using KeyRepeatEvent = std::shared_ptr<KeyRepeatEventCls>;

class HardwareKeyboardCls : public ObjectCls {
public:

    static HardwareKeyboard instance();

    virtual Set<PhysicalKeyboardKey> physicalKeysPressed();

    virtual Set<LogicalKeyboardKey> logicalKeysPressed();

    virtual LogicalKeyboardKey lookUpLayout(PhysicalKeyboardKey physicalKey);

    virtual Set<KeyboardLockMode> lockModesEnabled();

    virtual void addHandler(KeyEventCallback handler);

    virtual void removeHandler(KeyEventCallback handler);

    virtual bool handleKeyEvent(KeyEvent event);

    virtual void clearState();

private:
    Map<PhysicalKeyboardKey, LogicalKeyboardKey> _pressedKeys;

    Set<KeyboardLockMode> _lockModes;

    List<KeyEventCallback> _handlers;

    bool _duringDispatch;

    List<KeyEventCallback> _modifiedHandlers;


    virtual void _assertEventIsRegular(KeyEvent event);

    virtual bool _dispatchKeyEvent(KeyEvent event);

};
using HardwareKeyboard = std::shared_ptr<HardwareKeyboardCls>;

enum KeyDataTransitMode{
    rawKeyData,
    keyDataThenRawKeyData,
} // end KeyDataTransitMode

class KeyMessageCls : public ObjectCls {
public:
    List<KeyEvent> events;

    RawKeyEvent rawEvent;


     KeyMessageCls(List<KeyEvent> events, RawKeyEvent rawEvent);
    virtual String toString();

private:

};
using KeyMessage = std::shared_ptr<KeyMessageCls>;

class KeyEventManagerCls : public ObjectCls {
public:
    KeyMessageHandler keyMessageHandler;


     KeyEventManagerCls(HardwareKeyboard _hardwareKeyboard, RawKeyboard _rawKeyboard);
    virtual bool handleKeyData(KeyData data);

    virtual Future<Map<String, Object>> handleRawKeyMessage(Object message);

    virtual void clearState();

private:
    HardwareKeyboard _hardwareKeyboard;

    RawKeyboard _rawKeyboard;

    KeyDataTransitMode _transitMode;

    List<KeyEvent> _keyEventsSinceLastMessage;

    Set<PhysicalKeyboardKey> _skippedRawKeysPressed;


    virtual bool _dispatchKeyMessage(List<KeyEvent> keyEvents, RawKeyEvent rawEvent);

    virtual void _convertRawEventAndStore(RawKeyEvent rawEvent);

    static KeyEvent _eventFromData(KeyData keyData);

};
using KeyEventManager = std::shared_ptr<KeyEventManagerCls>;


#endif