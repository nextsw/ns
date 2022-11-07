#include "stack.hpp"
void RelativeRect::fromLTRB(double bottom, double left, double right, double top)

void RelativeRect::fromSize(Size container, Rect rect) {
    return RelativeRect.fromLTRB(rect.left, rect.top, container.width - rect.right, container.height - rect.bottom);
}

void RelativeRect::fromRect(Rect container, Rect rect) {
    return RelativeRect.fromLTRB(rect.left - container.left, rect.top - container.top, container.right - rect.right, container.bottom - rect.bottom);
}

void RelativeRect::fromDirectional(double bottom, double end, double start, TextDirection textDirection, double top) {
    double left;
    double right;
    ;
    return RelativeRect.fromLTRB(left, top, right, bottom);
}

bool RelativeRect::hasInsets() {
    return left > 0.0 || top > 0.0 || right > 0.0 || bottom > 0.0;
}

RelativeRect RelativeRect::shift(Offset offset) {
    return RelativeRect.fromLTRB(left + offset.dx, top + offset.dy, right - offset.dx, bottom - offset.dy);
}

RelativeRect RelativeRect::inflate(double delta) {
    return RelativeRect.fromLTRB(left - delta, top - delta, right - delta, bottom - delta);
}

RelativeRect RelativeRect::deflate(double delta) {
    return inflate(-delta);
}

RelativeRect RelativeRect::intersect(RelativeRect other) {
    return RelativeRect.fromLTRB(math.max(left, other.left), math.max(top, other.top), math.max(right, other.right), math.max(bottom, other.bottom));
}

Rect RelativeRect::toRect(Rect container) {
    return Rect.fromLTRB(left, top, container.width - right, container.height - bottom);
}

Size RelativeRect::toSize(Size container) {
    return Size(container.width - left - right, container.height - top - bottom);
}

RelativeRect RelativeRect::lerp(RelativeRect a, RelativeRect b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return RelativeRect.fromLTRB(b!.left * t, b.top * t, b.right * t, b.bottom * t);
    }
    if (b == nullptr) {
        double k = 1.0 - t;
        return RelativeRect.fromLTRB(b!.left * k, b.top * k, b.right * k, b.bottom * k);
    }
    return RelativeRect.fromLTRB(lerpDouble(a.left, b.left, t)!, lerpDouble(a.top, b.top, t)!, lerpDouble(a.right, b.right, t)!, lerpDouble(a.bottom, b.bottom, t)!);
}

bool RelativeRect::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return other is RelativeRect && other.left == left && other.top == top && other.right == right && other.bottom == bottom;
}

int RelativeRect::hashCode() {
    return Object.hash(left, top, right, bottom);
}

String RelativeRect::toString() {
    return "RelativeRect.fromLTRB(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)})";
}

RelativeRect StackParentData::rect() {
    return RelativeRect.fromLTRB(left!, top!, right!, bottom!);
}

void StackParentData::rect(RelativeRect value) {
    top = value.top;
    right = value.right;
    bottom = value.bottom;
    left = value.left;
}

bool StackParentData::isPositioned() {
    return top != nullptr || right != nullptr || bottom != nullptr || left != nullptr || width != nullptr || height != nullptr;
}

String StackParentData::toString() {
    List<String> values = ;
    if (values.isEmpty) {
        values.add("not positioned");
    }
    values.add(super.toString());
    return values.join("; ");
}

RenderStack::RenderStack(AlignmentGeometry alignment, List<RenderBox> children, Clip clipBehavior, StackFit fit, TextDirection textDirection) {
    {
        assert(alignment != nullptr);
        assert(fit != nullptr);
        assert(clipBehavior != nullptr);
        _alignment = alignment;
        _textDirection = textDirection;
        _fit = fit;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

void RenderStack::setupParentData(RenderBox child) {
    if (child.parentData is! StackParentData) {
        child.parentData = StackParentData();
    }
}

AlignmentGeometry RenderStack::alignment() {
    return _alignment;
}

void RenderStack::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

TextDirection RenderStack::textDirection() {
    return _textDirection;
}

void RenderStack::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

StackFit RenderStack::fit() {
    return _fit;
}

void RenderStack::fit(StackFit value) {
    assert(value != nullptr);
    if (_fit != value) {
        _fit = value;
        markNeedsLayout();
    }
}

Clip RenderStack::clipBehavior() {
    return _clipBehavior;
}

void RenderStack::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double RenderStack::getIntrinsicDimension(RenderBox firstChild, FunctionType mainChildSizeGetter) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = (;
        if (!childParentData.isPositioned) {
            extent = math.max(extent, mainChildSizeGetter(child));
        }
        assert(child.parentData == childParentData);
        child = childParentData.nextSibling;
    }
    return extent;
}

double RenderStack::computeMinIntrinsicWidth(double height) {
    return getIntrinsicDimension(firstChild, );
}

double RenderStack::computeMaxIntrinsicWidth(double height) {
    return getIntrinsicDimension(firstChild, );
}

double RenderStack::computeMinIntrinsicHeight(double width) {
    return getIntrinsicDimension(firstChild, );
}

double RenderStack::computeMaxIntrinsicHeight(double width) {
    return getIntrinsicDimension(firstChild, );
}

double RenderStack::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToHighestActualBaseline(baseline);
}

