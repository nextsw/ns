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
        assert(_keys->length == count, __s("Two or more provided keys are identical. Each key must appear only once."));
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
    int length = keys->length;
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
    Set<LogicalKeyboardKey> collapsedRequired = LogicalKeyboardKeyCls->collapseSynonyms(keys);
    Set<LogicalKeyboardKey> collapsedPressed = LogicalKeyboardKeyCls->collapseSynonyms(state->keysPressed());
    bool keysEqual = collapsedRequired->difference(collapsedPressed)->isEmpty && collapsedRequired->length == collapsedPressed->length;
    return keysEqual;
}

String LogicalKeySetCls::debugDescribeKeys() {
    });List<LogicalKeyboardKey> sortedKeys = auto _c1 = keys->toList();_c1.sort([=] (LogicalKeyboardKey a,LogicalKeyboardKey b) {    bool aIsModifier = a->synonyms->isNotEmpty || _modifiers->contains(a);    bool bIsModifier = b->synonyms->isNotEmpty || _modifiers->contains(b);    };    }        if (aIsModifier && !bIsModifier) {            return -1;        } else     {            if (bIsModifier && !aIsModifier) {            return 1;    return a->debugName!->compareTo(b->debugName!);_c1;
    return sortedKeys-><String>map([=] (LogicalKeyboardKey key)     {
        key->debugName->toString();
    })->join(__s(" + "));
}

void LogicalKeySetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Set<LogicalKeyboardKey>>make<DiagnosticsPropertyCls>(__s("keys"), _keysdebugDescribeKeys()));
}
