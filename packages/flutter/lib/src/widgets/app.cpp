#include "app.hpp"
Locale basicLocaleListResolution(List<Locale> preferredLocales, Iterable<Locale> supportedLocales) {
    if (preferredLocales == nullptr || preferredLocales->isEmpty()) {
        return supportedLocales->first();
    }
    Map<String, Locale> allSupportedLocales = <String, Locale>make<HashMapCls>();
    Map<String, Locale> languageAndCountryLocales = <String, Locale>make<HashMapCls>();
    Map<String, Locale> languageAndScriptLocales = <String, Locale>make<HashMapCls>();
    Map<String, Locale> languageLocales = <String, Locale>make<HashMapCls>();
    Map<String, Locale> countryLocales = <String, Locale>make<HashMapCls>();
    for (Locale locale : supportedLocales) {
        allSupportedLocales[__sf("%s_%s_%s", locale->languageCode, locale->scriptCode, locale->countryCode)] |= locale;
        languageAndScriptLocales[__sf("%s_%s", locale->languageCode, locale->scriptCode)] |= locale;
        languageAndCountryLocales[__sf("%s_%s", locale->languageCode, locale->countryCode)] |= locale;
        languageLocales[locale->languageCode] |= locale;
        countryLocales[locale->countryCode] |= locale;
    }
    Locale matchesLanguageCode;
    Locale matchesCountryCode;
    for (;  < preferredLocales->length(); localeIndex += 1) {
        Locale userLocale = preferredLocales[localeIndex];
        if (allSupportedLocales->containsKey(__sf("%s_%s_%s", userLocale->languageCode(), userLocale->scriptCode, userLocale->countryCode()))) {
            return userLocale;
        }
        if (userLocale->scriptCode != nullptr) {
            Locale match = languageAndScriptLocales[__sf("%s_%s", userLocale->languageCode(), userLocale->scriptCode)];
            if (match != nullptr) {
                return match;
            }
        }
        if (userLocale->countryCode() != nullptr) {
            Locale match = languageAndCountryLocales[__sf("%s_%s", userLocale->languageCode(), userLocale->countryCode())];
            if (match != nullptr) {
                return match;
            }
        }
        if (matchesLanguageCode != nullptr) {
            return matchesLanguageCode;
        }
        Locale match = languageLocales[userLocale->languageCode()];
        if (match != nullptr) {
            matchesLanguageCode = match;
            if (localeIndex == 0 && !(localeIndex + 1 < preferredLocales->length() && preferredLocales[localeIndex + 1]->languageCode() == userLocale->languageCode())) {
                return matchesLanguageCode;
            }
        }
        if (matchesCountryCode == nullptr && userLocale->countryCode() != nullptr) {
            match = countryLocales[userLocale->countryCode()];
            if (match != nullptr) {
                matchesCountryCode = match;
            }
        }
    }
    Locale resolvedLocale = matchesLanguageCode | matchesCountryCode | supportedLocales->first();
    return resolvedLocale;
}

