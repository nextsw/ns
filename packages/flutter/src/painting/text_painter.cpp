#include "text_painter.hpp"
PlaceholderDimensionsCls::PlaceholderDimensionsCls(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, Size size) {
    {
        assert(size != nullptr);
        assert(alignment != nullptr);
    }
}

String PlaceholderDimensionsCls::toString() {
    return __s("PlaceholderDimensions($size, $baseline)");
}

TextPainterCls::TextPainterCls(String ellipsis, Locale locale, int maxLines, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(text() == nullptr || text()->debugAssertIsValid());
        assert(textAlign() != nullptr);
        assert(textScaleFactor() != nullptr);
        assert(maxLines() == nullptr || maxLines() > 0);
        assert(textWidthBasis() != nullptr);
        _text = text();
        _textAlign = textAlign();
        _textDirection = textDirection();
        _textScaleFactor = textScaleFactor();
        _maxLines = maxLines();
        _ellipsis = ellipsis();
        _locale = locale();
        _strutStyle = strutStyle();
        _textWidthBasis = textWidthBasis();
        _textHeightBehavior = textHeightBehavior();
    }
}

void TextPainterCls::markNeedsLayout() {
    _paragraph = nullptr;
    _lineMetricsCache = nullptr;
    _previousCaretPosition = nullptr;
    _previousCaretPrototype = nullptr;
}

InlineSpan TextPainterCls::text() {
    return _text;
}

void TextPainterCls::text(InlineSpan value) {
    assert(value == nullptr || value->debugAssertIsValid());
    if (_text == value) {
        return;
    }
    if (_text?->style != value?->style) {
        _layoutTemplate = nullptr;
    }
    RenderComparison comparison = value == nullptr? RenderComparisonCls::layout : _text?->compareTo(value) or RenderComparisonCls::layout;
    _text = value;
    if (comparison->index >= RenderComparisonCls::layout->index) {
        markNeedsLayout();
    } else     {
        if (comparison->index >= RenderComparisonCls::paint->index) {
        _rebuildParagraphForPaint = true;
    }
;
    }}

TextAlign TextPainterCls::textAlign() {
    return _textAlign;
}

void TextPainterCls::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textAlign == value) {
        return;
    }
    _textAlign = value;
    markNeedsLayout();
}

TextDirection TextPainterCls::textDirection() {
    return _textDirection;
}

void TextPainterCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
    _layoutTemplate = nullptr;
}

double TextPainterCls::textScaleFactor() {
    return _textScaleFactor;
}

void TextPainterCls::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textScaleFactor == value) {
        return;
    }
    _textScaleFactor = value;
    markNeedsLayout();
    _layoutTemplate = nullptr;
}

String TextPainterCls::ellipsis() {
    return _ellipsis;
}

void TextPainterCls::ellipsis(String value) {
    assert(value == nullptr || value->isNotEmpty);
    if (_ellipsis == value) {
        return;
    }
    _ellipsis = value;
    markNeedsLayout();
}

Locale TextPainterCls::locale() {
    return _locale;
}

void TextPainterCls::locale(Locale value) {
    if (_locale == value) {
        return;
    }
    _locale = value;
    markNeedsLayout();
}

int TextPainterCls::maxLines() {
    return _maxLines;
}

void TextPainterCls::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (_maxLines == value) {
        return;
    }
    _maxLines = value;
    markNeedsLayout();
}

StrutStyle TextPainterCls::strutStyle() {
    return _strutStyle;
}

void TextPainterCls::strutStyle(StrutStyle value) {
    if (_strutStyle == value) {
        return;
    }
    _strutStyle = value;
    markNeedsLayout();
}

TextWidthBasis TextPainterCls::textWidthBasis() {
    return _textWidthBasis;
}

void TextPainterCls::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textWidthBasis == value) {
        return;
    }
    _textWidthBasis = value;
    markNeedsLayout();
}

TextHeightBehavior TextPainterCls::textHeightBehavior() {
    return _textHeightBehavior;
}

