#ifndef ENUM_H
#define ENUM_H
#include <memory>




class Enum {
public:

    int index();

    static int compareByIndex<T extends Enum>(T value1, T value2);

    static int compareByName<T extends Enum>(T value1, T value2);

private:

    String _name();

};

class _Enum {
public:
    int index;


private:
    String _name;


     _Enum(String _name, int index);

};

class EnumName {
public:

    String name();

private:

};

class EnumByName<T extends Enum> {
public:

    T byName(String name);

    Map<String, T> asNameMap();

private:

};

#endif