#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_MEDIA_QUERY
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_MEDIA_QUERY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"


enum Orientation{
    portrait,
    landscape,
} // end Orientation

class MediaQueryDataCls : public ObjectCls {
public:
    Size size;

    double devicePixelRatio;

    double textScaleFactor;

    Brightness platformBrightness;

    EdgeInsets viewInsets;

    EdgeInsets padding;

    EdgeInsets viewPadding;

    EdgeInsets systemGestureInsets;

    bool alwaysUse24HourFormat;

    bool accessibleNavigation;

    bool invertColors;

    bool highContrast;

    bool disableAnimations;

    bool boldText;

    NavigationMode navigationMode;

    DeviceGestureSettings gestureSettings;

    List<DisplayFeature> displayFeatures;


     MediaQueryDataCls(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding);

    virtual void  fromWindow(FlutterView window);

    virtual Orientation orientation();

    virtual MediaQueryData copyWith(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding);

    virtual MediaQueryData removePadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    virtual MediaQueryData removeViewInsets(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    virtual MediaQueryData removeViewPadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    virtual MediaQueryData removeDisplayFeatures(Rect subScreen);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using MediaQueryData = std::shared_ptr<MediaQueryDataCls>;

class MediaQueryCls : public InheritedWidgetCls {
public:
    MediaQueryData data;


     MediaQueryCls(Unknown child, MediaQueryData data, Unknown key);

    virtual void  removePadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    virtual void  removeViewInsets(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    virtual void  removeViewPadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    static Widget fromWindow(Widget child, Key key);

    static MediaQueryData of(BuildContext context);

    static MediaQueryData maybeOf(BuildContext context);

    static double textScaleFactorOf(BuildContext context);

    static Brightness platformBrightnessOf(BuildContext context);

    static bool highContrastOf(BuildContext context);

    static bool boldTextOverride(BuildContext context);

    virtual bool updateShouldNotify(MediaQuery oldWidget);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using MediaQuery = std::shared_ptr<MediaQueryCls>;

enum NavigationMode{
    traditional,
    directional,
} // end NavigationMode

class _MediaQueryFromWindowCls : public StatefulWidgetCls {
public:
    Widget child;


    virtual State<_MediaQueryFromWindow> createState();

private:

     _MediaQueryFromWindowCls(Widget child, Unknown key);
};
using _MediaQueryFromWindow = std::shared_ptr<_MediaQueryFromWindowCls>;

class _MediaQueryFromWindowStateCls : public StateCls<_MediaQueryFromWindow> {
public:

    virtual void initState();

    virtual void didChangeAccessibilityFeatures();

    virtual void didChangeMetrics();

    virtual void didChangeTextScaleFactor();

    virtual void didChangePlatformBrightness();

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:

};
using _MediaQueryFromWindowState = std::shared_ptr<_MediaQueryFromWindowStateCls>;


#endif