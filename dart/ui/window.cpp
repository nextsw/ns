#include "window.hpp"
double FlutterViewCls::devicePixelRatio() {
    return viewConfiguration()->devicePixelRatio;
}

Rect FlutterViewCls::physicalGeometry() {
    return viewConfiguration()->geometry;
}

Size FlutterViewCls::physicalSize() {
    return viewConfiguration()->geometry->size;
}

WindowPadding FlutterViewCls::viewInsets() {
    return viewConfiguration()->viewInsets;
}

WindowPadding FlutterViewCls::viewPadding() {
    return viewConfiguration()->viewPadding;
}

WindowPadding FlutterViewCls::systemGestureInsets() {
    return viewConfiguration()->systemGestureInsets;
}

WindowPadding FlutterViewCls::padding() {
    return viewConfiguration()->padding;
}

List<DisplayFeature> FlutterViewCls::displayFeatures() {
    return viewConfiguration()->displayFeatures;
}

void FlutterViewCls::render(Scene scene) {
    return _render(scene, this);
}

ViewConfiguration FlutterWindowCls::viewConfiguration() {
    assert(platformDispatcher->_viewConfigurations->containsKey(_windowId));
    return platformDispatcher->_viewConfigurations[_windowId]!;
}

VoidCallback SingletonFlutterWindowCls::onMetricsChanged() {
    return platformDispatcher->onMetricsChanged;
}

void SingletonFlutterWindowCls::onMetricsChanged(VoidCallback callback) {
    platformDispatcher->onMetricsChanged = callback;
}

Locale SingletonFlutterWindowCls::locale() {
    return platformDispatcher->locale;
}

List<Locale> SingletonFlutterWindowCls::locales() {
    return platformDispatcher->locales;
}

Locale SingletonFlutterWindowCls::computePlatformResolvedLocale(List<Locale> supportedLocales) {
    return platformDispatcher->computePlatformResolvedLocale(supportedLocales);
}

VoidCallback SingletonFlutterWindowCls::onLocaleChanged() {
    return platformDispatcher->onLocaleChanged;
}

void SingletonFlutterWindowCls::onLocaleChanged(VoidCallback callback) {
    platformDispatcher->onLocaleChanged = callback;
}

String SingletonFlutterWindowCls::initialLifecycleState() {
    return platformDispatcher->initialLifecycleState;
}

double SingletonFlutterWindowCls::textScaleFactor() {
    return platformDispatcher->textScaleFactor;
}

bool SingletonFlutterWindowCls::nativeSpellCheckServiceDefined() {
    return platformDispatcher->nativeSpellCheckServiceDefined;
}

bool SingletonFlutterWindowCls::brieflyShowPassword() {
    return platformDispatcher->brieflyShowPassword;
}

bool SingletonFlutterWindowCls::alwaysUse24HourFormat() {
    return platformDispatcher->alwaysUse24HourFormat;
}

VoidCallback SingletonFlutterWindowCls::onTextScaleFactorChanged() {
    return platformDispatcher->onTextScaleFactorChanged;
}

void SingletonFlutterWindowCls::onTextScaleFactorChanged(VoidCallback callback) {
    platformDispatcher->onTextScaleFactorChanged = callback;
}

Brightness SingletonFlutterWindowCls::platformBrightness() {
    return platformDispatcher->platformBrightness;
}

VoidCallback SingletonFlutterWindowCls::onPlatformBrightnessChanged() {
    return platformDispatcher->onPlatformBrightnessChanged;
}

void SingletonFlutterWindowCls::onPlatformBrightnessChanged(VoidCallback callback) {
    platformDispatcher->onPlatformBrightnessChanged = callback;
}

String SingletonFlutterWindowCls::systemFontFamily() {
    return platformDispatcher->systemFontFamily;
}

VoidCallback SingletonFlutterWindowCls::onSystemFontFamilyChanged() {
    return platformDispatcher->onSystemFontFamilyChanged;
}

void SingletonFlutterWindowCls::onSystemFontFamilyChanged(VoidCallback callback) {
    platformDispatcher->onSystemFontFamilyChanged = callback;
}

FrameCallback SingletonFlutterWindowCls::onBeginFrame() {
    return platformDispatcher->onBeginFrame;
}

void SingletonFlutterWindowCls::onBeginFrame(FrameCallback callback) {
    platformDispatcher->onBeginFrame = callback;
}

VoidCallback SingletonFlutterWindowCls::onDrawFrame() {
    return platformDispatcher->onDrawFrame;
}

void SingletonFlutterWindowCls::onDrawFrame(VoidCallback callback) {
    platformDispatcher->onDrawFrame = callback;
}

TimingsCallback SingletonFlutterWindowCls::onReportTimings() {
    return platformDispatcher->onReportTimings;
}

void SingletonFlutterWindowCls::onReportTimings(TimingsCallback callback) {
    platformDispatcher->onReportTimings = callback;
}

PointerDataPacketCallback SingletonFlutterWindowCls::onPointerDataPacket() {
    return platformDispatcher->onPointerDataPacket;
}

void SingletonFlutterWindowCls::onPointerDataPacket(PointerDataPacketCallback callback) {
    platformDispatcher->onPointerDataPacket = callback;
}

KeyDataCallback SingletonFlutterWindowCls::onKeyData() {
    return platformDispatcher->onKeyData;
}

void SingletonFlutterWindowCls::onKeyData(KeyDataCallback callback) {
    platformDispatcher->onKeyData = callback;
}

