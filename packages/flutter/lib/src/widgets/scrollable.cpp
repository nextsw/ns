#include "scrollable.hpp"
ScrollableCls::ScrollableCls(AxisDirection axisDirection, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, ScrollIncrementCalculator incrementCalculator, Unknown key, ScrollPhysics physics, String restorationId, ScrollBehavior scrollBehavior, int semanticChildCount, ViewportBuilder viewportBuilder) {
    {
        assert(axisDirection != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(viewportBuilder != nullptr);
        assert(excludeFromSemantics != nullptr);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
    }
}

Axis ScrollableCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

ScrollableState ScrollableCls::createState() {
    return make<ScrollableStateCls>();
}

void ScrollableCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>("axisDirection", axisDirection));
    properties->add(<ScrollPhysics>make<DiagnosticsPropertyCls>("physics", physics));
    properties->add(make<StringPropertyCls>("restorationId", restorationId));
}

ScrollableState ScrollableCls::of(BuildContext context) {
    _ScrollableScope widget = context-><_ScrollableScope>dependOnInheritedWidgetOfExactType();
    return widget?->scrollable;
}

bool ScrollableCls::recommendDeferredLoadingForContext(BuildContext context) {
    _ScrollableScope widget = ((_ScrollableScope)context-><_ScrollableScope>getElementForInheritedWidgetOfExactType()?->widget);
    if (widget == nullptr) {
        return false;
    }
    return widget->position->recommendDeferredLoading(context);
}

Future<void> ScrollableCls::ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, BuildContext context, Curve curve, Duration duration) {
    List<Future<void>> futures = makeList();
    RenderObject targetRenderObject;
    ScrollableState scrollable = ScrollableCls->of(context);
    while (scrollable != nullptr) {
        futures->add(scrollable->position->ensureVisible(context->findRenderObject()!alignment, duration, curve, alignmentPolicy, targetRenderObject));
        targetRenderObject = targetRenderObject ?? context->findRenderObject();
        context = scrollable->context;
        scrollable = ScrollableCls->of(context);
    }
    if (futures->isEmpty || duration == DurationCls::zero) {
        return <void>value();
    }
    if (futures->length == 1) {
        return futures->single;
    }
    return FutureCls-><void>wait(futures)-><void>then([=] (List<void> _)     {
        nullptr;
    });
}

bool _ScrollableScopeCls::updateShouldNotify(_ScrollableScope old) {
    return position != old->position;
}

_ScrollableScopeCls::_ScrollableScopeCls(Unknown child, ScrollPosition position, ScrollableState scrollable) {
    {
        assert(scrollable != nullptr);
        assert(child != nullptr);
    }
}

ScrollPosition ScrollableStateCls::position() {
    return _position!;
}

AxisDirection ScrollableStateCls::axisDirection() {
    return widget->axisDirection;
}

void ScrollableStateCls::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_persistedScrollOffset, "offset");
    assert(_position != nullptr);
    if (_persistedScrollOffset->value != nullptr) {
        position->restoreOffset(_persistedScrollOffset->value!initialRestore);
    }
}

void ScrollableStateCls::saveOffset(double offset) {
    assert(debugIsSerializableForRestoration(offset));
    _persistedScrollOffset->value = offset;
    ServicesBindingCls::instance->restorationManager->flushData();
}

void ScrollableStateCls::initState() {
    if (widget->controller == nullptr) {
        _fallbackScrollController = make<ScrollControllerCls>();
    }
    super->initState();
}

void ScrollableStateCls::didChangeDependencies() {
    _mediaQueryData = MediaQueryCls->maybeOf(context);
    _updatePosition();
    super->didChangeDependencies();
}

void ScrollableStateCls::didUpdateWidget(Scrollable oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->controller != oldWidget->controller) {
        if (oldWidget->controller == nullptr) {
            assert(_fallbackScrollController != nullptr);
            assert(widget->controller != nullptr);
            _fallbackScrollController!->detach(position);
            _fallbackScrollController!->dispose();
            _fallbackScrollController = nullptr;
        } else {
            oldWidget->controller?->detach(position);
            if (widget->controller == nullptr) {
                _fallbackScrollController = make<ScrollControllerCls>();
            }
        }
        _effectiveScrollController->attach(position);
    }
    if (_shouldUpdatePosition(oldWidget)) {
        _updatePosition();
    }
}

