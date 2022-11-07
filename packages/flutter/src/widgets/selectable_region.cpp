#include "selectable_region.hpp"
State<StatefulWidget> SelectableRegion::createState() {
    return _SelectableRegionState();
}

void _SelectableRegionState::initState() {
    super.initState();
    widget.focusNode.addListener(_handleFocusChanged);
    _initMouseGestureRecognizer();
    _initTouchGestureRecognizer();
    _gestureRecognizers[TapGestureRecognizer] = <TapGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
}

void _SelectableRegionState::didChangeDependencies() {
    super.didChangeDependencies();
    ;
    Orientation orientation = MediaQuery.of(context).orientation;
    if (_lastOrientation == nullptr) {
        _lastOrientation = orientation;
        return;
    }
    if (orientation != _lastOrientation) {
        _lastOrientation = orientation;
        hideToolbar(defaultTargetPlatform == TargetPlatform.android);
    }
}

void _SelectableRegionState::didUpdateWidget(SelectableRegion oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.focusNode != oldWidget.focusNode) {
        oldWidget.focusNode.removeListener(_handleFocusChanged);
        widget.focusNode.addListener(_handleFocusChanged);
        if (widget.focusNode.hasFocus != oldWidget.focusNode.hasFocus) {
            _handleFocusChanged();
        }
    }
}

bool _SelectableRegionState::cutEnabled() {
    return false;
}

bool _SelectableRegionState::pasteEnabled() {
    return false;
}

void _SelectableRegionState::hideToolbar(bool hideHandles) {
    _selectionOverlay?.hideToolbar();
    if (hideHandles) {
        _selectionOverlay?.hideHandles();
    }
}

void _SelectableRegionState::selectAll(SelectionChangedCause cause) {
    _clearSelection();
    _selectable?.dispatchSelectionEvent(const SelectAllSelectionEvent());
    if (cause == SelectionChangedCause.toolbar) {
        _showToolbar();
        _showHandles();
    }
}

void _SelectableRegionState::copySelection(SelectionChangedCause cause) {
    _copy();
    _clearSelection();
}

void _SelectableRegionState::bringIntoView(TextPosition position) {
}

void _SelectableRegionState::cutSelection(SelectionChangedCause cause) {
    assert(false);
}

void _SelectableRegionState::userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value) {
}

Future<void> _SelectableRegionState::pasteText(SelectionChangedCause cause) {
    assert(false);
}

void _SelectableRegionState::add(Selectable selectable) {
    assert(_selectable == nullptr);
    _selectable = selectable;
    _selectable!.addListener(_updateSelectionStatus);
    _selectable!.pushHandleLayers(_startHandleLayerLink, _endHandleLayerLink);
}

void _SelectableRegionState::remove(Selectable selectable) {
    assert(_selectable == selectable);
    _selectable!.removeListener(_updateSelectionStatus);
    _selectable!.pushHandleLayers(nullptr, nullptr);
    _selectable = nullptr;
}

void _SelectableRegionState::dispose() {
    _selectable?.removeListener(_updateSelectionStatus);
    _selectable?.pushHandleLayers(nullptr, nullptr);
    _selectionDelegate.dispose();
    _selectionOverlay?.dispose();
    _selectionOverlay = nullptr;
    super.dispose();
}

Widget _SelectableRegionState::build(BuildContext context) {
    assert(Overlay.of(contextwidget) != nullptr);
    return CompositedTransformTarget(_toolbarLayerLink, RawGestureDetector(_gestureRecognizers, HitTestBehavior.translucent, true, Actions(_actions, Focus(false, widget.focusNode, SelectionContainer(this, _selectionDelegate, widget.child)))));
}

bool _SelectableRegionState::_hasSelectionOverlayGeometry() {
    return _selectionDelegate.value.startSelectionPoint != nullptr || _selectionDelegate.value.endSelectionPoint != nullptr;
}

Action<T> _SelectableRegionState::_makeOverridable<T extends Intent>(Action<T> defaultAction) {
    return <T>overridable(context, defaultAction);
}

void _SelectableRegionState::_handleFocusChanged() {
    if (!widget.focusNode.hasFocus) {
        _clearSelection();
    }
}

void _SelectableRegionState::_updateSelectionStatus() {
    TextSelection selection;
    SelectionGeometry geometry = _selectionDelegate.value;
    ;
    textEditingValue = TextEditingValue("__", selection);
    if (_hasSelectionOverlayGeometry) {
        _updateSelectionOverlay();
    } else {
        _selectionOverlay?.dispose();
        _selectionOverlay = nullptr;
    }
}

