#include "transitions.hpp"
AnimatedWidget::AnimatedWidget(Unknown, Listenable listenable) {
    {
        assert(listenable != nullptr);
    }
}

State<AnimatedWidget> AnimatedWidget::createState() {
    return _AnimatedState();
}

void AnimatedWidget::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Listenable>DiagnosticsProperty("animation", listenable));
}

void _AnimatedState::initState() {
    super.initState();
    widget.listenable.addListener(_handleChange);
}

void _AnimatedState::didUpdateWidget(AnimatedWidget oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.listenable != oldWidget.listenable) {
        oldWidget.listenable.removeListener(_handleChange);
        widget.listenable.addListener(_handleChange);
    }
}

void _AnimatedState::dispose() {
    widget.listenable.removeListener(_handleChange);
    super.dispose();
}

Widget _AnimatedState::build(BuildContext context) {
    return widget.build(context);
}

void _AnimatedState::_handleChange() {
    setState();
}

SlideTransition::SlideTransition(Widget child, Unknown, Animation<Offset> position, TextDirection textDirection, bool transformHitTests) {
    {
        assert(position != nullptr);
        super(position);
    }
}

Animation<Offset> SlideTransition::position() {
    return (;
}

Widget SlideTransition::build(BuildContext context) {
    Offset offset = position.value;
    if (textDirection == TextDirection.rtl) {
        offset = Offset(-offset.dx, offset.dy);
    }
    return FractionalTranslation(offset, transformHitTests, child);
}

ScaleTransition::ScaleTransition(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown, Animation<double> scale) {
    {
        assert(scale != nullptr);
        super(scale);
    }
}

Animation<double> ScaleTransition::scale() {
    return (;
}

Widget ScaleTransition::build(BuildContext context) {
    bool useFilterQuality;
    ;
    return Transform.scale(scale.value, alignment, useFilterQuality? filterQuality : nullptr, child);
}

RotationTransition::RotationTransition(Alignment alignment, Widget child, FilterQuality filterQuality, Unknown, Animation<double> turns) {
    {
        assert(turns != nullptr);
        super(turns);
    }
}

Animation<double> RotationTransition::turns() {
    return (;
}

Widget RotationTransition::build(BuildContext context) {
    bool useFilterQuality;
    ;
    return Transform.rotate(turns.value * math.pi * 2.0, alignment, useFilterQuality? filterQuality : nullptr, child);
}

SizeTransition::SizeTransition(Axis axis, double axisAlignment, Widget child, Unknown, Animation<double> sizeFactor) {
    {
        assert(axis != nullptr);
        assert(sizeFactor != nullptr);
        assert(axisAlignment != nullptr);
        super(sizeFactor);
    }
}

Animation<double> SizeTransition::sizeFactor() {
    return (;
}

Widget SizeTransition::build(BuildContext context) {
    AlignmentDirectional alignment;
    if (axis == Axis.vertical) {
        alignment = AlignmentDirectional(-1.0, axisAlignment);
    } else {
        alignment = AlignmentDirectional(axisAlignment, -1.0);
    }
    return ClipRect(Align(alignment, axis == Axis.vertical? math.max(sizeFactor.value, 0.0) : nullptr, axis == Axis.horizontal? math.max(sizeFactor.value, 0.0) : nullptr, child));
}

FadeTransition::FadeTransition(bool alwaysIncludeSemantics, Unknown, Unknown, Animation<double> opacity) {
    {
        assert(opacity != nullptr);
    }
}

RenderAnimatedOpacity FadeTransition::createRenderObject(BuildContext context) {
    return RenderAnimatedOpacity(opacity, alwaysIncludeSemantics);
}

void FadeTransition::updateRenderObject(BuildContext context, RenderAnimatedOpacity renderObject) {
    ;
}

void FadeTransition::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

SliverFadeTransition::SliverFadeTransition(bool alwaysIncludeSemantics, Unknown, Animation<double> opacity, Widget sliver) {
    {
        assert(opacity != nullptr);
        super(sliver);
    }
}

RenderSliverAnimatedOpacity SliverFadeTransition::createRenderObject(BuildContext context) {
    return RenderSliverAnimatedOpacity(opacity, alwaysIncludeSemantics);
}

void SliverFadeTransition::updateRenderObject(BuildContext context, RenderSliverAnimatedOpacity renderObject) {
    ;
}

void SliverFadeTransition::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

RelativeRect RelativeRectTween::lerp(double t) {
    return RelativeRect.lerp(begin, end, t)!;
}

PositionedTransition::PositionedTransition(Widget child, Unknown, Animation<RelativeRect> rect) {
    {
        assert(rect != nullptr);
        super(rect);
    }
}

Animation<RelativeRect> PositionedTransition::rect() {
    return (;
}

Widget PositionedTransition::build(BuildContext context) {
    return Positioned.fromRelativeRect(rect.value, child);
}

RelativePositionedTransition::RelativePositionedTransition(Widget child, Unknown, Animation<Rect> rect, Size size) {
    {
        assert(rect != nullptr);
        assert(size != nullptr);
        assert(child != nullptr);
        super(rect);
    }
}

Animation<Rect> RelativePositionedTransition::rect() {
    return (;
}

Widget RelativePositionedTransition::build(BuildContext context) {
    RelativeRect offsets = RelativeRect.fromSize(rect.value ?? Rect.zero, size);
    return Positioned(offsets.top, offsets.right, offsets.bottom, offsets.left, child);
}

DecoratedBoxTransition::DecoratedBoxTransition(Widget child, Animation<Decoration> decoration, Unknown, DecorationPosition position) {
    {
        assert(decoration != nullptr);
        assert(child != nullptr);
        super(decoration);
    }
}

Widget DecoratedBoxTransition::build(BuildContext context) {
    return DecoratedBox(decoration.value, position, child);
}

AlignTransition::AlignTransition(Animation<AlignmentGeometry> alignment, Widget child, double heightFactor, Unknown, double widthFactor) {
    {
        assert(alignment != nullptr);
        assert(child != nullptr);
        super(alignment);
    }
}

Animation<AlignmentGeometry> AlignTransition::alignment() {
    return (;
}

Widget AlignTransition::build(BuildContext context) {
    return Align(alignment.value, widthFactor, heightFactor, child);
}

DefaultTextStyleTransition::DefaultTextStyleTransition(Widget child, Unknown, int maxLines, TextOverflow overflow, bool softWrap, Animation<TextStyle> style, TextAlign textAlign) {
    {
        assert(style != nullptr);
        assert(child != nullptr);
        super(style);
    }
}

Animation<TextStyle> DefaultTextStyleTransition::style() {
    return (;
}

Widget DefaultTextStyleTransition::build(BuildContext context) {
    return DefaultTextStyle(style.value, textAlign, softWrap, overflow, maxLines, child);
}

AnimatedBuilder::AnimatedBuilder(Listenable animation, TransitionBuilder builder, Widget child, Unknown) {
    {
        assert(animation != nullptr);
        assert(builder != nullptr);
        super(animation);
    }
}

Widget AnimatedBuilder::build(BuildContext context) {
    return builder(context, child);
}
