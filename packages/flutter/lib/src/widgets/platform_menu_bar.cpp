#include "platform_menu_bar.hpp"
void ShortcutSerializationCls::character(String character)

void ShortcutSerializationCls::modifier(LogicalKeyboardKey trigger, bool alt, bool control, bool meta, bool shift)

LogicalKeyboardKey ShortcutSerializationCls::trigger() {
    return _trigger;
}

String ShortcutSerializationCls::character() {
    return _character;
}

bool ShortcutSerializationCls::control() {
    return _control;
}

bool ShortcutSerializationCls::shift() {
    return _shift;
}

bool ShortcutSerializationCls::alt() {
    return _alt;
}

bool ShortcutSerializationCls::meta() {
    return _meta;
}

Map<String, Object> ShortcutSerializationCls::toChannelRepresentation() {
    return _internal;
}

MenuSerializableShortcut MenuItemCls::shortcut() {
    return nullptr;
}

List<MenuItem> MenuItemCls::menus() {
    return makeList();
}

List<MenuItem> MenuItemCls::descendants() {
    return makeList();
}

VoidCallback MenuItemCls::onSelected() {
    return nullptr;
}

Intent MenuItemCls::onSelectedIntent() {
    return nullptr;
}

VoidCallback MenuItemCls::onOpen() {
    return nullptr;
}

VoidCallback MenuItemCls::onClose() {
    return nullptr;
}

List<MenuItem> MenuItemCls::members() {
    return makeList();
}

DefaultPlatformMenuDelegateCls::DefaultPlatformMenuDelegateCls(MethodChannel channel) {
    {
        channel = channel | SystemChannelsCls::menu;
        _idMap = makeMap(makeList(), makeList();
    }
    {
        this->channel->setMethodCallHandler(_methodCallHandler);
    }
}

void DefaultPlatformMenuDelegateCls::clearMenus() {
    return setMenus(makeList());
}

void DefaultPlatformMenuDelegateCls::setMenus(List<MenuItem> topLevelMenus) {
    _idMap->clear();
    List<Map<String, Object>> representation = makeList();
    if (topLevelMenus->isNotEmpty()) {
        for (MenuItem childItem : topLevelMenus) {
            representation->addAll(childItem->toChannelRepresentation(this, _getId));
        }
    }
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("0"), representation);Map<String, Object> windowMenu = list1;
    channel-><void>invokeMethod(_kMenuSetMethod, windowMenu);
}

bool DefaultPlatformMenuDelegateCls::debugLockDelegate(BuildContext context) {
    assert([=] () {
        if (_lockedContext != nullptr && _lockedContext != context) {
            return false;
        }
        _lockedContext = context;
        return true;
    }());
    return true;
}

bool DefaultPlatformMenuDelegateCls::debugUnlockDelegate(BuildContext context) {
    assert([=] () {
        if (_lockedContext != nullptr && _lockedContext != context) {
            return false;
        }
        _lockedContext = nullptr;
        return true;
    }());
    return true;
}

int DefaultPlatformMenuDelegateCls::_getId(MenuItem item) {
    _serial += 1;
    _idMap[_serial] = item;
    return _serial;
}

Future<void> DefaultPlatformMenuDelegateCls::_methodCallHandler(MethodCall call) {
    int id = as<int>(call->arguments);
    assert(_idMap->containsKey(id), __sf("Received a menu %s for a menu item with an ID that was not recognized: %s", call->method, id));
    if (!_idMap->containsKey(id)) {
        return;
    }
    MenuItem item = _idMap[id]!;
    if (call->method == _kMenuSelectedCallbackMethod) {
        assert(item->onSelected() == nullptr || item->onSelectedIntent() == nullptr, __s("Only one of MenuItem.onSelected or MenuItem.onSelectedIntent may be specified"));
        item->onSelected()?->call();
        if (item->onSelectedIntent() != nullptr) {
            ActionsCls->maybeInvoke(FocusManagerCls::instance->primaryFocus!->context!, item->onSelectedIntent()!);
        }
    } else {
        if (call->method == _kMenuItemOpenedMethod) {
        item->onOpen()?->call();
    } else {
        if (call->method == _kMenuItemClosedMethod) {
        item->onClose()?->call();
    }
;
    };
    }}

PlatformMenuBarCls::PlatformMenuBarCls(Widget body, Widget child, Key key, List<MenuItem> menus) {
    {
        assert(body == nullptr || child == nullptr, __s("The body argument is deprecated, and only one of body or child may be used."));
    }
}

State<PlatformMenuBar> PlatformMenuBarCls::createState() {
    return make<_PlatformMenuBarStateCls>();
}

List<DiagnosticsNode> PlatformMenuBarCls::debugDescribeChildren() {
    return menus-><DiagnosticsNode>map([=] (MenuItem child) {
        child->toDiagnosticsNode();
    })->toList();
}

void _PlatformMenuBarStateCls::initState() {
    super->initState();
    assert(WidgetsBindingCls::instance->platformMenuDelegate->debugLockDelegate(context()), __sf("More than one active %s detected. Only one active platform-rendered menu bar is allowed at a time.", PlatformMenuBarCls));
    WidgetsBindingCls::instance->platformMenuDelegate->clearMenus();
    _updateMenu();
}

void _PlatformMenuBarStateCls::dispose() {
    assert(WidgetsBindingCls::instance->platformMenuDelegate->debugUnlockDelegate(context()), __sf("tried to unlock the %s more than once with context %s.", DefaultPlatformMenuDelegateCls, context()));
    WidgetsBindingCls::instance->platformMenuDelegate->clearMenus();
    super->dispose();
}