void _SelectableRegionState::_initMouseGestureRecognizer() {
    _gestureRecognizers[PanGestureRecognizer] = <PanGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
}

void _SelectableRegionState::_initTouchGestureRecognizer() {
    _gestureRecognizers[LongPressGestureRecognizer] = <LongPressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
}

void _SelectableRegionState::_startNewMouseSelectionGesture(DragDownDetails details) {
    widget.focusNode.requestFocus();
    hideToolbar();
    _clearSelection();
}

void _SelectableRegionState::_handleMouseDragStart(DragStartDetails details) {
    _selectStartTo(details.globalPosition);
}

void _SelectableRegionState::_handleMouseDragUpdate(DragUpdateDetails details) {
    _selectEndTo(details.globalPosition, true);
}

void _SelectableRegionState::_handleMouseDragEnd(DragEndDetails details) {
    _finalizeSelection();
}

void _SelectableRegionState::_handleTouchLongPressStart(LongPressStartDetails details) {
    widget.focusNode.requestFocus();
    _selectWordAt(details.globalPosition);
    _showToolbar();
    _showHandles();
}

void _SelectableRegionState::_handleTouchLongPressMoveUpdate(LongPressMoveUpdateDetails details) {
    _selectEndTo(details.globalPosition);
}

void _SelectableRegionState::_handleTouchLongPressEnd(LongPressEndDetails details) {
    _finalizeSelection();
}

void _SelectableRegionState::_handleRightClickDown(TapDownDetails details) {
    widget.focusNode.requestFocus();
    _selectWordAt(details.globalPosition);
    _showHandles();
    _showToolbar(details.globalPosition);
}

bool _SelectableRegionState::_userDraggingSelectionEnd() {
    return _selectionEndPosition != nullptr;
}

void _SelectableRegionState::_triggerSelectionEndEdgeUpdate() {
    if (_scheduledSelectionEndEdgeUpdate || !_userDraggingSelectionEnd) {
        return;
    }
    if (_selectable?.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forEnd(_selectionEndPosition!)) == SelectionResult.pending) {
        _scheduledSelectionEndEdgeUpdate = true;
        SchedulerBinding.instance.addPostFrameCallback();
        return;
    }
}

void _SelectableRegionState::_stopSelectionEndEdgeUpdate() {
    _scheduledSelectionEndEdgeUpdate = false;
    _selectionEndPosition = nullptr;
}

bool _SelectableRegionState::_userDraggingSelectionStart() {
    return _selectionStartPosition != nullptr;
}

void _SelectableRegionState::_triggerSelectionStartEdgeUpdate() {
    if (_scheduledSelectionStartEdgeUpdate || !_userDraggingSelectionStart) {
        return;
    }
    if (_selectable?.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forStart(_selectionStartPosition!)) == SelectionResult.pending) {
        _scheduledSelectionStartEdgeUpdate = true;
        SchedulerBinding.instance.addPostFrameCallback();
        return;
    }
}

void _SelectableRegionState::_stopSelectionStartEdgeUpdate() {
    _scheduledSelectionStartEdgeUpdate = false;
    _selectionEndPosition = nullptr;
}

void _SelectableRegionState::_handleSelectionStartHandleDragStart(DragStartDetails details) {
    assert(_selectionDelegate.value.startSelectionPoint != nullptr);
    Offset localPosition = _selectionDelegate.value.startSelectionPoint!.localPosition;
    Matrix4 globalTransform = _selectable!.getTransformTo(nullptr);
    _selectionStartHandleDragPosition = MatrixUtils.transformPoint(globalTransform, localPosition);
}

void _SelectableRegionState::_handleSelectionStartHandleDragUpdate(DragUpdateDetails details) {
    _selectionStartHandleDragPosition = _selectionStartHandleDragPosition + details.delta;
    _selectionStartPosition = _selectionStartHandleDragPosition - Offset(0, _selectionDelegate.value.startSelectionPoint!.lineHeight / 2);
    _triggerSelectionStartEdgeUpdate();
}

void _SelectableRegionState::_handleSelectionEndHandleDragStart(DragStartDetails details) {
    assert(_selectionDelegate.value.endSelectionPoint != nullptr);
    Offset localPosition = _selectionDelegate.value.endSelectionPoint!.localPosition;
    Matrix4 globalTransform = _selectable!.getTransformTo(nullptr);
    _selectionEndHandleDragPosition = MatrixUtils.transformPoint(globalTransform, localPosition);
}

