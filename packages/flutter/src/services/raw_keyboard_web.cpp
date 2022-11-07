#include "raw_keyboard_web.hpp"
String _unicodeChar(String key) {
    if (key.length == 1) {
        return key.substring(0, 1);
    }
    return nullptr;
}

RawKeyEventDataWeb::RawKeyEventDataWeb(String code, String key, int keyCode, int location, int metaState) {
    {
        assert(code != nullptr);
        assert(metaState != nullptr);
    }
}

String RawKeyEventDataWeb::keyLabel() {
    return key == "Unidentified"? "" : _unicodeChar(key) ?? "";
}

PhysicalKeyboardKey RawKeyEventDataWeb::physicalKey() {
    return kWebToPhysicalKey[code] ?? PhysicalKeyboardKey(LogicalKeyboardKey.webPlane + code.hashCode);
}

LogicalKeyboardKey RawKeyEventDataWeb::logicalKey() {
    LogicalKeyboardKey maybeLocationKey = kWebLocationMap[key]?[location];
    if (maybeLocationKey != nullptr) {
        return maybeLocationKey;
    }
    LogicalKeyboardKey newKey = kWebToLogicalKey[code];
    if (newKey != nullptr) {
        return newKey;
    }
    bool isPrintable = key.length == 1;
    if (isPrintable) {
        return LogicalKeyboardKey(key.toLowerCase().codeUnitAt(0));
    }
    return LogicalKeyboardKey(code.hashCode + LogicalKeyboardKey.webPlane);
}

bool RawKeyEventDataWeb::isModifierPressed(ModifierKey key, KeyboardSide side) {
    ;
}

KeyboardSide RawKeyEventDataWeb::getModifierSide(ModifierKey key) {
    return KeyboardSide.any;
}

void RawKeyEventDataWeb::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<String>DiagnosticsProperty("code", code));
    properties.add(<String>DiagnosticsProperty("key", key));
    properties.add(<int>DiagnosticsProperty("location", location));
    properties.add(<int>DiagnosticsProperty("metaState", metaState));
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
}

bool RawKeyEventDataWeb::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataWeb && other.code == code && other.key == key && other.location == location && other.metaState == metaState && other.keyCode == keyCode;
}

int RawKeyEventDataWeb::hashCode() {
    return Object.hash(code, key, location, metaState, keyCode);
}
