#ifndef DART_CORE_COMPARABLE
#define DART_CORE_COMPARABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class ComparableCls : public ObjectCls {
public:

    virtual int compareTo(T other);
    static int compare(Comparable<any> a, Comparable<any> b);

private:

};
template<typename T>
using Comparable = std::shared_ptr<ComparableCls<T>>;


#endif