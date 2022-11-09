#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NAVIGATION_TOOLBAR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NAVIGATION_TOOLBAR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"


class NavigationToolbarCls : public StatelessWidgetCls {
public:
    static double kMiddleSpacing;

    Widget leading;

    Widget middle;

    Widget trailing;

    bool centerMiddle;

    double middleSpacing;


     NavigationToolbarCls(bool centerMiddle, Unknown key, Widget leading, Widget middle, double middleSpacing, Widget trailing);

    virtual Widget build(BuildContext context);

private:

};
using NavigationToolbar = std::shared_ptr<NavigationToolbarCls>;

enum _ToolbarSlot{
    leading,
    middle,
    trailing,
} // end _ToolbarSlot

class _ToolbarLayoutCls : public MultiChildLayoutDelegateCls {
public:
    bool centerMiddle;

    double middleSpacing;

    TextDirection textDirection;


    virtual void performLayout(Size size);

    virtual bool shouldRelayout(_ToolbarLayout oldDelegate);

private:

     _ToolbarLayoutCls(bool centerMiddle, double middleSpacing, TextDirection textDirection);

};
using _ToolbarLayout = std::shared_ptr<_ToolbarLayoutCls>;


#endif