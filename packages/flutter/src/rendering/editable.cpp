#include "editable.hpp"
TextSelectionPoint::TextSelectionPoint(TextDirection direction, Offset point) {
    {
        assert(point != nullptr);
    }
}

String TextSelectionPoint::toString() {
    ;
}

bool VerticalCaretMovementRun::isValid() {
    if (!_isValid) {
        return false;
    }
    List<LineMetrics> newLineMetrics = _editable._textPainter.computeLineMetrics();
    if (!identical(newLineMetrics, _lineMetrics)) {
        _isValid = false;
    }
    return _isValid;
}

TextPosition VerticalCaretMovementRun::current() {
    assert(isValid);
    return _currentTextPosition;
}

bool VerticalCaretMovementRun::moveNext() {
    assert(isValid);
    if (_currentLine + 1 >= _lineMetrics.length) {
        return false;
    }
    MapEntry<Offset, TextPosition> position = _getTextPositionForLine(_currentLine + 1);
    _currentLine = 1;
    _currentOffset = position.key;
    _currentTextPosition = position.value;
    return true;
}

bool VerticalCaretMovementRun::movePrevious() {
    assert(isValid);
    if (_currentLine <= 0) {
        return false;
    }
    MapEntry<Offset, TextPosition> position = _getTextPositionForLine(_currentLine - 1);
    _currentLine = 1;
    _currentOffset = position.key;
    _currentTextPosition = position.value;
    return true;
}

MapEntry<Offset, TextPosition> VerticalCaretMovementRun::_getTextPositionForLine(int lineNumber) {
    assert(isValid);
    assert(lineNumber >= 0);
    MapEntry<Offset, TextPosition> cachedPosition = _positionCache[lineNumber];
    if (cachedPosition != nullptr) {
        return cachedPosition;
    }
    assert(lineNumber != _currentLine);
    Offset newOffset = Offset(_currentOffset.dx, _lineMetrics[lineNumber].baseline);
    TextPosition closestPosition = _editable._textPainter.getPositionForOffset(newOffset);
    MapEntry<Offset, TextPosition> position = <Offset, TextPosition>MapEntry(newOffset, closestPosition);
    _positionCache[lineNumber] = position;
    return position;
}

RenderEditable::RenderEditable(Color backgroundCursorColor, List<RenderBox> children, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, EdgeInsets floatingCursorAddedMargin, bool forceLine, RenderEditablePainter foregroundPainter, bool hasFocus, bool ignorePointer, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, RenderEditablePainter painter, Color promptRectColor, TextRange promptRectRange, bool readOnly, TextSelection selection, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis) {
    {
        assert(textAlign != nullptr);
        assert(textDirection != nullptr, "RenderEditable created without a textDirection.");
        assert(maxLines == nullptr || maxLines > 0);
        assert(minLines == nullptr || minLines > 0);
        assert(startHandleLayerLink != nullptr);
        assert(endHandleLayerLink != nullptr);
        assert((maxLines == nullptr) || (minLines == nullptr) || (maxLines >= minLines), "minLines can't be greater than maxLines");
        assert(expands != nullptr);
        assert(!expands || (maxLines == nullptr && minLines == nullptr), "minLines and maxLines must be null when expands is true.");
        assert(textScaleFactor != nullptr);
        assert(offset != nullptr);
        assert(ignorePointer != nullptr);
        assert(textWidthBasis != nullptr);
        assert(paintCursorAboveText != nullptr);
        assert(obscuringCharacter != nullptr && obscuringCharacter.characters.length == 1);
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
        _textPainter = TextPainter(text, textAlign, textDirection, textScaleFactor, locale, strutStyle, textHeightBehavior, textWidthBasis);
        _showCursor = showCursor ?? <bool>ValueNotifier(false);
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
        _hasFocus = hasFocus ?? false;
    }
    {
        assert(_showCursor != nullptr);
        assert(!_showCursor.value || cursorColor != nullptr);
        _selectionPainter.highlightColor = selectionColor;
        _selectionPainter.highlightedRange = selection;
        _selectionPainter.selectionHeightStyle = selectionHeightStyle;
        _selectionPainter.selectionWidthStyle = selectionWidthStyle;
        _autocorrectHighlightPainter.highlightColor = promptRectColor;
        _autocorrectHighlightPainter.highlightedRange = promptRectRange;
        _caretPainter.caretColor = cursorColor;
        _caretPainter.cursorRadius = cursorRadius;
        _caretPainter.cursorOffset = cursorOffset;
        _caretPainter.backgroundCursorColor = backgroundCursorColor;
        _updateForegroundPainter(foregroundPainter);
        _updatePainter(painter);
        addAll(children);
        _extractPlaceholderSpans(text);
    }
}

void RenderEditable::setupParentData(RenderBox child) {
    if (child.parentData is! TextParentData) {
        child.parentData = TextParentData();
    }
}

void RenderEditable::dispose() {
    _foregroundRenderObject?.dispose();
    _foregroundRenderObject = nullptr;
    _backgroundRenderObject?.dispose();
    _backgroundRenderObject = nullptr;
    _clipRectLayer.layer = nullptr;
    _cachedBuiltInForegroundPainters?.dispose();
    _cachedBuiltInPainters?.dispose();
    _selectionStartInViewport.dispose();
    _selectionEndInViewport.dispose();
    super.dispose();
}

RenderEditablePainter RenderEditable::foregroundPainter() {
    return _foregroundPainter;
}

void RenderEditable::foregroundPainter(RenderEditablePainter newPainter) {
    if (newPainter == _foregroundPainter) {
        return;
    }
    _updateForegroundPainter(newPainter);
}

RenderEditablePainter RenderEditable::painter() {
    return _painter;
}

void RenderEditable::painter(RenderEditablePainter newPainter) {
    if (newPainter == _painter) {
        return;
    }
    _updatePainter(newPainter);
}

void RenderEditable::debugAssertLayoutUpToDate() {
    assert(_textLayoutLastMaxWidth == constraints.maxWidth && _textLayoutLastMinWidth == constraints.minWidth, "Last width ($_textLayoutLastMinWidth, $_textLayoutLastMaxWidth) not the same as max width constraint (${constraints.minWidth}, ${constraints.maxWidth}).");
}

TextHeightBehavior RenderEditable::textHeightBehavior() {
    return _textPainter.textHeightBehavior;
}

void RenderEditable::textHeightBehavior(TextHeightBehavior value) {
    if (_textPainter.textHeightBehavior == value) {
        return;
    }
    _textPainter.textHeightBehavior = value;
    markNeedsTextLayout();
}

TextWidthBasis RenderEditable::textWidthBasis() {
    return _textPainter.textWidthBasis;
}

void RenderEditable::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textPainter.textWidthBasis == value) {
        return;
    }
    _textPainter.textWidthBasis = value;
    markNeedsTextLayout();
}

double RenderEditable::devicePixelRatio() {
    return _devicePixelRatio;
}

void RenderEditable::devicePixelRatio(double value) {
    if (devicePixelRatio == value) {
        return;
    }
    _devicePixelRatio = value;
    markNeedsTextLayout();
}

String RenderEditable::obscuringCharacter() {
    return _obscuringCharacter;
}

void RenderEditable::obscuringCharacter(String value) {
    if (_obscuringCharacter == value) {
        return;
    }
    assert(value != nullptr && value.characters.length == 1);
    _obscuringCharacter = value;
    markNeedsLayout();
}

bool RenderEditable::obscureText() {
    return _obscureText;
}

void RenderEditable::obscureText(bool value) {
    if (_obscureText == value) {
        return;
    }
    _obscureText = value;
    markNeedsSemanticsUpdate();
}

BoxHeightStyle RenderEditable::selectionHeightStyle() {
    return _selectionPainter.selectionHeightStyle;
}

void RenderEditable::selectionHeightStyle(BoxHeightStyle value) {
    _selectionPainter.selectionHeightStyle = value;
}

BoxWidthStyle RenderEditable::selectionWidthStyle() {
    return _selectionPainter.selectionWidthStyle;
}

void RenderEditable::selectionWidthStyle(BoxWidthStyle value) {
    _selectionPainter.selectionWidthStyle = value;
}

