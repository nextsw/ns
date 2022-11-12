#include "raw_keyboard_macos.hpp"
int runeToLowerCase(int rune) {
    int utf16BmpUpperBound = 0xD7FF;
    if (rune > utf16BmpUpperBound) {
        return rune;
    }
    return StringCls->fromCharCode(rune)->toLowerCase()->codeUnitAt(0);
}

RawKeyEventDataMacOsCls::RawKeyEventDataMacOsCls(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers, int specifiedLogicalKey) {
    {
        assert(characters != nullptr);
        assert(charactersIgnoringModifiers != nullptr);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataMacOsCls::keyLabel() {
    return charactersIgnoringModifiers;
}

PhysicalKeyboardKey RawKeyEventDataMacOsCls::physicalKey() {
    return kMacOsToPhysicalKey[keyCode] | make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::windowsPlane + keyCode);
}

LogicalKeyboardKey RawKeyEventDataMacOsCls::logicalKey() {
    if (specifiedLogicalKey != nullptr) {
        int key = specifiedLogicalKey!;
        return LogicalKeyboardKeyCls->findKeyByKeyId(key) | make<LogicalKeyboardKeyCls>(key);
    }
    LogicalKeyboardKey numPadKey = kMacOsNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    LogicalKeyboardKey knownKey = kMacOsToLogicalKey[keyCode];
    if (knownKey != nullptr) {
        return knownKey;
    }
    int character;
    if (keyLabel()->isNotEmpty()) {
        List<int> codePoints = keyLabel()->runes()->toList();
        if (codePoints->length() == 1 && !LogicalKeyboardKeyCls->isControlCharacter(keyLabel()) && !_isUnprintableKey(keyLabel())) {
            character = runeToLowerCase(codePoints[0]);
        }
    }
    if (character != nullptr) {
        int keyId = LogicalKeyboardKeyCls::unicodePlane | (character & LogicalKeyboardKeyCls::valueMask);
        return LogicalKeyboardKeyCls->findKeyByKeyId(keyId) | make<LogicalKeyboardKeyCls>(keyId);
    }
    return make<LogicalKeyboardKeyCls>(keyCode | LogicalKeyboardKeyCls::macosPlane);
}

bool RawKeyEventDataMacOsCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    int independentModifier = modifiers & deviceIndependentMask;
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, __s("%s)"));
    return result;
}

KeyboardSide RawKeyEventDataMacOsCls::getModifierSide(ModifierKey key) {
    InlineMethod;
    ;
}

bool RawKeyEventDataMacOsCls::shouldDispatchEvent() {
    return logicalKey() != LogicalKeyboardKeyCls::fn;
}

void RawKeyEventDataMacOsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("characters"), characters));
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("charactersIgnoringModifiers"), charactersIgnoringModifiers));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("keyCode"), keyCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("modifiers"), modifiers));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("specifiedLogicalKey"), specifiedLogicalKey, nullptr));
}

bool RawKeyEventDataMacOsCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RawKeyEventDataMacOs>(other) && other->characters == characters && other->charactersIgnoringModifiers == charactersIgnoringModifiers && other->keyCode == keyCode && other->modifiers == modifiers;
}

int RawKeyEventDataMacOsCls::hashCode() {
    return ObjectCls->hash(characters, charactersIgnoringModifiers, keyCode, modifiers);
}

bool RawKeyEventDataMacOsCls::_isLeftRightModifierPressed(KeyboardSide side, int anyMask, int leftMask, int rightMask) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}

bool RawKeyEventDataMacOsCls::_isUnprintableKey(String label) {
    if (label->length() != 1) {
        return false;
    }
    int codeUnit = label->codeUnitAt(0);
    return codeUnit >= 0xF700 && codeUnit <= 0xF8FF;
}
