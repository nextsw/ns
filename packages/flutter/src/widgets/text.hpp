#ifndef TEXT_H
#define TEXT_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "default_selection_style.hpp"
#include "framework.hpp"
#include "inherited_theme.hpp"
#include "media_query.hpp"
#include "selection_container.hpp"



class DefaultTextStyle : InheritedTheme {
public:
    TextStyle style;

    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;


     DefaultTextStyle(Unknown, Unknown, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis);

    void  fallback(Unknown);

    static Widget merge(Widget child, Key key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextWidthBasis textWidthBasis);

    static DefaultTextStyle of(BuildContext context);

    bool updateShouldNotify(DefaultTextStyle oldWidget);

    Widget wrap(Widget child, BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _NullWidget : StatelessWidget {
public:

    Widget build(BuildContext context);

private:

     _NullWidget();

};

class DefaultTextHeightBehavior : InheritedTheme {
public:
    TextHeightBehavior textHeightBehavior;


     DefaultTextHeightBehavior(Unknown, Unknown, TextHeightBehavior textHeightBehavior);

    static TextHeightBehavior of(BuildContext context);

    bool updateShouldNotify(DefaultTextHeightBehavior oldWidget);

    Widget wrap(Widget child, BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Text : StatelessWidget {
public:
    String data;

    InlineSpan textSpan;

    TextStyle style;

    StrutStyle strutStyle;

    TextAlign textAlign;

    TextDirection textDirection;

    Locale locale;

    bool softWrap;

    TextOverflow overflow;

    double textScaleFactor;

    int maxLines;

    String semanticsLabel;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;

    Color selectionColor;


     Text(String data, Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    void  rich(Unknown, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, InlineSpan textSpan, TextWidthBasis textWidthBasis);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif