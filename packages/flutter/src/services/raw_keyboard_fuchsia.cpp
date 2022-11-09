#include "raw_keyboard_fuchsia.hpp"
RawKeyEventDataFuchsiaCls::RawKeyEventDataFuchsiaCls(int codePoint, int hidUsage, int modifiers) {
    {
        assert(hidUsage != nullptr);
        assert(codePoint != nullptr);
        assert(modifiers != nullptr);
    }
}

String RawKeyEventDataFuchsiaCls::keyLabel() {
    return codePoint == 0? "" : StringCls->fromCharCode(codePoint);
}

LogicalKeyboardKey RawKeyEventDataFuchsiaCls::logicalKey() {
    if (codePoint != 0) {
        int flutterId = LogicalKeyboardKeyCls::unicodePlane | codePoint & LogicalKeyboardKeyCls::valueMask;
        return kFuchsiaToLogicalKey[flutterId] ?? make<LogicalKeyboardKeyCls>(LogicalKeyboardKeyCls::unicodePlane | codePoint & LogicalKeyboardKeyCls::valueMask);
    }
    LogicalKeyboardKey newKey = kFuchsiaToLogicalKey[hidUsage | LogicalKeyboardKeyCls::fuchsiaPlane];
    if (newKey != nullptr) {
        return newKey;
    }
    return make<LogicalKeyboardKeyCls>(hidUsage | LogicalKeyboardKeyCls::fuchsiaPlane);
}

PhysicalKeyboardKey RawKeyEventDataFuchsiaCls::physicalKey() {
    return kFuchsiaToPhysicalKey[hidUsage] ?? make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::fuchsiaPlane + hidUsage);
}

bool RawKeyEventDataFuchsiaCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    assert(side != nullptr);
    ;
}

KeyboardSide RawKeyEventDataFuchsiaCls::getModifierSide(ModifierKey key) {
    InlineMethod;
    ;
}

void RawKeyEventDataFuchsiaCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<int>make<DiagnosticsPropertyCls>("hidUsage", hidUsage));
    properties->add(<int>make<DiagnosticsPropertyCls>("codePoint", codePoint));
    properties->add(<int>make<DiagnosticsPropertyCls>("modifiers", modifiers));
}

bool RawKeyEventDataFuchsiaCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataFuchsia && other->hidUsage == hidUsage && other->codePoint == codePoint && other->modifiers == modifiers;
}

int RawKeyEventDataFuchsiaCls::hashCode() {
    return ObjectCls->hash(hidUsage, codePoint, modifiers);
}

bool RawKeyEventDataFuchsiaCls::_isLeftRightModifierPressed(int anyMask, int leftMask, int rightMask, KeyboardSide side) {
    if (modifiers & anyMask == 0) {
        return false;
    }
    ;
}