ValueListenable<bool> RenderEditable::selectionStartInViewport() {
    return _selectionStartInViewport;
}

ValueListenable<bool> RenderEditable::selectionEndInViewport() {
    return _selectionEndInViewport;
}

TextSelection RenderEditable::getLineAtOffset(TextPosition position) {
    debugAssertLayoutUpToDate();
    TextRange line = _textPainter.getLineBoundary(position);
    if (obscureText) {
        return TextSelection(0, _plainText.length);
    }
    return TextSelection(line.start, line.end);
}

TextRange RenderEditable::getWordBoundary(TextPosition position) {
    return _textPainter.getWordBoundary(position);
}

TextPosition RenderEditable::getTextPositionAbove(TextPosition position) {
    double preferredLineHeight = _textPainter.preferredLineHeight;
    double verticalOffset = -0.5 * preferredLineHeight;
    return _getTextPositionVertical(position, verticalOffset);
}

TextPosition RenderEditable::getTextPositionBelow(TextPosition position) {
    double preferredLineHeight = _textPainter.preferredLineHeight;
    double verticalOffset = 1.5 * preferredLineHeight;
    return _getTextPositionVertical(position, verticalOffset);
}

void RenderEditable::markNeedsPaint() {
    super.markNeedsPaint();
    _foregroundRenderObject?.markNeedsPaint();
    _backgroundRenderObject?.markNeedsPaint();
}

void RenderEditable::markNeedsTextLayout() {
    _textLayoutLastMaxWidth = nullptr;
    _textLayoutLastMinWidth = nullptr;
    markNeedsLayout();
}

void RenderEditable::systemFontsDidChange() {
    super.systemFontsDidChange();
    _textPainter.markNeedsLayout();
    _textLayoutLastMaxWidth = nullptr;
    _textLayoutLastMinWidth = nullptr;
}

InlineSpan RenderEditable::text() {
    return _textPainter.text;
}

void RenderEditable::text(InlineSpan value) {
    if (_textPainter.text == value) {
        return;
    }
    _textPainter.text = value;
    _cachedPlainText = nullptr;
    _cachedAttributedValue = nullptr;
    _cachedCombinedSemanticsInfos = nullptr;
    _extractPlaceholderSpans(value);
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

TextAlign RenderEditable::textAlign() {
    return _textPainter.textAlign;
}

void RenderEditable::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textPainter.textAlign == value) {
        return;
    }
    _textPainter.textAlign = value;
    markNeedsTextLayout();
}

TextDirection RenderEditable::textDirection() {
    return _textPainter.textDirection!;
}

void RenderEditable::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textPainter.textDirection == value) {
        return;
    }
    _textPainter.textDirection = value;
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

Locale RenderEditable::locale() {
    return _textPainter.locale;
}

void RenderEditable::locale(Locale value) {
    if (_textPainter.locale == value) {
        return;
    }
    _textPainter.locale = value;
    markNeedsTextLayout();
}

StrutStyle RenderEditable::strutStyle() {
    return _textPainter.strutStyle;
}

void RenderEditable::strutStyle(StrutStyle value) {
    if (_textPainter.strutStyle == value) {
        return;
    }
    _textPainter.strutStyle = value;
    markNeedsTextLayout();
}

Color RenderEditable::cursorColor() {
    return _caretPainter.caretColor;
}

void RenderEditable::cursorColor(Color value) {
    _caretPainter.caretColor = value;
}

Color RenderEditable::backgroundCursorColor() {
    return _caretPainter.backgroundCursorColor;
}

void RenderEditable::backgroundCursorColor(Color value) {
    _caretPainter.backgroundCursorColor = value;
}

ValueNotifier<bool> RenderEditable::showCursor() {
    return _showCursor;
}

void RenderEditable::showCursor(ValueNotifier<bool> value) {
    assert(value != nullptr);
    if (_showCursor == value) {
        return;
    }
    if (attached) {
        _showCursor.removeListener(_showHideCursor);
    }
    _showCursor = value;
    if (attached) {
        _showHideCursor();
        _showCursor.addListener(_showHideCursor);
    }
}

bool RenderEditable::hasFocus() {
    return _hasFocus;
}

void RenderEditable::hasFocus(bool value) {
    assert(value != nullptr);
    if (_hasFocus == value) {
        return;
    }
    _hasFocus = value;
    markNeedsSemanticsUpdate();
}

bool RenderEditable::forceLine() {
    return _forceLine;
}

void RenderEditable::forceLine(bool value) {
    assert(value != nullptr);
    if (_forceLine == value) {
        return;
    }
    _forceLine = value;
    markNeedsLayout();
}

bool RenderEditable::readOnly() {
    return _readOnly;
}

void RenderEditable::readOnly(bool value) {
    assert(value != nullptr);
    if (_readOnly == value) {
        return;
    }
    _readOnly = value;
    markNeedsSemanticsUpdate();
}

int RenderEditable::maxLines() {
    return _maxLines;
}

void RenderEditable::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (maxLines == value) {
        return;
    }
    _maxLines = value;
    markNeedsTextLayout();
}

int RenderEditable::minLines() {
    return _minLines;
}

void RenderEditable::minLines(int value) {
    assert(value == nullptr || value > 0);
    if (minLines == value) {
        return;
    }
    _minLines = value;
    markNeedsTextLayout();
}

bool RenderEditable::expands() {
    return _expands;
}

void RenderEditable::expands(bool value) {
    assert(value != nullptr);
    if (expands == value) {
        return;
    }
    _expands = value;
    markNeedsTextLayout();
}

Color RenderEditable::selectionColor() {
    return _selectionPainter.highlightColor;
}

void RenderEditable::selectionColor(Color value) {
    _selectionPainter.highlightColor = value;
}

double RenderEditable::textScaleFactor() {
    return _textPainter.textScaleFactor;
}

void RenderEditable::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textPainter.textScaleFactor == value) {
        return;
    }
    _textPainter.textScaleFactor = value;
    markNeedsTextLayout();
}

TextSelection RenderEditable::selection() {
    return _selection;
}

void RenderEditable::selection(TextSelection value) {
    if (_selection == value) {
        return;
    }
    _selection = value;
    _selectionPainter.highlightedRange = value;
    markNeedsPaint();
    markNeedsSemanticsUpdate();
}

ViewportOffset RenderEditable::offset() {
    return _offset;
}

void RenderEditable::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (_offset == value) {
        return;
    }
    if (attached) {
        _offset.removeListener(markNeedsPaint);
    }
    _offset = value;
    if (attached) {
        _offset.addListener(markNeedsPaint);
    }
    markNeedsLayout();
}

double RenderEditable::cursorWidth() {
    return _cursorWidth;
}

void RenderEditable::cursorWidth(double value) {
    if (_cursorWidth == value) {
        return;
    }
    _cursorWidth = value;
    markNeedsLayout();
}

double RenderEditable::cursorHeight() {
    return _cursorHeight ?? preferredLineHeight;
}

void RenderEditable::cursorHeight(double value) {
    if (_cursorHeight == value) {
        return;
    }
    _cursorHeight = value;
    markNeedsLayout();
}

bool RenderEditable::paintCursorAboveText() {
    return _paintCursorOnTop;
}

void RenderEditable::paintCursorAboveText(bool value) {
    if (_paintCursorOnTop == value) {
        return;
    }
    _paintCursorOnTop = value;
    _cachedBuiltInForegroundPainters = nullptr;
    _cachedBuiltInPainters = nullptr;
    _updateForegroundPainter(_foregroundPainter);
    _updatePainter(_painter);
}

Offset RenderEditable::cursorOffset() {
    return _caretPainter.cursorOffset;
}

void RenderEditable::cursorOffset(Offset value) {
    _caretPainter.cursorOffset = value;
}

Radius RenderEditable::cursorRadius() {
    return _caretPainter.cursorRadius;
}

void RenderEditable::cursorRadius(Radius value) {
    _caretPainter.cursorRadius = value;
}

LayerLink RenderEditable::startHandleLayerLink() {
    return _startHandleLayerLink;
}

