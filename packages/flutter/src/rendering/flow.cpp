#include "flow.hpp"
FlowDelegate::FlowDelegate(Listenable repaint) {
    {
        _repaint = repaint;
    }
}

Size FlowDelegate::getSize(BoxConstraints constraints) {
    return constraints.biggest;
}

BoxConstraints FlowDelegate::getConstraintsForChild(BoxConstraints constraints, int i) {
    return constraints;
}

bool FlowDelegate::shouldRelayout(FlowDelegate oldDelegate) {
    return false;
}

String FlowDelegate::toString() {
    return objectRuntimeType(this, "FlowDelegate");
}

RenderFlow::RenderFlow(List<RenderBox> children, Clip clipBehavior, FlowDelegate delegate) {
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

void RenderFlow::setupParentData(RenderBox child) {
    ParentData childParentData = child.parentData;
    if (childParentData is FlowParentData) {
        childParentData._transform = nullptr;
    } else {
        child.parentData = FlowParentData();
    }
}

FlowDelegate RenderFlow::delegate() {
    return _delegate;
}

void RenderFlow::delegate(FlowDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    FlowDelegate oldDelegate = _delegate;
    _delegate = newDelegate;
    if (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    } else     {
        if (newDelegate.shouldRepaint(oldDelegate)) {
        markNeedsPaint();
    }
;
    }    if (attached) {
        oldDelegate._repaint?.removeListener(markNeedsPaint);
        newDelegate._repaint?.addListener(markNeedsPaint);
    }
}

Clip RenderFlow::clipBehavior() {
    return _clipBehavior;
}

void RenderFlow::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderFlow::attach(PipelineOwner owner) {
    super.attach(owner);
    _delegate._repaint?.addListener(markNeedsPaint);
}

void RenderFlow::detach() {
    _delegate._repaint?.removeListener(markNeedsPaint);
    super.detach();
}

bool RenderFlow::isRepaintBoundary() {
    return true;
}

double RenderFlow::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderFlow::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderFlow::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

double RenderFlow::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

Size RenderFlow::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderFlow::performLayout() {
    BoxConstraints constraints = this.constraints;
    size = _getSize(constraints);
    int i = 0;
    _randomAccessChildren.clear();
    RenderBox child = firstChild;
    while (child != nullptr) {
        _randomAccessChildren.add(child);
        BoxConstraints innerConstraints = _delegate.getConstraintsForChild(i, constraints);
        child.layout(innerConstraintstrue);
        FlowParentData childParentData = (;
        childParentData.offset = Offset.zero;
        child = childParentData.nextSibling;
        i = 1;
    }
}

Size RenderFlow::getChildSize(int i) {
    if ( < 0 || i >= _randomAccessChildren.length) {
        return nullptr;
    }
    return _randomAccessChildren[i].size;
}

void RenderFlow::paintChild(int i, double opacity, Matrix4 transform) {
    transform = Matrix4.identity();
    RenderBox child = _randomAccessChildren[i];
    FlowParentData childParentData = (;
    assert(());
    _lastPaintOrder.add(i);
    childParentData._transform = transform;
    if (opacity == 0.0) {
        return;
    }
    ;
    if (opacity == 1.0) {
        _paintingContext!.pushTransform(needsCompositing, _paintingOffset!, transform, painter);
    } else {
        _paintingContext!.pushOpacity(_paintingOffset!, ui.Color.getAlphaFromOpacity(opacity), );
    }
}

void RenderFlow::paint(PaintingContext context, Offset offset) {
    _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, _paintWithDelegateclipBehavior, _clipRectLayer.layer);
}

void RenderFlow::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

bool RenderFlow::hitTestChildren(Offset position, BoxHitTestResult result) {
    List<RenderBox> children = getChildrenAsList();
    for (; i >= 0; --i) {
        int childIndex = _lastPaintOrder[i];
        if (childIndex >= children.length) {
            continue;
        }
        RenderBox child = children[childIndex];
        FlowParentData childParentData = (;
        Matrix4 transform = childParentData._transform;
        if (transform == nullptr) {
            continue;
        }
        bool absorbed = result.addWithPaintTransform(transform, position, );
        if (absorbed) {
            return true;
        }
    }
    return false;
}

void RenderFlow::applyPaintTransform(RenderBox child, Matrix4 transform) {
    FlowParentData childParentData = (;
    if (childParentData._transform != nullptr) {
        transform.multiply(childParentData._transform!);
    }
    super.applyPaintTransform(child, transform);
}

Size RenderFlow::_getSize(BoxConstraints constraints) {
    assert(constraints.debugAssertIsValid());
    return constraints.constrain(_delegate.getSize(constraints));
}

void RenderFlow::_paintWithDelegate(PaintingContext context, Offset offset) {
    _lastPaintOrder.clear();
    _paintingContext = context;
    _paintingOffset = offset;
    for (RenderBox child : _randomAccessChildren) {
        FlowParentData childParentData = (;
        childParentData._transform = nullptr;
    }
    ;
}
