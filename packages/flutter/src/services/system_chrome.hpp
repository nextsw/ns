#ifndef PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_CHROME
#define PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_CHROME
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "binding.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"
#include "system_channels.hpp"


enum DeviceOrientation{
    portraitUp,
    landscapeLeft,
    portraitDown,
    landscapeRight,
} // end DeviceOrientation

class ApplicationSwitcherDescriptionCls : public ObjectCls {
public:
    String label;

    int primaryColor;


     ApplicationSwitcherDescriptionCls(String label, int primaryColor);
private:

};
using ApplicationSwitcherDescription = std::shared_ptr<ApplicationSwitcherDescriptionCls>;

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

class SystemUiOverlayStyleCls : public ObjectCls {
public:
    Color systemNavigationBarColor;

    Color systemNavigationBarDividerColor;

    Brightness systemNavigationBarIconBrightness;

    bool systemNavigationBarContrastEnforced;

    Color statusBarColor;

    Brightness statusBarBrightness;

    Brightness statusBarIconBrightness;

    bool systemStatusBarContrastEnforced;

    static SystemUiOverlayStyle light;

    static SystemUiOverlayStyle dark;


     SystemUiOverlayStyleCls(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced);
    virtual String toString();

    virtual SystemUiOverlayStyle copyWith(Brightness statusBarBrightness, Color statusBarColor, Brightness statusBarIconBrightness, Color systemNavigationBarColor, bool systemNavigationBarContrastEnforced, Color systemNavigationBarDividerColor, Brightness systemNavigationBarIconBrightness, bool systemStatusBarContrastEnforced);

    virtual int hashCode();

    virtual bool operator==(Object other);

private:

    virtual Map<String, dynamic> _toMap();

};
using SystemUiOverlayStyle = std::shared_ptr<SystemUiOverlayStyleCls>;
List<String> _stringify(List<dynamic> list);


class SystemChromeCls : public ObjectCls {
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


    virtual void  _();
};
using SystemChrome = std::shared_ptr<SystemChromeCls>;


#endif