void RenderEditable::startHandleLayerLink(LayerLink value) {
    if (_startHandleLayerLink == value) {
        return;
    }
    _startHandleLayerLink = value;
    markNeedsPaint();
}

LayerLink RenderEditable::endHandleLayerLink() {
    return _endHandleLayerLink;
}

void RenderEditable::endHandleLayerLink(LayerLink value) {
    if (_endHandleLayerLink == value) {
        return;
    }
    _endHandleLayerLink = value;
    markNeedsPaint();
}

bool RenderEditable::enableInteractiveSelection() {
    return _enableInteractiveSelection;
}

void RenderEditable::enableInteractiveSelection(bool value) {
    if (_enableInteractiveSelection == value) {
        return;
    }
    _enableInteractiveSelection = value;
    markNeedsTextLayout();
    markNeedsSemanticsUpdate();
}

bool RenderEditable::selectionEnabled() {
    return enableInteractiveSelection ?? !obscureText;
}

Color RenderEditable::promptRectColor() {
    return _autocorrectHighlightPainter.highlightColor;
}

void RenderEditable::promptRectColor(Color newValue) {
    _autocorrectHighlightPainter.highlightColor = newValue;
}

void RenderEditable::setPromptRectRange(TextRange newRange) {
    _autocorrectHighlightPainter.highlightedRange = newRange;
}

double RenderEditable::maxScrollExtent() {
    return _maxScrollExtent;
}

Clip RenderEditable::clipBehavior() {
    return _clipBehavior;
}

void RenderEditable::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

List<Rect> RenderEditable::getBoxesForSelection(TextSelection selection) {
    _computeTextMetricsIfNeeded();
    return _textPainter.getBoxesForSelection(selection).map().toList();
}

void RenderEditable::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    _semanticsInfo = _textPainter.text!.getSemanticsInformation();
    if (_semanticsInfo!.any() && defaultTargetPlatform != TargetPlatform.macOS) {
        assert(readOnly && !obscureText);
        ;
        return;
    }
    if (_cachedAttributedValue == nullptr) {
        if (obscureText) {
            _cachedAttributedValue = AttributedString(obscuringCharacter * _plainText.length);
        } else {
            StringBuffer buffer = StringBuffer();
            int offset = 0;
            List<StringAttribute> attributes = ;
            for (InlineSpanSemanticsInformation info : _semanticsInfo!) {
                String label = info.semanticsLabel ?? info.text;
                for (StringAttribute infoAttribute : info.stringAttributes) {
                    TextRange originalRange = infoAttribute.range;
                    attributes.add(infoAttribute.copy(TextRange(offset + originalRange.start, offset + originalRange.end)));
                }
                buffer.write(label);
                offset = label.length;
            }
            _cachedAttributedValue = AttributedString(buffer.toString()attributes);
        }
    }
    ;
    if (hasFocus && selectionEnabled) {
        config.onSetSelection = _handleSetSelection;
    }
    if (hasFocus && !readOnly) {
        config.onSetText = _handleSetText;
    }
    if (selectionEnabled && (selection?.isValid ?? false)) {
        config.textSelection = selection;
        if (_textPainter.getOffsetBefore(selection!.extentOffset) != nullptr) {
            ;
        }
        if (_textPainter.getOffsetAfter(selection!.extentOffset) != nullptr) {
            ;
        }
    }
}

void RenderEditable::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    assert(_semanticsInfo != nullptr && _semanticsInfo!.isNotEmpty);
    List<SemanticsNode> newChildren = ;
    TextDirection currentDirection = textDirection;
    Rect currentRect;
    double ordinal = 0.0;
    int start = 0;
    int placeholderIndex = 0;
    int childIndex = 0;
    RenderBox child = firstChild;
    LinkedHashMap<Key, SemanticsNode> newChildCache = <Key, SemanticsNode>LinkedHashMap();
    _cachedCombinedSemanticsInfos = combineSemanticsInfo(_semanticsInfo!);
    for (InlineSpanSemanticsInformation info : _cachedCombinedSemanticsInfos!) {
        TextSelection selection = TextSelection(start, start + info.text.length);
        start = info.text.length;
        if (info.isPlaceholder) {
            while (children.length > childIndex && children.elementAt(childIndex).isTagged(PlaceholderSpanIndexSemanticsTag(placeholderIndex))) {
                SemanticsNode childNode = children.elementAt(childIndex);
                TextParentData parentData = (;
                assert(parentData.scale != nullptr);
                childNode.rect = Rect.fromLTWH(childNode.rect.left, childNode.rect.top, childNode.rect.width * parentData.scale!, childNode.rect.height * parentData.scale!);
                newChildren.add(childNode);
                childIndex = 1;
            }
            child = childAfter(child!);
            placeholderIndex = 1;
        } else {
            TextDirection initialDirection = currentDirection;
            List<TextBox> rects = _textPainter.getBoxesForSelection(selection);
            if (rects.isEmpty) {
                continue;
            }
            Rect rect = rects.first.toRect();
            currentDirection = rects.first.direction;
            for (TextBox textBox : rects.skip(1)) {
                rect = rect.expandToInclude(textBox.toRect());
                currentDirection = textBox.direction;
            }
            rect = Rect.fromLTWH(math.max(0.0, rect.left), math.max(0.0, rect.top), math.min(rect.width, constraints.maxWidth), math.min(rect.height, constraints.maxHeight));
            currentRect = Rect.fromLTRB(rect.left.floorToDouble() - 4.0, rect.top.floorToDouble() - 4.0, rect.right.ceilToDouble() + 4.0, rect.bottom.ceilToDouble() + 4.0);
            SemanticsConfiguration configuration = ;
            GestureRecognizer recognizer = info.recognizer;
            if (recognizer != nullptr) {
                if (recognizer is TapGestureRecognizer) {
                    if (recognizer.onTap != nullptr) {
                        configuration.onTap = recognizer.onTap;
                        configuration.isLink = true;
                    }
                } else                 {
                    if (recognizer is DoubleTapGestureRecognizer) {
                    if (recognizer.onDoubleTap != nullptr) {
                        configuration.onTap = recognizer.onDoubleTap;
                        configuration.isLink = true;
                    }
                } else                 {
                    if (recognizer is LongPressGestureRecognizer) {
                    if (recognizer.onLongPress != nullptr) {
                        configuration.onLongPress = recognizer.onLongPress;
                    }
                } else {
                    assert(false, "${recognizer.runtimeType} is not supported.");
                }
;
                };
                }            }
            if (node.parentPaintClipRect != nullptr) {
                Rect paintRect = node.parentPaintClipRect!.intersect(currentRect);
                configuration.isHidden = paintRect.isEmpty && !currentRect.isEmpty;
            }
            SemanticsNode newChild;
            if (_cachedChildNodes?.isNotEmpty ?? false) {
                newChild = _cachedChildNodes!.remove(_cachedChildNodes!.keys.first)!;
            } else {
                UniqueKey key = UniqueKey();
                newChild = SemanticsNode(key, _createShowOnScreenFor(key));
            }
            ;
            newChildCache[newChild.key!] = newChild;
            newChildren.add(newChild);
        }
    }
    _cachedChildNodes = newChildCache;
    node.updateWith(config, newChildren);
}

void RenderEditable::attach(PipelineOwner owner) {
    super.attach(owner);
    _foregroundRenderObject?.attach(owner);
    _backgroundRenderObject?.attach(owner);
    _tap = ;
    _longPress = ;
    _offset.addListener(markNeedsPaint);
    _showHideCursor();
    _showCursor.addListener(_showHideCursor);
}

void RenderEditable::detach() {
    _tap.dispose();
    _longPress.dispose();
    _offset.removeListener(markNeedsPaint);
    _showCursor.removeListener(_showHideCursor);
    super.detach();
    _foregroundRenderObject?.detach();
    _backgroundRenderObject?.detach();
}

void RenderEditable::redepthChildren() {
    RenderObject foregroundChild = _foregroundRenderObject;
    RenderObject backgroundChild = _backgroundRenderObject;
    if (foregroundChild != nullptr) {
        redepthChild(foregroundChild);
    }
    if (backgroundChild != nullptr) {
        redepthChild(backgroundChild);
    }
    super.redepthChildren();
}

void RenderEditable::visitChildren(RenderObjectVisitor visitor) {
    RenderObject foregroundChild = _foregroundRenderObject;
    RenderObject backgroundChild = _backgroundRenderObject;
    if (foregroundChild != nullptr) {
        visitor(foregroundChild);
    }
    if (backgroundChild != nullptr) {
        visitor(backgroundChild);
    }
    super.visitChildren(visitor);
}

List<TextSelectionPoint> RenderEditable::getEndpointsForSelection(TextSelection selection) {
    _computeTextMetricsIfNeeded();
    Offset paintOffset = _paintOffset;
    List<TextBox> boxes = selection.isCollapsed?  : _textPainter.getBoxesForSelection(selectionselectionHeightStyle, selectionWidthStyle);
    if (boxes.isEmpty) {
        Offset caretOffset = _textPainter.getOffsetForCaret(selection.extent, _caretPrototype);
        Offset start = Offset(0.0, preferredLineHeight) + caretOffset + paintOffset;
        return ;
    } else {
        Offset start = Offset(clampDouble(boxes.first.start, 0, _textPainter.size.width), boxes.first.bottom) + paintOffset;
        Offset end = Offset(clampDouble(boxes.last.end, 0, _textPainter.size.width), boxes.last.bottom) + paintOffset;
        return ;
    }
}

Rect RenderEditable::getRectForComposingRange(TextRange range) {
    if (!range.isValid || range.isCollapsed) {
        return nullptr;
    }
    _computeTextMetricsIfNeeded();
    List<TextBox> boxes = _textPainter.getBoxesForSelection(TextSelection(range.start, range.end)selectionHeightStyle, selectionWidthStyle);
    return boxes.fold(nullptr, )?.shift(_paintOffset);
}

TextPosition RenderEditable::getPositionForPoint(Offset globalPosition) {
    _computeTextMetricsIfNeeded();
    globalPosition = -_paintOffset;
    return _textPainter.getPositionForOffset(globalToLocal(globalPosition));
}

Rect RenderEditable::getLocalRectForCaret(TextPosition caretPosition) {
    _computeTextMetricsIfNeeded();
    Offset caretOffset = _textPainter.getOffsetForCaret(caretPosition, _caretPrototype);
    Rect rect = Rect.fromLTWH(0.0, 0.0, cursorWidth, cursorHeight).shift(caretOffset + _paintOffset + cursorOffset);
    return rect.shift(_snapToPhysicalPixel(rect.topLeft));
}

double RenderEditable::computeMinIntrinsicWidth(double height) {
    _layoutText();
    return _textPainter.minIntrinsicWidth;
}

double RenderEditable::computeMaxIntrinsicWidth(double height) {
    _layoutText();
    return _textPainter.maxIntrinsicWidth + _caretMargin;
}

double RenderEditable::preferredLineHeight() {
    return _textPainter.preferredLineHeight;
}

double RenderEditable::computeMinIntrinsicHeight(double width) {
    return _preferredHeight(width);
}

double RenderEditable::computeMaxIntrinsicHeight(double width) {
    return _preferredHeight(width);
}

double RenderEditable::computeDistanceToActualBaseline(TextBaseline baseline) {
    _computeTextMetricsIfNeeded();
    return _textPainter.computeDistanceToActualBaseline(baseline);
}

bool RenderEditable::hitTestSelf(Offset position) {
    return true;
}

bool RenderEditable::hitTestChildren(Offset position, BoxHitTestResult result) {
    bool hitText = false;
    Offset effectivePosition = position - _paintOffset;
    TextPosition textPosition = _textPainter.getPositionForOffset(effectivePosition);
    InlineSpan span = _textPainter.text!.getSpanForPosition(textPosition);
    if (span != nullptr && span is HitTestTarget) {
        result.add(HitTestEntry(());
        hitText = true;
    }
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        Matrix4 transform = ;
        bool isHit = result.addWithPaintTransform(transform, position, );
        if (isHit) {
            return true;
        }
        child = childAfter(child);
        childIndex = 1;
    }
    return hitText;
}

void RenderEditable::handleEvent(BoxHitTestEntry entry, PointerEvent event) {
    assert(debugHandleEvent(event, entry));
    if (event is PointerDownEvent) {
        assert(!debugNeedsLayout);
        if (!ignorePointer) {
            _tap.addPointer(event);
            _longPress.addPointer(event);
        }
    }
}

Offset RenderEditable::lastSecondaryTapDownPosition() {
    return _lastSecondaryTapDownPosition;
}

void RenderEditable::handleSecondaryTapDown(TapDownDetails details) {
    _lastTapDownPosition = details.globalPosition;
    _lastSecondaryTapDownPosition = details.globalPosition;
}

void RenderEditable::handleTapDown(TapDownDetails details) {
    _lastTapDownPosition = details.globalPosition;
}

void RenderEditable::handleTap() {
    selectPosition(SelectionChangedCause.tap);
}

void RenderEditable::handleDoubleTap() {
    selectWord(SelectionChangedCause.doubleTap);
}

void RenderEditable::handleLongPress() {
    selectWord(SelectionChangedCause.longPress);
}

void RenderEditable::selectPosition(SelectionChangedCause cause) {
    selectPositionAt(_lastTapDownPosition!, cause);
}

void RenderEditable::selectPositionAt(SelectionChangedCause cause, Offset from, Offset to) {
    assert(cause != nullptr);
    assert(from != nullptr);
    _layoutText(constraints.minWidth, constraints.maxWidth);
    TextPosition fromPosition = _textPainter.getPositionForOffset(globalToLocal(from - _paintOffset));
    TextPosition toPosition = to == nullptr? nullptr : _textPainter.getPositionForOffset(globalToLocal(to - _paintOffset));
    int baseOffset = fromPosition.offset;
    int extentOffset = toPosition?.offset ?? fromPosition.offset;
    TextSelection newSelection = TextSelection(baseOffset, extentOffset, fromPosition.affinity);
    _setSelection(newSelection, cause);
}

void RenderEditable::selectWord(SelectionChangedCause cause) {
    selectWordsInRange(_lastTapDownPosition!, cause);
}

void RenderEditable::selectWordsInRange(SelectionChangedCause cause, Offset from, Offset to) {
    assert(cause != nullptr);
    assert(from != nullptr);
    _computeTextMetricsIfNeeded();
    TextPosition firstPosition = _textPainter.getPositionForOffset(globalToLocal(from - _paintOffset));
    TextSelection firstWord = _getWordAtOffset(firstPosition);
    TextSelection lastWord = to == nullptr? firstWord : _getWordAtOffset(_textPainter.getPositionForOffset(globalToLocal(to - _paintOffset)));
    _setSelection(TextSelection(firstWord.base.offset, lastWord.extent.offset, firstWord.affinity), cause);
}

void RenderEditable::selectWordEdge(SelectionChangedCause cause) {
    assert(cause != nullptr);
    _computeTextMetricsIfNeeded();
    assert(_lastTapDownPosition != nullptr);
    TextPosition position = _textPainter.getPositionForOffset(globalToLocal(_lastTapDownPosition! - _paintOffset));
    TextRange word = _textPainter.getWordBoundary(position);
    TextSelection newSelection;
    if (position.offset - word.start <= 1) {
        newSelection = TextSelection.collapsed(word.start);
    } else {
        newSelection = TextSelection.collapsed(word.end, TextAffinity.upstream);
    }
    _setSelection(newSelection, cause);
}

Size RenderEditable::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeDryLayout()) {
        assert(debugCannotComputeDryLayout("Dry layout not available for alignments that require baseline."));
        return Size.zero;
    }
    _textPainter.setPlaceholderDimensions(_layoutChildren(constraintstrue));
    _layoutText(constraints.minWidth, constraints.maxWidth);
    double width = forceLine? constraints.maxWidth : constraints.constrainWidth(_textPainter.size.width + _caretMargin);
    return Size(width, constraints.constrainHeight(_preferredHeight(constraints.maxWidth)));
}

