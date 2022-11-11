#include "editable.hpp"
TextSelectionPointCls::TextSelectionPointCls(TextDirection direction, Offset point) {
    {
        assert(point != nullptr);
    }
}

String TextSelectionPointCls::toString() {
    ;
}

bool VerticalCaretMovementRunCls::isValid() {
    if (!_isValid) {
        return false;
    }
    List<LineMetrics> newLineMetrics = _editable->_textPainter->computeLineMetrics();
    if (!identical(newLineMetrics, _lineMetrics)) {
        _isValid = false;
    }
    return _isValid;
}

TextPosition VerticalCaretMovementRunCls::current() {
    assert(isValid());
    return _currentTextPosition;
}

bool VerticalCaretMovementRunCls::moveNext() {
    assert(isValid());
    if (_currentLine + 1 >= _lineMetrics->length()) {
        return false;
    }
    MapEntry<Offset, TextPosition> position = _getTextPositionForLine(_currentLine + 1);
    _currentLine = 1;
    _currentOffset = position->key;
    _currentTextPosition = position->value;
    return true;
}

bool VerticalCaretMovementRunCls::movePrevious() {
    assert(isValid());
    if (_currentLine <= 0) {
        return false;
    }
    MapEntry<Offset, TextPosition> position = _getTextPositionForLine(_currentLine - 1);
    _currentLine = 1;
    _currentOffset = position->key;
    _currentTextPosition = position->value;
    return true;
}

MapEntry<Offset, TextPosition> VerticalCaretMovementRunCls::_getTextPositionForLine(int lineNumber) {
    assert(isValid());
    assert(lineNumber >= 0);
    MapEntry<Offset, TextPosition> cachedPosition = _positionCache[lineNumber];
    if (cachedPosition != nullptr) {
        return cachedPosition;
    }
    assert(lineNumber != _currentLine);
    Offset newOffset = make<OffsetCls>(_currentOffset->dx(), _lineMetrics[lineNumber]->baseline);
    TextPosition closestPosition = _editable->_textPainter->getPositionForOffset(newOffset);
    MapEntry<Offset, TextPosition> position = <Offset, TextPosition>make<MapEntryCls>(newOffset, closestPosition);
    _positionCache[lineNumber] = position;
    return position;
}

RenderEditableCls::RenderEditableCls(Color backgroundCursorColor, List<RenderBox> children, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, EdgeInsets floatingCursorAddedMargin, bool forceLine, RenderEditablePainter foregroundPainter, bool hasFocus, bool ignorePointer, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, RenderEditablePainter painter, Color promptRectColor, TextRange promptRectRange, bool readOnly, TextSelection selection, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis) {
    {
        assert(textAlign != nullptr);
        assert(textDirection != nullptr, __s("RenderEditable created without a textDirection."));
        assert(maxLines == nullptr || maxLines > 0);
        assert(minLines == nullptr || minLines > 0);
        assert(startHandleLayerLink != nullptr);
        assert(endHandleLayerLink != nullptr);
        assert((maxLines == nullptr) || (minLines == nullptr) || (maxLines >= minLines), __s("minLines can't be greater than maxLines"));
        assert(expands != nullptr);
        assert(!expands || (maxLines == nullptr && minLines == nullptr), __s("minLines and maxLines must be null when expands is true."));
        assert(textScaleFactor != nullptr);
        assert(offset != nullptr);
        assert(ignorePointer != nullptr);
        assert(textWidthBasis != nullptr);
        assert(paintCursorAboveText != nullptr);
        assert(obscuringCharacter != nullptr && obscuringCharacter->characters->length == 1);
        assert(obscureText != nullptr);
        assert(textSelectionDelegate != nullptr);
        assert(cursorWidth != nullptr && cursorWidth >= 0.0);
        assert(cursorHeight == nullptr || cursorHeight >= 0.0);
        assert(readOnly != nullptr);
        assert(forceLine != nullptr);
        assert(devicePixelRatio != nullptr);
        assert(selectionHeightStyle != nullptr);
        assert(selectionWidthStyle != nullptr);
        assert(clipBehavior != nullptr);
        _textPainter = make<TextPainterCls>(text, textAlign, textDirection, textScaleFactor, locale, strutStyle, textHeightBehavior, textWidthBasis);
        _showCursor = showCursor or <bool>make<ValueNotifierCls>(false);
        _maxLines = maxLines;
        _minLines = minLines;
        _expands = expands;
        _selection = selection;
        _offset = offset;
        _cursorWidth = cursorWidth;
        _cursorHeight = cursorHeight;
        _paintCursorOnTop = paintCursorAboveText;
        _enableInteractiveSelection = enableInteractiveSelection;
        _devicePixelRatio = devicePixelRatio;
        _startHandleLayerLink = startHandleLayerLink;
        _endHandleLayerLink = endHandleLayerLink;
        _obscuringCharacter = obscuringCharacter;
        _obscureText = obscureText;
        _readOnly = readOnly;
        _forceLine = forceLine;
        _clipBehavior = clipBehavior;
        _hasFocus = hasFocus or false;
    }
    {
        assert(_showCursor != nullptr);
        assert(!_showCursor->value() || cursorColor != nullptr);
        _selectionPainter->highlightColor() = selectionColor;
        _selectionPainter->highlightedRange() = selection;
        _selectionPainter->selectionHeightStyle = selectionHeightStyle;
        _selectionPainter->selectionWidthStyle = selectionWidthStyle;
        _autocorrectHighlightPainter->highlightColor() = promptRectColor;
        _autocorrectHighlightPainter->highlightedRange() = promptRectRange;
        _caretPainter->caretColor() = cursorColor;
        _caretPainter->cursorRadius = cursorRadius;
        _caretPainter->cursorOffset = cursorOffset;
        _caretPainter->backgroundCursorColor = backgroundCursorColor;
        _updateForegroundPainter(foregroundPainter);
        _updatePainter(painter);
        addAll(children);
        _extractPlaceholderSpans(text);
    }
}

void RenderEditableCls::setupParentData(RenderBox child) {
    if (!is<TextParentData>(child->parentData)) {
        child->parentData = make<TextParentDataCls>();
    }
}

void RenderEditableCls::dispose() {
    _foregroundRenderObject?->dispose();
    _foregroundRenderObject = nullptr;
    _backgroundRenderObject?->dispose();
    _backgroundRenderObject = nullptr;
    _clipRectLayer->layer() = nullptr;
    _cachedBuiltInForegroundPainters?->dispose();
    _cachedBuiltInPainters?->dispose();
    _selectionStartInViewport->dispose();
    _selectionEndInViewport->dispose();
    super->dispose();
}

RenderEditablePainter RenderEditableCls::foregroundPainter() {
    return _foregroundPainter;
}

void RenderEditableCls::foregroundPainter(RenderEditablePainter newPainter) {
    if (newPainter == _foregroundPainter) {
        return;
    }
    _updateForegroundPainter(newPainter);
}

RenderEditablePainter RenderEditableCls::painter() {
    return _painter;
}

void RenderEditableCls::painter(RenderEditablePainter newPainter) {
    if (newPainter == _painter) {
        return;
    }
    _updatePainter(newPainter);
}

void RenderEditableCls::debugAssertLayoutUpToDate() {
    assert(_textLayoutLastMaxWidth == constraints->maxWidth && _textLayoutLastMinWidth == constraints->minWidth, __s("Last width ($_textLayoutLastMinWidth, $_textLayoutLastMaxWidth) not the same as max width constraint (${constraints.minWidth}, ${constraints.maxWidth})."));
}

TextHeightBehavior RenderEditableCls::textHeightBehavior() {
    return _textPainter->textHeightBehavior();
}

void RenderEditableCls::textHeightBehavior(TextHeightBehavior value) {
    if (_textPainter->textHeightBehavior() == value) {
        return;
    }
    _textPainter->textHeightBehavior() = value;
    markNeedsTextLayout();
}

TextWidthBasis RenderEditableCls::textWidthBasis() {
    return _textPainter->textWidthBasis();
}

void RenderEditableCls::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textPainter->textWidthBasis() == value) {
        return;
    }
    _textPainter->textWidthBasis() = value;
    markNeedsTextLayout();
}

double RenderEditableCls::devicePixelRatio() {
    return _devicePixelRatio;
}

void RenderEditableCls::devicePixelRatio(double value) {
    if (devicePixelRatio() == value) {
        return;
    }
    _devicePixelRatio = value;
    markNeedsTextLayout();
}

String RenderEditableCls::obscuringCharacter() {
    return _obscuringCharacter;
}

void RenderEditableCls::obscuringCharacter(String value) {
    if (_obscuringCharacter == value) {
        return;
    }
    assert(value != nullptr && value->characters->length == 1);
    _obscuringCharacter = value;
    markNeedsLayout();
}

bool RenderEditableCls::obscureText() {
    return _obscureText;
}

void RenderEditableCls::obscureText(bool value) {
    if (_obscureText == value) {
        return;
    }
    _obscureText = value;
    markNeedsSemanticsUpdate();
}

