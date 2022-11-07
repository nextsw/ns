#ifndef SYSTEM_CHROME_H
#define SYSTEM_CHROME_H
#include <memory>
#include <ui.hpp>
#include "binding.hpp"

#include <async/async.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"
#include "system_channels.hpp"



enum DeviceOrientation{
    portraitUp,
    landscapeLeft,
    portraitDown,
    landscapeRight,
} // end DeviceOrientation

class ApplicationSwitcherDescription {
public:
    String label;

    int primaryColor;


     ApplicationSwitcherDescription(String label, int primaryColor);

private:

};

enum SystemUiOverlay{
    top,
    bottom,
} // end SystemUiOverlay

enum SystemUiMode{
    leanBack,
    immersive,
    immersiveSticky,
    edgeToEdge,
    manual,
} // end SystemUiMode

class SystemUiOverlayStyle {
public:
    Color systemNavigationBarColor;

    Color systemNavigationBarDividerColor;

    Brightness systemNavigationBarIconBrightness;

    bool systemNavigationBarContrastEnforced;

    Color statusBarColor;

    Brightness statusBarBrightness;

    Brightness statusBarIconBrightness;

    bool systemStatusBarContrastEnforced;

    static const SystemUiOverlayStyle light;

    static const SystemUiOverlayStyle dark;


     SystemUiOverlayStyle(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced);

    String toString();

    SystemUiOverlayStyle copyWith(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced);

    int hashCode();

    bool ==(Object other);

private:

    Map<String, dynamic> _toMap();

};
List<String> _stringify(List<dynamic> list);


class SystemChrome {
public:

    static Future<void> setPreferredOrientations(List<DeviceOrientation> orientations);

    static Future<void> setApplicationSwitcherDescription(ApplicationSwitcherDescription description);

    static Future<void> setEnabledSystemUIOverlays(List<SystemUiOverlay> overlays);

    static Future<void> setEnabledSystemUIMode(SystemUiMode mode, List<SystemUiOverlay> overlays);

    static Future<void> setSystemUIChangeCallback(SystemUiChangeCallback callback);

    static Future<void> restoreSystemUIOverlays();

    static void setSystemUIOverlayStyle(SystemUiOverlayStyle style);

    static SystemUiOverlayStyle latestStyle();

private:
    static SystemUiOverlayStyle _pendingStyle;

    static SystemUiOverlayStyle _latestStyle;


    void  _();

};

#endif