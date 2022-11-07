#include "scrollable.hpp"
Scrollable::Scrollable(AxisDirection axisDirection, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, ScrollIncrementCalculator incrementCalculator, Unknown, ScrollPhysics physics, String restorationId, ScrollBehavior scrollBehavior, int semanticChildCount, ViewportBuilder viewportBuilder) {
    {
        assert(axisDirection != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(viewportBuilder != nullptr);
        assert(excludeFromSemantics != nullptr);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
    }
}

Axis Scrollable::axis() {
    return axisDirectionToAxis(axisDirection);
}

ScrollableState Scrollable::createState() {
    return ScrollableState();
}

void Scrollable::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
    properties.add(<ScrollPhysics>DiagnosticsProperty("physics", physics));
    properties.add(StringProperty("restorationId", restorationId));
}

ScrollableState Scrollable::of(BuildContext context) {
    _ScrollableScope widget = context.<_ScrollableScope>dependOnInheritedWidgetOfExactType();
    return widget?.scrollable;
}

bool Scrollable::recommendDeferredLoadingForContext(BuildContext context) {
    _ScrollableScope widget = (;
    if (widget == nullptr) {
        return false;
    }
    return widget.position.recommendDeferredLoading(context);
}

Future<void> Scrollable::ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, BuildContext context, Curve curve, Duration duration) {
    List<Future<void>> futures = ;
    RenderObject targetRenderObject;
    ScrollableState scrollable = Scrollable.of(context);
    while (scrollable != nullptr) {
        futures.add(scrollable.position.ensureVisible(context.findRenderObject()!alignment, duration, curve, alignmentPolicy, targetRenderObject));
        targetRenderObject = targetRenderObject ?? context.findRenderObject();
        context = scrollable.context;
        scrollable = Scrollable.of(context);
    }
    if (futures.isEmpty || duration == Duration.zero) {
        return <void>value();
    }
    if (futures.length == 1) {
        return futures.single;
    }
    return Future.<void>wait(futures).<void>then();
}

bool _ScrollableScope::updateShouldNotify(_ScrollableScope old) {
    return position != old.position;
}

_ScrollableScope::_ScrollableScope(Unknown, ScrollPosition position, ScrollableState scrollable) {
    {
        assert(scrollable != nullptr);
        assert(child != nullptr);
    }
}

ScrollPosition ScrollableState::position() {
    return _position!;
}

AxisDirection ScrollableState::axisDirection() {
    return widget.axisDirection;
}

void ScrollableState::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_persistedScrollOffset, "offset");
    assert(_position != nullptr);
    if (_persistedScrollOffset.value != nullptr) {
        position.restoreOffset(_persistedScrollOffset.value!initialRestore);
    }
}

void ScrollableState::saveOffset(double offset) {
    assert(debugIsSerializableForRestoration(offset));
    _persistedScrollOffset.value = offset;
    ServicesBinding.instance.restorationManager.flushData();
}

void ScrollableState::initState() {
    if (widget.controller == nullptr) {
        _fallbackScrollController = ScrollController();
    }
    super.initState();
}

void ScrollableState::didChangeDependencies() {
    _mediaQueryData = MediaQuery.maybeOf(context);
    _updatePosition();
    super.didChangeDependencies();
}

void ScrollableState::didUpdateWidget(Scrollable oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.controller != oldWidget.controller) {
        if (oldWidget.controller == nullptr) {
            assert(_fallbackScrollController != nullptr);
            assert(widget.controller != nullptr);
            _fallbackScrollController!.detach(position);
            _fallbackScrollController!.dispose();
            _fallbackScrollController = nullptr;
        } else {
            oldWidget.controller?.detach(position);
            if (widget.controller == nullptr) {
                _fallbackScrollController = ScrollController();
            }
        }
        _effectiveScrollController.attach(position);
    }
    if (_shouldUpdatePosition(oldWidget)) {
        _updatePosition();
    }
}