void ScrollableStateCls::dispose() {
    if (widget->controller != nullptr) {
        widget->controller!->detach(position);
    } else {
        _fallbackScrollController?->detach(position);
        _fallbackScrollController?->dispose();
    }
    position->dispose();
    _persistedScrollOffset->dispose();
    super->dispose();
}

void ScrollableStateCls::setSemanticsActions(Set<SemanticsAction> actions) {
    if (_gestureDetectorKey->currentState != nullptr) {
        _gestureDetectorKey->currentState!->replaceSemanticsActions(actions);
    }
}

void ScrollableStateCls::setCanDrag(bool value) {
    if (value == _lastCanDrag && (!value || widget->axis == _lastAxisDirection)) {
        return;
    }
    if (!value) {
        _gestureRecognizers = makeMap(makeList(), makeList();
        _handleDragCancel();
    } else {
        ;
    }
    _lastCanDrag = value;
    _lastAxisDirection = widget->axis;
    if (_gestureDetectorKey->currentState != nullptr) {
        _gestureDetectorKey->currentState!->replaceGestureRecognizers(_gestureRecognizers);
    }
}

TickerProvider ScrollableStateCls::vsync() {
    return this;
}

void ScrollableStateCls::setIgnorePointer(bool value) {
    if (_shouldIgnorePointer == value) {
        return;
    }
    _shouldIgnorePointer = value;
    if (_ignorePointerKey->currentContext != nullptr) {
        RenderIgnorePointer renderBox = ((RenderIgnorePointer)_ignorePointerKey->currentContext!->findRenderObject()!);
        renderBox->ignoring = _shouldIgnorePointer;
    }
}

BuildContext ScrollableStateCls::notificationContext() {
    return _gestureDetectorKey->currentContext;
}

BuildContext ScrollableStateCls::storageContext() {
    return context;
}

Widget ScrollableStateCls::build(BuildContext context) {
    assert(_position != nullptr);
    Widget result = make<_ScrollableScopeCls>(this, position, make<ListenerCls>(_receivedPointerSignal, make<RawGestureDetectorCls>(_gestureDetectorKey, _gestureRecognizers, HitTestBehaviorCls::opaque, widget->excludeFromSemantics, make<SemanticsCls>(!widget->excludeFromSemantics, make<IgnorePointerCls>(_ignorePointerKey, _shouldIgnorePointer, false, widget->viewportBuilder(context, position))))));
    if (!widget->excludeFromSemantics) {
        result = <ScrollMetricsNotification>make<NotificationListenerCls>(_handleScrollMetricsNotification, make<_ScrollSemanticsCls>(_scrollSemanticsKey, position, _physics!->allowImplicitScrolling, widget->semanticChildCount, result));
    }
    ScrollableDetails details = make<ScrollableDetailsCls>(widget->axisDirection, _effectiveScrollController, widget->clipBehavior);
    result = _configuration->buildScrollbar(context, _configuration->buildOverscrollIndicator(context, result, details), details);
    SelectionRegistrar registrar = SelectionContainerCls->maybeOf(context);
    if (registrar != nullptr) {
        result = make<_ScrollableSelectionHandlerCls>(this, position, registrar, result);
    }
    return result;
}

void ScrollableStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ScrollPosition>make<DiagnosticsPropertyCls>("position", position));
    properties->add(<ScrollPhysics>make<DiagnosticsPropertyCls>("effective physics", _physics));
}

String ScrollableStateCls::restorationId() {
    return widget->restorationId;
}

ScrollController ScrollableStateCls::_effectiveScrollController() {
    return widget->controller ?? _fallbackScrollController!;
}

void ScrollableStateCls::_updatePosition() {
    _configuration = widget->scrollBehavior ?? ScrollConfigurationCls->of(context);
    _physics = _configuration->getScrollPhysics(context);
    if (widget->physics != nullptr) {
        _physics = widget->physics!->applyTo(_physics);
    } else     {
        if (widget->scrollBehavior != nullptr) {
        _physics = widget->scrollBehavior!->getScrollPhysics(context)->applyTo(_physics);
    }
;
    }    ScrollPosition oldPosition = _position;
    if (oldPosition != nullptr) {
        _effectiveScrollController->detach(oldPosition);
        scheduleMicrotask(oldPosition->dispose);
    }
    _position = _effectiveScrollController->createScrollPosition(_physics!, this, oldPosition);
    assert(_position != nullptr);
    _effectiveScrollController->attach(position);
}

