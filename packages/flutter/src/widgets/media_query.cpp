#include "media_query.hpp"
MediaQueryData::MediaQueryData(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding) {
    {
        assert(size != nullptr);
        assert(devicePixelRatio != nullptr);
        assert(textScaleFactor != nullptr);
        assert(platformBrightness != nullptr);
        assert(padding != nullptr);
        assert(viewInsets != nullptr);
        assert(systemGestureInsets != nullptr);
        assert(viewPadding != nullptr);
        assert(alwaysUse24HourFormat != nullptr);
        assert(accessibleNavigation != nullptr);
        assert(invertColors != nullptr);
        assert(highContrast != nullptr);
        assert(disableAnimations != nullptr);
        assert(boldText != nullptr);
        assert(navigationMode != nullptr);
        assert(gestureSettings != nullptr);
        assert(displayFeatures != nullptr);
    }
}

void MediaQueryData::fromWindow(FlutterView window)

Orientation MediaQueryData::orientation() {
    return size.width > size.height? Orientation.landscape : Orientation.portrait;
}

MediaQueryData MediaQueryData::copyWith(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding) {
    return MediaQueryData(size ?? this.size, devicePixelRatio ?? this.devicePixelRatio, textScaleFactor ?? this.textScaleFactor, platformBrightness ?? this.platformBrightness, padding ?? this.padding, viewPadding ?? this.viewPadding, viewInsets ?? this.viewInsets, systemGestureInsets ?? this.systemGestureInsets, alwaysUse24HourFormat ?? this.alwaysUse24HourFormat, invertColors ?? this.invertColors, highContrast ?? this.highContrast, disableAnimations ?? this.disableAnimations, accessibleNavigation ?? this.accessibleNavigation, boldText ?? this.boldText, navigationMode ?? this.navigationMode, gestureSettings ?? this.gestureSettings, displayFeatures ?? this.displayFeatures);
}

MediaQueryData MediaQueryData::removePadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(padding.copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr), viewPadding.copyWith(removeLeft? math.max(0.0, viewPadding.left - padding.left) : nullptr, removeTop? math.max(0.0, viewPadding.top - padding.top) : nullptr, removeRight? math.max(0.0, viewPadding.right - padding.right) : nullptr, removeBottom? math.max(0.0, viewPadding.bottom - padding.bottom) : nullptr));
}

MediaQueryData MediaQueryData::removeViewInsets(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(viewPadding.copyWith(removeLeft? math.max(0.0, viewPadding.left - viewInsets.left) : nullptr, removeTop? math.max(0.0, viewPadding.top - viewInsets.top) : nullptr, removeRight? math.max(0.0, viewPadding.right - viewInsets.right) : nullptr, removeBottom? math.max(0.0, viewPadding.bottom - viewInsets.bottom) : nullptr), viewInsets.copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr));
}

MediaQueryData MediaQueryData::removeViewPadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(padding.copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr), viewPadding.copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr));
}

MediaQueryData MediaQueryData::removeDisplayFeatures(Rect subScreen) {
    assert(subScreen.left >= 0.0 && subScreen.top >= 0.0 && subScreen.right <= size.width && subScreen.bottom <= size.height, "'subScreen' argument cannot be outside the bounds of the screen");
    if (subScreen.size == size && subScreen.topLeft == Offset.zero) {
        return this;
    }
    double rightInset = size.width - subScreen.right;
    double bottomInset = size.height - subScreen.bottom;
    return copyWith(EdgeInsets.only(math.max(0.0, padding.left - subScreen.left), math.max(0.0, padding.top - subScreen.top), math.max(0.0, padding.right - rightInset), math.max(0.0, padding.bottom - bottomInset)), EdgeInsets.only(math.max(0.0, viewPadding.left - subScreen.left), math.max(0.0, viewPadding.top - subScreen.top), math.max(0.0, viewPadding.right - rightInset), math.max(0.0, viewPadding.bottom - bottomInset)), EdgeInsets.only(math.max(0.0, viewInsets.left - subScreen.left), math.max(0.0, viewInsets.top - subScreen.top), math.max(0.0, viewInsets.right - rightInset), math.max(0.0, viewInsets.bottom - bottomInset)), displayFeatures.where().toList());
}

