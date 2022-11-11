#include "transitions.hpp"
AnimatedWidgetCls::AnimatedWidgetCls(Unknown key, Listenable listenable) {
    {
        assert(listenable != nullptr);
    }
}

State<AnimatedWidget> AnimatedWidgetCls::createState() {
    return make<_AnimatedStateCls>();
}

void AnimatedWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Listenable>make<DiagnosticsPropertyCls>(__s("animation"), listenable));
}

void _AnimatedStateCls::initState() {
    super->initState();
    widget->listenable->addListener(_handleChange);
}

void _AnimatedStateCls::didUpdateWidget(AnimatedWidget oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->listenable != oldWidget->listenable) {
        oldWidget->listenable->removeListener(_handleChange);
        widget->listenable->addListener(_handleChange);
    }
}

void _AnimatedStateCls::dispose() {
    widget->listenable->removeListener(_handleChange);
    super->dispose();
}

Widget _AnimatedStateCls::build(BuildContext context) {
    return widget->build(context);
}

void _AnimatedStateCls::_handleChange() {
    setState([=] () {
    });
}

SlideTransitionCls::SlideTransitionCls(Widget child, Unknown key, Animation<Offset> position, TextDirection textDirection, bool transformHitTests) : AnimatedWidget(position) {
    {
        assert(position != nullptr);
    }
}

Animation<Offset> SlideTransitionCls::position() {
    return as<Animation<Offset>>(listenable);
}

Widget SlideTransitionCls::build(BuildContext context) {
    Offset offset = position->value;
    if (textDirection == TextDirectionCls::rtl) {
        offset = make<OffsetCls>(-offset->dx, offset->dy);
    }
    return make<FractionalTranslationCls>(offset, transformHitTests, child);
}

ScaleTransitionCls::ScaleTransitionCls(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown key, Animation<double> scale) : AnimatedWidget(scale) {
    {
        assert(scale != nullptr);
    }
}

Animation<double> ScaleTransitionCls::scale() {
    return as<Animation<double>>(listenable);
}

Widget ScaleTransitionCls::build(BuildContext context) {
    bool useFilterQuality;
    ;
    return TransformCls->scale(scale->value, alignment, useFilterQuality? filterQuality : nullptr, child);
}

RotationTransitionCls::RotationTransitionCls(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown key, Animation<double> turns) : AnimatedWidget(turns) {
    {
        assert(turns != nullptr);
    }
}

Animation<double> RotationTransitionCls::turns() {
    return as<Animation<double>>(listenable);
}

Widget RotationTransitionCls::build(BuildContext context) {
    bool useFilterQuality;
    ;
    return TransformCls->rotate(turns->value * math->pi * 2.0, alignment, useFilterQuality? filterQuality : nullptr, child);
}

SizeTransitionCls::SizeTransitionCls(Axis axis, double axisAlignment, Widget child, Unknown key, Animation<double> sizeFactor) : AnimatedWidget(sizeFactor) {
    {
        assert(axis != nullptr);
        assert(sizeFactor != nullptr);
        assert(axisAlignment != nullptr);
    }
}

Animation<double> SizeTransitionCls::sizeFactor() {
    return as<Animation<double>>(listenable);
}

Widget SizeTransitionCls::build(BuildContext context) {
    AlignmentDirectional alignment;
    if (axis == AxisCls::vertical) {
        alignment = make<AlignmentDirectionalCls>(-1.0, axisAlignment);
    } else {
        alignment = make<AlignmentDirectionalCls>(axisAlignment, -1.0);
    }
    return make<ClipRectCls>(make<AlignCls>(alignment, axis == AxisCls::vertical? math->max(sizeFactor->value, 0.0) : nullptr, axis == AxisCls::horizontal? math->max(sizeFactor->value, 0.0) : nullptr, child));
}

FadeTransitionCls::FadeTransitionCls(bool alwaysIncludeSemantics, Unknown child, Unknown key, Animation<double> opacity) {
    {
        assert(opacity != nullptr);
    }
}

RenderAnimatedOpacity FadeTransitionCls::createRenderObject(BuildContext context) {
    return make<RenderAnimatedOpacityCls>(opacity, alwaysIncludeSemantics);
}

void FadeTransitionCls::updateRenderObject(BuildContext context, RenderAnimatedOpacity renderObject) {
    auto _c1 = renderObject;_c1.opacity = auto _c2 = opacity;_c2.alwaysIncludeSemantics = alwaysIncludeSemantics;_c2;_c1;
}

void FadeTransitionCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacity));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics")alwaysIncludeSemantics, __s("alwaysIncludeSemantics")));
}

SliverFadeTransitionCls::SliverFadeTransitionCls(bool alwaysIncludeSemantics, Unknown key, Animation<double> opacity, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(opacity != nullptr);
    }
}

RenderSliverAnimatedOpacity SliverFadeTransitionCls::createRenderObject(BuildContext context) {
    return make<RenderSliverAnimatedOpacityCls>(opacity, alwaysIncludeSemantics);
}

void SliverFadeTransitionCls::updateRenderObject(BuildContext context, RenderSliverAnimatedOpacity renderObject) {
    auto _c1 = renderObject;_c1.opacity = auto _c2 = opacity;_c2.alwaysIncludeSemantics = alwaysIncludeSemantics;_c2;_c1;
}

void SliverFadeTransitionCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacity));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics")alwaysIncludeSemantics, __s("alwaysIncludeSemantics")));
}

RelativeRect RelativeRectTweenCls::lerp(double t) {
    return RelativeRectCls->lerp(begin, end, t)!;
}

PositionedTransitionCls::PositionedTransitionCls(Widget child, Unknown key, Animation<RelativeRect> rect) : AnimatedWidget(rect) {
    {
        assert(rect != nullptr);
    }
}

Animation<RelativeRect> PositionedTransitionCls::rect() {
    return as<Animation<RelativeRect>>(listenable);
}

Widget PositionedTransitionCls::build(BuildContext context) {
    return PositionedCls->fromRelativeRect(rect->value, child);
}

RelativePositionedTransitionCls::RelativePositionedTransitionCls(Widget child, Unknown key, Animation<Rect> rect, Size size) : AnimatedWidget(rect) {
    {
        assert(rect != nullptr);
        assert(size != nullptr);
        assert(child != nullptr);
    }
}

Animation<Rect> RelativePositionedTransitionCls::rect() {
    return as<Animation<Rect>>(listenable);
}

Widget RelativePositionedTransitionCls::build(BuildContext context) {
    RelativeRect offsets = RelativeRectCls->fromSize(rect->value or RectCls::zero, size);
    return make<PositionedCls>(offsets->top, offsets->right, offsets->bottom, offsets->left, child);
}

DecoratedBoxTransitionCls::DecoratedBoxTransitionCls(Widget child, Animation<Decoration> decoration, Unknown key, DecorationPosition position) : AnimatedWidget(decoration) {
    {
        assert(decoration != nullptr);
        assert(child != nullptr);
    }
}

Widget DecoratedBoxTransitionCls::build(BuildContext context) {
    return make<DecoratedBoxCls>(decoration->value, position, child);
}

AlignTransitionCls::AlignTransitionCls(Animation<AlignmentGeometry> alignment, Widget child, double heightFactor, Unknown key, double widthFactor) : AnimatedWidget(alignment) {
    {
        assert(alignment != nullptr);
        assert(child != nullptr);
    }
}

Animation<AlignmentGeometry> AlignTransitionCls::alignment() {
    return as<Animation<AlignmentGeometry>>(listenable);
}

Widget AlignTransitionCls::build(BuildContext context) {
    return make<AlignCls>(alignment->value, widthFactor, heightFactor, child);
}

DefaultTextStyleTransitionCls::DefaultTextStyleTransitionCls(Widget child, Unknown key, int maxLines, TextOverflow overflow, bool softWrap, Animation<TextStyle> style, TextAlign textAlign) : AnimatedWidget(style) {
    {
        assert(style != nullptr);
        assert(child != nullptr);
    }
}

Animation<TextStyle> DefaultTextStyleTransitionCls::style() {
    return as<Animation<TextStyle>>(listenable);
}

Widget DefaultTextStyleTransitionCls::build(BuildContext context) {
    return make<DefaultTextStyleCls>(style->value, textAlign, softWrap, overflow, maxLines, child);
}

AnimatedBuilderCls::AnimatedBuilderCls(Listenable animation, TransitionBuilder builder, Widget child, Unknown key) : AnimatedWidget(animation) {
    {
        assert(animation != nullptr);
        assert(builder != nullptr);
    }
}

Widget AnimatedBuilderCls::build(BuildContext context) {
    return builder(context, child);
}
