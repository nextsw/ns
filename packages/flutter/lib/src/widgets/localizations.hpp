#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LOCALIZATIONS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LOCALIZATIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "container.hpp"
#include "debug.hpp"
#include "framework.hpp"


class _PendingCls : public ObjectCls {
public:
    LocalizationsDelegate<dynamic> delegate;

    Future<dynamic> futureValue;


private:

     _PendingCls(LocalizationsDelegate<dynamic> delegate, Future<dynamic> futureValue);
};
using _Pending = std::shared_ptr<_PendingCls>;
Future<Map<Type, dynamic>> _loadAll(Locale locale, Iterable<LocalizationsDelegate<dynamic>> allDelegates);


template<typename T>
class LocalizationsDelegateCls : public ObjectCls {
public:

     LocalizationsDelegateCls();
    virtual bool isSupported(Locale locale);
    virtual Future<T> load(Locale locale);
    virtual bool shouldReload(LocalizationsDelegate<T> old);
    virtual Type type();

    virtual String toString();

private:

};
template<typename T>
using LocalizationsDelegate = std::shared_ptr<LocalizationsDelegateCls<T>>;

class WidgetsLocalizationsCls : public ObjectCls {
public:

    virtual TextDirection textDirection();
    static WidgetsLocalizations of(BuildContext context);

private:

};
using WidgetsLocalizations = std::shared_ptr<WidgetsLocalizationsCls>;

class _WidgetsLocalizationsDelegateCls : public LocalizationsDelegateCls<WidgetsLocalizations> {
public:

    virtual bool isSupported(Locale locale);

    virtual Future<WidgetsLocalizations> load(Locale locale);

    virtual bool shouldReload(_WidgetsLocalizationsDelegate old);

    virtual String toString();

private:

     _WidgetsLocalizationsDelegateCls();
};
using _WidgetsLocalizationsDelegate = std::shared_ptr<_WidgetsLocalizationsDelegateCls>;

class DefaultWidgetsLocalizationsCls : public ObjectCls {
public:
    static LocalizationsDelegate<WidgetsLocalizations> delegate;


     DefaultWidgetsLocalizationsCls();
    virtual TextDirection textDirection();

    static Future<WidgetsLocalizations> load(Locale locale);

private:

};
using DefaultWidgetsLocalizations = std::shared_ptr<DefaultWidgetsLocalizationsCls>;

class _LocalizationsScopeCls : public InheritedWidgetCls {
public:
    Locale locale;

    _LocalizationsState localizationsState;

    Map<Type, dynamic> typeToResources;


    virtual bool updateShouldNotify(_LocalizationsScope old);

private:

     _LocalizationsScopeCls(Widget child, Key key, Locale locale, _LocalizationsState localizationsState, Map<Type, dynamic> typeToResources);

};
using _LocalizationsScope = std::shared_ptr<_LocalizationsScopeCls>;

class LocalizationsCls : public StatefulWidgetCls {
public:
    Locale locale;

    List<LocalizationsDelegate<dynamic>> delegates;

    Widget child;


     LocalizationsCls(Widget child, List<LocalizationsDelegate<dynamic>> delegates, Key key, Locale locale);

    virtual void  override(Widget child, BuildContext context, List<LocalizationsDelegate<dynamic>> delegates, Key key, Locale locale);

    static Locale localeOf(BuildContext context);

    static Locale maybeLocaleOf(BuildContext context);

    template<typename T>
 static T of(BuildContext context, Type type);

    virtual State<Localizations> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static List<LocalizationsDelegate<dynamic>> _delegatesOf(BuildContext context);

};
using Localizations = std::shared_ptr<LocalizationsCls>;

class _LocalizationsStateCls : public StateCls<Localizations> {
public:

    virtual Locale locale();

    virtual void initState();

    virtual void didUpdateWidget(Localizations old);

    virtual void load(Locale locale);

    template<typename T>
 virtual T resourcesFor(Type type);

    virtual Widget build(BuildContext context);

private:
    GlobalKey _localizedResourcesScopeKey;

    Map<Type, dynamic> _typeToResources;

    Locale _locale;


    virtual bool _anyDelegatesShouldReload(Localizations old);

    virtual TextDirection _textDirection();

};
using _LocalizationsState = std::shared_ptr<_LocalizationsStateCls>;


#endif