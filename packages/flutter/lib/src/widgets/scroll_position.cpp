#include "scroll_position.hpp"
ScrollPositionCls::ScrollPositionCls(ScrollContext context, String debugLabel, bool keepScrollOffset, ScrollPosition oldPosition, ScrollPhysics physics) {
    {
        assert(physics != nullptr);
        assert(context != nullptr);
        assert(context->vsync() != nullptr);
        assert(keepScrollOffset != nullptr);
    }
    {
        if (oldPosition != nullptr) {
            absorb(oldPosition);
        }
        if (keepScrollOffset) {
            restoreScrollOffset();
        }
    }
}

double ScrollPositionCls::minScrollExtent() {
    return _minScrollExtent!;
}

double ScrollPositionCls::maxScrollExtent() {
    return _maxScrollExtent!;
}

bool ScrollPositionCls::hasContentDimensions() {
    return _minScrollExtent != nullptr && _maxScrollExtent != nullptr;
}

double ScrollPositionCls::pixels() {
    return _pixels!;
}

bool ScrollPositionCls::hasPixels() {
    return _pixels != nullptr;
}

double ScrollPositionCls::viewportDimension() {
    return _viewportDimension!;
}

bool ScrollPositionCls::hasViewportDimension() {
    return _viewportDimension != nullptr;
}

bool ScrollPositionCls::haveDimensions() {
    return _haveDimensions;
}

void ScrollPositionCls::absorb(ScrollPosition other) {
    assert(other != nullptr);
    assert(other->context == context);
    assert(_pixels == nullptr);
    if (other->hasContentDimensions) {
        _minScrollExtent = other->minScrollExtent;
        _maxScrollExtent = other->maxScrollExtent;
    }
    if (other->hasPixels) {
        _pixels = other->pixels;
    }
    if (other->hasViewportDimension) {
        _viewportDimension = other->viewportDimension;
    }
    assert(activity() == nullptr);
    assert(other->activity != nullptr);
    _activity = other->activity;
    other->_activity = nullptr;
    if (other->runtimeType() != runtimeType) {
        activity()!->resetActivity();
    }
    context->setIgnorePointer(activity()!->shouldIgnorePointer());
    isScrollingNotifier->value() = activity()!->isScrolling();
}

double ScrollPositionCls::setPixels(double newPixels) {
    assert(hasPixels());
    assert(SchedulerBindingCls::instance->schedulerPhase != SchedulerPhaseCls::persistentCallbacks, __s("A scrollable's position should not change during the build, layout, and paint phases, otherwise the rendering will be confused."));
    if (newPixels != pixels()) {
        double overscroll = applyBoundaryConditions(newPixels);
        assert([=] () {
            double delta = newPixels - pixels();
            if (overscroll->abs() > delta->abs()) {
                ;
            }
            return true;
        }());
        double oldPixels = pixels();
        _pixels = newPixels - overscroll;
        if (_pixels != oldPixels) {
            notifyListeners();
            didUpdateScrollPositionBy(pixels() - oldPixels);
        }
        if (overscroll != 0.0) {
            didOverscrollBy(overscroll);
            return overscroll;
        }
    }
    return 0.0;
}

void ScrollPositionCls::correctPixels(double value) {
    _pixels = value;
}

void ScrollPositionCls::correctBy(double correction) {
    assert(hasPixels(), __s("An initial pixels value must exist by calling correctPixels on the ScrollPosition"));
    _pixels = _pixels! + correction;
    _didChangeViewportDimensionOrReceiveCorrection = true;
}

void ScrollPositionCls::forcePixels(double value) {
    assert(hasPixels());
    assert(value != nullptr);
    _impliedVelocity = value - pixels();
    _pixels = value;
    notifyListeners();
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
        _impliedVelocity = 0;
    });
}

void ScrollPositionCls::saveScrollOffset() {
    PageStorageCls->of(context->storageContext())?->writeState(context->storageContext(), pixels());
}

void ScrollPositionCls::restoreScrollOffset() {
    if (!hasPixels()) {
        double value = as<double>(PageStorageCls->of(context->storageContext())?->readState(context->storageContext()));
        if (value != nullptr) {
            correctPixels(value);
        }
    }
}

void ScrollPositionCls::restoreOffset(bool initialRestore, double offset) {
    assert(initialRestore != nullptr);
    assert(offset != nullptr);
    if (initialRestore) {
        correctPixels(offset);
    } else {
        jumpTo(offset);
    }
}

