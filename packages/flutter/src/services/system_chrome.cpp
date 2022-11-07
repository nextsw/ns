#include "system_chrome.hpp"
String SystemUiOverlayStyle::toString() {
    return "${objectRuntimeType(this, 'SystemUiOverlayStyle')}(${_toMap()})";
}

SystemUiOverlayStyle SystemUiOverlayStyle::copyWith(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced) {
    return SystemUiOverlayStyle(systemNavigationBarColor ?? this.systemNavigationBarColor, systemNavigationBarDividerColor ?? this.systemNavigationBarDividerColor, systemNavigationBarContrastEnforced ?? this.systemNavigationBarContrastEnforced, statusBarColor ?? this.statusBarColor, statusBarIconBrightness ?? this.statusBarIconBrightness, statusBarBrightness ?? this.statusBarBrightness, systemStatusBarContrastEnforced ?? this.systemStatusBarContrastEnforced, systemNavigationBarIconBrightness ?? this.systemNavigationBarIconBrightness);
}

int SystemUiOverlayStyle::hashCode() {
    return Object.hash(systemNavigationBarColor, systemNavigationBarDividerColor, systemNavigationBarContrastEnforced, statusBarColor, statusBarBrightness, statusBarIconBrightness, systemStatusBarContrastEnforced, systemNavigationBarIconBrightness);
}

bool SystemUiOverlayStyle::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SystemUiOverlayStyle && other.systemNavigationBarColor == systemNavigationBarColor && other.systemNavigationBarDividerColor == systemNavigationBarDividerColor && other.systemNavigationBarContrastEnforced == systemNavigationBarContrastEnforced && other.statusBarColor == statusBarColor && other.statusBarIconBrightness == statusBarIconBrightness && other.statusBarBrightness == statusBarBrightness && other.systemStatusBarContrastEnforced == systemStatusBarContrastEnforced && other.systemNavigationBarIconBrightness == systemNavigationBarIconBrightness;
}

Map<String, dynamic> SystemUiOverlayStyle::_toMap() {
    return ;
}

List<String> _stringify(List<dynamic> list) {
    return ;
}

Future<void> SystemChrome::setPreferredOrientations(List<DeviceOrientation> orientations) {
    await await SystemChannels.platform.<void>invokeMethod("SystemChrome.setPreferredOrientations", _stringify(orientations));
}

Future<void> SystemChrome::setApplicationSwitcherDescription(ApplicationSwitcherDescription description) {
    await await SystemChannels.platform.<void>invokeMethod("SystemChrome.setApplicationSwitcherDescription", );
}

Future<void> SystemChrome::setEnabledSystemUIOverlays(List<SystemUiOverlay> overlays) {
    await await setEnabledSystemUIMode(SystemUiMode.manualoverlays);
}

Future<void> SystemChrome::setEnabledSystemUIMode(SystemUiMode mode, List<SystemUiOverlay> overlays) {
    if (mode != SystemUiMode.manual) {
        await await SystemChannels.platform.<void>invokeMethod("SystemChrome.setEnabledSystemUIMode", mode.toString());
    } else {
        assert(mode == SystemUiMode.manual && overlays != nullptr);
        await await SystemChannels.platform.<void>invokeMethod("SystemChrome.setEnabledSystemUIOverlays", _stringify(overlays!));
    }
}

Future<void> SystemChrome::setSystemUIChangeCallback(SystemUiChangeCallback callback) {
    ServicesBinding.instance.setSystemUiChangeCallback(callback);
    if (callback != nullptr) {
        await await SystemChannels.platform.<void>invokeMethod("SystemChrome.setSystemUIChangeListener");
    }
}

Future<void> SystemChrome::restoreSystemUIOverlays() {
    await await SystemChannels.platform.<void>invokeMethod("SystemChrome.restoreSystemUIOverlays");
}

void SystemChrome::setSystemUIOverlayStyle(SystemUiOverlayStyle style) {
    assert(style != nullptr);
    if (_pendingStyle != nullptr) {
        _pendingStyle = style;
        return;
    }
    if (style == _latestStyle) {
        return;
    }
    _pendingStyle = style;
    scheduleMicrotask();
}

SystemUiOverlayStyle SystemChrome::latestStyle() {
    return _latestStyle;
}
