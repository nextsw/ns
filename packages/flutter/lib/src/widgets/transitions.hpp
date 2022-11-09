#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TRANSITIONS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TRANSITIONS
#include <base.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "framework.hpp"
#include "text.hpp"


class AnimatedWidgetCls : public StatefulWidgetCls {
public:
    Listenable listenable;


     AnimatedWidgetCls(Unknown key, Listenable listenable);

    virtual Widget build(BuildContext context);
    virtual State<AnimatedWidget> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedWidget = std::shared_ptr<AnimatedWidgetCls>;

class _AnimatedStateCls : public StateCls<AnimatedWidget> {
public:

    virtual void initState();

    virtual void didUpdateWidget(AnimatedWidget oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _handleChange();

};
using _AnimatedState = std::shared_ptr<_AnimatedStateCls>;

class SlideTransitionCls : public AnimatedWidgetCls {
public:
    TextDirection textDirection;

    bool transformHitTests;

    Widget child;


     SlideTransitionCls(Widget child, Unknown key, Animation<Offset> position, TextDirection textDirection, bool transformHitTests);

    virtual Animation<Offset> position();

    virtual Widget build(BuildContext context);

private:

};
using SlideTransition = std::shared_ptr<SlideTransitionCls>;

class ScaleTransitionCls : public AnimatedWidgetCls {
public:
    Alignment alignment;

    FilterQuality filterQuality;

    Widget child;


     ScaleTransitionCls(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown key, Animation<double> scale);

    virtual Animation<double> scale();

    virtual Widget build(BuildContext context);

private:

};
using ScaleTransition = std::shared_ptr<ScaleTransitionCls>;

class RotationTransitionCls : public AnimatedWidgetCls {
public:
    Alignment alignment;

    FilterQuality filterQuality;

    Widget child;


     RotationTransitionCls(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown key, Animation<double> turns);

    virtual Animation<double> turns();

    virtual Widget build(BuildContext context);

private:

};
using RotationTransition = std::shared_ptr<RotationTransitionCls>;

class SizeTransitionCls : public AnimatedWidgetCls {
public:
    Axis axis;

    double axisAlignment;

    Widget child;


     SizeTransitionCls(Axis axis, double axisAlignment, Widget child, Unknown key, Animation<double> sizeFactor);

    virtual Animation<double> sizeFactor();

    virtual Widget build(BuildContext context);

private:

};
using SizeTransition = std::shared_ptr<SizeTransitionCls>;

class FadeTransitionCls : public SingleChildRenderObjectWidgetCls {
public:
    Animation<double> opacity;

    bool alwaysIncludeSemantics;


     FadeTransitionCls(bool alwaysIncludeSemantics, Unknown child, Unknown key, Animation<double> opacity);

    virtual RenderAnimatedOpacity createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAnimatedOpacity renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using FadeTransition = std::shared_ptr<FadeTransitionCls>;

class SliverFadeTransitionCls : public SingleChildRenderObjectWidgetCls {
public:
    Animation<double> opacity;

    bool alwaysIncludeSemantics;


     SliverFadeTransitionCls(bool alwaysIncludeSemantics, Unknown key, Animation<double> opacity, Widget sliver);

    virtual RenderSliverAnimatedOpacity createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverAnimatedOpacity renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverFadeTransition = std::shared_ptr<SliverFadeTransitionCls>;

class RelativeRectTweenCls : public TweenCls<RelativeRect> {
public:

     RelativeRectTweenCls(Unknown begin, Unknown end);
    virtual RelativeRect lerp(double t);

private:

};
using RelativeRectTween = std::shared_ptr<RelativeRectTweenCls>;

class PositionedTransitionCls : public AnimatedWidgetCls {
public:
    Widget child;


     PositionedTransitionCls(Widget child, Unknown key, Animation<RelativeRect> rect);

    virtual Animation<RelativeRect> rect();

    virtual Widget build(BuildContext context);

private:

};
using PositionedTransition = std::shared_ptr<PositionedTransitionCls>;

class RelativePositionedTransitionCls : public AnimatedWidgetCls {
public:
    Size size;

    Widget child;


     RelativePositionedTransitionCls(Widget child, Unknown key, Animation<Rect> rect, Size size);

    virtual Animation<Rect> rect();

    virtual Widget build(BuildContext context);

private:

};
using RelativePositionedTransition = std::shared_ptr<RelativePositionedTransitionCls>;

class DecoratedBoxTransitionCls : public AnimatedWidgetCls {
public:
    Animation<Decoration> decoration;

    DecorationPosition position;

    Widget child;


     DecoratedBoxTransitionCls(Widget child, Animation<Decoration> decoration, Unknown key, DecorationPosition position);

    virtual Widget build(BuildContext context);

private:

};
using DecoratedBoxTransition = std::shared_ptr<DecoratedBoxTransitionCls>;

class AlignTransitionCls : public AnimatedWidgetCls {
public:
    double widthFactor;

    double heightFactor;

    Widget child;


     AlignTransitionCls(Animation<AlignmentGeometry> alignment, Widget child, double heightFactor, Unknown key, double widthFactor);

    virtual Animation<AlignmentGeometry> alignment();

    virtual Widget build(BuildContext context);

private:

};
using AlignTransition = std::shared_ptr<AlignTransitionCls>;

class DefaultTextStyleTransitionCls : public AnimatedWidgetCls {
public:
    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    Widget child;


     DefaultTextStyleTransitionCls(Widget child, Unknown key, int maxLines, TextOverflow overflow, bool softWrap, Animation<TextStyle> style, TextAlign textAlign);

    virtual Animation<TextStyle> style();

    virtual Widget build(BuildContext context);

private:

};
using DefaultTextStyleTransition = std::shared_ptr<DefaultTextStyleTransitionCls>;

class AnimatedBuilderCls : public AnimatedWidgetCls {
public:
    TransitionBuilder builder;

    Widget child;


     AnimatedBuilderCls(Listenable animation, TransitionBuilder builder, Widget child, Unknown key);

    virtual Widget build(BuildContext context);

private:

};
using AnimatedBuilder = std::shared_ptr<AnimatedBuilderCls>;


#endif