void RenderEditable::performLayout() {
    BoxConstraints constraints = this.constraints;
    _placeholderDimensions = _layoutChildren(constraints);
    _textPainter.setPlaceholderDimensions(_placeholderDimensions);
    _computeTextMetricsIfNeeded();
    _setParentData();
    _computeCaretPrototype();
    Size textPainterSize = _textPainter.size;
    double width = forceLine? constraints.maxWidth : constraints.constrainWidth(_textPainter.size.width + _caretMargin);
    size = Size(width, constraints.constrainHeight(_preferredHeight(constraints.maxWidth)));
    Size contentSize = Size(textPainterSize.width + _caretMargin, textPainterSize.height);
    BoxConstraints painterConstraints = BoxConstraints.tight(contentSize);
    _foregroundRenderObject?.layout(painterConstraints);
    _backgroundRenderObject?.layout(painterConstraints);
    _maxScrollExtent = _getMaxScrollExtent(contentSize);
    offset.applyViewportDimension(_viewportExtent);
    offset.applyContentDimensions(0.0, _maxScrollExtent);
}

Offset RenderEditable::calculateBoundedFloatingCursorOffset(Offset rawCursorOffset) {
    Offset deltaPosition = Offset.zero;
    double topBound = -floatingCursorAddedMargin.top;
    double bottomBound = _textPainter.height - preferredLineHeight + floatingCursorAddedMargin.bottom;
    double leftBound = -floatingCursorAddedMargin.left;
    double rightBound = _textPainter.width + floatingCursorAddedMargin.right;
    if (_previousOffset != nullptr) {
        deltaPosition = rawCursorOffset - _previousOffset!;
    }
    if (_resetOriginOnLeft && deltaPosition.dx > 0) {
        _relativeOrigin = Offset(rawCursorOffset.dx - leftBound, _relativeOrigin.dy);
        _resetOriginOnLeft = false;
    } else     {
        if (_resetOriginOnRight && deltaPosition.dx < 0) {
        _relativeOrigin = Offset(rawCursorOffset.dx - rightBound, _relativeOrigin.dy);
        _resetOriginOnRight = false;
    }
;
    }    if (_resetOriginOnTop && deltaPosition.dy > 0) {
        _relativeOrigin = Offset(_relativeOrigin.dx, rawCursorOffset.dy - topBound);
        _resetOriginOnTop = false;
    } else     {
        if (_resetOriginOnBottom && deltaPosition.dy < 0) {
        _relativeOrigin = Offset(_relativeOrigin.dx, rawCursorOffset.dy - bottomBound);
        _resetOriginOnBottom = false;
    }
;
    }    double currentX = rawCursorOffset.dx - _relativeOrigin.dx;
    double currentY = rawCursorOffset.dy - _relativeOrigin.dy;
    double adjustedX = math.min(math.max(currentX, leftBound), rightBound);
    double adjustedY = math.min(math.max(currentY, topBound), bottomBound);
    Offset adjustedOffset = Offset(adjustedX, adjustedY);
    if ( < leftBound && deltaPosition.dx < 0) {
        _resetOriginOnLeft = true;
    } else     {
        if (currentX > rightBound && deltaPosition.dx > 0) {
        _resetOriginOnRight = true;
    }
;
    }    if ( < topBound && deltaPosition.dy < 0) {
        _resetOriginOnTop = true;
    } else     {
        if (currentY > bottomBound && deltaPosition.dy > 0) {
        _resetOriginOnBottom = true;
    }
;
    }    _previousOffset = rawCursorOffset;
    return adjustedOffset;
}

void RenderEditable::setFloatingCursor(Offset boundedOffset, TextPosition lastTextPosition, double resetLerpValue, FloatingCursorDragState state) {
    assert(state != nullptr);
    assert(boundedOffset != nullptr);
    assert(lastTextPosition != nullptr);
    if (state == FloatingCursorDragState.Start) {
        _relativeOrigin = Offset.zero;
        _previousOffset = nullptr;
        _resetOriginOnBottom = false;
        _resetOriginOnTop = false;
        _resetOriginOnRight = false;
        _resetOriginOnBottom = false;
    }
    _floatingCursorOn = state != FloatingCursorDragState.End;
    _resetFloatingCursorAnimationValue = resetLerpValue;
    if (_floatingCursorOn) {
        _floatingCursorTextPosition = lastTextPosition;
        double animationValue = _resetFloatingCursorAnimationValue;
        EdgeInsets sizeAdjustment = animationValue != nullptr? EdgeInsets.lerp(_kFloatingCaretSizeIncrease, EdgeInsets.zero, animationValue)! : _kFloatingCaretSizeIncrease;
        _caretPainter.floatingCursorRect = sizeAdjustment.inflateRect(_caretPrototype).shift(boundedOffset);
    } else {
        _caretPainter.floatingCursorRect = nullptr;
    }
    _caretPainter.showRegularCaret = _resetFloatingCursorAnimationValue == nullptr;
}

VerticalCaretMovementRun RenderEditable::startVerticalCaretMovement(TextPosition startPosition) {
    List<LineMetrics> metrics = _textPainter.computeLineMetrics();
    MapEntry<int, Offset> currentLine = _lineNumberFor(startPosition, metrics);
    return VerticalCaretMovementRun._(this, metrics, startPosition, currentLine.key, currentLine.value);
}

void RenderEditable::paint(PaintingContext context, Offset offset) {
    _computeTextMetricsIfNeeded();
    if (_hasVisualOverflow && clipBehavior != Clip.none) {
        _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, _paintContentsclipBehavior, _clipRectLayer.layer);
    } else {
        _clipRectLayer.layer = nullptr;
        _paintContents(context, offset);
    }
    if (selection!.isValid) {
        _paintHandleLayers(context, getEndpointsForSelection(selection!));
    }
}

Rect RenderEditable::describeApproximatePaintClip(RenderObject child) {
    ;
}

void RenderEditable::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(ColorProperty("cursorColor", cursorColor));
    properties.add(<ValueNotifier<bool>>DiagnosticsProperty("showCursor", showCursor));
    properties.add(IntProperty("maxLines", maxLines));
    properties.add(IntProperty("minLines", minLines));
    properties.add(<bool>DiagnosticsProperty("expands", expandsfalse));
    properties.add(ColorProperty("selectionColor", selectionColor));
    properties.add(DoubleProperty("textScaleFactor", textScaleFactor));
    properties.add(<Locale>DiagnosticsProperty("locale", localenullptr));
    properties.add(<TextSelection>DiagnosticsProperty("selection", selection));
    properties.add(<ViewportOffset>DiagnosticsProperty("offset", offset));
}

List<DiagnosticsNode> RenderEditable::debugDescribeChildren() {
    return ;
}

void RenderEditable::_updateForegroundPainter(RenderEditablePainter newPainter) {
    _CompositeRenderEditablePainter effectivePainter = newPainter == nullptr? _builtInForegroundPainters : _CompositeRenderEditablePainter();
    if (_foregroundRenderObject == nullptr) {
        _RenderEditableCustomPaint foregroundRenderObject = _RenderEditableCustomPaint(effectivePainter);
        adoptChild(foregroundRenderObject);
        _foregroundRenderObject = foregroundRenderObject;
    } else {
        _foregroundRenderObject?.painter = effectivePainter;
    }
    _foregroundPainter = newPainter;
}

void RenderEditable::_extractPlaceholderSpans(InlineSpan span) {
    _placeholderSpans = ;
    span?.visitChildren();
}

void RenderEditable::_updatePainter(RenderEditablePainter newPainter) {
    _CompositeRenderEditablePainter effectivePainter = newPainter == nullptr? _builtInPainters : _CompositeRenderEditablePainter();
    if (_backgroundRenderObject == nullptr) {
        _RenderEditableCustomPaint backgroundRenderObject = _RenderEditableCustomPaint(effectivePainter);
        adoptChild(backgroundRenderObject);
        _backgroundRenderObject = backgroundRenderObject;
    } else {
        _backgroundRenderObject?.painter = effectivePainter;
    }
    _painter = newPainter;
}

