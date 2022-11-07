#ifndef MULTIDRAG_H
#define MULTIDRAG_H
#include <memory>
#include <ui.hpp>
#include "arena.hpp"
#include "drag.hpp"
#include "events.hpp"
#include "gesture_settings.hpp"

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include "arena.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "drag.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"



class MultiDragPointerState {
public:
    DeviceGestureSettings gestureSettings;

    Offset initialPosition;

    PointerDeviceKind kind;


     MultiDragPointerState(DeviceGestureSettings gestureSettings, Offset initialPosition, PointerDeviceKind kind);

    Offset pendingDelta();

    void resolve(GestureDisposition disposition);

    void checkForResolutionAfterMove();

    void accepted(GestureMultiDragStartCallback starter);

    void rejected();

    void dispose();

private:
    VelocityTracker _velocityTracker;

    Drag _client;

    Offset _pendingDelta;

    Duration _lastPendingEventTimestamp;

    GestureArenaEntry _arenaEntry;


    void _setArenaEntry(GestureArenaEntry entry);

    void _move(PointerMoveEvent event);

    void _startDrag(Drag client);

    void _up();

    void _cancel();

};

class MultiDragGestureRecognizer : GestureRecognizer {
public:
    GestureMultiDragStartCallback onStart;


     MultiDragGestureRecognizer(Unknown, Unknown, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    MultiDragPointerState createNewPointerState(PointerDownEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void dispose();

private:
    Map<int, MultiDragPointerState> _pointers;


    void _handleEvent(PointerEvent event);

    Drag _startDrag(Offset initialPosition, int pointer);

    void _removeState(int pointer);

};

class _ImmediatePointerState : MultiDragPointerState {
public:

    void checkForResolutionAfterMove();

    void accepted(GestureMultiDragStartCallback starter);

private:

     _ImmediatePointerState(Unknown, Unknown, Unknown);

};

class ImmediateMultiDragGestureRecognizer : MultiDragGestureRecognizer {
public:

     ImmediateMultiDragGestureRecognizer(Unknown, Unknown, Unknown);

    MultiDragPointerState createNewPointerState(PointerDownEvent event);

    String debugDescription();

private:

};

class _HorizontalPointerState : MultiDragPointerState {
public:

    void checkForResolutionAfterMove();

    void accepted(GestureMultiDragStartCallback starter);

private:

     _HorizontalPointerState(Unknown, Unknown, Unknown);

};

class HorizontalMultiDragGestureRecognizer : MultiDragGestureRecognizer {
public:

     HorizontalMultiDragGestureRecognizer(Unknown, Unknown, Unknown);

    MultiDragPointerState createNewPointerState(PointerDownEvent event);

    String debugDescription();

private:

};

class _VerticalPointerState : MultiDragPointerState {
public:

    void checkForResolutionAfterMove();

    void accepted(GestureMultiDragStartCallback starter);

private:

     _VerticalPointerState(Unknown, Unknown, Unknown);

};

class VerticalMultiDragGestureRecognizer : MultiDragGestureRecognizer {
public:

     VerticalMultiDragGestureRecognizer(Unknown, Unknown, Unknown);

    MultiDragPointerState createNewPointerState(PointerDownEvent event);

    String debugDescription();

private:

};

class _DelayedPointerState : MultiDragPointerState {
public:

    void accepted(GestureMultiDragStartCallback starter);

    void checkForResolutionAfterMove();

    void dispose();

private:
    Timer _timer;

    GestureMultiDragStartCallback _starter;


     _DelayedPointerState(Duration delay, DeviceGestureSettings deviceGestureSettings, Offset initialPosition, PointerDeviceKind kind);

    void _delayPassed();

    void _ensureTimerStopped();

};

class DelayedMultiDragGestureRecognizer : MultiDragGestureRecognizer {
public:
    Duration delay;


     DelayedMultiDragGestureRecognizer(Unknown, Duration delay, Unknown, Unknown);

    MultiDragPointerState createNewPointerState(PointerDownEvent event);

    String debugDescription();

private:

};

#endif