#include "icon_data.hpp"
bool IconDataCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is IconData && other->codePoint == codePoint && other->fontFamily == fontFamily && other->fontPackage == fontPackage && other->matchTextDirection == matchTextDirection;
}

int IconDataCls::hashCode() {
    return ObjectCls->hash(codePoint, fontFamily, fontPackage, matchTextDirection);
}

String IconDataCls::toString() {
    return "IconData(U+${codePoint.toRadixString(16).toUpperCase().padLeft(5, '0')})";
}

IconDataPropertyCls::IconDataPropertyCls(Unknown ifNull, Unknown level, String name, Unknown showName, Unknown style, Unknown value) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> IconDataPropertyCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (value != nullptr) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set("codePoint", value!->codePoint);json["valueProperties"] = list1;
    }
    return json;
}
