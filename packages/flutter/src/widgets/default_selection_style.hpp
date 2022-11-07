#ifndef DEFAULT_SELECTION_STYLE_H
#define DEFAULT_SELECTION_STYLE_H
#include <memory>

#include <ui/ui.hpp>
#include "framework.hpp"
#include "inherited_theme.hpp"



class DefaultSelectionStyle : InheritedTheme {
public:
    Color cursorColor;

    Color selectionColor;


     DefaultSelectionStyle(Unknown, Color cursorColor, Unknown, Color selectionColor);

    void  fallback(Unknown);

    static DefaultSelectionStyle of(BuildContext context);

    Widget wrap(Widget child, BuildContext context);

    bool updateShouldNotify(DefaultSelectionStyle oldWidget);

private:

};

class _NullWidget : StatelessWidget {
public:

    Widget build(BuildContext context);

private:

     _NullWidget();

};

#endif