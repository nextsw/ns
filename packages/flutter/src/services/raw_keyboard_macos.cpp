#include "raw_keyboard_macos.hpp"
int runeToLowerCase(int rune) {
    int utf16BmpUpperBound = 0xD7FF;
    if (rune > utf16BmpUpperBound) {
        return rune;
    }
    return String.fromCharCode(rune).toLowerCase().codeUnitAt(0);
}

RawKeyEventDataMacOs::RawKeyEventDataMacOs(String characters, String charactersIgnoringModifiers, int keyCode, int modifiers, int specifiedLogicalKey) {
    {
        assert(characters != nullptr);
        assert(charactersIgnoringModifiers != nullptr);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataMacOs::keyLabel() {
    return charactersIgnoringModifiers;
}

PhysicalKeyboardKey RawKeyEventDataMacOs::physicalKey() {
    return kMacOsToPhysicalKey[keyCode] ?? PhysicalKeyboardKey(LogicalKeyboardKey.windowsPlane + keyCode);
}

LogicalKeyboardKey RawKeyEventDataMacOs::logicalKey() {
    if (specifiedLogicalKey != nullptr) {
        int key = specifiedLogicalKey!;
        return LogicalKeyboardKey.findKeyByKeyId(key) ?? LogicalKeyboardKey(key);
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
    if (keyLabel.isNotEmpty) {
        List<int> codePoints = keyLabel.runes.toList();
        if (codePoints.length == 1 && !LogicalKeyboardKey.isControlCharacter(keyLabel) && !_isUnprintableKey(keyLabel)) {
            character = runeToLowerCase(codePoints[0]);
        }
    }
    if (character != nullptr) {
        int keyId = LogicalKeyboardKey.unicodePlane | (character & LogicalKeyboardKey.valueMask);
        return LogicalKeyboardKey.findKeyByKeyId(keyId) ?? LogicalKeyboardKey(keyId);
    }
    return LogicalKeyboardKey(keyCode | LogicalKeyboardKey.macosPlane);
}

bool RawKeyEventDataMacOs::isModifierPressed(ModifierKey key, KeyboardSide side) {
    int independentModifier = modifiers & deviceIndependentMask;
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, "$runtimeType thinks that a modifier is pressed, but can't figure out what side it's on.");
    return result;
}

KeyboardSide RawKeyEventDataMacOs::getModifierSide(ModifierKey key) {
    ;
    ;
}

bool RawKeyEventDataMacOs::shouldDispatchEvent() {
    return logicalKey != LogicalKeyboardKey.fn;
}

void RawKeyEventDataMacOs::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<String>DiagnosticsProperty("characters", characters));
    properties.add(<String>DiagnosticsProperty("charactersIgnoringModifiers", charactersIgnoringModifiers));
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
    properties.add(<int>DiagnosticsProperty("modifiers", modifiers));
    properties.add(<int>DiagnosticsProperty("specifiedLogicalKey", specifiedLogicalKeynullptr));
}

bool RawKeyEventDataMacOs::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataMacOs && other.characters == characters && other.charactersIgnoringModifiers == charactersIgnoringModifiers && other.keyCode == keyCode && other.modifiers == modifiers;
}

int RawKeyEventDataMacOs::hashCode() {
    return Object.hash(characters, charactersIgnoringModifiers, keyCode, modifiers);
}

bool RawKeyEventDataMacOs::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}

bool RawKeyEventDataMacOs::_isUnprintableKey(String label) {
    if (label.length != 1) {
        return false;
    }
    int codeUnit = label.codeUnitAt(0);
    return codeUnit >= 0xF700 && codeUnit <= 0xF8FF;
}
