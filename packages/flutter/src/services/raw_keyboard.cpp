#include "raw_keyboard.hpp"
bool RawKeyEventDataCls::isControlPressed() {
    return isModifierPressed(ModifierKeyCls::controlModifier);
}

bool RawKeyEventDataCls::isShiftPressed() {
    return isModifierPressed(ModifierKeyCls::shiftModifier);
}

bool RawKeyEventDataCls::isAltPressed() {
    return isModifierPressed(ModifierKeyCls::altModifier);
}

bool RawKeyEventDataCls::isMetaPressed() {
    return isModifierPressed(ModifierKeyCls::metaModifier);
}

Map<ModifierKey, KeyboardSide> RawKeyEventDataCls::modifiersPressed() {
    Map<ModifierKey, KeyboardSide> result = makeMap(makeList(), makeList();
    for (ModifierKey key : ModifierKeyCls::values) {
        if (isModifierPressed(key)) {
            KeyboardSide side = getModifierSide(key);
            if (side != nullptr) {
                result[key] = side;
            }
            assert([=] () {
                if (side == nullptr) {
                    debugPrint(__s("Raw key data is returning inconsistent information for pressed modifiers. isModifierPressed returns true for $key being pressed, but when getModifierSide is called, it says that no modifiers are pressed."));
                    if (is<RawKeyEventDataAndroid>(this)) {
                        debugPrint(__s("Android raw key metaState: ${(this as RawKeyEventDataAndroid).metaState}"));
                    }
                }
                return true;
            }());
        }
    }
    return result;
}

bool RawKeyEventDataCls::shouldDispatchEvent() {
    return true;
}

void RawKeyEventCls::fromMessage(Map<String, Object> message) {
    String character;
    InlineMethod;
    RawKeyEventData data;
    if (kIsWeb) {
        data = dataFromWeb();
    } else {
        String keymap = as<String>(message[__s("keymap")]!);
        ;
    }
    bool repeat = RawKeyboardCls::instance->physicalKeysPressed->contains(data->physicalKey);
    String type = as<String>(message[__s("type")]!);
    ;
}

bool RawKeyEventCls::isKeyPressed(LogicalKeyboardKey key) {
    return RawKeyboardCls::instance->keysPressed->contains(key);
}

bool RawKeyEventCls::isControlPressed() {
    return isKeyPressed(LogicalKeyboardKeyCls::controlLeft) || isKeyPressed(LogicalKeyboardKeyCls::controlRight);
}

bool RawKeyEventCls::isShiftPressed() {
    return isKeyPressed(LogicalKeyboardKeyCls::shiftLeft) || isKeyPressed(LogicalKeyboardKeyCls::shiftRight);
}

bool RawKeyEventCls::isAltPressed() {
    return isKeyPressed(LogicalKeyboardKeyCls::altLeft) || isKeyPressed(LogicalKeyboardKeyCls::altRight);
}

bool RawKeyEventCls::isMetaPressed() {
    return isKeyPressed(LogicalKeyboardKeyCls::metaLeft) || isKeyPressed(LogicalKeyboardKeyCls::metaRight);
}

PhysicalKeyboardKey RawKeyEventCls::physicalKey() {
    return data->physicalKey;
}

LogicalKeyboardKey RawKeyEventCls::logicalKey() {
    return data->logicalKey;
}

void RawKeyEventCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<LogicalKeyboardKey>make<DiagnosticsPropertyCls>(__s("logicalKey"), logicalKey));
    properties->add(<PhysicalKeyboardKey>make<DiagnosticsPropertyCls>(__s("physicalKey"), physicalKey));
    if (is<RawKeyDownEvent>(this)) {
        properties->add(<bool>make<DiagnosticsPropertyCls>(__s("repeat"), repeat));
    }
}

RawKeyUpEventCls::RawKeyUpEventCls(Unknown character, Unknown data) : RawKeyEvent(false) {
}

void RawKeyboardCls::addListener(ValueChanged<RawKeyEvent> listener) {
    _listeners->add(listener);
}

void RawKeyboardCls::removeListener(ValueChanged<RawKeyEvent> listener) {
    _listeners->remove(listener);
}

RawKeyEventHandler RawKeyboardCls::keyEventHandler() {
    if (ServicesBindingCls::instance->keyEventManager->keyMessageHandler != _cachedKeyMessageHandler) {
        _cachedKeyMessageHandler = ServicesBindingCls::instance->keyEventManager->keyMessageHandler;
        _cachedKeyEventHandler = _cachedKeyMessageHandler == nullptr? nullptr : [=] (RawKeyEvent event) {
            assert(false, __s("The RawKeyboard.instance.keyEventHandler assigned by Flutter is a dummy callback kept for compatibility and should not be directly called. Use ServicesBinding.instance!.keyMessageHandler instead."));
            return true;
        };
    }
    return _cachedKeyEventHandler;
}

void RawKeyboardCls::keyEventHandler(RawKeyEventHandler handler) {
    _cachedKeyEventHandler = handler;
    _cachedKeyMessageHandler = handler == nullptr? nullptr : [=] (KeyMessage message) {
        if (message->rawEvent != nullptr) {
            return handler(message->rawEvent!);
        }
        return false;
    };
    ServicesBindingCls::instance->keyEventManager->keyMessageHandler = _cachedKeyMessageHandler;
}

