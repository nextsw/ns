#ifndef MULTITAP_H
#define MULTITAP_H
#include <memory>
#include <ui.hpp>
#include "events.hpp"
#include "tap.hpp"

#include <async/async.hpp>
#include "arena.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "events.hpp"
#include "pointer_router.hpp"
#include "recognizer.hpp"
#include "tap.hpp"



class _CountdownZoned {
public:

    bool timeout();

private:
    bool _timeout;


     _CountdownZoned(Duration duration);

    void _onTimeout();

};

class _TapTracker {
public:
    DeviceGestureSettings gestureSettings;

    int pointer;

    GestureArenaEntry entry;

    int initialButtons;


    void startTrackingPointer(PointerRoute route, Matrix4 transform);

    void stopTrackingPointer(PointerRoute route);

    bool isWithinGlobalTolerance(PointerEvent event, double tolerance);

    bool hasElapsedMinTime();

    bool hasSameButton(PointerDownEvent event);

private:
    Offset _initialGlobalPosition;

    _CountdownZoned _doubleTapMinTimeCountdown;

    bool _isTrackingPointer;


     _TapTracker(Duration doubleTapMinTime, GestureArenaEntry entry, PointerDownEvent event, DeviceGestureSettings gestureSettings);

};

class DoubleTapGestureRecognizer : GestureRecognizer {
public:
    GestureTapDownCallback onDoubleTapDown;

    GestureDoubleTapCallback onDoubleTap;

    GestureTapCancelCallback onDoubleTapCancel;


     DoubleTapGestureRecognizer(Unknown, Unknown, Unknown);

    bool isPointerAllowed(PointerDownEvent event);

    void addAllowedPointer(PointerDownEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void dispose();

    String debugDescription();

private:
    Timer _doubleTapTimer;

    _TapTracker _firstTap;

    Map<int, _TapTracker> _trackers;


    void _trackTap(PointerDownEvent event);

    void _handleEvent(PointerEvent event);

    void _reject(_TapTracker tracker);

    void _reset();

    void _registerFirstTap(_TapTracker tracker);

    void _registerSecondTap(_TapTracker tracker);

    void _clearTrackers();

    void _freezeTracker(_TapTracker tracker);

    void _startDoubleTapTimer();

    void _stopDoubleTapTimer();

    void _checkUp(int buttons);

    void _checkCancel();

};

class _TapGesture : _TapTracker {
public:
    MultiTapGestureRecognizer gestureRecognizer;


    void handleEvent(PointerEvent event);

    void stopTrackingPointer(PointerRoute route);

    void accept();

    void reject();

    void cancel();

private:
    bool _wonArena;

    Timer _timer;

    OffsetPair _lastPosition;

    OffsetPair _finalPosition;


     _TapGesture(PointerEvent event, MultiTapGestureRecognizer gestureRecognizer, Unknown, Duration longTapDelay);

    void _check();

};

class MultiTapGestureRecognizer : GestureRecognizer {
public:
    GestureMultiTapDownCallback onTapDown;

    GestureMultiTapUpCallback onTapUp;

    GestureMultiTapCallback onTap;

    GestureMultiTapCancelCallback onTapCancel;

    Duration longTapDelay;

    GestureMultiTapDownCallback onLongTapDown;


     MultiTapGestureRecognizer(Unknown, Unknown, Duration longTapDelay, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void dispose();

    String debugDescription();

private:
    Map<int, _TapGesture> _gestureMap;


    void _dispatchCancel(int pointer);

    void _dispatchTap(int pointer, OffsetPair position);

    void _dispatchLongTap(OffsetPair lastPosition, int pointer);

};

class SerialTapDownDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;

    int buttons;

    int count;


     SerialTapDownDetails(int buttons, int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};

class SerialTapCancelDetails {
public:
    int count;


     SerialTapCancelDetails(int count);

private:

};

class SerialTapUpDetails {
public:
    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;

    int count;


     SerialTapUpDetails(int count, Offset globalPosition, PointerDeviceKind kind, Offset localPosition);

private:

};

class SerialTapGestureRecognizer : GestureRecognizer {
public:
    GestureSerialTapDownCallback onSerialTapDown;

    GestureSerialTapCancelCallback onSerialTapCancel;

    GestureSerialTapUpCallback onSerialTapUp;


     SerialTapGestureRecognizer(Unknown, Unknown);

    bool isTrackingPointer();

    bool isPointerAllowed(PointerDownEvent event);

    void addAllowedPointer(PointerDownEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void dispose();

    String debugDescription();

private:
    Timer _serialTapTimer;

    List<_TapTracker> _completedTaps;

    Map<int, GestureDisposition> _gestureResolutions;

    _TapTracker _pendingTap;


    bool _representsSameSeries(PointerDownEvent event, _TapTracker tap);

    void _trackTap(PointerDownEvent event);

    void _handleEvent(PointerEvent event);

    void _rejectPendingTap();

    void _reset();

    void _registerTap(PointerUpEvent event, _TapTracker tracker);

    void _stopTrackingPointer(_TapTracker tracker);

    void _startSerialTapTimer();

    void _stopSerialTapTimer();

    void _checkUp(PointerUpEvent event, _TapTracker tracker);

    void _checkCancel(int count);

};

#endif