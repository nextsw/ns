#ifndef DART_COLLECTION_SPLAY_TREE
#define DART_COLLECTION_SPLAY_TREE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename K, typename Node>
class _SplayTreeNodeCls : public ObjectCls {
public:
    K key;


private:
    Node _left;

    Node _right;


     _SplayTreeNodeCls(K key);
};
template<typename K, typename Node>
using _SplayTreeNode = std::shared_ptr<_SplayTreeNodeCls<K, Node>>;

template<typename K>
class _SplayTreeSetNodeCls : public _SplayTreeNodeCls<K, _SplayTreeSetNode<K>> {
public:

private:

     _SplayTreeSetNodeCls(K key);

};
template<typename K>
using _SplayTreeSetNode = std::shared_ptr<_SplayTreeSetNodeCls<K>>;

template<typename K, typename V>
class _SplayTreeMapNodeCls : public _SplayTreeNodeCls<K, _SplayTreeMapNode<K, V>> {
public:
    V value;


    virtual String toString();

private:

     _SplayTreeMapNodeCls(K key, V value);

    virtual _SplayTreeMapNode<K, V> _replaceValue(V value);

};
template<typename K, typename V>
using _SplayTreeMapNode = std::shared_ptr<_SplayTreeMapNodeCls<K, V>>;

template<typename K, typename Node>
class _SplayTreeCls : public ObjectCls {
public:

private:
    int _count;

    int _modificationCount;

    int _splayCount;


    virtual Node _root();
    virtual void  _root(Node newValue);
    virtual Comparator<K> _compare();
    virtual _Predicate _validKey();
    virtual int _splay(K key);

    virtual Node _splayMin(Node node);

    virtual Node _splayMax(Node node);

    virtual Node _remove(K key);

    virtual void _addNewRoot(int comp, Node node);

    virtual Node _first();

    virtual Node _last();

    virtual void _clear();

    virtual bool _containsKey(Object key);

};
template<typename K, typename Node>
using _SplayTree = std::shared_ptr<_SplayTreeCls<K, Node>>;
int _dynamicCompare(dynamic a, dynamic b);

template<typename K>
 Comparator<K> _defaultCompare();


template<typename K, typename V>
class SplayTreeMapCls : public _SplayTreeCls<K, _SplayTreeMapNode<K, V>> {
public:

     SplayTreeMapCls(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey);

    virtual void  from(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey, Map<dynamic, dynamic> other);

    virtual void  of(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey, Map<K, V> other);

    virtual void  fromIterable(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey, Iterable iterable, std::function<K(dynamic element)> key, std::function<V(dynamic element)> value);

    virtual void  fromIterables(std::function<int(K key1, K key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey, Iterable<K> keys, Iterable<V> values);

    virtual V operator[](Object key);

    virtual V remove(Object key);

    virtual void operator[]=(K key, V value);

    virtual V putIfAbsent(std::function<V()> ifAbsent, K key);

    virtual V update(std::function<V()> ifAbsent, K key, std::function<V(V value)> update);

    virtual void updateAll(std::function<V(K key, V value)> update);

    virtual void addAll(Map<K, V> other);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual void forEach(std::function<void(K key, V value)> f);

    virtual int length();

    virtual void clear();

    virtual bool containsKey(Object key);

    virtual bool containsValue(Object value);

    virtual Iterable<K> keys();

    virtual Iterable<V> values();

    virtual Iterable<MapEntry<K, V>> entries();

    virtual K firstKey();

    virtual K lastKey();

    virtual K lastKeyBefore(K key);

    virtual K firstKeyAfter(K key);

private:
    _SplayTreeMapNode<K, V> _root;

    Comparator<K> _compare;

    _Predicate _validKey;


};
template<typename K, typename V>
using SplayTreeMap = std::shared_ptr<SplayTreeMapCls<K, V>>;

template<typename K, typename Node, typename T>
class _SplayTreeIteratorCls : public ObjectCls {
public:

    virtual T current();

    virtual bool moveNext();

private:
    _SplayTree<K, Node> _tree;

    List<Node> _path;

    int _modificationCount;

    int _splayCount;


     _SplayTreeIteratorCls(_SplayTree<K, Node> tree);

    virtual void _rebuildPath(K key);

    virtual void _findLeftMostDescendent(Node node);

    virtual T _getValue(Node node);
};
template<typename K, typename Node, typename T>
using _SplayTreeIterator = std::shared_ptr<_SplayTreeIteratorCls<K, Node, T>>;

template<typename K, typename Node>
class _SplayTreeKeyIterableCls : public EfficientLengthIterableCls<K> {
public:

    virtual int length();

    virtual bool isEmpty();

