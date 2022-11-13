#include "platform_dispatcher.hpp"
PlatformDispatcher PlatformDispatcherCls::instance() {
    return _instance;
}

PlatformConfiguration PlatformDispatcherCls::configuration() {
    return _configuration;
}

VoidCallback PlatformDispatcherCls::onPlatformConfigurationChanged() {
    return _onPlatformConfigurationChanged;
}

void PlatformDispatcherCls::onPlatformConfigurationChanged(VoidCallback callback) {
    _onPlatformConfigurationChanged = callback;
    _onPlatformConfigurationChangedZone = ZoneCls::current;
}

Iterable<FlutterView> PlatformDispatcherCls::views() {
    return _views->values();
}

VoidCallback PlatformDispatcherCls::onMetricsChanged() {
    return _onMetricsChanged;
}

void PlatformDispatcherCls::onMetricsChanged(VoidCallback callback) {
    _onMetricsChanged = callback;
    _onMetricsChangedZone = ZoneCls::current;
}

FrameCallback PlatformDispatcherCls::onBeginFrame() {
    return _onBeginFrame;
}

void PlatformDispatcherCls::onBeginFrame(FrameCallback callback) {
    _onBeginFrame = callback;
    _onBeginFrameZone = ZoneCls::current;
}

VoidCallback PlatformDispatcherCls::onDrawFrame() {
    return _onDrawFrame;
}

void PlatformDispatcherCls::onDrawFrame(VoidCallback callback) {
    _onDrawFrame = callback;
    _onDrawFrameZone = ZoneCls::current;
}

PointerDataPacketCallback PlatformDispatcherCls::onPointerDataPacket() {
    return _onPointerDataPacket;
}

void PlatformDispatcherCls::onPointerDataPacket(PointerDataPacketCallback callback) {
    _onPointerDataPacket = callback;
    _onPointerDataPacketZone = ZoneCls::current;
}

KeyDataCallback PlatformDispatcherCls::onKeyData() {
    return _onKeyData;
}

void PlatformDispatcherCls::onKeyData(KeyDataCallback callback) {
    _onKeyData = callback;
    if (callback != nullptr) {
        channelBuffers->setListener(_kFlutterKeyDataChannel, _keyDataListener(callback, ZoneCls::current));
    } else {
        channelBuffers->clearListener(_kFlutterKeyDataChannel);
    }
}

TimingsCallback PlatformDispatcherCls::onReportTimings() {
    return _onReportTimings;
}

void PlatformDispatcherCls::onReportTimings(TimingsCallback callback) {
    if ((callback == nullptr) != (_onReportTimings == nullptr)) {
        _setNeedsReportTimings(callback != nullptr);
    }
    _onReportTimings = callback;
    _onReportTimingsZone = ZoneCls::current;
}

void PlatformDispatcherCls::sendPlatformMessage(String name, ByteData data, PlatformMessageResponseCallback callback) {
    String error = _sendPlatformMessage(name, _zonedPlatformMessageResponseCallback(callback), data);
    if (error != nullptr) {
        throw make<ExceptionCls>(error);
    }
}

PlatformMessageCallback PlatformDispatcherCls::onPlatformMessage() {
    return _onPlatformMessage;
}

void PlatformDispatcherCls::onPlatformMessage(PlatformMessageCallback callback) {
    _onPlatformMessage = callback;
    _onPlatformMessageZone = ZoneCls::current;
}

AccessibilityFeatures PlatformDispatcherCls::accessibilityFeatures() {
    return configuration()->accessibilityFeatures;
}

VoidCallback PlatformDispatcherCls::onAccessibilityFeaturesChanged() {
    return _onAccessibilityFeaturesChanged;
}

void PlatformDispatcherCls::onAccessibilityFeaturesChanged(VoidCallback callback) {
    _onAccessibilityFeaturesChanged = callback;
    _onAccessibilityFeaturesChangedZone = ZoneCls::current;
}

Locale PlatformDispatcherCls::locale() {
    return locales()->isEmpty()? LocaleCls->fromSubtags() : locales()->first;
}

List<Locale> PlatformDispatcherCls::locales() {
    return configuration()->locales;
}

