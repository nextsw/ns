#include "single_child_scroll_view.hpp"
SingleChildScrollViewCls::SingleChildScrollViewCls(Widget child, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection) {
    {
        assert(scrollDirection != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(clipBehavior != nullptr);
        assert(!(controller != nullptr && (primary or false)), __s("Primary ScrollViews obtain their ScrollController via inheritance from a PrimaryScrollController widget. You cannot both set primary to true and pass an explicit controller."));
    }
}

Widget SingleChildScrollViewCls::build(BuildContext context) {
    AxisDirection axisDirection = _getDirection(context);
    Widget contents = child;
    if (padding != nullptr) {
        contents = make<PaddingCls>(padding!, contents);
    }
    bool effectivePrimary = primary or controller == nullptr && PrimaryScrollControllerCls->shouldInherit(context, scrollDirection);
    ScrollController scrollController = effectivePrimary? PrimaryScrollControllerCls->of(context) : controller;
    Widget scrollable = make<ScrollableCls>(dragStartBehavior, axisDirection, scrollController, physics, restorationId, [=] (BuildContext context,ViewportOffset offset) {
    return make<_SingleChildViewportCls>(axisDirection, offset, clipBehavior, contents);
});
    if (keyboardDismissBehavior == ScrollViewKeyboardDismissBehaviorCls::onDrag) {
        scrollable = <ScrollUpdateNotification>make<NotificationListenerCls>(scrollable, [=] (ScrollUpdateNotification notification) {
            FocusScopeNode focusNode = FocusScopeCls->of(context);
            if (notification->dragDetails != nullptr && focusNode->hasFocus) {
                focusNode->unfocus();
            }
            return false;
        });
    }
    return effectivePrimary && scrollController != nullptr? PrimaryScrollControllerCls->none(scrollable) : scrollable;
}

AxisDirection SingleChildScrollViewCls::_getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, scrollDirection, reverse);
}

_RenderSingleChildViewport _SingleChildViewportCls::createRenderObject(BuildContext context) {
    return make<_RenderSingleChildViewportCls>(axisDirection, offset, clipBehavior);
}

void _SingleChildViewportCls::updateRenderObject(BuildContext context, _RenderSingleChildViewport renderObject) {
    auto _c1 = renderObject;_c1.axisDirection = auto _c2 = axisDirection;_c2.offset = auto _c3 = offset;_c3.clipBehavior = clipBehavior;_c3;_c2;_c1;
}

SingleChildRenderObjectElement _SingleChildViewportCls::createElement() {
    return make<_SingleChildViewportElementCls>(this);
}

_SingleChildViewportCls::_SingleChildViewportCls(AxisDirection axisDirection, Unknown child, Clip clipBehavior, ViewportOffset offset) {
    {
        assert(axisDirection != nullptr);
        assert(clipBehavior != nullptr);
    }
}

AxisDirection _RenderSingleChildViewportCls::axisDirection() {
    return _axisDirection;
}

void _RenderSingleChildViewportCls::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _axisDirection) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

Axis _RenderSingleChildViewportCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

ViewportOffset _RenderSingleChildViewportCls::offset() {
    return _offset;
}

void _RenderSingleChildViewportCls::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    if (attached) {
        _offset->removeListener(_hasScrolled);
    }
    _offset = value;
    if (attached) {
        _offset->addListener(_hasScrolled);
    }
    markNeedsLayout();
}

double _RenderSingleChildViewportCls::cacheExtent() {
    return _cacheExtent;
}

void _RenderSingleChildViewportCls::cacheExtent(double value) {
    assert(value != nullptr);
    if (value == _cacheExtent) {
        return;
    }
    _cacheExtent = value;
    markNeedsLayout();
}

Clip _RenderSingleChildViewportCls::clipBehavior() {
    return _clipBehavior;
}

void _RenderSingleChildViewportCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void _RenderSingleChildViewportCls::setupParentData(RenderObject child) {
    if (!is<ParentData>(child->parentData)) {
        child->parentData = make<ParentDataCls>();
    }
}

void _RenderSingleChildViewportCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _offset->addListener(_hasScrolled);
}

void _RenderSingleChildViewportCls::detach() {
    _offset->removeListener(_hasScrolled);
    super->detach();
}

bool _RenderSingleChildViewportCls::isRepaintBoundary() {
    return true;
}

double _RenderSingleChildViewportCls::computeMinIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMinIntrinsicWidth(height);
    }
    return 0.0;
}

double _RenderSingleChildViewportCls::computeMaxIntrinsicWidth(double height) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicWidth(height);
    }
    return 0.0;
}

double _RenderSingleChildViewportCls::computeMinIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMinIntrinsicHeight(width);
    }
    return 0.0;
}

