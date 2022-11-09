#ifndef DART_CORE_STRING_BUFFER
#define DART_CORE_STRING_BUFFER
#include <base.hpp>

#include <dart/core/core.hpp>


class StringBufferCls : public ObjectCls {
public:

    extern  StringBufferCls(Object content);
    extern int length();
    virtual bool isEmpty();

    virtual bool isNotEmpty();

    extern void write(Object object);
    extern void writeCharCode(int charCode);
    extern void writeAll(Iterable<dynamic> objects, String separator);
    extern void writeln(Object obj);
    extern void clear();
    extern String toString();
private:

};
using StringBuffer = std::shared_ptr<StringBufferCls>;


#endif