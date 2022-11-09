#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_ANIMATED_SIZE
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_ANIMATED_SIZE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class RenderAnimatedSizeCls : public RenderAligningShiftedBoxCls {
public:

     RenderAnimatedSizeCls(Unknown alignment, Unknown child, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, Unknown textDirection, TickerProvider vsync);

    virtual RenderAnimatedSizeState state();

    virtual Duration duration();

    virtual void  duration(Duration value);

    virtual Duration reverseDuration();

    virtual void  reverseDuration(Duration value);

    virtual Curve curve();

    virtual void  curve(Curve value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual bool isAnimating();

    virtual TickerProvider vsync();

    virtual void  vsync(TickerProvider value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void performLayout();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

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


    virtual Size _animatedSize();

    virtual void _restartAnimation();

    virtual void _layoutStart();

    virtual void _layoutStable();

    virtual void _layoutChanged();

    virtual void _layoutUnstable();

};
using RenderAnimatedSize = std::shared_ptr<RenderAnimatedSizeCls>;


#endif