void ScrollableState::dispose() {
    if (widget.controller != nullptr) {
        widget.controller!.detach(position);
    } else {
        _fallbackScrollController?.detach(position);
        _fallbackScrollController?.dispose();
    }
    position.dispose();
    _persistedScrollOffset.dispose();
    super.dispose();
}

void ScrollableState::setSemanticsActions(Set<SemanticsAction> actions) {
    if (_gestureDetectorKey.currentState != nullptr) {
        _gestureDetectorKey.currentState!.replaceSemanticsActions(actions);
    }
}

void ScrollableState::setCanDrag(bool value) {
    if (value == _lastCanDrag && (!value || widget.axis == _lastAxisDirection)) {
        return;
    }
    if (!value) {
        _gestureRecognizers = const ;
        _handleDragCancel();
    } else {
        ;
    }
    _lastCanDrag = value;
    _lastAxisDirection = widget.axis;
    if (_gestureDetectorKey.currentState != nullptr) {
        _gestureDetectorKey.currentState!.replaceGestureRecognizers(_gestureRecognizers);
    }
}

TickerProvider ScrollableState::vsync() {
    return this;
}

void ScrollableState::setIgnorePointer(bool value) {
    if (_shouldIgnorePointer == value) {
        return;
    }
    _shouldIgnorePointer = value;
    if (_ignorePointerKey.currentContext != nullptr) {
        RenderIgnorePointer renderBox = (;
        renderBox.ignoring = _shouldIgnorePointer;
    }
}

BuildContext ScrollableState::notificationContext() {
    return _gestureDetectorKey.currentContext;
}

BuildContext ScrollableState::storageContext() {
    return context;
}

Widget ScrollableState::build(BuildContext context) {
    assert(_position != nullptr);
    Widget result = _ScrollableScope(this, position, Listener(_receivedPointerSignal, RawGestureDetector(_gestureDetectorKey, _gestureRecognizers, HitTestBehavior.opaque, widget.excludeFromSemantics, Semantics(!widget.excludeFromSemantics, IgnorePointer(_ignorePointerKey, _shouldIgnorePointer, false, widget.viewportBuilder(context, position))))));
    if (!widget.excludeFromSemantics) {
        result = <ScrollMetricsNotification>NotificationListener(_handleScrollMetricsNotification, _ScrollSemantics(_scrollSemanticsKey, position, _physics!.allowImplicitScrolling, widget.semanticChildCount, result));
    }
    ScrollableDetails details = ScrollableDetails(widget.axisDirection, _effectiveScrollController, widget.clipBehavior);
    result = _configuration.buildScrollbar(context, _configuration.buildOverscrollIndicator(context, result, details), details);
    SelectionRegistrar registrar = SelectionContainer.maybeOf(context);
    if (registrar != nullptr) {
        result = _ScrollableSelectionHandler(this, position, registrar, result);
    }
    return result;
}

void ScrollableState::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ScrollPosition>DiagnosticsProperty("position", position));
    properties.add(<ScrollPhysics>DiagnosticsProperty("effective physics", _physics));
}

String ScrollableState::restorationId() {
    return widget.restorationId;
}

ScrollController ScrollableState::_effectiveScrollController() {
    return widget.controller ?? _fallbackScrollController!;
}

void ScrollableState::_updatePosition() {
    _configuration = widget.scrollBehavior ?? ScrollConfiguration.of(context);
    _physics = _configuration.getScrollPhysics(context);
    if (widget.physics != nullptr) {
        _physics = widget.physics!.applyTo(_physics);
    } else     {
        if (widget.scrollBehavior != nullptr) {
        _physics = widget.scrollBehavior!.getScrollPhysics(context).applyTo(_physics);
    }
;
    }    ScrollPosition oldPosition = _position;
    if (oldPosition != nullptr) {
        _effectiveScrollController.detach(oldPosition);
        scheduleMicrotask(oldPosition.dispose);
    }
    _position = _effectiveScrollController.createScrollPosition(_physics!, this, oldPosition);
    assert(_position != nullptr);
    _effectiveScrollController.attach(position);
}

