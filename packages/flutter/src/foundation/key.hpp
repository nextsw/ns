#ifndef KEY_H
#define KEY_H
#include <memory>

#include <meta/meta.hpp>
#include "diagnostics.hpp"



class Key {
public:

     Key(String value);

    void  empty();

private:

};

class LocalKey : Key {
public:

     LocalKey();

private:

};

class UniqueKey : LocalKey {
public:

     UniqueKey();

    String toString();

private:

};

class ValueKey<T> : LocalKey {
public:
    T value;


     ValueKey(T value);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class _TypeLiteral<T> {
public:

    Type type();

private:

};

#endif