#include "text_style.hpp"
TextStyleCls::TextStyleCls(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    {
        fontFamily = package == nullptr? fontFamily : __s("packages/$package/$fontFamily");
        _fontFamilyFallback = fontFamilyFallback;
        _package = package;
        assert(inherit != nullptr);
        assert(color == nullptr || foreground == nullptr, _kColorForegroundWarning);
        assert(backgroundColor == nullptr || background == nullptr, _kColorBackgroundWarning);
    }
}

List<String> TextStyleCls::fontFamilyFallback() {
    return _package != nullptr && _fontFamilyFallback != nullptr? _fontFamilyFallback!->map([=] (String str) {
        __s("packages/$_package/$str");
    })->toList() : _fontFamilyFallback;
}

TextStyle TextStyleCls::copyWith(Paint background, Color backgroundColor, Color color, String debugLabel, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, bool inherit, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    assert(color == nullptr || foreground == nullptr, _kColorForegroundWarning);
    assert(backgroundColor == nullptr || background == nullptr, _kColorBackgroundWarning);
    String newDebugLabel;
    assert([=] () {
        if (this->debugLabel != nullptr) {
            newDebugLabel = debugLabel | __s("(${this.debugLabel}).copyWith");
        }
        return true;
    }());
    return make<TextStyleCls>(inherit | this->inherit, this->foreground == nullptr && foreground == nullptr? color | this->color : nullptr, this->background == nullptr && background == nullptr? backgroundColor | this->backgroundColor : nullptr, fontSize | this->fontSize, fontWeight | this->fontWeight, fontStyle | this->fontStyle, letterSpacing | this->letterSpacing, wordSpacing | this->wordSpacing, textBaseline | this->textBaseline, height | this->height, leadingDistribution | this->leadingDistribution, locale | this->locale, foreground | this->foreground, background | this->background, shadows | this->shadows, fontFeatures | this->fontFeatures, fontVariations | this->fontVariations, decoration | this->decoration, decorationColor | this->decorationColor, decorationStyle | this->decorationStyle, decorationThickness | this->decorationThickness, newDebugLabel, fontFamily | _fontFamily(), fontFamilyFallback | this->fontFamilyFallback, package | _package, overflow | this->overflow);
}

TextStyle TextStyleCls::apply(Color backgroundColor, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThicknessDelta, double decorationThicknessFactor, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSizeDelta, double fontSizeFactor, FontStyle fontStyle, List<FontVariation> fontVariations, int fontWeightDelta, double heightDelta, double heightFactor, TextLeadingDistribution leadingDistribution, double letterSpacingDelta, double letterSpacingFactor, Locale locale, TextOverflow overflow, String package, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacingDelta, double wordSpacingFactor) {
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
    assert([=] () {
        if (debugLabel != nullptr) {
            modifiedDebugLabel = __s("($debugLabel).apply");
        }
        return true;
    }());
    return make<TextStyleCls>(inherit, foreground == nullptr? color | this->color : nullptr, background == nullptr? backgroundColor | this->backgroundColor : nullptr, fontFamily | _fontFamily(), fontFamilyFallback | this->fontFamilyFallback, fontSize == nullptr? nullptr : fontSize! * fontSizeFactor + fontSizeDelta, fontWeight == nullptr? nullptr : FontWeightCls::values[(fontWeight!->index + fontWeightDelta)->clamp(0, FontWeightCls::values->length - 1)], fontStyle | this->fontStyle, letterSpacing == nullptr? nullptr : letterSpacing! * letterSpacingFactor + letterSpacingDelta, wordSpacing == nullptr? nullptr : wordSpacing! * wordSpacingFactor + wordSpacingDelta, textBaseline | this->textBaseline, height == nullptr? nullptr : height! * heightFactor + heightDelta, leadingDistribution | this->leadingDistribution, locale | this->locale, foreground, background, shadows | this->shadows, fontFeatures | this->fontFeatures, fontVariations | this->fontVariations, decoration | this->decoration, decorationColor | this->decorationColor, decorationStyle | this->decorationStyle, decorationThickness == nullptr? nullptr : decorationThickness! * decorationThicknessFactor + decorationThicknessDelta, overflow | this->overflow, package | _package, modifiedDebugLabel);
}