_CompositeRenderEditablePainter RenderEditable::_builtInForegroundPainters() {
    return _cachedBuiltInForegroundPainters ??= _createBuiltInForegroundPainters();
}

_CompositeRenderEditablePainter RenderEditable::_createBuiltInForegroundPainters() {
    return _CompositeRenderEditablePainter();
}

_CompositeRenderEditablePainter RenderEditable::_builtInPainters() {
    return _cachedBuiltInPainters ??= _createBuiltInPainters();
}

_CompositeRenderEditablePainter RenderEditable::_createBuiltInPainters() {
    return _CompositeRenderEditablePainter();
}

void RenderEditable::_onCaretChanged(Rect caretRect) {
    if (_lastCaretRect != caretRect) {
        onCaretChanged?.call(caretRect);
    }
    _lastCaretRect = onCaretChanged == nullptr? nullptr : caretRect;
}

TextPosition RenderEditable::_getTextPositionVertical(TextPosition position, double verticalOffset) {
    Offset caretOffset = _textPainter.getOffsetForCaret(position, _caretPrototype);
    Offset caretOffsetTranslated = caretOffset.translate(0.0, verticalOffset);
    return _textPainter.getPositionForOffset(caretOffsetTranslated);
}

void RenderEditable::_updateSelectionExtentsVisibility(Offset effectiveOffset) {
    assert(selection != nullptr);
    Rect visibleRegion = Offset.zero & size;
    Offset startOffset = _textPainter.getOffsetForCaret(TextPosition(selection!.start, selection!.affinity), _caretPrototype);
    double visibleRegionSlop = 0.5;
    _selectionStartInViewport.value = visibleRegion.inflate(visibleRegionSlop).contains(startOffset + effectiveOffset);
    Offset endOffset = _textPainter.getOffsetForCaret(TextPosition(selection!.end, selection!.affinity), _caretPrototype);
    _selectionEndInViewport.value = visibleRegion.inflate(visibleRegionSlop).contains(endOffset + effectiveOffset);
}

void RenderEditable::_setTextEditingValue(SelectionChangedCause cause, TextEditingValue newValue) {
    textSelectionDelegate.userUpdateTextEditingValue(newValue, cause);
}

void RenderEditable::_setSelection(SelectionChangedCause cause, TextSelection nextSelection) {
    if (nextSelection.isValid) {
        int textLength = textSelectionDelegate.textEditingValue.text.length;
        nextSelection = nextSelection.copyWith(math.min(nextSelection.baseOffset, textLength), math.min(nextSelection.extentOffset, textLength));
    }
    _setTextEditingValue(textSelectionDelegate.textEditingValue.copyWith(nextSelection), cause);
}

String RenderEditable::_plainText() {
    _cachedPlainText = _textPainter.text!.toPlainText(false);
    return _cachedPlainText!;
}

void RenderEditable::_showHideCursor() {
    _caretPainter.shouldPaint = showCursor.value;
}

double RenderEditable::_caretMargin() {
    return _kCaretGap + cursorWidth;
}

void RenderEditable::_handleSetText(String text) {
    textSelectionDelegate.userUpdateTextEditingValue(TextEditingValue(text, TextSelection.collapsed(text.length)), SelectionChangedCause.keyboard);
}

VoidCallback RenderEditable::_createShowOnScreenFor(Key key) {
    return ;
}

void RenderEditable::_handleSetSelection(TextSelection selection) {
    _setSelection(selection, SelectionChangedCause.keyboard);
}

void RenderEditable::_handleMoveCursorForwardByCharacter(bool extendSelection) {
    assert(selection != nullptr);
    int extentOffset = _textPainter.getOffsetAfter(selection!.extentOffset);
    if (extentOffset == nullptr) {
        return;
    }
    int baseOffset = !extendSelection? extentOffset : selection!.baseOffset;
    _setSelection(TextSelection(baseOffset, extentOffset), SelectionChangedCause.keyboard);
}

void RenderEditable::_handleMoveCursorBackwardByCharacter(bool extendSelection) {
    assert(selection != nullptr);
    int extentOffset = _textPainter.getOffsetBefore(selection!.extentOffset);
    if (extentOffset == nullptr) {
        return;
    }
    int baseOffset = !extendSelection? extentOffset : selection!.baseOffset;
    _setSelection(TextSelection(baseOffset, extentOffset), SelectionChangedCause.keyboard);
}

void RenderEditable::_handleMoveCursorForwardByWord(bool extendSelection) {
    assert(selection != nullptr);
    TextRange currentWord = _textPainter.getWordBoundary(selection!.extent);
    TextRange nextWord = _getNextWord(currentWord.end);
    if (nextWord == nullptr) {
        return;
    }
    int baseOffset = extendSelection? selection!.baseOffset : nextWord.start;
    _setSelection(TextSelection(baseOffset, nextWord.start), SelectionChangedCause.keyboard);
}

void RenderEditable::_handleMoveCursorBackwardByWord(bool extendSelection) {
    assert(selection != nullptr);
    TextRange currentWord = _textPainter.getWordBoundary(selection!.extent);
    TextRange previousWord = _getPreviousWord(currentWord.start - 1);
    if (previousWord == nullptr) {
        return;
    }
    int baseOffset = extendSelection? selection!.baseOffset : previousWord.start;
    _setSelection(TextSelection(baseOffset, previousWord.start), SelectionChangedCause.keyboard);
}

TextRange RenderEditable::_getNextWord(int offset) {
    while (true) {
        TextRange range = _textPainter.getWordBoundary(TextPosition(offset));
        if (range == nullptr || !range.isValid || range.isCollapsed) {
            return nullptr;
        }
        if (!_onlyWhitespace(range)) {
            return range;
        }
        offset = range.end;
    }
}

TextRange RenderEditable::_getPreviousWord(int offset) {
    while (offset >= 0) {
        TextRange range = _textPainter.getWordBoundary(TextPosition(offset));
        if (range == nullptr || !range.isValid || range.isCollapsed) {
            return nullptr;
        }
        if (!_onlyWhitespace(range)) {
            return range;
        }
        offset = range.start - 1;
    }
    return nullptr;
}

bool RenderEditable::_onlyWhitespace(TextRange range) {
    for (;  < range.end; i++) {
        int codeUnit = text!.codeUnitAt(i)!;
        if (!TextLayoutMetrics.isWhitespace(codeUnit)) {
            return false;
        }
    }
    return true;
}

bool RenderEditable::_isMultiline() {
    return maxLines != 1;
}

Axis RenderEditable::_viewportAxis() {
    return _isMultiline? Axis.vertical : Axis.horizontal;
}

Offset RenderEditable::_paintOffset() {
    ;
}

double RenderEditable::_viewportExtent() {
    assert(hasSize);
    ;
}

double RenderEditable::_getMaxScrollExtent(Size contentSize) {
    assert(hasSize);
    ;
}

bool RenderEditable::_hasVisualOverflow() {
    return _maxScrollExtent > 0 || _paintOffset != Offset.zero;
}

double RenderEditable::_preferredHeight(double width) {
    bool lockedMax = maxLines != nullptr && minLines == nullptr;
    bool lockedBoth = minLines != nullptr && minLines == maxLines;
    bool singleLine = maxLines == 1;
    if (singleLine || lockedMax || lockedBoth) {
        return preferredLineHeight * maxLines!;
    }
    bool minLimited = minLines != nullptr && minLines! > 1;
    bool maxLimited = maxLines != nullptr;
    if (minLimited || maxLimited) {
        _layoutText(width);
        if (minLimited && _textPainter.height < preferredLineHeight * minLines!) {
            return preferredLineHeight * minLines!;
        }
        if (maxLimited && _textPainter.height > preferredLineHeight * maxLines!) {
            return preferredLineHeight * maxLines!;
        }
    }
    if (width == double.infinity) {
        String text = _plainText;
        int lines = 1;
        for (;  < text.length; index = 1) {
            if (text.codeUnitAt(index) == 0x0A) {
                lines = 1;
            }
        }
        return preferredLineHeight * lines;
    }
    _layoutText(width);
    return math.max(preferredLineHeight, _textPainter.height);
}

