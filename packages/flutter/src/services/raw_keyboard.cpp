#include "raw_keyboard.hpp"
bool RawKeyEventData::isControlPressed() {
    return isModifierPressed(ModifierKey.controlModifier);
}

bool RawKeyEventData::isShiftPressed() {
    return isModifierPressed(ModifierKey.shiftModifier);
}

bool RawKeyEventData::isAltPressed() {
    return isModifierPressed(ModifierKey.altModifier);
}

bool RawKeyEventData::isMetaPressed() {
    return isModifierPressed(ModifierKey.metaModifier);
}

Map<ModifierKey, KeyboardSide> RawKeyEventData::modifiersPressed() {
    Map<ModifierKey, KeyboardSide> result = ;
    for (ModifierKey key : ModifierKey.values) {
        if (isModifierPressed(key)) {
            KeyboardSide side = getModifierSide(key);
            if (side != nullptr) {
                result[key] = side;
            }
            assert(());
        }
    }
    return result;
}

bool RawKeyEventData::shouldDispatchEvent() {
    return true;
}

void RawKeyEvent::fromMessage(Map<String, Object> message) {
    String character;
    ;
    RawKeyEventData data;
    if (kIsWeb) {
        data = dataFromWeb();
    } else {
        String keymap = (;
        ;
    }
    bool repeat = RawKeyboard.instance.physicalKeysPressed.contains(data.physicalKey);
    String type = (;
    ;
}

bool RawKeyEvent::isKeyPressed(LogicalKeyboardKey key) {
    return RawKeyboard.instance.keysPressed.contains(key);
}

bool RawKeyEvent::isControlPressed() {
    return isKeyPressed(LogicalKeyboardKey.controlLeft) || isKeyPressed(LogicalKeyboardKey.controlRight);
}

bool RawKeyEvent::isShiftPressed() {
    return isKeyPressed(LogicalKeyboardKey.shiftLeft) || isKeyPressed(LogicalKeyboardKey.shiftRight);
}

bool RawKeyEvent::isAltPressed() {
    return isKeyPressed(LogicalKeyboardKey.altLeft) || isKeyPressed(LogicalKeyboardKey.altRight);
}

bool RawKeyEvent::isMetaPressed() {
    return isKeyPressed(LogicalKeyboardKey.metaLeft) || isKeyPressed(LogicalKeyboardKey.metaRight);
}

PhysicalKeyboardKey RawKeyEvent::physicalKey() {
    return data.physicalKey;
}

LogicalKeyboardKey RawKeyEvent::logicalKey() {
    return data.logicalKey;
}

void RawKeyEvent::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<LogicalKeyboardKey>DiagnosticsProperty("logicalKey", logicalKey));
    properties.add(<PhysicalKeyboardKey>DiagnosticsProperty("physicalKey", physicalKey));
    if (this is RawKeyDownEvent) {
        properties.add(<bool>DiagnosticsProperty("repeat", repeat));
    }
}

RawKeyUpEvent::RawKeyUpEvent(Unknown, Unknown) {
    {
        super(false);
    }
}

void RawKeyboard::addListener(ValueChanged<RawKeyEvent> listener) {
    _listeners.add(listener);
}

void RawKeyboard::removeListener(ValueChanged<RawKeyEvent> listener) {
    _listeners.remove(listener);
}

RawKeyEventHandler RawKeyboard::keyEventHandler() {
    if (ServicesBinding.instance.keyEventManager.keyMessageHandler != _cachedKeyMessageHandler) {
        _cachedKeyMessageHandler = ServicesBinding.instance.keyEventManager.keyMessageHandler;
        _cachedKeyEventHandler = _cachedKeyMessageHandler == nullptr? nullptr : ;
    }
    return _cachedKeyEventHandler;
}

void RawKeyboard::keyEventHandler(RawKeyEventHandler handler) {
    _cachedKeyEventHandler = handler;
    _cachedKeyMessageHandler = handler == nullptr? nullptr : ;
    ServicesBinding.instance.keyEventManager.keyMessageHandler = _cachedKeyMessageHandler;
}