BoxHeightStyle RenderEditableCls::selectionHeightStyle() {
    return _selectionPainter->selectionHeightStyle();
}

void RenderEditableCls::selectionHeightStyle(BoxHeightStyle value) {
    _selectionPainter->selectionHeightStyle() = value;
}

BoxWidthStyle RenderEditableCls::selectionWidthStyle() {
    return _selectionPainter->selectionWidthStyle();
}

void RenderEditableCls::selectionWidthStyle(BoxWidthStyle value) {
    _selectionPainter->selectionWidthStyle() = value;
}

ValueListenable<bool> RenderEditableCls::selectionStartInViewport() {
    return _selectionStartInViewport;
}

ValueListenable<bool> RenderEditableCls::selectionEndInViewport() {
    return _selectionEndInViewport;
}

TextSelection RenderEditableCls::getLineAtOffset(TextPosition position) {
    debugAssertLayoutUpToDate();
    TextRange line = _textPainter->getLineBoundary(position);
    if (obscureText()) {
        return make<TextSelectionCls>(0, _plainText()->length());
    }
    return make<TextSelectionCls>(line->start, line->end);
}

TextRange RenderEditableCls::getWordBoundary(TextPosition position) {
    return _textPainter->getWordBoundary(position);
}

TextPosition RenderEditableCls::getTextPositionAbove(TextPosition position) {
    double preferredLineHeight = _textPainter->preferredLineHeight();
    double verticalOffset = -0.5 * preferredLineHeight;
    return _getTextPositionVertical(position, verticalOffset);
}

TextPosition RenderEditableCls::getTextPositionBelow(TextPosition position) {
    double preferredLineHeight = _textPainter->preferredLineHeight();
    double verticalOffset = 1.5 * preferredLineHeight;
    return _getTextPositionVertical(position, verticalOffset);
}

void RenderEditableCls::markNeedsPaint() {
    super->markNeedsPaint();
    _foregroundRenderObject?->markNeedsPaint();
    _backgroundRenderObject?->markNeedsPaint();
}

void RenderEditableCls::markNeedsTextLayout() {
    _textLayoutLastMaxWidth = nullptr;
    _textLayoutLastMinWidth = nullptr;
    markNeedsLayout();
}

void RenderEditableCls::systemFontsDidChange() {
    super->systemFontsDidChange();
    _textPainter->markNeedsLayout();
    _textLayoutLastMaxWidth = nullptr;
    _textLayoutLastMinWidth = nullptr;
}

InlineSpan RenderEditableCls::text() {
    return _textPainter->text();
}

void RenderEditableCls::text(InlineSpan value) {
    if (_textPainter->text() == value) {
        return;
    }
    _textPainter->text() = value;
    _cachedPlainText = nullptr;
    _cachedAttributedValue = nullptr;
    _cachedCombinedSemanticsInfos = nullptr;
    _extractPlaceholderSpans(value);
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

TextAlign RenderEditableCls::textAlign() {
    return _textPainter->textAlign();
}

void RenderEditableCls::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textPainter->textAlign() == value) {
        return;
    }
    _textPainter->textAlign() = value;
    markNeedsTextLayout();
}

TextDirection RenderEditableCls::textDirection() {
    return _textPainter->textDirection()!;
}

void RenderEditableCls::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textPainter->textDirection() == value) {
        return;
    }
    _textPainter->textDirection() = value;
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

Locale RenderEditableCls::locale() {
    return _textPainter->locale();
}

void RenderEditableCls::locale(Locale value) {
    if (_textPainter->locale() == value) {
        return;
    }
    _textPainter->locale() = value;
    markNeedsTextLayout();
}

StrutStyle RenderEditableCls::strutStyle() {
    return _textPainter->strutStyle();
}

void RenderEditableCls::strutStyle(StrutStyle value) {
    if (_textPainter->strutStyle() == value) {
        return;
    }
    _textPainter->strutStyle() = value;
    markNeedsTextLayout();
}

Color RenderEditableCls::cursorColor() {
    return _caretPainter->caretColor();
}

void RenderEditableCls::cursorColor(Color value) {
    _caretPainter->caretColor() = value;
}

Color RenderEditableCls::backgroundCursorColor() {
    return _caretPainter->backgroundCursorColor();
}

void RenderEditableCls::backgroundCursorColor(Color value) {
    _caretPainter->backgroundCursorColor() = value;
}

ValueNotifier<bool> RenderEditableCls::showCursor() {
    return _showCursor;
}

void RenderEditableCls::showCursor(ValueNotifier<bool> value) {
    assert(value != nullptr);
    if (_showCursor == value) {
        return;
    }
    if (attached) {
        _showCursor->removeListener(_showHideCursor);
    }
    _showCursor = value;
    if (attached) {
        _showHideCursor();
        _showCursor->addListener(_showHideCursor);
    }
}

bool RenderEditableCls::hasFocus() {
    return _hasFocus;
}

void RenderEditableCls::hasFocus(bool value) {
    assert(value != nullptr);
    if (_hasFocus == value) {
        return;
    }
    _hasFocus = value;
    markNeedsSemanticsUpdate();
}

bool RenderEditableCls::forceLine() {
    return _forceLine;
}

void RenderEditableCls::forceLine(bool value) {
    assert(value != nullptr);
    if (_forceLine == value) {
        return;
    }
    _forceLine = value;
    markNeedsLayout();
}

bool RenderEditableCls::readOnly() {
    return _readOnly;
}

void RenderEditableCls::readOnly(bool value) {
    assert(value != nullptr);
    if (_readOnly == value) {
        return;
    }
    _readOnly = value;
    markNeedsSemanticsUpdate();
}

int RenderEditableCls::maxLines() {
    return _maxLines;
}

void RenderEditableCls::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (maxLines() == value) {
        return;
    }
    _maxLines = value;
    markNeedsTextLayout();
}

int RenderEditableCls::minLines() {
    return _minLines;
}

void RenderEditableCls::minLines(int value) {
    assert(value == nullptr || value > 0);
    if (minLines() == value) {
        return;
    }
    _minLines = value;
    markNeedsTextLayout();
}

bool RenderEditableCls::expands() {
    return _expands;
}

void RenderEditableCls::expands(bool value) {
    assert(value != nullptr);
    if (expands() == value) {
        return;
    }
    _expands = value;
    markNeedsTextLayout();
}

Color RenderEditableCls::selectionColor() {
    return _selectionPainter->highlightColor();
}

void RenderEditableCls::selectionColor(Color value) {
    _selectionPainter->highlightColor() = value;
}

double RenderEditableCls::textScaleFactor() {
    return _textPainter->textScaleFactor();
}

void RenderEditableCls::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textPainter->textScaleFactor() == value) {
        return;
    }
    _textPainter->textScaleFactor() = value;
    markNeedsTextLayout();
}

TextSelection RenderEditableCls::selection() {
    return _selection;
}

void RenderEditableCls::selection(TextSelection value) {
    if (_selection == value) {
        return;
    }
    _selection = value;
    _selectionPainter->highlightedRange() = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

ViewportOffset RenderEditableCls::offset() {
    return _offset;
}

void RenderEditableCls::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (_offset == value) {
        return;
    }
    if (attached) {
        _offset->removeListener(markNeedsPaint);
    }
    _offset = value;
    if (attached) {
        _offset->addListener(markNeedsPaint);
    }
    markNeedsLayout();
}

double RenderEditableCls::cursorWidth() {
    return _cursorWidth;
}

void RenderEditableCls::cursorWidth(double value) {
    if (_cursorWidth == value) {
        return;
    }
    _cursorWidth = value;
    markNeedsLayout();
}

double RenderEditableCls::cursorHeight() {
    return _cursorHeight or preferredLineHeight();
}

void RenderEditableCls::cursorHeight(double value) {
    if (_cursorHeight == value) {
        return;
    }
    _cursorHeight = value;
    markNeedsLayout();
}

bool RenderEditableCls::paintCursorAboveText() {
    return _paintCursorOnTop;
}

void RenderEditableCls::paintCursorAboveText(bool value) {
    if (_paintCursorOnTop == value) {
        return;
    }
    _paintCursorOnTop = value;
    _cachedBuiltInForegroundPainters = nullptr;
    _cachedBuiltInPainters = nullptr;
    _updateForegroundPainter(_foregroundPainter);
    _updatePainter(_painter);
}

Offset RenderEditableCls::cursorOffset() {
    return _caretPainter->cursorOffset();
}

void RenderEditableCls::cursorOffset(Offset value) {
    _caretPainter->cursorOffset() = value;
}

Radius RenderEditableCls::cursorRadius() {
    return _caretPainter->cursorRadius();
}

void RenderEditableCls::cursorRadius(Radius value) {
    _caretPainter->cursorRadius() = value;
}

LayerLink RenderEditableCls::startHandleLayerLink() {
    return _startHandleLayerLink;
}

void RenderEditableCls::startHandleLayerLink(LayerLink value) {
    if (_startHandleLayerLink == value) {
        return;
    }
    _startHandleLayerLink = value;
    markNeedsPaint();
}

LayerLink RenderEditableCls::endHandleLayerLink() {
    return _endHandleLayerLink;
}

