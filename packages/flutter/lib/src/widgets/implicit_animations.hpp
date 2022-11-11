#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMPLICIT_ANIMATIONS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMPLICIT_ANIMATIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "text.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"


class BoxConstraintsTweenCls : public TweenCls<BoxConstraints> {
public:

     BoxConstraintsTweenCls(Unknown begin, Unknown end);
    virtual BoxConstraints lerp(double t);

private:

};
using BoxConstraintsTween = std::shared_ptr<BoxConstraintsTweenCls>;

class DecorationTweenCls : public TweenCls<Decoration> {
public:

     DecorationTweenCls(Unknown begin, Unknown end);
    virtual Decoration lerp(double t);

private:

};
using DecorationTween = std::shared_ptr<DecorationTweenCls>;

class EdgeInsetsTweenCls : public TweenCls<EdgeInsets> {
public:

     EdgeInsetsTweenCls(Unknown begin, Unknown end);
    virtual EdgeInsets lerp(double t);

private:

};
using EdgeInsetsTween = std::shared_ptr<EdgeInsetsTweenCls>;

class EdgeInsetsGeometryTweenCls : public TweenCls<EdgeInsetsGeometry> {
public:

     EdgeInsetsGeometryTweenCls(Unknown begin, Unknown end);
    virtual EdgeInsetsGeometry lerp(double t);

private:

};
using EdgeInsetsGeometryTween = std::shared_ptr<EdgeInsetsGeometryTweenCls>;

class BorderRadiusTweenCls : public TweenCls<BorderRadius> {
public:

     BorderRadiusTweenCls(Unknown begin, Unknown end);
    virtual BorderRadius lerp(double t);

private:

};
using BorderRadiusTween = std::shared_ptr<BorderRadiusTweenCls>;

class BorderTweenCls : public TweenCls<Border> {
public:

     BorderTweenCls(Unknown begin, Unknown end);
    virtual Border lerp(double t);

private:

};
using BorderTween = std::shared_ptr<BorderTweenCls>;

class Matrix4TweenCls : public TweenCls<Matrix4> {
public:

     Matrix4TweenCls(Unknown begin, Unknown end);
    virtual Matrix4 lerp(double t);

private:

};
using Matrix4Tween = std::shared_ptr<Matrix4TweenCls>;

class TextStyleTweenCls : public TweenCls<TextStyle> {
public:

     TextStyleTweenCls(Unknown begin, Unknown end);
    virtual TextStyle lerp(double t);

private:

};
using TextStyleTween = std::shared_ptr<TextStyleTweenCls>;

class ImplicitlyAnimatedWidgetCls : public StatefulWidgetCls {
public:
    Curve curve;

    Duration duration;

    VoidCallback onEnd;


     ImplicitlyAnimatedWidgetCls(Curve curve, Duration duration, Unknown key, VoidCallback onEnd);

    virtual ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> createState() override;
    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ImplicitlyAnimatedWidget = std::shared_ptr<ImplicitlyAnimatedWidgetCls>;

template<typename T>
class ImplicitlyAnimatedWidgetStateCls : public StateCls<T> {
public:

    virtual AnimationController controller();

    virtual Animation<double> animation();

    virtual void initState();

    virtual void didUpdateWidget(T oldWidget);

    virtual void dispose();

    virtual void forEachTween(TweenVisitor<dynamic> visitor);
    virtual void didUpdateTweens();

private:
    AnimationController _controller;

    Animation<double> _animation;


    virtual CurvedAnimation _createCurve();

    virtual bool _shouldAnimateTween(Tween<dynamic> tween, dynamic targetValue);

    virtual void _updateTween(Tween<dynamic> tween, dynamic targetValue);

    virtual bool _constructTweens();

};
template<typename T>
using ImplicitlyAnimatedWidgetState = std::shared_ptr<ImplicitlyAnimatedWidgetStateCls<T>>;

template<typename T>
class AnimatedWidgetBaseStateCls : public ImplicitlyAnimatedWidgetStateCls<T> {
public:

    virtual void initState();

private:

    virtual void _handleAnimationChanged();

};
template<typename T>
using AnimatedWidgetBaseState = std::shared_ptr<AnimatedWidgetBaseStateCls<T>>;

class AnimatedContainerCls : public ImplicitlyAnimatedWidgetCls {
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


     AnimatedContainerCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Unknown curve, Decoration decoration, Unknown duration, Decoration foregroundDecoration, double height, Unknown key, EdgeInsetsGeometry margin, Unknown onEnd, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width);

