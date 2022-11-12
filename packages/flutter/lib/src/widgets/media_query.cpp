#include "media_query.hpp"
MediaQueryDataCls::MediaQueryDataCls(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding) {
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

void MediaQueryDataCls::fromWindow(FlutterView window)

Orientation MediaQueryDataCls::orientation() {
    return size->width() > size->height()? OrientationCls::landscape : OrientationCls::portrait;
}

MediaQueryData MediaQueryDataCls::copyWith(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding) {
    return make<MediaQueryDataCls>(size | this->size, devicePixelRatio | this->devicePixelRatio, textScaleFactor | this->textScaleFactor, platformBrightness | this->platformBrightness, padding | this->padding, viewPadding | this->viewPadding, viewInsets | this->viewInsets, systemGestureInsets | this->systemGestureInsets, alwaysUse24HourFormat | this->alwaysUse24HourFormat, invertColors | this->invertColors, highContrast | this->highContrast, disableAnimations | this->disableAnimations, accessibleNavigation | this->accessibleNavigation, boldText | this->boldText, navigationMode | this->navigationMode, gestureSettings | this->gestureSettings, displayFeatures | this->displayFeatures);
}

MediaQueryData MediaQueryDataCls::removePadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(padding->copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr), viewPadding->copyWith(removeLeft? math->max(0.0, viewPadding->left - padding->left) : nullptr, removeTop? math->max(0.0, viewPadding->top - padding->top) : nullptr, removeRight? math->max(0.0, viewPadding->right - padding->right) : nullptr, removeBottom? math->max(0.0, viewPadding->bottom - padding->bottom) : nullptr));
}

MediaQueryData MediaQueryDataCls::removeViewInsets(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(viewPadding->copyWith(removeLeft? math->max(0.0, viewPadding->left - viewInsets->left) : nullptr, removeTop? math->max(0.0, viewPadding->top - viewInsets->top) : nullptr, removeRight? math->max(0.0, viewPadding->right - viewInsets->right) : nullptr, removeBottom? math->max(0.0, viewPadding->bottom - viewInsets->bottom) : nullptr), viewInsets->copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr));
}

MediaQueryData MediaQueryDataCls::removeViewPadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    if (!(removeLeft || removeTop || removeRight || removeBottom)) {
        return this;
    }
    return copyWith(padding->copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr), viewPadding->copyWith(removeLeft? 0.0 : nullptr, removeTop? 0.0 : nullptr, removeRight? 0.0 : nullptr, removeBottom? 0.0 : nullptr));
}

MediaQueryData MediaQueryDataCls::removeDisplayFeatures(Rect subScreen) {
    assert(subScreen->left >= 0.0 && subScreen->top >= 0.0 && subScreen->right <= size->width() && subScreen->bottom <= size->height(), __s("'subScreen' argument cannot be outside the bounds of the screen"));
    if (subScreen->size == size && subScreen->topLeft() == OffsetCls::zero) {
        return this;
    }
    double rightInset = size->width() - subScreen->right;
    double bottomInset = size->height() - subScreen->bottom;
    return copyWith(EdgeInsetsCls->only(math->max(0.0, padding->left - subScreen->left), math->max(0.0, padding->top - subScreen->top), math->max(0.0, padding->right - rightInset), math->max(0.0, padding->bottom - bottomInset)), EdgeInsetsCls->only(math->max(0.0, viewPadding->left - subScreen->left), math->max(0.0, viewPadding->top - subScreen->top), math->max(0.0, viewPadding->right - rightInset), math->max(0.0, viewPadding->bottom - bottomInset)), EdgeInsetsCls->only(math->max(0.0, viewInsets->left - subScreen->left), math->max(0.0, viewInsets->top - subScreen->top), math->max(0.0, viewInsets->right - rightInset), math->max(0.0, viewInsets->bottom - bottomInset)), displayFeatures->where([=] (DisplayFeature displayFeature) {
        subScreen->overlaps(displayFeature->bounds);
    })->toList());
}

