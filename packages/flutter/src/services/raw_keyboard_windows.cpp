#include "raw_keyboard_windows.hpp"
RawKeyEventDataWindows::RawKeyEventDataWindows(int characterCodePoint, int keyCode, int modifiers, int scanCode) {
    {
        assert(keyCode != nullptr);
        assert(scanCode != nullptr);
        assert(characterCodePoint != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataWindows::keyLabel() {
    return characterCodePoint == 0? "" : String.fromCharCode(characterCodePoint);
}

PhysicalKeyboardKey RawKeyEventDataWindows::physicalKey() {
    return kWindowsToPhysicalKey[scanCode] ?? PhysicalKeyboardKey(LogicalKeyboardKey.windowsPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataWindows::logicalKey() {
    LogicalKeyboardKey numPadKey = kWindowsNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel.isNotEmpty && !LogicalKeyboardKey.isControlCharacter(keyLabel)) {
        int keyId = LogicalKeyboardKey.unicodePlane | (characterCodePoint & LogicalKeyboardKey.valueMask);
        return LogicalKeyboardKey.findKeyByKeyId(keyId) ?? LogicalKeyboardKey(keyId);
    }
    LogicalKeyboardKey newKey = kWindowsToLogicalKey[keyCode];
    if (newKey != nullptr) {
        return newKey;
    }
    return LogicalKeyboardKey(keyCode | LogicalKeyboardKey.windowsPlane);
}

bool RawKeyEventDataWindows::isModifierPressed(ModifierKey key, KeyboardSide side) {
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, "$runtimeType thinks that a modifier is pressed, but can't figure out what side it's on.");
    return result;
}

KeyboardSide RawKeyEventDataWindows::getModifierSide(ModifierKey key) {
    ;
    ;
}

bool RawKeyEventDataWindows::shouldDispatchEvent() {
    return keyCode != _vkProcessKey;
}

void RawKeyEventDataWindows::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
    properties.add(<int>DiagnosticsProperty("scanCode", scanCode));
    properties.add(<int>DiagnosticsProperty("characterCodePoint", characterCodePoint));
    properties.add(<int>DiagnosticsProperty("modifiers", modifiers));
}

bool RawKeyEventDataWindows::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataWindows && other.keyCode == keyCode && other.scanCode == scanCode && other.characterCodePoint == characterCodePoint && other.modifiers == modifiers;
}

int RawKeyEventDataWindows::hashCode() {
    return Object.hash(keyCode, scanCode, characterCodePoint, modifiers);
}

bool RawKeyEventDataWindows::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0 && modifiers & leftMask == 0 && modifiers & rightMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}
