#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_SIZE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_SIZE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"


class AnimatedSizeCls : public StatefulWidgetCls {
public:
    Widget child;

    AlignmentGeometry alignment;

    Curve curve;

    Duration duration;

    Duration reverseDuration;

    Clip clipBehavior;


     AnimatedSizeCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Key key, Duration reverseDuration, TickerProvider vsync);

    virtual State<AnimatedSize> createState();

private:

};
using AnimatedSize = std::shared_ptr<AnimatedSizeCls>;

class _AnimatedSizeStateCls : public StateCls<AnimatedSize> {
public:

    virtual Widget build(BuildContext context);

private:

};
using _AnimatedSizeState = std::shared_ptr<_AnimatedSizeStateCls>;

class _AnimatedSizeCls : public SingleChildRenderObjectWidgetCls {
public:
    AlignmentGeometry alignment;

    Curve curve;

    Duration duration;

    Duration reverseDuration;

    TickerProvider vsync;

    Clip clipBehavior;


    virtual RenderAnimatedSize createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAnimatedSize renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _AnimatedSizeCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, TickerProvider vsync);

};
using _AnimatedSize = std::shared_ptr<_AnimatedSizeCls>;


#endif