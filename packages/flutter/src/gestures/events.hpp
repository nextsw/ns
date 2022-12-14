#ifndef PACKAGES_FLUTTER_SRC_GESTURES_EVENTS
#define PACKAGES_FLUTTER_SRC_GESTURES_EVENTS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "gesture_settings.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "constants.hpp"
#include "gesture_settings.hpp"

int kPrimaryButton;

int kSecondaryButton;

int kPrimaryMouseButton;

int kSecondaryMouseButton;

int kStylusContact;

int kPrimaryStylusButton;

int kTertiaryButton;

int kMiddleMouseButton;

int kSecondaryStylusButton;

int kBackMouseButton;

int kForwardMouseButton;

int kTouchContact;

int nthMouseButton(int number);

int nthStylusButton(int number);

int smallestButton(int buttons);

bool isSingleButton(int buttons);


class PointerEventCls : public ObjectCls {
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


     PointerEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, PointerEvent original, int platformData, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp, Matrix4 transform);
    virtual Offset localPosition();

    virtual Offset localDelta();

    virtual double distanceMin();

    virtual PointerEvent transformed(Matrix4 transform);
    virtual PointerEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);
    static Offset transformPosition(Matrix4 transform, Offset position);

    static Offset transformDeltaViaPositions(Matrix4 transform, Offset transformedEndPosition, Offset untransformedDelta, Offset untransformedEndPosition);

    static Matrix4 removePerspectiveTransform(Matrix4 transform);

private:

};
using PointerEvent = std::shared_ptr<PointerEventCls>;

class _PointerEventDescriptionCls : public ObjectCls {
public:

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String toStringFull();

private:

};
using _PointerEventDescription = std::shared_ptr<_PointerEventDescriptionCls>;

class _AbstractPointerEventCls : public ObjectCls {
public:

private:

};
using _AbstractPointerEvent = std::shared_ptr<_AbstractPointerEventCls>;

class _TransformedPointerEventCls : public _AbstractPointerEventCls {
public:
    Offset localPosition;

    Offset localDelta;


    virtual PointerEvent original();
    virtual Matrix4 transform();
    virtual int embedderId();

    virtual Duration timeStamp();

    virtual int pointer();

    virtual PointerDeviceKind kind();

    virtual int device();

    virtual Offset position();

    virtual Offset delta();

    virtual int buttons();

    virtual bool down();

    virtual bool obscured();

    virtual double pressure();

    virtual double pressureMin();

    virtual double pressureMax();

    virtual double distance();

    virtual double distanceMin();

    virtual double distanceMax();

    virtual double size();

    virtual double radiusMajor();

    virtual double radiusMinor();

    virtual double radiusMin();

    virtual double radiusMax();

    virtual double orientation();

    virtual double tilt();

    virtual int platformData();

    virtual bool synthesized();

private:

};
using _TransformedPointerEvent = std::shared_ptr<_TransformedPointerEventCls>;

class _CopyPointerAddedEventCls : public ObjectCls {
public:

    virtual PointerAddedEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerAddedEvent = std::shared_ptr<_CopyPointerAddedEventCls>;

class PointerAddedEventCls : public PointerEventCls {
public:

     PointerAddedEventCls(int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMax, double radiusMin, double tilt, Duration timeStamp);

    virtual PointerAddedEvent transformed(Matrix4 transform);

private:

};
using PointerAddedEvent = std::shared_ptr<PointerAddedEventCls>;

class _TransformedPointerAddedEventCls : public _TransformedPointerEventCls {
public:
    PointerAddedEvent original;

    Matrix4 transform;


    virtual PointerAddedEvent transformed(Matrix4 transform);

private:

     _TransformedPointerAddedEventCls(PointerAddedEvent original, Matrix4 transform);

};
using _TransformedPointerAddedEvent = std::shared_ptr<_TransformedPointerAddedEventCls>;

class _CopyPointerRemovedEventCls : public ObjectCls {
public:

    virtual PointerRemovedEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerRemovedEvent = std::shared_ptr<_CopyPointerRemovedEventCls>;

class PointerRemovedEventCls : public PointerEventCls {
public:

     PointerRemovedEventCls(int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, PointerEvent original, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMax, double radiusMin, Duration timeStamp);

