#include "rotated_box.hpp"
RenderRotatedBoxCls::RenderRotatedBoxCls(RenderBox child, int quarterTurns) {
    {
        assert(quarterTurns != nullptr);
        _quarterTurns = quarterTurns;
    }
    {
        this->child = child;
    }
}

int RenderRotatedBoxCls::quarterTurns() {
    return _quarterTurns;
}

void RenderRotatedBoxCls::quarterTurns(int value) {
    assert(value != nullptr);
    if (_quarterTurns == value) {
        return;
    }
    _quarterTurns = value;
    markNeedsLayout();
}

double RenderRotatedBoxCls::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical()? child!->getMinIntrinsicHeight(height) : child!->getMinIntrinsicWidth(height);
}

double RenderRotatedBoxCls::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical()? child!->getMaxIntrinsicHeight(height) : child!->getMaxIntrinsicWidth(height);
}

double RenderRotatedBoxCls::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical()? child!->getMinIntrinsicWidth(width) : child!->getMinIntrinsicHeight(width);
}

double RenderRotatedBoxCls::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return 0.0;
    }
    return _isVertical()? child!->getMaxIntrinsicWidth(width) : child!->getMaxIntrinsicHeight(width);
}

Size RenderRotatedBoxCls::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr) {
        return constraints->smallest();
    }
    Size childSize = child!->getDryLayout(_isVertical()? constraints->flipped() : constraints);
    return _isVertical()? make<SizeCls>(childSize->height(), childSize->width()) : childSize;
}

void RenderRotatedBoxCls::performLayout() {
    _paintTransform = nullptr;
    if (child != nullptr) {
        child!->layout(_isVertical()? constraints()->flipped() : constraints(), true);
        size() = _isVertical()? make<SizeCls>(child!->size->height, child!->size->width) : child!->size;
            auto _c1 = Matrix4Cls->identity();    _c1.auto _c2 = translate(size()->width() / 2.0, size()->height() / 2.0);    _c2.auto _c3 = rotateZ(_kQuarterTurnsInRadians * (quarterTurns() % 4));    _c3.translate(-child!->size->width / 2.0, -child!->size->height / 2.0);    _c3;    _c2;_paintTransform = _c1;
    } else {
        size() = constraints()->smallest();
    }
}

bool RenderRotatedBoxCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    assert(_paintTransform != nullptr || debugNeedsLayout() || child == nullptr);
    if (child == nullptr || _paintTransform == nullptr) {
        return false;
    }
    return result->addWithPaintTransform(_paintTransform, position, [=] (BoxHitTestResult result,Offset position) {
        return child!->hitTest(result, position);
    });
}

void RenderRotatedBoxCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        _transformLayer->layer() = context->pushTransform(needsCompositing(), offset, _paintTransform!, _paintChild, _transformLayer->layer());
    } else {
        _transformLayer->layer() = nullptr;
    }
}

void RenderRotatedBoxCls::dispose() {
    _transformLayer->layer() = nullptr;
    super->dispose();
}

void RenderRotatedBoxCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (_paintTransform != nullptr) {
        transform->multiply(_paintTransform!);
    }
    super->applyPaintTransform(child, transform);
}

bool RenderRotatedBoxCls::_isVertical() {
    return quarterTurns()->isOdd();
}

void RenderRotatedBoxCls::_paintChild(PaintingContext context, Offset offset) {
    context->paintChild(child!, offset);
}
