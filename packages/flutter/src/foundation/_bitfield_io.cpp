#include "_bitfield_io.hpp"
BitField::BitField(int _length) {
    {
        assert(_length <= _smiBits);
        _bits = _allZeros;
    }
}

void BitField::filled(int _length, bool value)

bool BitField::[](T index) {
    int intIndex = (;
    assert( < _length);
    return (_bits & 1 << intIndex) > 0;
}

void BitField::[]=(T index, bool value) {
    int intIndex = (;
    assert( < _length);
    if (value) {
        _bits = _bits | (1 << intIndex);
    } else {
        _bits = _bits & ~(1 << intIndex);
    }
}

void BitField::reset(bool value) {
    _bits = value? _allOnes : _allZeros;
}
