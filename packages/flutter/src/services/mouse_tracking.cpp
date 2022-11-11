#include "mouse_tracking.hpp"
MouseTrackerAnnotationCls::MouseTrackerAnnotationCls(MouseCursor cursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, bool validForMouseTracker) {
    {
        assert(cursor != nullptr);
    }
}

void MouseTrackerAnnotationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    Map<String, std::function<void ()>> map1 = make<MapCls<>>();map1.set(__s("enter"), onEnter);map1.set(__s("exit"), onExit);properties->add(<std::function<void ()>>make<FlagsSummaryCls>(__s("callbacks"), list1__s("<none>")));
    properties->add(<MouseCursor>make<DiagnosticsPropertyCls>(__s("cursor"), cursorMouseCursorCls::defer));
}
