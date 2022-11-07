#include "events.hpp"
int nthMouseButton(int number) {
    return (kPrimaryMouseButton << (number - 1)) & kMaxUnsignedSMI;
}

int nthStylusButton(int number) {
    return (kPrimaryStylusButton << (number - 1)) & kMaxUnsignedSMI;
}

int smallestButton(int buttons) {
    return buttons & (-buttons);
}

bool isSingleButton(int buttons) {
    return buttons != 0 && (smallestButton(buttons) == buttons);
}

Offset PointerEvent::localPosition() {
    return position;
}

Offset PointerEvent::localDelta() {
    return delta;
}

double PointerEvent::distanceMin() {
    return 0.0;
}

Offset PointerEvent::transformPosition(Offset position, Matrix4 transform) {
    if (transform == nullptr) {
        return position;
    }
    Vector3 position3 = Vector3(position.dx, position.dy, 0.0);
    Vector3 transformed3 = transform.perspectiveTransform(position3);
    return Offset(transformed3.x, transformed3.y);
}

Offset PointerEvent::transformDeltaViaPositions(Matrix4 transform, Offset transformedEndPosition, Offset untransformedDelta, Offset untransformedEndPosition) {
    if (transform == nullptr) {
        return untransformedDelta;
    }
    transformedEndPosition = transformPosition(transform, untransformedEndPosition);
    Offset transformedStartPosition = transformPosition(transform, untransformedEndPosition - untransformedDelta);
    return transformedEndPosition - transformedStartPosition;
}

Matrix4 PointerEvent::removePerspectiveTransform(Matrix4 transform) {
    Vector4 vector = Vector4(0, 0, 1, 0);
    return ;
}