    virtual PointerRemovedEvent transformed(Matrix4 transform);

private:

};
using PointerRemovedEvent = std::shared_ptr<PointerRemovedEventCls>;

class _TransformedPointerRemovedEventCls : public _TransformedPointerEventCls {
public:
    PointerRemovedEvent original;

    Matrix4 transform;


    virtual PointerRemovedEvent transformed(Matrix4 transform);

private:

     _TransformedPointerRemovedEventCls(PointerRemovedEvent original, Matrix4 transform);

};
using _TransformedPointerRemovedEvent = std::shared_ptr<_TransformedPointerRemovedEventCls>;

class _CopyPointerHoverEventCls : public ObjectCls {
public:

    virtual PointerHoverEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerHoverEvent = std::shared_ptr<_CopyPointerHoverEventCls>;

class PointerHoverEventCls : public PointerEventCls {
public:

     PointerHoverEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

    virtual PointerHoverEvent transformed(Matrix4 transform);

private:

};
using PointerHoverEvent = std::shared_ptr<PointerHoverEventCls>;

class _TransformedPointerHoverEventCls : public _TransformedPointerEventCls {
public:
    PointerHoverEvent original;

    Matrix4 transform;


    virtual PointerHoverEvent transformed(Matrix4 transform);

private:

     _TransformedPointerHoverEventCls(PointerHoverEvent original, Matrix4 transform);

};
using _TransformedPointerHoverEvent = std::shared_ptr<_TransformedPointerHoverEventCls>;

class _CopyPointerEnterEventCls : public ObjectCls {
public:

    virtual PointerEnterEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerEnterEvent = std::shared_ptr<_CopyPointerEnterEventCls>;

class PointerEnterEventCls : public PointerEventCls {
public:

     PointerEnterEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

    virtual void  fromMouseEvent(PointerEvent event);

    virtual PointerEnterEvent transformed(Matrix4 transform);

private:

};
using PointerEnterEvent = std::shared_ptr<PointerEnterEventCls>;

class _TransformedPointerEnterEventCls : public _TransformedPointerEventCls {
public:
    PointerEnterEvent original;

    Matrix4 transform;


    virtual PointerEnterEvent transformed(Matrix4 transform);

private:

     _TransformedPointerEnterEventCls(PointerEnterEvent original, Matrix4 transform);

};
using _TransformedPointerEnterEvent = std::shared_ptr<_TransformedPointerEnterEventCls>;

class _CopyPointerExitEventCls : public ObjectCls {
public:

    virtual PointerExitEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerExitEvent = std::shared_ptr<_CopyPointerExitEventCls>;

class PointerExitEventCls : public PointerEventCls {
public:

     PointerExitEventCls(int buttons, Offset delta, int device, double distance, double distanceMax, bool down, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

    virtual void  fromMouseEvent(PointerEvent event);

    virtual PointerExitEvent transformed(Matrix4 transform);

private:

};
using PointerExitEvent = std::shared_ptr<PointerExitEventCls>;

class _TransformedPointerExitEventCls : public _TransformedPointerEventCls {
public:
    PointerExitEvent original;

    Matrix4 transform;


    virtual PointerExitEvent transformed(Matrix4 transform);

private:

     _TransformedPointerExitEventCls(PointerExitEvent original, Matrix4 transform);

};
using _TransformedPointerExitEvent = std::shared_ptr<_TransformedPointerExitEventCls>;

class _CopyPointerDownEventCls : public ObjectCls {
public:

    virtual PointerDownEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerDownEvent = std::shared_ptr<_CopyPointerDownEventCls>;

class PointerDownEventCls : public PointerEventCls {
public:

     PointerDownEventCls(int buttons, int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp);

    virtual PointerDownEvent transformed(Matrix4 transform);

private:

};
using PointerDownEvent = std::shared_ptr<PointerDownEventCls>;

class _TransformedPointerDownEventCls : public _TransformedPointerEventCls {
public:
    PointerDownEvent original;

    Matrix4 transform;


    virtual PointerDownEvent transformed(Matrix4 transform);

private:

     _TransformedPointerDownEventCls(PointerDownEvent original, Matrix4 transform);

};
using _TransformedPointerDownEvent = std::shared_ptr<_TransformedPointerDownEventCls>;

class _CopyPointerMoveEventCls : public ObjectCls {
public:

