#include "shortcuts.hpp"
template<typename T>
KeySetCls<T>::KeySetCls(T key1, T key2, T key3, T key4) {
    {
        assert(key1 != nullptr);
            auto _c1 = <T>make<HashSetCls>();    _c1.add(key1);_keys = _c1;
    }
    {
        int count = 1;
        if (key2 != nullptr) {
            _keys->add(key2);
            assert([=] () {
                count++;
                return true;
            }());
        }
        if (key3 != nullptr) {
            _keys->add(key3);
            assert([=] () {
                count++;
                return true;
            }());
        }
        if (key4 != nullptr) {
            _keys->add(key4);
            assert([=] () {
                count++;
                return true;
            }());
        }
        assert(_keys->length() == count, __s("Two or more provided keys are identical. Each key must appear only once."));
    }
}

template<typename T>
void KeySetCls<T>::fromSet(Set<T> keys)

template<typename T>
Set<T> KeySetCls<T>::keys() {
    return _keys->toSet();
}

template<typename T>
bool KeySetCls<T>::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<KeySet<T>>(other) && <T>setEquals(other->_keys, _keys);
}

template<typename T>
template<typename T>
int KeySetCls<T>::_computeHashCode(Set<T> keys) {
    int length = keys->length();
    Iterator<T> iterator = keys->iterator();
    iterator->moveNext();
    int h1 = iterator->current()->hashCode;
    if (length == 1) {
        return h1;
    }
    iterator->moveNext();
    int h2 = iterator->current()->hashCode;
    if (length == 2) {
        return  < h2? ObjectCls->hash(h1, h2) : ObjectCls->hash(h2, h1);
    }
    List<int> sortedHashes = length == 3? _tempHashStore3 : _tempHashStore4;
    sortedHashes[0] = h1;
    sortedHashes[1] = h2;
    iterator->moveNext();
    sortedHashes[2] = iterator->current()->hashCode;
    if (length == 4) {
        iterator->moveNext();
        sortedHashes[3] = iterator->current()->hashCode;
    }
    sortedHashes->sort();
    return ObjectCls->hashAll(sortedHashes);
}

bool ShortcutActivatorCls::isActivatedBy(ShortcutActivator activator, RawKeyEvent event) {
    return (activator->triggers()?->contains(event->logicalKey()) | true) && activator->accepts(event, RawKeyboardCls::instance);
}

void LogicalKeySetCls::fromSet(Unknown keys)

Iterable<LogicalKeyboardKey> LogicalKeySetCls::triggers() {
    return _triggers;
}

bool LogicalKeySetCls::accepts(RawKeyEvent event, RawKeyboard state) {
    if (!is<RawKeyDownEvent>(event)) {
        return false;
    }
    Set<LogicalKeyboardKey> collapsedRequired = LogicalKeyboardKeyCls->collapseSynonyms(keys());
    Set<LogicalKeyboardKey> collapsedPressed = LogicalKeyboardKeyCls->collapseSynonyms(state->keysPressed());
    bool keysEqual = collapsedRequired->difference(collapsedPressed)->isEmpty() && collapsedRequired->length() == collapsedPressed->length();
    return keysEqual;
}

String LogicalKeySetCls::debugDescribeKeys() {
    });List<LogicalKeyboardKey> sortedKeys = auto _c1 = keys()->toList();_c1.sort([=] (LogicalKeyboardKey a,LogicalKeyboardKey b) {    bool aIsModifier = a->synonyms->isNotEmpty || _modifiers->contains(a);    bool bIsModifier = b->synonyms->isNotEmpty || _modifiers->contains(b);    };    }        if (aIsModifier && !bIsModifier) {            return -1;        } else {            if (bIsModifier && !aIsModifier) {            return 1;    return a->debugName!->compareTo(b->debugName!);_c1;
    return sortedKeys-><String>map([=] (LogicalKeyboardKey key) {
        key->debugName->toString();
    })->join(__s(" + "));
}

void LogicalKeySetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Set<LogicalKeyboardKey>>make<DiagnosticsPropertyCls>(__s("keys"), _keys, debugDescribeKeys()));
}