void _PointerEventDescription::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("position", position));
    properties.add(<Offset>DiagnosticsProperty("localPosition", localPositionposition, DiagnosticLevel.debug));
    properties.add(<Offset>DiagnosticsProperty("delta", deltaOffset.zero, DiagnosticLevel.debug));
    properties.add(<Offset>DiagnosticsProperty("localDelta", localDeltadelta, DiagnosticLevel.debug));
    properties.add(<Duration>DiagnosticsProperty("timeStamp", timeStampDuration.zero, DiagnosticLevel.debug));
    properties.add(IntProperty("pointer", pointerDiagnosticLevel.debug));
    properties.add(<PointerDeviceKind>EnumProperty("kind", kindDiagnosticLevel.debug));
    properties.add(IntProperty("device", device0, DiagnosticLevel.debug));
    properties.add(IntProperty("buttons", buttons0, DiagnosticLevel.debug));
    properties.add(<bool>DiagnosticsProperty("down", downDiagnosticLevel.debug));
    properties.add(DoubleProperty("pressure", pressure1.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("pressureMin", pressureMin1.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("pressureMax", pressureMax1.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("distance", distance0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("distanceMin", distanceMin0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("distanceMax", distanceMax0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("size", size0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("radiusMajor", radiusMajor0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("radiusMinor", radiusMinor0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("radiusMin", radiusMin0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("radiusMax", radiusMax0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("orientation", orientation0.0, DiagnosticLevel.debug));
    properties.add(DoubleProperty("tilt", tilt0.0, DiagnosticLevel.debug));
    properties.add(IntProperty("platformData", platformData0, DiagnosticLevel.debug));
    properties.add(FlagProperty("obscured"obscured, "obscured", DiagnosticLevel.debug));
    properties.add(FlagProperty("synthesized"synthesized, "synthesized", DiagnosticLevel.debug));
    properties.add(IntProperty("embedderId", embedderId0, DiagnosticLevel.debug));
}

String _PointerEventDescription::toStringFull() {
    return toString(DiagnosticLevel.fine);
}

int _TransformedPointerEvent::embedderId() {
    return original.embedderId;
}

Duration _TransformedPointerEvent::timeStamp() {
    return original.timeStamp;
}

int _TransformedPointerEvent::pointer() {
    return original.pointer;
}

PointerDeviceKind _TransformedPointerEvent::kind() {
    return original.kind;
}

int _TransformedPointerEvent::device() {
    return original.device;
}

Offset _TransformedPointerEvent::position() {
    return original.position;
}

Offset _TransformedPointerEvent::delta() {
    return original.delta;
}

int _TransformedPointerEvent::buttons() {
    return original.buttons;
}

bool _TransformedPointerEvent::down() {
    return original.down;
}

bool _TransformedPointerEvent::obscured() {
    return original.obscured;
}

double _TransformedPointerEvent::pressure() {
    return original.pressure;
}

double _TransformedPointerEvent::pressureMin() {
    return original.pressureMin;
}

double _TransformedPointerEvent::pressureMax() {
    return original.pressureMax;
}

double _TransformedPointerEvent::distance() {
    return original.distance;
}

double _TransformedPointerEvent::distanceMin() {
    return 0.0;
}

double _TransformedPointerEvent::distanceMax() {
    return original.distanceMax;
}

double _TransformedPointerEvent::size() {
    return original.size;
}

double _TransformedPointerEvent::radiusMajor() {
    return original.radiusMajor;
}

double _TransformedPointerEvent::radiusMinor() {
    return original.radiusMinor;
}

double _TransformedPointerEvent::radiusMin() {
    return original.radiusMin;
}

double _TransformedPointerEvent::radiusMax() {
    return original.radiusMax;
}

double _TransformedPointerEvent::orientation() {
    return original.orientation;
}

double _TransformedPointerEvent::tilt() {
    return original.tilt;
}

int _TransformedPointerEvent::platformData() {
    return original.platformData;
}

bool _TransformedPointerEvent::synthesized() {
    return original.synthesized;
}

PointerAddedEvent _CopyPointerAddedEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerAddedEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, embedderId ?? this.embedderId).transformed(transform);
}

PointerAddedEvent::PointerAddedEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(0.0);
    }
}

PointerAddedEvent PointerAddedEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerAddedEvent(( ?? this, transform);
}

PointerAddedEvent _TransformedPointerAddedEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerAddedEvent::_TransformedPointerAddedEvent(PointerAddedEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerRemovedEvent _CopyPointerRemovedEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerRemovedEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distanceMax ?? this.distanceMax, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, embedderId ?? this.embedderId).transformed(transform);
}

PointerRemovedEvent::PointerRemovedEvent(Unknown, Unknown, Unknown, Unknown, Unknown, PointerRemovedEvent original, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(0.0);
    }
}

PointerRemovedEvent PointerRemovedEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerRemovedEvent(( ?? this, transform);
}

PointerRemovedEvent _TransformedPointerRemovedEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerRemovedEvent::_TransformedPointerRemovedEvent(PointerRemovedEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerHoverEvent _CopyPointerHoverEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerHoverEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, delta ?? this.delta, buttons ?? this.buttons, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, synthesized ?? this.synthesized, embedderId ?? this.embedderId).transformed(transform);
}

PointerHoverEvent::PointerHoverEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(false, 0.0);
    }
}

PointerHoverEvent PointerHoverEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerHoverEvent(( ?? this, transform);
}

PointerHoverEvent _TransformedPointerHoverEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerHoverEvent::_TransformedPointerHoverEvent(PointerHoverEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerEnterEvent _CopyPointerEnterEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerEnterEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, delta ?? this.delta, buttons ?? this.buttons, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, synthesized ?? this.synthesized, embedderId ?? this.embedderId).transformed(transform);
}

PointerEnterEvent::PointerEnterEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(0.0);
    }
}

void PointerEnterEvent::fromMouseEvent(PointerEvent event) {
    return PointerEnterEvent(event.timeStamp, event.pointer, event.kind, event.device, event.position, event.delta, event.buttons, event.obscured, event.pressureMin, event.pressureMax, event.distance, event.distanceMax, event.size, event.radiusMajor, event.radiusMinor, event.radiusMin, event.radiusMax, event.orientation, event.tilt, event.down, event.synthesized).transformed(event.transform);
}

PointerEnterEvent PointerEnterEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerEnterEvent(( ?? this, transform);
}

PointerEnterEvent _TransformedPointerEnterEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerEnterEvent::_TransformedPointerEnterEvent(PointerEnterEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerExitEvent _CopyPointerExitEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerExitEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, delta ?? this.delta, buttons ?? this.buttons, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, synthesized ?? this.synthesized, embedderId ?? this.embedderId).transformed(transform);
}

PointerExitEvent::PointerExitEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(0.0);
    }
}

