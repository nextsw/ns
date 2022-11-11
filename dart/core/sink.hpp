#ifndef DART_CORE_SINK
#define DART_CORE_SINK
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class SinkCls : public ObjectCls {
public:

    virtual void add(T data);
    virtual void close();
private:

};
template<typename T>
using Sink = std::shared_ptr<SinkCls<T>>;


#endif