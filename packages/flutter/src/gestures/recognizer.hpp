#ifndef PACKAGES_FLUTTER_SRC_GESTURES_RECOGNIZER
#define PACKAGES_FLUTTER_SRC_GESTURES_RECOGNIZER
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "gesture_settings.hpp"
#include "team.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class GestureRecognizerCls : public GestureArenaMemberCls {
public:
    Object debugOwner;

    DeviceGestureSettings gestureSettings;


     GestureRecognizerCls(Object debugOwner, PointerDeviceKind kind, Set<PointerDeviceKind> supportedDevices);

    virtual void addPointerPanZoom(PointerPanZoomStartEvent event);

    virtual void addAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    virtual void addPointer(PointerDownEvent event);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void handleNonAllowedPointer(PointerDownEvent event);

    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void handleNonAllowedPointerPanZoom(PointerPanZoomStartEvent event);

    virtual bool isPointerPanZoomAllowed(PointerPanZoomStartEvent event);

    virtual PointerDeviceKind getKindForPointer(int pointer);

    virtual void dispose();

    virtual String debugDescription();
    template<typename T>  virtual T invokeCallback(RecognizerCallback<T> callback, String debugReport() , String name);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<PointerDeviceKind> _supportedDevices;

    Map<int, PointerDeviceKind> _pointerToKind;


};
using GestureRecognizer = std::shared_ptr<GestureRecognizerCls>;

class OneSequenceGestureRecognizerCls : public GestureRecognizerCls {
public:

     OneSequenceGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void handleNonAllowedPointer(PointerDownEvent event);

    virtual void handleEvent(PointerEvent event);
    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void didStopTrackingLastPointer(int pointer);
    virtual void resolve(GestureDisposition disposition);

    virtual void resolvePointer(GestureDisposition disposition, int pointer);

    virtual void dispose();

    virtual GestureArenaTeam team();

    virtual void  team(GestureArenaTeam value);

    virtual void startTrackingPointer(int pointer, Matrix4 transform);

    virtual void stopTrackingPointer(int pointer);

    virtual void stopTrackingIfPointerNoLongerDown(PointerEvent event);

private:
    Map<int, GestureArenaEntry> _entries;

    Set<int> _trackedPointers;

    GestureArenaTeam _team;


    virtual GestureArenaEntry _addPointerToArena(int pointer);

};
using OneSequenceGestureRecognizer = std::shared_ptr<OneSequenceGestureRecognizerCls>;

enum GestureRecognizerState{
    ready,
    possible,
    defunct,
} // end GestureRecognizerState

class PrimaryPointerGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    Duration deadline;

    double preAcceptSlopTolerance;

    double postAcceptSlopTolerance;


     PrimaryPointerGestureRecognizerCls(Duration deadline, Unknown debugOwner, Unknown kind, double postAcceptSlopTolerance, double preAcceptSlopTolerance, Unknown supportedDevices);

    virtual GestureRecognizerState state();

    virtual int primaryPointer();

    virtual OffsetPair initialPosition();

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void handleNonAllowedPointer(PointerDownEvent event);

    virtual void handleEvent(PointerEvent event);

    virtual void handlePrimaryPointer(PointerEvent event);
    virtual void didExceedDeadline();

    virtual void didExceedDeadlineWithEvent(PointerDownEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void dispose();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    GestureRecognizerState _state;

    int _primaryPointer;

    OffsetPair _initialPosition;

    bool _gestureAccepted;

    Timer _timer;


    virtual void _stopTimer();

    virtual double _getGlobalDistance(PointerEvent event);

};
using PrimaryPointerGestureRecognizer = std::shared_ptr<PrimaryPointerGestureRecognizerCls>;

class OffsetPairCls : public ObjectCls {
public:
    static OffsetPair zero;

    Offset local;

    Offset global;


     OffsetPairCls(Offset global, Offset local);
    virtual void  fromEventPosition(PointerEvent event);

    virtual void  fromEventDelta(PointerEvent event);

    virtual OffsetPair operator+(OffsetPair other);

    virtual OffsetPair operator-(OffsetPair other);

    virtual String toString();

private:

};
using OffsetPair = std::shared_ptr<OffsetPairCls>;


#endif