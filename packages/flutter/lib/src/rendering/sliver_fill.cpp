#include "sliver_fill.hpp"
RenderSliverFillViewportCls::RenderSliverFillViewportCls(Unknown childManager, double viewportFraction) {
    {
        assert(viewportFraction != nullptr);
        assert(viewportFraction > 0.0);
        _viewportFraction = viewportFraction;
    }
}

double RenderSliverFillViewportCls::itemExtent() {
    return constraints->viewportMainAxisExtent * viewportFraction();
}

double RenderSliverFillViewportCls::viewportFraction() {
    return _viewportFraction;
}

void RenderSliverFillViewportCls::viewportFraction(double value) {
    assert(value != nullptr);
    if (_viewportFraction == value) {
        return;
    }
    _viewportFraction = value;
    markNeedsLayout();
}

void RenderSliverFillRemainingWithScrollableCls::performLayout() {
    SliverConstraints constraints = this->constraints;
    double extent = constraints->remainingPaintExtent - math->min(constraints->overlap, 0.0);
    if (child != nullptr) {
        child!->layout(constraints->asBoxConstraints(extent, extent));
    }
    double paintedChildSize = calculatePaintOffset(constraints0.0, extent);
    assert(paintedChildSize->isFinite);
    assert(paintedChildSize >= 0.0);
    geometry = make<SliverGeometryCls>(constraints->viewportMainAxisExtent, paintedChildSize, paintedChildSize, extent > constraints->remainingPaintExtent || constraints->scrollOffset > 0.0);
    if (child != nullptr) {
        setChildParentData(child!, constraints, geometry!);
    }
}

void RenderSliverFillRemainingCls::performLayout() {
    SliverConstraints constraints = this->constraints;
    double extent = constraints->viewportMainAxisExtent - constraints->precedingScrollExtent;
    if (child != nullptr) {
        double childExtent;
        ;
        extent = math->max(extent, childExtent);
        child!->layout(constraints->asBoxConstraints(extent, extent));
    }
    assert(extent->isFinite, __s("The calculated extent for the child of SliverFillRemaining is not finite. This can happen if the child is a scrollable, in which case, the hasScrollBody property of SliverFillRemaining should not be set to false."));
    double paintedChildSize = calculatePaintOffset(constraints0.0, extent);
    assert(paintedChildSize->isFinite);
    assert(paintedChildSize >= 0.0);
    geometry = make<SliverGeometryCls>(extent, paintedChildSize, paintedChildSize, extent > constraints->remainingPaintExtent || constraints->scrollOffset > 0.0);
    if (child != nullptr) {
        setChildParentData(child!, constraints, geometry!);
    }
}

void RenderSliverFillRemainingAndOverscrollCls::performLayout() {
    SliverConstraints constraints = this->constraints;
    double extent = constraints->viewportMainAxisExtent - constraints->precedingScrollExtent;
    double maxExtent = constraints->remainingPaintExtent - math->min(constraints->overlap, 0.0);
    if (child != nullptr) {
        double childExtent;
        ;
        extent = math->max(extent, childExtent);
        maxExtent = math->max(extent, maxExtent);
        child!->layout(constraints->asBoxConstraints(extent, maxExtent));
    }
    assert(extent->isFinite, __s("The calculated extent for the child of SliverFillRemaining is not finite. This can happen if the child is a scrollable, in which case, the hasScrollBody property of SliverFillRemaining should not be set to false."));
    double paintedChildSize = calculatePaintOffset(constraints0.0, extent);
    assert(paintedChildSize->isFinite);
    assert(paintedChildSize >= 0.0);
    geometry = make<SliverGeometryCls>(extent, math->min(maxExtent, constraints->remainingPaintExtent), maxExtent, extent > constraints->remainingPaintExtent || constraints->scrollOffset > 0.0);
    if (child != nullptr) {
        setChildParentData(child!, constraints, geometry!);
    }
}
