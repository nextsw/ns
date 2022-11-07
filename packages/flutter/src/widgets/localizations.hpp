#ifndef LOCALIZATIONS_H
#define LOCALIZATIONS_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "debug.hpp"
#include "framework.hpp"



class _Pending {
public:
    LocalizationsDelegate<dynamic> delegate;

    Future<dynamic> futureValue;


private:

     _Pending(LocalizationsDelegate<dynamic> delegate, Future<dynamic> futureValue);

};
Future<Map<Type, dynamic>> _loadAll(Iterable<LocalizationsDelegate<dynamic>> allDelegates, Locale locale);


class LocalizationsDelegate<T> {
public:

     LocalizationsDelegate();

    bool isSupported(Locale locale);

    Future<T> load(Locale locale);

    bool shouldReload(LocalizationsDelegate<T> old);

    Type type();

    String toString();

private:

};

class WidgetsLocalizations {
public:

    TextDirection textDirection();

    static WidgetsLocalizations of(BuildContext context);

private:

};

class _WidgetsLocalizationsDelegate : LocalizationsDelegate<WidgetsLocalizations> {
public:

    bool isSupported(Locale locale);

    Future<WidgetsLocalizations> load(Locale locale);

    bool shouldReload(_WidgetsLocalizationsDelegate old);

    String toString();

private:

     _WidgetsLocalizationsDelegate();

};

class DefaultWidgetsLocalizations {
public:
    static const LocalizationsDelegate<WidgetsLocalizations> delegate;


     DefaultWidgetsLocalizations();

    TextDirection textDirection();

    static Future<WidgetsLocalizations> load(Locale locale);

private:

};

class _LocalizationsScope : InheritedWidget {
public:
    Locale locale;

    _LocalizationsState localizationsState;

    Map<Type, dynamic> typeToResources;


    bool updateShouldNotify(_LocalizationsScope old);

private:

     _LocalizationsScope(Unknown, Unknown, Locale locale, _LocalizationsState localizationsState, Map<Type, dynamic> typeToResources);

};

class Localizations : StatefulWidget {
public:
    Locale locale;

    List<LocalizationsDelegate<dynamic>> delegates;

    Widget child;


     Localizations(Widget child, List<LocalizationsDelegate<dynamic>> delegates, Unknown, Locale locale);

    void  override(Widget child, BuildContext context, List<LocalizationsDelegate<dynamic>> delegates, Key key, Locale locale);

    static Locale localeOf(BuildContext context);

    static Locale maybeLocaleOf(BuildContext context);

    static T of<T>(BuildContext context, Type type);

    State<Localizations> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static List<LocalizationsDelegate<dynamic>> _delegatesOf(BuildContext context);

};

class _LocalizationsState : State<Localizations> {
public:

    Locale locale();

    void initState();

    void didUpdateWidget(Localizations old);

    void load(Locale locale);

    T resourcesFor<T>(Type type);

    Widget build(BuildContext context);

private:
    GlobalKey _localizedResourcesScopeKey;

    Map<Type, dynamic> _typeToResources;

    Locale _locale;


    bool _anyDelegatesShouldReload(Localizations old);

    TextDirection _textDirection();

};

#endif