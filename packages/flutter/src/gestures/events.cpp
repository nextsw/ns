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

Offset PointerEventCls::transformPosition(Matrix4 transform, Offset position) {
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
    transformedEndPosition |= transformPosition(transform, untransformedEndPosition);
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
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("localPosition"), localPosition, position, DiagnosticLevelCls::debug));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("delta"), delta, OffsetCls::zero, DiagnosticLevelCls::debug));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("localDelta"), localDelta, delta, DiagnosticLevelCls::debug));
    properties->add(<Duration>make<DiagnosticsPropertyCls>(__s("timeStamp"), timeStamp, DurationCls::zero, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("pointer"), pointer, DiagnosticLevelCls::debug));
    properties->add(<PointerDeviceKind>make<EnumPropertyCls>(__s("kind"), kind, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("device"), device, 0, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("buttons"), buttons, 0, DiagnosticLevelCls::debug));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("down"), down, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressure"), pressure, 1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressureMin"), pressureMin, 1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("pressureMax"), pressureMax, 1.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distance"), distance, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distanceMin"), distanceMin, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("distanceMax"), distanceMax, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("size"), size, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMajor"), radiusMajor, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMinor"), radiusMinor, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMin"), radiusMin, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("radiusMax"), radiusMax, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("orientation"), orientation, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<DoublePropertyCls>(__s("tilt"), tilt, 0.0, DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("platformData"), platformData, 0, DiagnosticLevelCls::debug));
    properties->add(make<FlagPropertyCls>(__s("obscured"), obscured, __s("obscured"), DiagnosticLevelCls::debug));
    properties->add(make<FlagPropertyCls>(__s("synthesized"), synthesized, __s("synthesized"), DiagnosticLevelCls::debug));
    properties->add(make<IntPropertyCls>(__s("embedderId"), embedderId, 0, DiagnosticLevelCls::debug));
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
    return make<PointerAddedEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, embedderId | this->embedderId)->transformed(transform);
}

PointerAddedEventCls::PointerAddedEventCls(int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMax, double radiusMin, double tilt, Duration timeStamp) : PointerEvent(0.0) {
}

PointerAddedEvent PointerAddedEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerAddedEventCls>(as<PointerAddedEvent>(original) | this, transform);
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
    return make<PointerRemovedEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distanceMax | this->distanceMax, radiusMin | this->radiusMin, radiusMax | this->radiusMax, embedderId | this->embedderId)->transformed(transform);
}

PointerRemovedEventCls::PointerRemovedEventCls(int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, PointerRemovedEvent original, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMax, double radiusMin, Duration timeStamp) : PointerEvent(0.0) {
}

PointerRemovedEvent PointerRemovedEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerRemovedEventCls>(as<PointerRemovedEvent>(original) | this, transform);
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
    return make<PointerHoverEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, delta | this->delta, buttons | this->buttons, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, synthesized | this->synthesized, embedderId | this->embedderId)->transformed(transform);
}

PointerHoverEventCls::PointerHoverEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) : PointerEvent(false, 0.0) {
}

PointerHoverEvent PointerHoverEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerHoverEventCls>(as<PointerHoverEvent>(original) | this, transform);
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
    return make<PointerEnterEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, delta | this->delta, buttons | this->buttons, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, synthesized | this->synthesized, embedderId | this->embedderId)->transformed(transform);
}

PointerEnterEventCls::PointerEnterEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) : PointerEvent(0.0) {
}

void PointerEnterEventCls::fromMouseEvent(PointerEvent event) {
    return make<PointerEnterEventCls>(event->timeStamp, event->pointer, event->kind, event->device, event->position, event->delta, event->buttons, event->obscured, event->pressureMin, event->pressureMax, event->distance, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->down, event->synthesized)->transformed(event->transform);
}

PointerEnterEvent PointerEnterEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerEnterEventCls>(as<PointerEnterEvent>(original) | this, transform);
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
    return make<PointerExitEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, delta | this->delta, buttons | this->buttons, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, synthesized | this->synthesized, embedderId | this->embedderId)->transformed(transform);
}

PointerExitEventCls::PointerExitEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) : PointerEvent(0.0) {
}

void PointerExitEventCls::fromMouseEvent(PointerEvent event) {
    return make<PointerExitEventCls>(event->timeStamp, event->pointer, event->kind, event->device, event->position, event->delta, event->buttons, event->obscured, event->pressureMin, event->pressureMax, event->distance, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->down, event->synthesized)->transformed(event->transform);
}

