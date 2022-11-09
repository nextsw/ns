#include "system_chrome.hpp"
String SystemUiOverlayStyleCls::toString() {
    return "${objectRuntimeType(this, 'SystemUiOverlayStyle')}(${_toMap()})";
}

SystemUiOverlayStyle SystemUiOverlayStyleCls::copyWith(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced) {
    return make<SystemUiOverlayStyleCls>(systemNavigationBarColor ?? this->systemNavigationBarColor, systemNavigationBarDividerColor ?? this->systemNavigationBarDividerColor, systemNavigationBarContrastEnforced ?? this->systemNavigationBarContrastEnforced, statusBarColor ?? this->statusBarColor, statusBarIconBrightness ?? this->statusBarIconBrightness, statusBarBrightness ?? this->statusBarBrightness, systemStatusBarContrastEnforced ?? this->systemStatusBarContrastEnforced, systemNavigationBarIconBrightness ?? this->systemNavigationBarIconBrightness);
}

int SystemUiOverlayStyleCls::hashCode() {
    return ObjectCls->hash(systemNavigationBarColor, systemNavigationBarDividerColor, systemNavigationBarContrastEnforced, statusBarColor, statusBarBrightness, statusBarIconBrightness, systemStatusBarContrastEnforced, systemNavigationBarIconBrightness);
}

bool SystemUiOverlayStyleCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is SystemUiOverlayStyle && other->systemNavigationBarColor == systemNavigationBarColor && other->systemNavigationBarDividerColor == systemNavigationBarDividerColor && other->systemNavigationBarContrastEnforced == systemNavigationBarContrastEnforced && other->statusBarColor == statusBarColor && other->statusBarIconBrightness == statusBarIconBrightness && other->statusBarBrightness == statusBarBrightness && other->systemStatusBarContrastEnforced == systemStatusBarContrastEnforced && other->systemNavigationBarIconBrightness == systemNavigationBarIconBrightness;
}

Map<String, dynamic> SystemUiOverlayStyleCls::_toMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("systemNavigationBarColor", systemNavigationBarColor?->value);map1.set("systemNavigationBarDividerColor", systemNavigationBarDividerColor?->value);map1.set("systemStatusBarContrastEnforced", systemStatusBarContrastEnforced);map1.set("statusBarColor", statusBarColor?->value);map1.set("statusBarBrightness", statusBarBrightness?->toString());map1.set("statusBarIconBrightness", statusBarIconBrightness?->toString());map1.set("systemNavigationBarIconBrightness", systemNavigationBarIconBrightness?->toString());map1.set("systemNavigationBarContrastEnforced", systemNavigationBarContrastEnforced);return list1;
}

List<String> _stringify(List<dynamic> list) {
    return list1;
}

Future<void> SystemChromeCls::setPreferredOrientations(List<DeviceOrientation> orientations) {
    List<String> list1 = make<ListCls<>>();for (dynamic item : list)     {        ;    }{    list1.add(ArrayItem);}await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setPreferredOrientations", _stringify(orientations));
}

Future<void> SystemChromeCls::setApplicationSwitcherDescription(ApplicationSwitcherDescription description) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("label", description->label);map1.set("primaryColor", description->primaryColor);await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setApplicationSwitcherDescription", list1);
}

Future<void> SystemChromeCls::setEnabledSystemUIOverlays(List<SystemUiOverlay> overlays) {
    await await setEnabledSystemUIMode(SystemUiModeCls::manualoverlays);
}

Future<void> SystemChromeCls::setEnabledSystemUIMode(SystemUiMode mode, List<SystemUiOverlay> overlays) {
    if (mode != SystemUiModeCls::manual) {
        await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setEnabledSystemUIMode", mode->toString());
    } else {
        assert(mode == SystemUiModeCls::manual && overlays != nullptr);
        await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setEnabledSystemUIOverlays", _stringify(overlays!));
    }
}

Future<void> SystemChromeCls::setSystemUIChangeCallback(SystemUiChangeCallback callback) {
    ServicesBindingCls::instance->setSystemUiChangeCallback(callback);
    if (callback != nullptr) {
        await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setSystemUIChangeListener");
    }
}

Future<void> SystemChromeCls::restoreSystemUIOverlays() {
    await await SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.restoreSystemUIOverlays");
}

void SystemChromeCls::setSystemUIOverlayStyle(SystemUiOverlayStyle style) {
    assert(style != nullptr);
    if (_pendingStyle != nullptr) {
        _pendingStyle = style;
        return;
    }
    if (style == _latestStyle) {
        return;
    }
    _pendingStyle = style;
    scheduleMicrotask([=] () {
        assert(_pendingStyle != nullptr);
        if (_pendingStyle != _latestStyle) {
            SystemChannelsCls::platform-><void>invokeMethod("SystemChrome.setSystemUIOverlayStyle", _pendingStyle!->_toMap());
            _latestStyle = _pendingStyle;
        }
        _pendingStyle = nullptr;
    });
}

SystemUiOverlayStyle SystemChromeCls::latestStyle() {
    return _latestStyle;
}
