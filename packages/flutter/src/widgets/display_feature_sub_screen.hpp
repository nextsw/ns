#ifndef DISPLAY_FEATURE_SUB_SCREEN_H
#define DISPLAY_FEATURE_SUB_SCREEN_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "media_query.hpp"



class DisplayFeatureSubScreen : StatelessWidget {
public:
    Offset anchorPoint;

    Widget child;


     DisplayFeatureSubScreen(Offset anchorPoint, Widget child, Unknown);

    Widget build(BuildContext context);

    static Iterable<Rect> avoidBounds(MediaQueryData mediaQuery);

    static Iterable<Rect> subScreensInBounds(Iterable<Rect> avoidBounds, Rect wantedBounds);

private:

    static Offset _fallbackAnchorPoint(BuildContext context);

    static Rect _closestToAnchorPoint(Offset anchorPoint, Iterable<Rect> subScreens);

    static double _distanceFromPointToRect(Offset point, Rect rect);

    static Offset _capOffset(Size maximum, Offset offset);

};

#endif