#include "selectable_region.hpp"
State<StatefulWidget> SelectableRegionCls::createState() {
    return make<_SelectableRegionStateCls>();
}

void _SelectableRegionStateCls::initState() {
    super->initState();
    widget->focusNode->addListener(_handleFocusChanged);
    _initMouseGestureRecognizer();
    _initTouchGestureRecognizer();
    _gestureRecognizers[TapGestureRecognizerCls] = <TapGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<TapGestureRecognizerCls>(this);
    }, [=] (TapGestureRecognizer instance) {
        instance->onTap = _clearSelection;
        instance->onSecondaryTapDown = _handleRightClickDown;
    });
}

void _SelectableRegionStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    ;
    Orientation orientation = MediaQueryCls->of(context)->orientation;
    if (_lastOrientation == nullptr) {
        _lastOrientation = orientation;
        return;
    }
    if (orientation != _lastOrientation) {
        _lastOrientation = orientation;
        hideToolbar(defaultTargetPlatform == TargetPlatformCls::android);
    }
}

void _SelectableRegionStateCls::didUpdateWidget(SelectableRegion oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->focusNode != oldWidget->focusNode) {
        oldWidget->focusNode->removeListener(_handleFocusChanged);
        widget->focusNode->addListener(_handleFocusChanged);
        if (widget->focusNode->hasFocus != oldWidget->focusNode->hasFocus()) {
            _handleFocusChanged();
        }
    }
}

bool _SelectableRegionStateCls::cutEnabled() {
    return false;
}

bool _SelectableRegionStateCls::pasteEnabled() {
    return false;
}

void _SelectableRegionStateCls::hideToolbar(bool hideHandles) {
    _selectionOverlay?->hideToolbar();
    if (hideHandles) {
        _selectionOverlay?->hideHandles();
    }
}

void _SelectableRegionStateCls::selectAll(SelectionChangedCause cause) {
    _clearSelection();
    _selectable?->dispatchSelectionEvent(make<SelectAllSelectionEventCls>());
    if (cause == SelectionChangedCauseCls::toolbar) {
        _showToolbar();
        _showHandles();
    }
}

void _SelectableRegionStateCls::copySelection(SelectionChangedCause cause) {
    _copy();
    _clearSelection();
}

void _SelectableRegionStateCls::bringIntoView(TextPosition position) {
}

void _SelectableRegionStateCls::cutSelection(SelectionChangedCause cause) {
    assert(false);
}

void _SelectableRegionStateCls::userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value) {
}

Future<void> _SelectableRegionStateCls::pasteText(SelectionChangedCause cause) {
    assert(false);
}

void _SelectableRegionStateCls::add(Selectable selectable) {
    assert(_selectable == nullptr);
    _selectable = selectable;
    _selectable!->addListener(_updateSelectionStatus);
    _selectable!->pushHandleLayers(_startHandleLayerLink, _endHandleLayerLink);
}

void _SelectableRegionStateCls::remove(Selectable selectable) {
    assert(_selectable == selectable);
    _selectable!->removeListener(_updateSelectionStatus);
    _selectable!->pushHandleLayers(nullptr, nullptr);
    _selectable = nullptr;
}

void _SelectableRegionStateCls::dispose() {
    _selectable?->removeListener(_updateSelectionStatus);
    _selectable?->pushHandleLayers(nullptr, nullptr);
    _selectionDelegate->dispose();
    _selectionOverlay?->dispose();
    _selectionOverlay = nullptr;
    super->dispose();
}

Widget _SelectableRegionStateCls::build(BuildContext context) {
    assert(OverlayCls->of(contextwidget) != nullptr);
    return make<CompositedTransformTargetCls>(_toolbarLayerLink, make<RawGestureDetectorCls>(_gestureRecognizers, HitTestBehaviorCls::translucent, true, make<ActionsCls>(_actions, make<FocusCls>(false, widget->focusNode, make<SelectionContainerCls>(this, _selectionDelegate, widget->child)))));
}

bool _SelectableRegionStateCls::_hasSelectionOverlayGeometry() {
    return _selectionDelegate->value->startSelectionPoint != nullptr || _selectionDelegate->value->endSelectionPoint != nullptr;
}

Action<T> _SelectableRegionStateCls::_makeOverridabletemplate<typename T> (Action<T> defaultAction) {
    return <T>overridable(context, defaultAction);
}

void _SelectableRegionStateCls::_handleFocusChanged() {
    if (!widget->focusNode->hasFocus) {
        _clearSelection();
    }
}

void _SelectableRegionStateCls::_updateSelectionStatus() {
    TextSelection selection;
    SelectionGeometry geometry = _selectionDelegate->value;
    ;
    textEditingValue = make<TextEditingValueCls>(__s("__"), selection);
    if (_hasSelectionOverlayGeometry()) {
        _updateSelectionOverlay();
    } else {
        _selectionOverlay?->dispose();
        _selectionOverlay = nullptr;
    }
}

