#include "hardware_keyboard.hpp"
KeyboardLockMode KeyboardLockModeCls::findLockByLogicalKey(LogicalKeyboardKey logicalKey) {
    return _knownLockModes[logicalKey->keyId];
}

void KeyEventCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<PhysicalKeyboardKey>make<DiagnosticsPropertyCls>(__s("physicalKey"), physicalKey));
    properties->add(<LogicalKeyboardKey>make<DiagnosticsPropertyCls>(__s("logicalKey"), logicalKey));
    properties->add(make<StringPropertyCls>(__s("character"), character));
    properties->add(<Duration>make<DiagnosticsPropertyCls>(__s("timeStamp"), timeStamp));
    properties->add(make<FlagPropertyCls>(__s("synthesized"), synthesized, __s("synthesized")));
}

HardwareKeyboard HardwareKeyboardCls::instance() {
    return ServicesBindingCls::instance->keyboard;
}

Set<PhysicalKeyboardKey> HardwareKeyboardCls::physicalKeysPressed() {
    return _pressedKeys->keys()->toSet();
}

Set<LogicalKeyboardKey> HardwareKeyboardCls::logicalKeysPressed() {
    return _pressedKeys->values()->toSet();
}

LogicalKeyboardKey HardwareKeyboardCls::lookUpLayout(PhysicalKeyboardKey physicalKey) {
    return _pressedKeys[physicalKey];
}

Set<KeyboardLockMode> HardwareKeyboardCls::lockModesEnabled() {
    return _lockModes;
}

void HardwareKeyboardCls::addHandler(KeyEventCallback handler) {
    if (_duringDispatch) {
            List<KeyEventCallback> list1 = make<ListCls<>>();    for (auto _x1 : _handlers) {    {        list1.add(_x1);    }_modifiedHandlers |= list1;
        _modifiedHandlers!->add(handler);
    } else {
        _handlers->add(handler);
    }
}

void HardwareKeyboardCls::removeHandler(KeyEventCallback handler) {
    if (_duringDispatch) {
            List<KeyEventCallback> list1 = make<ListCls<>>();    for (auto _x1 : _handlers) {    {        list1.add(_x1);    }_modifiedHandlers |= list1;
        _modifiedHandlers!->remove(handler);
    } else {
        _handlers->remove(handler);
    }
}

bool HardwareKeyboardCls::handleKeyEvent(KeyEvent event) {
    _assertEventIsRegular(event);
    PhysicalKeyboardKey physicalKey = event->physicalKey;
    LogicalKeyboardKey logicalKey = event->logicalKey;
    if (is<KeyDownEvent>(event)) {
        _pressedKeys[physicalKey] = logicalKey;
        KeyboardLockMode lockMode = KeyboardLockModeCls->findLockByLogicalKey(as<KeyDownEventCls>(event)->logicalKey);
        if (lockMode != nullptr) {
            if (_lockModes->contains(lockMode)) {
                _lockModes->remove(lockMode);
            } else {
                _lockModes->add(lockMode);
            }
        }
    } else {
        if (is<KeyUpEvent>(event)) {
        _pressedKeys->remove(physicalKey);
    } else {
        if (is<KeyRepeatEvent>(event)) {
    }
;
    };
    }    return _dispatchKeyEvent(event);
}

void HardwareKeyboardCls::clearState() {
    _pressedKeys->clear();
    _lockModes->clear();
    _handlers->clear();
    assert(_modifiedHandlers == nullptr);
}

void HardwareKeyboardCls::_assertEventIsRegular(KeyEvent event) {
    assert([=] () {
        String common = __s("If this occurs in real application, please report this bug to Flutter. If this occurs in unit tests, please ensure that simulated events follow Flutter's event model as documented in `HardwareKeyboard`. This was the event: ");
        if (is<KeyDownEvent>(event)) {
            assert(!_pressedKeys->containsKey(as<KeyDownEventCls>(event)->physicalKey), __s("A ${event.runtimeType} is dispatched, but the state shows that the physical key is already pressed. $common$event"));
        } else {
            if (is<KeyRepeatEvent>(event) || is<KeyUpEvent>(event)) {
            assert(_pressedKeys->containsKey(event->physicalKey), __s("A ${event.runtimeType} is dispatched, but the state shows that the physical key is not pressed. $common$event"));
            assert(_pressedKeys[event->physicalKey] == event->logicalKey, __s("A ${event.runtimeType} is dispatched, but the state shows that the physical key is pressed on a different logical key. $common$event and the recorded logical key ${_pressedKeys[event.physicalKey]}"));
        } else {
            assert(false, __s("Unexpected key event class ${event.runtimeType}"));
        }
;
        }        return true;
    }());
}

bool HardwareKeyboardCls::_dispatchKeyEvent(KeyEvent event) {
    assert(!_duringDispatch, __s("Nested keyboard dispatching is not supported"));
    _duringDispatch = true;
    bool handled = false;
    for (KeyEventCallback handler : _handlers) {
        try {
            bool thisResult = handler(event);
            handled = handled || thisResult;
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] () {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__s("while processing a key handler")), collector));
        };
    }
    _duringDispatch = false;
    if (_modifiedHandlers != nullptr) {
        _handlers = _modifiedHandlers!;
        _modifiedHandlers = nullptr;
    }
    return handled;
}

String KeyMessageCls::toString() {
    return __s("KeyMessage($events)");
}

bool KeyEventManagerCls::handleKeyData(KeyData data) {
    _transitMode |= KeyDataTransitModeCls::keyDataThenRawKeyData;
    ;
}