bool ScrollableStateCls::_shouldUpdatePosition(Scrollable oldWidget) {
    ScrollPhysics newPhysics = widget->physics ?? widget->scrollBehavior?->getScrollPhysics(context);
    ScrollPhysics oldPhysics = oldWidget->physics ?? oldWidget->scrollBehavior?->getScrollPhysics(context);
    do {
        if (newPhysics?->runtimeType != oldPhysics?->runtimeType) {
            return true;
        }
        newPhysics = newPhysics?->parent;
        oldPhysics = oldPhysics?->parent;
    } while (newPhysics != nullptr || oldPhysics != nullptr);
    return widget->controller?->runtimeType != oldWidget->controller?->runtimeType;
}

void ScrollableStateCls::_handleDragDown(DragDownDetails details) {
    assert(_drag == nullptr);
    assert(_hold == nullptr);
    _hold = position->hold(_disposeHold);
}

void ScrollableStateCls::_handleDragStart(DragStartDetails details) {
    assert(_drag == nullptr);
    _drag = position->drag(details, _disposeDrag);
    assert(_drag != nullptr);
    assert(_hold == nullptr);
}

void ScrollableStateCls::_handleDragUpdate(DragUpdateDetails details) {
    assert(_hold == nullptr || _drag == nullptr);
    _drag?->update(details);
}

void ScrollableStateCls::_handleDragEnd(DragEndDetails details) {
    assert(_hold == nullptr || _drag == nullptr);
    _drag?->end(details);
    assert(_drag == nullptr);
}

void ScrollableStateCls::_handleDragCancel() {
    assert(_hold == nullptr || _drag == nullptr);
    _hold?->cancel();
    _drag?->cancel();
    assert(_hold == nullptr);
    assert(_drag == nullptr);
}

void ScrollableStateCls::_disposeHold() {
    _hold = nullptr;
}

void ScrollableStateCls::_disposeDrag() {
    _drag = nullptr;
}

double ScrollableStateCls::_targetScrollOffsetForPointerScroll(double delta) {
    return math->min(math->max(position->pixels + delta, position->minScrollExtent), position->maxScrollExtent);
}

double ScrollableStateCls::_pointerSignalEventDelta(PointerScrollEvent event) {
    double delta = widget->axis == AxisCls::horizontal? event->scrollDelta->dx : event->scrollDelta->dy;
    if (axisDirectionIsReversed(widget->axisDirection)) {
        delta = -1;
    }
    return delta;
}

void ScrollableStateCls::_receivedPointerSignal(PointerSignalEvent event) {
    if (event is PointerScrollEvent && _position != nullptr) {
        if (_physics != nullptr && !_physics!->shouldAcceptUserOffset(position)) {
            return;
        }
        double delta = _pointerSignalEventDelta(event);
        double targetScrollOffset = _targetScrollOffsetForPointerScroll(delta);
        if (delta != 0.0 && targetScrollOffset != position->pixels) {
            GestureBindingCls::instance->pointerSignalResolver->register(event, _handlePointerScroll);
        }
    }
}

void ScrollableStateCls::_handlePointerScroll(PointerEvent event) {
    assert(event is PointerScrollEvent);
    double delta = _pointerSignalEventDelta(((PointerScrollEvent)event));
    double targetScrollOffset = _targetScrollOffsetForPointerScroll(delta);
    if (delta != 0.0 && targetScrollOffset != position->pixels) {
        position->pointerScroll(delta);
    }
}

bool ScrollableStateCls::_handleScrollMetricsNotification(ScrollMetricsNotification notification) {
    if (notification->depth == 0) {
        RenderObject scrollSemanticsRenderObject = _scrollSemanticsKey->currentContext?->findRenderObject();
        if (scrollSemanticsRenderObject != nullptr) {
            scrollSemanticsRenderObject->markNeedsSemanticsUpdate();
        }
    }
    return false;
}

