#include "_bitfield_io.hpp"
template<typename T : dynamic> BitFieldCls<T>::BitFieldCls(int _length) {
    {
        assert(_length <= _smiBits);
        _bits = _allZeros;
    }
}

template<typename T : dynamic> void BitFieldCls<T>::filled(int _length, bool value)

template<typename T : dynamic> bool BitFieldCls<T>::[](T index) {
    int intIndex = ((int)index->index);
    assert( < _length);
    return (_bits & 1 << intIndex) > 0;
}

template<typename T : dynamic> void BitFieldCls<T>::[]=(T index, bool value) {
    int intIndex = ((int)index->index);
    assert( < _length);
    if (value) {
        _bits = _bits | (1 << intIndex);
    } else {
        _bits = _bits & ~(1 << intIndex);
    }
}

template<typename T : dynamic> void BitFieldCls<T>::reset(bool value) {
    _bits = value? _allOnes : _allZeros;
}
