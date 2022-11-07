#ifndef COMBINED_LIST_H
#define COMBINED_LIST_H
#include <memory>

#include <collection/collection.hpp>
#include "combined_iterator.hpp"



class CombinedListView<T> : ListBase<T> {
public:

     CombinedListView(List<List<T>> _lists);

    Iterator<T> iterator();

    void  length(int length);

    int length();

    T [](int index);

    void []=(int index, T value);

    void clear();

    bool remove(Object element);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

private:
    List<List<T>> _lists;


    static Never _throw();

};

#endif