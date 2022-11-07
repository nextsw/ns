#include "text_selection.hpp"
String ToolbarItemsParentData::toString() {
    return "${super.toString()}; shouldPaint=$shouldPaint";
}

bool TextSelectionControls::canCut(TextSelectionDelegate delegate) {
    return delegate.cutEnabled && !delegate.textEditingValue.selection.isCollapsed;
}

bool TextSelectionControls::canCopy(TextSelectionDelegate delegate) {
    return delegate.copyEnabled && !delegate.textEditingValue.selection.isCollapsed;
}

bool TextSelectionControls::canPaste(TextSelectionDelegate delegate) {
    return delegate.pasteEnabled;
}

bool TextSelectionControls::canSelectAll(TextSelectionDelegate delegate) {
    return delegate.selectAllEnabled && delegate.textEditingValue.text.isNotEmpty && delegate.textEditingValue.selection.isCollapsed;
}

void TextSelectionControls::handleCut(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate) {
    delegate.cutSelection(SelectionChangedCause.toolbar);
}

void TextSelectionControls::handleCopy(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate) {
    delegate.copySelection(SelectionChangedCause.toolbar);
}

Future<void> TextSelectionControls::handlePaste(TextSelectionDelegate delegate) {
    delegate.pasteText(SelectionChangedCause.toolbar);
}

void TextSelectionControls::handleSelectAll(TextSelectionDelegate delegate) {
    delegate.selectAll(SelectionChangedCause.toolbar);
    delegate.bringIntoView(delegate.textEditingValue.selection.extent);
}

TextSelectionOverlay::TextSelectionOverlay(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, bool handlesVisible, VoidCallback onSelectionHandleTapped, RenderEditable renderObject, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, LayerLink startHandleLayerLink, LayerLink toolbarLayerLink, TextEditingValue value) {
    {
        assert(value != nullptr);
        assert(context != nullptr);
        assert(handlesVisible != nullptr);
        _handlesVisible = handlesVisible;
        _value = value;
    }
    {
        renderObject.selectionStartInViewport.addListener(_updateTextSelectionOverlayVisibilities);
        renderObject.selectionEndInViewport.addListener(_updateTextSelectionOverlayVisibilities);
        _updateTextSelectionOverlayVisibilities();
        _selectionOverlay = SelectionOverlay(context, debugRequiredFor, TextSelectionHandleType.collapsed, _effectiveStartHandleVisibility, 0.0, _handleSelectionStartHandleDragStart, _handleSelectionStartHandleDragUpdate, TextSelectionHandleType.collapsed, _effectiveEndHandleVisibility, 0.0, _handleSelectionEndHandleDragStart, _handleSelectionEndHandleDragUpdate, _effectiveToolbarVisibility, const , selectionControls, selectionDelegate, clipboardStatus, startHandleLayerLink, endHandleLayerLink, toolbarLayerLink, onSelectionHandleTapped, dragStartBehavior, renderObject.lastSecondaryTapDownPosition);
    }
}

TextEditingValue TextSelectionOverlay::value() {
    return _value;
}

bool TextSelectionOverlay::handlesVisible() {
    return _handlesVisible;
}

void TextSelectionOverlay::handlesVisible(bool visible) {
    assert(visible != nullptr);
    if (_handlesVisible == visible) {
        return;
    }
    _handlesVisible = visible;
    _updateTextSelectionOverlayVisibilities();
}

void TextSelectionOverlay::showHandles() {
    _updateSelectionOverlay();
    _selectionOverlay.showHandles();
}

void TextSelectionOverlay::hideHandles() {
    return _selectionOverlay.hideHandles();
}

void TextSelectionOverlay::showToolbar() {
    _updateSelectionOverlay();
    _selectionOverlay.showToolbar();
}

void TextSelectionOverlay::update(TextEditingValue newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    _updateSelectionOverlay();
}

void TextSelectionOverlay::updateForScroll() {
    return _updateSelectionOverlay();
}

bool TextSelectionOverlay::handlesAreVisible() {
    return _selectionOverlay._handles != nullptr && handlesVisible;
}

bool TextSelectionOverlay::toolbarIsVisible() {
    return _selectionOverlay._toolbar != nullptr;
}

void TextSelectionOverlay::hide() {
    return _selectionOverlay.hide();
}

void TextSelectionOverlay::hideToolbar() {
    return _selectionOverlay.hideToolbar();
}

void TextSelectionOverlay::dispose() {
    _selectionOverlay.dispose();
    renderObject.selectionStartInViewport.removeListener(_updateTextSelectionOverlayVisibilities);
    renderObject.selectionEndInViewport.removeListener(_updateTextSelectionOverlayVisibilities);
    _effectiveToolbarVisibility.dispose();
    _effectiveStartHandleVisibility.dispose();
    _effectiveEndHandleVisibility.dispose();
}