TextStyle TextStyleCls::merge(TextStyle other) {
    if (other == nullptr) {
        return this;
    }
    if (!other->inherit) {
        return other;
    }
    String mergedDebugLabel;
    assert([=] () {
        if (other->debugLabel != nullptr || debugLabel != nullptr) {
            mergedDebugLabel = __s("(${debugLabel ?? _kDefaultDebugLabel}).merge(${other.debugLabel ?? _kDefaultDebugLabel})");
        }
        return true;
    }());
    return copyWith(other->color, other->backgroundColor, other->fontSize, other->fontWeight, other->fontStyle, other->letterSpacing, other->wordSpacing, other->textBaseline, other->height, other->leadingDistribution, other->locale, other->foreground, other->background, other->shadows, other->fontFeatures, other->fontVariations, other->decoration, other->decorationColor, other->decorationStyle, other->decorationThickness, mergedDebugLabel, other->_fontFamily(), other->fontFamilyFallback(), other->_package, other->overflow);
}

TextStyle TextStyleCls::lerp(TextStyle a, TextStyle b, double t) {
    assert(t != nullptr);
    assert(a == nullptr || b == nullptr || a->inherit == b->inherit);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    String lerpDebugLabel;
    assert([=] () {
        lerpDebugLabel = __s("lerp(${a?.debugLabel ?? _kDefaultDebugLabel} ⎯${t.toStringAsFixed(1)}→ ${b?.debugLabel ?? _kDefaultDebugLabel})");
        return true;
    }());
    if (a == nullptr) {
        return make<TextStyleCls>(b!->inherit, ColorCls->lerp(nullptr, b->color, t), ColorCls->lerp(nullptr, b->backgroundColor, t),  < 0.5? nullptr : b->fontSize, FontWeightCls->lerp(nullptr, b->fontWeight, t),  < 0.5? nullptr : b->fontStyle,  < 0.5? nullptr : b->letterSpacing,  < 0.5? nullptr : b->wordSpacing,  < 0.5? nullptr : b->textBaseline,  < 0.5? nullptr : b->height,  < 0.5? nullptr : b->leadingDistribution,  < 0.5? nullptr : b->locale,  < 0.5? nullptr : b->foreground,  < 0.5? nullptr : b->background,  < 0.5? nullptr : b->shadows,  < 0.5? nullptr : b->fontFeatures,  < 0.5? nullptr : b->fontVariations,  < 0.5? nullptr : b->decoration, ColorCls->lerp(nullptr, b->decorationColor, t),  < 0.5? nullptr : b->decorationStyle,  < 0.5? nullptr : b->decorationThickness, lerpDebugLabel,  < 0.5? nullptr : b->_fontFamily(),  < 0.5? nullptr : b->fontFamilyFallback(),  < 0.5? nullptr : b->_package,  < 0.5? nullptr : b->overflow);
    }
    if (b == nullptr) {
        return make<TextStyleCls>(a->inherit, ColorCls->lerp(a->color, nullptr, t), ColorCls->lerp(nullptr, a->backgroundColor, t),  < 0.5? a->fontSize : nullptr, FontWeightCls->lerp(a->fontWeight, nullptr, t),  < 0.5? a->fontStyle : nullptr,  < 0.5? a->letterSpacing : nullptr,  < 0.5? a->wordSpacing : nullptr,  < 0.5? a->textBaseline : nullptr,  < 0.5? a->height : nullptr,  < 0.5? a->leadingDistribution : nullptr,  < 0.5? a->locale : nullptr,  < 0.5? a->foreground : nullptr,  < 0.5? a->background : nullptr,  < 0.5? a->shadows : nullptr,  < 0.5? a->fontFeatures : nullptr,  < 0.5? a->fontVariations : nullptr,  < 0.5? a->decoration : nullptr, ColorCls->lerp(a->decorationColor, nullptr, t),  < 0.5? a->decorationStyle : nullptr,  < 0.5? a->decorationThickness : nullptr, lerpDebugLabel,  < 0.5? a->_fontFamily() : nullptr,  < 0.5? a->fontFamilyFallback() : nullptr,  < 0.5? a->_package : nullptr,  < 0.5? a->overflow : nullptr);
    }
    auto _c1 = make<PaintCls>();_c1.color = a->color!;auto _c2 = make<PaintCls>();_c2.color = b->color!;auto _c3 = make<PaintCls>();_c3.color = a->backgroundColor!;auto _c4 = make<PaintCls>();_c4.color = b->backgroundColor!;return make<TextStyleCls>(b->inherit, a->foreground == nullptr && b->foreground == nullptr? ColorCls->lerp(a->color, b->color, t) : nullptr, a->background == nullptr && b->background == nullptr? ColorCls->lerp(a->backgroundColor, b->backgroundColor, t) : nullptr, ui->lerpDouble(a->fontSize | b->fontSize, b->fontSize | a->fontSize, t), FontWeightCls->lerp(a->fontWeight, b->fontWeight, t),  < 0.5? a->fontStyle : b->fontStyle, ui->lerpDouble(a->letterSpacing | b->letterSpacing, b->letterSpacing | a->letterSpacing, t), ui->lerpDouble(a->wordSpacing | b->wordSpacing, b->wordSpacing | a->wordSpacing, t),  < 0.5? a->textBaseline : b->textBaseline, ui->lerpDouble(a->height | b->height, b->height | a->height, t),  < 0.5? a->leadingDistribution : b->leadingDistribution,  < 0.5? a->locale : b->locale, (a->foreground != nullptr || b->foreground != nullptr)?  < 0.5? a->foreground | (_c1) : b->foreground | (_c2) : nullptr, (a->background != nullptr || b->background != nullptr)?  < 0.5? a->background | (_c3) : b->background | (_c4) : nullptr,  < 0.5? a->shadows : b->shadows,  < 0.5? a->fontFeatures : b->fontFeatures,  < 0.5? a->fontVariations : b->fontVariations,  < 0.5? a->decoration : b->decoration, ColorCls->lerp(a->decorationColor, b->decorationColor, t),  < 0.5? a->decorationStyle : b->decorationStyle, ui->lerpDouble(a->decorationThickness | b->decorationThickness, b->decorationThickness | a->decorationThickness, t), lerpDebugLabel,  < 0.5? a->_fontFamily() : b->_fontFamily(),  < 0.5? a->fontFamilyFallback() : b->fontFamilyFallback(),  < 0.5? a->_package : b->_package,  < 0.5? a->overflow : b->overflow);
}