bool ScrollableState::_shouldUpdatePosition(Scrollable oldWidget) {
    ScrollPhysics newPhysics = widget.physics ?? widget.scrollBehavior?.getScrollPhysics(context);
    ScrollPhysics oldPhysics = oldWidget.physics ?? oldWidget.scrollBehavior?.getScrollPhysics(context);
    do {
        if (newPhysics?.runtimeType != oldPhysics?.runtimeType) {
            return true;
        }
        newPhysics = newPhysics?.parent;
        oldPhysics = oldPhysics?.parent;
    } while (newPhysics != nullptr || oldPhysics != nullptr);
    return widget.controller?.runtimeType != oldWidget.controller?.runtimeType;
}

void ScrollableState::_handleDragDown(DragDownDetails details) {
    assert(_drag == nullptr);
    assert(_hold == nullptr);
    _hold = position.hold(_disposeHold);
}

void ScrollableState::_handleDragStart(DragStartDetails details) {
    assert(_drag == nullptr);
    _drag = position.drag(details, _disposeDrag);
    assert(_drag != nullptr);
    assert(_hold == nullptr);
}

void ScrollableState::_handleDragUpdate(DragUpdateDetails details) {
    assert(_hold == nullptr || _drag == nullptr);
    _drag?.update(details);
}

void ScrollableState::_handleDragEnd(DragEndDetails details) {
    assert(_hold == nullptr || _drag == nullptr);
    _drag?.end(details);
    assert(_drag == nullptr);
}

void ScrollableState::_handleDragCancel() {
    assert(_hold == nullptr || _drag == nullptr);
    _hold?.cancel();
    _drag?.cancel();
    assert(_hold == nullptr);
    assert(_drag == nullptr);
}

void ScrollableState::_disposeHold() {
    _hold = nullptr;
}

void ScrollableState::_disposeDrag() {
    _drag = nullptr;
}

double ScrollableState::_targetScrollOffsetForPointerScroll(double delta) {
    return math.min(math.max(position.pixels + delta, position.minScrollExtent), position.maxScrollExtent);
}

double ScrollableState::_pointerSignalEventDelta(PointerScrollEvent event) {
    double delta = widget.axis == Axis.horizontal? event.scrollDelta.dx : event.scrollDelta.dy;
    if (axisDirectionIsReversed(widget.axisDirection)) {
        delta = -1;
    }
    return delta;
}

void ScrollableState::_receivedPointerSignal(PointerSignalEvent event) {
    if (event is PointerScrollEvent && _position != nullptr) {
        if (_physics != nullptr && !_physics!.shouldAcceptUserOffset(position)) {
            return;
        }
        double delta = _pointerSignalEventDelta(event);
        double targetScrollOffset = _targetScrollOffsetForPointerScroll(delta);
        if (delta != 0.0 && targetScrollOffset != position.pixels) {
            GestureBinding.instance.pointerSignalResolver.register(event, _handlePointerScroll);
        }
    }
}

void ScrollableState::_handlePointerScroll(PointerEvent event) {
    assert(event is PointerScrollEvent);
    double delta = _pointerSignalEventDelta(();
    double targetScrollOffset = _targetScrollOffsetForPointerScroll(delta);
    if (delta != 0.0 && targetScrollOffset != position.pixels) {
        position.pointerScroll(delta);
    }
}

bool ScrollableState::_handleScrollMetricsNotification(ScrollMetricsNotification notification) {
    if (notification.depth == 0) {
        RenderObject scrollSemanticsRenderObject = _scrollSemanticsKey.currentContext?.findRenderObject();
        if (scrollSemanticsRenderObject != nullptr) {
            scrollSemanticsRenderObject.markNeedsSemanticsUpdate();
        }
    }
    return false;
}

_ScrollableSelectionHandlerState _ScrollableSelectionHandler::createState() {
    return _ScrollableSelectionHandlerState();
}

void _ScrollableSelectionHandlerState::initState() {
    super.initState();
    _selectionDelegate = _ScrollableSelectionContainerDelegate(widget.state, widget.position);
}

void _ScrollableSelectionHandlerState::didUpdateWidget(_ScrollableSelectionHandler oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.position != widget.position) {
        _selectionDelegate.position = widget.position;
    }
}

