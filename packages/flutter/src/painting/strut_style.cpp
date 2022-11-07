#include "strut_style.hpp"
StrutStyle::StrutStyle(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package) {
    {
        fontFamily = package == nullptr? fontFamily : "packages/$package/$fontFamily";
        _fontFamilyFallback = fontFamilyFallback;
        _package = package;
        assert(fontSize == nullptr || fontSize > 0);
        assert(leading == nullptr || leading >= 0);
        assert(package == nullptr || (fontFamily != nullptr || fontFamilyFallback != nullptr));
    }
}

void StrutStyle::fromTextStyle(String debugLabel, String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution, String package, TextStyle textStyle)

List<String> StrutStyle::fontFamilyFallback() {
    if (_package != nullptr && _fontFamilyFallback != nullptr) {
        return _fontFamilyFallback!.map().toList();
    }
    return _fontFamilyFallback;
}

RenderComparison StrutStyle::compareTo(StrutStyle other) {
    if (identical(this, other)) {
        return RenderComparison.identical;
    }
    if (fontFamily != other.fontFamily || fontSize != other.fontSize || fontWeight != other.fontWeight || fontStyle != other.fontStyle || height != other.height || leading != other.leading || forceStrutHeight != other.forceStrutHeight || !listEquals(fontFamilyFallback, other.fontFamilyFallback)) {
        return RenderComparison.layout;
    }
    return RenderComparison.identical;
}

StrutStyle StrutStyle::inheritFromTextStyle(TextStyle other) {
    if (other == nullptr) {
        return this;
    }
    return StrutStyle(fontFamily ?? other.fontFamily, fontFamilyFallback ?? other.fontFamilyFallback, fontSize ?? other.fontSize, height ?? other.height, leading, fontWeight ?? other.fontWeight, fontStyle ?? other.fontStyle, forceStrutHeight, debugLabel ?? other.debugLabel);
}

bool StrutStyle::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is StrutStyle && other.fontFamily == fontFamily && other.fontSize == fontSize && other.fontWeight == fontWeight && other.fontStyle == fontStyle && other.height == height && other.leading == leading && other.forceStrutHeight == forceStrutHeight;
}

int StrutStyle::hashCode() {
    return Object.hash(fontFamily, fontSize, fontWeight, fontStyle, height, leading, forceStrutHeight);
}

String StrutStyle::toStringShort() {
    return objectRuntimeType(this, "StrutStyle");
}

void StrutStyle::debugFillProperties(String prefix, DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    if (debugLabel != nullptr) {
        properties.add(MessageProperty("${prefix}debugLabel", debugLabel!));
    }
    List<DiagnosticsNode> styles = ;
    String weightDescription;
    if (fontWeight != nullptr) {
        weightDescription = "w${fontWeight!.index + 1}00";
    }
    styles.add(<FontWeight>DiagnosticsProperty("${prefix}weight", fontWeightweightDescription, nullptr));
    styles.add(<FontStyle>EnumProperty("${prefix}style", fontStylenullptr));
    styles.add(DoubleProperty("${prefix}height", height"x", nullptr));
    styles.add(FlagProperty("${prefix}forceStrutHeight"forceStrutHeight, "$prefix<strut height forced>", "$prefix<strut height normal>"));
    bool styleSpecified = styles.any();
    styles.forEach(properties.add);
    if (!styleSpecified) {
        properties.add(FlagProperty("forceStrutHeight"forceStrutHeight, "$prefix<strut height forced>", "$prefix<strut height normal>"));
    }
}
