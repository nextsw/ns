#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHORTCUTS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHORTCUTS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "platform_menu_bar.hpp"


template<typename T>
class KeySetCls : public ObjectCls {
public:
    int hashCode;


     KeySetCls(T key1, T key2, T key3, T key4);

    virtual void  fromSet(Set<T> keys);

    virtual Set<T> keys();

    virtual bool operator==(Object other);

private:
    HashSet<T> _keys;

    static List<int> _tempHashStore3;

    static List<int> _tempHashStore4;


    template<typename T>
 static int _computeHashCode(Set<T> keys);

};
template<typename T>
using KeySet = std::shared_ptr<KeySetCls<T>>;

class ShortcutActivatorCls : public ObjectCls {
public:

     ShortcutActivatorCls();
    virtual Iterable<LogicalKeyboardKey> triggers();
    virtual bool accepts(RawKeyEvent event, RawKeyboard state);
    static bool isActivatedBy(ShortcutActivator activator, RawKeyEvent event);

    virtual String debugDescribeKeys();
private:

};
using ShortcutActivator = std::shared_ptr<ShortcutActivatorCls>;

class LogicalKeySetCls : public KeySetCls<LogicalKeyboardKey> {
public:

     LogicalKeySetCls(Unknown key1, Unknown key2, Unknown key3, Unknown key4);
    virtual void  fromSet(Unknown keys);

    virtual Iterable<LogicalKeyboardKey> triggers();

    virtual bool accepts(RawKeyEvent event, RawKeyboard state);

    virtual String debugDescribeKeys();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<LogicalKeyboardKey> _triggers;

    static Set<LogicalKeyboardKey> _modifiers;

    static Map<LogicalKeyboardKey, List<LogicalKeyboardKey>> _unmapSynonyms;


};
using LogicalKeySet = std::shared_ptr<LogicalKeySetCls>;

class ShortcutMapPropertyCls : public DiagnosticsPropertyCls<Map<ShortcutActivator, Intent>> {
public:

     ShortcutMapPropertyCls(String name, Map<ShortcutActivator, Intent> value, Object defaultValue, Unknown description, Unknown level, bool showName);

    virtual Map<ShortcutActivator, Intent> value();

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
using ShortcutMapProperty = std::shared_ptr<ShortcutMapPropertyCls>;

class SingleActivatorCls : public ObjectCls {
public:
    LogicalKeyboardKey trigger;

    bool control;

    bool shift;

    bool alt;

    bool meta;

    bool includeRepeats;


     SingleActivatorCls(LogicalKeyboardKey trigger, bool alt, bool control, bool includeRepeats, bool meta, bool shift);

    virtual Iterable<LogicalKeyboardKey> triggers();

    virtual bool accepts(RawKeyEvent event, RawKeyboard state);

    virtual ShortcutSerialization serializeForMenu();

    virtual String debugDescribeKeys();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SingleActivator = std::shared_ptr<SingleActivatorCls>;

class CharacterActivatorCls : public ObjectCls {
public:
    String character;


     CharacterActivatorCls(String character);
    virtual Iterable<LogicalKeyboardKey> triggers();

    virtual bool accepts(RawKeyEvent event, RawKeyboard state);

    virtual String debugDescribeKeys();

    virtual ShortcutSerialization serializeForMenu();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using CharacterActivator = std::shared_ptr<CharacterActivatorCls>;

class _ActivatorIntentPairCls : public ObjectCls {
public:
    ShortcutActivator activator;

    Intent intent;


    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _ActivatorIntentPairCls(ShortcutActivator activator, Intent intent);
};
using _ActivatorIntentPair = std::shared_ptr<_ActivatorIntentPairCls>;

class ShortcutManagerCls : public ObjectCls {
public:
    bool modal;


     ShortcutManagerCls(bool modal, Map<ShortcutActivator, Intent> shortcuts);

    virtual Map<ShortcutActivator, Intent> shortcuts();

    virtual void  shortcuts(Map<ShortcutActivator, Intent> value);

    virtual KeyEventResult handleKeypress(BuildContext context, RawKeyEvent event);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<ShortcutActivator, Intent> _shortcuts;

    Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> _indexedShortcutsCache;


