#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BITFIELD
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BITFIELD
#include <base.hpp>

#include <dart/core/core.hpp>
#include "_bitfield_io.hpp"

int kMaxUnsignedSMI;


template<typename T>
class BitFieldCls : public ObjectCls {
public:

     BitFieldCls(int length);
    virtual void  filled(int length, bool value);
    virtual bool operator[](T index);
    virtual void operator[]=(T index, bool value);
    virtual void reset(bool value);
private:

};
template<typename T>
using BitField = std::shared_ptr<BitFieldCls<T>>;


#endif