    virtual Iterator<K> iterator();

    virtual bool contains(Object o);

    virtual Set<K> toSet();

private:
    _SplayTree<K, Node> _tree;


     _SplayTreeKeyIterableCls(_SplayTree<K, Node> _tree);
};
template<typename K, typename Node>
using _SplayTreeKeyIterable = std::shared_ptr<_SplayTreeKeyIterableCls<K, Node>>;

template<typename K, typename V>
class _SplayTreeValueIterableCls : public EfficientLengthIterableCls<V> {
public:

    virtual int length();

    virtual bool isEmpty();

    virtual Iterator<V> iterator();

private:
    SplayTreeMap<K, V> _map;


     _SplayTreeValueIterableCls(SplayTreeMap<K, V> _map);
};
template<typename K, typename V>
using _SplayTreeValueIterable = std::shared_ptr<_SplayTreeValueIterableCls<K, V>>;

template<typename K, typename V>
class _SplayTreeMapEntryIterableCls : public EfficientLengthIterableCls<MapEntry<K, V>> {
public:

    virtual int length();

    virtual bool isEmpty();

    virtual Iterator<MapEntry<K, V>> iterator();

private:
    SplayTreeMap<K, V> _map;


     _SplayTreeMapEntryIterableCls(SplayTreeMap<K, V> _map);
};
template<typename K, typename V>
using _SplayTreeMapEntryIterable = std::shared_ptr<_SplayTreeMapEntryIterableCls<K, V>>;

template<typename K, typename Node>
class _SplayTreeKeyIteratorCls : public _SplayTreeIteratorCls<K, Node, K> {
public:

private:

     _SplayTreeKeyIteratorCls(_SplayTree<K, Node> map);

    virtual K _getValue(Node node);

};
template<typename K, typename Node>
using _SplayTreeKeyIterator = std::shared_ptr<_SplayTreeKeyIteratorCls<K, Node>>;

template<typename K, typename V>
class _SplayTreeValueIteratorCls : public _SplayTreeIteratorCls<K, _SplayTreeMapNode<K, V>, V> {
public:

private:

     _SplayTreeValueIteratorCls(SplayTreeMap<K, V> map);

    virtual V _getValue(_SplayTreeMapNode<K, V> node);

};
template<typename K, typename V>
using _SplayTreeValueIterator = std::shared_ptr<_SplayTreeValueIteratorCls<K, V>>;

template<typename K, typename V>
class _SplayTreeMapEntryIteratorCls : public _SplayTreeIteratorCls<K, _SplayTreeMapNode<K, V>, MapEntry<K, V>> {
public:

private:

     _SplayTreeMapEntryIteratorCls(SplayTreeMap<K, V> tree);

    virtual MapEntry<K, V> _getValue(_SplayTreeMapNode<K, V> node);

    virtual void _replaceValue(V value);

};
template<typename K, typename V>
using _SplayTreeMapEntryIterator = std::shared_ptr<_SplayTreeMapEntryIteratorCls<K, V>>;

template<typename E>
class SplayTreeSetCls : public _SplayTreeCls<E, _SplayTreeSetNode<E>> {
public:

     SplayTreeSetCls(std::function<int(E key1, E key2)> compare, std::function<bool(dynamic potentialKey)> isValidKey);

    virtual void  from(std::function<int(E key1, E key2)> compare, Iterable elements, std::function<bool(dynamic potentialKey)> isValidKey);

    virtual void  of(std::function<int(E key1, E key2)> compare, Iterable<E> elements, std::function<bool(dynamic potentialKey)> isValidKey);

    template<typename R>
 virtual Set<R> cast();

    virtual Iterator<E> iterator();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual E first();

    virtual E last();

    virtual E single();

    virtual bool contains(Object element);

    virtual bool add(E element);

    virtual bool remove(Object object);

    virtual void addAll(Iterable<E> elements);

    virtual void removeAll(Iterable<Object> elements);

    virtual void retainAll(Iterable<Object> elements);

    virtual E lookup(Object object);

    virtual Set<E> intersection(Set<Object> other);

    virtual Set<E> difference(Set<Object> other);

    virtual Set<E> union(Set<E> other);

    virtual void clear();

    virtual Set<E> toSet();

    virtual String toString();

private:
    _SplayTreeSetNode<E> _root;

    Comparator<E> _compare;

    _Predicate _validKey;


    template<typename T>
 virtual Set<T> _newSet();

    virtual bool _add(E element);

    virtual SplayTreeSet<E> _clone();

    template<typename Node>
 virtual _SplayTreeSetNode<E> _copyNode(Node node);

};
template<typename E>
using SplayTreeSet = std::shared_ptr<SplayTreeSetCls<E>>;


#endif