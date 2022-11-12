#ifndef DART_UI_PLATFORM_DISPATCHER
#define DART_UI_PLATFORM_DISPATCHER
#include <base.hpp>

#include <dart/core/core.hpp>

double _kUnsetGestureSetting;

String _kFlutterKeyDataChannel;


class PlatformDispatcherCls : public ObjectCls {
public:

    static PlatformDispatcher instance();

    virtual PlatformConfiguration configuration();

    virtual VoidCallback onPlatformConfigurationChanged();

    virtual void  onPlatformConfigurationChanged(VoidCallback callback);

    virtual Iterable<FlutterView> views();

    virtual VoidCallback onMetricsChanged();

    virtual void  onMetricsChanged(VoidCallback callback);

    virtual FrameCallback onBeginFrame();

    virtual void  onBeginFrame(FrameCallback callback);

    virtual VoidCallback onDrawFrame();

    virtual void  onDrawFrame(VoidCallback callback);

    virtual PointerDataPacketCallback onPointerDataPacket();

    virtual void  onPointerDataPacket(PointerDataPacketCallback callback);

    virtual KeyDataCallback onKeyData();

    virtual void  onKeyData(KeyDataCallback callback);

    virtual TimingsCallback onReportTimings();

    virtual void  onReportTimings(TimingsCallback callback);

    virtual void sendPlatformMessage(String name, ByteData data, PlatformMessageResponseCallback callback);

    virtual PlatformMessageCallback onPlatformMessage();

    virtual void  onPlatformMessage(PlatformMessageCallback callback);

    virtual void setIsolateDebugName(String name);
    virtual ByteData getPersistentIsolateData();
    virtual void scheduleFrame();
    virtual AccessibilityFeatures accessibilityFeatures();

    virtual VoidCallback onAccessibilityFeaturesChanged();

    virtual void  onAccessibilityFeaturesChanged(VoidCallback callback);

    virtual void updateSemantics(SemanticsUpdate update);
    virtual Locale locale();

    virtual List<Locale> locales();

    virtual Locale computePlatformResolvedLocale(List<Locale> supportedLocales);

    virtual VoidCallback onLocaleChanged();

    virtual void  onLocaleChanged(VoidCallback callback);

    virtual String initialLifecycleState();

    virtual bool alwaysUse24HourFormat();

    virtual double textScaleFactor();

    virtual VoidCallback onTextScaleFactorChanged();

    virtual void  onTextScaleFactorChanged(VoidCallback callback);

    virtual bool nativeSpellCheckServiceDefined();

    virtual bool brieflyShowPassword();

    virtual Brightness platformBrightness();

    virtual VoidCallback onPlatformBrightnessChanged();

    virtual void  onPlatformBrightnessChanged(VoidCallback callback);

    virtual String systemFontFamily();

    virtual VoidCallback onSystemFontFamilyChanged();

    virtual void  onSystemFontFamilyChanged(VoidCallback callback);

    virtual bool semanticsEnabled();

    virtual VoidCallback onSemanticsEnabledChanged();

    virtual void  onSemanticsEnabledChanged(VoidCallback callback);

    virtual SemanticsActionCallback onSemanticsAction();

    virtual void  onSemanticsAction(SemanticsActionCallback callback);

    virtual FrameData frameData();

    virtual VoidCallback onFrameDataChanged();

    virtual void  onFrameDataChanged(VoidCallback callback);

    virtual ErrorCallback onError();

    virtual void  onError(ErrorCallback callback);

    virtual String defaultRouteName();

private:
    static PlatformDispatcher _instance;

    PlatformConfiguration _configuration;

    VoidCallback _onPlatformConfigurationChanged;

    Zone _onPlatformConfigurationChangedZone;

    Map<Object, FlutterView> _views;

    Map<Object, ViewConfiguration> _viewConfigurations;

    VoidCallback _onMetricsChanged;

    Zone _onMetricsChangedZone;

    FrameCallback _onBeginFrame;

    Zone _onBeginFrameZone;

    VoidCallback _onDrawFrame;

    Zone _onDrawFrameZone;

    PointerDataPacketCallback _onPointerDataPacket;

    Zone _onPointerDataPacketZone;

    static int _kPointerDataFieldCount;

    KeyDataCallback _onKeyData;

    static int _kKeyDataFieldCount;

    TimingsCallback _onReportTimings;

    Zone _onReportTimingsZone;

    _SetNeedsReportTimingsFunc _setNeedsReportTimings;

