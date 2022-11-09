#ifndef DART_CORE_OBJECT
#define DART_CORE_OBJECT
#include <base.hpp>

#include <dart/core/core.hpp>


class ObjectCls : public ObjectCls {
public:

     ObjectCls();
    extern bool operator==(Object other);
    extern int hashCode();
    extern String toString();
    extern dynamic noSuchMethod(Invocation invocation);
    extern Type runtimeType();
    static int hash(Object object1, Object object10, Object object11, Object object12, Object object13, Object object14, Object object15, Object object16, Object object17, Object object18, Object object19, Object object2, Object object20, Object object3, Object object4, Object object5, Object object6, Object object7, Object object8, Object object9);

    static int hashAll(Iterable<Object> objects);

    static int hashAllUnordered(Iterable<Object> objects);

private:

};
using Object = std::shared_ptr<ObjectCls>;
int _hashSeed;



#endif