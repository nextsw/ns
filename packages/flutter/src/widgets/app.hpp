#ifndef APP_H
#define APP_H
#include <memory>
#include <ui.hpp>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
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


class WidgetsApp : StatefulWidget {
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


     WidgetsApp(Map<Type, Action<Intent>> actions, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, Widget home, String initialRoute, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GlobalKey<NavigatorState> navigatorKey, List<NavigatorObserver> navigatorObservers, InitialRouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, GenerateAppTitle onGenerateTitle, RouteFactory onUnknownRoute, PageRouteFactory pageRouteBuilder, String restorationScopeId, Map<String, WidgetBuilder> routes, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery);

    void  router(Map<Type, Action<Intent>> actions, BackButtonDispatcher backButtonDispatcher, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GenerateAppTitle onGenerateTitle, String restorationScopeId, RouteInformationParser<Object> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterConfig<Object> routerConfig, RouterDelegate<Object> routerDelegate, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery);

    static Map<ShortcutActivator, Intent> defaultShortcuts();

    State<WidgetsApp> createState();

private:
    static const Map<ShortcutActivator, Intent> _defaultShortcuts;

    static const Map<ShortcutActivator, Intent> _defaultWebShortcuts;

    static const Map<ShortcutActivator, Intent> _defaultAppleOsShortcuts;


};

class _WidgetsAppState : State<WidgetsApp> {
public:

    void initState();

    void didUpdateWidget(WidgetsApp oldWidget);

    void dispose();

    Future<bool> didPopRoute();

    Future<bool> didPushRoute(String route);

    void didChangeLocales(List<Locale> locales);

    Widget build(BuildContext context);

private:
    PlatformRouteInformationProvider _defaultRouteInformationProvider;

    RootBackButtonDispatcher _defaultBackButtonDispatcher;

    GlobalKey<NavigatorState> _navigator;

    Locale _locale;


    String _initialRouteName();

    void _clearRouterResource();

    void _clearNavigatorResource();

    void _updateRouting(WidgetsApp oldWidget);

    bool _usesRouterWithDelegates();

    bool _usesRouterWithConfig();

    bool _usesNavigator();

    RouteInformationProvider _effectiveRouteInformationProvider();

    BackButtonDispatcher _effectiveBackButtonDispatcher();

    Route<dynamic> _onGenerateRoute(RouteSettings settings);

    Route<dynamic> _onUnknownRoute(RouteSettings settings);

    Locale _resolveLocales(List<Locale> preferredLocales, Iterable<Locale> supportedLocales);

    Iterable<LocalizationsDelegate<dynamic>> _localizationsDelegates();

    bool _debugCheckLocalizations(Locale appLocale);

};

#endif