Locale PlatformDispatcherCls::computePlatformResolvedLocale(List<Locale> supportedLocales) {
    List<String> supportedLocalesData = makeList();
    for (Locale locale : supportedLocales) {
        supportedLocalesData->add(locale()->languageCode());
        supportedLocalesData->add(locale()->countryCode());
        supportedLocalesData->add(locale()->scriptCode);
    }
    List<String> result = _computePlatformResolvedLocale(supportedLocalesData);
    if (result->isNotEmpty()) {
        return LocaleCls->fromSubtags(result[0], result[1] == __s("")? nullptr : result[1], result[2] == __s("")? nullptr : result[2]);
    }
    return nullptr;
}

VoidCallback PlatformDispatcherCls::onLocaleChanged() {
    return _onLocaleChanged;
}

void PlatformDispatcherCls::onLocaleChanged(VoidCallback callback) {
    _onLocaleChanged = callback;
    _onLocaleChangedZone = ZoneCls::current;
}

String PlatformDispatcherCls::initialLifecycleState() {
    _initialLifecycleStateAccessed = true;
    return _initialLifecycleState;
}

bool PlatformDispatcherCls::alwaysUse24HourFormat() {
    return configuration()->alwaysUse24HourFormat;
}

double PlatformDispatcherCls::textScaleFactor() {
    return configuration()->textScaleFactor;
}

VoidCallback PlatformDispatcherCls::onTextScaleFactorChanged() {
    return _onTextScaleFactorChanged;
}

void PlatformDispatcherCls::onTextScaleFactorChanged(VoidCallback callback) {
    _onTextScaleFactorChanged = callback;
    _onTextScaleFactorChangedZone = ZoneCls::current;
}

bool PlatformDispatcherCls::nativeSpellCheckServiceDefined() {
    return _nativeSpellCheckServiceDefined;
}

bool PlatformDispatcherCls::brieflyShowPassword() {
    return _brieflyShowPassword;
}

Brightness PlatformDispatcherCls::platformBrightness() {
    return configuration()->platformBrightness;
}

VoidCallback PlatformDispatcherCls::onPlatformBrightnessChanged() {
    return _onPlatformBrightnessChanged;
}

void PlatformDispatcherCls::onPlatformBrightnessChanged(VoidCallback callback) {
    _onPlatformBrightnessChanged = callback;
    _onPlatformBrightnessChangedZone = ZoneCls::current;
}

String PlatformDispatcherCls::systemFontFamily() {
    return configuration()->systemFontFamily;
}

VoidCallback PlatformDispatcherCls::onSystemFontFamilyChanged() {
    return _onSystemFontFamilyChanged;
}

void PlatformDispatcherCls::onSystemFontFamilyChanged(VoidCallback callback) {
    _onSystemFontFamilyChanged = callback;
    _onSystemFontFamilyChangedZone = ZoneCls::current;
}

bool PlatformDispatcherCls::semanticsEnabled() {
    return configuration()->semanticsEnabled;
}

VoidCallback PlatformDispatcherCls::onSemanticsEnabledChanged() {
    return _onSemanticsEnabledChanged;
}

void PlatformDispatcherCls::onSemanticsEnabledChanged(VoidCallback callback) {
    _onSemanticsEnabledChanged = callback;
    _onSemanticsEnabledChangedZone = ZoneCls::current;
}

SemanticsActionCallback PlatformDispatcherCls::onSemanticsAction() {
    return _onSemanticsAction;
}

void PlatformDispatcherCls::onSemanticsAction(SemanticsActionCallback callback) {
    _onSemanticsAction = callback;
    _onSemanticsActionZone = ZoneCls::current;
}

FrameData PlatformDispatcherCls::frameData() {
    return _frameData;
}

VoidCallback PlatformDispatcherCls::onFrameDataChanged() {
    return _onFrameDataChanged;
}

void PlatformDispatcherCls::onFrameDataChanged(VoidCallback callback) {
    _onFrameDataChanged = callback;
    _onFrameDataChangedZone = ZoneCls::current;
}

ErrorCallback PlatformDispatcherCls::onError() {
    return _onError;
}

void PlatformDispatcherCls::onError(ErrorCallback callback) {
    _onError = callback;
    _onErrorZone = ZoneCls::current;
}

String PlatformDispatcherCls::defaultRouteName() {
    return _defaultRouteName();
}

void PlatformDispatcherCls::_() {
    _setNeedsReportTimings = _nativeSetNeedsReportTimings;
}