_ScrollableSelectionHandlerState _ScrollableSelectionHandlerCls::createState() {
    return make<_ScrollableSelectionHandlerStateCls>();
}

void _ScrollableSelectionHandlerStateCls::initState() {
    super->initState();
    _selectionDelegate = make<_ScrollableSelectionContainerDelegateCls>(widget->state, widget->position);
}

void _ScrollableSelectionHandlerStateCls::didUpdateWidget(_ScrollableSelectionHandler oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->position != widget->position) {
        _selectionDelegate->position = widget->position;
    }
}

void _ScrollableSelectionHandlerStateCls::dispose() {
    _selectionDelegate->dispose();
    super->dispose();
}

Widget _ScrollableSelectionHandlerStateCls::build(BuildContext context) {
    return make<SelectionContainerCls>(widget->registrar, _selectionDelegate, widget->child);
}

bool EdgeDraggingAutoScrollerCls::scrolling() {
    return _scrolling;
}

void EdgeDraggingAutoScrollerCls::startAutoScrollIfNecessary(Rect dragTarget) {
    Offset deltaToOrigin = _getDeltaToScrollOrigin(scrollable);
    _dragTargetRelatedToScrollOrigin = dragTarget->translate(deltaToOrigin->dx, deltaToOrigin->dy);
    if (_scrolling) {
        return;
    }
    if (!_scrolling) {
        _scroll();
    }
}

void EdgeDraggingAutoScrollerCls::stopAutoScroll() {
    _scrolling = false;
}

double EdgeDraggingAutoScrollerCls::_offsetExtent(Offset offset, Axis scrollDirection) {
    ;
}

double EdgeDraggingAutoScrollerCls::_sizeExtent(Axis scrollDirection, Size size) {
    ;
}

AxisDirection EdgeDraggingAutoScrollerCls::_axisDirection() {
    return scrollable->axisDirection;
}

Axis EdgeDraggingAutoScrollerCls::_scrollDirection() {
    return axisDirectionToAxis(_axisDirection);
}

Future<void> EdgeDraggingAutoScrollerCls::_scroll() {
    RenderBox scrollRenderBox = ((RenderBox)scrollable->context->findRenderObject()!);
    Rect globalRect = MatrixUtilsCls->transformRect(scrollRenderBox->getTransformTo(nullptr), RectCls->fromLTWH(0, 0, scrollRenderBox->size->width, scrollRenderBox->size->height));
    _scrolling = true;
    double newOffset;
    double overDragMax = 20.0;
    Offset deltaToOrigin = _getDeltaToScrollOrigin(scrollable);
    Offset viewportOrigin = globalRect->topLeft->translate(deltaToOrigin->dx, deltaToOrigin->dy);
    double viewportStart = _offsetExtent(viewportOrigin, _scrollDirection);
    double viewportEnd = viewportStart + _sizeExtent(globalRect->size, _scrollDirection);
    double proxyStart = _offsetExtent(_dragTargetRelatedToScrollOrigin->topLeft, _scrollDirection);
    double proxyEnd = _offsetExtent(_dragTargetRelatedToScrollOrigin->bottomRight, _scrollDirection);
    double overDrag;
    if (_axisDirection == AxisDirectionCls::up || _axisDirection == AxisDirectionCls::left) {
        if (proxyEnd > viewportEnd && scrollable->position->pixels > scrollable->position->minScrollExtent) {
            overDrag = math->max(proxyEnd - viewportEnd, overDragMax);
            newOffset = math->max(scrollable->position->minScrollExtent, scrollable->position->pixels - overDrag);
        } else         {
            if ( < viewportStart && scrollable->position->pixels < scrollable->position->maxScrollExtent) {
            overDrag = math->max(viewportStart - proxyStart, overDragMax);
            newOffset = math->min(scrollable->position->maxScrollExtent, scrollable->position->pixels + overDrag);
        }
;
        }    } else {
        if ( < viewportStart && scrollable->position->pixels > scrollable->position->minScrollExtent) {
            overDrag = math->max(viewportStart - proxyStart, overDragMax);
            newOffset = math->max(scrollable->position->minScrollExtent, scrollable->position->pixels - overDrag);
        } else         {
            if (proxyEnd > viewportEnd && scrollable->position->pixels < scrollable->position->maxScrollExtent) {
            overDrag = math->max(proxyEnd - viewportEnd, overDragMax);
            newOffset = math->min(scrollable->position->maxScrollExtent, scrollable->position->pixels + overDrag);
        }
;
        }    }
    if (newOffset == nullptr || (newOffset - scrollable->position->pixels)->abs() < 1.0) {
        _scrolling = false;
        return;
    }
    Duration duration = make<DurationCls>((1000 / velocityScalar)->round());
    await await scrollable->position->animateTo(newOffsetduration, CurvesCls::linear);
    if (onScrollViewScrolled != nullptr) {
        onScrollViewScrolled!();
    }
    if (_scrolling) {
        await await _scroll();
    }
}

