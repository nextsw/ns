#ifndef LONG_PRESS_H
#define LONG_PRESS_H
#include <memory>
#include <ui.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "velocity_tracker.hpp"

#include "constants.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"



class LongPressDownDetails {
public:
    Offset globalPosition;

    PointerDeviceKind kind;

    Offset localPosition;


     LongPressDownDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};

class LongPressStartDetails {
public:
    Offset globalPosition;

    Offset localPosition;


     LongPressStartDetails(Offset globalPosition, Offset localPosition);

private:

};

class LongPressMoveUpdateDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    Offset offsetFromOrigin;

    Offset localOffsetFromOrigin;


     LongPressMoveUpdateDetails(Offset globalPosition, Offset localOffsetFromOrigin, Offset localPosition, Offset offsetFromOrigin);

private:

};

class LongPressEndDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    Velocity velocity;


     LongPressEndDetails(Offset globalPosition, Offset localPosition, Velocity velocity);

private:

};

class LongPressGestureRecognizer : PrimaryPointerGestureRecognizer {
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


     LongPressGestureRecognizer(Unknown, Duration duration, Unknown, Unknown, Unknown);

    bool isPointerAllowed(PointerDownEvent event);

    void didExceedDeadline();

    void handlePrimaryPointer(PointerEvent event);

    void resolve(GestureDisposition disposition);

    void acceptGesture(int pointer);

    String debugDescription();

private:
    bool _longPressAccepted;

    OffsetPair _longPressOrigin;

    int _initialButtons;

    VelocityTracker _velocityTracker;


    void _checkLongPressDown(PointerDownEvent event);

    void _checkLongPressCancel();

    void _checkLongPressStart();

    void _checkLongPressMoveUpdate(PointerEvent event);

    void _checkLongPressEnd(PointerEvent event);

    void _reset();

};

#endif