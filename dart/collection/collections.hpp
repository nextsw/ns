#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#include <memory>




class UnmodifiableListView<E> : UnmodifiableListBase<E> {
public:

     UnmodifiableListView(Iterable<E> source);

    List<R> cast<R>();

    int length();

    E [](int index);

private:
    Iterable<E> _source;


};

#endif