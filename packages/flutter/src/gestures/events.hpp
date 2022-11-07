#ifndef EVENTS_H
#define EVENTS_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "gesture_settings.hpp"

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "constants.hpp"
#include "gesture_settings.hpp"


const int kPrimaryButton;

const int kSecondaryButton;

const int kPrimaryMouseButton;

const int kSecondaryMouseButton;

const int kStylusContact;

const int kPrimaryStylusButton;

const int kTertiaryButton;

const int kMiddleMouseButton;

const int kSecondaryStylusButton;

const int kBackMouseButton;

const int kForwardMouseButton;

const int kTouchContact;

int nthMouseButton(int number);

int nthStylusButton(int number);

int smallestButton(int buttons);

bool isSingleButton(int buttons);


class PointerEvent {
public:
    int embedderId;

    Duration timeStamp;

    int pointer;

    PointerDeviceKind kind;

    int device;

    Offset position;

    Offset delta;

    int buttons;

    bool down;

    bool obscured;

    double pressure;

    double pressureMin;

    double pressureMax;

    double distance;

    double distanceMax;

    double size;

    double radiusMajor;

    double radiusMinor;

    double radiusMin;

    double radiusMax;

    double orientation;

    double tilt;

    int platformData;

    bool synthesized;

    Matrix4 transform;

    PointerEvent original;


     PointerEvent(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, PointerEvent original, int platformData, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp, Matrix4 transform);

    Offset localPosition();

    Offset localDelta();

    double distanceMin();

    PointerEvent transformed(Matrix4 transform);

    PointerEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

    static Offset transformPosition(Offset position, Matrix4 transform);

    static Offset transformDeltaViaPositions(Matrix4 transform, Offset transformedEndPosition, Offset untransformedDelta, Offset untransformedEndPosition);

    static Matrix4 removePerspectiveTransform(Matrix4 transform);

private:

};

class _PointerEventDescription {
public:

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String toStringFull();

private:

};

class _AbstractPointerEvent {
public:

private:

};

class _TransformedPointerEvent : _AbstractPointerEvent {
public:
    Offset localPosition;

    Offset localDelta;


    PointerEvent original();

    Matrix4 transform();

    int embedderId();

    Duration timeStamp();

    int pointer();

    PointerDeviceKind kind();

    int device();

    Offset position();

    Offset delta();

    int buttons();

    bool down();

    bool obscured();

    double pressure();

    double pressureMin();

    double pressureMax();

    double distance();

    double distanceMin();

    double distanceMax();

    double size();

    double radiusMajor();

    double radiusMinor();

    double radiusMin();

    double radiusMax();

    double orientation();

    double tilt();

    int platformData();

    bool synthesized();

private:

};

class _CopyPointerAddedEvent {
public:

    PointerAddedEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerAddedEvent : PointerEvent {
public:

     PointerAddedEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerAddedEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerAddedEvent : _TransformedPointerEvent {
public:
    PointerAddedEvent original;

    Matrix4 transform;


    PointerAddedEvent transformed(Matrix4 transform);

private:

     _TransformedPointerAddedEvent(PointerAddedEvent original, Matrix4 transform);

};

class _CopyPointerRemovedEvent {
public:

    PointerRemovedEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerRemovedEvent : PointerEvent {
public:

     PointerRemovedEvent(Unknown, Unknown, Unknown, Unknown, Unknown, PointerRemovedEvent original, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerRemovedEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerRemovedEvent : _TransformedPointerEvent {
public:
    PointerRemovedEvent original;

    Matrix4 transform;


    PointerRemovedEvent transformed(Matrix4 transform);

private:

     _TransformedPointerRemovedEvent(PointerRemovedEvent original, Matrix4 transform);

};

class _CopyPointerHoverEvent {
public:

    PointerHoverEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerHoverEvent : PointerEvent {
public:

     PointerHoverEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerHoverEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerHoverEvent : _TransformedPointerEvent {
public:
    PointerHoverEvent original;

    Matrix4 transform;


    PointerHoverEvent transformed(Matrix4 transform);

private:

     _TransformedPointerHoverEvent(PointerHoverEvent original, Matrix4 transform);

};

class _CopyPointerEnterEvent {
public:

    PointerEnterEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerEnterEvent : PointerEvent {
public:

     PointerEnterEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    void  fromMouseEvent(PointerEvent event);

    PointerEnterEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerEnterEvent : _TransformedPointerEvent {
public:
    PointerEnterEvent original;

    Matrix4 transform;


    PointerEnterEvent transformed(Matrix4 transform);

private:

     _TransformedPointerEnterEvent(PointerEnterEvent original, Matrix4 transform);

};

class _CopyPointerExitEvent {
public:

    PointerExitEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerExitEvent : PointerEvent {
public:

     PointerExitEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    void  fromMouseEvent(PointerEvent event);

    PointerExitEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerExitEvent : _TransformedPointerEvent {
public:
    PointerExitEvent original;

    Matrix4 transform;


    PointerExitEvent transformed(Matrix4 transform);

private:

     _TransformedPointerExitEvent(PointerExitEvent original, Matrix4 transform);

};

class _CopyPointerDownEvent {
public:

    PointerDownEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerDownEvent : PointerEvent {
public:

     PointerDownEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerDownEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerDownEvent : _TransformedPointerEvent {
public:
    PointerDownEvent original;

    Matrix4 transform;


    PointerDownEvent transformed(Matrix4 transform);

private:

     _TransformedPointerDownEvent(PointerDownEvent original, Matrix4 transform);

};

class _CopyPointerMoveEvent {
public:

    PointerMoveEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerMoveEvent : PointerEvent {
public:

     PointerMoveEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerMoveEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerMoveEvent : _TransformedPointerEvent {
public:
    PointerMoveEvent original;

    Matrix4 transform;


    PointerMoveEvent transformed(Matrix4 transform);

private:

     _TransformedPointerMoveEvent(PointerMoveEvent original, Matrix4 transform);

};

class _CopyPointerUpEvent {
public:

    PointerUpEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPosition, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerUpEvent : PointerEvent {
public:

     PointerUpEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerUpEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerUpEvent : _TransformedPointerEvent {
public:
    PointerUpEvent original;

    Matrix4 transform;


    PointerUpEvent transformed(Matrix4 transform);

private:

     _TransformedPointerUpEvent(PointerUpEvent original, Matrix4 transform);

};

class PointerSignalEvent : PointerEvent {
public:

     PointerSignalEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

private:

};

class _CopyPointerScrollEvent {
public:

    Offset scrollDelta();

    PointerScrollEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerScrollEvent : PointerSignalEvent {
public:
    Offset scrollDelta;


     PointerScrollEvent(Unknown, Unknown, Unknown, Unknown, Offset scrollDelta, Unknown);

    PointerScrollEvent transformed(Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _TransformedPointerScrollEvent : _TransformedPointerEvent {
public:
    PointerScrollEvent original;

    Matrix4 transform;


    Offset scrollDelta();

    PointerScrollEvent transformed(Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _TransformedPointerScrollEvent(PointerScrollEvent original, Matrix4 transform);

};

class _CopyPointerPanZoomStartEvent {
public:

    PointerPanZoomStartEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerPanZoomStartEvent : PointerEvent {
public:

     PointerPanZoomStartEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerPanZoomStartEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerPanZoomStartEvent : _TransformedPointerEvent {
public:
    PointerPanZoomStartEvent original;

    Matrix4 transform;


    PointerPanZoomStartEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomStartEvent(PointerPanZoomStartEvent original, Matrix4 transform);

};

class _CopyPointerPanZoomUpdateEvent {
public:

    Offset pan();

    Offset localPan();

    Offset panDelta();

    Offset localPanDelta();

    double scale();

    double rotation();

    PointerPanZoomUpdateEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPan, Offset localPanDelta, bool obscured, double orientation, Offset pan, Offset panDelta, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerPanZoomUpdateEvent : PointerEvent {
public:
    Offset pan;

    Offset panDelta;

    double scale;

    double rotation;


     PointerPanZoomUpdateEvent(Unknown, Unknown, Unknown, Offset pan, Offset panDelta, Unknown, Unknown, double rotation, double scale, Unknown, Unknown);

    Offset localPan();

    Offset localPanDelta();

    PointerPanZoomUpdateEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerPanZoomUpdateEvent : _TransformedPointerEvent {
public:
    Offset localPan;

    Offset localPanDelta;

    PointerPanZoomUpdateEvent original;

    Matrix4 transform;


    Offset pan();

    Offset panDelta();

    double scale();

    double rotation();

    PointerPanZoomUpdateEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomUpdateEvent(PointerPanZoomUpdateEvent original, Matrix4 transform);

};

class _CopyPointerPanZoomEndEvent {
public:

    PointerPanZoomEndEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerPanZoomEndEvent : PointerEvent {
public:

     PointerPanZoomEndEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerPanZoomEndEvent transformed(Matrix4 transform);

private:

};

class _TransformedPointerPanZoomEndEvent : _TransformedPointerEvent {
public:
    PointerPanZoomEndEvent original;

    Matrix4 transform;


    PointerPanZoomEndEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomEndEvent(PointerPanZoomEndEvent original, Matrix4 transform);

};

class _CopyPointerCancelEvent {
public:

    PointerCancelEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};

class PointerCancelEvent : PointerEvent {
public:

     PointerCancelEvent(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    PointerCancelEvent transformed(Matrix4 transform);

private:

};
double computeHitSlop(PointerDeviceKind kind, DeviceGestureSettings settings);

double computePanSlop(PointerDeviceKind kind, DeviceGestureSettings settings);

double computeScaleSlop(PointerDeviceKind kind);


class _TransformedPointerCancelEvent : _TransformedPointerEvent {
public:
    PointerCancelEvent original;

    Matrix4 transform;


    PointerCancelEvent transformed(Matrix4 transform);

private:

     _TransformedPointerCancelEvent(PointerCancelEvent original, Matrix4 transform);

};

#endif