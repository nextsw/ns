#ifndef PLATFORM_MENU_BAR_H
#define PLATFORM_MENU_BAR_H
#include <memory>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "shortcuts.hpp"


const String _kMenuSetMethod;

const String _kMenuSelectedCallbackMethod;

const String _kMenuItemOpenedMethod;

const String _kMenuItemClosedMethod;

const String _kIdKey;

const String _kLabelKey;

const String _kEnabledKey;

const String _kChildrenKey;

const String _kIsDividerKey;

const String _kPlatformDefaultMenuKey;

const String _kShortcutCharacter;

const String _kShortcutTrigger;

const String _kShortcutModifiers;


class ShortcutSerialization {
public:

    void  character(String character);

    void  modifier(bool alt, bool control, bool meta, bool shift, LogicalKeyboardKey trigger);

    LogicalKeyboardKey trigger();

    String character();

    bool control();

    bool shift();

    bool alt();

    bool meta();

    Map<String, Object> toChannelRepresentation();

private:
    Map<String, Object> _internal;

    LogicalKeyboardKey _trigger;

    String _character;

    bool _control;

    bool _shift;

    bool _alt;

    bool _meta;

    static const int _shortcutModifierMeta;

    static const int _shortcutModifierShift;

    static const int _shortcutModifierAlt;

    static const int _shortcutModifierControl;


};

class MenuSerializableShortcut {
public:

    ShortcutSerialization serializeForMenu();

private:

};

class MenuItem {
public:

     MenuItem();

    Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    MenuSerializableShortcut shortcut();

    List<MenuItem> menus();

    List<MenuItem> descendants();

    VoidCallback onSelected();

    Intent onSelectedIntent();

    VoidCallback onOpen();

    VoidCallback onClose();

    List<MenuItem> members();

private:

};

class PlatformMenuDelegate {
public:

     PlatformMenuDelegate();

    void setMenus(List<MenuItem> topLevelMenus);

    void clearMenus();

    bool debugLockDelegate(BuildContext context);

    bool debugUnlockDelegate(BuildContext context);

private:

};

class DefaultPlatformMenuDelegate : PlatformMenuDelegate {
public:
    MethodChannel channel;


     DefaultPlatformMenuDelegate(MethodChannel channel);

    void clearMenus();

    void setMenus(List<MenuItem> topLevelMenus);

    bool debugLockDelegate(BuildContext context);

    bool debugUnlockDelegate(BuildContext context);

private:
    Map<int, MenuItem> _idMap;

    int _serial;

    BuildContext _lockedContext;


    int _getId(MenuItem item);

    Future<void> _methodCallHandler(MethodCall call);

};

class PlatformMenuBar : StatefulWidget {
public:
    Widget child;

    Widget body;

    List<MenuItem> menus;


     PlatformMenuBar(Widget body, Widget child, Unknown, List<MenuItem> menus);

    State<PlatformMenuBar> createState();

    List<DiagnosticsNode> debugDescribeChildren();

private:

};

class _PlatformMenuBarState : State<PlatformMenuBar> {
public:
    List<MenuItem> descendants;


    void initState();

    void dispose();

    void didUpdateWidget(PlatformMenuBar oldWidget);

    Widget build(BuildContext context);

private:

    void _updateMenu();

};

class PlatformMenu : MenuItem {
public:
    String label;

    VoidCallback onOpen;

    VoidCallback onClose;

    List<MenuItem> menus;


     PlatformMenu(String label, List<MenuItem> menus, VoidCallback onClose, VoidCallback onOpen);

    List<MenuItem> descendants();

    static List<MenuItem> getDescendants(PlatformMenu item);

    Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Map<String, Object> serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, PlatformMenu item);

    List<DiagnosticsNode> debugDescribeChildren();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PlatformMenuItemGroup : MenuItem {
public:
    List<MenuItem> members;


     PlatformMenuItemGroup(List<MenuItem> members);

    Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Iterable<Map<String, Object>> serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, MenuItem group);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PlatformMenuItem : MenuItem {
public:
    String label;

    MenuSerializableShortcut shortcut;

    VoidCallback onSelected;

    Intent onSelectedIntent;


     PlatformMenuItem(String label, VoidCallback onSelected, Intent onSelectedIntent, MenuSerializableShortcut shortcut);

    Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Map<String, Object> serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, PlatformMenuItem item);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class PlatformProvidedMenuItem : PlatformMenuItem {
public:
    PlatformProvidedMenuItemType type;

    bool enabled;


     PlatformProvidedMenuItem(bool enabled, PlatformProvidedMenuItemType type);

    static bool hasMenu(PlatformProvidedMenuItemType menu);

    Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

enum PlatformProvidedMenuItemType{
    about,
    quit,
    servicesSubmenu,
    hide,
    hideOtherApplications,
    showAllApplications,
    startSpeaking,
    stopSpeaking,
    toggleFullScreen,
    minimizeWindow,
    zoomWindow,
    arrangeWindowsInFront,
} // end PlatformProvidedMenuItemType

#endif