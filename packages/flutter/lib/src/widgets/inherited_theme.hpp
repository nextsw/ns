#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_THEME
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_THEME
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"


class InheritedThemeCls : public InheritedWidgetCls {
public:

     InheritedThemeCls(Unknown child, Unknown key);
    virtual Widget wrap(BuildContext context, Widget child);
    static Widget captureAll(BuildContext context, Widget child, BuildContext to);

    static CapturedThemes capture(BuildContext from, BuildContext to);

private:

};
using InheritedTheme = std::shared_ptr<InheritedThemeCls>;

class CapturedThemesCls : public ObjectCls {
public:

    virtual Widget wrap(Widget child);

private:
    List<InheritedTheme> _themes;


    virtual void  _(List<InheritedTheme> _themes);
};
using CapturedThemes = std::shared_ptr<CapturedThemesCls>;

class _CaptureAllCls : public StatelessWidgetCls {
public:
    List<InheritedTheme> themes;

    Widget child;


    virtual Widget build(BuildContext context);

private:

     _CaptureAllCls(Widget child, List<InheritedTheme> themes);

};
using _CaptureAll = std::shared_ptr<_CaptureAllCls>;


#endif