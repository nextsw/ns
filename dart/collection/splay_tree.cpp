#include "splay_tree.hpp"
template<typename K>
_SplayTreeSetNodeCls<K>::_SplayTreeSetNodeCls(K key) : _SplayTreeNode<K, _SplayTreeSetNode<K>>(key) {
}

template<typename K, typename V>
String _SplayTreeMapNodeCls<K, V>::toString() {
    return __s("MapEntry($key: $value)");
}

template<typename K, typename V>
_SplayTreeMapNodeCls<K, V>::_SplayTreeMapNodeCls(K key, V value) : _SplayTreeNode<K, _SplayTreeMapNode<K, V>>(key) {
}

template<typename K, typename V>
_SplayTreeMapNode<K, V> _SplayTreeMapNodeCls<K, V>::_replaceValue(V value) {
    return _c1;
}

template<typename K, typename Node>
int _SplayTreeCls<K, Node>::_splay(K key) {
    auto _c1 = <K, V>make<_SplayTreeMapNodeCls>(key, value);_c1._left = auto _c2 = _left;_c2._right = _right;_c2;auto root = _root();
    if (root == nullptr) {
        _compare(key, key);
        return -1;
    }
    Node right;
    Node newTreeRight;
    Node left;
    Node newTreeLeft;
    auto current = root;
    auto compare = _compare();
    int comp;
    while (true) {
        comp = compare(current->key, key);
        if (comp > 0) {
            auto currentLeft = current->_left;
            if (currentLeft == nullptr)             {
                break;
            }
            comp = compare(currentLeft->key, key);
            if (comp > 0) {
                current->_left = currentLeft->_right;
                currentLeft->_right = current;
                current = currentLeft;
                currentLeft = current->_left;
                if (currentLeft == nullptr)                 {
                    break;
                }
            }
            if (right == nullptr) {
                newTreeRight = current;
            } else {
                right->_left = current;
            }
            right = current;
            current = currentLeft;
        } else         {
            if ( < 0) {
            auto currentRight = current->_right;
            if (currentRight == nullptr)             {
                break;
            }
            comp = compare(currentRight->key, key);
            if ( < 0) {
                current->_right = currentRight->_left;
                currentRight->_left = current;
                current = currentRight;
                currentRight = current->_right;
                if (currentRight == nullptr)                 {
                    break;
                }
            }
            if (left == nullptr) {
                newTreeLeft = current;
            } else {
                left->_right = current;
            }
            left = current;
            current = currentRight;
        } else {
            break;
        }
;
        }    }
    if (left != nullptr) {
        left->_right = current->_left;
        current->_left = newTreeLeft;
    }
    if (right != nullptr) {
        right->_left = current->_right;
        current->_right = newTreeRight;
    }
    if (!identical(_root(), current)) {
        _root() = current;
        _splayCount++;
    }
    return comp;
}

template<typename K, typename Node>
Node _SplayTreeCls<K, Node>::_splayMin(Node node) {
    auto current = node;
    auto nextLeft = current->_left;
    while (nextLeft != nullptr) {
        auto left = nextLeft;
        current->_left = left->_right;
        left->_right = current;
        current = left;
        nextLeft = current->_left;
    }
    return current;
}

template<typename K, typename Node>
Node _SplayTreeCls<K, Node>::_splayMax(Node node) {
    auto current = node;
    auto nextRight = current->_right;
    while (nextRight != nullptr) {
        auto right = nextRight;
        current->_right = right->_left;
        right->_left = current;
        current = right;
        nextRight = current->_right;
    }
    return current;
}