    static Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> _indexShortcuts(Map<ShortcutActivator, Intent> source);

    virtual Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> _indexedShortcuts();

    virtual Intent _find(RawKeyEvent event, RawKeyboard state);

};
using ShortcutManager = std::shared_ptr<ShortcutManagerCls>;

class ShortcutsCls : public StatefulWidgetCls {
public:
    ShortcutManager manager;

    Widget child;

    String debugLabel;


     ShortcutsCls(Widget child, String debugLabel, Key key, Map<ShortcutActivator, Intent> shortcuts);

    virtual void  manager(Widget child, String debugLabel, Key key, ShortcutManager manager);

    virtual Map<ShortcutActivator, Intent> shortcuts();

    virtual State<Shortcuts> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<ShortcutActivator, Intent> _shortcuts;


};
using Shortcuts = std::shared_ptr<ShortcutsCls>;

class _ShortcutsStateCls : public StateCls<Shortcuts> {
public:

    virtual ShortcutManager manager();

    virtual void dispose();

    virtual void initState();

    virtual void didUpdateWidget(Shortcuts oldWidget);

    virtual Widget build(BuildContext context);

private:
    ShortcutManager _internalManager;


    virtual KeyEventResult _handleOnKey(FocusNode node, RawKeyEvent event);

};
using _ShortcutsState = std::shared_ptr<_ShortcutsStateCls>;

class CallbackShortcutsCls : public StatelessWidgetCls {
public:
    Map<ShortcutActivator, VoidCallback> bindings;

    Widget child;


     CallbackShortcutsCls(Map<ShortcutActivator, VoidCallback> bindings, Widget child, Key key);
    virtual Widget build(BuildContext context);

private:

    virtual bool _applyKeyBinding(ShortcutActivator activator, RawKeyEvent event);

};
using CallbackShortcuts = std::shared_ptr<CallbackShortcutsCls>;

class ShortcutRegistryEntryCls : public ObjectCls {
public:
    ShortcutRegistry registry;


    virtual void replaceAll(Map<ShortcutActivator, Intent> value);

    virtual void dispose();

private:

    virtual void  _(ShortcutRegistry registry);
};
using ShortcutRegistryEntry = std::shared_ptr<ShortcutRegistryEntryCls>;

class ShortcutRegistryCls : public ObjectCls {
public:

    virtual Map<ShortcutActivator, Intent> shortcuts();

    virtual ShortcutRegistryEntry addAll(Map<ShortcutActivator, Intent> value);

    static ShortcutRegistry of(BuildContext context);

    static ShortcutRegistry maybeOf(BuildContext context);

private:
    Map<ShortcutRegistryEntry, Map<ShortcutActivator, Intent>> _tokenShortcuts;


    virtual void _replaceAll(ShortcutRegistryEntry entry, Map<ShortcutActivator, Intent> value);

    virtual void _disposeToken(ShortcutRegistryEntry entry);

    virtual bool _debugCheckTokenIsValid(ShortcutRegistryEntry entry);

    virtual bool _debugCheckForDuplicates();

};
using ShortcutRegistry = std::shared_ptr<ShortcutRegistryCls>;

class ShortcutRegistrarCls : public StatefulWidgetCls {
public:
    Widget child;


     ShortcutRegistrarCls(Widget child, Key key);
    virtual State<ShortcutRegistrar> createState();

private:

};
using ShortcutRegistrar = std::shared_ptr<ShortcutRegistrarCls>;

class _ShortcutRegistrarStateCls : public StateCls<ShortcutRegistrar> {
public:
    ShortcutRegistry registry;

    ShortcutManager manager;


    virtual void initState();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _shortcutsChanged();

};
using _ShortcutRegistrarState = std::shared_ptr<_ShortcutRegistrarStateCls>;

class _ShortcutRegistrarMarkerCls : public InheritedWidgetCls {
public:
    ShortcutRegistry registry;


    virtual bool updateShouldNotify(_ShortcutRegistrarMarker oldWidget);

private:

     _ShortcutRegistrarMarkerCls(Widget child, ShortcutRegistry registry);
};
using _ShortcutRegistrarMarker = std::shared_ptr<_ShortcutRegistrarMarkerCls>;


#endif