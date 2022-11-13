#include "semantics_event.hpp"
Map<String, Object> SemanticsEventCls::toMap(int nodeId) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("type"), type);map1.set(__s("data"), getDataMap());Map<String, Object> event = list1;
    if (nodeId != nullptr) {
        event[__s("nodeId")] = nodeId;
    }
    return event;
}

String SemanticsEventCls::toString() {
    List<String> pairs = makeList();
    Map<String, Object> dataMap = getDataMap();
    auto _c1 = dataMap->keys()->toList();_c1.sort();List<String> sortedKeys = _c1;
    for (String key : sortedKeys) {
        pairs->add(__sf("%s: %s", key, dataMap[key]));
    }
    return __sf("%s(%s)", objectRuntimeType(this, __s("SemanticsEvent")), pairs->join(__s(", ")));
}

AnnounceSemanticsEventCls::AnnounceSemanticsEventCls(String message, TextDirection textDirection) : SemanticsEvent(__s("announce")) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
    }
}

Map<String, Object> AnnounceSemanticsEventCls::getDataMap() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("message"), message);map1.set(__s("textDirection"), textDirection->index);return list1;
}

TooltipSemanticsEventCls::TooltipSemanticsEventCls(String message) : SemanticsEvent(__s("tooltip")) {
}

Map<String, Object> TooltipSemanticsEventCls::getDataMap() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("message"), message);return list1;
}

LongPressSemanticsEventCls::LongPressSemanticsEventCls() : SemanticsEvent(__s("longPress")) {
}

Map<String, Object> LongPressSemanticsEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}

TapSemanticEventCls::TapSemanticEventCls() : SemanticsEvent(__s("tap")) {
}

Map<String, Object> TapSemanticEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}
