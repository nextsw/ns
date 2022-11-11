#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DRAG_TARGET
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DRAG_TARGET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "overlay.hpp"

Offset childDragAnchorStrategy(Draggable<Object> draggable, BuildContext context, Offset position);

Offset pointerDragAnchorStrategy(Draggable<Object> draggable, BuildContext context, Offset position);


enum DragAnchor{
    child,
    pointer,
} // end DragAnchor

template<typename T>
class DraggableCls : public StatefulWidgetCls {
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


     DraggableCls(Axis affinity, Axis axis, Widget child, Widget childWhenDragging, T data, DragAnchor dragAnchor, DragAnchorStrategy dragAnchorStrategy, Widget feedback, Offset feedbackOffset, HitTestBehavior hitTestBehavior, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Key key, int maxSimultaneousDrags, VoidCallback onDragCompleted, DragEndCallback onDragEnd, VoidCallback onDragStarted, DragUpdateCallback onDragUpdate, DraggableCanceledCallback onDraggableCanceled, bool rootOverlay);

    virtual MultiDragGestureRecognizer createRecognizer(GestureMultiDragStartCallback onStart);

    virtual State<Draggable<T>> createState();

private:

};
template<typename T>
using Draggable = std::shared_ptr<DraggableCls<T>>;

template<typename T>
class LongPressDraggableCls : public DraggableCls<T> {
public:
    bool hapticFeedbackOnStart;

    Duration delay;


     LongPressDraggableCls(Axis axis, Widget child, Widget childWhenDragging, T data, Duration delay, DragAnchor dragAnchor, DragAnchorStrategy dragAnchorStrategy, Widget feedback, Offset feedbackOffset, bool hapticFeedbackOnStart, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Key key, int maxSimultaneousDrags, VoidCallback onDragCompleted, DragEndCallback onDragEnd, VoidCallback onDragStarted, DragUpdateCallback onDragUpdate, DraggableCanceledCallback onDraggableCanceled);
    virtual DelayedMultiDragGestureRecognizer createRecognizer(GestureMultiDragStartCallback onStart);

private:

};
template<typename T>
using LongPressDraggable = std::shared_ptr<LongPressDraggableCls<T>>;

template<typename T>
class _DraggableStateCls : public StateCls<Draggable<T>> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void didChangeDependencies();

    virtual Widget build(BuildContext context);

private:
    GestureRecognizer _recognizer;

    int _activeCount;


    virtual void _disposeRecognizerIfInactive();

    virtual void _routePointer(PointerDownEvent event);

    virtual _DragAvatar<T> _startDrag(Offset position);

};
template<typename T>
using _DraggableState = std::shared_ptr<_DraggableStateCls<T>>;

class DraggableDetailsCls : public ObjectCls {
public:
    bool wasAccepted;

    Velocity velocity;

    Offset offset;


     DraggableDetailsCls(Offset offset, Velocity velocity, bool wasAccepted);

private:

};
using DraggableDetails = std::shared_ptr<DraggableDetailsCls>;

template<typename T>
class DragTargetDetailsCls : public ObjectCls {
public:
    T data;

    Offset offset;


     DragTargetDetailsCls(T data, Offset offset);

private:

};
template<typename T>
using DragTargetDetails = std::shared_ptr<DragTargetDetailsCls<T>>;

template<typename T>
class DragTargetCls : public StatefulWidgetCls {
public:
    DragTargetBuilder<T> builder;

    DragTargetWillAccept<T> onWillAccept;

    DragTargetAccept<T> onAccept;

    DragTargetAcceptWithDetails<T> onAcceptWithDetails;

    DragTargetLeave<T> onLeave;

    DragTargetMove<T> onMove;

    HitTestBehavior hitTestBehavior;


     DragTargetCls(DragTargetBuilder<T> builder, HitTestBehavior hitTestBehavior, Key key, DragTargetAccept<T> onAccept, DragTargetAcceptWithDetails<T> onAcceptWithDetails, DragTargetLeave<T> onLeave, DragTargetMove<T> onMove, DragTargetWillAccept<T> onWillAccept);
    virtual State<DragTarget<T>> createState();

private:

};
template<typename T>
using DragTarget = std::shared_ptr<DragTargetCls<T>>;
template<typename T>
 List<T> _mapAvatarsToData(List<_DragAvatar<Object>> avatars);


template<typename T>
class _DragTargetStateCls : public StateCls<DragTarget<T>> {
public:

    virtual bool isExpectedDataType(Object data, Type type);

    virtual bool didEnter(_DragAvatar<Object> avatar);

    virtual void didLeave(_DragAvatar<Object> avatar);

    virtual void didDrop(_DragAvatar<Object> avatar);

    virtual void didMove(_DragAvatar<Object> avatar);

    virtual Widget build(BuildContext context);

private:
    List<_DragAvatar<Object>> _candidateAvatars;

    List<_DragAvatar<Object>> _rejectedAvatars;


};
template<typename T>
using _DragTargetState = std::shared_ptr<_DragTargetStateCls<T>>;

enum _DragEndKind{
    dropped,
    canceled,
} // end _DragEndKind

template<typename T>
class _DragAvatarCls : public DragCls {
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


    virtual void update(DragUpdateDetails details);

    virtual void end(DragEndDetails details);

    virtual void cancel();

    virtual void updateDrag(Offset globalPosition);

    virtual void finishDrag(_DragEndKind endKind, Velocity velocity);

private:
    _DragTargetState<Object> _activeTarget;

    List<_DragTargetState<Object>> _enteredTargets;

    Offset _position;

    Offset _lastOffset;

    OverlayEntry _entry;


     _DragAvatarCls(Axis axis, T data, Offset dragStartPoint, Widget feedback, Offset feedbackOffset, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Offset initialPosition, _OnDragEnd onDragEnd, DragUpdateCallback onDragUpdate, OverlayState overlayState);

    virtual Iterable<_DragTargetState<Object>> _getDragTargets(Iterable<HitTestEntry<any>> path);

    virtual void _leaveAllEntered();

    virtual Widget _build(BuildContext context);

    virtual Velocity _restrictVelocityAxis(Velocity velocity);

    virtual Offset _restrictAxis(Offset offset);

};
template<typename T>
using _DragAvatar = std::shared_ptr<_DragAvatarCls<T>>;


#endif