void PlatformDispatcherCls::_updateWindowMetrics(Object id, double devicePixelRatio, double width, double height, double viewPaddingTop, double viewPaddingRight, double viewPaddingBottom, double viewPaddingLeft, double viewInsetTop, double viewInsetRight, double viewInsetBottom, double viewInsetLeft, double systemGestureInsetTop, double systemGestureInsetRight, double systemGestureInsetBottom, double systemGestureInsetLeft, double physicalTouchSlop, List<double> displayFeaturesBounds, List<int> displayFeaturesType, List<int> displayFeaturesState) {
    ViewConfiguration previousConfiguration = _viewConfigurations[id] | make<ViewConfigurationCls>();
    if (!_views->containsKey(id)) {
        _views[id] = FlutterWindowCls->_(id, this);
    }
    _viewConfigurations[id] = previousConfiguration->copyWith(_views[id], devicePixelRatio, RectCls->fromLTWH(0.0, 0.0, width, height), WindowPaddingCls->_(viewPaddingTop, viewPaddingRight, viewPaddingBottom, viewPaddingLeft), WindowPaddingCls->_(viewInsetTop, viewInsetRight, viewInsetBottom, viewInsetLeft), WindowPaddingCls->_(math->max(0.0, viewPaddingTop - viewInsetTop), math->max(0.0, viewPaddingRight - viewInsetRight), math->max(0.0, viewPaddingBottom - viewInsetBottom), math->max(0.0, viewPaddingLeft - viewInsetLeft)), WindowPaddingCls->_(math->max(0.0, systemGestureInsetTop), math->max(0.0, systemGestureInsetRight), math->max(0.0, systemGestureInsetBottom), math->max(0.0, systemGestureInsetLeft)), make<GestureSettingsCls>(physicalTouchSlop == _kUnsetGestureSetting? nullptr : physicalTouchSlop), _decodeDisplayFeatures(displayFeaturesBounds, displayFeaturesType, displayFeaturesState, devicePixelRatio));
    _invoke(onMetricsChanged(), _onMetricsChangedZone);
}

List<DisplayFeature> PlatformDispatcherCls::_decodeDisplayFeatures(List<double> bounds, double devicePixelRatio, List<int> state, List<int> type) {
    assert(bounds->length() / 4 == type->length(), __s("Bounds are rectangles, requiring 4 measurements each"));
    assert(type->length() == state->length());
    List<DisplayFeature> result = makeList();
    for (;  < type->length(); i++) {
        int rectOffset = i * 4;
        result->add(make<DisplayFeatureCls>(RectCls->fromLTRB(bounds[rectOffset] / devicePixelRatio, bounds[rectOffset + 1] / devicePixelRatio, bounds[rectOffset + 2] / devicePixelRatio, bounds[rectOffset + 3] / devicePixelRatio), DisplayFeatureTypeCls::values[type[i]], state[i] < DisplayFeatureStateCls::values->length? DisplayFeatureStateCls::values[state[i]] : DisplayFeatureStateCls::unknown));
    }
    return result;
}

void PlatformDispatcherCls::_beginFrame(int microseconds) {
    <Duration>_invoke1(onBeginFrame(), _onBeginFrameZone, make<DurationCls>(microseconds));
}

void PlatformDispatcherCls::_drawFrame() {
    _invoke(onDrawFrame(), _onDrawFrameZone);
}

void PlatformDispatcherCls::_dispatchPointerDataPacket(ByteData packet) {
    if (onPointerDataPacket() != nullptr) {
        <PointerDataPacket>_invoke1(onPointerDataPacket(), _onPointerDataPacketZone, _unpackPointerDataPacket(packet));
    }
}

PointerDataPacket PlatformDispatcherCls::_unpackPointerDataPacket(ByteData packet) {
    int kStride = Int64ListCls::bytesPerElement;
    int kBytesPerPointerData = _kPointerDataFieldCount * kStride;
    int length = packet->lengthInBytes() ~/ kBytesPerPointerData;
    assert(length * kBytesPerPointerData == packet->lengthInBytes());
    List<PointerData> data = makeList();
    for (;  < length; ++i) {
        int offset = i * _kPointerDataFieldCount;
        data->add(make<PointerDataCls>(packet->getInt64(kStride * offset++, _kFakeHostEndian), make<DurationCls>(packet->getInt64(kStride * offset++, _kFakeHostEndian)), PointerChangeCls::values[packet->getInt64(kStride * offset++, _kFakeHostEndian)], PointerDeviceKindCls::values[packet->getInt64(kStride * offset++, _kFakeHostEndian)], PointerSignalKindCls::values[packet->getInt64(kStride * offset++, _kFakeHostEndian)], packet->getInt64(kStride * offset++, _kFakeHostEndian), packet->getInt64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getInt64(kStride * offset++, _kFakeHostEndian), packet->getInt64(kStride * offset++, _kFakeHostEndian) != 0, packet->getInt64(kStride * offset++, _kFakeHostEndian) != 0, packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getInt64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian), packet->getFloat64(kStride * offset++, _kFakeHostEndian)));
        assert(offset == (i + 1) * _kPointerDataFieldCount);
    }
    return make<PointerDataPacketCls>(data);
}

