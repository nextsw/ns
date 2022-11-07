#ifndef SAFE_AREA_H
#define SAFE_AREA_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "media_query.hpp"



class SafeArea : StatelessWidget {
public:
    bool left;

    bool top;

    bool right;

    bool bottom;

    EdgeInsets minimum;

    bool maintainBottomViewPadding;

    Widget child;


     SafeArea(bool bottom, Widget child, Unknown, bool left, bool maintainBottomViewPadding, EdgeInsets minimum, bool right, bool top);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverSafeArea : StatelessWidget {
public:
    bool left;

    bool top;

    bool right;

    bool bottom;

    EdgeInsets minimum;

    Widget sliver;


     SliverSafeArea(bool bottom, Unknown, bool left, EdgeInsets minimum, bool right, Widget sliver, bool top);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif