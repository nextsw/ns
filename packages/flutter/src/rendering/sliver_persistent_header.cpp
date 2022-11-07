#include "sliver_persistent_header.hpp"
Rect _trim(double bottom, double left, Rect original, double right, double top) {
    return original?.intersect(Rect.fromLTRB(left, top, right, bottom));
}

OverScrollHeaderStretchConfiguration::OverScrollHeaderStretchConfiguration(AsyncCallback onStretchTrigger, double stretchTriggerOffset) {
    {
        assert(stretchTriggerOffset != nullptr);
    }
}

PersistentHeaderShowOnScreenConfiguration::PersistentHeaderShowOnScreenConfiguration(double maxShowOnScreenExtent, double minShowOnScreenExtent) {
    {
        assert(minShowOnScreenExtent <= maxShowOnScreenExtent);
    }
}

RenderSliverPersistentHeader::RenderSliverPersistentHeader(RenderBox child, OverScrollHeaderStretchConfiguration stretchConfiguration) {
    {
        this.child = child;
    }
}

double RenderSliverPersistentHeader::childExtent() {
    if (child == nullptr) {
        return 0.0;
    }
    assert(child!.hasSize);
    assert(constraints.axis != nullptr);
    ;
}

void RenderSliverPersistentHeader::updateChild(bool overlapsContent, double shrinkOffset) {
}

void RenderSliverPersistentHeader::markNeedsLayout() {
    _needsUpdateChild = true;
    super.markNeedsLayout();
}

void RenderSliverPersistentHeader::layoutChild(double maxExtent, bool overlapsContent, double scrollOffset) {
    assert(maxExtent != nullptr);
    double shrinkOffset = math.min(scrollOffset, maxExtent);
    if (_needsUpdateChild || _lastShrinkOffset != shrinkOffset || _lastOverlapsContent != overlapsContent) {
        <SliverConstraints>invokeLayoutCallback();
        _lastShrinkOffset = shrinkOffset;
        _lastOverlapsContent = overlapsContent;
        _needsUpdateChild = false;
    }
    assert(minExtent != nullptr);
    assert(());
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr && constraints.scrollOffset == 0.0) {
        stretchOffset = constraints.overlap.abs();
    }
    child?.layout(constraints.asBoxConstraints(math.max(minExtent, maxExtent - shrinkOffset) + stretchOffset)true);
    if (stretchConfiguration != nullptr && stretchConfiguration!.onStretchTrigger != nullptr && stretchOffset >= stretchConfiguration!.stretchTriggerOffset && _lastStretchOffset <= stretchConfiguration!.stretchTriggerOffset) {
        stretchConfiguration!.onStretchTrigger!();
    }
    _lastStretchOffset = stretchOffset;
}

double RenderSliverPersistentHeader::childMainAxisPosition(RenderObject child) {
    return super.childMainAxisPosition(child);
}

bool RenderSliverPersistentHeader::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    assert(geometry!.hitTestExtent > 0.0);
    if (child != nullptr) {
        return hitTestBoxChild(BoxHitTestResult.wrap(result), child!mainAxisPosition, crossAxisPosition);
    }
    return false;
}

void RenderSliverPersistentHeader::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this.child);
    applyPaintTransformForBoxChild((, transform);
}

void RenderSliverPersistentHeader::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && geometry!.visible) {
        assert(constraints.axisDirection != nullptr);
        ;
        context.paintChild(child!, offset);
    }
}

void RenderSliverPersistentHeader::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.addTagForChildren(RenderViewport.excludeFromScrolling);
}

void RenderSliverPersistentHeader::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty.lazy("maxExtent", ));
    properties.add(DoubleProperty.lazy("child position", ));
}

double RenderSliverScrollingPersistentHeader::updateGeometry() {
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr) {
        stretchOffset = constraints.overlap.abs();
    }
    double maxExtent = this.maxExtent;
    double paintExtent = maxExtent - constraints.scrollOffset;
    geometry = SliverGeometry(maxExtent, math.min(constraints.overlap, 0.0), clampDouble(paintExtent, 0.0, constraints.remainingPaintExtent), maxExtent + stretchOffset, true);
    return stretchOffset > 0? 0.0 : math.min(0.0, paintExtent - childExtent);
}

