#ifndef TRANSITIONS_H
#define TRANSITIONS_H
#include <memory>
#include <flutter/rendering.hpp>

#include <math/math.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "framework.hpp"
#include "text.hpp"



class AnimatedWidget : StatefulWidget {
public:
    Listenable listenable;


     AnimatedWidget(Unknown, Listenable listenable);

    Widget build(BuildContext context);

    State<AnimatedWidget> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedState : State<AnimatedWidget> {
public:

    void initState();

    void didUpdateWidget(AnimatedWidget oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

    void _handleChange();

};

class SlideTransition : AnimatedWidget {
public:
    TextDirection textDirection;

    bool transformHitTests;

    Widget child;


     SlideTransition(Widget child, Unknown, Animation<Offset> position, TextDirection textDirection, bool transformHitTests);

    Animation<Offset> position();

    Widget build(BuildContext context);

private:

};

class ScaleTransition : AnimatedWidget {
public:
    Alignment alignment;

    FilterQuality filterQuality;

    Widget child;


     ScaleTransition(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown, Animation<double> scale);

    Animation<double> scale();

    Widget build(BuildContext context);

private:

};

class RotationTransition : AnimatedWidget {
public:
    Alignment alignment;

    FilterQuality filterQuality;

    Widget child;


     RotationTransition(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown, Animation<double> turns);

    Animation<double> turns();

    Widget build(BuildContext context);

private:

};

class SizeTransition : AnimatedWidget {
public:
    Axis axis;

    double axisAlignment;

    Widget child;


     SizeTransition(Axis axis, double axisAlignment, Widget child, Unknown, Animation<double> sizeFactor);

    Animation<double> sizeFactor();

    Widget build(BuildContext context);

private:

};

class FadeTransition : SingleChildRenderObjectWidget {
public:
    Animation<double> opacity;

    bool alwaysIncludeSemantics;


     FadeTransition(bool alwaysIncludeSemantics, Unknown, Unknown, Animation<double> opacity);

    RenderAnimatedOpacity createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAnimatedOpacity renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverFadeTransition : SingleChildRenderObjectWidget {
public:
    Animation<double> opacity;

    bool alwaysIncludeSemantics;


     SliverFadeTransition(bool alwaysIncludeSemantics, Unknown, Animation<double> opacity, Widget sliver);

    RenderSliverAnimatedOpacity createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverAnimatedOpacity renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RelativeRectTween : Tween<RelativeRect> {
public:

     RelativeRectTween(Unknown, Unknown);

    RelativeRect lerp(double t);

private:

};

class PositionedTransition : AnimatedWidget {
public:
    Widget child;


     PositionedTransition(Widget child, Unknown, Animation<RelativeRect> rect);

    Animation<RelativeRect> rect();

    Widget build(BuildContext context);

private:

};

class RelativePositionedTransition : AnimatedWidget {
public:
    Size size;

    Widget child;


     RelativePositionedTransition(Widget child, Unknown, Animation<Rect> rect, Size size);

    Animation<Rect> rect();

    Widget build(BuildContext context);

private:

};

class DecoratedBoxTransition : AnimatedWidget {
public:
    Animation<Decoration> decoration;

    DecorationPosition position;

    Widget child;


     DecoratedBoxTransition(Widget child, Animation<Decoration> decoration, Unknown, DecorationPosition position);

    Widget build(BuildContext context);

private:

};

class AlignTransition : AnimatedWidget {
public:
    double widthFactor;

    double heightFactor;

    Widget child;


     AlignTransition(Animation<AlignmentGeometry> alignment, Widget child, double heightFactor, Unknown, double widthFactor);

    Animation<AlignmentGeometry> alignment();

    Widget build(BuildContext context);

private:

};

class DefaultTextStyleTransition : AnimatedWidget {
public:
    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    Widget child;


     DefaultTextStyleTransition(Widget child, Unknown, int maxLines, TextOverflow overflow, bool softWrap, Animation<TextStyle> style, TextAlign textAlign);

    Animation<TextStyle> style();

    Widget build(BuildContext context);

private:

};

class AnimatedBuilder : AnimatedWidget {
public:
    TransitionBuilder builder;

    Widget child;


     AnimatedBuilder(Listenable animation, TransitionBuilder builder, Widget child, Unknown);

    Widget build(BuildContext context);

private:

};

#endif