TextSelection TextSelectionOverlay::_selection() {
    return _value.selection;
}

void TextSelectionOverlay::_updateTextSelectionOverlayVisibilities() {
    _effectiveStartHandleVisibility.value = _handlesVisible && renderObject.selectionStartInViewport.value;
    _effectiveEndHandleVisibility.value = _handlesVisible && renderObject.selectionEndInViewport.value;
    _effectiveToolbarVisibility.value = renderObject.selectionStartInViewport.value || renderObject.selectionEndInViewport.value;
}

void TextSelectionOverlay::_updateSelectionOverlay() {
    ;
}

double TextSelectionOverlay::_getStartGlyphHeight() {
    InlineSpan span = renderObject.text!;
    String prevText = span.toPlainText();
    String currText = selectionDelegate.textEditingValue.text;
    int firstSelectedGraphemeExtent;
    Rect startHandleRect;
    if (prevText == currText && _selection != nullptr && _selection.isValid && !_selection.isCollapsed) {
        String selectedGraphemes = _selection.textInside(currText);
        firstSelectedGraphemeExtent = selectedGraphemes.characters.first.length;
        startHandleRect = renderObject.getRectForComposingRange(TextRange(_selection.start, _selection.start + firstSelectedGraphemeExtent));
    }
    return startHandleRect?.height ?? renderObject.preferredLineHeight;
}

double TextSelectionOverlay::_getEndGlyphHeight() {
    InlineSpan span = renderObject.text!;
    String prevText = span.toPlainText();
    String currText = selectionDelegate.textEditingValue.text;
    int lastSelectedGraphemeExtent;
    Rect endHandleRect;
    if (prevText == currText && _selection != nullptr && _selection.isValid && !_selection.isCollapsed) {
        String selectedGraphemes = _selection.textInside(currText);
        lastSelectedGraphemeExtent = selectedGraphemes.characters.last.length;
        endHandleRect = renderObject.getRectForComposingRange(TextRange(_selection.end - lastSelectedGraphemeExtent, _selection.end));
    }
    return endHandleRect?.height ?? renderObject.preferredLineHeight;
}

void TextSelectionOverlay::_handleSelectionEndHandleDragStart(DragStartDetails details) {
    Size handleSize = selectionControls!.getHandleSize(renderObject.preferredLineHeight);
    _dragEndPosition = details.globalPosition + Offset(0.0, -handleSize.height);
}

void TextSelectionOverlay::_handleSelectionEndHandleDragUpdate(DragUpdateDetails details) {
    _dragEndPosition = details.delta;
    TextPosition position = renderObject.getPositionForPoint(_dragEndPosition);
    if (_selection.isCollapsed) {
        _handleSelectionHandleChanged(TextSelection.fromPosition(position)true);
        return;
    }
    TextSelection newSelection;
    ;
    _handleSelectionHandleChanged(newSelectiontrue);
}

void TextSelectionOverlay::_handleSelectionStartHandleDragStart(DragStartDetails details) {
    Size handleSize = selectionControls!.getHandleSize(renderObject.preferredLineHeight);
    _dragStartPosition = details.globalPosition + Offset(0.0, -handleSize.height);
}

void TextSelectionOverlay::_handleSelectionStartHandleDragUpdate(DragUpdateDetails details) {
    _dragStartPosition = details.delta;
    TextPosition position = renderObject.getPositionForPoint(_dragStartPosition);
    if (_selection.isCollapsed) {
        _handleSelectionHandleChanged(TextSelection.fromPosition(position)false);
        return;
    }
    TextSelection newSelection;
    ;
    _handleSelectionHandleChanged(newSelectionfalse);
}

void TextSelectionOverlay::_handleSelectionHandleChanged(bool isEnd, TextSelection newSelection) {
    TextPosition textPosition = isEnd? newSelection.extent : newSelection.base;
    selectionDelegate.userUpdateTextEditingValue(_value.copyWith(newSelection), SelectionChangedCause.drag);
    selectionDelegate.bringIntoView(textPosition);
}

TextSelectionHandleType TextSelectionOverlay::_chooseType(TextSelectionHandleType ltrType, TextSelectionHandleType rtlType, TextDirection textDirection) {
    if (_selection.isCollapsed) {
        return TextSelectionHandleType.collapsed;
    }
    assert(textDirection != nullptr);
    ;
}

