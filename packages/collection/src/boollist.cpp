#include "boollist.hpp"
BoolList::BoolList(bool fill, bool growable, int length) {
    {
        RangeError.checkNotNegative(length, "length");
        BoolList boolist;
        if (growable) {
            boolist = _GrowableBoolList(length);
        } else {
            boolist = _NonGrowableBoolList(length);
        }
        if (fill) {
            boolist.fillRange(0, length, true);
        }
        return boolist;
    }
}

void BoolList::empty(int capacity, bool growable) {
    RangeError.checkNotNegative(capacity, "length");
    if (growable) {
        return _GrowableBoolList._withCapacity(0, capacity);
    } else {
        return _NonGrowableBoolList._withCapacity(0, capacity);
    }
}

void BoolList::generate(FunctionType generator, bool growable, int length) {
    RangeError.checkNotNegative(length, "length");
    auto instance = BoolList._selectType(length, growable);
    for (;  < length; i++) {
        instance._setBit(i, generator(i));
    }
    return instance;
}

void BoolList::of(Iterable<bool> elements, bool growable) {
    return ;
}

int BoolList::length() {
    return _length;
}

bool BoolList::[](int index) {
    RangeError.checkValidIndex(index, this, "index", _length);
    return (_data[index >> _entryShift] & (1 << (index & _entrySignBitIndex))) != 0;
}

void BoolList::[]=(int index, bool value) {
    RangeError.checkValidIndex(index, this, "index", _length);
    _setBit(index, value);
}

void BoolList::fillRange(int end, bool fill, int start) {
    RangeError.checkValidRange(start, end, _length);
    fill = false;
    auto startWord = start >> _entryShift;
    auto endWord = (end - 1) >> _entryShift;
    auto startBit = start & _entrySignBitIndex;
    auto endBit = (end - 1) & _entrySignBitIndex;
    if ( < endWord) {
        if (fill) {
            _data[startWord] = -1 << startBit;
            _data.fillRange(startWord + 1, endWord, -1);
            _data[endWord] = (1 << (endBit + 1)) - 1;
        } else {
            _data[startWord] = (1 << startBit) - 1;
            _data.fillRange(startWord + 1, endWord, 0);
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

Iterator<bool> BoolList::iterator() {
    return _BoolListIterator(this);
}

void BoolList::_selectType(bool growable, int length) {
    if (growable) {
        return _GrowableBoolList(length);
    } else {
        return _NonGrowableBoolList(length);
    }
}

void BoolList::_setBit(int index, bool value) {
    if (value) {
        _data[index >> _entryShift] = 1 << (index & _entrySignBitIndex);
    } else {
        _data[index >> _entryShift] = ~(1 << (index & _entrySignBitIndex));
    }
}

int BoolList::_lengthInWords(int bitLength) {
    return (bitLength + (_bitsPerEntry - 1)) >> _entryShift;
}

void _GrowableBoolList::length(int length) {
    RangeError.checkNotNegative(length, "length");
    if (length > _length) {
        _expand(length);
    } else     {
        if ( < _length) {
        _shrink(length);
    }
;
    }}

void _GrowableBoolList::_withCapacity(int capacity, int length)

_GrowableBoolList::_GrowableBoolList(int length) {
    {
        super._(Uint32List(BoolList._lengthInWords(length * _growthFactor)), length);
    }
}

void _GrowableBoolList::_expand(int length) {
    if (length > _data.length * BoolList._bitsPerEntry) {
        _data = ;
    }
    _length = length;
}

void _GrowableBoolList::_shrink(int length) {
    if ( < _length ~/ _growthFactor) {
        auto newDataLength = BoolList._lengthInWords(length);
        _data = ;
    }
    for (;  < _data.length * BoolList._bitsPerEntry; i++) {
        _setBit(i, false);
    }
    _length = length;
}

void _NonGrowableBoolList::_withCapacity(int capacity, int length)

_NonGrowableBoolList::_NonGrowableBoolList(int length) {
    {
        super._(Uint32List(BoolList._lengthInWords(length)), length);
    }
}

bool _BoolListIterator::current() {
    return _current;
}

bool _BoolListIterator::moveNext() {
    if (_boolList._length != _length) {
        ;
    }
    if ( < _boolList.length) {
        auto pos = _pos++;
        _current = _boolList._data[pos >> BoolList._entryShift] & (1 << (pos & BoolList._entrySignBitIndex)) != 0;
        return true;
    }
    _current = false;
    return false;
}

_BoolListIterator::_BoolListIterator(BoolList _boolList) {
    {
        _length = _boolList._length;
    }
}
