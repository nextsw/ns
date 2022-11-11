#ifndef PACKAGES_FLUTTER_SRC_GESTURES_SCALE
#define PACKAGES_FLUTTER_SRC_GESTURES_SCALE
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "constants.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"


enum _ScaleState{
    ready,
    possible,
    accepted,
    started,
} // end _ScaleState

class _PointerPanZoomDataCls : public ObjectCls {
public:
    Offset focalPoint;

    double scale;

    double rotation;


    virtual String toString();

private:

     _PointerPanZoomDataCls(Offset focalPoint, double rotation, double scale);
};
using _PointerPanZoomData = std::shared_ptr<_PointerPanZoomDataCls>;

class ScaleStartDetailsCls : public ObjectCls {
public:
    Offset focalPoint;

    Offset localFocalPoint;

    int pointerCount;


     ScaleStartDetailsCls(Offset focalPoint, Offset localFocalPoint, int pointerCount);

    virtual String toString();

private:

};
using ScaleStartDetails = std::shared_ptr<ScaleStartDetailsCls>;

class ScaleUpdateDetailsCls : public ObjectCls {
public:
    Offset focalPointDelta;

    Offset focalPoint;

    Offset localFocalPoint;

    double scale;

    double horizontalScale;

    double verticalScale;

    double rotation;

    int pointerCount;


     ScaleUpdateDetailsCls(Offset focalPoint, Offset focalPointDelta, double horizontalScale, Offset localFocalPoint, int pointerCount, double rotation, double scale, double verticalScale);

    virtual String toString();

private:

};
using ScaleUpdateDetails = std::shared_ptr<ScaleUpdateDetailsCls>;

class ScaleEndDetailsCls : public ObjectCls {
public:
    Velocity velocity;

    int pointerCount;


     ScaleEndDetailsCls(int pointerCount, Velocity velocity);

    virtual String toString();

private:

};
using ScaleEndDetails = std::shared_ptr<ScaleEndDetailsCls>;
bool _isFlingGesture(Velocity velocity);


class _LineBetweenPointersCls : public ObjectCls {
public:
    Offset pointerStartLocation;

    int pointerStartId;

    Offset pointerEndLocation;

    int pointerEndId;


private:

     _LineBetweenPointersCls(int pointerEndId, Offset pointerEndLocation, int pointerStartId, Offset pointerStartLocation);

};
using _LineBetweenPointers = std::shared_ptr<_LineBetweenPointersCls>;

class ScaleGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    DragStartBehavior dragStartBehavior;

    GestureScaleStartCallback onStart;

    GestureScaleUpdateCallback onUpdate;

    GestureScaleEndCallback onEnd;


     ScaleGestureRecognizerCls(Object debugOwner, DragStartBehavior dragStartBehavior, Unknown kind, Unknown supportedDevices);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual bool isPointerPanZoomAllowed(PointerPanZoomStartEvent event);

    virtual void addAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    virtual void handleEvent(PointerEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void dispose();

    virtual String debugDescription();

private:
    _ScaleState _state;

    Matrix4 _lastTransform;

    Offset _initialFocalPoint;

    Offset _currentFocalPoint;

    double _initialSpan;

    double _currentSpan;

    double _initialHorizontalSpan;

    double _currentHorizontalSpan;

    double _initialVerticalSpan;

    double _currentVerticalSpan;

    Offset _localFocalPoint;

    _LineBetweenPointers _initialLine;

    _LineBetweenPointers _currentLine;

    Map<int, Offset> _pointerLocations;

    List<int> _pointerQueue;

    Map<int, VelocityTracker> _velocityTrackers;

    Offset _delta;

    Map<int, _PointerPanZoomData> _pointerPanZooms;

    double _initialPanZoomScaleFactor;

    double _initialPanZoomRotationFactor;


    virtual double _pointerScaleFactor();

    virtual double _pointerHorizontalScaleFactor();

    virtual double _pointerVerticalScaleFactor();

    virtual double _scaleFactor();

    virtual double _horizontalScaleFactor();

    virtual double _verticalScaleFactor();

    virtual int _pointerCount();

    virtual double _computeRotationFactor();

    virtual void _update();

    virtual void _updateLines();

    virtual bool _reconfigure(int pointer);

    virtual void _advanceStateMachine(bool shouldStartIfAccepted, PointerDeviceKind pointerDeviceKind);

    virtual void _dispatchOnStartCallbackIfNeeded();

};
using ScaleGestureRecognizer = std::shared_ptr<ScaleGestureRecognizerCls>;


#endif