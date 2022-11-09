#ifndef PACKAGES_FLUTTER_SRC_SERVICES_MOUSE_TRACKING
#define PACKAGES_FLUTTER_SRC_SERVICES_MOUSE_TRACKING
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "mouse_cursor.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "mouse_cursor.hpp"


class MouseTrackerAnnotationCls : public ObjectCls {
public:
    PointerEnterEventListener onEnter;

    PointerExitEventListener onExit;

    MouseCursor cursor;

    bool validForMouseTracker;


     MouseTrackerAnnotationCls(MouseCursor cursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, bool validForMouseTracker);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using MouseTrackerAnnotation = std::shared_ptr<MouseTrackerAnnotationCls>;


#endif