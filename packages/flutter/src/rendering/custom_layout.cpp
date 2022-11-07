#include "custom_layout.hpp"
String MultiChildLayoutParentData::toString() {
    return "${super.toString()}; id=$id";
}

MultiChildLayoutDelegate::MultiChildLayoutDelegate(Listenable relayout) {
    {
        _relayout = relayout;
    }
}

bool MultiChildLayoutDelegate::hasChild(Object childId) {
    return _idToChild![childId] != nullptr;
}

Size MultiChildLayoutDelegate::layoutChild(Object childId, BoxConstraints constraints) {
    RenderBox child = _idToChild![childId];
    assert(());
    child!.layout(constraintstrue);
    return child.size;
}

void MultiChildLayoutDelegate::positionChild(Object childId, Offset offset) {
    RenderBox child = _idToChild![childId];
    assert(());
    MultiChildLayoutParentData childParentData = (;
    childParentData.offset = offset;
}

Size MultiChildLayoutDelegate::getSize(BoxConstraints constraints) {
    return constraints.biggest;
}

String MultiChildLayoutDelegate::toString() {
    return objectRuntimeType(this, "MultiChildLayoutDelegate");
}

DiagnosticsNode MultiChildLayoutDelegate::_debugDescribeChild(RenderBox child) {
    MultiChildLayoutParentData childParentData = (;
    return <RenderBox>DiagnosticsProperty("${childParentData.id}", child);
}

void MultiChildLayoutDelegate::_callPerformLayout(RenderBox firstChild, Size size) {
    Map<Object, RenderBox> previousIdToChild = _idToChild;
    Set<RenderBox> debugPreviousChildrenNeedingLayout;
    assert(());
    ;
}

RenderCustomMultiChildLayoutBox::RenderCustomMultiChildLayoutBox(List<RenderBox> children, MultiChildLayoutDelegate delegate) {
    {
        assert(delegate != nullptr);
        _delegate = delegate;
    }
    {
        addAll(children);
    }
}

void RenderCustomMultiChildLayoutBox::setupParentData(RenderBox child) {
    if (child.parentData is! MultiChildLayoutParentData) {
        child.parentData = MultiChildLayoutParentData();
    }
}

MultiChildLayoutDelegate RenderCustomMultiChildLayoutBox::delegate() {
    return _delegate;
}

void RenderCustomMultiChildLayoutBox::delegate(MultiChildLayoutDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    MultiChildLayoutDelegate oldDelegate = _delegate;
    if (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    }
    _delegate = newDelegate;
    if (attached) {
        oldDelegate._relayout?.removeListener(markNeedsLayout);
        newDelegate._relayout?.addListener(markNeedsLayout);
    }
}

void RenderCustomMultiChildLayoutBox::attach(PipelineOwner owner) {
    super.attach(owner);
    _delegate._relayout?.addListener(markNeedsLayout);
}

void RenderCustomMultiChildLayoutBox::detach() {
    _delegate._relayout?.removeListener(markNeedsLayout);
    super.detach();
}

double RenderCustomMultiChildLayoutBox::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBox::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraints.tightForFinite(height)).width;
    if (width.isFinite) {
        return width;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBox::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBox::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraints.tightForFinite(width)).height;
    if (height.isFinite) {
        return height;
    }
    return 0.0;
}

Size RenderCustomMultiChildLayoutBox::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderCustomMultiChildLayoutBox::performLayout() {
    size = _getSize(constraints);
    delegate._callPerformLayout(size, firstChild);
}

void RenderCustomMultiChildLayoutBox::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

bool RenderCustomMultiChildLayoutBox::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

Size RenderCustomMultiChildLayoutBox::_getSize(BoxConstraints constraints) {
    assert(constraints.debugAssertIsValid());
    return constraints.constrain(_delegate.getSize(constraints));
}
