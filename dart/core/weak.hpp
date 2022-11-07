#ifndef WEAK_H
#define WEAK_H
#include <memory>




class Expando<T extends Object> {
public:
    String name;


    external  Expando(String name);

    String toString();

    external T [](Object object);

    external void []=(Object object, T value);

private:

};

class WeakReference<T extends Object> {
public:

    external  WeakReference(T target);

    T target();

private:

};

class Finalizer<T> {
public:

    external  Finalizer(FunctionType callback);

    void attach(Object detach, T finalizationToken, Object value);

    void detach(Object detach);

private:

};

#endif