    virtual AnimatedWidgetBaseState<AnimatedContainer> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedContainer = std::shared_ptr<AnimatedContainerCls>;

class _AnimatedContainerStateCls : public AnimatedWidgetBaseStateCls<AnimatedContainer> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

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
using _AnimatedContainerState = std::shared_ptr<_AnimatedContainerStateCls>;

class AnimatedPaddingCls : public ImplicitlyAnimatedWidgetCls {
public:
    EdgeInsetsGeometry padding;

    Widget child;


     AnimatedPaddingCls(Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, EdgeInsetsGeometry padding);

    virtual AnimatedWidgetBaseState<AnimatedPadding> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedPadding = std::shared_ptr<AnimatedPaddingCls>;

class _AnimatedPaddingStateCls : public AnimatedWidgetBaseStateCls<AnimatedPadding> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    EdgeInsetsGeometryTween _padding;


};
using _AnimatedPaddingState = std::shared_ptr<_AnimatedPaddingStateCls>;

class AnimatedAlignCls : public ImplicitlyAnimatedWidgetCls {
public:
    AlignmentGeometry alignment;

    Widget child;

    double heightFactor;

    double widthFactor;


     AnimatedAlignCls(AlignmentGeometry alignment, Widget child, Unknown curve, Unknown duration, double heightFactor, Unknown key, Unknown onEnd, double widthFactor);

    virtual AnimatedWidgetBaseState<AnimatedAlign> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedAlign = std::shared_ptr<AnimatedAlignCls>;

class _AnimatedAlignStateCls : public AnimatedWidgetBaseStateCls<AnimatedAlign> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AlignmentGeometryTween _alignment;

    Tween<double> _heightFactorTween;

    Tween<double> _widthFactorTween;


};
using _AnimatedAlignState = std::shared_ptr<_AnimatedAlignStateCls>;

class AnimatedPositionedCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double left;

    double top;

    double right;

    double bottom;

    double width;

    double height;


     AnimatedPositionedCls(double bottom, Widget child, Unknown curve, Unknown duration, double height, Unknown key, double left, Unknown onEnd, double right, double top, double width);

    virtual void  fromRect(Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, Rect rect);

    virtual AnimatedWidgetBaseState<AnimatedPositioned> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedPositioned = std::shared_ptr<AnimatedPositionedCls>;

class _AnimatedPositionedStateCls : public AnimatedWidgetBaseStateCls<AnimatedPositioned> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Tween<double> _left;

    Tween<double> _top;

    Tween<double> _right;

    Tween<double> _bottom;

    Tween<double> _width;

    Tween<double> _height;


};
using _AnimatedPositionedState = std::shared_ptr<_AnimatedPositionedStateCls>;

class AnimatedPositionedDirectionalCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double start;

    double top;

    double end;

    double bottom;

    double width;

    double height;


     AnimatedPositionedDirectionalCls(double bottom, Widget child, Unknown curve, Unknown duration, double end, double height, Unknown key, Unknown onEnd, double start, double top, double width);

    virtual AnimatedWidgetBaseState<AnimatedPositionedDirectional> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedPositionedDirectional = std::shared_ptr<AnimatedPositionedDirectionalCls>;

class _AnimatedPositionedDirectionalStateCls : public AnimatedWidgetBaseStateCls<AnimatedPositionedDirectional> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Tween<double> _start;

    Tween<double> _top;

    Tween<double> _end;

    Tween<double> _bottom;

    Tween<double> _width;

    Tween<double> _height;


};
using _AnimatedPositionedDirectionalState = std::shared_ptr<_AnimatedPositionedDirectionalStateCls>;

class AnimatedScaleCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double scale;

    Alignment alignment;

    FilterQuality filterQuality;


     AnimatedScaleCls(Alignment alignment, Widget child, Unknown curve, Unknown duration, FilterQuality filterQuality, Unknown key, Unknown onEnd, double scale);

    virtual ImplicitlyAnimatedWidgetState<AnimatedScale> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedScale = std::shared_ptr<AnimatedScaleCls>;

class _AnimatedScaleStateCls : public ImplicitlyAnimatedWidgetStateCls<AnimatedScale> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

private:
    Tween<double> _scale;

    Animation<double> _scaleAnimation;


};
using _AnimatedScaleState = std::shared_ptr<_AnimatedScaleStateCls>;

class AnimatedRotationCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double turns;

    Alignment alignment;

    FilterQuality filterQuality;


     AnimatedRotationCls(Alignment alignment, Widget child, Unknown curve, Unknown duration, FilterQuality filterQuality, Unknown key, Unknown onEnd, double turns);

    virtual ImplicitlyAnimatedWidgetState<AnimatedRotation> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedRotation = std::shared_ptr<AnimatedRotationCls>;

class _AnimatedRotationStateCls : public ImplicitlyAnimatedWidgetStateCls<AnimatedRotation> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