bool RenderStack::layoutPositionedChild(Alignment alignment, RenderBox child, StackParentData childParentData, Size size) {
    assert(childParentData.isPositioned);
    assert(child.parentData == childParentData);
    bool hasVisualOverflow = false;
    BoxConstraints childConstraints = const BoxConstraints();
    if (childParentData.left != nullptr && childParentData.right != nullptr) {
        childConstraints = childConstraints.tighten(size.width - childParentData.right! - childParentData.left!);
    } else     {
        if (childParentData.width != nullptr) {
        childConstraints = childConstraints.tighten(childParentData.width);
    }
;
    }    if (childParentData.top != nullptr && childParentData.bottom != nullptr) {
        childConstraints = childConstraints.tighten(size.height - childParentData.bottom! - childParentData.top!);
    } else     {
        if (childParentData.height != nullptr) {
        childConstraints = childConstraints.tighten(childParentData.height);
    }
;
    }    child.layout(childConstraintstrue);
    double x;
    if (childParentData.left != nullptr) {
        x = childParentData.left!;
    } else     {
        if (childParentData.right != nullptr) {
        x = size.width - childParentData.right! - child.size.width;
    } else {
        x = alignment.alongOffset(().dx;
    }
;
    }    if ( < 0.0 || x + child.size.width > size.width) {
        hasVisualOverflow = true;
    }
    double y;
    if (childParentData.top != nullptr) {
        y = childParentData.top!;
    } else     {
        if (childParentData.bottom != nullptr) {
        y = size.height - childParentData.bottom! - child.size.height;
    } else {
        y = alignment.alongOffset(().dy;
    }
;
    }    if ( < 0.0 || y + child.size.height > size.height) {
        hasVisualOverflow = true;
    }
    childParentData.offset = Offset(x, y);
    return hasVisualOverflow;
}

Size RenderStack::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(constraints, ChildLayoutHelper.dryLayoutChild);
}

void RenderStack::performLayout() {
    BoxConstraints constraints = this.constraints;
    _hasVisualOverflow = false;
    size = _computeSize(constraints, ChildLayoutHelper.layoutChild);
    assert(_resolvedAlignment != nullptr);
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = (;
        if (!childParentData.isPositioned) {
            childParentData.offset = _resolvedAlignment!.alongOffset(();
        } else {
            _hasVisualOverflow = layoutPositionedChild(child, childParentData, size, _resolvedAlignment!) || _hasVisualOverflow;
        }
        assert(child.parentData == childParentData);
        child = childParentData.nextSibling;
    }
}

bool RenderStack::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

void RenderStack::paintStack(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

void RenderStack::paint(PaintingContext context, Offset offset) {
    if (clipBehavior != Clip.none && _hasVisualOverflow) {
        _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, paintStackclipBehavior, _clipRectLayer.layer);
    } else {
        _clipRectLayer.layer = nullptr;
        paintStack(context, offset);
    }
}

void RenderStack::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

Rect RenderStack::describeApproximatePaintClip(RenderObject child) {
    ;
}

void RenderStack::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignment));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirection));
    properties.add(<StackFit>EnumProperty("fit", fit));
    properties.add(<Clip>EnumProperty("clipBehavior", clipBehaviorClip.hardEdge));
}

void RenderStack::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment.resolve(textDirection);
}

void RenderStack::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

Size RenderStack::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    _resolve();
    assert(_resolvedAlignment != nullptr);
    bool hasNonPositionedChildren = false;
    if (childCount == 0) {
        return (constraints.biggest.isFinite)? constraints.biggest : constraints.smallest;
    }
    double width = constraints.minWidth;
    double height = constraints.minHeight;
    BoxConstraints nonPositionedConstraints;
    assert(fit != nullptr);
    ;
    assert(nonPositionedConstraints != nullptr);
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = (;
        if (!childParentData.isPositioned) {
            hasNonPositionedChildren = true;
            Size childSize = layoutChild(child, nonPositionedConstraints);
            width = math.max(width, childSize.width);
            height = math.max(height, childSize.height);
        }
        child = childParentData.nextSibling;
    }
    Size size;
    if (hasNonPositionedChildren) {
        size = Size(width, height);
        assert(size.width == constraints.constrainWidth(width));
        assert(size.height == constraints.constrainHeight(height));
    } else {
        size = constraints.biggest;
    }
    assert(size.isFinite);
    return size;
}

RenderIndexedStack::RenderIndexedStack(Unknown, Unknown, int index, Unknown) {
    {
        _index = index;
    }
}

void RenderIndexedStack::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (index != nullptr && firstChild != nullptr) {
        visitor(_childAtIndex());
    }
}

int RenderIndexedStack::index() {
    return _index;
}

void RenderIndexedStack::index(int value) {
    if (_index != value) {
        _index = value;
        markNeedsLayout();
    }
}

bool RenderIndexedStack::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (firstChild == nullptr || index == nullptr) {
        return false;
    }
    assert(position != nullptr);
    RenderBox child = _childAtIndex();
    StackParentData childParentData = (;
    return result.addWithPaintOffset(childParentData.offset, position, );
}

void RenderIndexedStack::paintStack(PaintingContext context, Offset offset) {
    if (firstChild == nullptr || index == nullptr) {
        return;
    }
    RenderBox child = _childAtIndex();
    StackParentData childParentData = (;
    context.paintChild(child, childParentData.offset + offset);
}

void RenderIndexedStack::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("index", index));
}

List<DiagnosticsNode> RenderIndexedStack::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    int i = 0;
    RenderObject child = firstChild;
    while (child != nullptr) {
        children.add(child.toDiagnosticsNode("child ${i + 1}", i != index!? DiagnosticsTreeStyle.offstage : nullptr));
        child = (().nextSibling;
        i = 1;
    }
    return children;
}

RenderBox RenderIndexedStack::_childAtIndex() {
    assert(index != nullptr);
    RenderBox child = firstChild;
    int i = 0;
    while (child != nullptr &&  < index!) {
        StackParentData childParentData = (;
        child = childParentData.nextSibling;
        i = 1;
    }
    assert(i == index);
    assert(child != nullptr);
    return child!;
}
