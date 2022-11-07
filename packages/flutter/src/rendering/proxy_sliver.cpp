#include "proxy_sliver.hpp"
RenderProxySliver::RenderProxySliver(RenderSliver child) {
    {
        this.child = child;
    }
}

void RenderProxySliver::setupParentData(RenderObject child) {
    if (child.parentData is! SliverPhysicalParentData) {
        child.parentData = SliverPhysicalParentData();
    }
}

void RenderProxySliver::performLayout() {
    assert(child != nullptr);
    child!.layout(constraintstrue);
    geometry = child!.geometry;
}

void RenderProxySliver::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

bool RenderProxySliver::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return child != nullptr && child!.geometry!.hitTestExtent > 0 && child!.hitTest(resultmainAxisPosition, crossAxisPosition);
}

double RenderProxySliver::childMainAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this.child);
    return 0.0;
}

void RenderProxySliver::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    SliverPhysicalParentData childParentData = (;
    childParentData.applyPaintTransform(transform);
}

RenderSliverOpacity::RenderSliverOpacity(bool alwaysIncludeSemantics, double opacity, RenderSliver sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
        _opacity = opacity;
        _alwaysIncludeSemantics = alwaysIncludeSemantics;
        _alpha = ui.Color.getAlphaFromOpacity(opacity);
    }
    {
        child = sliver;
    }
}

bool RenderSliverOpacity::alwaysNeedsCompositing() {
    return child != nullptr && (_alpha > 0);
}

double RenderSliverOpacity::opacity() {
    return _opacity;
}

void RenderSliverOpacity::opacity(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (_opacity == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing;
    bool wasVisible = _alpha != 0;
    _opacity = value;
    _alpha = ui.Color.getAlphaFromOpacity(_opacity);
    if (didNeedCompositing != alwaysNeedsCompositing) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
    if (wasVisible != (_alpha != 0) && !alwaysIncludeSemantics) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverOpacity::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics;
}

void RenderSliverOpacity::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

void RenderSliverOpacity::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && child!.geometry!.visible) {
        if (_alpha == 0) {
            layer = nullptr;
            return;
        }
        assert(needsCompositing);
        layer = context.pushOpacity(offset, _alpha, super.paint();
        assert(());
    }
}

void RenderSliverOpacity::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics)) {
        visitor(child!);
    }
}

void RenderSliverOpacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

RenderSliverIgnorePointer::RenderSliverIgnorePointer(bool ignoring, bool ignoringSemantics, RenderSliver sliver) {
    {
        assert(ignoring != nullptr);
        _ignoring = ignoring;
        _ignoringSemantics = ignoringSemantics;
    }
    {
        child = sliver;
    }
}

bool RenderSliverIgnorePointer::ignoring() {
    return _ignoring;
}

void RenderSliverIgnorePointer::ignoring(bool value) {
    assert(value != nullptr);
    if (value == _ignoring) {
        return;
    }
    _ignoring = value;
    if (_ignoringSemantics == nullptr || !_ignoringSemantics!) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverIgnorePointer::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderSliverIgnorePointer::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics;
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverIgnorePointer::hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return !ignoring && super.hitTest(resultmainAxisPosition, crossAxisPosition);
}

void RenderSliverIgnorePointer::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics) {
        visitor(child!);
    }
}

void RenderSliverIgnorePointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("ignoring", ignoring));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", _effectiveIgnoringSemanticsignoringSemantics == nullptr? "implicitly $_effectiveIgnoringSemantics" : nullptr));
}

bool RenderSliverIgnorePointer::_effectiveIgnoringSemantics() {
    return ignoringSemantics ?? ignoring;
}

RenderSliverOffstage::RenderSliverOffstage(bool offstage, RenderSliver sliver) {
    {
        assert(offstage != nullptr);
        _offstage = offstage;
    }
    {
        child = sliver;
    }
}

bool RenderSliverOffstage::offstage() {
    return _offstage;
}

void RenderSliverOffstage::offstage(bool value) {
    assert(value != nullptr);
    if (value == _offstage) {
        return;
    }
    _offstage = value;
    markNeedsLayoutForSizedByParentChange();
}

void RenderSliverOffstage::performLayout() {
    assert(child != nullptr);
    child!.layout(constraintstrue);
    if (!offstage) {
        geometry = child!.geometry;
    } else {
        geometry = SliverGeometry.zero;
    }
}

bool RenderSliverOffstage::hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return !offstage && super.hitTest(resultmainAxisPosition, crossAxisPosition);
}

bool RenderSliverOffstage::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return !offstage && child != nullptr && child!.geometry!.hitTestExtent > 0 && child!.hitTest(resultmainAxisPosition, crossAxisPosition);
}

void RenderSliverOffstage::paint(PaintingContext context, Offset offset) {
    if (offstage) {
        return;
    }
    context.paintChild(child!, offset);
}

void RenderSliverOffstage::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (offstage) {
        return;
    }
    super.visitChildrenForSemantics(visitor);
}

void RenderSliverOffstage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("offstage", offstage));
}

List<DiagnosticsNode> RenderSliverOffstage::debugDescribeChildren() {
    if (child == nullptr) {
        return ;
    }
    return ;
}

RenderSliverAnimatedOpacity::RenderSliverAnimatedOpacity(bool alwaysIncludeSemantics, Animation<double> opacity, RenderSliver sliver) {
    {
        assert(opacity != nullptr);
        assert(alwaysIncludeSemantics != nullptr);
    }
    {
        this.opacity = opacity;
        this.alwaysIncludeSemantics = alwaysIncludeSemantics;
        child = sliver;
    }
}