private:
    Tween<double> _turns;

    Animation<double> _turnsAnimation;


};
using _AnimatedRotationState = std::shared_ptr<_AnimatedRotationStateCls>;

class AnimatedSlideCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    Offset offset;


     AnimatedSlideCls(Widget child, Unknown curve, Unknown duration, Unknown key, Offset offset, Unknown onEnd);
    virtual ImplicitlyAnimatedWidgetState<AnimatedSlide> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedSlide = std::shared_ptr<AnimatedSlideCls>;

class _AnimatedSlideStateCls : public ImplicitlyAnimatedWidgetStateCls<AnimatedSlide> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

private:
    Tween<Offset> _offset;

    Animation<Offset> _offsetAnimation;


};
using _AnimatedSlideState = std::shared_ptr<_AnimatedSlideStateCls>;

class AnimatedOpacityCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double opacity;

    bool alwaysIncludeSemantics;


     AnimatedOpacityCls(bool alwaysIncludeSemantics, Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, double opacity);

    virtual ImplicitlyAnimatedWidgetState<AnimatedOpacity> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedOpacity = std::shared_ptr<AnimatedOpacityCls>;

class _AnimatedOpacityStateCls : public ImplicitlyAnimatedWidgetStateCls<AnimatedOpacity> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

private:
    Tween<double> _opacity;

    Animation<double> _opacityAnimation;


};
using _AnimatedOpacityState = std::shared_ptr<_AnimatedOpacityStateCls>;

class SliverAnimatedOpacityCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget sliver;

    double opacity;

    bool alwaysIncludeSemantics;


     SliverAnimatedOpacityCls(bool alwaysIncludeSemantics, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, double opacity, Widget sliver);

    virtual ImplicitlyAnimatedWidgetState<SliverAnimatedOpacity> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverAnimatedOpacity = std::shared_ptr<SliverAnimatedOpacityCls>;

class _SliverAnimatedOpacityStateCls : public ImplicitlyAnimatedWidgetStateCls<SliverAnimatedOpacity> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

private:
    Tween<double> _opacity;

    Animation<double> _opacityAnimation;


};
using _SliverAnimatedOpacityState = std::shared_ptr<_SliverAnimatedOpacityStateCls>;

class AnimatedDefaultTextStyleCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    TextStyle style;

    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;


     AnimatedDefaultTextStyleCls(Widget child, Unknown curve, Unknown duration, Unknown key, int maxLines, Unknown onEnd, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis);

    virtual AnimatedWidgetBaseState<AnimatedDefaultTextStyle> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedDefaultTextStyle = std::shared_ptr<AnimatedDefaultTextStyleCls>;

class _AnimatedDefaultTextStyleStateCls : public AnimatedWidgetBaseStateCls<AnimatedDefaultTextStyle> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

private:
    TextStyleTween _style;


};
using _AnimatedDefaultTextStyleState = std::shared_ptr<_AnimatedDefaultTextStyleStateCls>;

class AnimatedPhysicalModelCls : public ImplicitlyAnimatedWidgetCls {
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


     AnimatedPhysicalModelCls(bool animateColor, bool animateShadowColor, BorderRadius borderRadius, Widget child, Clip clipBehavior, Color color, Unknown curve, Unknown duration, double elevation, Unknown key, Unknown onEnd, Color shadowColor, BoxShape shape);

    virtual AnimatedWidgetBaseState<AnimatedPhysicalModel> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedPhysicalModel = std::shared_ptr<AnimatedPhysicalModelCls>;

class _AnimatedPhysicalModelStateCls : public AnimatedWidgetBaseStateCls<AnimatedPhysicalModel> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

private:
    BorderRadiusTween _borderRadius;

    Tween<double> _elevation;

    ColorTween _color;

    ColorTween _shadowColor;


};
using _AnimatedPhysicalModelState = std::shared_ptr<_AnimatedPhysicalModelStateCls>;

class AnimatedFractionallySizedBoxCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget child;

    double heightFactor;

    double widthFactor;

    AlignmentGeometry alignment;


     AnimatedFractionallySizedBoxCls(AlignmentGeometry alignment, Widget child, Unknown curve, Unknown duration, double heightFactor, Unknown key, Unknown onEnd, double widthFactor);

    virtual AnimatedWidgetBaseState<AnimatedFractionallySizedBox> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedFractionallySizedBox = std::shared_ptr<AnimatedFractionallySizedBoxCls>;

class _AnimatedFractionallySizedBoxStateCls : public AnimatedWidgetBaseStateCls<AnimatedFractionallySizedBox> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AlignmentGeometryTween _alignment;

    Tween<double> _heightFactorTween;

    Tween<double> _widthFactorTween;


};
using _AnimatedFractionallySizedBoxState = std::shared_ptr<_AnimatedFractionallySizedBoxStateCls>;


#endif