void _SelectableRegionStateCls::_initMouseGestureRecognizer() {
    _gestureRecognizers[PanGestureRecognizerCls] = <PanGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<PanGestureRecognizerCls>(this, makeSet(ArrayItem));
    }, [=] (PanGestureRecognizer instance) {
            auto _c1 = instance;    _c1.onDown = auto _c2 = _startNewMouseSelectionGesture;    _c2.onStart = auto _c3 = _handleMouseDragStart;    _c3.onUpdate = auto _c4 = _handleMouseDragUpdate;    _c4.onEnd = auto _c5 = _handleMouseDragEnd;    _c5.onCancel = auto _c6 = _clearSelection;    _c6.dragStartBehavior = DragStartBehaviorCls::down;    _c6;    _c5;    _c4;    _c3;    _c2;_c1;
    });
}

void _SelectableRegionStateCls::_initTouchGestureRecognizer() {
    _gestureRecognizers[LongPressGestureRecognizerCls] = <LongPressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<LongPressGestureRecognizerCls>(this, _kLongPressSelectionDevices);
    }, [=] (LongPressGestureRecognizer instance) {
            auto _c1 = instance;    _c1.onLongPressStart = auto _c2 = _handleTouchLongPressStart;    _c2.onLongPressMoveUpdate = auto _c3 = _handleTouchLongPressMoveUpdate;    _c3.onLongPressEnd = auto _c4 = _handleTouchLongPressEnd;    _c4.onLongPressCancel = _clearSelection;    _c4;    _c3;    _c2;_c1;
    });
}

void _SelectableRegionStateCls::_startNewMouseSelectionGesture(DragDownDetails details) {
    widget->focusNode->requestFocus();
    hideToolbar();
    _clearSelection();
}

void _SelectableRegionStateCls::_handleMouseDragStart(DragStartDetails details) {
    _selectStartTo(details->globalPosition);
}

void _SelectableRegionStateCls::_handleMouseDragUpdate(DragUpdateDetails details) {
    _selectEndTo(details->globalPosition, true);
}

void _SelectableRegionStateCls::_handleMouseDragEnd(DragEndDetails details) {
    _finalizeSelection();
}

void _SelectableRegionStateCls::_handleTouchLongPressStart(LongPressStartDetails details) {
    widget->focusNode->requestFocus();
    _selectWordAt(details->globalPosition);
    _showToolbar();
    _showHandles();
}

void _SelectableRegionStateCls::_handleTouchLongPressMoveUpdate(LongPressMoveUpdateDetails details) {
    _selectEndTo(details->globalPosition);
}

void _SelectableRegionStateCls::_handleTouchLongPressEnd(LongPressEndDetails details) {
    _finalizeSelection();
}

void _SelectableRegionStateCls::_handleRightClickDown(TapDownDetails details) {
    widget->focusNode->requestFocus();
    _selectWordAt(details->globalPosition);
    _showHandles();
    _showToolbar(details->globalPosition);
}

bool _SelectableRegionStateCls::_userDraggingSelectionEnd() {
    return _selectionEndPosition != nullptr;
}

void _SelectableRegionStateCls::_triggerSelectionEndEdgeUpdate() {
    if (_scheduledSelectionEndEdgeUpdate || !_userDraggingSelectionEnd()) {
        return;
    }
    if (_selectable?->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forEnd(_selectionEndPosition!)) == SelectionResultCls::pending) {
        _scheduledSelectionEndEdgeUpdate = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            if (!_scheduledSelectionEndEdgeUpdate) {
                return;
            }
            _scheduledSelectionEndEdgeUpdate = false;
            _triggerSelectionEndEdgeUpdate();
        });
        return;
    }
}

void _SelectableRegionStateCls::_stopSelectionEndEdgeUpdate() {
    _scheduledSelectionEndEdgeUpdate = false;
    _selectionEndPosition = nullptr;
}

bool _SelectableRegionStateCls::_userDraggingSelectionStart() {
    return _selectionStartPosition != nullptr;
}

void _SelectableRegionStateCls::_triggerSelectionStartEdgeUpdate() {
    if (_scheduledSelectionStartEdgeUpdate || !_userDraggingSelectionStart()) {
        return;
    }
    if (_selectable?->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forStart(_selectionStartPosition!)) == SelectionResultCls::pending) {
        _scheduledSelectionStartEdgeUpdate = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            if (!_scheduledSelectionStartEdgeUpdate) {
                return;
            }
            _scheduledSelectionStartEdgeUpdate = false;
            _triggerSelectionStartEdgeUpdate();
        });
        return;
    }
}

void _SelectableRegionStateCls::_stopSelectionStartEdgeUpdate() {
    _scheduledSelectionStartEdgeUpdate = false;
    _selectionEndPosition = nullptr;
}

