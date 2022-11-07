#ifndef TEXT_STYLE_H
#define TEXT_STYLE_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "colors.hpp"
#include "strut_style.hpp"
#include "text_painter.hpp"


const String _kDefaultDebugLabel;

const String _kColorForegroundWarning;

const String _kColorBackgroundWarning;

const double _kDefaultFontSize;


class TextStyle {
public:
    bool inherit;

    Color color;

    Color backgroundColor;

    String fontFamily;

    double fontSize;

    FontWeight fontWeight;

    FontStyle fontStyle;

    double letterSpacing;

    double wordSpacing;

    TextBaseline textBaseline;

    double height;

    TextLeadingDistribution leadingDistribution;

    Locale locale;

    Paint foreground;

    Paint background;

    TextDecoration decoration;

    Color decorationColor;

    TextDecorationStyle decorationStyle;

    double decorationThickness;

    String debugLabel;

    List<Shadow> shadows;

    List<FontFeature> fontFeatures;

    List<FontVariation> fontVariations;

    TextOverflow overflow;


     TextStyle(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    List<String> fontFamilyFallback();

    TextStyle copyWith(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    TextStyle apply(Color backgroundColor, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThicknessDelta, double decorationThicknessFactor, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSizeDelta, double fontSizeFactor, FontStyle fontStyle, List<FontVariation> fontVariations, int fontWeightDelta, double heightDelta, double heightFactor, TextLeadingDistribution leadingDistribution, double letterSpacingDelta, double letterSpacingFactor, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacingDelta, double wordSpacingFactor);

    TextStyle merge(TextStyle other);

    static TextStyle lerp(TextStyle a, TextStyle b, double t);

    TextStyle getTextStyle(double textScaleFactor);

    ParagraphStyle getParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor);

    RenderComparison compareTo(TextStyle other);

    bool ==(Object other);

    int hashCode();

    String toStringShort();

    void debugFillProperties(String prefix, DiagnosticPropertiesBuilder properties);

private:
    List<String> _fontFamilyFallback;

    String _package;


    String _fontFamily();

};

#endif