TextStyle TextStyleCls::getTextStyle(double textScaleFactor) {
    auto _c1 = make<PaintCls>();_c1.color = backgroundColor!;return ui->make<TextStyleCls>(color, decoration, decorationColor, decorationStyle, decorationThickness, fontWeight, fontStyle, textBaseline, leadingDistribution, fontFamily, fontFamilyFallback(), fontSize == nullptr? nullptr : fontSize! * textScaleFactor, letterSpacing, wordSpacing, height, locale, foreground, background | (backgroundColor != nullptr? (_c1) : nullptr), shadows, fontFeatures, fontVariations);
}

ParagraphStyle TextStyleCls::getParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor) {
    assert(textScaleFactor != nullptr);
    assert(maxLines == nullptr || maxLines > 0);
    TextLeadingDistribution leadingDistribution = this->leadingDistribution;
    TextHeightBehavior effectiveTextHeightBehavior = textHeightBehavior | (leadingDistribution == nullptr? nullptr : ui->make<TextHeightBehaviorCls>(leadingDistribution));
    return ui->make<ParagraphStyleCls>(textAlign, textDirection, fontWeight | this->fontWeight, fontStyle | this->fontStyle, fontFamily | this->fontFamily, (fontSize | this->fontSize | _kDefaultFontSize) * textScaleFactor, height | this->height, effectiveTextHeightBehavior, strutStyle == nullptr? nullptr : ui->make<StrutStyleCls>(strutStyle->fontFamily, strutStyle->fontFamilyFallback(), strutStyle->fontSize == nullptr? nullptr : strutStyle->fontSize! * textScaleFactor, strutStyle->height, strutStyle->leading, strutStyle->fontWeight, strutStyle->fontStyle, strutStyle->forceStrutHeight), maxLines, ellipsis, locale);
}

