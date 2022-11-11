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

Offset PointerEventCls::localPosition() {
    return position;
}

Offset PointerEventCls::localDelta() {
    return delta;
}

double PointerEventCls::distanceMin() {
    return 0.0;
}

Offset PointerEventCls::transformPosition(Offset position, Matrix4 transform) {
    if (transform == nullptr) {
        return position;
    }
    Vector3 position3 = make<Vector3Cls>(position->dx(), position->dy(), 0.0);
    Vector3 transformed3 = transform->perspectiveTransform(position3);
    return make<OffsetCls>(transformed3->x, transformed3->y);
}

Offset PointerEventCls::transformDeltaViaPositions(Matrix4 transform, Offset transformedEndPosition, Offset untransformedDelta, Offset untransformedEndPosition) {
    if (transform == nullptr) {
        return untransformedDelta;
    }
    transformedEndPosition = transformPosition(transform, untransformedEndPosition);
    Offset transformedStartPosition = transformPosition(transform, untransformedEndPosition - untransformedDelta);
    return transformedEndPosition - transformedStartPosition;
}

Matrix4 PointerEventCls::removePerspectiveTransform(Matrix4 transform) {
    Vector4 vector = make<Vector4Cls>(0, 0, 1, 0);
    auto _c1 = transform->clone();_c1.auto _c2 = setColumn(2, vector);_c2.setRow(2, vector);_c2;return _c1;
}

void _PointerEventDescriptionCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("position"), position));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("localPosition"), localPositionposition, DiagnosticLevelCls::debug));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("delta"), deltaOffsetCls::zero, DiagnosticLevelCls::debug));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("localDelta"), localDeltadelta, DiagnosticLevelCls::debug));
    properties->add(<Duration>make<DiagnosticsPropertyCls>(__s("timeStamp"), timeStampDurationCls::zero, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("pointer"), pointerDiagnosticLevelCls::debug));
    properties->add(<PointerDeviceKind>make<EnumPropertyCls>(__s("kind"), kindDiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("device"), device0, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("buttons"), buttons0, DiagnosticLevelCls::debug));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("down"), downDiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressure"), pressure1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressureMin"), pressureMin1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressureMax"), pressureMax1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distance"), distance0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distanceMin"), distanceMin0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distanceMax"), distanceMax0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("size"), size0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMajor"), radiusMajor0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMinor"), radiusMinor0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMin"), radiusMin0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMax"), radiusMax0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("orientation"), orientation0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("tilt"), tilt0.0, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("platformData"), platformData0, DiagnosticLevelCls::debug));
    properties->add(make<FlagPropertyCls>(__s("obscured")obscured, __s("obscured"), DiagnosticLevelCls::debug));
    properties->add(make<FlagPropertyCls>(__s("synthesized")synthesized, __s("synthesized"), DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("embedderId"), embedderId0, DiagnosticLevelCls::debug));
}

String _PointerEventDescriptionCls::toStringFull() {
    return toString(DiagnosticLevelCls::fine);
}

int _TransformedPointerEventCls::embedderId() {
    return original()->embedderId;
}

Duration _TransformedPointerEventCls::timeStamp() {
    return original()->timeStamp;
}

int _TransformedPointerEventCls::pointer() {
    return original()->pointer;
}

PointerDeviceKind _TransformedPointerEventCls::kind() {
    return original()->kind;
}

int _TransformedPointerEventCls::device() {
    return original()->device;
}

Offset _TransformedPointerEventCls::position() {
    return original()->position;
}

Offset _TransformedPointerEventCls::delta() {
    return original()->delta;
}

int _TransformedPointerEventCls::buttons() {
    return original()->buttons;
}

bool _TransformedPointerEventCls::down() {
    return original()->down;
}

bool _TransformedPointerEventCls::obscured() {
    return original()->obscured;
}

double _TransformedPointerEventCls::pressure() {
    return original()->pressure;
}

double _TransformedPointerEventCls::pressureMin() {
    return original()->pressureMin;
}

double _TransformedPointerEventCls::pressureMax() {
    return original()->pressureMax;
}

double _TransformedPointerEventCls::distance() {
    return original()->distance;
}

double _TransformedPointerEventCls::distanceMin() {
    return 0.0;
}

double _TransformedPointerEventCls::distanceMax() {
    return original()->distanceMax;
}