void _SelectableRegionState::_handleSelectionEndHandleDragUpdate(DragUpdateDetails details) {
    _selectionEndHandleDragPosition = _selectionEndHandleDragPosition + details.delta;
    _selectionEndPosition = _selectionEndHandleDragPosition - Offset(0, _selectionDelegate.value.endSelectionPoint!.lineHeight / 2);
    _triggerSelectionEndEdgeUpdate();
}

void _SelectableRegionState::_createSelectionOverlay() {
    assert(_hasSelectionOverlayGeometry);
    if (_selectionOverlay != nullptr) {
        return;
    }
    SelectionPoint start = _selectionDelegate.value.startSelectionPoint;
    SelectionPoint end = _selectionDelegate.value.endSelectionPoint;
    List<TextSelectionPoint> points;
    Offset startLocalPosition = start?.localPosition ?? end!.localPosition;
    Offset endLocalPosition = end?.localPosition ?? start!.localPosition;
    if (startLocalPosition.dy > endLocalPosition.dy) {
        points = ;
    } else {
        points = ;
    }
    _selectionOverlay = SelectionOverlay(context, widget, start?.handleType ?? TextSelectionHandleType.left, start?.lineHeight ?? end!.lineHeight, _handleSelectionStartHandleDragStart, _handleSelectionStartHandleDragUpdate, , end?.handleType ?? TextSelectionHandleType.right, end?.lineHeight ?? start!.lineHeight, _handleSelectionEndHandleDragStart, _handleSelectionEndHandleDragUpdate, , points, widget.selectionControls, this, nullptr, _startHandleLayerLink, _endHandleLayerLink, _toolbarLayerLink);
}

void _SelectableRegionState::_updateSelectionOverlay() {
    if (_selectionOverlay == nullptr) {
        return;
    }
    assert(_hasSelectionOverlayGeometry);
    SelectionPoint start = _selectionDelegate.value.startSelectionPoint;
    SelectionPoint end = _selectionDelegate.value.endSelectionPoint;
    List<TextSelectionPoint> points;
    Offset startLocalPosition = start?.localPosition ?? end!.localPosition;
    Offset endLocalPosition = end?.localPosition ?? start!.localPosition;
    if (startLocalPosition.dy > endLocalPosition.dy) {
        points = ;
    } else {
        points = ;
    }
    ;
}

bool _SelectableRegionState::_showHandles() {
    if (_selectionOverlay != nullptr) {
        _selectionOverlay!.showHandles();
        return true;
    }
    if (!_hasSelectionOverlayGeometry) {
        return false;
    }
    _createSelectionOverlay();
    _selectionOverlay!.showHandles();
    return true;
}

bool _SelectableRegionState::_showToolbar(Offset location) {
    if (!_hasSelectionOverlayGeometry && _selectionOverlay == nullptr) {
        return false;
    }
    if (kIsWeb) {
        return false;
    }
    if (_selectionOverlay == nullptr) {
        _createSelectionOverlay();
    }
    _selectionOverlay!.toolbarLocation = location;
    _selectionOverlay!.showToolbar();
    return true;
}

void _SelectableRegionState::_selectEndTo(bool continuous, Offset offset) {
    if (!continuous) {
        _selectable?.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forEnd(offset));
        return;
    }
    if (_selectionEndPosition != offset) {
        _selectionEndPosition = offset;
        _triggerSelectionEndEdgeUpdate();
    }
}

void _SelectableRegionState::_selectStartTo(bool continuous, Offset offset) {
    if (!continuous) {
        _selectable?.dispatchSelectionEvent(SelectionEdgeUpdateEvent.forStart(offset));
        return;
    }
    if (_selectionStartPosition != offset) {
        _selectionStartPosition = offset;
        _triggerSelectionStartEdgeUpdate();
    }
}

void _SelectableRegionState::_selectWordAt(Offset offset) {
    _finalizeSelection();
    _selectable?.dispatchSelectionEvent(SelectWordSelectionEvent(offset));
}

void _SelectableRegionState::_finalizeSelection() {
    _stopSelectionEndEdgeUpdate();
    _stopSelectionStartEdgeUpdate();
}

void _SelectableRegionState::_clearSelection() {
    _finalizeSelection();
    _selectable?.dispatchSelectionEvent(const ClearSelectionEvent());
}