bool RawKeyboardCls::handleRawKeyEvent(RawKeyEvent event) {
    if (is<RawKeyDownEvent>(event)) {
        _keysPressed[as<RawKeyDownEventCls>(event)->physicalKey] = as<RawKeyDownEventCls>(event)->logicalKey;
    } else     {
        if (is<RawKeyUpEvent>(event)) {
        _keysPressed->remove(as<RawKeyUpEventCls>(event)->physicalKey);
    }
;
    }    _synchronizeModifiers(event);
    assert(!is<RawKeyDownEvent>(event) || _keysPressed->isNotEmpty(), __s("Attempted to send a key down event when no keys are in keysPressed. This state can occur if the key event being sent doesn't properly set its modifier flags. This was the event: $event and its data: ${event.data}"));
    for (ValueChanged<RawKeyEvent> listener : <ValueChanged<RawKeyEvent>>of(_listeners)) {
        try {
            if (_listeners->contains(listener)) {
                listener(event);
            }
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] ()                 {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__s("while processing a raw key listener")), collector));
        };
    }
    return false;
}

Set<LogicalKeyboardKey> RawKeyboardCls::keysPressed() {
    return _keysPressed->values->toSet();
}

Set<PhysicalKeyboardKey> RawKeyboardCls::physicalKeysPressed() {
    return _keysPressed->keys->toSet();
}

LogicalKeyboardKey RawKeyboardCls::lookUpLayout(PhysicalKeyboardKey physicalKey) {
    return _keysPressed[physicalKey];
}

void RawKeyboardCls::clearKeysPressed() {
    return _keysPressed->clear();
}

void RawKeyboardCls::_synchronizeModifiers(RawKeyEvent event) {
    Map<ModifierKey, KeyboardSide> modifiersPressed = event->data->modifiersPressed;
    Map<PhysicalKeyboardKey, LogicalKeyboardKey> modifierKeys = makeMap(makeList(), makeList();
    Set<PhysicalKeyboardKey> anySideKeys = makeSet();
    Set<PhysicalKeyboardKey> set1 = make<SetCls<>>();for (auto _x1 : _keysPressed->keys) {{    set1.add(_x1);}if (is<RawKeyDownEvent>(event)) {    set1.add(ArrayItem);}Set<PhysicalKeyboardKey> keysPressedAfterEvent = list1;
    ModifierKey thisKeyModifier;
    for (ModifierKey key : ModifierKeyCls::values) {
        Set<PhysicalKeyboardKey> thisModifierKeys = _modifierKeyMap[make<_ModifierSidePairCls>(key, KeyboardSideCls::all)];
        if (thisModifierKeys == nullptr) {
            continue;
        }
        if (thisModifierKeys->contains(event->physicalKey)) {
            thisKeyModifier = key;
        }
        if (modifiersPressed[key] == KeyboardSideCls::any) {
            anySideKeys->addAll(thisModifierKeys);
            if (thisModifierKeys->any(keysPressedAfterEvent->contains)) {
                continue;
            }
        }
        Set<PhysicalKeyboardKey> mappedKeys = modifiersPressed[key] == nullptr? makeSet() : _modifierKeyMap[make<_ModifierSidePairCls>(key, modifiersPressed[key])];
        assert([=] () {
            if (mappedKeys == nullptr) {
                debugPrint(__s("Platform key support for ${Platform.operatingSystem} is producing unsupported modifier combinations for modifier $key on side ${modifiersPressed[key]}."));
                if (is<RawKeyEventDataAndroid>(event->data)) {
                    debugPrint(__s("Android raw key metaState: ${(event.data as RawKeyEventDataAndroid).metaState}"));
                }
            }
            return true;
        }());
        if (mappedKeys == nullptr) {
            continue;
        }
        for (PhysicalKeyboardKey physicalModifier : mappedKeys) {
            modifierKeys[physicalModifier] = _allModifiers[physicalModifier]!;
        }
    }
    _allModifiersExceptFn->keys->where([=] (PhysicalKeyboardKey key)     {
        !anySideKeys->contains(key);
    })->forEach(_keysPressed->remove);
    if (!is<RawKeyEventDataFuchsia>(event->data) && !is<RawKeyEventDataMacOs>(event->data)) {
        _keysPressed->remove(PhysicalKeyboardKeyCls::fn);
    }
    _keysPressed->addAll(modifierKeys);
    if (is<RawKeyDownEvent>(event) && thisKeyModifier != nullptr && !_keysPressed->containsKey(event->physicalKey)) {
        if (is<RawKeyEventDataLinux>(event->data) && event->physicalKey == PhysicalKeyboardKeyCls::altRight) {
            LogicalKeyboardKey logicalKey = _allModifiersExceptFn[event->physicalKey];
            if (logicalKey != nullptr) {
                _keysPressed[event->physicalKey] = logicalKey;
            }
        }
    }
}

bool _ModifierSidePairCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_ModifierSidePair>(other) && other->modifier == modifier && other->side == side;
}

int _ModifierSidePairCls::hashCode() {
    return ObjectCls->hash(modifier, side);
}
