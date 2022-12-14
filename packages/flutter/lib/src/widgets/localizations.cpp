#include "localizations.hpp"
Future<Map<Type, Object>> _loadAll(Locale locale, Iterable<LocalizationsDelegate<Object>> allDelegates) {
    Map<Type, Object> output = makeMap(makeList(), makeList();
    List<_Pending> pendingList;
    Set<Type> types = makeSet();
    List<LocalizationsDelegate<Object>> delegates = makeList();
    for (LocalizationsDelegate<Object> delegate : allDelegates) {
        if (!types->contains(delegate->type) && delegate->isSupported(locale)) {
            types->add(delegate->type);
            delegates->add(delegate);
        }
    }
    for (LocalizationsDelegate<Object> delegate : delegates) {
        Future<Object> inputValue = delegate->load(locale);
        Object completedValue;
        Future<Object> futureValue = inputValue-><Object>then([=] (Object value) {
    return completedValue = value;
});
        if (completedValue != nullptr) {
            Type type = delegate->type;
            assert(!output->containsKey(type));
            output[type] = completedValue;
        } else {
            pendingList |= makeList();
            pendingList->add(make<_PendingCls>(delegate, futureValue));
        }
    }
    if (pendingList == nullptr) {
        return <Map<Type, Object>>make<SynchronousFutureCls>(output);
    }
    return FutureCls-><Object>wait(pendingList-><Future<Object>>map([=] (_Pending p) {
        p->futureValue;
    }))-><Map<Type, Object>>then([=] (List<Object> values) {
        assert(values->length == pendingList!->length());
        for (;  < values->length; i += 1) {
            Type type = pendingList![i]->delegate->type();
            assert(!output->containsKey(type));
            output[type] = values[i];
        }
        return output;
    });
}

template<typename T>
Type LocalizationsDelegateCls<T>::type() {
    return T;
}

template<typename T>
String LocalizationsDelegateCls<T>::toString() {
    return __sf("%s[%s]", objectRuntimeType(this, __s("LocalizationsDelegate")), type());
}

WidgetsLocalizations WidgetsLocalizationsCls::of(BuildContext context) {
    assert(debugCheckHasWidgetsLocalizations(context));
    return LocalizationsCls-><WidgetsLocalizations>of(context, WidgetsLocalizationsCls)!;
}

bool _WidgetsLocalizationsDelegateCls::isSupported(Locale locale) {
    return true;
}

Future<WidgetsLocalizations> _WidgetsLocalizationsDelegateCls::load(Locale locale) {
    return DefaultWidgetsLocalizationsCls->load(locale);
}

bool _WidgetsLocalizationsDelegateCls::shouldReload(_WidgetsLocalizationsDelegate old) {
    return false;
}

String _WidgetsLocalizationsDelegateCls::toString() {
    return __s("DefaultWidgetsLocalizations.delegate(en_US)");
}

TextDirection DefaultWidgetsLocalizationsCls::textDirection() {
    return TextDirectionCls::ltr;
}

Future<WidgetsLocalizations> DefaultWidgetsLocalizationsCls::load(Locale locale) {
    return <WidgetsLocalizations>make<SynchronousFutureCls>(make<DefaultWidgetsLocalizationsCls>());
}

bool _LocalizationsScopeCls::updateShouldNotify(_LocalizationsScope old) {
    return typeToResources != old->typeToResources;
}

_LocalizationsScopeCls::_LocalizationsScopeCls(Widget child, Key key, Locale locale, _LocalizationsState localizationsState, Map<Type, Object> typeToResources) {
    {
        assert(localizationsState != nullptr);
        assert(typeToResources != nullptr);
    }
}

LocalizationsCls::LocalizationsCls(Widget child, List<LocalizationsDelegate<Object>> delegates, Key key, Locale locale) {
    {
        assert(locale != nullptr);
        assert(delegates != nullptr);
        assert(delegates->any([=] (LocalizationsDelegate<Object> delegate) {
            is<LocalizationsDelegate<WidgetsLocalizations>>(delegate);
        }));
    }
}

void LocalizationsCls::override(Widget child, BuildContext context, List<LocalizationsDelegate<Object>> delegates, Key key, Locale locale) {
    List<LocalizationsDelegate<Object>> mergedDelegates = LocalizationsCls->_delegatesOf(context);
    if (delegates != nullptr) {
        mergedDelegates->insertAll(0, delegates);
    }
    return make<LocalizationsCls>(key, locale | LocalizationsCls->localeOf(context), mergedDelegates, child);
}

Locale LocalizationsCls::localeOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context-><_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    assert([=] () {
        if (scope == nullptr) {
            throw make<FlutterErrorCls>(__s("Requested the Locale of a context that does not include a Localizations ancestor.\nTo request the Locale, the context used to retrieve the Localizations widget must be that of a widget that is a descendant of a Localizations widget."));
        }
        if (scope->localizationsState->locale() == nullptr) {
            throw make<FlutterErrorCls>(__s("Localizations.localeOf found a Localizations widget that had a unexpected null locale.\n"));
        }
        return true;
    }());
    return scope!->localizationsState->locale()!;
}