Future<void> _SelectableRegionState::_copy() {
    SelectedContent data = _selectable?.getSelectedContent();
    if (data == nullptr) {
        return;
    }
    await await Clipboard.setData(ClipboardData(data.plainText));
}

Object _NonOverrideAction::invoke(BuildContext context, T intent) {
    if (callingAction != nullptr) {
        return callingAction!.invoke(intent);
    }
    return invokeAction(intent, context);
}

void _SelectAllAction::invokeAction(BuildContext context, SelectAllTextIntent intent) {
    state.selectAll(SelectionChangedCause.keyboard);
}

void _CopySelectionAction::invokeAction(BuildContext context, CopySelectionTextIntent intent) {
    state._copy();
}

void _SelectableRegionContainerDelegate::remove(Selectable selectable) {
    _hasReceivedStartEvent.remove(selectable);
    _hasReceivedEndEvent.remove(selectable);
    super.remove(selectable);
}

SelectionResult _SelectableRegionContainerDelegate::handleSelectAll(SelectAllSelectionEvent event) {
    SelectionResult result = super.handleSelectAll(event);
    for (Selectable selectable : selectables) {
        _hasReceivedStartEvent.add(selectable);
        _hasReceivedEndEvent.add(selectable);
    }
    _updateLastEdgeEventsFromGeometries();
    return result;
}

SelectionResult _SelectableRegionContainerDelegate::handleSelectWord(SelectWordSelectionEvent event) {
    SelectionResult result = super.handleSelectWord(event);
    if (currentSelectionStartIndex != -1) {
        _hasReceivedStartEvent.add(selectables[currentSelectionStartIndex]);
    }
    if (currentSelectionEndIndex != -1) {
        _hasReceivedEndEvent.add(selectables[currentSelectionEndIndex]);
    }
    _updateLastEdgeEventsFromGeometries();
    return result;
}

SelectionResult _SelectableRegionContainerDelegate::handleClearSelection(ClearSelectionEvent event) {
    SelectionResult result = super.handleClearSelection(event);
    _hasReceivedStartEvent.clear();
    _hasReceivedEndEvent.clear();
    _lastStartEdgeUpdateGlobalPosition = nullptr;
    _lastEndEdgeUpdateGlobalPosition = nullptr;
    return result;
}

SelectionResult _SelectableRegionContainerDelegate::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (event.type == SelectionEventType.endEdgeUpdate) {
        _lastEndEdgeUpdateGlobalPosition = event.globalPosition;
    } else {
        _lastStartEdgeUpdateGlobalPosition = event.globalPosition;
    }
    return super.handleSelectionEdgeUpdate(event);
}

void _SelectableRegionContainerDelegate::dispose() {
    _hasReceivedStartEvent.clear();
    _hasReceivedEndEvent.clear();
    super.dispose();
}

SelectionResult _SelectableRegionContainerDelegate::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    ;
    return super.dispatchSelectionEventToChild(selectable, event);
}

void _SelectableRegionContainerDelegate::ensureChildUpdated(Selectable selectable) {
    if (_lastEndEdgeUpdateGlobalPosition != nullptr && _hasReceivedEndEvent.add(selectable)) {
        SelectionEdgeUpdateEvent synthesizedEvent = SelectionEdgeUpdateEvent.forEnd(_lastEndEdgeUpdateGlobalPosition!);
        if (currentSelectionEndIndex == -1) {
            handleSelectionEdgeUpdate(synthesizedEvent);
        }
        selectable.dispatchSelectionEvent(synthesizedEvent);
    }
    if (_lastStartEdgeUpdateGlobalPosition != nullptr && _hasReceivedStartEvent.add(selectable)) {
        SelectionEdgeUpdateEvent synthesizedEvent = SelectionEdgeUpdateEvent.forStart(_lastStartEdgeUpdateGlobalPosition!);
        if (currentSelectionStartIndex == -1) {
            handleSelectionEdgeUpdate(synthesizedEvent);
        }
        selectable.dispatchSelectionEvent(synthesizedEvent);
    }
}

void _SelectableRegionContainerDelegate::didChangeSelectables() {
    if (_lastEndEdgeUpdateGlobalPosition != nullptr) {
        handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent.forEnd(_lastEndEdgeUpdateGlobalPosition!));
    }
    if (_lastStartEdgeUpdateGlobalPosition != nullptr) {
        handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent.forStart(_lastStartEdgeUpdateGlobalPosition!));
    }
    Set<Selectable> selectableSet = selectables.toSet();
    _hasReceivedEndEvent.removeWhere();
    _hasReceivedStartEvent.removeWhere();
    super.didChangeSelectables();
}

