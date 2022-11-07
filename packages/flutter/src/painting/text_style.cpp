#include "text_style.hpp"
TextStyle::TextStyle(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    {
        fontFamily = package == nullptr? fontFamily : "packages/$package/$fontFamily";
        _fontFamilyFallback = fontFamilyFallback;
        _package = package;
        assert(inherit != nullptr);
        assert(color == nullptr || foreground == nullptr, _kColorForegroundWarning);
        assert(backgroundColor == nullptr || background == nullptr, _kColorBackgroundWarning);
    }
}

List<String> TextStyle::fontFamilyFallback() {
    return _package != nullptr && _fontFamilyFallback != nullptr? _fontFamilyFallback!.map().toList() : _fontFamilyFallback;
}

TextStyle TextStyle::copyWith(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    assert(color == nullptr || foreground == nullptr, _kColorForegroundWarning);
    assert(backgroundColor == nullptr || background == nullptr, _kColorBackgroundWarning);
    String newDebugLabel;
    assert(());
    return TextStyle(inherit ?? this.inherit, this.foreground == nullptr && foreground == nullptr? color ?? this.color : nullptr, this.background == nullptr && background == nullptr? backgroundColor ?? this.backgroundColor : nullptr, fontSize ?? this.fontSize, fontWeight ?? this.fontWeight, fontStyle ?? this.fontStyle, letterSpacing ?? this.letterSpacing, wordSpacing ?? this.wordSpacing, textBaseline ?? this.textBaseline, height ?? this.height, leadingDistribution ?? this.leadingDistribution, locale ?? this.locale, foreground ?? this.foreground, background ?? this.background, shadows ?? this.shadows, fontFeatures ?? this.fontFeatures, fontVariations ?? this.fontVariations, decoration ?? this.decoration, decorationColor ?? this.decorationColor, decorationStyle ?? this.decorationStyle, decorationThickness ?? this.decorationThickness, newDebugLabel, fontFamily ?? _fontFamily, fontFamilyFallback ?? this.fontFamilyFallback, package ?? _package, overflow ?? this.overflow);
}

TextStyle TextStyle::apply(Color backgroundColor, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThicknessDelta, double decorationThicknessFactor, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSizeDelta, double fontSizeFactor, FontStyle fontStyle, List<FontVariation> fontVariations, int fontWeightDelta, double heightDelta, double heightFactor, TextLeadingDistribution leadingDistribution, double letterSpacingDelta, double letterSpacingFactor, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacingDelta, double wordSpacingFactor) {
    assert(fontSizeFactor != nullptr);
    assert(fontSizeDelta != nullptr);
    assert(fontSize != nullptr || (fontSizeFactor == 1.0 && fontSizeDelta == 0.0));
    assert(fontWeightDelta != nullptr);
    assert(fontWeight != nullptr || fontWeightDelta == 0.0);
    assert(letterSpacingFactor != nullptr);
    assert(letterSpacingDelta != nullptr);
    assert(letterSpacing != nullptr || (letterSpacingFactor == 1.0 && letterSpacingDelta == 0.0));
    assert(wordSpacingFactor != nullptr);
    assert(wordSpacingDelta != nullptr);
    assert(wordSpacing != nullptr || (wordSpacingFactor == 1.0 && wordSpacingDelta == 0.0));
    assert(heightFactor != nullptr);
    assert(heightDelta != nullptr);
    assert(decorationThicknessFactor != nullptr);
    assert(decorationThicknessDelta != nullptr);
    assert(decorationThickness != nullptr || (decorationThicknessFactor == 1.0 && decorationThicknessDelta == 0.0));
    String modifiedDebugLabel;
    assert(());
    return TextStyle(inherit, foreground == nullptr? color ?? this.color : nullptr, background == nullptr? backgroundColor ?? this.backgroundColor : nullptr, fontFamily ?? _fontFamily, fontFamilyFallback ?? this.fontFamilyFallback, fontSize == nullptr? nullptr : fontSize! * fontSizeFactor + fontSizeDelta, fontWeight == nullptr? nullptr : FontWeight.values[(fontWeight!.index + fontWeightDelta).clamp(0, FontWeight.values.length - 1)], fontStyle ?? this.fontStyle, letterSpacing == nullptr? nullptr : letterSpacing! * letterSpacingFactor + letterSpacingDelta, wordSpacing == nullptr? nullptr : wordSpacing! * wordSpacingFactor + wordSpacingDelta, textBaseline ?? this.textBaseline, height == nullptr? nullptr : height! * heightFactor + heightDelta, leadingDistribution ?? this.leadingDistribution, locale ?? this.locale, foreground, background, shadows ?? this.shadows, fontFeatures ?? this.fontFeatures, fontVariations ?? this.fontVariations, decoration ?? this.decoration, decorationColor ?? this.decorationColor, decorationStyle ?? this.decorationStyle, decorationThickness == nullptr? nullptr : decorationThickness! * decorationThicknessFactor + decorationThicknessDelta, overflow ?? this.overflow, package ?? _package, modifiedDebugLabel);
}

