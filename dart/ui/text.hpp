#ifndef DART_UI_TEXT
#define DART_UI_TEXT
#include <base.hpp>

#include <dart/core/core.hpp>


enum FontStyle{
    normal,
    italic,
} // end FontStyle

class FontWeightCls : public ObjectCls {
public:
    int index;

    static FontWeight w100;

    static FontWeight w200;

    static FontWeight w300;

    static FontWeight w400;

    static FontWeight w500;

    static FontWeight w600;

    static FontWeight w700;

    static FontWeight w800;

    static FontWeight w900;

    static FontWeight normal;

    static FontWeight bold;

    static List<FontWeight> values;


    static FontWeight lerp(FontWeight a, FontWeight b, double t);

    virtual String toString();

private:

    virtual void  _(int index);
};
using FontWeight = std::shared_ptr<FontWeightCls>;

class FontFeatureCls : public ObjectCls {
public:
    String feature;

    int value;


     FontFeatureCls(String feature, int value);

    virtual void  enable(String feature);

    virtual void  disable(String feature);

    virtual void  alternative(int value);

    virtual void  alternativeFractions();

    virtual void  contextualAlternates();

    virtual void  caseSensitiveForms();

    virtual void  characterVariant(int value);

    virtual void  denominator();

    virtual void  fractions();

    virtual void  historicalForms();

    virtual void  historicalLigatures();

    virtual void  liningFigures();

    virtual void  localeAware(bool enable);

    virtual void  notationalForms(int value);

    virtual void  numerators();

    virtual void  oldstyleFigures();

    virtual void  ordinalForms();

    virtual void  proportionalFigures();

    virtual void  randomize();

    virtual void  stylisticAlternates();

    virtual void  scientificInferiors();

    virtual void  stylisticSet(int value);

    virtual void  subscripts();

    virtual void  superscripts();

    virtual void  swash(int value);

    virtual void  tabularFigures();

    virtual void  slashedZero();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static int _kEncodedSize;


    virtual void _encode(ByteData byteData);

};
using FontFeature = std::shared_ptr<FontFeatureCls>;

class FontVariationCls : public ObjectCls {
public:
    String axis;

    double value;


     FontVariationCls(String axis, double value);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static int _kEncodedSize;


    virtual void _encode(ByteData byteData);

};
using FontVariation = std::shared_ptr<FontVariationCls>;

enum TextAlign{
    left,
    right,
    center,
    justify,
    start,
    end,
} // end TextAlign

enum TextBaseline{
    alphabetic,
    ideographic,
} // end TextBaseline

class TextDecorationCls : public ObjectCls {
public:
    static TextDecoration none;

    static TextDecoration underline;

    static TextDecoration overline;

    static TextDecoration lineThrough;


    virtual void  combine(List<TextDecoration> decorations);

    virtual bool contains(TextDecoration other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    int _mask;


    virtual void  _(int _mask);
};
using TextDecoration = std::shared_ptr<TextDecorationCls>;

enum TextDecorationStyle{
    solid,
    double,
    dotted,
    dashed,
    wavy,
} // end TextDecorationStyle

enum TextLeadingDistribution{
    proportional,
    even,
} // end TextLeadingDistribution

class TextHeightBehaviorCls : public ObjectCls {
public:
    bool applyHeightToFirstAscent;

    bool applyHeightToLastDescent;

    TextLeadingDistribution leadingDistribution;


     TextHeightBehaviorCls(bool applyHeightToFirstAscent, bool applyHeightToLastDescent, TextLeadingDistribution leadingDistribution);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual void  _fromEncoded(int encoded, TextLeadingDistribution leadingDistribution);

    virtual int _encode();

};
using TextHeightBehavior = std::shared_ptr<TextHeightBehaviorCls>;
template<typename T>
 bool _listEquals(List<T> a, List<T> b);

Int32List _encodeTextStyle(Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, FontWeight fontWeight, FontStyle fontStyle, TextBaseline textBaseline, String fontFamily, List<String> fontFamilyFallback, double fontSize, double letterSpacing, double wordSpacing, double height, Locale locale, Paint background, Paint foreground, List<Shadow> shadows, List<FontFeature> fontFeatures, List<FontVariation> fontVariations);


class TextStyleCls : public ObjectCls {
public:

     TextStyleCls(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    Int32List _encoded;

    String _fontFamily;

    List<String> _fontFamilyFallback;

    double _fontSize;

    double _letterSpacing;

    double _wordSpacing;

    double _height;

    double _decorationThickness;

    Locale _locale;

    Paint _background;

    Paint _foreground;

    List<Shadow> _shadows;

    List<FontFeature> _fontFeatures;

    List<FontVariation> _fontVariations;

    TextLeadingDistribution _leadingDistribution;


};
using TextStyle = std::shared_ptr<TextStyleCls>;
Int32List _encodeParagraphStyle(TextAlign textAlign, TextDirection textDirection, int maxLines, String fontFamily, double fontSize, double height, TextHeightBehavior textHeightBehavior, FontWeight fontWeight, FontStyle fontStyle, StrutStyle strutStyle, String ellipsis, Locale locale);


class ParagraphStyleCls : public ObjectCls {
public:

     ParagraphStyleCls(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    Int32List _encoded;

    String _fontFamily;

    double _fontSize;

    double _height;

    StrutStyle _strutStyle;

    String _ellipsis;

    Locale _locale;

    TextLeadingDistribution _leadingDistribution;


};
using ParagraphStyle = std::shared_ptr<ParagraphStyleCls>;
ByteData _encodeStrut(String fontFamily, List<String> fontFamilyFallback, double fontSize, double height, TextLeadingDistribution leadingDistribution, double leading, FontWeight fontWeight, FontStyle fontStyle, bool forceStrutHeight);


class StrutStyleCls : public ObjectCls {
public:

