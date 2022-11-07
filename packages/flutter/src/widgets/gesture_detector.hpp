#ifndef GESTURE_DETECTOR_H
#define GESTURE_DETECTOR_H
#include <memory>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "media_query.hpp"



class GestureRecognizerFactory<T extends GestureRecognizer> {
public:

     GestureRecognizerFactory();

    T constructor();

    void initializer(T instance);

private:

    bool _debugAssertTypeMatches(Type type);

};

class GestureRecognizerFactoryWithHandlers<T extends GestureRecognizer> : GestureRecognizerFactory<T> {
public:

     GestureRecognizerFactoryWithHandlers(GestureRecognizerFactoryConstructor<T> _constructor, GestureRecognizerFactoryInitializer<T> _initializer);

    T constructor();

    void initializer(T instance);

private:
    GestureRecognizerFactoryConstructor<T> _constructor;

    GestureRecognizerFactoryInitializer<T> _initializer;


};

class GestureDetector : StatelessWidget {
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


     GestureDetector(HitTestBehavior behavior, Widget child, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, Unknown, GestureTapCallback onDoubleTap, GestureTapCancelCallback onDoubleTapCancel, GestureTapDownCallback onDoubleTapDown, GestureForcePressEndCallback onForcePressEnd, GestureForcePressPeakCallback onForcePressPeak, GestureForcePressStartCallback onForcePressStart, GestureForcePressUpdateCallback onForcePressUpdate, GestureDragCancelCallback onHorizontalDragCancel, GestureDragDownCallback onHorizontalDragDown, GestureDragEndCallback onHorizontalDragEnd, GestureDragStartCallback onHorizontalDragStart, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureLongPressCancelCallback onLongPressCancel, GestureLongPressDownCallback onLongPressDown, GestureLongPressEndCallback onLongPressEnd, GestureLongPressMoveUpdateCallback onLongPressMoveUpdate, GestureLongPressStartCallback onLongPressStart, GestureLongPressUpCallback onLongPressUp, GestureDragCancelCallback onPanCancel, GestureDragDownCallback onPanDown, GestureDragEndCallback onPanEnd, GestureDragStartCallback onPanStart, GestureDragUpdateCallback onPanUpdate, GestureScaleEndCallback onScaleEnd, GestureScaleStartCallback onScaleStart, GestureScaleUpdateCallback onScaleUpdate, GestureLongPressCallback onSecondaryLongPress, GestureLongPressCancelCallback onSecondaryLongPressCancel, GestureLongPressDownCallback onSecondaryLongPressDown, GestureLongPressEndCallback onSecondaryLongPressEnd, GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate, GestureLongPressStartCallback onSecondaryLongPressStart, GestureLongPressUpCallback onSecondaryLongPressUp, GestureTapCallback onSecondaryTap, GestureTapCancelCallback onSecondaryTapCancel, GestureTapDownCallback onSecondaryTapDown, GestureTapUpCallback onSecondaryTapUp, GestureTapCallback onTap, GestureTapCancelCallback onTapCancel, GestureTapDownCallback onTapDown, GestureTapUpCallback onTapUp, GestureLongPressCallback onTertiaryLongPress, GestureLongPressCancelCallback onTertiaryLongPressCancel, GestureLongPressDownCallback onTertiaryLongPressDown, GestureLongPressEndCallback onTertiaryLongPressEnd, GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate, GestureLongPressStartCallback onTertiaryLongPressStart, GestureLongPressUpCallback onTertiaryLongPressUp, GestureTapCancelCallback onTertiaryTapCancel, GestureTapDownCallback onTertiaryTapDown, GestureTapUpCallback onTertiaryTapUp, GestureDragCancelCallback onVerticalDragCancel, GestureDragDownCallback onVerticalDragDown, GestureDragEndCallback onVerticalDragEnd, GestureDragStartCallback onVerticalDragStart, GestureDragUpdateCallback onVerticalDragUpdate);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RawGestureDetector : StatefulWidget {
public:
    Widget child;

    Map<Type, GestureRecognizerFactory> gestures;

    HitTestBehavior behavior;

    bool excludeFromSemantics;

    SemanticsGestureDelegate semantics;


     RawGestureDetector(HitTestBehavior behavior, Widget child, bool excludeFromSemantics, Map<Type, GestureRecognizerFactory> gestures, Unknown, SemanticsGestureDelegate semantics);

    RawGestureDetectorState createState();

private:

};

class RawGestureDetectorState : State<RawGestureDetector> {
public:

    void initState();

    void didUpdateWidget(RawGestureDetector oldWidget);

    void replaceGestureRecognizers(Map<Type, GestureRecognizerFactory> gestures);

    void replaceSemanticsActions(Set<SemanticsAction> actions);

    void dispose();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<Type, GestureRecognizer> _recognizers;

    SemanticsGestureDelegate _semantics;


    void _syncAll(Map<Type, GestureRecognizerFactory> gestures);

    void _handlePointerDown(PointerDownEvent event);

    void _handlePointerPanZoomStart(PointerPanZoomStartEvent event);

    HitTestBehavior _defaultBehavior();

    void _updateSemanticsForRenderObject(RenderSemanticsGestureHandler renderObject);

};

class _GestureSemantics : SingleChildRenderObjectWidget {
public:
    HitTestBehavior behavior;

    _AssignSemantics assignSemantics;


    RenderSemanticsGestureHandler createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSemanticsGestureHandler renderObject);

private:

     _GestureSemantics(_AssignSemantics assignSemantics, HitTestBehavior behavior, Unknown);

};

class SemanticsGestureDelegate {
public:

     SemanticsGestureDelegate();

    void assignSemantics(RenderSemanticsGestureHandler renderObject);

    String toString();

private:

};

class _DefaultSemanticsGestureDelegate : SemanticsGestureDelegate {
public:
    RawGestureDetectorState detectorState;


    void assignSemantics(RenderSemanticsGestureHandler renderObject);

private:

     _DefaultSemanticsGestureDelegate(RawGestureDetectorState detectorState);

    GestureTapCallback _getTapHandler(Map<Type, GestureRecognizer> recognizers);

    GestureLongPressCallback _getLongPressHandler(Map<Type, GestureRecognizer> recognizers);

    GestureDragUpdateCallback _getHorizontalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers);

    GestureDragUpdateCallback _getVerticalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers);

};

#endif