SelectionOverlay::SelectionOverlay(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, TextSelectionHandleType endHandleType, ValueListenable<bool> endHandlesVisible, double lineHeightAtEnd, double lineHeightAtStart, ValueChanged<DragEndDetails> onEndHandleDragEnd, ValueChanged<DragStartDetails> onEndHandleDragStart, ValueChanged<DragUpdateDetails> onEndHandleDragUpdate, VoidCallback onSelectionHandleTapped, ValueChanged<DragEndDetails> onStartHandleDragEnd, ValueChanged<DragStartDetails> onStartHandleDragStart, ValueChanged<DragUpdateDetails> onStartHandleDragUpdate, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, LayerLink startHandleLayerLink, TextSelectionHandleType startHandleType, ValueListenable<bool> startHandlesVisible, LayerLink toolbarLayerLink, Offset toolbarLocation, ValueListenable<bool> toolbarVisible) {
    {
        _startHandleType = startHandleType;
        _lineHeightAtStart = lineHeightAtStart;
        _endHandleType = endHandleType;
        _lineHeightAtEnd = lineHeightAtEnd;
        _selectionEndpoints = selectionEndpoints;
        _toolbarLocation = toolbarLocation;
    }
    {
        OverlayState overlay = Overlay.of(contexttrue);
        assert(overlay != nullptr, "No Overlay widget exists above $context.\nUsually the Navigator created by WidgetsApp provides the overlay. Perhaps your app content was created above the Navigator with the WidgetsApp builder parameter.");
    }
}

TextSelectionHandleType SelectionOverlay::startHandleType() {
    return _startHandleType;
}

void SelectionOverlay::startHandleType(TextSelectionHandleType value) {
    if (_startHandleType == value) {
        return;
    }
    _startHandleType = value;
    _markNeedsBuild();
}

double SelectionOverlay::lineHeightAtStart() {
    return _lineHeightAtStart;
}

void SelectionOverlay::lineHeightAtStart(double value) {
    if (_lineHeightAtStart == value) {
        return;
    }
    _lineHeightAtStart = value;
    _markNeedsBuild();
}

TextSelectionHandleType SelectionOverlay::endHandleType() {
    return _endHandleType;
}

void SelectionOverlay::endHandleType(TextSelectionHandleType value) {
    if (_endHandleType == value) {
        return;
    }
    _endHandleType = value;
    _markNeedsBuild();
}

double SelectionOverlay::lineHeightAtEnd() {
    return _lineHeightAtEnd;
}

void SelectionOverlay::lineHeightAtEnd(double value) {
    if (_lineHeightAtEnd == value) {
        return;
    }
    _lineHeightAtEnd = value;
    _markNeedsBuild();
}

List<TextSelectionPoint> SelectionOverlay::selectionEndpoints() {
    return _selectionEndpoints;
}

void SelectionOverlay::selectionEndpoints(List<TextSelectionPoint> value) {
    if (!listEquals(_selectionEndpoints, value)) {
        _markNeedsBuild();
    }
    _selectionEndpoints = value;
}

Offset SelectionOverlay::toolbarLocation() {
    return _toolbarLocation;
}

void SelectionOverlay::toolbarLocation(Offset value) {
    if (_toolbarLocation == value) {
        return;
    }
    _toolbarLocation = value;
    _markNeedsBuild();
}

void SelectionOverlay::showHandles() {
    if (_handles != nullptr) {
        return;
    }
    _handles = ;
    Overlay.of(contexttrue, debugRequiredFor)!.insertAll(_handles!);
}

void SelectionOverlay::hideHandles() {
    if (_handles != nullptr) {
        _handles![0].remove();
        _handles![1].remove();
        _handles = nullptr;
    }
}

void SelectionOverlay::showToolbar() {
    if (_toolbar != nullptr) {
        return;
    }
    _toolbar = OverlayEntry(_buildToolbar);
    Overlay.of(contexttrue, debugRequiredFor)!.insert(_toolbar!);
}

void SelectionOverlay::hide() {
    if (_handles != nullptr) {
        _handles![0].remove();
        _handles![1].remove();
        _handles = nullptr;
    }
    if (_toolbar != nullptr) {
        hideToolbar();
    }
}

void SelectionOverlay::hideToolbar() {
    if (_toolbar == nullptr) {
        return;
    }
    _toolbar?.remove();
    _toolbar = nullptr;
}

void SelectionOverlay::dispose() {
    hide();
}

void SelectionOverlay::_markNeedsBuild() {
    if (_handles == nullptr && _toolbar == nullptr) {
        return;
    }
    if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.persistentCallbacks) {
        if (_buildScheduled) {
            return;
        }
        _buildScheduled = true;
        SchedulerBinding.instance.addPostFrameCallback();
    } else {
        if (_handles != nullptr) {
            _handles![0].markNeedsBuild();
            _handles![1].markNeedsBuild();
        }
        _toolbar?.markNeedsBuild();
    }
}

