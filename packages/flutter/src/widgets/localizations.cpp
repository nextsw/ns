#include "localizations.hpp"
Future<Map<Type, dynamic>> _loadAll(Iterable<LocalizationsDelegate<dynamic>> allDelegates, Locale locale) {
    Map<Type, dynamic> output = ;
    List<_Pending> pendingList;
    Set<Type> types = ;
    List<LocalizationsDelegate<dynamic>> delegates = ;
    for (LocalizationsDelegate<dynamic> delegate : allDelegates) {
        if (!types.contains(delegate.type) && delegate.isSupported(locale)) {
            types.add(delegate.type);
            delegates.add(delegate);
        }
    }
    for (LocalizationsDelegate<dynamic> delegate : delegates) {
        Future<dynamic> inputValue = delegate.load(locale);
        dynamic completedValue;
        Future<dynamic> futureValue = inputValue.<dynamic>then();
        if (completedValue != nullptr) {
            Type type = delegate.type;
            assert(!output.containsKey(type));
            output[type] = completedValue;
        } else {
            pendingList = ;
            pendingList.add(_Pending(delegate, futureValue));
        }
    }
    if (pendingList == nullptr) {
        return <Map<Type, dynamic>>SynchronousFuture(output);
    }
    return Future.<dynamic>wait(pendingList.<Future<dynamic>>map()).<Map<Type, dynamic>>then();
}

Type LocalizationsDelegate::type() {
    return T;
}

String LocalizationsDelegate::toString() {
    return "${objectRuntimeType(this, 'LocalizationsDelegate')}[$type]";
}

WidgetsLocalizations WidgetsLocalizations::of(BuildContext context) {
    assert(debugCheckHasWidgetsLocalizations(context));
    return Localizations.<WidgetsLocalizations>of(context, WidgetsLocalizations)!;
}

bool _WidgetsLocalizationsDelegate::isSupported(Locale locale) {
    return true;
}

Future<WidgetsLocalizations> _WidgetsLocalizationsDelegate::load(Locale locale) {
    return DefaultWidgetsLocalizations.load(locale);
}

bool _WidgetsLocalizationsDelegate::shouldReload(_WidgetsLocalizationsDelegate old) {
    return false;
}

String _WidgetsLocalizationsDelegate::toString() {
    return "DefaultWidgetsLocalizations.delegate(en_US)";
}

TextDirection DefaultWidgetsLocalizations::textDirection() {
    return TextDirection.ltr;
}

Future<WidgetsLocalizations> DefaultWidgetsLocalizations::load(Locale locale) {
    return <WidgetsLocalizations>SynchronousFuture(const DefaultWidgetsLocalizations());
}

bool _LocalizationsScope::updateShouldNotify(_LocalizationsScope old) {
    return typeToResources != old.typeToResources;
}

_LocalizationsScope::_LocalizationsScope(Unknown, Unknown, Locale locale, _LocalizationsState localizationsState, Map<Type, dynamic> typeToResources) {
    {
        assert(localizationsState != nullptr);
        assert(typeToResources != nullptr);
    }
}

Localizations::Localizations(Widget child, List<LocalizationsDelegate<dynamic>> delegates, Unknown, Locale locale) {
    {
        assert(locale != nullptr);
        assert(delegates != nullptr);
        assert(delegates.any());
    }
}

void Localizations::override(Widget child, BuildContext context, List<LocalizationsDelegate<dynamic>> delegates, Key key, Locale locale) {
    List<LocalizationsDelegate<dynamic>> mergedDelegates = Localizations._delegatesOf(context);
    if (delegates != nullptr) {
        mergedDelegates.insertAll(0, delegates);
    }
    return Localizations(key, locale ?? Localizations.localeOf(context), mergedDelegates, child);
}

Locale Localizations::localeOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context.<_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    assert(());
    return scope!.localizationsState.locale!;
}

Locale Localizations::maybeLocaleOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context.<_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    return scope?.localizationsState.locale;
}

T Localizations::of<T>(BuildContext context, Type type) {
    assert(context != nullptr);
    assert(type != nullptr);
    _LocalizationsScope scope = context.<_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    return scope?.localizationsState.<T>resourcesFor(type);
}

State<Localizations> Localizations::createState() {
    return _LocalizationsState();
}

void Localizations::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Locale>DiagnosticsProperty("locale", locale));
    properties.add(<LocalizationsDelegate<dynamic>>IterableProperty("delegates", delegates));
}

List<LocalizationsDelegate<dynamic>> Localizations::_delegatesOf(BuildContext context) {
    assert(context != nullptr);
    _LocalizationsScope scope = context.<_LocalizationsScope>dependOnInheritedWidgetOfExactType();
    assert(scope != nullptr, "a Localizations ancestor was not found");
    return <LocalizationsDelegate<dynamic>>of(scope!.localizationsState.widget.delegates);
}

Locale _LocalizationsState::locale() {
    return _locale;
}

void _LocalizationsState::initState() {
    super.initState();
    load(widget.locale);
}

void _LocalizationsState::didUpdateWidget(Localizations old) {
    super.didUpdateWidget(old);
    if (widget.locale != old.locale || (widget.delegates == nullptr) || (widget.delegates != nullptr && old.delegates == nullptr) || (widget.delegates != nullptr && _anyDelegatesShouldReload(old))) {
        load(widget.locale);
    }
}

void _LocalizationsState::load(Locale locale) {
    Iterable<LocalizationsDelegate<dynamic>> delegates = widget.delegates;
    if (delegates == nullptr || delegates.isEmpty) {
        _locale = locale;
        return;
    }
    Map<Type, dynamic> typeToResources;
    Future<Map<Type, dynamic>> typeToResourcesFuture = _loadAll(locale, delegates).<Map<Type, dynamic>>then();
    if (typeToResources != nullptr) {
        _typeToResources = typeToResources!;
        _locale = locale;
    } else {
        RendererBinding.instance.deferFirstFrame();
        typeToResourcesFuture.<void>then();
    }
}

T _LocalizationsState::resourcesFor<T>(Type type) {
    assert(type != nullptr);
    T resources = (;
    return resources;
}

Widget _LocalizationsState::build(BuildContext context) {
    if (_locale == nullptr) {
        return Container();
    }
    return Semantics(_textDirection, _LocalizationsScope(_localizedResourcesScopeKey, _locale!, this, _typeToResources, Directionality(_textDirection, widget.child!)));
}

bool _LocalizationsState::_anyDelegatesShouldReload(Localizations old) {
    if (widget.delegates.length != old.delegates.length) {
        return true;
    }
    List<LocalizationsDelegate<dynamic>> delegates = widget.delegates.toList();
    List<LocalizationsDelegate<dynamic>> oldDelegates = old.delegates.toList();
    for (;  < delegates.length; i = 1) {
        LocalizationsDelegate<dynamic> delegate = delegates[i];
        LocalizationsDelegate<dynamic> oldDelegate = oldDelegates[i];
        if (delegate.runtimeType != oldDelegate.runtimeType || delegate.shouldReload(oldDelegate)) {
            return true;
        }
    }
    return false;
}

TextDirection _LocalizationsState::_textDirection() {
    WidgetsLocalizations resources = (;
    assert(resources != nullptr);
    return resources.textDirection;
}