void RenderEditable::_handleTapDown(TapDownDetails details) {
    assert(!ignorePointer);
    handleTapDown(details);
}

void RenderEditable::_handleTap() {
    assert(!ignorePointer);
    handleTap();
}

void RenderEditable::_handleLongPress() {
    assert(!ignorePointer);
    handleLongPress();
}

TextSelection RenderEditable::_getWordAtOffset(TextPosition position) {
    debugAssertLayoutUpToDate();
    TextRange word = _textPainter.getWordBoundary(position);
    if (position.offset >= word.end) {
        return TextSelection.fromPosition(position);
    }
    if (obscureText) {
        return TextSelection(0, _plainText.length);
    } else     {
        if (TextLayoutMetrics.isWhitespace(_plainText.codeUnitAt(position.offset)) && position.offset > 0) {
        assert(defaultTargetPlatform != nullptr);
        TextRange previousWord = _getPreviousWord(word.start);
        ;
    }
;
    }    return TextSelection(word.start, word.end);
}

List<PlaceholderDimensions> RenderEditable::_layoutChildren(BoxConstraints constraints, bool dry) {
    if (childCount == 0) {
        _textPainter.setPlaceholderDimensions();
        return ;
    }
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensions.empty);
    int childIndex = 0;
    BoxConstraints boxConstraints = BoxConstraints(constraints.maxWidth);
    boxConstraints = boxConstraints / textScaleFactor;
    while (child != nullptr) {
        double baselineOffset;
        Size childSize;
        if (!dry) {
            child.layout(boxConstraintstrue);
            childSize = child.size;
            ;
        } else {
            assert(_placeholderSpans[childIndex].alignment != ui.PlaceholderAlignment.baseline);
            childSize = child.getDryLayout(boxConstraints);
        }
        placeholderDimensions[childIndex] = PlaceholderDimensions(childSize, _placeholderSpans[childIndex].alignment, _placeholderSpans[childIndex].baseline, baselineOffset);
        child = childAfter(child);
        childIndex = 1;
    }
    return placeholderDimensions;
}

void RenderEditable::_setParentData() {
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        textParentData.offset = Offset(_textPainter.inlinePlaceholderBoxes![childIndex].left, _textPainter.inlinePlaceholderBoxes![childIndex].top);
        textParentData.scale = _textPainter.inlinePlaceholderScales![childIndex];
        child = childAfter(child);
        childIndex = 1;
    }
}

void RenderEditable::_layoutText(double maxWidth, double minWidth) {
    assert(maxWidth != nullptr && minWidth != nullptr);
    double availableMaxWidth = math.max(0.0, maxWidth - _caretMargin);
    double availableMinWidth = math.min(minWidth, availableMaxWidth);
    double textMaxWidth = _isMultiline? availableMaxWidth : double.infinity;
    double textMinWidth = forceLine? availableMaxWidth : availableMinWidth;
    _textPainter.layout(textMinWidth, textMaxWidth);
    _textLayoutLastMinWidth = minWidth;
    _textLayoutLastMaxWidth = maxWidth;
}

void RenderEditable::_computeTextMetricsIfNeeded() {
    assert(constraints != nullptr);
    _layoutText(constraints.minWidth, constraints.maxWidth);
}

void RenderEditable::_computeCaretPrototype() {
    assert(defaultTargetPlatform != nullptr);
    ;
}

Offset RenderEditable::_snapToPhysicalPixel(Offset sourceOffset) {
    Offset globalOffset = localToGlobal(sourceOffset);
    double pixelMultiple = 1.0 / _devicePixelRatio;
    return Offset(globalOffset.dx.isFinite? (globalOffset.dx / pixelMultiple).round() * pixelMultiple - globalOffset.dx : 0, globalOffset.dy.isFinite? (globalOffset.dy / pixelMultiple).round() * pixelMultiple - globalOffset.dy : 0);
}

bool RenderEditable::_canComputeDryLayout() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

MapEntry<int, Offset> RenderEditable::_lineNumberFor(List<LineMetrics> metrics, TextPosition startPosition) {
    Offset offset = _textPainter.getOffsetForCaret(startPosition, Rect.zero);
    for (LineMetrics lineMetrics : metrics) {
        if (lineMetrics.baseline > offset.dy) {
            return <int, Offset>MapEntry(lineMetrics.lineNumber, Offset(offset.dx, lineMetrics.baseline));
        }
    }
    assert(startPosition.offset == 0, "unable to find the line for $startPosition");
    return <int, Offset>MapEntry(math.max(0, metrics.length - 1), Offset(offset.dx, metrics.isNotEmpty? metrics.last.baseline + metrics.last.descent : 0.0));
}

void RenderEditable::_paintContents(PaintingContext context, Offset offset) {
    debugAssertLayoutUpToDate();
    Offset effectiveOffset = offset + _paintOffset;
    if (selection != nullptr && !_floatingCursorOn) {
        _updateSelectionExtentsVisibility(effectiveOffset);
    }
    RenderBox foregroundChild = _foregroundRenderObject;
    RenderBox backgroundChild = _backgroundRenderObject;
    if (backgroundChild != nullptr) {
        context.paintChild(backgroundChild, offset);
    }
    _textPainter.paint(context.canvas, effectiveOffset);
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        double scale = textParentData.scale!;
        context.pushTransform(needsCompositing, effectiveOffset + textParentData.offset, Matrix4.diagonal3Values(scale, scale, scale), );
        child = childAfter(child);
        childIndex = 1;
    }
    if (foregroundChild != nullptr) {
        context.paintChild(foregroundChild, offset);
    }
}

void RenderEditable::_paintHandleLayers(PaintingContext context, List<TextSelectionPoint> endpoints) {
    Offset startPoint = endpoints[0].point;
    startPoint = Offset(clampDouble(startPoint.dx, 0.0, size.width), clampDouble(startPoint.dy, 0.0, size.height));
    context.pushLayer(LeaderLayer(startHandleLayerLink, startPoint), super.paint, Offset.zero);
    if (endpoints.length == 2) {
        Offset endPoint = endpoints[1].point;
        endPoint = Offset(clampDouble(endPoint.dx, 0.0, size.width), clampDouble(endPoint.dy, 0.0, size.height));
        context.pushLayer(LeaderLayer(endHandleLayerLink, endPoint), super.paint, Offset.zero);
    }
}

RenderEditable _RenderEditableCustomPaint::parent() {
    return (;
}

bool _RenderEditableCustomPaint::isRepaintBoundary() {
    return true;
}

bool _RenderEditableCustomPaint::sizedByParent() {
    return true;
}

RenderEditablePainter _RenderEditableCustomPaint::painter() {
    return _painter;
}

void _RenderEditableCustomPaint::painter(RenderEditablePainter newValue) {
    if (newValue == painter) {
        return;
    }
    RenderEditablePainter oldPainter = painter;
    _painter = newValue;
    if (newValue?.shouldRepaint(oldPainter) ?? true) {
        markNeedsPaint();
    }
    if (attached) {
        oldPainter?.removeListener(markNeedsPaint);
        newValue?.addListener(markNeedsPaint);
    }
}

void _RenderEditableCustomPaint::paint(PaintingContext context, Offset offset) {
    RenderEditable parent = this.parent;
    assert(parent != nullptr);
    RenderEditablePainter painter = this.painter;
    if (painter != nullptr && parent != nullptr) {
        parent._computeTextMetricsIfNeeded();
        painter.paint(context.canvas, size, parent);
    }
}

void _RenderEditableCustomPaint::attach(PipelineOwner owner) {
    super.attach(owner);
    _painter?.addListener(markNeedsPaint);
}

void _RenderEditableCustomPaint::detach() {
    _painter?.removeListener(markNeedsPaint);
    super.detach();
}

Size _RenderEditableCustomPaint::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

_RenderEditableCustomPaint::_RenderEditableCustomPaint(RenderEditablePainter painter) {
    {
        _painter = painter;
        super();
    }
}

Color _TextHighlightPainter::highlightColor() {
    return _highlightColor;
}

void _TextHighlightPainter::highlightColor(Color newValue) {
    if (newValue == _highlightColor) {
        return;
    }
    _highlightColor = newValue;
    notifyListeners();
}

TextRange _TextHighlightPainter::highlightedRange() {
    return _highlightedRange;
}

void _TextHighlightPainter::highlightedRange(TextRange newValue) {
    if (newValue == _highlightedRange) {
        return;
    }
    _highlightedRange = newValue;
    notifyListeners();
}

BoxHeightStyle _TextHighlightPainter::selectionHeightStyle() {
    return _selectionHeightStyle;
}

void _TextHighlightPainter::selectionHeightStyle(BoxHeightStyle value) {
    assert(value != nullptr);
    if (_selectionHeightStyle == value) {
        return;
    }
    _selectionHeightStyle = value;
    notifyListeners();
}

BoxWidthStyle _TextHighlightPainter::selectionWidthStyle() {
    return _selectionWidthStyle;
}

void _TextHighlightPainter::selectionWidthStyle(BoxWidthStyle value) {
    assert(value != nullptr);
    if (_selectionWidthStyle == value) {
        return;
    }
    _selectionWidthStyle = value;
    notifyListeners();
}

void _TextHighlightPainter::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    TextRange range = highlightedRange;
    Color color = highlightColor;
    if (range == nullptr || color == nullptr || range.isCollapsed) {
        return;
    }
    highlightPaint.color = color;
    TextPainter textPainter = renderEditable._textPainter;
    List<TextBox> boxes = textPainter.getBoxesForSelection(TextSelection(range.start, range.end)selectionHeightStyle, selectionWidthStyle);
    for (TextBox box : boxes) {
        canvas.drawRect(box.toRect().shift(renderEditable._paintOffset).intersect(Rect.fromLTWH(0, 0, textPainter.width, textPainter.height)), highlightPaint);
    }
}

