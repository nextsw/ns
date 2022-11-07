#ifndef DEFERRED_LOAD_H
#define DEFERRED_LOAD_H
#include <memory>




class DeferredLibrary {
public:
    String libraryName;

    String uri;


     DeferredLibrary(String libraryName, String uri);

    external Future<Null> load();

private:

};

class DeferredLoadException {
public:

     DeferredLoadException(String message);

    String toString();

private:
    String _s;


};

#endif