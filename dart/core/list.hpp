#ifndef DART_CORE_LIST
#define DART_CORE_LIST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class ListCls : public ObjectCls {
public:

     ListCls(int length);
    void  filled(E fill, bool growable, int length);
    void  empty(bool growable);
    void  from(Iterable elements, bool growable);
    void  of(Iterable<E> elements, bool growable);
    void  generate(std::function<E(int index)> generator, bool growable, int length);
    void  unmodifiable(Iterable elements);
    template<typename S, typename T>
 static List<T> castFrom(List<S> source);

    template<typename T>
 static void copyRange(int at, int end, List<T> source, int start, List<T> target);

    template<typename T>
 static void writeIterable(int at, Iterable<T> source, List<T> target);

    template<typename R>
 virtual List<R> cast();
    virtual E operator[](int index);
    virtual void operator[]=(int index, E value);
    virtual void first(E value);
    virtual void last(E value);
    virtual int length();
    virtual void  length(int newLength);
    virtual void add(E value);
    virtual void addAll(Iterable<E> iterable);
    virtual Iterable<E> reversed();
    virtual void sort(std::function<int(E a, E b)> compare);
    virtual void shuffle(Random random);
    virtual int indexOf(E element, int start);
    virtual int indexWhere(int start, std::function<bool(E element)> test);
    virtual int lastIndexWhere(int start, std::function<bool(E element)> test);
    virtual int lastIndexOf(E element, int start);
    virtual void clear();
    virtual void insert(E element, int index);
    virtual void insertAll(int index, Iterable<E> iterable);
    virtual void setAll(int index, Iterable<E> iterable);
    virtual bool remove(Object value);
    virtual E removeAt(int index);
    virtual E removeLast();
    virtual void removeWhere(std::function<bool(E element)> test);
    virtual void retainWhere(std::function<bool(E element)> test);
    virtual List<E> operator+(List<E> other);
    virtual List<E> sublist(int end, int start);
    virtual Iterable<E> getRange(int end, int start);
    virtual void setRange(int end, Iterable<E> iterable, int skipCount, int start);
    virtual void removeRange(int end, int start);
    virtual void fillRange(int end, E fillValue, int start);
    virtual void replaceRange(int end, Iterable<E> replacements, int start);
    virtual Map<int, E> asMap();
    virtual bool operator==(Object other);
private:

};
template<typename E>
using List = std::shared_ptr<ListCls<E>>;


#endif