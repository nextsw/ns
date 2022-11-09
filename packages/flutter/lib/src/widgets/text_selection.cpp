#include "text_selection.hpp"
String ToolbarItemsParentDataCls::toString() {
    return "${super.toString()}; shouldPaint=$shouldPaint";
}

bool TextSelectionControlsCls::canCut(TextSelectionDelegate delegate) {
    return delegate->cutEnabled && !delegate->textEditingValue->selection->isCollapsed;
}

bool TextSelectionControlsCls::canCopy(TextSelectionDelegate delegate) {
    return delegate->copyEnabled && !delegate->textEditingValue->selection->isCollapsed;
}

bool TextSelectionControlsCls::canPaste(TextSelectionDelegate delegate) {
    return delegate->pasteEnabled;
}

bool TextSelectionControlsCls::canSelectAll(TextSelectionDelegate delegate) {
    return delegate->selectAllEnabled && delegate->textEditingValue->text->isNotEmpty && delegate->textEditingValue->selection->isCollapsed;
}

void TextSelectionControlsCls::handleCut(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate) {
    delegate->cutSelection(SelectionChangedCauseCls::toolbar);
}

void TextSelectionControlsCls::handleCopy(ClipboardStatusNotifier clipboardStatus, TextSelectionDelegate delegate) {
    delegate->copySelection(SelectionChangedCauseCls::toolbar);
}

Future<void> TextSelectionControlsCls::handlePaste(TextSelectionDelegate delegate) {
    delegate->pasteText(SelectionChangedCauseCls::toolbar);
}

void TextSelectionControlsCls::handleSelectAll(TextSelectionDelegate delegate) {
    delegate->selectAll(SelectionChangedCauseCls::toolbar);
    delegate->bringIntoView(delegate->textEditingValue->selection->extent);
}

TextSelectionOverlayCls::TextSelectionOverlayCls(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, bool handlesVisible, VoidCallback onSelectionHandleTapped, RenderEditable renderObject, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, LayerLink startHandleLayerLink, LayerLink toolbarLayerLink, TextEditingValue value) {
    {
        assert(value != nullptr);
        assert(context != nullptr);
        assert(handlesVisible != nullptr);
        _handlesVisible = handlesVisible;
        _value = value;
    }
    {
        renderObject->selectionStartInViewport->addListener(_updateTextSelectionOverlayVisibilities);
        renderObject->selectionEndInViewport->addListener(_updateTextSelectionOverlayVisibilities);
        _updateTextSelectionOverlayVisibilities();
        _selectionOverlay = make<SelectionOverlayCls>(context, debugRequiredFor, TextSelectionHandleTypeCls::collapsed, _effectiveStartHandleVisibility, 0.0, _handleSelectionStartHandleDragStart, _handleSelectionStartHandleDragUpdate, TextSelectionHandleTypeCls::collapsed, _effectiveEndHandleVisibility, 0.0, _handleSelectionEndHandleDragStart, _handleSelectionEndHandleDragUpdate, _effectiveToolbarVisibility, makeList(), selectionControls, selectionDelegate, clipboardStatus, startHandleLayerLink, endHandleLayerLink, toolbarLayerLink, onSelectionHandleTapped, dragStartBehavior, renderObject->lastSecondaryTapDownPosition);
    }
}

TextEditingValue TextSelectionOverlayCls::value() {
    return _value;
}

bool TextSelectionOverlayCls::handlesVisible() {
    return _handlesVisible;
}

void TextSelectionOverlayCls::handlesVisible(bool visible) {
    assert(visible != nullptr);
    if (_handlesVisible == visible) {
        return;
    }
    _handlesVisible = visible;
    _updateTextSelectionOverlayVisibilities();
}

void TextSelectionOverlayCls::showHandles() {
    _updateSelectionOverlay();
    _selectionOverlay->showHandles();
}

void TextSelectionOverlayCls::hideHandles() {
    return _selectionOverlay->hideHandles();
}

void TextSelectionOverlayCls::showToolbar() {
    _updateSelectionOverlay();
    _selectionOverlay->showToolbar();
}

void TextSelectionOverlayCls::update(TextEditingValue newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    _updateSelectionOverlay();
}

void TextSelectionOverlayCls::updateForScroll() {
    return _updateSelectionOverlay();
}

bool TextSelectionOverlayCls::handlesAreVisible() {
    return _selectionOverlay->_handles != nullptr && handlesVisible;
}

bool TextSelectionOverlayCls::toolbarIsVisible() {
    return _selectionOverlay->_toolbar != nullptr;
}

void TextSelectionOverlayCls::hide() {
    return _selectionOverlay->hide();
}

void TextSelectionOverlayCls::hideToolbar() {
    return _selectionOverlay->hideToolbar();
}

void TextSelectionOverlayCls::dispose() {
    _selectionOverlay->dispose();
    renderObject->selectionStartInViewport->removeListener(_updateTextSelectionOverlayVisibilities);
    renderObject->selectionEndInViewport->removeListener(_updateTextSelectionOverlayVisibilities);
    _effectiveToolbarVisibility->dispose();
    _effectiveStartHandleVisibility->dispose();
    _effectiveEndHandleVisibility->dispose();
}

TextSelection TextSelectionOverlayCls::_selection() {
    return _value->selection;
}

