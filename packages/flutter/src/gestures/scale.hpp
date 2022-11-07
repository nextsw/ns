#ifndef SCALE_H
#define SCALE_H
#include <memory>
#include <ui.hpp>
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"

#include <math/math.hpp>
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

class _PointerPanZoomData {
public:
    Offset focalPoint;

    double scale;

    double rotation;


    String toString();

private:

     _PointerPanZoomData(Offset focalPoint, double rotation, double scale);

};

class ScaleStartDetails {
public:
    Offset focalPoint;

    Offset localFocalPoint;

    int pointerCount;


     ScaleStartDetails(Offset focalPoint, Offset localFocalPoint, int pointerCount);

    String toString();

private:

};

class ScaleUpdateDetails {
public:
    Offset focalPointDelta;

    Offset focalPoint;

    Offset localFocalPoint;

    double scale;

    double horizontalScale;

    double verticalScale;

    double rotation;

    int pointerCount;


     ScaleUpdateDetails(Offset focalPoint, Offset focalPointDelta, double horizontalScale, Offset localFocalPoint, int pointerCount, double rotation, double scale, double verticalScale);

    String toString();

private:

};

class ScaleEndDetails {
public:
    Velocity velocity;

    int pointerCount;


     ScaleEndDetails(int pointerCount, Velocity velocity);

    String toString();

private:

};
bool _isFlingGesture(Velocity velocity);


class _LineBetweenPointers {
public:
    Offset pointerStartLocation;

    int pointerStartId;

    Offset pointerEndLocation;

    int pointerEndId;


private:

     _LineBetweenPointers(int pointerEndId, Offset pointerEndLocation, int pointerStartId, Offset pointerStartLocation);

};

class ScaleGestureRecognizer : OneSequenceGestureRecognizer {
public:
    DragStartBehavior dragStartBehavior;

    GestureScaleStartCallback onStart;

    GestureScaleUpdateCallback onUpdate;

    GestureScaleEndCallback onEnd;


     ScaleGestureRecognizer(Unknown, DragStartBehavior dragStartBehavior, Unknown, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    bool isPointerPanZoomAllowed(PointerPanZoomStartEvent event);

    void addAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    void handleEvent(PointerEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void didStopTrackingLastPointer(int pointer);

    void dispose();

    String debugDescription();

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


    double _pointerScaleFactor();

    double _pointerHorizontalScaleFactor();

    double _pointerVerticalScaleFactor();

    double _scaleFactor();

    double _horizontalScaleFactor();

    double _verticalScaleFactor();

    int _pointerCount();

    double _computeRotationFactor();

    void _update();

    void _updateLines();

    bool _reconfigure(int pointer);

    void _advanceStateMachine(PointerDeviceKind pointerDeviceKind, bool shouldStartIfAccepted);

    void _dispatchOnStartCallbackIfNeeded();

};

#endif