void _SelectableRegionStateCls::_handleSelectionStartHandleDragStart(DragStartDetails details) {
    assert(_selectionDelegate->value->startSelectionPoint != nullptr);
    Offset localPosition = _selectionDelegate->value->startSelectionPoint!->localPosition;
    Matrix4 globalTransform = _selectable!->getTransformTo(nullptr);
    _selectionStartHandleDragPosition = MatrixUtilsCls->transformPoint(globalTransform, localPosition);
}

void _SelectableRegionStateCls::_handleSelectionStartHandleDragUpdate(DragUpdateDetails details) {
    _selectionStartHandleDragPosition = _selectionStartHandleDragPosition + details->delta;
    _selectionStartPosition = _selectionStartHandleDragPosition - make<OffsetCls>(0, _selectionDelegate->value->startSelectionPoint!->lineHeight / 2);
    _triggerSelectionStartEdgeUpdate();
}

void _SelectableRegionStateCls::_handleSelectionEndHandleDragStart(DragStartDetails details) {
    assert(_selectionDelegate->value->endSelectionPoint != nullptr);
    Offset localPosition = _selectionDelegate->value->endSelectionPoint!->localPosition;
    Matrix4 globalTransform = _selectable!->getTransformTo(nullptr);
    _selectionEndHandleDragPosition = MatrixUtilsCls->transformPoint(globalTransform, localPosition);
}

void _SelectableRegionStateCls::_handleSelectionEndHandleDragUpdate(DragUpdateDetails details) {
    _selectionEndHandleDragPosition = _selectionEndHandleDragPosition + details->delta;
    _selectionEndPosition = _selectionEndHandleDragPosition - make<OffsetCls>(0, _selectionDelegate->value->endSelectionPoint!->lineHeight / 2);
    _triggerSelectionEndEdgeUpdate();
}

void _SelectableRegionStateCls::_createSelectionOverlay() {
    assert(_hasSelectionOverlayGeometry());
    if (_selectionOverlay != nullptr) {
        return;
    }
    SelectionPoint start = _selectionDelegate->value->startSelectionPoint;
    SelectionPoint end = _selectionDelegate->value->endSelectionPoint;
    List<TextSelectionPoint> points;
    Offset startLocalPosition = start?->localPosition or end!->localPosition;
    Offset endLocalPosition = end?->localPosition or start!->localPosition;
    if (startLocalPosition->dy() > endLocalPosition->dy()) {
        points = makeList(ArrayItem, ArrayItem);
    } else {
        points = makeList(ArrayItem, ArrayItem);
    }
    _selectionOverlay = make<SelectionOverlayCls>(context, widget, start?->handleType or TextSelectionHandleTypeCls::left, start?->lineHeight or end!->lineHeight, _handleSelectionStartHandleDragStart, _handleSelectionStartHandleDragUpdate, [=] (DragEndDetails details)     {
        _stopSelectionStartEdgeUpdate();
    }, end?->handleType or TextSelectionHandleTypeCls::right, end?->lineHeight or start!->lineHeight, _handleSelectionEndHandleDragStart, _handleSelectionEndHandleDragUpdate, [=] (DragEndDetails details)     {
        _stopSelectionEndEdgeUpdate();
    }, points, widget->selectionControls, this, nullptr, _startHandleLayerLink, _endHandleLayerLink, _toolbarLayerLink);
}

void _SelectableRegionStateCls::_updateSelectionOverlay() {
    if (_selectionOverlay == nullptr) {
        return;
    }
    assert(_hasSelectionOverlayGeometry());
    SelectionPoint start = _selectionDelegate->value->startSelectionPoint;
    SelectionPoint end = _selectionDelegate->value->endSelectionPoint;
    List<TextSelectionPoint> points;
    Offset startLocalPosition = start?->localPosition or end!->localPosition;
    Offset endLocalPosition = end?->localPosition or start!->localPosition;
    if (startLocalPosition->dy() > endLocalPosition->dy()) {
        points = makeList(ArrayItem, ArrayItem);
    } else {
        points = makeList(ArrayItem, ArrayItem);
    }
    auto _c1 = _selectionOverlay!;_c1.startHandleType = auto _c2 = start?->handleType or TextSelectionHandleTypeCls::left;_c2.lineHeightAtStart = auto _c3 = start?->lineHeight or end!->lineHeight;_c3.endHandleType = auto _c4 = end?->handleType or TextSelectionHandleTypeCls::right;_c4.lineHeightAtEnd = auto _c5 = end?->lineHeight or start!->lineHeight;_c5.selectionEndpoints = points;_c5;_c4;_c3;_c2;_c1;
}

bool _SelectableRegionStateCls::_showHandles() {
    if (_selectionOverlay != nullptr) {
        _selectionOverlay!->showHandles();
        return true;
    }
    if (!_hasSelectionOverlayGeometry()) {
        return false;
    }
    _createSelectionOverlay();
    _selectionOverlay!->showHandles();
    return true;
}

bool _SelectableRegionStateCls::_showToolbar(Offset location) {
    if (!_hasSelectionOverlayGeometry() && _selectionOverlay == nullptr) {
        return false;
    }
    if (kIsWeb) {
        return false;
    }
    if (_selectionOverlay == nullptr) {
        _createSelectionOverlay();
    }
    _selectionOverlay!->toolbarLocation() = location;
    _selectionOverlay!->showToolbar();
    return true;
}

