#ifndef ANIMATED_SIZE_H
#define ANIMATED_SIZE_H
#include <memory>

#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"



class AnimatedSize : StatefulWidget {
public:
    Widget child;

    AlignmentGeometry alignment;

    Curve curve;

    Duration duration;

    Duration reverseDuration;

    Clip clipBehavior;


     AnimatedSize(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Unknown, Duration reverseDuration, TickerProvider vsync);

    State<AnimatedSize> createState();

private:

};

class _AnimatedSizeState : State<AnimatedSize> {
public:

    Widget build(BuildContext context);

private:

};

class _AnimatedSize : SingleChildRenderObjectWidget {
public:
    AlignmentGeometry alignment;

    Curve curve;

    Duration duration;

    Duration reverseDuration;

    TickerProvider vsync;

    Clip clipBehavior;


    RenderAnimatedSize createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAnimatedSize renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _AnimatedSize(AlignmentGeometry alignment, Unknown, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, TickerProvider vsync);

};

#endif