bool RawKeyboard::handleRawKeyEvent(RawKeyEvent event) {
    if (event is RawKeyDownEvent) {
        _keysPressed[event.physicalKey] = event.logicalKey;
    } else     {
        if (event is RawKeyUpEvent) {
        _keysPressed.remove(event.physicalKey);
    }
;
    }    _synchronizeModifiers(event);
    assert(event is! RawKeyDownEvent || _keysPressed.isNotEmpty, "Attempted to send a key down event when no keys are in keysPressed. This state can occur if the key event being sent doesn't properly set its modifier flags. This was the event: $event and its data: ${event.data}");
    for (ValueChanged<RawKeyEvent> listener : <ValueChanged<RawKeyEvent>>of(_listeners)) {
        ;
    }
    return false;
}

Set<LogicalKeyboardKey> RawKeyboard::keysPressed() {
    return _keysPressed.values.toSet();
}

Set<PhysicalKeyboardKey> RawKeyboard::physicalKeysPressed() {
    return _keysPressed.keys.toSet();
}

LogicalKeyboardKey RawKeyboard::lookUpLayout(PhysicalKeyboardKey physicalKey) {
    return _keysPressed[physicalKey];
}

void RawKeyboard::clearKeysPressed() {
    return _keysPressed.clear();
}

void RawKeyboard::_synchronizeModifiers(RawKeyEvent event) {
    Map<ModifierKey, KeyboardSide> modifiersPressed = event.data.modifiersPressed;
    Map<PhysicalKeyboardKey, LogicalKeyboardKey> modifierKeys = ;
    Set<PhysicalKeyboardKey> anySideKeys = ;
    Set<PhysicalKeyboardKey> keysPressedAfterEvent = ;
    ModifierKey thisKeyModifier;
    for (ModifierKey key : ModifierKey.values) {
        Set<PhysicalKeyboardKey> thisModifierKeys = _modifierKeyMap[_ModifierSidePair(key, KeyboardSide.all)];
        if (thisModifierKeys == nullptr) {
            continue;
        }
        if (thisModifierKeys.contains(event.physicalKey)) {
            thisKeyModifier = key;
        }
        if (modifiersPressed[key] == KeyboardSide.any) {
            anySideKeys.addAll(thisModifierKeys);
            if (thisModifierKeys.any(keysPressedAfterEvent.contains)) {
                continue;
            }
        }
        Set<PhysicalKeyboardKey> mappedKeys = modifiersPressed[key] == nullptr?  : _modifierKeyMap[_ModifierSidePair(key, modifiersPressed[key])];
        assert(());
        if (mappedKeys == nullptr) {
            continue;
        }
        for (PhysicalKeyboardKey physicalModifier : mappedKeys) {
            modifierKeys[physicalModifier] = _allModifiers[physicalModifier]!;
        }
    }
    _allModifiersExceptFn.keys.where().forEach(_keysPressed.remove);
    if (event.data is! RawKeyEventDataFuchsia && event.data is! RawKeyEventDataMacOs) {
        _keysPressed.remove(PhysicalKeyboardKey.fn);
    }
    _keysPressed.addAll(modifierKeys);
    if (event is RawKeyDownEvent && thisKeyModifier != nullptr && !_keysPressed.containsKey(event.physicalKey)) {
        if (event.data is RawKeyEventDataLinux && event.physicalKey == PhysicalKeyboardKey.altRight) {
            LogicalKeyboardKey logicalKey = _allModifiersExceptFn[event.physicalKey];
            if (logicalKey != nullptr) {
                _keysPressed[event.physicalKey] = logicalKey;
            }
        }
    }
}

bool _ModifierSidePair::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _ModifierSidePair && other.modifier == modifier && other.side == side;
}

int _ModifierSidePair::hashCode() {
    return Object.hash(modifier, side);
}
