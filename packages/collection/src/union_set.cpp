#include "union_set.hpp"
template<typename E> UnionSetCls<E>::UnionSetCls(bool disjoint, Set<Set<E>> sets) {
    {
        _sets = sets;
        _disjoint = disjoint;
    }
}

template<typename E> void UnionSetCls<E>::from(bool disjoint, Iterable<Set<E>> sets)

template<typename E> int UnionSetCls<E>::length() {
    return _disjoint? _sets->fold(0, [=] (Unknown  length,Unknown  set)     {
        length + set->length;
    }) : _iterable->length;
}

template<typename E> Iterator<E> UnionSetCls<E>::iterator() {
    return _iterable->iterator();
}

template<typename E> bool UnionSetCls<E>::contains(Object element) {
    return _sets->any([=] (Unknown  set)     {
        set->contains(element);
    });
}

template<typename E> E UnionSetCls<E>::lookup(Object element) {
    for (auto set : _sets) {
        auto result = set->lookup(element);
        if (result != nullptr || set->contains(nullptr))         {
            return result;
        }
    }
    return nullptr;
}

template<typename E> Set<E> UnionSetCls<E>::toSet() {
    return list1;
}

template<typename E> Iterable<E> UnionSetCls<E>::_iterable() {
    Set<E> set1 = make<SetCls<>>();for (auto set : _sets)     {        ;    }{    set1.add(ArrayItem);}auto allElements = _sets->expand([=] (Unknown  set) {
    set;
});
    return _disjoint? allElements : allElements->where(makeSet()->add);
}