template<typename K, typename Node>
Node _SplayTreeCls<K, Node>::_remove(K key) {
    if (_root() == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if (comp != 0)     {
        return nullptr;
    }
    auto root = _root()!;
    auto result = root;
    auto left = root->_left;
    _count--;
    if (left == nullptr) {
        _root() = root->_right;
    } else {
        auto right = root->_right;
        root = _splayMax(left);
        root->_right = right;
        _root() = root;
    }
    _modificationCount++;
    return result;
}

template<typename K, typename Node>
void _SplayTreeCls<K, Node>::_addNewRoot(Node node, int comp) {
    _count++;
    _modificationCount++;
    auto root = _root();
    if (root == nullptr) {
        _root() = node;
        return;
    }
    if ( < 0) {
        node->_left = root;
        node->_right = root->_right;
        root->_right = nullptr;
    } else {
        node->_right = root;
        node->_left = root->_left;
        root->_left = nullptr;
    }
    _root() = node;
}

template<typename K, typename Node>
Node _SplayTreeCls<K, Node>::_first() {
    auto root = _root();
    if (root == nullptr)     {
        return nullptr;
    }
    _root() = _splayMin(root);
    return _root();
}

template<typename K, typename Node>
Node _SplayTreeCls<K, Node>::_last() {
    auto root = _root();
    if (root == nullptr)     {
        return nullptr;
    }
    _root() = _splayMax(root);
    return _root();
}

template<typename K, typename Node>
void _SplayTreeCls<K, Node>::_clear() {
    _root() = nullptr;
    _count = 0;
    _modificationCount++;
}

template<typename K, typename Node>
bool _SplayTreeCls<K, Node>::_containsKey(Object key) {
    return _validKey(key) && _splay(as<dynamic>(key)) == 0;
}

int _dynamicCompare(dynamic a, dynamic b) {
    return ComparableCls->compare(a, b);
}

template<typename K>
Comparator<K> _defaultCompare() {
    Object compare = ComparableCls::compare;
    if (is<Comparator<K>>(compare)) {
        return compare;
    }
    return _dynamicCompare;
}

template<typename K, typename V>
SplayTreeMapCls<K, V>::SplayTreeMapCls(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    {
        _compare = compare | <K>_defaultCompare();
        _validKey = isValidKey | ([=] (dynamic a)         {
            is<K>(a);
        });
    }
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::from(Map<dynamic, dynamic> other, std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    if (is<Map<K, V>>(other)) {
        return <K, V>of(as<MapCls>(other), compare, isValidKey);
    }
    SplayTreeMap<K, V> result = <K, V>make<SplayTreeMapCls>(compare, isValidKey);
    other->forEach([=] (dynamic k,dynamic v) {
        result[k] = v;
    });
    return result;
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::of(Map<K, V> other, std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    return _c1;
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::fromIterable(Iterable iterable, std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey, std::function<K(dynamic element)> key, std::function<V(dynamic element)> value) {
    auto _c1 = <K, V>make<SplayTreeMapCls>(compare, isValidKey);_c1.addAll(other);SplayTreeMap<K, V> map = <K, V>make<SplayTreeMapCls>(compare, isValidKey);
    MapBaseCls->_fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::fromIterables(Iterable<K> keys, Iterable<V> values, std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    SplayTreeMap<K, V> map = <K, V>make<SplayTreeMapCls>(compare, isValidKey);
    MapBaseCls->_fillMapWithIterables(map, keys, values);
    return map;
}

template<typename K, typename V>
V SplayTreeMapCls<K, V>::[](Object key) {
    if (!_validKey(key))     {
        return nullptr;
    }
    if (_root != nullptr) {
        int comp = _splay(as<dynamic>(key));
        if (comp == 0) {
            return _root!->value;
        }
    }
    return nullptr;
}

template<typename K, typename V>
V SplayTreeMapCls<K, V>::remove(Object key) {
    if (!_validKey(key))     {
        return nullptr;
    }
    _SplayTreeMapNode<K, V> mapRoot = _remove(as<dynamic>(key));
    if (mapRoot != nullptr)     {
        return mapRoot->value;
    }
    return nullptr;
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::[]=(K key, V value) {
    int comp = _splay(key);
    if (comp == 0) {
        _root = _root!->_replaceValue(value);
        _splayCount += 1;
        return;
    }
    _addNewRoot(make<_SplayTreeMapNodeCls>(key, value), comp);
}

template<typename K, typename V>
V SplayTreeMapCls<K, V>::putIfAbsent(K key, std::function<V()> ifAbsent) {
    int comp = _splay(key);
    if (comp == 0) {
        return _root!->value;
    }
    int modificationCount = _modificationCount;
    int splayCount = _splayCount;
    V value = ifAbsent();
    if (modificationCount != _modificationCount) {
        throw make<ConcurrentModificationErrorCls>(this);
    }
    if (splayCount != _splayCount) {
        comp = _splay(key);
        assert(comp != 0);
    }
    _addNewRoot(make<_SplayTreeMapNodeCls>(key, value), comp);
    return value;
}

template<typename K, typename V>
V SplayTreeMapCls<K, V>::update(K key, std::function<V(V value)> update, std::function<V()> ifAbsent) {
    auto comp = _splay(key);
    if (comp == 0) {
        auto modificationCount = _modificationCount;
        auto splayCount = _splayCount;
        auto newValue = update(_root!->value);
        if (modificationCount != _modificationCount) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        if (splayCount != _splayCount) {
            _splay(key);
        }
        _root = _root!->_replaceValue(newValue);
        _splayCount += 1;
        return newValue;
    }
    if (ifAbsent != nullptr) {
        auto modificationCount = _modificationCount;
        auto splayCount = _splayCount;
        auto newValue = ifAbsent();
        if (modificationCount != _modificationCount) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        if (splayCount != _splayCount) {
            comp = _splay(key);
        }
        _addNewRoot(make<_SplayTreeMapNodeCls>(key, newValue), comp);
        return newValue;
    }
    throw ArgumentErrorCls->value(key, __s("key"), __s("Key not in map."));
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::updateAll(std::function<V(K key, V value)> update) {
    auto root = _root;
    if (root == nullptr)     {
        return;
    }
    auto iterator = make<_SplayTreeMapEntryIteratorCls>(this);
    while (iterator->moveNext()) {
        auto node = iterator->current;
        auto newValue = update(node->key, node->value);
        iterator->_replaceValue(newValue);
    }
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::addAll(Map<K, V> other) {
    other->forEach([=] (K key,V value) {
        this[key] = value;
    });
}

template<typename K, typename V>
bool SplayTreeMapCls<K, V>::isEmpty() {
    return (_root == nullptr);
}

template<typename K, typename V>
bool SplayTreeMapCls<K, V>::isNotEmpty() {
    return !isEmpty();
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::forEach(std::function<void(K key, V value)> f) {
    Iterator<MapEntry<K, V>> nodes = <K, V>make<_SplayTreeMapEntryIteratorCls>(this);
    while (nodes->moveNext()) {
        MapEntry<K, V> node = nodes->current();
        f(node->key, node->value);
    }
}

template<typename K, typename V>
int SplayTreeMapCls<K, V>::length() {
    return _count;
}

template<typename K, typename V>
void SplayTreeMapCls<K, V>::clear() {
    _clear();
}

template<typename K, typename V>
bool SplayTreeMapCls<K, V>::containsKey(Object key) {
    return _containsKey(key);
}

template<typename K, typename V>
bool SplayTreeMapCls<K, V>::containsValue(Object value) {
    int initialSplayCount = _splayCount;
    InlineMethod;
    return visit(_root);
}

template<typename K, typename V>
Iterable<K> SplayTreeMapCls<K, V>::keys() {
    return <K, _SplayTreeMapNode<K, V>>make<_SplayTreeKeyIterableCls>(this);
}

template<typename K, typename V>
Iterable<V> SplayTreeMapCls<K, V>::values() {
    return <K, V>make<_SplayTreeValueIterableCls>(this);
}

template<typename K, typename V>
Iterable<MapEntry<K, V>> SplayTreeMapCls<K, V>::entries() {
    return <K, V>make<_SplayTreeMapEntryIterableCls>(this);
}

template<typename K, typename V>
K SplayTreeMapCls<K, V>::firstKey() {
    if (_root == nullptr)     {
        return nullptr;
    }
    return _first!->key;
}

template<typename K, typename V>
K SplayTreeMapCls<K, V>::lastKey() {
    if (_root == nullptr)     {
        return nullptr;
    }
    return _last!->key;
}

template<typename K, typename V>
K SplayTreeMapCls<K, V>::lastKeyBefore(K key) {
    if (key == nullptr)     {
        throw make<ArgumentErrorCls>(key);
    }
    if (_root == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if ( < 0)     {
        return _root!->key;
    }
    _SplayTreeMapNode<K, V> node = _root!->_left;
    if (node == nullptr)     {
        return nullptr;
    }
    auto nodeRight = node->_right;
    while (nodeRight != nullptr) {
        node = nodeRight;
        nodeRight = node->_right;
    }
    return node!->key;
}

template<typename K, typename V>
K SplayTreeMapCls<K, V>::firstKeyAfter(K key) {
    if (key == nullptr)     {
        throw make<ArgumentErrorCls>(key);
    }
    if (_root == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if (comp > 0)     {
        return _root!->key;
    }
    _SplayTreeMapNode<K, V> node = _root!->_right;
    if (node == nullptr)     {
        return nullptr;
    }
    auto nodeLeft = node->_left;
    while (nodeLeft != nullptr) {
        node = nodeLeft;
        nodeLeft = node->_left;
    }
    return node!->key;
}

template<typename K, typename Node, typename T>
T _SplayTreeIteratorCls<K, Node, T>::current() {
    if (_path->isEmpty)     {
        return as<T>(nullptr);
    }
    auto node = _path->last;
    return _getValue(node);
}

template<typename K, typename Node, typename T>
bool _SplayTreeIteratorCls<K, Node, T>::moveNext() {
    if (_modificationCount != _tree->_modificationCount) {
        if (_modificationCount == nullptr) {
            _modificationCount = _tree->_modificationCount;
            auto node = _tree->_root();
            while (node != nullptr) {
                _path->add(node);
                node = node->_left;
            }
            return _path->isNotEmpty;
        }
        throw make<ConcurrentModificationErrorCls>(_tree);
    }
    if (_path->isEmpty)     {
        return false;
    }
    if (_splayCount != _tree->_splayCount) {
        _rebuildPath(_path->last->key);
    }
    auto node = _path->last;
    auto next = node->_right;
    if (next != nullptr) {
        while (next != nullptr) {
            _path->add(next);
            next = next->_left;
        }
        return true;
    }
    _path->removeLast();
    while (_path->isNotEmpty && identical(_path->last->_right, node)) {
        node = _path->removeLast();
    }
    return _path->isNotEmpty;
}

template<typename K, typename Node, typename T>
_SplayTreeIteratorCls<K, Node, T>::_SplayTreeIteratorCls(_SplayTree<K, Node> tree) {
    {
        _tree = tree;
        _splayCount = tree->_splayCount;
    }
}

template<typename K, typename Node, typename T>
void _SplayTreeIteratorCls<K, Node, T>::_rebuildPath(K key) {
    _path->clear();
    _tree->_splay(key);
    _path->add(_tree->_root()!);
    _splayCount = _tree->_splayCount;
}

template<typename K, typename Node, typename T>
void _SplayTreeIteratorCls<K, Node, T>::_findLeftMostDescendent(Node node) {
    while (node != nullptr) {
        _path->add(node);
        node = node->_left;
    }
}

template<typename K, typename Node>
int _SplayTreeKeyIterableCls<K, Node>::length() {
    return _tree->_count;
}

template<typename K, typename Node>
bool _SplayTreeKeyIterableCls<K, Node>::isEmpty() {
    return _tree->_count == 0;
}

template<typename K, typename Node>
Iterator<K> _SplayTreeKeyIterableCls<K, Node>::iterator() {
    return <K, Node>make<_SplayTreeKeyIteratorCls>(_tree);
}

template<typename K, typename Node>
bool _SplayTreeKeyIterableCls<K, Node>::contains(Object o) {
    return _tree->_containsKey(o);
}

template<typename K, typename Node>
Set<K> _SplayTreeKeyIterableCls<K, Node>::toSet() {
    SplayTreeSet<K> set = <K>make<SplayTreeSetCls>(_tree->_compare(), _tree->_validKey());
    set->_count = _tree->_count;
    set->_root = set-><Node>_copyNode(_tree->_root());
    return set;
}

template<typename K, typename V>
int _SplayTreeValueIterableCls<K, V>::length() {
    return _map->_count;
}

template<typename K, typename V>
bool _SplayTreeValueIterableCls<K, V>::isEmpty() {
    return _map->_count == 0;
}

template<typename K, typename V>
Iterator<V> _SplayTreeValueIterableCls<K, V>::iterator() {
    return <K, V>make<_SplayTreeValueIteratorCls>(_map);
}

template<typename K, typename V>
int _SplayTreeMapEntryIterableCls<K, V>::length() {
    return _map->_count;
}

template<typename K, typename V>
bool _SplayTreeMapEntryIterableCls<K, V>::isEmpty() {
    return _map->_count == 0;
}

template<typename K, typename V>
Iterator<MapEntry<K, V>> _SplayTreeMapEntryIterableCls<K, V>::iterator() {
    return <K, V>make<_SplayTreeMapEntryIteratorCls>(_map);
}

template<typename K, typename Node>
_SplayTreeKeyIteratorCls<K, Node>::_SplayTreeKeyIteratorCls(_SplayTree<K, Node> map) : _SplayTreeIterator<K, Node, K>(map) {
}

template<typename K, typename Node>
K _SplayTreeKeyIteratorCls<K, Node>::_getValue(Node node) {
    return node->key;
}

template<typename K, typename V>
_SplayTreeValueIteratorCls<K, V>::_SplayTreeValueIteratorCls(SplayTreeMap<K, V> map) : _SplayTreeIterator<K, _SplayTreeMapNode<K, V>, V>(map) {
}

template<typename K, typename V>
V _SplayTreeValueIteratorCls<K, V>::_getValue(_SplayTreeMapNode<K, V> node) {
    return node->value;
}

template<typename K, typename V>
_SplayTreeMapEntryIteratorCls<K, V>::_SplayTreeMapEntryIteratorCls(SplayTreeMap<K, V> tree) : _SplayTreeIterator<K, _SplayTreeMapNode<K, V>, MapEntry<K, V>>(tree) {
}

template<typename K, typename V>
MapEntry<K, V> _SplayTreeMapEntryIteratorCls<K, V>::_getValue(_SplayTreeMapNode<K, V> node) {
    return node;
}

template<typename K, typename V>
void _SplayTreeMapEntryIteratorCls<K, V>::_replaceValue(V value) {
    assert(_path->isNotEmpty);
    if (_modificationCount != _tree->_modificationCount) {
        throw make<ConcurrentModificationErrorCls>(_tree);
    }
    if (_splayCount != _tree->_splayCount) {
        _rebuildPath(_path->last->key);
    }
    auto last = _path->removeLast();
    auto newLast = last->_replaceValue(value);
    if (_path->isEmpty) {
        _tree->_root = newLast;
    } else {
        auto parent = _path->last;
        if (identical(last, parent->_left)) {
            parent->_left = newLast;
        } else {
            assert(identical(last, parent->_right));
            parent->_right = newLast;
        }
    }
    _path->add(newLast);
    _splayCount = ++_tree->_splayCount;
}

template<typename E>
SplayTreeSetCls<E>::SplayTreeSetCls(std::function<int(E key1, E key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    {
        _compare = compare | <E>_defaultCompare();
        _validKey = isValidKey | ([=] (dynamic v)         {
            is<E>(v);
        });
    }
}

template<typename E>
void SplayTreeSetCls<E>::from(Iterable elements, std::function<int(E key1, E key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    if (is<Iterable<E>>(elements)) {
        return <E>of(as<IterableCls>(elements), compare, isValidKey);
    }
    SplayTreeSet<E> result = <E>make<SplayTreeSetCls>(compare, isValidKey);
    for (auto element : elements) {
        result->add(as<dynamic>(element));
    }
    return result;
}

template<typename E>
void SplayTreeSetCls<E>::of(Iterable<E> elements, std::function<int(E key1, E key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey) {
    return _c1;
}

template<typename E>
template<typename R>
Set<R> SplayTreeSetCls<E>::cast() {
    return SetCls-><E, R>castFrom(this_newSet);
}

template<typename E>
Iterator<E> SplayTreeSetCls<E>::iterator() {
    return <E, _SplayTreeSetNode<E>>make<_SplayTreeKeyIteratorCls>(this);
}

template<typename E>
int SplayTreeSetCls<E>::length() {
    return _count;
}

template<typename E>
bool SplayTreeSetCls<E>::isEmpty() {
    return _root == nullptr;
}

template<typename E>
bool SplayTreeSetCls<E>::isNotEmpty() {
    return _root != nullptr;
}

template<typename E>
E SplayTreeSetCls<E>::first() {
    auto _c1 = make<SplayTreeSetCls>(compare, isValidKey);_c1.addAll(elements);if (_count == 0)     {
        throw IterableElementErrorCls->noElement();
    }
    return _first!->key;
}

template<typename E>
E SplayTreeSetCls<E>::last() {
    if (_count == 0)     {
        throw IterableElementErrorCls->noElement();
    }
    return _last!->key;
}

template<typename E>
E SplayTreeSetCls<E>::single() {
    if (_count == 0)     {
        throw IterableElementErrorCls->noElement();
    }
    if (_count > 1)     {
        throw IterableElementErrorCls->tooMany();
    }
    return _root!->key;
}

template<typename E>
bool SplayTreeSetCls<E>::contains(Object element) {
    return _validKey(element) && _splay(as<E>(element)) == 0;
}

template<typename E>
bool SplayTreeSetCls<E>::add(E element) {
    return _add(element);
}

template<typename E>
bool SplayTreeSetCls<E>::remove(Object object) {
    if (!_validKey(object))     {
        return false;
    }
    return _remove(as<E>(object)) != nullptr;
}

template<typename E>
void SplayTreeSetCls<E>::addAll(Iterable<E> elements) {
    for (E element : elements) {
        _add(element);
    }
}

template<typename E>
void SplayTreeSetCls<E>::removeAll(Iterable<Object> elements) {
    for (Object element : elements) {
        if (_validKey(element))         {
            _remove(as<E>(element));
        }
    }
}

template<typename E>
void SplayTreeSetCls<E>::retainAll(Iterable<Object> elements) {
    SplayTreeSet<E> retainSet = <E>make<SplayTreeSetCls>(_compare, _validKey);
    int modificationCount = _modificationCount;
    for (Object object : elements) {
        if (modificationCount != _modificationCount) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        if (_validKey(object) && _splay(as<E>(object)) == 0) {
            retainSet->add(_root!->key);
        }
    }
    if (retainSet->_count != _count) {
        _root = retainSet->_root;
        _count = retainSet->_count;
        _modificationCount++;
    }
}

template<typename E>
E SplayTreeSetCls<E>::lookup(Object object) {
    if (!_validKey(object))     {
        return nullptr;
    }
    int comp = _splay(as<E>(object));
    if (comp != 0)     {
        return nullptr;
    }
    return _root!->key;
}

template<typename E>
Set<E> SplayTreeSetCls<E>::intersection(Set<Object> other) {
    Set<E> result = <E>make<SplayTreeSetCls>(_compare, _validKey);
    for (E element : this) {
        if (other->contains(element))         {
            result->add(element);
        }
    }
    return result;
}

template<typename E>
Set<E> SplayTreeSetCls<E>::difference(Set<Object> other) {
    Set<E> result = <E>make<SplayTreeSetCls>(_compare, _validKey);
    for (E element : this) {
        if (!other->contains(element))         {
            result->add(element);
        }
    }
    return result;
}

template<typename E>
Set<E> SplayTreeSetCls<E>::union(Set<E> other) {
    auto _c1 = _clone();_c1.addAll(other);return _c1;
}

template<typename E>
void SplayTreeSetCls<E>::clear() {
    _clear();
}

template<typename E>
Set<E> SplayTreeSetCls<E>::toSet() {
    return _clone();
}

template<typename E>
String SplayTreeSetCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("{"), __s("}"));
}

template<typename E>
template<typename T>
Set<T> SplayTreeSetCls<E>::_newSet() {
    return <T>make<SplayTreeSetCls>([=] (T a,T b)     {
        _compare(as<E>(a), as<E>(b));
    }, _validKey);
}

template<typename E>
bool SplayTreeSetCls<E>::_add(E element) {
    int compare = _splay(element);
    if (compare == 0)     {
        return false;
    }
    _addNewRoot(make<_SplayTreeSetNodeCls>(element), compare);
    return true;
}

template<typename E>
SplayTreeSet<E> SplayTreeSetCls<E>::_clone() {
    auto set = <E>make<SplayTreeSetCls>(_compare, _validKey);
    set->_count = _count;
    set->_root = <_SplayTreeSetNode<E>>_copyNode(_root);
    return set;
}

template<typename E>
template<typename Node>
_SplayTreeSetNode<E> SplayTreeSetCls<E>::_copyNode(Node node) {
    if (node == nullptr)     {
        return nullptr;
    }
    InlineMethod;
    auto result = <E>make<_SplayTreeSetNodeCls>(node->key);
    copyChildren(node, result);
    return result;
}
