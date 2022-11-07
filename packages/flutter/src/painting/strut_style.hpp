#ifndef STRUT_STYLE_H
#define STRUT_STYLE_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "text_style.hpp"



class StrutStyle {
public:
    static const StrutStyle disabled;

    String fontFamily;

    double fontSize;

    double height;

    TextLeadingDistribution leadingDistribution;

    FontWeight fontWeight;

    FontStyle fontStyle;

    double leading;

    bool forceStrutHeight;

    String debugLabel;


     StrutStyle(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package);

    void  fromTextStyle(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package, TextStyle textStyle);

    List<String> fontFamilyFallback();

    RenderComparison compareTo(StrutStyle other);

    StrutStyle inheritFromTextStyle(TextStyle other);

    bool ==(Object other);

    int hashCode();

    String toStringShort();

    void debugFillProperties(String prefix, DiagnosticPropertiesBuilder properties);

private:
    List<String> _fontFamilyFallback;

    String _package;


};

#endif