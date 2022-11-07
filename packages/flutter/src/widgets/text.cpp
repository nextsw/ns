#include "text.hpp"
DefaultTextStyle::DefaultTextStyle(Unknown, Unknown, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis) {
    {
        assert(style != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(child != nullptr);
        assert(textWidthBasis != nullptr);
    }
}

void DefaultTextStyle::fallback(Unknown)

Widget DefaultTextStyle::merge(Widget child, Key key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextWidthBasis textWidthBasis) {
    assert(child != nullptr);
    return Builder();
}

DefaultTextStyle DefaultTextStyle::of(BuildContext context) {
    return context.<DefaultTextStyle>dependOnInheritedWidgetOfExactType() ?? const DefaultTextStyle.fallback();
}

bool DefaultTextStyle::updateShouldNotify(DefaultTextStyle oldWidget) {
    return style != oldWidget.style || textAlign != oldWidget.textAlign || softWrap != oldWidget.softWrap || overflow != oldWidget.overflow || maxLines != oldWidget.maxLines || textWidthBasis != oldWidget.textWidthBasis || textHeightBehavior != oldWidget.textHeightBehavior;
}

Widget DefaultTextStyle::wrap(Widget child, BuildContext context) {
    return DefaultTextStyle(style, textAlign, softWrap, overflow, maxLines, textWidthBasis, textHeightBehavior, child);
}

void DefaultTextStyle::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    style.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlignnullptr));
    properties.add(FlagProperty("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties.add(<TextOverflow>EnumProperty("overflow", overflownullptr));
    properties.add(IntProperty("maxLines", maxLinesnullptr));
    properties.add(<TextWidthBasis>EnumProperty("textWidthBasis", textWidthBasisTextWidthBasis.parent));
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
}

Widget _NullWidget::build(BuildContext context) {
    ;
}

DefaultTextHeightBehavior::DefaultTextHeightBehavior(Unknown, Unknown, TextHeightBehavior textHeightBehavior) {
    {
        assert(textHeightBehavior != nullptr);
        assert(child != nullptr);
    }
}

TextHeightBehavior DefaultTextHeightBehavior::of(BuildContext context) {
    return context.<DefaultTextHeightBehavior>dependOnInheritedWidgetOfExactType()?.textHeightBehavior;
}

bool DefaultTextHeightBehavior::updateShouldNotify(DefaultTextHeightBehavior oldWidget) {
    return textHeightBehavior != oldWidget.textHeightBehavior;
}

Widget DefaultTextHeightBehavior::wrap(Widget child, BuildContext context) {
    return DefaultTextHeightBehavior(textHeightBehavior, child);
}

void DefaultTextHeightBehavior::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
}

Text::Text(String data, Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(data != nullptr, "A non-null String must be provided to a Text widget.");
        textSpan = nullptr;
    }
}

void Text::rich(Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, InlineSpan textSpan, TextWidthBasis textWidthBasis)

Widget Text::build(BuildContext context) {
    DefaultTextStyle defaultTextStyle = DefaultTextStyle.of(context);
    TextStyle effectiveTextStyle = style;
    if (style == nullptr || style!.inherit) {
        effectiveTextStyle = defaultTextStyle.style.merge(style);
    }
    if (MediaQuery.boldTextOverride(context)) {
        effectiveTextStyle = effectiveTextStyle!.merge(const TextStyle(FontWeight.bold));
    }
    SelectionRegistrar registrar = SelectionContainer.maybeOf(context);
    Widget result = RichText(textAlign ?? defaultTextStyle.textAlign ?? TextAlign.start, textDirection, locale, softWrap ?? defaultTextStyle.softWrap, overflow ?? effectiveTextStyle?.overflow ?? defaultTextStyle.overflow, textScaleFactor ?? MediaQuery.textScaleFactorOf(context), maxLines ?? defaultTextStyle.maxLines, strutStyle, textWidthBasis ?? defaultTextStyle.textWidthBasis, textHeightBehavior ?? defaultTextStyle.textHeightBehavior ?? DefaultTextHeightBehavior.of(context), registrar, selectionColor ?? DefaultSelectionStyle.of(context).selectionColor, TextSpan(effectiveTextStyle, data, textSpan != nullptr?  : nullptr));
    if (registrar != nullptr) {
        result = MouseRegion(SystemMouseCursors.text, result);
    }
    if (semanticsLabel != nullptr) {
        result = Semantics(textDirection, semanticsLabel, ExcludeSemantics(result));
    }
    return result;
}

void Text::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("data", datafalse));
    if (textSpan != nullptr) {
        properties.add(textSpan!.toDiagnosticsNode("textSpan", DiagnosticsTreeStyle.transition));
    }
    style?.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlignnullptr));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<Locale>DiagnosticsProperty("locale", localenullptr));
    properties.add(FlagProperty("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties.add(<TextOverflow>EnumProperty("overflow", overflownullptr));
    properties.add(DoubleProperty("textScaleFactor", textScaleFactornullptr));
    properties.add(IntProperty("maxLines", maxLinesnullptr));
    properties.add(<TextWidthBasis>EnumProperty("textWidthBasis", textWidthBasisnullptr));
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
    if (semanticsLabel != nullptr) {
        properties.add(StringProperty("semanticsLabel", semanticsLabel));
    }
}