bool MediaQueryData::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is MediaQueryData && other.size == size && other.devicePixelRatio == devicePixelRatio && other.textScaleFactor == textScaleFactor && other.platformBrightness == platformBrightness && other.padding == padding && other.viewPadding == viewPadding && other.viewInsets == viewInsets && other.alwaysUse24HourFormat == alwaysUse24HourFormat && other.highContrast == highContrast && other.disableAnimations == disableAnimations && other.invertColors == invertColors && other.accessibleNavigation == accessibleNavigation && other.boldText == boldText && other.navigationMode == navigationMode && other.gestureSettings == gestureSettings && listEquals(other.displayFeatures, displayFeatures);
}

int MediaQueryData::hashCode() {
    return Object.hash(size, devicePixelRatio, textScaleFactor, platformBrightness, padding, viewPadding, viewInsets, alwaysUse24HourFormat, highContrast, disableAnimations, invertColors, accessibleNavigation, boldText, navigationMode, gestureSettings, Object.hashAll(displayFeatures));
}

String MediaQueryData::toString() {
    List<String> properties = ;
    return "${objectRuntimeType(this, 'MediaQueryData')}(${properties.join(', ')})";
}

MediaQuery::MediaQuery(Unknown, MediaQueryData data, Unknown) {
    {
        assert(child != nullptr);
        assert(data != nullptr);
    }
}

void MediaQuery::removePadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return MediaQuery(key, MediaQuery.of(context).removePadding(removeLeft, removeTop, removeRight, removeBottom), child);
}

void MediaQuery::removeViewInsets(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return MediaQuery(key, MediaQuery.of(context).removeViewInsets(removeLeft, removeTop, removeRight, removeBottom), child);
}

void MediaQuery::removeViewPadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return MediaQuery(key, MediaQuery.of(context).removeViewPadding(removeLeft, removeTop, removeRight, removeBottom), child);
}

Widget MediaQuery::fromWindow(Widget child, Key key) {
    return _MediaQueryFromWindow(key, child);
}

MediaQueryData MediaQuery::of(BuildContext context) {
    assert(context != nullptr);
    assert(debugCheckHasMediaQuery(context));
    return context.<MediaQuery>dependOnInheritedWidgetOfExactType()!.data;
}

MediaQueryData MediaQuery::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context.<MediaQuery>dependOnInheritedWidgetOfExactType()?.data;
}

double MediaQuery::textScaleFactorOf(BuildContext context) {
    return MediaQuery.maybeOf(context)?.textScaleFactor ?? 1.0;
}

Brightness MediaQuery::platformBrightnessOf(BuildContext context) {
    return MediaQuery.maybeOf(context)?.platformBrightness ?? Brightness.light;
}

bool MediaQuery::highContrastOf(BuildContext context) {
    return MediaQuery.maybeOf(context)?.highContrast ?? false;
}

bool MediaQuery::boldTextOverride(BuildContext context) {
    return MediaQuery.maybeOf(context)?.boldText ?? false;
}

bool MediaQuery::updateShouldNotify(MediaQuery oldWidget) {
    return data != oldWidget.data;
}

void MediaQuery::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<MediaQueryData>DiagnosticsProperty("data", datafalse));
}

State<_MediaQueryFromWindow> _MediaQueryFromWindow::createState() {
    return _MediaQueryFromWindowState();
}

void _MediaQueryFromWindowState::initState() {
    super.initState();
    WidgetsBinding.instance.addObserver(this);
}

void _MediaQueryFromWindowState::didChangeAccessibilityFeatures() {
    setState();
}

void _MediaQueryFromWindowState::didChangeMetrics() {
    setState();
}

void _MediaQueryFromWindowState::didChangeTextScaleFactor() {
    setState();
}

void _MediaQueryFromWindowState::didChangePlatformBrightness() {
    setState();
}

Widget _MediaQueryFromWindowState::build(BuildContext context) {
    MediaQueryData data = MediaQueryData.fromWindow(WidgetsBinding.instance.window);
    if (!kReleaseMode) {
        data = data.copyWith(debugBrightnessOverride);
    }
    return MediaQuery(data, widget.child);
}

void _MediaQueryFromWindowState::dispose() {
    WidgetsBinding.instance.removeObserver(this);
    super.dispose();
}
