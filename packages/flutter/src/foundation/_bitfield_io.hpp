#ifndef _BITFIELD_IO_H
#define _BITFIELD_IO_H
#include <memory>

#include "bitfield.hpp"


const int kMaxUnsignedSMI;


class BitField<T extends dynamic> {
public:

     BitField(int _length);

    void  filled(int _length, bool value);

    bool [](T index);

    void []=(T index, bool value);

    void reset(bool value);

private:
    int _length;

    int _bits;

    static const int _smiBits;

    static const int _allZeros;

    static const int _allOnes;


};

#endif