void PointerExitEvent::fromMouseEvent(PointerEvent event) {
    return PointerExitEvent(event.timeStamp, event.pointer, event.kind, event.device, event.position, event.delta, event.buttons, event.obscured, event.pressureMin, event.pressureMax, event.distance, event.distanceMax, event.size, event.radiusMajor, event.radiusMinor, event.radiusMin, event.radiusMax, event.orientation, event.tilt, event.down, event.synthesized).transformed(event.transform);
}

PointerExitEvent PointerExitEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerExitEvent(( ?? this, transform);
}

PointerExitEvent _TransformedPointerExitEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerExitEvent::_TransformedPointerExitEvent(PointerExitEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerDownEvent _CopyPointerDownEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerDownEvent(timeStamp ?? this.timeStamp, pointer ?? this.pointer, kind ?? this.kind, device ?? this.device, position ?? this.position, buttons ?? this.buttons, obscured ?? this.obscured, pressure ?? this.pressure, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, embedderId ?? this.embedderId).transformed(transform);
}

PointerDownEvent::PointerDownEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(true, 0.0);
    }
}

PointerDownEvent PointerDownEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerDownEvent(( ?? this, transform);
}

PointerDownEvent _TransformedPointerDownEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerDownEvent::_TransformedPointerDownEvent(PointerDownEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerMoveEvent _CopyPointerMoveEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerMoveEvent(timeStamp ?? this.timeStamp, pointer ?? this.pointer, kind ?? this.kind, device ?? this.device, position ?? this.position, delta ?? this.delta, buttons ?? this.buttons, obscured ?? this.obscured, pressure ?? this.pressure, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, synthesized ?? this.synthesized, embedderId ?? this.embedderId).transformed(transform);
}

PointerMoveEvent::PointerMoveEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(true, 0.0);
    }
}

PointerMoveEvent PointerMoveEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerMoveEvent(( ?? this, transform);
}

PointerMoveEvent _TransformedPointerMoveEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerMoveEvent::_TransformedPointerMoveEvent(PointerMoveEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerUpEvent _CopyPointerUpEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPosition, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerUpEvent(timeStamp ?? this.timeStamp, pointer ?? this.pointer, kind ?? this.kind, device ?? this.device, position ?? this.position, buttons ?? this.buttons, obscured ?? this.obscured, pressure ?? this.pressure, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, embedderId ?? this.embedderId).transformed(transform);
}

PointerUpEvent::PointerUpEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(false);
    }
}

PointerUpEvent PointerUpEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerUpEvent(( ?? this, transform);
}

PointerUpEvent _TransformedPointerUpEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerUpEvent::_TransformedPointerUpEvent(PointerUpEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerScrollEvent _CopyPointerScrollEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerScrollEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, scrollDelta, embedderId ?? this.embedderId).transformed(transform);
}

PointerScrollEvent::PointerScrollEvent(Unknown, Unknown, Unknown, Unknown, Offset scrollDelta, Unknown) {
    {
        assert(timeStamp != nullptr);
        assert(kind != nullptr);
        assert(device != nullptr);
        assert(position != nullptr);
        assert(scrollDelta != nullptr);
    }
}

PointerScrollEvent PointerScrollEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerScrollEvent(( ?? this, transform);
}

void PointerScrollEvent::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("scrollDelta", scrollDelta));
}

Offset _TransformedPointerScrollEvent::scrollDelta() {
    return original.scrollDelta;
}

PointerScrollEvent _TransformedPointerScrollEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

void _TransformedPointerScrollEvent::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("scrollDelta", scrollDelta));
}

_TransformedPointerScrollEvent::_TransformedPointerScrollEvent(PointerScrollEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomStartEvent _CopyPointerPanZoomStartEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerPanZoomStartEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, embedderId ?? this.embedderId).transformed(transform);
}

PointerPanZoomStartEvent::PointerPanZoomStartEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(timeStamp != nullptr);
        assert(kind != nullptr);
        assert(device != nullptr);
        assert(pointer != nullptr);
        assert(position != nullptr);
        assert(embedderId != nullptr);
        assert(synthesized != nullptr);
    }
}

PointerPanZoomStartEvent PointerPanZoomStartEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerPanZoomStartEvent(( ?? this, transform);
}

