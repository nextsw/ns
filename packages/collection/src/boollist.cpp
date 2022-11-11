#include "boollist.hpp"
BoolListCls::BoolListCls(bool fill, bool growable, int length) {
    {
        RangeErrorCls->checkNotNegative(length, __s("length"));
        BoolList boolist;
        if (growable) {
            boolist = make<_GrowableBoolListCls>(length);
        } else {
            boolist = make<_NonGrowableBoolListCls>(length);
        }
        if (fill) {
            boolist->fillRange(0, length, true);
        }
        return boolist;
    }
}

void BoolListCls::empty(int capacity, bool growable) {
    RangeErrorCls->checkNotNegative(capacity, __s("length"));
    if (growable) {
        return _GrowableBoolListCls->_withCapacity(0, capacity);
    } else {
        return _NonGrowableBoolListCls->_withCapacity(0, capacity);
    }
}

void BoolListCls::generate(bool generator(int ) , bool growable, int length) {
    RangeErrorCls->checkNotNegative(length, __s("length"));
    auto instance = BoolListCls->_selectType(length, growable);
    for (;  < length; i++) {
        instance->_setBit(i, generator(i));
    }
    return instance;
}

void BoolListCls::of(Iterable<bool> elements, bool growable) {
    auto _c1 = BoolListCls->_selectType(elements->length(), growable);_c1.setAll(0, elements);return _c1;
}

int BoolListCls::length() {
    return _length;
}

bool BoolListCls::[](int index) {
    RangeErrorCls->checkValidIndex(index, this, __s("index"), _length);
    return (_data[index >> _entryShift] & (1 << (index & _entrySignBitIndex))) != 0;
}

void BoolListCls::[]=(int index, bool value) {
    RangeErrorCls->checkValidIndex(index, this, __s("index"), _length);
    _setBit(index, value);
}

void BoolListCls::fillRange(int end, bool fill, int start) {
    RangeErrorCls->checkValidRange(start, end, _length);
    fill = false;
    auto startWord = start >> _entryShift;
    auto endWord = (end - 1) >> _entryShift;
    auto startBit = start & _entrySignBitIndex;
    auto endBit = (end - 1) & _entrySignBitIndex;
    if ( < endWord) {
        if (fill) {
            _data[startWord] = -1 << startBit;
            _data->fillRange(startWord + 1, endWord, -1);
            _data[endWord] = (1 << (endBit + 1)) - 1;
        } else {
            _data[startWord] = (1 << startBit) - 1;
            _data->fillRange(startWord + 1, endWord, 0);
            _data[endWord] = -1 << (endBit + 1);
        }
    } else {
        if (fill) {
            _data[startWord] = ((1 << (endBit - startBit + 1)) - 1) << startBit;
        } else {
            _data[startWord] = ((1 << startBit) - 1) | (-1 << (endBit + 1));
        }
    }
}

Iterator<bool> BoolListCls::iterator() {
    return make<_BoolListIteratorCls>(this);
}

void BoolListCls::_selectType(bool growable, int length) {
    if (growable) {
        return make<_GrowableBoolListCls>(length);
    } else {
        return make<_NonGrowableBoolListCls>(length);
    }
}

void BoolListCls::_setBit(int index, bool value) {
    if (value) {
        _data[index >> _entryShift] = 1 << (index & _entrySignBitIndex);
    } else {
        _data[index >> _entryShift] = ~(1 << (index & _entrySignBitIndex));
    }
}

int BoolListCls::_lengthInWords(int bitLength) {
    return (bitLength + (_bitsPerEntry - 1)) >> _entryShift;
}

void _GrowableBoolListCls::length(int length) {
    RangeErrorCls->checkNotNegative(length, __s("length"));
    if (length > _length) {
        _expand(length);
    } else     {
        if ( < _length) {
        _shrink(length);
    }
;
    }}

void _GrowableBoolListCls::_withCapacity(int capacity, int length)

_GrowableBoolListCls::_GrowableBoolListCls(int length) {
    {
        super->_(make<Uint32ListCls>(BoolListCls->_lengthInWords(length * _growthFactor)), length);
    }
}

void _GrowableBoolListCls::_expand(int length) {
    if (length > _data->length * BoolListCls::_bitsPerEntry) {
            auto _c1 = make<Uint32ListCls>(BoolListCls->_lengthInWords(length * _growthFactor));    _c1.setRange(0, _data->length, _data);_data = _c1;
    }
    _length = length;
}

void _GrowableBoolListCls::_shrink(int length) {
    if ( < _length ~/ _growthFactor) {
        auto newDataLength = BoolListCls->_lengthInWords(length);
            auto _c1 = make<Uint32ListCls>(newDataLength);    _c1.setRange(0, newDataLength, _data);_data = _c1;
    }
    for (;  < _data->length * BoolListCls::_bitsPerEntry; i++) {
        _setBit(i, false);
    }
    _length = length;
}

void _NonGrowableBoolListCls::_withCapacity(int capacity, int length)

_NonGrowableBoolListCls::_NonGrowableBoolListCls(int length) {
    {
        super->_(make<Uint32ListCls>(BoolListCls->_lengthInWords(length)), length);
    }
}

bool _BoolListIteratorCls::current() {
    return _current;
}

bool _BoolListIteratorCls::moveNext() {
    if (_boolList->_length != _length) {
        ;
    }
    if ( < _boolList->length()) {
        auto pos = _pos++;
        _current = _boolList->_data[pos >> BoolListCls::_entryShift] & (1 << (pos & BoolListCls::_entrySignBitIndex)) != 0;
        return true;
    }
    _current = false;
    return false;
}

_BoolListIteratorCls::_BoolListIteratorCls(BoolList _boolList) {
    {
        _length = _boolList->_length;
    }
}
