#include "system_chrome.hpp"
String SystemUiOverlayStyleCls::toString() {
    return __s("${objectRuntimeType(this, 'SystemUiOverlayStyle')}(${_toMap()})");
}

SystemUiOverlayStyle SystemUiOverlayStyleCls::copyWith(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced) {
    return make<SystemUiOverlayStyleCls>(systemNavigationBarColor or this->systemNavigationBarColor, systemNavigationBarDividerColor or this->systemNavigationBarDividerColor, systemNavigationBarContrastEnforced or this->systemNavigationBarContrastEnforced, statusBarColor or this->statusBarColor, statusBarIconBrightness or this->statusBarIconBrightness, statusBarBrightness or this->statusBarBrightness, systemStatusBarContrastEnforced or this->systemStatusBarContrastEnforced, systemNavigationBarIconBrightness or this->systemNavigationBarIconBrightness);
}

int SystemUiOverlayStyleCls::hashCode() {
    return ObjectCls->hash(systemNavigationBarColor, systemNavigationBarDividerColor, systemNavigationBarContrastEnforced, statusBarColor, statusBarBrightness, statusBarIconBrightness, systemStatusBarContrastEnforced, systemNavigationBarIconBrightness);
}

bool SystemUiOverlayStyleCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<SystemUiOverlayStyle>(other) && other->systemNavigationBarColor == systemNavigationBarColor && other->systemNavigationBarDividerColor == systemNavigationBarDividerColor && other->systemNavigationBarContrastEnforced == systemNavigationBarContrastEnforced && other->statusBarColor == statusBarColor && other->statusBarIconBrightness == statusBarIconBrightness && other->statusBarBrightness == statusBarBrightness && other->systemStatusBarContrastEnforced == systemStatusBarContrastEnforced && other->systemNavigationBarIconBrightness == systemNavigationBarIconBrightness;
}

Map<String, dynamic> SystemUiOverlayStyleCls::_toMap() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("systemNavigationBarColor"), systemNavigationBarColor?->value);map1.set(__s("systemNavigationBarDividerColor"), systemNavigationBarDividerColor?->value);map1.set(__s("systemStatusBarContrastEnforced"), systemStatusBarContrastEnforced);map1.set(__s("statusBarColor"), statusBarColor?->value);map1.set(__s("statusBarBrightness"), statusBarBrightness?->toString());map1.set(__s("statusBarIconBrightness"), statusBarIconBrightness?->toString());map1.set(__s("systemNavigationBarIconBrightness"), systemNavigationBarIconBrightness?->toString());map1.set(__s("systemNavigationBarContrastEnforced"), systemNavigationBarContrastEnforced);return list1;
}

List<String> _stringify(List<dynamic> list) {
    return list1;
}

Future<void> SystemChromeCls::setPreferredOrientations(List<DeviceOrientation> orientations) {
    List<String> list1 = make<ListCls<>>();for (dynamic item : list)     {        ;    }{    list1.add(ArrayItem);}await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setPreferredOrientations"), _stringify(orientations));
}

Future<void> SystemChromeCls::setApplicationSwitcherDescription(ApplicationSwitcherDescription description) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("label"), description->label);map1.set(__s("primaryColor"), description->primaryColor);await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setApplicationSwitcherDescription"), list1);
}

Future<void> SystemChromeCls::setEnabledSystemUIOverlays(List<SystemUiOverlay> overlays) {
    await await setEnabledSystemUIMode(SystemUiModeCls::manualoverlays);
}

Future<void> SystemChromeCls::setEnabledSystemUIMode(SystemUiMode mode, List<SystemUiOverlay> overlays) {
    if (mode != SystemUiModeCls::manual) {
        await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setEnabledSystemUIMode"), mode->toString());
    } else {
        assert(mode == SystemUiModeCls::manual && overlays != nullptr);
        await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setEnabledSystemUIOverlays"), _stringify(overlays!));
    }
}

Future<void> SystemChromeCls::setSystemUIChangeCallback(SystemUiChangeCallback callback) {
    ServicesBindingCls::instance->setSystemUiChangeCallback(callback);
    if (callback != nullptr) {
        await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setSystemUIChangeListener"));
    }
}

Future<void> SystemChromeCls::restoreSystemUIOverlays() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.restoreSystemUIOverlays"));
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
            SystemChannelsCls::platform-><void>invokeMethod(__s("SystemChrome.setSystemUIOverlayStyle"), _pendingStyle!->_toMap());
            _latestStyle = _pendingStyle;
        }
        _pendingStyle = nullptr;
    });
}

SystemUiOverlayStyle SystemChromeCls::latestStyle() {
    return _latestStyle;
}