void RenderSliverScrollingPersistentHeader::performLayout() {
    SliverConstraints constraints = this.constraints;
    double maxExtent = this.maxExtent;
    layoutChild(constraints.scrollOffset, maxExtent);
    double paintExtent = maxExtent - constraints.scrollOffset;
    geometry = SliverGeometry(maxExtent, math.min(constraints.overlap, 0.0), clampDouble(paintExtent, 0.0, constraints.remainingPaintExtent), maxExtent, true);
    _childPosition = updateGeometry();
}

double RenderSliverScrollingPersistentHeader::childMainAxisPosition(RenderBox child) {
    assert(child == this.child);
    assert(_childPosition != nullptr);
    return _childPosition!;
}

void RenderSliverPinnedPersistentHeader::performLayout() {
    SliverConstraints constraints = this.constraints;
    double maxExtent = this.maxExtent;
    bool overlapsContent = constraints.overlap > 0.0;
    layoutChild(constraints.scrollOffset, maxExtentoverlapsContent);
    double effectiveRemainingPaintExtent = math.max(0, constraints.remainingPaintExtent - constraints.overlap);
    double layoutExtent = clampDouble(maxExtent - constraints.scrollOffset, 0.0, effectiveRemainingPaintExtent);
    double stretchOffset = stretchConfiguration != nullptr? constraints.overlap.abs() : 0.0;
    geometry = SliverGeometry(maxExtent, constraints.overlap, math.min(childExtent, effectiveRemainingPaintExtent), layoutExtent, maxExtent + stretchOffset, minExtent, layoutExtent > 0.0? -constraints.cacheOrigin + layoutExtent : layoutExtent, true);
}

double RenderSliverPinnedPersistentHeader::childMainAxisPosition(RenderBox child) {
    return 0.0;
}

void RenderSliverPinnedPersistentHeader::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    Rect localBounds = descendant != nullptr? MatrixUtils.transformRect(descendant.getTransformTo(this), rect ?? descendant.paintBounds) : rect;
    Rect newRect;
    ;
    super.showOnScreen(this, newRect, duration, curve);
}

FloatingHeaderSnapConfiguration::FloatingHeaderSnapConfiguration(Curve curve, Duration duration) {
    {
        assert(curve != nullptr);
        assert(duration != nullptr);
    }
}

RenderSliverFloatingPersistentHeader::RenderSliverFloatingPersistentHeader(Unknown, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, Unknown, TickerProvider vsync) {
    {
        _vsync = vsync;
    }
}

void RenderSliverFloatingPersistentHeader::detach() {
    _controller?.dispose();
    _controller = nullptr;
    super.detach();
}

TickerProvider RenderSliverFloatingPersistentHeader::vsync() {
    return _vsync;
}

void RenderSliverFloatingPersistentHeader::vsync(TickerProvider value) {
    if (value == _vsync) {
        return;
    }
    _vsync = value;
    if (value == nullptr) {
        _controller?.dispose();
        _controller = nullptr;
    } else {
        _controller?.resync(value);
    }
}

double RenderSliverFloatingPersistentHeader::updateGeometry() {
    double stretchOffset = 0.0;
    if (stretchConfiguration != nullptr) {
        stretchOffset = constraints.overlap.abs();
    }
    double maxExtent = this.maxExtent;
    double paintExtent = maxExtent - _effectiveScrollOffset!;
    double layoutExtent = maxExtent - constraints.scrollOffset;
    geometry = SliverGeometry(maxExtent, math.min(constraints.overlap, 0.0), clampDouble(paintExtent, 0.0, constraints.remainingPaintExtent), clampDouble(layoutExtent, 0.0, constraints.remainingPaintExtent), maxExtent + stretchOffset, true);
    return stretchOffset > 0? 0.0 : math.min(0.0, paintExtent - childExtent);
}

void RenderSliverFloatingPersistentHeader::updateScrollStartDirection(ScrollDirection direction) {
    _lastStartedScrollDirection = direction;
}

void RenderSliverFloatingPersistentHeader::maybeStartSnapAnimation(ScrollDirection direction) {
    FloatingHeaderSnapConfiguration snap = snapConfiguration;
    if (snap == nullptr) {
        return;
    }
    if (direction == ScrollDirection.forward && _effectiveScrollOffset! <= 0.0) {
        return;
    }
    if (direction == ScrollDirection.reverse && _effectiveScrollOffset! >= maxExtent) {
        return;
    }
    _updateAnimation(snap.duration, direction == ScrollDirection.forward? 0.0 : maxExtent, snap.curve);
    _controller?.forward(0.0);
}

