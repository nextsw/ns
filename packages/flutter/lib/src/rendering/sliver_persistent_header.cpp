#include "sliver_persistent_header.hpp"
Rect _trim(Rect original, double bottom, double left, double right, double top) {
    return original?->intersect(RectCls->fromLTRB(left, top, right, bottom));
}

OverScrollHeaderStretchConfigurationCls::OverScrollHeaderStretchConfigurationCls(AsyncCallback onStretchTrigger, double stretchTriggerOffset) {
    {
        assert(stretchTriggerOffset != nullptr);
    }
}

PersistentHeaderShowOnScreenConfigurationCls::PersistentHeaderShowOnScreenConfigurationCls(double maxShowOnScreenExtent, double minShowOnScreenExtent) {
    {
        assert(minShowOnScreenExtent <= maxShowOnScreenExtent);
    }
}

RenderSliverPersistentHeaderCls::RenderSliverPersistentHeaderCls(RenderBox child, OverScrollHeaderStretchConfiguration stretchConfiguration) {
    {
        this->child = child;
    }
}

double RenderSliverPersistentHeaderCls::childExtent() {
    if (child == nullptr) {
        return 0.0;
    }
    assert(child!->hasSize);
    assert(constraints()->axis() != nullptr);
    ;
}

void RenderSliverPersistentHeaderCls::updateChild(double shrinkOffset, bool overlapsContent) {
}

void RenderSliverPersistentHeaderCls::markNeedsLayout() {
    _needsUpdateChild = true;
    super->markNeedsLayout();
}

void RenderSliverPersistentHeaderCls::layoutChild(double scrollOffset, double maxExtent, bool overlapsContent) {
    assert(maxExtent != nullptr);
    double shrinkOffset = math->min(scrollOffset, maxExtent);
    if (_needsUpdateChild || _lastShrinkOffset != shrinkOffset || _lastOverlapsContent != overlapsContent) {
        <SliverConstraints>invokeLayoutCallback([=] (SliverConstraints constraints) {
            assert(constraints() == this->constraints());
            updateChild(shrinkOffset, overlapsContent);
        });
        _lastShrinkOffset = shrinkOffset;
        _lastOverlapsContent = overlapsContent;
        _needsUpdateChild = false;
    }
    assert(minExtent() != nullptr);
    assert([=] () {
        if (minExtent() <= maxExtent) {
            return true;
        }
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
    }());
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr && constraints()->scrollOffset == 0.0) {
        stretchOffset += constraints()->overlap->abs();
    }
    child?->layout(constraints()->asBoxConstraints(math->max(minExtent(), maxExtent - shrinkOffset) + stretchOffset), true);
    if (stretchConfiguration != nullptr && stretchConfiguration!->onStretchTrigger != nullptr && stretchOffset >= stretchConfiguration!->stretchTriggerOffset && _lastStretchOffset <= stretchConfiguration!->stretchTriggerOffset) {
        stretchConfiguration!->onStretchTrigger!();
    }
    _lastStretchOffset = stretchOffset;
}

double RenderSliverPersistentHeaderCls::childMainAxisPosition(RenderObject child) {
    return super->childMainAxisPosition(child);
}

bool RenderSliverPersistentHeaderCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    assert(geometry()!->hitTestExtent > 0.0);
    if (child != nullptr) {
        return hitTestBoxChild(BoxHitTestResultCls->wrap(result), child!, mainAxisPosition, crossAxisPosition);
    }
    return false;
}

void RenderSliverPersistentHeaderCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this->child);
    applyPaintTransformForBoxChild(as<RenderBox>(child), transform);
}

void RenderSliverPersistentHeaderCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && geometry()!->visible) {
        assert(constraints()->axisDirection != nullptr);
        ;
        context->paintChild(child!, offset);
    }
}

void RenderSliverPersistentHeaderCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->addTagForChildren(RenderViewportCls::excludeFromScrolling);
}

void RenderSliverPersistentHeaderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(DoublePropertyCls->lazy(__s("maxExtent"), [=] () {
        maxExtent();
    }));
    properties->add(DoublePropertyCls->lazy(__s("child position"), [=] () {
        childMainAxisPosition(child!);
    }));
}

double RenderSliverScrollingPersistentHeaderCls::updateGeometry() {
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr) {
        stretchOffset += constraints()->overlap->abs();
    }
    double maxExtent = this->maxExtent();
    double paintExtent = maxExtent - constraints()->scrollOffset;
    geometry() = make<SliverGeometryCls>(maxExtent, math->min(constraints()->overlap, 0.0), clampDouble(paintExtent, 0.0, constraints()->remainingPaintExtent), maxExtent + stretchOffset, true);
    return stretchOffset > 0? 0.0 : math->min(0.0, paintExtent - childExtent());
}