void TextPainterCls::textHeightBehavior(TextHeightBehavior value) {
    if (_textHeightBehavior == value) {
        return;
    }
    _textHeightBehavior = value;
    markNeedsLayout();
}

List<TextBox> TextPainterCls::inlinePlaceholderBoxes() {
    return _inlinePlaceholderBoxes;
}

List<double> TextPainterCls::inlinePlaceholderScales() {
    return _inlinePlaceholderScales;
}

void TextPainterCls::setPlaceholderDimensions(List<PlaceholderDimensions> value) {
    if (value == nullptr || value->isEmpty || listEquals(value, _placeholderDimensions)) {
        return;
    }
    assert([=] () {
        int placeholderCount = 0;
        text()!->visitChildren([=] (InlineSpan span) {
            if (is<PlaceholderSpan>(span)) {
                placeholderCount = 1;
            }
            return true;
        });
        return placeholderCount;
    }() == value->length);
    _placeholderDimensions = value;
    markNeedsLayout();
}

double TextPainterCls::preferredLineHeight() {
    return (_layoutTemplate ??= _createLayoutTemplate())->height();
}

double TextPainterCls::minIntrinsicWidth() {
    assert(!_debugNeedsLayout());
    return _applyFloatingPointHack(_paragraph!->minIntrinsicWidth());
}

double TextPainterCls::maxIntrinsicWidth() {
    assert(!_debugNeedsLayout());
    return _applyFloatingPointHack(_paragraph!->maxIntrinsicWidth());
}

double TextPainterCls::width() {
    assert(!_debugNeedsLayout());
    return _applyFloatingPointHack(textWidthBasis() == TextWidthBasisCls::longestLine? _paragraph!->longestLine() : _paragraph!->width());
}

double TextPainterCls::height() {
    assert(!_debugNeedsLayout());
    return _applyFloatingPointHack(_paragraph!->height());
}

Size TextPainterCls::size() {
    assert(!_debugNeedsLayout());
    return make<SizeCls>(width(), height());
}

double TextPainterCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!_debugNeedsLayout());
    assert(baseline != nullptr);
    ;
}

bool TextPainterCls::didExceedMaxLines() {
    assert(!_debugNeedsLayout());
    return _paragraph!->didExceedMaxLines();
}

void TextPainterCls::layout(double maxWidth, double minWidth) {
    assert(text() != nullptr, __s("TextPainter.text must be set to a non-null value before using the TextPainter."));
    assert(textDirection() != nullptr, __s("TextPainter.textDirection must be set to a non-null value before using the TextPainter."));
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
    _inlinePlaceholderBoxes = _paragraph!->getBoxesForPlaceholders();
}

void TextPainterCls::paint(Canvas canvas, Offset offset) {
    double minWidth = _lastMinWidth;
    double maxWidth = _lastMaxWidth;
    if (_paragraph == nullptr || minWidth == nullptr || maxWidth == nullptr) {
        ;
    }
    if (_rebuildParagraphForPaint) {
        Size debugSize;
        assert([=] () {
            debugSize = size();
            return true;
        }());
        _createParagraph();
        _layoutParagraph(minWidth, maxWidth);
        assert(debugSize == size());
    }
    canvas->drawParagraph(_paragraph!, offset);
}

int TextPainterCls::getOffsetAfter(int offset) {
    int nextCodeUnit = _text!->codeUnitAt(offset);
    if (nextCodeUnit == nullptr) {
        return nullptr;
    }
    return _isUtf16Surrogate(nextCodeUnit)? offset + 2 : offset + 1;
}

int TextPainterCls::getOffsetBefore(int offset) {
    int prevCodeUnit = _text!->codeUnitAt(offset - 1);
    if (prevCodeUnit == nullptr) {
        return nullptr;
    }
    return _isUtf16Surrogate(prevCodeUnit)? offset - 2 : offset - 1;
}

Offset TextPainterCls::getOffsetForCaret(Rect caretPrototype, TextPosition position) {
    _computeCaretMetrics(position, caretPrototype);
    return _caretMetrics->offset;
}

