#ifndef PACKAGES_FLUTTER_SRC_GESTURES_LONG_PRESS
#define PACKAGES_FLUTTER_SRC_GESTURES_LONG_PRESS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "velocity_tracker.hpp"

#include <dart/core/core.hpp>
#include "constants.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"


class LongPressDownDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    PointerDeviceKind kind;

    Offset localPosition;


     LongPressDownDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};
using LongPressDownDetails = std::shared_ptr<LongPressDownDetailsCls>;

class LongPressStartDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;


     LongPressStartDetailsCls(Offset globalPosition, Offset localPosition);

private:

};
using LongPressStartDetails = std::shared_ptr<LongPressStartDetailsCls>;

class LongPressMoveUpdateDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    Offset offsetFromOrigin;

    Offset localOffsetFromOrigin;


     LongPressMoveUpdateDetailsCls(Offset globalPosition, Offset localOffsetFromOrigin, Offset localPosition, Offset offsetFromOrigin);

private:

};
using LongPressMoveUpdateDetails = std::shared_ptr<LongPressMoveUpdateDetailsCls>;

class LongPressEndDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    Velocity velocity;


     LongPressEndDetailsCls(Offset globalPosition, Offset localPosition, Velocity velocity);

private:

};
using LongPressEndDetails = std::shared_ptr<LongPressEndDetailsCls>;

class LongPressGestureRecognizerCls : public PrimaryPointerGestureRecognizerCls {
public:
    GestureLongPressDownCallback onLongPressDown;

    GestureLongPressCancelCallback onLongPressCancel;

    GestureLongPressCallback onLongPress;

    GestureLongPressStartCallback onLongPressStart;

    GestureLongPressMoveUpdateCallback onLongPressMoveUpdate;

    GestureLongPressUpCallback onLongPressUp;

    GestureLongPressEndCallback onLongPressEnd;

    GestureLongPressDownCallback onSecondaryLongPressDown;

    GestureLongPressCancelCallback onSecondaryLongPressCancel;

    GestureLongPressCallback onSecondaryLongPress;

    GestureLongPressStartCallback onSecondaryLongPressStart;

    GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate;

    GestureLongPressUpCallback onSecondaryLongPressUp;

    GestureLongPressEndCallback onSecondaryLongPressEnd;

    GestureLongPressDownCallback onTertiaryLongPressDown;

    GestureLongPressCancelCallback onTertiaryLongPressCancel;

    GestureLongPressCallback onTertiaryLongPress;

    GestureLongPressStartCallback onTertiaryLongPressStart;

    GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate;

    GestureLongPressUpCallback onTertiaryLongPressUp;

    GestureLongPressEndCallback onTertiaryLongPressEnd;


     LongPressGestureRecognizerCls(Unknown debugOwner, Duration duration, Unknown kind, Unknown postAcceptSlopTolerance, Unknown supportedDevices);

    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void didExceedDeadline();

    virtual void handlePrimaryPointer(PointerEvent event);

    virtual void resolve(GestureDisposition disposition);

    virtual void acceptGesture(int pointer);

    virtual String debugDescription();

private:
    bool _longPressAccepted;

    OffsetPair _longPressOrigin;

    int _initialButtons;

    VelocityTracker _velocityTracker;


    virtual void _checkLongPressDown(PointerDownEvent event);

    virtual void _checkLongPressCancel();

    virtual void _checkLongPressStart();

    virtual void _checkLongPressMoveUpdate(PointerEvent event);

    virtual void _checkLongPressEnd(PointerEvent event);

    virtual void _reset();

};
using LongPressGestureRecognizer = std::shared_ptr<LongPressGestureRecognizerCls>;


#endif