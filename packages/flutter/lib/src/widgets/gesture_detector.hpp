#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_GESTURE_DETECTOR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_GESTURE_DETECTOR
#include <base.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "media_query.hpp"


template<typename T : GestureRecognizer> class GestureRecognizerFactoryCls : public ObjectCls {
public:

     GestureRecognizerFactoryCls();
    virtual T constructor();
    virtual void initializer(T instance);
private:

    virtual bool _debugAssertTypeMatches(Type type);

};
template<typename T : GestureRecognizer> using GestureRecognizerFactory = std::shared_ptr<GestureRecognizerFactoryCls<T : GestureRecognizer>>;

template<typename T : GestureRecognizer> class GestureRecognizerFactoryWithHandlersCls : public GestureRecognizerFactoryCls<T> {
public:

     GestureRecognizerFactoryWithHandlersCls(GestureRecognizerFactoryConstructor<T> _constructor, GestureRecognizerFactoryInitializer<T> _initializer);

    virtual T constructor();

    virtual void initializer(T instance);

private:
    GestureRecognizerFactoryConstructor<T> _constructor;

    GestureRecognizerFactoryInitializer<T> _initializer;


};
template<typename T : GestureRecognizer> using GestureRecognizerFactoryWithHandlers = std::shared_ptr<GestureRecognizerFactoryWithHandlersCls<T : GestureRecognizer>>;

class GestureDetectorCls : public StatelessWidgetCls {
public:
    Widget child;

    GestureTapDownCallback onTapDown;

    GestureTapUpCallback onTapUp;

    GestureTapCallback onTap;

    GestureTapCancelCallback onTapCancel;

    GestureTapCallback onSecondaryTap;

    GestureTapDownCallback onSecondaryTapDown;

    GestureTapUpCallback onSecondaryTapUp;

    GestureTapCancelCallback onSecondaryTapCancel;

    GestureTapDownCallback onTertiaryTapDown;

    GestureTapUpCallback onTertiaryTapUp;

    GestureTapCancelCallback onTertiaryTapCancel;

    GestureTapDownCallback onDoubleTapDown;

    GestureTapCallback onDoubleTap;

    GestureTapCancelCallback onDoubleTapCancel;

    GestureLongPressDownCallback onLongPressDown;

    GestureLongPressCancelCallback onLongPressCancel;

    GestureLongPressCallback onLongPress;

    GestureLongPressStartCallback onLongPressStart;

    GestureLongPressMoveUpdateCallback onLongPressMoveUpdate;

    GestureLongPressUpCallback onLongPressUp;

    GestureLongPressEndCallback onLongPressEnd;

    GestureLongPressDownCallback onSecondaryLongPressDown;

    GestureLongPressCancelCallback onSecondaryLongPressCancel;

    GestureLongPressCallback onSecondaryLongPress;

    GestureLongPressStartCallback onSecondaryLongPressStart;

    GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate;

    GestureLongPressUpCallback onSecondaryLongPressUp;

    GestureLongPressEndCallback onSecondaryLongPressEnd;

    GestureLongPressDownCallback onTertiaryLongPressDown;

    GestureLongPressCancelCallback onTertiaryLongPressCancel;

    GestureLongPressCallback onTertiaryLongPress;

    GestureLongPressStartCallback onTertiaryLongPressStart;

    GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate;

    GestureLongPressUpCallback onTertiaryLongPressUp;

    GestureLongPressEndCallback onTertiaryLongPressEnd;

    GestureDragDownCallback onVerticalDragDown;

    GestureDragStartCallback onVerticalDragStart;

    GestureDragUpdateCallback onVerticalDragUpdate;

    GestureDragEndCallback onVerticalDragEnd;

    GestureDragCancelCallback onVerticalDragCancel;

    GestureDragDownCallback onHorizontalDragDown;

    GestureDragStartCallback onHorizontalDragStart;

    GestureDragUpdateCallback onHorizontalDragUpdate;

    GestureDragEndCallback onHorizontalDragEnd;

    GestureDragCancelCallback onHorizontalDragCancel;

    GestureDragDownCallback onPanDown;

    GestureDragStartCallback onPanStart;

    GestureDragUpdateCallback onPanUpdate;

    GestureDragEndCallback onPanEnd;

    GestureDragCancelCallback onPanCancel;

    GestureScaleStartCallback onScaleStart;

    GestureScaleUpdateCallback onScaleUpdate;

    GestureScaleEndCallback onScaleEnd;

    GestureForcePressStartCallback onForcePressStart;

    GestureForcePressPeakCallback onForcePressPeak;

    GestureForcePressUpdateCallback onForcePressUpdate;

    GestureForcePressEndCallback onForcePressEnd;

    HitTestBehavior behavior;

    bool excludeFromSemantics;

    DragStartBehavior dragStartBehavior;


