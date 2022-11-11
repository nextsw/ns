#include "icon_data.hpp"
bool IconDataCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<IconData>(other) && other->codePoint == codePoint && other->fontFamily == fontFamily && other->fontPackage == fontPackage && other->matchTextDirection == matchTextDirection;
}

int IconDataCls::hashCode() {
    return ObjectCls->hash(codePoint, fontFamily, fontPackage, matchTextDirection);
}

String IconDataCls::toString() {
    return __s("IconData(U+${codePoint.toRadixString(16).toUpperCase().padLeft(5, '0')})");
}

IconDataPropertyCls::IconDataPropertyCls(String name, Unknown value, Unknown ifNull, Unknown level, Unknown showName, Unknown style) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> IconDataPropertyCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (value != nullptr) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("codePoint"), value!->codePoint);json[__s("valueProperties")] = list1;
    }
    return json;
}
