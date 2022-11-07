#include "raw_keyboard_ios.hpp"
RawKeyEventDataIos::RawKeyEventDataIos(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers) {
    {
        assert(characters != nullptr);
        assert(charactersIgnoringModifiers != nullptr);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataIos::keyLabel() {
    return charactersIgnoringModifiers;
}

PhysicalKeyboardKey RawKeyEventDataIos::physicalKey() {
    return kIosToPhysicalKey[keyCode] ?? PhysicalKeyboardKey(LogicalKeyboardKey.iosPlane + keyCode);
}

LogicalKeyboardKey RawKeyEventDataIos::logicalKey() {
    LogicalKeyboardKey numPadKey = kIosNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    LogicalKeyboardKey newKey = _kIosToLogicalMap[keyLabel];
    if (newKey != nullptr) {
        return newKey;
    }
    LogicalKeyboardKey knownKey = kIosToLogicalKey[keyCode];
    if (knownKey != nullptr) {
        return knownKey;
    }
    if (keyLabel.isNotEmpty && !LogicalKeyboardKey.isControlCharacter(keyLabel) && !_isUnprintableKey(keyLabel)) {
        assert(charactersIgnoringModifiers.length <= 2);
        int codeUnit = charactersIgnoringModifiers.codeUnitAt(0);
        if (charactersIgnoringModifiers.length == 2) {
            int secondCode = charactersIgnoringModifiers.codeUnitAt(1);
            codeUnit = (codeUnit << 16) | secondCode;
        }
        int keyId = LogicalKeyboardKey.unicodePlane | (codeUnit & LogicalKeyboardKey.valueMask);
        return LogicalKeyboardKey.findKeyByKeyId(keyId) ?? LogicalKeyboardKey(keyId);
    }
    return LogicalKeyboardKey(keyCode | LogicalKeyboardKey.iosPlane);
}

bool RawKeyEventDataIos::isModifierPressed(ModifierKey key, KeyboardSide side) {
    int independentModifier = modifiers & deviceIndependentMask;
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, "$runtimeType thinks that a modifier is pressed, but can't figure out what side it's on.");
    return result;
}

KeyboardSide RawKeyEventDataIos::getModifierSide(ModifierKey key) {
    ;
    ;
}

void RawKeyEventDataIos::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<String>DiagnosticsProperty("characters", characters));
    properties.add(<String>DiagnosticsProperty("charactersIgnoringModifiers", charactersIgnoringModifiers));
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
    properties.add(<int>DiagnosticsProperty("modifiers", modifiers));
}

bool RawKeyEventDataIos::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataIos && other.characters == characters && other.charactersIgnoringModifiers == charactersIgnoringModifiers && other.keyCode == keyCode && other.modifiers == modifiers;
}

int RawKeyEventDataIos::hashCode() {
    return Object.hash(characters, charactersIgnoringModifiers, keyCode, modifiers);
}

bool RawKeyEventDataIos::_isUnprintableKey(String label) {
    if (label.length != 1) {
        return false;
    }
    int codeUnit = label.codeUnitAt(0);
    return codeUnit >= 0xF700 && codeUnit <= 0xF8FF;
}

bool RawKeyEventDataIos::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}
