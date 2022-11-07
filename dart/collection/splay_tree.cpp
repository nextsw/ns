#include "splay_tree.hpp"
_SplayTreeSetNode::_SplayTreeSetNode(K key) {
    {
        super(key);
    }
}

String _SplayTreeMapNode::toString() {
    return "MapEntry($key: $value)";
}

_SplayTreeMapNode::_SplayTreeMapNode(K key, V value) {
    {
        super(key);
    }
}

_SplayTreeMapNode<K, V> _SplayTreeMapNode::_replaceValue(V value) {
    return ;
}

int _SplayTree::_splay(K key) {
    auto root = _root;
    if (root == nullptr) {
        _compare(key, key);
        return -1;
    }
    Node right;
    Node newTreeRight;
    Node left;
    Node newTreeLeft;
    auto current = root;
    auto compare = _compare;
    int comp;
    while (true) {
        comp = compare(current.key, key);
        if (comp > 0) {
            auto currentLeft = current._left;
            if (currentLeft == nullptr)             {
                            break;
            }
            comp = compare(currentLeft.key, key);
            if (comp > 0) {
                current._left = currentLeft._right;
                currentLeft._right = current;
                current = currentLeft;
                currentLeft = current._left;
                if (currentLeft == nullptr)                 {
                                    break;
                }
            }
            if (right == nullptr) {
                newTreeRight = current;
            } else {
                right._left = current;
            }
            right = current;
            current = currentLeft;
        } else         {
            if ( < 0) {
            auto currentRight = current._right;
            if (currentRight == nullptr)             {
                            break;
            }
            comp = compare(currentRight.key, key);
            if ( < 0) {
                current._right = currentRight._left;
                currentRight._left = current;
                current = currentRight;
                currentRight = current._right;
                if (currentRight == nullptr)                 {
                                    break;
                }
            }
            if (left == nullptr) {
                newTreeLeft = current;
            } else {
                left._right = current;
            }
            left = current;
            current = currentRight;
        } else {
                        break;
        }
;
        }    }
    if (left != nullptr) {
        left._right = current._left;
        current._left = newTreeLeft;
    }
    if (right != nullptr) {
        right._left = current._right;
        current._right = newTreeRight;
    }
    if (!identical(_root, current)) {
        _root = current;
        _splayCount++;
    }
    return comp;
}

Node _SplayTree::_splayMin(Node node) {
    auto current = node;
    auto nextLeft = current._left;
    while (nextLeft != nullptr) {
        auto left = nextLeft;
        current._left = left._right;
        left._right = current;
        current = left;
        nextLeft = current._left;
    }
    return current;
}

Node _SplayTree::_splayMax(Node node) {
    auto current = node;
    auto nextRight = current._right;
    while (nextRight != nullptr) {
        auto right = nextRight;
        current._right = right._left;
        right._left = current;
        current = right;
        nextRight = current._right;
    }
    return current;
}

