#include "strut_style.hpp"
StrutStyleCls::StrutStyleCls(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package) {
    {
        fontFamily = package == nullptr? fontFamily : __s("packages/%s$%s,");
        _fontFamilyFallback = fontFamilyFallback;
        _package = package;
        assert(fontSize == nullptr || fontSize > 0);
        assert(leading == nullptr || leading >= 0);
        assert(package == nullptr || (fontFamily != nullptr || fontFamilyFallback != nullptr));
    }
}

void StrutStyleCls::fromTextStyle(TextStyle textStyle, String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package)

List<String> StrutStyleCls::fontFamilyFallback() {
    if (_package != nullptr && _fontFamilyFallback != nullptr) {
        return _fontFamilyFallback!->map([=] (String family) {
            __s("packages/%s$%s)");
        })->toList();
    }
    return _fontFamilyFallback;
}

RenderComparison StrutStyleCls::compareTo(StrutStyle other) {
    if (identical(this, other)) {
        return RenderComparisonCls::identical;
    }
    if (fontFamily != other->fontFamily || fontSize != other->fontSize || fontWeight != other->fontWeight || fontStyle != other->fontStyle || height != other->height || leading != other->leading || forceStrutHeight != other->forceStrutHeight || !listEquals(fontFamilyFallback(), other->fontFamilyFallback())) {
        return RenderComparisonCls::layout;
    }
    return RenderComparisonCls::identical;
}

StrutStyle StrutStyleCls::inheritFromTextStyle(TextStyle other) {
    if (other == nullptr) {
        return this;
    }
    return make<StrutStyleCls>(fontFamily | other->fontFamily, fontFamilyFallback() | other->fontFamilyFallback(), fontSize | other->fontSize, height | other->height, leading, fontWeight | other->fontWeight, fontStyle | other->fontStyle, forceStrutHeight, debugLabel | other->debugLabel);
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

void StrutStyleCls::debugFillProperties(DiagnosticPropertiesBuilder properties, String prefix) {
    super->debugFillProperties(properties);
    if (debugLabel != nullptr) {
        properties->add(make<MessagePropertyCls>(__s("%s,"), debugLabel!));
    }
    List<DiagnosticsNode> styles = makeList(ArrayItem, ArrayItem, ArrayItem);
    String weightDescription;
    if (fontWeight != nullptr) {
        weightDescription = __s("w%s;");
    }
    styles->add(<FontWeight>make<DiagnosticsPropertyCls>(__s("%s,"), fontWeight, weightDescription, nullptr));
    styles->add(<FontStyle>make<EnumPropertyCls>(__s("%s,"), fontStyle, nullptr));
    styles->add(make<DoublePropertyCls>(__s("%s,"), height, __s("x"), nullptr));
    styles->add(make<FlagPropertyCls>(__s("%s,"), forceStrutHeight, __s("%s,"), __s("%s)")));
    bool styleSpecified = styles->any([=] (DiagnosticsNode n) {
    !n->isFiltered(DiagnosticLevelCls::info);
});
    styles->forEach(properties->add);
    if (!styleSpecified) {
        properties->add(make<FlagPropertyCls>(__s("forceStrutHeight"), forceStrutHeight, __s("%s,"), __s("%s)")));
    }
}
