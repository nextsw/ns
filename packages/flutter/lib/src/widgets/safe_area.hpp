#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SAFE_AREA
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SAFE_AREA
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "media_query.hpp"


class SafeAreaCls : public StatelessWidgetCls {
public:
    bool left;

    bool top;

    bool right;

    bool bottom;

    EdgeInsets minimum;

    bool maintainBottomViewPadding;

    Widget child;


     SafeAreaCls(bool bottom, Widget child, Key key, bool left, bool maintainBottomViewPadding, EdgeInsets minimum, bool right, bool top);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SafeArea = std::shared_ptr<SafeAreaCls>;

class SliverSafeAreaCls : public StatelessWidgetCls {
public:
    bool left;

    bool top;

    bool right;

    bool bottom;

    EdgeInsets minimum;

    Widget sliver;


     SliverSafeAreaCls(bool bottom, Key key, bool left, EdgeInsets minimum, bool right, Widget sliver, bool top);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverSafeArea = std::shared_ptr<SliverSafeAreaCls>;


#endif