void _SelectableRegionContainerDelegate::_updateLastEdgeEventsFromGeometries() {
    if (currentSelectionStartIndex != -1) {
        Selectable start = selectables[currentSelectionStartIndex];
        Offset localStartEdge = start.value.startSelectionPoint!.localPosition + Offset(0, -start.value.startSelectionPoint!.lineHeight / 2);
        _lastStartEdgeUpdateGlobalPosition = MatrixUtils.transformPoint(start.getTransformTo(nullptr), localStartEdge);
    }
    if (currentSelectionEndIndex != -1) {
        Selectable end = selectables[currentSelectionEndIndex];
        Offset localEndEdge = end.value.endSelectionPoint!.localPosition + Offset(0, -end.value.endSelectionPoint!.lineHeight / 2);
        _lastEndEdgeUpdateGlobalPosition = MatrixUtils.transformPoint(end.getTransformTo(nullptr), localEndEdge);
    }
}

void MultiSelectableSelectionContainerDelegate::add(Selectable selectable) {
    assert(!selectables.contains(selectable));
    _additions.add(selectable);
    _scheduleSelectableUpdate();
}

void MultiSelectableSelectionContainerDelegate::remove(Selectable selectable) {
    if (_additions.remove(selectable)) {
        return;
    }
    _removeSelectable(selectable);
    _scheduleSelectableUpdate();
}

void MultiSelectableSelectionContainerDelegate::layoutDidChange() {
    _updateSelectionGeometry();
}

void MultiSelectableSelectionContainerDelegate::didChangeSelectables() {
    _updateSelectionGeometry();
}

SelectionGeometry MultiSelectableSelectionContainerDelegate::value() {
    return _selectionGeometry;
}

Comparator<Selectable> MultiSelectableSelectionContainerDelegate::compareOrder() {
    return _compareScreenOrder;
}

SelectionGeometry MultiSelectableSelectionContainerDelegate::getSelectionGeometry() {
    if (currentSelectionEndIndex == -1 || currentSelectionStartIndex == -1 || selectables.isEmpty) {
        return SelectionGeometry(SelectionStatus.none, selectables.isNotEmpty);
    }
    currentSelectionStartIndex = _adjustSelectionIndexBasedOnSelectionGeometry(currentSelectionStartIndex, currentSelectionEndIndex);
    currentSelectionEndIndex = _adjustSelectionIndexBasedOnSelectionGeometry(currentSelectionEndIndex, currentSelectionStartIndex);
    SelectionGeometry startGeometry = selectables[currentSelectionStartIndex].value;
    bool forwardSelection = currentSelectionEndIndex >= currentSelectionStartIndex;
    int startIndexWalker = currentSelectionStartIndex;
    while (startIndexWalker != currentSelectionEndIndex && startGeometry.startSelectionPoint == nullptr) {
        startIndexWalker = forwardSelection? 1 : -1;
        startGeometry = selectables[startIndexWalker].value;
    }
    SelectionPoint startPoint;
    if (startGeometry.startSelectionPoint != nullptr) {
        Matrix4 startTransform = getTransformFrom(selectables[startIndexWalker]);
        Offset start = MatrixUtils.transformPoint(startTransform, startGeometry.startSelectionPoint!.localPosition);
        if (start.isFinite) {
            startPoint = SelectionPoint(start, startGeometry.startSelectionPoint!.lineHeight, startGeometry.startSelectionPoint!.handleType);
        }
    }
    SelectionGeometry endGeometry = selectables[currentSelectionEndIndex].value;
    int endIndexWalker = currentSelectionEndIndex;
    while (endIndexWalker != currentSelectionStartIndex && endGeometry.endSelectionPoint == nullptr) {
        endIndexWalker = forwardSelection? -1 : 1;
        endGeometry = selectables[endIndexWalker].value;
    }
    SelectionPoint endPoint;
    if (endGeometry.endSelectionPoint != nullptr) {
        Matrix4 endTransform = getTransformFrom(selectables[endIndexWalker]);
        Offset end = MatrixUtils.transformPoint(endTransform, endGeometry.endSelectionPoint!.localPosition);
        if (end.isFinite) {
            endPoint = SelectionPoint(end, endGeometry.endSelectionPoint!.lineHeight, endGeometry.endSelectionPoint!.handleType);
        }
    }
    return SelectionGeometry(startPoint, endPoint, startGeometry != endGeometry? SelectionStatus.uncollapsed : startGeometry.status, true);
}

