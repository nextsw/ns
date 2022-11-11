#include "drag_target.hpp"
Offset childDragAnchorStrategy(Draggable<Object> draggable, BuildContext context, Offset position) {
    RenderBox renderObject = as<RenderBox>(context->findRenderObject()!);
    return renderObject->globalToLocal(position);
}

Offset pointerDragAnchorStrategy(Draggable<Object> draggable, BuildContext context, Offset position) {
    return OffsetCls::zero;
}

template<typename T>
DraggableCls<T>::DraggableCls(Axis affinity, Axis axis, Widget child, Widget childWhenDragging, T data, DragAnchor dragAnchor, DragAnchorStrategy dragAnchorStrategy, Widget feedback, Offset feedbackOffset, HitTestBehavior hitTestBehavior, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Unknown key, int maxSimultaneousDrags, VoidCallback onDragCompleted, DragEndCallback onDragEnd, VoidCallback onDragStarted, DragUpdateCallback onDragUpdate, DraggableCanceledCallback onDraggableCanceled, bool rootOverlay) {
    {
        assert(child != nullptr);
        assert(feedback != nullptr);
        assert(ignoringFeedbackSemantics != nullptr);
        assert(ignoringFeedbackPointer != nullptr);
        assert(maxSimultaneousDrags == nullptr || maxSimultaneousDrags >= 0);
    }
}

template<typename T>
MultiDragGestureRecognizer DraggableCls<T>::createRecognizer(GestureMultiDragStartCallback onStart) {
    ;
}

template<typename T>
State<Draggable<T>> DraggableCls<T>::createState() {
    return <T>make<_DraggableStateCls>();
}

template<typename T>
DelayedMultiDragGestureRecognizer LongPressDraggableCls<T>::createRecognizer(GestureMultiDragStartCallback onStart) {
        };return     auto _c1 = make<DelayedMultiDragGestureRecognizerCls>(delay);    _c1.onStart = [=] (Offset position) {            Drag result = onStart(position);            }                if (result != nullptr && hapticFeedbackOnStart) {                    HapticFeedbackCls->selectionClick();            return result;_c1;
}

template<typename T>
void _DraggableStateCls<T>::initState() {
    super->initState();
    _recognizer = widget()->createRecognizer(_startDrag);
}

template<typename T>
void _DraggableStateCls<T>::dispose() {
    _disposeRecognizerIfInactive();
    super->dispose();
}

template<typename T>
void _DraggableStateCls<T>::didChangeDependencies() {
    _recognizer!->gestureSettings = MediaQueryCls->maybeOf(context())?->gestureSettings;
    super->didChangeDependencies();
}

template<typename T>
Widget _DraggableStateCls<T>::build(BuildContext context) {
    assert(OverlayCls->of(context, widget(), widget()->rootOverlay) != nullptr);
    bool canDrag = widget()->maxSimultaneousDrags == nullptr ||  < widget()->maxSimultaneousDrags!;
    bool showChild = _activeCount == 0 || widget()->childWhenDragging == nullptr;
    return make<ListenerCls>(widget()->hitTestBehavior, canDrag? _routePointer : nullptr, showChild? widget()->child : widget()->childWhenDragging);
}

template<typename T>
void _DraggableStateCls<T>::_disposeRecognizerIfInactive() {
    if (_activeCount > 0) {
        return;
    }
    _recognizer!->dispose();
    _recognizer = nullptr;
}

template<typename T>
void _DraggableStateCls<T>::_routePointer(PointerDownEvent event) {
    if (widget()->maxSimultaneousDrags != nullptr && _activeCount >= widget()->maxSimultaneousDrags!) {
        return;
    }
    _recognizer!->addPointer(event);
}

template<typename T>
_DragAvatar<T> _DraggableStateCls<T>::_startDrag(Offset position) {
    if (widget()->maxSimultaneousDrags != nullptr && _activeCount >= widget()->maxSimultaneousDrags!) {
        return nullptr;
    }
    Offset dragStartPoint;
    if (widget()->dragAnchorStrategy == nullptr) {
        ;
    } else {
        dragStartPoint = widget()->dragAnchorStrategy!(widget(), context(), position);
    }
    setState([=] () {
        _activeCount += 1;
    });
    _DragAvatar<T> avatar = <T>make<_DragAvatarCls>(OverlayCls->of(context(), widget(), widget()->rootOverlay)!, widget()->data, widget()->axis, position, dragStartPoint, widget()->feedback, widget()->feedbackOffset, widget()->ignoringFeedbackSemantics, widget()->ignoringFeedbackPointer, [=] (DragUpdateDetails details) {
    if (mounted() && widget()->onDragUpdate != nullptr) {
        widget()->onDragUpdate!(details);
    }
}, [=] (Velocity velocity,Offset offset,bool wasAccepted) {
    if (mounted()) {
        setState([=] () {
            _activeCount -= 1;
        });
    } else {
        _activeCount -= 1;
        _disposeRecognizerIfInactive();
    }
    if (mounted() && widget()->onDragEnd != nullptr) {
        widget()->onDragEnd!(make<DraggableDetailsCls>(wasAccepted, velocity, offset));
    }
    if (wasAccepted && widget()->onDragCompleted != nullptr) {
        widget()->onDragCompleted!();
    }
    if (!wasAccepted && widget()->onDraggableCanceled != nullptr) {
        widget()->onDraggableCanceled!(velocity, offset);
    }
});
    widget()->onDragStarted?->call();
    return avatar;
}