Widget SelectionOverlay::_buildStartHandle(BuildContext context) {
    Widget handle;
    TextSelectionControls selectionControls = this.selectionControls;
    if (selectionControls == nullptr) {
        handle = Container();
    } else {
        handle = _SelectionHandleOverlay(_startHandleType, startHandleLayerLink, onSelectionHandleTapped, onStartHandleDragStart, onStartHandleDragUpdate, onStartHandleDragEnd, selectionControls, startHandlesVisible, _lineHeightAtStart, dragStartBehavior);
    }
    return ExcludeSemantics(handle);
}

Widget SelectionOverlay::_buildEndHandle(BuildContext context) {
    Widget handle;
    TextSelectionControls selectionControls = this.selectionControls;
    if (selectionControls == nullptr || _startHandleType == TextSelectionHandleType.collapsed) {
        handle = Container();
    } else {
        handle = _SelectionHandleOverlay(_endHandleType, endHandleLayerLink, onSelectionHandleTapped, onEndHandleDragStart, onEndHandleDragUpdate, onEndHandleDragEnd, selectionControls, endHandlesVisible, _lineHeightAtEnd, dragStartBehavior);
    }
    return ExcludeSemantics(handle);
}

Widget SelectionOverlay::_buildToolbar(BuildContext context) {
    if (selectionControls == nullptr) {
        return Container();
    }
    RenderBox renderBox = (;
    Rect editingRegion = Rect.fromPoints(renderBox.localToGlobal(Offset.zero), renderBox.localToGlobal(renderBox.size.bottomRight(Offset.zero)));
    bool isMultiline = selectionEndpoints.last.point.dy - selectionEndpoints.first.point.dy > lineHeightAtEnd / 2;
    double midX = isMultiline? editingRegion.width / 2 : (selectionEndpoints.first.point.dx + selectionEndpoints.last.point.dx) / 2;
    Offset midpoint = Offset(midX, selectionEndpoints.first.point.dy - lineHeightAtStart);
    return Directionality(Directionality.of(this.context), _SelectionToolbarOverlay(lineHeightAtStart, toolbarLocation, toolbarLayerLink, editingRegion, selectionControls, midpoint, selectionEndpoints, toolbarVisible, selectionDelegate, clipboardStatus));
}

_SelectionToolbarOverlayState _SelectionToolbarOverlay::createState() {
    return _SelectionToolbarOverlayState();
}

void _SelectionToolbarOverlayState::initState() {
    super.initState();
    _controller = AnimationController(SelectionOverlay.fadeDuration, this);
    _toolbarVisibilityChanged();
    widget.visibility?.addListener(_toolbarVisibilityChanged);
}

void _SelectionToolbarOverlayState::didUpdateWidget(_SelectionToolbarOverlay oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.visibility == widget.visibility) {
        return;
    }
    oldWidget.visibility?.removeListener(_toolbarVisibilityChanged);
    _toolbarVisibilityChanged();
    widget.visibility?.addListener(_toolbarVisibilityChanged);
}

void _SelectionToolbarOverlayState::dispose() {
    widget.visibility?.removeListener(_toolbarVisibilityChanged);
    _controller.dispose();
    super.dispose();
}

Widget _SelectionToolbarOverlayState::build(BuildContext context) {
    return FadeTransition(_opacity, CompositedTransformFollower(widget.layerLink, false, -widget.editingRegion.topLeft, Builder()));
}

Animation<double> _SelectionToolbarOverlayState::_opacity() {
    return _controller.view;
}

void _SelectionToolbarOverlayState::_toolbarVisibilityChanged() {
    if (widget.visibility?.value ?? true) {
        _controller.forward();
    } else {
        _controller.reverse();
    }
}

State<_SelectionHandleOverlay> _SelectionHandleOverlay::createState() {
    return _SelectionHandleOverlayState();
}

void _SelectionHandleOverlayState::initState() {
    super.initState();
    _controller = AnimationController(SelectionOverlay.fadeDuration, this);
    _handleVisibilityChanged();
    widget.visibility?.addListener(_handleVisibilityChanged);
}

void _SelectionHandleOverlayState::didUpdateWidget(_SelectionHandleOverlay oldWidget) {
    super.didUpdateWidget(oldWidget);
    oldWidget.visibility?.removeListener(_handleVisibilityChanged);
    _handleVisibilityChanged();
    widget.visibility?.addListener(_handleVisibilityChanged);
}

void _SelectionHandleOverlayState::dispose() {
    widget.visibility?.removeListener(_handleVisibilityChanged);
    _controller.dispose();
    super.dispose();
}

Widget _SelectionHandleOverlayState::build(BuildContext context) {
    Offset handleAnchor = widget.selectionControls.getHandleAnchor(widget.type, widget.preferredLineHeight);
    Size handleSize = widget.selectionControls.getHandleSize(widget.preferredLineHeight);
    Rect handleRect = Rect.fromLTWH(-handleAnchor.dx, -handleAnchor.dy, handleSize.width, handleSize.height);
    Rect interactiveRect = handleRect.expandToInclude(Rect.fromCircle(handleRect.center, kMinInteractiveDimension / 2));
    RelativeRect padding = RelativeRect.fromLTRB(math.max((interactiveRect.width - handleRect.width) / 2, 0), math.max((interactiveRect.height - handleRect.height) / 2, 0), math.max((interactiveRect.width - handleRect.width) / 2, 0), math.max((interactiveRect.height - handleRect.height) / 2, 0));
    return CompositedTransformFollower(widget.handleLayerLink, interactiveRect.topLeft, false, FadeTransition(_opacity, Container(Alignment.topLeft, interactiveRect.width, interactiveRect.height, RawGestureDetector(HitTestBehavior.translucent, , Padding(EdgeInsets.only(padding.left, padding.top, padding.right, padding.bottom), widget.selectionControls.buildHandle(context, widget.type, widget.preferredLineHeight, widget.onSelectionHandleTapped))))));
}

Animation<double> _SelectionHandleOverlayState::_opacity() {
    return _controller.view;
}

void _SelectionHandleOverlayState::_handleVisibilityChanged() {
    if (widget.visibility?.value ?? true) {
        _controller.forward();
    } else {
        _controller.reverse();
    }
}

TextSelectionGestureDetectorBuilder::TextSelectionGestureDetectorBuilder(TextSelectionGestureDetectorBuilderDelegate delegate) {
    {
        assert(delegate != nullptr);
    }
}

bool TextSelectionGestureDetectorBuilder::shouldShowSelectionToolbar() {
    return _shouldShowSelectionToolbar;
}

EditableTextState TextSelectionGestureDetectorBuilder::editableText() {
    return delegate.editableTextKey.currentState!;
}

RenderEditable TextSelectionGestureDetectorBuilder::renderEditable() {
    return editableText.renderEditable;
}

void TextSelectionGestureDetectorBuilder::onTapDown(TapDownDetails details) {
    if (!delegate.selectionEnabled) {
        return;
    }
    renderEditable.handleTapDown(details);
    PointerDeviceKind kind = details.kind;
    _shouldShowSelectionToolbar = kind == nullptr || kind == PointerDeviceKind.touch || kind == PointerDeviceKind.stylus;
    bool isShiftPressedValid = _isShiftPressed && renderEditable.selection?.baseOffset != nullptr;
    ;
}

void TextSelectionGestureDetectorBuilder::onForcePressStart(ForcePressDetails details) {
    assert(delegate.forcePressEnabled);
    _shouldShowSelectionToolbar = true;
    if (delegate.selectionEnabled) {
        renderEditable.selectWordsInRange(details.globalPosition, SelectionChangedCause.forcePress);
    }
}

void TextSelectionGestureDetectorBuilder::onForcePressEnd(ForcePressDetails details) {
    assert(delegate.forcePressEnabled);
    renderEditable.selectWordsInRange(details.globalPosition, SelectionChangedCause.forcePress);
    if (shouldShowSelectionToolbar) {
        editableText.showToolbar();
    }
}

void TextSelectionGestureDetectorBuilder::onSingleTapUp(TapUpDetails details) {
    if (delegate.selectionEnabled) {
        bool isShiftPressedValid = _isShiftPressed && renderEditable.selection?.baseOffset != nullptr;
        ;
    }
}

void TextSelectionGestureDetectorBuilder::onSingleTapCancel() {
}

void TextSelectionGestureDetectorBuilder::onSingleLongTapStart(LongPressStartDetails details) {
    if (delegate.selectionEnabled) {
        renderEditable.selectPositionAt(details.globalPosition, SelectionChangedCause.longPress);
    }
}

void TextSelectionGestureDetectorBuilder::onSingleLongTapMoveUpdate(LongPressMoveUpdateDetails details) {
    if (delegate.selectionEnabled) {
        renderEditable.selectPositionAt(details.globalPosition, SelectionChangedCause.longPress);
    }
}

void TextSelectionGestureDetectorBuilder::onSingleLongTapEnd(LongPressEndDetails details) {
    if (shouldShowSelectionToolbar) {
        editableText.showToolbar();
    }
}

