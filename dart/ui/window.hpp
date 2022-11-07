#ifndef WINDOW_H
#define WINDOW_H
#include <memory>




class FlutterView {
public:

    PlatformDispatcher platformDispatcher();

    ViewConfiguration viewConfiguration();

    double devicePixelRatio();

    Rect physicalGeometry();

    Size physicalSize();

    WindowPadding viewInsets();

    WindowPadding viewPadding();

    WindowPadding systemGestureInsets();

    WindowPadding padding();

    List<DisplayFeature> displayFeatures();

    void render(Scene scene);

private:

    void _render(Scene scene, FlutterView view);

};

class FlutterWindow : FlutterView {
public:
    PlatformDispatcher platformDispatcher;


    ViewConfiguration viewConfiguration();

private:
    Object _windowId;


    void  _(Object _windowId, PlatformDispatcher platformDispatcher);

};

class SingletonFlutterWindow : FlutterWindow {
public:

    VoidCallback onMetricsChanged();

    void  onMetricsChanged(VoidCallback callback);

    Locale locale();

    List<Locale> locales();

    Locale computePlatformResolvedLocale(List<Locale> supportedLocales);

    VoidCallback onLocaleChanged();

    void  onLocaleChanged(VoidCallback callback);

    String initialLifecycleState();

    double textScaleFactor();

    bool nativeSpellCheckServiceDefined();

    bool brieflyShowPassword();

    bool alwaysUse24HourFormat();

    VoidCallback onTextScaleFactorChanged();

    void  onTextScaleFactorChanged(VoidCallback callback);

    Brightness platformBrightness();

    VoidCallback onPlatformBrightnessChanged();

    void  onPlatformBrightnessChanged(VoidCallback callback);

    String systemFontFamily();

    VoidCallback onSystemFontFamilyChanged();

    void  onSystemFontFamilyChanged(VoidCallback callback);

    FrameCallback onBeginFrame();

    void  onBeginFrame(FrameCallback callback);

    VoidCallback onDrawFrame();

    void  onDrawFrame(VoidCallback callback);

    TimingsCallback onReportTimings();

    void  onReportTimings(TimingsCallback callback);

    PointerDataPacketCallback onPointerDataPacket();

    void  onPointerDataPacket(PointerDataPacketCallback callback);

    KeyDataCallback onKeyData();

    void  onKeyData(KeyDataCallback callback);

    String defaultRouteName();

    void scheduleFrame();

    bool semanticsEnabled();

    VoidCallback onSemanticsEnabledChanged();

    void  onSemanticsEnabledChanged(VoidCallback callback);

    FrameData frameData();

    VoidCallback onFrameDataChanged();

    void  onFrameDataChanged(VoidCallback callback);

    SemanticsActionCallback onSemanticsAction();

    void  onSemanticsAction(SemanticsActionCallback callback);

    AccessibilityFeatures accessibilityFeatures();

    VoidCallback onAccessibilityFeaturesChanged();

    void  onAccessibilityFeaturesChanged(VoidCallback callback);

    void updateSemantics(SemanticsUpdate update);

    void sendPlatformMessage(PlatformMessageResponseCallback callback, ByteData data, String name);

    PlatformMessageCallback onPlatformMessage();

    void  onPlatformMessage(PlatformMessageCallback callback);

    void setIsolateDebugName(String name);

private:

    void  _(PlatformDispatcher platformDispatcher, Object windowId);

};

class AccessibilityFeatures {
public:

    bool accessibleNavigation();

    bool invertColors();

    bool disableAnimations();

    bool boldText();

    bool reduceMotion();

    bool highContrast();

    bool onOffSwitchLabels();

    String toString();

    bool ==(Object other);

    int hashCode();

private:
    static const int _kAccessibleNavigationIndex;

    static const int _kInvertColorsIndex;

    static const int _kDisableAnimationsIndex;

    static const int _kBoldTextIndex;

    static const int _kReduceMotionIndex;

    static const int _kHighContrastIndex;

    static const int _kOnOffSwitchLabelsIndex;

    int _index;


    void  _(int _index);

};

enum Brightness{
    dark,
    light,
} // end Brightness
SingletonFlutterWindow window;


class FrameData {
public:
    int frameNumber;


private:

    void  _(int frameNumber);

};

class GestureSettings {
public:
    double physicalTouchSlop;

    double physicalDoubleTapSlop;


     GestureSettings(double physicalDoubleTapSlop, double physicalTouchSlop);

    GestureSettings copyWith(double physicalDoubleTapSlop, double physicalTouchSlop);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

#endif