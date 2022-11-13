#include "hooks.hpp"
void _updateWindowMetrics(Object id, double devicePixelRatio, double width, double height, double viewPaddingTop, double viewPaddingRight, double viewPaddingBottom, double viewPaddingLeft, double viewInsetTop, double viewInsetRight, double viewInsetBottom, double viewInsetLeft, double systemGestureInsetTop, double systemGestureInsetRight, double systemGestureInsetBottom, double systemGestureInsetLeft, double physicalTouchSlop, List<double> displayFeaturesBounds, List<int> displayFeaturesType, List<int> displayFeaturesState) {
    PlatformDispatcherCls::instance->_updateWindowMetrics(id, devicePixelRatio, width, height, viewPaddingTop, viewPaddingRight, viewPaddingBottom, viewPaddingLeft, viewInsetTop, viewInsetRight, viewInsetBottom, viewInsetLeft, systemGestureInsetTop, systemGestureInsetRight, systemGestureInsetBottom, systemGestureInsetLeft, physicalTouchSlop, displayFeaturesBounds, displayFeaturesType, displayFeaturesState);
}

_LocaleClosure _getLocaleClosure() {
    return PlatformDispatcherCls::instance->_localeClosure;
}

void _updateLocales(List<String> locales) {
    PlatformDispatcherCls::instance->_updateLocales(locales);
}

void _updateUserSettingsData(String jsonData) {
    PlatformDispatcherCls::instance->_updateUserSettingsData(jsonData);
}

void _updateLifecycleState(String state) {
    PlatformDispatcherCls::instance->_updateLifecycleState(state);
}

void _updateSemanticsEnabled(bool enabled) {
    PlatformDispatcherCls::instance->_updateSemanticsEnabled(enabled);
}

void _updateAccessibilityFeatures(int values) {
    PlatformDispatcherCls::instance->_updateAccessibilityFeatures(values);
}

void _dispatchPlatformMessage(String name, ByteData data, int responseId) {
    PlatformDispatcherCls::instance->_dispatchPlatformMessage(name, data, responseId);
}

void _dispatchPointerDataPacket(ByteData packet) {
    PlatformDispatcherCls::instance->_dispatchPointerDataPacket(packet);
}

void _dispatchSemanticsAction(int id, int action, ByteData args) {
    PlatformDispatcherCls::instance->_dispatchSemanticsAction(id, action, args);
}

void _beginFrame(int microseconds, int frameNumber) {
    PlatformDispatcherCls::instance->_beginFrame(microseconds);
    PlatformDispatcherCls::instance->_updateFrameData(frameNumber);
}

void _reportTimings(List<int> timings) {
    PlatformDispatcherCls::instance->_reportTimings(timings);
}

void _drawFrame() {
    PlatformDispatcherCls::instance->_drawFrame();
}

bool _onError(Object error, StackTrace stackTrace) {
    return PlatformDispatcherCls::instance->_dispatchError(error, stackTrace | StackTraceCls::empty);
}

void _runMain(std::function<void ()> startMainIsolateFunction, std::function<void ()> userMainFunction, List<String> args) {
    startMainIsolateFunction([=] () {
        if (is<_ListStringArgFunction>(userMainFunction)) {
            userMainFunction(args);
        } else {
            userMainFunction();
        }
    }, nullptr);
}

void _invoke(std::function<void()> callback, Zone zone) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, ZoneCls::current)) {
        callback();
    } else {
        zone->runGuarded(callback);
    }
}

template<typename A>
void _invoke1(std::function<void(A a)> callback, Zone zone, A arg) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, ZoneCls::current)) {
        callback(arg);
    } else {
        zone-><A>runUnaryGuarded(callback, arg);
    }
}

template<typename A1, typename A2>
void _invoke2(std::function<void(A1 a1, A2 a2)> callback, Zone zone, A1 arg1, A2 arg2) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, ZoneCls::current)) {
        callback(arg1, arg2);
    } else {
        zone->runGuarded([=] () {
            callback(arg1, arg2);
        });
    }
}

template<typename A1, typename A2, typename A3>
void _invoke3(std::function<void(A1 a1, A2 a2, A3 a3)> callback, Zone zone, A1 arg1, A2 arg2, A3 arg3) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, ZoneCls::current)) {
        callback(arg1, arg2, arg3);
    } else {
        zone->runGuarded([=] () {
            callback(arg1, arg2, arg3);
        });
    }
}

bool _isLoopback(String host) {
    if (host->isEmpty()) {
        return false;
    }
    if (__s("localhost") == host) {
        return true;
    }
    try {
        return make<InternetAddressCls>(host)->isLoopback;
    } catch (ArgumentError null) {
        return false;
    };
}

std::function<void(Uri )> _getHttpConnectionHookClosure(bool mayInsecurelyConnectToAllDomains) {
    return [=] (Uri uri) {
        Object zoneOverride = ZoneCls::current[__symbol("flutter.io.allow_http")];
        if (zoneOverride == true) {
            return;
        }
        if (zoneOverride == false && uri->isScheme(__s("http"))) {
        } else {
            if (mayInsecurelyConnectToAllDomains || uri->isScheme(__s("https"))) {
            return;
        }
;
        }        if (_isLoopback(uri->host)) {
            return;
        }
        throw make<UnsupportedErrorCls>(__sf("Non-https connection "%s" is not supported by the platform. Refer to https://flutter.dev/docs/release/breaking-changes/network-policy-ios-android.", uri));
    };
}
