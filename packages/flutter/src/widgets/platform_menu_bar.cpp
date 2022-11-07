#include "platform_menu_bar.hpp"
void ShortcutSerialization::character(String character)

void ShortcutSerialization::modifier(bool alt, bool control, bool meta, bool shift, LogicalKeyboardKey trigger)

LogicalKeyboardKey ShortcutSerialization::trigger() {
    return _trigger;
}

String ShortcutSerialization::character() {
    return _character;
}

bool ShortcutSerialization::control() {
    return _control;
}

bool ShortcutSerialization::shift() {
    return _shift;
}

bool ShortcutSerialization::alt() {
    return _alt;
}

bool ShortcutSerialization::meta() {
    return _meta;
}

Map<String, Object> ShortcutSerialization::toChannelRepresentation() {
    return _internal;
}

MenuSerializableShortcut MenuItem::shortcut() {
    return nullptr;
}

List<MenuItem> MenuItem::menus() {
    return const ;
}

List<MenuItem> MenuItem::descendants() {
    return const ;
}

VoidCallback MenuItem::onSelected() {
    return nullptr;
}

Intent MenuItem::onSelectedIntent() {
    return nullptr;
}

VoidCallback MenuItem::onOpen() {
    return nullptr;
}

VoidCallback MenuItem::onClose() {
    return nullptr;
}

List<MenuItem> MenuItem::members() {
    return const ;
}

DefaultPlatformMenuDelegate::DefaultPlatformMenuDelegate(MethodChannel channel) {
    {
        channel = channel ?? SystemChannels.menu;
        _idMap = ;
    }
    {
        this.channel.setMethodCallHandler(_methodCallHandler);
    }
}

void DefaultPlatformMenuDelegate::clearMenus() {
    return setMenus();
}

void DefaultPlatformMenuDelegate::setMenus(List<MenuItem> topLevelMenus) {
    _idMap.clear();
    List<Map<String, Object>> representation = ;
    if (topLevelMenus.isNotEmpty) {
        for (MenuItem childItem : topLevelMenus) {
            representation.addAll(childItem.toChannelRepresentation(this_getId));
        }
    }
    Map<String, Object> windowMenu = ;
    channel.<void>invokeMethod(_kMenuSetMethod, windowMenu);
}

bool DefaultPlatformMenuDelegate::debugLockDelegate(BuildContext context) {
    assert(());
    return true;
}

bool DefaultPlatformMenuDelegate::debugUnlockDelegate(BuildContext context) {
    assert(());
    return true;
}

int DefaultPlatformMenuDelegate::_getId(MenuItem item) {
    _serial = 1;
    _idMap[_serial] = item;
    return _serial;
}

Future<void> DefaultPlatformMenuDelegate::_methodCallHandler(MethodCall call) {
    int id = (;
    assert(_idMap.containsKey(id), "Received a menu ${call.method} for a menu item with an ID that was not recognized: $id");
    if (!_idMap.containsKey(id)) {
        return;
    }
    MenuItem item = _idMap[id]!;
    if (call.method == _kMenuSelectedCallbackMethod) {
        assert(item.onSelected == nullptr || item.onSelectedIntent == nullptr, "Only one of MenuItem.onSelected or MenuItem.onSelectedIntent may be specified");
        item.onSelected?.call();
        if (item.onSelectedIntent != nullptr) {
            Actions.maybeInvoke(FocusManager.instance.primaryFocus!.context!, item.onSelectedIntent!);
        }
    } else     {
        if (call.method == _kMenuItemOpenedMethod) {
        item.onOpen?.call();
    } else     {
        if (call.method == _kMenuItemClosedMethod) {
        item.onClose?.call();
    }
;
    };
    }}

PlatformMenuBar::PlatformMenuBar(Widget body, Widget child, Unknown, List<MenuItem> menus) {
    {
        assert(body == nullptr || child == nullptr, "The body argument is deprecated, and only one of body or child may be used.");
    }
}

State<PlatformMenuBar> PlatformMenuBar::createState() {
    return _PlatformMenuBarState();
}

List<DiagnosticsNode> PlatformMenuBar::debugDescribeChildren() {
    return menus.<DiagnosticsNode>map().toList();
}

void _PlatformMenuBarState::initState() {
    super.initState();
    assert(WidgetsBinding.instance.platformMenuDelegate.debugLockDelegate(context), "More than one active $PlatformMenuBar detected. Only one active platform-rendered menu bar is allowed at a time.");
    WidgetsBinding.instance.platformMenuDelegate.clearMenus();
    _updateMenu();
}

void _PlatformMenuBarState::dispose() {
    assert(WidgetsBinding.instance.platformMenuDelegate.debugUnlockDelegate(context), "tried to unlock the $DefaultPlatformMenuDelegate more than once with context $context.");
    WidgetsBinding.instance.platformMenuDelegate.clearMenus();
    super.dispose();
}

void _PlatformMenuBarState::didUpdateWidget(PlatformMenuBar oldWidget) {
    super.didUpdateWidget(oldWidget);
    List<MenuItem> newDescendants = ;
    if (!listEquals(newDescendants, descendants)) {
        descendants = newDescendants;
        _updateMenu();
    }
}

Widget _PlatformMenuBarState::build(BuildContext context) {
    return widget.child ?? widget.body ?? const SizedBox();
}

void _PlatformMenuBarState::_updateMenu() {
    WidgetsBinding.instance.platformMenuDelegate.setMenus(widget.menus);
}

List<MenuItem> PlatformMenu::descendants() {
    return getDescendants(this);
}

List<MenuItem> PlatformMenu::getDescendants(PlatformMenu item) {
    return ;
}

Iterable<Map<String, Object>> PlatformMenu::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    return ;
}

