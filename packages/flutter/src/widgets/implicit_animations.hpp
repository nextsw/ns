#ifndef IMPLICIT_ANIMATIONS_H
#define IMPLICIT_ANIMATIONS_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <vector_math/vector_math_64.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "text.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"



class BoxConstraintsTween : Tween<BoxConstraints> {
public:

     BoxConstraintsTween(Unknown, Unknown);

    BoxConstraints lerp(double t);

private:

};

class DecorationTween : Tween<Decoration> {
public:

     DecorationTween(Unknown, Unknown);

    Decoration lerp(double t);

private:

};

class EdgeInsetsTween : Tween<EdgeInsets> {
public:

     EdgeInsetsTween(Unknown, Unknown);

    EdgeInsets lerp(double t);

private:

};

class EdgeInsetsGeometryTween : Tween<EdgeInsetsGeometry> {
public:

     EdgeInsetsGeometryTween(Unknown, Unknown);

    EdgeInsetsGeometry lerp(double t);

private:

};

class BorderRadiusTween : Tween<BorderRadius> {
public:

     BorderRadiusTween(Unknown, Unknown);

    BorderRadius lerp(double t);

private:

};

class BorderTween : Tween<Border> {
public:

     BorderTween(Unknown, Unknown);

    Border lerp(double t);

private:

};

class Matrix4Tween : Tween<Matrix4> {
public:

     Matrix4Tween(Unknown, Unknown);

    Matrix4 lerp(double t);

private:

};

class TextStyleTween : Tween<TextStyle> {
public:

     TextStyleTween(Unknown, Unknown);

    TextStyle lerp(double t);

private:

};

class ImplicitlyAnimatedWidget : StatefulWidget {
public:
    Curve curve;

    Duration duration;

    VoidCallback onEnd;


     ImplicitlyAnimatedWidget(Curve curve, Duration duration, Unknown, VoidCallback onEnd);

    ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ImplicitlyAnimatedWidgetState<T extends ImplicitlyAnimatedWidget> : State<T> {
public:

    AnimationController controller();

    Animation<double> animation();

    void initState();

    void didUpdateWidget(T oldWidget);

    void dispose();

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

private:
    AnimationController _controller;

    Animation<double> _animation;


    CurvedAnimation _createCurve();

    bool _shouldAnimateTween(dynamic targetValue, Tween<dynamic> tween);

    void _updateTween(dynamic targetValue, Tween<dynamic> tween);

    bool _constructTweens();

};

class AnimatedWidgetBaseState<T extends ImplicitlyAnimatedWidget> : ImplicitlyAnimatedWidgetState<T> {
public:

    void initState();

private:

    void _handleAnimationChanged();

};

class AnimatedContainer : ImplicitlyAnimatedWidget {
public:
    Widget child;

    AlignmentGeometry alignment;

    EdgeInsetsGeometry padding;

    Decoration decoration;

    Decoration foregroundDecoration;

    BoxConstraints constraints;

    EdgeInsetsGeometry margin;

    Matrix4 transform;

    AlignmentGeometry transformAlignment;

    Clip clipBehavior;


     AnimatedContainer(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Unknown, Decoration decoration, Unknown, Decoration foregroundDecoration, double height, Unknown, EdgeInsetsGeometry margin, Unknown, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width);

    AnimatedWidgetBaseState<AnimatedContainer> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedContainerState : AnimatedWidgetBaseState<AnimatedContainer> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AlignmentGeometryTween _alignment;

    EdgeInsetsGeometryTween _padding;

    DecorationTween _decoration;

    DecorationTween _foregroundDecoration;

    BoxConstraintsTween _constraints;

    EdgeInsetsGeometryTween _margin;

    Matrix4Tween _transform;

    AlignmentGeometryTween _transformAlignment;


};

class AnimatedPadding : ImplicitlyAnimatedWidget {
public:
    EdgeInsetsGeometry padding;

    Widget child;


     AnimatedPadding(Widget child, Unknown, Unknown, Unknown, Unknown, EdgeInsetsGeometry padding);

    AnimatedWidgetBaseState<AnimatedPadding> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedPaddingState : AnimatedWidgetBaseState<AnimatedPadding> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    EdgeInsetsGeometryTween _padding;


};

class AnimatedAlign : ImplicitlyAnimatedWidget {
public:
    AlignmentGeometry alignment;

    Widget child;

    double heightFactor;

    double widthFactor;


     AnimatedAlign(AlignmentGeometry alignment, Widget child, Unknown, Unknown, double heightFactor, Unknown, Unknown, double widthFactor);

    AnimatedWidgetBaseState<AnimatedAlign> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedAlignState : AnimatedWidgetBaseState<AnimatedAlign> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AlignmentGeometryTween _alignment;

    Tween<double> _heightFactorTween;

    Tween<double> _widthFactorTween;


};

class AnimatedPositioned : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double left;

    double top;

    double right;

    double bottom;

    double width;

    double height;


     AnimatedPositioned(double bottom, Widget child, Unknown, Unknown, double height, Unknown, double left, Unknown, double right, double top, double width);

    void  fromRect(Widget child, Unknown, Unknown, Unknown, Unknown, Rect rect);

    AnimatedWidgetBaseState<AnimatedPositioned> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedPositionedState : AnimatedWidgetBaseState<AnimatedPositioned> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Tween<double> _left;

