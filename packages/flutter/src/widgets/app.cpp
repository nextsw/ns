#include "app.hpp"
Locale basicLocaleListResolution(List<Locale> preferredLocales, Iterable<Locale> supportedLocales) {
    if (preferredLocales == nullptr || preferredLocales.isEmpty) {
        return supportedLocales.first;
    }
    Map<String, Locale> allSupportedLocales = <String, Locale>HashMap();
    Map<String, Locale> languageAndCountryLocales = <String, Locale>HashMap();
    Map<String, Locale> languageAndScriptLocales = <String, Locale>HashMap();
    Map<String, Locale> languageLocales = <String, Locale>HashMap();
    Map<String, Locale> countryLocales = <String, Locale>HashMap();
    for (Locale locale : supportedLocales) {
        allSupportedLocales["${locale.languageCode}_${locale.scriptCode}_${locale.countryCode}"] = locale;
        languageAndScriptLocales["${locale.languageCode}_${locale.scriptCode}"] = locale;
        languageAndCountryLocales["${locale.languageCode}_${locale.countryCode}"] = locale;
        languageLocales[locale.languageCode] = locale;
        countryLocales[locale.countryCode] = locale;
    }
    Locale matchesLanguageCode;
    Locale matchesCountryCode;
    for (;  < preferredLocales.length; localeIndex = 1) {
        Locale userLocale = preferredLocales[localeIndex];
        if (allSupportedLocales.containsKey("${userLocale.languageCode}_${userLocale.scriptCode}_${userLocale.countryCode}")) {
            return userLocale;
        }
        if (userLocale.scriptCode != nullptr) {
            Locale match = languageAndScriptLocales["${userLocale.languageCode}_${userLocale.scriptCode}"];
            if (match != nullptr) {
                return match;
            }
        }
        if (userLocale.countryCode != nullptr) {
            Locale match = languageAndCountryLocales["${userLocale.languageCode}_${userLocale.countryCode}"];
            if (match != nullptr) {
                return match;
            }
        }
        if (matchesLanguageCode != nullptr) {
            return matchesLanguageCode;
        }
        Locale match = languageLocales[userLocale.languageCode];
        if (match != nullptr) {
            matchesLanguageCode = match;
            if (localeIndex == 0 && !(localeIndex + 1 < preferredLocales.length && preferredLocales[localeIndex + 1].languageCode == userLocale.languageCode)) {
                return matchesLanguageCode;
            }
        }
        if (matchesCountryCode == nullptr && userLocale.countryCode != nullptr) {
            match = countryLocales[userLocale.countryCode];
            if (match != nullptr) {
                matchesCountryCode = match;
            }
        }
    }
    Locale resolvedLocale = matchesLanguageCode ?? matchesCountryCode ?? supportedLocales.first;
    return resolvedLocale;
}

WidgetsApp::WidgetsApp(Map<Type, Action<Intent>> actions, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, Widget home, String initialRoute, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GlobalKey<NavigatorState> navigatorKey, List<NavigatorObserver> navigatorObservers, InitialRouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, GenerateAppTitle onGenerateTitle, RouteFactory onUnknownRoute, PageRouteFactory pageRouteBuilder, String restorationScopeId, Map<String, WidgetBuilder> routes, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery) {
    {
        assert(navigatorObservers != nullptr);
        assert(routes != nullptr);
        assert(home == nullptr || onGenerateInitialRoutes == nullptr, "If onGenerateInitialRoutes is specified, the home argument will be redundant.");
        assert(home == nullptr || !routes.containsKey(Navigator.defaultRouteName), "If the home property is specified, the routes table cannot include an entry for "/", since it would be redundant.");
        assert(builder != nullptr || home != nullptr || routes.containsKey(Navigator.defaultRouteName) || onGenerateRoute != nullptr || onUnknownRoute != nullptr, "Either the home property must be specified, or the routes table must include an entry for "/", or there must be on onGenerateRoute callback specified, or there must be an onUnknownRoute callback specified, or the builder property must be specified, because otherwise there is nothing to fall back on if the app is started with an intent that specifies an unknown route.");
        assert((home != nullptr || routes.isNotEmpty || onGenerateRoute != nullptr || onUnknownRoute != nullptr) || (builder != nullptr && navigatorKey == nullptr && initialRoute == nullptr && navigatorObservers.isEmpty), "If no route is provided using home, routes, onGenerateRoute, or onUnknownRoute, a non-null callback for the builder property must be provided, and the other navigator-related properties, navigatorKey, initialRoute, and navigatorObservers, must have their initial values (null, null, and the empty list, respectively).");
        assert(builder != nullptr || onGenerateRoute != nullptr || pageRouteBuilder != nullptr, "If neither builder nor onGenerateRoute are provided, the pageRouteBuilder must be specified so that the default handler will know what kind of PageRoute transition to build.");
        assert(title != nullptr);
        assert(color != nullptr);
        assert(supportedLocales != nullptr && supportedLocales.isNotEmpty);
        assert(showPerformanceOverlay != nullptr);
        assert(checkerboardRasterCacheImages != nullptr);
        assert(checkerboardOffscreenLayers != nullptr);
        assert(showSemanticsDebugger != nullptr);
        assert(debugShowCheckedModeBanner != nullptr);
        assert(debugShowWidgetInspector != nullptr);
        routeInformationProvider = nullptr;
        routeInformationParser = nullptr;
        routerDelegate = nullptr;
        backButtonDispatcher = nullptr;
        routerConfig = nullptr;
    }
}

