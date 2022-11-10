#include "bottom_navigation_bar_item.hpp"
BottomNavigationBarItemCls::BottomNavigationBarItemCls(Widget activeIcon, Color backgroundColor, Widget icon, String label, String tooltip) {
    {
        activeIcon = activeIcon or icon;
        assert(icon != nullptr);
    }
}