void TextSelectionOverlayCls::_updateTextSelectionOverlayVisibilities() {
    _effectiveStartHandleVisibility->value = _handlesVisible && renderObject->selectionStartInViewport->value;
    _effectiveEndHandleVisibility->value = _handlesVisible && renderObject->selectionEndInViewport->value;
    _effectiveToolbarVisibility->value = renderObject->selectionStartInViewport->value || renderObject->selectionEndInViewport->value;
}

void TextSelectionOverlayCls::_updateSelectionOverlay() {
    auto _c1 = _selectionOverlay;_c1.startHandleType = auto _c2 = _chooseType(renderObject->textDirection, TextSelectionHandleTypeCls::left, TextSelectionHandleTypeCls::right);_c2.lineHeightAtStart = auto _c3 = _getStartGlyphHeight();_c3.endHandleType = auto _c4 = _chooseType(renderObject->textDirection, TextSelectionHandleTypeCls::right, TextSelectionHandleTypeCls::left);_c4.lineHeightAtEnd = auto _c5 = _getEndGlyphHeight();_c5.selectionEndpoints = auto _c6 = renderObject->getEndpointsForSelection(_selection);_c6.toolbarLocation = renderObject->lastSecondaryTapDownPosition;_c6;_c5;_c4;_c3;_c2;_c1;
}

double TextSelectionOverlayCls::_getStartGlyphHeight() {
    InlineSpan span = renderObject->text!;
    String prevText = span->toPlainText();
    String currText = selectionDelegate->textEditingValue->text;
    int firstSelectedGraphemeExtent;
    Rect startHandleRect;
    if (prevText == currText && _selection != nullptr && _selection->isValid && !_selection->isCollapsed) {
        String selectedGraphemes = _selection->textInside(currText);
        firstSelectedGraphemeExtent = selectedGraphemes->characters->first->length;
        startHandleRect = renderObject->getRectForComposingRange(make<TextRangeCls>(_selection->start, _selection->start + firstSelectedGraphemeExtent));
    }
    return startHandleRect?->height ?? renderObject->preferredLineHeight;
}

double TextSelectionOverlayCls::_getEndGlyphHeight() {
    InlineSpan span = renderObject->text!;
    String prevText = span->toPlainText();
    String currText = selectionDelegate->textEditingValue->text;
    int lastSelectedGraphemeExtent;
    Rect endHandleRect;
    if (prevText == currText && _selection != nullptr && _selection->isValid && !_selection->isCollapsed) {
        String selectedGraphemes = _selection->textInside(currText);
        lastSelectedGraphemeExtent = selectedGraphemes->characters->last->length;
        endHandleRect = renderObject->getRectForComposingRange(make<TextRangeCls>(_selection->end - lastSelectedGraphemeExtent, _selection->end));
    }
    return endHandleRect?->height ?? renderObject->preferredLineHeight;
}

void TextSelectionOverlayCls::_handleSelectionEndHandleDragStart(DragStartDetails details) {
    Size handleSize = selectionControls!->getHandleSize(renderObject->preferredLineHeight);
    _dragEndPosition = details->globalPosition + make<OffsetCls>(0.0, -handleSize->height);
}

void TextSelectionOverlayCls::_handleSelectionEndHandleDragUpdate(DragUpdateDetails details) {
    _dragEndPosition = details->delta;
    TextPosition position = renderObject->getPositionForPoint(_dragEndPosition);
    if (_selection->isCollapsed) {
        _handleSelectionHandleChanged(TextSelectionCls->fromPosition(position)true);
        return;
    }
    TextSelection newSelection;
    ;
    _handleSelectionHandleChanged(newSelectiontrue);
}

void TextSelectionOverlayCls::_handleSelectionStartHandleDragStart(DragStartDetails details) {
    Size handleSize = selectionControls!->getHandleSize(renderObject->preferredLineHeight);
    _dragStartPosition = details->globalPosition + make<OffsetCls>(0.0, -handleSize->height);
}

void TextSelectionOverlayCls::_handleSelectionStartHandleDragUpdate(DragUpdateDetails details) {
    _dragStartPosition = details->delta;
    TextPosition position = renderObject->getPositionForPoint(_dragStartPosition);
    if (_selection->isCollapsed) {
        _handleSelectionHandleChanged(TextSelectionCls->fromPosition(position)false);
        return;
    }
    TextSelection newSelection;
    ;
    _handleSelectionHandleChanged(newSelectionfalse);
}

void TextSelectionOverlayCls::_handleSelectionHandleChanged(bool isEnd, TextSelection newSelection) {
    TextPosition textPosition = isEnd? newSelection->extent : newSelection->base;
    selectionDelegate->userUpdateTextEditingValue(_value->copyWith(newSelection), SelectionChangedCauseCls::drag);
    selectionDelegate->bringIntoView(textPosition);
}

TextSelectionHandleType TextSelectionOverlayCls::_chooseType(TextSelectionHandleType ltrType, TextSelectionHandleType rtlType, TextDirection textDirection) {
    if (_selection->isCollapsed) {
        return TextSelectionHandleTypeCls::collapsed;
    }
    assert(textDirection != nullptr);
    ;
}