void RenderEditableCls::endHandleLayerLink(LayerLink value) {
    if (_endHandleLayerLink == value) {
        return;
    }
    _endHandleLayerLink = value;
    markNeedsPaint();
}

bool RenderEditableCls::enableInteractiveSelection() {
    return _enableInteractiveSelection;
}

void RenderEditableCls::enableInteractiveSelection(bool value) {
    if (_enableInteractiveSelection == value) {
        return;
    }
    _enableInteractiveSelection = value;
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

bool RenderEditableCls::selectionEnabled() {
    return enableInteractiveSelection() or !obscureText();
}

Color RenderEditableCls::promptRectColor() {
    return _autocorrectHighlightPainter->highlightColor();
}

void RenderEditableCls::promptRectColor(Color newValue) {
    _autocorrectHighlightPainter->highlightColor() = newValue;
}

void RenderEditableCls::setPromptRectRange(TextRange newRange) {
    _autocorrectHighlightPainter->highlightedRange() = newRange;
}

double RenderEditableCls::maxScrollExtent() {
    return _maxScrollExtent;
}

Clip RenderEditableCls::clipBehavior() {
    return _clipBehavior;
}

void RenderEditableCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

List<Rect> RenderEditableCls::getBoxesForSelection(TextSelection selection) {
    _computeTextMetricsIfNeeded();
    return _textPainter->getBoxesForSelection(selection)->map([=] (TextBox textBox)     {
        textBox->toRect()->shift(_paintOffset());
    })->toList();
}

void RenderEditableCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    _semanticsInfo = _textPainter->text()!->getSemanticsInformation();
    if (_semanticsInfo!->any([=] (InlineSpanSemanticsInformation info)     {
        info->recognizer != nullptr;
    }) && defaultTargetPlatform != TargetPlatformCls::macOS) {
        assert(readOnly() && !obscureText());
            auto _c1 = config;    _c1.isSemanticBoundary = auto _c2 = true;    _c2.explicitChildNodes = true;    _c2;_c1;
        return;
    }
    if (_cachedAttributedValue == nullptr) {
        if (obscureText()) {
            _cachedAttributedValue = make<AttributedStringCls>(obscuringCharacter() * _plainText()->length());
        } else {
            StringBuffer buffer = make<StringBufferCls>();
            int offset = 0;
            List<StringAttribute> attributes = makeList();
            for (InlineSpanSemanticsInformation info : _semanticsInfo!) {
                String label = info->semanticsLabel or info->text;
                for (StringAttribute infoAttribute : info->stringAttributes) {
                    TextRange originalRange = infoAttribute->range;
                    attributes->add(infoAttribute->copy(make<TextRangeCls>(offset + originalRange->start, offset + originalRange->end)));
                }
                buffer->write(label);
                offset = label->length();
            }
            _cachedAttributedValue = make<AttributedStringCls>(buffer->toString()attributes);
        }
    }
    auto _c3 = config;_c3.attributedValue = auto _c4 = _cachedAttributedValue!;_c4.isObscured = auto _c5 = obscureText();_c5.isMultiline = auto _c6 = _isMultiline();_c6.textDirection() = auto _c7 = textDirection();_c7.isFocused = auto _c8 = hasFocus();_c8.isTextField = auto _c9 = true;_c9.isReadOnly = readOnly();_c9;_c8;_c7;_c6;_c5;_c4;_c3;
    if (hasFocus() && selectionEnabled()) {
        config->onSetSelection() = _handleSetSelection;
    }
    if (hasFocus() && !readOnly()) {
        config->onSetText() = _handleSetText;
    }
    if (selectionEnabled() && (selection()?->isValid or false)) {
        config->textSelection() = selection();
        if (_textPainter->getOffsetBefore(selection()!->extentOffset) != nullptr) {
                    auto _c10 = config;        _c10.onMoveCursorBackwardByWord = auto _c11 = _handleMoveCursorBackwardByWord;        _c11.onMoveCursorBackwardByCharacter = _handleMoveCursorBackwardByCharacter;        _c11;_c10;
        }
        if (_textPainter->getOffsetAfter(selection()!->extentOffset) != nullptr) {
                    auto _c12 = config;        _c12.onMoveCursorForwardByWord = auto _c13 = _handleMoveCursorForwardByWord;        _c13.onMoveCursorForwardByCharacter = _handleMoveCursorForwardByCharacter;        _c13;_c12;
        }
    }
}

void RenderEditableCls::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    assert(_semanticsInfo != nullptr && _semanticsInfo!->isNotEmpty);
    List<SemanticsNode> newChildren = makeList();
    TextDirection currentDirection = textDirection();
    Rect currentRect;
    double ordinal = 0.0;
    int start = 0;
    int placeholderIndex = 0;
    int childIndex = 0;
    RenderBox child = firstChild;
    LinkedHashMap<Key, SemanticsNode> newChildCache = <Key, SemanticsNode>make<LinkedHashMapCls>();
    _cachedCombinedSemanticsInfos = combineSemanticsInfo(_semanticsInfo!);
    for (InlineSpanSemanticsInformation info : _cachedCombinedSemanticsInfos!) {
        TextSelection selection = make<TextSelectionCls>(start, start + info->text->length);
        start = info->text->length;
        if (info->isPlaceholder) {
            while (children->length() > childIndex && children->elementAt(childIndex)->isTagged(make<PlaceholderSpanIndexSemanticsTagCls>(placeholderIndex))) {
                SemanticsNode childNode = children->elementAt(childIndex);
                TextParentData parentData = as<TextParentData>(child!->parentData!);
                assert(parentData->scale != nullptr);
                childNode->rect() = RectCls->fromLTWH(childNode->rect()->left, childNode->rect()->top, childNode->rect()->width() * parentData->scale!, childNode->rect()->height() * parentData->scale!);
                newChildren->add(childNode);
                childIndex = 1;
            }
            child = childAfter(child!);
            placeholderIndex = 1;
        } else {
            TextDirection initialDirection = currentDirection;
            List<TextBox> rects = _textPainter->getBoxesForSelection(selection);
            if (rects->isEmpty) {
                continue;
            }
            Rect rect = rects->first->toRect();
            currentDirection = rects->first->direction;
            for (TextBox textBox : rects->skip(1)) {
                rect = rect->expandToInclude(textBox->toRect());
                currentDirection = textBox->direction;
            }
            rect = RectCls->fromLTWH(math->max(0.0, rect->left), math->max(0.0, rect->top), math->min(rect->width(), constraints->maxWidth), math->min(rect->height(), constraints->maxHeight));
            currentRect = RectCls->fromLTRB(rect->left->floorToDouble() - 4.0, rect->top->floorToDouble() - 4.0, rect->right->ceilToDouble() + 4.0, rect->bottom->ceilToDouble() + 4.0);
                    auto _c1 = make<SemanticsConfigurationCls>();        _c1.sortKey = auto _c2 = make<OrdinalSortKeyCls>(ordinal++);        _c2.textDirection() = auto _c3 = initialDirection;        _c3.attributedLabel = make<AttributedStringCls>(info->semanticsLabel or info->textinfo->stringAttributes);        _c3;        _c2;SemanticsConfiguration configuration = _c1;
            GestureRecognizer recognizer = info->recognizer;
            if (recognizer != nullptr) {
                if (is<TapGestureRecognizer>(recognizer)) {
                    if (as<TapGestureRecognizerCls>(recognizer)->onTap != nullptr) {
                        configuration->onTap() = recognizer->onTap;
                        configuration->isLink() = true;
                    }
                } else                 {
                    if (is<DoubleTapGestureRecognizer>(recognizer)) {
                    if (as<DoubleTapGestureRecognizerCls>(recognizer)->onDoubleTap != nullptr) {
                        configuration->onTap() = recognizer->onDoubleTap;
                        configuration->isLink() = true;
                    }
                } else                 {
                    if (is<LongPressGestureRecognizer>(recognizer)) {
                    if (as<LongPressGestureRecognizerCls>(recognizer)->onLongPress != nullptr) {
                        configuration->onLongPress() = recognizer->onLongPress;
                    }
                } else {
                    assert(false, __s("${recognizer.runtimeType} is not supported."));
                }
;
                };
                }            }
            if (node->parentPaintClipRect != nullptr) {
                Rect paintRect = node->parentPaintClipRect!->intersect(currentRect);
                configuration->isHidden() = paintRect->isEmpty() && !currentRect->isEmpty();
            }
            SemanticsNode newChild;
            if (_cachedChildNodes?->isNotEmpty or false) {
                newChild = _cachedChildNodes!->remove(_cachedChildNodes!->keys->first)!;
            } else {
                UniqueKey key = make<UniqueKeyCls>();
                newChild = make<SemanticsNodeCls>(key, _createShowOnScreenFor(key));
            }
                    auto _c4 = newChild;        _c4.auto _c5 = updateWith(configuration);        _c5.rect = currentRect;        _c5;_c4;
            newChildCache[newChild->key!] = newChild;
            newChildren->add(newChild);
        }
    }
    _cachedChildNodes = newChildCache;
    node->updateWith(config, newChildren);
}

void RenderEditableCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _foregroundRenderObject?->attach(owner);
    _backgroundRenderObject?->attach(owner);
    auto _c1 = make<TapGestureRecognizerCls>(this);_c1.onTapDown = auto _c2 = _handleTapDown;_c2.onTap = _handleTap;_c2;_tap = _c1;
    auto _c3 = make<LongPressGestureRecognizerCls>(this);_c3.onLongPress = _handleLongPress;_longPress = _c3;
    _offset->addListener(markNeedsPaint);
    _showHideCursor();
    _showCursor->addListener(_showHideCursor);
}

void RenderEditableCls::detach() {
    _tap->dispose();
    _longPress->dispose();
    _offset->removeListener(markNeedsPaint);
    _showCursor->removeListener(_showHideCursor);
    super->detach();
    _foregroundRenderObject?->detach();
    _backgroundRenderObject?->detach();
}

void RenderEditableCls::redepthChildren() {
    RenderObject foregroundChild = _foregroundRenderObject;
    RenderObject backgroundChild = _backgroundRenderObject;
    if (foregroundChild != nullptr) {
        redepthChild(foregroundChild);
    }
    if (backgroundChild != nullptr) {
        redepthChild(backgroundChild);
    }
    super->redepthChildren();
}

void RenderEditableCls::visitChildren(RenderObjectVisitor visitor) {
    RenderObject foregroundChild = _foregroundRenderObject;
    RenderObject backgroundChild = _backgroundRenderObject;
    if (foregroundChild != nullptr) {
        visitor(foregroundChild);
    }
    if (backgroundChild != nullptr) {
        visitor(backgroundChild);
    }
    super->visitChildren(visitor);
}

List<TextSelectionPoint> RenderEditableCls::getEndpointsForSelection(TextSelection selection) {
    _computeTextMetricsIfNeeded();
    Offset paintOffset = _paintOffset();
    List<TextBox> boxes = selection->isCollapsed? makeList() : _textPainter->getBoxesForSelection(selectionselectionHeightStyle(), selectionWidthStyle());
    if (boxes->isEmpty) {
        Offset caretOffset = _textPainter->getOffsetForCaret(selection->extent(), _caretPrototype);
        Offset start = make<OffsetCls>(0.0, preferredLineHeight()) + caretOffset + paintOffset;
        return makeList(ArrayItem);
    } else {
        Offset start = make<OffsetCls>(clampDouble(boxes->first->start, 0, _textPainter->size()->width()), boxes->first->bottom) + paintOffset;
        Offset end = make<OffsetCls>(clampDouble(boxes->last->end, 0, _textPainter->size()->width()), boxes->last->bottom) + paintOffset;
        return makeList(ArrayItem, ArrayItem);
    }
}

Rect RenderEditableCls::getRectForComposingRange(TextRange range) {
    if (!range->isValid() || range->isCollapsed()) {
        return nullptr;
    }
    _computeTextMetricsIfNeeded();
    List<TextBox> boxes = _textPainter->getBoxesForSelection(make<TextSelectionCls>(range->start, range->end)selectionHeightStyle(), selectionWidthStyle());
    return boxes->fold(nullptr, [=] (Rect accum,TextBox incoming)     {
        accum?->expandToInclude(incoming->toRect()) or incoming->toRect();
    })?->shift(_paintOffset());
}

TextPosition RenderEditableCls::getPositionForPoint(Offset globalPosition) {
    _computeTextMetricsIfNeeded();
    globalPosition = -_paintOffset();
    return _textPainter->getPositionForOffset(globalToLocal(globalPosition));
}

Rect RenderEditableCls::getLocalRectForCaret(TextPosition caretPosition) {
    _computeTextMetricsIfNeeded();
    Offset caretOffset = _textPainter->getOffsetForCaret(caretPosition, _caretPrototype);
    Rect rect = RectCls->fromLTWH(0.0, 0.0, cursorWidth(), cursorHeight())->shift(caretOffset + _paintOffset() + cursorOffset());
    return rect->shift(_snapToPhysicalPixel(rect->topLeft()));
}

double RenderEditableCls::computeMinIntrinsicWidth(double height) {
    _layoutText();
    return _textPainter->minIntrinsicWidth();
}

double RenderEditableCls::computeMaxIntrinsicWidth(double height) {
    _layoutText();
    return _textPainter->maxIntrinsicWidth() + _caretMargin();
}

double RenderEditableCls::preferredLineHeight() {
    return _textPainter->preferredLineHeight();
}

double RenderEditableCls::computeMinIntrinsicHeight(double width) {
    return _preferredHeight(width);
}

double RenderEditableCls::computeMaxIntrinsicHeight(double width) {
    return _preferredHeight(width);
}

double RenderEditableCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    _computeTextMetricsIfNeeded();
    return _textPainter->computeDistanceToActualBaseline(baseline);
}

bool RenderEditableCls::hitTestSelf(Offset position) {
    return true;
}

bool RenderEditableCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    bool hitText = false;
    Offset effectivePosition = position - _paintOffset();
    TextPosition textPosition = _textPainter->getPositionForOffset(effectivePosition);
    InlineSpan span = _textPainter->text()!->getSpanForPosition(textPosition);
    if (span != nullptr && is<HitTestTarget>(span)) {
        result->add(make<HitTestEntryCls>(as<HitTestTarget>(span)));
        hitText = true;
    }
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
            auto _c1 = Matrix4Cls->translationValues(textParentData->offset->dx, textParentData->offset->dy, 0.0);    _c1.scale(textParentData->scale, textParentData->scale, textParentData->scale);Matrix4 transform = _c1;
        bool isHit = result->addWithPaintTransform(transform, position, [=] (BoxHitTestResult result,Offset transformed) {
    assert([=] () {
        Offset manualPosition = (position - textParentData->offset) / textParentData->scale!;
        return (transformed->dx - manualPosition->dx())->abs() < precisionErrorTolerance && (transformed->dy - manualPosition->dy())->abs() < precisionErrorTolerance;
    }());
    return child!->hitTest(resulttransformed);
});
        if (isHit) {
            return true;
        }
        child = childAfter(child);
        childIndex = 1;
    }
    return hitText;
}

void RenderEditableCls::handleEvent(BoxHitTestEntry entry, PointerEvent event) {
    assert(debugHandleEvent(event, entry));
    if (is<PointerDownEvent>(event)) {
        assert(!debugNeedsLayout);
        if (!ignorePointer) {
            _tap->addPointer(event);
            _longPress->addPointer(event);
        }
    }
}

Offset RenderEditableCls::lastSecondaryTapDownPosition() {
    return _lastSecondaryTapDownPosition;
}

void RenderEditableCls::handleSecondaryTapDown(TapDownDetails details) {
    _lastTapDownPosition = details->globalPosition;
    _lastSecondaryTapDownPosition = details->globalPosition;
}

void RenderEditableCls::handleTapDown(TapDownDetails details) {
    _lastTapDownPosition = details->globalPosition;
}

void RenderEditableCls::handleTap() {
    selectPosition(SelectionChangedCauseCls::tap);
}

void RenderEditableCls::handleDoubleTap() {
    selectWord(SelectionChangedCauseCls::doubleTap);
}

void RenderEditableCls::handleLongPress() {
    selectWord(SelectionChangedCauseCls::longPress);
}

void RenderEditableCls::selectPosition(SelectionChangedCause cause) {
    selectPositionAt(_lastTapDownPosition!, cause);
}

void RenderEditableCls::selectPositionAt(SelectionChangedCause cause, Offset from, Offset to) {
    assert(cause != nullptr);
    assert(from != nullptr);
    _layoutText(constraints->minWidth, constraints->maxWidth);
    TextPosition fromPosition = _textPainter->getPositionForOffset(globalToLocal(from - _paintOffset()));
    TextPosition toPosition = to == nullptr? nullptr : _textPainter->getPositionForOffset(globalToLocal(to - _paintOffset()));
    int baseOffset = fromPosition->offset;
    int extentOffset = toPosition?->offset or fromPosition->offset;
    TextSelection newSelection = make<TextSelectionCls>(baseOffset, extentOffset, fromPosition->affinity);
    _setSelection(newSelection, cause);
}

void RenderEditableCls::selectWord(SelectionChangedCause cause) {
    selectWordsInRange(_lastTapDownPosition!, cause);
}

void RenderEditableCls::selectWordsInRange(SelectionChangedCause cause, Offset from, Offset to) {
    assert(cause != nullptr);
    assert(from != nullptr);
    _computeTextMetricsIfNeeded();
    TextPosition firstPosition = _textPainter->getPositionForOffset(globalToLocal(from - _paintOffset()));
    TextSelection firstWord = _getWordAtOffset(firstPosition);
    TextSelection lastWord = to == nullptr? firstWord : _getWordAtOffset(_textPainter->getPositionForOffset(globalToLocal(to - _paintOffset())));
    _setSelection(make<TextSelectionCls>(firstWord->base()->offset, lastWord->extent()->offset, firstWord->affinity), cause);
}

