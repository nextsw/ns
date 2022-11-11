#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISPLAY_FEATURE_SUB_SCREEN
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISPLAY_FEATURE_SUB_SCREEN
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "media_query.hpp"


class DisplayFeatureSubScreenCls : public StatelessWidgetCls {
public:
    Offset anchorPoint;

    Widget child;


     DisplayFeatureSubScreenCls(Offset anchorPoint, Widget child, Unknown key);
    virtual Widget build(BuildContext context);

    static Iterable<Rect> avoidBounds(MediaQueryData mediaQuery);

    static Iterable<Rect> subScreensInBounds(Rect wantedBounds, Iterable<Rect> avoidBounds);

private:

    static Offset _fallbackAnchorPoint(BuildContext context);

    static Rect _closestToAnchorPoint(Iterable<Rect> subScreens, Offset anchorPoint);

    static double _distanceFromPointToRect(Offset point, Rect rect);

    static Offset _capOffset(Offset offset, Size maximum);

};
using DisplayFeatureSubScreen = std::shared_ptr<DisplayFeatureSubScreenCls>;


#endif