#include "text_painter.hpp"
PlaceholderDimensions::PlaceholderDimensions(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, Size size) {
    {
        assert(size != nullptr);
        assert(alignment != nullptr);
    }
}

String PlaceholderDimensions::toString() {
    return "PlaceholderDimensions($size, $baseline)";
}

TextPainter::TextPainter(String ellipsis, Locale locale, int maxLines, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(text == nullptr || text.debugAssertIsValid());
        assert(textAlign != nullptr);
        assert(textScaleFactor != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
        _text = text;
        _textAlign = textAlign;
        _textDirection = textDirection;
        _textScaleFactor = textScaleFactor;
        _maxLines = maxLines;
        _ellipsis = ellipsis;
        _locale = locale;
        _strutStyle = strutStyle;
        _textWidthBasis = textWidthBasis;
        _textHeightBehavior = textHeightBehavior;
    }
}

void TextPainter::markNeedsLayout() {
    _paragraph = nullptr;
    _lineMetricsCache = nullptr;
    _previousCaretPosition = nullptr;
    _previousCaretPrototype = nullptr;
}

InlineSpan TextPainter::text() {
    return _text;
}

void TextPainter::text(InlineSpan value) {
    assert(value == nullptr || value.debugAssertIsValid());
    if (_text == value) {
        return;
    }
    if (_text?.style != value?.style) {
        _layoutTemplate = nullptr;
    }
    RenderComparison comparison = value == nullptr? RenderComparison.layout : _text?.compareTo(value) ?? RenderComparison.layout;
    _text = value;
    if (comparison.index >= RenderComparison.layout.index) {
        markNeedsLayout();
    } else     {
        if (comparison.index >= RenderComparison.paint.index) {
        _rebuildParagraphForPaint = true;
    }
;
    }}

TextAlign TextPainter::textAlign() {
    return _textAlign;
}

void TextPainter::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textAlign == value) {
        return;
    }
    _textAlign = value;
    markNeedsLayout();
}

TextDirection TextPainter::textDirection() {
    return _textDirection;
}

void TextPainter::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
    _layoutTemplate = nullptr;
}

double TextPainter::textScaleFactor() {
    return _textScaleFactor;
}

void TextPainter::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textScaleFactor == value) {
        return;
    }
    _textScaleFactor = value;
    markNeedsLayout();
    _layoutTemplate = nullptr;
}

String TextPainter::ellipsis() {
    return _ellipsis;
}

void TextPainter::ellipsis(String value) {
    assert(value == nullptr || value.isNotEmpty);
    if (_ellipsis == value) {
        return;
    }
    _ellipsis = value;
    markNeedsLayout();
}

Locale TextPainter::locale() {
    return _locale;
}

void TextPainter::locale(Locale value) {
    if (_locale == value) {
        return;
    }
    _locale = value;
    markNeedsLayout();
}

int TextPainter::maxLines() {
    return _maxLines;
}

void TextPainter::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (_maxLines == value) {
        return;
    }
    _maxLines = value;
    markNeedsLayout();
}

StrutStyle TextPainter::strutStyle() {
    return _strutStyle;
}

void TextPainter::strutStyle(StrutStyle value) {
    if (_strutStyle == value) {
        return;
    }
    _strutStyle = value;
    markNeedsLayout();
}

TextWidthBasis TextPainter::textWidthBasis() {
    return _textWidthBasis;
}

void TextPainter::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textWidthBasis == value) {
        return;
    }
    _textWidthBasis = value;
    markNeedsLayout();
}

TextHeightBehavior TextPainter::textHeightBehavior() {
    return _textHeightBehavior;
}

void TextPainter::textHeightBehavior(TextHeightBehavior value) {
    if (_textHeightBehavior == value) {
        return;
    }
    _textHeightBehavior = value;
    markNeedsLayout();
}

List<TextBox> TextPainter::inlinePlaceholderBoxes() {
    return _inlinePlaceholderBoxes;
}

List<double> TextPainter::inlinePlaceholderScales() {
    return _inlinePlaceholderScales;
}

void TextPainter::setPlaceholderDimensions(List<PlaceholderDimensions> value) {
    if (value == nullptr || value.isEmpty || listEquals(value, _placeholderDimensions)) {
        return;
    }
    assert(() == value.length);
    _placeholderDimensions = value;
    markNeedsLayout();
}

double TextPainter::preferredLineHeight() {
    return (_layoutTemplate ??= _createLayoutTemplate()).height;
}

double TextPainter::minIntrinsicWidth() {
    assert(!_debugNeedsLayout);
    return _applyFloatingPointHack(_paragraph!.minIntrinsicWidth);
}

double TextPainter::maxIntrinsicWidth() {
    assert(!_debugNeedsLayout);
    return _applyFloatingPointHack(_paragraph!.maxIntrinsicWidth);
}

double TextPainter::width() {
    assert(!_debugNeedsLayout);
    return _applyFloatingPointHack(textWidthBasis == TextWidthBasis.longestLine? _paragraph!.longestLine : _paragraph!.width);
}

