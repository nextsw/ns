#include "single_child_scroll_view.hpp"
SingleChildScrollView::SingleChildScrollView(Widget child, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection) {
    {
        assert(scrollDirection != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(clipBehavior != nullptr);
        assert(!(controller != nullptr && (primary ?? false)), "Primary ScrollViews obtain their ScrollController via inheritance from a PrimaryScrollController widget. You cannot both set primary to true and pass an explicit controller.");
    }
}

Widget SingleChildScrollView::build(BuildContext context) {
    AxisDirection axisDirection = _getDirection(context);
    Widget contents = child;
    if (padding != nullptr) {
        contents = Padding(padding!, contents);
    }
    bool effectivePrimary = primary ?? controller == nullptr && PrimaryScrollController.shouldInherit(context, scrollDirection);
    ScrollController scrollController = effectivePrimary? PrimaryScrollController.of(context) : controller;
    Widget scrollable = Scrollable(dragStartBehavior, axisDirection, scrollController, physics, restorationId, );
    if (keyboardDismissBehavior == ScrollViewKeyboardDismissBehavior.onDrag) {
        scrollable = <ScrollUpdateNotification>NotificationListener(scrollable, );
    }
    return effectivePrimary && scrollController != nullptr? PrimaryScrollController.none(scrollable) : scrollable;
}

AxisDirection SingleChildScrollView::_getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, scrollDirection, reverse);
}

_RenderSingleChildViewport _SingleChildViewport::createRenderObject(BuildContext context) {
    return _RenderSingleChildViewport(axisDirection, offset, clipBehavior);
}

void _SingleChildViewport::updateRenderObject(BuildContext context, _RenderSingleChildViewport renderObject) {
    ;
}

SingleChildRenderObjectElement _SingleChildViewport::createElement() {
    return _SingleChildViewportElement(this);
}

_SingleChildViewport::_SingleChildViewport(AxisDirection axisDirection, Unknown, Clip clipBehavior, ViewportOffset offset) {
    {
        assert(axisDirection != nullptr);
        assert(clipBehavior != nullptr);
    }
}

AxisDirection _RenderSingleChildViewport::axisDirection() {
    return _axisDirection;
}

void _RenderSingleChildViewport::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _axisDirection) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

Axis _RenderSingleChildViewport::axis() {
    return axisDirectionToAxis(axisDirection);
}

ViewportOffset _RenderSingleChildViewport::offset() {
    return _offset;
}

void _RenderSingleChildViewport::offset(ViewportOffset value) {
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

double _RenderSingleChildViewport::cacheExtent() {
    return _cacheExtent;
}

void _RenderSingleChildViewport::cacheExtent(double value) {
    assert(value != nullptr);
    if (value == _cacheExtent) {
        return;
    }
    _cacheExtent = value;
    markNeedsLayout();
}

Clip _RenderSingleChildViewport::clipBehavior() {
    return _clipBehavior;
}

void _RenderSingleChildViewport::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void _RenderSingleChildViewport::setupParentData(RenderObject child) {
    if (child.parentData is! ParentData) {
        child.parentData = ParentData();
    }
}

void _RenderSingleChildViewport::attach(PipelineOwner owner) {
    super.attach(owner);
    _offset.addListener(_hasScrolled);
}

void _RenderSingleChildViewport::detach() {
    _offset.removeListener(_hasScrolled);
    super.detach();
}

bool _RenderSingleChildViewport::isRepaintBoundary() {
    return true;
}

double _RenderSingleChildViewport::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double _RenderSingleChildViewport::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double _RenderSingleChildViewport::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double _RenderSingleChildViewport::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!.getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

Size _RenderSingleChildViewport::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr) {
        return constraints.smallest;
    }
    Size childSize = child!.getDryLayout(_getInnerConstraints(constraints));
    return constraints.constrain(childSize);
}

void _RenderSingleChildViewport::performLayout() {
    BoxConstraints constraints = this.constraints;
    if (child == nullptr) {
        size = constraints.smallest;
    } else {
        child!.layout(_getInnerConstraints(constraints)true);
        size = constraints.constrain(child!.size);
    }
    offset.applyViewportDimension(_viewportExtent);
    offset.applyContentDimensions(_minScrollExtent, _maxScrollExtent);
}

