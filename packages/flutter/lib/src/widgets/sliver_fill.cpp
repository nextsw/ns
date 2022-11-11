#include "sliver_fill.hpp"
SliverFillViewportCls::SliverFillViewportCls(SliverChildDelegate delegate, Unknown key, bool padEnds, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
        assert(padEnds != nullptr);
    }
}

Widget SliverFillViewportCls::build(BuildContext context) {
    return make<_SliverFractionalPaddingCls>(padEnds? clampDouble(1 - viewportFraction, 0, 1) / 2 : 0, make<_SliverFillViewportRenderObjectWidgetCls>(viewportFraction, delegate));
}

RenderSliverFillViewport _SliverFillViewportRenderObjectWidgetCls::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = as<SliverMultiBoxAdaptorElement>(context);
    return make<RenderSliverFillViewportCls>(element, viewportFraction);
}

void _SliverFillViewportRenderObjectWidgetCls::updateRenderObject(BuildContext context, RenderSliverFillViewport renderObject) {
    renderObject->viewportFraction = viewportFraction;
}

_SliverFillViewportRenderObjectWidgetCls::_SliverFillViewportRenderObjectWidgetCls(Unknown delegate, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
    }
}

RenderObject _SliverFractionalPaddingCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverFractionalPaddingCls>(viewportFraction);
}

void _SliverFractionalPaddingCls::updateRenderObject(BuildContext context, _RenderSliverFractionalPadding renderObject) {
    renderObject->viewportFraction = viewportFraction;
}

_SliverFractionalPaddingCls::_SliverFractionalPaddingCls(Widget sliver, double viewportFraction) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction >= 0);
        assert(viewportFraction <= 0.5);
    }
}

double _RenderSliverFractionalPaddingCls::viewportFraction() {
    return _viewportFraction;
}

void _RenderSliverFractionalPaddingCls::viewportFraction(double newValue) {
    assert(newValue != nullptr);
    if (_viewportFraction == newValue) {
        return;
    }
    _viewportFraction = newValue;
    _markNeedsResolution();
}

EdgeInsets _RenderSliverFractionalPaddingCls::resolvedPadding() {
    return _resolvedPadding;
}

void _RenderSliverFractionalPaddingCls::performLayout() {
    _resolve();
    super->performLayout();
}

_RenderSliverFractionalPaddingCls::_RenderSliverFractionalPaddingCls(double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction <= 0.5);
        assert(viewportFraction >= 0);
        _viewportFraction = viewportFraction;
    }
}

void _RenderSliverFractionalPaddingCls::_markNeedsResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}

void _RenderSliverFractionalPaddingCls::_resolve() {
    if (_resolvedPadding != nullptr && _lastResolvedConstraints == constraints) {
        return;
    }
    assert(constraints->axis != nullptr);
    double paddingValue = constraints->viewportMainAxisExtent * viewportFraction();
    _lastResolvedConstraints = constraints;
    ;
    return;
}

SliverFillRemainingCls::SliverFillRemainingCls(Widget child, bool fillOverscroll, bool hasScrollBody, Unknown key) {
    {
        assert(hasScrollBody != nullptr);
        assert(fillOverscroll != nullptr);
    }
}

Widget SliverFillRemainingCls::build(BuildContext context) {
    if (hasScrollBody) {
        return make<_SliverFillRemainingWithScrollableCls>(child);
    }
    if (!fillOverscroll) {
        return make<_SliverFillRemainingWithoutScrollableCls>(child);
    }
    return make<_SliverFillRemainingAndOverscrollCls>(child);
}

void SliverFillRemainingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Widget>make<DiagnosticsPropertyCls>(__s("child"), child));
    List<String> list1 = make<ListCls<>>();if (hasScrollBody) {    list1.add(ArrayItem);}if (fillOverscroll) {    list1.add(ArrayItem);}List<String> flags = list1;
    if (flags->isEmpty) {
        flags->add(__s("nonscrollable"));
    }
    properties->add(<String>make<IterablePropertyCls>(__s("mode"), flags));
}

RenderSliverFillRemainingWithScrollable _SliverFillRemainingWithScrollableCls::createRenderObject(BuildContext context) {
    return make<RenderSliverFillRemainingWithScrollableCls>();
}

RenderSliverFillRemaining _SliverFillRemainingWithoutScrollableCls::createRenderObject(BuildContext context) {
    return make<RenderSliverFillRemainingCls>();
}

RenderSliverFillRemainingAndOverscroll _SliverFillRemainingAndOverscrollCls::createRenderObject(BuildContext context) {
    return make<RenderSliverFillRemainingAndOverscrollCls>();
}