bool _TextHighlightPainter::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(oldDelegate, this)) {
        return false;
    }
    if (oldDelegate == nullptr) {
        return highlightColor != nullptr && highlightedRange != nullptr;
    }
    return oldDelegate is! _TextHighlightPainter || oldDelegate.highlightColor != highlightColor || oldDelegate.highlightedRange != highlightedRange || oldDelegate.selectionHeightStyle != selectionHeightStyle || oldDelegate.selectionWidthStyle != selectionWidthStyle;
}

_TextHighlightPainter::_TextHighlightPainter(Color highlightColor, TextRange highlightedRange) {
    {
        _highlightedRange = highlightedRange;
        _highlightColor = highlightColor;
    }
}

bool _FloatingCursorPainter::shouldPaint() {
    return _shouldPaint;
}

void _FloatingCursorPainter::shouldPaint(bool value) {
    if (shouldPaint == value) {
        return;
    }
    _shouldPaint = value;
    notifyListeners();
}

Color _FloatingCursorPainter::caretColor() {
    return _caretColor;
}

void _FloatingCursorPainter::caretColor(Color value) {
    if (caretColor?.value == value?.value) {
        return;
    }
    _caretColor = value;
    notifyListeners();
}

Radius _FloatingCursorPainter::cursorRadius() {
    return _cursorRadius;
}

void _FloatingCursorPainter::cursorRadius(Radius value) {
    if (_cursorRadius == value) {
        return;
    }
    _cursorRadius = value;
    notifyListeners();
}

Offset _FloatingCursorPainter::cursorOffset() {
    return _cursorOffset;
}

void _FloatingCursorPainter::cursorOffset(Offset value) {
    if (_cursorOffset == value) {
        return;
    }
    _cursorOffset = value;
    notifyListeners();
}

Color _FloatingCursorPainter::backgroundCursorColor() {
    return _backgroundCursorColor;
}

void _FloatingCursorPainter::backgroundCursorColor(Color value) {
    if (backgroundCursorColor?.value == value?.value) {
        return;
    }
    _backgroundCursorColor = value;
    if (showRegularCaret) {
        notifyListeners();
    }
}

Rect _FloatingCursorPainter::floatingCursorRect() {
    return _floatingCursorRect;
}

void _FloatingCursorPainter::floatingCursorRect(Rect value) {
    if (_floatingCursorRect == value) {
        return;
    }
    _floatingCursorRect = value;
    notifyListeners();
}

void _FloatingCursorPainter::paintRegularCursor(Canvas canvas, Color caretColor, RenderEditable renderEditable, TextPosition textPosition) {
    Rect caretPrototype = renderEditable._caretPrototype;
    Offset caretOffset = renderEditable._textPainter.getOffsetForCaret(textPosition, caretPrototype);
    Rect caretRect = caretPrototype.shift(caretOffset + cursorOffset);
    double caretHeight = renderEditable._textPainter.getFullHeightForCaret(textPosition, caretPrototype);
    if (caretHeight != nullptr) {
        ;
    }
    caretRect = caretRect.shift(renderEditable._paintOffset);
    Rect integralRect = caretRect.shift(renderEditable._snapToPhysicalPixel(caretRect.topLeft));
    if (shouldPaint) {
        Radius radius = cursorRadius;
        caretPaint.color = caretColor;
        if (radius == nullptr) {
            canvas.drawRect(integralRect, caretPaint);
        } else {
            RRect caretRRect = RRect.fromRectAndRadius(integralRect, radius);
            canvas.drawRRect(caretRRect, caretPaint);
        }
    }
    caretPaintCallback(integralRect);
}

void _FloatingCursorPainter::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    assert(renderEditable != nullptr);
    TextSelection selection = renderEditable.selection;
    if (selection == nullptr || !selection.isCollapsed) {
        return;
    }
    Rect floatingCursorRect = this.floatingCursorRect;
    Color caretColor = floatingCursorRect == nullptr? this.caretColor : showRegularCaret? backgroundCursorColor : nullptr;
    TextPosition caretTextPosition = floatingCursorRect == nullptr? selection.extent : renderEditable._floatingCursorTextPosition;
    if (caretColor != nullptr) {
        paintRegularCursor(canvas, renderEditable, caretColor, caretTextPosition);
    }
    Color floatingCursorColor = this.caretColor?.withOpacity(0.75);
    if (floatingCursorRect == nullptr || floatingCursorColor == nullptr || !shouldPaint) {
        return;
    }
    canvas.drawRRect(RRect.fromRectAndRadius(floatingCursorRect.shift(renderEditable._paintOffset), _kFloatingCaretRadius), );
}

bool _FloatingCursorPainter::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(this, oldDelegate)) {
        return false;
    }
    if (oldDelegate == nullptr) {
        return shouldPaint;
    }
    return oldDelegate is! _FloatingCursorPainter || oldDelegate.shouldPaint != shouldPaint || oldDelegate.showRegularCaret != showRegularCaret || oldDelegate.caretColor != caretColor || oldDelegate.cursorRadius != cursorRadius || oldDelegate.cursorOffset != cursorOffset || oldDelegate.backgroundCursorColor != backgroundCursorColor || oldDelegate.floatingCursorRect != floatingCursorRect;
}

void _CompositeRenderEditablePainter::addListener(VoidCallback listener) {
    for (RenderEditablePainter painter : painters) {
        painter.addListener(listener);
    }
}

void _CompositeRenderEditablePainter::removeListener(VoidCallback listener) {
    for (RenderEditablePainter painter : painters) {
        painter.removeListener(listener);
    }
}

void _CompositeRenderEditablePainter::paint(Canvas canvas, RenderEditable renderEditable, Size size) {
    for (RenderEditablePainter painter : painters) {
        painter.paint(canvas, size, renderEditable);
    }
}

bool _CompositeRenderEditablePainter::shouldRepaint(RenderEditablePainter oldDelegate) {
    if (identical(oldDelegate, this)) {
        return false;
    }
    if (oldDelegate is! _CompositeRenderEditablePainter || oldDelegate.painters.length != painters.length) {
        return true;
    }
    Iterator<RenderEditablePainter> oldPainters = oldDelegate.painters.iterator;
    Iterator<RenderEditablePainter> newPainters = painters.iterator;
    while (oldPainters.moveNext() && newPainters.moveNext()) {
        if (newPainters.current.shouldRepaint(oldPainters.current)) {
            return true;
        }
    }
    return false;
}
