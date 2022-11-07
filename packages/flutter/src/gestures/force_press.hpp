#ifndef FORCE_PRESS_H
#define FORCE_PRESS_H
#include <memory>
#include <ui.hpp>
#include "events.hpp"

#include <flutter/foundation.hpp>
#include "events.hpp"
#include "recognizer.hpp"



enum _ForceState{
    ready,
    possible,
    accepted,
    started,
    peaked,
} // end _ForceState

class ForcePressDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    double pressure;


     ForcePressDetails(Offset globalPosition, Offset localPosition, double pressure);

private:

};

class ForcePressGestureRecognizer : OneSequenceGestureRecognizer {
public:
    GestureForcePressStartCallback onStart;

    GestureForcePressUpdateCallback onUpdate;

    GestureForcePressPeakCallback onPeak;

    GestureForcePressEndCallback onEnd;

    double startPressure;

    double peakPressure;

    GestureForceInterpolation interpolation;


     ForcePressGestureRecognizer(Unknown, GestureForceInterpolation interpolation, Unknown, double peakPressure, double startPressure, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    void handleEvent(PointerEvent event);

    void acceptGesture(int pointer);

    void didStopTrackingLastPointer(int pointer);

    void rejectGesture(int pointer);

    String debugDescription();

private:
    OffsetPair _lastPosition;

    double _lastPressure;

    _ForceState _state;


    static double _inverseLerp(double max, double min, double t);

};

#endif