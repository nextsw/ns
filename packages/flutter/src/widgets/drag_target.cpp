#include "drag_target.hpp"
Offset childDragAnchorStrategy(BuildContext context, Draggable<Object> draggable, Offset position) {
    RenderBox renderObject = (;
    return renderObject.globalToLocal(position);
}

Offset pointerDragAnchorStrategy(BuildContext context, Draggable<Object> draggable, Offset position) {
    return Offset.zero;
}

Draggable::Draggable(Axis affinity, Axis axis, Widget child, Widget childWhenDragging, T data, DragAnchor dragAnchor, DragAnchorStrategy dragAnchorStrategy, Widget feedback, Offset feedbackOffset, HitTestBehavior hitTestBehavior, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Unknown, int maxSimultaneousDrags, VoidCallback onDragCompleted, DragEndCallback onDragEnd, VoidCallback onDragStarted, DragUpdateCallback onDragUpdate, DraggableCanceledCallback onDraggableCanceled, bool rootOverlay) {
    {
        assert(child != nullptr);
        assert(feedback != nullptr);
        assert(ignoringFeedbackSemantics != nullptr);
        assert(ignoringFeedbackPointer != nullptr);
        assert(maxSimultaneousDrags == nullptr || maxSimultaneousDrags >= 0);
    }
}

MultiDragGestureRecognizer Draggable::createRecognizer(GestureMultiDragStartCallback onStart) {
    ;
}

State<Draggable<T>> Draggable::createState() {
    return <T>_DraggableState();
}

DelayedMultiDragGestureRecognizer LongPressDraggable::createRecognizer(GestureMultiDragStartCallback onStart) {
    return ;
}

void _DraggableState::initState() {
    super.initState();
    _recognizer = widget.createRecognizer(_startDrag);
}

void _DraggableState::dispose() {
    _disposeRecognizerIfInactive();
    super.dispose();
}

void _DraggableState::didChangeDependencies() {
    _recognizer!.gestureSettings = MediaQuery.maybeOf(context)?.gestureSettings;
    super.didChangeDependencies();
}

Widget _DraggableState::build(BuildContext context) {
    assert(Overlay.of(contextwidget, widget.rootOverlay) != nullptr);
    bool canDrag = widget.maxSimultaneousDrags == nullptr ||  < widget.maxSimultaneousDrags!;
    bool showChild = _activeCount == 0 || widget.childWhenDragging == nullptr;
    return Listener(widget.hitTestBehavior, canDrag? _routePointer : nullptr, showChild? widget.child : widget.childWhenDragging);
}

void _DraggableState::_disposeRecognizerIfInactive() {
    if (_activeCount > 0) {
        return;
    }
    _recognizer!.dispose();
    _recognizer = nullptr;
}

void _DraggableState::_routePointer(PointerDownEvent event) {
    if (widget.maxSimultaneousDrags != nullptr && _activeCount >= widget.maxSimultaneousDrags!) {
        return;
    }
    _recognizer!.addPointer(event);
}

_DragAvatar<T> _DraggableState::_startDrag(Offset position) {
    if (widget.maxSimultaneousDrags != nullptr && _activeCount >= widget.maxSimultaneousDrags!) {
        return nullptr;
    }
    Offset dragStartPoint;
    if (widget.dragAnchorStrategy == nullptr) {
        ;
    } else {
        dragStartPoint = widget.dragAnchorStrategy!(widget, context, position);
    }
    setState();
    _DragAvatar<T> avatar = <T>_DragAvatar(Overlay.of(contextwidget, widget.rootOverlay)!, widget.data, widget.axis, position, dragStartPoint, widget.feedback, widget.feedbackOffset, widget.ignoringFeedbackSemantics, widget.ignoringFeedbackPointer, , );
    widget.onDragStarted?.call();
    return avatar;
}

DraggableDetails::DraggableDetails(Offset offset, Velocity velocity, bool wasAccepted) {
    {
        assert(velocity != nullptr);
        assert(offset != nullptr);
    }
}

DragTargetDetails::DragTargetDetails(T data, Offset offset) {
    {
        assert(offset != nullptr);
    }
}

State<DragTarget<T>> DragTarget::createState() {
    return <T>_DragTargetState();
}

List<T> _mapAvatarsToData<T extends Object>(List<_DragAvatar<Object>> avatars) {
    return avatars.<T>map().toList();
}

bool _DragTargetState::isExpectedDataType(Object data, Type type) {
    if (kIsWeb && ((type == int && T == double) || (type == double && T == int))) {
        return false;
    }
    return data is T;
}

bool _DragTargetState::didEnter(_DragAvatar<Object> avatar) {
    assert(!_candidateAvatars.contains(avatar));
    assert(!_rejectedAvatars.contains(avatar));
    if (widget.onWillAccept == nullptr || widget.onWillAccept!(()) {
        setState();
        return true;
    } else {
        setState();
        return false;
    }
}

void _DragTargetState::didLeave(_DragAvatar<Object> avatar) {
    assert(_candidateAvatars.contains(avatar) || _rejectedAvatars.contains(avatar));
    if (!mounted) {
        return;
    }
    setState();
    widget.onLeave?.call(();
}

void _DragTargetState::didDrop(_DragAvatar<Object> avatar) {
    assert(_candidateAvatars.contains(avatar));
    if (!mounted) {
        return;
    }
    setState();
    widget.onAccept?.call(();
    widget.onAcceptWithDetails?.call(<T>DragTargetDetails((, avatar._lastOffset!));
}

void _DragTargetState::didMove(_DragAvatar<Object> avatar) {
    if (!mounted) {
        return;
    }
    widget.onMove?.call(<T>DragTargetDetails((, avatar._lastOffset!));
}

Widget _DragTargetState::build(BuildContext context) {
    assert(widget.builder != nullptr);
    return MetaData(this, widget.hitTestBehavior, widget.builder(context, <T>_mapAvatarsToData(_candidateAvatars), <Object>_mapAvatarsToData(_rejectedAvatars)));
}

void _DragAvatar::update(DragUpdateDetails details) {
    Offset oldPosition = _position;
    _position = _restrictAxis(details.delta);
    updateDrag(_position);
    if (onDragUpdate != nullptr && _position != oldPosition) {
        onDragUpdate!(details);
    }
}

void _DragAvatar::end(DragEndDetails details) {
    finishDrag(_DragEndKind.dropped, _restrictVelocityAxis(details.velocity));
}

void _DragAvatar::cancel() {
    finishDrag(_DragEndKind.canceled);
}

void _DragAvatar::updateDrag(Offset globalPosition) {
    _lastOffset = globalPosition - dragStartPoint;
    _entry!.markNeedsBuild();
    HitTestResult result = HitTestResult();
    WidgetsBinding.instance.hitTest(result, globalPosition + feedbackOffset);
    List<_DragTargetState<Object>> targets = _getDragTargets(result.path).toList();
    bool listsMatch = false;
    if (targets.length >= _enteredTargets.length && _enteredTargets.isNotEmpty) {
        listsMatch = true;
        Iterator<_DragTargetState<Object>> iterator = targets.iterator;
        for (;  < _enteredTargets.length; i = 1) {
            iterator.moveNext();
            if (iterator.current != _enteredTargets[i]) {
                listsMatch = false;
                                break;
            }
        }
    }
    if (listsMatch) {
        for (_DragTargetState<Object> target : _enteredTargets) {
            target.didMove(this);
        }
        return;
    }
    _leaveAllEntered();
    _DragTargetState<Object> newTarget = targets.<_DragTargetState<Object>>cast().firstWhere();
    for (_DragTargetState<Object> target : _enteredTargets) {
        target.didMove(this);
    }
    _activeTarget = newTarget;
}

void _DragAvatar::finishDrag(_DragEndKind endKind, Velocity velocity) {
    bool wasAccepted = false;
    if (endKind == _DragEndKind.dropped && _activeTarget != nullptr) {
        _activeTarget!.didDrop(this);
        wasAccepted = true;
        _enteredTargets.remove(_activeTarget);
    }
    _leaveAllEntered();
    _activeTarget = nullptr;
    _entry!.remove();
    _entry = nullptr;
    onDragEnd?.call(velocity ?? Velocity.zero, _lastOffset!, wasAccepted);
}

_DragAvatar::_DragAvatar(Axis axis, T data, Offset dragStartPoint, Widget feedback, Offset feedbackOffset, bool ignoringFeedbackPointer, bool ignoringFeedbackSemantics, Offset initialPosition, _OnDragEnd onDragEnd, DragUpdateCallback onDragUpdate, OverlayState overlayState) {
    {
        assert(overlayState != nullptr);
        assert(ignoringFeedbackSemantics != nullptr);
        assert(ignoringFeedbackPointer != nullptr);
        assert(dragStartPoint != nullptr);
        assert(feedbackOffset != nullptr);
        _position = initialPosition;
    }
    {
        _entry = OverlayEntry(_build);
        overlayState.insert(_entry!);
        updateDrag(initialPosition);
    }
}

Iterable<_DragTargetState<Object>> _DragAvatar::_getDragTargets(Iterable<HitTestEntry> path) {
    List<_DragTargetState<Object>> targets = ;
    for (HitTestEntry entry : path) {
        HitTestTarget target = entry.target;
        if (target is RenderMetaData) {
            dynamic metaData = target.metaData;
            if (metaData is _DragTargetState && metaData.isExpectedDataType(data, T)) {
                targets.add(metaData);
            }
        }
    }
    return targets;
}

void _DragAvatar::_leaveAllEntered() {
    for (;  < _enteredTargets.length; i = 1) {
        _enteredTargets[i].didLeave(this);
    }
    _enteredTargets.clear();
}

Widget _DragAvatar::_build(BuildContext context) {
    RenderBox box = (;
    Offset overlayTopLeft = box.localToGlobal(Offset.zero);
    return Positioned(_lastOffset!.dx - overlayTopLeft.dx, _lastOffset!.dy - overlayTopLeft.dy, IgnorePointer(ignoringFeedbackPointer, ignoringFeedbackSemantics, feedback));
}

Velocity _DragAvatar::_restrictVelocityAxis(Velocity velocity) {
    if (axis == nullptr) {
        return velocity;
    }
    return Velocity(_restrictAxis(velocity.pixelsPerSecond));
}

Offset _DragAvatar::_restrictAxis(Offset offset) {
    if (axis == nullptr) {
        return offset;
    }
    if (axis == Axis.horizontal) {
        return Offset(offset.dx, 0.0);
    }
    return Offset(0.0, offset.dy);
}