void RenderEditableCls::selectWordEdge(SelectionChangedCause cause) {
    assert(cause != nullptr);
    _computeTextMetricsIfNeeded();
    assert(_lastTapDownPosition != nullptr);
    TextPosition position = _textPainter->getPositionForOffset(globalToLocal(_lastTapDownPosition! - _paintOffset()));
    TextRange word = _textPainter->getWordBoundary(position);
    TextSelection newSelection;
    if (position->offset - word->start <= 1) {
        newSelection = TextSelectionCls->collapsed(word->start);
    } else {
        newSelection = TextSelectionCls->collapsed(word->end, TextAffinityCls::upstream);
    }
    _setSelection(newSelection, cause);
}

Size RenderEditableCls::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeDryLayout()) {
        assert(debugCannotComputeDryLayout(__s("Dry layout not available for alignments that require baseline.")));
        return SizeCls::zero;
    }
    _textPainter->setPlaceholderDimensions(_layoutChildren(constraintstrue));
    _layoutText(constraints->minWidth, constraints->maxWidth);
    double width = forceLine()? constraints->maxWidth : constraints->constrainWidth(_textPainter->size()->width() + _caretMargin());
    return make<SizeCls>(width, constraints->constrainHeight(_preferredHeight(constraints->maxWidth)));
}

void RenderEditableCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    _placeholderDimensions = _layoutChildren(constraints);
    _textPainter->setPlaceholderDimensions(_placeholderDimensions);
    _computeTextMetricsIfNeeded();
    _setParentData();
    _computeCaretPrototype();
    Size textPainterSize = _textPainter->size();
    double width = forceLine()? constraints->maxWidth : constraints->constrainWidth(_textPainter->size()->width() + _caretMargin());
    size = make<SizeCls>(width, constraints->constrainHeight(_preferredHeight(constraints->maxWidth)));
    Size contentSize = make<SizeCls>(textPainterSize->width + _caretMargin(), textPainterSize->height());
    BoxConstraints painterConstraints = BoxConstraintsCls->tight(contentSize);
    _foregroundRenderObject?->layout(painterConstraints);
    _backgroundRenderObject?->layout(painterConstraints);
    _maxScrollExtent = _getMaxScrollExtent(contentSize);
    offset()->applyViewportDimension(_viewportExtent());
    offset()->applyContentDimensions(0.0, _maxScrollExtent);
}

Offset RenderEditableCls::calculateBoundedFloatingCursorOffset(Offset rawCursorOffset) {
    Offset deltaPosition = OffsetCls::zero;
    double topBound = -floatingCursorAddedMargin->top;
    double bottomBound = _textPainter->height() - preferredLineHeight() + floatingCursorAddedMargin->bottom;
    double leftBound = -floatingCursorAddedMargin->left;
    double rightBound = _textPainter->width() + floatingCursorAddedMargin->right;
    if (_previousOffset != nullptr) {
        deltaPosition = rawCursorOffset - _previousOffset!;
    }
    if (_resetOriginOnLeft && deltaPosition->dx() > 0) {
        _relativeOrigin = make<OffsetCls>(rawCursorOffset->dx() - leftBound, _relativeOrigin->dy());
        _resetOriginOnLeft = false;
    } else     {
        if (_resetOriginOnRight && deltaPosition->dx() < 0) {
        _relativeOrigin = make<OffsetCls>(rawCursorOffset->dx() - rightBound, _relativeOrigin->dy());
        _resetOriginOnRight = false;
    }
;
    }    if (_resetOriginOnTop && deltaPosition->dy() > 0) {
        _relativeOrigin = make<OffsetCls>(_relativeOrigin->dx(), rawCursorOffset->dy() - topBound);
        _resetOriginOnTop = false;
    } else     {
        if (_resetOriginOnBottom && deltaPosition->dy() < 0) {
        _relativeOrigin = make<OffsetCls>(_relativeOrigin->dx(), rawCursorOffset->dy() - bottomBound);
        _resetOriginOnBottom = false;
    }
;
    }    double currentX = rawCursorOffset->dx() - _relativeOrigin->dx();
    double currentY = rawCursorOffset->dy() - _relativeOrigin->dy();
    double adjustedX = math->min(math->max(currentX, leftBound), rightBound);
    double adjustedY = math->min(math->max(currentY, topBound), bottomBound);
    Offset adjustedOffset = make<OffsetCls>(adjustedX, adjustedY);
    if ( < leftBound && deltaPosition->dx() < 0) {
        _resetOriginOnLeft = true;
    } else     {
        if (currentX > rightBound && deltaPosition->dx() > 0) {
        _resetOriginOnRight = true;
    }
;
    }    if ( < topBound && deltaPosition->dy() < 0) {
        _resetOriginOnTop = true;
    } else     {
        if (currentY > bottomBound && deltaPosition->dy() > 0) {
        _resetOriginOnBottom = true;
    }
;
    }    _previousOffset = rawCursorOffset;
    return adjustedOffset;
}

void RenderEditableCls::setFloatingCursor(Offset boundedOffset, TextPosition lastTextPosition, double resetLerpValue, FloatingCursorDragState state) {
    assert(state != nullptr);
    assert(boundedOffset != nullptr);
    assert(lastTextPosition != nullptr);
    if (state == FloatingCursorDragStateCls::StartCls) {
        _relativeOrigin = OffsetCls::zero;
        _previousOffset = nullptr;
        _resetOriginOnBottom = false;
        _resetOriginOnTop = false;
        _resetOriginOnRight = false;
        _resetOriginOnBottom = false;
    }
    _floatingCursorOn = state != FloatingCursorDragStateCls::EndCls;
    _resetFloatingCursorAnimationValue = resetLerpValue;
    if (_floatingCursorOn) {
        _floatingCursorTextPosition = lastTextPosition;
        double animationValue = _resetFloatingCursorAnimationValue;
        EdgeInsets sizeAdjustment = animationValue != nullptr? EdgeInsetsCls->lerp(_kFloatingCaretSizeIncrease, EdgeInsetsCls::zero, animationValue)! : _kFloatingCaretSizeIncrease;
        _caretPainter->floatingCursorRect() = sizeAdjustment->inflateRect(_caretPrototype)->shift(boundedOffset);
    } else {
        _caretPainter->floatingCursorRect() = nullptr;
    }
    _caretPainter->showRegularCaret = _resetFloatingCursorAnimationValue == nullptr;
}

VerticalCaretMovementRun RenderEditableCls::startVerticalCaretMovement(TextPosition startPosition) {
    List<LineMetrics> metrics = _textPainter->computeLineMetrics();
    MapEntry<int, Offset> currentLine = _lineNumberFor(startPosition, metrics);
    return VerticalCaretMovementRunCls->_(this, metrics, startPosition, currentLine->key, currentLine->value);
}

void RenderEditableCls::paint(PaintingContext context, Offset offset) {
    _computeTextMetricsIfNeeded();
    if (_hasVisualOverflow() && clipBehavior() != ClipCls::none) {
        _clipRectLayer->layer() = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, _paintContentsclipBehavior(), _clipRectLayer->layer());
    } else {
        _clipRectLayer->layer() = nullptr;
        _paintContents(context, offset);
    }
    if (selection()!->isValid) {
        _paintHandleLayers(context, getEndpointsForSelection(selection()!));
    }
}

Rect RenderEditableCls::describeApproximatePaintClip(RenderObject child) {
    ;
}

void RenderEditableCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<ColorPropertyCls>(__s("cursorColor"), cursorColor()));
    properties->add(<ValueNotifier<bool>>make<DiagnosticsPropertyCls>(__s("showCursor"), showCursor()));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLines()));
    properties->add(make<IntPropertyCls>(__s("minLines"), minLines()));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("expands"), expands()false));
    properties->add(make<ColorPropertyCls>(__s("selectionColor"), selectionColor()));
    properties->add(make<DoublePropertyCls>(__s("textScaleFactor"), textScaleFactor()));
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), locale()nullptr));
    properties->add(<TextSelection>make<DiagnosticsPropertyCls>(__s("selection"), selection()));
    properties->add(<ViewportOffset>make<DiagnosticsPropertyCls>(__s("offset"), offset()));
}

List<DiagnosticsNode> RenderEditableCls::debugDescribeChildren() {
    List<DiagnosticsNode> list1 = make<ListCls<>>();if (text() != nullptr) {    list1.add(ArrayItem);}return list1;
}

void RenderEditableCls::_updateForegroundPainter(RenderEditablePainter newPainter) {
    _CompositeRenderEditablePainter effectivePainter = newPainter == nullptr? _builtInForegroundPainters() : make<_CompositeRenderEditablePainterCls>(makeList(ArrayItem, ArrayItem));
    if (_foregroundRenderObject == nullptr) {
        _RenderEditableCustomPaint foregroundRenderObject = make<_RenderEditableCustomPaintCls>(effectivePainter);
        adoptChild(foregroundRenderObject);
        _foregroundRenderObject = foregroundRenderObject;
    } else {
        _foregroundRenderObject?->painter() = effectivePainter;
    }
    _foregroundPainter = newPainter;
}

