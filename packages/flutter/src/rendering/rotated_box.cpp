#include "rotated_box.hpp"
RenderRotatedBox::RenderRotatedBox(RenderBox child, int quarterTurns) {
    {
        assert(quarterTurns != nullptr);
        _quarterTurns = quarterTurns;
    }
    {
        this.child = child;
    }
}

int RenderRotatedBox::quarterTurns() {
    return _quarterTurns;
}

void RenderRotatedBox::quarterTurns(int value) {
    assert(value != nullptr);
    if (_quarterTurns == value) {
        return;
    }
    _quarterTurns = value;
    markNeedsLayout();
}

double RenderRotatedBox::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical? child!.getMinIntrinsicHeight(height) : child!.getMinIntrinsicWidth(height);
}

double RenderRotatedBox::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical? child!.getMaxIntrinsicHeight(height) : child!.getMaxIntrinsicWidth(height);
}

double RenderRotatedBox::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical? child!.getMinIntrinsicWidth(width) : child!.getMinIntrinsicHeight(width);
}

double RenderRotatedBox::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical? child!.getMaxIntrinsicWidth(width) : child!.getMaxIntrinsicHeight(width);
}

Size RenderRotatedBox::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr) {
        return constraints.smallest;
    }
    Size childSize = child!.getDryLayout(_isVertical? constraints.flipped : constraints);
    return _isVertical? Size(childSize.height, childSize.width) : childSize;
}

void RenderRotatedBox::performLayout() {
    _paintTransform = nullptr;
    if (child != nullptr) {
        child!.layout(_isVertical? constraints.flipped : constraintstrue);
        size = _isVertical? Size(child!.size.height, child!.size.width) : child!.size;
        _paintTransform = ;
    } else {
        size = constraints.smallest;
    }
}

bool RenderRotatedBox::hitTestChildren(Offset position, BoxHitTestResult result) {
    assert(_paintTransform != nullptr || debugNeedsLayout || child == nullptr);
    if (child == nullptr || _paintTransform == nullptr) {
        return false;
    }
    return result.addWithPaintTransform(_paintTransform, position, );
}

void RenderRotatedBox::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        _transformLayer.layer = context.pushTransform(needsCompositing, offset, _paintTransform!, _paintChild_transformLayer.layer);
    } else {
        _transformLayer.layer = nullptr;
    }
}

void RenderRotatedBox::dispose() {
    _transformLayer.layer = nullptr;
    super.dispose();
}

void RenderRotatedBox::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (_paintTransform != nullptr) {
        transform.multiply(_paintTransform!);
    }
    super.applyPaintTransform(child, transform);
}

bool RenderRotatedBox::_isVertical() {
    return quarterTurns.isOdd;
}

void RenderRotatedBox::_paintChild(PaintingContext context, Offset offset) {
    context.paintChild(child!, offset);
}
