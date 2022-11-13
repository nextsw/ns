#ifndef DART_CORE_STRING_SINK
#define DART_CORE_STRING_SINK
#include <base.hpp>

#include <dart/core/core.hpp>


class StringSinkCls : public ObjectCls {
public:

    virtual void write(Object object);
    virtual void writeAll(Iterable<Object> objects, String separator);
    virtual void writeln(Object object);
    virtual void writeCharCode(int charCode);
private:

};
using StringSink = std::shared_ptr<StringSinkCls>;


#endif