SelectionOverlayCls::SelectionOverlayCls(ClipboardStatusNotifier clipboardStatus, BuildContext context, Widget debugRequiredFor, DragStartBehavior dragStartBehavior, LayerLink endHandleLayerLink, TextSelectionHandleType endHandleType, ValueListenable<bool> endHandlesVisible, double lineHeightAtEnd, double lineHeightAtStart, ValueChanged<DragEndDetails> onEndHandleDragEnd, ValueChanged<DragStartDetails> onEndHandleDragStart, ValueChanged<DragUpdateDetails> onEndHandleDragUpdate, VoidCallback onSelectionHandleTapped, ValueChanged<DragEndDetails> onStartHandleDragEnd, ValueChanged<DragStartDetails> onStartHandleDragStart, ValueChanged<DragUpdateDetails> onStartHandleDragUpdate, TextSelectionControls selectionControls, TextSelectionDelegate selectionDelegate, List<TextSelectionPoint> selectionEndpoints, LayerLink startHandleLayerLink, TextSelectionHandleType startHandleType, ValueListenable<bool> startHandlesVisible, LayerLink toolbarLayerLink, Offset toolbarLocation, ValueListenable<bool> toolbarVisible) {
    {
        _startHandleType = startHandleType;
        _lineHeightAtStart = lineHeightAtStart;
        _endHandleType = endHandleType;
        _lineHeightAtEnd = lineHeightAtEnd;
        _selectionEndpoints = selectionEndpoints;
        _toolbarLocation = toolbarLocation;
    }
    {
        OverlayState overlay = OverlayCls->of(contexttrue);
        assert(overlay != nullptr, "No Overlay widget exists above $context.\nUsually the Navigator created by WidgetsApp provides the overlay. Perhaps your app content was created above the Navigator with the WidgetsApp builder parameter.");
    }
}

TextSelectionHandleType SelectionOverlayCls::startHandleType() {
    return _startHandleType;
}

void SelectionOverlayCls::startHandleType(TextSelectionHandleType value) {
    if (_startHandleType == value) {
        return;
    }
    _startHandleType = value;
    _markNeedsBuild();
}

double SelectionOverlayCls::lineHeightAtStart() {
    return _lineHeightAtStart;
}

void SelectionOverlayCls::lineHeightAtStart(double value) {
    if (_lineHeightAtStart == value) {
        return;
    }
    _lineHeightAtStart = value;
    _markNeedsBuild();
}

TextSelectionHandleType SelectionOverlayCls::endHandleType() {
    return _endHandleType;
}

void SelectionOverlayCls::endHandleType(TextSelectionHandleType value) {
    if (_endHandleType == value) {
        return;
    }
    _endHandleType = value;
    _markNeedsBuild();
}

double SelectionOverlayCls::lineHeightAtEnd() {
    return _lineHeightAtEnd;
}

void SelectionOverlayCls::lineHeightAtEnd(double value) {
    if (_lineHeightAtEnd == value) {
        return;
    }
    _lineHeightAtEnd = value;
    _markNeedsBuild();
}

List<TextSelectionPoint> SelectionOverlayCls::selectionEndpoints() {
    return _selectionEndpoints;
}

void SelectionOverlayCls::selectionEndpoints(List<TextSelectionPoint> value) {
    if (!listEquals(_selectionEndpoints, value)) {
        _markNeedsBuild();
    }
    _selectionEndpoints = value;
}

Offset SelectionOverlayCls::toolbarLocation() {
    return _toolbarLocation;
}

void SelectionOverlayCls::toolbarLocation(Offset value) {
    if (_toolbarLocation == value) {
        return;
    }
    _toolbarLocation = value;
    _markNeedsBuild();
}

void SelectionOverlayCls::showHandles() {
    if (_handles != nullptr) {
        return;
    }
    _handles = makeList(ArrayItem, ArrayItem);
    OverlayCls->of(contexttrue, debugRequiredFor)!->insertAll(_handles!);
}

void SelectionOverlayCls::hideHandles() {
    if (_handles != nullptr) {
        _handles![0]->remove();
        _handles![1]->remove();
        _handles = nullptr;
    }
}

void SelectionOverlayCls::showToolbar() {
    if (_toolbar != nullptr) {
        return;
    }
    _toolbar = make<OverlayEntryCls>(_buildToolbar);
    OverlayCls->of(contexttrue, debugRequiredFor)!->insert(_toolbar!);
}

void SelectionOverlayCls::hide() {
    if (_handles != nullptr) {
        _handles![0]->remove();
        _handles![1]->remove();
        _handles = nullptr;
    }
    if (_toolbar != nullptr) {
        hideToolbar();
    }
}

void SelectionOverlayCls::hideToolbar() {
    if (_toolbar == nullptr) {
        return;
    }
    _toolbar?->remove();
    _toolbar = nullptr;
}

void SelectionOverlayCls::dispose() {
    hide();
}

void SelectionOverlayCls::_markNeedsBuild() {
    if (_handles == nullptr && _toolbar == nullptr) {
        return;
    }
    if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::persistentCallbacks) {
        if (_buildScheduled) {
            return;
        }
        _buildScheduled = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
            _buildScheduled = false;
            if (_handles != nullptr) {
                _handles![0]->markNeedsBuild();
                _handles![1]->markNeedsBuild();
            }
            _toolbar?->markNeedsBuild();
        });
    } else {
        if (_handles != nullptr) {
            _handles![0]->markNeedsBuild();
            _handles![1]->markNeedsBuild();
        }
        _toolbar?->markNeedsBuild();
    }
}

Widget SelectionOverlayCls::_buildStartHandle(BuildContext context) {
    Widget handle;
    TextSelectionControls selectionControls = this->selectionControls;
    if (selectionControls == nullptr) {
        handle = make<ContainerCls>();
    } else {
        handle = make<_SelectionHandleOverlayCls>(_startHandleType, startHandleLayerLink, onSelectionHandleTapped, onStartHandleDragStart, onStartHandleDragUpdate, onStartHandleDragEnd, selectionControls, startHandlesVisible, _lineHeightAtStart, dragStartBehavior);
    }
    return make<ExcludeSemanticsCls>(handle);
}

