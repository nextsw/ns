#include "animated_size.hpp"
RenderAnimatedSize::RenderAnimatedSize(Unknown, Unknown, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, Unknown, TickerProvider vsync) {
    {
        assert(vsync != nullptr);
        assert(duration != nullptr);
        assert(curve != nullptr);
        assert(clipBehavior != nullptr);
        _vsync = vsync;
        _clipBehavior = clipBehavior;
    }
    {
        _controller = ;
        _animation = CurvedAnimation(_controller, curve);
    }
}

RenderAnimatedSizeState RenderAnimatedSize::state() {
    return _state;
}

Duration RenderAnimatedSize::duration() {
    return _controller.duration!;
}

void RenderAnimatedSize::duration(Duration value) {
    assert(value != nullptr);
    if (value == _controller.duration) {
        return;
    }
    _controller.duration = value;
}

Duration RenderAnimatedSize::reverseDuration() {
    return _controller.reverseDuration;
}

void RenderAnimatedSize::reverseDuration(Duration value) {
    if (value == _controller.reverseDuration) {
        return;
    }
    _controller.reverseDuration = value;
}

Curve RenderAnimatedSize::curve() {
    return _animation.curve;
}

void RenderAnimatedSize::curve(Curve value) {
    assert(value != nullptr);
    if (value == _animation.curve) {
        return;
    }
    _animation.curve = value;
}

Clip RenderAnimatedSize::clipBehavior() {
    return _clipBehavior;
}

void RenderAnimatedSize::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

bool RenderAnimatedSize::isAnimating() {
    return _controller.isAnimating;
}

TickerProvider RenderAnimatedSize::vsync() {
    return _vsync;
}

void RenderAnimatedSize::vsync(TickerProvider value) {
    assert(value != nullptr);
    if (value == _vsync) {
        return;
    }
    _vsync = value;
    _controller.resync(vsync);
}

void RenderAnimatedSize::attach(PipelineOwner owner) {
    super.attach(owner);
    ;
}

void RenderAnimatedSize::detach() {
    _controller.stop();
    super.detach();
}

void RenderAnimatedSize::performLayout() {
    _lastValue = _controller.value;
    _hasVisualOverflow = false;
    BoxConstraints constraints = this.constraints;
    if (child == nullptr || constraints.isTight) {
        _controller.stop();
        size = _sizeTween.begin = _sizeTween.end = constraints.smallest;
        _state = RenderAnimatedSizeState.start;
        child?.layout(constraints);
        return;
    }
    child!.layout(constraintstrue);
    assert(_state != nullptr);
    ;
    size = constraints.constrain(_animatedSize!);
    alignChild();
    if (size.width < _sizeTween.end!.width || size.height < _sizeTween.end!.height) {
        _hasVisualOverflow = true;
    }
}

Size RenderAnimatedSize::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr || constraints.isTight) {
        return constraints.smallest;
    }
    Size childSize = child!.getDryLayout(constraints);
    assert(_state != nullptr);
    ;
    return constraints.constrain(_animatedSize!);
}

void RenderAnimatedSize::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && _hasVisualOverflow && clipBehavior != Clip.none) {
        Rect rect = Offset.zero & size;
        _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, rect, super.paintclipBehavior, _clipRectLayer.layer);
    } else {
        _clipRectLayer.layer = nullptr;
        super.paint(context, offset);
    }
}

void RenderAnimatedSize::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

Size RenderAnimatedSize::_animatedSize() {
    return _sizeTween.evaluate(_animation);
}

void RenderAnimatedSize::_restartAnimation() {
    _lastValue = 0.0;
    _controller.forward(0.0);
}

void RenderAnimatedSize::_layoutStart() {
    _sizeTween.begin = _sizeTween.end = debugAdoptSize(child!.size);
    _state = RenderAnimatedSizeState.stable;
}

void RenderAnimatedSize::_layoutStable() {
    if (_sizeTween.end != child!.size) {
        _sizeTween.begin = size;
        _sizeTween.end = debugAdoptSize(child!.size);
        _restartAnimation();
        _state = RenderAnimatedSizeState.changed;
    } else     {
        if (_controller.value == _controller.upperBound) {
        _sizeTween.begin = _sizeTween.end = debugAdoptSize(child!.size);
    } else     {
        if (!_controller.isAnimating) {
        _controller.forward();
    }
;
    };
    }}

void RenderAnimatedSize::_layoutChanged() {
    if (_sizeTween.end != child!.size) {
        _sizeTween.begin = _sizeTween.end = debugAdoptSize(child!.size);
        _restartAnimation();
        _state = RenderAnimatedSizeState.unstable;
    } else {
        _state = RenderAnimatedSizeState.stable;
        if (!_controller.isAnimating) {
            _controller.forward();
        }
    }
}

void RenderAnimatedSize::_layoutUnstable() {
    if (_sizeTween.end != child!.size) {
        _sizeTween.begin = _sizeTween.end = debugAdoptSize(child!.size);
        _restartAnimation();
    } else {
        _controller.stop();
        _state = RenderAnimatedSizeState.stable;
    }
}
