#include "mouse_tracking.hpp"
MouseTrackerAnnotationCls::MouseTrackerAnnotationCls(MouseCursor cursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, bool validForMouseTracker) {
    {
        assert(cursor != nullptr);
    }
}

void MouseTrackerAnnotationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    Map<String, void  Function()> map1 = make<MapCls<>>();map1.set("enter", onEnter);map1.set("exit", onExit);properties->add(<void  Function()>make<FlagsSummaryCls>("callbacks", list1"<none>"));
    properties->add(<MouseCursor>make<DiagnosticsPropertyCls>("cursor", cursorMouseCursorCls::defer));
}
