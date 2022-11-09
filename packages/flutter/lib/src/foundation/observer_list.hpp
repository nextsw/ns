#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_OBSERVER_LIST
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_OBSERVER_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>


template<typename T> class ObserverListCls : public IterableCls<T> {
public:

    virtual void add(T item);

    virtual bool remove(T item);

    virtual void clear();

    virtual bool contains(Object element);

    virtual Iterator<T> iterator();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual List<T> toList(bool growable);

private:
    List<T> _list;

    bool _isDirty;

    HashSet<T> _set;


};
template<typename T> using ObserverList = std::shared_ptr<ObserverListCls<T>>;

template<typename T> class HashedObserverListCls : public IterableCls<T> {
public:

    virtual void add(T item);

    virtual bool remove(T item);

    virtual bool contains(Object element);

    virtual Iterator<T> iterator();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

private:
    LinkedHashMap<T, int> _map;


};
template<typename T> using HashedObserverList = std::shared_ptr<HashedObserverListCls<T>>;


#endif