void RenderSliverScrollingPersistentHeaderCls::performLayout() {
    SliverConstraints constraints = this->constraints();
    double maxExtent = this->maxExtent();
    layoutChild(constraints->scrollOffset, maxExtent);
    double paintExtent = maxExtent - constraints->scrollOffset;
    geometry() = make<SliverGeometryCls>(maxExtent, math->min(constraints->overlap, 0.0), clampDouble(paintExtent, 0.0, constraints->remainingPaintExtent), maxExtent, true);
    _childPosition = updateGeometry();
}

double RenderSliverScrollingPersistentHeaderCls::childMainAxisPosition(RenderBox child) {
    assert(child == this->child);
    assert(_childPosition != nullptr);
    return _childPosition!;
}

void RenderSliverPinnedPersistentHeaderCls::performLayout() {
    SliverConstraints constraints = this->constraints();
    double maxExtent = this->maxExtent();
    bool overlapsContent = constraints->overlap > 0.0;
    layoutChild(constraints->scrollOffset, maxExtent, overlapsContent);
    double effectiveRemainingPaintExtent = math->max(0, constraints->remainingPaintExtent - constraints->overlap);
    double layoutExtent = clampDouble(maxExtent - constraints->scrollOffset, 0.0, effectiveRemainingPaintExtent);
    double stretchOffset = stretchConfiguration != nullptr? constraints->overlap->abs() : 0.0;
    geometry() = make<SliverGeometryCls>(maxExtent, constraints->overlap, math->min(childExtent(), effectiveRemainingPaintExtent), layoutExtent, maxExtent + stretchOffset, minExtent(), layoutExtent > 0.0? -constraints->cacheOrigin + layoutExtent : layoutExtent, true);
}

double RenderSliverPinnedPersistentHeaderCls::childMainAxisPosition(RenderBox child) {
    return 0.0;
}

void RenderSliverPinnedPersistentHeaderCls::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    Rect localBounds = descendant != nullptr? MatrixUtilsCls->transformRect(descendant->getTransformTo(this), rect | descendant->paintBounds()) : rect;
    Rect newRect;
    ;
    super->showOnScreen(this, newRect, duration, curve);
}

FloatingHeaderSnapConfigurationCls::FloatingHeaderSnapConfigurationCls(Curve curve, Duration duration) {
    {
        assert(curve != nullptr);
        assert(duration != nullptr);
    }
}

RenderSliverFloatingPersistentHeaderCls::RenderSliverFloatingPersistentHeaderCls(Unknown child, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, Unknown stretchConfiguration, TickerProvider vsync) {
    {
        _vsync = vsync;
    }
}

void RenderSliverFloatingPersistentHeaderCls::detach() {
    _controller?->dispose();
    _controller = nullptr;
    super->detach();
}

TickerProvider RenderSliverFloatingPersistentHeaderCls::vsync() {
    return _vsync;
}

void RenderSliverFloatingPersistentHeaderCls::vsync(TickerProvider value) {
    if (value == _vsync) {
        return;
    }
    _vsync = value;
    if (value == nullptr) {
        _controller?->dispose();
        _controller = nullptr;
    } else {
        _controller?->resync(value);
    }
}

double RenderSliverFloatingPersistentHeaderCls::updateGeometry() {
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr) {
        stretchOffset += constraints()->overlap->abs();
    }
    double maxExtent = this->maxExtent();
    double paintExtent = maxExtent - _effectiveScrollOffset!;
    double layoutExtent = maxExtent - constraints()->scrollOffset;
    geometry() = make<SliverGeometryCls>(maxExtent, math->min(constraints()->overlap, 0.0), clampDouble(paintExtent, 0.0, constraints()->remainingPaintExtent), clampDouble(layoutExtent, 0.0, constraints()->remainingPaintExtent), maxExtent + stretchOffset, true);
    return stretchOffset > 0? 0.0 : math->min(0.0, paintExtent - childExtent());
}

void RenderSliverFloatingPersistentHeaderCls::updateScrollStartDirection(ScrollDirection direction) {
    _lastStartedScrollDirection = direction;
}

void RenderSliverFloatingPersistentHeaderCls::maybeStartSnapAnimation(ScrollDirection direction) {
    FloatingHeaderSnapConfiguration snap = snapConfiguration;
    if (snap == nullptr) {
        return;
    }
    if (direction == ScrollDirectionCls::forward && _effectiveScrollOffset! <= 0.0) {
        return;
    }
    if (direction == ScrollDirectionCls::reverse && _effectiveScrollOffset! >= maxExtent()) {
        return;
    }
    _updateAnimation(snap->duration, direction == ScrollDirectionCls::forward? 0.0 : maxExtent(), snap->curve);
    _controller?->forward(0.0);
}