ShortcutMapPropertyCls::ShortcutMapPropertyCls(String name, T value, Object defaultValue, String description, DiagnosticLevel level, bool showName) : DiagnosticsProperty<Map<ShortcutActivator, Intent>>(name, valuename, value) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

Map<ShortcutActivator, Intent> ShortcutMapPropertyCls::value() {
    return super->value!;
}

String ShortcutMapPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    return __sf("{%s}", value()->keys()-><String>map([=] (ShortcutActivator keySet) {
    __sf("{%s}: %s", keySet->debugDescribeKeys(), value()[keySet]);
})->join(__s(", ")));
}

SingleActivatorCls::SingleActivatorCls(LogicalKeyboardKey trigger, bool alt, bool control, bool includeRepeats, bool meta, bool shift) {
    {
        assert(!identical(trigger, LogicalKeyboardKeyCls::control) && !identical(trigger, LogicalKeyboardKeyCls::controlLeft) && !identical(trigger, LogicalKeyboardKeyCls::controlRight) && !identical(trigger, LogicalKeyboardKeyCls::shift) && !identical(trigger, LogicalKeyboardKeyCls::shiftLeft) && !identical(trigger, LogicalKeyboardKeyCls::shiftRight) && !identical(trigger, LogicalKeyboardKeyCls::alt) && !identical(trigger, LogicalKeyboardKeyCls::altLeft) && !identical(trigger, LogicalKeyboardKeyCls::altRight) && !identical(trigger, LogicalKeyboardKeyCls::meta) && !identical(trigger, LogicalKeyboardKeyCls::metaLeft) && !identical(trigger, LogicalKeyboardKeyCls::metaRight));
    }
}

Iterable<LogicalKeyboardKey> SingleActivatorCls::triggers() {
    return makeList(ArrayItem);
}

bool SingleActivatorCls::accepts(RawKeyEvent event, RawKeyboard state) {
    Set<LogicalKeyboardKey> pressed = state->keysPressed();
    return is<RawKeyDownEvent>(event) && (includeRepeats || !event->repeat) && (control == (pressed->contains(LogicalKeyboardKeyCls::controlLeft) || pressed->contains(LogicalKeyboardKeyCls::controlRight))) && (shift == (pressed->contains(LogicalKeyboardKeyCls::shiftLeft) || pressed->contains(LogicalKeyboardKeyCls::shiftRight))) && (alt == (pressed->contains(LogicalKeyboardKeyCls::altLeft) || pressed->contains(LogicalKeyboardKeyCls::altRight))) && (meta == (pressed->contains(LogicalKeyboardKeyCls::metaLeft) || pressed->contains(LogicalKeyboardKeyCls::metaRight)));
}

ShortcutSerialization SingleActivatorCls::serializeForMenu() {
    return ShortcutSerializationCls->modifier(trigger, shift, alt, meta, control);
}

String SingleActivatorCls::debugDescribeKeys() {
    String result = __s("");
    assert([=] () {
            List<String> list1 = make<ListCls<>>();    if (control) {        list1.add(ArrayItem);    }if (alt) {        list1.add(ArrayItem);    }if (meta) {        list1.add(ArrayItem);    }if (shift) {        list1.add(ArrayItem);    }list1.add(ArrayItem);List<String> keys = list1;
        result = keys->join(__s(" + "));
        return true;
    }());
    return result;
}

void SingleActivatorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("keys"), debugDescribeKeys()));
    properties->add(make<FlagPropertyCls>(__s("includeRepeats"), includeRepeats, __s("excluding repeats")));
}

Iterable<LogicalKeyboardKey> CharacterActivatorCls::triggers() {
    return nullptr;
}

