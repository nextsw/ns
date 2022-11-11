#ifndef PACKAGES_FLUTTER_SRC_PAINTING_STRUT_STYLE
#define PACKAGES_FLUTTER_SRC_PAINTING_STRUT_STYLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "text_style.hpp"


class StrutStyleCls : public ObjectCls {
public:
    static StrutStyle disabled;

    String fontFamily;

    double fontSize;

    double height;

    TextLeadingDistribution leadingDistribution;

    FontWeight fontWeight;

    FontStyle fontStyle;

    double leading;

    bool forceStrutHeight;

    String debugLabel;


     StrutStyleCls(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package);

    virtual void  fromTextStyle(TextStyle textStyle, String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package);

    virtual List<String> fontFamilyFallback();

    virtual RenderComparison compareTo(StrutStyle other);

    virtual StrutStyle inheritFromTextStyle(TextStyle other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties, String prefix);

private:
    List<String> _fontFamilyFallback;

    String _package;


};
using StrutStyle = std::shared_ptr<StrutStyleCls>;


#endif