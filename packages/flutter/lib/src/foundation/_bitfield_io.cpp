#include "_bitfield_io.hpp"
template<typename T>
BitFieldCls<T>::BitFieldCls(int _length) {
    {
        assert(_length <= _smiBits);
        _bits = _allZeros;
    }
}

template<typename T>
void BitFieldCls<T>::filled(int _length, bool value)

template<typename T>
bool BitFieldCls<T>::[](T index) {
    int intIndex = as<int>(index->index);
    assert( < _length);
    return (_bits & 1 << intIndex) > 0;
}

template<typename T>
void BitFieldCls<T>::[]=(T index, bool value) {
    int intIndex = as<int>(index->index);
    assert( < _length);
    if (value) {
        _bits = _bits | (1 << intIndex);
    } else {
        _bits = _bits & ~(1 << intIndex);
    }
}

template<typename T>
void BitFieldCls<T>::reset(bool value) {
    _bits = value? _allOnes : _allZeros;
}