void RenderSliverFloatingPersistentHeaderCls::maybeStopSnapAnimation(ScrollDirection direction) {
    _controller?->stop();
}

void RenderSliverFloatingPersistentHeaderCls::performLayout() {
    SliverConstraints constraints = this->constraints();
    double maxExtent = this->maxExtent();
    if (_lastActualScrollOffset != nullptr && ((constraints->scrollOffset < _lastActualScrollOffset!) || (_effectiveScrollOffset! < maxExtent))) {
        double delta = _lastActualScrollOffset! - constraints->scrollOffset;
        bool allowFloatingExpansion = constraints->userScrollDirection == ScrollDirectionCls::forward || (_lastStartedScrollDirection != nullptr && _lastStartedScrollDirection == ScrollDirectionCls::forward);
        if (allowFloatingExpansion) {
            if (_effectiveScrollOffset! > maxExtent) {
                _effectiveScrollOffset = maxExtent;
            }
        } else {
            if (delta > 0.0) {
                delta = 0.0;
            }
        }
        _effectiveScrollOffset = clampDouble(_effectiveScrollOffset! - delta, 0.0, constraints->scrollOffset);
    } else {
        _effectiveScrollOffset = constraints->scrollOffset;
    }
    bool overlapsContent = _effectiveScrollOffset! < constraints->scrollOffset;
    layoutChild(_effectiveScrollOffset!, maxExtent, overlapsContent);
    _childPosition = updateGeometry();
    _lastActualScrollOffset = constraints->scrollOffset;
}

void RenderSliverFloatingPersistentHeaderCls::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    PersistentHeaderShowOnScreenConfiguration showOnScreen = showOnScreenConfiguration;
    if (showOnScreen == nullptr) {
        return super->showOnScreen(descendant, rect, duration, curve);
    }
    assert(child != nullptr || descendant == nullptr);
    Rect childBounds = descendant != nullptr? MatrixUtilsCls->transformRect(descendant->getTransformTo(child), rect | descendant->paintBounds()) : rect;
    double targetExtent;
    Rect targetRect;
    ;
    double effectiveMaxExtent = math->max(childExtent(), maxExtent());
    targetExtent = clampDouble(clampDouble(targetExtent, showOnScreen->minShowOnScreenExtent, showOnScreen->maxShowOnScreenExtent), childExtent(), effectiveMaxExtent);
    if (targetExtent > childExtent()) {
        double targetScrollOffset = maxExtent() - targetExtent;
        assert(vsync() != nullptr, __s("vsync must not be null if the floating header changes size animatedly."));
        _updateAnimation(duration, targetScrollOffset, curve);
        _controller?->forward(0.0);
    }
    super->showOnScreen(descendant == nullptr? this : child, targetRect, duration, curve);
}

double RenderSliverFloatingPersistentHeaderCls::childMainAxisPosition(RenderBox child) {
    assert(child == this->child);
    return _childPosition | 0.0;
}

void RenderSliverFloatingPersistentHeaderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("effective scroll offset"), _effectiveScrollOffset));
}

void RenderSliverFloatingPersistentHeaderCls::_updateAnimation(Duration duration, double endValue, Curve curve) {
    assert(duration != nullptr);
    assert(endValue != nullptr);
    assert(curve != nullptr);
    assert(vsync() != nullptr, __s("vsync must not be null if the floating header changes size animatedly."));
    });AnimationController effectiveController = _controller ??=     }    auto _c1 = make<AnimationControllerCls>(vsync()!, duration);    _c1.addListener([=] () {        if (_effectiveScrollOffset == _animation->value()) {            return;    _effectiveScrollOffset = _animation->value();    markNeedsLayout();_c1;
    _animation = effectiveController->drive(<double>make<TweenCls>(_effectiveScrollOffset, endValue)->chain(make<CurveTweenCls>(curve)));
}

double RenderSliverFloatingPinnedPersistentHeaderCls::updateGeometry() {
    double minExtent = this->minExtent();
    double minAllowedExtent = constraints()->remainingPaintExtent > minExtent? minExtent : constraints()->remainingPaintExtent;
    double maxExtent = this->maxExtent();
    double paintExtent = maxExtent - _effectiveScrollOffset!;
    double clampedPaintExtent = clampDouble(paintExtent, minAllowedExtent, constraints()->remainingPaintExtent);
    double layoutExtent = maxExtent - constraints()->scrollOffset;
    double stretchOffset = stretchConfiguration != nullptr? constraints()->overlap->abs() : 0.0;
    geometry() = make<SliverGeometryCls>(maxExtent, math->min(constraints()->overlap, 0.0), clampedPaintExtent, clampDouble(layoutExtent, 0.0, clampedPaintExtent), maxExtent + stretchOffset, minExtent, true);
    return 0.0;
}