ChannelCallback PlatformDispatcherCls::_keyDataListener(KeyDataCallback onKeyData, Zone zone) {
    return [=] (ByteData packet,PlatformMessageResponseCallback callback) {
        <KeyData>_invoke1([=] (KeyData keyData) {
            bool handled = onKeyData(keyData);
            Uint8List response = make<Uint8ListCls>(1);
            response[0] = handled? 1 : 0;
            callback(response->buffer->asByteData());
        }, zone, _unpackKeyData(packet!));
    };
}

KeyData PlatformDispatcherCls::_unpackKeyData(ByteData packet) {
    int kStride = Int64ListCls::bytesPerElement;
    int offset = 0;
    int charDataSize = packet->getUint64(kStride * offset++, _kFakeHostEndian);
    String character = charDataSize == 0? nullptr : utf8->decoder->convert(packet->buffer()->asUint8List(kStride * (offset + _kKeyDataFieldCount), charDataSize));
    KeyData keyData = make<KeyDataCls>(make<DurationCls>(packet->getUint64(kStride * offset++, _kFakeHostEndian)), KeyEventTypeCls::values[packet->getInt64(kStride * offset++, _kFakeHostEndian)], packet->getUint64(kStride * offset++, _kFakeHostEndian), packet->getUint64(kStride * offset++, _kFakeHostEndian), character, packet->getUint64(kStride * offset++, _kFakeHostEndian) != 0);
    return keyData;
}

void PlatformDispatcherCls::_reportTimings(List<int> timings) {
    assert(timings->length() % FrameTimingCls::_dataLength == 0);
    List<FrameTiming> frameTimings = makeList();
    for (;  < timings->length(); i += FrameTimingCls::_dataLength) {
        frameTimings->add(FrameTimingCls->_(timings->sublist(i, i + FrameTimingCls::_dataLength)));
    }
    _invoke1(onReportTimings(), _onReportTimingsZone, frameTimings);
}

PlatformMessageResponseCallback PlatformDispatcherCls::_zonedPlatformMessageResponseCallback(PlatformMessageResponseCallback callback) {
    if (callback == nullptr) {
        return nullptr;
    }
    Zone registrationZone = ZoneCls::current;
    return [=] (ByteData data) {
        registrationZone->runUnaryGuarded(callback, data);
    };
}

void PlatformDispatcherCls::_dispatchPlatformMessage(String name, ByteData data, int responseId) {
    if (name == ChannelBuffersCls::kControlChannelName) {
        try {
            channelBuffers->handleMessage(data!);
        } finally {
            _respondToPlatformMessage(responseId, nullptr);
        };
    } else {
        if (onPlatformMessage() != nullptr) {
        <String, ByteData, PlatformMessageResponseCallback>_invoke3(onPlatformMessage(), _onPlatformMessageZone, name, data, [=] (ByteData responseData) {
            _respondToPlatformMessage(responseId, responseData);
        });
    } else {
        channelBuffers->push(name, data, [=] (ByteData responseData) {
            _respondToPlatformMessage(responseId, responseData);
        });
    }
;
    }}

void PlatformDispatcherCls::_updateAccessibilityFeatures(int values) {
    AccessibilityFeatures newFeatures = AccessibilityFeaturesCls->_(values);
    PlatformConfiguration previousConfiguration = configuration();
    if (newFeatures == previousConfiguration->accessibilityFeatures) {
        return;
    }
    _configuration = previousConfiguration->copyWith(newFeatures);
    _invoke(onPlatformConfigurationChanged(), _onPlatformConfigurationChangedZone);
    _invoke(onAccessibilityFeaturesChanged(), _onAccessibilityFeaturesChangedZone);
}