Node _SplayTree::_remove(K key) {
    if (_root == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if (comp != 0)     {
        return nullptr;
    }
    auto root = _root!;
    auto result = root;
    auto left = root._left;
    _count--;
    if (left == nullptr) {
        _root = root._right;
    } else {
        auto right = root._right;
        root = _splayMax(left);
        root._right = right;
        _root = root;
    }
    _modificationCount++;
    return result;
}

void _SplayTree::_addNewRoot(int comp, Node node) {
    _count++;
    _modificationCount++;
    auto root = _root;
    if (root == nullptr) {
        _root = node;
        return;
    }
    if ( < 0) {
        node._left = root;
        node._right = root._right;
        root._right = nullptr;
    } else {
        node._right = root;
        node._left = root._left;
        root._left = nullptr;
    }
    _root = node;
}

Node _SplayTree::_first() {
    auto root = _root;
    if (root == nullptr)     {
        return nullptr;
    }
    _root = _splayMin(root);
    return _root;
}

Node _SplayTree::_last() {
    auto root = _root;
    if (root == nullptr)     {
        return nullptr;
    }
    _root = _splayMax(root);
    return _root;
}

void _SplayTree::_clear() {
    _root = nullptr;
    _count = 0;
    _modificationCount++;
}

bool _SplayTree::_containsKey(Object key) {
    return _validKey(key) && _splay(() == 0;
}

int _dynamicCompare(dynamic a, dynamic b) {
    return Comparable.compare(a, b);
}

Comparator<K> _defaultCompare<K>() {
    Object compare = Comparable.compare;
    if (compare is Comparator<K>) {
        return compare;
    }
    return _dynamicCompare;
}

SplayTreeMap::SplayTreeMap(FunctionType compare, FunctionType isValidKey) {
    {
        _compare = compare ?? <K>_defaultCompare();
        _validKey = isValidKey ?? ();
    }
}

void SplayTreeMap::from(FunctionType compare, FunctionType isValidKey, Map<dynamic, dynamic> other) {
    if (other is Map<K, V>) {
        return <K, V>of(other, compare, isValidKey);
    }
    SplayTreeMap<K, V> result = <K, V>SplayTreeMap(compare, isValidKey);
    other.forEach();
    return result;
}

void SplayTreeMap::of(FunctionType compare, FunctionType isValidKey, Map<K, V> other) {
    return ;
}

void SplayTreeMap::fromIterable(FunctionType compare, FunctionType isValidKey, Iterable iterable, FunctionType key, FunctionType value) {
    SplayTreeMap<K, V> map = <K, V>SplayTreeMap(compare, isValidKey);
    MapBase._fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

void SplayTreeMap::fromIterables(FunctionType compare, FunctionType isValidKey, Iterable<K> keys, Iterable<V> values) {
    SplayTreeMap<K, V> map = <K, V>SplayTreeMap(compare, isValidKey);
    MapBase._fillMapWithIterables(map, keys, values);
    return map;
}

V SplayTreeMap::[](Object key) {
    if (!_validKey(key))     {
        return nullptr;
    }
    if (_root != nullptr) {
        int comp = _splay(();
        if (comp == 0) {
            return _root!.value;
        }
    }
    return nullptr;
}

V SplayTreeMap::remove(Object key) {
    if (!_validKey(key))     {
        return nullptr;
    }
    _SplayTreeMapNode<K, V> mapRoot = _remove(();
    if (mapRoot != nullptr)     {
        return mapRoot.value;
    }
    return nullptr;
}

void SplayTreeMap::[]=(K key, V value) {
    int comp = _splay(key);
    if (comp == 0) {
        _root = _root!._replaceValue(value);
        _splayCount = 1;
        return;
    }
    _addNewRoot(_SplayTreeMapNode(key, value), comp);
}

V SplayTreeMap::putIfAbsent(FunctionType ifAbsent, K key) {
    int comp = _splay(key);
    if (comp == 0) {
        return _root!.value;
    }
    int modificationCount = _modificationCount;
    int splayCount = _splayCount;
    V value = ifAbsent();
    if (modificationCount != _modificationCount) {
        ;
    }
    if (splayCount != _splayCount) {
        comp = _splay(key);
        assert(comp != 0);
    }
    _addNewRoot(_SplayTreeMapNode(key, value), comp);
    return value;
}

V SplayTreeMap::update(FunctionType ifAbsent, K key, FunctionType update) {
    auto comp = _splay(key);
    if (comp == 0) {
        auto modificationCount = _modificationCount;
        auto splayCount = _splayCount;
        auto newValue = update(_root!.value);
        if (modificationCount != _modificationCount) {
            ;
        }
        if (splayCount != _splayCount) {
            _splay(key);
        }
        _root = _root!._replaceValue(newValue);
        _splayCount = 1;
        return newValue;
    }
    if (ifAbsent != nullptr) {
        auto modificationCount = _modificationCount;
        auto splayCount = _splayCount;
        auto newValue = ifAbsent();
        if (modificationCount != _modificationCount) {
            ;
        }
        if (splayCount != _splayCount) {
            comp = _splay(key);
        }
        _addNewRoot(_SplayTreeMapNode(key, newValue), comp);
        return newValue;
    }
    ;
}

void SplayTreeMap::updateAll(FunctionType update) {
    auto root = _root;
    if (root == nullptr)     {
        return;
    }
    auto iterator = _SplayTreeMapEntryIterator(this);
    while (iterator.moveNext()) {
        auto node = iterator.current;
        auto newValue = update(node.key, node.value);
        iterator._replaceValue(newValue);
    }
}

void SplayTreeMap::addAll(Map<K, V> other) {
    other.forEach();
}

bool SplayTreeMap::isEmpty() {
    return (_root == nullptr);
}

bool SplayTreeMap::isNotEmpty() {
    return !isEmpty;
}

void SplayTreeMap::forEach(FunctionType f) {
    Iterator<MapEntry<K, V>> nodes = <K, V>_SplayTreeMapEntryIterator(this);
    while (nodes.moveNext()) {
        MapEntry<K, V> node = nodes.current;
        f(node.key, node.value);
    }
}

int SplayTreeMap::length() {
    return _count;
}

void SplayTreeMap::clear() {
    _clear();
}

bool SplayTreeMap::containsKey(Object key) {
    return _containsKey(key);
}

bool SplayTreeMap::containsValue(Object value) {
    int initialSplayCount = _splayCount;
    ;
    return visit(_root);
}

Iterable<K> SplayTreeMap::keys() {
    return <K, _SplayTreeMapNode<K, V>>_SplayTreeKeyIterable(this);
}

Iterable<V> SplayTreeMap::values() {
    return <K, V>_SplayTreeValueIterable(this);
}

Iterable<MapEntry<K, V>> SplayTreeMap::entries() {
    return <K, V>_SplayTreeMapEntryIterable(this);
}

K SplayTreeMap::firstKey() {
    if (_root == nullptr)     {
        return nullptr;
    }
    return _first!.key;
}

K SplayTreeMap::lastKey() {
    if (_root == nullptr)     {
        return nullptr;
    }
    return _last!.key;
}

K SplayTreeMap::lastKeyBefore(K key) {
    if (key == nullptr)     {
        ;
    }
    if (_root == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if ( < 0)     {
        return _root!.key;
    }
    _SplayTreeMapNode<K, V> node = _root!._left;
    if (node == nullptr)     {
        return nullptr;
    }
    auto nodeRight = node._right;
    while (nodeRight != nullptr) {
        node = nodeRight;
        nodeRight = node._right;
    }
    return node!.key;
}

K SplayTreeMap::firstKeyAfter(K key) {
    if (key == nullptr)     {
        ;
    }
    if (_root == nullptr)     {
        return nullptr;
    }
    int comp = _splay(key);
    if (comp > 0)     {
        return _root!.key;
    }
    _SplayTreeMapNode<K, V> node = _root!._right;
    if (node == nullptr)     {
        return nullptr;
    }
    auto nodeLeft = node._left;
    while (nodeLeft != nullptr) {
        node = nodeLeft;
        nodeLeft = node._left;
    }
    return node!.key;
}

T _SplayTreeIterator::current() {
    if (_path.isEmpty)     {
        return (;
    }
    auto node = _path.last;
    return _getValue(node);
}

bool _SplayTreeIterator::moveNext() {
    if (_modificationCount != _tree._modificationCount) {
        if (_modificationCount == nullptr) {
            _modificationCount = _tree._modificationCount;
            auto node = _tree._root;
            while (node != nullptr) {
                _path.add(node);
                node = node._left;
            }
            return _path.isNotEmpty;
        }
        ;
    }
    if (_path.isEmpty)     {
        return false;
    }
    if (_splayCount != _tree._splayCount) {
        _rebuildPath(_path.last.key);
    }
    auto node = _path.last;
    auto next = node._right;
    if (next != nullptr) {
        while (next != nullptr) {
            _path.add(next);
            next = next._left;
        }
        return true;
    }
    _path.removeLast();
    while (_path.isNotEmpty && identical(_path.last._right, node)) {
        node = _path.removeLast();
    }
    return _path.isNotEmpty;
}

_SplayTreeIterator::_SplayTreeIterator(_SplayTree<K, Node> tree) {
    {
        _tree = tree;
        _splayCount = tree._splayCount;
    }
}

void _SplayTreeIterator::_rebuildPath(K key) {
    _path.clear();
    _tree._splay(key);
    _path.add(_tree._root!);
    _splayCount = _tree._splayCount;
}

void _SplayTreeIterator::_findLeftMostDescendent(Node node) {
    while (node != nullptr) {
        _path.add(node);
        node = node._left;
    }
}

int _SplayTreeKeyIterable::length() {
    return _tree._count;
}

bool _SplayTreeKeyIterable::isEmpty() {
    return _tree._count == 0;
}

Iterator<K> _SplayTreeKeyIterable::iterator() {
    return <K, Node>_SplayTreeKeyIterator(_tree);
}

bool _SplayTreeKeyIterable::contains(Object o) {
    return _tree._containsKey(o);
}

Set<K> _SplayTreeKeyIterable::toSet() {
    SplayTreeSet<K> set = <K>SplayTreeSet(_tree._compare, _tree._validKey);
    set._count = _tree._count;
    set._root = set.<Node>_copyNode(_tree._root);
    return set;
}

int _SplayTreeValueIterable::length() {
    return _map._count;
}

bool _SplayTreeValueIterable::isEmpty() {
    return _map._count == 0;
}

Iterator<V> _SplayTreeValueIterable::iterator() {
    return <K, V>_SplayTreeValueIterator(_map);
}

int _SplayTreeMapEntryIterable::length() {
    return _map._count;
}

bool _SplayTreeMapEntryIterable::isEmpty() {
    return _map._count == 0;
}

Iterator<MapEntry<K, V>> _SplayTreeMapEntryIterable::iterator() {
    return <K, V>_SplayTreeMapEntryIterator(_map);
}

_SplayTreeKeyIterator::_SplayTreeKeyIterator(_SplayTree<K, Node> map) {
    {
        super(map);
    }
}

K _SplayTreeKeyIterator::_getValue(Node node) {
    return node.key;
}

_SplayTreeValueIterator::_SplayTreeValueIterator(SplayTreeMap<K, V> map) {
    {
        super(map);
    }
}

V _SplayTreeValueIterator::_getValue(_SplayTreeMapNode<K, V> node) {
    return node.value;
}

_SplayTreeMapEntryIterator::_SplayTreeMapEntryIterator(SplayTreeMap<K, V> tree) {
    {
        super(tree);
    }
}

MapEntry<K, V> _SplayTreeMapEntryIterator::_getValue(_SplayTreeMapNode<K, V> node) {
    return node;
}

void _SplayTreeMapEntryIterator::_replaceValue(V value) {
    assert(_path.isNotEmpty);
    if (_modificationCount != _tree._modificationCount) {
        ;
    }
    if (_splayCount != _tree._splayCount) {
        _rebuildPath(_path.last.key);
    }
    auto last = _path.removeLast();
    auto newLast = last._replaceValue(value);
    if (_path.isEmpty) {
        _tree._root = newLast;
    } else {
        auto parent = _path.last;
        if (identical(last, parent._left)) {
            parent._left = newLast;
        } else {
            assert(identical(last, parent._right));
            parent._right = newLast;
        }
    }
    _path.add(newLast);
    _splayCount = ++_tree._splayCount;
}

SplayTreeSet::SplayTreeSet(FunctionType compare, FunctionType isValidKey) {
    {
        _compare = compare ?? <E>_defaultCompare();
        _validKey = isValidKey ?? ();
    }
}

void SplayTreeSet::from(FunctionType compare, Iterable elements, FunctionType isValidKey) {
    if (elements is Iterable<E>) {
        return <E>of(elements, compare, isValidKey);
    }
    SplayTreeSet<E> result = <E>SplayTreeSet(compare, isValidKey);
    for (auto element : elements) {
        result.add(();
    }
    return result;
}

void SplayTreeSet::of(FunctionType compare, Iterable<E> elements, FunctionType isValidKey) {
    return ;
}

Set<R> SplayTreeSet::cast<R>() {
    return Set.<E, R>castFrom(this_newSet);
}

Iterator<E> SplayTreeSet::iterator() {
    return <E, _SplayTreeSetNode<E>>_SplayTreeKeyIterator(this);
}

int SplayTreeSet::length() {
    return _count;
}

bool SplayTreeSet::isEmpty() {
    return _root == nullptr;
}

bool SplayTreeSet::isNotEmpty() {
    return _root != nullptr;
}

E SplayTreeSet::first() {
    if (_count == 0)     {
        ;
    }
    return _first!.key;
}

E SplayTreeSet::last() {
    if (_count == 0)     {
        ;
    }
    return _last!.key;
}

E SplayTreeSet::single() {
    if (_count == 0)     {
        ;
    }
    if (_count > 1)     {
        ;
    }
    return _root!.key;
}

bool SplayTreeSet::contains(Object element) {
    return _validKey(element) && _splay(() == 0;
}

bool SplayTreeSet::add(E element) {
    return _add(element);
}

bool SplayTreeSet::remove(Object object) {
    if (!_validKey(object))     {
        return false;
    }
    return _remove(() != nullptr;
}

void SplayTreeSet::addAll(Iterable<E> elements) {
    for (E element : elements) {
        _add(element);
    }
}

void SplayTreeSet::removeAll(Iterable<Object> elements) {
    for (Object element : elements) {
        if (_validKey(element))         {
            _remove(();
        }
    }
}

void SplayTreeSet::retainAll(Iterable<Object> elements) {
    SplayTreeSet<E> retainSet = <E>SplayTreeSet(_compare, _validKey);
    int modificationCount = _modificationCount;
    for (Object object : elements) {
        if (modificationCount != _modificationCount) {
            ;
        }
        if (_validKey(object) && _splay(() == 0) {
            retainSet.add(_root!.key);
        }
    }
    if (retainSet._count != _count) {
        _root = retainSet._root;
        _count = retainSet._count;
        _modificationCount++;
    }
}

E SplayTreeSet::lookup(Object object) {
    if (!_validKey(object))     {
        return nullptr;
    }
    int comp = _splay(();
    if (comp != 0)     {
        return nullptr;
    }
    return _root!.key;
}

Set<E> SplayTreeSet::intersection(Set<Object> other) {
    Set<E> result = <E>SplayTreeSet(_compare, _validKey);
    for (E element : this) {
        if (other.contains(element))         {
            result.add(element);
        }
    }
    return result;
}

Set<E> SplayTreeSet::difference(Set<Object> other) {
    Set<E> result = <E>SplayTreeSet(_compare, _validKey);
    for (E element : this) {
        if (!other.contains(element))         {
            result.add(element);
        }
    }
    return result;
}

Set<E> SplayTreeSet::union(Set<E> other) {
    return ;
}

void SplayTreeSet::clear() {
    _clear();
}

Set<E> SplayTreeSet::toSet() {
    return _clone();
}

String SplayTreeSet::toString() {
    return IterableBase.iterableToFullString(this, "{", "}");
}

Set<T> SplayTreeSet::_newSet<T>() {
    return <T>SplayTreeSet(, _validKey);
}

bool SplayTreeSet::_add(E element) {
    int compare = _splay(element);
    if (compare == 0)     {
        return false;
    }
    _addNewRoot(_SplayTreeSetNode(element), compare);
    return true;
}

SplayTreeSet<E> SplayTreeSet::_clone() {
    auto set = <E>SplayTreeSet(_compare, _validKey);
    set._count = _count;
    set._root = <_SplayTreeSetNode<E>>_copyNode(_root);
    return set;
}

_SplayTreeSetNode<E> SplayTreeSet::_copyNode<Node extends _SplayTreeNode<E, Node>>(Node node) {
    if (node == nullptr)     {
        return nullptr;
    }
    ;
    auto result = <E>_SplayTreeSetNode(node.key);
    copyChildren(node, result);
    return result;
}