void _SelectableRegionStateCls::_selectEndTo(bool continuous, Offset offset) {
    if (!continuous) {
        _selectable?->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forEnd(offset));
        return;
    }
    if (_selectionEndPosition != offset) {
        _selectionEndPosition = offset;
        _triggerSelectionEndEdgeUpdate();
    }
}

void _SelectableRegionStateCls::_selectStartTo(bool continuous, Offset offset) {
    if (!continuous) {
        _selectable?->dispatchSelectionEvent(SelectionEdgeUpdateEventCls->forStart(offset));
        return;
    }
    if (_selectionStartPosition != offset) {
        _selectionStartPosition = offset;
        _triggerSelectionStartEdgeUpdate();
    }
}

void _SelectableRegionStateCls::_selectWordAt(Offset offset) {
    _finalizeSelection();
    _selectable?->dispatchSelectionEvent(make<SelectWordSelectionEventCls>(offset));
}

void _SelectableRegionStateCls::_finalizeSelection() {
    _stopSelectionEndEdgeUpdate();
    _stopSelectionStartEdgeUpdate();
}

void _SelectableRegionStateCls::_clearSelection() {
    _finalizeSelection();
    _selectable?->dispatchSelectionEvent(make<ClearSelectionEventCls>());
}

Future<void> _SelectableRegionStateCls::_copy() {
    SelectedContent data = _selectable?->getSelectedContent();
    if (data == nullptr) {
        return;
    }
    await await ClipboardCls->setData(make<ClipboardDataCls>(data->plainText));
}

template<typename T> Object _NonOverrideActionCls<T>::invoke(BuildContext context, T intent) {
    if (callingAction != nullptr) {
        return callingAction!->invoke(intent);
    }
    return invokeAction(intent, context);
}

void _SelectAllActionCls::invokeAction(BuildContext context, SelectAllTextIntent intent) {
    state->selectAll(SelectionChangedCauseCls::keyboard);
}

void _CopySelectionActionCls::invokeAction(BuildContext context, CopySelectionTextIntent intent) {
    state->_copy();
}

void _SelectableRegionContainerDelegateCls::remove(Selectable selectable) {
    _hasReceivedStartEvent->remove(selectable);
    _hasReceivedEndEvent->remove(selectable);
    super->remove(selectable);
}

SelectionResult _SelectableRegionContainerDelegateCls::handleSelectAll(SelectAllSelectionEvent event) {
    SelectionResult result = super->handleSelectAll(event);
    for (Selectable selectable : selectables) {
        _hasReceivedStartEvent->add(selectable);
        _hasReceivedEndEvent->add(selectable);
    }
    _updateLastEdgeEventsFromGeometries();
    return result;
}

SelectionResult _SelectableRegionContainerDelegateCls::handleSelectWord(SelectWordSelectionEvent event) {
    SelectionResult result = super->handleSelectWord(event);
    if (currentSelectionStartIndex != -1) {
        _hasReceivedStartEvent->add(selectables[currentSelectionStartIndex]);
    }
    if (currentSelectionEndIndex != -1) {
        _hasReceivedEndEvent->add(selectables[currentSelectionEndIndex]);
    }
    _updateLastEdgeEventsFromGeometries();
    return result;
}

SelectionResult _SelectableRegionContainerDelegateCls::handleClearSelection(ClearSelectionEvent event) {
    SelectionResult result = super->handleClearSelection(event);
    _hasReceivedStartEvent->clear();
    _hasReceivedEndEvent->clear();
    _lastStartEdgeUpdateGlobalPosition = nullptr;
    _lastEndEdgeUpdateGlobalPosition = nullptr;
    return result;
}

SelectionResult _SelectableRegionContainerDelegateCls::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (event->type == SelectionEventTypeCls::endEdgeUpdate) {
        _lastEndEdgeUpdateGlobalPosition = event->globalPosition;
    } else {
        _lastStartEdgeUpdateGlobalPosition = event->globalPosition;
    }
    return super->handleSelectionEdgeUpdate(event);
}

void _SelectableRegionContainerDelegateCls::dispose() {
    _hasReceivedStartEvent->clear();
    _hasReceivedEndEvent->clear();
    super->dispose();
}

SelectionResult _SelectableRegionContainerDelegateCls::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    ;
    return super->dispatchSelectionEventToChild(selectable, event);
}

