#include "mouse_tracking.hpp"
MouseTrackerAnnotation::MouseTrackerAnnotation(MouseCursor cursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, bool validForMouseTracker) {
    {
        assert(cursor != nullptr);
    }
}

void MouseTrackerAnnotation::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FunctionType>FlagsSummary("callbacks", "<none>"));
    properties.add(<MouseCursor>DiagnosticsProperty("cursor", cursorMouseCursor.defer));
}
