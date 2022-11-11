#ifndef PACKAGES_FLUTTER_SRC_PAINTING_TEXT_STYLE
#define PACKAGES_FLUTTER_SRC_PAINTING_TEXT_STYLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "colors.hpp"
#include "strut_style.hpp"
#include "text_painter.hpp"

String _kDefaultDebugLabel;

String _kColorForegroundWarning;

String _kColorBackgroundWarning;

double _kDefaultFontSize;


class TextStyleCls : public ObjectCls {
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


     TextStyleCls(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    virtual List<String> fontFamilyFallback();

    virtual TextStyle copyWith(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing);

    virtual TextStyle apply(Color backgroundColor, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThicknessDelta, double decorationThicknessFactor, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSizeDelta, double fontSizeFactor, FontStyle fontStyle, List<FontVariation> fontVariations, int fontWeightDelta, double heightDelta, double heightFactor, TextLeadingDistribution leadingDistribution, double letterSpacingDelta, double letterSpacingFactor, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacingDelta, double wordSpacingFactor);

    virtual TextStyle merge(TextStyle other);

    static TextStyle lerp(TextStyle a, TextStyle b, double t);

    virtual TextStyle getTextStyle(double textScaleFactor);

    virtual ParagraphStyle getParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor);

    virtual RenderComparison compareTo(TextStyle other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties, String prefix);

private:
    List<String> _fontFamilyFallback;

    String _package;


    virtual String _fontFamily();

};
using TextStyle = std::shared_ptr<TextStyleCls>;


#endif