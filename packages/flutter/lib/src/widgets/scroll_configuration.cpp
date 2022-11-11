#include "scroll_configuration.hpp"
ScrollBehaviorCls::ScrollBehaviorCls(AndroidOverscrollIndicator androidOverscrollIndicator) {
    {
        _androidOverscrollIndicator = androidOverscrollIndicator;
    }
}

AndroidOverscrollIndicator ScrollBehaviorCls::androidOverscrollIndicator() {
    return _androidOverscrollIndicator or _kDefaultAndroidOverscrollIndicator;
}

ScrollBehavior ScrollBehaviorCls::copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    return make<_WrappedScrollBehaviorCls>(this, scrollbars or true, overscroll or true, physics, platform, dragDevices, androidOverscrollIndicator);
}

TargetPlatform ScrollBehaviorCls::getPlatform(BuildContext context) {
    return defaultTargetPlatform;
}

Set<PointerDeviceKind> ScrollBehaviorCls::dragDevices() {
    return _kTouchLikeDeviceTypes;
}

Widget ScrollBehaviorCls::buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context) {
    ;
}

Widget ScrollBehaviorCls::buildScrollbar(Widget child, BuildContext context, ScrollableDetails details) {
    ;
}

Widget ScrollBehaviorCls::buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details) {
    return buildViewportChrome(context, child, details->direction);
}

GestureVelocityTrackerBuilder ScrollBehaviorCls::velocityTrackerBuilder(BuildContext context) {
    ;
}

ScrollPhysics ScrollBehaviorCls::getScrollPhysics(BuildContext context) {
    ;
}

bool ScrollBehaviorCls::shouldNotify(ScrollBehavior oldDelegate) {
    return false;
}

String ScrollBehaviorCls::toString() {
    return objectRuntimeType(this, __s("ScrollBehavior"));
}

Set<PointerDeviceKind> _WrappedScrollBehaviorCls::dragDevices() {
    return _dragDevices or delegate->dragDevices;
}

AndroidOverscrollIndicator _WrappedScrollBehaviorCls::androidOverscrollIndicator() {
    return _androidOverscrollIndicator or delegate->androidOverscrollIndicator;
}

Widget _WrappedScrollBehaviorCls::buildOverscrollIndicator(Widget child, BuildContext context, ScrollableDetails details) {
    if (overscroll) {
        return delegate->buildOverscrollIndicator(context, child, details);
    }
    return child;
}

Widget _WrappedScrollBehaviorCls::buildScrollbar(Widget child, BuildContext context, ScrollableDetails details) {
    if (scrollbars) {
        return delegate->buildScrollbar(context, child, details);
    }
    return child;
}

Widget _WrappedScrollBehaviorCls::buildViewportChrome(AxisDirection axisDirection, Widget child, BuildContext context) {
    return delegate->buildViewportChrome(context, child, axisDirection);
}

ScrollBehavior _WrappedScrollBehaviorCls::copyWith(AndroidOverscrollIndicator androidOverscrollIndicator, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    return delegate->copyWith(scrollbars or this->scrollbars, overscroll or this->overscroll, physics or this->physics, platform or this->platform, dragDevices or this->dragDevices, androidOverscrollIndicator or this->androidOverscrollIndicator);
}

TargetPlatform _WrappedScrollBehaviorCls::getPlatform(BuildContext context) {
    return platform or delegate->getPlatform(context);
}

ScrollPhysics _WrappedScrollBehaviorCls::getScrollPhysics(BuildContext context) {
    return physics or delegate->getScrollPhysics(context);
}

bool _WrappedScrollBehaviorCls::shouldNotify(_WrappedScrollBehavior oldDelegate) {
    return oldDelegate->delegate->runtimeType != delegate->runtimeType || oldDelegate->scrollbars != scrollbars || oldDelegate->overscroll != overscroll || oldDelegate->physics != physics || oldDelegate->platform != platform || !<PointerDeviceKind>setEquals(oldDelegate->dragDevices, dragDevices) || delegate->shouldNotify(oldDelegate->delegate);
}

GestureVelocityTrackerBuilder _WrappedScrollBehaviorCls::velocityTrackerBuilder(BuildContext context) {
    return delegate->velocityTrackerBuilder(context);
}

String _WrappedScrollBehaviorCls::toString() {
    return objectRuntimeType(this, __s("_WrappedScrollBehavior"));
}

_WrappedScrollBehaviorCls::_WrappedScrollBehaviorCls(AndroidOverscrollIndicator androidOverscrollIndicator, ScrollBehavior delegate, Set<PointerDeviceKind> dragDevices, bool overscroll, ScrollPhysics physics, TargetPlatform platform, bool scrollbars) {
    {
        _androidOverscrollIndicator = androidOverscrollIndicator;
        _dragDevices = dragDevices;
    }
}

ScrollBehavior ScrollConfigurationCls::of(BuildContext context) {
    ScrollConfiguration configuration = context-><ScrollConfiguration>dependOnInheritedWidgetOfExactType();
    return configuration?->behavior or make<ScrollBehaviorCls>();
}

bool ScrollConfigurationCls::updateShouldNotify(ScrollConfiguration oldWidget) {
    assert(behavior != nullptr);
    return behavior->runtimeType != oldWidget->behavior->runtimeType || (behavior != oldWidget->behavior && behavior->shouldNotify(oldWidget->behavior));
}

void ScrollConfigurationCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ScrollBehavior>make<DiagnosticsPropertyCls>(__s("behavior"), behavior));
}
