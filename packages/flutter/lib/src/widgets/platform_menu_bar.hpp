#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLATFORM_MENU_BAR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLATFORM_MENU_BAR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "shortcuts.hpp"

String _kMenuSetMethod;

String _kMenuSelectedCallbackMethod;

String _kMenuItemOpenedMethod;

String _kMenuItemClosedMethod;

String _kIdKey;

String _kLabelKey;

String _kEnabledKey;

String _kChildrenKey;

String _kIsDividerKey;

String _kPlatformDefaultMenuKey;

String _kShortcutCharacter;

String _kShortcutTrigger;

String _kShortcutModifiers;


class ShortcutSerializationCls : public ObjectCls {
public:

    virtual void  character(String character);

    virtual void  modifier(LogicalKeyboardKey trigger, bool alt, bool control, bool meta, bool shift);

    virtual LogicalKeyboardKey trigger();

    virtual String character();

    virtual bool control();

    virtual bool shift();

    virtual bool alt();

    virtual bool meta();

    virtual Map<String, Object> toChannelRepresentation();

private:
    Map<String, Object> _internal;

    LogicalKeyboardKey _trigger;

    String _character;

    bool _control;

    bool _shift;

    bool _alt;

    bool _meta;

    static int _shortcutModifierMeta;

    static int _shortcutModifierShift;

    static int _shortcutModifierAlt;

    static int _shortcutModifierControl;


};
using ShortcutSerialization = std::shared_ptr<ShortcutSerializationCls>;

class MenuSerializableShortcutCls : public ObjectCls {
public:

    virtual ShortcutSerialization serializeForMenu();
private:

};
using MenuSerializableShortcut = std::shared_ptr<MenuSerializableShortcutCls>;

class MenuItemCls : public ObjectCls {
public:

     MenuItemCls();
    virtual Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);
    virtual MenuSerializableShortcut shortcut();

    virtual List<MenuItem> menus();

    virtual List<MenuItem> descendants();

    virtual VoidCallback onSelected();

    virtual Intent onSelectedIntent();

    virtual VoidCallback onOpen();

    virtual VoidCallback onClose();

    virtual List<MenuItem> members();

private:

};
using MenuItem = std::shared_ptr<MenuItemCls>;

class PlatformMenuDelegateCls : public ObjectCls {
public:

     PlatformMenuDelegateCls();
    virtual void setMenus(List<MenuItem> topLevelMenus);
    virtual void clearMenus();
    virtual bool debugLockDelegate(BuildContext context);
    virtual bool debugUnlockDelegate(BuildContext context);
private:

};
using PlatformMenuDelegate = std::shared_ptr<PlatformMenuDelegateCls>;

class DefaultPlatformMenuDelegateCls : public PlatformMenuDelegateCls {
public:
    MethodChannel channel;


     DefaultPlatformMenuDelegateCls(MethodChannel channel);

    virtual void clearMenus();

    virtual void setMenus(List<MenuItem> topLevelMenus);

    virtual bool debugLockDelegate(BuildContext context);

    virtual bool debugUnlockDelegate(BuildContext context);

private:
    Map<int, MenuItem> _idMap;

    int _serial;

    BuildContext _lockedContext;


    virtual int _getId(MenuItem item);

    virtual Future<void> _methodCallHandler(MethodCall call);

};
using DefaultPlatformMenuDelegate = std::shared_ptr<DefaultPlatformMenuDelegateCls>;

class PlatformMenuBarCls : public StatefulWidgetCls {
public:
    Widget child;

    Widget body;

    List<MenuItem> menus;


     PlatformMenuBarCls(Widget body, Widget child, Key key, List<MenuItem> menus);

    virtual State<PlatformMenuBar> createState();

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:

};
using PlatformMenuBar = std::shared_ptr<PlatformMenuBarCls>;

class _PlatformMenuBarStateCls : public StateCls<PlatformMenuBar> {
public:
    List<MenuItem> descendants;


    virtual void initState();

    virtual void dispose();

    virtual void didUpdateWidget(PlatformMenuBar oldWidget);

    virtual Widget build(BuildContext context);

private:

    virtual void _updateMenu();

};
using _PlatformMenuBarState = std::shared_ptr<_PlatformMenuBarStateCls>;

class PlatformMenuCls : public MenuItemCls {
public:
    String label;

    VoidCallback onOpen;

    VoidCallback onClose;

    List<MenuItem> menus;


     PlatformMenuCls(String label, List<MenuItem> menus, VoidCallback onClose, VoidCallback onOpen);
    virtual List<MenuItem> descendants();

    static List<MenuItem> getDescendants(PlatformMenu item);

    virtual Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Map<String, Object> serialize(PlatformMenu item, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PlatformMenu = std::shared_ptr<PlatformMenuCls>;

class PlatformMenuItemGroupCls : public MenuItemCls {
public:
    List<MenuItem> members;


     PlatformMenuItemGroupCls(List<MenuItem> members);
    virtual Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Iterable<Map<String, Object>> serialize(MenuItem group, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PlatformMenuItemGroup = std::shared_ptr<PlatformMenuItemGroupCls>;

class PlatformMenuItemCls : public MenuItemCls {
public:
    String label;

    MenuSerializableShortcut shortcut;

    VoidCallback onSelected;

    Intent onSelectedIntent;


     PlatformMenuItemCls(String label, VoidCallback onSelected, Intent onSelectedIntent, MenuSerializableShortcut shortcut);

    virtual Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    static Map<String, Object> serialize(PlatformMenuItem item, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PlatformMenuItem = std::shared_ptr<PlatformMenuItemCls>;

class PlatformProvidedMenuItemCls : public PlatformMenuItemCls {
public:
    PlatformProvidedMenuItemType type;

    bool enabled;


     PlatformProvidedMenuItemCls(bool enabled, PlatformProvidedMenuItemType type);

    static bool hasMenu(PlatformProvidedMenuItemType menu);

    virtual Iterable<Map<String, Object>> toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PlatformProvidedMenuItem = std::shared_ptr<PlatformProvidedMenuItemCls>;

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