void _ScrollableSelectionHandlerState::dispose() {
    _selectionDelegate.dispose();
    super.dispose();
}

Widget _ScrollableSelectionHandlerState::build(BuildContext context) {
    return SelectionContainer(widget.registrar, _selectionDelegate, widget.child);
}

bool EdgeDraggingAutoScroller::scrolling() {
    return _scrolling;
}

void EdgeDraggingAutoScroller::startAutoScrollIfNecessary(Rect dragTarget) {
    Offset deltaToOrigin = _getDeltaToScrollOrigin(scrollable);
    _dragTargetRelatedToScrollOrigin = dragTarget.translate(deltaToOrigin.dx, deltaToOrigin.dy);
    if (_scrolling) {
        return;
    }
    if (!_scrolling) {
        _scroll();
    }
}

void EdgeDraggingAutoScroller::stopAutoScroll() {
    _scrolling = false;
}

double EdgeDraggingAutoScroller::_offsetExtent(Offset offset, Axis scrollDirection) {
    ;
}

double EdgeDraggingAutoScroller::_sizeExtent(Axis scrollDirection, Size size) {
    ;
}

AxisDirection EdgeDraggingAutoScroller::_axisDirection() {
    return scrollable.axisDirection;
}

Axis EdgeDraggingAutoScroller::_scrollDirection() {
    return axisDirectionToAxis(_axisDirection);
}