void ScrollPositionCls::saveOffset() {
    assert(hasPixels());
    context->saveOffset(pixels());
}

double ScrollPositionCls::applyBoundaryConditions(double value) {
    double result = physics->applyBoundaryConditions(this, value);
    assert([=] () {
        double delta = value - pixels();
        if (result->abs() > delta->abs()) {
            ;
        }
        return true;
    }());
    return result;
}

bool ScrollPositionCls::applyViewportDimension(double viewportDimension) {
    if (_viewportDimension != viewportDimension()) {
        _viewportDimension = viewportDimension();
        _didChangeViewportDimensionOrReceiveCorrection = true;
    }
    return true;
}

bool ScrollPositionCls::applyContentDimensions(double maxScrollExtent, double minScrollExtent) {
    assert(minScrollExtent() != nullptr);
    assert(maxScrollExtent() != nullptr);
    assert(haveDimensions() == (_lastMetrics != nullptr));
    if (!nearEqual(_minScrollExtent, minScrollExtent(), ToleranceCls::defaultTolerance->distance) || !nearEqual(_maxScrollExtent, maxScrollExtent(), ToleranceCls::defaultTolerance->distance) || _didChangeViewportDimensionOrReceiveCorrection || _lastAxis != axis) {
        assert(minScrollExtent() != nullptr);
        assert(maxScrollExtent() != nullptr);
        assert(minScrollExtent() <= maxScrollExtent());
        _minScrollExtent = minScrollExtent();
        _maxScrollExtent = maxScrollExtent();
        _lastAxis = axis;
        ScrollMetrics currentMetrics = haveDimensions()? copyWith() : nullptr;
        _didChangeViewportDimensionOrReceiveCorrection = false;
        _pendingDimensions = true;
        if (haveDimensions() && !correctForNewDimensions(_lastMetrics!, currentMetrics!)) {
            return false;
        }
        _haveDimensions = true;
    }
    assert(haveDimensions());
    if (_pendingDimensions) {
        applyNewDimensions();
        _pendingDimensions = false;
    }
    assert(!_didChangeViewportDimensionOrReceiveCorrection, __s("Use correctForNewDimensions() (and return true) to change the scroll offset during applyContentDimensions()."));
    if (_isMetricsChanged()) {
        if (!_haveScheduledUpdateNotification) {
            scheduleMicrotask(didUpdateScrollMetrics);
            _haveScheduledUpdateNotification = true;
        }
        _lastMetrics = copyWith();
    }
    return true;
}

bool ScrollPositionCls::correctForNewDimensions(ScrollMetrics newPosition, ScrollMetrics oldPosition) {
    double newPixels = physics->adjustPositionForNewDimensions(oldPosition, newPosition, activity()!->isScrolling(), activity()!->velocity());
    if (newPixels != pixels()) {
        correctPixels(newPixels);
        return false;
    }
    return true;
}

void ScrollPositionCls::applyNewDimensions() {
    assert(hasPixels());
    assert(_pendingDimensions);
    activity()!->applyNewDimensions();
    _updateSemanticActions();
}

Future<void> ScrollPositionCls::ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject) {
    assert(alignmentPolicy != nullptr);
    assert(object->attached);
    RenderAbstractViewport viewport = RenderAbstractViewportCls->of(object)!;
    assert(viewport != nullptr);
    Rect targetRect;
    if (targetRenderObject != nullptr && targetRenderObject != object) {
        targetRect = MatrixUtilsCls->transformRect(targetRenderObject->getTransformTo(object), object->paintBounds->intersect(targetRenderObject->paintBounds));
    }
    double target;
    ;
    if (target == pixels()) {
        return <void>value();
    }
    if (duration == DurationCls::zero) {
        jumpTo(target);
        return <void>value();
    }
    return animateTo(targetduration, curve);
}

Future<void> ScrollPositionCls::moveTo(bool clamp, Curve curve, Duration duration, double to) {
    assert(to != nullptr);
    assert(clamp != nullptr);
    if (clamp!) {
        to = clampDouble(to, minScrollExtent(), maxScrollExtent());
    }
    return super->moveTo(toduration, curve);
}

bool ScrollPositionCls::allowImplicitScrolling() {
    return physics->allowImplicitScrolling();
}

ScrollActivity ScrollPositionCls::activity() {
    return _activity;
}