    PlatformMessageCallback _onPlatformMessage;

    Zone _onPlatformMessageZone;

    VoidCallback _onAccessibilityFeaturesChanged;

    Zone _onAccessibilityFeaturesChangedZone;

    VoidCallback _onLocaleChanged;

    Zone _onLocaleChangedZone;

    String _initialLifecycleState;

    bool _initialLifecycleStateAccessed;

    VoidCallback _onTextScaleFactorChanged;

    Zone _onTextScaleFactorChangedZone;

    bool _nativeSpellCheckServiceDefined;

    bool _brieflyShowPassword;

    VoidCallback _onPlatformBrightnessChanged;

    Zone _onPlatformBrightnessChangedZone;

    VoidCallback _onSystemFontFamilyChanged;

    Zone _onSystemFontFamilyChangedZone;

    VoidCallback _onSemanticsEnabledChanged;

    Zone _onSemanticsEnabledChangedZone;

    SemanticsActionCallback _onSemanticsAction;

    Zone _onSemanticsActionZone;

    FrameData _frameData;

    VoidCallback _onFrameDataChanged;

    Zone _onFrameDataChangedZone;

    ErrorCallback _onError;

    Zone _onErrorZone;


    virtual void  _();

    virtual void _updateWindowMetrics(Object id, double devicePixelRatio, double width, double height, double viewPaddingTop, double viewPaddingRight, double viewPaddingBottom, double viewPaddingLeft, double viewInsetTop, double viewInsetRight, double viewInsetBottom, double viewInsetLeft, double systemGestureInsetTop, double systemGestureInsetRight, double systemGestureInsetBottom, double systemGestureInsetLeft, double physicalTouchSlop, List<double> displayFeaturesBounds, List<int> displayFeaturesType, List<int> displayFeaturesState);

    virtual List<DisplayFeature> _decodeDisplayFeatures(List<double> bounds, double devicePixelRatio, List<int> state, List<int> type);

    virtual void _beginFrame(int microseconds);

    virtual void _drawFrame();

    virtual void _dispatchPointerDataPacket(ByteData packet);

    static PointerDataPacket _unpackPointerDataPacket(ByteData packet);

    static ChannelCallback _keyDataListener(KeyDataCallback onKeyData, Zone zone);

    static KeyData _unpackKeyData(ByteData packet);

    virtual void _nativeSetNeedsReportTimings(bool value);
    virtual void _reportTimings(List<int> timings);

    virtual String _sendPlatformMessage(String name, PlatformMessageResponseCallback callback, ByteData data);
    virtual void _respondToPlatformMessage(int responseId, ByteData data);
    static PlatformMessageResponseCallback _zonedPlatformMessageResponseCallback(PlatformMessageResponseCallback callback);

    virtual void _dispatchPlatformMessage(String name, ByteData data, int responseId);

    virtual void _updateAccessibilityFeatures(int values);

    virtual List<String> _computePlatformResolvedLocale(List<String> supportedLocalesData);
    virtual void _updateLocales(List<String> locales);

    virtual String _localeClosure();

    virtual void _updateLifecycleState(String state);

    virtual void _updateUserSettingsData(String jsonData);

    virtual void _updateSemanticsEnabled(bool enabled);

    virtual void _updateFrameData(int frameNumber);

    virtual void _dispatchSemanticsAction(int id, int action, ByteData args);

    virtual bool _dispatchError(Object error, StackTrace stackTrace);

    virtual String _defaultRouteName();
};
using PlatformDispatcher = std::shared_ptr<PlatformDispatcherCls>;

class PlatformConfigurationCls : public ObjectCls {
public:
    AccessibilityFeatures accessibilityFeatures;

    bool alwaysUse24HourFormat;

    bool semanticsEnabled;

    Brightness platformBrightness;

    double textScaleFactor;

    List<Locale> locales;

    String defaultRouteName;

    String systemFontFamily;


     PlatformConfigurationCls(AccessibilityFeatures accessibilityFeatures, bool alwaysUse24HourFormat, String defaultRouteName, List<Locale> locales, Brightness platformBrightness, bool semanticsEnabled, String systemFontFamily, double textScaleFactor);
    virtual PlatformConfiguration copyWith(AccessibilityFeatures accessibilityFeatures, bool alwaysUse24HourFormat, String defaultRouteName, List<Locale> locales, Brightness platformBrightness, bool semanticsEnabled, String systemFontFamily, double textScaleFactor);

private:

};
using PlatformConfiguration = std::shared_ptr<PlatformConfigurationCls>;