ScrollPosition _ScrollableSelectionContainerDelegateCls::position() {
    return _position;
}

void _ScrollableSelectionContainerDelegateCls::position(ScrollPosition other) {
    if (other == _position) {
        return;
    }
    _position->removeListener(_scheduleLayoutChange);
    _position = other;
    _position->addListener(_scheduleLayoutChange);
}

void _ScrollableSelectionContainerDelegateCls::didChangeSelectables() {
    Set<Selectable> selectableSet = selectables->toSet();
    _selectableStartEdgeUpdateRecords->removeWhere([=] (Selectable key,double value)     {
        !selectableSet->contains(key);
    });
    _selectableEndEdgeUpdateRecords->removeWhere([=] (Selectable key,double value)     {
        !selectableSet->contains(key);
    });
    super->didChangeSelectables();
}

SelectionResult _ScrollableSelectionContainerDelegateCls::handleClearSelection(ClearSelectionEvent event) {
    _selectableStartEdgeUpdateRecords->clear();
    _selectableEndEdgeUpdateRecords->clear();
    _currentDragStartRelatedToOrigin = nullptr;
    _currentDragEndRelatedToOrigin = nullptr;
    _selectionStartsInScrollable = false;
    return super->handleClearSelection(event);
}

SelectionResult _ScrollableSelectionContainerDelegateCls::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (_currentDragEndRelatedToOrigin == nullptr && _currentDragStartRelatedToOrigin == nullptr) {
        assert(!_selectionStartsInScrollable);
        _selectionStartsInScrollable = _globalPositionInScrollable(event->globalPosition);
    }
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    if (event->type == SelectionEventTypeCls::endEdgeUpdate) {
        _currentDragEndRelatedToOrigin = _inferPositionRelatedToOrigin(event->globalPosition);
        Offset endOffset = _currentDragEndRelatedToOrigin!->translate(-deltaToOrigin->dx, -deltaToOrigin->dy);
        event = SelectionEdgeUpdateEventCls->forEnd(endOffset);
    } else {
        _currentDragStartRelatedToOrigin = _inferPositionRelatedToOrigin(event->globalPosition);
        Offset startOffset = _currentDragStartRelatedToOrigin!->translate(-deltaToOrigin->dx, -deltaToOrigin->dy);
        event = SelectionEdgeUpdateEventCls->forStart(startOffset);
    }
    SelectionResult result = super->handleSelectionEdgeUpdate(event);
    if (result == SelectionResultCls::pending) {
        _autoScroller->stopAutoScroll();
        return result;
    }
    if (_selectionStartsInScrollable) {
        _autoScroller->startAutoScrollIfNecessary(_dragTargetFromEvent(event));
        if (_autoScroller->scrolling) {
            return SelectionResultCls::pending;
        }
    }
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegateCls::handleSelectAll(SelectAllSelectionEvent event) {
    assert(!_selectionStartsInScrollable);
    SelectionResult result = super->handleSelectAll(event);
    assert((currentSelectionStartIndex == -1) == (currentSelectionEndIndex == -1));
    if (currentSelectionStartIndex != -1) {
        _updateDragLocationsFromGeometries();
    }
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegateCls::handleSelectWord(SelectWordSelectionEvent event) {
    _selectionStartsInScrollable = _globalPositionInScrollable(event->globalPosition);
    SelectionResult result = super->handleSelectWord(event);
    _updateDragLocationsFromGeometries();
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegateCls::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    ;
    return super->dispatchSelectionEventToChild(selectable, event);
}

void _ScrollableSelectionContainerDelegateCls::ensureChildUpdated(Selectable selectable) {
    double newRecord = state->position->pixels;
    double previousStartRecord = _selectableStartEdgeUpdateRecords[selectable];
    if (_currentDragStartRelatedToOrigin != nullptr && (previousStartRecord == nullptr || (newRecord - previousStartRecord)->abs() > precisionErrorTolerance)) {
        Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
        Offset startOffset = _currentDragStartRelatedToOrigin!->translate(-deltaToOrigin->dx, -deltaToOrigin->dy);
        selectable->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forStart(startOffset));
    }
    double previousEndRecord = _selectableEndEdgeUpdateRecords[selectable];
    if (_currentDragEndRelatedToOrigin != nullptr && (previousEndRecord == nullptr || (newRecord - previousEndRecord)->abs() > precisionErrorTolerance)) {
        Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
        Offset endOffset = _currentDragEndRelatedToOrigin!->translate(-deltaToOrigin->dx, -deltaToOrigin->dy);
        selectable->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forEnd(endOffset));
    }
}

