#ifndef PACKAGES_COLLECTION_SRC_CANONICALIZED_MAP
#define PACKAGES_COLLECTION_SRC_CANONICALIZED_MAP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>


template<typename C, typename K, typename V>
class CanonicalizedMapCls : public ObjectCls {
public:

     CanonicalizedMapCls(std::function<C(K key)> canonicalize, std::function<bool(K key)> isValidKey);

    virtual void  from(Map<K, V> other, std::function<C(K key)> canonicalize, std::function<bool(K key)> isValidKey);

    virtual V operator[](Object key);

    virtual void operator[]=(K key, V value);

    virtual void addAll(Map<K, V> other);

    virtual void addEntries(Iterable<MapEntry<K, V>> entries);

    template<typename K2, typename V2>
 virtual Map<K2, V2> cast();

    virtual void clear();

    virtual bool containsKey(Object key);

    virtual bool containsValue(Object value);

    virtual Iterable<MapEntry<K, V>> entries();

    virtual void forEach(std::function<void(K , V )> f);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<K> keys();

    virtual int length();

    template<typename K2, typename V2>
 virtual Map<K2, V2> map(std::function<MapEntry<K2, V2>(K , V )> transform);

    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);

    virtual V remove(Object key);

    virtual void removeWhere(std::function<bool(K key, V value)> test);

    template<typename K2, typename V2>
 virtual Map<K2, V2> retype();

    virtual V update(K key, std::function<V(V )> update, std::function<V()> ifAbsent);

    virtual void updateAll(std::function<V(K key, V value)> update);

    virtual Iterable<V> values();

    virtual String toString();

private:
    std::function<C(K )> _canonicalize;

    std::function<bool(K )> _isValidKeyFn;

    auto  _base;


    virtual bool _isValidKey(Object key);

};
template<typename C, typename K, typename V>
using CanonicalizedMap = std::shared_ptr<CanonicalizedMapCls<C, K, V>>;


#endif