double TextPainterCls::getFullHeightForCaret(Rect caretPrototype, TextPosition position) {
    _computeCaretMetrics(position, caretPrototype);
    return _caretMetrics->fullHeight;
}

List<TextBox> TextPainterCls::getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection) {
    assert(!_debugNeedsLayout());
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    return _paragraph!->getBoxesForRange(selection->start, selection->endboxHeightStyle, boxWidthStyle);
}

TextPosition TextPainterCls::getPositionForOffset(Offset offset) {
    assert(!_debugNeedsLayout());
    return _paragraph!->getPositionForOffset(offset);
}

TextRange TextPainterCls::getWordBoundary(TextPosition position) {
    assert(!_debugNeedsLayout());
    return _paragraph!->getWordBoundary(position);
}

TextRange TextPainterCls::getLineBoundary(TextPosition position) {
    assert(!_debugNeedsLayout());
    return _paragraph!->getLineBoundary(position);
}

List<LineMetrics> TextPainterCls::computeLineMetrics() {
    assert(!_debugNeedsLayout());
    return _lineMetricsCache ??= _paragraph!->computeLineMetrics();
}

bool TextPainterCls::_debugNeedsLayout() {
    return _paragraph == nullptr;
}

ParagraphStyle TextPainterCls::_createParagraphStyle(TextDirection defaultTextDirection) {
    assert(textAlign() != nullptr);
    assert(textDirection() != nullptr || defaultTextDirection != nullptr, __s("TextPainter.textDirection must be set to a non-null value before using the TextPainter."));
    return _text!->style?->getParagraphStyle(textAlign(), textDirection() or defaultTextDirection, textScaleFactor(), _maxLines, _textHeightBehavior, _ellipsis, _locale, _strutStyle) or ui->make<ParagraphStyleCls>(textAlign(), textDirection() or defaultTextDirection, _kDefaultFontSize * textScaleFactor(), maxLines(), _textHeightBehavior, ellipsis(), locale());
}

Paragraph TextPainterCls::_createLayoutTemplate() {
    ParagraphBuilder builder = ui->make<ParagraphBuilderCls>(_createParagraphStyle(TextDirectionCls::rtl));
    TextStyle textStyle = text()?->style?->getTextStyle(textScaleFactor());
    if (textStyle != nullptr) {
        builder->pushStyle(textStyle);
    }
    builder->addText(__s(" "));
    auto _c1 = builder->build();_c1.layout(ui->make<ParagraphConstraintsCls>(double->infinity));return _c1;
}

double TextPainterCls::_applyFloatingPointHack(double layoutValue) {
    return layoutValue->ceilToDouble();
}

void TextPainterCls::_createParagraph() {
    assert(_paragraph == nullptr || _rebuildParagraphForPaint);
    InlineSpan text = this->text;
    if (text() == nullptr) {
        ;
    }
    ParagraphBuilder builder = ui->make<ParagraphBuilderCls>(_createParagraphStyle());
    text()->build(buildertextScaleFactor(), _placeholderDimensions);
    _inlinePlaceholderScales = builder->placeholderScales;
    _paragraph = builder->build();
    _rebuildParagraphForPaint = false;
}

void TextPainterCls::_layoutParagraph(double maxWidth, double minWidth) {
    _paragraph!->layout(ui->make<ParagraphConstraintsCls>(maxWidth));
    if (minWidth != maxWidth) {
        double newWidth;
        ;
        newWidth = clampDouble(newWidth, minWidth, maxWidth);
        if (newWidth != _applyFloatingPointHack(_paragraph!->width())) {
            _paragraph!->layout(ui->make<ParagraphConstraintsCls>(newWidth));
        }
    }
}

bool TextPainterCls::_isUtf16Surrogate(int value) {
    return value & 0xF800 == 0xD800;
}

bool TextPainterCls::_isUnicodeDirectionality(int value) {
    return value == 0x200F || value == 0x200E;
}

