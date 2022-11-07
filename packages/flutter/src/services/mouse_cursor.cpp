#include "mouse_cursor.hpp"
MouseCursorManager::MouseCursorManager(MouseCursor fallbackMouseCursor) {
    {
        assert(fallbackMouseCursor != MouseCursor.defer);
    }
}

MouseCursor MouseCursorManager::debugDeviceActiveCursor(int device) {
    MouseCursor result;
    assert(());
    return result;
}

void MouseCursorManager::handleDeviceCursorUpdate(Iterable<MouseCursor> cursorCandidates, int device, PointerEvent triggeringEvent) {
    if (triggeringEvent is PointerRemovedEvent) {
        _lastSession.remove(device);
        return;
    }
    MouseCursorSession lastSession = _lastSession[device];
    MouseCursor nextCursor = _DeferringMouseCursor.firstNonDeferred(cursorCandidates) ?? fallbackMouseCursor;
    assert(nextCursor is! _DeferringMouseCursor);
    if (lastSession?.cursor == nextCursor) {
        return;
    }
    MouseCursorSession nextSession = nextCursor.createSession(device);
    _lastSession[device] = nextSession;
    lastSession?.dispose();
    nextSession.activate();
}

MouseCursorSession::MouseCursorSession(MouseCursor cursor, int device) {
    {
        assert(cursor != nullptr);
        assert(device != nullptr);
    }
}

String MouseCursor::toString(DiagnosticLevel minLevel) {
    String debugDescription = this.debugDescription;
    if (minLevel.index >= DiagnosticLevel.info.index && debugDescription != nullptr) {
        return debugDescription;
    }
    return super.toString(minLevel);
}

MouseCursorSession _DeferringMouseCursor::createSession(int device) {
    assert(false, "_DeferringMouseCursor can not create a session");
    ;
}

String _DeferringMouseCursor::debugDescription() {
    return "defer";
}

MouseCursor _DeferringMouseCursor::firstNonDeferred(Iterable<MouseCursor> cursors) {
    for (MouseCursor cursor : cursors) {
        assert(cursor != nullptr);
        if (cursor != MouseCursor.defer) {
            return cursor;
        }
    }
    return nullptr;
}

Future<void> _NoopMouseCursorSession::activate() {
}

void _NoopMouseCursorSession::dispose() {
}

_NoopMouseCursorSession _NoopMouseCursor::createSession(int device) {
    return _NoopMouseCursorSession(this, device);
}

String _NoopMouseCursor::debugDescription() {
    return "uncontrolled";
}

SystemMouseCursor _SystemMouseCursorSession::cursor() {
    return (;
}

Future<void> _SystemMouseCursorSession::activate() {
    return SystemChannels.mouseCursor.<void>invokeMethod("activateSystemCursor", );
}

void _SystemMouseCursorSession::dispose() {
}

String SystemMouseCursor::debugDescription() {
    return "${objectRuntimeType(this, 'SystemMouseCursor')}($kind)";
}

MouseCursorSession SystemMouseCursor::createSession(int device) {
    return _SystemMouseCursorSession(this, device);
}

bool SystemMouseCursor::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SystemMouseCursor && other.kind == kind;
}

int SystemMouseCursor::hashCode() {
    return kind.hashCode;
}

void SystemMouseCursor::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<String>DiagnosticsProperty("kind", kindDiagnosticLevel.debug));
}

void SystemMouseCursor::_(String kind)