void WidgetsApp::router(Map<Type, Action<Intent>> actions, BackButtonDispatcher backButtonDispatcher, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<dynamic>> localizationsDelegates, GenerateAppTitle onGenerateTitle, String restorationScopeId, RouteInformationParser<Object> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterConfig<Object> routerConfig, RouterDelegate<Object> routerDelegate, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery)

Map<ShortcutActivator, Intent> WidgetsApp::defaultShortcuts() {
    if (kIsWeb) {
        return _defaultWebShortcuts;
    }
    ;
}

State<WidgetsApp> WidgetsApp::createState() {
    return _WidgetsAppState();
}

void _WidgetsAppState::initState() {
    super.initState();
    _updateRouting();
    _locale = _resolveLocales(WidgetsBinding.instance.platformDispatcher.locales, widget.supportedLocales);
    WidgetsBinding.instance.addObserver(this);
}

void _WidgetsAppState::didUpdateWidget(WidgetsApp oldWidget) {
    super.didUpdateWidget(oldWidget);
    _updateRouting(oldWidget);
}

void _WidgetsAppState::dispose() {
    WidgetsBinding.instance.removeObserver(this);
    _defaultRouteInformationProvider?.dispose();
    super.dispose();
}

Future<bool> _WidgetsAppState::didPopRoute() {
    assert(mounted);
    if (_usesRouterWithDelegates) {
        return false;
    }
    NavigatorState navigator = _navigator?.currentState;
    if (navigator == nullptr) {
        return false;
    }
    return navigator.maybePop();
}

Future<bool> _WidgetsAppState::didPushRoute(String route) {
    assert(mounted);
    if (_usesRouterWithDelegates) {
        return false;
    }
    NavigatorState navigator = _navigator?.currentState;
    if (navigator == nullptr) {
        return false;
    }
    navigator.pushNamed(route);
    return true;
}

void _WidgetsAppState::didChangeLocales(List<Locale> locales) {
    Locale newLocale = _resolveLocales(locales, widget.supportedLocales);
    if (newLocale != _locale) {
        setState();
    }
}

Widget _WidgetsAppState::build(BuildContext context) {
    Widget routing;
    if (_usesRouterWithDelegates) {
        routing = <Object>Router("router", _effectiveRouteInformationProvider, widget.routeInformationParser, widget.routerDelegate!, _effectiveBackButtonDispatcher);
    } else     {
        if (_usesNavigator) {
        assert(_navigator != nullptr);
        routing = Navigator("nav", _navigator, _initialRouteName, _onGenerateRoute, widget.onGenerateInitialRoutes == nullptr? Navigator.defaultGenerateInitialRoutes : , _onUnknownRoute, widget.navigatorObservers!, true);
    } else     {
        if (_usesRouterWithConfig) {
        routing = <Object>withConfig("router", widget.routerConfig!);
    }
;
    };
    }    Widget result;
    if (widget.builder != nullptr) {
        result = Builder();
    } else {
        assert(routing != nullptr);
        result = routing!;
    }
    if (widget.textStyle != nullptr) {
        result = DefaultTextStyle(widget.textStyle!, result);
    }
    PerformanceOverlay performanceOverlay;
    if (widget.showPerformanceOverlay || WidgetsApp.showPerformanceOverlayOverride) {
        performanceOverlay = PerformanceOverlay.allEnabled(widget.checkerboardRasterCacheImages, widget.checkerboardOffscreenLayers);
    } else     {
        if (widget.checkerboardRasterCacheImages || widget.checkerboardOffscreenLayers) {
        performanceOverlay = PerformanceOverlay(widget.checkerboardRasterCacheImages, widget.checkerboardOffscreenLayers);
    }
;
    }    if (performanceOverlay != nullptr) {
        result = Stack();
    }
    if (widget.showSemanticsDebugger) {
        result = SemanticsDebugger(result);
    }
    assert(());
    Widget title;
    if (widget.onGenerateTitle != nullptr) {
        title = Builder();
    } else {
        title = Title(widget.title, widget.color.withOpacity(1.0), result);
    }
    Locale appLocale = widget.locale != nullptr? _resolveLocales(, widget.supportedLocales) : _locale!;
    assert(_debugCheckLocalizations(appLocale));
    Widget child = Localizations(appLocale, _localizationsDelegates.toList(), title);
    MediaQueryData data = MediaQuery.maybeOf(context);
    if (!widget.useInheritedMediaQuery || data == nullptr) {
        child = MediaQuery.fromWindow(child);
    }
    return RootRestorationScope(widget.restorationScopeId, SharedAppData(Shortcuts("<Default WidgetsApp Shortcuts>", widget.shortcuts ?? WidgetsApp.defaultShortcuts, DefaultTextEditingShortcuts(Actions(widget.actions ?? WidgetsApp.defaultActions, FocusTraversalGroup(ReadingOrderTraversalPolicy(), ShortcutRegistrar(child)))))));
}

