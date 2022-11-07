#include "window.hpp"
double FlutterView::devicePixelRatio() {
    return viewConfiguration.devicePixelRatio;
}

Rect FlutterView::physicalGeometry() {
    return viewConfiguration.geometry;
}

Size FlutterView::physicalSize() {
    return viewConfiguration.geometry.size;
}

WindowPadding FlutterView::viewInsets() {
    return viewConfiguration.viewInsets;
}

WindowPadding FlutterView::viewPadding() {
    return viewConfiguration.viewPadding;
}

WindowPadding FlutterView::systemGestureInsets() {
    return viewConfiguration.systemGestureInsets;
}

WindowPadding FlutterView::padding() {
    return viewConfiguration.padding;
}

List<DisplayFeature> FlutterView::displayFeatures() {
    return viewConfiguration.displayFeatures;
}

void FlutterView::render(Scene scene) {
    return _render(scene, this);
}

ViewConfiguration FlutterWindow::viewConfiguration() {
    assert(platformDispatcher._viewConfigurations.containsKey(_windowId));
    return platformDispatcher._viewConfigurations[_windowId]!;
}

VoidCallback SingletonFlutterWindow::onMetricsChanged() {
    return platformDispatcher.onMetricsChanged;
}

void SingletonFlutterWindow::onMetricsChanged(VoidCallback callback) {
    platformDispatcher.onMetricsChanged = callback;
}

Locale SingletonFlutterWindow::locale() {
    return platformDispatcher.locale;
}

List<Locale> SingletonFlutterWindow::locales() {
    return platformDispatcher.locales;
}

Locale SingletonFlutterWindow::computePlatformResolvedLocale(List<Locale> supportedLocales) {
    return platformDispatcher.computePlatformResolvedLocale(supportedLocales);
}

VoidCallback SingletonFlutterWindow::onLocaleChanged() {
    return platformDispatcher.onLocaleChanged;
}

void SingletonFlutterWindow::onLocaleChanged(VoidCallback callback) {
    platformDispatcher.onLocaleChanged = callback;
}

String SingletonFlutterWindow::initialLifecycleState() {
    return platformDispatcher.initialLifecycleState;
}

double SingletonFlutterWindow::textScaleFactor() {
    return platformDispatcher.textScaleFactor;
}

bool SingletonFlutterWindow::nativeSpellCheckServiceDefined() {
    return platformDispatcher.nativeSpellCheckServiceDefined;
}

bool SingletonFlutterWindow::brieflyShowPassword() {
    return platformDispatcher.brieflyShowPassword;
}

bool SingletonFlutterWindow::alwaysUse24HourFormat() {
    return platformDispatcher.alwaysUse24HourFormat;
}

VoidCallback SingletonFlutterWindow::onTextScaleFactorChanged() {
    return platformDispatcher.onTextScaleFactorChanged;
}

void SingletonFlutterWindow::onTextScaleFactorChanged(VoidCallback callback) {
    platformDispatcher.onTextScaleFactorChanged = callback;
}

Brightness SingletonFlutterWindow::platformBrightness() {
    return platformDispatcher.platformBrightness;
}

VoidCallback SingletonFlutterWindow::onPlatformBrightnessChanged() {
    return platformDispatcher.onPlatformBrightnessChanged;
}

void SingletonFlutterWindow::onPlatformBrightnessChanged(VoidCallback callback) {
    platformDispatcher.onPlatformBrightnessChanged = callback;
}

String SingletonFlutterWindow::systemFontFamily() {
    return platformDispatcher.systemFontFamily;
}

VoidCallback SingletonFlutterWindow::onSystemFontFamilyChanged() {
    return platformDispatcher.onSystemFontFamilyChanged;
}

void SingletonFlutterWindow::onSystemFontFamilyChanged(VoidCallback callback) {
    platformDispatcher.onSystemFontFamilyChanged = callback;
}

FrameCallback SingletonFlutterWindow::onBeginFrame() {
    return platformDispatcher.onBeginFrame;
}

void SingletonFlutterWindow::onBeginFrame(FrameCallback callback) {
    platformDispatcher.onBeginFrame = callback;
}

VoidCallback SingletonFlutterWindow::onDrawFrame() {
    return platformDispatcher.onDrawFrame;
}

void SingletonFlutterWindow::onDrawFrame(VoidCallback callback) {
    platformDispatcher.onDrawFrame = callback;
}

TimingsCallback SingletonFlutterWindow::onReportTimings() {
    return platformDispatcher.onReportTimings;
}

void SingletonFlutterWindow::onReportTimings(TimingsCallback callback) {
    platformDispatcher.onReportTimings = callback;
}

PointerDataPacketCallback SingletonFlutterWindow::onPointerDataPacket() {
    return platformDispatcher.onPointerDataPacket;
}

void SingletonFlutterWindow::onPointerDataPacket(PointerDataPacketCallback callback) {
    platformDispatcher.onPointerDataPacket = callback;
}

KeyDataCallback SingletonFlutterWindow::onKeyData() {
    return platformDispatcher.onKeyData;
}