void _SelectableRegionContainerDelegateCls::ensureChildUpdated(Selectable selectable) {
    if (_lastEndEdgeUpdateGlobalPosition != nullptr && _hasReceivedEndEvent->add(selectable)) {
        SelectionEdgeUpdateEvent synthesizedEvent = SelectionEdgeUpdateEventCls->forEnd(_lastEndEdgeUpdateGlobalPosition!);
        if (currentSelectionEndIndex == -1) {
            handleSelectionEdgeUpdate(synthesizedEvent);
        }
        selectable->dispatchSelectionEvent(synthesizedEvent);
    }
    if (_lastStartEdgeUpdateGlobalPosition != nullptr && _hasReceivedStartEvent->add(selectable)) {
        SelectionEdgeUpdateEvent synthesizedEvent = SelectionEdgeUpdateEventCls->forStart(_lastStartEdgeUpdateGlobalPosition!);
        if (currentSelectionStartIndex == -1) {
            handleSelectionEdgeUpdate(synthesizedEvent);
        }
        selectable->dispatchSelectionEvent(synthesizedEvent);
    }
}

void _SelectableRegionContainerDelegateCls::didChangeSelectables() {
    if (_lastEndEdgeUpdateGlobalPosition != nullptr) {
        handleSelectionEdgeUpdate(SelectionEdgeUpdateEventCls->forEnd(_lastEndEdgeUpdateGlobalPosition!));
    }
    if (_lastStartEdgeUpdateGlobalPosition != nullptr) {
        handleSelectionEdgeUpdate(SelectionEdgeUpdateEventCls->forStart(_lastStartEdgeUpdateGlobalPosition!));
    }
    Set<Selectable> selectableSet = selectables->toSet();
    _hasReceivedEndEvent->removeWhere([=] (Selectable selectable)     {
        !selectableSet->contains(selectable);
    });
    _hasReceivedStartEvent->removeWhere([=] (Selectable selectable)     {
        !selectableSet->contains(selectable);
    });
    super->didChangeSelectables();
}

void _SelectableRegionContainerDelegateCls::_updateLastEdgeEventsFromGeometries() {
    if (currentSelectionStartIndex != -1) {
        Selectable start = selectables[currentSelectionStartIndex];
        Offset localStartEdge = start->value->startSelectionPoint!->localPosition + make<OffsetCls>(0, -start->value->startSelectionPoint!->lineHeight / 2);
        _lastStartEdgeUpdateGlobalPosition = MatrixUtilsCls->transformPoint(start->getTransformTo(nullptr), localStartEdge);
    }
    if (currentSelectionEndIndex != -1) {
        Selectable end = selectables[currentSelectionEndIndex];
        Offset localEndEdge = end->value->endSelectionPoint!->localPosition + make<OffsetCls>(0, -end->value->endSelectionPoint!->lineHeight / 2);
        _lastEndEdgeUpdateGlobalPosition = MatrixUtilsCls->transformPoint(end->getTransformTo(nullptr), localEndEdge);
    }
}

void MultiSelectableSelectionContainerDelegateCls::add(Selectable selectable) {
    assert(!selectables->contains(selectable));
    _additions->add(selectable);
    _scheduleSelectableUpdate();
}

void MultiSelectableSelectionContainerDelegateCls::remove(Selectable selectable) {
    if (_additions->remove(selectable)) {
        return;
    }
    _removeSelectable(selectable);
    _scheduleSelectableUpdate();
}

void MultiSelectableSelectionContainerDelegateCls::layoutDidChange() {
    _updateSelectionGeometry();
}

void MultiSelectableSelectionContainerDelegateCls::didChangeSelectables() {
    _updateSelectionGeometry();
}

SelectionGeometry MultiSelectableSelectionContainerDelegateCls::value() {
    return _selectionGeometry;
}

Comparator<Selectable> MultiSelectableSelectionContainerDelegateCls::compareOrder() {
    return _compareScreenOrder;
}

SelectionGeometry MultiSelectableSelectionContainerDelegateCls::getSelectionGeometry() {
    if (currentSelectionEndIndex == -1 || currentSelectionStartIndex == -1 || selectables->isEmpty) {
        return make<SelectionGeometryCls>(SelectionStatusCls::none, selectables->isNotEmpty);
    }
    currentSelectionStartIndex = _adjustSelectionIndexBasedOnSelectionGeometry(currentSelectionStartIndex, currentSelectionEndIndex);
    currentSelectionEndIndex = _adjustSelectionIndexBasedOnSelectionGeometry(currentSelectionEndIndex, currentSelectionStartIndex);
    SelectionGeometry startGeometry = selectables[currentSelectionStartIndex]->value;
    bool forwardSelection = currentSelectionEndIndex >= currentSelectionStartIndex;
    int startIndexWalker = currentSelectionStartIndex;
    while (startIndexWalker != currentSelectionEndIndex && startGeometry->startSelectionPoint == nullptr) {
        startIndexWalker = forwardSelection? 1 : -1;
        startGeometry = selectables[startIndexWalker]->value;
    }
    SelectionPoint startPoint;
    if (startGeometry->startSelectionPoint != nullptr) {
        Matrix4 startTransform = getTransformFrom(selectables[startIndexWalker]);
        Offset start = MatrixUtilsCls->transformPoint(startTransform, startGeometry->startSelectionPoint!->localPosition);
        if (start->isFinite) {
            startPoint = make<SelectionPointCls>(start, startGeometry->startSelectionPoint!->lineHeight, startGeometry->startSelectionPoint!->handleType);
        }
    }
    SelectionGeometry endGeometry = selectables[currentSelectionEndIndex]->value;
    int endIndexWalker = currentSelectionEndIndex;
    while (endIndexWalker != currentSelectionStartIndex && endGeometry->endSelectionPoint == nullptr) {
        endIndexWalker = forwardSelection? -1 : 1;
        endGeometry = selectables[endIndexWalker]->value;
    }
    SelectionPoint endPoint;
    if (endGeometry->endSelectionPoint != nullptr) {
        Matrix4 endTransform = getTransformFrom(selectables[endIndexWalker]);
        Offset end = MatrixUtilsCls->transformPoint(endTransform, endGeometry->endSelectionPoint!->localPosition);
        if (end->isFinite) {
            endPoint = make<SelectionPointCls>(end, endGeometry->endSelectionPoint!->lineHeight, endGeometry->endSelectionPoint!->handleType);
        }
    }
    return make<SelectionGeometryCls>(startPoint, endPoint, startGeometry != endGeometry? SelectionStatusCls::uncollapsed : startGeometry->status, true);
}

