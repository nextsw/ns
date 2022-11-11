#include "mouse_cursor.hpp"
MouseCursorManagerCls::MouseCursorManagerCls(MouseCursor fallbackMouseCursor) {
    {
        assert(fallbackMouseCursor != MouseCursorCls::defer);
    }
}

MouseCursor MouseCursorManagerCls::debugDeviceActiveCursor(int device) {
    MouseCursor result;
    assert([=] () {
        result = _lastSession[device]?->cursor;
        return true;
    }());
    return result;
}

void MouseCursorManagerCls::handleDeviceCursorUpdate(Iterable<MouseCursor> cursorCandidates, int device, PointerEvent triggeringEvent) {
    if (is<PointerRemovedEvent>(triggeringEvent)) {
        _lastSession->remove(device);
        return;
    }
    MouseCursorSession lastSession = _lastSession[device];
    MouseCursor nextCursor = _DeferringMouseCursorCls->firstNonDeferred(cursorCandidates) or fallbackMouseCursor;
    assert(!is<_DeferringMouseCursor>(nextCursor));
    if (lastSession?->cursor == nextCursor) {
        return;
    }
    MouseCursorSession nextSession = nextCursor->createSession(device);
    _lastSession[device] = nextSession;
    lastSession?->dispose();
    nextSession->activate();
}

MouseCursorSessionCls::MouseCursorSessionCls(MouseCursor cursor, int device) {
    {
        assert(cursor != nullptr);
        assert(device != nullptr);
    }
}

String MouseCursorCls::toString(DiagnosticLevel minLevel) {
    String debugDescription = this->debugDescription();
    if (minLevel->index >= DiagnosticLevelCls::info->index && debugDescription != nullptr) {
        return debugDescription;
    }
    return super->toString(minLevel);
}

MouseCursorSession _DeferringMouseCursorCls::createSession(int device) {
    assert(false, __s("_DeferringMouseCursor can not create a session"));
    throw make<UnimplementedErrorCls>();
}

String _DeferringMouseCursorCls::debugDescription() {
    return __s("defer");
}

MouseCursor _DeferringMouseCursorCls::firstNonDeferred(Iterable<MouseCursor> cursors) {
    for (MouseCursor cursor : cursors) {
        assert(cursor != nullptr);
        if (cursor != MouseCursorCls::defer) {
            return cursor;
        }
    }
    return nullptr;
}

Future<void> _NoopMouseCursorSessionCls::activate() {
}

void _NoopMouseCursorSessionCls::dispose() {
}

_NoopMouseCursorSession _NoopMouseCursorCls::createSession(int device) {
    return make<_NoopMouseCursorSessionCls>(this, device);
}

String _NoopMouseCursorCls::debugDescription() {
    return __s("uncontrolled");
}

SystemMouseCursor _SystemMouseCursorSessionCls::cursor() {
    return as<SystemMouseCursor>(super->cursor);
}

Future<void> _SystemMouseCursorSessionCls::activate() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("device"), device);map1.set(__s("kind"), cursor()->kind);return SystemChannelsCls::mouseCursor-><void>invokeMethod(__s("activateSystemCursor"), list1);
}

void _SystemMouseCursorSessionCls::dispose() {
}

String SystemMouseCursorCls::debugDescription() {
    return __s("${objectRuntimeType(this, 'SystemMouseCursor')}($kind)");
}

MouseCursorSession SystemMouseCursorCls::createSession(int device) {
    return make<_SystemMouseCursorSessionCls>(this, device);
}

bool SystemMouseCursorCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<SystemMouseCursor>(other) && other->kind == kind;
}

int SystemMouseCursorCls::hashCode() {
    return kind->hashCode();
}

void SystemMouseCursorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("kind"), kindDiagnosticLevelCls::debug));
}

void SystemMouseCursorCls::_(String kind)