    virtual PointerMoveEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerMoveEvent = std::shared_ptr<_CopyPointerMoveEventCls>;

class PointerMoveEventCls : public PointerEventCls {
public:

     PointerMoveEventCls(int buttons, Offset delta, int device, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int platformData, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

    virtual PointerMoveEvent transformed(Matrix4 transform);

private:

};
using PointerMoveEvent = std::shared_ptr<PointerMoveEventCls>;

class _TransformedPointerMoveEventCls : public _TransformedPointerEventCls {
public:
    PointerMoveEvent original;

    Matrix4 transform;


    virtual PointerMoveEvent transformed(Matrix4 transform);

private:

     _TransformedPointerMoveEventCls(PointerMoveEvent original, Matrix4 transform);

};
using _TransformedPointerMoveEvent = std::shared_ptr<_TransformedPointerMoveEventCls>;

class _CopyPointerUpEventCls : public ObjectCls {
public:

    virtual PointerUpEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPosition, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerUpEvent = std::shared_ptr<_CopyPointerUpEventCls>;

class PointerUpEventCls : public PointerEventCls {
public:

     PointerUpEventCls(int buttons, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp);

    virtual PointerUpEvent transformed(Matrix4 transform);

private:

};
using PointerUpEvent = std::shared_ptr<PointerUpEventCls>;

class _TransformedPointerUpEventCls : public _TransformedPointerEventCls {
public:
    PointerUpEvent original;

    Matrix4 transform;


    virtual PointerUpEvent transformed(Matrix4 transform);

private:

     _TransformedPointerUpEventCls(PointerUpEvent original, Matrix4 transform);

};
using _TransformedPointerUpEvent = std::shared_ptr<_TransformedPointerUpEventCls>;

class PointerSignalEventCls : public PointerEventCls {
public:

     PointerSignalEventCls(int device, int embedderId, PointerDeviceKind kind, int pointer, Offset position, Duration timeStamp);
private:

};
using PointerSignalEvent = std::shared_ptr<PointerSignalEventCls>;

class _CopyPointerScrollEventCls : public ObjectCls {
public:

    virtual Offset scrollDelta();
    virtual PointerScrollEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerScrollEvent = std::shared_ptr<_CopyPointerScrollEventCls>;

class PointerScrollEventCls : public PointerSignalEventCls {
public:
    Offset scrollDelta;


     PointerScrollEventCls(int device, int embedderId, PointerDeviceKind kind, Offset position, Offset scrollDelta, Duration timeStamp);