TextStyle TextStyle::merge(TextStyle other) {
    if (other == nullptr) {
        return this;
    }
    if (!other.inherit) {
        return other;
    }
    String mergedDebugLabel;
    assert(());
    return copyWith(other.color, other.backgroundColor, other.fontSize, other.fontWeight, other.fontStyle, other.letterSpacing, other.wordSpacing, other.textBaseline, other.height, other.leadingDistribution, other.locale, other.foreground, other.background, other.shadows, other.fontFeatures, other.fontVariations, other.decoration, other.decorationColor, other.decorationStyle, other.decorationThickness, mergedDebugLabel, other._fontFamily, other.fontFamilyFallback, other._package, other.overflow);
}

TextStyle TextStyle::lerp(TextStyle a, TextStyle b, double t) {
    assert(t != nullptr);
    assert(a == nullptr || b == nullptr || a.inherit == b.inherit);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    String lerpDebugLabel;
    assert(());
    if (a == nullptr) {
        return TextStyle(b!.inherit, Color.lerp(nullptr, b.color, t), Color.lerp(nullptr, b.backgroundColor, t),  < 0.5? nullptr : b.fontSize, FontWeight.lerp(nullptr, b.fontWeight, t),  < 0.5? nullptr : b.fontStyle,  < 0.5? nullptr : b.letterSpacing,  < 0.5? nullptr : b.wordSpacing,  < 0.5? nullptr : b.textBaseline,  < 0.5? nullptr : b.height,  < 0.5? nullptr : b.leadingDistribution,  < 0.5? nullptr : b.locale,  < 0.5? nullptr : b.foreground,  < 0.5? nullptr : b.background,  < 0.5? nullptr : b.shadows,  < 0.5? nullptr : b.fontFeatures,  < 0.5? nullptr : b.fontVariations,  < 0.5? nullptr : b.decoration, Color.lerp(nullptr, b.decorationColor, t),  < 0.5? nullptr : b.decorationStyle,  < 0.5? nullptr : b.decorationThickness, lerpDebugLabel,  < 0.5? nullptr : b._fontFamily,  < 0.5? nullptr : b.fontFamilyFallback,  < 0.5? nullptr : b._package,  < 0.5? nullptr : b.overflow);
    }
    if (b == nullptr) {
        return TextStyle(a.inherit, Color.lerp(a.color, nullptr, t), Color.lerp(nullptr, a.backgroundColor, t),  < 0.5? a.fontSize : nullptr, FontWeight.lerp(a.fontWeight, nullptr, t),  < 0.5? a.fontStyle : nullptr,  < 0.5? a.letterSpacing : nullptr,  < 0.5? a.wordSpacing : nullptr,  < 0.5? a.textBaseline : nullptr,  < 0.5? a.height : nullptr,  < 0.5? a.leadingDistribution : nullptr,  < 0.5? a.locale : nullptr,  < 0.5? a.foreground : nullptr,  < 0.5? a.background : nullptr,  < 0.5? a.shadows : nullptr,  < 0.5? a.fontFeatures : nullptr,  < 0.5? a.fontVariations : nullptr,  < 0.5? a.decoration : nullptr, Color.lerp(a.decorationColor, nullptr, t),  < 0.5? a.decorationStyle : nullptr,  < 0.5? a.decorationThickness : nullptr, lerpDebugLabel,  < 0.5? a._fontFamily : nullptr,  < 0.5? a.fontFamilyFallback : nullptr,  < 0.5? a._package : nullptr,  < 0.5? a.overflow : nullptr);
    }
    return TextStyle(b.inherit, a.foreground == nullptr && b.foreground == nullptr? Color.lerp(a.color, b.color, t) : nullptr, a.background == nullptr && b.background == nullptr? Color.lerp(a.backgroundColor, b.backgroundColor, t) : nullptr, ui.lerpDouble(a.fontSize ?? b.fontSize, b.fontSize ?? a.fontSize, t), FontWeight.lerp(a.fontWeight, b.fontWeight, t),  < 0.5? a.fontStyle : b.fontStyle, ui.lerpDouble(a.letterSpacing ?? b.letterSpacing, b.letterSpacing ?? a.letterSpacing, t), ui.lerpDouble(a.wordSpacing ?? b.wordSpacing, b.wordSpacing ?? a.wordSpacing, t),  < 0.5? a.textBaseline : b.textBaseline, ui.lerpDouble(a.height ?? b.height, b.height ?? a.height, t),  < 0.5? a.leadingDistribution : b.leadingDistribution,  < 0.5? a.locale : b.locale, (a.foreground != nullptr || b.foreground != nullptr)?  < 0.5? a.foreground ?? () : b.foreground ?? () : nullptr, (a.background != nullptr || b.background != nullptr)?  < 0.5? a.background ?? () : b.background ?? () : nullptr,  < 0.5? a.shadows : b.shadows,  < 0.5? a.fontFeatures : b.fontFeatures,  < 0.5? a.fontVariations : b.fontVariations,  < 0.5? a.decoration : b.decoration, Color.lerp(a.decorationColor, b.decorationColor, t),  < 0.5? a.decorationStyle : b.decorationStyle, ui.lerpDouble(a.decorationThickness ?? b.decorationThickness, b.decorationThickness ?? a.decorationThickness, t), lerpDebugLabel,  < 0.5? a._fontFamily : b._fontFamily,  < 0.5? a.fontFamilyFallback : b.fontFamilyFallback,  < 0.5? a._package : b._package,  < 0.5? a.overflow : b.overflow);
}

TextStyle TextStyle::getTextStyle(double textScaleFactor) {
    return ui.TextStyle(color, decoration, decorationColor, decorationStyle, decorationThickness, fontWeight, fontStyle, textBaseline, leadingDistribution, fontFamily, fontFamilyFallback, fontSize == nullptr? nullptr : fontSize! * textScaleFactor, letterSpacing, wordSpacing, height, locale, foreground, background ?? (backgroundColor != nullptr? () : nullptr), shadows, fontFeatures, fontVariations);
}

ParagraphStyle TextStyle::getParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor) {
    assert(textScaleFactor != nullptr);
    assert(maxLines == nullptr || maxLines > 0);
    TextLeadingDistribution leadingDistribution = this.leadingDistribution;
    TextHeightBehavior effectiveTextHeightBehavior = textHeightBehavior ?? (leadingDistribution == nullptr? nullptr : ui.TextHeightBehavior(leadingDistribution));
    return ui.ParagraphStyle(textAlign, textDirection, fontWeight ?? this.fontWeight, fontStyle ?? this.fontStyle, fontFamily ?? this.fontFamily, (fontSize ?? this.fontSize ?? _kDefaultFontSize) * textScaleFactor, height ?? this.height, effectiveTextHeightBehavior, strutStyle == nullptr? nullptr : ui.StrutStyle(strutStyle.fontFamily, strutStyle.fontFamilyFallback, strutStyle.fontSize == nullptr? nullptr : strutStyle.fontSize! * textScaleFactor, strutStyle.height, strutStyle.leading, strutStyle.fontWeight, strutStyle.fontStyle, strutStyle.forceStrutHeight), maxLines, ellipsis, locale);
}

RenderComparison TextStyle::compareTo(TextStyle other) {
    if (identical(this, other)) {
        return RenderComparison.identical;
    }
    if (inherit != other.inherit || fontFamily != other.fontFamily || fontSize != other.fontSize || fontWeight != other.fontWeight || fontStyle != other.fontStyle || letterSpacing != other.letterSpacing || wordSpacing != other.wordSpacing || textBaseline != other.textBaseline || height != other.height || leadingDistribution != other.leadingDistribution || locale != other.locale || foreground != other.foreground || background != other.background || !listEquals(shadows, other.shadows) || !listEquals(fontFeatures, other.fontFeatures) || !listEquals(fontVariations, other.fontVariations) || !listEquals(fontFamilyFallback, other.fontFamilyFallback) || overflow != other.overflow) {
        return RenderComparison.layout;
    }
    if (color != other.color || backgroundColor != other.backgroundColor || decoration != other.decoration || decorationColor != other.decorationColor || decorationStyle != other.decorationStyle || decorationThickness != other.decorationThickness) {
        return RenderComparison.paint;
    }
    return RenderComparison.identical;
}

