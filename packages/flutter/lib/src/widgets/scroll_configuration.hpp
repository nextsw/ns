#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONFIGURATION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONFIGURATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "overscroll_indicator.hpp"
#include "scroll_physics.hpp"
#include "scrollable.hpp"
#include "scrollbar.hpp"

Color _kDefaultGlowColor;

Set<PointerDeviceKind> _kTouchLikeDeviceTypes;

AndroidOverscrollIndicator _kDefaultAndroidOverscrollIndicator;


enum AndroidOverscrollIndicator{
    stretch,
    glow,
} // end AndroidOverscrollIndicator

class ScrollBehaviorCls : public ObjectCls {
public:

     ScrollBehaviorCls(AndroidOverscrollIndicator androidOverscrollIndicator);

    virtual AndroidOverscrollIndicator androidOverscrollIndicator();

    virtual ScrollBehavior copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

    virtual TargetPlatform getPlatform(BuildContext context);

    virtual Set<PointerDeviceKind> dragDevices();

    virtual Widget buildViewportChrome(BuildContext context, Widget child, AxisDirection axisDirection);

    virtual Widget buildScrollbar(BuildContext context, Widget child, ScrollableDetails details);

    virtual Widget buildOverscrollIndicator(BuildContext context, Widget child, ScrollableDetails details);

    virtual GestureVelocityTrackerBuilder velocityTrackerBuilder(BuildContext context);

    virtual ScrollPhysics getScrollPhysics(BuildContext context);

    virtual bool shouldNotify(ScrollBehavior oldDelegate);

    virtual String toString();

private:
    AndroidOverscrollIndicator _androidOverscrollIndicator;

    static ScrollPhysics _bouncingPhysics;

    static ScrollPhysics _clampingPhysics;


};
using ScrollBehavior = std::shared_ptr<ScrollBehaviorCls>;

class _WrappedScrollBehaviorCls : public ObjectCls {
public:
    ScrollBehavior delegate;

    bool scrollbars;

    bool overscroll;

    ScrollPhysics physics;

    TargetPlatform platform;


    virtual Set<PointerDeviceKind> dragDevices();

    virtual AndroidOverscrollIndicator androidOverscrollIndicator();

    virtual Widget buildOverscrollIndicator(BuildContext context, Widget child, ScrollableDetails details);

    virtual Widget buildScrollbar(BuildContext context, Widget child, ScrollableDetails details);

    virtual Widget buildViewportChrome(BuildContext context, Widget child, AxisDirection axisDirection);

    virtual ScrollBehavior copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

    virtual TargetPlatform getPlatform(BuildContext context);

    virtual ScrollPhysics getScrollPhysics(BuildContext context);

    virtual bool shouldNotify(_WrappedScrollBehavior oldDelegate);

    virtual GestureVelocityTrackerBuilder velocityTrackerBuilder(BuildContext context);

    virtual String toString();

private:
    Set<PointerDeviceKind> _dragDevices;

    AndroidOverscrollIndicator _androidOverscrollIndicator;


     _WrappedScrollBehaviorCls(AndroidOverscrollIndicator androidOverscrollIndicator, ScrollBehavior delegate, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

};
using _WrappedScrollBehavior = std::shared_ptr<_WrappedScrollBehaviorCls>;

class ScrollConfigurationCls : public InheritedWidgetCls {
public:
    ScrollBehavior behavior;


     ScrollConfigurationCls(ScrollBehavior behavior, Unknown child, Unknown key);
    static ScrollBehavior of(BuildContext context);

    virtual bool updateShouldNotify(ScrollConfiguration oldWidget);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ScrollConfiguration = std::shared_ptr<ScrollConfigurationCls>;


#endif