#include "sliver_fill.hpp"
SliverFillViewport::SliverFillViewport(SliverChildDelegate delegate, Unknown, bool padEnds, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
        assert(padEnds != nullptr);
    }
}

Widget SliverFillViewport::build(BuildContext context) {
    return _SliverFractionalPadding(padEnds? clampDouble(1 - viewportFraction, 0, 1) / 2 : 0, _SliverFillViewportRenderObjectWidget(viewportFraction, delegate));
}

RenderSliverFillViewport _SliverFillViewportRenderObjectWidget::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = (;
    return RenderSliverFillViewport(element, viewportFraction);
}

void _SliverFillViewportRenderObjectWidget::updateRenderObject(BuildContext context, RenderSliverFillViewport renderObject) {
    renderObject.viewportFraction = viewportFraction;
}

_SliverFillViewportRenderObjectWidget::_SliverFillViewportRenderObjectWidget(Unknown, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
    }
}

RenderObject _SliverFractionalPadding::createRenderObject(BuildContext context) {
    return _RenderSliverFractionalPadding(viewportFraction);
}

void _SliverFractionalPadding::updateRenderObject(BuildContext context, _RenderSliverFractionalPadding renderObject) {
    renderObject.viewportFraction = viewportFraction;
}

_SliverFractionalPadding::_SliverFractionalPadding(Widget sliver, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction >= 0);
        assert(viewportFraction <= 0.5);
        super(sliver);
    }
}

double _RenderSliverFractionalPadding::viewportFraction() {
    return _viewportFraction;
}

void _RenderSliverFractionalPadding::viewportFraction(double newValue) {
    assert(newValue != nullptr);
    if (_viewportFraction == newValue) {
        return;
    }
    _viewportFraction = newValue;
    _markNeedsResolution();
}

EdgeInsets _RenderSliverFractionalPadding::resolvedPadding() {
    return _resolvedPadding;
}

void _RenderSliverFractionalPadding::performLayout() {
    _resolve();
    super.performLayout();
}

_RenderSliverFractionalPadding::_RenderSliverFractionalPadding(double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction <= 0.5);
        assert(viewportFraction >= 0);
        _viewportFraction = viewportFraction;
    }
}

void _RenderSliverFractionalPadding::_markNeedsResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}

void _RenderSliverFractionalPadding::_resolve() {
    if (_resolvedPadding != nullptr && _lastResolvedConstraints == constraints) {
        return;
    }
    assert(constraints.axis != nullptr);
    double paddingValue = constraints.viewportMainAxisExtent * viewportFraction;
    _lastResolvedConstraints = constraints;
    ;
    return;
}

SliverFillRemaining::SliverFillRemaining(Widget child, bool fillOverscroll, bool hasScrollBody, Unknown) {
    {
        assert(hasScrollBody != nullptr);
        assert(fillOverscroll != nullptr);
    }
}

Widget SliverFillRemaining::build(BuildContext context) {
    if (hasScrollBody) {
        return _SliverFillRemainingWithScrollable(child);
    }
    if (!fillOverscroll) {
        return _SliverFillRemainingWithoutScrollable(child);
    }
    return _SliverFillRemainingAndOverscroll(child);
}

void SliverFillRemaining::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Widget>DiagnosticsProperty("child", child));
    List<String> flags = ;
    if (flags.isEmpty) {
        flags.add("nonscrollable");
    }
    properties.add(<String>IterableProperty("mode", flags));
}

RenderSliverFillRemainingWithScrollable _SliverFillRemainingWithScrollable::createRenderObject(BuildContext context) {
    return RenderSliverFillRemainingWithScrollable();
}

RenderSliverFillRemaining _SliverFillRemainingWithoutScrollable::createRenderObject(BuildContext context) {
    return RenderSliverFillRemaining();
}

RenderSliverFillRemainingAndOverscroll _SliverFillRemainingAndOverscroll::createRenderObject(BuildContext context) {
    return RenderSliverFillRemainingAndOverscroll();
}
