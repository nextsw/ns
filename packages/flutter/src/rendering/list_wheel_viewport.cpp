#include "list_wheel_viewport.hpp"
RenderListWheelViewport::RenderListWheelViewport(ListWheelChildManager childManager, List<RenderBox> children, Clip clipBehavior, double diameterRatio, double itemExtent, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier) {
    {
        assert(childManager != nullptr);
        assert(offset != nullptr);
        assert(diameterRatio != nullptr);
        assert(diameterRatio > 0, diameterRatioZeroMessage);
        assert(perspective != nullptr);
        assert(perspective > 0);
        assert(perspective <= 0.01, perspectiveTooHighMessage);
        assert(offAxisFraction != nullptr);
        assert(useMagnifier != nullptr);
        assert(magnification != nullptr);
        assert(magnification > 0);
        assert(overAndUnderCenterOpacity != nullptr);
        assert(overAndUnderCenterOpacity >= 0 && overAndUnderCenterOpacity <= 1);
        assert(itemExtent != nullptr);
        assert(squeeze != nullptr);
        assert(squeeze > 0);
        assert(itemExtent > 0);
        assert(renderChildrenOutsideViewport != nullptr);
        assert(clipBehavior != nullptr);
        assert(!renderChildrenOutsideViewport || clipBehavior == Clip.none, clipBehaviorAndRenderChildrenOutsideViewportConflict);
        _offset = offset;
        _diameterRatio = diameterRatio;
        _perspective = perspective;
        _offAxisFraction = offAxisFraction;
        _useMagnifier = useMagnifier;
        _magnification = magnification;
        _overAndUnderCenterOpacity = overAndUnderCenterOpacity;
        _itemExtent = itemExtent;
        _squeeze = squeeze;
        _renderChildrenOutsideViewport = renderChildrenOutsideViewport;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

ViewportOffset RenderListWheelViewport::offset() {
    return _offset;
}

void RenderListWheelViewport::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    if (attached) {
        _offset.removeListener(_hasScrolled);
    }
    _offset = value;
    if (attached) {
        _offset.addListener(_hasScrolled);
    }
    markNeedsLayout();
}

double RenderListWheelViewport::diameterRatio() {
    return _diameterRatio;
}

void RenderListWheelViewport::diameterRatio(double value) {
    assert(value != nullptr);
    assert(value > 0, diameterRatioZeroMessage);
    if (value == _diameterRatio) {
        return;
    }
    _diameterRatio = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

double RenderListWheelViewport::perspective() {
    return _perspective;
}

void RenderListWheelViewport::perspective(double value) {
    assert(value != nullptr);
    assert(value > 0);
    assert(value <= 0.01, perspectiveTooHighMessage);
    if (value == _perspective) {
        return;
    }
    _perspective = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

double RenderListWheelViewport::offAxisFraction() {
    return _offAxisFraction;
}

void RenderListWheelViewport::offAxisFraction(double value) {
    assert(value != nullptr);
    if (value == _offAxisFraction) {
        return;
    }
    _offAxisFraction = value;
    markNeedsPaint();
}

bool RenderListWheelViewport::useMagnifier() {
    return _useMagnifier;
}

void RenderListWheelViewport::useMagnifier(bool value) {
    assert(value != nullptr);
    if (value == _useMagnifier) {
        return;
    }
    _useMagnifier = value;
    markNeedsPaint();
}

double RenderListWheelViewport::magnification() {
    return _magnification;
}

void RenderListWheelViewport::magnification(double value) {
    assert(value != nullptr);
    assert(value > 0);
    if (value == _magnification) {
        return;
    }
    _magnification = value;
    markNeedsPaint();
}

double RenderListWheelViewport::overAndUnderCenterOpacity() {
    return _overAndUnderCenterOpacity;
}

void RenderListWheelViewport::overAndUnderCenterOpacity(double value) {
    assert(value != nullptr);
    assert(value >= 0 && value <= 1);
    if (value == _overAndUnderCenterOpacity) {
        return;
    }
    _overAndUnderCenterOpacity = value;
    markNeedsPaint();
}

double RenderListWheelViewport::itemExtent() {
    return _itemExtent;
}

void RenderListWheelViewport::itemExtent(double value) {
    assert(value != nullptr);
    assert(value > 0);
    if (value == _itemExtent) {
        return;
    }
    _itemExtent = value;
    markNeedsLayout();
}

double RenderListWheelViewport::squeeze() {
    return _squeeze;
}

void RenderListWheelViewport::squeeze(double value) {
    assert(value != nullptr);
    assert(value > 0);
    if (value == _squeeze) {
        return;
    }
    _squeeze = value;
    markNeedsLayout();
    markNeedsSemanticsUpdate();
}

bool RenderListWheelViewport::renderChildrenOutsideViewport() {
    return _renderChildrenOutsideViewport;
}

void RenderListWheelViewport::renderChildrenOutsideViewport(bool value) {
    assert(value != nullptr);
    assert(!renderChildrenOutsideViewport || clipBehavior == Clip.none, clipBehaviorAndRenderChildrenOutsideViewportConflict);
    if (value == _renderChildrenOutsideViewport) {
        return;
    }
    _renderChildrenOutsideViewport = value;
    markNeedsLayout();
    markNeedsSemanticsUpdate();
}

Clip RenderListWheelViewport::clipBehavior() {
    return _clipBehavior;
}

void RenderListWheelViewport::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderListWheelViewport::setupParentData(RenderObject child) {
    if (child.parentData is! ListWheelParentData) {
        child.parentData = ListWheelParentData();
    }
}

void RenderListWheelViewport::attach(PipelineOwner owner) {
    super.attach(owner);
    _offset.addListener(_hasScrolled);
}

void RenderListWheelViewport::detach() {
    _offset.removeListener(_hasScrolled);
    super.detach();
}

bool RenderListWheelViewport::isRepaintBoundary() {
    return true;
}

double RenderListWheelViewport::computeMinIntrinsicWidth(double height) {
    return _getIntrinsicCrossAxis();
}

double RenderListWheelViewport::computeMaxIntrinsicWidth(double height) {
    return _getIntrinsicCrossAxis();
}

double RenderListWheelViewport::computeMinIntrinsicHeight(double width) {
    if (childManager.childCount == nullptr) {
        return 0.0;
    }
    return childManager.childCount! * _itemExtent;
}

double RenderListWheelViewport::computeMaxIntrinsicHeight(double width) {
    if (childManager.childCount == nullptr) {
        return 0.0;
    }
    return childManager.childCount! * _itemExtent;
}

bool RenderListWheelViewport::sizedByParent() {
    return true;
}

Size RenderListWheelViewport::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

int RenderListWheelViewport::indexOf(RenderBox child) {
    assert(child != nullptr);
    ListWheelParentData childParentData = (;
    assert(childParentData.index != nullptr);
    return childParentData.index!;
}

int RenderListWheelViewport::scrollOffsetToIndex(double scrollOffset) {
    return (scrollOffset / itemExtent).floor();
}

double RenderListWheelViewport::indexToScrollOffset(int index) {
    return index * itemExtent;
}

void RenderListWheelViewport::performLayout() {
    offset.applyViewportDimension(_viewportExtent);
    offset.applyContentDimensions(_minEstimatedScrollExtent, _maxEstimatedScrollExtent);
    double visibleHeight = size.height * _squeeze;
    if (renderChildrenOutsideViewport) {
        visibleHeight = 2;
    }
    double firstVisibleOffset = offset.pixels + _itemExtent / 2 - visibleHeight / 2;
    double lastVisibleOffset = firstVisibleOffset + visibleHeight;
    int targetFirstIndex = scrollOffsetToIndex(firstVisibleOffset);
    int targetLastIndex = scrollOffsetToIndex(lastVisibleOffset);
    if (targetLastIndex * _itemExtent == lastVisibleOffset) {
        targetLastIndex--;
    }
    while (!childManager.childExistsAt(targetFirstIndex) && targetFirstIndex <= targetLastIndex) {
        targetFirstIndex++;
    }
    while (!childManager.childExistsAt(targetLastIndex) && targetFirstIndex <= targetLastIndex) {
        targetLastIndex--;
    }
    if (targetFirstIndex > targetLastIndex) {
        while (firstChild != nullptr) {
            _destroyChild(firstChild!);
        }
        return;
    }
    if (childCount > 0 && (indexOf(firstChild!) > targetLastIndex || indexOf(lastChild!) < targetFirstIndex)) {
        while (firstChild != nullptr) {
            _destroyChild(firstChild!);
        }
    }
    BoxConstraints childConstraints = constraints.copyWith(_itemExtent, _itemExtent, 0.0);
    if (childCount == 0) {
        _createChild(targetFirstIndex);
        _layoutChild(firstChild!, childConstraints, targetFirstIndex);
    }
    int currentFirstIndex = indexOf(firstChild!);
    int currentLastIndex = indexOf(lastChild!);
    while ( < targetFirstIndex) {
        _destroyChild(firstChild!);
        currentFirstIndex++;
    }
    while (currentLastIndex > targetLastIndex) {
        _destroyChild(lastChild!);
        currentLastIndex--;
    }
    RenderBox child = firstChild;
    while (child != nullptr) {
        child.layout(childConstraintstrue);
        child = childAfter(child);
    }
    while (currentFirstIndex > targetFirstIndex) {
        _createChild(currentFirstIndex - 1);
        _layoutChild(firstChild!, childConstraints, --currentFirstIndex);
    }
    while ( < targetLastIndex) {
        _createChild(currentLastIndex + 1lastChild);
        _layoutChild(lastChild!, childConstraints, ++currentLastIndex);
    }
    double minScrollExtent = childManager.childExistsAt(targetFirstIndex - 1)? _minEstimatedScrollExtent : indexToScrollOffset(targetFirstIndex);
    double maxScrollExtent = childManager.childExistsAt(targetLastIndex + 1)? _maxEstimatedScrollExtent : indexToScrollOffset(targetLastIndex);
    offset.applyContentDimensions(minScrollExtent, maxScrollExtent);
}

void RenderListWheelViewport::paint(PaintingContext context, Offset offset) {
    if (childCount > 0) {
        if (_shouldClipAtCurrentOffset() && clipBehavior != Clip.none) {
            _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, _paintVisibleChildrenclipBehavior, _clipRectLayer.layer);
        } else {
            _clipRectLayer.layer = nullptr;
            _paintVisibleChildren(context, offset);
        }
    }
}

void RenderListWheelViewport::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

void RenderListWheelViewport::applyPaintTransform(RenderBox child, Matrix4 transform) {
    ListWheelParentData parentData = (;
    transform.translate(0.0, _getUntransformedPaintingCoordinateY(parentData.offset.dy));
}

Rect RenderListWheelViewport::describeApproximatePaintClip(RenderObject child) {
    if (_shouldClipAtCurrentOffset()) {
        return Offset.zero & size;
    }
    return nullptr;
}

bool RenderListWheelViewport::hitTestChildren(Offset position, BoxHitTestResult result) {
    return false;
}

RevealedOffset RenderListWheelViewport::getOffsetToReveal(double alignment, Rect rect, RenderObject target) {
    rect = target.paintBounds;
    RenderObject child = target;
    while (child.parent != this) {
        child = (;
    }
    ListWheelParentData parentData = (;
    double targetOffset = parentData.offset.dy;
    Matrix4 transform = target.getTransformTo(child);
    Rect bounds = MatrixUtils.transformRect(transform, rect);
    Rect targetRect = bounds.translate(0.0, (size.height - itemExtent) / 2);
    return RevealedOffset(targetOffset, targetRect);
}

void RenderListWheelViewport::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (descendant != nullptr) {
        RevealedOffset revealedOffset = getOffsetToReveal(descendant, 0.5rect);
        if (duration == Duration.zero) {
            offset.jumpTo(revealedOffset.offset);
        } else {
            offset.animateTo(revealedOffset.offsetduration, curve);
        }
        rect = revealedOffset.rect;
    }
    super.showOnScreen(rect, duration, curve);
}

void RenderListWheelViewport::_hasScrolled() {
    markNeedsLayout();
    markNeedsSemanticsUpdate();
}

double RenderListWheelViewport::_viewportExtent() {
    assert(hasSize);
    return size.height;
}

double RenderListWheelViewport::_minEstimatedScrollExtent() {
    assert(hasSize);
    if (childManager.childCount == nullptr) {
        return double.negativeInfinity;
    }
    return 0.0;
}

double RenderListWheelViewport::_maxEstimatedScrollExtent() {
    assert(hasSize);
    if (childManager.childCount == nullptr) {
        return double.infinity;
    }
    return math.max(0.0, (childManager.childCount! - 1) * _itemExtent);
}

double RenderListWheelViewport::_topScrollMarginExtent() {
    assert(hasSize);
    return -size.height / 2.0 + _itemExtent / 2.0;
}

double RenderListWheelViewport::_getUntransformedPaintingCoordinateY(double layoutCoordinateY) {
    return layoutCoordinateY - _topScrollMarginExtent - offset.pixels;
}

double RenderListWheelViewport::_maxVisibleRadian() {
    if ( < 1.0) {
        return math.pi / 2.0;
    }
    return math.asin(1.0 / _diameterRatio);
}

double RenderListWheelViewport::_getIntrinsicCrossAxis(_ChildSizingFunction childSize) {
    double extent = 0.0;
    RenderBox child = firstChild;
    while (child != nullptr) {
        extent = math.max(extent, childSize(child));
        child = childAfter(child);
    }
    return extent;
}

void RenderListWheelViewport::_createChild(RenderBox after, int index) {
    <BoxConstraints>invokeLayoutCallback();
}

void RenderListWheelViewport::_destroyChild(RenderBox child) {
    <BoxConstraints>invokeLayoutCallback();
}

void RenderListWheelViewport::_layoutChild(RenderBox child, BoxConstraints constraints, int index) {
    child.layout(constraintstrue);
    ListWheelParentData childParentData = (;
    double crossPosition = size.width / 2.0 - child.size.width / 2.0;
    childParentData.offset = Offset(crossPosition, indexToScrollOffset(index));
}

bool RenderListWheelViewport::_shouldClipAtCurrentOffset() {
    double highestUntransformedPaintY = _getUntransformedPaintingCoordinateY(0.0);
    return  < 0.0 || size.height < highestUntransformedPaintY + _maxEstimatedScrollExtent + _itemExtent;
}

void RenderListWheelViewport::_paintVisibleChildren(PaintingContext context, Offset offset) {
    RenderBox childToPaint = firstChild;
    while (childToPaint != nullptr) {
        ListWheelParentData childParentData = (;
        _paintTransformedChild(childToPaint, context, offset, childParentData.offset);
        childToPaint = childAfter(childToPaint);
    }
}

void RenderListWheelViewport::_paintTransformedChild(RenderBox child, PaintingContext context, Offset layoutOffset, Offset offset) {
    Offset untransformedPaintingCoordinates = offset + Offset(layoutOffset.dx, _getUntransformedPaintingCoordinateY(layoutOffset.dy));
    double fractionalY = (untransformedPaintingCoordinates.dy + _itemExtent / 2.0) / size.height;
    double angle = -(fractionalY - 0.5) * 2.0 * _maxVisibleRadian / squeeze;
    if (angle > math.pi / 2.0 ||  < -math.pi / 2.0) {
        return;
    }
    Matrix4 transform = MatrixUtils.createCylindricalProjectionTransform(size.height * _diameterRatio / 2.0, angle, _perspective);
    Offset offsetToCenter = Offset(untransformedPaintingCoordinates.dx, -_topScrollMarginExtent);
    bool shouldApplyOffCenterDim =  < 1;
    if (useMagnifier || shouldApplyOffCenterDim) {
        _paintChildWithMagnifier(context, offset, child, transform, offsetToCenter, untransformedPaintingCoordinates);
    } else {
        _paintChildCylindrically(context, offset, child, transform, offsetToCenter);
    }
}

void RenderListWheelViewport::_paintChildWithMagnifier(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter, Offset untransformedPaintingCoordinates) {
    double magnifierTopLinePosition = size.height / 2 - _itemExtent * _magnification / 2;
    double magnifierBottomLinePosition = size.height / 2 + _itemExtent * _magnification / 2;
    bool isAfterMagnifierTopLine = untransformedPaintingCoordinates.dy >= magnifierTopLinePosition - _itemExtent * _magnification;
    bool isBeforeMagnifierBottomLine = untransformedPaintingCoordinates.dy <= magnifierBottomLinePosition;
    if (isAfterMagnifierTopLine && isBeforeMagnifierBottomLine) {
        Rect centerRect = Rect.fromLTWH(0.0, magnifierTopLinePosition, size.width, _itemExtent * _magnification);
        Rect topHalfRect = Rect.fromLTWH(0.0, 0.0, size.width, magnifierTopLinePosition);
        Rect bottomHalfRect = Rect.fromLTWH(0.0, magnifierBottomLinePosition, size.width, magnifierTopLinePosition);
        context.pushClipRect(needsCompositing, offset, centerRect, );
        context.pushClipRect(needsCompositing, offset, untransformedPaintingCoordinates.dy <= magnifierTopLinePosition? topHalfRect : bottomHalfRect, );
    } else {
        _paintChildCylindrically(context, offset, child, cylindricalTransform, offsetToCenter);
    }
}

void RenderListWheelViewport::_paintChildCylindrically(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter) {
    ;
    ;
    context.pushTransform(needsCompositing, offset, _centerOriginTransform(cylindricalTransform), overAndUnderCenterOpacity == 1? painter : opacityPainter);
}

Matrix4 RenderListWheelViewport::_magnifyTransform() {
    Matrix4 magnify = Matrix4.identity();
    magnify.translate(size.width * (-_offAxisFraction + 0.5), size.height / 2);
    magnify.scale(_magnification, _magnification, _magnification);
    magnify.translate(-size.width * (-_offAxisFraction + 0.5), -size.height / 2);
    return magnify;
}

Matrix4 RenderListWheelViewport::_centerOriginTransform(Matrix4 originalMatrix) {
    Matrix4 result = Matrix4.identity();
    Offset centerOriginTranslation = Alignment.center.alongSize(size);
    result.translate(centerOriginTranslation.dx * (-_offAxisFraction * 2 + 1), centerOriginTranslation.dy);
    result.multiply(originalMatrix);
    result.translate(-centerOriginTranslation.dx * (-_offAxisFraction * 2 + 1), -centerOriginTranslation.dy);
    return result;
}