void TextSelectionGestureDetectorBuilder::onSecondaryTap() {
    if (!delegate.selectionEnabled) {
        return;
    }
    ;
}

void TextSelectionGestureDetectorBuilder::onSecondaryTapDown(TapDownDetails details) {
    renderEditable.handleSecondaryTapDown(details);
    _shouldShowSelectionToolbar = true;
}

void TextSelectionGestureDetectorBuilder::onDoubleTapDown(TapDownDetails details) {
    if (delegate.selectionEnabled) {
        renderEditable.selectWord(SelectionChangedCause.tap);
        if (shouldShowSelectionToolbar) {
            editableText.showToolbar();
        }
    }
}

void TextSelectionGestureDetectorBuilder::onDragSelectionStart(DragStartDetails details) {
    if (!delegate.selectionEnabled) {
        return;
    }
    PointerDeviceKind kind = details.kind;
    _shouldShowSelectionToolbar = kind == nullptr || kind == PointerDeviceKind.touch || kind == PointerDeviceKind.stylus;
    if (_isShiftPressed && renderEditable.selection != nullptr && renderEditable.selection!.isValid) {
        _isShiftTapping = true;
        ;
        _shiftTapDragSelection = renderEditable.selection;
    } else {
        renderEditable.selectPositionAt(details.globalPosition, SelectionChangedCause.drag);
    }
    _dragStartViewportOffset = renderEditable.offset.pixels;
}

void TextSelectionGestureDetectorBuilder::onDragSelectionUpdate(DragStartDetails startDetails, DragUpdateDetails updateDetails) {
    if (!delegate.selectionEnabled) {
        return;
    }
    if (!_isShiftTapping) {
        Offset startOffset = renderEditable.maxLines == 1? Offset(renderEditable.offset.pixels - _dragStartViewportOffset, 0.0) : Offset(0.0, renderEditable.offset.pixels - _dragStartViewportOffset);
        return renderEditable.selectPositionAt(startDetails.globalPosition - startOffset, updateDetails.globalPosition, SelectionChangedCause.drag);
    }
    if (_shiftTapDragSelection!.isCollapsed || (defaultTargetPlatform != TargetPlatform.iOS && defaultTargetPlatform != TargetPlatform.macOS)) {
        return _extendSelection(updateDetails.globalPosition, SelectionChangedCause.drag);
    }
    TextSelection selection = editableText.textEditingValue.selection;
    TextPosition nextExtent = renderEditable.getPositionForPoint(updateDetails.globalPosition);
    bool isShiftTapDragSelectionForward = _shiftTapDragSelection!.baseOffset < _shiftTapDragSelection!.extentOffset;
    bool isInverted = isShiftTapDragSelectionForward? nextExtent.offset < _shiftTapDragSelection!.baseOffset : nextExtent.offset > _shiftTapDragSelection!.baseOffset;
    if (isInverted && selection.baseOffset == _shiftTapDragSelection!.baseOffset) {
        editableText.userUpdateTextEditingValue(editableText.textEditingValue.copyWith(TextSelection(_shiftTapDragSelection!.extentOffset, nextExtent.offset)), SelectionChangedCause.drag);
    } else     {
        if (!isInverted && nextExtent.offset != _shiftTapDragSelection!.baseOffset && selection.baseOffset != _shiftTapDragSelection!.baseOffset) {
        editableText.userUpdateTextEditingValue(editableText.textEditingValue.copyWith(TextSelection(_shiftTapDragSelection!.baseOffset, nextExtent.offset)), SelectionChangedCause.drag);
    } else {
        _extendSelection(updateDetails.globalPosition, SelectionChangedCause.drag);
    }
;
    }}

void TextSelectionGestureDetectorBuilder::onDragSelectionEnd(DragEndDetails details) {
    if (_isShiftTapping) {
        _isShiftTapping = false;
        _shiftTapDragSelection = nullptr;
    }
}

Widget TextSelectionGestureDetectorBuilder::buildGestureDetector(HitTestBehavior behavior, Widget child, Key key) {
    return TextSelectionGestureDetector(key, onTapDown, delegate.forcePressEnabled? onForcePressStart : nullptr, delegate.forcePressEnabled? onForcePressEnd : nullptr, onSecondaryTap, onSecondaryTapDown, onSingleTapUp, onSingleTapCancel, onSingleLongTapStart, onSingleLongTapMoveUpdate, onSingleLongTapEnd, onDoubleTapDown, onDragSelectionStart, onDragSelectionUpdate, onDragSelectionEnd, behavior, child);
}

