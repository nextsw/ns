#ifndef MOUSE_TRACKER_H
#define MOUSE_TRACKER_H
#include <memory>
#include <flutter/services.hpp>

#include <collection/collection.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/services.hpp>
#include "object.hpp"



class _MouseState {
public:

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> annotations();

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> replaceAnnotations(LinkedHashMap<MouseTrackerAnnotation, Matrix4> value);

    PointerEvent latestEvent();

    PointerEvent replaceLatestEvent(PointerEvent value);

    int device();

    String toString();

private:
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> _annotations;

    PointerEvent _latestEvent;


     _MouseState(PointerEvent initialEvent);

};

class _MouseTrackerUpdateDetails {
public:
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations;

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations;

    PointerEvent previousEvent;

    PointerEvent triggeringEvent;


    void  byNewFrame(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent);

    void  byPointerEvent(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent, PointerEvent triggeringEvent);

    int device();

    PointerEvent latestEvent();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class MouseTracker : ChangeNotifier {
public:

    bool mouseIsConnected();

    void updateWithEvent(PointerEvent event, ValueGetter<HitTestResult> getResult);

    void updateAllDevices(MouseDetectorAnnotationFinder hitTest);

    MouseCursor debugDeviceActiveCursor(int device);

private:
    MouseCursorManager _mouseCursorMixin;

    Map<int, _MouseState> _mouseStates;

    bool _debugDuringDeviceUpdate;


    void _monitorMouseConnection(VoidCallback task);

    void _deviceUpdatePhase(VoidCallback task);

    static bool _shouldMarkStateDirty(PointerEvent event, _MouseState state);

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> _hitTestResultToAnnotations(HitTestResult result);

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> _findAnnotations(MouseDetectorAnnotationFinder hitTest, _MouseState state);

    void _handleDeviceUpdate(_MouseTrackerUpdateDetails details);

    static void _handleDeviceUpdateMouseEvents(_MouseTrackerUpdateDetails details);

};

#endif