DraggableDetailsCls::DraggableDetailsCls(Offset offset, Velocity velocity, bool wasAccepted) {
    {
        assert(velocity != nullptr);
        assert(offset != nullptr);
    }
}

template<typename T>
DragTargetDetailsCls<T>::DragTargetDetailsCls(T data, Offset offset) {
    {
        assert(offset != nullptr);
    }
}

template<typename T>
State<DragTarget<T>> DragTargetCls<T>::createState() {
    return <T>make<_DragTargetStateCls>();
}

template<typename T>
List<T> _mapAvatarsToData(List<_DragAvatar<Object>> avatars) {
    return avatars-><T>map([=] (_DragAvatar<Object> avatar) {
        as<T>(avatar->data);
    })->toList();
}

template<typename T>
bool _DragTargetStateCls<T>::isExpectedDataType(Object data, Type type) {
    if (kIsWeb && ((type == intValue && T == double) || (type == double && T == intValue))) {
        return false;
    }
    return is<T>(data);
}

template<typename T>
bool _DragTargetStateCls<T>::didEnter(_DragAvatar<Object> avatar) {
    assert(!_candidateAvatars->contains(avatar));
    assert(!_rejectedAvatars->contains(avatar));
    if (widget()->onWillAccept == nullptr || widget()->onWillAccept!(as<T>(avatar->data))) {
        setState([=] () {
            _candidateAvatars->add(avatar);
        });
        return true;
    } else {
        setState([=] () {
            _rejectedAvatars->add(avatar);
        });
        return false;
    }
}

template<typename T>
void _DragTargetStateCls<T>::didLeave(_DragAvatar<Object> avatar) {
    assert(_candidateAvatars->contains(avatar) || _rejectedAvatars->contains(avatar));
    if (!mounted()) {
        return;
    }
    setState([=] () {
        _candidateAvatars->remove(avatar);
        _rejectedAvatars->remove(avatar);
    });
    widget()->onLeave?->call(as<T>(avatar->data));
}

template<typename T>
void _DragTargetStateCls<T>::didDrop(_DragAvatar<Object> avatar) {
    assert(_candidateAvatars->contains(avatar));
    if (!mounted()) {
        return;
    }
    setState([=] () {
        _candidateAvatars->remove(avatar);
    });
    widget()->onAccept?->call(as<T>(avatar->data!));
    widget()->onAcceptWithDetails?->call(<T>make<DragTargetDetailsCls>(as<T>(avatar->data!), avatar->_lastOffset!));
}

template<typename T>
void _DragTargetStateCls<T>::didMove(_DragAvatar<Object> avatar) {
    if (!mounted()) {
        return;
    }
    widget()->onMove?->call(<T>make<DragTargetDetailsCls>(as<T>(avatar->data!), avatar->_lastOffset!));
}

template<typename T>
Widget _DragTargetStateCls<T>::build(BuildContext context) {
    assert(widget()->builder != nullptr);
    return make<MetaDataCls>(this, widget()->hitTestBehavior, widget()->builder(context, <T>_mapAvatarsToData(_candidateAvatars), <Object>_mapAvatarsToData(_rejectedAvatars)));
}

template<typename T>
void _DragAvatarCls<T>::update(DragUpdateDetails details) {
    Offset oldPosition = _position;
    _position += _restrictAxis(details->delta);
    updateDrag(_position);
    if (onDragUpdate != nullptr && _position != oldPosition) {
        onDragUpdate!(details);
    }
}

template<typename T>
void _DragAvatarCls<T>::end(DragEndDetails details) {
    finishDrag(_DragEndKindCls::dropped, _restrictVelocityAxis(details->velocity));
}

template<typename T>
void _DragAvatarCls<T>::cancel() {
    finishDrag(_DragEndKindCls::canceled);
}

