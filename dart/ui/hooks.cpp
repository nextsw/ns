#include "hooks.hpp"
void _updateWindowMetrics(double devicePixelRatio, List<double> displayFeaturesBounds, List<int> displayFeaturesState, List<int> displayFeaturesType, double height, Object id, double physicalTouchSlop, double systemGestureInsetBottom, double systemGestureInsetLeft, double systemGestureInsetRight, double systemGestureInsetTop, double viewInsetBottom, double viewInsetLeft, double viewInsetRight, double viewInsetTop, double viewPaddingBottom, double viewPaddingLeft, double viewPaddingRight, double viewPaddingTop, double width) {
    PlatformDispatcher.instance._updateWindowMetrics(id, devicePixelRatio, width, height, viewPaddingTop, viewPaddingRight, viewPaddingBottom, viewPaddingLeft, viewInsetTop, viewInsetRight, viewInsetBottom, viewInsetLeft, systemGestureInsetTop, systemGestureInsetRight, systemGestureInsetBottom, systemGestureInsetLeft, physicalTouchSlop, displayFeaturesBounds, displayFeaturesType, displayFeaturesState);
}

_LocaleClosure _getLocaleClosure() {
    return PlatformDispatcher.instance._localeClosure;
}

void _updateLocales(List<String> locales) {
    PlatformDispatcher.instance._updateLocales(locales);
}

void _updateUserSettingsData(String jsonData) {
    PlatformDispatcher.instance._updateUserSettingsData(jsonData);
}

void _updateLifecycleState(String state) {
    PlatformDispatcher.instance._updateLifecycleState(state);
}

void _updateSemanticsEnabled(bool enabled) {
    PlatformDispatcher.instance._updateSemanticsEnabled(enabled);
}

void _updateAccessibilityFeatures(int values) {
    PlatformDispatcher.instance._updateAccessibilityFeatures(values);
}

void _dispatchPlatformMessage(ByteData data, String name, int responseId) {
    PlatformDispatcher.instance._dispatchPlatformMessage(name, data, responseId);
}

void _dispatchPointerDataPacket(ByteData packet) {
    PlatformDispatcher.instance._dispatchPointerDataPacket(packet);
}

void _dispatchSemanticsAction(int action, ByteData args, int id) {
    PlatformDispatcher.instance._dispatchSemanticsAction(id, action, args);
}

void _beginFrame(int frameNumber, int microseconds) {
    PlatformDispatcher.instance._beginFrame(microseconds);
    PlatformDispatcher.instance._updateFrameData(frameNumber);
}

void _reportTimings(List<int> timings) {
    PlatformDispatcher.instance._reportTimings(timings);
}

void _drawFrame() {
    PlatformDispatcher.instance._drawFrame();
}

bool _onError(Object error, StackTrace stackTrace) {
    return PlatformDispatcher.instance._dispatchError(error, stackTrace ?? StackTrace.empty);
}

void _runMain(List<String> args, FunctionType startMainIsolateFunction, FunctionType userMainFunction) {
    startMainIsolateFunction(, nullptr);
}

void _invoke(FunctionType callback, Zone zone) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, Zone.current)) {
        callback();
    } else {
        zone.runGuarded(callback);
    }
}

void _invoke1<A>(A arg, FunctionType callback, Zone zone) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, Zone.current)) {
        callback(arg);
    } else {
        zone.<A>runUnaryGuarded(callback, arg);
    }
}

void _invoke2<A1, A2>(A1 arg1, A2 arg2, FunctionType callback, Zone zone) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, Zone.current)) {
        callback(arg1, arg2);
    } else {
        zone.runGuarded();
    }
}

void _invoke3<A1, A2, A3>(A1 arg1, A2 arg2, A3 arg3, FunctionType callback, Zone zone) {
    if (callback == nullptr) {
        return;
    }
    assert(zone != nullptr);
    if (identical(zone, Zone.current)) {
        callback(arg1, arg2, arg3);
    } else {
        zone.runGuarded();
    }
}

bool _isLoopback(String host) {
    if (host.isEmpty) {
        return false;
    }
    if ("localhost" == host) {
        return true;
    }
    ;
}
