#ifndef DART_UI_WINDOW
#define DART_UI_WINDOW
#include <base.hpp>

#include <dart/core/core.hpp>


class FlutterViewCls : public ObjectCls {
public:

    virtual PlatformDispatcher platformDispatcher();
    virtual ViewConfiguration viewConfiguration();
    virtual double devicePixelRatio();

    virtual Rect physicalGeometry();

    virtual Size physicalSize();

    virtual WindowPadding viewInsets();

    virtual WindowPadding viewPadding();

    virtual WindowPadding systemGestureInsets();

    virtual WindowPadding padding();

    virtual List<DisplayFeature> displayFeatures();

    virtual void render(Scene scene);

private:

    virtual void _render(Scene scene, FlutterView view);
};
using FlutterView = std::shared_ptr<FlutterViewCls>;

class FlutterWindowCls : public FlutterViewCls {
public:
    PlatformDispatcher platformDispatcher;


    virtual ViewConfiguration viewConfiguration();

private:
    Object _windowId;


    virtual void  _(Object _windowId, PlatformDispatcher platformDispatcher);
};
using FlutterWindow = std::shared_ptr<FlutterWindowCls>;

class SingletonFlutterWindowCls : public FlutterWindowCls {
public:

    virtual VoidCallback onMetricsChanged();

    virtual void  onMetricsChanged(VoidCallback callback);

    virtual Locale locale();

    virtual List<Locale> locales();

    virtual Locale computePlatformResolvedLocale(List<Locale> supportedLocales);

    virtual VoidCallback onLocaleChanged();

    virtual void  onLocaleChanged(VoidCallback callback);

    virtual String initialLifecycleState();

    virtual double textScaleFactor();

    virtual bool nativeSpellCheckServiceDefined();

    virtual bool brieflyShowPassword();

    virtual bool alwaysUse24HourFormat();

    virtual VoidCallback onTextScaleFactorChanged();

    virtual void  onTextScaleFactorChanged(VoidCallback callback);

    virtual Brightness platformBrightness();

    virtual VoidCallback onPlatformBrightnessChanged();

    virtual void  onPlatformBrightnessChanged(VoidCallback callback);

    virtual String systemFontFamily();

    virtual VoidCallback onSystemFontFamilyChanged();

    virtual void  onSystemFontFamilyChanged(VoidCallback callback);

    virtual FrameCallback onBeginFrame();

    virtual void  onBeginFrame(FrameCallback callback);

    virtual VoidCallback onDrawFrame();

    virtual void  onDrawFrame(VoidCallback callback);

    virtual TimingsCallback onReportTimings();

    virtual void  onReportTimings(TimingsCallback callback);

    virtual PointerDataPacketCallback onPointerDataPacket();

    virtual void  onPointerDataPacket(PointerDataPacketCallback callback);

    virtual KeyDataCallback onKeyData();

    virtual void  onKeyData(KeyDataCallback callback);

    virtual String defaultRouteName();

    virtual void scheduleFrame();

    virtual bool semanticsEnabled();

    virtual VoidCallback onSemanticsEnabledChanged();

    virtual void  onSemanticsEnabledChanged(VoidCallback callback);

    virtual FrameData frameData();

    virtual VoidCallback onFrameDataChanged();

    virtual void  onFrameDataChanged(VoidCallback callback);

    virtual SemanticsActionCallback onSemanticsAction();

    virtual void  onSemanticsAction(SemanticsActionCallback callback);

    virtual AccessibilityFeatures accessibilityFeatures();

    virtual VoidCallback onAccessibilityFeaturesChanged();

    virtual void  onAccessibilityFeaturesChanged(VoidCallback callback);

    virtual void updateSemantics(SemanticsUpdate update);

    virtual void sendPlatformMessage(String name, ByteData data, PlatformMessageResponseCallback callback);

    virtual PlatformMessageCallback onPlatformMessage();

    virtual void  onPlatformMessage(PlatformMessageCallback callback);

    virtual void setIsolateDebugName(String name);

private:

    virtual void  _(Object windowId, PlatformDispatcher platformDispatcher);

};
using SingletonFlutterWindow = std::shared_ptr<SingletonFlutterWindowCls>;

class AccessibilityFeaturesCls : public ObjectCls {
public:

    virtual bool accessibleNavigation();

    virtual bool invertColors();

    virtual bool disableAnimations();

    virtual bool boldText();

    virtual bool reduceMotion();

    virtual bool highContrast();

    virtual bool onOffSwitchLabels();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    static int _kAccessibleNavigationIndex;

    static int _kInvertColorsIndex;

    static int _kDisableAnimationsIndex;

    static int _kBoldTextIndex;

    static int _kReduceMotionIndex;

    static int _kHighContrastIndex;

    static int _kOnOffSwitchLabelsIndex;

    int _index;


    virtual void  _(int _index);
};
using AccessibilityFeatures = std::shared_ptr<AccessibilityFeaturesCls>;

enum Brightness{
    dark,
    light,
} // end Brightness
SingletonFlutterWindow window;


class FrameDataCls : public ObjectCls {
public:
    int frameNumber;


private:

    virtual void  _(int frameNumber);
};
using FrameData = std::shared_ptr<FrameDataCls>;

class GestureSettingsCls : public ObjectCls {
public:
    double physicalTouchSlop;

    double physicalDoubleTapSlop;


     GestureSettingsCls(double physicalDoubleTapSlop, double physicalTouchSlop);
    virtual GestureSettings copyWith(double physicalDoubleTapSlop, double physicalTouchSlop);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using GestureSettings = std::shared_ptr<GestureSettingsCls>;


#endif