#include "flow.hpp"
FlowDelegateCls::FlowDelegateCls(Listenable repaint) {
    {
        _repaint = repaint;
    }
}

Size FlowDelegateCls::getSize(BoxConstraints constraints) {
    return constraints->biggest();
}

BoxConstraints FlowDelegateCls::getConstraintsForChild(BoxConstraints constraints, int i) {
    return constraints;
}

bool FlowDelegateCls::shouldRelayout(FlowDelegate oldDelegate) {
    return false;
}

String FlowDelegateCls::toString() {
    return objectRuntimeType(this, __s("FlowDelegate"));
}

RenderFlowCls::RenderFlowCls(List<RenderBox> children, Clip clipBehavior, FlowDelegate delegate) {
    {
        assert(delegate != nullptr);
        assert(clipBehavior != nullptr);
        _delegate = delegate;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

void RenderFlowCls::setupParentData(RenderBox child) {
    ParentData childParentData = child->parentData;
    if (is<FlowParentData>(childParentData)) {
        as<FlowParentDataCls>(childParentData)->_transform = nullptr;
    } else {
        child->parentData = make<FlowParentDataCls>();
    }
}

FlowDelegate RenderFlowCls::delegate() {
    return _delegate;
}

void RenderFlowCls::delegate(FlowDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    FlowDelegate oldDelegate = _delegate;
    _delegate = newDelegate;
    if (newDelegate->runtimeType != oldDelegate->runtimeType || newDelegate->shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    } else     {
        if (newDelegate->shouldRepaint(oldDelegate)) {
        markNeedsPaint();
    }
;
    }    if (attached) {
        oldDelegate->_repaint?->removeListener(markNeedsPaint);
        newDelegate->_repaint?->addListener(markNeedsPaint);
    }
}

Clip RenderFlowCls::clipBehavior() {
    return _clipBehavior;
}

void RenderFlowCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFlowCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _delegate->_repaint?->addListener(markNeedsPaint);
}

void RenderFlowCls::detach() {
    _delegate->_repaint?->removeListener(markNeedsPaint);
    super->detach();
}

bool RenderFlowCls::isRepaintBoundary() {
    return true;
}

double RenderFlowCls::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width;
    if (width->isFinite) {
        return width;
    }
    return 0.0;
}

double RenderFlowCls::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width;
    if (width->isFinite) {
        return width;
    }
    return 0.0;
}

double RenderFlowCls::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height;
    if (height->isFinite) {
        return height;
    }
    return 0.0;
}

double RenderFlowCls::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height;
    if (height->isFinite) {
        return height;
    }
    return 0.0;
}

Size RenderFlowCls::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderFlowCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    size = _getSize(constraints);
    int i = 0;
    _randomAccessChildren->clear();
    RenderBox child = firstChild;
    while (child != nullptr) {
        _randomAccessChildren->add(child);
        BoxConstraints innerConstraints = _delegate->getConstraintsForChild(i, constraints);
        child->layout(innerConstraintstrue);
        FlowParentData childParentData = as<FlowParentData>(child->parentData!);
        childParentData->offset = OffsetCls::zero;
        child = childParentData->nextSibling;
        i = 1;
    }
}

Size RenderFlowCls::getChildSize(int i) {
    if ( < 0 || i >= _randomAccessChildren->length) {
        return nullptr;
    }
    return _randomAccessChildren[i]->size;
}

void RenderFlowCls::paintChild(int i, double opacity, Matrix4 transform) {
    transform = Matrix4Cls->identity();
    RenderBox child = _randomAccessChildren[i];
    FlowParentData childParentData = as<FlowParentData>(child->parentData!);
    assert([=] () {
        if (childParentData->_transform != nullptr) {
            ;
        }
        return true;
    }());
    _lastPaintOrder->add(i);
    childParentData->_transform = transform;
    if (opacity == 0.0) {
        return;
    }
    InlineMethod;
    if (opacity == 1.0) {
        _paintingContext!->pushTransform(needsCompositing, _paintingOffset!, transform, painter);
    } else {
        _paintingContext!->pushOpacity(_paintingOffset!, ui->ColorCls->getAlphaFromOpacity(opacity), [=] (PaintingContext context,Offset offset) {
            context->pushTransform(needsCompositing, offset, transform!, painter);
        });
    }
}

void RenderFlowCls::paint(PaintingContext context, Offset offset) {
    _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, _paintWithDelegateclipBehavior, _clipRectLayer->layer);
}

void RenderFlowCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

bool RenderFlowCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    List<RenderBox> children = getChildrenAsList();
    for (; i >= 0; --i) {
        int childIndex = _lastPaintOrder[i];
        if (childIndex >= children->length) {
            continue;
        }
        RenderBox child = children[childIndex];
        FlowParentData childParentData = as<FlowParentData>(child->parentData!);
        Matrix4 transform = childParentData->_transform;
        if (transform == nullptr) {
            continue;
        }
        bool absorbed = result->addWithPaintTransform(transform, position, [=] (BoxHitTestResult result,Offset position) {
    return child->hitTest(resultposition);
});
        if (absorbed) {
            return true;
        }
    }
    return false;
}

void RenderFlowCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    FlowParentData childParentData = as<FlowParentData>(child->parentData!);
    if (childParentData->_transform != nullptr) {
        transform->multiply(childParentData->_transform!);
    }
    super->applyPaintTransform(child, transform);
}

Size RenderFlowCls::_getSize(BoxConstraints constraints) {
    assert(constraints->debugAssertIsValid());
    return constraints->constrain(_delegate->getSize(constraints));
}

void RenderFlowCls::_paintWithDelegate(PaintingContext context, Offset offset) {
    _lastPaintOrder->clear();
    _paintingContext = context;
    _paintingOffset = offset;
    for (RenderBox child : _randomAccessChildren) {
        FlowParentData childParentData = as<FlowParentData>(child->parentData!);
        childParentData->_transform = nullptr;
    }
    try {
        _delegate->paintChildren(this);
    } finally {
        _paintingContext = nullptr;
        _paintingOffset = nullptr;
    };
}
