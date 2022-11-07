#ifndef DRAG_TARGET_H
#define DRAG_TARGET_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "overlay.hpp"


Offset childDragAnchorStrategy(BuildContext context, Draggable<Object> draggable, Offset position);

Offset pointerDragAnchorStrategy(BuildContext context, Draggable<Object> draggable, Offset position);


enum DragAnchor{
    child,
    pointer,
} // end DragAnchor

class Draggable<T extends Object> : StatefulWidget {
public:
    T data;

    Axis axis;

    Widget child;

    Widget childWhenDragging;

    Widget feedback;

    Offset feedbackOffset;

    DragAnchor dragAnchor;

    DragAnchorStrategy dragAnchorStrategy;

    bool ignoringFeedbackSemantics;

    bool ignoringFeedbackPointer;

    Axis affinity;

    int maxSimultaneousDrags;

    VoidCallback onDragStarted;

    DragUpdateCallback onDragUpdate;

    DraggableCanceledCallback onDraggableCanceled;

    VoidCallback onDragCompleted;

    DragEndCallback onDragEnd;

    bool rootOverlay;

    HitTestBehavior hitTestBehavior;


     Draggable(Axis affinity, Axis axis, Widget child, Widget childWhenDragging, T data, DragAnchor dragAnchor, DragAnchorStrategy dragAnchorStrategy, Widget feedback, Offset feedbackOffset, HitTestBehavior hitTestBehavior, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Unknown, int maxSimultaneousDrags, VoidCallback onDragCompleted, DragEndCallback onDragEnd, VoidCallback onDragStarted, DragUpdateCallback onDragUpdate, DraggableCanceledCallback onDraggableCanceled, bool rootOverlay);

    MultiDragGestureRecognizer createRecognizer(GestureMultiDragStartCallback onStart);

    State<Draggable<T>> createState();

private:

};

class LongPressDraggable<T extends Object> : Draggable<T> {
public:
    bool hapticFeedbackOnStart;

    Duration delay;


     LongPressDraggable(Unknown, Unknown, Unknown, Unknown, Duration delay, Unknown, Unknown, Unknown, Unknown, bool hapticFeedbackOnStart, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    DelayedMultiDragGestureRecognizer createRecognizer(GestureMultiDragStartCallback onStart);

private:

};

class _DraggableState<T extends Object> : State<Draggable<T>> {
public:

    void initState();

    void dispose();

    void didChangeDependencies();

    Widget build(BuildContext context);

private:
    GestureRecognizer _recognizer;

    int _activeCount;


    void _disposeRecognizerIfInactive();

    void _routePointer(PointerDownEvent event);

    _DragAvatar<T> _startDrag(Offset position);

};

class DraggableDetails {
public:
    bool wasAccepted;

    Velocity velocity;

    Offset offset;


     DraggableDetails(Offset offset, Velocity velocity, bool wasAccepted);

private:

};

class DragTargetDetails<T> {
public:
    T data;

    Offset offset;


     DragTargetDetails(T data, Offset offset);

private:

};

class DragTarget<T extends Object> : StatefulWidget {
public:
    DragTargetBuilder<T> builder;

    DragTargetWillAccept<T> onWillAccept;

    DragTargetAccept<T> onAccept;

    DragTargetAcceptWithDetails<T> onAcceptWithDetails;

    DragTargetLeave<T> onLeave;

    DragTargetMove<T> onMove;

    HitTestBehavior hitTestBehavior;


     DragTarget(DragTargetBuilder<T> builder, HitTestBehavior hitTestBehavior, Unknown, DragTargetAccept<T> onAccept, DragTargetAcceptWithDetails<T> onAcceptWithDetails, DragTargetLeave<T> onLeave, DragTargetMove<T> onMove, DragTargetWillAccept<T> onWillAccept);

    State<DragTarget<T>> createState();

private:

};
List<T> _mapAvatarsToData<T extends Object>(List<_DragAvatar<Object>> avatars);


class _DragTargetState<T extends Object> : State<DragTarget<T>> {
public:

    bool isExpectedDataType(Object data, Type type);

    bool didEnter(_DragAvatar<Object> avatar);

    void didLeave(_DragAvatar<Object> avatar);

    void didDrop(_DragAvatar<Object> avatar);

    void didMove(_DragAvatar<Object> avatar);

    Widget build(BuildContext context);

private:
    List<_DragAvatar<Object>> _candidateAvatars;

    List<_DragAvatar<Object>> _rejectedAvatars;


};

enum _DragEndKind{
    dropped,
    canceled,
} // end _DragEndKind

class _DragAvatar<T extends Object> : Drag {
public:
    T data;

    Axis axis;

    Offset dragStartPoint;

    Widget feedback;

    Offset feedbackOffset;

    DragUpdateCallback onDragUpdate;

    _OnDragEnd onDragEnd;

    OverlayState overlayState;

    bool ignoringFeedbackSemantics;

    bool ignoringFeedbackPointer;


    void update(DragUpdateDetails details);

    void end(DragEndDetails details);

    void cancel();

    void updateDrag(Offset globalPosition);

    void finishDrag(_DragEndKind endKind, Velocity velocity);

private:
    _DragTargetState<Object> _activeTarget;

    List<_DragTargetState<Object>> _enteredTargets;

    Offset _position;

    Offset _lastOffset;

    OverlayEntry _entry;


     _DragAvatar(Axis axis, T data, Offset dragStartPoint, Widget feedback, Offset feedbackOffset, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Offset initialPosition, _OnDragEnd onDragEnd, DragUpdateCallback onDragUpdate, OverlayState overlayState);

    Iterable<_DragTargetState<Object>> _getDragTargets(Iterable<HitTestEntry> path);

    void _leaveAllEntered();

    Widget _build(BuildContext context);

    Velocity _restrictVelocityAxis(Velocity velocity);

    Offset _restrictAxis(Offset offset);

};

#endif