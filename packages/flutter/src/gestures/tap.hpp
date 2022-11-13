#ifndef PACKAGES_FLUTTER_SRC_GESTURES_TAP
#define PACKAGES_FLUTTER_SRC_GESTURES_TAP
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "arena.hpp"
#include "events.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "arena.hpp"
#include "constants.hpp"
#include "events.hpp"
#include "recognizer.hpp"


class TapDownDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    PointerDeviceKind kind;

    Offset localPosition;


     TapDownDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};
using TapDownDetails = std::shared_ptr<TapDownDetailsCls>;

class TapUpDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;


     TapUpDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};
using TapUpDetails = std::shared_ptr<TapUpDetailsCls>;

class BaseTapGestureRecognizerCls : public PrimaryPointerGestureRecognizerCls {
public:

     BaseTapGestureRecognizerCls(Object debugOwner, Set<PointerDeviceKind> supportedDevices);

    virtual void handleTapDown(PointerDownEvent down);
    virtual void handleTapUp(PointerDownEvent down, PointerUpEvent up);
    virtual void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);
    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void startTrackingPointer(int pointer, Matrix4 transform);

    virtual void handlePrimaryPointer(PointerEvent event);

    virtual void resolve(GestureDisposition disposition);

    virtual void didExceedDeadline();

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual String debugDescription();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _sentTapDown;

    bool _wonArenaForPrimaryPointer;

    PointerDownEvent _down;

    PointerUpEvent _up;


    virtual void _checkDown();

    virtual void _checkUp();

    virtual void _checkCancel(PointerCancelEvent event, String note);

    virtual void _reset();

};
using BaseTapGestureRecognizer = std::shared_ptr<BaseTapGestureRecognizerCls>;

class TapGestureRecognizerCls : public BaseTapGestureRecognizerCls {
public:
    GestureTapDownCallback onTapDown;

    GestureTapUpCallback onTapUp;

    GestureTapCallback onTap;

    GestureTapCancelCallback onTapCancel;

    GestureTapCallback onSecondaryTap;

    GestureTapDownCallback onSecondaryTapDown;

    GestureTapUpCallback onSecondaryTapUp;

    GestureTapCancelCallback onSecondaryTapCancel;

    GestureTapDownCallback onTertiaryTapDown;

    GestureTapUpCallback onTertiaryTapUp;

    GestureTapCancelCallback onTertiaryTapCancel;


     TapGestureRecognizerCls(Object debugOwner, Set<PointerDeviceKind> supportedDevices);
    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void handleTapDown(PointerDownEvent down);

    virtual void handleTapUp(PointerDownEvent down, PointerUpEvent up);

    virtual void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);

    virtual String debugDescription();

private:

};
using TapGestureRecognizer = std::shared_ptr<TapGestureRecognizerCls>;


#endif