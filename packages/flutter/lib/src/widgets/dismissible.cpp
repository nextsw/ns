#include "dismissible.hpp"
DismissibleCls::DismissibleCls(Widget background, HitTestBehavior behavior, Widget child, ConfirmDismissCallback confirmDismiss, double crossAxisEndOffset, DismissDirection direction, Map<DismissDirection, double> dismissThresholds, DragStartBehavior dragStartBehavior, Key key, Duration movementDuration, DismissDirectionCallback onDismissed, VoidCallback onResize, DismissUpdateCallback onUpdate, Duration resizeDuration, Widget secondaryBackground) : StatefulWidget(key) {
    {
        assert(key != nullptr);
        assert(secondaryBackground == nullptr || background != nullptr);
        assert(dragStartBehavior != nullptr);
    }
}

State<Dismissible> DismissibleCls::createState() {
    return make<_DismissibleStateCls>();
}

Rect _DismissibleClipperCls::getClip(Size size) {
    assert(axis != nullptr);
    ;
}

Rect _DismissibleClipperCls::getApproximateClipRect(Size size) {
    return getClip(size);
}

bool _DismissibleClipperCls::shouldReclip(_DismissibleClipper oldClipper) {
    return oldClipper->axis != axis || oldClipper->moveAnimation->value() != moveAnimation->value();
}

_DismissibleClipperCls::_DismissibleClipperCls(Axis axis, Animation<Offset> moveAnimation) : CustomClipper<Rect>(moveAnimation) {
    {
        assert(axis != nullptr);
        assert(moveAnimation != nullptr);
    }
}

void _DismissibleStateCls::initState() {
    super->initState();
    auto _c1 = make<AnimationControllerCls>(widget()->movementDuration, this);_c1.auto _c2 = addStatusListener(_handleDismissStatusChanged);_c2.addListener(_handleDismissUpdateValueChanged);_c2;_moveController = _c1;
    _updateMoveAnimation();
}

bool _DismissibleStateCls::wantKeepAlive() {
    return (_moveController?->isAnimating() | false) || (_resizeController?->isAnimating() | false);
}

void _DismissibleStateCls::dispose() {
    _moveController!->dispose();
    _resizeController?->dispose();
    super->dispose();
}

Widget _DismissibleStateCls::build(BuildContext context) {
    super->build(context);
    assert(!_directionIsXAxis() || debugCheckHasDirectionality(context));
    Widget background = widget()->background;
    if (widget()->secondaryBackground != nullptr) {
        DismissDirection direction = _dismissDirection();
        if (direction == DismissDirectionCls::endToStart || direction == DismissDirectionCls::up) {
            background = widget()->secondaryBackground;
        }
    }
    if (_resizeAnimation != nullptr) {
        assert([=] () {
            if (_resizeAnimation!->status() != AnimationStatusCls::forward) {
                assert(_resizeAnimation!->status() == AnimationStatusCls::completed);
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
            }
            return true;
        }());
        return make<SizeTransitionCls>(_resizeAnimation!, _directionIsXAxis()? AxisCls::vertical : AxisCls::horizontal, make<SizedBoxCls>(_sizePriorToCollapse!->width(), _sizePriorToCollapse!->height(), background));
    }
    Widget content = make<SlideTransitionCls>(_moveAnimation, widget()->child);
    if (background != nullptr) {
            List<Widget> list1 = make<ListCls<>>();    if (!_moveAnimation->isDismissed()) {        list1.add(ArrayItem);    }list1.add(ArrayItem);content = make<StackCls>(list1);
    }
    if (widget()->direction == DismissDirectionCls::none) {
        return content;
    }
    return make<GestureDetectorCls>(_directionIsXAxis()? _handleDragStart : nullptr, _directionIsXAxis()? _handleDragUpdate : nullptr, _directionIsXAxis()? _handleDragEnd : nullptr, _directionIsXAxis()? nullptr : _handleDragStart, _directionIsXAxis()? nullptr : _handleDragUpdate, _directionIsXAxis()? nullptr : _handleDragEnd, widget()->behavior, widget()->dragStartBehavior, content);
}

bool _DismissibleStateCls::_directionIsXAxis() {
    return widget()->direction == DismissDirectionCls::horizontal || widget()->direction == DismissDirectionCls::endToStart || widget()->direction == DismissDirectionCls::startToEnd;
}

DismissDirection _DismissibleStateCls::_extentToDirection(double extent) {
    if (extent == 0.0) {
        return DismissDirectionCls::none;
    }
    if (_directionIsXAxis()) {
        ;
    }
    return extent > 0? DismissDirectionCls::down : DismissDirectionCls::up;
}

DismissDirection _DismissibleStateCls::_dismissDirection() {
    return _extentToDirection(_dragExtent);
}

bool _DismissibleStateCls::_isActive() {
    return _dragUnderway || _moveController!->isAnimating();
}

double _DismissibleStateCls::_overallDragAxisExtent() {
    Size size = context()->size()!;
    return _directionIsXAxis()? size->width() : size->height();
}

void _DismissibleStateCls::_handleDragStart(DragStartDetails details) {
    if (_confirming) {
        return;
    }
    _dragUnderway = true;
    if (_moveController!->isAnimating()) {
        _dragExtent = _moveController!->value() * _overallDragAxisExtent() * _dragExtent->sign();
        _moveController!->stop();
    } else {
        _dragExtent = 0.0;
        _moveController!->value() = 0.0;
    }
    setState([=] () {
        _updateMoveAnimation();
    });
}

