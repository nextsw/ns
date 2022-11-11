#include "hooks.hpp"
void _updateWindowMetrics(double devicePixelRatio, List<double> displayFeaturesBounds, List<int> displayFeaturesState, List<int> displayFeaturesType, double height, Object id, double physicalTouchSlop, double systemGestureInsetBottom, double systemGestureInsetLeft, double systemGestureInsetRight, double systemGestureInsetTop, double viewInsetBottom, double viewInsetLeft, double viewInsetRight, double viewInsetTop, double viewPaddingBottom, double viewPaddingLeft, double viewPaddingRight, double viewPaddingTop, double width) {
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

void _dispatchPlatformMessage(ByteData data, String name, int responseId) {
    PlatformDispatcherCls::instance->_dispatchPlatformMessage(name, data, responseId);
}

void _dispatchPointerDataPacket(ByteData packet) {
    PlatformDispatcherCls::instance->_dispatchPointerDataPacket(packet);
}

void _dispatchSemanticsAction(int action, ByteData args, int id) {
    PlatformDispatcherCls::instance->_dispatchSemanticsAction(id, action, args);
}

void _beginFrame(int frameNumber, int microseconds) {
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
    return PlatformDispatcherCls::instance->_dispatchError(error, stackTrace or StackTraceCls::empty);
}

void _runMain(List<String> args, void  startMainIsolateFunction() , void  userMainFunction() ) {
    startMainIsolateFunction([=] () {
        if (is<_ListStringArgFunction>(userMainFunction)) {
            userMainFunction(args);
        } else {
            userMainFunction();
        }
    }, nullptr);
}

void _invoke(void callback() , Zone zone) {
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

void _invoke1template<typename A> (A arg, void callback(A a) , Zone zone) {
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

void _invoke2template<typename A1, typename A2> (A1 arg1, A2 arg2, void callback(A1 a1, A2 a2) , Zone zone) {
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

void _invoke3template<typename A1, typename A2, typename A3> (A1 arg1, A2 arg2, A3 arg3, void callback(A1 a1, A2 a2, A3 a3) , Zone zone) {
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