Future<Map<String, dynamic>> KeyEventManagerCls::handleRawKeyMessage(dynamic message) {
    if (_transitMode == nullptr) {
        _transitMode = KeyDataTransitModeCls::rawKeyData;
        _rawKeyboard->addListener(_convertRawEventAndStore);
    }
    RawKeyEvent rawEvent = RawKeyEventCls->fromMessage(as<Map<String, dynamic>>(message));
    bool shouldDispatch = true;
    if (is<RawKeyDownEvent>(rawEvent)) {
        if (!as<RawKeyDownEventCls>(rawEvent)->data->shouldDispatchEvent()) {
            shouldDispatch = false;
            _skippedRawKeysPressed->add(rawEvent->physicalKey());
        } else {
            _skippedRawKeysPressed->remove(rawEvent->physicalKey());
        }
    } else {
        if (is<RawKeyUpEvent>(rawEvent)) {
        if (_skippedRawKeysPressed->contains(as<RawKeyUpEventCls>(rawEvent)->physicalKey())) {
            _skippedRawKeysPressed->remove(rawEvent->physicalKey());
            shouldDispatch = false;
        }
    }
;
    }    bool handled = true;
    if (shouldDispatch) {
        handled = _rawKeyboard->handleRawKeyEvent(rawEvent);
        for (KeyEvent event : _keyEventsSinceLastMessage) {
            handled = _hardwareKeyboard->handleKeyEvent(event) || handled;
        }
        if (_transitMode == KeyDataTransitModeCls::rawKeyData) {
            assert(setEquals(_rawKeyboard->physicalKeysPressed(), _hardwareKeyboard->physicalKeysPressed()), __s("RawKeyboard reported ${_rawKeyboard.physicalKeysPressed}, while HardwareKeyboard reported ${_hardwareKeyboard.physicalKeysPressed}"));
        }
        handled = _dispatchKeyMessage(_keyEventsSinceLastMessage, rawEvent) || handled;
        _keyEventsSinceLastMessage->clear();
    }
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("handled"), handled);return list1;
}

void KeyEventManagerCls::clearState() {
    assert([=] () {
        _transitMode = nullptr;
        _rawKeyboard->removeListener(_convertRawEventAndStore);
        _keyEventsSinceLastMessage->clear();
        return true;
    }());
}

bool KeyEventManagerCls::_dispatchKeyMessage(List<KeyEvent> keyEvents, RawKeyEvent rawEvent) {
    if (keyMessageHandler != nullptr) {
        KeyMessage message = make<KeyMessageCls>(keyEvents, rawEvent);
        try {
            return keyMessageHandler!(message);
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] () {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__s("while processing the key message handler")), collector));
        };
    }
    return false;
}

void KeyEventManagerCls::_convertRawEventAndStore(RawKeyEvent rawEvent) {
    PhysicalKeyboardKey physicalKey = rawEvent->physicalKey();
    LogicalKeyboardKey logicalKey = rawEvent->logicalKey();
    Set<PhysicalKeyboardKey> physicalKeysPressed = _hardwareKeyboard->physicalKeysPressed();
    List<KeyEvent> eventAfterwards = makeList();
    KeyEvent mainEvent;
    LogicalKeyboardKey recordedLogicalMain = _hardwareKeyboard->lookUpLayout(physicalKey);
    Duration timeStamp = ServicesBindingCls::instance->currentSystemFrameTimeStamp;
    String character = rawEvent->character == __s("")? nullptr : rawEvent->character;
    if (is<RawKeyDownEvent>(rawEvent)) {
        if (recordedLogicalMain == nullptr) {
            mainEvent = make<KeyDownEventCls>(physicalKey, logicalKey, character, timeStamp);
            physicalKeysPressed->add(physicalKey);
        } else {
            assert(physicalKeysPressed->contains(physicalKey));
            mainEvent = make<KeyRepeatEventCls>(physicalKey, recordedLogicalMain, character, timeStamp);
        }
    } else {
        assert(is<RawKeyUpEvent>(rawEvent), __s("Unexpected subclass of RawKeyEvent: ${rawEvent.runtimeType}"));
        if (recordedLogicalMain == nullptr) {
            mainEvent = nullptr;
        } else {
            mainEvent = make<KeyUpEventCls>(recordedLogicalMain, physicalKey, timeStamp);
            physicalKeysPressed->remove(physicalKey);
        }
    }
    for (PhysicalKeyboardKey key : physicalKeysPressed->difference(_rawKeyboard->physicalKeysPressed)) {
        if (key == physicalKey) {
            eventAfterwards->add(make<KeyUpEventCls>(key, logicalKey, timeStamp, true));
        } else {
            _keyEventsSinceLastMessage->add(make<KeyUpEventCls>(key, _hardwareKeyboard->lookUpLayout(key)!, timeStamp, true));
        }
    }
    for (PhysicalKeyboardKey key : _rawKeyboard->physicalKeysPressed->difference(physicalKeysPressed)) {
        _keyEventsSinceLastMessage->add(make<KeyDownEventCls>(key, _rawKeyboard->lookUpLayout(key)!, timeStamp, true));
    }
    if (mainEvent != nullptr) {
        _keyEventsSinceLastMessage->add(mainEvent);
    }
    _keyEventsSinceLastMessage->addAll(eventAfterwards);
}

KeyEvent KeyEventManagerCls::_eventFromData(KeyData keyData) {
    PhysicalKeyboardKey physicalKey = PhysicalKeyboardKeyCls->findKeyByCode(keyData->physical) | make<PhysicalKeyboardKeyCls>(keyData->physical);
    LogicalKeyboardKey logicalKey = LogicalKeyboardKeyCls->findKeyByKeyId(keyData->logical) | make<LogicalKeyboardKeyCls>(keyData->logical);
    Duration timeStamp = keyData->timeStamp;
    ;
}
