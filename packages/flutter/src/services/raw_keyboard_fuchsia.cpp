#include "raw_keyboard_fuchsia.hpp"
RawKeyEventDataFuchsia::RawKeyEventDataFuchsia(int codePoint, int hidUsage, int modifiers) {
    {
        assert(hidUsage != nullptr);
        assert(codePoint != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataFuchsia::keyLabel() {
    return codePoint == 0? "" : String.fromCharCode(codePoint);
}

LogicalKeyboardKey RawKeyEventDataFuchsia::logicalKey() {
    if (codePoint != 0) {
        int flutterId = LogicalKeyboardKey.unicodePlane | codePoint & LogicalKeyboardKey.valueMask;
        return kFuchsiaToLogicalKey[flutterId] ?? LogicalKeyboardKey(LogicalKeyboardKey.unicodePlane | codePoint & LogicalKeyboardKey.valueMask);
    }
    LogicalKeyboardKey newKey = kFuchsiaToLogicalKey[hidUsage | LogicalKeyboardKey.fuchsiaPlane];
    if (newKey != nullptr) {
        return newKey;
    }
    return LogicalKeyboardKey(hidUsage | LogicalKeyboardKey.fuchsiaPlane);
}

PhysicalKeyboardKey RawKeyEventDataFuchsia::physicalKey() {
    return kFuchsiaToPhysicalKey[hidUsage] ?? PhysicalKeyboardKey(LogicalKeyboardKey.fuchsiaPlane + hidUsage);
}

bool RawKeyEventDataFuchsia::isModifierPressed(ModifierKey key, KeyboardSide side) {
    assert(side != nullptr);
    ;
}

KeyboardSide RawKeyEventDataFuchsia::getModifierSide(ModifierKey key) {
    ;
    ;
}

void RawKeyEventDataFuchsia::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<int>DiagnosticsProperty("hidUsage", hidUsage));
    properties.add(<int>DiagnosticsProperty("codePoint", codePoint));
    properties.add(<int>DiagnosticsProperty("modifiers", modifiers));
}

bool RawKeyEventDataFuchsia::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataFuchsia && other.hidUsage == hidUsage && other.codePoint == codePoint && other.modifiers == modifiers;
}

int RawKeyEventDataFuchsia::hashCode() {
    return Object.hash(hidUsage, codePoint, modifiers);
}

bool RawKeyEventDataFuchsia::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    ;
}