class ViewConfigurationCls : public ObjectCls {
public:
    FlutterView window;

    double devicePixelRatio;

    Rect geometry;

    bool visible;

    WindowPadding viewInsets;

    WindowPadding viewPadding;

    WindowPadding systemGestureInsets;

    WindowPadding padding;

    GestureSettings gestureSettings;

    List<DisplayFeature> displayFeatures;


     ViewConfigurationCls(double devicePixelRatio, List<DisplayFeature> displayFeatures, Rect geometry, GestureSettings gestureSettings, WindowPadding padding, WindowPadding systemGestureInsets, WindowPadding viewInsets, WindowPadding viewPadding, bool visible, FlutterView window);
    virtual ViewConfiguration copyWith(double devicePixelRatio, List<DisplayFeature> displayFeatures, Rect geometry, GestureSettings gestureSettings, WindowPadding padding, WindowPadding systemGestureInsets, WindowPadding viewInsets, WindowPadding viewPadding, bool visible, FlutterView window);

    virtual String toString();

private:

};
using ViewConfiguration = std::shared_ptr<ViewConfigurationCls>;

enum FramePhase{
    vsyncStart,
    buildStart,
    buildFinish,
    rasterStart,
    rasterFinish,
    rasterFinishWallTime,
} // end FramePhase

enum _FrameTimingInfo{
    layerCacheCount,
    layerCacheBytes,
    pictureCacheCount,
    pictureCacheBytes,
    frameNumber,
} // end _FrameTimingInfo

class FrameTimingCls : public ObjectCls {
public:

     FrameTimingCls(int buildFinish, int buildStart, int frameNumber, int layerCacheBytes, int layerCacheCount, int pictureCacheBytes, int pictureCacheCount, int rasterFinish, int rasterFinishWallTime, int rasterStart, int vsyncStart);

    virtual int timestampInMicroseconds(FramePhase phase);

    virtual Duration buildDuration();

    virtual Duration rasterDuration();

    virtual Duration vsyncOverhead();

    virtual Duration totalSpan();

    virtual int layerCacheCount();

    virtual int layerCacheBytes();

    virtual double layerCacheMegabytes();

    virtual int pictureCacheCount();

    virtual int pictureCacheBytes();

    virtual double pictureCacheMegabytes();

    virtual int frameNumber();

    virtual String toString();

private:
    static int _dataLength;

    List<int> _data;


    virtual void  _(List<int> _data);

    virtual Duration _rawDuration(FramePhase phase);

    virtual int _rawInfo(_FrameTimingInfo info);

    virtual String _formatMS(Duration duration);

};
using FrameTiming = std::shared_ptr<FrameTimingCls>;

enum AppLifecycleState{
    resumed,
    inactive,
    paused,
    detached,
} // end AppLifecycleState

class WindowPaddingCls : public ObjectCls {
public:
    double left;

    double top;

    double right;

    double bottom;

    static WindowPadding zero;


    virtual String toString();

private:

    virtual void  _(double bottom, double left, double right, double top);
};
using WindowPadding = std::shared_ptr<WindowPaddingCls>;

class DisplayFeatureCls : public ObjectCls {
public:
    Rect bounds;

    DisplayFeatureType type;

    DisplayFeatureState state;


     DisplayFeatureCls(Rect bounds, DisplayFeatureState state, DisplayFeatureType type);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using DisplayFeature = std::shared_ptr<DisplayFeatureCls>;

enum DisplayFeatureType{
    unknown,
    fold,
    hinge,
    cutout,
} // end DisplayFeatureType

enum DisplayFeatureState{
    unknown,
    postureFlat,
    postureHalfOpened,
} // end DisplayFeatureState

class LocaleCls : public ObjectCls {
public:
    String scriptCode;


     LocaleCls(String _languageCode, String _countryCode);

    virtual void  fromSubtags(String countryCode, String languageCode, String scriptCode);

    virtual String languageCode();

    virtual String countryCode();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

    virtual String toLanguageTag();

private:
    String _languageCode;

    static Map<String, String> _deprecatedLanguageSubtagMap;

    String _countryCode;

    static Map<String, String> _deprecatedRegionSubtagMap;

    static Locale _cachedLocale;

    static String _cachedLocaleString;


    virtual String _rawToString(String separator);

};
using Locale = std::shared_ptr<LocaleCls>;


#endif