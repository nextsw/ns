#include "list_body.hpp"
RenderListBodyCls::RenderListBodyCls(AxisDirection axisDirection, List<RenderBox> children) {
    {
        assert(axisDirection != nullptr);
        _axisDirection = axisDirection;
    }
    {
        addAll(children);
    }
}

void RenderListBodyCls::setupParentData(RenderBox child) {
    if (child->parentData is! ListBodyParentData) {
        child->parentData = make<ListBodyParentDataCls>();
    }
}

AxisDirection RenderListBodyCls::axisDirection() {
    return _axisDirection;
}

void RenderListBodyCls::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (_axisDirection == value) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

Axis RenderListBodyCls::mainAxis() {
    return axisDirectionToAxis(axisDirection);
}

Size RenderListBodyCls::computeDryLayout(BoxConstraints constraints) {
    assert(_debugCheckConstraints(constraints));
    double mainAxisExtent = 0.0;
    RenderBox child = firstChild;
    ;
}

void RenderListBodyCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    assert(_debugCheckConstraints(constraints));
    double mainAxisExtent = 0.0;
    RenderBox child = firstChild;
    ;
    assert(size->isFinite);
}

void RenderListBodyCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>("axisDirection", axisDirection));
}

double RenderListBodyCls::computeMinIntrinsicWidth(double height) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBodyCls::computeMaxIntrinsicWidth(double height) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBodyCls::computeMinIntrinsicHeight(double width) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBodyCls::computeMaxIntrinsicHeight(double width) {
    assert(mainAxis != nullptr);
    ;
}

double RenderListBodyCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToFirstActualBaseline(baseline);
}

void RenderListBodyCls::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

bool RenderListBodyCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

bool RenderListBodyCls::_debugCheckConstraints(BoxConstraints constraints) {
    assert([=] () {
        ;
        ;
    }());
    assert([=] () {
        ;
        ;
    }());
    return true;
}

double RenderListBodyCls::_getIntrinsicCrossAxis(_ChildSizingFunction childSize) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        extent = math->max(extent, childSize(child));
        ListBodyParentData childParentData = ((ListBodyParentData)child->parentData!);
        child = childParentData->nextSibling;
    }
    return extent;
}

double RenderListBodyCls::_getIntrinsicMainAxis(_ChildSizingFunction childSize) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        extent = childSize(child);
        ListBodyParentData childParentData = ((ListBodyParentData)child->parentData!);
        child = childParentData->nextSibling;
    }
    return extent;
}