void PlatformDispatcherCls::_updateLocales(List<String> locales) {
    int stringsPerLocale = 4;
    int numLocales = locales->length() ~/ stringsPerLocale;
    PlatformConfiguration previousConfiguration = configuration();
    List<Locale> newLocales = makeList();
    bool localesDiffer = numLocales != previousConfiguration->locales->length();
    for (;  < numLocales; localeIndex++) {
        String countryCode = locales[localeIndex * stringsPerLocale + 1];
        String scriptCode = locales[localeIndex * stringsPerLocale + 2];
        newLocales->add(LocaleCls->fromSubtags(locales[localeIndex * stringsPerLocale], countryCode->isEmpty()? nullptr : countryCode, scriptCode->isEmpty()? nullptr : scriptCode));
        if (!localesDiffer && newLocales[localeIndex] != previousConfiguration->locales[localeIndex]) {
            localesDiffer = true;
        }
    }
    if (!localesDiffer) {
        return;
    }
    _configuration = previousConfiguration->copyWith(newLocales);
    _invoke(onPlatformConfigurationChanged(), _onPlatformConfigurationChangedZone);
    _invoke(onLocaleChanged(), _onLocaleChangedZone);
}

String PlatformDispatcherCls::_localeClosure() {
    return locale()->toString();
}

void PlatformDispatcherCls::_updateLifecycleState(String state) {
    if (!_initialLifecycleStateAccessed) {
        _initialLifecycleState = state;
    }
}

void PlatformDispatcherCls::_updateUserSettingsData(String jsonData) {
    Map<String, Object> data = as<Map<String, Object>>(json->decode(jsonData));
    if (data->isEmpty()) {
        return;
    }
    double textScaleFactor = (as<num>(data[__s("textScaleFactor")]!))->toDouble();
    bool alwaysUse24HourFormat = as<bool>(data[__s("alwaysUse24HourFormat")]!);
    bool nativeSpellCheckServiceDefined = as<bool>(data[__s("nativeSpellCheckServiceDefined")]);
    if (nativeSpellCheckServiceDefined != nullptr) {
        _nativeSpellCheckServiceDefined = nativeSpellCheckServiceDefined;
    } else {
        _nativeSpellCheckServiceDefined = false;
    }
    bool brieflyShowPassword = as<bool>(data[__s("brieflyShowPassword")]);
    if (brieflyShowPassword != nullptr) {
        _brieflyShowPassword = brieflyShowPassword;
    }
    Brightness platformBrightness = as<String>(data[__s("platformBrightness")]!) == __s("dark")? BrightnessCls::dark : BrightnessCls::light;
    String systemFontFamily = as<String>(data[__s("systemFontFamily")]);
    PlatformConfiguration previousConfiguration = configuration();
    bool platformBrightnessChanged = previousConfiguration->platformBrightness != platformBrightness;
    bool textScaleFactorChanged = previousConfiguration->textScaleFactor != textScaleFactor;
    bool alwaysUse24HourFormatChanged = previousConfiguration->alwaysUse24HourFormat != alwaysUse24HourFormat;
    bool systemFontFamilyChanged = previousConfiguration->systemFontFamily != systemFontFamily;
    if (!platformBrightnessChanged && !textScaleFactorChanged && !alwaysUse24HourFormatChanged && !systemFontFamilyChanged) {
        return;
    }
    _configuration = previousConfiguration->copyWith(textScaleFactor, alwaysUse24HourFormat, platformBrightness, systemFontFamily);
    _invoke(onPlatformConfigurationChanged(), _onPlatformConfigurationChangedZone);
    if (textScaleFactorChanged) {
        _invoke(onTextScaleFactorChanged(), _onTextScaleFactorChangedZone);
    }
    if (platformBrightnessChanged) {
        _invoke(onPlatformBrightnessChanged(), _onPlatformBrightnessChangedZone);
    }
    if (systemFontFamilyChanged) {
        _invoke(onSystemFontFamilyChanged(), _onSystemFontFamilyChangedZone);
    }
}

void PlatformDispatcherCls::_updateSemanticsEnabled(bool enabled) {
    PlatformConfiguration previousConfiguration = configuration();
    if (previousConfiguration->semanticsEnabled == enabled) {
        return;
    }
    _configuration = previousConfiguration->copyWith(enabled);
    _invoke(onPlatformConfigurationChanged(), _onPlatformConfigurationChangedZone);
    _invoke(onSemanticsEnabledChanged(), _onSemanticsEnabledChangedZone);
}