void RenderEditableCls::_extractPlaceholderSpans(InlineSpan span) {
    _placeholderSpans = makeList();
    span?->visitChildren([=] (InlineSpan span) {
        if (is<PlaceholderSpan>(span)) {
            _placeholderSpans->add(as<PlaceholderSpanCls>(span));
        }
        return true;
    });
}

void RenderEditableCls::_updatePainter(RenderEditablePainter newPainter) {
    _CompositeRenderEditablePainter effectivePainter = newPainter == nullptr? _builtInPainters() : make<_CompositeRenderEditablePainterCls>(makeList(ArrayItem, ArrayItem));
    if (_backgroundRenderObject == nullptr) {
        _RenderEditableCustomPaint backgroundRenderObject = make<_RenderEditableCustomPaintCls>(effectivePainter);
        adoptChild(backgroundRenderObject);
        _backgroundRenderObject = backgroundRenderObject;
    } else {
        _backgroundRenderObject?->painter() = effectivePainter;
    }
    _painter = newPainter;
}

_CompositeRenderEditablePainter RenderEditableCls::_builtInForegroundPainters() {
    return _cachedBuiltInForegroundPainters ??= _createBuiltInForegroundPainters();
}

_CompositeRenderEditablePainter RenderEditableCls::_createBuiltInForegroundPainters() {
    List<RenderEditablePainter> list1 = make<ListCls<>>();if (paintCursorAboveText()) {    list1.add(ArrayItem);}return make<_CompositeRenderEditablePainterCls>(list1);
}

_CompositeRenderEditablePainter RenderEditableCls::_builtInPainters() {
    return _cachedBuiltInPainters ??= _createBuiltInPainters();
}

_CompositeRenderEditablePainter RenderEditableCls::_createBuiltInPainters() {
    List<RenderEditablePainter> list1 = make<ListCls<>>();list1.add(ArrayItem);list1.add(ArrayItem);if (!paintCursorAboveText()) {    list1.add(ArrayItem);}return make<_CompositeRenderEditablePainterCls>(list1);
}

void RenderEditableCls::_onCaretChanged(Rect caretRect) {
    if (_lastCaretRect != caretRect) {
        onCaretChanged?->call(caretRect);
    }
    _lastCaretRect = onCaretChanged == nullptr? nullptr : caretRect;
}

TextPosition RenderEditableCls::_getTextPositionVertical(TextPosition position, double verticalOffset) {
    Offset caretOffset = _textPainter->getOffsetForCaret(position, _caretPrototype);
    Offset caretOffsetTranslated = caretOffset->translate(0.0, verticalOffset);
    return _textPainter->getPositionForOffset(caretOffsetTranslated);
}

void RenderEditableCls::_updateSelectionExtentsVisibility(Offset effectiveOffset) {
    assert(selection() != nullptr);
    Rect visibleRegion = OffsetCls::zero & size;
    Offset startOffset = _textPainter->getOffsetForCaret(make<TextPositionCls>(selection()!->start, selection()!->affinity), _caretPrototype);
    double visibleRegionSlop = 0.5;
    _selectionStartInViewport->value() = visibleRegion->inflate(visibleRegionSlop)->contains(startOffset + effectiveOffset);
    Offset endOffset = _textPainter->getOffsetForCaret(make<TextPositionCls>(selection()!->end, selection()!->affinity), _caretPrototype);
    _selectionEndInViewport->value() = visibleRegion->inflate(visibleRegionSlop)->contains(endOffset + effectiveOffset);
}

void RenderEditableCls::_setTextEditingValue(SelectionChangedCause cause, TextEditingValue newValue) {
    textSelectionDelegate->userUpdateTextEditingValue(newValue, cause);
}

void RenderEditableCls::_setSelection(SelectionChangedCause cause, TextSelection nextSelection) {
    if (nextSelection->isValid) {
        int textLength = textSelectionDelegate->textEditingValue()->text->length();
        nextSelection = nextSelection->copyWith(math->min(nextSelection->baseOffset, textLength), math->min(nextSelection->extentOffset, textLength));
    }
    _setTextEditingValue(textSelectionDelegate->textEditingValue()->copyWith(nextSelection), cause);
}

String RenderEditableCls::_plainText() {
    _cachedPlainText = _textPainter->text()!->toPlainText(false);
    return _cachedPlainText!;
}

void RenderEditableCls::_showHideCursor() {
    _caretPainter->shouldPaint() = showCursor()->value();
}

double RenderEditableCls::_caretMargin() {
    return _kCaretGap + cursorWidth();
}

void RenderEditableCls::_handleSetText(String text) {
    textSelectionDelegate->userUpdateTextEditingValue(make<TextEditingValueCls>(text, TextSelectionCls->collapsed(text->length())), SelectionChangedCauseCls::keyboard);
}

VoidCallback RenderEditableCls::_createShowOnScreenFor(Key key) {
    return [=] () {
        SemanticsNode node = _cachedChildNodes![key]!;
        showOnScreen(this, node->rect());
    };
}

void RenderEditableCls::_handleSetSelection(TextSelection selection) {
    _setSelection(selection, SelectionChangedCauseCls::keyboard);
}

void RenderEditableCls::_handleMoveCursorForwardByCharacter(bool extendSelection) {
    assert(selection() != nullptr);
    int extentOffset = _textPainter->getOffsetAfter(selection()!->extentOffset);
    if (extentOffset == nullptr) {
        return;
    }
    int baseOffset = !extendSelection? extentOffset : selection()!->baseOffset;
    _setSelection(make<TextSelectionCls>(baseOffset, extentOffset), SelectionChangedCauseCls::keyboard);
}

void RenderEditableCls::_handleMoveCursorBackwardByCharacter(bool extendSelection) {
    assert(selection() != nullptr);
    int extentOffset = _textPainter->getOffsetBefore(selection()!->extentOffset);
    if (extentOffset == nullptr) {
        return;
    }
    int baseOffset = !extendSelection? extentOffset : selection()!->baseOffset;
    _setSelection(make<TextSelectionCls>(baseOffset, extentOffset), SelectionChangedCauseCls::keyboard);
}

void RenderEditableCls::_handleMoveCursorForwardByWord(bool extendSelection) {
    assert(selection() != nullptr);
    TextRange currentWord = _textPainter->getWordBoundary(selection()!->extent());
    TextRange nextWord = _getNextWord(currentWord->end);
    if (nextWord == nullptr) {
        return;
    }
    int baseOffset = extendSelection? selection()!->baseOffset : nextWord->start;
    _setSelection(make<TextSelectionCls>(baseOffset, nextWord->start), SelectionChangedCauseCls::keyboard);
}

void RenderEditableCls::_handleMoveCursorBackwardByWord(bool extendSelection) {
    assert(selection() != nullptr);
    TextRange currentWord = _textPainter->getWordBoundary(selection()!->extent());
    TextRange previousWord = _getPreviousWord(currentWord->start - 1);
    if (previousWord == nullptr) {
        return;
    }
    int baseOffset = extendSelection? selection()!->baseOffset : previousWord->start;
    _setSelection(make<TextSelectionCls>(baseOffset, previousWord->start), SelectionChangedCauseCls::keyboard);
}

TextRange RenderEditableCls::_getNextWord(int offset) {
    while (true) {
        TextRange range = _textPainter->getWordBoundary(make<TextPositionCls>(offset));
        if (range == nullptr || !range->isValid() || range->isCollapsed()) {
            return nullptr;
        }
        if (!_onlyWhitespace(range)) {
            return range;
        }
        offset = range->end;
    }
}

TextRange RenderEditableCls::_getPreviousWord(int offset) {
    while (offset >= 0) {
        TextRange range = _textPainter->getWordBoundary(make<TextPositionCls>(offset));
        if (range == nullptr || !range->isValid() || range->isCollapsed()) {
            return nullptr;
        }
        if (!_onlyWhitespace(range)) {
            return range;
        }
        offset = range->start - 1;
    }
    return nullptr;
}

bool RenderEditableCls::_onlyWhitespace(TextRange range) {
    for (;  < range->end; i++) {
        int codeUnit = text()!->codeUnitAt(i)!;
        if (!TextLayoutMetricsCls->isWhitespace(codeUnit)) {
            return false;
        }
    }
    return true;
}

bool RenderEditableCls::_isMultiline() {
    return maxLines() != 1;
}

Axis RenderEditableCls::_viewportAxis() {
    return _isMultiline()? AxisCls::vertical : AxisCls::horizontal;
}

Offset RenderEditableCls::_paintOffset() {
    ;
}

double RenderEditableCls::_viewportExtent() {
    assert(hasSize);
    ;
}

double RenderEditableCls::_getMaxScrollExtent(Size contentSize) {
    assert(hasSize);
    ;
}

bool RenderEditableCls::_hasVisualOverflow() {
    return _maxScrollExtent > 0 || _paintOffset() != OffsetCls::zero;
}

