#ifndef SCROLL_CONFIGURATION_H
#define SCROLL_CONFIGURATION_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "overscroll_indicator.hpp"
#include "scroll_physics.hpp"
#include "scrollable.hpp"
#include "scrollbar.hpp"


const Color _kDefaultGlowColor;

const Set<PointerDeviceKind> _kTouchLikeDeviceTypes;

const AndroidOverscrollIndicator _kDefaultAndroidOverscrollIndicator;


enum AndroidOverscrollIndicator{
    stretch,
    glow,
} // end AndroidOverscrollIndicator

class ScrollBehavior {
public:

     ScrollBehavior(AndroidOverscrollIndicator androidOverscrollIndicator);

    AndroidOverscrollIndicator androidOverscrollIndicator();

    ScrollBehavior copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

    TargetPlatform getPlatform(BuildContext context);

    Set<PointerDeviceKind> dragDevices();

    Widget buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context);

    Widget buildScrollbar(Widget child, BuildContext context, ScrollableDetails details);

    Widget buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details);

    GestureVelocityTrackerBuilder velocityTrackerBuilder(BuildContext context);

    ScrollPhysics getScrollPhysics(BuildContext context);

    bool shouldNotify(ScrollBehavior oldDelegate);

    String toString();

private:
    AndroidOverscrollIndicator _androidOverscrollIndicator;

    static const ScrollPhysics _bouncingPhysics;

    static const ScrollPhysics _clampingPhysics;


};

class _WrappedScrollBehavior {
public:
    ScrollBehavior delegate;

    bool scrollbars;

    bool overscroll;

    ScrollPhysics physics;

    TargetPlatform platform;


    Set<PointerDeviceKind> dragDevices();

    AndroidOverscrollIndicator androidOverscrollIndicator();

    Widget buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details);

    Widget buildScrollbar(Widget child, BuildContext context, ScrollableDetails details);

    Widget buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context);

    ScrollBehavior copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

    TargetPlatform getPlatform(BuildContext context);

    ScrollPhysics getScrollPhysics(BuildContext context);

    bool shouldNotify(_WrappedScrollBehavior oldDelegate);

    GestureVelocityTrackerBuilder velocityTrackerBuilder(BuildContext context);

    String toString();

private:
    Set<PointerDeviceKind> _dragDevices;

    AndroidOverscrollIndicator _androidOverscrollIndicator;


     _WrappedScrollBehavior(AndroidOverscrollIndicator androidOverscrollIndicator, ScrollBehavior delegate, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars);

};

class ScrollConfiguration : InheritedWidget {
public:
    ScrollBehavior behavior;


     ScrollConfiguration(ScrollBehavior behavior, Unknown, Unknown);

    static ScrollBehavior of(BuildContext context);

    bool updateShouldNotify(ScrollConfiguration oldWidget);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif