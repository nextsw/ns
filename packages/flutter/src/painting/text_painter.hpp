#ifndef TEXT_PAINTER_H
#define TEXT_PAINTER_H
#include <memory>
#include <flutter/services.hpp>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "placeholder_span.hpp"
#include "strut_style.hpp"
#include "text_span.hpp"


const double _kDefaultFontSize;


enum TextOverflow{
    clip,
    fade,
    ellipsis,
    visible,
} // end TextOverflow

class PlaceholderDimensions {
public:
    static const PlaceholderDimensions empty;

    Size size;

    PlaceholderAlignment alignment;

    double baselineOffset;

    TextBaseline baseline;


     PlaceholderDimensions(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, Size size);

    String toString();

private:

};

enum TextWidthBasis{
    parent,
    longestLine,
} // end TextWidthBasis

class _CaretMetrics {
public:
    Offset offset;

    double fullHeight;


private:

     _CaretMetrics(double fullHeight, Offset offset);

};

class TextPainter {
public:

     TextPainter(String ellipsis, Locale locale, int maxLines, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    void markNeedsLayout();

    InlineSpan text();

    void  text(InlineSpan value);

    TextAlign textAlign();

    void  textAlign(TextAlign value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    double textScaleFactor();

    void  textScaleFactor(double value);

    String ellipsis();

    void  ellipsis(String value);

    Locale locale();

    void  locale(Locale value);

    int maxLines();

    void  maxLines(int value);

    StrutStyle strutStyle();

    void  strutStyle(StrutStyle value);

    TextWidthBasis textWidthBasis();

    void  textWidthBasis(TextWidthBasis value);

    TextHeightBehavior textHeightBehavior();

    void  textHeightBehavior(TextHeightBehavior value);

    List<TextBox> inlinePlaceholderBoxes();

    List<double> inlinePlaceholderScales();

    void setPlaceholderDimensions(List<PlaceholderDimensions> value);

    double preferredLineHeight();

    double minIntrinsicWidth();

    double maxIntrinsicWidth();

    double width();

    double height();

    Size size();

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool didExceedMaxLines();

    void layout(double maxWidth, double minWidth);

    void paint(Canvas canvas, Offset offset);

    int getOffsetAfter(int offset);

    int getOffsetBefore(int offset);

    Offset getOffsetForCaret(Rect caretPrototype, TextPosition position);

    double getFullHeightForCaret(Rect caretPrototype, TextPosition position);

    List<TextBox> getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection);

    TextPosition getPositionForOffset(Offset offset);

    TextRange getWordBoundary(TextPosition position);

    TextRange getLineBoundary(TextPosition position);

    List<LineMetrics> computeLineMetrics();

private:
    Paragraph _paragraph;

    bool _rebuildParagraphForPaint;

    InlineSpan _text;

    TextAlign _textAlign;

    TextDirection _textDirection;

    double _textScaleFactor;

    String _ellipsis;

    Locale _locale;

    int _maxLines;

    StrutStyle _strutStyle;

    TextWidthBasis _textWidthBasis;

    TextHeightBehavior _textHeightBehavior;

    List<TextBox> _inlinePlaceholderBoxes;

    List<double> _inlinePlaceholderScales;

    List<PlaceholderDimensions> _placeholderDimensions;

    Paragraph _layoutTemplate;

    double _lastMinWidth;

    double _lastMaxWidth;

    static const int _zwjUtf16;

    _CaretMetrics _caretMetrics;

    TextPosition _previousCaretPosition;

    Rect _previousCaretPrototype;

    List<LineMetrics> _lineMetricsCache;


    bool _debugNeedsLayout();

    ParagraphStyle _createParagraphStyle(TextDirection defaultTextDirection);

    Paragraph _createLayoutTemplate();

    double _applyFloatingPointHack(double layoutValue);

    void _createParagraph();

    void _layoutParagraph(double maxWidth, double minWidth);

    static bool _isUtf16Surrogate(int value);

    static bool _isUnicodeDirectionality(int value);

    Rect _getRectFromUpstream(Rect caretPrototype, int offset);

    Rect _getRectFromDownstream(Rect caretPrototype, int offset);

    Offset _emptyOffset();

    void _computeCaretMetrics(Rect caretPrototype, TextPosition position);

};

#endif