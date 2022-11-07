#ifndef TEXT_H
#define TEXT_H
#include <memory>




enum FontStyle{
    normal,
    italic,
} // end FontStyle

class FontWeight {
public:
    int index;

    static const FontWeight w100;

    static const FontWeight w200;

    static const FontWeight w300;

    static const FontWeight w400;

    static const FontWeight w500;

    static const FontWeight w600;

    static const FontWeight w700;

    static const FontWeight w800;

    static const FontWeight w900;

    static const FontWeight normal;

    static const FontWeight bold;

    static const List<FontWeight> values;


    static FontWeight lerp(FontWeight a, FontWeight b, double t);

    String toString();

private:

    void  _(int index);

};

class FontFeature {
public:
    String feature;

    int value;


     FontFeature(String feature, int value);

    void  enable(String feature);

    void  disable(String feature);

    void  alternative(int value);

    void  alternativeFractions();

    void  contextualAlternates();

    void  caseSensitiveForms();

    void  characterVariant(int value);

    void  denominator();

    void  fractions();

    void  historicalForms();

    void  historicalLigatures();

    void  liningFigures();

    void  localeAware(bool enable);

    void  notationalForms(int value);

    void  numerators();

    void  oldstyleFigures();

    void  ordinalForms();

    void  proportionalFigures();

    void  randomize();

    void  stylisticAlternates();

    void  scientificInferiors();

    void  stylisticSet(int value);

    void  subscripts();

    void  superscripts();

    void  swash(int value);

    void  tabularFigures();

    void  slashedZero();

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static const int _kEncodedSize;


    void _encode(ByteData byteData);

};

class FontVariation {
public:
    String axis;

    double value;


     FontVariation(String axis, double value);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static const int _kEncodedSize;


    void _encode(ByteData byteData);

};

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

class TextDecoration {
public:
    static const TextDecoration none;

    static const TextDecoration underline;

    static const TextDecoration overline;

    static const TextDecoration lineThrough;


    void  combine(List<TextDecoration> decorations);

    bool contains(TextDecoration other);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    int _mask;


    void  _(int _mask);

};

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

class TextHeightBehavior {
public:
    bool applyHeightToFirstAscent;

    bool applyHeightToLastDescent;

    TextLeadingDistribution leadingDistribution;


     TextHeightBehavior(bool applyHeightToFirstAscent, bool applyHeightToLastDescent, TextLeadingDistribution leadingDistribution);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    void  _fromEncoded(int encoded, TextLeadingDistribution leadingDistribution);

    int _encode();

};
bool _listEquals<T>(List<T> a, List<T> b);

Int32List _encodeTextStyle(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);


class TextStyle {
public:

     TextStyle(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    bool ==(Object other);

    int hashCode();

    String toString();

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
Int32List _encodeParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior);


class ParagraphStyle {
public:

     ParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior);

    bool ==(Object other);

    int hashCode();

    String toString();

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
ByteData _encodeStrut(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution);


class StrutStyle {
public:

     StrutStyle(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution);

    bool ==(Object other);

    int hashCode();

private:
    ByteData _encoded;

    String _fontFamily;

    List<String> _fontFamilyFallback;

    TextLeadingDistribution _leadingDistribution;


    bool _enabled();

};

enum TextDirection{
    rtl,
    ltr,
} // end TextDirection

class TextBox {
public:
    double left;

    double top;

    double right;

    double bottom;

    TextDirection direction;


    void  fromLTRBD(double bottom, TextDirection direction, double left, double right, double top);

    Rect toRect();

    double start();

    double end();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

enum TextAffinity{
    upstream,
    downstream,
} // end TextAffinity

class TextPosition {
public:
    int offset;

    TextAffinity affinity;


     TextPosition(TextAffinity affinity, int offset);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class TextRange {
public:
    static const TextRange empty;

    int start;

    int end;


     TextRange(int end, int start);

    void  collapsed(int offset);

    bool isValid();

    bool isCollapsed();

    bool isNormalized();

    String textBefore(String text);

    String textAfter(String text);

    String textInside(String text);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class ParagraphConstraints {
public:
    double width;


     ParagraphConstraints(double width);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

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

class LineMetrics {
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


     LineMetrics(double ascent, double baseline, double descent, bool hardBreak, double height, double left, int lineNumber, double unscaledAscent, double width);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class Paragraph : NativeFieldWrapperClass1 {
public:

    double width();

    double height();

    double longestLine();

    double minIntrinsicWidth();

    double maxIntrinsicWidth();

    double alphabeticBaseline();

    double ideographicBaseline();

    bool didExceedMaxLines();

    void layout(ParagraphConstraints constraints);

    List<TextBox> getBoxesForRange(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, int end, int start);

    List<TextBox> getBoxesForPlaceholders();

    TextPosition getPositionForOffset(Offset offset);

    TextRange getWordBoundary(TextPosition position);

    TextRange getLineBoundary(TextPosition position);

    List<LineMetrics> computeLineMetrics();

private:
    bool _needsLayout;


    void  _();

    void _layout(double width);

    List<TextBox> _decodeTextBoxes(Float32List encoded);

    Float32List _getBoxesForRange(int boxHeightStyle, int boxWidthStyle, int end, int start);

    Float32List _getBoxesForPlaceholders();

    List<int> _getPositionForOffset(double dx, double dy);

    List<int> _getWordBoundary(int offset);

    List<int> _getLineBoundary(int offset);

    void _paint(Canvas canvas, double x, double y);

    Float64List _computeLineMetrics();

};

class ParagraphBuilder : NativeFieldWrapperClass1 {
public:

     ParagraphBuilder(ParagraphStyle style);

    int placeholderCount();

    List<double> placeholderScales();

    void pushStyle(TextStyle style);

    void pop();

    void addText(String text);

    void addPlaceholder(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, double height, double scale, double width);

    Paragraph build();

private:
    int _placeholderCount;

    List<double> _placeholderScales;

    TextLeadingDistribution _defaultLeadingDistribution;


    void _constructor(String ellipsis, Int32List encoded, String fontFamily, double fontSize, double height, String locale, ByteData strutData, List<Object> strutFontFamily);

    void _pushStyle(ByteData backgroundData, List<Object> backgroundObjects, double decorationThickness, Int32List encoded, List<Object> fontFamilies, ByteData fontFeaturesData, double fontSize, ByteData fontVariationsData, ByteData foregroundData, List<Object> foregroundObjects, double height, double letterSpacing, String locale, ByteData shadowsData, double wordSpacing);

    static String _encodeLocale(Locale locale);

    String _addText(String text);

    String _addPlaceholder(int alignment, int baseline, double baselineOffset, double height, double width);

    void _build(Paragraph outParagraph);

};
Future<void> loadFontFromList(String fontFamily, Uint8List list);

ByteData _fontChangeMessage;


#endif