double TextPainter::height() {
    assert(!_debugNeedsLayout);
    return _applyFloatingPointHack(_paragraph!.height);
}

Size TextPainter::size() {
    assert(!_debugNeedsLayout);
    return Size(width, height);
}

double TextPainter::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!_debugNeedsLayout);
    assert(baseline != nullptr);
    ;
}

bool TextPainter::didExceedMaxLines() {
    assert(!_debugNeedsLayout);
    return _paragraph!.didExceedMaxLines;
}

void TextPainter::layout(double maxWidth, double minWidth) {
    assert(text != nullptr, "TextPainter.text must be set to a non-null value before using the TextPainter.");
    assert(textDirection != nullptr, "TextPainter.textDirection must be set to a non-null value before using the TextPainter.");
    if (_paragraph != nullptr && minWidth == _lastMinWidth && maxWidth == _lastMaxWidth) {
        return;
    }
    if (_rebuildParagraphForPaint || _paragraph == nullptr) {
        _createParagraph();
    }
    _lastMinWidth = minWidth;
    _lastMaxWidth = maxWidth;
    _lineMetricsCache = nullptr;
    _previousCaretPosition = nullptr;
    _previousCaretPrototype = nullptr;
    _layoutParagraph(minWidth, maxWidth);
    _inlinePlaceholderBoxes = _paragraph!.getBoxesForPlaceholders();
}

void TextPainter::paint(Canvas canvas, Offset offset) {
    double minWidth = _lastMinWidth;
    double maxWidth = _lastMaxWidth;
    if (_paragraph == nullptr || minWidth == nullptr || maxWidth == nullptr) {
        ;
    }
    if (_rebuildParagraphForPaint) {
        Size debugSize;
        assert(());
        _createParagraph();
        _layoutParagraph(minWidth, maxWidth);
        assert(debugSize == size);
    }
    canvas.drawParagraph(_paragraph!, offset);
}

int TextPainter::getOffsetAfter(int offset) {
    int nextCodeUnit = _text!.codeUnitAt(offset);
    if (nextCodeUnit == nullptr) {
        return nullptr;
    }
    return _isUtf16Surrogate(nextCodeUnit)? offset + 2 : offset + 1;
}

int TextPainter::getOffsetBefore(int offset) {
    int prevCodeUnit = _text!.codeUnitAt(offset - 1);
    if (prevCodeUnit == nullptr) {
        return nullptr;
    }
    return _isUtf16Surrogate(prevCodeUnit)? offset - 2 : offset - 1;
}

Offset TextPainter::getOffsetForCaret(Rect caretPrototype, TextPosition position) {
    _computeCaretMetrics(position, caretPrototype);
    return _caretMetrics.offset;
}

double TextPainter::getFullHeightForCaret(Rect caretPrototype, TextPosition position) {
    _computeCaretMetrics(position, caretPrototype);
    return _caretMetrics.fullHeight;
}

List<TextBox> TextPainter::getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection) {
    assert(!_debugNeedsLayout);
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    return _paragraph!.getBoxesForRange(selection.start, selection.endboxHeightStyle, boxWidthStyle);
}

TextPosition TextPainter::getPositionForOffset(Offset offset) {
    assert(!_debugNeedsLayout);
    return _paragraph!.getPositionForOffset(offset);
}

TextRange TextPainter::getWordBoundary(TextPosition position) {
    assert(!_debugNeedsLayout);
    return _paragraph!.getWordBoundary(position);
}

TextRange TextPainter::getLineBoundary(TextPosition position) {
    assert(!_debugNeedsLayout);
    return _paragraph!.getLineBoundary(position);
}

List<LineMetrics> TextPainter::computeLineMetrics() {
    assert(!_debugNeedsLayout);
    return _lineMetricsCache ??= _paragraph!.computeLineMetrics();
}

bool TextPainter::_debugNeedsLayout() {
    return _paragraph == nullptr;
}

ParagraphStyle TextPainter::_createParagraphStyle(TextDirection defaultTextDirection) {
    assert(textAlign != nullptr);
    assert(textDirection != nullptr || defaultTextDirection != nullptr, "TextPainter.textDirection must be set to a non-null value before using the TextPainter.");
    return _text!.style?.getParagraphStyle(textAlign, textDirection ?? defaultTextDirection, textScaleFactor, _maxLines, _textHeightBehavior, _ellipsis, _locale, _strutStyle) ?? ui.ParagraphStyle(textAlign, textDirection ?? defaultTextDirection, _kDefaultFontSize * textScaleFactor, maxLines, _textHeightBehavior, ellipsis, locale);
}

Paragraph TextPainter::_createLayoutTemplate() {
    ParagraphBuilder builder = ui.ParagraphBuilder(_createParagraphStyle(TextDirection.rtl));
    TextStyle textStyle = text?.style?.getTextStyle(textScaleFactor);
    if (textStyle != nullptr) {
        builder.pushStyle(textStyle);
    }
    builder.addText(" ");
    return ;
}

double TextPainter::_applyFloatingPointHack(double layoutValue) {
    return layoutValue.ceilToDouble();
}

