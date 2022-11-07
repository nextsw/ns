#ifndef ANIMATED_SIZE_H
#define ANIMATED_SIZE_H
#include <memory>

#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "shifted_box.hpp"



enum RenderAnimatedSizeState{
    start,
    stable,
    changed,
    unstable,
} // end RenderAnimatedSizeState

class RenderAnimatedSize : RenderAligningShiftedBox {
public:

     RenderAnimatedSize(Unknown, Unknown, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, Unknown, TickerProvider vsync);

    RenderAnimatedSizeState state();

    Duration duration();

    void  duration(Duration value);

    Duration reverseDuration();

    void  reverseDuration(Duration value);

    Curve curve();

    void  curve(Curve value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    bool isAnimating();

    TickerProvider vsync();

    void  vsync(TickerProvider value);

    void attach(PipelineOwner owner);

    void detach();

    void performLayout();

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

    void dispose();

private:
    AnimationController _controller;

    CurvedAnimation _animation;

    SizeTween _sizeTween;

    bool _hasVisualOverflow;

    double _lastValue;

    RenderAnimatedSizeState _state;

    Clip _clipBehavior;

    TickerProvider _vsync;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    Size _animatedSize();

    void _restartAnimation();

    void _layoutStart();

    void _layoutStable();

    void _layoutChanged();

    void _layoutUnstable();

};

#endif