bool TextSelectionGestureDetectorBuilder::_lastSecondaryTapWasOnSelection() {
    assert(renderEditable.lastSecondaryTapDownPosition != nullptr);
    if (renderEditable.selection == nullptr) {
        return false;
    }
    TextPosition textPosition = renderEditable.getPositionForPoint(renderEditable.lastSecondaryTapDownPosition!);
    return renderEditable.selection!.start <= textPosition.offset && renderEditable.selection!.end >= textPosition.offset;
}

void TextSelectionGestureDetectorBuilder::_expandSelection(SelectionChangedCause cause, TextSelection fromSelection, Offset offset) {
    assert(cause != nullptr);
    assert(offset != nullptr);
    assert(renderEditable.selection?.baseOffset != nullptr);
    TextPosition tappedPosition = renderEditable.getPositionForPoint(offset);
    TextSelection selection = fromSelection ?? renderEditable.selection!;
    bool baseIsCloser = (tappedPosition.offset - selection.baseOffset).abs() < (tappedPosition.offset - selection.extentOffset).abs();
    TextSelection nextSelection = selection.copyWith(baseIsCloser? selection.extentOffset : selection.baseOffset, tappedPosition.offset);
    editableText.userUpdateTextEditingValue(editableText.textEditingValue.copyWith(nextSelection), cause);
}

void TextSelectionGestureDetectorBuilder::_extendSelection(SelectionChangedCause cause, Offset offset) {
    assert(cause != nullptr);
    assert(offset != nullptr);
    assert(renderEditable.selection?.baseOffset != nullptr);
    TextPosition tappedPosition = renderEditable.getPositionForPoint(offset);
    TextSelection selection = renderEditable.selection!;
    TextSelection nextSelection = selection.copyWith(tappedPosition.offset);
    editableText.userUpdateTextEditingValue(editableText.textEditingValue.copyWith(nextSelection), cause);
}

bool TextSelectionGestureDetectorBuilder::_isShiftPressed() {
    return HardwareKeyboard.instance.logicalKeysPressed.any(.contains);
}

TextSelectionGestureDetector::TextSelectionGestureDetector(HitTestBehavior behavior, Widget child, Unknown, GestureTapDownCallback onDoubleTapDown, GestureDragEndCallback onDragSelectionEnd, GestureDragStartCallback onDragSelectionStart, DragSelectionUpdateCallback onDragSelectionUpdate, GestureForcePressEndCallback onForcePressEnd, GestureForcePressStartCallback onForcePressStart, GestureTapCallback onSecondaryTap, GestureTapDownCallback onSecondaryTapDown, GestureLongPressEndCallback onSingleLongTapEnd, GestureLongPressMoveUpdateCallback onSingleLongTapMoveUpdate, GestureLongPressStartCallback onSingleLongTapStart, GestureTapCancelCallback onSingleTapCancel, GestureTapUpCallback onSingleTapUp, GestureTapDownCallback onTapDown) {
    {
        assert(child != nullptr);
    }
}

State<StatefulWidget> TextSelectionGestureDetector::createState() {
    return _TextSelectionGestureDetectorState();
}

void _TextSelectionGestureDetectorState::dispose() {
    _doubleTapTimer?.cancel();
    _dragUpdateThrottleTimer?.cancel();
    super.dispose();
}