void PlatformDispatcherCls::_updateFrameData(int frameNumber) {
    FrameData previous = _frameData;
    if (previous->frameNumber == frameNumber) {
        return;
    }
    _frameData = FrameDataCls->_(frameNumber);
    _invoke(onFrameDataChanged(), _onFrameDataChangedZone);
}

void PlatformDispatcherCls::_dispatchSemanticsAction(int id, int action, ByteData args) {
    <int, SemanticsAction, ByteData>_invoke3(onSemanticsAction(), _onSemanticsActionZone, id, SemanticsActionCls::values[action]!, args);
}

bool PlatformDispatcherCls::_dispatchError(Object error, StackTrace stackTrace) {
    if (_onError == nullptr) {
        return false;
    }
    assert(_onErrorZone != nullptr);
    if (identical(_onErrorZone, ZoneCls::current)) {
        return _onError!(error, stackTrace);
    } else {
        try {
            return _onErrorZone!-><bool, Object, StackTrace>runBinary(_onError!, error, stackTrace);
        } catch (Unknown e) {
            _onErrorZone!->handleUncaughtError(e, s);
            return false;
        };
    }
}

PlatformConfiguration PlatformConfigurationCls::copyWith(AccessibilityFeatures accessibilityFeatures, bool alwaysUse24HourFormat, String defaultRouteName, List<Locale> locales, Brightness platformBrightness, bool semanticsEnabled, String systemFontFamily, double textScaleFactor) {
    return make<PlatformConfigurationCls>(accessibilityFeatures | this->accessibilityFeatures, alwaysUse24HourFormat | this->alwaysUse24HourFormat, semanticsEnabled | this->semanticsEnabled, platformBrightness | this->platformBrightness, textScaleFactor | this->textScaleFactor, locales | this->locales, defaultRouteName | this->defaultRouteName, systemFontFamily | this->systemFontFamily);
}

ViewConfiguration ViewConfigurationCls::copyWith(double devicePixelRatio, List<DisplayFeature> displayFeatures, Rect geometry, GestureSettings gestureSettings, WindowPadding padding, WindowPadding systemGestureInsets, WindowPadding viewInsets, WindowPadding viewPadding, bool visible, FlutterView window) {
    return make<ViewConfigurationCls>(window | this->window, devicePixelRatio | this->devicePixelRatio, geometry | this->geometry, visible | this->visible, viewInsets | this->viewInsets, viewPadding | this->viewPadding, systemGestureInsets | this->systemGestureInsets, padding | this->padding, gestureSettings | this->gestureSettings, displayFeatures | this->displayFeatures);
}

String ViewConfigurationCls::toString() {
    return __sf("%s[window: %s, geometry: %s]", runtimeType, window, geometry);
}

