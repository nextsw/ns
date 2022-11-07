#include "shortcuts.hpp"
KeySet::KeySet(T key1, T key2, T key3, T key4) {
    {
        assert(key1 != nullptr);
        _keys = ;
    }
    {
        int count = 1;
        if (key2 != nullptr) {
            _keys.add(key2);
            assert(());
        }
        if (key3 != nullptr) {
            _keys.add(key3);
            assert(());
        }
        if (key4 != nullptr) {
            _keys.add(key4);
            assert(());
        }
        assert(_keys.length == count, "Two or more provided keys are identical. Each key must appear only once.");
    }
}

void KeySet::fromSet(Set<T> keys)

Set<T> KeySet::keys() {
    return _keys.toSet();
}

bool KeySet::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is KeySet<T> && <T>setEquals(other._keys, _keys);
}

int KeySet::_computeHashCode<T>(Set<T> keys) {
    int length = keys.length;
    Iterator<T> iterator = keys.iterator;
    iterator.moveNext();
    int h1 = iterator.current.hashCode;
    if (length == 1) {
        return h1;
    }
    iterator.moveNext();
    int h2 = iterator.current.hashCode;
    if (length == 2) {
        return  < h2? Object.hash(h1, h2) : Object.hash(h2, h1);
    }
    List<int> sortedHashes = length == 3? _tempHashStore3 : _tempHashStore4;
    sortedHashes[0] = h1;
    sortedHashes[1] = h2;
    iterator.moveNext();
    sortedHashes[2] = iterator.current.hashCode;
    if (length == 4) {
        iterator.moveNext();
        sortedHashes[3] = iterator.current.hashCode;
    }
    sortedHashes.sort();
    return Object.hashAll(sortedHashes);
}

bool ShortcutActivator::isActivatedBy(ShortcutActivator activator, RawKeyEvent event) {
    return (activator.triggers?.contains(event.logicalKey) ?? true) && activator.accepts(event, RawKeyboard.instance);
}

void LogicalKeySet::fromSet(Unknown)

Iterable<LogicalKeyboardKey> LogicalKeySet::triggers() {
    return _triggers;
}

bool LogicalKeySet::accepts(RawKeyEvent event, RawKeyboard state) {
    if (event is! RawKeyDownEvent) {
        return false;
    }
    Set<LogicalKeyboardKey> collapsedRequired = LogicalKeyboardKey.collapseSynonyms(keys);
    Set<LogicalKeyboardKey> collapsedPressed = LogicalKeyboardKey.collapseSynonyms(state.keysPressed);
    bool keysEqual = collapsedRequired.difference(collapsedPressed).isEmpty && collapsedRequired.length == collapsedPressed.length;
    return keysEqual;
}

String LogicalKeySet::debugDescribeKeys() {
    List<LogicalKeyboardKey> sortedKeys = ;
    return sortedKeys.<String>map().join(" + ");
}

void LogicalKeySet::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Set<LogicalKeyboardKey>>DiagnosticsProperty("keys", _keysdebugDescribeKeys()));
}