void _DismissibleStateCls::_handleDragUpdate(DragUpdateDetails details) {
    if (!_isActive() || _moveController!->isAnimating()) {
        return;
    }
    double delta = details->primaryDelta!;
    double oldDragExtent = _dragExtent;
    ;
    if (oldDragExtent->sign() != _dragExtent->sign()) {
        setState([=] () {
            _updateMoveAnimation();
        });
    }
    if (!_moveController!->isAnimating()) {
        _moveController!->value() = _dragExtent->abs() / _overallDragAxisExtent();
    }
}

void _DismissibleStateCls::_handleDismissUpdateValueChanged() {
    if (widget()->onUpdate != nullptr) {
        bool oldDismissThresholdReached = _dismissThresholdReached;
        _dismissThresholdReached = _moveController!->value() > (widget()->dismissThresholds[_dismissDirection()] | _kDismissThreshold);
        DismissUpdateDetails details = make<DismissUpdateDetailsCls>(_dismissDirection(), _dismissThresholdReached, oldDismissThresholdReached, _moveController!->value());
        widget()->onUpdate!(details);
    }
}

void _DismissibleStateCls::_updateMoveAnimation() {
    double end = _dragExtent->sign();
    _moveAnimation = _moveController!->drive(<Offset>make<TweenCls>(OffsetCls::zero, _directionIsXAxis()? make<OffsetCls>(end, widget()->crossAxisEndOffset) : make<OffsetCls>(widget()->crossAxisEndOffset, end)));
}

_FlingGestureKind _DismissibleStateCls::_describeFlingGesture(Velocity velocity) {
    assert(widget()->direction != nullptr);
    if (_dragExtent == 0.0) {
        return _FlingGestureKindCls::none;
    }
    double vx = velocity->pixelsPerSecond->dx();
    double vy = velocity->pixelsPerSecond->dy();
    DismissDirection flingDirection;
    if (_directionIsXAxis()) {
        if (vx->abs() - vy->abs() < _kMinFlingVelocityDelta || vx->abs() < _kMinFlingVelocity) {
            return _FlingGestureKindCls::none;
        }
        assert(vx != 0.0);
        flingDirection = _extentToDirection(vx);
    } else {
        if (vy->abs() - vx->abs() < _kMinFlingVelocityDelta || vy->abs() < _kMinFlingVelocity) {
            return _FlingGestureKindCls::none;
        }
        assert(vy != 0.0);
        flingDirection = _extentToDirection(vy);
    }
    assert(_dismissDirection() != nullptr);
    if (flingDirection == _dismissDirection()) {
        return _FlingGestureKindCls::forward;
    }
    return _FlingGestureKindCls::reverse;
}

void _DismissibleStateCls::_handleDragEnd(DragEndDetails details) {
    if (!_isActive() || _moveController!->isAnimating()) {
        return;
    }
    _dragUnderway = false;
    if (_moveController!->isCompleted()) {
        _handleMoveCompleted();
        return;
    }
    double flingVelocity = _directionIsXAxis()? details->velocity->pixelsPerSecond->dx() : details->velocity->pixelsPerSecond->dy();
    ;
}

Future<void> _DismissibleStateCls::_handleDismissStatusChanged(AnimationStatus status) {
    if (status == AnimationStatusCls::completed && !_dragUnderway) {
        await await _handleMoveCompleted();
    }
    if (mounted()) {
        updateKeepAlive();
    }
}

Future<void> _DismissibleStateCls::_handleMoveCompleted() {
    if ((widget()->dismissThresholds[_dismissDirection()] | _kDismissThreshold) >= 1.0) {
        _moveController!->reverse();
        return;
    }
    bool result = await _confirmStartResizeAnimation();
    if (mounted()) {
        if (result) {
            _startResizeAnimation();
        } else {
            _moveController!->reverse();
        }
    }
}

Future<bool> _DismissibleStateCls::_confirmStartResizeAnimation() {
    if (widget()->confirmDismiss != nullptr) {
        _confirming = true;
        DismissDirection direction = _dismissDirection();
        try {
            return await widget()->confirmDismiss!(direction) | false;
        } finally {
            _confirming = false;
        };
    }
    return true;
}

void _DismissibleStateCls::_startResizeAnimation() {
    assert(_moveController!->isCompleted());
    assert(_resizeController == nullptr);
    assert(_sizePriorToCollapse == nullptr);
    if (widget()->resizeDuration == nullptr) {
        if (widget()->onDismissed != nullptr) {
            DismissDirection direction = _dismissDirection();
            widget()->onDismissed!(direction);
        }
    } else {
            auto _c1 = make<AnimationControllerCls>(widget()->resizeDuration, this);    _c1.auto _c2 = addListener(_handleResizeProgressChanged);    _c2.addStatusListener([=] (AnimationStatus status) {                updateKeepAlive();            });    _c2;_resizeController = _c1;
        _resizeController!->forward();
        setState([=] () {
            _sizePriorToCollapse = context()->size();
            _resizeAnimation = _resizeController!->drive(make<CurveTweenCls>(_kResizeTimeCurve))->drive(<double>make<TweenCls>(1.0, 0.0));
        });
    }
}

void _DismissibleStateCls::_handleResizeProgressChanged() {
    if (_resizeController!->isCompleted()) {
        widget()->onDismissed?->call(_dismissDirection());
    } else {
        widget()->onResize?->call();
    }
}