double _TransformedPointerEventCls::size() {
    return original()->size;
}

double _TransformedPointerEventCls::radiusMajor() {
    return original()->radiusMajor;
}

double _TransformedPointerEventCls::radiusMinor() {
    return original()->radiusMinor;
}

double _TransformedPointerEventCls::radiusMin() {
    return original()->radiusMin;
}

double _TransformedPointerEventCls::radiusMax() {
    return original()->radiusMax;
}

double _TransformedPointerEventCls::orientation() {
    return original()->orientation;
}

double _TransformedPointerEventCls::tilt() {
    return original()->tilt;
}

int _TransformedPointerEventCls::platformData() {
    return original()->platformData;
}

bool _TransformedPointerEventCls::synthesized() {
    return original()->synthesized;
}

PointerAddedEvent _CopyPointerAddedEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerAddedEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, embedderId or this->embedderId)->transformed(transform);
}

PointerAddedEventCls::PointerAddedEventCls(Unknown device, Unknown distance, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMax, Unknown radiusMin, Unknown tilt, Unknown timeStamp) {
}

PointerAddedEvent PointerAddedEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerAddedEventCls>(as<PointerAddedEvent>(original) or this, transform);
}

PointerAddedEvent _TransformedPointerAddedEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerAddedEventCls::_TransformedPointerAddedEventCls(PointerAddedEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerRemovedEvent _CopyPointerRemovedEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerRemovedEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distanceMax or this->distanceMax, radiusMin or this->radiusMin, radiusMax or this->radiusMax, embedderId or this->embedderId)->transformed(transform);
}

PointerRemovedEventCls::PointerRemovedEventCls(Unknown device, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, PointerRemovedEvent original, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMax, Unknown radiusMin, Unknown timeStamp) {
}

PointerRemovedEvent PointerRemovedEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerRemovedEventCls>(as<PointerRemovedEvent>(original) or this, transform);
}

PointerRemovedEvent _TransformedPointerRemovedEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerRemovedEventCls::_TransformedPointerRemovedEventCls(PointerRemovedEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerHoverEvent _CopyPointerHoverEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerHoverEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, delta or this->delta, buttons or this->buttons, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, synthesized or this->synthesized, embedderId or this->embedderId)->transformed(transform);
}

PointerHoverEventCls::PointerHoverEventCls(Unknown buttons, Unknown delta, Unknown device, Unknown distance, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown synthesized, Unknown tilt, Unknown timeStamp) {
}

PointerHoverEvent PointerHoverEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerHoverEventCls>(as<PointerHoverEvent>(original) or this, transform);
}

PointerHoverEvent _TransformedPointerHoverEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerHoverEventCls::_TransformedPointerHoverEventCls(PointerHoverEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerEnterEvent _CopyPointerEnterEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerEnterEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, delta or this->delta, buttons or this->buttons, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, synthesized or this->synthesized, embedderId or this->embedderId)->transformed(transform);
}

PointerEnterEventCls::PointerEnterEventCls(Unknown buttons, Unknown delta, Unknown device, Unknown distance, Unknown distanceMax, Unknown down, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown synthesized, Unknown tilt, Unknown timeStamp) {
}

void PointerEnterEventCls::fromMouseEvent(PointerEvent event) {
    return make<PointerEnterEventCls>(event->timeStamp, event->pointer, event->kind, event->device, event->position, event->delta, event->buttons, event->obscured, event->pressureMin, event->pressureMax, event->distance, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->down, event->synthesized)->transformed(event->transform);
}

PointerEnterEvent PointerEnterEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerEnterEventCls>(as<PointerEnterEvent>(original) or this, transform);
}

PointerEnterEvent _TransformedPointerEnterEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerEnterEventCls::_TransformedPointerEnterEventCls(PointerEnterEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerExitEvent _CopyPointerExitEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerExitEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, delta or this->delta, buttons or this->buttons, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, synthesized or this->synthesized, embedderId or this->embedderId)->transformed(transform);
}

PointerExitEventCls::PointerExitEventCls(Unknown buttons, Unknown delta, Unknown device, Unknown distance, Unknown distanceMax, Unknown down, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown synthesized, Unknown tilt, Unknown timeStamp) {
}