WidgetsAppCls::WidgetsAppCls(Map<Type, Action<Intent>> actions, TransitionBuilder builder, bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Color color, bool debugShowCheckedModeBanner, bool debugShowWidgetInspector, Widget home, String initialRoute, InspectorSelectButtonBuilder inspectorSelectButtonBuilder, Unknown key, Locale locale, LocaleListResolutionCallback localeListResolutionCallback, LocaleResolutionCallback localeResolutionCallback, Iterable<LocalizationsDelegate<Object>> localizationsDelegates, GlobalKey<NavigatorState> navigatorKey, List<NavigatorObserver> navigatorObservers, InitialRouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, GenerateAppTitle onGenerateTitle, RouteFactory onUnknownRoute, PageRouteFactory pageRouteBuilder, String restorationScopeId, Map<String, WidgetBuilder> routes, Map<ShortcutActivator, Intent> shortcuts, bool showPerformanceOverlay, bool showSemanticsDebugger, Iterable<Locale> supportedLocales, TextStyle textStyle, String title, bool useInheritedMediaQuery) {
    {
        assert(navigatorObservers != nullptr);
        assert(routes != nullptr);
        assert(home == nullptr || onGenerateInitialRoutes == nullptr, __s("If onGenerateInitialRoutes is specified, the home argument will be redundant."));
        assert(home == nullptr || !routes->containsKey(NavigatorCls::defaultRouteName), __s("If the home property is specified, the routes table cannot include an entry for "/", since it would be redundant."));
        assert(builder != nullptr || home != nullptr || routes->containsKey(NavigatorCls::defaultRouteName) || onGenerateRoute != nullptr || onUnknownRoute != nullptr, __s("Either the home property must be specified, or the routes table must include an entry for "/", or there must be on onGenerateRoute callback specified, or there must be an onUnknownRoute callback specified, or the builder property must be specified, because otherwise there is nothing to fall back on if the app is started with an intent that specifies an unknown route."));
        assert((home != nullptr || routes->isNotEmpty() || onGenerateRoute != nullptr || onUnknownRoute != nullptr) || (builder != nullptr && navigatorKey == nullptr && initialRoute == nullptr && navigatorObservers->isEmpty()), __s("If no route is provided using home, routes, onGenerateRoute, or onUnknownRoute, a non-null callback for the builder property must be provided, and the other navigator-related properties, navigatorKey, initialRoute, and navigatorObservers, must have their initial values (null, null, and the empty list, respectively)."));
        assert(builder != nullptr || onGenerateRoute != nullptr || pageRouteBuilder != nullptr, __s("If neither builder nor onGenerateRoute are provided, the pageRouteBuilder must be specified so that the default handler will know what kind of PageRoute transition to build."));
        assert(title != nullptr);
        assert(color != nullptr);
        assert(supportedLocales != nullptr && supportedLocales->isNotEmpty());
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

void WidgetsAppCls::router(Unknown actions, Unknown backButtonDispatcher, Unknown builder, Unknown checkerboardOffscreenLayers, Unknown checkerboardRasterCacheImages, Unknown color, Unknown debugShowCheckedModeBanner, Unknown debugShowWidgetInspector, Unknown inspectorSelectButtonBuilder, Unknown key, Unknown locale, Unknown localeListResolutionCallback, Unknown localeResolutionCallback, Unknown localizationsDelegates, Unknown onGenerateTitle, Unknown restorationScopeId, Unknown routeInformationParser, Unknown routeInformationProvider, Unknown routerConfig, Unknown routerDelegate, Unknown shortcuts, Unknown showPerformanceOverlay, Unknown showSemanticsDebugger, Unknown supportedLocales, Unknown textStyle, Unknown title, Unknown useInheritedMediaQuery)

Map<ShortcutActivator, Intent> WidgetsAppCls::defaultShortcuts() {
    if (kIsWeb) {
        return _defaultWebShortcuts;
    }
    ;
}

State<WidgetsApp> WidgetsAppCls::createState() {
    return make<_WidgetsAppStateCls>();
}

void _WidgetsAppStateCls::initState() {
    super->initState();
    _updateRouting();
    _locale = _resolveLocales(WidgetsBindingCls::instance->platformDispatcher->locales, widget()->supportedLocales);
    WidgetsBindingCls::instance->addObserver(this);
}

void _WidgetsAppStateCls::didUpdateWidget(WidgetsApp oldWidget) {
    super->didUpdateWidget(oldWidget);
    _updateRouting(oldWidget);
}

void _WidgetsAppStateCls::dispose() {
    WidgetsBindingCls::instance->removeObserver(this);
    _defaultRouteInformationProvider?->dispose();
    super->dispose();
}

Future<bool> _WidgetsAppStateCls::didPopRoute() {
    assert(mounted());
    if (_usesRouterWithDelegates()) {
        return false;
    }
    NavigatorState navigator = _navigator?->currentState();
    if (navigator == nullptr) {
        return false;
    }
    return navigator->maybePop();
}

Future<bool> _WidgetsAppStateCls::didPushRoute(String route) {
    assert(mounted());
    if (_usesRouterWithDelegates()) {
        return false;
    }
    NavigatorState navigator = _navigator?->currentState();
    if (navigator == nullptr) {
        return false;
    }
    navigator->pushNamed(route);
    return true;
}

void _WidgetsAppStateCls::didChangeLocales(List<Locale> locales) {
    Locale newLocale = _resolveLocales(locales, widget()->supportedLocales);
    if (newLocale != _locale) {
        setState([=] () {
            _locale = newLocale;
        });
    }
}

Widget _WidgetsAppStateCls::build(BuildContext context) {
    Widget routing;
    if (_usesRouterWithDelegates()) {
        routing = <Object>make<RouterCls>(__s("router"), _effectiveRouteInformationProvider(), widget()->routeInformationParser, widget()->routerDelegate!, _effectiveBackButtonDispatcher());
    } else {
        if (_usesNavigator()) {
        assert(_navigator != nullptr);
        routing = make<NavigatorCls>(__s("nav"), _navigator, _initialRouteName(), _onGenerateRoute, widget()->onGenerateInitialRoutes == nullptr? NavigatorCls::defaultGenerateInitialRoutes : [=] (NavigatorState navigator,String initialRouteName) {
            return widget()->onGenerateInitialRoutes!(initialRouteName);
        }, _onUnknownRoute, widget()->navigatorObservers!, true);
    } else {
        if (_usesRouterWithConfig()) {
        routing = <Object>withConfig(__s("router"), widget()->routerConfig!);
    }
;
    };
    }    Widget result;
    if (widget()->builder != nullptr) {
        result = make<BuilderCls>([=] (BuildContext context) {
            return widget()->builder!(context, routing);
        });
    } else {
        assert(routing != nullptr);
        result = routing!;
    }
    if (widget()->textStyle != nullptr) {
        result = make<DefaultTextStyleCls>(widget()->textStyle!, result);
    }
    PerformanceOverlay performanceOverlay;
    if (widget()->showPerformanceOverlay || WidgetsAppCls::showPerformanceOverlayOverride) {
        performanceOverlay = PerformanceOverlayCls->allEnabled(widget()->checkerboardRasterCacheImages, widget()->checkerboardOffscreenLayers);
    } else {
        if (widget()->checkerboardRasterCacheImages || widget()->checkerboardOffscreenLayers) {
        performanceOverlay = make<PerformanceOverlayCls>(widget()->checkerboardRasterCacheImages, widget()->checkerboardOffscreenLayers);
    }
;
    }    if (performanceOverlay != nullptr) {
        result = make<StackCls>(makeList(ArrayItem, ArrayItem));
    }
    if (widget()->showSemanticsDebugger) {
        result = make<SemanticsDebuggerCls>(result);
    }
    assert([=] () {
        if (widget()->debugShowWidgetInspector || WidgetsAppCls::debugShowWidgetInspectorOverride) {
            result = make<WidgetInspectorCls>(widget()->inspectorSelectButtonBuilder, result);
        }
        if (widget()->debugShowCheckedModeBanner && WidgetsAppCls::debugAllowBannerOverride) {
            result = make<CheckedModeBannerCls>(result);
        }
        return true;
    }());
    Widget title;
    if (widget()->onGenerateTitle != nullptr) {
        title = make<BuilderCls>([=] (BuildContext context) {
            String title = widget()->onGenerateTitle!(context);
            assert(title != nullptr, __s("onGenerateTitle must return a non-null String"));
            return make<TitleCls>(title, widget()->color->withOpacity(1.0), result);
        });
    } else {
        title = make<TitleCls>(widget()->title, widget()->color->withOpacity(1.0), result);
    }
    Locale appLocale = widget()->locale != nullptr? _resolveLocales(makeList(ArrayItem), widget()->supportedLocales) : _locale!;
    assert(_debugCheckLocalizations(appLocale));
    Widget child = make<LocalizationsCls>(appLocale, _localizationsDelegates()->toList(), title);
    MediaQueryData data = MediaQueryCls->maybeOf(context);
    if (!widget()->useInheritedMediaQuery || data == nullptr) {
        child = MediaQueryCls->fromWindow(child);
    }
    return make<RootRestorationScopeCls>(widget()->restorationScopeId, make<SharedAppDataCls>(make<ShortcutsCls>(__s("<Default WidgetsApp Shortcuts>"), widget()->shortcuts | WidgetsAppCls::defaultShortcuts, make<DefaultTextEditingShortcutsCls>(make<ActionsCls>(widget()->actions | WidgetsAppCls::defaultActions, make<FocusTraversalGroupCls>(make<ReadingOrderTraversalPolicyCls>(), make<ShortcutRegistrarCls>(child)))))));
}

String _WidgetsAppStateCls::_initialRouteName() {
    return WidgetsBindingCls::instance->platformDispatcher->defaultRouteName != NavigatorCls::defaultRouteName? WidgetsBindingCls::instance->platformDispatcher->defaultRouteName : widget()->initialRoute | WidgetsBindingCls::instance->platformDispatcher->defaultRouteName;
}

void _WidgetsAppStateCls::_clearRouterResource() {
    _defaultRouteInformationProvider?->dispose();
    _defaultRouteInformationProvider = nullptr;
    _defaultBackButtonDispatcher = nullptr;
}

void _WidgetsAppStateCls::_clearNavigatorResource() {
    _navigator = nullptr;
}

void _WidgetsAppStateCls::_updateRouting(WidgetsApp oldWidget) {
    if (_usesRouterWithDelegates()) {
        assert(!_usesNavigator() && !_usesRouterWithConfig());
        _clearNavigatorResource();
        if (widget()->routeInformationProvider == nullptr && widget()->routeInformationParser != nullptr) {
            _defaultRouteInformationProvider |= make<PlatformRouteInformationProviderCls>(make<RouteInformationCls>(_initialRouteName()));
        } else {
            _defaultRouteInformationProvider?->dispose();
            _defaultRouteInformationProvider = nullptr;
        }
        if (widget()->backButtonDispatcher == nullptr) {
            _defaultBackButtonDispatcher |= make<RootBackButtonDispatcherCls>();
        }
    } else {
        if (_usesNavigator()) {
        assert(!_usesRouterWithDelegates() && !_usesRouterWithConfig());
        _clearRouterResource();
        if (_navigator == nullptr || widget()->navigatorKey != oldWidget!->navigatorKey) {
            _navigator = widget()->navigatorKey | <NavigatorState>make<GlobalObjectKeyCls>(this);
        }
        assert(_navigator != nullptr);
    } else {
        assert(widget()->builder != nullptr || _usesRouterWithConfig());
        assert(!_usesRouterWithDelegates() && !_usesNavigator());
        _clearRouterResource();
        _clearNavigatorResource();
    }
;
    }    assert(_usesNavigator() == (_navigator != nullptr));
}

bool _WidgetsAppStateCls::_usesRouterWithDelegates() {
    return widget()->routerDelegate != nullptr;
}

bool _WidgetsAppStateCls::_usesRouterWithConfig() {
    return widget()->routerConfig != nullptr;
}

bool _WidgetsAppStateCls::_usesNavigator() {
    return widget()->home != nullptr || (widget()->routes?->isNotEmpty | false) || widget()->onGenerateRoute != nullptr || widget()->onUnknownRoute != nullptr;
}

RouteInformationProvider _WidgetsAppStateCls::_effectiveRouteInformationProvider() {
    return widget()->routeInformationProvider | _defaultRouteInformationProvider;
}

BackButtonDispatcher _WidgetsAppStateCls::_effectiveBackButtonDispatcher() {
    return widget()->backButtonDispatcher | _defaultBackButtonDispatcher!;
}

Route<Object> _WidgetsAppStateCls::_onGenerateRoute(RouteSettings settings) {
    String name = settings->name;
    WidgetBuilder pageContentBuilder = name == NavigatorCls::defaultRouteName && widget()->home != nullptr? [=] (BuildContext context) {
    widget()->home!;
} : widget()->routes![name];
    if (pageContentBuilder != nullptr) {
        assert(widget()->pageRouteBuilder != nullptr, __s("The default onGenerateRoute handler for WidgetsApp must have a pageRouteBuilder set if the home or routes properties are set."));
        Route<Object> route = widget()->pageRouteBuilder;
        assert(route != nullptr, __s("The pageRouteBuilder for WidgetsApp must return a valid non-null Route."));
        return route;
    }
    if (widget()->onGenerateRoute != nullptr) {
        return widget()->onGenerateRoute!(settings);
    }
    return nullptr;
}

Route<Object> _WidgetsAppStateCls::_onUnknownRoute(RouteSettings settings) {
    assert([=] () {
        if (widget()->onUnknownRoute == nullptr) {
            throw make<FlutterErrorCls>(__sf("Could not find a generator for route %s in the %s.\nMake sure your root app widget has provided a way to generate \nthis route.\nGenerators for routes are searched for in the following order:\n 1. For the "/" route, the "home" property, if non-null, is used.\n 2. Otherwise, the "routes" table is used, if it has an entry for the route.\n 3. Otherwise, onGenerateRoute is called. It should return a non-null value for any valid route not handled by "home" and "routes".\n 4. Finally if all else fails onUnknownRoute is called.\nUnfortunately, onUnknownRoute was not set.", settings, runtimeType));
        }
        return true;
    }());
    Route<Object> result = widget()->onUnknownRoute!(settings);
    assert([=] () {
        if (result == nullptr) {
            throw make<FlutterErrorCls>(__sf("The onUnknownRoute callback returned null.\nWhen the %s requested the route %s from its onUnknownRoute callback, the callback returned null. Such callbacks must never return null.", runtimeType, settings));
        }
        return true;
    }());
    return result!;
}

Locale _WidgetsAppStateCls::_resolveLocales(List<Locale> preferredLocales, Iterable<Locale> supportedLocales) {
    if (widget()->localeListResolutionCallback != nullptr) {
        Locale locale = widget()->localeListResolutionCallback!(preferredLocales, widget()->supportedLocales);
        if (locale != nullptr) {
            return locale;
        }
    }
    if (widget()->localeResolutionCallback != nullptr) {
        Locale locale = widget()->localeResolutionCallback!(preferredLocales != nullptr && preferredLocales->isNotEmpty()? preferredLocales->first : nullptr, widget()->supportedLocales);
        if (locale != nullptr) {
            return locale;
        }
    }
    return basicLocaleListResolution(preferredLocales, supportedLocales);
}

Iterable<LocalizationsDelegate<Object>> _WidgetsAppStateCls::_localizationsDelegates() {
    List<LocalizationsDelegate<Object>> list1 = make<ListCls<>>();if (widget()->localizationsDelegates != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);return list1;
}

bool _WidgetsAppStateCls::_debugCheckLocalizations(Locale appLocale) {
    assert([=] () {
        Set<Type> unsupportedTypes = _localizationsDelegates()-><Type>map([=] (LocalizationsDelegate<Object> delegate) {
    delegate->type;
})->toSet();
        for (LocalizationsDelegate<Object> delegate : _localizationsDelegates()) {
            if (!unsupportedTypes->contains(delegate->type)) {
                continue;
            }
            if (delegate->isSupported(appLocale)) {
                unsupportedTypes->remove(delegate->type);
            }
        }
        if (unsupportedTypes->isEmpty()) {
            return true;
        }
            List<DiagnosticsNode> list1 = make<ListCls<>>();    for (Type unsupportedType : unsupportedTypes) {                ;            }    {        list1.add(ArrayItem);    }list1.add(ArrayItem);    if (unsupportedTypes->length() == 1 && unsupportedTypes->single()->toString() == __s("CupertinoLocalizations")) {        list1.add(ArrayItem);    }list1.add(ArrayItem);    list1.add(ArrayItem);    list1.add(ArrayItem);FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(__sf("Warning: This application's locale, %s, is not supported by all of its localization delegates.", appLocale), __s("widgets"), [=] () {
            list1;
        }));
        return true;
    }());
    return true;
}
