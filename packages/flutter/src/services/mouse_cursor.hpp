#ifndef PACKAGES_FLUTTER_SRC_SERVICES_MOUSE_CURSOR
#define PACKAGES_FLUTTER_SRC_SERVICES_MOUSE_CURSOR
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "system_channels.hpp"


class MouseCursorManagerCls : public ObjectCls {
public:
    MouseCursor fallbackMouseCursor;


     MouseCursorManagerCls(MouseCursor fallbackMouseCursor);

    virtual MouseCursor debugDeviceActiveCursor(int device);

    virtual void handleDeviceCursorUpdate(int device, PointerEvent triggeringEvent, Iterable<MouseCursor> cursorCandidates);

private:
    Map<int, MouseCursorSession> _lastSession;


};
using MouseCursorManager = std::shared_ptr<MouseCursorManagerCls>;

class MouseCursorSessionCls : public ObjectCls {
public:
    MouseCursor cursor;

    int device;


     MouseCursorSessionCls(MouseCursor cursor, int device);

    virtual Future<void> activate();
    virtual void dispose();
private:

};
using MouseCursorSession = std::shared_ptr<MouseCursorSessionCls>;

class MouseCursorCls : public ObjectCls {
public:
    static MouseCursor defer;

    static MouseCursor uncontrolled;


     MouseCursorCls();
    virtual MouseCursorSession createSession(int device);
    virtual String debugDescription();
    virtual String toString(DiagnosticLevel minLevel);

private:

};
using MouseCursor = std::shared_ptr<MouseCursorCls>;

class _DeferringMouseCursorCls : public MouseCursorCls {
public:

    virtual MouseCursorSession createSession(int device);

    virtual String debugDescription();

    static MouseCursor firstNonDeferred(Iterable<MouseCursor> cursors);

private:

    virtual void  _();
};
using _DeferringMouseCursor = std::shared_ptr<_DeferringMouseCursorCls>;

class _NoopMouseCursorSessionCls : public MouseCursorSessionCls {
public:

    virtual Future<void> activate();

    virtual void dispose();

private:

     _NoopMouseCursorSessionCls(_NoopMouseCursor cursor, Unknown device);
};
using _NoopMouseCursorSession = std::shared_ptr<_NoopMouseCursorSessionCls>;

class _NoopMouseCursorCls : public MouseCursorCls {
public:

    virtual _NoopMouseCursorSession createSession(int device);

    virtual String debugDescription();

private:

    virtual void  _();
};
using _NoopMouseCursor = std::shared_ptr<_NoopMouseCursorCls>;

class _SystemMouseCursorSessionCls : public MouseCursorSessionCls {
public:

    virtual SystemMouseCursor cursor();

    virtual Future<void> activate();

    virtual void dispose();

private:

     _SystemMouseCursorSessionCls(SystemMouseCursor cursor, Unknown device);
};
using _SystemMouseCursorSession = std::shared_ptr<_SystemMouseCursorSessionCls>;

class SystemMouseCursorCls : public MouseCursorCls {
public:
    String kind;


    virtual String debugDescription();

    virtual MouseCursorSession createSession(int device);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual void  _(String kind);

};
using SystemMouseCursor = std::shared_ptr<SystemMouseCursorCls>;

class SystemMouseCursorsCls : public ObjectCls {
public:
    static SystemMouseCursor none;

    static SystemMouseCursor basic;

    static SystemMouseCursor click;

    static SystemMouseCursor forbidden;

    static SystemMouseCursor wait;

    static SystemMouseCursor progress;

    static SystemMouseCursor contextMenu;

    static SystemMouseCursor help;

    static SystemMouseCursor text;

    static SystemMouseCursor verticalText;

    static SystemMouseCursor cell;

    static SystemMouseCursor precise;

    static SystemMouseCursor move;

    static SystemMouseCursor grab;

    static SystemMouseCursor grabbing;

    static SystemMouseCursor noDrop;

    static SystemMouseCursor alias;

    static SystemMouseCursor copy;

    static SystemMouseCursor disappearing;

    static SystemMouseCursor allScroll;

    static SystemMouseCursor resizeLeftRight;

    static SystemMouseCursor resizeUpDown;

    static SystemMouseCursor resizeUpLeftDownRight;

    static SystemMouseCursor resizeUpRightDownLeft;

    static SystemMouseCursor resizeUp;

    static SystemMouseCursor resizeDown;

    static SystemMouseCursor resizeLeft;

    static SystemMouseCursor resizeRight;

    static SystemMouseCursor resizeUpLeft;

    static SystemMouseCursor resizeUpRight;

    static SystemMouseCursor resizeDownLeft;

    static SystemMouseCursor resizeDownRight;

    static SystemMouseCursor resizeColumn;

    static SystemMouseCursor resizeRow;

    static SystemMouseCursor zoomIn;

    static SystemMouseCursor zoomOut;


private:

    virtual void  _();
};
using SystemMouseCursors = std::shared_ptr<SystemMouseCursorsCls>;


#endif