bool TextStyle::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is TextStyle && other.inherit == inherit && other.color == color && other.backgroundColor == backgroundColor && other.fontSize == fontSize && other.fontWeight == fontWeight && other.fontStyle == fontStyle && other.letterSpacing == letterSpacing && other.wordSpacing == wordSpacing && other.textBaseline == textBaseline && other.height == height && other.leadingDistribution == leadingDistribution && other.locale == locale && other.foreground == foreground && other.background == background && listEquals(other.shadows, shadows) && listEquals(other.fontFeatures, fontFeatures) && listEquals(other.fontVariations, fontVariations) && other.decoration == decoration && other.decorationColor == decorationColor && other.decorationStyle == decorationStyle && other.decorationThickness == decorationThickness && other.fontFamily == fontFamily && listEquals(other.fontFamilyFallback, fontFamilyFallback) && other._package == _package && other.overflow == overflow;
}

int TextStyle::hashCode() {
    return Object.hash(inherit, color, backgroundColor, fontSize, fontWeight, fontStyle, letterSpacing, wordSpacing, textBaseline, height, leadingDistribution, locale, foreground, background, shadows == nullptr? nullptr : Object.hashAll(shadows!), fontFeatures == nullptr? nullptr : Object.hashAll(fontFeatures!), fontVariations == nullptr? nullptr : Object.hashAll(fontVariations!), decoration, decorationColor, Object.hash(decorationStyle, decorationThickness, fontFamily, fontFamilyFallback == nullptr? nullptr : Object.hashAll(fontFamilyFallback!), _package, overflow));
}

String TextStyle::toStringShort() {
    return objectRuntimeType(this, "TextStyle");
}

void TextStyle::debugFillProperties(String prefix, DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    if (debugLabel != nullptr) {
        properties.add(MessageProperty("${prefix}debugLabel", debugLabel!));
    }
    List<DiagnosticsNode> styles = ;
    String weightDescription;
    if (fontWeight != nullptr) {
        weightDescription = "${fontWeight!.index + 1}00";
    }
    styles.add(<FontWeight>DiagnosticsProperty("${prefix}weight", fontWeightweightDescription, nullptr));
    styles.add(<FontStyle>EnumProperty("${prefix}style", fontStylenullptr));
    styles.add(DoubleProperty("${prefix}letterSpacing", letterSpacingnullptr));
    styles.add(DoubleProperty("${prefix}wordSpacing", wordSpacingnullptr));
    styles.add(<TextBaseline>EnumProperty("${prefix}baseline", textBaselinenullptr));
    styles.add(DoubleProperty("${prefix}height", height"x", nullptr));
    styles.add(<TextLeadingDistribution>EnumProperty("${prefix}leadingDistribution", leadingDistributionnullptr));
    styles.add(<Locale>DiagnosticsProperty("${prefix}locale", localenullptr));
    styles.add(<Paint>DiagnosticsProperty("${prefix}foreground", foregroundnullptr));
    styles.add(<Paint>DiagnosticsProperty("${prefix}background", backgroundnullptr));
    if (decoration != nullptr || decorationColor != nullptr || decorationStyle != nullptr || decorationThickness != nullptr) {
        List<String> decorationDescription = ;
        if (decorationStyle != nullptr) {
            decorationDescription.add(decorationStyle!.name);
        }
        styles.add(ColorProperty("${prefix}decorationColor", decorationColornullptr, DiagnosticLevel.fine));
        if (decorationColor != nullptr) {
            decorationDescription.add("$decorationColor");
        }
        styles.add(<TextDecoration>DiagnosticsProperty("${prefix}decoration", decorationnullptr, DiagnosticLevel.hidden));
        if (decoration != nullptr) {
            decorationDescription.add("$decoration");
        }
        assert(decorationDescription.isNotEmpty);
        styles.add(MessageProperty("${prefix}decoration", decorationDescription.join(" ")));
        styles.add(DoubleProperty("${prefix}decorationThickness", decorationThickness"x", nullptr));
    }
    bool styleSpecified = styles.any();
    properties.add(<bool>DiagnosticsProperty("${prefix}inherit", inherit(!styleSpecified && inherit)? DiagnosticLevel.fine : DiagnosticLevel.info));
    styles.forEach(properties.add);
    if (!styleSpecified) {
        properties.add(FlagProperty("inherit"inherit, "$prefix<all styles inherited>", "$prefix<no style specified>"));
    }
    styles.add(<TextOverflow>EnumProperty("${prefix}overflow", overflownullptr));
}

String TextStyle::_fontFamily() {
    if (_package != nullptr && fontFamily != nullptr) {
        String fontFamilyPrefix = "packages/$_package/";
        assert(fontFamily!.startsWith(fontFamilyPrefix));
        return fontFamily!.substring(fontFamilyPrefix.length);
    }
    return fontFamily;
}
