#ifndef MOUSE_TRACKING_H
#define MOUSE_TRACKING_H
#include <memory>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "mouse_cursor.hpp"

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "mouse_cursor.hpp"



class MouseTrackerAnnotation {
public:
    PointerEnterEventListener onEnter;

    PointerExitEventListener onExit;

    MouseCursor cursor;

    bool validForMouseTracker;


     MouseTrackerAnnotation(MouseCursor cursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, bool validForMouseTracker);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif