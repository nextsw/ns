#include "dismissible.hpp"
Dismissible::Dismissible(Widget background, HitTestBehavior behavior, Widget child, ConfirmDismissCallback confirmDismiss, double crossAxisEndOffset, DismissDirection direction, Map<DismissDirection, double> dismissThresholds, DragStartBehavior dragStartBehavior, Key key, Duration movementDuration, DismissDirectionCallback onDismissed, VoidCallback onResize, DismissUpdateCallback onUpdate, Duration resizeDuration, Widget secondaryBackground) {
    {
        assert(key != nullptr);
        assert(secondaryBackground == nullptr || background != nullptr);
        assert(dragStartBehavior != nullptr);
        super(key);
    }
}

State<Dismissible> Dismissible::createState() {
    return _DismissibleState();
}

Rect _DismissibleClipper::getClip(Size size) {
    assert(axis != nullptr);
    ;
}

Rect _DismissibleClipper::getApproximateClipRect(Size size) {
    return getClip(size);
}

bool _DismissibleClipper::shouldReclip(_DismissibleClipper oldClipper) {
    return oldClipper.axis != axis || oldClipper.moveAnimation.value != moveAnimation.value;
}

_DismissibleClipper::_DismissibleClipper(Axis axis, Animation<Offset> moveAnimation) {
    {
        assert(axis != nullptr);
        assert(moveAnimation != nullptr);
        super(moveAnimation);
    }
}

void _DismissibleState::initState() {
    super.initState();
    _moveController = ;
    _updateMoveAnimation();
}

bool _DismissibleState::wantKeepAlive() {
    return (_moveController?.isAnimating ?? false) || (_resizeController?.isAnimating ?? false);
}

void _DismissibleState::dispose() {
    _moveController!.dispose();
    _resizeController?.dispose();
    super.dispose();
}

Widget _DismissibleState::build(BuildContext context) {
    super.build(context);
    assert(!_directionIsXAxis || debugCheckHasDirectionality(context));
    Widget background = widget.background;
    if (widget.secondaryBackground != nullptr) {
        DismissDirection direction = _dismissDirection;
        if (direction == DismissDirection.endToStart || direction == DismissDirection.up) {
            background = widget.secondaryBackground;
        }
    }
    if (_resizeAnimation != nullptr) {
        assert(());
        return SizeTransition(_resizeAnimation!, _directionIsXAxis? Axis.vertical : Axis.horizontal, SizedBox(_sizePriorToCollapse!.width, _sizePriorToCollapse!.height, background));
    }
    Widget content = SlideTransition(_moveAnimation, widget.child);
    if (background != nullptr) {
        content = Stack();
    }
    if (widget.direction == DismissDirection.none) {
        return content;
    }
    return GestureDetector(_directionIsXAxis? _handleDragStart : nullptr, _directionIsXAxis? _handleDragUpdate : nullptr, _directionIsXAxis? _handleDragEnd : nullptr, _directionIsXAxis? nullptr : _handleDragStart, _directionIsXAxis? nullptr : _handleDragUpdate, _directionIsXAxis? nullptr : _handleDragEnd, widget.behavior, widget.dragStartBehavior, content);
}

bool _DismissibleState::_directionIsXAxis() {
    return widget.direction == DismissDirection.horizontal || widget.direction == DismissDirection.endToStart || widget.direction == DismissDirection.startToEnd;
}

DismissDirection _DismissibleState::_extentToDirection(double extent) {
    if (extent == 0.0) {
        return DismissDirection.none;
    }
    if (_directionIsXAxis) {
        ;
    }
    return extent > 0? DismissDirection.down : DismissDirection.up;
}

DismissDirection _DismissibleState::_dismissDirection() {
    return _extentToDirection(_dragExtent);
}

bool _DismissibleState::_isActive() {
    return _dragUnderway || _moveController!.isAnimating;
}

double _DismissibleState::_overallDragAxisExtent() {
    Size size = context.size!;
    return _directionIsXAxis? size.width : size.height;
}

void _DismissibleState::_handleDragStart(DragStartDetails details) {
    if (_confirming) {
        return;
    }
    _dragUnderway = true;
    if (_moveController!.isAnimating) {
        _dragExtent = _moveController!.value * _overallDragAxisExtent * _dragExtent.sign;
        _moveController!.stop();
    } else {
        _dragExtent = 0.0;
        _moveController!.value = 0.0;
    }
    setState();
}