void _RenderSingleChildViewport::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        Offset paintOffset = _paintOffset;
        ;
        if (_shouldClipAtPaintOffset(paintOffset)) {
            _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, paintContentsclipBehavior, _clipRectLayer.layer);
        } else {
            _clipRectLayer.layer = nullptr;
            paintContents(context, offset);
        }
    }
}

void _RenderSingleChildViewport::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

void _RenderSingleChildViewport::applyPaintTransform(RenderBox child, Matrix4 transform) {
    Offset paintOffset = _paintOffset;
    transform.translate(paintOffset.dx, paintOffset.dy);
}

Rect _RenderSingleChildViewport::describeApproximatePaintClip(RenderObject child) {
    if (child != nullptr && _shouldClipAtPaintOffset(_paintOffset)) {
        return Offset.zero & size;
    }
    return nullptr;
}

bool _RenderSingleChildViewport::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (child != nullptr) {
        return result.addWithPaintOffset(_paintOffset, position, );
    }
    return false;
}

RevealedOffset _RenderSingleChildViewport::getOffsetToReveal(double alignment, Rect rect, RenderObject target) {
    rect = target.paintBounds;
    if (target is! RenderBox) {
        return RevealedOffset(offset.pixels, rect);
    }
    RenderBox targetBox = target;
    Matrix4 transform = targetBox.getTransformTo(child);
    Rect bounds = MatrixUtils.transformRect(transform, rect);
    Size contentSize = child!.size;
    double leadingScrollOffset;
    double targetMainAxisExtent;
    double mainAxisExtent;
    assert(axisDirection != nullptr);
    ;
    double targetOffset = leadingScrollOffset - (mainAxisExtent - targetMainAxisExtent) * alignment;
    Rect targetRect = bounds.shift(_paintOffsetForPosition(targetOffset));
    return RevealedOffset(targetOffset, targetRect);
}

void _RenderSingleChildViewport::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (!offset.allowImplicitScrolling) {
        return super.showOnScreen(descendant, rect, duration, curve);
    }
    Rect newRect = RenderViewportBase.showInViewport(descendant, this, offset, rect, duration, curve);
    super.showOnScreen(newRect, duration, curve);
}

void _RenderSingleChildViewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("offset", _paintOffset));
}

Rect _RenderSingleChildViewport::describeSemanticsClip(RenderObject child) {
    assert(axis != nullptr);
    ;
}

_RenderSingleChildViewport::_RenderSingleChildViewport(AxisDirection axisDirection, double cacheExtent, RenderBox child, Clip clipBehavior, ViewportOffset offset) {
    {
        assert(axisDirection != nullptr);
        assert(offset != nullptr);
        assert(cacheExtent != nullptr);
        assert(clipBehavior != nullptr);
        _axisDirection = axisDirection;
        _offset = offset;
        _cacheExtent = cacheExtent;
        _clipBehavior = clipBehavior;
    }
    {
        this.child = child;
    }
}

void _RenderSingleChildViewport::_hasScrolled() {
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

double _RenderSingleChildViewport::_viewportExtent() {
    assert(hasSize);
    ;
}

double _RenderSingleChildViewport::_minScrollExtent() {
    assert(hasSize);
    return 0.0;
}

double _RenderSingleChildViewport::_maxScrollExtent() {
    assert(hasSize);
    if (child == nullptr) {
        return 0.0;
    }
    ;
}

BoxConstraints _RenderSingleChildViewport::_getInnerConstraints(BoxConstraints constraints) {
    ;
}

Offset _RenderSingleChildViewport::_paintOffset() {
    return _paintOffsetForPosition(offset.pixels);
}

Offset _RenderSingleChildViewport::_paintOffsetForPosition(double position) {
    assert(axisDirection != nullptr);
    ;
}

bool _RenderSingleChildViewport::_shouldClipAtPaintOffset(Offset paintOffset) {
    assert(child != nullptr);
    ;
}
