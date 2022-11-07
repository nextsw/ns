#ifndef TAP_H
#define TAP_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "arena.hpp"
#include "events.hpp"

#include <flutter/foundation.hpp>
#include "arena.hpp"
#include "constants.hpp"
#include "events.hpp"
#include "recognizer.hpp"



class TapDownDetails {
public:
    Offset globalPosition;

    PointerDeviceKind kind;

    Offset localPosition;


     TapDownDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};

class TapUpDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;


     TapUpDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};

class BaseTapGestureRecognizer : PrimaryPointerGestureRecognizer {
public:

     BaseTapGestureRecognizer(Unknown, Unknown);

    void handleTapDown(PointerDownEvent down);

    void handleTapUp(PointerDownEvent down, PointerUpEvent up);

    void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);

    void addAllowedPointer(PointerDownEvent event);

    void startTrackingPointer(int pointer, Matrix4 transform);

    void handlePrimaryPointer(PointerEvent event);

    void resolve(GestureDisposition disposition);

    void didExceedDeadline();

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    String debugDescription();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _sentTapDown;

    bool _wonArenaForPrimaryPointer;

    PointerDownEvent _down;

    PointerUpEvent _up;


    void _checkDown();

    void _checkUp();

    void _checkCancel(PointerCancelEvent event, String note);

    void _reset();

};

class TapGestureRecognizer : BaseTapGestureRecognizer {
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


     TapGestureRecognizer(Unknown, Unknown);

    bool isPointerAllowed(PointerDownEvent event);

    void handleTapDown(PointerDownEvent down);

    void handleTapUp(PointerDownEvent down, PointerUpEvent up);

    void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);

    String debugDescription();

private:

};

#endif