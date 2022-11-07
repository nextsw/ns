#include "raw_keyboard_android.hpp"
RawKeyEventDataAndroid::RawKeyEventDataAndroid(int codePoint, int deviceId, int eventSource, int flags, int keyCode, int metaState, int plainCodePoint, int productId, int repeatCount, int scanCode, int vendorId) {
    {
        assert(flags != nullptr);
        assert(codePoint != nullptr);
        assert(keyCode != nullptr);
        assert(scanCode != nullptr);
        assert(metaState != nullptr);
    }
}

String RawKeyEventDataAndroid::keyLabel() {
    return plainCodePoint == 0? "" : String.fromCharCode(plainCodePoint & _kCombiningCharacterMask);
}

PhysicalKeyboardKey RawKeyEventDataAndroid::physicalKey() {
    if (kAndroidToPhysicalKey.containsKey(scanCode)) {
        return kAndroidToPhysicalKey[scanCode]!;
    }
    if (eventSource & _sourceJoystick == _sourceJoystick) {
        LogicalKeyboardKey foundKey = kAndroidToLogicalKey[keyCode];
        if (foundKey == LogicalKeyboardKey.arrowUp) {
            return PhysicalKeyboardKey.arrowUp;
        }
        if (foundKey == LogicalKeyboardKey.arrowDown) {
            return PhysicalKeyboardKey.arrowDown;
        }
        if (foundKey == LogicalKeyboardKey.arrowLeft) {
            return PhysicalKeyboardKey.arrowLeft;
        }
        if (foundKey == LogicalKeyboardKey.arrowRight) {
            return PhysicalKeyboardKey.arrowRight;
        }
    }
    return PhysicalKeyboardKey(LogicalKeyboardKey.androidPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataAndroid::logicalKey() {
    LogicalKeyboardKey numPadKey = kAndroidNumPadMap[keyCode];
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel.isNotEmpty && !LogicalKeyboardKey.isControlCharacter(keyLabel)) {
        int combinedCodePoint = plainCodePoint & _kCombiningCharacterMask;
        int keyId = LogicalKeyboardKey.unicodePlane | (combinedCodePoint & LogicalKeyboardKey.valueMask);
        return LogicalKeyboardKey.findKeyByKeyId(keyId) ?? LogicalKeyboardKey(keyId);
    }
    LogicalKeyboardKey newKey = kAndroidToLogicalKey[keyCode];
    if (newKey != nullptr) {
        return newKey;
    }
    return LogicalKeyboardKey(keyCode | LogicalKeyboardKey.androidPlane);
}

bool RawKeyEventDataAndroid::isModifierPressed(ModifierKey key, KeyboardSide side) {
    assert(side != nullptr);
    ;
}

KeyboardSide RawKeyEventDataAndroid::getModifierSide(ModifierKey key) {
    ;
    ;
}

void RawKeyEventDataAndroid::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<int>DiagnosticsProperty("flags", flags));
    properties.add(<int>DiagnosticsProperty("codePoint", codePoint));
    properties.add(<int>DiagnosticsProperty("plainCodePoint", plainCodePoint));
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
    properties.add(<int>DiagnosticsProperty("scanCode", scanCode));
    properties.add(<int>DiagnosticsProperty("metaState", metaState));
}

bool RawKeyEventDataAndroid::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataAndroid && other.flags == flags && other.codePoint == codePoint && other.plainCodePoint == plainCodePoint && other.keyCode == keyCode && other.scanCode == scanCode && other.metaState == metaState;
}

int RawKeyEventDataAndroid::hashCode() {
    return Object.hash(flags, codePoint, plainCodePoint, keyCode, scanCode, metaState);
}

bool RawKeyEventDataAndroid::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (metaState & anyMask == 0) {
        return false;
    }
    ;
}