RenderComparison TextStyleCls::compareTo(TextStyle other) {
    if (identical(this, other)) {
        return RenderComparisonCls::identical;
    }
    if (inherit != other->inherit || fontFamily != other->fontFamily || fontSize != other->fontSize || fontWeight != other->fontWeight || fontStyle != other->fontStyle || letterSpacing != other->letterSpacing || wordSpacing != other->wordSpacing || textBaseline != other->textBaseline || height != other->height || leadingDistribution != other->leadingDistribution || locale != other->locale || foreground != other->foreground || background != other->background || !listEquals(shadows, other->shadows) || !listEquals(fontFeatures, other->fontFeatures) || !listEquals(fontVariations, other->fontVariations) || !listEquals(fontFamilyFallback(), other->fontFamilyFallback()) || overflow != other->overflow) {
        return RenderComparisonCls::layout;
    }
    if (color != other->color || backgroundColor != other->backgroundColor || decoration != other->decoration || decorationColor != other->decorationColor || decorationStyle != other->decorationStyle || decorationThickness != other->decorationThickness) {
        return RenderComparisonCls::paint;
    }
    return RenderComparisonCls::identical;
}

bool TextStyleCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<TextStyle>(other) && other->inherit == inherit && other->color == color && other->backgroundColor == backgroundColor && other->fontSize == fontSize && other->fontWeight == fontWeight && other->fontStyle == fontStyle && other->letterSpacing == letterSpacing && other->wordSpacing == wordSpacing && other->textBaseline == textBaseline && other->height == height && other->leadingDistribution == leadingDistribution && other->locale == locale && other->foreground == foreground && other->background == background && listEquals(other->shadows, shadows) && listEquals(other->fontFeatures, fontFeatures) && listEquals(other->fontVariations, fontVariations) && other->decoration == decoration && other->decorationColor == decorationColor && other->decorationStyle == decorationStyle && other->decorationThickness == decorationThickness && other->fontFamily == fontFamily && listEquals(other->fontFamilyFallback, fontFamilyFallback()) && other->_package == _package && other->overflow == overflow;
}

int TextStyleCls::hashCode() {
    return ObjectCls->hash(inherit, color, backgroundColor, fontSize, fontWeight, fontStyle, letterSpacing, wordSpacing, textBaseline, height, leadingDistribution, locale, foreground, background, shadows == nullptr? nullptr : ObjectCls->hashAll(shadows!), fontFeatures == nullptr? nullptr : ObjectCls->hashAll(fontFeatures!), fontVariations == nullptr? nullptr : ObjectCls->hashAll(fontVariations!), decoration, decorationColor, ObjectCls->hash(decorationStyle, decorationThickness, fontFamily, fontFamilyFallback() == nullptr? nullptr : ObjectCls->hashAll(fontFamilyFallback()!), _package, overflow));
}

String TextStyleCls::toStringShort() {
    return objectRuntimeType(this, __s("TextStyle"));
}

void TextStyleCls::debugFillProperties(DiagnosticPropertiesBuilder properties, String prefix) {
    super->debugFillProperties(properties);
    if (debugLabel != nullptr) {
        properties->add(make<MessagePropertyCls>(__s("${prefix}debugLabel"), debugLabel!));
    }
    List<DiagnosticsNode> styles = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    String weightDescription;
    if (fontWeight != nullptr) {
        weightDescription = __s("${fontWeight!.index + 1}00");
    }
    styles->add(<FontWeight>make<DiagnosticsPropertyCls>(__s("${prefix}weight"), fontWeight, weightDescription, nullptr));
    styles->add(<FontStyle>make<EnumPropertyCls>(__s("${prefix}style"), fontStyle, nullptr));
    styles->add(make<DoublePropertyCls>(__s("${prefix}letterSpacing"), letterSpacing, nullptr));
    styles->add(make<DoublePropertyCls>(__s("${prefix}wordSpacing"), wordSpacing, nullptr));
    styles->add(<TextBaseline>make<EnumPropertyCls>(__s("${prefix}baseline"), textBaseline, nullptr));
    styles->add(make<DoublePropertyCls>(__s("${prefix}height"), height, __s("x"), nullptr));
    styles->add(<TextLeadingDistribution>make<EnumPropertyCls>(__s("${prefix}leadingDistribution"), leadingDistribution, nullptr));
    styles->add(<Locale>make<DiagnosticsPropertyCls>(__s("${prefix}locale"), locale, nullptr));
    styles->add(<Paint>make<DiagnosticsPropertyCls>(__s("${prefix}foreground"), foreground, nullptr));
    styles->add(<Paint>make<DiagnosticsPropertyCls>(__s("${prefix}background"), background, nullptr));
    if (decoration != nullptr || decorationColor != nullptr || decorationStyle != nullptr || decorationThickness != nullptr) {
        List<String> decorationDescription = makeList();
        if (decorationStyle != nullptr) {
            decorationDescription->add(decorationStyle!->name);
        }
        styles->add(make<ColorPropertyCls>(__s("${prefix}decorationColor"), decorationColor, nullptr, DiagnosticLevelCls::fine));
        if (decorationColor != nullptr) {
            decorationDescription->add(__s("$decorationColor"));
        }
        styles->add(<TextDecoration>make<DiagnosticsPropertyCls>(__s("${prefix}decoration"), decoration, nullptr, DiagnosticLevelCls::hidden));
        if (decoration != nullptr) {
            decorationDescription->add(__s("$decoration"));
        }
        assert(decorationDescription->isNotEmpty);
        styles->add(make<MessagePropertyCls>(__s("${prefix}decoration"), decorationDescription->join(__s(" "))));
        styles->add(make<DoublePropertyCls>(__s("${prefix}decorationThickness"), decorationThickness, __s("x"), nullptr));
    }
    bool styleSpecified = styles->any([=] (DiagnosticsNode n) {
    !n->isFiltered(DiagnosticLevelCls::info);
});
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("${prefix}inherit"), inherit, (!styleSpecified && inherit)? DiagnosticLevelCls::fine : DiagnosticLevelCls::info));
    styles->forEach(properties->add);
    if (!styleSpecified) {
        properties->add(make<FlagPropertyCls>(__s("inherit"), inherit, __s("$prefix<all styles inherited>"), __s("$prefix<no style specified>")));
    }
    styles->add(<TextOverflow>make<EnumPropertyCls>(__s("${prefix}overflow"), overflow, nullptr));
}

String TextStyleCls::_fontFamily() {
    if (_package != nullptr && fontFamily != nullptr) {
        String fontFamilyPrefix = __s("packages/$_package/");
        assert(fontFamily!->startsWith(fontFamilyPrefix));
        return fontFamily!->substring(fontFamilyPrefix->length());
    }
    return fontFamily;
}