bool MediaQueryDataCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<MediaQueryData>(other) && other->size == size && other->devicePixelRatio == devicePixelRatio && other->textScaleFactor == textScaleFactor && other->platformBrightness == platformBrightness && other->padding == padding && other->viewPadding == viewPadding && other->viewInsets == viewInsets && other->alwaysUse24HourFormat == alwaysUse24HourFormat && other->highContrast == highContrast && other->disableAnimations == disableAnimations && other->invertColors == invertColors && other->accessibleNavigation == accessibleNavigation && other->boldText == boldText && other->navigationMode == navigationMode && other->gestureSettings == gestureSettings && listEquals(other->displayFeatures, displayFeatures);
}

int MediaQueryDataCls::hashCode() {
    return ObjectCls->hash(size, devicePixelRatio, textScaleFactor, platformBrightness, padding, viewPadding, viewInsets, alwaysUse24HourFormat, highContrast, disableAnimations, invertColors, accessibleNavigation, boldText, navigationMode, gestureSettings, ObjectCls->hashAll(displayFeatures));
}

String MediaQueryDataCls::toString() {
    List<String> properties = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    return __s("%s$%s;");
}

MediaQueryCls::MediaQueryCls(Widget child, MediaQueryData data, Key key) {
    {
        assert(child != nullptr);
        assert(data != nullptr);
    }
}

void MediaQueryCls::removePadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return make<MediaQueryCls>(key, MediaQueryCls->of(context)->removePadding(removeLeft, removeTop, removeRight, removeBottom), child);
}

void MediaQueryCls::removeViewInsets(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return make<MediaQueryCls>(key, MediaQueryCls->of(context)->removeViewInsets(removeLeft, removeTop, removeRight, removeBottom), child);
}

void MediaQueryCls::removeViewPadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop) {
    return make<MediaQueryCls>(key, MediaQueryCls->of(context)->removeViewPadding(removeLeft, removeTop, removeRight, removeBottom), child);
}

Widget MediaQueryCls::fromWindow(Widget child, Key key) {
    return make<_MediaQueryFromWindowCls>(key, child);
}

MediaQueryData MediaQueryCls::of(BuildContext context) {
    assert(context != nullptr);
    assert(debugCheckHasMediaQuery(context));
    return context-><MediaQuery>dependOnInheritedWidgetOfExactType()!->data;
}

MediaQueryData MediaQueryCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context-><MediaQuery>dependOnInheritedWidgetOfExactType()?->data;
}

double MediaQueryCls::textScaleFactorOf(BuildContext context) {
    return MediaQueryCls->maybeOf(context)?->textScaleFactor | 1.0;
}

Brightness MediaQueryCls::platformBrightnessOf(BuildContext context) {
    return MediaQueryCls->maybeOf(context)?->platformBrightness | BrightnessCls::light;
}

bool MediaQueryCls::highContrastOf(BuildContext context) {
    return MediaQueryCls->maybeOf(context)?->highContrast | false;
}

bool MediaQueryCls::boldTextOverride(BuildContext context) {
    return MediaQueryCls->maybeOf(context)?->boldText | false;
}

bool MediaQueryCls::updateShouldNotify(MediaQuery oldWidget) {
    return data != oldWidget->data;
}

void MediaQueryCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<MediaQueryData>make<DiagnosticsPropertyCls>(__s("data"), data, false));
}

State<_MediaQueryFromWindow> _MediaQueryFromWindowCls::createState() {
    return make<_MediaQueryFromWindowStateCls>();
}

void _MediaQueryFromWindowStateCls::initState() {
    super->initState();
    WidgetsBindingCls::instance->addObserver(this);
}

void _MediaQueryFromWindowStateCls::didChangeAccessibilityFeatures() {
    setState([=] () {
    });
}

void _MediaQueryFromWindowStateCls::didChangeMetrics() {
    setState([=] () {
    });
}

void _MediaQueryFromWindowStateCls::didChangeTextScaleFactor() {
    setState([=] () {
    });
}

void _MediaQueryFromWindowStateCls::didChangePlatformBrightness() {
    setState([=] () {
    });
}

Widget _MediaQueryFromWindowStateCls::build(BuildContext context) {
    MediaQueryData data = MediaQueryDataCls->fromWindow(WidgetsBindingCls::instance->window);
    if (!kReleaseMode) {
        data = data->copyWith(debugBrightnessOverride);
    }
    return make<MediaQueryCls>(data, widget()->child);
}

void _MediaQueryFromWindowStateCls::dispose() {
    WidgetsBindingCls::instance->removeObserver(this);
    super->dispose();
}
