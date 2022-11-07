#ifndef ICON_THEME_H
#define ICON_THEME_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "icon_theme_data.hpp"
#include "inherited_theme.hpp"



class IconTheme : InheritedTheme {
public:
    IconThemeData data;


     IconTheme(Unknown, IconThemeData data, Unknown);

    static Widget merge(Widget child, IconThemeData data, Key key);

    static IconThemeData of(BuildContext context);

    bool updateShouldNotify(IconTheme oldWidget);

    Widget wrap(Widget child, BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static IconThemeData _getInheritedIconThemeData(BuildContext context);

};

#endif