Future<void> EdgeDraggingAutoScroller::_scroll() {
    RenderBox scrollRenderBox = (;
    Rect globalRect = MatrixUtils.transformRect(scrollRenderBox.getTransformTo(nullptr), Rect.fromLTWH(0, 0, scrollRenderBox.size.width, scrollRenderBox.size.height));
    _scrolling = true;
    double newOffset;
    double overDragMax = 20.0;
    Offset deltaToOrigin = _getDeltaToScrollOrigin(scrollable);
    Offset viewportOrigin = globalRect.topLeft.translate(deltaToOrigin.dx, deltaToOrigin.dy);
    double viewportStart = _offsetExtent(viewportOrigin, _scrollDirection);
    double viewportEnd = viewportStart + _sizeExtent(globalRect.size, _scrollDirection);
    double proxyStart = _offsetExtent(_dragTargetRelatedToScrollOrigin.topLeft, _scrollDirection);
    double proxyEnd = _offsetExtent(_dragTargetRelatedToScrollOrigin.bottomRight, _scrollDirection);
    double overDrag;
    if (_axisDirection == AxisDirection.up || _axisDirection == AxisDirection.left) {
        if (proxyEnd > viewportEnd && scrollable.position.pixels > scrollable.position.minScrollExtent) {
            overDrag = math.max(proxyEnd - viewportEnd, overDragMax);
            newOffset = math.max(scrollable.position.minScrollExtent, scrollable.position.pixels - overDrag);
        } else         {
            if ( < viewportStart && scrollable.position.pixels < scrollable.position.maxScrollExtent) {
            overDrag = math.max(viewportStart - proxyStart, overDragMax);
            newOffset = math.min(scrollable.position.maxScrollExtent, scrollable.position.pixels + overDrag);
        }
;
        }    } else {
        if ( < viewportStart && scrollable.position.pixels > scrollable.position.minScrollExtent) {
            overDrag = math.max(viewportStart - proxyStart, overDragMax);
            newOffset = math.max(scrollable.position.minScrollExtent, scrollable.position.pixels - overDrag);
        } else         {
            if (proxyEnd > viewportEnd && scrollable.position.pixels < scrollable.position.maxScrollExtent) {
            overDrag = math.max(proxyEnd - viewportEnd, overDragMax);
            newOffset = math.min(scrollable.position.maxScrollExtent, scrollable.position.pixels + overDrag);
        }
;
        }    }
    if (newOffset == nullptr || (newOffset - scrollable.position.pixels).abs() < 1.0) {
        _scrolling = false;
        return;
    }
    Duration duration = Duration((1000 / velocityScalar).round());
    await await scrollable.position.animateTo(newOffsetduration, Curves.linear);
    if (onScrollViewScrolled != nullptr) {
        onScrollViewScrolled!();
    }
    if (_scrolling) {
        await await _scroll();
    }
}

ScrollPosition _ScrollableSelectionContainerDelegate::position() {
    return _position;
}

void _ScrollableSelectionContainerDelegate::position(ScrollPosition other) {
    if (other == _position) {
        return;
    }
    _position.removeListener(_scheduleLayoutChange);
    _position = other;
    _position.addListener(_scheduleLayoutChange);
}

void _ScrollableSelectionContainerDelegate::didChangeSelectables() {
    Set<Selectable> selectableSet = selectables.toSet();
    _selectableStartEdgeUpdateRecords.removeWhere();
    _selectableEndEdgeUpdateRecords.removeWhere();
    super.didChangeSelectables();
}

SelectionResult _ScrollableSelectionContainerDelegate::handleClearSelection(ClearSelectionEvent event) {
    _selectableStartEdgeUpdateRecords.clear();
    _selectableEndEdgeUpdateRecords.clear();
    _currentDragStartRelatedToOrigin = nullptr;
    _currentDragEndRelatedToOrigin = nullptr;
    _selectionStartsInScrollable = false;
    return super.handleClearSelection(event);
}

SelectionResult _ScrollableSelectionContainerDelegate::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (_currentDragEndRelatedToOrigin == nullptr && _currentDragStartRelatedToOrigin == nullptr) {
        assert(!_selectionStartsInScrollable);
        _selectionStartsInScrollable = _globalPositionInScrollable(event.globalPosition);
    }
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    if (event.type == SelectionEventType.endEdgeUpdate) {
        _currentDragEndRelatedToOrigin = _inferPositionRelatedToOrigin(event.globalPosition);
        Offset endOffset = _currentDragEndRelatedToOrigin!.translate(-deltaToOrigin.dx, -deltaToOrigin.dy);
        event = SelectionEdgeUpdateEvent.forEnd(endOffset);
    } else {
        _currentDragStartRelatedToOrigin = _inferPositionRelatedToOrigin(event.globalPosition);
        Offset startOffset = _currentDragStartRelatedToOrigin!.translate(-deltaToOrigin.dx, -deltaToOrigin.dy);
        event = SelectionEdgeUpdateEvent.forStart(startOffset);
    }
    SelectionResult result = super.handleSelectionEdgeUpdate(event);
    if (result == SelectionResult.pending) {
        _autoScroller.stopAutoScroll();
        return result;
    }
    if (_selectionStartsInScrollable) {
        _autoScroller.startAutoScrollIfNecessary(_dragTargetFromEvent(event));
        if (_autoScroller.scrolling) {
            return SelectionResult.pending;
        }
    }
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegate::handleSelectAll(SelectAllSelectionEvent event) {
    assert(!_selectionStartsInScrollable);
    SelectionResult result = super.handleSelectAll(event);
    assert((currentSelectionStartIndex == -1) == (currentSelectionEndIndex == -1));
    if (currentSelectionStartIndex != -1) {
        _updateDragLocationsFromGeometries();
    }
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegate::handleSelectWord(SelectWordSelectionEvent event) {
    _selectionStartsInScrollable = _globalPositionInScrollable(event.globalPosition);
    SelectionResult result = super.handleSelectWord(event);
    _updateDragLocationsFromGeometries();
    return result;
}

SelectionResult _ScrollableSelectionContainerDelegate::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    ;
    return super.dispatchSelectionEventToChild(selectable, event);
}

void _ScrollableSelectionContainerDelegate::ensureChildUpdated(Selectable selectable) {
    double newRecord = state.position.pixels;
    double previousStartRecord = _selectableStartEdgeUpdateRecords[selectable];
    if (_currentDragStartRelatedToOrigin != nullptr && (previousStartRecord == nullptr || (newRecord - previousStartRecord).abs() > precisionErrorTolerance)) {
        Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
        Offset startOffset = _currentDragStartRelatedToOrigin!.translate(-deltaToOrigin.dx, -deltaToOrigin.dy);
        selectable.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forStart(startOffset));
    }
    double previousEndRecord = _selectableEndEdgeUpdateRecords[selectable];
    if (_currentDragEndRelatedToOrigin != nullptr && (previousEndRecord == nullptr || (newRecord - previousEndRecord).abs() > precisionErrorTolerance)) {
        Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
        Offset endOffset = _currentDragEndRelatedToOrigin!.translate(-deltaToOrigin.dx, -deltaToOrigin.dy);
        selectable.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forEnd(endOffset));
    }
}

