#include "container.hpp"
DecoratedBox::DecoratedBox(Unknown, Decoration decoration, Unknown, DecorationPosition position) {
    {
        assert(decoration != nullptr);
        assert(position != nullptr);
    }
}

RenderDecoratedBox DecoratedBox::createRenderObject(BuildContext context) {
    return RenderDecoratedBox(decoration, position, createLocalImageConfiguration(context));
}

void DecoratedBox::updateRenderObject(BuildContext context, RenderDecoratedBox renderObject) {
    ;
}

void DecoratedBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    String label;
    ;
    properties.add(<DecorationPosition>EnumProperty("position", positionDiagnosticLevel.hidden));
    properties.add(<Decoration>DiagnosticsProperty(label, decoration));
}

Container::Container(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Decoration decoration, Decoration foregroundDecoration, double height, Unknown, EdgeInsetsGeometry margin, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width) {
    {
        assert(margin == nullptr || margin.isNonNegative);
        assert(padding == nullptr || padding.isNonNegative);
        assert(decoration == nullptr || decoration.debugAssertIsValid());
        assert(constraints == nullptr || constraints.debugAssertIsValid());
        assert(clipBehavior != nullptr);
        assert(decoration != nullptr || clipBehavior == Clip.none);
        assert(color == nullptr || decoration == nullptr, "Cannot provide both a color and a decoration\nTo provide both, use "decoration: BoxDecoration(color: color)".");
        constraints = (width != nullptr || height != nullptr)? constraints?.tighten(width, height) ?? BoxConstraints.tightFor(width, height) : constraints;
    }
}

Widget Container::build(BuildContext context) {
    Widget current = child;
    if (child == nullptr && (constraints == nullptr || !constraints!.isTight)) {
        current = LimitedBox(0.0, 0.0, ConstrainedBox(const BoxConstraints.expand()));
    } else     {
        if (alignment != nullptr) {
        current = Align(alignment!, current);
    }
;
    }    EdgeInsetsGeometry effectivePadding = _paddingIncludingDecoration;
    if (effectivePadding != nullptr) {
        current = Padding(effectivePadding, current);
    }
    if (color != nullptr) {
        current = ColoredBox(color!, current);
    }
    if (clipBehavior != Clip.none) {
        assert(decoration != nullptr);
        current = ClipPath(_DecorationClipper(Directionality.maybeOf(context), decoration!), clipBehavior, current);
    }
    if (decoration != nullptr) {
        current = DecoratedBox(decoration!, current);
    }
    if (foregroundDecoration != nullptr) {
        current = DecoratedBox(foregroundDecoration!, DecorationPosition.foreground, current);
    }
    if (constraints != nullptr) {
        current = ConstrainedBox(constraints!, current);
    }
    if (margin != nullptr) {
        current = Padding(margin!, current);
    }
    if (transform != nullptr) {
        current = Transform(transform!, transformAlignment, current);
    }
    return current!;
}

void Container::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentfalse, nullptr));
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", paddingnullptr));
    properties.add(<Clip>DiagnosticsProperty("clipBehavior", clipBehaviorClip.none));
    if (color != nullptr) {
        properties.add(<Color>DiagnosticsProperty("bg", color));
    } else {
        properties.add(<Decoration>DiagnosticsProperty("bg", decorationnullptr));
    }
    properties.add(<Decoration>DiagnosticsProperty("fg", foregroundDecorationnullptr));
    properties.add(<BoxConstraints>DiagnosticsProperty("constraints", constraintsnullptr));
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("margin", marginnullptr));
    properties.add(<Matrix4>has("transform", transform));
}

EdgeInsetsGeometry Container::_paddingIncludingDecoration() {
    if (decoration == nullptr || decoration!.padding == nullptr) {
        return padding;
    }
    EdgeInsetsGeometry decorationPadding = decoration!.padding;
    if (padding == nullptr) {
        return decorationPadding;
    }
    return padding!.add(decorationPadding!);
}

Path _DecorationClipper::getClip(Size size) {
    return decoration.getClipPath(Offset.zero & size, textDirection);
}

bool _DecorationClipper::shouldReclip(_DecorationClipper oldClipper) {
    return oldClipper.decoration != decoration || oldClipper.textDirection != textDirection;
}

_DecorationClipper::_DecorationClipper(Decoration decoration, TextDirection textDirection) {
    {
        assert(decoration != nullptr);
        textDirection = textDirection ?? TextDirection.ltr;
    }
}
