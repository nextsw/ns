#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION__BITFIELD_IO
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION__BITFIELD_IO
#include <base.hpp>

#include <dart/core/core.hpp>
#include "bitfield.hpp"

int kMaxUnsignedSMI;


template<typename T : dynamic> class BitFieldCls : public ObjectCls {
public:

     BitFieldCls(int _length);

    virtual void  filled(int _length, bool value);

    virtual bool operator[](T index);

    virtual void operator[]=(T index, bool value);

    virtual void reset(bool value);

private:
    int _length;

    int _bits;

    static int _smiBits;

    static int _allZeros;

    static int _allOnes;


};
template<typename T : dynamic> using BitField = std::shared_ptr<BitFieldCls<T : dynamic>>;


#endif