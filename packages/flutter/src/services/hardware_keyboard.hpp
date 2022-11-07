#ifndef HARDWARE_KEYBOARD_H
#define HARDWARE_KEYBOARD_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include "keyboard_key.g.hpp"
#include "raw_keyboard.hpp"

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"
#include "raw_keyboard.hpp"



class KeyboardLockMode {
public:
    LogicalKeyboardKey logicalKey;

    static const KeyboardLockMode numLock;

    static const KeyboardLockMode scrollLock;

    static const KeyboardLockMode capsLock;


    static KeyboardLockMode findLockByLogicalKey(LogicalKeyboardKey logicalKey);

private:
    static Map<int, KeyboardLockMode> _knownLockModes;


    void  _(LogicalKeyboardKey logicalKey);

};

class KeyEvent {
public:
    PhysicalKeyboardKey physicalKey;

    LogicalKeyboardKey logicalKey;

    String character;

    Duration timeStamp;

    bool synthesized;


     KeyEvent(String character, LogicalKeyboardKey logicalKey, PhysicalKeyboardKey physicalKey, bool synthesized, Duration timeStamp);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class KeyDownEvent : KeyEvent {
public:

     KeyDownEvent(Unknown, Unknown, Unknown, Unknown, Unknown);

private:

};

class KeyUpEvent : KeyEvent {
public:

     KeyUpEvent(Unknown, Unknown, Unknown, Unknown);

private:

};

class KeyRepeatEvent : KeyEvent {
public:

     KeyRepeatEvent(Unknown, Unknown, Unknown, Unknown);

private:

};

class HardwareKeyboard {
public:

    static HardwareKeyboard instance();

    Set<PhysicalKeyboardKey> physicalKeysPressed();

    Set<LogicalKeyboardKey> logicalKeysPressed();

    LogicalKeyboardKey lookUpLayout(PhysicalKeyboardKey physicalKey);

    Set<KeyboardLockMode> lockModesEnabled();

    void addHandler(KeyEventCallback handler);

    void removeHandler(KeyEventCallback handler);

    bool handleKeyEvent(KeyEvent event);

    void clearState();

private:
    Map<PhysicalKeyboardKey, LogicalKeyboardKey> _pressedKeys;

    Set<KeyboardLockMode> _lockModes;

    List<KeyEventCallback> _handlers;

    bool _duringDispatch;

    List<KeyEventCallback> _modifiedHandlers;


    void _assertEventIsRegular(KeyEvent event);

    bool _dispatchKeyEvent(KeyEvent event);

};

enum KeyDataTransitMode{
    rawKeyData,
    keyDataThenRawKeyData,
} // end KeyDataTransitMode

class KeyMessage {
public:
    List<KeyEvent> events;

    RawKeyEvent rawEvent;


     KeyMessage(List<KeyEvent> events, RawKeyEvent rawEvent);

    String toString();

private:

};

class KeyEventManager {
public:
    KeyMessageHandler keyMessageHandler;


     KeyEventManager(HardwareKeyboard _hardwareKeyboard, RawKeyboard _rawKeyboard);

    bool handleKeyData(KeyData data);

    Future<Map<String, dynamic>> handleRawKeyMessage(dynamic message);

    void clearState();

private:
    HardwareKeyboard _hardwareKeyboard;

    RawKeyboard _rawKeyboard;

    KeyDataTransitMode _transitMode;

    List<KeyEvent> _keyEventsSinceLastMessage;

    Set<PhysicalKeyboardKey> _skippedRawKeysPressed;


    bool _dispatchKeyMessage(List<KeyEvent> keyEvents, RawKeyEvent rawEvent);

    void _convertRawEventAndStore(RawKeyEvent rawEvent);

    static KeyEvent _eventFromData(KeyData keyData);

};

#endif