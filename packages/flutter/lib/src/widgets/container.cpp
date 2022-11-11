#include "container.hpp"
DecoratedBoxCls::DecoratedBoxCls(Unknown child, Decoration decoration, Unknown key, DecorationPosition position) {
    {
        assert(decoration != nullptr);
        assert(position != nullptr);
    }
}

RenderDecoratedBox DecoratedBoxCls::createRenderObject(BuildContext context) {
    return make<RenderDecoratedBoxCls>(decoration, position, createLocalImageConfiguration(context));
}

void DecoratedBoxCls::updateRenderObject(BuildContext context, RenderDecoratedBox renderObject) {
    auto _c1 = renderObject;_c1.decoration = auto _c2 = decoration;_c2.configuration = auto _c3 = createLocalImageConfiguration(context);_c3.position = position;_c3;_c2;_c1;
}

void DecoratedBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    String label;
    ;
    properties->add(<DecorationPosition>make<EnumPropertyCls>(__s("position"), position, DiagnosticLevelCls::hidden));
    properties->add(<Decoration>make<DiagnosticsPropertyCls>(label, decoration));
}

ContainerCls::ContainerCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Decoration decoration, Decoration foregroundDecoration, double height, Unknown key, EdgeInsetsGeometry margin, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width) {
    {
        assert(margin == nullptr || margin->isNonNegative());
        assert(padding == nullptr || padding->isNonNegative());
        assert(decoration == nullptr || decoration->debugAssertIsValid());
        assert(constraints == nullptr || constraints->debugAssertIsValid());
        assert(clipBehavior != nullptr);
        assert(decoration != nullptr || clipBehavior == ClipCls::none);
        assert(color == nullptr || decoration == nullptr, __s("Cannot provide both a color and a decoration\nTo provide both, use "decoration: BoxDecoration(color: color)"."));
        constraints = (width != nullptr || height != nullptr)? constraints?->tighten(width, height) | BoxConstraintsCls->tightFor(width, height) : constraints;
    }
}

Widget ContainerCls::build(BuildContext context) {
    Widget current = child;
    if (child == nullptr && (constraints == nullptr || !constraints!->isTight())) {
        current = make<LimitedBoxCls>(0.0, 0.0, make<ConstrainedBoxCls>(BoxConstraintsCls->expand()));
    } else     {
        if (alignment != nullptr) {
        current = make<AlignCls>(alignment!, current);
    }
;
    }    EdgeInsetsGeometry effectivePadding = _paddingIncludingDecoration();
    if (effectivePadding != nullptr) {
        current = make<PaddingCls>(effectivePadding, current);
    }
    if (color != nullptr) {
        current = make<ColoredBoxCls>(color!, current);
    }
    if (clipBehavior != ClipCls::none) {
        assert(decoration != nullptr);
        current = make<ClipPathCls>(make<_DecorationClipperCls>(DirectionalityCls->maybeOf(context), decoration!), clipBehavior, current);
    }
    if (decoration != nullptr) {
        current = make<DecoratedBoxCls>(decoration!, current);
    }
    if (foregroundDecoration != nullptr) {
        current = make<DecoratedBoxCls>(foregroundDecoration!, DecorationPositionCls::foreground, current);
    }
    if (constraints != nullptr) {
        current = make<ConstrainedBoxCls>(constraints!, current);
    }
    if (margin != nullptr) {
        current = make<PaddingCls>(margin!, current);
    }
    if (transform != nullptr) {
        current = make<TransformCls>(transform!, transformAlignment, current);
    }
    return current!;
}

void ContainerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, false, nullptr));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding, nullptr));
    properties->add(<Clip>make<DiagnosticsPropertyCls>(__s("clipBehavior"), clipBehavior, ClipCls::none));
    if (color != nullptr) {
        properties->add(<Color>make<DiagnosticsPropertyCls>(__s("bg"), color));
    } else {
        properties->add(<Decoration>make<DiagnosticsPropertyCls>(__s("bg"), decoration, nullptr));
    }
    properties->add(<Decoration>make<DiagnosticsPropertyCls>(__s("fg"), foregroundDecoration, nullptr));
    properties->add(<BoxConstraints>make<DiagnosticsPropertyCls>(__s("constraints"), constraints, nullptr));
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("margin"), margin, nullptr));
    properties->add(<Matrix4>has(__s("transform"), transform));
}

EdgeInsetsGeometry ContainerCls::_paddingIncludingDecoration() {
    if (decoration == nullptr || decoration!->padding == nullptr) {
        return padding;
    }
    EdgeInsetsGeometry decorationPadding = decoration!->padding;
    if (padding == nullptr) {
        return decorationPadding;
    }
    return padding!->add(decorationPadding!);
}

Path _DecorationClipperCls::getClip(Size size) {
    return decoration->getClipPath(OffsetCls::zero & size, textDirection);
}

bool _DecorationClipperCls::shouldReclip(_DecorationClipper oldClipper) {
    return oldClipper->decoration != decoration || oldClipper->textDirection != textDirection;
}

_DecorationClipperCls::_DecorationClipperCls(Decoration decoration, TextDirection textDirection) {
    {
        assert(decoration != nullptr);
        textDirection = textDirection | TextDirectionCls::ltr;
    }
}
