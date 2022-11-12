#include "raw_keyboard_windows.hpp"
RawKeyEventDataWindowsCls::RawKeyEventDataWindowsCls(int characterCodePoint, int keyCode, int modifiers, int scanCode) {
    {
        assert(keyCode != nullptr);
        assert(scanCode != nullptr);
        assert(characterCodePoint != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataWindowsCls::keyLabel() {
    return characterCodePoint == 0? __s("") : StringCls->fromCharCode(characterCodePoint);
}

PhysicalKeyboardKey RawKeyEventDataWindowsCls::physicalKey() {
    return kWindowsToPhysicalKey[scanCode] | make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::windowsPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataWindowsCls::logicalKey() {
    LogicalKeyboardKey numPadKey = kWindowsNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel()->isNotEmpty() && !LogicalKeyboardKeyCls->isControlCharacter(keyLabel())) {
        int keyId = LogicalKeyboardKeyCls::unicodePlane | (characterCodePoint & LogicalKeyboardKeyCls::valueMask);
        return LogicalKeyboardKeyCls->findKeyByKeyId(keyId) | make<LogicalKeyboardKeyCls>(keyId);
    }
    LogicalKeyboardKey newKey = kWindowsToLogicalKey[keyCode];
    if (newKey != nullptr) {
        return newKey;
    }
    return make<LogicalKeyboardKeyCls>(keyCode | LogicalKeyboardKeyCls::windowsPlane);
}

bool RawKeyEventDataWindowsCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    bool result;
    ;
    assert(!result || getModifierSide(key) != nullptr, __s("%s)"));
    return result;
}

KeyboardSide RawKeyEventDataWindowsCls::getModifierSide(ModifierKey key) {
    InlineMethod;
    ;
}

bool RawKeyEventDataWindowsCls::shouldDispatchEvent() {
    return keyCode != _vkProcessKey;
}

void RawKeyEventDataWindowsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("keyCode"), keyCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("scanCode"), scanCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("characterCodePoint"), characterCodePoint));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("modifiers"), modifiers));
}

bool RawKeyEventDataWindowsCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RawKeyEventDataWindows>(other) && other->keyCode == keyCode && other->scanCode == scanCode && other->characterCodePoint == characterCodePoint && other->modifiers == modifiers;
}

int RawKeyEventDataWindowsCls::hashCode() {
    return ObjectCls->hash(keyCode, scanCode, characterCodePoint, modifiers);
}

bool RawKeyEventDataWindowsCls::_isLeftRightModifierPressed(KeyboardSide side, int anyMask, int leftMask, int rightMask) {
    if (modifiers & anyMask == 0 && modifiers & leftMask == 0 && modifiers & rightMask == 0) {
        return false;
    }
    bool anyOnly = modifiers & (leftMask | rightMask | anyMask) == anyMask;
    ;
}