Widget _TextSelectionGestureDetectorState::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> gestures = ;
    gestures[TapGestureRecognizer] = <TapGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    if (widget.onSingleLongTapStart != nullptr || widget.onSingleLongTapMoveUpdate != nullptr || widget.onSingleLongTapEnd != nullptr) {
        gestures[LongPressGestureRecognizer] = <LongPressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (widget.onDragSelectionStart != nullptr || widget.onDragSelectionUpdate != nullptr || widget.onDragSelectionEnd != nullptr) {
        gestures[PanGestureRecognizer] = <PanGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (widget.onForcePressStart != nullptr || widget.onForcePressEnd != nullptr) {
        gestures[ForcePressGestureRecognizer] = <ForcePressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    return RawGestureDetector(gestures, true, widget.behavior, widget.child);
}

void _TextSelectionGestureDetectorState::_handleTapDown(TapDownDetails details) {
    widget.onTapDown?.call(details);
    if (_doubleTapTimer != nullptr && _isWithinDoubleTapTolerance(details.globalPosition)) {
        widget.onDoubleTapDown?.call(details);
        _doubleTapTimer!.cancel();
        _doubleTapTimeout();
        _isDoubleTap = true;
    }
}

void _TextSelectionGestureDetectorState::_handleTapUp(TapUpDetails details) {
    if (!_isDoubleTap) {
        widget.onSingleTapUp?.call(details);
        _lastTapOffset = details.globalPosition;
        _doubleTapTimer = Timer(kDoubleTapTimeout, _doubleTapTimeout);
    }
    _isDoubleTap = false;
}

void _TextSelectionGestureDetectorState::_handleTapCancel() {
    widget.onSingleTapCancel?.call();
}

void _TextSelectionGestureDetectorState::_handleDragStart(DragStartDetails details) {
    assert(_lastDragStartDetails == nullptr);
    _lastDragStartDetails = details;
    widget.onDragSelectionStart?.call(details);
}

void _TextSelectionGestureDetectorState::_handleDragUpdate(DragUpdateDetails details) {
    _lastDragUpdateDetails = details;
    _dragUpdateThrottleTimer = Timer(_kDragSelectionUpdateThrottle, _handleDragUpdateThrottled);
}

void _TextSelectionGestureDetectorState::_handleDragUpdateThrottled() {
    assert(_lastDragStartDetails != nullptr);
    assert(_lastDragUpdateDetails != nullptr);
    widget.onDragSelectionUpdate?.call(_lastDragStartDetails!, _lastDragUpdateDetails!);
    _dragUpdateThrottleTimer = nullptr;
    _lastDragUpdateDetails = nullptr;
}

void _TextSelectionGestureDetectorState::_handleDragEnd(DragEndDetails details) {
    assert(_lastDragStartDetails != nullptr);
    if (_dragUpdateThrottleTimer != nullptr) {
        _dragUpdateThrottleTimer!.cancel();
        _handleDragUpdateThrottled();
    }
    widget.onDragSelectionEnd?.call(details);
    _dragUpdateThrottleTimer = nullptr;
    _lastDragStartDetails = nullptr;
    _lastDragUpdateDetails = nullptr;
}

void _TextSelectionGestureDetectorState::_forcePressStarted(ForcePressDetails details) {
    _doubleTapTimer?.cancel();
    _doubleTapTimer = nullptr;
    widget.onForcePressStart?.call(details);
}

void _TextSelectionGestureDetectorState::_forcePressEnded(ForcePressDetails details) {
    widget.onForcePressEnd?.call(details);
}

void _TextSelectionGestureDetectorState::_handleLongPressStart(LongPressStartDetails details) {
    if (!_isDoubleTap && widget.onSingleLongTapStart != nullptr) {
        widget.onSingleLongTapStart!(details);
    }
}

void _TextSelectionGestureDetectorState::_handleLongPressMoveUpdate(LongPressMoveUpdateDetails details) {
    if (!_isDoubleTap && widget.onSingleLongTapMoveUpdate != nullptr) {
        widget.onSingleLongTapMoveUpdate!(details);
    }
}

void _TextSelectionGestureDetectorState::_handleLongPressEnd(LongPressEndDetails details) {
    if (!_isDoubleTap && widget.onSingleLongTapEnd != nullptr) {
        widget.onSingleLongTapEnd!(details);
    }
    _isDoubleTap = false;
}

void _TextSelectionGestureDetectorState::_doubleTapTimeout() {
    _doubleTapTimer = nullptr;
    _lastTapOffset = nullptr;
}

bool _TextSelectionGestureDetectorState::_isWithinDoubleTapTolerance(Offset secondTapOffset) {
    assert(secondTapOffset != nullptr);
    if (_lastTapOffset == nullptr) {
        return false;
    }
    Offset difference = secondTapOffset - _lastTapOffset!;
    return difference.distance <= kDoubleTapSlop;
}

ClipboardStatusNotifier::ClipboardStatusNotifier(ClipboardStatus value) {
    {
        super(value);
    }
}

bool ClipboardStatusNotifier::disposed() {
    return _disposed;
}

Future<void> ClipboardStatusNotifier::update() {
    if (_disposed) {
        return;
    }
    bool hasStrings;
    ;
    ClipboardStatus nextStatus = hasStrings? ClipboardStatus.pasteable : ClipboardStatus.notPasteable;
    if (_disposed || nextStatus == value) {
        return;
    }
    value = nextStatus;
}

void ClipboardStatusNotifier::addListener(VoidCallback listener) {
    if (!hasListeners) {
        WidgetsBinding.instance.addObserver(this);
    }
    if (value == ClipboardStatus.unknown) {
        update();
    }
    super.addListener(listener);
}

void ClipboardStatusNotifier::removeListener(VoidCallback listener) {
    super.removeListener(listener);
    if (!_disposed && !hasListeners) {
        WidgetsBinding.instance.removeObserver(this);
    }
}

void ClipboardStatusNotifier::didChangeAppLifecycleState(AppLifecycleState state) {
    ;
}

void ClipboardStatusNotifier::dispose() {
    WidgetsBinding.instance.removeObserver(this);
    _disposed = true;
    super.dispose();
}
