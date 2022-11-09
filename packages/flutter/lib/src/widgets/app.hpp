#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_APP
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_APP
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "banner.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "default_text_editing_shortcuts.hpp"
#include "focus_traversal.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "media_query.hpp"
#include "navigator.hpp"
#include "pages.hpp"
#include "performance_overlay.hpp"
#include "restoration.hpp"
#include "router.hpp"
#include "scrollable.hpp"
#include "semantics_debugger.hpp"
#include "shared_app_data.hpp"
#include "shortcuts.hpp"
#include "text.hpp"
#include "title.hpp"
#include "widget_inspector.hpp"

Locale basicLocaleListResolution(List<Locale> preferredLocales, Iterable<Locale> supportedLocales);


class WidgetsAppCls : public StatefulWidgetCls {
public:
    GlobalKey<NavigatorState> navigatorKey;

    RouteFactory onGenerateRoute;

    InitialRouteListFactory onGenerateInitialRoutes;

    PageRouteFactory pageRouteBuilder;

    RouteInformationParser<Object> routeInformationParser;

    RouterDelegate<Object> routerDelegate;

    BackButtonDispatcher backButtonDispatcher;

    RouteInformationProvider routeInformationProvider;

    RouterConfig<Object> routerConfig;

    Widget home;

    Map<String, WidgetBuilder> routes;

    RouteFactory onUnknownRoute;

    String initialRoute;

    List<NavigatorObserver> navigatorObservers;

    TransitionBuilder builder;

    String title;

    GenerateAppTitle onGenerateTitle;

    TextStyle textStyle;

    Color color;

    Locale locale;

    Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates;

    LocaleListResolutionCallback localeListResolutionCallback;

    LocaleResolutionCallback localeResolutionCallback;

    Iterable<Locale> supportedLocales;

    bool showPerformanceOverlay;

    bool checkerboardRasterCacheImages;

    bool checkerboardOffscreenLayers;

    bool showSemanticsDebugger;

    bool debugShowWidgetInspector;

    InspectorSelectButtonBuilder inspectorSelectButtonBuilder;

    bool debugShowCheckedModeBanner;

    Map<ShortcutActivator, Intent> shortcuts;

    Map<Type, Action<Intent>> actions;

    String restorationScopeId;

    bool useInheritedMediaQuery;

    static bool showPerformanceOverlayOverride;

    static bool debugShowWidgetInspectorOverride;

    static bool debugAllowBannerOverride;

    static Map<Type, Action<Intent>> defaultActions;


     WidgetsAppCls(Map<Type, Action<Intent>> actions, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, Widget home, String initialRoute, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown key, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GlobalKey<NavigatorState> navigatorKey, List<NavigatorObserver> navigatorObservers, InitialRouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, GenerateAppTitle onGenerateTitle, RouteFactory onUnknownRoute, PageRouteFactory pageRouteBuilder, String restorationScopeId, Map<String, WidgetBuilder> routes, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery);

    virtual void  router(Map<Type, Action<Intent>> actions, BackButtonDispatcher backButtonDispatcher, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown key, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GenerateAppTitle onGenerateTitle, String restorationScopeId, RouteInformationParser<Object> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterConfig<Object> routerConfig, RouterDelegate<Object> routerDelegate, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery);

    static Map<ShortcutActivator, Intent> defaultShortcuts();

    virtual State<WidgetsApp> createState();

private:
    static Map<ShortcutActivator, Intent> _defaultShortcuts;

    static Map<ShortcutActivator, Intent> _defaultWebShortcuts;

    static Map<ShortcutActivator, Intent> _defaultAppleOsShortcuts;


};
using WidgetsApp = std::shared_ptr<WidgetsAppCls>;

class _WidgetsAppStateCls : public StateCls<WidgetsApp> {
public:

    virtual void initState();

    virtual void didUpdateWidget(WidgetsApp oldWidget);

    virtual void dispose();

    virtual Future<bool> didPopRoute();

    virtual Future<bool> didPushRoute(String route);

    virtual void didChangeLocales(List<Locale> locales);

    virtual Widget build(BuildContext context);

private:
    PlatformRouteInformationProvider _defaultRouteInformationProvider;

    RootBackButtonDispatcher _defaultBackButtonDispatcher;

    GlobalKey<NavigatorState> _navigator;

    Locale _locale;


    virtual String _initialRouteName();

    virtual void _clearRouterResource();

    virtual void _clearNavigatorResource();

    virtual void _updateRouting(WidgetsApp oldWidget);

    virtual bool _usesRouterWithDelegates();

    virtual bool _usesRouterWithConfig();

    virtual bool _usesNavigator();

    virtual RouteInformationProvider _effectiveRouteInformationProvider();

    virtual BackButtonDispatcher _effectiveBackButtonDispatcher();

    virtual Route<dynamic> _onGenerateRoute(RouteSettings settings);

    virtual Route<dynamic> _onUnknownRoute(RouteSettings settings);

    virtual Locale _resolveLocales(List<Locale> preferredLocales, Iterable<Locale> supportedLocales);

    virtual Iterable<LocalizationsDelegate<dynamic>> _localizationsDelegates();

    virtual bool _debugCheckLocalizations(Locale appLocale);

};
using _WidgetsAppState = std::shared_ptr<_WidgetsAppStateCls>;


#endif