PointerExitEvent PointerExitEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerExitEventCls>(as<PointerExitEvent>(original) | this, transform);
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
    return make<PointerDownEventCls>(timeStamp | this->timeStamp, pointer | this->pointer, kind | this->kind, device | this->device, position | this->position, buttons | this->buttons, obscured | this->obscured, pressure | this->pressure, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, embedderId | this->embedderId)->transformed(transform);
}

PointerDownEventCls::PointerDownEventCls(int buttons, int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp) : PointerEvent(true, 0.0) {
}

PointerDownEvent PointerDownEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerDownEventCls>(as<PointerDownEvent>(original) | this, transform);
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
    return make<PointerMoveEventCls>(timeStamp | this->timeStamp, pointer | this->pointer, kind | this->kind, device | this->device, position | this->position, delta | this->delta, buttons | this->buttons, obscured | this->obscured, pressure | this->pressure, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, synthesized | this->synthesized, embedderId | this->embedderId)->transformed(transform);
}

PointerMoveEventCls::PointerMoveEventCls(int buttons, Offset delta, int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int platformData, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp) : PointerEvent(true, 0.0) {
}

PointerMoveEvent PointerMoveEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerMoveEventCls>(as<PointerMoveEvent>(original) | this, transform);
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
    return make<PointerUpEventCls>(timeStamp | this->timeStamp, pointer | this->pointer, kind | this->kind, device | this->device, position | this->position, buttons | this->buttons, obscured | this->obscured, pressure | this->pressure, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, embedderId | this->embedderId)->transformed(transform);
}

PointerUpEventCls::PointerUpEventCls(int buttons, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp) : PointerEvent(false) {
}

PointerUpEvent PointerUpEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerUpEventCls>(as<PointerUpEvent>(original) | this, transform);
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
    return make<PointerScrollEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, scrollDelta(), embedderId | this->embedderId)->transformed(transform);
}

PointerScrollEventCls::PointerScrollEventCls(int device, int embedderId, PointerDeviceKind kind, Offset position, Offset scrollDelta, Duration timeStamp) {
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
    return make<_TransformedPointerScrollEventCls>(as<PointerScrollEvent>(original) | this, transform);
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
    return make<PointerPanZoomStartEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, embedderId | this->embedderId)->transformed(transform);
}

PointerPanZoomStartEventCls::PointerPanZoomStartEventCls(int device, int embedderId, PointerDeviceKind kind, int pointer, Offset position, bool synthesized, Duration timeStamp) {
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
    return make<_TransformedPointerPanZoomStartEventCls>(as<PointerPanZoomStartEvent>(original) | this, transform);
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
    return make<PointerPanZoomUpdateEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, embedderId | this->embedderId, pan | this->pan, panDelta | this->panDelta, scale | this->scale, rotation | this->rotation)->transformed(transform);
}

PointerPanZoomUpdateEventCls::PointerPanZoomUpdateEventCls(int device, int embedderId, PointerDeviceKind kind, Offset pan, Offset panDelta, int pointer, Offset position, double rotation, double scale, bool synthesized, Duration timeStamp) {
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
    return make<_TransformedPointerPanZoomUpdateEventCls>(as<PointerPanZoomUpdateEvent>(original) | this, transform);
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
    return make<PointerPanZoomEndEventCls>(timeStamp | this->timeStamp, kind | this->kind, device | this->device, position | this->position, embedderId | this->embedderId)->transformed(transform);
}

PointerPanZoomEndEventCls::PointerPanZoomEndEventCls(int device, int embedderId, PointerDeviceKind kind, int pointer, Offset position, bool synthesized, Duration timeStamp) {
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
    return make<_TransformedPointerPanZoomEndEventCls>(as<PointerPanZoomEndEvent>(original) | this, transform);
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
    return make<PointerCancelEventCls>(timeStamp | this->timeStamp, pointer | this->pointer, kind | this->kind, device | this->device, position | this->position, buttons | this->buttons, obscured | this->obscured, pressureMin | this->pressureMin, pressureMax | this->pressureMax, distance | this->distance, distanceMax | this->distanceMax, size | this->size, radiusMajor | this->radiusMajor, radiusMinor | this->radiusMinor, radiusMin | this->radiusMin, radiusMax | this->radiusMax, orientation | this->orientation, tilt | this->tilt, embedderId | this->embedderId)->transformed(transform);
}

PointerCancelEventCls::PointerCancelEventCls(int buttons, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp) : PointerEvent(false, 0.0) {
}

PointerCancelEvent PointerCancelEventCls::transformed(Matrix4 transform) {
    if (transform == nullptr || transform == this->transform) {
        return this;
    }
    return make<_TransformedPointerCancelEventCls>(as<PointerCancelEvent>(original) | this, transform);
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