template<typename T>
void _DragAvatarCls<T>::updateDrag(Offset globalPosition) {
    _lastOffset = globalPosition - dragStartPoint;
    _entry!->markNeedsBuild();
    HitTestResult result = make<HitTestResultCls>();
    WidgetsBindingCls::instance->hitTest(result, globalPosition + feedbackOffset);
    List<_DragTargetState<Object>> targets = _getDragTargets(result->path())->toList();
    bool listsMatch = false;
    if (targets->length() >= _enteredTargets->length() && _enteredTargets->isNotEmpty()) {
        listsMatch = true;
        Iterator<_DragTargetState<Object>> iterator = targets->iterator();
        for (;  < _enteredTargets->length(); i += 1) {
            iterator->moveNext();
            if (iterator->current() != _enteredTargets[i]) {
                listsMatch = false;
                break;
            }
        }
    }
    if (listsMatch) {
        for (_DragTargetState<Object> target : _enteredTargets) {
            target->didMove(this);
        }
        return;
    }
    _leaveAllEntered();
    _DragTargetState<Object> newTarget = targets-><_DragTargetState<Object>>cast()->firstWhere([=] (_DragTargetState<Object> target) {
    if (target == nullptr) {
        return false;
    }
    _enteredTargets->add(target);
    return target->didEnter(this);
}, [=] () {
    nullptr;
});
    for (_DragTargetState<Object> target : _enteredTargets) {
        target->didMove(this);
    }
    _activeTarget = newTarget;
}

template<typename T>
void _DragAvatarCls<T>::finishDrag(_DragEndKind endKind, Velocity velocity) {
    bool wasAccepted = false;
    if (endKind == _DragEndKindCls::dropped && _activeTarget != nullptr) {
        _activeTarget!->didDrop(this);
        wasAccepted = true;
        _enteredTargets->remove(_activeTarget);
    }
    _leaveAllEntered();
    _activeTarget = nullptr;
    _entry!->remove();
    _entry = nullptr;
    onDragEnd?->call(velocity | VelocityCls::zero, _lastOffset!, wasAccepted);
}

template<typename T>
_DragAvatarCls<T>::_DragAvatarCls(Axis axis, T data, Offset dragStartPoint, Widget feedback, Offset feedbackOffset, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Offset initialPosition, _OnDragEnd onDragEnd, DragUpdateCallback onDragUpdate, OverlayState overlayState) {
    {
        assert(overlayState != nullptr);
        assert(ignoringFeedbackSemantics != nullptr);
        assert(ignoringFeedbackPointer != nullptr);
        assert(dragStartPoint != nullptr);
        assert(feedbackOffset != nullptr);
        _position = initialPosition;
    }
    {
        _entry = make<OverlayEntryCls>(_build);
        overlayState->insert(_entry!);
        updateDrag(initialPosition);
    }
}

template<typename T>
Iterable<_DragTargetState<Object>> _DragAvatarCls<T>::_getDragTargets(Iterable<HitTestEntry> path) {
    List<_DragTargetState<Object>> targets = makeList();
    for (HitTestEntry entry : path) {
        HitTestTarget target = entry->target;
        if (is<RenderMetaData>(target)) {
            dynamic metaData = as<RenderMetaDataCls>(target)->metaData;
            if (is<_DragTargetState>(metaData) && metaData->isExpectedDataType(data, T)) {
                targets->add(metaData);
            }
        }
    }
    return targets;
}

template<typename T>
void _DragAvatarCls<T>::_leaveAllEntered() {
    for (;  < _enteredTargets->length(); i += 1) {
        _enteredTargets[i]->didLeave(this);
    }
    _enteredTargets->clear();
}

template<typename T>
Widget _DragAvatarCls<T>::_build(BuildContext context) {
    RenderBox box = as<RenderBox>(overlayState->context->findRenderObject()!);
    Offset overlayTopLeft = box->localToGlobal(OffsetCls::zero);
    return make<PositionedCls>(_lastOffset!->dx() - overlayTopLeft->dx(), _lastOffset!->dy() - overlayTopLeft->dy(), make<IgnorePointerCls>(ignoringFeedbackPointer, ignoringFeedbackSemantics, feedback));
}

template<typename T>
Velocity _DragAvatarCls<T>::_restrictVelocityAxis(Velocity velocity) {
    if (axis == nullptr) {
        return velocity;
    }
    return make<VelocityCls>(_restrictAxis(velocity->pixelsPerSecond));
}

template<typename T>
Offset _DragAvatarCls<T>::_restrictAxis(Offset offset) {
    if (axis == nullptr) {
        return offset;
    }
    if (axis == AxisCls::horizontal) {
        return make<OffsetCls>(offset->dx(), 0.0);
    }
    return make<OffsetCls>(0.0, offset->dy());
}
