#include "raw_keyboard_android.hpp"
RawKeyEventDataAndroidCls::RawKeyEventDataAndroidCls(int codePoint, int deviceId, int eventSource, int flags, int keyCode, int metaState, int plainCodePoint, int productId, int repeatCount, int scanCode, int vendorId) {
    {
        assert(flags != nullptr);
        assert(codePoint != nullptr);
        assert(keyCode != nullptr);
        assert(scanCode != nullptr);
        assert(metaState != nullptr);
    }
}

String RawKeyEventDataAndroidCls::keyLabel() {
    return plainCodePoint == 0? __s("") : StringCls->fromCharCode(plainCodePoint & _kCombiningCharacterMask);
}

PhysicalKeyboardKey RawKeyEventDataAndroidCls::physicalKey() {
    if (kAndroidToPhysicalKey->containsKey(scanCode)) {
        return kAndroidToPhysicalKey[scanCode]!;
    }
    if (eventSource & _sourceJoystick == _sourceJoystick) {
        LogicalKeyboardKey foundKey = kAndroidToLogicalKey[keyCode];
        if (foundKey == LogicalKeyboardKeyCls::arrowUp) {
            return PhysicalKeyboardKeyCls::arrowUp;
        }
        if (foundKey == LogicalKeyboardKeyCls::arrowDown) {
            return PhysicalKeyboardKeyCls::arrowDown;
        }
        if (foundKey == LogicalKeyboardKeyCls::arrowLeft) {
            return PhysicalKeyboardKeyCls::arrowLeft;
        }
        if (foundKey == LogicalKeyboardKeyCls::arrowRight) {
            return PhysicalKeyboardKeyCls::arrowRight;
        }
    }
    return make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::androidPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataAndroidCls::logicalKey() {
    LogicalKeyboardKey numPadKey = kAndroidNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel()->isNotEmpty() && !LogicalKeyboardKeyCls->isControlCharacter(keyLabel())) {
        int combinedCodePoint = plainCodePoint & _kCombiningCharacterMask;
        int keyId = LogicalKeyboardKeyCls::unicodePlane | (combinedCodePoint & LogicalKeyboardKeyCls::valueMask);
        return LogicalKeyboardKeyCls->findKeyByKeyId(keyId) or make<LogicalKeyboardKeyCls>(keyId);
    }
    LogicalKeyboardKey newKey = kAndroidToLogicalKey[keyCode];
    if (newKey != nullptr) {
        return newKey;
    }
    return make<LogicalKeyboardKeyCls>(keyCode | LogicalKeyboardKeyCls::androidPlane);
}

bool RawKeyEventDataAndroidCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    assert(side != nullptr);
    ;
}

KeyboardSide RawKeyEventDataAndroidCls::getModifierSide(ModifierKey key) {
    InlineMethod;
    ;
}

void RawKeyEventDataAndroidCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("flags"), flags));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("codePoint"), codePoint));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("plainCodePoint"), plainCodePoint));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("keyCode"), keyCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("scanCode"), scanCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("metaState"), metaState));
}

bool RawKeyEventDataAndroidCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RawKeyEventDataAndroid>(other) && other->flags == flags && other->codePoint == codePoint && other->plainCodePoint == plainCodePoint && other->keyCode == keyCode && other->scanCode == scanCode && other->metaState == metaState;
}

int RawKeyEventDataAndroidCls::hashCode() {
    return ObjectCls->hash(flags, codePoint, plainCodePoint, keyCode, scanCode, metaState);
}

bool RawKeyEventDataAndroidCls::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (metaState & anyMask == 0) {
        return false;
    }
    ;
}
