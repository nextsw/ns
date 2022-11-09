#ifndef PACKAGES_FLUTTER_SRC_GESTURES_MULTIDRAG
#define PACKAGES_FLUTTER_SRC_GESTURES_MULTIDRAG
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "arena.hpp"
#include "drag.hpp"
#include "events.hpp"
#include "gesture_settings.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "arena.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "drag.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"


class MultiDragPointerStateCls : public ObjectCls {
public:
    DeviceGestureSettings gestureSettings;

    Offset initialPosition;

    PointerDeviceKind kind;


     MultiDragPointerStateCls(DeviceGestureSettings gestureSettings, Offset initialPosition, PointerDeviceKind kind);

    virtual Offset pendingDelta();

    virtual void resolve(GestureDisposition disposition);

    virtual void checkForResolutionAfterMove();

    virtual void accepted(GestureMultiDragStartCallback starter);
    virtual void rejected();

    virtual void dispose();

private:
    VelocityTracker _velocityTracker;

    Drag _client;

    Offset _pendingDelta;

    Duration _lastPendingEventTimestamp;

    GestureArenaEntry _arenaEntry;


    virtual void _setArenaEntry(GestureArenaEntry entry);

    virtual void _move(PointerMoveEvent event);

    virtual void _startDrag(Drag client);

    virtual void _up();

    virtual void _cancel();

};
using MultiDragPointerState = std::shared_ptr<MultiDragPointerStateCls>;

class MultiDragGestureRecognizerCls : public GestureRecognizerCls {
public:
    GestureMultiDragStartCallback onStart;


     MultiDragGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual void addAllowedPointer(PointerDownEvent event);

    virtual MultiDragPointerState createNewPointerState(PointerDownEvent event);
    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void dispose();

private:
    Map<int, MultiDragPointerState> _pointers;


    virtual void _handleEvent(PointerEvent event);

    virtual Drag _startDrag(Offset initialPosition, int pointer);

    virtual void _removeState(int pointer);

};
using MultiDragGestureRecognizer = std::shared_ptr<MultiDragGestureRecognizerCls>;

class _ImmediatePointerStateCls : public MultiDragPointerStateCls {
public:

    virtual void checkForResolutionAfterMove();

    virtual void accepted(GestureMultiDragStartCallback starter);

private:

     _ImmediatePointerStateCls(Unknown deviceGestureSettings, Unknown initialPosition, Unknown kind);
};
using _ImmediatePointerState = std::shared_ptr<_ImmediatePointerStateCls>;

class ImmediateMultiDragGestureRecognizerCls : public MultiDragGestureRecognizerCls {
public:

     ImmediateMultiDragGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual MultiDragPointerState createNewPointerState(PointerDownEvent event);

    virtual String debugDescription();

private:

};
using ImmediateMultiDragGestureRecognizer = std::shared_ptr<ImmediateMultiDragGestureRecognizerCls>;

class _HorizontalPointerStateCls : public MultiDragPointerStateCls {
public:

    virtual void checkForResolutionAfterMove();

    virtual void accepted(GestureMultiDragStartCallback starter);

private:

     _HorizontalPointerStateCls(Unknown deviceGestureSettings, Unknown initialPosition, Unknown kind);
};
using _HorizontalPointerState = std::shared_ptr<_HorizontalPointerStateCls>;

class HorizontalMultiDragGestureRecognizerCls : public MultiDragGestureRecognizerCls {
public:

     HorizontalMultiDragGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual MultiDragPointerState createNewPointerState(PointerDownEvent event);

    virtual String debugDescription();

private:

};
using HorizontalMultiDragGestureRecognizer = std::shared_ptr<HorizontalMultiDragGestureRecognizerCls>;

class _VerticalPointerStateCls : public MultiDragPointerStateCls {
public:

    virtual void checkForResolutionAfterMove();

    virtual void accepted(GestureMultiDragStartCallback starter);

private:

     _VerticalPointerStateCls(Unknown deviceGestureSettings, Unknown initialPosition, Unknown kind);
};
using _VerticalPointerState = std::shared_ptr<_VerticalPointerStateCls>;

class VerticalMultiDragGestureRecognizerCls : public MultiDragGestureRecognizerCls {
public:

     VerticalMultiDragGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual MultiDragPointerState createNewPointerState(PointerDownEvent event);

    virtual String debugDescription();

private:

};
using VerticalMultiDragGestureRecognizer = std::shared_ptr<VerticalMultiDragGestureRecognizerCls>;

class _DelayedPointerStateCls : public MultiDragPointerStateCls {
public:

    virtual void accepted(GestureMultiDragStartCallback starter);

    virtual void checkForResolutionAfterMove();

    virtual void dispose();

private:
    Timer _timer;

    GestureMultiDragStartCallback _starter;


     _DelayedPointerStateCls(Duration delay, DeviceGestureSettings deviceGestureSettings, Offset initialPosition, PointerDeviceKind kind);

    virtual void _delayPassed();

    virtual void _ensureTimerStopped();

};
using _DelayedPointerState = std::shared_ptr<_DelayedPointerStateCls>;

class DelayedMultiDragGestureRecognizerCls : public MultiDragGestureRecognizerCls {
public:
    Duration delay;


     DelayedMultiDragGestureRecognizerCls(Unknown debugOwner, Duration delay, Unknown kind, Unknown supportedDevices);

    virtual MultiDragPointerState createNewPointerState(PointerDownEvent event);

    virtual String debugDescription();

private:

};
using DelayedMultiDragGestureRecognizer = std::shared_ptr<DelayedMultiDragGestureRecognizerCls>;


#endif