void MultiSelectableSelectionContainerDelegate::pushHandleLayers(LayerLink endHandle, LayerLink startHandle) {
    if (_startHandleLayer == startHandle && _endHandleLayer == endHandle) {
        return;
    }
    _startHandleLayer = startHandle;
    _endHandleLayer = endHandle;
    _updateHandleLayersAndOwners();
}

SelectedContent MultiSelectableSelectionContainerDelegate::getSelectedContent() {
    List<SelectedContent> selections = ;
    for (Selectable selectable : selectables) {
        SelectedContent data = selectable.getSelectedContent();
        if (data != nullptr) {
            selections.add(data);
        }
    }
    if (selections.isEmpty) {
        return nullptr;
    }
    StringBuffer buffer = StringBuffer();
    for (SelectedContent selection : selections) {
        buffer.write(selection.plainText);
    }
    return SelectedContent(buffer.toString());
}

SelectionResult MultiSelectableSelectionContainerDelegate::handleSelectAll(SelectAllSelectionEvent event) {
    for (Selectable selectable : selectables) {
        dispatchSelectionEventToChild(selectable, event);
    }
    currentSelectionStartIndex = 0;
    currentSelectionEndIndex = selectables.length - 1;
    return SelectionResult.none;
}

SelectionResult MultiSelectableSelectionContainerDelegate::handleSelectWord(SelectWordSelectionEvent event) {
    for (;  < selectables.length; index = 1) {
        Rect localRect = Rect.fromLTWH(0, 0, selectables[index].size.width, selectables[index].size.height);
        Matrix4 transform = selectables[index].getTransformTo(nullptr);
        Rect globalRect = MatrixUtils.transformRect(transform, localRect);
        if (globalRect.contains(event.globalPosition)) {
            SelectionGeometry existingGeometry = selectables[index].value;
            dispatchSelectionEventToChild(selectables[index], event);
            if (selectables[index].value != existingGeometry) {
                selectables.where().forEach();
                currentSelectionStartIndex = currentSelectionEndIndex = index;
            }
            return SelectionResult.end;
        }
    }
    return SelectionResult.none;
}

SelectionResult MultiSelectableSelectionContainerDelegate::handleClearSelection(ClearSelectionEvent event) {
    for (Selectable selectable : selectables) {
        dispatchSelectionEventToChild(selectable, event);
    }
    currentSelectionEndIndex = -1;
    currentSelectionStartIndex = -1;
    return SelectionResult.none;
}

SelectionResult MultiSelectableSelectionContainerDelegate::handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event) {
    if (event.type == SelectionEventType.endEdgeUpdate) {
        return currentSelectionEndIndex == -1? _initSelection(eventtrue) : _adjustSelection(eventtrue);
    }
    return currentSelectionStartIndex == -1? _initSelection(eventfalse) : _adjustSelection(eventfalse);
}

SelectionResult MultiSelectableSelectionContainerDelegate::dispatchSelectionEvent(SelectionEvent event) {
    bool selectionWillbeInProgress = event is! ClearSelectionEvent;
    if (!_selectionInProgress && selectionWillbeInProgress) {
        selectables.sort(compareOrder);
    }
    _selectionInProgress = selectionWillbeInProgress;
    _isHandlingSelectionEvent = true;
    SelectionResult result;
    ;
    _isHandlingSelectionEvent = false;
    _updateSelectionGeometry();
    return result;
}

void MultiSelectableSelectionContainerDelegate::dispose() {
    for (Selectable selectable : selectables) {
        selectable.removeListener(_handleSelectableGeometryChange);
    }
    selectables = const ;
    _scheduledSelectableUpdate = false;
    super.dispose();
}

SelectionResult MultiSelectableSelectionContainerDelegate::dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable) {
    return selectable.dispatchSelectionEvent(event);
}

void MultiSelectableSelectionContainerDelegate::_scheduleSelectableUpdate() {
    if (!_scheduledSelectableUpdate) {
        _scheduledSelectableUpdate = true;
        SchedulerBinding.instance.addPostFrameCallback();
    }
}

void MultiSelectableSelectionContainerDelegate::_updateSelectables() {
    if (_additions.isNotEmpty) {
        _flushAdditions();
    }
    didChangeSelectables();
}