Widget SelectionOverlayCls::_buildEndHandle(BuildContext context) {
    Widget handle;
    TextSelectionControls selectionControls = this->selectionControls;
    if (selectionControls == nullptr || _startHandleType == TextSelectionHandleTypeCls::collapsed) {
        handle = make<ContainerCls>();
    } else {
        handle = make<_SelectionHandleOverlayCls>(_endHandleType, endHandleLayerLink, onSelectionHandleTapped, onEndHandleDragStart, onEndHandleDragUpdate, onEndHandleDragEnd, selectionControls, endHandlesVisible, _lineHeightAtEnd, dragStartBehavior);
    }
    return make<ExcludeSemanticsCls>(handle);
}

Widget SelectionOverlayCls::_buildToolbar(BuildContext context) {
    if (selectionControls == nullptr) {
        return make<ContainerCls>();
    }
    RenderBox renderBox = ((RenderBox)this->context->findRenderObject()!);
    Rect editingRegion = RectCls->fromPoints(renderBox->localToGlobal(OffsetCls::zero), renderBox->localToGlobal(renderBox->size->bottomRight(OffsetCls::zero)));
    bool isMultiline = selectionEndpoints->last->point->dy - selectionEndpoints->first->point->dy > lineHeightAtEnd / 2;
    double midX = isMultiline? editingRegion->width / 2 : (selectionEndpoints->first->point->dx + selectionEndpoints->last->point->dx) / 2;
    Offset midpoint = make<OffsetCls>(midX, selectionEndpoints->first->point->dy - lineHeightAtStart);
    return make<DirectionalityCls>(DirectionalityCls->of(this->context), make<_SelectionToolbarOverlayCls>(lineHeightAtStart, toolbarLocation, toolbarLayerLink, editingRegion, selectionControls, midpoint, selectionEndpoints, toolbarVisible, selectionDelegate, clipboardStatus));
}

_SelectionToolbarOverlayState _SelectionToolbarOverlayCls::createState() {
    return make<_SelectionToolbarOverlayStateCls>();
}

void _SelectionToolbarOverlayStateCls::initState() {
    super->initState();
    _controller = make<AnimationControllerCls>(SelectionOverlayCls::fadeDuration, this);
    _toolbarVisibilityChanged();
    widget->visibility?->addListener(_toolbarVisibilityChanged);
}

void _SelectionToolbarOverlayStateCls::didUpdateWidget(_SelectionToolbarOverlay oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->visibility == widget->visibility) {
        return;
    }
    oldWidget->visibility?->removeListener(_toolbarVisibilityChanged);
    _toolbarVisibilityChanged();
    widget->visibility?->addListener(_toolbarVisibilityChanged);
}

void _SelectionToolbarOverlayStateCls::dispose() {
    widget->visibility?->removeListener(_toolbarVisibilityChanged);
    _controller->dispose();
    super->dispose();
}

Widget _SelectionToolbarOverlayStateCls::build(BuildContext context) {
    return make<FadeTransitionCls>(_opacity, make<CompositedTransformFollowerCls>(widget->layerLink, false, -widget->editingRegion->topLeft, make<BuilderCls>([=] (BuildContext context) {
        return widget->selectionControls!->buildToolbar(context, widget->editingRegion, widget->preferredLineHeight, widget->midpoint, widget->selectionEndpoints, widget->selectionDelegate!, widget->clipboardStatus, widget->toolbarLocation);
    })));
}

Animation<double> _SelectionToolbarOverlayStateCls::_opacity() {
    return _controller->view;
}

void _SelectionToolbarOverlayStateCls::_toolbarVisibilityChanged() {
    if (widget->visibility?->value ?? true) {
        _controller->forward();
    } else {
        _controller->reverse();
    }
}

State<_SelectionHandleOverlay> _SelectionHandleOverlayCls::createState() {
    return make<_SelectionHandleOverlayStateCls>();
}

void _SelectionHandleOverlayStateCls::initState() {
    super->initState();
    _controller = make<AnimationControllerCls>(SelectionOverlayCls::fadeDuration, this);
    _handleVisibilityChanged();
    widget->visibility?->addListener(_handleVisibilityChanged);
}

void _SelectionHandleOverlayStateCls::didUpdateWidget(_SelectionHandleOverlay oldWidget) {
    super->didUpdateWidget(oldWidget);
    oldWidget->visibility?->removeListener(_handleVisibilityChanged);
    _handleVisibilityChanged();
    widget->visibility?->addListener(_handleVisibilityChanged);
}

void _SelectionHandleOverlayStateCls::dispose() {
    widget->visibility?->removeListener(_handleVisibilityChanged);
    _controller->dispose();
    super->dispose();
}

