#ifndef PACKAGES_FLUTTER_SRC_GESTURES_MONODRAG
#define PACKAGES_FLUTTER_SRC_GESTURES_MONODRAG
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "drag.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "constants.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"


enum _DragState{
    ready,
    possible,
    accepted,
} // end _DragState

class DragGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    DragStartBehavior dragStartBehavior;

    GestureDragDownCallback onDown;

    GestureDragStartCallback onStart;

    GestureDragUpdateCallback onUpdate;

    GestureDragEndCallback onEnd;

    GestureDragCancelCallback onCancel;

    double minFlingDistance;

    double minFlingVelocity;

    double maxFlingVelocity;

    GestureVelocityTrackerBuilder velocityTrackerBuilder;


     DragGestureRecognizerCls(Object debugOwner, DragStartBehavior dragStartBehavior, Unknown kind, Unknown supportedDevices, GestureVelocityTrackerBuilder velocityTrackerBuilder);

    virtual bool isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind);
    virtual bool isPointerAllowed(PointerEvent event);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void addAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    virtual void handleEvent(PointerEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void dispose();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    _DragState _state;

    OffsetPair _initialPosition;

    OffsetPair _pendingDragOffset;

    Duration _lastPendingEventTimestamp;

    int _initialButtons;

    Matrix4 _lastTransform;

    double _globalDistanceMoved;

    Map<int, VelocityTracker> _velocityTrackers;

    Set<int> _acceptedActivePointers;


    static VelocityTracker _defaultBuilder(PointerEvent event);

    virtual Offset _getDeltaForDetails(Offset delta);
    virtual double _getPrimaryValueFromOffset(Offset value);
    virtual bool _hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop);
    virtual void _addPointer(PointerEvent event);

    virtual void _giveUpPointer(int pointer);

    virtual void _checkDown();

    virtual void _checkStart(Duration timestamp, int pointer);

    virtual void _checkUpdate(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp);

    virtual void _checkEnd(int pointer);

    virtual void _checkCancel();

};
using DragGestureRecognizer = std::shared_ptr<DragGestureRecognizerCls>;

class VerticalDragGestureRecognizerCls : public DragGestureRecognizerCls {
public:

     VerticalDragGestureRecognizerCls(Object debugOwner, Unknown kind, Unknown supportedDevices);
    virtual bool isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind);

    virtual String debugDescription();

private:

    virtual bool _hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop);

    virtual Offset _getDeltaForDetails(Offset delta);

    virtual double _getPrimaryValueFromOffset(Offset value);

};
using VerticalDragGestureRecognizer = std::shared_ptr<VerticalDragGestureRecognizerCls>;

class HorizontalDragGestureRecognizerCls : public DragGestureRecognizerCls {
public:

     HorizontalDragGestureRecognizerCls(Object debugOwner, Unknown kind, Unknown supportedDevices);
    virtual bool isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind);

    virtual String debugDescription();

private:

    virtual bool _hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop);

    virtual Offset _getDeltaForDetails(Offset delta);

    virtual double _getPrimaryValueFromOffset(Offset value);

};
using HorizontalDragGestureRecognizer = std::shared_ptr<HorizontalDragGestureRecognizerCls>;

class PanGestureRecognizerCls : public DragGestureRecognizerCls {
public:

     PanGestureRecognizerCls(Object debugOwner, Unknown supportedDevices);
    virtual bool isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind);

    virtual String debugDescription();

private:

    virtual bool _hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop);

    virtual Offset _getDeltaForDetails(Offset delta);

    virtual double _getPrimaryValueFromOffset(Offset value);

};
using PanGestureRecognizer = std::shared_ptr<PanGestureRecognizerCls>;


#endif