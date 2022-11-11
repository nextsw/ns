#include "animated_size.hpp"
RenderAnimatedSizeCls::RenderAnimatedSizeCls(Unknown alignment, Unknown child, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, Unknown textDirection, TickerProvider vsync) {
    {
        assert(vsync != nullptr);
        assert(duration != nullptr);
        assert(curve != nullptr);
        assert(clipBehavior != nullptr);
        _vsync = vsync;
        _clipBehavior = clipBehavior;
    }
    {
                    });_controller =                     }            auto _c1 = make<AnimationControllerCls>(vsync, duration, reverseDuration);            _c1.addListener([=] () {                        if (_controller->value != _lastValue) {                            markNeedsLayout();_c1;
        _animation = make<CurvedAnimationCls>(_controller, curve);
    }
}

RenderAnimatedSizeState RenderAnimatedSizeCls::state() {
    return _state;
}

Duration RenderAnimatedSizeCls::duration() {
    return _controller->duration!;
}

void RenderAnimatedSizeCls::duration(Duration value) {
    assert(value != nullptr);
    if (value == _controller->duration) {
        return;
    }
    _controller->duration = value;
}

Duration RenderAnimatedSizeCls::reverseDuration() {
    return _controller->reverseDuration;
}

void RenderAnimatedSizeCls::reverseDuration(Duration value) {
    if (value == _controller->reverseDuration) {
        return;
    }
    _controller->reverseDuration = value;
}

Curve RenderAnimatedSizeCls::curve() {
    return _animation->curve;
}

void RenderAnimatedSizeCls::curve(Curve value) {
    assert(value != nullptr);
    if (value == _animation->curve) {
        return;
    }
    _animation->curve = value;
}

Clip RenderAnimatedSizeCls::clipBehavior() {
    return _clipBehavior;
}

void RenderAnimatedSizeCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

bool RenderAnimatedSizeCls::isAnimating() {
    return _controller->isAnimating;
}

TickerProvider RenderAnimatedSizeCls::vsync() {
    return _vsync;
}

void RenderAnimatedSizeCls::vsync(TickerProvider value) {
    assert(value != nullptr);
    if (value == _vsync) {
        return;
    }
    _vsync = value;
    _controller->resync(vsync);
}

void RenderAnimatedSizeCls::attach(PipelineOwner owner) {
    super->attach(owner);
    ;
}

void RenderAnimatedSizeCls::detach() {
    _controller->stop();
    super->detach();
}

void RenderAnimatedSizeCls::performLayout() {
    _lastValue = _controller->value;
    _hasVisualOverflow = false;
    BoxConstraints constraints = this->constraints;
    if (child == nullptr || constraints->isTight()) {
        _controller->stop();
        size = _sizeTween->begin = _sizeTween->end = constraints->smallest();
        _state = RenderAnimatedSizeStateCls::start;
        child?->layout(constraints);
        return;
    }
    child!->layout(constraintstrue);
    assert(_state != nullptr);
    ;
    size = constraints->constrain(_animatedSize()!);
    alignChild();
    if (size->width < _sizeTween->end!->width || size->height < _sizeTween->end!->height) {
        _hasVisualOverflow = true;
    }
}

Size RenderAnimatedSizeCls::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr || constraints->isTight()) {
        return constraints->smallest();
    }
    Size childSize = child!->getDryLayout(constraints);
    assert(_state != nullptr);
    ;
    return constraints->constrain(_animatedSize()!);
}

void RenderAnimatedSizeCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && _hasVisualOverflow && clipBehavior != ClipCls::none) {
        Rect rect = OffsetCls::zero & size;
        _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, rect, super->paintclipBehavior, _clipRectLayer->layer);
    } else {
        _clipRectLayer->layer = nullptr;
        super->paint(context, offset);
    }
}

void RenderAnimatedSizeCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

Size RenderAnimatedSizeCls::_animatedSize() {
    return _sizeTween->evaluate(_animation);
}

void RenderAnimatedSizeCls::_restartAnimation() {
    _lastValue = 0.0;
    _controller->forward(0.0);
}

void RenderAnimatedSizeCls::_layoutStart() {
    _sizeTween->begin = _sizeTween->end = debugAdoptSize(child!->size);
    _state = RenderAnimatedSizeStateCls::stable;
}

void RenderAnimatedSizeCls::_layoutStable() {
    if (_sizeTween->end != child!->size) {
        _sizeTween->begin = size;
        _sizeTween->end = debugAdoptSize(child!->size);
        _restartAnimation();
        _state = RenderAnimatedSizeStateCls::changed;
    } else     {
        if (_controller->value == _controller->upperBound) {
        _sizeTween->begin = _sizeTween->end = debugAdoptSize(child!->size);
    } else     {
        if (!_controller->isAnimating) {
        _controller->forward();
    }
;
    };
    }}

void RenderAnimatedSizeCls::_layoutChanged() {
    if (_sizeTween->end != child!->size) {
        _sizeTween->begin = _sizeTween->end = debugAdoptSize(child!->size);
        _restartAnimation();
        _state = RenderAnimatedSizeStateCls::unstable;
    } else {
        _state = RenderAnimatedSizeStateCls::stable;
        if (!_controller->isAnimating) {
            _controller->forward();
        }
    }
}

void RenderAnimatedSizeCls::_layoutUnstable() {
    if (_sizeTween->end != child!->size) {
        _sizeTween->begin = _sizeTween->end = debugAdoptSize(child!->size);
        _restartAnimation();
    } else {
        _controller->stop();
        _state = RenderAnimatedSizeStateCls::stable;
    }
}
