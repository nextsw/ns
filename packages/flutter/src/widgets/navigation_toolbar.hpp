#ifndef NAVIGATION_TOOLBAR_H
#define NAVIGATION_TOOLBAR_H
#include <memory>

#include <math/math.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"



class NavigationToolbar : StatelessWidget {
public:
    static const double kMiddleSpacing;

    Widget leading;

    Widget middle;

    Widget trailing;

    bool centerMiddle;

    double middleSpacing;


     NavigationToolbar(bool centerMiddle, Unknown, Widget leading, Widget middle, double middleSpacing, Widget trailing);

    Widget build(BuildContext context);

private:

};

enum _ToolbarSlot{
    leading,
    middle,
    trailing,
} // end _ToolbarSlot

class _ToolbarLayout : MultiChildLayoutDelegate {
public:
    bool centerMiddle;

    double middleSpacing;

    TextDirection textDirection;


    void performLayout(Size size);

    bool shouldRelayout(_ToolbarLayout oldDelegate);

private:

     _ToolbarLayout(bool centerMiddle, double middleSpacing, TextDirection textDirection);

};

#endif