void RenderSliverFloatingPersistentHeader::maybeStopSnapAnimation(ScrollDirection direction) {
    _controller?.stop();
}

void RenderSliverFloatingPersistentHeader::performLayout() {
    SliverConstraints constraints = this.constraints;
    double maxExtent = this.maxExtent;
    if (_lastActualScrollOffset != nullptr && ((constraints.scrollOffset < _lastActualScrollOffset!) || (_effectiveScrollOffset! < maxExtent))) {
        double delta = _lastActualScrollOffset! - constraints.scrollOffset;
        bool allowFloatingExpansion = constraints.userScrollDirection == ScrollDirection.forward || (_lastStartedScrollDirection != nullptr && _lastStartedScrollDirection == ScrollDirection.forward);
        if (allowFloatingExpansion) {
            if (_effectiveScrollOffset! > maxExtent) {
                _effectiveScrollOffset = maxExtent;
            }
        } else {
            if (delta > 0.0) {
                delta = 0.0;
            }
        }
        _effectiveScrollOffset = clampDouble(_effectiveScrollOffset! - delta, 0.0, constraints.scrollOffset);
    } else {
        _effectiveScrollOffset = constraints.scrollOffset;
    }
    bool overlapsContent = _effectiveScrollOffset! < constraints.scrollOffset;
    layoutChild(_effectiveScrollOffset!, maxExtentoverlapsContent);
    _childPosition = updateGeometry();
    _lastActualScrollOffset = constraints.scrollOffset;
}

void RenderSliverFloatingPersistentHeader::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    PersistentHeaderShowOnScreenConfiguration showOnScreen = showOnScreenConfiguration;
    if (showOnScreen == nullptr) {
        return super.showOnScreen(descendant, rect, duration, curve);
    }
    assert(child != nullptr || descendant == nullptr);
    Rect childBounds = descendant != nullptr? MatrixUtils.transformRect(descendant.getTransformTo(child), rect ?? descendant.paintBounds) : rect;
    double targetExtent;
    Rect targetRect;
    ;
    double effectiveMaxExtent = math.max(childExtent, maxExtent);
    targetExtent = clampDouble(clampDouble(targetExtent, showOnScreen.minShowOnScreenExtent, showOnScreen.maxShowOnScreenExtent), childExtent, effectiveMaxExtent);
    if (targetExtent > childExtent) {
        double targetScrollOffset = maxExtent - targetExtent;
        assert(vsync != nullptr, "vsync must not be null if the floating header changes size animatedly.");
        _updateAnimation(duration, targetScrollOffset, curve);
        _controller?.forward(0.0);
    }
    super.showOnScreen(descendant == nullptr? this : child, targetRect, duration, curve);
}

double RenderSliverFloatingPersistentHeader::childMainAxisPosition(RenderBox child) {
    assert(child == this.child);
    return _childPosition ?? 0.0;
}

void RenderSliverFloatingPersistentHeader::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("effective scroll offset", _effectiveScrollOffset));
}

void RenderSliverFloatingPersistentHeader::_updateAnimation(Curve curve, Duration duration, double endValue) {
    assert(duration != nullptr);
    assert(endValue != nullptr);
    assert(curve != nullptr);
    assert(vsync != nullptr, "vsync must not be null if the floating header changes size animatedly.");
    AnimationController effectiveController = _controller ??= ;
    _animation = effectiveController.drive(<double>Tween(_effectiveScrollOffset, endValue).chain(CurveTween(curve)));
}

double RenderSliverFloatingPinnedPersistentHeader::updateGeometry() {
    double minExtent = this.minExtent;
    double minAllowedExtent = constraints.remainingPaintExtent > minExtent? minExtent : constraints.remainingPaintExtent;
    double maxExtent = this.maxExtent;
    double paintExtent = maxExtent - _effectiveScrollOffset!;
    double clampedPaintExtent = clampDouble(paintExtent, minAllowedExtent, constraints.remainingPaintExtent);
    double layoutExtent = maxExtent - constraints.scrollOffset;
    double stretchOffset = stretchConfiguration != nullptr? constraints.overlap.abs() : 0.0;
    geometry = SliverGeometry(maxExtent, math.min(constraints.overlap, 0.0), clampedPaintExtent, clampDouble(layoutExtent, 0.0, clampedPaintExtent), maxExtent + stretchOffset, minExtent, true);
    return 0.0;
}