     GestureDetectorCls(HitTestBehavior behavior, Widget child, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, Unknown key, GestureTapCallback onDoubleTap, GestureTapCancelCallback onDoubleTapCancel, GestureTapDownCallback onDoubleTapDown, GestureForcePressEndCallback onForcePressEnd, GestureForcePressPeakCallback onForcePressPeak, GestureForcePressStartCallback onForcePressStart, GestureForcePressUpdateCallback onForcePressUpdate, GestureDragCancelCallback onHorizontalDragCancel, GestureDragDownCallback onHorizontalDragDown, GestureDragEndCallback onHorizontalDragEnd, GestureDragStartCallback onHorizontalDragStart, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureLongPressCancelCallback onLongPressCancel, GestureLongPressDownCallback onLongPressDown, GestureLongPressEndCallback onLongPressEnd, GestureLongPressMoveUpdateCallback onLongPressMoveUpdate, GestureLongPressStartCallback onLongPressStart, GestureLongPressUpCallback onLongPressUp, GestureDragCancelCallback onPanCancel, GestureDragDownCallback onPanDown, GestureDragEndCallback onPanEnd, GestureDragStartCallback onPanStart, GestureDragUpdateCallback onPanUpdate, GestureScaleEndCallback onScaleEnd, GestureScaleStartCallback onScaleStart, GestureScaleUpdateCallback onScaleUpdate, GestureLongPressCallback onSecondaryLongPress, GestureLongPressCancelCallback onSecondaryLongPressCancel, GestureLongPressDownCallback onSecondaryLongPressDown, GestureLongPressEndCallback onSecondaryLongPressEnd, GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate, GestureLongPressStartCallback onSecondaryLongPressStart, GestureLongPressUpCallback onSecondaryLongPressUp, GestureTapCallback onSecondaryTap, GestureTapCancelCallback onSecondaryTapCancel, GestureTapDownCallback onSecondaryTapDown, GestureTapUpCallback onSecondaryTapUp, GestureTapCallback onTap, GestureTapCancelCallback onTapCancel, GestureTapDownCallback onTapDown, GestureTapUpCallback onTapUp, GestureLongPressCallback onTertiaryLongPress, GestureLongPressCancelCallback onTertiaryLongPressCancel, GestureLongPressDownCallback onTertiaryLongPressDown, GestureLongPressEndCallback onTertiaryLongPressEnd, GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate, GestureLongPressStartCallback onTertiaryLongPressStart, GestureLongPressUpCallback onTertiaryLongPressUp, GestureTapCancelCallback onTertiaryTapCancel, GestureTapDownCallback onTertiaryTapDown, GestureTapUpCallback onTertiaryTapUp, GestureDragCancelCallback onVerticalDragCancel, GestureDragDownCallback onVerticalDragDown, GestureDragEndCallback onVerticalDragEnd, GestureDragStartCallback onVerticalDragStart, GestureDragUpdateCallback onVerticalDragUpdate);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using GestureDetector = std::shared_ptr<GestureDetectorCls>;

class RawGestureDetectorCls : public StatefulWidgetCls {
public:
    Widget child;

    Map<Type, GestureRecognizerFactory> gestures;

    HitTestBehavior behavior;

    bool excludeFromSemantics;

    SemanticsGestureDelegate semantics;


     RawGestureDetectorCls(HitTestBehavior behavior, Widget child, bool excludeFromSemantics, Map<Type, GestureRecognizerFactory> gestures, Unknown key, SemanticsGestureDelegate semantics);

    virtual RawGestureDetectorState createState();

private:

};
using RawGestureDetector = std::shared_ptr<RawGestureDetectorCls>;

class RawGestureDetectorStateCls : public StateCls<RawGestureDetector> {
public:

    virtual void initState();

    virtual void didUpdateWidget(RawGestureDetector oldWidget);

    virtual void replaceGestureRecognizers(Map<Type, GestureRecognizerFactory> gestures);

    virtual void replaceSemanticsActions(Set<SemanticsAction> actions);

    virtual void dispose();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<Type, GestureRecognizer> _recognizers;

    SemanticsGestureDelegate _semantics;


    virtual void _syncAll(Map<Type, GestureRecognizerFactory> gestures);

    virtual void _handlePointerDown(PointerDownEvent event);

    virtual void _handlePointerPanZoomStart(PointerPanZoomStartEvent event);

    virtual HitTestBehavior _defaultBehavior();

    virtual void _updateSemanticsForRenderObject(RenderSemanticsGestureHandler renderObject);

};
using RawGestureDetectorState = std::shared_ptr<RawGestureDetectorStateCls>;

class _GestureSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    HitTestBehavior behavior;

    _AssignSemantics assignSemantics;


    virtual RenderSemanticsGestureHandler createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSemanticsGestureHandler renderObject);

private:

     _GestureSemanticsCls(_AssignSemantics assignSemantics, HitTestBehavior behavior, Unknown child);

};
using _GestureSemantics = std::shared_ptr<_GestureSemanticsCls>;

class SemanticsGestureDelegateCls : public ObjectCls {
public:

     SemanticsGestureDelegateCls();
    virtual void assignSemantics(RenderSemanticsGestureHandler renderObject);
    virtual String toString();

private:

};
using SemanticsGestureDelegate = std::shared_ptr<SemanticsGestureDelegateCls>;

class _DefaultSemanticsGestureDelegateCls : public SemanticsGestureDelegateCls {
public:
    RawGestureDetectorState detectorState;


    virtual void assignSemantics(RenderSemanticsGestureHandler renderObject);

private:

     _DefaultSemanticsGestureDelegateCls(RawGestureDetectorState detectorState);
    virtual GestureTapCallback _getTapHandler(Map<Type, GestureRecognizer> recognizers);

    virtual GestureLongPressCallback _getLongPressHandler(Map<Type, GestureRecognizer> recognizers);

    virtual GestureDragUpdateCallback _getHorizontalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers);

    virtual GestureDragUpdateCallback _getVerticalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers);

};
using _DefaultSemanticsGestureDelegate = std::shared_ptr<_DefaultSemanticsGestureDelegateCls>;


#endif