Locale LocalizationsCls::maybeLocaleOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context-><_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    return scope?->localizationsState->locale();
}

template<typename T>
T LocalizationsCls::of(BuildContext context, Type type) {
    assert(context != nullptr);
    assert(type != nullptr);
    _LocalizationsScope scope = context-><_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    return scope?->localizationsState-><T>resourcesFor(type);
}

State<Localizations> LocalizationsCls::createState() {
    return make<_LocalizationsStateCls>();
}

void LocalizationsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), locale));
    properties->add(<LocalizationsDelegate<Object>>make<IterablePropertyCls>(__s("delegates"), delegates));
}

List<LocalizationsDelegate<Object>> LocalizationsCls::_delegatesOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context-><_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    assert(scope != nullptr, __s("a Localizations ancestor was not found"));
    return <LocalizationsDelegate<Object>>of(scope!->localizationsState->widget()->delegates);
}

Locale _LocalizationsStateCls::locale() {
    return _locale;
}

void _LocalizationsStateCls::initState() {
    super->initState();
    load(widget()->locale());
}

void _LocalizationsStateCls::didUpdateWidget(Localizations old) {
    super->didUpdateWidget(old);
    if (widget()->locale() != old->locale || (widget()->delegates == nullptr) || (widget()->delegates != nullptr && old->delegates == nullptr) || (widget()->delegates != nullptr && _anyDelegatesShouldReload(old))) {
        load(widget()->locale());
    }
}

void _LocalizationsStateCls::load(Locale locale) {
    Iterable<LocalizationsDelegate<Object>> delegates = widget()->delegates;
    if (delegates == nullptr || delegates->isEmpty()) {
        _locale = locale;
        return;
    }
    Map<Type, Object> typeToResources;
    Future<Map<Type, Object>> typeToResourcesFuture = _loadAll(locale, delegates)-><Map<Type, Object>>then([=] (Map<Type, Object> value) {
    return typeToResources = value;
});
    if (typeToResources != nullptr) {
        _typeToResources = typeToResources!;
        _locale = locale;
    } else {
        RendererBindingCls::instance->deferFirstFrame();
        typeToResourcesFuture-><void>then([=] (Map<Type, Object> value) {
            if (mounted()) {
                setState([=] () {
                    _typeToResources = value;
                    _locale = locale;
                });
            }
            RendererBindingCls::instance->allowFirstFrame();
        });
    }
}

template<typename T>
T _LocalizationsStateCls::resourcesFor(Type type) {
    assert(type != nullptr);
    T resources = as<T>(_typeToResources[type]);
    return resources;
}

Widget _LocalizationsStateCls::build(BuildContext context) {
    if (_locale == nullptr) {
        return make<ContainerCls>();
    }
    return make<SemanticsCls>(_textDirection(), make<_LocalizationsScopeCls>(_localizedResourcesScopeKey, _locale!, this, _typeToResources, make<DirectionalityCls>(_textDirection(), widget()->child!)));
}

bool _LocalizationsStateCls::_anyDelegatesShouldReload(Localizations old) {
    if (widget()->delegates->length != old->delegates->length()) {
        return true;
    }
    List<LocalizationsDelegate<Object>> delegates = widget()->delegates->toList();
    List<LocalizationsDelegate<Object>> oldDelegates = old->delegates->toList();
    for (;  < delegates->length(); i += 1) {
        LocalizationsDelegate<Object> delegate = delegates[i];
        LocalizationsDelegate<Object> oldDelegate = oldDelegates[i];
        if (delegate->runtimeType != oldDelegate->runtimeType || delegate->shouldReload(oldDelegate)) {
            return true;
        }
    }
    return false;
}

TextDirection _LocalizationsStateCls::_textDirection() {
    WidgetsLocalizations resources = as<WidgetsLocalizations>(_typeToResources[WidgetsLocalizationsCls]);
    assert(resources != nullptr);
    return resources->textDirection();
}