void _DismissibleState::_handleDragUpdate(DragUpdateDetails details) {
    if (!_isActive || _moveController!.isAnimating) {
        return;
    }
    double delta = details.primaryDelta!;
    double oldDragExtent = _dragExtent;
    ;
    if (oldDragExtent.sign != _dragExtent.sign) {
        setState();
    }
    if (!_moveController!.isAnimating) {
        _moveController!.value = _dragExtent.abs() / _overallDragAxisExtent;
    }
}

void _DismissibleState::_handleDismissUpdateValueChanged() {
    if (widget.onUpdate != nullptr) {
        bool oldDismissThresholdReached = _dismissThresholdReached;
        _dismissThresholdReached = _moveController!.value > (widget.dismissThresholds[_dismissDirection] ?? _kDismissThreshold);
        DismissUpdateDetails details = DismissUpdateDetails(_dismissDirection, _dismissThresholdReached, oldDismissThresholdReached, _moveController!.value);
        widget.onUpdate!(details);
    }
}

void _DismissibleState::_updateMoveAnimation() {
    double end = _dragExtent.sign;
    _moveAnimation = _moveController!.drive(<Offset>Tween(Offset.zero, _directionIsXAxis? Offset(end, widget.crossAxisEndOffset) : Offset(widget.crossAxisEndOffset, end)));
}

_FlingGestureKind _DismissibleState::_describeFlingGesture(Velocity velocity) {
    assert(widget.direction != nullptr);
    if (_dragExtent == 0.0) {
        return _FlingGestureKind.none;
    }
    double vx = velocity.pixelsPerSecond.dx;
    double vy = velocity.pixelsPerSecond.dy;
    DismissDirection flingDirection;
    if (_directionIsXAxis) {
        if (vx.abs() - vy.abs() < _kMinFlingVelocityDelta || vx.abs() < _kMinFlingVelocity) {
            return _FlingGestureKind.none;
        }
        assert(vx != 0.0);
        flingDirection = _extentToDirection(vx);
    } else {
        if (vy.abs() - vx.abs() < _kMinFlingVelocityDelta || vy.abs() < _kMinFlingVelocity) {
            return _FlingGestureKind.none;
        }
        assert(vy != 0.0);
        flingDirection = _extentToDirection(vy);
    }
    assert(_dismissDirection != nullptr);
    if (flingDirection == _dismissDirection) {
        return _FlingGestureKind.forward;
    }
    return _FlingGestureKind.reverse;
}

void _DismissibleState::_handleDragEnd(DragEndDetails details) {
    if (!_isActive || _moveController!.isAnimating) {
        return;
    }
    _dragUnderway = false;
    if (_moveController!.isCompleted) {
        _handleMoveCompleted();
        return;
    }
    double flingVelocity = _directionIsXAxis? details.velocity.pixelsPerSecond.dx : details.velocity.pixelsPerSecond.dy;
    ;
}

Future<void> _DismissibleState::_handleDismissStatusChanged(AnimationStatus status) {
    if (status == AnimationStatus.completed && !_dragUnderway) {
        await await _handleMoveCompleted();
    }
    if (mounted) {
        updateKeepAlive();
    }
}

Future<void> _DismissibleState::_handleMoveCompleted() {
    if ((widget.dismissThresholds[_dismissDirection] ?? _kDismissThreshold) >= 1.0) {
        _moveController!.reverse();
        return;
    }
    bool result = await _confirmStartResizeAnimation();
    if (mounted) {
        if (result) {
            _startResizeAnimation();
        } else {
            _moveController!.reverse();
        }
    }
}

Future<bool> _DismissibleState::_confirmStartResizeAnimation() {
    if (widget.confirmDismiss != nullptr) {
        _confirming = true;
        DismissDirection direction = _dismissDirection;
        ;
    }
    return true;
}

void _DismissibleState::_startResizeAnimation() {
    assert(_moveController!.isCompleted);
    assert(_resizeController == nullptr);
    assert(_sizePriorToCollapse == nullptr);
    if (widget.resizeDuration == nullptr) {
        if (widget.onDismissed != nullptr) {
            DismissDirection direction = _dismissDirection;
            widget.onDismissed!(direction);
        }
    } else {
        _resizeController = ;
        _resizeController!.forward();
        setState();
    }
}

void _DismissibleState::_handleResizeProgressChanged() {
    if (_resizeController!.isCompleted) {
        widget.onDismissed?.call(_dismissDirection);
    } else {
        widget.onResize?.call();
    }
}
