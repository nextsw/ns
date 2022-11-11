#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "icon_data.hpp"
#include "icon_theme.hpp"
#include "icon_theme_data.hpp"


class IconCls : public StatelessWidgetCls {
public:
    IconData icon;

    double size;

    Color color;

    String semanticLabel;

    TextDirection textDirection;

    List<Shadow> shadows;


     IconCls(IconData icon, Color color, Unknown key, String semanticLabel, List<Shadow> shadows, double size, TextDirection textDirection);
    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Icon = std::shared_ptr<IconCls>;


#endif