Widget _SelectionHandleOverlayStateCls::build(BuildContext context) {
    Offset handleAnchor = widget->selectionControls->getHandleAnchor(widget->type, widget->preferredLineHeight);
    Size handleSize = widget->selectionControls->getHandleSize(widget->preferredLineHeight);
    Rect handleRect = RectCls->fromLTWH(-handleAnchor->dx, -handleAnchor->dy, handleSize->width, handleSize->height);
    Rect interactiveRect = handleRect->expandToInclude(RectCls->fromCircle(handleRect->center, kMinInteractiveDimension / 2));
    RelativeRect padding = RelativeRectCls->fromLTRB(math->max((interactiveRect->width - handleRect->width) / 2, 0), math->max((interactiveRect->height - handleRect->height) / 2, 0), math->max((interactiveRect->width - handleRect->width) / 2, 0), math->max((interactiveRect->height - handleRect->height) / 2, 0));
        }));return make<CompositedTransformFollowerCls>(widget->handleLayerLink, interactiveRect->topLeft, false, make<FadeTransitionCls>(_opacity, make<ContainerCls>(AlignmentCls::topLeft, interactiveRect->width, interactiveRect->height, make<RawGestureDetectorCls>(HitTestBehaviorCls::translucent,     Map<Type, GestureRecognizerFactory> map1 = make<MapCls<>>();    map1.set(PanGestureRecognizerCls, <PanGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {            make<PanGestureRecognizerCls>(this, makeSet(ArrayItem, ArrayItem, ArrayItem));        }, [=] (PanGestureRecognizer instance) {            auto _c2 = instance;    _c2.dragStartBehavior = auto _c3 = widget->dragStartBehavior;    _c3.onStart = auto _c4 = widget->onSelectionHandleDragStart;    _c4.onUpdate = auto _c5 = widget->onSelectionHandleDragUpdate;    _c5.onEnd = widget->onSelectionHandleDragEnd;    _c5;    _c4;    _c3;    _c2;list1, make<PaddingCls>(EdgeInsetsCls->only(padding->left, padding->top, padding->right, padding->bottom), widget->selectionControls->buildHandle(context, widget->type, widget->preferredLineHeight, widget->onSelectionHandleTapped))))));
}

Animation<double> _SelectionHandleOverlayStateCls::_opacity() {
    return _controller->view;
}

void _SelectionHandleOverlayStateCls::_handleVisibilityChanged() {
    if (widget->visibility?->value ?? true) {
        _controller->forward();
    } else {
        _controller->reverse();
    }
}

TextSelectionGestureDetectorBuilderCls::TextSelectionGestureDetectorBuilderCls(TextSelectionGestureDetectorBuilderDelegate delegate) {
    {
        assert(delegate != nullptr);
    }
}

bool TextSelectionGestureDetectorBuilderCls::shouldShowSelectionToolbar() {
    return _shouldShowSelectionToolbar;
}

EditableTextState TextSelectionGestureDetectorBuilderCls::editableText() {
    return delegate->editableTextKey->currentState!;
}

RenderEditable TextSelectionGestureDetectorBuilderCls::renderEditable() {
    return editableText->renderEditable;
}

void TextSelectionGestureDetectorBuilderCls::onTapDown(TapDownDetails details) {
    if (!delegate->selectionEnabled) {
        return;
    }
    renderEditable->handleTapDown(details);
    PointerDeviceKind kind = details->kind;
    _shouldShowSelectionToolbar = kind == nullptr || kind == PointerDeviceKindCls::touch || kind == PointerDeviceKindCls::stylus;
    bool isShiftPressedValid = _isShiftPressed && renderEditable->selection?->baseOffset != nullptr;
    ;
}

void TextSelectionGestureDetectorBuilderCls::onForcePressStart(ForcePressDetails details) {
    assert(delegate->forcePressEnabled);
    _shouldShowSelectionToolbar = true;
    if (delegate->selectionEnabled) {
        renderEditable->selectWordsInRange(details->globalPosition, SelectionChangedCauseCls::forcePress);
    }
}

void TextSelectionGestureDetectorBuilderCls::onForcePressEnd(ForcePressDetails details) {
    assert(delegate->forcePressEnabled);
    renderEditable->selectWordsInRange(details->globalPosition, SelectionChangedCauseCls::forcePress);
    if (shouldShowSelectionToolbar) {
        editableText->showToolbar();
    }
}

void TextSelectionGestureDetectorBuilderCls::onSingleTapUp(TapUpDetails details) {
    if (delegate->selectionEnabled) {
        bool isShiftPressedValid = _isShiftPressed && renderEditable->selection?->baseOffset != nullptr;
        ;
    }
}

void TextSelectionGestureDetectorBuilderCls::onSingleTapCancel() {
}

void TextSelectionGestureDetectorBuilderCls::onSingleLongTapStart(LongPressStartDetails details) {
    if (delegate->selectionEnabled) {
        renderEditable->selectPositionAt(details->globalPosition, SelectionChangedCauseCls::longPress);
    }
}

void TextSelectionGestureDetectorBuilderCls::onSingleLongTapMoveUpdate(LongPressMoveUpdateDetails details) {
    if (delegate->selectionEnabled) {
        renderEditable->selectPositionAt(details->globalPosition, SelectionChangedCauseCls::longPress);
    }
}

void TextSelectionGestureDetectorBuilderCls::onSingleLongTapEnd(LongPressEndDetails details) {
    if (shouldShowSelectionToolbar) {
        editableText->showToolbar();
    }
}

void TextSelectionGestureDetectorBuilderCls::onSecondaryTap() {
    if (!delegate->selectionEnabled) {
        return;
    }
    ;
}

void TextSelectionGestureDetectorBuilderCls::onSecondaryTapDown(TapDownDetails details) {
    renderEditable->handleSecondaryTapDown(details);
    _shouldShowSelectionToolbar = true;
}

void TextSelectionGestureDetectorBuilderCls::onDoubleTapDown(TapDownDetails details) {
    if (delegate->selectionEnabled) {
        renderEditable->selectWord(SelectionChangedCauseCls::tap);
        if (shouldShowSelectionToolbar) {
            editableText->showToolbar();
        }
    }
}

void TextSelectionGestureDetectorBuilderCls::onDragSelectionStart(DragStartDetails details) {
    if (!delegate->selectionEnabled) {
        return;
    }
    PointerDeviceKind kind = details->kind;
    _shouldShowSelectionToolbar = kind == nullptr || kind == PointerDeviceKindCls::touch || kind == PointerDeviceKindCls::stylus;
    if (_isShiftPressed && renderEditable->selection != nullptr && renderEditable->selection!->isValid) {
        _isShiftTapping = true;
        ;
        _shiftTapDragSelection = renderEditable->selection;
    } else {
        renderEditable->selectPositionAt(details->globalPosition, SelectionChangedCauseCls::drag);
    }
    _dragStartViewportOffset = renderEditable->offset->pixels;
}

void TextSelectionGestureDetectorBuilderCls::onDragSelectionUpdate(DragStartDetails startDetails, DragUpdateDetails updateDetails) {
    if (!delegate->selectionEnabled) {
        return;
    }
    if (!_isShiftTapping) {
        Offset startOffset = renderEditable->maxLines == 1? make<OffsetCls>(renderEditable->offset->pixels - _dragStartViewportOffset, 0.0) : make<OffsetCls>(0.0, renderEditable->offset->pixels - _dragStartViewportOffset);
        return renderEditable->selectPositionAt(startDetails->globalPosition - startOffset, updateDetails->globalPosition, SelectionChangedCauseCls::drag);
    }
    if (_shiftTapDragSelection!->isCollapsed || (defaultTargetPlatform != TargetPlatformCls::iOS && defaultTargetPlatform != TargetPlatformCls::macOS)) {
        return _extendSelection(updateDetails->globalPosition, SelectionChangedCauseCls::drag);
    }
    TextSelection selection = editableText->textEditingValue->selection;
    TextPosition nextExtent = renderEditable->getPositionForPoint(updateDetails->globalPosition);
    bool isShiftTapDragSelectionForward = _shiftTapDragSelection!->baseOffset < _shiftTapDragSelection!->extentOffset;
    bool isInverted = isShiftTapDragSelectionForward? nextExtent->offset < _shiftTapDragSelection!->baseOffset : nextExtent->offset > _shiftTapDragSelection!->baseOffset;
    if (isInverted && selection->baseOffset == _shiftTapDragSelection!->baseOffset) {
        editableText->userUpdateTextEditingValue(editableText->textEditingValue->copyWith(make<TextSelectionCls>(_shiftTapDragSelection!->extentOffset, nextExtent->offset)), SelectionChangedCauseCls::drag);
    } else     {
        if (!isInverted && nextExtent->offset != _shiftTapDragSelection!->baseOffset && selection->baseOffset != _shiftTapDragSelection!->baseOffset) {
        editableText->userUpdateTextEditingValue(editableText->textEditingValue->copyWith(make<TextSelectionCls>(_shiftTapDragSelection!->baseOffset, nextExtent->offset)), SelectionChangedCauseCls::drag);
    } else {
        _extendSelection(updateDetails->globalPosition, SelectionChangedCauseCls::drag);
    }
;
    }}

void TextSelectionGestureDetectorBuilderCls::onDragSelectionEnd(DragEndDetails details) {
    if (_isShiftTapping) {
        _isShiftTapping = false;
        _shiftTapDragSelection = nullptr;
    }
}

Widget TextSelectionGestureDetectorBuilderCls::buildGestureDetector(HitTestBehavior behavior, Widget child, Key key) {
    return make<TextSelectionGestureDetectorCls>(key, onTapDown, delegate->forcePressEnabled? onForcePressStart : nullptr, delegate->forcePressEnabled? onForcePressEnd : nullptr, onSecondaryTap, onSecondaryTapDown, onSingleTapUp, onSingleTapCancel, onSingleLongTapStart, onSingleLongTapMoveUpdate, onSingleLongTapEnd, onDoubleTapDown, onDragSelectionStart, onDragSelectionUpdate, onDragSelectionEnd, behavior, child);
}

bool TextSelectionGestureDetectorBuilderCls::_lastSecondaryTapWasOnSelection() {
    assert(renderEditable->lastSecondaryTapDownPosition != nullptr);
    if (renderEditable->selection == nullptr) {
        return false;
    }
    TextPosition textPosition = renderEditable->getPositionForPoint(renderEditable->lastSecondaryTapDownPosition!);
    return renderEditable->selection!->start <= textPosition->offset && renderEditable->selection!->end >= textPosition->offset;
}

void TextSelectionGestureDetectorBuilderCls::_expandSelection(SelectionChangedCause cause, TextSelection fromSelection, Offset offset) {
    assert(cause != nullptr);
    assert(offset != nullptr);
    assert(renderEditable->selection?->baseOffset != nullptr);
    TextPosition tappedPosition = renderEditable->getPositionForPoint(offset);
    TextSelection selection = fromSelection ?? renderEditable->selection!;
    bool baseIsCloser = (tappedPosition->offset - selection->baseOffset)->abs() < (tappedPosition->offset - selection->extentOffset)->abs();
    TextSelection nextSelection = selection->copyWith(baseIsCloser? selection->extentOffset : selection->baseOffset, tappedPosition->offset);
    editableText->userUpdateTextEditingValue(editableText->textEditingValue->copyWith(nextSelection), cause);
}

void TextSelectionGestureDetectorBuilderCls::_extendSelection(SelectionChangedCause cause, Offset offset) {
    assert(cause != nullptr);
    assert(offset != nullptr);
    assert(renderEditable->selection?->baseOffset != nullptr);
    TextPosition tappedPosition = renderEditable->getPositionForPoint(offset);
    TextSelection selection = renderEditable->selection!;
    TextSelection nextSelection = selection->copyWith(tappedPosition->offset);
    editableText->userUpdateTextEditingValue(editableText->textEditingValue->copyWith(nextSelection), cause);
}

bool TextSelectionGestureDetectorBuilderCls::_isShiftPressed() {
    return HardwareKeyboardCls::instance->logicalKeysPressed->any(makeSet(ArrayItem, ArrayItem)->contains);
}

TextSelectionGestureDetectorCls::TextSelectionGestureDetectorCls(HitTestBehavior behavior, Widget child, Unknown key, GestureTapDownCallback onDoubleTapDown, GestureDragEndCallback onDragSelectionEnd, GestureDragStartCallback onDragSelectionStart, DragSelectionUpdateCallback onDragSelectionUpdate, GestureForcePressEndCallback onForcePressEnd, GestureForcePressStartCallback onForcePressStart, GestureTapCallback onSecondaryTap, GestureTapDownCallback onSecondaryTapDown, GestureLongPressEndCallback onSingleLongTapEnd, GestureLongPressMoveUpdateCallback onSingleLongTapMoveUpdate, GestureLongPressStartCallback onSingleLongTapStart, GestureTapCancelCallback onSingleTapCancel, GestureTapUpCallback onSingleTapUp, GestureTapDownCallback onTapDown) {
    {
        assert(child != nullptr);
    }
}

State<StatefulWidget> TextSelectionGestureDetectorCls::createState() {
    return make<_TextSelectionGestureDetectorStateCls>();
}

void _TextSelectionGestureDetectorStateCls::dispose() {
    _doubleTapTimer?->cancel();
    _dragUpdateThrottleTimer?->cancel();
    super->dispose();
}

Widget _TextSelectionGestureDetectorStateCls::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> gestures = makeMap(makeList(), makeList();
    gestures[TapGestureRecognizerCls] = <TapGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<TapGestureRecognizerCls>(this);
    }, [=] (TapGestureRecognizer instance) {
            auto _c1 = instance;    _c1.onSecondaryTap = auto _c2 = widget->onSecondaryTap;    _c2.onSecondaryTapDown = auto _c3 = widget->onSecondaryTapDown;    _c3.onTapDown = auto _c4 = _handleTapDown;    _c4.onTapUp = auto _c5 = _handleTapUp;    _c5.onTapCancel = _handleTapCancel;    _c5;    _c4;    _c3;    _c2;_c1;
    });
    if (widget->onSingleLongTapStart != nullptr || widget->onSingleLongTapMoveUpdate != nullptr || widget->onSingleLongTapEnd != nullptr) {
        gestures[LongPressGestureRecognizerCls] = <LongPressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()         {
            make<LongPressGestureRecognizerCls>(this, PointerDeviceKindCls::touch);
        }, [=] (LongPressGestureRecognizer instance) {
                    auto _c6 = instance;        _c6.onLongPressStart = auto _c7 = _handleLongPressStart;        _c7.onLongPressMoveUpdate = auto _c8 = _handleLongPressMoveUpdate;        _c8.onLongPressEnd = _handleLongPressEnd;        _c8;        _c7;_c6;
        });
    }
    if (widget->onDragSelectionStart != nullptr || widget->onDragSelectionUpdate != nullptr || widget->onDragSelectionEnd != nullptr) {
        gestures[PanGestureRecognizerCls] = <PanGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()         {
            make<PanGestureRecognizerCls>(this, makeSet(ArrayItem));
        }, [=] (PanGestureRecognizer instance) {
                    auto _c9 = instance;        _c9.dragStartBehavior = auto _c10 = DragStartBehaviorCls::down;        _c10.onStart = auto _c11 = _handleDragStart;        _c11.onUpdate = auto _c12 = _handleDragUpdate;        _c12.onEnd = _handleDragEnd;        _c12;        _c11;        _c10;_c9;
        });
    }
    if (widget->onForcePressStart != nullptr || widget->onForcePressEnd != nullptr) {
        gestures[ForcePressGestureRecognizerCls] = <ForcePressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()         {
            make<ForcePressGestureRecognizerCls>(this);
        }, [=] (ForcePressGestureRecognizer instance) {
                    auto _c13 = instance;        _c13.onStart = widget->onForcePressStart != nullptr? _forcePressStarted : auto _c14 = nullptr;        _c14.onEnd = widget->onForcePressEnd != nullptr? _forcePressEnded : nullptr;        _c14;_c13;
        });
    }
    return make<RawGestureDetectorCls>(gestures, true, widget->behavior, widget->child);
}

void _TextSelectionGestureDetectorStateCls::_handleTapDown(TapDownDetails details) {
    widget->onTapDown?->call(details);
    if (_doubleTapTimer != nullptr && _isWithinDoubleTapTolerance(details->globalPosition)) {
        widget->onDoubleTapDown?->call(details);
        _doubleTapTimer!->cancel();
        _doubleTapTimeout();
        _isDoubleTap = true;
    }
}

void _TextSelectionGestureDetectorStateCls::_handleTapUp(TapUpDetails details) {
    if (!_isDoubleTap) {
        widget->onSingleTapUp?->call(details);
        _lastTapOffset = details->globalPosition;
        _doubleTapTimer = make<TimerCls>(kDoubleTapTimeout, _doubleTapTimeout);
    }
    _isDoubleTap = false;
}

void _TextSelectionGestureDetectorStateCls::_handleTapCancel() {
    widget->onSingleTapCancel?->call();
}

void _TextSelectionGestureDetectorStateCls::_handleDragStart(DragStartDetails details) {
    assert(_lastDragStartDetails == nullptr);
    _lastDragStartDetails = details;
    widget->onDragSelectionStart?->call(details);
}

void _TextSelectionGestureDetectorStateCls::_handleDragUpdate(DragUpdateDetails details) {
    _lastDragUpdateDetails = details;
    _dragUpdateThrottleTimer = make<TimerCls>(_kDragSelectionUpdateThrottle, _handleDragUpdateThrottled);
}