void MultiSelectableSelectionContainerDelegate::_flushAdditions() {
    List<Selectable> mergingSelectables = ;
    List<Selectable> existingSelectables = selectables;
    selectables = ;
    int mergingIndex = 0;
    int existingIndex = 0;
    int selectionStartIndex = currentSelectionStartIndex;
    int selectionEndIndex = currentSelectionEndIndex;
    while ( < mergingSelectables.length ||  < existingSelectables.length) {
        if (mergingIndex >= mergingSelectables.length || ( < existingSelectables.length && compareOrder(existingSelectables[existingIndex], mergingSelectables[mergingIndex]) < 0)) {
            if (existingIndex == currentSelectionStartIndex) {
                selectionStartIndex = selectables.length;
            }
            if (existingIndex == currentSelectionEndIndex) {
                selectionEndIndex = selectables.length;
            }
            selectables.add(existingSelectables[existingIndex]);
            existingIndex = 1;
            continue;
        }
        Selectable mergingSelectable = mergingSelectables[mergingIndex];
        if ( < max(currentSelectionStartIndex, currentSelectionEndIndex) && existingIndex > min(currentSelectionStartIndex, currentSelectionEndIndex)) {
            ensureChildUpdated(mergingSelectable);
        }
        mergingSelectable.addListener(_handleSelectableGeometryChange);
        selectables.add(mergingSelectable);
        mergingIndex = 1;
    }
    assert(mergingIndex == mergingSelectables.length && existingIndex == existingSelectables.length && selectables.length == existingIndex + mergingIndex);
    assert(selectionStartIndex >= -1 ||  < selectables.length);
    assert(selectionEndIndex >= -1 ||  < selectables.length);
    assert((currentSelectionStartIndex == -1) == (selectionStartIndex == -1));
    assert((currentSelectionEndIndex == -1) == (selectionEndIndex == -1));
    currentSelectionEndIndex = selectionEndIndex;
    currentSelectionStartIndex = selectionStartIndex;
    _additions = ;
}

void MultiSelectableSelectionContainerDelegate::_removeSelectable(Selectable selectable) {
    assert(selectables.contains(selectable), "The selectable is not in this registrar.");
    int index = selectables.indexOf(selectable);
    selectables.removeAt(index);
    if (index <= currentSelectionEndIndex) {
        currentSelectionEndIndex = 1;
    }
    if (index <= currentSelectionStartIndex) {
        currentSelectionStartIndex = 1;
    }
    selectable.removeListener(_handleSelectableGeometryChange);
}

void MultiSelectableSelectionContainerDelegate::_updateSelectionGeometry() {
    SelectionGeometry newValue = getSelectionGeometry();
    if (_selectionGeometry != newValue) {
        _selectionGeometry = newValue;
        notifyListeners();
    }
    _updateHandleLayersAndOwners();
}

int MultiSelectableSelectionContainerDelegate::_compareScreenOrder(Selectable a, Selectable b) {
    Rect rectA = MatrixUtils.transformRect(a.getTransformTo(nullptr), Rect.fromLTWH(0, 0, a.size.width, a.size.height));
    Rect rectB = MatrixUtils.transformRect(b.getTransformTo(nullptr), Rect.fromLTWH(0, 0, b.size.width, b.size.height));
    int result = _compareVertically(rectA, rectB);
    if (result != 0) {
        return result;
    }
    return _compareHorizontally(rectA, rectB);
}

int MultiSelectableSelectionContainerDelegate::_compareVertically(Rect a, Rect b) {
    if ((a.top - b.top < precisionErrorTolerance && a.bottom - b.bottom > -precisionErrorTolerance) || (b.top - a.top < precisionErrorTolerance && b.bottom - a.bottom > -precisionErrorTolerance)) {
        return 0;
    }
    if ((a.top - b.top).abs() > precisionErrorTolerance) {
        return a.top > b.top? 1 : -1;
    }
    return a.bottom > b.bottom? 1 : -1;
}

int MultiSelectableSelectionContainerDelegate::_compareHorizontally(Rect a, Rect b) {
    if (a.left - b.left < precisionErrorTolerance && a.right - b.right > -precisionErrorTolerance) {
        return -1;
    }
    if (b.left - a.left < precisionErrorTolerance && b.right - a.right > -precisionErrorTolerance) {
        return 1;
    }
    if ((a.left - b.left).abs() > precisionErrorTolerance) {
        return a.left > b.left? 1 : -1;
    }
    return a.right > b.right? 1 : -1;
}

