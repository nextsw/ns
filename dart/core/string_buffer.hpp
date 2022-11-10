#ifndef DART_CORE_STRING_BUFFER
#define DART_CORE_STRING_BUFFER
#include <base.hpp>

#include <dart/core/core.hpp>


class StringBufferCls : public ObjectCls {
public:

     StringBufferCls(Object content);
    int length();
    virtual bool isEmpty();

    virtual bool isNotEmpty();

    void write(Object object);
    void writeCharCode(int charCode);
    void writeAll(Iterable<dynamic> objects, String separator);
    void writeln(Object obj);
    void clear();
    String toString();
private:

};
using StringBuffer = std::shared_ptr<StringBufferCls>;


#endif