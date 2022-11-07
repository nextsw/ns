#ifndef RECOGNIZER_H
#define RECOGNIZER_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "gesture_settings.hpp"
#include "team.hpp"

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include "arena.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "debug.hpp"
#include "events.hpp"
#include "pointer_router.hpp"
#include "team.hpp"



enum DragStartBehavior{
    down,
    start,
} // end DragStartBehavior

class GestureRecognizer : GestureArenaMember {
public:
    Object debugOwner;

    DeviceGestureSettings gestureSettings;


     GestureRecognizer(Object debugOwner, PointerDeviceKind kind, Set<PointerDeviceKind> supportedDevices);

    void addPointerPanZoom(PointerPanZoomStartEvent event);

    void addAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    void addPointer(PointerDownEvent event);

    void addAllowedPointer(PointerDownEvent event);

    void handleNonAllowedPointer(PointerDownEvent event);

    bool isPointerAllowed(PointerDownEvent event);

    void handleNonAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    bool isPointerPanZoomAllowed(PointerPanZoomStartEvent event);

    PointerDeviceKind getKindForPointer(int pointer);

    void dispose();

    String debugDescription();

    T invokeCallback<T>(RecognizerCallback<T> callback, FunctionType debugReport, String name);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<PointerDeviceKind> _supportedDevices;

    Map<int, PointerDeviceKind> _pointerToKind;


};

class OneSequenceGestureRecognizer : GestureRecognizer {
public:

     OneSequenceGestureRecognizer(Unknown, Unknown, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    void handleNonAllowedPointer(PointerDownEvent event);

    void handleEvent(PointerEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void didStopTrackingLastPointer(int pointer);

    void resolve(GestureDisposition disposition);

    void resolvePointer(GestureDisposition disposition, int pointer);

    void dispose();

    GestureArenaTeam team();

    void  team(GestureArenaTeam value);

    void startTrackingPointer(int pointer, Matrix4 transform);

    void stopTrackingPointer(int pointer);

    void stopTrackingIfPointerNoLongerDown(PointerEvent event);

private:
    Map<int, GestureArenaEntry> _entries;

    Set<int> _trackedPointers;

    GestureArenaTeam _team;


    GestureArenaEntry _addPointerToArena(int pointer);

};

enum GestureRecognizerState{
    ready,
    possible,
    defunct,
} // end GestureRecognizerState

class PrimaryPointerGestureRecognizer : OneSequenceGestureRecognizer {
public:
    Duration deadline;

    double preAcceptSlopTolerance;

    double postAcceptSlopTolerance;


     PrimaryPointerGestureRecognizer(Duration deadline, Unknown, Unknown, double postAcceptSlopTolerance, double preAcceptSlopTolerance, Unknown);

    GestureRecognizerState state();

    int primaryPointer();

    OffsetPair initialPosition();

    void addAllowedPointer(PointerDownEvent event);

    void handleNonAllowedPointer(PointerDownEvent event);

    void handleEvent(PointerEvent event);

    void handlePrimaryPointer(PointerEvent event);

    void didExceedDeadline();

    void didExceedDeadlineWithEvent(PointerDownEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void didStopTrackingLastPointer(int pointer);

    void dispose();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    GestureRecognizerState _state;

    int _primaryPointer;

    OffsetPair _initialPosition;

    bool _gestureAccepted;

    Timer _timer;


    void _stopTimer();

    double _getGlobalDistance(PointerEvent event);

};

class OffsetPair {
public:
    static const OffsetPair zero;

    Offset local;

    Offset global;


     OffsetPair(Offset global, Offset local);

    void  fromEventPosition(PointerEvent event);

    void  fromEventDelta(PointerEvent event);

    OffsetPair +(OffsetPair other);

    OffsetPair -(OffsetPair other);

    String toString();

private:

};

#endif