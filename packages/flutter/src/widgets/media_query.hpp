#ifndef MEDIA_QUERY_H
#define MEDIA_QUERY_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"



enum Orientation{
    portrait,
    landscape,
} // end Orientation

class MediaQueryData {
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


     MediaQueryData(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding);

    void  fromWindow(FlutterView window);

    Orientation orientation();

    MediaQueryData copyWith(bool accessibleNavigation, bool alwaysUse24HourFormat, bool boldText, double devicePixelRatio, bool disableAnimations, List<DisplayFeature> displayFeatures, DeviceGestureSettings gestureSettings, bool highContrast, bool invertColors, NavigationMode navigationMode, EdgeInsets padding, Brightness platformBrightness, Size size, EdgeInsets systemGestureInsets, double textScaleFactor, EdgeInsets viewInsets, EdgeInsets viewPadding);

    MediaQueryData removePadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    MediaQueryData removeViewInsets(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    MediaQueryData removeViewPadding(bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    MediaQueryData removeDisplayFeatures(Rect subScreen);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class MediaQuery : InheritedWidget {
public:
    MediaQueryData data;


     MediaQuery(Unknown, MediaQueryData data, Unknown);

    void  removePadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    void  removeViewInsets(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    void  removeViewPadding(Widget child, BuildContext context, Key key, bool removeBottom, bool removeLeft, bool removeRight, bool removeTop);

    static Widget fromWindow(Widget child, Key key);

    static MediaQueryData of(BuildContext context);

    static MediaQueryData maybeOf(BuildContext context);

    static double textScaleFactorOf(BuildContext context);

    static Brightness platformBrightnessOf(BuildContext context);

    static bool highContrastOf(BuildContext context);

    static bool boldTextOverride(BuildContext context);

    bool updateShouldNotify(MediaQuery oldWidget);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

enum NavigationMode{
    traditional,
    directional,
} // end NavigationMode

class _MediaQueryFromWindow : StatefulWidget {
public:
    Widget child;


    State<_MediaQueryFromWindow> createState();

private:

     _MediaQueryFromWindow(Widget child, Unknown);

};

class _MediaQueryFromWindowState : State<_MediaQueryFromWindow> {
public:

    void initState();

    void didChangeAccessibilityFeatures();

    void didChangeMetrics();

    void didChangeTextScaleFactor();

    void didChangePlatformBrightness();

    Widget build(BuildContext context);

    void dispose();

private:

};

#endif