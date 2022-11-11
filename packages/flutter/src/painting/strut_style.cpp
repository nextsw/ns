#include "strut_style.hpp"
StrutStyleCls::StrutStyleCls(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package) {
    {
        fontFamily = package == nullptr? fontFamily : __s("packages/$package/$fontFamily");
        _fontFamilyFallback = fontFamilyFallback;
        _package = package;
        assert(fontSize == nullptr || fontSize > 0);
        assert(leading == nullptr || leading >= 0);
        assert(package == nullptr || (fontFamily != nullptr || fontFamilyFallback != nullptr));
    }
}

void StrutStyleCls::fromTextStyle(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package, TextStyle textStyle)

List<String> StrutStyleCls::fontFamilyFallback() {
    if (_package != nullptr && _fontFamilyFallback != nullptr) {
        return _fontFamilyFallback!->map([=] (String family)         {
            __s("packages/$_package/$family");
        })->toList();
    }
    return _fontFamilyFallback;
}

RenderComparison StrutStyleCls::compareTo(StrutStyle other) {
    if (identical(this, other)) {
        return RenderComparisonCls::identical;
    }
    if (fontFamily != other->fontFamily || fontSize != other->fontSize || fontWeight != other->fontWeight || fontStyle != other->fontStyle || height != other->height || leading != other->leading || forceStrutHeight != other->forceStrutHeight || !listEquals(fontFamilyFallback, other->fontFamilyFallback)) {
        return RenderComparisonCls::layout;
    }
    return RenderComparisonCls::identical;
}

StrutStyle StrutStyleCls::inheritFromTextStyle(TextStyle other) {
    if (other == nullptr) {
        return this;
    }
    return make<StrutStyleCls>(fontFamily or other->fontFamily, fontFamilyFallback or other->fontFamilyFallback, fontSize or other->fontSize, height or other->height, leading, fontWeight or other->fontWeight, fontStyle or other->fontStyle, forceStrutHeight, debugLabel or other->debugLabel);
}

bool StrutStyleCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<StrutStyle>(other) && other->fontFamily == fontFamily && other->fontSize == fontSize && other->fontWeight == fontWeight && other->fontStyle == fontStyle && other->height == height && other->leading == leading && other->forceStrutHeight == forceStrutHeight;
}

int StrutStyleCls::hashCode() {
    return ObjectCls->hash(fontFamily, fontSize, fontWeight, fontStyle, height, leading, forceStrutHeight);
}

String StrutStyleCls::toStringShort() {
    return objectRuntimeType(this, __s("StrutStyle"));
}

void StrutStyleCls::debugFillProperties(String prefix, DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    if (debugLabel != nullptr) {
        properties->add(make<MessagePropertyCls>(__s("${prefix}debugLabel"), debugLabel!));
    }
    List<DiagnosticsNode> styles = makeList(ArrayItem, ArrayItem, ArrayItem);
    String weightDescription;
    if (fontWeight != nullptr) {
        weightDescription = __s("w${fontWeight!.index + 1}00");
    }
    styles->add(<FontWeight>make<DiagnosticsPropertyCls>(__s("${prefix}weight"), fontWeightweightDescription, nullptr));
    styles->add(<FontStyle>make<EnumPropertyCls>(__s("${prefix}style"), fontStylenullptr));
    styles->add(make<DoublePropertyCls>(__s("${prefix}height"), height__s("x"), nullptr));
    styles->add(make<FlagPropertyCls>(__s("${prefix}forceStrutHeight")forceStrutHeight, __s("$prefix<strut height forced>"), __s("$prefix<strut height normal>")));
    bool styleSpecified = styles->any([=] (DiagnosticsNode n) {
    !n->isFiltered(DiagnosticLevelCls::info);
});
    styles->forEach(properties->add);
    if (!styleSpecified) {
        properties->add(make<FlagPropertyCls>(__s("forceStrutHeight")forceStrutHeight, __s("$prefix<strut height forced>"), __s("$prefix<strut height normal>")));
    }
}
