#ifndef PACKAGES_FLUTTER_SRC_GESTURES_MULTITAP
#define PACKAGES_FLUTTER_SRC_GESTURES_MULTITAP
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"
#include "tap.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include "arena.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "events.hpp"
#include "pointer_router.hpp"
#include "recognizer.hpp"
#include "tap.hpp"


class _CountdownZonedCls : public ObjectCls {
public:

    virtual bool timeout();

private:
    bool _timeout;


     _CountdownZonedCls(Duration duration);

    virtual void _onTimeout();

};
using _CountdownZoned = std::shared_ptr<_CountdownZonedCls>;

class _TapTrackerCls : public ObjectCls {
public:
    DeviceGestureSettings gestureSettings;

    int pointer;

    GestureArenaEntry entry;

    int initialButtons;


    virtual void startTrackingPointer(PointerRoute route, Matrix4 transform);

    virtual void stopTrackingPointer(PointerRoute route);

    virtual bool isWithinGlobalTolerance(PointerEvent event, double tolerance);

    virtual bool hasElapsedMinTime();

    virtual bool hasSameButton(PointerDownEvent event);

private:
    Offset _initialGlobalPosition;

    _CountdownZoned _doubleTapMinTimeCountdown;

    bool _isTrackingPointer;


     _TapTrackerCls(Duration doubleTapMinTime, GestureArenaEntry entry, PointerDownEvent event, DeviceGestureSettings gestureSettings);

};
using _TapTracker = std::shared_ptr<_TapTrackerCls>;

class DoubleTapGestureRecognizerCls : public GestureRecognizerCls {
public:
    GestureTapDownCallback onDoubleTapDown;

    GestureDoubleTapCallback onDoubleTap;

    GestureTapCancelCallback onDoubleTapCancel;


     DoubleTapGestureRecognizerCls(Unknown debugOwner, Unknown kind, Unknown supportedDevices);
    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void dispose();

    virtual String debugDescription();

private:
    Timer _doubleTapTimer;

    _TapTracker _firstTap;

    Map<int, _TapTracker> _trackers;


    virtual void _trackTap(PointerDownEvent event);

    virtual void _handleEvent(PointerEvent event);

    virtual void _reject(_TapTracker tracker);

    virtual void _reset();

    virtual void _registerFirstTap(_TapTracker tracker);

    virtual void _registerSecondTap(_TapTracker tracker);

    virtual void _clearTrackers();

    virtual void _freezeTracker(_TapTracker tracker);

    virtual void _startDoubleTapTimer();

    virtual void _stopDoubleTapTimer();

    virtual void _checkUp(int buttons);

    virtual void _checkCancel();

};
using DoubleTapGestureRecognizer = std::shared_ptr<DoubleTapGestureRecognizerCls>;

class _TapGestureCls : public _TapTrackerCls {
public:
    MultiTapGestureRecognizer gestureRecognizer;


    virtual void handleEvent(PointerEvent event);

    virtual void stopTrackingPointer(PointerRoute route);

    virtual void accept();

    virtual void reject();

    virtual void cancel();

private:
    bool _wonArena;

    Timer _timer;

    OffsetPair _lastPosition;

    OffsetPair _finalPosition;


     _TapGestureCls(PointerEvent event, MultiTapGestureRecognizer gestureRecognizer, Unknown gestureSettings, Duration longTapDelay);

    virtual void _check();

};
using _TapGesture = std::shared_ptr<_TapGestureCls>;

class MultiTapGestureRecognizerCls : public GestureRecognizerCls {
public:
    GestureMultiTapDownCallback onTapDown;

    GestureMultiTapUpCallback onTapUp;

    GestureMultiTapCallback onTap;

    GestureMultiTapCancelCallback onTapCancel;

    Duration longTapDelay;

    GestureMultiTapDownCallback onLongTapDown;


     MultiTapGestureRecognizerCls(Unknown debugOwner, Unknown kind, Duration longTapDelay, Unknown supportedDevices);
    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void dispose();

    virtual String debugDescription();

private:
    Map<int, _TapGesture> _gestureMap;


    virtual void _dispatchCancel(int pointer);

    virtual void _dispatchTap(int pointer, OffsetPair position);

    virtual void _dispatchLongTap(int pointer, OffsetPair lastPosition);

};
using MultiTapGestureRecognizer = std::shared_ptr<MultiTapGestureRecognizerCls>;

class SerialTapDownDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;

    int buttons;

    int count;


     SerialTapDownDetailsCls(int buttons, int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};
using SerialTapDownDetails = std::shared_ptr<SerialTapDownDetailsCls>;

class SerialTapCancelDetailsCls : public ObjectCls {
public:
    int count;


     SerialTapCancelDetailsCls(int count);

private:

};
using SerialTapCancelDetails = std::shared_ptr<SerialTapCancelDetailsCls>;

class SerialTapUpDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;

    int count;


     SerialTapUpDetailsCls(int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};
using SerialTapUpDetails = std::shared_ptr<SerialTapUpDetailsCls>;

class SerialTapGestureRecognizerCls : public GestureRecognizerCls {
public:
    GestureSerialTapDownCallback onSerialTapDown;

    GestureSerialTapCancelCallback onSerialTapCancel;

    GestureSerialTapUpCallback onSerialTapUp;


     SerialTapGestureRecognizerCls(Unknown debugOwner, Unknown supportedDevices);
    virtual bool isTrackingPointer();

    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void addAllowedPointer(PointerDownEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void dispose();

    virtual String debugDescription();

private:
    Timer _serialTapTimer;

    List<_TapTracker> _completedTaps;

    Map<int, GestureDisposition> _gestureResolutions;

    _TapTracker _pendingTap;


    virtual bool _representsSameSeries(_TapTracker tap, PointerDownEvent event);

    virtual void _trackTap(PointerDownEvent event);

    virtual void _handleEvent(PointerEvent event);

    virtual void _rejectPendingTap();

    virtual void _reset();

    virtual void _registerTap(PointerUpEvent event, _TapTracker tracker);

    virtual void _stopTrackingPointer(_TapTracker tracker);

    virtual void _startSerialTapTimer();

    virtual void _stopSerialTapTimer();

    virtual void _checkUp(PointerUpEvent event, _TapTracker tracker);

    virtual void _checkCancel(int count);

};
using SerialTapGestureRecognizer = std::shared_ptr<SerialTapGestureRecognizerCls>;


#endif