void PointerExitEventCls::fromMouseEvent(PointerEvent event) {
    return make<PointerExitEventCls>(event->timeStamp, event->pointer, event->kind, event->device, event->position, event->delta, event->buttons, event->obscured, event->pressureMin, event->pressureMax, event->distance, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->down, event->synthesized)->transformed(event->transform);
}

PointerExitEvent PointerExitEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerExitEventCls>(as<PointerExitEvent>(original) or this, transform);
}

PointerExitEvent _TransformedPointerExitEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerExitEventCls::_TransformedPointerExitEventCls(PointerExitEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerDownEvent _CopyPointerDownEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerDownEventCls>(timeStamp or this->timeStamp, pointer or this->pointer, kind or this->kind, device or this->device, position or this->position, buttons or this->buttons, obscured or this->obscured, pressure or this->pressure, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, embedderId or this->embedderId)->transformed(transform);
}

PointerDownEventCls::PointerDownEventCls(Unknown buttons, Unknown device, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressure, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown tilt, Unknown timeStamp) {
}

PointerDownEvent PointerDownEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerDownEventCls>(as<PointerDownEvent>(original) or this, transform);
}

PointerDownEvent _TransformedPointerDownEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerDownEventCls::_TransformedPointerDownEventCls(PointerDownEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerMoveEvent _CopyPointerMoveEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerMoveEventCls>(timeStamp or this->timeStamp, pointer or this->pointer, kind or this->kind, device or this->device, position or this->position, delta or this->delta, buttons or this->buttons, obscured or this->obscured, pressure or this->pressure, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, synthesized or this->synthesized, embedderId or this->embedderId)->transformed(transform);
}

PointerMoveEventCls::PointerMoveEventCls(Unknown buttons, Unknown delta, Unknown device, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown platformData, Unknown pointer, Unknown position, Unknown pressure, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown synthesized, Unknown tilt, Unknown timeStamp) {
}

PointerMoveEvent PointerMoveEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerMoveEventCls>(as<PointerMoveEvent>(original) or this, transform);
}

PointerMoveEvent _TransformedPointerMoveEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerMoveEventCls::_TransformedPointerMoveEventCls(PointerMoveEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerUpEvent _CopyPointerUpEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPosition, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerUpEventCls>(timeStamp or this->timeStamp, pointer or this->pointer, kind or this->kind, device or this->device, position or this->position, buttons or this->buttons, obscured or this->obscured, pressure or this->pressure, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, embedderId or this->embedderId)->transformed(transform);
}

PointerUpEventCls::PointerUpEventCls(Unknown buttons, Unknown device, Unknown distance, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressure, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown tilt, Unknown timeStamp) {
}

PointerUpEvent PointerUpEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerUpEventCls>(as<PointerUpEvent>(original) or this, transform);
}

PointerUpEvent _TransformedPointerUpEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerUpEventCls::_TransformedPointerUpEventCls(PointerUpEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerScrollEvent _CopyPointerScrollEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerScrollEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, scrollDelta(), embedderId or this->embedderId)->transformed(transform);
}

PointerScrollEventCls::PointerScrollEventCls(Unknown device, Unknown embedderId, Unknown kind, Unknown position, Offset scrollDelta, Unknown timeStamp) {
    {
        assert(timeStamp != nullptr);
        assert(kind != nullptr);
        assert(device != nullptr);
        assert(position != nullptr);
        assert(scrollDelta != nullptr);
    }
}

PointerScrollEvent PointerScrollEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerScrollEventCls>(as<PointerScrollEvent>(original) or this, transform);
}

void PointerScrollEventCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("scrollDelta"), scrollDelta));
}

Offset _TransformedPointerScrollEventCls::scrollDelta() {
    return original->scrollDelta;
}

PointerScrollEvent _TransformedPointerScrollEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

void _TransformedPointerScrollEventCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("scrollDelta"), scrollDelta()));
}

_TransformedPointerScrollEventCls::_TransformedPointerScrollEventCls(PointerScrollEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomStartEvent _CopyPointerPanZoomStartEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerPanZoomStartEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, embedderId or this->embedderId)->transformed(transform);
}

PointerPanZoomStartEventCls::PointerPanZoomStartEventCls(Unknown device, Unknown embedderId, Unknown kind, Unknown pointer, Unknown position, Unknown synthesized, Unknown timeStamp) {
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

PointerPanZoomStartEvent PointerPanZoomStartEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerPanZoomStartEventCls>(as<PointerPanZoomStartEvent>(original) or this, transform);
}