String SingletonFlutterWindowCls::defaultRouteName() {
    return platformDispatcher->defaultRouteName;
}

void SingletonFlutterWindowCls::scheduleFrame() {
    return platformDispatcher->scheduleFrame();
}

bool SingletonFlutterWindowCls::semanticsEnabled() {
    return platformDispatcher->semanticsEnabled;
}

VoidCallback SingletonFlutterWindowCls::onSemanticsEnabledChanged() {
    return platformDispatcher->onSemanticsEnabledChanged;
}

void SingletonFlutterWindowCls::onSemanticsEnabledChanged(VoidCallback callback) {
    platformDispatcher->onSemanticsEnabledChanged = callback;
}

FrameData SingletonFlutterWindowCls::frameData() {
    return platformDispatcher->frameData;
}

VoidCallback SingletonFlutterWindowCls::onFrameDataChanged() {
    return platformDispatcher->onFrameDataChanged;
}

void SingletonFlutterWindowCls::onFrameDataChanged(VoidCallback callback) {
    platformDispatcher->onFrameDataChanged = callback;
}

SemanticsActionCallback SingletonFlutterWindowCls::onSemanticsAction() {
    return platformDispatcher->onSemanticsAction;
}

void SingletonFlutterWindowCls::onSemanticsAction(SemanticsActionCallback callback) {
    platformDispatcher->onSemanticsAction = callback;
}

AccessibilityFeatures SingletonFlutterWindowCls::accessibilityFeatures() {
    return platformDispatcher->accessibilityFeatures;
}

VoidCallback SingletonFlutterWindowCls::onAccessibilityFeaturesChanged() {
    return platformDispatcher->onAccessibilityFeaturesChanged;
}

void SingletonFlutterWindowCls::onAccessibilityFeaturesChanged(VoidCallback callback) {
    platformDispatcher->onAccessibilityFeaturesChanged = callback;
}

void SingletonFlutterWindowCls::updateSemantics(SemanticsUpdate update) {
    return platformDispatcher->updateSemantics(update);
}

void SingletonFlutterWindowCls::sendPlatformMessage(String name, ByteData data, PlatformMessageResponseCallback callback) {
    platformDispatcher->sendPlatformMessage(name, data, callback);
}

PlatformMessageCallback SingletonFlutterWindowCls::onPlatformMessage() {
    return platformDispatcher->onPlatformMessage;
}

void SingletonFlutterWindowCls::onPlatformMessage(PlatformMessageCallback callback) {
    platformDispatcher->onPlatformMessage = callback;
}

void SingletonFlutterWindowCls::setIsolateDebugName(String name) {
    return PlatformDispatcherCls::instance->setIsolateDebugName(name);
}

void SingletonFlutterWindowCls::_(Object windowId, PlatformDispatcher platformDispatcher)

bool AccessibilityFeaturesCls::accessibleNavigation() {
    return _kAccessibleNavigationIndex & _index != 0;
}

bool AccessibilityFeaturesCls::invertColors() {
    return _kInvertColorsIndex & _index != 0;
}

bool AccessibilityFeaturesCls::disableAnimations() {
    return _kDisableAnimationsIndex & _index != 0;
}

bool AccessibilityFeaturesCls::boldText() {
    return _kBoldTextIndex & _index != 0;
}

bool AccessibilityFeaturesCls::reduceMotion() {
    return _kReduceMotionIndex & _index != 0;
}

bool AccessibilityFeaturesCls::highContrast() {
    return _kHighContrastIndex & _index != 0;
}

bool AccessibilityFeaturesCls::onOffSwitchLabels() {
    return _kOnOffSwitchLabelsIndex & _index != 0;
}

String AccessibilityFeaturesCls::toString() {
    List<String> features = makeList();
    if (accessibleNavigation()) {
        features->add(__s("accessibleNavigation"));
    }
    if (invertColors()) {
        features->add(__s("invertColors"));
    }
    if (disableAnimations()) {
        features->add(__s("disableAnimations"));
    }
    if (boldText()) {
        features->add(__s("boldText"));
    }
    if (reduceMotion()) {
        features->add(__s("reduceMotion"));
    }
    if (highContrast()) {
        features->add(__s("highContrast"));
    }
    if (onOffSwitchLabels()) {
        features->add(__s("onOffSwitchLabels"));
    }
    return __s("AccessibilityFeatures$features");
}

bool AccessibilityFeaturesCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<AccessibilityFeatures>(other) && other->_index == _index;
}

int AccessibilityFeaturesCls::hashCode() {
    return _index->hashCode;
}

GestureSettings GestureSettingsCls::copyWith(double physicalDoubleTapSlop, double physicalTouchSlop) {
    return make<GestureSettingsCls>(physicalTouchSlop | this->physicalTouchSlop, physicalDoubleTapSlop | this->physicalDoubleTapSlop);
}

bool GestureSettingsCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<GestureSettings>(other) && other->physicalTouchSlop == physicalTouchSlop && other->physicalDoubleTapSlop == physicalDoubleTapSlop;
}

int GestureSettingsCls::hashCode() {
    return ObjectCls->hash(physicalTouchSlop, physicalDoubleTapSlop);
}

String GestureSettingsCls::toString() {
    return __s("GestureSettings(physicalTouchSlop: $physicalTouchSlop, physicalDoubleTapSlop: $physicalDoubleTapSlop)");
}
