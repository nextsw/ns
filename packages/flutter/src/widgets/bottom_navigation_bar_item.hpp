#ifndef BOTTOM_NAVIGATION_BAR_ITEM_H
#define BOTTOM_NAVIGATION_BAR_ITEM_H
#include <memory>

#include <ui/ui.hpp>
#include "framework.hpp"



class BottomNavigationBarItem {
public:
    Widget icon;

    Widget activeIcon;

    String label;

    Color backgroundColor;

    String tooltip;


     BottomNavigationBarItem(Widget activeIcon, Color backgroundColor, Widget icon, String label, String tooltip);

private:

};

#endif