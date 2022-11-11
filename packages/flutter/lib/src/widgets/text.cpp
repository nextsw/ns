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
        return make<DefaultTextStyleCls>(key, parent->style->merge(style), textAlign | parent->textAlign, softWrap | parent->softWrap, overflow | parent->overflow, maxLines | parent->maxLines, textWidthBasis | parent->textWidthBasis, child);
    });
}

DefaultTextStyle DefaultTextStyleCls::of(BuildContext context) {
    return context-><DefaultTextStyle>dependOnInheritedWidgetOfExactType() | DefaultTextStyleCls->fallback();
}

bool DefaultTextStyleCls::updateShouldNotify(DefaultTextStyle oldWidget) {
    return style != oldWidget->style || textAlign != oldWidget->textAlign || softWrap != oldWidget->softWrap || overflow != oldWidget->overflow || maxLines != oldWidget->maxLines || textWidthBasis != oldWidget->textWidthBasis || textHeightBehavior != oldWidget->textHeightBehavior;
}

Widget DefaultTextStyleCls::wrap(BuildContext context, Widget child) {
    return make<DefaultTextStyleCls>(style, textAlign, softWrap, overflow, maxLines, textWidthBasis, textHeightBehavior, child);
}

void DefaultTextStyleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    style->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlignnullptr));
    properties->add(make<FlagPropertyCls>(__s("softWrap")softWrap, __s("wrapping at box width"), __s("no wrapping except at line break characters"), true));
    properties->add(<TextOverflow>make<EnumPropertyCls>(__s("overflow"), overflownullptr));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLinesnullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>(__s("textWidthBasis"), textWidthBasisTextWidthBasisCls::parent));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehaviornullptr));
}

Widget _NullWidgetCls::build(BuildContext context) {
    throw make<FlutterErrorCls>(__s("A DefaultTextStyle constructed with DefaultTextStyle.fallback cannot be incorporated into the widget tree, it is meant only to provide a fallback value returned by DefaultTextStyle.of() when no enclosing default text style is present in a BuildContext."));
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

Widget DefaultTextHeightBehaviorCls::wrap(BuildContext context, Widget child) {
    return make<DefaultTextHeightBehaviorCls>(textHeightBehavior, child);
}

void DefaultTextHeightBehaviorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehaviornullptr));
}

TextCls::TextCls(String data, Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(data != nullptr, __s("A non-null String must be provided to a Text widget."));
        textSpan = nullptr;
    }
}

void TextCls::rich(InlineSpan textSpan, Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis)

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
    Widget result = make<RichTextCls>(textAlign | defaultTextStyle->textAlign | TextAlignCls::start, textDirection, locale, softWrap | defaultTextStyle->softWrap, overflow | effectiveTextStyle?->overflow | defaultTextStyle->overflow, textScaleFactor | MediaQueryCls->textScaleFactorOf(context), maxLines | defaultTextStyle->maxLines, strutStyle, textWidthBasis | defaultTextStyle->textWidthBasis, textHeightBehavior | defaultTextStyle->textHeightBehavior | DefaultTextHeightBehaviorCls->of(context), registrar, selectionColor | DefaultSelectionStyleCls->of(context)->selectionColor, make<TextSpanCls>(effectiveTextStyle, data, textSpan != nullptr? makeList(ArrayItem) : nullptr));
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
    properties->add(make<StringPropertyCls>(__s("data"), datafalse));
    if (textSpan != nullptr) {
        properties->add(textSpan!->toDiagnosticsNode(__s("textSpan"), DiagnosticsTreeStyleCls::transition));
    }
    style?->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlignnullptr));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirectionnullptr));
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), localenullptr));
    properties->add(make<FlagPropertyCls>(__s("softWrap")softWrap, __s("wrapping at box width"), __s("no wrapping except at line break characters"), true));
    properties->add(<TextOverflow>make<EnumPropertyCls>(__s("overflow"), overflownullptr));
    properties->add(make<DoublePropertyCls>(__s("textScaleFactor"), textScaleFactornullptr));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLinesnullptr));
    properties->add(<TextWidthBasis>make<EnumPropertyCls>(__s("textWidthBasis"), textWidthBasisnullptr));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehaviornullptr));
    if (semanticsLabel != nullptr) {
        properties->add(make<StringPropertyCls>(__s("semanticsLabel"), semanticsLabel));
    }
}