void _ScrollableSelectionContainerDelegate::dispose() {
    _selectableStartEdgeUpdateRecords.clear();
    _selectableEndEdgeUpdateRecords.clear();
    _scheduledLayoutChange = false;
    _autoScroller.stopAutoScroll();
    super.dispose();
}

_ScrollableSelectionContainerDelegate::_ScrollableSelectionContainerDelegate(ScrollPosition position, ScrollableState state) {
    {
        _position = position;
        _autoScroller = EdgeDraggingAutoScroller(state_kDefaultSelectToScrollVelocityScalar);
    }
    {
        _position.addListener(_scheduleLayoutChange);
    }
}

void _ScrollableSelectionContainerDelegate::_scheduleLayoutChange() {
    if (_scheduledLayoutChange) {
        return;
    }
    _scheduledLayoutChange = true;
    SchedulerBinding.instance.addPostFrameCallback();
}

Offset _ScrollableSelectionContainerDelegate::_inferPositionRelatedToOrigin(Offset globalPosition) {
    RenderBox box = (;
    Offset localPosition = box.globalToLocal(globalPosition);
    if (!_selectionStartsInScrollable) {
        if (localPosition.dy < 0 || localPosition.dx < 0) {
            return box.localToGlobal(Offset.zero);
        }
        if (localPosition.dy > box.size.height || localPosition.dx > box.size.width) {
            return Offset.infinite;
        }
    }
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    return box.localToGlobal(localPosition.translate(deltaToOrigin.dx, deltaToOrigin.dy));
}

void _ScrollableSelectionContainerDelegate::_updateDragLocationsFromGeometries() {
    Offset deltaToOrigin = _getDeltaToScrollOrigin(state);
    RenderBox box = (;
    Matrix4 transform = box.getTransformTo(nullptr);
    if (currentSelectionStartIndex != -1) {
        SelectionGeometry geometry = selectables[currentSelectionStartIndex].value;
        assert(geometry.hasSelection);
        SelectionPoint start = geometry.startSelectionPoint!;
        Matrix4 childTransform = selectables[currentSelectionStartIndex].getTransformTo(box);
        Offset localDragStart = MatrixUtils.transformPoint(childTransform, start.localPosition + Offset(0, -start.lineHeight / 2));
        _currentDragStartRelatedToOrigin = MatrixUtils.transformPoint(transform, localDragStart + deltaToOrigin);
    }
    if (currentSelectionEndIndex != -1) {
        SelectionGeometry geometry = selectables[currentSelectionEndIndex].value;
        assert(geometry.hasSelection);
        SelectionPoint end = geometry.endSelectionPoint!;
        Matrix4 childTransform = selectables[currentSelectionEndIndex].getTransformTo(box);
        Offset localDragEnd = MatrixUtils.transformPoint(childTransform, end.localPosition + Offset(0, -end.lineHeight / 2));
        _currentDragEndRelatedToOrigin = MatrixUtils.transformPoint(transform, localDragEnd + deltaToOrigin);
    }
}

bool _ScrollableSelectionContainerDelegate::_globalPositionInScrollable(Offset globalPosition) {
    RenderBox box = (;
    Offset localPosition = box.globalToLocal(globalPosition);
    Rect rect = Rect.fromLTWH(0, 0, box.size.width, box.size.height);
    return rect.contains(localPosition);
}

Rect _ScrollableSelectionContainerDelegate::_dragTargetFromEvent(SelectionEdgeUpdateEvent event) {
    return Rect.fromCenter(event.globalPosition, _kDefaultDragTargetSize, _kDefaultDragTargetSize);
}

Offset _getDeltaToScrollOrigin(ScrollableState scrollableState) {
    ;
}

_RenderScrollSemantics _ScrollSemantics::createRenderObject(BuildContext context) {
    return _RenderScrollSemantics(position, allowImplicitScrolling, semanticChildCount);
}

void _ScrollSemantics::updateRenderObject(BuildContext context, _RenderScrollSemantics renderObject) {
    ;
}

_ScrollSemantics::_ScrollSemantics(bool allowImplicitScrolling, Unknown, Unknown, ScrollPosition position, int semanticChildCount) {
    {
        assert(position != nullptr);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
    }
}

ScrollPosition _RenderScrollSemantics::position() {
    return _position;
}

void _RenderScrollSemantics::position(ScrollPosition value) {
    assert(value != nullptr);
    if (value == _position) {
        return;
    }
    _position.removeListener(markNeedsSemanticsUpdate);
    _position = value;
    _position.addListener(markNeedsSemanticsUpdate);
    markNeedsSemanticsUpdate();
}

bool _RenderScrollSemantics::allowImplicitScrolling() {
    return _allowImplicitScrolling;
}

void _RenderScrollSemantics::allowImplicitScrolling(bool value) {
    if (value == _allowImplicitScrolling) {
        return;
    }
    _allowImplicitScrolling = value;
    markNeedsSemanticsUpdate();
}

int _RenderScrollSemantics::semanticChildCount() {
    return _semanticChildCount;
}

void _RenderScrollSemantics::semanticChildCount(int value) {
    if (value == semanticChildCount) {
        return;
    }
    _semanticChildCount = value;
    markNeedsSemanticsUpdate();
}

void _RenderScrollSemantics::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.isSemanticBoundary = true;
    if (position.haveDimensions) {
        ;
    }
}

void _RenderScrollSemantics::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    if (children.isEmpty || !children.first.isTagged(RenderViewport.useTwoPaneSemantics)) {
        super.assembleSemanticsNode(node, config, children);
        return;
    }
    _innerNode = SemanticsNode(showOnScreen);
    ;
    int firstVisibleIndex;
    List<SemanticsNode> excluded = ;
    List<SemanticsNode> included = ;
    for (SemanticsNode child : children) {
        assert(child.isTagged(RenderViewport.useTwoPaneSemantics));
        if (child.isTagged(RenderViewport.excludeFromScrolling)) {
            excluded.add(child);
        } else {
            if (!child.hasFlag(SemanticsFlag.isHidden)) {
                firstVisibleIndex = child.indexInParent;
            }
            included.add(child);
        }
    }
    config.scrollIndex = firstVisibleIndex;
    node.updateWith(nullptr, excluded);
    _innerNode!.updateWith(config, included);
}

void _RenderScrollSemantics::clearSemantics() {
    super.clearSemantics();
    _innerNode = nullptr;
}

_RenderScrollSemantics::_RenderScrollSemantics(bool allowImplicitScrolling, RenderBox child, ScrollPosition position, int semanticChildCount) {
    {
        _position = position;
        _allowImplicitScrolling = allowImplicitScrolling;
        _semanticChildCount = semanticChildCount;
        assert(position != nullptr);
        super(child);
    }
    {
        position.addListener(markNeedsSemanticsUpdate);
    }
}

ScrollIncrementDetails::ScrollIncrementDetails(ScrollMetrics metrics, ScrollIncrementType type) {
    {
        assert(type != nullptr);
        assert(metrics != nullptr);
    }
}

ScrollIntent::ScrollIntent(AxisDirection direction, ScrollIncrementType type) {
    {
        assert(direction != nullptr);
        assert(type != nullptr);
    }
}

bool ScrollAction::isEnabled(ScrollIntent intent) {
    FocusNode focus = primaryFocus;
    bool contextIsValid = focus != nullptr && focus.context != nullptr;
    if (contextIsValid) {
        if (Scrollable.of(focus.context!) != nullptr) {
            return true;
        }
        ScrollController primaryScrollController = PrimaryScrollController.of(focus.context!);
        return primaryScrollController != nullptr && primaryScrollController.hasClients;
    }
    return false;
}

void ScrollAction::invoke(ScrollIntent intent) {
    ScrollableState state = Scrollable.of(primaryFocus!.context!);
    if (state == nullptr) {
        ScrollController primaryScrollController = PrimaryScrollController.of(primaryFocus!.context!);
        assert(());
        if (primaryScrollController!.position.context.notificationContext == nullptr && Scrollable.of(primaryScrollController.position.context.notificationContext!) == nullptr) {
            return;
        }
        state = Scrollable.of(primaryScrollController.position.context.notificationContext!);
    }
    assert(state != nullptr, "$ScrollAction was invoked on a context that has no scrollable parent");
    assert(state!.position.hasPixels, "Scrollable must be laid out before it can be scrolled via a ScrollAction");
    assert(state!.position.viewportDimension != nullptr);
    assert(state!.position.maxScrollExtent != nullptr);
    assert(state!.position.minScrollExtent != nullptr);
    if (state!._physics != nullptr && !state._physics!.shouldAcceptUserOffset(state.position)) {
        return;
    }
    double increment = _getIncrement(state, intent);
    if (increment == 0.0) {
        return;
    }
    state.position.moveTo(state.position.pixels + incrementconst Duration(100), Curves.easeInOut);
}

double ScrollAction::_calculateScrollIncrement(ScrollableState state, ScrollIncrementType type) {
    assert(type != nullptr);
    assert(state.position != nullptr);
    assert(state.position.hasPixels);
    assert(state.position.viewportDimension != nullptr);
    assert(state.position.maxScrollExtent != nullptr);
    assert(state.position.minScrollExtent != nullptr);
    assert(state._physics == nullptr || state._physics!.shouldAcceptUserOffset(state.position));
    if (state.widget.incrementCalculator != nullptr) {
        return state.widget.incrementCalculator!(ScrollIncrementDetails(type, state.position));
    }
    ;
}

double ScrollAction::_getIncrement(ScrollIntent intent, ScrollableState state) {
    double increment = _calculateScrollIncrement(stateintent.type);
    ;
}

double _RestorableScrollOffset::createDefaultValue() {
    return nullptr;
}

void _RestorableScrollOffset::didUpdateValue(double oldValue) {
    notifyListeners();
}

double _RestorableScrollOffset::fromPrimitives(Object data) {
    return (;
}

Object _RestorableScrollOffset::toPrimitives() {
    return value;
}

bool _RestorableScrollOffset::enabled() {
    return value != nullptr;
}
