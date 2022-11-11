#include "stack.hpp"
void RelativeRectCls::fromLTRB(double bottom, double left, double right, double top)

void RelativeRectCls::fromSize(Size container, Rect rect) {
    return RelativeRectCls->fromLTRB(rect->left, rect->top, container->width - rect->right, container->height - rect->bottom);
}

void RelativeRectCls::fromRect(Rect container, Rect rect) {
    return RelativeRectCls->fromLTRB(rect->left - container->left, rect->top - container->top, container->right - rect->right, container->bottom - rect->bottom);
}

void RelativeRectCls::fromDirectional(double bottom, double end, double start, TextDirection textDirection, double top) {
    double left;
    double right;
    ;
    return RelativeRectCls->fromLTRB(left, top, right, bottom);
}

bool RelativeRectCls::hasInsets() {
    return left > 0.0 || top > 0.0 || right > 0.0 || bottom > 0.0;
}

RelativeRect RelativeRectCls::shift(Offset offset) {
    return RelativeRectCls->fromLTRB(left + offset->dx, top + offset->dy, right - offset->dx, bottom - offset->dy);
}

RelativeRect RelativeRectCls::inflate(double delta) {
    return RelativeRectCls->fromLTRB(left - delta, top - delta, right - delta, bottom - delta);
}

RelativeRect RelativeRectCls::deflate(double delta) {
    return inflate(-delta);
}

RelativeRect RelativeRectCls::intersect(RelativeRect other) {
    return RelativeRectCls->fromLTRB(math->max(left, other->left), math->max(top, other->top), math->max(right, other->right), math->max(bottom, other->bottom));
}

Rect RelativeRectCls::toRect(Rect container) {
    return RectCls->fromLTRB(left, top, container->width - right, container->height - bottom);
}

Size RelativeRectCls::toSize(Size container) {
    return make<SizeCls>(container->width - left - right, container->height - top - bottom);
}

RelativeRect RelativeRectCls::lerp(RelativeRect a, RelativeRect b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return RelativeRectCls->fromLTRB(b!->left * t, b->top * t, b->right * t, b->bottom * t);
    }
    if (b == nullptr) {
        double k = 1.0 - t;
        return RelativeRectCls->fromLTRB(b!->left * k, b->top * k, b->right * k, b->bottom * k);
    }
    return RelativeRectCls->fromLTRB(lerpDouble(a->left, b->left, t)!, lerpDouble(a->top, b->top, t)!, lerpDouble(a->right, b->right, t)!, lerpDouble(a->bottom, b->bottom, t)!);
}

bool RelativeRectCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<RelativeRect>(other) && other->left == left && other->top == top && other->right == right && other->bottom == bottom;
}

int RelativeRectCls::hashCode() {
    return ObjectCls->hash(left, top, right, bottom);
}

String RelativeRectCls::toString() {
    return __s("RelativeRect.fromLTRB(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)})");
}

RelativeRect StackParentDataCls::rect() {
    return RelativeRectCls->fromLTRB(left!, top!, right!, bottom!);
}

void StackParentDataCls::rect(RelativeRect value) {
    top = value->top;
    right = value->right;
    bottom = value->bottom;
    left = value->left;
}

bool StackParentDataCls::isPositioned() {
    return top != nullptr || right != nullptr || bottom != nullptr || left != nullptr || width != nullptr || height != nullptr;
}

String StackParentDataCls::toString() {
    List<String> list1 = make<ListCls<>>();if (top != nullptr) {    list1.add(ArrayItem);}if (right != nullptr) {    list1.add(ArrayItem);}if (bottom != nullptr) {    list1.add(ArrayItem);}if (left != nullptr) {    list1.add(ArrayItem);}if (width != nullptr) {    list1.add(ArrayItem);}if (height != nullptr) {    list1.add(ArrayItem);}List<String> values = list1;
    if (values->isEmpty) {
        values->add(__s("not positioned"));
    }
    values->add(super->toString());
    return values->join(__s("; "));
}

