#ifndef INHERITED_THEME_H
#define INHERITED_THEME_H
#include <memory>

#include "framework.hpp"



class InheritedTheme : InheritedWidget {
public:

     InheritedTheme(Unknown, Unknown);

    Widget wrap(Widget child, BuildContext context);

    static Widget captureAll(Widget child, BuildContext context, BuildContext to);

    static CapturedThemes capture(BuildContext from, BuildContext to);

private:

};

class CapturedThemes {
public:

    Widget wrap(Widget child);

private:
    List<InheritedTheme> _themes;


    void  _(List<InheritedTheme> _themes);

};

class _CaptureAll : StatelessWidget {
public:
    List<InheritedTheme> themes;

    Widget child;


    Widget build(BuildContext context);

private:

     _CaptureAll(Widget child, List<InheritedTheme> themes);

};

#endif