#include "scroll_configuration.hpp"
ScrollBehavior::ScrollBehavior(AndroidOverscrollIndicator androidOverscrollIndicator) {
    {
        _androidOverscrollIndicator = androidOverscrollIndicator;
    }
}

AndroidOverscrollIndicator ScrollBehavior::androidOverscrollIndicator() {
    return _androidOverscrollIndicator ?? _kDefaultAndroidOverscrollIndicator;
}

ScrollBehavior ScrollBehavior::copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    return _WrappedScrollBehavior(this, scrollbars ?? true, overscroll ?? true, physics, platform, dragDevices, androidOverscrollIndicator);
}

TargetPlatform ScrollBehavior::getPlatform(BuildContext context) {
    return defaultTargetPlatform;
}

Set<PointerDeviceKind> ScrollBehavior::dragDevices() {
    return _kTouchLikeDeviceTypes;
}

Widget ScrollBehavior::buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context) {
    ;
}

Widget ScrollBehavior::buildScrollbar(Widget child, BuildContext context, ScrollableDetails details) {
    ;
}

Widget ScrollBehavior::buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details) {
    return buildViewportChrome(context, child, details.direction);
}

GestureVelocityTrackerBuilder ScrollBehavior::velocityTrackerBuilder(BuildContext context) {
    ;
}

ScrollPhysics ScrollBehavior::getScrollPhysics(BuildContext context) {
    ;
}

bool ScrollBehavior::shouldNotify(ScrollBehavior oldDelegate) {
    return false;
}

String ScrollBehavior::toString() {
    return objectRuntimeType(this, "ScrollBehavior");
}

Set<PointerDeviceKind> _WrappedScrollBehavior::dragDevices() {
    return _dragDevices ?? delegate.dragDevices;
}

AndroidOverscrollIndicator _WrappedScrollBehavior::androidOverscrollIndicator() {
    return _androidOverscrollIndicator ?? delegate.androidOverscrollIndicator;
}

Widget _WrappedScrollBehavior::buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details) {
    if (overscroll) {
        return delegate.buildOverscrollIndicator(context, child, details);
    }
    return child;
}

Widget _WrappedScrollBehavior::buildScrollbar(Widget child, BuildContext context, ScrollableDetails details) {
    if (scrollbars) {
        return delegate.buildScrollbar(context, child, details);
    }
    return child;
}

Widget _WrappedScrollBehavior::buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context) {
    return delegate.buildViewportChrome(context, child, axisDirection);
}

ScrollBehavior _WrappedScrollBehavior::copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    return delegate.copyWith(scrollbars ?? this.scrollbars, overscroll ?? this.overscroll, physics ?? this.physics, platform ?? this.platform, dragDevices ?? this.dragDevices, androidOverscrollIndicator ?? this.androidOverscrollIndicator);
}

TargetPlatform _WrappedScrollBehavior::getPlatform(BuildContext context) {
    return platform ?? delegate.getPlatform(context);
}

ScrollPhysics _WrappedScrollBehavior::getScrollPhysics(BuildContext context) {
    return physics ?? delegate.getScrollPhysics(context);
}

bool _WrappedScrollBehavior::shouldNotify(_WrappedScrollBehavior oldDelegate) {
    return oldDelegate.delegate.runtimeType != delegate.runtimeType || oldDelegate.scrollbars != scrollbars || oldDelegate.overscroll != overscroll || oldDelegate.physics != physics || oldDelegate.platform != platform || !<PointerDeviceKind>setEquals(oldDelegate.dragDevices, dragDevices) || delegate.shouldNotify(oldDelegate.delegate);
}

GestureVelocityTrackerBuilder _WrappedScrollBehavior::velocityTrackerBuilder(BuildContext context) {
    return delegate.velocityTrackerBuilder(context);
}

String _WrappedScrollBehavior::toString() {
    return objectRuntimeType(this, "_WrappedScrollBehavior");
}

_WrappedScrollBehavior::_WrappedScrollBehavior(AndroidOverscrollIndicator androidOverscrollIndicator, ScrollBehavior delegate, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    {
        _androidOverscrollIndicator = androidOverscrollIndicator;
        _dragDevices = dragDevices;
    }
}

ScrollBehavior ScrollConfiguration::of(BuildContext context) {
    ScrollConfiguration configuration = context.<ScrollConfiguration>dependOnInheritedWidgetOfExactType();
    return configuration?.behavior ?? const ScrollBehavior();
}

bool ScrollConfiguration::updateShouldNotify(ScrollConfiguration oldWidget) {
    assert(behavior != nullptr);
    return behavior.runtimeType != oldWidget.behavior.runtimeType || (behavior != oldWidget.behavior && behavior.shouldNotify(oldWidget.behavior));
}

void ScrollConfiguration::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ScrollBehavior>DiagnosticsProperty("behavior", behavior));
}
