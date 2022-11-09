#include "text.hpp"
DefaultTextStyleCls::DefaultTextStyleCls(Unknown child, Unknown key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis) {
    {
        assert(style != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(child != nullptr);
        assert(textWidthBasis != nullptr);
    }
}

void DefaultTextStyleCls::fallback(Unknown key)

Widget DefaultTextStyleCls::merge(Widget child, Key key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextWidthBasis textWidthBasis) {
    assert(child != nullptr);
    return make<BuilderCls>([=] (BuildContext context) {
        DefaultTextStyle parent = DefaultTextStyleCls->of(context);
        return make<DefaultTextStyleCls>(key, parent->style->merge(style), textAlign ?? parent->textAlign, softWrap ?? parent->softWrap, overflow ?? parent->overflow, maxLines ?? parent->maxLines, textWidthBasis ?? parent->textWidthBasis, child);
    });
}

DefaultTextStyle DefaultTextStyleCls::of(BuildContext context) {
    return context-><DefaultTextStyle>dependOnInheritedWidgetOfExactType() ?? DefaultTextStyleCls->fallback();
}

bool DefaultTextStyleCls::updateShouldNotify(DefaultTextStyle oldWidget) {
    return style != oldWidget->style || textAlign != oldWidget->textAlign || softWrap != oldWidget->softWrap || overflow != oldWidget->overflow || maxLines != oldWidget->maxLines || textWidthBasis != oldWidget->textWidthBasis || textHeightBehavior != oldWidget->textHeightBehavior;
}

Widget DefaultTextStyleCls::wrap(Widget child, BuildContext context) {
    return make<DefaultTextStyleCls>(style, textAlign, softWrap, overflow, maxLines, textWidthBasis, textHeightBehavior, child);
}

void DefaultTextStyleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    style->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>("textAlign", textAlignnullptr));
    properties->add(make<FlagPropertyCls>("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties->add(<TextOverflow>make<EnumPropertyCls>("overflow", overflownullptr));
    properties->add(make<IntPropertyCls>("maxLines", maxLinesnullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>("textWidthBasis", textWidthBasisTextWidthBasisCls::parent));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>("textHeightBehavior", textHeightBehaviornullptr));
}

Widget _NullWidgetCls::build(BuildContext context) {
    ;
}

DefaultTextHeightBehaviorCls::DefaultTextHeightBehaviorCls(Unknown child, Unknown key, TextHeightBehavior textHeightBehavior) {
    {
        assert(textHeightBehavior != nullptr);
        assert(child != nullptr);
    }
}

TextHeightBehavior DefaultTextHeightBehaviorCls::of(BuildContext context) {
    return context-><DefaultTextHeightBehavior>dependOnInheritedWidgetOfExactType()?->textHeightBehavior;
}

bool DefaultTextHeightBehaviorCls::updateShouldNotify(DefaultTextHeightBehavior oldWidget) {
    return textHeightBehavior != oldWidget->textHeightBehavior;
}

Widget DefaultTextHeightBehaviorCls::wrap(Widget child, BuildContext context) {
    return make<DefaultTextHeightBehaviorCls>(textHeightBehavior, child);
}

void DefaultTextHeightBehaviorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>("textHeightBehavior", textHeightBehaviornullptr));
}

TextCls::TextCls(String data, Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(data != nullptr, "A non-null String must be provided to a Text widget.");
        textSpan = nullptr;
    }
}

void TextCls::rich(Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, InlineSpan textSpan, TextWidthBasis textWidthBasis)

Widget TextCls::build(BuildContext context) {
    DefaultTextStyle defaultTextStyle = DefaultTextStyleCls->of(context);
    TextStyle effectiveTextStyle = style;
    if (style == nullptr || style!->inherit) {
        effectiveTextStyle = defaultTextStyle->style->merge(style);
    }
    if (MediaQueryCls->boldTextOverride(context)) {
        effectiveTextStyle = effectiveTextStyle!->merge(make<TextStyleCls>(FontWeightCls::bold));
    }
    SelectionRegistrar registrar = SelectionContainerCls->maybeOf(context);
    Widget result = make<RichTextCls>(textAlign ?? defaultTextStyle->textAlign ?? TextAlignCls::start, textDirection, locale, softWrap ?? defaultTextStyle->softWrap, overflow ?? effectiveTextStyle?->overflow ?? defaultTextStyle->overflow, textScaleFactor ?? MediaQueryCls->textScaleFactorOf(context), maxLines ?? defaultTextStyle->maxLines, strutStyle, textWidthBasis ?? defaultTextStyle->textWidthBasis, textHeightBehavior ?? defaultTextStyle->textHeightBehavior ?? DefaultTextHeightBehaviorCls->of(context), registrar, selectionColor ?? DefaultSelectionStyleCls->of(context)->selectionColor, make<TextSpanCls>(effectiveTextStyle, data, textSpan != nullptr? makeList(ArrayItem) : nullptr));
    if (registrar != nullptr) {
        result = make<MouseRegionCls>(SystemMouseCursorsCls::text, result);
    }
    if (semanticsLabel != nullptr) {
        result = make<SemanticsCls>(textDirection, semanticsLabel, make<ExcludeSemanticsCls>(result));
    }
    return result;
}

void TextCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>("data", datafalse));
    if (textSpan != nullptr) {
        properties->add(textSpan!->toDiagnosticsNode("textSpan", DiagnosticsTreeStyleCls::transition));
    }
    style?->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>("textAlign", textAlignnullptr));
    properties->add(<TextDirection>make<EnumPropertyCls>("textDirection", textDirectionnullptr));
    properties->add(<Locale>make<DiagnosticsPropertyCls>("locale", localenullptr));
    properties->add(make<FlagPropertyCls>("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties->add(<TextOverflow>make<EnumPropertyCls>("overflow", overflownullptr));
    properties->add(make<DoublePropertyCls>("textScaleFactor", textScaleFactornullptr));
    properties->add(make<IntPropertyCls>("maxLines", maxLinesnullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>("textWidthBasis", textWidthBasisnullptr));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>("textHeightBehavior", textHeightBehaviornullptr));
    if (semanticsLabel != nullptr) {
        properties->add(make<StringPropertyCls>("semanticsLabel", semanticsLabel));
    }
}
