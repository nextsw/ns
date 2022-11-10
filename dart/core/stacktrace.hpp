#ifndef DART_CORE_STACKTRACE
#define DART_CORE_STACKTRACE
#include <base.hpp>

#include <dart/core/core.hpp>


class StackTraceCls : public ObjectCls {
public:
    static auto  empty;


     StackTraceCls();
    virtual void  fromString(String stackTraceString);
    static StackTrace current();
    virtual String toString();
private:

};
using StackTrace = std::shared_ptr<StackTraceCls>;

class _StringStackTraceCls : public ObjectCls {
public:

    virtual String toString();

private:
    String _stackTrace;


     _StringStackTraceCls(String _stackTrace);
};
using _StringStackTrace = std::shared_ptr<_StringStackTraceCls>;


#endif