PointerPanZoomStartEvent _TransformedPointerPanZoomStartEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerPanZoomStartEventCls::_TransformedPointerPanZoomStartEventCls(PointerPanZoomStartEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomUpdateEvent _CopyPointerPanZoomUpdateEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPan, Offset localPanDelta, bool obscured, double orientation, Offset pan, Offset panDelta, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerPanZoomUpdateEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, embedderId or this->embedderId, pan or this->pan, panDelta or this->panDelta, scale or this->scale, rotation or this->rotation)->transformed(transform);
}

PointerPanZoomUpdateEventCls::PointerPanZoomUpdateEventCls(Unknown device, Unknown embedderId, Unknown kind, Offset pan, Offset panDelta, Unknown pointer, Unknown position, double rotation, double scale, Unknown synthesized, Unknown timeStamp) {
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

Offset PointerPanZoomUpdateEventCls::localPan() {
    return pan;
}

Offset PointerPanZoomUpdateEventCls::localPanDelta() {
    return panDelta;
}

PointerPanZoomUpdateEvent PointerPanZoomUpdateEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerPanZoomUpdateEventCls>(as<PointerPanZoomUpdateEvent>(original) or this, transform);
}

Offset _TransformedPointerPanZoomUpdateEventCls::pan() {
    return original->pan;
}

Offset _TransformedPointerPanZoomUpdateEventCls::panDelta() {
    return original->panDelta;
}

double _TransformedPointerPanZoomUpdateEventCls::scale() {
    return original->scale;
}

double _TransformedPointerPanZoomUpdateEventCls::rotation() {
    return original->rotation;
}

PointerPanZoomUpdateEvent _TransformedPointerPanZoomUpdateEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerPanZoomUpdateEventCls::_TransformedPointerPanZoomUpdateEventCls(PointerPanZoomUpdateEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerPanZoomEndEvent _CopyPointerPanZoomEndEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerPanZoomEndEventCls>(timeStamp or this->timeStamp, kind or this->kind, device or this->device, position or this->position, embedderId or this->embedderId)->transformed(transform);
}

PointerPanZoomEndEventCls::PointerPanZoomEndEventCls(Unknown device, Unknown embedderId, Unknown kind, Unknown pointer, Unknown position, Unknown synthesized, Unknown timeStamp) {
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

PointerPanZoomEndEvent PointerPanZoomEndEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerPanZoomEndEventCls>(as<PointerPanZoomEndEvent>(original) or this, transform);
}

PointerPanZoomEndEvent _TransformedPointerPanZoomEndEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerPanZoomEndEventCls::_TransformedPointerPanZoomEndEventCls(PointerPanZoomEndEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}

PointerCancelEvent _CopyPointerCancelEventCls::copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) {
    return make<PointerCancelEventCls>(timeStamp or this->timeStamp, pointer or this->pointer, kind or this->kind, device or this->device, position or this->position, buttons or this->buttons, obscured or this->obscured, pressureMin or this->pressureMin, pressureMax or this->pressureMax, distance or this->distance, distanceMax or this->distanceMax, size or this->size, radiusMajor or this->radiusMajor, radiusMinor or this->radiusMinor, radiusMin or this->radiusMin, radiusMax or this->radiusMax, orientation or this->orientation, tilt or this->tilt, embedderId or this->embedderId)->transformed(transform);
}

PointerCancelEventCls::PointerCancelEventCls(Unknown buttons, Unknown device, Unknown distance, Unknown distanceMax, Unknown embedderId, Unknown kind, Unknown obscured, Unknown orientation, Unknown pointer, Unknown position, Unknown pressureMax, Unknown pressureMin, Unknown radiusMajor, Unknown radiusMax, Unknown radiusMin, Unknown radiusMinor, Unknown size, Unknown tilt, Unknown timeStamp) {
}

PointerCancelEvent PointerCancelEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerCancelEventCls>(as<PointerCancelEvent>(original) or this, transform);
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

PointerCancelEvent _TransformedPointerCancelEventCls::transformed(Matrix4 transform) {
    return original->transformed(transform);
}

_TransformedPointerCancelEventCls::_TransformedPointerCancelEventCls(PointerCancelEvent original, Matrix4 transform) {
    {
        assert(original != nullptr);
        assert(transform != nullptr);
    }
}