bool CharacterActivatorCls::accepts(RawKeyEvent event, RawKeyboard state) {
    return is<RawKeyDownEvent>(event) && event->character == character;
}

String CharacterActivatorCls::debugDescribeKeys() {
    String result = __s("");
    assert([=] () {
        result = __sf("'%s'", character);
        return true;
    }());
    return result;
}

ShortcutSerialization CharacterActivatorCls::serializeForMenu() {
    return ShortcutSerializationCls->character(character);
}

void CharacterActivatorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("character"), character));
}

void _ActivatorIntentPairCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("activator"), activator->debugDescribeKeys()));
    properties->add(<Intent>make<DiagnosticsPropertyCls>(__s("intent"), intent));
}

ShortcutManagerCls::ShortcutManagerCls(bool modal, Map<ShortcutActivator, Intent> shortcuts) {
    {
        assert(shortcuts != nullptr);
        _shortcuts = shortcuts;
    }
}

Map<ShortcutActivator, Intent> ShortcutManagerCls::shortcuts() {
    return _shortcuts;
}

void ShortcutManagerCls::shortcuts(Map<ShortcutActivator, Intent> value) {
    assert(value != nullptr);
    if (!<ShortcutActivator, Intent>mapEquals(_shortcuts, value)) {
        _shortcuts = value;
        _indexedShortcutsCache = nullptr;
        notifyListeners();
    }
}

KeyEventResult ShortcutManagerCls::handleKeypress(BuildContext context, RawKeyEvent event) {
    assert(context != nullptr);
    Intent matchedIntent = _find(event, RawKeyboardCls::instance);
    if (matchedIntent != nullptr) {
        BuildContext primaryContext = primaryFocus?->context;
        if (primaryContext != nullptr) {
            Action<Intent> action = ActionsCls-><Intent>maybeFind(primaryContext, matchedIntent);
            if (action != nullptr && action->isEnabled(matchedIntent)) {
                ActionsCls->of(primaryContext)->invokeAction(action, matchedIntent, primaryContext);
                return action->consumesKey(matchedIntent)? KeyEventResultCls::handled : KeyEventResultCls::skipRemainingHandlers;
            }
        }
    }
    return modal? KeyEventResultCls::skipRemainingHandlers : KeyEventResultCls::ignored;
}

void ShortcutManagerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Map<ShortcutActivator, Intent>>make<DiagnosticsPropertyCls>(__s("shortcuts"), shortcuts()));
    properties->add(make<FlagPropertyCls>(__s("modal"), modal, __s("modal"), false));
}

Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> ShortcutManagerCls::_indexShortcuts(Map<ShortcutActivator, Intent> source) {
    Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> result = makeMap(makeList(), makeList();
    source->forEach([=] (ShortcutActivator activator,Intent intent) {
        Iterable<LogicalKeyboardKey> nullableTriggers = activator->triggers;
        for (LogicalKeyboardKey trigger : nullableTriggers | makeList(ArrayItem)) {
            result->putIfAbsent(trigger, [=] () {
                makeList();
            })->add(make<_ActivatorIntentPairCls>(activator, intent));
        }
    });
    return result;
}

Map<LogicalKeyboardKey, List<_ActivatorIntentPair>> ShortcutManagerCls::_indexedShortcuts() {
    return _indexedShortcutsCache ??= _indexShortcuts(shortcuts());
}

Intent ShortcutManagerCls::_find(RawKeyEvent event, RawKeyboard state) {
    List<_ActivatorIntentPair> candidatesByKey = _indexedShortcuts()[event->logicalKey()];
    List<_ActivatorIntentPair> candidatesByNull = _indexedShortcuts()[nullptr];
    List<_ActivatorIntentPair> list1 = make<ListCls<>>();if (candidatesByKey != nullptr) {    list1.add(ArrayItem);}if (candidatesByNull != nullptr) {    list1.add(ArrayItem);}List<_ActivatorIntentPair> candidates = list1;
    for (_ActivatorIntentPair activatorIntent : candidates) {
        if (activatorIntent->activator->accepts(event, state)) {
            return activatorIntent->intent;
        }
    }
    return nullptr;
}

ShortcutsCls::ShortcutsCls(Widget child, String debugLabel, Key key, Map<ShortcutActivator, Intent> shortcuts) {
    {
        _shortcuts = shortcuts;
        manager = nullptr;
        assert(shortcuts != nullptr);
        assert(child != nullptr);
    }
}

void ShortcutsCls::manager(Unknown child, Unknown debugLabel, Unknown key, ShortcutManager manager)

Map<ShortcutActivator, Intent> ShortcutsCls::shortcuts() {
    return manager == nullptr? _shortcuts : manager!->shortcuts();
}

State<Shortcuts> ShortcutsCls::createState() {
    return make<_ShortcutsStateCls>();
}

void ShortcutsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ShortcutManager>make<DiagnosticsPropertyCls>(__s("manager"), manager, nullptr));
    properties->add(make<ShortcutMapPropertyCls>(__s("shortcuts"), shortcuts(), debugLabel?->isNotEmpty() | false? debugLabel : nullptr));
}