void MultiSelectableSelectionContainerDelegate::_handleSelectableGeometryChange() {
    if (_isHandlingSelectionEvent) {
        return;
    }
    _updateSelectionGeometry();
}

int MultiSelectableSelectionContainerDelegate::_adjustSelectionIndexBasedOnSelectionGeometry(int currentIndex, int towardIndex) {
    bool forward = towardIndex > currentIndex;
    while (currentIndex != towardIndex && selectables[currentIndex].value.status != SelectionStatus.uncollapsed) {
        currentIndex = forward? 1 : -1;
    }
    return currentIndex;
}

void MultiSelectableSelectionContainerDelegate::_updateHandleLayersAndOwners() {
    LayerLink effectiveStartHandle = _startHandleLayer;
    LayerLink effectiveEndHandle = _endHandleLayer;
    if (effectiveStartHandle != nullptr || effectiveEndHandle != nullptr) {
        Rect drawableArea = Rect.fromLTWH(0, 0, containerSize.width, containerSize.height).inflate(_kSelectionHandleDrawableAreaPadding);
        bool hideStartHandle = value.startSelectionPoint == nullptr || !drawableArea.contains(value.startSelectionPoint!.localPosition);
        bool hideEndHandle = value.endSelectionPoint == nullptr || !drawableArea.contains(value.endSelectionPoint!.localPosition);
        effectiveStartHandle = hideStartHandle? nullptr : _startHandleLayer;
        effectiveEndHandle = hideEndHandle? nullptr : _endHandleLayer;
    }
    if (currentSelectionStartIndex == -1 || currentSelectionEndIndex == -1) {
        if (_startHandleLayerOwner != nullptr) {
            _startHandleLayerOwner!.pushHandleLayers(nullptr, nullptr);
            _startHandleLayerOwner = nullptr;
        }
        if (_endHandleLayerOwner != nullptr) {
            _endHandleLayerOwner!.pushHandleLayers(nullptr, nullptr);
            _endHandleLayerOwner = nullptr;
        }
        return;
    }
    if (selectables[currentSelectionStartIndex] != _startHandleLayerOwner) {
        _startHandleLayerOwner?.pushHandleLayers(nullptr, nullptr);
    }
    if (selectables[currentSelectionEndIndex] != _endHandleLayerOwner) {
        _endHandleLayerOwner?.pushHandleLayers(nullptr, nullptr);
    }
    _startHandleLayerOwner = selectables[currentSelectionStartIndex];
    if (currentSelectionStartIndex == currentSelectionEndIndex) {
        _endHandleLayerOwner = _startHandleLayerOwner;
        _startHandleLayerOwner!.pushHandleLayers(effectiveStartHandle, effectiveEndHandle);
        return;
    }
    _startHandleLayerOwner!.pushHandleLayers(effectiveStartHandle, nullptr);
    _endHandleLayerOwner = selectables[currentSelectionEndIndex];
    _endHandleLayerOwner!.pushHandleLayers(nullptr, effectiveEndHandle);
}

SelectionResult MultiSelectableSelectionContainerDelegate::_initSelection(SelectionEdgeUpdateEvent event, bool isEnd) {
    assert((isEnd && currentSelectionEndIndex == -1) || (!isEnd && currentSelectionStartIndex == -1));
    int newIndex = -1;
    bool hasFoundEdgeIndex = false;
    SelectionResult result;
    for (;  < selectables.length && !hasFoundEdgeIndex; index = 1) {
        Selectable child = selectables[index];
        SelectionResult childResult = dispatchSelectionEventToChild(child, event);
        ;
    }
    if (newIndex == -1) {
        assert(selectables.isEmpty);
        return SelectionResult.none;
    }
    if (isEnd) {
        currentSelectionEndIndex = newIndex;
    } else {
        currentSelectionStartIndex = newIndex;
    }
    return result ?? SelectionResult.next;
}

SelectionResult MultiSelectableSelectionContainerDelegate::_adjustSelection(SelectionEdgeUpdateEvent event, bool isEnd) {
    assert(());
    SelectionResult finalResult;
    int newIndex = isEnd? currentSelectionEndIndex : currentSelectionStartIndex;
    bool forward;
    SelectionResult currentSelectableResult;
    while ( < selectables.length && newIndex >= 0 && finalResult == nullptr) {
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
