#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "default_selection_style.hpp"
#include "framework.hpp"
#include "inherited_theme.hpp"
#include "media_query.hpp"
#include "selection_container.hpp"


class DefaultTextStyleCls : public InheritedThemeCls {
public:
    TextStyle style;

    TextAlign textAlign;

    bool softWrap;

    TextOverflow overflow;

    int maxLines;

    TextWidthBasis textWidthBasis;

    TextHeightBehavior textHeightBehavior;


     DefaultTextStyleCls(Unknown child, Unknown key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextHeightBehavior textHeightBehavior, TextWidthBasis textWidthBasis);

    virtual void  fallback(Unknown key);

    static Widget merge(Widget child, Key key, int maxLines, TextOverflow overflow, bool softWrap, TextStyle style, TextAlign textAlign, TextWidthBasis textWidthBasis);

    static DefaultTextStyle of(BuildContext context);

    virtual bool updateShouldNotify(DefaultTextStyle oldWidget);

    virtual Widget wrap(BuildContext context, Widget child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using DefaultTextStyle = std::shared_ptr<DefaultTextStyleCls>;

class _NullWidgetCls : public StatelessWidgetCls {
public:

    virtual Widget build(BuildContext context);

private:

     _NullWidgetCls();
};
using _NullWidget = std::shared_ptr<_NullWidgetCls>;

class DefaultTextHeightBehaviorCls : public InheritedThemeCls {
public:
    TextHeightBehavior textHeightBehavior;


     DefaultTextHeightBehaviorCls(Unknown child, Unknown key, TextHeightBehavior textHeightBehavior);

    static TextHeightBehavior of(BuildContext context);

    virtual bool updateShouldNotify(DefaultTextHeightBehavior oldWidget);

    virtual Widget wrap(BuildContext context, Widget child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using DefaultTextHeightBehavior = std::shared_ptr<DefaultTextHeightBehaviorCls>;

class TextCls : public StatelessWidgetCls {
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


     TextCls(String data, Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    virtual void  rich(InlineSpan textSpan, Unknown key, Locale locale, int maxLines, TextOverflow overflow, Color selectionColor, String semanticsLabel, bool softWrap, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Text = std::shared_ptr<TextCls>;


#endif