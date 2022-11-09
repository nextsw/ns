#include "raw_keyboard_web.hpp"
String _unicodeChar(String key) {
    if (key->length == 1) {
        return key->substring(0, 1);
    }
    return nullptr;
}

RawKeyEventDataWebCls::RawKeyEventDataWebCls(String code, String key, int keyCode, int location, int metaState) {
    {
        assert(code != nullptr);
        assert(metaState != nullptr);
    }
}

String RawKeyEventDataWebCls::keyLabel() {
    return key == "Unidentified"? "" : _unicodeChar(key) ?? "";
}

PhysicalKeyboardKey RawKeyEventDataWebCls::physicalKey() {
    return kWebToPhysicalKey[code] ?? make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::webPlane + code->hashCode);
}

LogicalKeyboardKey RawKeyEventDataWebCls::logicalKey() {
    LogicalKeyboardKey maybeLocationKey = kWebLocationMap[key]?[location];
    if (maybeLocationKey != nullptr) {
        return maybeLocationKey;
    }
    LogicalKeyboardKey newKey = kWebToLogicalKey[code];
    if (newKey != nullptr) {
        return newKey;
    }
    bool isPrintable = key->length == 1;
    if (isPrintable) {
        return make<LogicalKeyboardKeyCls>(key->toLowerCase()->codeUnitAt(0));
    }
    return make<LogicalKeyboardKeyCls>(code->hashCode + LogicalKeyboardKeyCls::webPlane);
}

bool RawKeyEventDataWebCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    ;
}

KeyboardSide RawKeyEventDataWebCls::getModifierSide(ModifierKey key) {
    return KeyboardSideCls::any;
}

void RawKeyEventDataWebCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>("code", code));
    properties->add(<String>make<DiagnosticsPropertyCls>("key", key));
    properties->add(<int>make<DiagnosticsPropertyCls>("location", location));
    properties->add(<int>make<DiagnosticsPropertyCls>("metaState", metaState));
    properties->add(<int>make<DiagnosticsPropertyCls>("keyCode", keyCode));
}

bool RawKeyEventDataWebCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataWeb && other->code == code && other->key == key && other->location == location && other->metaState == metaState && other->keyCode == keyCode;
}

int RawKeyEventDataWebCls::hashCode() {
    return ObjectCls->hash(code, key, location, metaState, keyCode);
}
