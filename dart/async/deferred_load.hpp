#ifndef DART_ASYNC_DEFERRED_LOAD
#define DART_ASYNC_DEFERRED_LOAD
#include <base.hpp>

#include <dart/core/core.hpp>


class DeferredLibraryCls : public ObjectCls {
public:
    String libraryName;

    String uri;


     DeferredLibraryCls(String libraryName, String uri);
    extern Future<Null> load();
private:

};
using DeferredLibrary = std::shared_ptr<DeferredLibraryCls>;

class DeferredLoadExceptionCls : public ObjectCls {
public:

     DeferredLoadExceptionCls(String message);

    virtual String toString();

private:
    String _s;


};
using DeferredLoadException = std::shared_ptr<DeferredLoadExceptionCls>;


#endif