    virtual PointerScrollEvent transformed(Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PointerScrollEvent = std::shared_ptr<PointerScrollEventCls>;

class _TransformedPointerScrollEventCls : public _TransformedPointerEventCls {
public:
    PointerScrollEvent original;

    Matrix4 transform;


    virtual Offset scrollDelta();

    virtual PointerScrollEvent transformed(Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _TransformedPointerScrollEventCls(PointerScrollEvent original, Matrix4 transform);

};
using _TransformedPointerScrollEvent = std::shared_ptr<_TransformedPointerScrollEventCls>;

class _CopyPointerPanZoomStartEventCls : public ObjectCls {
public:

    virtual PointerPanZoomStartEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerPanZoomStartEvent = std::shared_ptr<_CopyPointerPanZoomStartEventCls>;

class PointerPanZoomStartEventCls : public PointerEventCls {
public:

     PointerPanZoomStartEventCls(int device, int embedderId, PointerDeviceKind kind, int pointer, Offset position, bool synthesized, Duration timeStamp);

    virtual PointerPanZoomStartEvent transformed(Matrix4 transform);

private:

};
using PointerPanZoomStartEvent = std::shared_ptr<PointerPanZoomStartEventCls>;

class _TransformedPointerPanZoomStartEventCls : public _TransformedPointerEventCls {
public:
    PointerPanZoomStartEvent original;

    Matrix4 transform;


    virtual PointerPanZoomStartEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomStartEventCls(PointerPanZoomStartEvent original, Matrix4 transform);

};
using _TransformedPointerPanZoomStartEvent = std::shared_ptr<_TransformedPointerPanZoomStartEventCls>;

class _CopyPointerPanZoomUpdateEventCls : public ObjectCls {
public:

    virtual Offset pan();
    virtual Offset localPan();
    virtual Offset panDelta();
    virtual Offset localPanDelta();
    virtual double scale();
    virtual double rotation();
    virtual PointerPanZoomUpdateEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, Offset localPan, Offset localPanDelta, bool obscured, double orientation, Offset pan, Offset panDelta, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerPanZoomUpdateEvent = std::shared_ptr<_CopyPointerPanZoomUpdateEventCls>;

class PointerPanZoomUpdateEventCls : public PointerEventCls {
public:
    Offset pan;

    Offset panDelta;

    double scale;

    double rotation;


     PointerPanZoomUpdateEventCls(int device, int embedderId, PointerDeviceKind kind, Offset pan, Offset panDelta, int pointer, Offset position, double rotation, double scale, bool synthesized, Duration timeStamp);

    virtual Offset localPan();

    virtual Offset localPanDelta();

    virtual PointerPanZoomUpdateEvent transformed(Matrix4 transform);

private:

};
using PointerPanZoomUpdateEvent = std::shared_ptr<PointerPanZoomUpdateEventCls>;

class _TransformedPointerPanZoomUpdateEventCls : public _TransformedPointerEventCls {
public:
    Offset localPan;

    Offset localPanDelta;

    PointerPanZoomUpdateEvent original;

    Matrix4 transform;


    virtual Offset pan();

    virtual Offset panDelta();

    virtual double scale();

    virtual double rotation();

    virtual PointerPanZoomUpdateEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomUpdateEventCls(PointerPanZoomUpdateEvent original, Matrix4 transform);

};
using _TransformedPointerPanZoomUpdateEvent = std::shared_ptr<_TransformedPointerPanZoomUpdateEventCls>;

class _CopyPointerPanZoomEndEventCls : public ObjectCls {
public:

    virtual PointerPanZoomEndEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerPanZoomEndEvent = std::shared_ptr<_CopyPointerPanZoomEndEventCls>;

class PointerPanZoomEndEventCls : public PointerEventCls {
public:

     PointerPanZoomEndEventCls(int device, int embedderId, PointerDeviceKind kind, int pointer, Offset position, bool synthesized, Duration timeStamp);

    virtual PointerPanZoomEndEvent transformed(Matrix4 transform);

private:

};
using PointerPanZoomEndEvent = std::shared_ptr<PointerPanZoomEndEventCls>;

class _TransformedPointerPanZoomEndEventCls : public _TransformedPointerEventCls {
public:
    PointerPanZoomEndEvent original;

    Matrix4 transform;


    virtual PointerPanZoomEndEvent transformed(Matrix4 transform);

private:

     _TransformedPointerPanZoomEndEventCls(PointerPanZoomEndEvent original, Matrix4 transform);

};
using _TransformedPointerPanZoomEndEvent = std::shared_ptr<_TransformedPointerPanZoomEndEventCls>;

class _CopyPointerCancelEventCls : public ObjectCls {
public:

    virtual PointerCancelEvent copyWith(int buttons, Offset delta, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, bool synthesized, double tilt, Duration timeStamp);

private:

};
using _CopyPointerCancelEvent = std::shared_ptr<_CopyPointerCancelEventCls>;

class PointerCancelEventCls : public PointerEventCls {
public:

     PointerCancelEventCls(int buttons, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, int pointer, Offset position, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double size, double tilt, Duration timeStamp);

    virtual PointerCancelEvent transformed(Matrix4 transform);

private:

};
using PointerCancelEvent = std::shared_ptr<PointerCancelEventCls>;
double computeHitSlop(PointerDeviceKind kind, DeviceGestureSettings settings);

double computePanSlop(PointerDeviceKind kind, DeviceGestureSettings settings);

double computeScaleSlop(PointerDeviceKind kind);


class _TransformedPointerCancelEventCls : public _TransformedPointerEventCls {
public:
    PointerCancelEvent original;

    Matrix4 transform;


    virtual PointerCancelEvent transformed(Matrix4 transform);

private:

     _TransformedPointerCancelEventCls(PointerCancelEvent original, Matrix4 transform);

};
using _TransformedPointerCancelEvent = std::shared_ptr<_TransformedPointerCancelEventCls>;


#endif