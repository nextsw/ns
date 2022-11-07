#include "list_body.hpp"
RenderListBody::RenderListBody(AxisDirection axisDirection, List<RenderBox> children) {
    {
        assert(axisDirection != nullptr);
        _axisDirection = axisDirection;
    }
    {
        addAll(children);
    }
}

void RenderListBody::setupParentData(RenderBox child) {
    if (child.parentData is! ListBodyParentData) {
        child.parentData = ListBodyParentData();
    }
}

AxisDirection RenderListBody::axisDirection() {
    return _axisDirection;
}

void RenderListBody::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (_axisDirection == value) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

Axis RenderListBody::mainAxis() {
    return axisDirectionToAxis(axisDirection);
}

Size RenderListBody::computeDryLayout(BoxConstraints constraints) {
    assert(_debugCheckConstraints(constraints));
    double mainAxisExtent = 0.0;
    RenderBox child = firstChild;
    ;
}

void RenderListBody::performLayout() {
    BoxConstraints constraints = this.constraints;
    assert(_debugCheckConstraints(constraints));
    double mainAxisExtent = 0.0;
    RenderBox child = firstChild;
    ;
    assert(size.isFinite);
}

void RenderListBody::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
}

double RenderListBody::computeMinIntrinsicWidth(double height) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBody::computeMaxIntrinsicWidth(double height) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBody::computeMinIntrinsicHeight(double width) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBody::computeMaxIntrinsicHeight(double width) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBody::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToFirstActualBaseline(baseline);
}

void RenderListBody::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

bool RenderListBody::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

bool RenderListBody::_debugCheckConstraints(BoxConstraints constraints) {
    assert(());
    assert(());
    return true;
}

double RenderListBody::_getIntrinsicCrossAxis(_ChildSizingFunction childSize) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        extent = math.max(extent, childSize(child));
        ListBodyParentData childParentData = (;
        child = childParentData.nextSibling;
    }
    return extent;
}

double RenderListBody::_getIntrinsicMainAxis(_ChildSizingFunction childSize) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        extent = childSize(child);
        ListBodyParentData childParentData = (;
        child = childParentData.nextSibling;
    }
    return extent;
}