    Tween<double> _top;

    Tween<double> _right;

    Tween<double> _bottom;

    Tween<double> _width;

    Tween<double> _height;


};

class AnimatedPositionedDirectional : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double start;

    double top;

    double end;

    double bottom;

    double width;

    double height;


     AnimatedPositionedDirectional(double bottom, Widget child, Unknown, Unknown, double end, double height, Unknown, Unknown, double start, double top, double width);

    AnimatedWidgetBaseState<AnimatedPositionedDirectional> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedPositionedDirectionalState : AnimatedWidgetBaseState<AnimatedPositionedDirectional> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Tween<double> _start;

    Tween<double> _top;

    Tween<double> _end;

    Tween<double> _bottom;

    Tween<double> _width;

    Tween<double> _height;


};

class AnimatedScale : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double scale;

    Alignment alignment;

    FilterQuality filterQuality;


     AnimatedScale(Alignment alignment, Widget child, Unknown, Unknown, FilterQuality filterQuality, Unknown, Unknown, double scale);

    ImplicitlyAnimatedWidgetState<AnimatedScale> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedScaleState : ImplicitlyAnimatedWidgetState<AnimatedScale> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

private:
    Tween<double> _scale;

    Animation<double> _scaleAnimation;


};

class AnimatedRotation : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double turns;

    Alignment alignment;

    FilterQuality filterQuality;


     AnimatedRotation(Alignment alignment, Widget child, Unknown, Unknown, FilterQuality filterQuality, Unknown, Unknown, double turns);

    ImplicitlyAnimatedWidgetState<AnimatedRotation> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedRotationState : ImplicitlyAnimatedWidgetState<AnimatedRotation> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

private:
    Tween<double> _turns;

    Animation<double> _turnsAnimation;


};

class AnimatedSlide : ImplicitlyAnimatedWidget {
public:
    Widget child;

    Offset offset;


     AnimatedSlide(Widget child, Unknown, Unknown, Unknown, Offset offset, Unknown);

    ImplicitlyAnimatedWidgetState<AnimatedSlide> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedSlideState : ImplicitlyAnimatedWidgetState<AnimatedSlide> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

private:
    Tween<Offset> _offset;

    Animation<Offset> _offsetAnimation;


};

class AnimatedOpacity : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double opacity;

    bool alwaysIncludeSemantics;


     AnimatedOpacity(bool alwaysIncludeSemantics, Widget child, Unknown, Unknown, Unknown, Unknown, double opacity);

    ImplicitlyAnimatedWidgetState<AnimatedOpacity> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedOpacityState : ImplicitlyAnimatedWidgetState<AnimatedOpacity> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

private:
    Tween<double> _opacity;

    Animation<double> _opacityAnimation;


};

class SliverAnimatedOpacity : ImplicitlyAnimatedWidget {
public:
    Widget sliver;

    double opacity;

    bool alwaysIncludeSemantics;


     SliverAnimatedOpacity(bool alwaysIncludeSemantics, Unknown, Unknown, Unknown, Unknown, double opacity, Widget sliver);

    ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _SliverAnimatedOpacityState : ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

private:
    Tween<double> _opacity;

    Animation<double> _opacityAnimation;


};

class AnimatedDefaultTextStyle : ImplicitlyAnimatedWidget {
public:
    Widget child;

    TextStyle style;

    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;


     AnimatedDefaultTextStyle(Widget child, Unknown, Unknown, Unknown, int maxLines, Unknown, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis);

    AnimatedWidgetBaseState<AnimatedDefaultTextStyle> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedDefaultTextStyleState : AnimatedWidgetBaseState<AnimatedDefaultTextStyle> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

private:
    TextStyleTween _style;


};

class AnimatedPhysicalModel : ImplicitlyAnimatedWidget {
public:
    Widget child;

    BoxShape shape;

    Clip clipBehavior;

    BorderRadius borderRadius;

    double elevation;

    Color color;

    bool animateColor;

    Color shadowColor;

    bool animateShadowColor;


     AnimatedPhysicalModel(bool animateColor, bool animateShadowColor, BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, Unknown, Unknown, double elevation, Unknown, Unknown, Color shadowColor, BoxShape shape);

    AnimatedWidgetBaseState<AnimatedPhysicalModel> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedPhysicalModelState : AnimatedWidgetBaseState<AnimatedPhysicalModel> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

private:
    BorderRadiusTween _borderRadius;

    Tween<double> _elevation;

    ColorTween _color;

    ColorTween _shadowColor;


};

class AnimatedFractionallySizedBox : ImplicitlyAnimatedWidget {
public:
    Widget child;

    double heightFactor;

    double widthFactor;

    AlignmentGeometry alignment;


     AnimatedFractionallySizedBox(AlignmentGeometry alignment, Widget child, Unknown, Unknown, double heightFactor, Unknown, Unknown, double widthFactor);

    AnimatedWidgetBaseState<AnimatedFractionallySizedBox> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedFractionallySizedBoxState : AnimatedWidgetBaseState<AnimatedFractionallySizedBox> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AlignmentGeometryTween _alignment;

    Tween<double> _heightFactorTween;

    Tween<double> _widthFactorTween;


};

#endif