ShortcutManager _ShortcutsStateCls::manager() {
    return widget()->manager() | _internalManager!;
}

void _ShortcutsStateCls::dispose() {
    _internalManager?->dispose();
    super->dispose();
}

void _ShortcutsStateCls::initState() {
    super->initState();
    if (widget()->manager() == nullptr) {
        _internalManager = make<ShortcutManagerCls>();
        _internalManager!->shortcuts() = widget()->shortcuts;
    }
}

void _ShortcutsStateCls::didUpdateWidget(Shortcuts oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->manager() != oldWidget->manager) {
        if (widget()->manager() != nullptr) {
            _internalManager?->dispose();
            _internalManager = nullptr;
        } else {
            _internalManager |= make<ShortcutManagerCls>();
        }
    }
    _internalManager?->shortcuts() = widget()->shortcuts;
}

Widget _ShortcutsStateCls::build(BuildContext context) {
    return make<FocusCls>(__sf("%s", ShortcutsCls), false, _handleOnKey, widget()->child);
}

KeyEventResult _ShortcutsStateCls::_handleOnKey(FocusNode node, RawKeyEvent event) {
    if (node->context() == nullptr) {
        return KeyEventResultCls::ignored;
    }
    return manager()->handleKeypress(node->context()!, event);
}

Widget CallbackShortcutsCls::build(BuildContext context) {
    return make<FocusCls>(false, true, [=] (FocusNode node,RawKeyEvent event) {
        KeyEventResult result = KeyEventResultCls::ignored;
        for (ShortcutActivator activator : bindings->keys()) {
            result = _applyKeyBinding(activator, event)? KeyEventResultCls::handled : result;
        }
        return result;
    }, child);
}

bool CallbackShortcutsCls::_applyKeyBinding(ShortcutActivator activator, RawKeyEvent event) {
    if (ShortcutActivatorCls->isActivatedBy(activator, event)) {
        bindings[activator]!->call();
        return true;
    }
    return false;
}

void ShortcutRegistryEntryCls::replaceAll(Map<ShortcutActivator, Intent> value) {
    registry->_replaceAll(this, value);
}

void ShortcutRegistryEntryCls::dispose() {
    registry->_disposeToken(this);
}

Map<ShortcutActivator, Intent> ShortcutRegistryCls::shortcuts() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    Map<ShortcutActivator, Intent> map1 = make<MapCls<>>();NeedMapItemHerereturn list1;
}

ShortcutRegistryEntry ShortcutRegistryCls::addAll(Map<ShortcutActivator, Intent> value) {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    ShortcutRegistryEntry entry = ShortcutRegistryEntryCls->_(this);
    _tokenShortcuts[entry] = value;
    assert(_debugCheckForDuplicates());
    notifyListeners();
    return entry;
}