RenderStackCls::RenderStackCls(AlignmentGeometry alignment, List<RenderBox> children, Clip clipBehavior, StackFit fit, TextDirection textDirection) {
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

void RenderStackCls::setupParentData(RenderBox child) {
    if (!is<StackParentData>(child->parentData)) {
        child->parentData = make<StackParentDataCls>();
    }
}

AlignmentGeometry RenderStackCls::alignment() {
    return _alignment;
}

void RenderStackCls::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (_alignment == value) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

TextDirection RenderStackCls::textDirection() {
    return _textDirection;
}

void RenderStackCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

StackFit RenderStackCls::fit() {
    return _fit;
}

void RenderStackCls::fit(StackFit value) {
    assert(value != nullptr);
    if (_fit != value) {
        _fit = value;
        markNeedsLayout();
    }
}

Clip RenderStackCls::clipBehavior() {
    return _clipBehavior;
}

void RenderStackCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double RenderStackCls::getIntrinsicDimension(RenderBox firstChild, double mainChildSizeGetter(RenderBox child) ) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        if (!childParentData->isPositioned()) {
            extent = math->max(extent, mainChildSizeGetter(child));
        }
        assert(child->parentData == childParentData);
        child = childParentData->nextSibling;
    }
    return extent;
}

double RenderStackCls::computeMinIntrinsicWidth(double height) {
    return getIntrinsicDimension(firstChild, [=] (RenderBox child)     {
        child->getMinIntrinsicWidth(height);
    });
}

double RenderStackCls::computeMaxIntrinsicWidth(double height) {
    return getIntrinsicDimension(firstChild, [=] (RenderBox child)     {
        child->getMaxIntrinsicWidth(height);
    });
}

double RenderStackCls::computeMinIntrinsicHeight(double width) {
    return getIntrinsicDimension(firstChild, [=] (RenderBox child)     {
        child->getMinIntrinsicHeight(width);
    });
}

double RenderStackCls::computeMaxIntrinsicHeight(double width) {
    return getIntrinsicDimension(firstChild, [=] (RenderBox child)     {
        child->getMaxIntrinsicHeight(width);
    });
}

double RenderStackCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    return defaultComputeDistanceToHighestActualBaseline(baseline);
}

bool RenderStackCls::layoutPositionedChild(Alignment alignment, RenderBox child, StackParentData childParentData, Size size) {
    assert(childParentData->isPositioned());
    assert(child->parentData == childParentData);
    bool hasVisualOverflow = false;
    BoxConstraints childConstraints = make<BoxConstraintsCls>();
    if (childParentData->left != nullptr && childParentData->right != nullptr) {
        childConstraints = childConstraints->tighten(size->width - childParentData->right! - childParentData->left!);
    } else     {
        if (childParentData->width != nullptr) {
        childConstraints = childConstraints->tighten(childParentData->width);
    }
;
    }    if (childParentData->top != nullptr && childParentData->bottom != nullptr) {
        childConstraints = childConstraints->tighten(size->height - childParentData->bottom! - childParentData->top!);
    } else     {
        if (childParentData->height != nullptr) {
        childConstraints = childConstraints->tighten(childParentData->height);
    }
;
    }    child->layout(childConstraintstrue);
    double x;
    if (childParentData->left != nullptr) {
        x = childParentData->left!;
    } else     {
        if (childParentData->right != nullptr) {
        x = size->width - childParentData->right! - child->size->width;
    } else {
        x = alignment->alongOffset(as<Offset>(size - child->size))->dx;
    }
;
    }    if ( < 0.0 || x + child->size->width > size->width) {
        hasVisualOverflow = true;
    }
    double y;
    if (childParentData->top != nullptr) {
        y = childParentData->top!;
    } else     {
        if (childParentData->bottom != nullptr) {
        y = size->height - childParentData->bottom! - child->size->height;
    } else {
        y = alignment->alongOffset(as<Offset>(size - child->size))->dy;
    }
;
    }    if ( < 0.0 || y + child->size->height > size->height) {
        hasVisualOverflow = true;
    }
    childParentData->offset = make<OffsetCls>(x, y);
    return hasVisualOverflow;
}

Size RenderStackCls::computeDryLayout(BoxConstraints constraints) {
    return _computeSize(constraints, ChildLayoutHelperCls::dryLayoutChild);
}

void RenderStackCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    _hasVisualOverflow = false;
    size = _computeSize(constraints, ChildLayoutHelperCls::layoutChild);
    assert(_resolvedAlignment != nullptr);
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        if (!childParentData->isPositioned()) {
            childParentData->offset = _resolvedAlignment!->alongOffset(as<Offset>(size - child->size));
        } else {
            _hasVisualOverflow = layoutPositionedChild(child, childParentData, size, _resolvedAlignment!) || _hasVisualOverflow;
        }
        assert(child->parentData == childParentData);
        child = childParentData->nextSibling;
    }
}