FrameTimingCls::FrameTimingCls(int buildFinish, int buildStart, int frameNumber, int layerCacheBytes, int layerCacheCount, int pictureCacheBytes, int pictureCacheCount, int rasterFinish, int rasterFinishWallTime, int rasterStart, int vsyncStart) {
    {
        return FrameTimingCls->_(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
    }
}

int FrameTimingCls::timestampInMicroseconds(FramePhase phase) {
    return _data[phase->index];
}

Duration FrameTimingCls::buildDuration() {
    return _rawDuration(FramePhaseCls::buildFinish) - _rawDuration(FramePhaseCls::buildStart);
}

Duration FrameTimingCls::rasterDuration() {
    return _rawDuration(FramePhaseCls::rasterFinish) - _rawDuration(FramePhaseCls::rasterStart);
}

Duration FrameTimingCls::vsyncOverhead() {
    return _rawDuration(FramePhaseCls::buildStart) - _rawDuration(FramePhaseCls::vsyncStart);
}

Duration FrameTimingCls::totalSpan() {
    return _rawDuration(FramePhaseCls::rasterFinish) - _rawDuration(FramePhaseCls::vsyncStart);
}

int FrameTimingCls::layerCacheCount() {
    return _rawInfo(_FrameTimingInfoCls::layerCacheCount);
}

int FrameTimingCls::layerCacheBytes() {
    return _rawInfo(_FrameTimingInfoCls::layerCacheBytes);
}

double FrameTimingCls::layerCacheMegabytes() {
    return layerCacheBytes() / 1024.0 / 1024.0;
}

int FrameTimingCls::pictureCacheCount() {
    return _rawInfo(_FrameTimingInfoCls::pictureCacheCount);
}

int FrameTimingCls::pictureCacheBytes() {
    return _rawInfo(_FrameTimingInfoCls::pictureCacheBytes);
}

double FrameTimingCls::pictureCacheMegabytes() {
    return pictureCacheBytes() / 1024.0 / 1024.0;
}

int FrameTimingCls::frameNumber() {
    return _data->last;
}

String FrameTimingCls::toString() {
    return __sf("%s(buildDuration: %s, rasterDuration: %s, vsyncOverhead: %s, totalSpan: %s, layerCacheCount: %s, layerCacheBytes: %s, pictureCacheCount: %s, pictureCacheBytes: %s, frameNumber: %s)", runtimeType, _formatMS(buildDuration()), _formatMS(rasterDuration()), _formatMS(vsyncOverhead()), _formatMS(totalSpan()), layerCacheCount(), layerCacheBytes(), pictureCacheCount(), pictureCacheBytes(), _data->last);
}

void FrameTimingCls::_(List<int> _data)

Duration FrameTimingCls::_rawDuration(FramePhase phase) {
    return make<DurationCls>(_data[phase->index]);
}

int FrameTimingCls::_rawInfo(_FrameTimingInfo info) {
    return _data[FramePhaseCls::values->length + info->index];
}

String FrameTimingCls::_formatMS(Duration duration) {
    return __sf("%sms", duration->inMicroseconds() * 0.001);
}

String WindowPaddingCls::toString() {
    return __sf("WindowPadding(left: %s, top: %s, right: %s, bottom: %s)", left, top, right, bottom);
}

DisplayFeatureCls::DisplayFeatureCls(Rect bounds, DisplayFeatureState state, DisplayFeatureType type) {
    {
        assert(!identical(type, DisplayFeatureTypeCls::cutout) || identical(state, DisplayFeatureStateCls::unknown));
    }
}

bool DisplayFeatureCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<DisplayFeature>(other) && bounds == other->bounds && type == other->type && state == other->state;
}

int DisplayFeatureCls::hashCode() {
    return ObjectCls->hash(bounds, type, state);
}

String DisplayFeatureCls::toString() {
    return __sf("DisplayFeature(rect: %s, type: %s, state: %s)", bounds, type, state);
}

LocaleCls::LocaleCls(String _languageCode, String _countryCode) {
    {
        assert(_languageCode != nullptr);
        assert(_languageCode != __s(""));
        scriptCode = nullptr;
    }
}

void LocaleCls::fromSubtags(String countryCode, String languageCode, String scriptCode)

String LocaleCls::languageCode() {
    return _deprecatedLanguageSubtagMap[_languageCode] | _languageCode;
}

String LocaleCls::countryCode() {
    return _deprecatedRegionSubtagMap[_countryCode] | _countryCode;
}

bool LocaleCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (!is<Locale>(other)) {
        return false;
    }
    String thisCountryCode = countryCode();
    String otherCountryCode = other->countryCode;
    return other->languageCode == languageCode() && other->scriptCode == scriptCode && (other->countryCode == thisCountryCode || otherCountryCode != nullptr && otherCountryCode->isEmpty() && thisCountryCode == nullptr || thisCountryCode != nullptr && thisCountryCode->isEmpty() && other->countryCode == nullptr);
}

int LocaleCls::hashCode() {
    return ObjectCls->hash(languageCode(), scriptCode, countryCode() == __s("")? nullptr : countryCode());
}

String LocaleCls::toString() {
    if (!identical(_cachedLocale, this)) {
        _cachedLocale = this;
        _cachedLocaleString = _rawToString(__s("_"));
    }
    return _cachedLocaleString!;
}

String LocaleCls::toLanguageTag() {
    return _rawToString(__s("-"));
}

String LocaleCls::_rawToString(String separator) {
    StringBuffer out = make<StringBufferCls>(languageCode());
    if (scriptCode != nullptr && scriptCode!->isNotEmpty()) {
        out->write(__sf("%s%s", separator, scriptCode));
    }
    if (_countryCode != nullptr && _countryCode!->isNotEmpty()) {
        out->write(__sf("%s%s", separator, countryCode()));
    }
    return out->toString();
}