ShortcutRegistry ShortcutRegistryCls::of(BuildContext context) {
    assert(context != nullptr);
    _ShortcutRegistrarMarker inherited = context-><_ShortcutRegistrarMarker>dependOnInheritedWidgetOfExactType();
    assert([=] () {
        if (inherited == nullptr) {
            throw make<FlutterErrorCls>(__sf("Unable to find a %s widget in the context.\n%s.of() was called with a context that does not contain a %s widget.\nNo %s ancestor could be found starting from the context that was passed to %s.of().\nThe context used was:\n  %s", ShortcutRegistrarCls, ShortcutRegistrarCls, ShortcutRegistrarCls, ShortcutRegistrarCls, ShortcutRegistrarCls, context));
        }
        return true;
    }());
    return inherited!->registry;
}

ShortcutRegistry ShortcutRegistryCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    _ShortcutRegistrarMarker inherited = context-><_ShortcutRegistrarMarker>dependOnInheritedWidgetOfExactType();
    return inherited?->registry;
}

void ShortcutRegistryCls::_replaceAll(ShortcutRegistryEntry entry, Map<ShortcutActivator, Intent> value) {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    assert(_debugCheckTokenIsValid(entry));
    _tokenShortcuts[entry] = value;
    assert(_debugCheckForDuplicates());
    notifyListeners();
}

void ShortcutRegistryCls::_disposeToken(ShortcutRegistryEntry entry) {
    assert(_debugCheckTokenIsValid(entry));
    if (_tokenShortcuts->remove(entry) != nullptr) {
        notifyListeners();
    }
}

bool ShortcutRegistryCls::_debugCheckTokenIsValid(ShortcutRegistryEntry entry) {
    if (!_tokenShortcuts->containsKey(entry)) {
        if (entry->registry == this) {
            throw make<FlutterErrorCls>(__sf("entry %s is invalid.\nThe entry has already been disposed of. Tokens are not valid after dispose is called on them, and should no longer be used.", describeIdentity(entry)));
        } else {
            throw make<FlutterErrorCls>(__sf("Foreign entry %s used.\nThis entry was not created by this registry, it was created by %s, and should be used with that registry instead.", describeIdentity(entry), describeIdentity(entry->registry)));
        }
    }
    return true;
}

bool ShortcutRegistryCls::_debugCheckForDuplicates() {
    Map<ShortcutActivator, ShortcutRegistryEntry> previous = makeMap(makeList(), makeList();
    for (MapEntry<ShortcutRegistryEntry, Map<ShortcutActivator, Intent>> tokenEntry : _tokenShortcuts->entries()) {
        for (ShortcutActivator shortcut : tokenEntry->value->keys) {
            if (previous->containsKey(shortcut)) {
                throw make<FlutterErrorCls>(__sf("%s: Received a duplicate registration for the shortcut %s in %s and %s.", ShortcutRegistryCls, shortcut, describeIdentity(tokenEntry->key), previous[shortcut]));
            }
            previous[shortcut] = tokenEntry->key;
        }
    }
    return true;
}

State<ShortcutRegistrar> ShortcutRegistrarCls::createState() {
    return make<_ShortcutRegistrarStateCls>();
}

void _ShortcutRegistrarStateCls::initState() {
    super->initState();
    registry->addListener(_shortcutsChanged);
}

void _ShortcutRegistrarStateCls::dispose() {
    registry->removeListener(_shortcutsChanged);
    registry->dispose();
    super->dispose();
}

Widget _ShortcutRegistrarStateCls::build(BuildContext context) {
    return ShortcutsCls->manager(manager, make<_ShortcutRegistrarMarkerCls>(registry, widget()->child));
}

void _ShortcutRegistrarStateCls::_shortcutsChanged() {
    manager->shortcuts() = registry->shortcuts();
}

bool _ShortcutRegistrarMarkerCls::updateShouldNotify(_ShortcutRegistrarMarker oldWidget) {
    return registry != oldWidget->registry;
}