Rect TextPainterCls::_getRectFromUpstream(Rect caretPrototype, int offset) {
    String flattenedText = _text!->toPlainText(false);
    int prevCodeUnit = _text!->codeUnitAt(max(0, offset - 1));
    if (prevCodeUnit == nullptr) {
        return nullptr;
    }
    int NEWLINE_CODE_UNIT = 10;
    bool needsSearch = _isUtf16Surrogate(prevCodeUnit) || _text!->codeUnitAt(offset) == _zwjUtf16 || _isUnicodeDirectionality(prevCodeUnit);
    int graphemeClusterLength = needsSearch? 2 : 1;
    List<TextBox> boxes = makeList();
    while (boxes->isEmpty) {
        int prevRuneOffset = offset - graphemeClusterLength;
        boxes = _paragraph!->getBoxesForRange(prevRuneOffset, offsetui->BoxHeightStyleCls::strut);
        if (boxes->isEmpty) {
            if (!needsSearch && prevCodeUnit == NEWLINE_CODE_UNITCls) {
                                break;
            }
            if ( < -flattenedText->length) {
                                break;
            }
            graphemeClusterLength = 2;
            continue;
        }
        TextBox box = boxes->first;
        if (prevCodeUnit == NEWLINE_CODE_UNITCls) {
            return RectCls->fromLTRB(_emptyOffset()->dx(), box->bottom, _emptyOffset()->dx(), box->bottom + box->bottom - box->top);
        }
        double caretEnd = box->end;
        double dx = box->direction == TextDirectionCls::rtl? caretEnd - caretPrototype->width : caretEnd;
        return RectCls->fromLTRB(clampDouble(dx, 0, _paragraph!->width()), box->top, clampDouble(dx, 0, _paragraph!->width()), box->bottom);
    }
    return nullptr;
}

Rect TextPainterCls::_getRectFromDownstream(Rect caretPrototype, int offset) {
    String flattenedText = _text!->toPlainText(false);
    int nextCodeUnit = _text!->codeUnitAt(min(offset, flattenedText->length - 1));
    if (nextCodeUnit == nullptr) {
        return nullptr;
    }
    bool needsSearch = _isUtf16Surrogate(nextCodeUnit) || nextCodeUnit == _zwjUtf16 || _isUnicodeDirectionality(nextCodeUnit);
    int graphemeClusterLength = needsSearch? 2 : 1;
    List<TextBox> boxes = makeList();
    while (boxes->isEmpty) {
        int nextRuneOffset = offset + graphemeClusterLength;
        boxes = _paragraph!->getBoxesForRange(offset, nextRuneOffsetui->BoxHeightStyleCls::strut);
        if (boxes->isEmpty) {
            if (!needsSearch) {
                                break;
            }
            if (nextRuneOffset >= flattenedText->length << 1) {
                                break;
            }
            graphemeClusterLength = 2;
            continue;
        }
        TextBox box = boxes->last;
        double caretStart = box->start;
        double dx = box->direction == TextDirectionCls::rtl? caretStart - caretPrototype->width : caretStart;
        return RectCls->fromLTRB(clampDouble(dx, 0, _paragraph!->width()), box->top, clampDouble(dx, 0, _paragraph!->width()), box->bottom);
    }
    return nullptr;
}

Offset TextPainterCls::_emptyOffset() {
    assert(!_debugNeedsLayout());
    assert(textAlign() != nullptr);
    ;
}

void TextPainterCls::_computeCaretMetrics(Rect caretPrototype, TextPosition position) {
    assert(!_debugNeedsLayout());
    if (position == _previousCaretPosition && caretPrototype == _previousCaretPrototype) {
        return;
    }
    int offset = position->offset;
    assert(position->affinity != nullptr);
    Rect rect;
    ;
    _caretMetrics = make<_CaretMetricsCls>(rect != nullptr? make<OffsetCls>(rect->left, rect->top) : _emptyOffset(), rect != nullptr? rect->bottom - rect->top : nullptr);
    _previousCaretPosition = position;
    _previousCaretPrototype = caretPrototype;
}