void _ScrollableSelectionContainerDelegateCls::dispose() {
    _selectableStartEdgeUpdateRecords->clear();
    _selectableEndEdgeUpdateRecords->clear();
    _scheduledLayoutChange = false;
    _autoScroller->stopAutoScroll();
    super->dispose();
}

_ScrollableSelectionContainerDelegateCls::_ScrollableSelectionContainerDelegateCls(ScrollPosition position, ScrollableState state) {
    {
        _position = position;
        _autoScroller = make<EdgeDraggingAutoScrollerCls>(state_kDefaultSelectToScrollVelocityScalar);
    }
    {
        _position->addListener(_scheduleLayoutChange);
    }
}

void _ScrollableSelectionContainerDelegateCls::_scheduleLayoutChange() {
    if (_scheduledLayoutChange) {
        return;
    }
    _scheduledLayoutChange = true;
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
        if (!_scheduledLayoutChange) {
            return;
        }
        _scheduledLayoutChange = false;
        layoutDidChange();
    });
}

Offset _ScrollableSelectionContainerDelegateCls::_inferPositionRelatedToOrigin(Offset globalPosition) {
    RenderBox box = ((RenderBox)state->context->findRenderObject()!);
    Offset localPosition = box->globalToLocal(globalPosition);
    if (!_selectionStartsInScrollable) {
        if (localPosition->dy < 0 || localPosition->dx < 0) {
            return box->localToGlobal(OffsetCls::zero);
        }
        if (localPosition->dy > box->size->height || localPosition->dx > box->size->width) {
            return OffsetCls::infinite;
        }
    }
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    return box->localToGlobal(localPosition->translate(deltaToOrigin->dx, deltaToOrigin->dy));
}

void _ScrollableSelectionContainerDelegateCls::_updateDragLocationsFromGeometries() {
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    RenderBox box = ((RenderBox)state->context->findRenderObject()!);
    Matrix4 transform = box->getTransformTo(nullptr);
    if (currentSelectionStartIndex != -1) {
        SelectionGeometry geometry = selectables[currentSelectionStartIndex]->value;
        assert(geometry->hasSelection);
        SelectionPoint start = geometry->startSelectionPoint!;
        Matrix4 childTransform = selectables[currentSelectionStartIndex]->getTransformTo(box);
        Offset localDragStart = MatrixUtilsCls->transformPoint(childTransform, start->localPosition + make<OffsetCls>(0, -start->lineHeight / 2));
        _currentDragStartRelatedToOrigin = MatrixUtilsCls->transformPoint(transform, localDragStart + deltaToOrigin);
    }
    if (currentSelectionEndIndex != -1) {
        SelectionGeometry geometry = selectables[currentSelectionEndIndex]->value;
        assert(geometry->hasSelection);
        SelectionPoint end = geometry->endSelectionPoint!;
        Matrix4 childTransform = selectables[currentSelectionEndIndex]->getTransformTo(box);
        Offset localDragEnd = MatrixUtilsCls->transformPoint(childTransform, end->localPosition + make<OffsetCls>(0, -end->lineHeight / 2));
        _currentDragEndRelatedToOrigin = MatrixUtilsCls->transformPoint(transform, localDragEnd + deltaToOrigin);
    }
}