void ScrollPositionCls::beginActivity(ScrollActivity newActivity) {
    if (newActivity == nullptr) {
        return;
    }
    bool wasScrolling, oldIgnorePointer;
    if (_activity != nullptr) {
        oldIgnorePointer = _activity!->shouldIgnorePointer();
        wasScrolling = _activity!->isScrolling();
        if (wasScrolling && !newActivity->isScrolling) {
            didEndScroll();
        }
        _activity!->dispose();
    } else {
        oldIgnorePointer = false;
        wasScrolling = false;
    }
    _activity = newActivity;
    if (oldIgnorePointer != activity()!->shouldIgnorePointer()) {
        context->setIgnorePointer(activity()!->shouldIgnorePointer());
    }
    isScrollingNotifier->value() = activity()!->isScrolling();
    if (!wasScrolling && _activity!->isScrolling()) {
        didStartScroll();
    }
}

void ScrollPositionCls::didStartScroll() {
    activity()!->dispatchScrollStartNotification(copyWith(), context->notificationContext());
}

void ScrollPositionCls::didUpdateScrollPositionBy(double delta) {
    activity()!->dispatchScrollUpdateNotification(copyWith(), context->notificationContext()!, delta);
}

void ScrollPositionCls::didEndScroll() {
    activity()!->dispatchScrollEndNotification(copyWith(), context->notificationContext()!);
    saveOffset();
    if (keepScrollOffset) {
        saveScrollOffset();
    }
}

void ScrollPositionCls::didOverscrollBy(double value) {
    assert(activity()!->isScrolling());
    activity()!->dispatchOverscrollNotification(copyWith(), context->notificationContext()!, value);
}

void ScrollPositionCls::didUpdateScrollDirection(ScrollDirection direction) {
    make<UserScrollNotificationCls>(copyWith(), context->notificationContext()!, direction)->dispatch(context->notificationContext());
}

void ScrollPositionCls::didUpdateScrollMetrics() {
    assert(SchedulerBindingCls::instance->schedulerPhase != SchedulerPhaseCls::persistentCallbacks);
    assert(_haveScheduledUpdateNotification);
    _haveScheduledUpdateNotification = false;
    if (context->notificationContext() != nullptr) {
        make<ScrollMetricsNotificationCls>(copyWith(), context->notificationContext()!)->dispatch(context->notificationContext());
    }
}

bool ScrollPositionCls::recommendDeferredLoading(BuildContext context) {
    assert(context != nullptr);
    assert(activity() != nullptr);
    assert(activity()!->velocity() != nullptr);
    assert(_impliedVelocity != nullptr);
    return physics->recommendDeferredLoading(activity()!->velocity() + _impliedVelocity, copyWith(), context);
}

void ScrollPositionCls::dispose() {
    activity()?->dispose();
    _activity = nullptr;
    super->dispose();
}

void ScrollPositionCls::notifyListeners() {
    _updateSemanticActions();
    super->notifyListeners();
}

void ScrollPositionCls::debugFillDescription(List<String> description) {
    if (debugLabel != nullptr) {
        description->add(debugLabel!);
    }
    super->debugFillDescription(description);
    description->add(__s("range: ${_minScrollExtent?.toStringAsFixed(1)}..${_maxScrollExtent?.toStringAsFixed(1)}"));
    description->add(__s("viewport: ${_viewportDimension?.toStringAsFixed(1)}"));
}

bool ScrollPositionCls::_isMetricsChanged() {
    assert(haveDimensions());
    ScrollMetrics currentMetrics = copyWith();
    return _lastMetrics == nullptr || !(currentMetrics->extentBefore == _lastMetrics!->extentBefore() && currentMetrics->extentInside == _lastMetrics!->extentInside() && currentMetrics->extentAfter == _lastMetrics!->extentAfter() && currentMetrics->axisDirection == _lastMetrics!->axisDirection());
}

void ScrollPositionCls::_updateSemanticActions() {
    SemanticsAction forward;
    SemanticsAction backward;
    ;
    Set<SemanticsAction> actions = makeSet();
    if (pixels() > minScrollExtent()) {
        actions->add(backward);
    }
    if ( < maxScrollExtent()) {
        actions->add(forward);
    }
    if (<SemanticsAction>setEquals(actions, _semanticActions)) {
        return;
    }
    _semanticActions = actions;
    context->setSemanticsActions(_semanticActions!);
}

void ScrollMetricsNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("$metrics"));
}