String _WidgetsAppState::_initialRouteName() {
    return WidgetsBinding.instance.platformDispatcher.defaultRouteName != Navigator.defaultRouteName? WidgetsBinding.instance.platformDispatcher.defaultRouteName : widget.initialRoute ?? WidgetsBinding.instance.platformDispatcher.defaultRouteName;
}

void _WidgetsAppState::_clearRouterResource() {
    _defaultRouteInformationProvider?.dispose();
    _defaultRouteInformationProvider = nullptr;
    _defaultBackButtonDispatcher = nullptr;
}

void _WidgetsAppState::_clearNavigatorResource() {
    _navigator = nullptr;
}

void _WidgetsAppState::_updateRouting(WidgetsApp oldWidget) {
    if (_usesRouterWithDelegates) {
        assert(!_usesNavigator && !_usesRouterWithConfig);
        _clearNavigatorResource();
        if (widget.routeInformationProvider == nullptr && widget.routeInformationParser != nullptr) {
            _defaultRouteInformationProvider = PlatformRouteInformationProvider(RouteInformation(_initialRouteName));
        } else {
            _defaultRouteInformationProvider?.dispose();
            _defaultRouteInformationProvider = nullptr;
        }
        if (widget.backButtonDispatcher == nullptr) {
            _defaultBackButtonDispatcher = RootBackButtonDispatcher();
        }
    } else     {
        if (_usesNavigator) {
        assert(!_usesRouterWithDelegates && !_usesRouterWithConfig);
        _clearRouterResource();
        if (_navigator == nullptr || widget.navigatorKey != oldWidget!.navigatorKey) {
            _navigator = widget.navigatorKey ?? <NavigatorState>GlobalObjectKey(this);
        }
        assert(_navigator != nullptr);
    } else {
        assert(widget.builder != nullptr || _usesRouterWithConfig);
        assert(!_usesRouterWithDelegates && !_usesNavigator);
        _clearRouterResource();
        _clearNavigatorResource();
    }
;
    }    assert(_usesNavigator == (_navigator != nullptr));
}

bool _WidgetsAppState::_usesRouterWithDelegates() {
    return widget.routerDelegate != nullptr;
}

bool _WidgetsAppState::_usesRouterWithConfig() {
    return widget.routerConfig != nullptr;
}

bool _WidgetsAppState::_usesNavigator() {
    return widget.home != nullptr || (widget.routes?.isNotEmpty ?? false) || widget.onGenerateRoute != nullptr || widget.onUnknownRoute != nullptr;
}

RouteInformationProvider _WidgetsAppState::_effectiveRouteInformationProvider() {
    return widget.routeInformationProvider ?? _defaultRouteInformationProvider;
}

BackButtonDispatcher _WidgetsAppState::_effectiveBackButtonDispatcher() {
    return widget.backButtonDispatcher ?? _defaultBackButtonDispatcher!;
}

Route<dynamic> _WidgetsAppState::_onGenerateRoute(RouteSettings settings) {
    String name = settings.name;
    WidgetBuilder pageContentBuilder = name == Navigator.defaultRouteName && widget.home != nullptr?  : widget.routes![name];
    if (pageContentBuilder != nullptr) {
        assert(widget.pageRouteBuilder != nullptr, "The default onGenerateRoute handler for WidgetsApp must have a pageRouteBuilder set if the home or routes properties are set.");
        Route<dynamic> route = widget.pageRouteBuilder;
        assert(route != nullptr, "The pageRouteBuilder for WidgetsApp must return a valid non-null Route.");
        return route;
    }
    if (widget.onGenerateRoute != nullptr) {
        return widget.onGenerateRoute!(settings);
    }
    return nullptr;
}

Route<dynamic> _WidgetsAppState::_onUnknownRoute(RouteSettings settings) {
    assert(());
    Route<dynamic> result = widget.onUnknownRoute!(settings);
    assert(());
    return result!;
}

Locale _WidgetsAppState::_resolveLocales(List<Locale> preferredLocales, Iterable<Locale> supportedLocales) {
    if (widget.localeListResolutionCallback != nullptr) {
        Locale locale = widget.localeListResolutionCallback!(preferredLocales, widget.supportedLocales);
        if (locale != nullptr) {
            return locale;
        }
    }
    if (widget.localeResolutionCallback != nullptr) {
        Locale locale = widget.localeResolutionCallback!(preferredLocales != nullptr && preferredLocales.isNotEmpty? preferredLocales.first : nullptr, widget.supportedLocales);
        if (locale != nullptr) {
            return locale;
        }
    }
    return basicLocaleListResolution(preferredLocales, supportedLocales);
}

Iterable<LocalizationsDelegate<dynamic>> _WidgetsAppState::_localizationsDelegates() {
    return ;
}

bool _WidgetsAppState::_debugCheckLocalizations(Locale appLocale) {
    assert(());
    return true;
}
