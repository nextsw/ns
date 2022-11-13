#include "semantics_service.hpp"
Future<void> SemanticsServiceCls::announce(String message, TextDirection textDirection) {
    AnnounceSemanticsEvent event = make<AnnounceSemanticsEventCls>(message, textDirection);
    await SystemChannelsCls::accessibility->send(event->toMap());
}

Future<void> SemanticsServiceCls::tooltip(String message) {
    TooltipSemanticsEvent event = make<TooltipSemanticsEventCls>(message);
    await SystemChannelsCls::accessibility->send(event->toMap());
}