PointerPanZoomStartEvent _TransformedPointerPanZoomStartEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerPanZoomStartEvent::_TransformedPointerPanZoomStartEvent(PointerPanZoomStartEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomUpdateEvent _CopyPointerPanZoomUpdateEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPan, Offset localPanDelta, bool obscured, double orientation, Offset pan, Offset panDelta, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerPanZoomUpdateEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, embedderId ?? this.embedderId, pan ?? this.pan, panDelta ?? this.panDelta, scale ?? this.scale, rotation ?? this.rotation).transformed(transform);
}

PointerPanZoomUpdateEvent::PointerPanZoomUpdateEvent(Unknown, Unknown, Unknown, Offset pan, Offset panDelta, Unknown, Unknown, double rotation, double scale, Unknown, Unknown) {
    {
        assert(timeStamp != nullptr);
        assert(kind != nullptr);
        assert(device != nullptr);
        assert(pointer != nullptr);
        assert(position != nullptr);
        assert(embedderId != nullptr);
        assert(pan != nullptr);
        assert(panDelta != nullptr);
        assert(scale != nullptr);
        assert(rotation != nullptr);
        assert(synthesized != nullptr);
    }
}

Offset PointerPanZoomUpdateEvent::localPan() {
    return pan;
}

Offset PointerPanZoomUpdateEvent::localPanDelta() {
    return panDelta;
}

PointerPanZoomUpdateEvent PointerPanZoomUpdateEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerPanZoomUpdateEvent(( ?? this, transform);
}

Offset _TransformedPointerPanZoomUpdateEvent::pan() {
    return original.pan;
}

Offset _TransformedPointerPanZoomUpdateEvent::panDelta() {
    return original.panDelta;
}

double _TransformedPointerPanZoomUpdateEvent::scale() {
    return original.scale;
}

double _TransformedPointerPanZoomUpdateEvent::rotation() {
    return original.rotation;
}

PointerPanZoomUpdateEvent _TransformedPointerPanZoomUpdateEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerPanZoomUpdateEvent::_TransformedPointerPanZoomUpdateEvent(PointerPanZoomUpdateEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomEndEvent _CopyPointerPanZoomEndEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerPanZoomEndEvent(timeStamp ?? this.timeStamp, kind ?? this.kind, device ?? this.device, position ?? this.position, embedderId ?? this.embedderId).transformed(transform);
}

PointerPanZoomEndEvent::PointerPanZoomEndEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(timeStamp != nullptr);
        assert(kind != nullptr);
        assert(device != nullptr);
        assert(pointer != nullptr);
        assert(position != nullptr);
        assert(embedderId != nullptr);
        assert(synthesized != nullptr);
    }
}

PointerPanZoomEndEvent PointerPanZoomEndEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerPanZoomEndEvent(( ?? this, transform);
}

PointerPanZoomEndEvent _TransformedPointerPanZoomEndEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerPanZoomEndEvent::_TransformedPointerPanZoomEndEvent(PointerPanZoomEndEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerCancelEvent _CopyPointerCancelEvent::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return PointerCancelEvent(timeStamp ?? this.timeStamp, pointer ?? this.pointer, kind ?? this.kind, device ?? this.device, position ?? this.position, buttons ?? this.buttons, obscured ?? this.obscured, pressureMin ?? this.pressureMin, pressureMax ?? this.pressureMax, distance ?? this.distance, distanceMax ?? this.distanceMax, size ?? this.size, radiusMajor ?? this.radiusMajor, radiusMinor ?? this.radiusMinor, radiusMin ?? this.radiusMin, radiusMax ?? this.radiusMax, orientation ?? this.orientation, tilt ?? this.tilt, embedderId ?? this.embedderId).transformed(transform);
}

PointerCancelEvent::PointerCancelEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        super(false, 0.0);
    }
}

PointerCancelEvent PointerCancelEvent::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this.transform) {
        return this;
    }
    return _TransformedPointerCancelEvent(( ?? this, transform);
}

double computeHitSlop(PointerDeviceKind kind, DeviceGestureSettings settings) {
    ;
}

double computePanSlop(PointerDeviceKind kind, DeviceGestureSettings settings) {
    ;
}

double computeScaleSlop(PointerDeviceKind kind) {
    ;
}

PointerCancelEvent _TransformedPointerCancelEvent::transformed(Matrix4 transform) {
    return original.transformed(transform);
}

_TransformedPointerCancelEvent::_TransformedPointerCancelEvent(PointerCancelEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}