void _TextSelectionGestureDetectorStateCls::_handleDragUpdateThrottled() {
    assert(_lastDragStartDetails != nullptr);
    assert(_lastDragUpdateDetails != nullptr);
    widget->onDragSelectionUpdate?->call(_lastDragStartDetails!, _lastDragUpdateDetails!);
    _dragUpdateThrottleTimer = nullptr;
    _lastDragUpdateDetails = nullptr;
}

void _TextSelectionGestureDetectorStateCls::_handleDragEnd(DragEndDetails details) {
    assert(_lastDragStartDetails != nullptr);
    if (_dragUpdateThrottleTimer != nullptr) {
        _dragUpdateThrottleTimer!->cancel();
        _handleDragUpdateThrottled();
    }
    widget->onDragSelectionEnd?->call(details);
    _dragUpdateThrottleTimer = nullptr;
    _lastDragStartDetails = nullptr;
    _lastDragUpdateDetails = nullptr;
}

void _TextSelectionGestureDetectorStateCls::_forcePressStarted(ForcePressDetails details) {
    _doubleTapTimer?->cancel();
    _doubleTapTimer = nullptr;
    widget->onForcePressStart?->call(details);
}

void _TextSelectionGestureDetectorStateCls::_forcePressEnded(ForcePressDetails details) {
    widget->onForcePressEnd?->call(details);
}

