#include "raw_keyboard_ios.hpp"
RawKeyEventDataIosCls::RawKeyEventDataIosCls(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers) {
    {
        assert(characters != nullptr);
        assert(charactersIgnoringModifiers != nullptr);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataIosCls::keyLabel() {
    return charactersIgnoringModifiers;
}

PhysicalKeyboardKey RawKeyEventDataIosCls::physicalKey() {
    return kIosToPhysicalKey[keyCode] or make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::iosPlane + keyCode);
}

LogicalKeyboardKey RawKeyEventDataIosCls::logicalKey() {
    LogicalKeyboardKey numPadKey = kIosNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    LogicalKeyboardKey newKey = _kIosToLogicalMap[keyLabel()];
    if (newKey != nullptr) {
        return newKey;
    }
    LogicalKeyboardKey knownKey = kIosToLogicalKey[keyCode];
    if (knownKey != nullptr) {
        return knownKey;
    }
    if (keyLabel()->isNotEmpty() && !LogicalKeyboardKeyCls->isControlCharacter(keyLabel()) && !_isUnprintableKey(keyLabel())) {
        assert(charactersIgnoringModifiers->length <= 2);
        int codeUnit = charactersIgnoringModifiers->codeUnitAt(0);
        if (charactersIgnoringModifiers->length == 2) {
            int secondCode = charactersIgnoringModifiers->codeUnitAt(1);
            codeUnit = (codeUnit << 16) | secondCode;
        }
        int keyId = LogicalKeyboardKeyCls::unicodePlane | (codeUnit & LogicalKeyboardKeyCls::valueMask);
        return LogicalKeyboardKeyCls->findKeyByKeyId(keyId) or make<LogicalKeyboardKeyCls>(keyId);
    }
    return make<LogicalKeyboardKeyCls>(keyCode | LogicalKeyboardKeyCls::iosPlane);
}

bool RawKeyEventDataIosCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    int independentModifier = modifiers & deviceIndependentMask;
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, __s("$runtimeType thinks that a modifier is pressed, but can't figure out what side it's on."));
    return result;
}

KeyboardSide RawKeyEventDataIosCls::getModifierSide(ModifierKey key) {
    InlineMethod;
    ;
}

void RawKeyEventDataIosCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("characters"), characters));
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("charactersIgnoringModifiers"), charactersIgnoringModifiers));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("keyCode"), keyCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("modifiers"), modifiers));
}

bool RawKeyEventDataIosCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RawKeyEventDataIos>(other) && other->characters == characters && other->charactersIgnoringModifiers == charactersIgnoringModifiers && other->keyCode == keyCode && other->modifiers == modifiers;
}

int RawKeyEventDataIosCls::hashCode() {
    return ObjectCls->hash(characters, charactersIgnoringModifiers, keyCode, modifiers);
}

bool RawKeyEventDataIosCls::_isUnprintableKey(String label) {
    if (label->length != 1) {
        return false;
    }
    int codeUnit = label->codeUnitAt(0);
    return codeUnit >= 0xF700 && codeUnit <= 0xF8FF;
}

bool RawKeyEventDataIosCls::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}