bool _ScrollableSelectionContainerDelegateCls::_globalPositionInScrollable(Offset globalPosition) {
    RenderBox box = ((RenderBox)state->context->findRenderObject()!);
    Offset localPosition = box->globalToLocal(globalPosition);
    Rect rect = RectCls->fromLTWH(0, 0, box->size->width, box->size->height);
    return rect->contains(localPosition);
}

Rect _ScrollableSelectionContainerDelegateCls::_dragTargetFromEvent(SelectionEdgeUpdateEvent event) {
    return RectCls->fromCenter(event->globalPosition, _kDefaultDragTargetSize, _kDefaultDragTargetSize);
}

Offset _getDeltaToScrollOrigin(ScrollableState scrollableState) {
    ;
}

_RenderScrollSemantics _ScrollSemanticsCls::createRenderObject(BuildContext context) {
    return make<_RenderScrollSemanticsCls>(position, allowImplicitScrolling, semanticChildCount);
}

void _ScrollSemanticsCls::updateRenderObject(BuildContext context, _RenderScrollSemantics renderObject) {
    auto _c1 = renderObject;_c1.allowImplicitScrolling = auto _c2 = allowImplicitScrolling;_c2.position = auto _c3 = position;_c3.semanticChildCount = semanticChildCount;_c3;_c2;_c1;
}

_ScrollSemanticsCls::_ScrollSemanticsCls(bool allowImplicitScrolling, Unknown child, Unknown key, ScrollPosition position, int semanticChildCount) {
    {
        assert(position != nullptr);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
    }
}

ScrollPosition _RenderScrollSemanticsCls::position() {
    return _position;
}

void _RenderScrollSemanticsCls::position(ScrollPosition value) {
    assert(value != nullptr);
    if (value == _position) {
        return;
    }
    _position->removeListener(markNeedsSemanticsUpdate);
    _position = value;
    _position->addListener(markNeedsSemanticsUpdate);
    markNeedsSemanticsUpdate();
}

bool _RenderScrollSemanticsCls::allowImplicitScrolling() {
    return _allowImplicitScrolling;
}

void _RenderScrollSemanticsCls::allowImplicitScrolling(bool value) {
    if (value == _allowImplicitScrolling) {
        return;
    }
    _allowImplicitScrolling = value;
    markNeedsSemanticsUpdate();
}

int _RenderScrollSemanticsCls::semanticChildCount() {
    return _semanticChildCount;
}

void _RenderScrollSemanticsCls::semanticChildCount(int value) {
    if (value == semanticChildCount) {
        return;
    }
    _semanticChildCount = value;
    markNeedsSemanticsUpdate();
}

void _RenderScrollSemanticsCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->isSemanticBoundary = true;
    if (position->haveDimensions) {
            auto _c1 = config;    _c1.hasImplicitScrolling = auto _c2 = allowImplicitScrolling;    _c2.scrollPosition = auto _c3 = _position->pixels;    _c3.scrollExtentMax = auto _c4 = _position->maxScrollExtent;    _c4.scrollExtentMin = auto _c5 = _position->minScrollExtent;    _c5.scrollChildCount = semanticChildCount;    _c5;    _c4;    _c3;    _c2;_c1;
    }
}

void _RenderScrollSemanticsCls::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    if (children->isEmpty || !children->first->isTagged(RenderViewportCls::useTwoPaneSemantics)) {
        super->assembleSemanticsNode(node, config, children);
        return;
    }
    _innerNode = make<SemanticsNodeCls>(showOnScreen);
    auto _c1 = _innerNode!;_c1.isMergedIntoParent = auto _c2 = node->isPartOfNodeMerging;_c2.rect = node->rect;_c2;_c1;
    int firstVisibleIndex;
    List<SemanticsNode> excluded = makeList(ArrayItem);
    List<SemanticsNode> included = makeList();
    for (SemanticsNode child : children) {
        assert(child->isTagged(RenderViewportCls::useTwoPaneSemantics));
        if (child->isTagged(RenderViewportCls::excludeFromScrolling)) {
            excluded->add(child);
        } else {
            if (!child->hasFlag(SemanticsFlagCls::isHidden)) {
                firstVisibleIndex = child->indexInParent;
            }
            included->add(child);
        }
    }
    config->scrollIndex = firstVisibleIndex;
    node->updateWith(nullptr, excluded);
    _innerNode!->updateWith(config, included);
}

