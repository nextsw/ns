#include "hardware_keyboard.hpp"
KeyboardLockMode KeyboardLockMode::findLockByLogicalKey(LogicalKeyboardKey logicalKey) {
    return _knownLockModes[logicalKey.keyId];
}

void KeyEvent::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<PhysicalKeyboardKey>DiagnosticsProperty("physicalKey", physicalKey));
    properties.add(<LogicalKeyboardKey>DiagnosticsProperty("logicalKey", logicalKey));
    properties.add(StringProperty("character", character));
    properties.add(<Duration>DiagnosticsProperty("timeStamp", timeStamp));
    properties.add(FlagProperty("synthesized"synthesized, "synthesized"));
}

HardwareKeyboard HardwareKeyboard::instance() {
    return ServicesBinding.instance.keyboard;
}

Set<PhysicalKeyboardKey> HardwareKeyboard::physicalKeysPressed() {
    return _pressedKeys.keys.toSet();
}

Set<LogicalKeyboardKey> HardwareKeyboard::logicalKeysPressed() {
    return _pressedKeys.values.toSet();
}

LogicalKeyboardKey HardwareKeyboard::lookUpLayout(PhysicalKeyboardKey physicalKey) {
    return _pressedKeys[physicalKey];
}

Set<KeyboardLockMode> HardwareKeyboard::lockModesEnabled() {
    return _lockModes;
}

void HardwareKeyboard::addHandler(KeyEventCallback handler) {
    if (_duringDispatch) {
        _modifiedHandlers = ;
        _modifiedHandlers!.add(handler);
    } else {
        _handlers.add(handler);
    }
}

void HardwareKeyboard::removeHandler(KeyEventCallback handler) {
    if (_duringDispatch) {
        _modifiedHandlers = ;
        _modifiedHandlers!.remove(handler);
    } else {
        _handlers.remove(handler);
    }
}

bool HardwareKeyboard::handleKeyEvent(KeyEvent event) {
    _assertEventIsRegular(event);
    PhysicalKeyboardKey physicalKey = event.physicalKey;
    LogicalKeyboardKey logicalKey = event.logicalKey;
    if (event is KeyDownEvent) {
        _pressedKeys[physicalKey] = logicalKey;
        KeyboardLockMode lockMode = KeyboardLockMode.findLockByLogicalKey(event.logicalKey);
        if (lockMode != nullptr) {
            if (_lockModes.contains(lockMode)) {
                _lockModes.remove(lockMode);
            } else {
                _lockModes.add(lockMode);
            }
        }
    } else     {
        if (event is KeyUpEvent) {
        _pressedKeys.remove(physicalKey);
    } else     {
        if (event is KeyRepeatEvent) {
    }
;
    };
    }    return _dispatchKeyEvent(event);
}

void HardwareKeyboard::clearState() {
    _pressedKeys.clear();
    _lockModes.clear();
    _handlers.clear();
    assert(_modifiedHandlers == nullptr);
}

void HardwareKeyboard::_assertEventIsRegular(KeyEvent event) {
    assert(());
}

bool HardwareKeyboard::_dispatchKeyEvent(KeyEvent event) {
    assert(!_duringDispatch, "Nested keyboard dispatching is not supported");
    _duringDispatch = true;
    bool handled = false;
    for (KeyEventCallback handler : _handlers) {
        ;
    }
    _duringDispatch = false;
    if (_modifiedHandlers != nullptr) {
        _handlers = _modifiedHandlers!;
        _modifiedHandlers = nullptr;
    }
    return handled;
}

String KeyMessage::toString() {
    return "KeyMessage($events)";
}

bool KeyEventManager::handleKeyData(KeyData data) {
    _transitMode = KeyDataTransitMode.keyDataThenRawKeyData;
    ;
}

