#include "semantics_event.hpp"
Map<String, dynamic> SemanticsEventCls::toMap(int nodeId) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("type", type);map1.set("data", getDataMap());Map<String, dynamic> event = list1;
    if (nodeId != nullptr) {
        event["nodeId"] = nodeId;
    }
    return event;
}

String SemanticsEventCls::toString() {
    List<String> pairs = makeList();
    Map<String, dynamic> dataMap = getDataMap();
    auto _c1 = dataMap->keys->toList();_c1.sort();List<String> sortedKeys = _c1;
    for (String key : sortedKeys) {
        pairs->add("$key: ${dataMap[key]}");
    }
    return "${objectRuntimeType(this, 'SemanticsEvent')}(${pairs.join(', ')})";
}

AnnounceSemanticsEventCls::AnnounceSemanticsEventCls(String message, TextDirection textDirection) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
    }
}

Map<String, dynamic> AnnounceSemanticsEventCls::getDataMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("message", message);map1.set("textDirection", textDirection->index);return list1;
}

TooltipSemanticsEventCls::TooltipSemanticsEventCls(String message) {
}

Map<String, dynamic> TooltipSemanticsEventCls::getDataMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("message", message);return list1;
}

LongPressSemanticsEventCls::LongPressSemanticsEventCls() {
}

Map<String, dynamic> LongPressSemanticsEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}

TapSemanticEventCls::TapSemanticEventCls() {
}

Map<String, dynamic> TapSemanticEventCls::getDataMap() {
    return makeMap(makeList(), makeList();
}
