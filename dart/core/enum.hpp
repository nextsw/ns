#ifndef DART_CORE_ENUM
#define DART_CORE_ENUM
#include <base.hpp>

#include <dart/core/core.hpp>


class EnumCls : public ObjectCls {
public:

    virtual int index();
    template<typename T>
 static int compareByIndex(T value1, T value2);

    template<typename T>
 static int compareByName(T value1, T value2);

private:

    virtual String _name();
};
using Enum = std::shared_ptr<EnumCls>;

class _EnumCls : public ObjectCls {
public:
    int index;


private:
    String _name;


     _EnumCls(String _name, int index);
};
using _Enum = std::shared_ptr<_EnumCls>;

class EnumNameCls : public ObjectCls {
public:

    virtual String name();

private:

};
using EnumName = std::shared_ptr<EnumNameCls>;

template<typename T>
class EnumByNameCls : public ObjectCls {
public:

    virtual T byName(String name);

    virtual Map<String, T> asNameMap();

private:

};
template<typename T>
using EnumByName = std::shared_ptr<EnumByNameCls<T>>;


#endif