#include "proxy_sliver.hpp"
RenderProxySliverCls::RenderProxySliverCls(RenderSliver child) {
    {
        this->child = child;
    }
}

void RenderProxySliverCls::setupParentData(RenderObject child) {
    if (!is<SliverPhysicalParentData>(child->parentData)) {
        child->parentData = make<SliverPhysicalParentDataCls>();
    }
}

void RenderProxySliverCls::performLayout() {
    assert(child != nullptr);
    child!->layout(constraints(), true);
    geometry() = child!->geometry;
}

void RenderProxySliverCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

bool RenderProxySliverCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return child != nullptr && child!->geometry!->hitTestExtent > 0 && child!->hitTest(result, mainAxisPosition, crossAxisPosition);
}

double RenderProxySliverCls::childMainAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this->child);
    return 0.0;
}

void RenderProxySliverCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    childParentData->applyPaintTransform(transform);
}

RenderSliverOpacityCls::RenderSliverOpacityCls(bool alwaysIncludeSemantics, double opacity, RenderSliver sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
        _opacity = opacity;
        _alwaysIncludeSemantics = alwaysIncludeSemantics;
        _alpha = ui->ColorCls->getAlphaFromOpacity(opacity);
    }
    {
        child = sliver;
    }
}

bool RenderSliverOpacityCls::alwaysNeedsCompositing() {
    return child != nullptr && (_alpha > 0);
}

double RenderSliverOpacityCls::opacity() {
    return _opacity;
}

void RenderSliverOpacityCls::opacity(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (_opacity == value) {
        return;
    }
    bool didNeedCompositing = alwaysNeedsCompositing();
    bool wasVisible = _alpha != 0;
    _opacity = value;
    _alpha = ui->ColorCls->getAlphaFromOpacity(_opacity);
    if (didNeedCompositing != alwaysNeedsCompositing()) {
        markNeedsCompositingBitsUpdate();
    }
    markNeedsPaint();
    if (wasVisible != (_alpha != 0) && !alwaysIncludeSemantics()) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverOpacityCls::alwaysIncludeSemantics() {
    return _alwaysIncludeSemantics;
}

void RenderSliverOpacityCls::alwaysIncludeSemantics(bool value) {
    if (value == _alwaysIncludeSemantics) {
        return;
    }
    _alwaysIncludeSemantics = value;
    markNeedsSemanticsUpdate();
}

void RenderSliverOpacityCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && child!->geometry!->visible) {
        if (_alpha == 0) {
            layer() = nullptr;
            return;
        }
        assert(needsCompositing());
        layer() = context->pushOpacity(offset, _alpha, super->paint, as<OpacityLayer>(layer()));
        assert([=] () {
            layer()!->debugCreator = debugCreator;
            return true;
        }());
    }
}

void RenderSliverOpacityCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && (_alpha != 0 || alwaysIncludeSemantics())) {
        visitor(child!);
    }
}

void RenderSliverOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("opacity"), opacity()));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics"), alwaysIncludeSemantics(), __s("alwaysIncludeSemantics")));
}

RenderSliverIgnorePointerCls::RenderSliverIgnorePointerCls(bool ignoring, bool ignoringSemantics, RenderSliver sliver) {
    {
        assert(ignoring != nullptr);
        _ignoring = ignoring;
        _ignoringSemantics = ignoringSemantics;
    }
    {
        child = sliver;
    }
}

bool RenderSliverIgnorePointerCls::ignoring() {
    return _ignoring;
}

void RenderSliverIgnorePointerCls::ignoring(bool value) {
    assert(value != nullptr);
    if (value == _ignoring) {
        return;
    }
    _ignoring = value;
    if (_ignoringSemantics == nullptr || !_ignoringSemantics!) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverIgnorePointerCls::ignoringSemantics() {
    return _ignoringSemantics;
}

void RenderSliverIgnorePointerCls::ignoringSemantics(bool value) {
    if (value == _ignoringSemantics) {
        return;
    }
    bool oldEffectiveValue = _effectiveIgnoringSemantics();
    _ignoringSemantics = value;
    if (oldEffectiveValue != _effectiveIgnoringSemantics()) {
        markNeedsSemanticsUpdate();
    }
}

bool RenderSliverIgnorePointerCls::hitTest(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return !ignoring() && super->hitTest(result, mainAxisPosition, crossAxisPosition);
}

void RenderSliverIgnorePointerCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (child != nullptr && !_effectiveIgnoringSemantics()) {
        visitor(child!);
    }
}

void RenderSliverIgnorePointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoring"), ignoring()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), _effectiveIgnoringSemantics(), ignoringSemantics() == nullptr? __s("implicitly $_effectiveIgnoringSemantics") : nullptr));
}

bool RenderSliverIgnorePointerCls::_effectiveIgnoringSemantics() {
    return ignoringSemantics() | ignoring();
}

RenderSliverOffstageCls::RenderSliverOffstageCls(bool offstage, RenderSliver sliver) {
    {
        assert(offstage != nullptr);
        _offstage = offstage;
    }
    {
        child = sliver;
    }
}

bool RenderSliverOffstageCls::offstage() {
    return _offstage;
}

void RenderSliverOffstageCls::offstage(bool value) {
    assert(value != nullptr);
    if (value == _offstage) {
        return;
    }
    _offstage = value;
    markNeedsLayoutForSizedByParentChange();
}

void RenderSliverOffstageCls::performLayout() {
    assert(child != nullptr);
    child!->layout(constraints(), true);
    if (!offstage()) {
        geometry() = child!->geometry;
    } else {
        geometry() = SliverGeometryCls::zero;
    }
}

bool RenderSliverOffstageCls::hitTest(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return !offstage() && super->hitTest(result, mainAxisPosition, crossAxisPosition);
}

bool RenderSliverOffstageCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return !offstage() && child != nullptr && child!->geometry!->hitTestExtent > 0 && child!->hitTest(result, mainAxisPosition, crossAxisPosition);
}

void RenderSliverOffstageCls::paint(PaintingContext context, Offset offset) {
    if (offstage()) {
        return;
    }
    context->paintChild(child!, offset);
}

void RenderSliverOffstageCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (offstage()) {
        return;
    }
    super->visitChildrenForSemantics(visitor);
}

void RenderSliverOffstageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("offstage"), offstage()));
}

List<DiagnosticsNode> RenderSliverOffstageCls::debugDescribeChildren() {
    if (child == nullptr) {
        return makeList();
    }
    return makeList(ArrayItem);
}

RenderSliverAnimatedOpacityCls::RenderSliverAnimatedOpacityCls(bool alwaysIncludeSemantics, Animation<double> opacity, RenderSliver sliver) {
    {
        assert(opacity != nullptr);
        assert(alwaysIncludeSemantics != nullptr);
    }
    {
        this->opacity = opacity;
        this->alwaysIncludeSemantics = alwaysIncludeSemantics;
        child = sliver;
    }
}
