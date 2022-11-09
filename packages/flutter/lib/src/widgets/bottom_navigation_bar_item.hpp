#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BOTTOM_NAVIGATION_BAR_ITEM
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BOTTOM_NAVIGATION_BAR_ITEM
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "framework.hpp"


class BottomNavigationBarItemCls : public ObjectCls {
public:
    Widget icon;

    Widget activeIcon;

    String label;

    Color backgroundColor;

    String tooltip;


     BottomNavigationBarItemCls(Widget activeIcon, Color backgroundColor, Widget icon, String label, String tooltip);

private:

};
using BottomNavigationBarItem = std::shared_ptr<BottomNavigationBarItemCls>;


#endif