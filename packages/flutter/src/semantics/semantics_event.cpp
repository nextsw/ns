#include "semantics_event.hpp"
Map<String, dynamic> SemanticsEvent::toMap(int nodeId) {
    Map<String, dynamic> event = ;
    if (nodeId != nullptr) {
        event["nodeId"] = nodeId;
    }
    return event;
}

String SemanticsEvent::toString() {
    List<String> pairs = ;
    Map<String, dynamic> dataMap = getDataMap();
    List<String> sortedKeys = ;
    for (String key : sortedKeys) {
        pairs.add("$key: ${dataMap[key]}");
    }
    return "${objectRuntimeType(this, 'SemanticsEvent')}(${pairs.join(', ')})";
}

AnnounceSemanticsEvent::AnnounceSemanticsEvent(String message, TextDirection textDirection) {
    {
        assert(message != nullptr);
        assert(textDirection != nullptr);
        super("announce");
    }
}

Map<String, dynamic> AnnounceSemanticsEvent::getDataMap() {
    return ;
}

TooltipSemanticsEvent::TooltipSemanticsEvent(String message) {
    {
        super("tooltip");
    }
}

Map<String, dynamic> TooltipSemanticsEvent::getDataMap() {
    return ;
}

LongPressSemanticsEvent::LongPressSemanticsEvent() {
    {
        super("longPress");
    }
}

Map<String, dynamic> LongPressSemanticsEvent::getDataMap() {
    return const ;
}

TapSemanticEvent::TapSemanticEvent() {
    {
        super("tap");
    }
}

Map<String, dynamic> TapSemanticEvent::getDataMap() {
    return const ;
}