void SingletonFlutterWindow::onKeyData(KeyDataCallback callback) {
    platformDispatcher.onKeyData = callback;
}

String SingletonFlutterWindow::defaultRouteName() {
    return platformDispatcher.defaultRouteName;
}

void SingletonFlutterWindow::scheduleFrame() {
    return platformDispatcher.scheduleFrame();
}

bool SingletonFlutterWindow::semanticsEnabled() {
    return platformDispatcher.semanticsEnabled;
}

VoidCallback SingletonFlutterWindow::onSemanticsEnabledChanged() {
    return platformDispatcher.onSemanticsEnabledChanged;
}

void SingletonFlutterWindow::onSemanticsEnabledChanged(VoidCallback callback) {
    platformDispatcher.onSemanticsEnabledChanged = callback;
}

FrameData SingletonFlutterWindow::frameData() {
    return platformDispatcher.frameData;
}

VoidCallback SingletonFlutterWindow::onFrameDataChanged() {
    return platformDispatcher.onFrameDataChanged;
}

void SingletonFlutterWindow::onFrameDataChanged(VoidCallback callback) {
    platformDispatcher.onFrameDataChanged = callback;
}

SemanticsActionCallback SingletonFlutterWindow::onSemanticsAction() {
    return platformDispatcher.onSemanticsAction;
}

void SingletonFlutterWindow::onSemanticsAction(SemanticsActionCallback callback) {
    platformDispatcher.onSemanticsAction = callback;
}

AccessibilityFeatures SingletonFlutterWindow::accessibilityFeatures() {
    return platformDispatcher.accessibilityFeatures;
}

VoidCallback SingletonFlutterWindow::onAccessibilityFeaturesChanged() {
    return platformDispatcher.onAccessibilityFeaturesChanged;
}

void SingletonFlutterWindow::onAccessibilityFeaturesChanged(VoidCallback callback) {
    platformDispatcher.onAccessibilityFeaturesChanged = callback;
}

void SingletonFlutterWindow::updateSemantics(SemanticsUpdate update) {
    return platformDispatcher.updateSemantics(update);
}

void SingletonFlutterWindow::sendPlatformMessage(PlatformMessageResponseCallback callback, ByteData data, String name) {
    platformDispatcher.sendPlatformMessage(name, data, callback);
}

PlatformMessageCallback SingletonFlutterWindow::onPlatformMessage() {
    return platformDispatcher.onPlatformMessage;
}

void SingletonFlutterWindow::onPlatformMessage(PlatformMessageCallback callback) {
    platformDispatcher.onPlatformMessage = callback;
}

void SingletonFlutterWindow::setIsolateDebugName(String name) {
    return PlatformDispatcher.instance.setIsolateDebugName(name);
}

void SingletonFlutterWindow::_(PlatformDispatcher platformDispatcher, Object windowId)

bool AccessibilityFeatures::accessibleNavigation() {
    return _kAccessibleNavigationIndex & _index != 0;
}

bool AccessibilityFeatures::invertColors() {
    return _kInvertColorsIndex & _index != 0;
}

bool AccessibilityFeatures::disableAnimations() {
    return _kDisableAnimationsIndex & _index != 0;
}

bool AccessibilityFeatures::boldText() {
    return _kBoldTextIndex & _index != 0;
}

bool AccessibilityFeatures::reduceMotion() {
    return _kReduceMotionIndex & _index != 0;
}

bool AccessibilityFeatures::highContrast() {
    return _kHighContrastIndex & _index != 0;
}

bool AccessibilityFeatures::onOffSwitchLabels() {
    return _kOnOffSwitchLabelsIndex & _index != 0;
}

String AccessibilityFeatures::toString() {
    List<String> features = ;
    if (accessibleNavigation)     {
        features.add("accessibleNavigation");
    }
    if (invertColors)     {
        features.add("invertColors");
    }
    if (disableAnimations)     {
        features.add("disableAnimations");
    }
    if (boldText)     {
        features.add("boldText");
    }
    if (reduceMotion)     {
        features.add("reduceMotion");
    }
    if (highContrast)     {
        features.add("highContrast");
    }
    if (onOffSwitchLabels)     {
        features.add("onOffSwitchLabels");
    }
    return "AccessibilityFeatures$features";
}

bool AccessibilityFeatures::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is AccessibilityFeatures && other._index == _index;
}

int AccessibilityFeatures::hashCode() {
    return _index.hashCode;
}

GestureSettings GestureSettings::copyWith(double physicalDoubleTapSlop, double physicalTouchSlop) {
    return GestureSettings(physicalTouchSlop ?? this.physicalTouchSlop, physicalDoubleTapSlop ?? this.physicalDoubleTapSlop);
}

bool GestureSettings::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is GestureSettings && other.physicalTouchSlop == physicalTouchSlop && other.physicalDoubleTapSlop == physicalDoubleTapSlop;
}

int GestureSettings::hashCode() {
    return Object.hash(physicalTouchSlop, physicalDoubleTapSlop);
}

String GestureSettings::toString() {
    return "GestureSettings(physicalTouchSlop: $physicalTouchSlop, physicalDoubleTapSlop: $physicalDoubleTapSlop)";
}