bool RenderStackCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    return defaultHitTestChildren(resultposition);
}

void RenderStackCls::paintStack(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

void RenderStackCls::paint(PaintingContext context, Offset offset) {
    if (clipBehavior != ClipCls::none && _hasVisualOverflow) {
        _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, paintStackclipBehavior, _clipRectLayer->layer);
    } else {
        _clipRectLayer->layer = nullptr;
        paintStack(context, offset);
    }
}

void RenderStackCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

Rect RenderStackCls::describeApproximatePaintClip(RenderObject child) {
    ;
}

void RenderStackCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection));
    properties->add(<StackFit>make<EnumPropertyCls>(__s("fit"), fit));
    properties->add(<Clip>make<EnumPropertyCls>(__s("clipBehavior"), clipBehaviorClipCls::hardEdge));
}

void RenderStackCls::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment->resolve(textDirection);
}

void RenderStackCls::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

Size RenderStackCls::_computeSize(BoxConstraints constraints, ChildLayouter layoutChild) {
    _resolve();
    assert(_resolvedAlignment != nullptr);
    bool hasNonPositionedChildren = false;
    if (childCount == 0) {
        return (constraints->biggest()->isFinite)? constraints->biggest() : constraints->smallest();
    }
    double width = constraints->minWidth;
    double height = constraints->minHeight;
    BoxConstraints nonPositionedConstraints;
    assert(fit != nullptr);
    ;
    assert(nonPositionedConstraints != nullptr);
    RenderBox child = firstChild;
    while (child != nullptr) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        if (!childParentData->isPositioned()) {
            hasNonPositionedChildren = true;
            Size childSize = layoutChild(child, nonPositionedConstraints);
            width = math->max(width, childSize->width);
            height = math->max(height, childSize->height);
        }
        child = childParentData->nextSibling;
    }
    Size size;
    if (hasNonPositionedChildren) {
        size = make<SizeCls>(width, height);
        assert(size->width == constraints->constrainWidth(width));
        assert(size->height == constraints->constrainHeight(height));
    } else {
        size = constraints->biggest();
    }
    assert(size->isFinite);
    return size;
}

RenderIndexedStackCls::RenderIndexedStackCls(Unknown alignment, Unknown children, int index, Unknown textDirection) {
    {
        _index = index;
    }
}

void RenderIndexedStackCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    if (index != nullptr && firstChild != nullptr) {
        visitor(_childAtIndex());
    }
}

int RenderIndexedStackCls::index() {
    return _index;
}

void RenderIndexedStackCls::index(int value) {
    if (_index != value) {
        _index = value;
        markNeedsLayout();
    }
}

bool RenderIndexedStackCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (firstChild == nullptr || index == nullptr) {
        return false;
    }
    assert(position != nullptr);
    RenderBox child = _childAtIndex();
    StackParentData childParentData = as<StackParentData>(child->parentData!);
    return result->addWithPaintOffset(childParentData->offset, position, [=] (BoxHitTestResult result,Offset transformed) {
        assert(transformed == position - childParentData->offset);
        return child->hitTest(resulttransformed);
    });
}

void RenderIndexedStackCls::paintStack(PaintingContext context, Offset offset) {
    if (firstChild == nullptr || index == nullptr) {
        return;
    }
    RenderBox child = _childAtIndex();
    StackParentData childParentData = as<StackParentData>(child->parentData!);
    context->paintChild(child, childParentData->offset + offset);
}

void RenderIndexedStackCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("index"), index));
}

List<DiagnosticsNode> RenderIndexedStackCls::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    int i = 0;
    RenderObject child = firstChild;
    while (child != nullptr) {
        children->add(child->toDiagnosticsNode(__s("child ${i + 1}"), i != index!? DiagnosticsTreeStyleCls::offstage : nullptr));
        child = (as<StackParentData>(child->parentData!))->nextSibling;
        i = 1;
    }
    return children;
}

RenderBox RenderIndexedStackCls::_childAtIndex() {
    assert(index != nullptr);
    RenderBox child = firstChild;
    int i = 0;
    while (child != nullptr &&  < index!) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        child = childParentData->nextSibling;
        i = 1;
    }
    assert(i == index);
    assert(child != nullptr);
    return child!;
}
