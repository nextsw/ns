#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_THEME
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_THEME
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "icon_theme_data.hpp"
#include "inherited_theme.hpp"


class IconThemeCls : public InheritedThemeCls {
public:
    IconThemeData data;


     IconThemeCls(Unknown child, IconThemeData data, Unknown key);

    static Widget merge(Widget child, IconThemeData data, Key key);

    static IconThemeData of(BuildContext context);

    virtual bool updateShouldNotify(IconTheme oldWidget);

    virtual Widget wrap(Widget child, BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static IconThemeData _getInheritedIconThemeData(BuildContext context);

};
using IconTheme = std::shared_ptr<IconThemeCls>;


#endif