Future<Map<String, dynamic>> KeyEventManager::handleRawKeyMessage(dynamic message) {
    if (_transitMode == nullptr) {
        _transitMode = KeyDataTransitMode.rawKeyData;
        _rawKeyboard.addListener(_convertRawEventAndStore);
    }
    RawKeyEvent rawEvent = RawKeyEvent.fromMessage(();
    bool shouldDispatch = true;
    if (rawEvent is RawKeyDownEvent) {
        if (!rawEvent.data.shouldDispatchEvent()) {
            shouldDispatch = false;
            _skippedRawKeysPressed.add(rawEvent.physicalKey);
        } else {
            _skippedRawKeysPressed.remove(rawEvent.physicalKey);
        }
    } else     {
        if (rawEvent is RawKeyUpEvent) {
        if (_skippedRawKeysPressed.contains(rawEvent.physicalKey)) {
            _skippedRawKeysPressed.remove(rawEvent.physicalKey);
            shouldDispatch = false;
        }
    }
;
    }    bool handled = true;
    if (shouldDispatch) {
        handled = _rawKeyboard.handleRawKeyEvent(rawEvent);
        for (KeyEvent event : _keyEventsSinceLastMessage) {
            handled = _hardwareKeyboard.handleKeyEvent(event) || handled;
        }
        if (_transitMode == KeyDataTransitMode.rawKeyData) {
            assert(setEquals(_rawKeyboard.physicalKeysPressed, _hardwareKeyboard.physicalKeysPressed), "RawKeyboard reported ${_rawKeyboard.physicalKeysPressed}, while HardwareKeyboard reported ${_hardwareKeyboard.physicalKeysPressed}");
        }
        handled = _dispatchKeyMessage(_keyEventsSinceLastMessage, rawEvent) || handled;
        _keyEventsSinceLastMessage.clear();
    }
    return ;
}

void KeyEventManager::clearState() {
    assert(());
}

bool KeyEventManager::_dispatchKeyMessage(List<KeyEvent> keyEvents, RawKeyEvent rawEvent) {
    if (keyMessageHandler != nullptr) {
        KeyMessage message = KeyMessage(keyEvents, rawEvent);
        ;
    }
    return false;
}

void KeyEventManager::_convertRawEventAndStore(RawKeyEvent rawEvent) {
    PhysicalKeyboardKey physicalKey = rawEvent.physicalKey;
    LogicalKeyboardKey logicalKey = rawEvent.logicalKey;
    Set<PhysicalKeyboardKey> physicalKeysPressed = _hardwareKeyboard.physicalKeysPressed;
    List<KeyEvent> eventAfterwards = ;
    KeyEvent mainEvent;
    LogicalKeyboardKey recordedLogicalMain = _hardwareKeyboard.lookUpLayout(physicalKey);
    Duration timeStamp = ServicesBinding.instance.currentSystemFrameTimeStamp;
    String character = rawEvent.character == ""? nullptr : rawEvent.character;
    if (rawEvent is RawKeyDownEvent) {
        if (recordedLogicalMain == nullptr) {
            mainEvent = KeyDownEvent(physicalKey, logicalKey, character, timeStamp);
            physicalKeysPressed.add(physicalKey);
        } else {
            assert(physicalKeysPressed.contains(physicalKey));
            mainEvent = KeyRepeatEvent(physicalKey, recordedLogicalMain, character, timeStamp);
        }
    } else {
        assert(rawEvent is RawKeyUpEvent, "Unexpected subclass of RawKeyEvent: ${rawEvent.runtimeType}");
        if (recordedLogicalMain == nullptr) {
            mainEvent = nullptr;
        } else {
            mainEvent = KeyUpEvent(recordedLogicalMain, physicalKey, timeStamp);
            physicalKeysPressed.remove(physicalKey);
        }
    }
    for (PhysicalKeyboardKey key : physicalKeysPressed.difference(_rawKeyboard.physicalKeysPressed)) {
        if (key == physicalKey) {
            eventAfterwards.add(KeyUpEvent(key, logicalKey, timeStamp, true));
        } else {
            _keyEventsSinceLastMessage.add(KeyUpEvent(key, _hardwareKeyboard.lookUpLayout(key)!, timeStamp, true));
        }
    }
    for (PhysicalKeyboardKey key : _rawKeyboard.physicalKeysPressed.difference(physicalKeysPressed)) {
        _keyEventsSinceLastMessage.add(KeyDownEvent(key, _rawKeyboard.lookUpLayout(key)!, timeStamp, true));
    }
    if (mainEvent != nullptr) {
        _keyEventsSinceLastMessage.add(mainEvent);
    }
    _keyEventsSinceLastMessage.addAll(eventAfterwards);
}

KeyEvent KeyEventManager::_eventFromData(KeyData keyData) {
    PhysicalKeyboardKey physicalKey = PhysicalKeyboardKey.findKeyByCode(keyData.physical) ?? PhysicalKeyboardKey(keyData.physical);
    LogicalKeyboardKey logicalKey = LogicalKeyboardKey.findKeyByKeyId(keyData.logical) ?? LogicalKeyboardKey(keyData.logical);
    Duration timeStamp = keyData.timeStamp;
    ;
}