     StrutStyleCls(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    ByteData _encoded;

    String _fontFamily;

    List<String> _fontFamilyFallback;

    TextLeadingDistribution _leadingDistribution;


    virtual bool _enabled();

};
using StrutStyle = std::shared_ptr<StrutStyleCls>;

enum TextDirection{
    rtl,
    ltr,
} // end TextDirection

class TextBoxCls : public ObjectCls {
public:
    double left;

    double top;

    double right;

    double bottom;

    TextDirection direction;


    virtual void  fromLTRBD(double left, double top, double right, double bottom, TextDirection direction);
    virtual Rect toRect();

    virtual double start();

    virtual double end();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using TextBox = std::shared_ptr<TextBoxCls>;

enum TextAffinity{
    upstream,
    downstream,
} // end TextAffinity

class TextPositionCls : public ObjectCls {
public:
    int offset;

    TextAffinity affinity;


     TextPositionCls(TextAffinity affinity, int offset);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using TextPosition = std::shared_ptr<TextPositionCls>;

class TextRangeCls : public ObjectCls {
public:
    static TextRange empty;

    int start;

    int end;


     TextRangeCls(int end, int start);

    virtual void  collapsed(int offset);

    virtual bool isValid();

    virtual bool isCollapsed();

    virtual bool isNormalized();

    virtual String textBefore(String text);

    virtual String textAfter(String text);

    virtual String textInside(String text);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using TextRange = std::shared_ptr<TextRangeCls>;

class ParagraphConstraintsCls : public ObjectCls {
public:
    double width;


     ParagraphConstraintsCls(double width);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using ParagraphConstraints = std::shared_ptr<ParagraphConstraintsCls>;

enum BoxHeightStyle{
    tight,
    max,
    includeLineSpacingMiddle,
    includeLineSpacingTop,
    includeLineSpacingBottom,
    strut,
} // end BoxHeightStyle

enum BoxWidthStyle{
    tight,
    max,
} // end BoxWidthStyle

enum PlaceholderAlignment{
    baseline,
    aboveBaseline,
    belowBaseline,
    top,
    bottom,
    middle,
} // end PlaceholderAlignment

class LineMetricsCls : public ObjectCls {
public:
    bool hardBreak;

    double ascent;

    double descent;

    double unscaledAscent;

    double height;

    double width;

    double left;

    double baseline;

    int lineNumber;


     LineMetricsCls(double ascent, double baseline, double descent, bool hardBreak, double height, double left, int lineNumber, double unscaledAscent, double width);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using LineMetrics = std::shared_ptr<LineMetricsCls>;

class ParagraphCls : public NativeFieldWrapperClass1Cls {
public:

    virtual double width();
    virtual double height();
    virtual double longestLine();
    virtual double minIntrinsicWidth();
    virtual double maxIntrinsicWidth();
    virtual double alphabeticBaseline();
    virtual double ideographicBaseline();
    virtual bool didExceedMaxLines();
    virtual void layout(ParagraphConstraints constraints);

    virtual List<TextBox> getBoxesForRange(int start, int end, BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle);

    virtual List<TextBox> getBoxesForPlaceholders();

    virtual TextPosition getPositionForOffset(Offset offset);

    virtual TextRange getWordBoundary(TextPosition position);

    virtual TextRange getLineBoundary(TextPosition position);

    virtual List<LineMetrics> computeLineMetrics();

private:
    bool _needsLayout;


    virtual void  _();
    virtual void _layout(double width);
    virtual List<TextBox> _decodeTextBoxes(Float32List encoded);

    virtual Float32List _getBoxesForRange(int start, int end, int boxHeightStyle, int boxWidthStyle);
    virtual Float32List _getBoxesForPlaceholders();
    virtual List<int> _getPositionForOffset(double dx, double dy);
    virtual List<int> _getWordBoundary(int offset);
    virtual List<int> _getLineBoundary(int offset);
    virtual void _paint(Canvas canvas, double x, double y);
    virtual Float64List _computeLineMetrics();
};
using Paragraph = std::shared_ptr<ParagraphCls>;

class ParagraphBuilderCls : public NativeFieldWrapperClass1Cls {
public:

     ParagraphBuilderCls(ParagraphStyle style);

    virtual int placeholderCount();

    virtual List<double> placeholderScales();

    virtual void pushStyle(TextStyle style);

    virtual void pop();
    virtual void addText(String text);

    virtual void addPlaceholder(double width, double height, PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, double scale);

    virtual Paragraph build();

private:
    int _placeholderCount;

    List<double> _placeholderScales;

    TextLeadingDistribution _defaultLeadingDistribution;


    virtual void _constructor(Int32List encoded, ByteData strutData, String fontFamily, List<Object> strutFontFamily, double fontSize, double height, String ellipsis, String locale);
    virtual void _pushStyle(Int32List encoded, List<Object> fontFamilies, double fontSize, double letterSpacing, double wordSpacing, double height, double decorationThickness, String locale, List<Object> backgroundObjects, ByteData backgroundData, List<Object> foregroundObjects, ByteData foregroundData, ByteData shadowsData, ByteData fontFeaturesData, ByteData fontVariationsData);
    static String _encodeLocale(Locale locale);

    virtual String _addText(String text);
    virtual String _addPlaceholder(double width, double height, int alignment, double baselineOffset, int baseline);
    virtual void _build(Paragraph outParagraph);
};
using ParagraphBuilder = std::shared_ptr<ParagraphBuilderCls>;
Future<void> loadFontFromList(Uint8List list, String fontFamily);

ByteData _fontChangeMessage;



#endif