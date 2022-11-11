#include "semantics_event.hpp"
Map<String, dynamic> SemanticsEventCls::toMap(int nodeId) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("type"), type);map1.set(__s("data"), getDataMap());Map<String, dynamic> event = list1;
    if (nodeId != nullptr) {
        event[__s("nodeId")] = nodeId;
    }
    return event;
}

String SemanticsEventCls::toString() {
    List<String> pairs = makeList();
    Map<String, dynamic> dataMap = getDataMap();
    auto _c1 = dataMap->keys()->toList();_c1.sort();List<String> sortedKeys = _c1;
    for (String key : sortedKeys) {
        pairs->add(__s("$key: ${dataMap[key]}"));
    }
    return __s("${objectRuntimeType(this, 'SemanticsEvent')}(${pairs.join(', ')})");
}

AnnounceSemanticsEventCls::AnnounceSemanticsEventCls(String message, TextDirection textDirection) : SemanticsEvent(__s("announce")) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
    }
}

Map<String, dynamic> AnnounceSemanticsEventCls::getDataMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("message"), message);map1.set(__s("textDirection"), textDirection->index);return list1;
}

TooltipSemanticsEventCls::TooltipSemanticsEventCls(String message) : SemanticsEvent(__s("tooltip")) {
}

Map<String, dynamic> TooltipSemanticsEventCls::getDataMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("message"), message);return list1;
}

LongPressSemanticsEventCls::LongPressSemanticsEventCls() : SemanticsEvent(__s("longPress")) {
}

Map<String, dynamic> LongPressSemanticsEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}

TapSemanticEventCls::TapSemanticEventCls() : SemanticsEvent(__s("tap")) {
}

Map<String, dynamic> TapSemanticEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}
