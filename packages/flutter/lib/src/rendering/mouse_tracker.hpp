#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_MOUSE_TRACKER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_MOUSE_TRACKER
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "object.hpp"


class _MouseStateCls : public ObjectCls {
public:

    virtual LinkedHashMap<MouseTrackerAnnotation, Matrix4> annotations();

    virtual LinkedHashMap<MouseTrackerAnnotation, Matrix4> replaceAnnotations(LinkedHashMap<MouseTrackerAnnotation, Matrix4> value);

    virtual PointerEvent latestEvent();

    virtual PointerEvent replaceLatestEvent(PointerEvent value);

    virtual int device();

    virtual String toString();

private:
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> _annotations;

    PointerEvent _latestEvent;


     _MouseStateCls(PointerEvent initialEvent);

};
using _MouseState = std::shared_ptr<_MouseStateCls>;

class _MouseTrackerUpdateDetailsCls : public ObjectCls {
public:
    LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations;

    LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations;

    PointerEvent previousEvent;

    PointerEvent triggeringEvent;


    virtual void  byNewFrame(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent);

    virtual void  byPointerEvent(LinkedHashMap<MouseTrackerAnnotation, Matrix4> lastAnnotations, LinkedHashMap<MouseTrackerAnnotation, Matrix4> nextAnnotations, PointerEvent previousEvent, PointerEvent triggeringEvent);

    virtual int device();

    virtual PointerEvent latestEvent();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using _MouseTrackerUpdateDetails = std::shared_ptr<_MouseTrackerUpdateDetailsCls>;

class MouseTrackerCls : public ChangeNotifierCls {
public:

    virtual bool mouseIsConnected();

    virtual void updateWithEvent(PointerEvent event, ValueGetter<HitTestResult> getResult);

    virtual void updateAllDevices(MouseDetectorAnnotationFinder hitTest);

    virtual MouseCursor debugDeviceActiveCursor(int device);

private:
    MouseCursorManager _mouseCursorMixin;

    Map<int, _MouseState> _mouseStates;

    bool _debugDuringDeviceUpdate;


    virtual void _monitorMouseConnection(VoidCallback task);

    virtual void _deviceUpdatePhase(VoidCallback task);

    static bool _shouldMarkStateDirty(_MouseState state, PointerEvent event);

    virtual LinkedHashMap<MouseTrackerAnnotation, Matrix4> _hitTestResultToAnnotations(HitTestResult result);

    virtual LinkedHashMap<MouseTrackerAnnotation, Matrix4> _findAnnotations(_MouseState state, MouseDetectorAnnotationFinder hitTest);

    virtual void _handleDeviceUpdate(_MouseTrackerUpdateDetails details);

    static void _handleDeviceUpdateMouseEvents(_MouseTrackerUpdateDetails details);

};
using MouseTracker = std::shared_ptr<MouseTrackerCls>;


#endif