double RenderEditableCls::_preferredHeight(double width) {
    bool lockedMax = maxLines() != nullptr && minLines() == nullptr;
    bool lockedBoth = minLines() != nullptr && minLines() == maxLines();
    bool singleLine = maxLines() == 1;
    if (singleLine || lockedMax || lockedBoth) {
        return preferredLineHeight() * maxLines()!;
    }
    bool minLimited = minLines() != nullptr && minLines()! > 1;
    bool maxLimited = maxLines() != nullptr;
    if (minLimited || maxLimited) {
        _layoutText(width);
        if (minLimited && _textPainter->height() < preferredLineHeight() * minLines()!) {
            return preferredLineHeight() * minLines()!;
        }
        if (maxLimited && _textPainter->height() > preferredLineHeight() * maxLines()!) {
            return preferredLineHeight() * maxLines()!;
        }
    }
    if (width == double->infinity) {
        String text = _plainText();
        int lines = 1;
        for (;  < text->length(); index = 1) {
            if (text->codeUnitAt(index) == 0x0A) {
                lines = 1;
            }
        }
        return preferredLineHeight() * lines;
    }
    _layoutText(width);
    return math->max(preferredLineHeight(), _textPainter->height());
}

void RenderEditableCls::_handleTapDown(TapDownDetails details) {
    assert(!ignorePointer);
    handleTapDown(details);
}

void RenderEditableCls::_handleTap() {
    assert(!ignorePointer);
    handleTap();
}

void RenderEditableCls::_handleLongPress() {
    assert(!ignorePointer);
    handleLongPress();
}

TextSelection RenderEditableCls::_getWordAtOffset(TextPosition position) {
    debugAssertLayoutUpToDate();
    TextRange word = _textPainter->getWordBoundary(position);
    if (position->offset >= word->end) {
        return TextSelectionCls->fromPosition(position);
    }
    if (obscureText()) {
        return make<TextSelectionCls>(0, _plainText()->length());
    } else     {
        if (TextLayoutMetricsCls->isWhitespace(_plainText()->codeUnitAt(position->offset)) && position->offset > 0) {
        assert(defaultTargetPlatform != nullptr);
        TextRange previousWord = _getPreviousWord(word->start);
        ;
    }
;
    }    return make<TextSelectionCls>(word->start, word->end);
}

List<PlaceholderDimensions> RenderEditableCls::_layoutChildren(BoxConstraints constraints, bool dry) {
    if (childCount == 0) {
        _textPainter->setPlaceholderDimensions(makeList());
        return makeList();
    }
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensionsCls::empty);
    int childIndex = 0;
    BoxConstraints boxConstraints = make<BoxConstraintsCls>(constraints->maxWidth);
    boxConstraints = boxConstraints / textScaleFactor();
    while (child != nullptr) {
        double baselineOffset;
        Size childSize;
        if (!dry) {
            child->layout(boxConstraintstrue);
            childSize = child->size();
            ;
        } else {
            assert(_placeholderSpans[childIndex]->alignment != ui->PlaceholderAlignmentCls::baseline);
            childSize = child->getDryLayout(boxConstraints);
        }
        placeholderDimensions[childIndex] = make<PlaceholderDimensionsCls>(childSize, _placeholderSpans[childIndex]->alignment, _placeholderSpans[childIndex]->baseline, baselineOffset);
        child = childAfter(child);
        childIndex = 1;
    }
    return placeholderDimensions;
}

void RenderEditableCls::_setParentData() {
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
        textParentData->offset = make<OffsetCls>(_textPainter->inlinePlaceholderBoxes()![childIndex]->left, _textPainter->inlinePlaceholderBoxes()![childIndex]->top);
        textParentData->scale = _textPainter->inlinePlaceholderScales()![childIndex];
        child = childAfter(child);
        childIndex = 1;
    }
}

void RenderEditableCls::_layoutText(double maxWidth, double minWidth) {
    assert(maxWidth != nullptr && minWidth != nullptr);
    double availableMaxWidth = math->max(0.0, maxWidth - _caretMargin());
    double availableMinWidth = math->min(minWidth, availableMaxWidth);
    double textMaxWidth = _isMultiline()? availableMaxWidth : double->infinity;
    double textMinWidth = forceLine()? availableMaxWidth : availableMinWidth;
    _textPainter->layout(textMinWidth, textMaxWidth);
    _textLayoutLastMinWidth = minWidth;
    _textLayoutLastMaxWidth = maxWidth;
}

void RenderEditableCls::_computeTextMetricsIfNeeded() {
    assert(constraints != nullptr);
    _layoutText(constraints->minWidth, constraints->maxWidth);
}

void RenderEditableCls::_computeCaretPrototype() {
    assert(defaultTargetPlatform != nullptr);
    ;
}

Offset RenderEditableCls::_snapToPhysicalPixel(Offset sourceOffset) {
    Offset globalOffset = localToGlobal(sourceOffset);
    double pixelMultiple = 1.0 / _devicePixelRatio;
    return make<OffsetCls>(globalOffset->dx()->isFinite? (globalOffset->dx() / pixelMultiple)->round() * pixelMultiple - globalOffset->dx() : 0, globalOffset->dy()->isFinite? (globalOffset->dy() / pixelMultiple)->round() * pixelMultiple - globalOffset->dy() : 0);
}

bool RenderEditableCls::_canComputeDryLayout() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

MapEntry<int, Offset> RenderEditableCls::_lineNumberFor(List<LineMetrics> metrics, TextPosition startPosition) {
    Offset offset = _textPainter->getOffsetForCaret(startPosition, RectCls::zero);
    for (LineMetrics lineMetrics : metrics) {
        if (lineMetrics->baseline > offset->dy()) {
            return <int, Offset>make<MapEntryCls>(lineMetrics->lineNumber, make<OffsetCls>(offset->dx(), lineMetrics->baseline));
        }
    }
    assert(startPosition->offset == 0, __s("unable to find the line for $startPosition"));
    return <int, Offset>make<MapEntryCls>(math->max(0, metrics->length() - 1), make<OffsetCls>(offset->dx(), metrics->isNotEmpty? metrics->last->baseline + metrics->last->descent : 0.0));
}

void RenderEditableCls::_paintContents(PaintingContext context, Offset offset) {
    debugAssertLayoutUpToDate();
    Offset effectiveOffset = offset + _paintOffset();
    if (selection() != nullptr && !_floatingCursorOn) {
        _updateSelectionExtentsVisibility(effectiveOffset);
    }
    RenderBox foregroundChild = _foregroundRenderObject;
    RenderBox backgroundChild = _backgroundRenderObject;
    if (backgroundChild != nullptr) {
        context->paintChild(backgroundChild, offset);
    }
    _textPainter->paint(context->canvas(), effectiveOffset);
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter->inlinePlaceholderBoxes()!->length()) {
        TextParentData textParentData = as<TextParentData>(child->parentData!);
        double scale = textParentData->scale!;
        context->pushTransform(needsCompositing, effectiveOffset + textParentData->offset, Matrix4Cls->diagonal3Values(scale, scale, scale), [=] (PaintingContext context,Offset offset) {
            context->paintChild(child!, offset);
        });
        child = childAfter(child);
        childIndex = 1;
    }
    if (foregroundChild != nullptr) {
        context->paintChild(foregroundChild, offset);
    }
}

void RenderEditableCls::_paintHandleLayers(PaintingContext context, List<TextSelectionPoint> endpoints) {
    Offset startPoint = endpoints[0]->point;
    startPoint = make<OffsetCls>(clampDouble(startPoint->dx(), 0.0, size->width), clampDouble(startPoint->dy(), 0.0, size->height));
    context->pushLayer(make<LeaderLayerCls>(startHandleLayerLink(), startPoint), super->paint, OffsetCls::zero);
    if (endpoints->length() == 2) {
        Offset endPoint = endpoints[1]->point;
        endPoint = make<OffsetCls>(clampDouble(endPoint->dx(), 0.0, size->width), clampDouble(endPoint->dy(), 0.0, size->height));
        context->pushLayer(make<LeaderLayerCls>(endHandleLayerLink(), endPoint), super->paint, OffsetCls::zero);
    }
}

RenderEditable _RenderEditableCustomPaintCls::parent() {
    return as<RenderEditable>(super->parent);
}

bool _RenderEditableCustomPaintCls::isRepaintBoundary() {
    return true;
}

bool _RenderEditableCustomPaintCls::sizedByParent() {
    return true;
}

RenderEditablePainter _RenderEditableCustomPaintCls::painter() {
    return _painter;
}

void _RenderEditableCustomPaintCls::painter(RenderEditablePainter newValue) {
    if (newValue == painter()) {
        return;
    }
    RenderEditablePainter oldPainter = painter();
    _painter = newValue;
    if (newValue?->shouldRepaint(oldPainter) or true) {
        markNeedsPaint();
    }
    if (attached) {
        oldPainter?->removeListener(markNeedsPaint);
        newValue?->addListener(markNeedsPaint);
    }
}

void _RenderEditableCustomPaintCls::paint(PaintingContext context, Offset offset) {
    RenderEditable parent = this->parent();
    assert(parent != nullptr);
    RenderEditablePainter painter = this->painter();
    if (painter != nullptr && parent != nullptr) {
        parent->_computeTextMetricsIfNeeded();
        painter->paint(context->canvas(), size, parent);
    }
}

void _RenderEditableCustomPaintCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _painter?->addListener(markNeedsPaint);
}

void _RenderEditableCustomPaintCls::detach() {
    _painter?->removeListener(markNeedsPaint);
    super->detach();
}

Size _RenderEditableCustomPaintCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest();
}

_RenderEditableCustomPaintCls::_RenderEditableCustomPaintCls(RenderEditablePainter painter) {
    {
        _painter = painter;
    }
}

Color _TextHighlightPainterCls::highlightColor() {
    return _highlightColor;
}

void _TextHighlightPainterCls::highlightColor(Color newValue) {
    if (newValue == _highlightColor) {
        return;
    }
    _highlightColor = newValue;
    notifyListeners();
}

TextRange _TextHighlightPainterCls::highlightedRange() {
    return _highlightedRange;
}

void _TextHighlightPainterCls::highlightedRange(TextRange newValue) {
    if (newValue == _highlightedRange) {
        return;
    }
    _highlightedRange = newValue;
    notifyListeners();
}

BoxHeightStyle _TextHighlightPainterCls::selectionHeightStyle() {
    return _selectionHeightStyle;
}

void _TextHighlightPainterCls::selectionHeightStyle(BoxHeightStyle value) {
    assert(value != nullptr);
    if (_selectionHeightStyle == value) {
        return;
    }
    _selectionHeightStyle = value;
    notifyListeners();
}

BoxWidthStyle _TextHighlightPainterCls::selectionWidthStyle() {
    return _selectionWidthStyle;
}

void _TextHighlightPainterCls::selectionWidthStyle(BoxWidthStyle value) {
    assert(value != nullptr);
    if (_selectionWidthStyle == value) {
        return;
    }
    _selectionWidthStyle = value;
    notifyListeners();
}

void _TextHighlightPainterCls::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    TextRange range = highlightedRange();
    Color color = highlightColor();
    if (range == nullptr || color == nullptr || range->isCollapsed()) {
        return;
    }
    highlightPaint->color = color;
    TextPainter textPainter = renderEditable->_textPainter;
    List<TextBox> boxes = textPainter->getBoxesForSelection(make<TextSelectionCls>(range->start, range->end)selectionHeightStyle(), selectionWidthStyle());
    for (TextBox box : boxes) {
        canvas->drawRect(box->toRect()->shift(renderEditable->_paintOffset())->intersect(RectCls->fromLTWH(0, 0, textPainter->width(), textPainter->height())), highlightPaint);
    }
}

bool _TextHighlightPainterCls::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(oldDelegate, this)) {
        return false;
    }
    if (oldDelegate == nullptr) {
        return highlightColor() != nullptr && highlightedRange() != nullptr;
    }
    return !is<_TextHighlightPainter>(oldDelegate) || oldDelegate->highlightColor != highlightColor() || oldDelegate->highlightedRange != highlightedRange() || oldDelegate->selectionHeightStyle != selectionHeightStyle() || oldDelegate->selectionWidthStyle != selectionWidthStyle();
}

_TextHighlightPainterCls::_TextHighlightPainterCls(Color highlightColor, TextRange highlightedRange) {
    {
        _highlightedRange = highlightedRange;
        _highlightColor = highlightColor;
    }
}

bool _FloatingCursorPainterCls::shouldPaint() {
    return _shouldPaint;
}

void _FloatingCursorPainterCls::shouldPaint(bool value) {
    if (shouldPaint() == value) {
        return;
    }
    _shouldPaint = value;
    notifyListeners();
}

Color _FloatingCursorPainterCls::caretColor() {
    return _caretColor;
}

void _FloatingCursorPainterCls::caretColor(Color value) {
    if (caretColor()?->value == value?->value) {
        return;
    }
    _caretColor = value;
    notifyListeners();
}

Radius _FloatingCursorPainterCls::cursorRadius() {
    return _cursorRadius;
}

void _FloatingCursorPainterCls::cursorRadius(Radius value) {
    if (_cursorRadius == value) {
        return;
    }
    _cursorRadius = value;
    notifyListeners();
}

Offset _FloatingCursorPainterCls::cursorOffset() {
    return _cursorOffset;
}

void _FloatingCursorPainterCls::cursorOffset(Offset value) {
    if (_cursorOffset == value) {
        return;
    }
    _cursorOffset = value;
    notifyListeners();
}

Color _FloatingCursorPainterCls::backgroundCursorColor() {
    return _backgroundCursorColor;
}

void _FloatingCursorPainterCls::backgroundCursorColor(Color value) {
    if (backgroundCursorColor()?->value == value?->value) {
        return;
    }
    _backgroundCursorColor = value;
    if (showRegularCaret) {
        notifyListeners();
    }
}

Rect _FloatingCursorPainterCls::floatingCursorRect() {
    return _floatingCursorRect;
}

void _FloatingCursorPainterCls::floatingCursorRect(Rect value) {
    if (_floatingCursorRect == value) {
        return;
    }
    _floatingCursorRect = value;
    notifyListeners();
}

void _FloatingCursorPainterCls::paintRegularCursor(Canvas canvas, Color caretColor, RenderEditable renderEditable, TextPosition textPosition) {
    Rect caretPrototype = renderEditable->_caretPrototype;
    Offset caretOffset = renderEditable->_textPainter->getOffsetForCaret(textPosition, caretPrototype);
    Rect caretRect = caretPrototype->shift(caretOffset + cursorOffset());
    double caretHeight = renderEditable->_textPainter->getFullHeightForCaret(textPosition, caretPrototype);
    if (caretHeight != nullptr) {
        ;
    }
    caretRect = caretRect->shift(renderEditable->_paintOffset());
    Rect integralRect = caretRect->shift(renderEditable->_snapToPhysicalPixel(caretRect->topLeft()));
    if (shouldPaint()) {
        Radius radius = cursorRadius();
        caretPaint->color() = caretColor;
        if (radius == nullptr) {
            canvas->drawRect(integralRect, caretPaint);
        } else {
            RRect caretRRect = RRectCls->fromRectAndRadius(integralRect, radius);
            canvas->drawRRect(caretRRect, caretPaint);
        }
    }
    caretPaintCallback(integralRect);
}

void _FloatingCursorPainterCls::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    assert(renderEditable != nullptr);
    TextSelection selection = renderEditable->selection();
    if (selection == nullptr || !selection->isCollapsed) {
        return;
    }
    Rect floatingCursorRect = this->floatingCursorRect();
    Color caretColor = floatingCursorRect == nullptr? this->caretColor() : showRegularCaret? backgroundCursorColor() : nullptr;
    TextPosition caretTextPosition = floatingCursorRect == nullptr? selection->extent() : renderEditable->_floatingCursorTextPosition;
    if (caretColor != nullptr) {
        paintRegularCursor(canvas, renderEditable, caretColor, caretTextPosition);
    }
    Color floatingCursorColor = this->caretColor?->withOpacity(0.75);
    if (floatingCursorRect == nullptr || floatingCursorColor == nullptr || !shouldPaint()) {
        return;
    }
    auto _c1 = floatingCursorPaint;_c1.color = floatingCursorColor;canvas->drawRRect(RRectCls->fromRectAndRadius(floatingCursorRect->shift(renderEditable->_paintOffset()), _kFloatingCaretRadius), _c1);
}

bool _FloatingCursorPainterCls::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(this, oldDelegate)) {
        return false;
    }
    if (oldDelegate == nullptr) {
        return shouldPaint();
    }
    return !is<_FloatingCursorPainter>(oldDelegate) || oldDelegate->shouldPaint != shouldPaint() || oldDelegate->showRegularCaret != showRegularCaret || oldDelegate->caretColor != caretColor() || oldDelegate->cursorRadius != cursorRadius() || oldDelegate->cursorOffset != cursorOffset() || oldDelegate->backgroundCursorColor != backgroundCursorColor() || oldDelegate->floatingCursorRect != floatingCursorRect();
}

void _CompositeRenderEditablePainterCls::addListener(VoidCallback listener) {
    for (RenderEditablePainter painter : painters) {
        painter->addListener(listener);
    }
}

void _CompositeRenderEditablePainterCls::removeListener(VoidCallback listener) {
    for (RenderEditablePainter painter : painters) {
        painter->removeListener(listener);
    }
}

void _CompositeRenderEditablePainterCls::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    for (RenderEditablePainter painter : painters) {
        painter->paint(canvas, size, renderEditable);
    }
}

bool _CompositeRenderEditablePainterCls::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(oldDelegate, this)) {
        return false;
    }
    if (!is<_CompositeRenderEditablePainter>(oldDelegate) || oldDelegate->painters->length() != painters->length()) {
        return true;
    }
    Iterator<RenderEditablePainter> oldPainters = oldDelegate->painters->iterator;
    Iterator<RenderEditablePainter> newPainters = painters->iterator;
    while (oldPainters->moveNext() && newPainters->moveNext()) {
        if (newPainters->current()->shouldRepaint(oldPainters->current())) {
            return true;
        }
    }
    return false;
}