void MultiSelectableSelectionContainerDelegateCls::pushHandleLayers(LayerLink endHandle, LayerLink startHandle) {
    if (_startHandleLayer == startHandle && _endHandleLayer == endHandle) {
        return;
    }
    _startHandleLayer = startHandle;
    _endHandleLayer = endHandle;
    _updateHandleLayersAndOwners();
}

SelectedContent MultiSelectableSelectionContainerDelegateCls::getSelectedContent() {
    List<SelectedContent> selections = makeList();
    for (Selectable selectable : selectables) {
        SelectedContent data = selectable->getSelectedContent();
        if (data != nullptr) {
            selections->add(data);
        }
    }
    if (selections->isEmpty) {
        return nullptr;
    }
    StringBuffer buffer = make<StringBufferCls>();
    for (SelectedContent selection : selections) {
        buffer->write(selection->plainText);
    }
    return make<SelectedContentCls>(buffer->toString());
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::handleSelectAll(SelectAllSelectionEvent event) {
    for (Selectable selectable : selectables) {
        dispatchSelectionEventToChild(selectable, event);
    }
    currentSelectionStartIndex = 0;
    currentSelectionEndIndex = selectables->length() - 1;
    return SelectionResultCls::none;
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::handleSelectWord(SelectWordSelectionEvent event) {
    for (;  < selectables->length(); index = 1) {
        Rect localRect = RectCls->fromLTWH(0, 0, selectables[index]->size()->width(), selectables[index]->size()->height());
        Matrix4 transform = selectables[index]->getTransformTo(nullptr);
        Rect globalRect = MatrixUtilsCls->transformRect(transform, localRect);
        if (globalRect->contains(event->globalPosition)) {
            SelectionGeometry existingGeometry = selectables[index]->value;
            dispatchSelectionEventToChild(selectables[index], event);
            if (selectables[index]->value != existingGeometry) {
                selectables->where([=] (Selectable target)                 {
                    target != selectables[index];
                })->forEach([=] (Selectable target)                 {
                    dispatchSelectionEventToChild(target, make<ClearSelectionEventCls>());
                });
                currentSelectionStartIndex = currentSelectionEndIndex = index;
            }
            return SelectionResultCls::end;
        }
    }
    return SelectionResultCls::none;
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::handleClearSelection(ClearSelectionEvent event) {
    for (Selectable selectable : selectables) {
        dispatchSelectionEventToChild(selectable, event);
    }
    currentSelectionEndIndex = -1;
    currentSelectionStartIndex = -1;
    return SelectionResultCls::none;
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (event->type == SelectionEventTypeCls::endEdgeUpdate) {
        return currentSelectionEndIndex == -1? _initSelection(eventtrue) : _adjustSelection(eventtrue);
    }
    return currentSelectionStartIndex == -1? _initSelection(eventfalse) : _adjustSelection(eventfalse);
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::dispatchSelectionEvent(SelectionEvent event) {
    bool selectionWillbeInProgress = !is<ClearSelectionEvent>(event);
    if (!_selectionInProgress && selectionWillbeInProgress) {
        selectables->sort(compareOrder());
    }
    _selectionInProgress = selectionWillbeInProgress;
    _isHandlingSelectionEvent = true;
    SelectionResult result;
    ;
    _isHandlingSelectionEvent = false;
    _updateSelectionGeometry();
    return result;
}

void MultiSelectableSelectionContainerDelegateCls::dispose() {
    for (Selectable selectable : selectables) {
        selectable->removeListener(_handleSelectableGeometryChange);
    }
    selectables = makeList();
    _scheduledSelectableUpdate = false;
    super->dispose();
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    return selectable->dispatchSelectionEvent(event);
}

void MultiSelectableSelectionContainerDelegateCls::_scheduleSelectableUpdate() {
    if (!_scheduledSelectableUpdate) {
        _scheduledSelectableUpdate = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            if (!_scheduledSelectableUpdate) {
                return;
            }
            _scheduledSelectableUpdate = false;
            _updateSelectables();
        });
    }
}

void MultiSelectableSelectionContainerDelegateCls::_updateSelectables() {
    if (_additions->isNotEmpty) {
        _flushAdditions();
    }
    didChangeSelectables();
}

void MultiSelectableSelectionContainerDelegateCls::_flushAdditions() {
    auto _c1 = _additions->toList();_c1.sort(compareOrder());List<Selectable> mergingSelectables = _c1;
    List<Selectable> existingSelectables = selectables;
    selectables = makeList();
    int mergingIndex = 0;
    int existingIndex = 0;
    int selectionStartIndex = currentSelectionStartIndex;
    int selectionEndIndex = currentSelectionEndIndex;
    while ( < mergingSelectables->length() ||  < existingSelectables->length()) {
        if (mergingIndex >= mergingSelectables->length() || ( < existingSelectables->length() && compareOrder(existingSelectables[existingIndex], mergingSelectables[mergingIndex]) < 0)) {
            if (existingIndex == currentSelectionStartIndex) {
                selectionStartIndex = selectables->length();
            }
            if (existingIndex == currentSelectionEndIndex) {
                selectionEndIndex = selectables->length();
            }
            selectables->add(existingSelectables[existingIndex]);
            existingIndex = 1;
            continue;
        }
        Selectable mergingSelectable = mergingSelectables[mergingIndex];
        if ( < max(currentSelectionStartIndex, currentSelectionEndIndex) && existingIndex > min(currentSelectionStartIndex, currentSelectionEndIndex)) {
            ensureChildUpdated(mergingSelectable);
        }
        mergingSelectable->addListener(_handleSelectableGeometryChange);
        selectables->add(mergingSelectable);
        mergingIndex = 1;
    }
    assert(mergingIndex == mergingSelectables->length() && existingIndex == existingSelectables->length() && selectables->length() == existingIndex + mergingIndex);
    assert(selectionStartIndex >= -1 ||  < selectables->length());
    assert(selectionEndIndex >= -1 ||  < selectables->length());
    assert((currentSelectionStartIndex == -1) == (selectionStartIndex == -1));
    assert((currentSelectionEndIndex == -1) == (selectionEndIndex == -1));
    currentSelectionEndIndex = selectionEndIndex;
    currentSelectionStartIndex = selectionStartIndex;
    _additions = makeSet();
}

void MultiSelectableSelectionContainerDelegateCls::_removeSelectable(Selectable selectable) {
    assert(selectables->contains(selectable), __s("The selectable is not in this registrar."));
    int index = selectables->indexOf(selectable);
    selectables->removeAt(index);
    if (index <= currentSelectionEndIndex) {
        currentSelectionEndIndex = 1;
    }
    if (index <= currentSelectionStartIndex) {
        currentSelectionStartIndex = 1;
    }
    selectable->removeListener(_handleSelectableGeometryChange);
}

void MultiSelectableSelectionContainerDelegateCls::_updateSelectionGeometry() {
    SelectionGeometry newValue = getSelectionGeometry();
    if (_selectionGeometry != newValue) {
        _selectionGeometry = newValue;
        notifyListeners();
    }
    _updateHandleLayersAndOwners();
}

int MultiSelectableSelectionContainerDelegateCls::_compareScreenOrder(Selectable a, Selectable b) {
    Rect rectA = MatrixUtilsCls->transformRect(a->getTransformTo(nullptr), RectCls->fromLTWH(0, 0, a->size()->width(), a->size()->height()));
    Rect rectB = MatrixUtilsCls->transformRect(b->getTransformTo(nullptr), RectCls->fromLTWH(0, 0, b->size()->width(), b->size()->height()));
    int result = _compareVertically(rectA, rectB);
    if (result != 0) {
        return result;
    }
    return _compareHorizontally(rectA, rectB);
}

int MultiSelectableSelectionContainerDelegateCls::_compareVertically(Rect a, Rect b) {
    if ((a->top - b->top < precisionErrorTolerance && a->bottom - b->bottom > -precisionErrorTolerance) || (b->top - a->top < precisionErrorTolerance && b->bottom - a->bottom > -precisionErrorTolerance)) {
        return 0;
    }
    if ((a->top - b->top)->abs() > precisionErrorTolerance) {
        return a->top > b->top? 1 : -1;
    }
    return a->bottom > b->bottom? 1 : -1;
}

int MultiSelectableSelectionContainerDelegateCls::_compareHorizontally(Rect a, Rect b) {
    if (a->left - b->left < precisionErrorTolerance && a->right - b->right > -precisionErrorTolerance) {
        return -1;
    }
    if (b->left - a->left < precisionErrorTolerance && b->right - a->right > -precisionErrorTolerance) {
        return 1;
    }
    if ((a->left - b->left)->abs() > precisionErrorTolerance) {
        return a->left > b->left? 1 : -1;
    }
    return a->right > b->right? 1 : -1;
}

void MultiSelectableSelectionContainerDelegateCls::_handleSelectableGeometryChange() {
    if (_isHandlingSelectionEvent) {
        return;
    }
    _updateSelectionGeometry();
}

int MultiSelectableSelectionContainerDelegateCls::_adjustSelectionIndexBasedOnSelectionGeometry(int currentIndex, int towardIndex) {
    bool forward = towardIndex > currentIndex;
    while (currentIndex != towardIndex && selectables[currentIndex]->value->status != SelectionStatusCls::uncollapsed) {
        currentIndex = forward? 1 : -1;
    }
    return currentIndex;
}

void MultiSelectableSelectionContainerDelegateCls::_updateHandleLayersAndOwners() {
    LayerLink effectiveStartHandle = _startHandleLayer;
    LayerLink effectiveEndHandle = _endHandleLayer;
    if (effectiveStartHandle != nullptr || effectiveEndHandle != nullptr) {
        Rect drawableArea = RectCls->fromLTWH(0, 0, containerSize->width, containerSize->height)->inflate(_kSelectionHandleDrawableAreaPadding);
        bool hideStartHandle = value()->startSelectionPoint == nullptr || !drawableArea->contains(value()->startSelectionPoint!->localPosition);
        bool hideEndHandle = value()->endSelectionPoint == nullptr || !drawableArea->contains(value()->endSelectionPoint!->localPosition);
        effectiveStartHandle = hideStartHandle? nullptr : _startHandleLayer;
        effectiveEndHandle = hideEndHandle? nullptr : _endHandleLayer;
    }
    if (currentSelectionStartIndex == -1 || currentSelectionEndIndex == -1) {
        if (_startHandleLayerOwner != nullptr) {
            _startHandleLayerOwner!->pushHandleLayers(nullptr, nullptr);
            _startHandleLayerOwner = nullptr;
        }
        if (_endHandleLayerOwner != nullptr) {
            _endHandleLayerOwner!->pushHandleLayers(nullptr, nullptr);
            _endHandleLayerOwner = nullptr;
        }
        return;
    }
    if (selectables[currentSelectionStartIndex] != _startHandleLayerOwner) {
        _startHandleLayerOwner?->pushHandleLayers(nullptr, nullptr);
    }
    if (selectables[currentSelectionEndIndex] != _endHandleLayerOwner) {
        _endHandleLayerOwner?->pushHandleLayers(nullptr, nullptr);
    }
    _startHandleLayerOwner = selectables[currentSelectionStartIndex];
    if (currentSelectionStartIndex == currentSelectionEndIndex) {
        _endHandleLayerOwner = _startHandleLayerOwner;
        _startHandleLayerOwner!->pushHandleLayers(effectiveStartHandle, effectiveEndHandle);
        return;
    }
    _startHandleLayerOwner!->pushHandleLayers(effectiveStartHandle, nullptr);
    _endHandleLayerOwner = selectables[currentSelectionEndIndex];
    _endHandleLayerOwner!->pushHandleLayers(nullptr, effectiveEndHandle);
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::_initSelection(SelectionEdgeUpdateEvent event, bool isEnd) {
    assert((isEnd && currentSelectionEndIndex == -1) || (!isEnd && currentSelectionStartIndex == -1));
    int newIndex = -1;
    bool hasFoundEdgeIndex = false;
    SelectionResult result;
    for (;  < selectables->length() && !hasFoundEdgeIndex; index = 1) {
        Selectable child = selectables[index];
        SelectionResult childResult = dispatchSelectionEventToChild(child, event);
        ;
    }
    if (newIndex == -1) {
        assert(selectables->isEmpty);
        return SelectionResultCls::none;
    }
    if (isEnd) {
        currentSelectionEndIndex = newIndex;
    } else {
        currentSelectionStartIndex = newIndex;
    }
    return result or SelectionResultCls::next;
}

SelectionResult MultiSelectableSelectionContainerDelegateCls::_adjustSelection(SelectionEdgeUpdateEvent event, bool isEnd) {
    assert([=] () {
        if (isEnd) {
            assert( < selectables->length() && currentSelectionEndIndex >= 0);
            return true;
        }
        assert( < selectables->length() && currentSelectionStartIndex >= 0);
        return true;
    }());
    SelectionResult finalResult;
    int newIndex = isEnd? currentSelectionEndIndex : currentSelectionStartIndex;
    bool forward;
    SelectionResult currentSelectableResult;
    while ( < selectables->length() && newIndex >= 0 && finalResult == nullptr) {
        currentSelectableResult = dispatchSelectionEventToChild(selectables[newIndex], event);
        ;
    }
    if (isEnd) {
        currentSelectionEndIndex = newIndex;
    } else {
        currentSelectionStartIndex = newIndex;
    }
    return finalResult!;
}