double _RenderSingleChildViewportCls::computeMaxIntrinsicHeight(double width) {
    if (child != nullptr) {
        return child!->getMaxIntrinsicHeight(width);
    }
    return 0.0;
}

Size _RenderSingleChildViewportCls::computeDryLayout(BoxConstraints constraints) {
    if (child == nullptr) {
        return constraints->smallest();
    }
    Size childSize = child!->getDryLayout(_getInnerConstraints(constraints));
    return constraints->constrain(childSize);
}

void _RenderSingleChildViewportCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    if (child == nullptr) {
        size = constraints->smallest();
    } else {
        child!->layout(_getInnerConstraints(constraints)true);
        size = constraints->constrain(child!->size);
    }
    offset->applyViewportDimension(_viewportExtent());
    offset->applyContentDimensions(_minScrollExtent(), _maxScrollExtent());
}

void _RenderSingleChildViewportCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        Offset paintOffset = _paintOffset();
        InlineMethod;
        if (_shouldClipAtPaintOffset(paintOffset)) {
            _clipRectLayer->layer = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, paintContentsclipBehavior, _clipRectLayer->layer);
        } else {
            _clipRectLayer->layer = nullptr;
            paintContents(context, offset);
        }
    }
}

void _RenderSingleChildViewportCls::dispose() {
    _clipRectLayer->layer = nullptr;
    super->dispose();
}

void _RenderSingleChildViewportCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    Offset paintOffset = _paintOffset();
    transform->translate(paintOffset->dx, paintOffset->dy);
}

Rect _RenderSingleChildViewportCls::describeApproximatePaintClip(RenderObject child) {
    if (child != nullptr && _shouldClipAtPaintOffset(_paintOffset())) {
        return OffsetCls::zero & size;
    }
    return nullptr;
}

bool _RenderSingleChildViewportCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (child != nullptr) {
        return result->addWithPaintOffset(_paintOffset(), position, [=] (BoxHitTestResult result,Offset transformed) {
            assert(transformed == position + -_paintOffset());
            return child!->hitTest(resulttransformed);
        });
    }
    return false;
}

RevealedOffset _RenderSingleChildViewportCls::getOffsetToReveal(double alignment, Rect rect, RenderObject target) {
    rect = target->paintBounds();
    if (!is<RenderBox>(target)) {
        return make<RevealedOffsetCls>(offset->pixels, rect);
    }
    RenderBox targetBox = target;
    Matrix4 transform = targetBox->getTransformTo(child);
    Rect bounds = MatrixUtilsCls->transformRect(transform, rect);
    Size contentSize = child!->size;
    double leadingScrollOffset;
    double targetMainAxisExtent;
    double mainAxisExtent;
    assert(axisDirection != nullptr);
    ;
    double targetOffset = leadingScrollOffset - (mainAxisExtent - targetMainAxisExtent) * alignment;
    Rect targetRect = bounds->shift(_paintOffsetForPosition(targetOffset));
    return make<RevealedOffsetCls>(targetOffset, targetRect);
}

void _RenderSingleChildViewportCls::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (!offset->allowImplicitScrolling) {
        return super->showOnScreen(descendant, rect, duration, curve);
    }
    Rect newRect = RenderViewportBaseCls->showInViewport(descendant, this, offset, rect, duration, curve);
    super->showOnScreen(newRect, duration, curve);
}

void _RenderSingleChildViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), _paintOffset()));
}

Rect _RenderSingleChildViewportCls::describeSemanticsClip(RenderObject child) {
    assert(axis != nullptr);
    ;
}

_RenderSingleChildViewportCls::_RenderSingleChildViewportCls(AxisDirection axisDirection, double cacheExtent, RenderBox child, Clip clipBehavior, ViewportOffset offset) {
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
        this->child = child;
    }
}

void _RenderSingleChildViewportCls::_hasScrolled() {
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

double _RenderSingleChildViewportCls::_viewportExtent() {
    assert(hasSize);
    ;
}

double _RenderSingleChildViewportCls::_minScrollExtent() {
    assert(hasSize);
    return 0.0;
}

double _RenderSingleChildViewportCls::_maxScrollExtent() {
    assert(hasSize);
    if (child == nullptr) {
        return 0.0;
    }
    ;
}

BoxConstraints _RenderSingleChildViewportCls::_getInnerConstraints(BoxConstraints constraints) {
    ;
}

Offset _RenderSingleChildViewportCls::_paintOffset() {
    return _paintOffsetForPosition(offset->pixels);
}

Offset _RenderSingleChildViewportCls::_paintOffsetForPosition(double position) {
    assert(axisDirection != nullptr);
    ;
}

bool _RenderSingleChildViewportCls::_shouldClipAtPaintOffset(Offset paintOffset) {
    assert(child != nullptr);
    ;
}