void TextPainter::_createParagraph() {
    assert(_paragraph == nullptr || _rebuildParagraphForPaint);
    InlineSpan text = this.text;
    if (text == nullptr) {
        ;
    }
    ParagraphBuilder builder = ui.ParagraphBuilder(_createParagraphStyle());
    text.build(buildertextScaleFactor, _placeholderDimensions);
    _inlinePlaceholderScales = builder.placeholderScales;
    _paragraph = builder.build();
    _rebuildParagraphForPaint = false;
}

void TextPainter::_layoutParagraph(double maxWidth, double minWidth) {
    _paragraph!.layout(ui.ParagraphConstraints(maxWidth));
    if (minWidth != maxWidth) {
        double newWidth;
        ;
        newWidth = clampDouble(newWidth, minWidth, maxWidth);
        if (newWidth != _applyFloatingPointHack(_paragraph!.width)) {
            _paragraph!.layout(ui.ParagraphConstraints(newWidth));
        }
    }
}

bool TextPainter::_isUtf16Surrogate(int value) {
    return value & 0xF800 == 0xD800;
}

bool TextPainter::_isUnicodeDirectionality(int value) {
    return value == 0x200F || value == 0x200E;
}

Rect TextPainter::_getRectFromUpstream(Rect caretPrototype, int offset) {
    String flattenedText = _text!.toPlainText(false);
    int prevCodeUnit = _text!.codeUnitAt(max(0, offset - 1));
    if (prevCodeUnit == nullptr) {
        return nullptr;
    }
    int NEWLINE_CODE_UNIT = 10;
    bool needsSearch = _isUtf16Surrogate(prevCodeUnit) || _text!.codeUnitAt(offset) == _zwjUtf16 || _isUnicodeDirectionality(prevCodeUnit);
    int graphemeClusterLength = needsSearch? 2 : 1;
    List<TextBox> boxes = ;
    while (boxes.isEmpty) {
        int prevRuneOffset = offset - graphemeClusterLength;
        boxes = _paragraph!.getBoxesForRange(prevRuneOffset, offsetui.BoxHeightStyle.strut);
        if (boxes.isEmpty) {
            if (!needsSearch && prevCodeUnit == NEWLINE_CODE_UNIT) {
                                break;
            }
            if ( < -flattenedText.length) {
                                break;
            }
            graphemeClusterLength = 2;
            continue;
        }
        TextBox box = boxes.first;
        if (prevCodeUnit == NEWLINE_CODE_UNIT) {
            return Rect.fromLTRB(_emptyOffset.dx, box.bottom, _emptyOffset.dx, box.bottom + box.bottom - box.top);
        }
        double caretEnd = box.end;
        double dx = box.direction == TextDirection.rtl? caretEnd - caretPrototype.width : caretEnd;
        return Rect.fromLTRB(clampDouble(dx, 0, _paragraph!.width), box.top, clampDouble(dx, 0, _paragraph!.width), box.bottom);
    }
    return nullptr;
}

Rect TextPainter::_getRectFromDownstream(Rect caretPrototype, int offset) {
    String flattenedText = _text!.toPlainText(false);
    int nextCodeUnit = _text!.codeUnitAt(min(offset, flattenedText.length - 1));
    if (nextCodeUnit == nullptr) {
        return nullptr;
    }
    bool needsSearch = _isUtf16Surrogate(nextCodeUnit) || nextCodeUnit == _zwjUtf16 || _isUnicodeDirectionality(nextCodeUnit);
    int graphemeClusterLength = needsSearch? 2 : 1;
    List<TextBox> boxes = ;
    while (boxes.isEmpty) {
        int nextRuneOffset = offset + graphemeClusterLength;
        boxes = _paragraph!.getBoxesForRange(offset, nextRuneOffsetui.BoxHeightStyle.strut);
        if (boxes.isEmpty) {
            if (!needsSearch) {
                                break;
            }
            if (nextRuneOffset >= flattenedText.length << 1) {
                                break;
            }
            graphemeClusterLength = 2;
            continue;
        }
        TextBox box = boxes.last;
        double caretStart = box.start;
        double dx = box.direction == TextDirection.rtl? caretStart - caretPrototype.width : caretStart;
        return Rect.fromLTRB(clampDouble(dx, 0, _paragraph!.width), box.top, clampDouble(dx, 0, _paragraph!.width), box.bottom);
    }
    return nullptr;
}

Offset TextPainter::_emptyOffset() {
    assert(!_debugNeedsLayout);
    assert(textAlign != nullptr);
    ;
}

void TextPainter::_computeCaretMetrics(Rect caretPrototype, TextPosition position) {
    assert(!_debugNeedsLayout);
    if (position == _previousCaretPosition && caretPrototype == _previousCaretPrototype) {
        return;
    }
    int offset = position.offset;
    assert(position.affinity != nullptr);
    Rect rect;
    ;
    _caretMetrics = _CaretMetrics(rect != nullptr? Offset(rect.left, rect.top) : _emptyOffset, rect != nullptr? rect.bottom - rect.top : nullptr);
    _previousCaretPosition = position;
    _previousCaretPrototype = caretPrototype;
}