Map<String, Object> PlatformMenu::serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, PlatformMenu item) {
    List<Map<String, Object>> result = ;
    for (MenuItem childItem : item.menus) {
        result.addAll(childItem.toChannelRepresentation(delegategetId));
    }
    Map<String, Object> previousItem;
    result.removeWhere();
    if (result.isNotEmpty && result.last[_kIsDividerKey] == true) {
        result.removeLast();
    }
    return ;
}

List<DiagnosticsNode> PlatformMenu::debugDescribeChildren() {
    return menus.<DiagnosticsNode>map().toList();
}

void PlatformMenu::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("label", label));
    properties.add(FlagProperty("enabled"menus.isNotEmpty, "DISABLED"));
}

Iterable<Map<String, Object>> PlatformMenuItemGroup::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    assert(members.isNotEmpty, "There must be at least one member in a PlatformMenuItemGroup");
    return serialize(this, delegategetId);
}

Iterable<Map<String, Object>> PlatformMenuItemGroup::serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, MenuItem group) {
    List<Map<String, Object>> result = ;
    result.add();
    for (MenuItem item : group.members) {
        result.addAll(item.toChannelRepresentation(delegategetId));
    }
    result.add();
    return result;
}

void PlatformMenuItemGroup::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<MenuItem>IterableProperty("members", members));
}

PlatformMenuItem::PlatformMenuItem(String label, VoidCallback onSelected, Intent onSelectedIntent, MenuSerializableShortcut shortcut) {
    {
        assert(onSelected == nullptr || onSelectedIntent == nullptr, "Only one of onSelected or onSelectedIntent may be specified");
    }
}

Iterable<Map<String, Object>> PlatformMenuItem::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    return ;
}

Map<String, Object> PlatformMenuItem::serialize(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId, PlatformMenuItem item) {
    MenuSerializableShortcut shortcut = item.shortcut;
    return ;
}

String PlatformMenuItem::toStringShort() {
    return "${describeIdentity(this)}($label)";
}

void PlatformMenuItem::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("label", label));
    properties.add(<MenuSerializableShortcut>DiagnosticsProperty("shortcut", shortcutnullptr));
    properties.add(FlagProperty("enabled"onSelected != nullptr, "DISABLED"));
}

PlatformProvidedMenuItem::PlatformProvidedMenuItem(bool enabled, PlatformProvidedMenuItemType type) {
    {
        super("");
    }
}

bool PlatformProvidedMenuItem::hasMenu(PlatformProvidedMenuItemType menu) {
    ;
}

Iterable<Map<String, Object>> PlatformProvidedMenuItem::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    assert(());
    return ;
}

void PlatformProvidedMenuItem::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("enabled"enabled, "DISABLED"));
}
