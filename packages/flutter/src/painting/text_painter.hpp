#ifndef PACKAGES_FLUTTER_SRC_PAINTING_TEXT_PAINTER
#define PACKAGES_FLUTTER_SRC_PAINTING_TEXT_PAINTER
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "placeholder_span.hpp"
#include "strut_style.hpp"
#include "text_span.hpp"

double _kDefaultFontSize;


enum TextOverflow{
    clip,
    fade,
    ellipsis,
    visible,
} // end TextOverflow

class PlaceholderDimensionsCls : public ObjectCls {
public:
    static PlaceholderDimensions empty;

    Size size;

    PlaceholderAlignment alignment;

    double baselineOffset;

    TextBaseline baseline;


     PlaceholderDimensionsCls(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, Size size);

    virtual String toString();

private:

};
using PlaceholderDimensions = std::shared_ptr<PlaceholderDimensionsCls>;

enum TextWidthBasis{
    parent,
    longestLine,
} // end TextWidthBasis

class _CaretMetricsCls : public ObjectCls {
public:
    Offset offset;

    double fullHeight;


private:

     _CaretMetricsCls(double fullHeight, Offset offset);
};
using _CaretMetrics = std::shared_ptr<_CaretMetricsCls>;

class TextPainterCls : public ObjectCls {
public:

     TextPainterCls(String ellipsis, Locale locale, int maxLines, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    virtual void markNeedsLayout();

    virtual InlineSpan text();

    virtual void  text(InlineSpan value);

    virtual TextAlign textAlign();

    virtual void  textAlign(TextAlign value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual double textScaleFactor();

    virtual void  textScaleFactor(double value);

    virtual String ellipsis();

    virtual void  ellipsis(String value);

    virtual Locale locale();

    virtual void  locale(Locale value);

    virtual int maxLines();

    virtual void  maxLines(int value);

    virtual StrutStyle strutStyle();

    virtual void  strutStyle(StrutStyle value);

    virtual TextWidthBasis textWidthBasis();

    virtual void  textWidthBasis(TextWidthBasis value);

    virtual TextHeightBehavior textHeightBehavior();

    virtual void  textHeightBehavior(TextHeightBehavior value);

    virtual List<TextBox> inlinePlaceholderBoxes();

    virtual List<double> inlinePlaceholderScales();

    virtual void setPlaceholderDimensions(List<PlaceholderDimensions> value);

    virtual double preferredLineHeight();

    virtual double minIntrinsicWidth();

    virtual double maxIntrinsicWidth();

    virtual double width();

    virtual double height();

    virtual Size size();

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool didExceedMaxLines();

    virtual void layout(double maxWidth, double minWidth);

    virtual void paint(Canvas canvas, Offset offset);

    virtual int getOffsetAfter(int offset);

    virtual int getOffsetBefore(int offset);

    virtual Offset getOffsetForCaret(TextPosition position, Rect caretPrototype);

    virtual double getFullHeightForCaret(TextPosition position, Rect caretPrototype);

    virtual List<TextBox> getBoxesForSelection(TextSelection selection, BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle);

    virtual TextPosition getPositionForOffset(Offset offset);

    virtual TextRange getWordBoundary(TextPosition position);

    virtual TextRange getLineBoundary(TextPosition position);

    virtual List<LineMetrics> computeLineMetrics();

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

    static int _zwjUtf16;

    _CaretMetrics _caretMetrics;

    TextPosition _previousCaretPosition;

    Rect _previousCaretPrototype;

    List<LineMetrics> _lineMetricsCache;


    virtual bool _debugNeedsLayout();

    virtual ParagraphStyle _createParagraphStyle(TextDirection defaultTextDirection);

    virtual Paragraph _createLayoutTemplate();

    virtual double _applyFloatingPointHack(double layoutValue);

    virtual void _createParagraph();

    virtual void _layoutParagraph(double minWidth, double maxWidth);

    static bool _isUtf16Surrogate(int value);

    static bool _isUnicodeDirectionality(int value);

    virtual Rect _getRectFromUpstream(int offset, Rect caretPrototype);

    virtual Rect _getRectFromDownstream(int offset, Rect caretPrototype);

    virtual Offset _emptyOffset();

    virtual void _computeCaretMetrics(TextPosition position, Rect caretPrototype);

};
using TextPainter = std::shared_ptr<TextPainterCls>;


#endif