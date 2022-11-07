#include "icon_data.hpp"
bool IconData::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is IconData && other.codePoint == codePoint && other.fontFamily == fontFamily && other.fontPackage == fontPackage && other.matchTextDirection == matchTextDirection;
}

int IconData::hashCode() {
    return Object.hash(codePoint, fontFamily, fontPackage, matchTextDirection);
}

String IconData::toString() {
    return "IconData(U+${codePoint.toRadixString(16).toUpperCase().padLeft(5, '0')})";
}

IconDataProperty::IconDataProperty(Unknown, Unknown, String name, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> IconDataProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (value != nullptr) {
        json["valueProperties"] = ;
    }
    return json;
}