void _RenderScrollSemanticsCls::clearSemantics() {
    super->clearSemantics();
    _innerNode = nullptr;
}

_RenderScrollSemanticsCls::_RenderScrollSemanticsCls(bool allowImplicitScrolling, RenderBox child, ScrollPosition position, int semanticChildCount) {
    {
        _position = position;
        _allowImplicitScrolling = allowImplicitScrolling;
        _semanticChildCount = semanticChildCount;
        assert(position != nullptr);
    }
    {
        position->addListener(markNeedsSemanticsUpdate);
    }
}

ScrollIncrementDetailsCls::ScrollIncrementDetailsCls(ScrollMetrics metrics, ScrollIncrementType type) {
    {
        assert(type != nullptr);
        assert(metrics != nullptr);
    }
}

ScrollIntentCls::ScrollIntentCls(AxisDirection direction, ScrollIncrementType type) {
    {
        assert(direction != nullptr);
        assert(type != nullptr);
    }
}

bool ScrollActionCls::isEnabled(ScrollIntent intent) {
    FocusNode focus = primaryFocus;
    bool contextIsValid = focus != nullptr && focus->context != nullptr;
    if (contextIsValid) {
        if (ScrollableCls->of(focus->context!) != nullptr) {
            return true;
        }
        ScrollController primaryScrollController = PrimaryScrollControllerCls->of(focus->context!);
        return primaryScrollController != nullptr && primaryScrollController->hasClients;
    }
    return false;
}

void ScrollActionCls::invoke(ScrollIntent intent) {
    ScrollableState state = ScrollableCls->of(primaryFocus!->context!);
    if (state == nullptr) {
        ScrollController primaryScrollController = PrimaryScrollControllerCls->of(primaryFocus!->context!);
        assert([=] () {
            if (primaryScrollController!->positions->length != 1) {
                ;
            }
            return true;
        }());
        if (primaryScrollController!->position->context->notificationContext == nullptr && ScrollableCls->of(primaryScrollController->position->context->notificationContext!) == nullptr) {
            return;
        }
        state = ScrollableCls->of(primaryScrollController->position->context->notificationContext!);
    }
    assert(state != nullptr, "$ScrollAction was invoked on a context that has no scrollable parent");
    assert(state!->position->hasPixels, "Scrollable must be laid out before it can be scrolled via a ScrollAction");
    assert(state!->position->viewportDimension != nullptr);
    assert(state!->position->maxScrollExtent != nullptr);
    assert(state!->position->minScrollExtent != nullptr);
    if (state!->_physics != nullptr && !state->_physics!->shouldAcceptUserOffset(state->position)) {
        return;
    }
    double increment = _getIncrement(state, intent);
    if (increment == 0.0) {
        return;
    }
    state->position->moveTo(state->position->pixels + incrementmake<DurationCls>(100), CurvesCls::easeInOut);
}

double ScrollActionCls::_calculateScrollIncrement(ScrollableState state, ScrollIncrementType type) {
    assert(type != nullptr);
    assert(state->position != nullptr);
    assert(state->position->hasPixels);
    assert(state->position->viewportDimension != nullptr);
    assert(state->position->maxScrollExtent != nullptr);
    assert(state->position->minScrollExtent != nullptr);
    assert(state->_physics == nullptr || state->_physics!->shouldAcceptUserOffset(state->position));
    if (state->widget->incrementCalculator != nullptr) {
        return state->widget->incrementCalculator!(make<ScrollIncrementDetailsCls>(type, state->position));
    }
    ;
}

double ScrollActionCls::_getIncrement(ScrollIntent intent, ScrollableState state) {
    double increment = _calculateScrollIncrement(stateintent->type);
    ;
}

double _RestorableScrollOffsetCls::createDefaultValue() {
    return nullptr;
}

void _RestorableScrollOffsetCls::didUpdateValue(double oldValue) {
    notifyListeners();
}

double _RestorableScrollOffsetCls::fromPrimitives(Object data) {
    return ((double)data!);
}

Object _RestorableScrollOffsetCls::toPrimitives() {
    return value;
}

bool _RestorableScrollOffsetCls::enabled() {
    return value != nullptr;
}