void _PlatformMenuBarStateCls::didUpdateWidget(PlatformMenuBar oldWidget) {
    super->didUpdateWidget(oldWidget);
    List<MenuItem> list1 = make<ListCls<>>();for (MenuItem item : widget()->menus) {    ;}{    list1.add(ArrayItem);}List<MenuItem> newDescendants = list1;
    if (!listEquals(newDescendants, descendants)) {
        descendants = newDescendants;
        _updateMenu();
    }
}

Widget _PlatformMenuBarStateCls::build(BuildContext context) {
    return widget()->child | widget()->body | make<SizedBoxCls>();
}

void _PlatformMenuBarStateCls::_updateMenu() {
    WidgetsBindingCls::instance->platformMenuDelegate->setMenus(widget()->menus);
}

List<MenuItem> PlatformMenuCls::descendants() {
    return getDescendants(this);
}

List<MenuItem> PlatformMenuCls::getDescendants(PlatformMenu item) {
    List<MenuItem> list1 = make<ListCls<>>();for (MenuItem child : item->menus) {        ;    }{    list1.add(ArrayItem);}return list1;
}

Iterable<Map<String, Object>> PlatformMenuCls::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    return makeList(ArrayItem);
}

Map<String, Object> PlatformMenuCls::serialize(PlatformMenu item, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    List<Map<String, Object>> result = makeList();
    for (MenuItem childItem : item->menus) {
        result->addAll(childItem->toChannelRepresentation(delegate, getId));
    }
    Map<String, Object> previousItem;
    result->removeWhere([=] (Map<String, Object> item) {
        if (previousItem == nullptr && item[_kIsDividerKey] == true) {
            return true;
        }
        if (previousItem != nullptr && previousItem![_kIsDividerKey] == true && item[_kIsDividerKey] == true) {
            return true;
        }
        previousItem = item;
        return false;
    });
    if (result->isNotEmpty() && result->last[_kIsDividerKey] == true) {
        result->removeLast();
    }
    Map<String, Object> map1 = make<MapCls<>>();map1.set(_kIdKey, getId(item));map1.set(_kLabelKey, item->label);map1.set(_kEnabledKey, item->menus->isNotEmpty());map1.set(_kChildrenKey, result);return list1;
}

List<DiagnosticsNode> PlatformMenuCls::debugDescribeChildren() {
    return menus-><DiagnosticsNode>map([=] (MenuItem child) {
        child->toDiagnosticsNode();
    })->toList();
}

void PlatformMenuCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("label"), label));
    properties->add(make<FlagPropertyCls>(__s("enabled"), menus->isNotEmpty(), __s("DISABLED")));
}

Iterable<Map<String, Object>> PlatformMenuItemGroupCls::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    assert(members->isNotEmpty(), __s("There must be at least one member in a PlatformMenuItemGroup"));
    return serialize(this, delegate, getId);
}

Iterable<Map<String, Object>> PlatformMenuItemGroupCls::serialize(MenuItem group, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    List<Map<String, Object>> result = makeList();
    Map<String, Object> map1 = make<MapCls<>>();map1.set(_kIdKey, getId(group));map1.set(_kIsDividerKey, true);result->add(list1);
    for (MenuItem item : group->members()) {
        result->addAll(item->toChannelRepresentation(delegate, getId));
    }
    Map<String, Object> map2 = make<MapCls<>>();map2.set(_kIdKey, getId(group));map2.set(_kIsDividerKey, true);result->add(list2);
    return result;
}

void PlatformMenuItemGroupCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<MenuItem>make<IterablePropertyCls>(__s("members"), members));
}

PlatformMenuItemCls::PlatformMenuItemCls(String label, VoidCallback onSelected, Intent onSelectedIntent, MenuSerializableShortcut shortcut) {
    {
        assert(onSelected == nullptr || onSelectedIntent == nullptr, __s("Only one of onSelected or onSelectedIntent may be specified"));
    }
}

Iterable<Map<String, Object>> PlatformMenuItemCls::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    return makeList(ArrayItem);
}

Map<String, Object> PlatformMenuItemCls::serialize(PlatformMenuItem item, PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    MenuSerializableShortcut shortcut = item->shortcut;
    Map<String, Object> map1 = make<MapCls<>>();map1.set(_kIdKey, getId(item));map1.set(_kLabelKey, item->label);map1.set(_kEnabledKey, item->onSelected != nullptr);NeedMapItemHerereturn list1;
}

String PlatformMenuItemCls::toStringShort() {
    return __sf("%s(%s)", describeIdentity(this), label);
}

void PlatformMenuItemCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("label"), label));
    properties->add(<MenuSerializableShortcut>make<DiagnosticsPropertyCls>(__s("shortcut"), shortcut, nullptr));
    properties->add(make<FlagPropertyCls>(__s("enabled"), onSelected != nullptr, __s("DISABLED")));
}

PlatformProvidedMenuItemCls::PlatformProvidedMenuItemCls(bool enabled, PlatformProvidedMenuItemType type) : PlatformMenuItem(__s("")) {
}

bool PlatformProvidedMenuItemCls::hasMenu(PlatformProvidedMenuItemType menu) {
    ;
}

Iterable<Map<String, Object>> PlatformProvidedMenuItemCls::toChannelRepresentation(PlatformMenuDelegate delegate, MenuItemSerializableIdGenerator getId) {
    assert([=] () {
        if (!hasMenu(type)) {
            throw make<ArgumentErrorCls>(__sf("Platform %s has no platform provided menu for %s. Call PlatformProvidedMenuItem.hasMenu to determine this before instantiating one.", defaultTargetPlatform->name, type));
        }
        return true;
    }());
    return makeList(ArrayItem);
}

void PlatformProvidedMenuItemCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("enabled"), enabled, __s("DISABLED")));
}
