#ifndef MOUSE_CURSOR_H
#define MOUSE_CURSOR_H
#include <memory>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "system_channels.hpp"



class MouseCursorManager {
public:
    MouseCursor fallbackMouseCursor;


     MouseCursorManager(MouseCursor fallbackMouseCursor);

    MouseCursor debugDeviceActiveCursor(int device);

    void handleDeviceCursorUpdate(Iterable<MouseCursor> cursorCandidates, int device, PointerEvent triggeringEvent);

private:
    Map<int, MouseCursorSession> _lastSession;


};

class MouseCursorSession {
public:
    MouseCursor cursor;

    int device;


     MouseCursorSession(MouseCursor cursor, int device);

    Future<void> activate();

    void dispose();

private:

};

class MouseCursor {
public:
    static const MouseCursor defer;

    static const MouseCursor uncontrolled;


     MouseCursor();

    MouseCursorSession createSession(int device);

    String debugDescription();

    String toString(DiagnosticLevel minLevel);

private:

};

class _DeferringMouseCursor : MouseCursor {
public:

    MouseCursorSession createSession(int device);

    String debugDescription();

    static MouseCursor firstNonDeferred(Iterable<MouseCursor> cursors);

private:

    void  _();

};

class _NoopMouseCursorSession : MouseCursorSession {
public:

    Future<void> activate();

    void dispose();

private:

     _NoopMouseCursorSession(_NoopMouseCursor cursor, Unknown);

};

class _NoopMouseCursor : MouseCursor {
public:

    _NoopMouseCursorSession createSession(int device);

    String debugDescription();

private:

    void  _();

};

class _SystemMouseCursorSession : MouseCursorSession {
public:

    SystemMouseCursor cursor();

    Future<void> activate();

    void dispose();

private:

     _SystemMouseCursorSession(SystemMouseCursor cursor, Unknown);

};

class SystemMouseCursor : MouseCursor {
public:
    String kind;


    String debugDescription();

    MouseCursorSession createSession(int device);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    void  _(String kind);

};

class SystemMouseCursors {
public:
    static const SystemMouseCursor none;

    static const SystemMouseCursor basic;

    static const SystemMouseCursor click;

    static const SystemMouseCursor forbidden;

    static const SystemMouseCursor wait;

    static const SystemMouseCursor progress;

    static const SystemMouseCursor contextMenu;

    static const SystemMouseCursor help;

    static const SystemMouseCursor text;

    static const SystemMouseCursor verticalText;

    static const SystemMouseCursor cell;

    static const SystemMouseCursor precise;

    static const SystemMouseCursor move;

    static const SystemMouseCursor grab;

    static const SystemMouseCursor grabbing;

    static const SystemMouseCursor noDrop;

    static const SystemMouseCursor alias;

    static const SystemMouseCursor copy;

    static const SystemMouseCursor disappearing;

    static const SystemMouseCursor allScroll;

    static const SystemMouseCursor resizeLeftRight;

    static const SystemMouseCursor resizeUpDown;

    static const SystemMouseCursor resizeUpLeftDownRight;

    static const SystemMouseCursor resizeUpRightDownLeft;

    static const SystemMouseCursor resizeUp;

    static const SystemMouseCursor resizeDown;

    static const SystemMouseCursor resizeLeft;

    static const SystemMouseCursor resizeRight;

    static const SystemMouseCursor resizeUpLeft;

    static const SystemMouseCursor resizeUpRight;

    static const SystemMouseCursor resizeDownLeft;

    static const SystemMouseCursor resizeDownRight;

    static const SystemMouseCursor resizeColumn;

    static const SystemMouseCursor resizeRow;

    static const SystemMouseCursor zoomIn;

    static const SystemMouseCursor zoomOut;


private:

    void  _();

};

#endif