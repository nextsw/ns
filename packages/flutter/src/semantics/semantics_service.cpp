#include "semantics_service.hpp"
Future<void> SemanticsService::announce(String message, TextDirection textDirection) {
    AnnounceSemanticsEvent event = AnnounceSemanticsEvent(message, textDirection);
    await await SystemChannels.accessibility.send(event.toMap());
}

Future<void> SemanticsService::tooltip(String message) {
    TooltipSemanticsEvent event = TooltipSemanticsEvent(message);
    await await SystemChannels.accessibility.send(event.toMap());
}