void _TextSelectionGestureDetectorStateCls::_handleLongPressStart(LongPressStartDetails details) {
    if (!_isDoubleTap && widget->onSingleLongTapStart != nullptr) {
        widget->onSingleLongTapStart!(details);
    }
}

void _TextSelectionGestureDetectorStateCls::_handleLongPressMoveUpdate(LongPressMoveUpdateDetails details) {
    if (!_isDoubleTap && widget->onSingleLongTapMoveUpdate != nullptr) {
        widget->onSingleLongTapMoveUpdate!(details);
    }
}

void _TextSelectionGestureDetectorStateCls::_handleLongPressEnd(LongPressEndDetails details) {
    if (!_isDoubleTap && widget->onSingleLongTapEnd != nullptr) {
        widget->onSingleLongTapEnd!(details);
    }
    _isDoubleTap = false;
}

void _TextSelectionGestureDetectorStateCls::_doubleTapTimeout() {
    _doubleTapTimer = nullptr;
    _lastTapOffset = nullptr;
}

bool _TextSelectionGestureDetectorStateCls::_isWithinDoubleTapTolerance(Offset secondTapOffset) {
    assert(secondTapOffset != nullptr);
    if (_lastTapOffset == nullptr) {
        return false;
    }
    Offset difference = secondTapOffset - _lastTapOffset!;
    return difference->distance <= kDoubleTapSlop;
}

ClipboardStatusNotifierCls::ClipboardStatusNotifierCls(ClipboardStatus value) {
}

bool ClipboardStatusNotifierCls::disposed() {
    return _disposed;
}

Future<void> ClipboardStatusNotifierCls::update() {
    if (_disposed) {
        return;
    }
    bool hasStrings;
    try {
        hasStrings = await ClipboardCls->hasStrings();
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, "widget library", make<ErrorDescriptionCls>("while checking if the clipboard has strings")));
        if (_disposed || value == ClipboardStatusCls::unknown) {
            return;
        }
        value = ClipboardStatusCls::unknown;
        return;
    };
    ClipboardStatus nextStatus = hasStrings? ClipboardStatusCls::pasteable : ClipboardStatusCls::notPasteable;
    if (_disposed || nextStatus == value) {
        return;
    }
    value = nextStatus;
}

void ClipboardStatusNotifierCls::addListener(VoidCallback listener) {
    if (!hasListeners) {
        WidgetsBindingCls::instance->addObserver(this);
    }
    if (value == ClipboardStatusCls::unknown) {
        update();
    }
    super->addListener(listener);
}

void ClipboardStatusNotifierCls::removeListener(VoidCallback listener) {
    super->removeListener(listener);
    if (!_disposed && !hasListeners) {
        WidgetsBindingCls::instance->removeObserver(this);
    }
}

void ClipboardStatusNotifierCls::didChangeAppLifecycleState(AppLifecycleState state) {
    ;
}

void ClipboardStatusNotifierCls::dispose() {
    WidgetsBindingCls::instance->removeObserver(this);
    _disposed = true;
    super->dispose();
}
