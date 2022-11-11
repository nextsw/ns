#ifndef PACKAGES_FLUTTER_SRC_GESTURES_FORCE_PRESS
#define PACKAGES_FLUTTER_SRC_GESTURES_FORCE_PRESS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "events.hpp"
#include "recognizer.hpp"


enum _ForceState{
    ready,
    possible,
    accepted,
    started,
    peaked,
} // end _ForceState

class ForcePressDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    double pressure;


     ForcePressDetailsCls(Offset globalPosition, Offset localPosition, double pressure);

private:

};
using ForcePressDetails = std::shared_ptr<ForcePressDetailsCls>;

class ForcePressGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    GestureForcePressStartCallback onStart;

    GestureForcePressUpdateCallback onUpdate;

    GestureForcePressPeakCallback onPeak;

    GestureForcePressEndCallback onEnd;

    double startPressure;

    double peakPressure;

    GestureForceInterpolation interpolation;


     ForcePressGestureRecognizerCls(Object debugOwner, GestureForceInterpolation interpolation, Unknown kind, double peakPressure, double startPressure, Unknown supportedDevices);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void handleEvent(PointerEvent event);

    virtual void acceptGesture(int pointer);

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void rejectGesture(int pointer);

    virtual String debugDescription();

private:
    OffsetPair _lastPosition;

    double _lastPressure;

    _ForceState _state;


    static double _inverseLerp(double min, double max, double t);

};
using ForcePressGestureRecognizer = std::shared_ptr<ForcePressGestureRecognizerCls>;


#endif