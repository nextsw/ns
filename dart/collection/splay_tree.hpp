#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H
#include <memory>




class _SplayTreeNode<K, Node extends _SplayTreeNode<K, Node>> {
public:
    K key;


private:
    Node _left;

    Node _right;


     _SplayTreeNode(K key);

};

class _SplayTreeSetNode<K> : _SplayTreeNode<K, _SplayTreeSetNode<K>> {
public:

private:

     _SplayTreeSetNode(K key);

};

class _SplayTreeMapNode<K, V> : _SplayTreeNode<K, _SplayTreeMapNode<K, V>> {
public:
    V value;


    String toString();

private:

     _SplayTreeMapNode(K key, V value);

    _SplayTreeMapNode<K, V> _replaceValue(V value);

};

class _SplayTree<K, Node extends _SplayTreeNode<K, Node>> {
public:

private:
    int _count;

    int _modificationCount;

    int _splayCount;


    Node _root();

    void  _root(Node newValue);

    Comparator<K> _compare();

    _Predicate _validKey();

    int _splay(K key);

    Node _splayMin(Node node);

    Node _splayMax(Node node);

    Node _remove(K key);

    void _addNewRoot(int comp, Node node);

    Node _first();

    Node _last();

    void _clear();

    bool _containsKey(Object key);

};
int _dynamicCompare(dynamic a, dynamic b);

Comparator<K> _defaultCompare<K>();


class SplayTreeMap<K, V> : _SplayTree<K, _SplayTreeMapNode<K, V>> {
public:

     SplayTreeMap(FunctionType compare, FunctionType isValidKey);

    void  from(FunctionType compare, FunctionType isValidKey, Map<dynamic, dynamic> other);

    void  of(FunctionType compare, FunctionType isValidKey, Map<K, V> other);

    void  fromIterable(FunctionType compare, FunctionType isValidKey, Iterable iterable, FunctionType key, FunctionType value);

    void  fromIterables(FunctionType compare, FunctionType isValidKey, Iterable<K> keys, Iterable<V> values);

    V [](Object key);

    V remove(Object key);

    void []=(K key, V value);

    V putIfAbsent(FunctionType ifAbsent, K key);

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

    void addAll(Map<K, V> other);

    bool isEmpty();

    bool isNotEmpty();

    void forEach(FunctionType f);

    int length();

    void clear();

    bool containsKey(Object key);

    bool containsValue(Object value);

    Iterable<K> keys();

    Iterable<V> values();

    Iterable<MapEntry<K, V>> entries();

    K firstKey();

    K lastKey();

    K lastKeyBefore(K key);

    K firstKeyAfter(K key);

private:
    _SplayTreeMapNode<K, V> _root;

    Comparator<K> _compare;

    _Predicate _validKey;


};

class _SplayTreeIterator<K, Node extends _SplayTreeNode<K, Node>, T> {
public:

    T current();

    bool moveNext();

private:
    _SplayTree<K, Node> _tree;

    List<Node> _path;

    int _modificationCount;

    int _splayCount;


     _SplayTreeIterator(_SplayTree<K, Node> tree);

    void _rebuildPath(K key);

    void _findLeftMostDescendent(Node node);

    T _getValue(Node node);

};

class _SplayTreeKeyIterable<K, Node extends _SplayTreeNode<K, Node>> : EfficientLengthIterable<K> {
public:

    int length();

    bool isEmpty();

    Iterator<K> iterator();

    bool contains(Object o);

    Set<K> toSet();

private:
    _SplayTree<K, Node> _tree;


     _SplayTreeKeyIterable(_SplayTree<K, Node> _tree);

};

class _SplayTreeValueIterable<K, V> : EfficientLengthIterable<V> {
public:

    int length();

    bool isEmpty();

    Iterator<V> iterator();

private:
    SplayTreeMap<K, V> _map;


     _SplayTreeValueIterable(SplayTreeMap<K, V> _map);

};

class _SplayTreeMapEntryIterable<K, V> : EfficientLengthIterable<MapEntry<K, V>> {
public:

    int length();

    bool isEmpty();

    Iterator<MapEntry<K, V>> iterator();

private:
    SplayTreeMap<K, V> _map;


     _SplayTreeMapEntryIterable(SplayTreeMap<K, V> _map);

};

class _SplayTreeKeyIterator<K, Node extends _SplayTreeNode<K, Node>> : _SplayTreeIterator<K, Node, K> {
public:

private:

     _SplayTreeKeyIterator(_SplayTree<K, Node> map);

    K _getValue(Node node);

};

class _SplayTreeValueIterator<K, V> : _SplayTreeIterator<K, _SplayTreeMapNode<K, V>, V> {
public:

private:

     _SplayTreeValueIterator(SplayTreeMap<K, V> map);

    V _getValue(_SplayTreeMapNode<K, V> node);

};

class _SplayTreeMapEntryIterator<K, V> : _SplayTreeIterator<K, _SplayTreeMapNode<K, V>, MapEntry<K, V>> {
public:

private:

     _SplayTreeMapEntryIterator(SplayTreeMap<K, V> tree);

    MapEntry<K, V> _getValue(_SplayTreeMapNode<K, V> node);

    void _replaceValue(V value);

};

class SplayTreeSet<E> : _SplayTree<E, _SplayTreeSetNode<E>> {
public:

     SplayTreeSet(FunctionType compare, FunctionType isValidKey);

    void  from(FunctionType compare, Iterable elements, FunctionType isValidKey);

    void  of(FunctionType compare, Iterable<E> elements, FunctionType isValidKey);

    Set<R> cast<R>();

    Iterator<E> iterator();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    E first();

    E last();

    E single();

    bool contains(Object element);

    bool add(E element);

    bool remove(Object object);

    void addAll(Iterable<E> elements);

    void removeAll(Iterable<Object> elements);

    void retainAll(Iterable<Object> elements);

    E lookup(Object object);

    Set<E> intersection(Set<Object> other);

    Set<E> difference(Set<Object> other);

    Set<E> union(Set<E> other);

    void clear();

    Set<E> toSet();

    String toString();

private:
    _SplayTreeSetNode<E> _root;

    Comparator<E> _compare;

    _Predicate _validKey;


    Set<T> _newSet<T>();

    bool _add(E element);

    SplayTreeSet<E> _clone();

    _SplayTreeSetNode<E> _copyNode<Node extends _SplayTreeNode<E, Node>>(Node node);

};

#endif