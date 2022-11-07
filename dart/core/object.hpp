#ifndef OBJECT_H
#define OBJECT_H
#include <memory>




class Object {
public:

     Object();

    external bool ==(Object other);

    external int hashCode();

    external String toString();

    external dynamic noSuchMethod(Invocation invocation);

    external Type runtimeType();

    static int hash(Object object1, Object object10, Object object11, Object object12, Object object13, Object object14, Object object15, Object object16, Object object17, Object object18, Object object19, Object object2, Object object20, Object object3, Object object4, Object object5, Object object6, Object object7, Object object8, Object object9);

    static int hashAll(Iterable<Object> objects);

    static int hashAllUnordered(Iterable<Object> objects);

private:

};
int _hashSeed;


#endif