#ifndef BOOLLIST_H
#define BOOLLIST_H
#include <memory>

#include <collection/collection.hpp>
#include <typed_data/typed_data.hpp>
#include "unmodifiable_wrappers.hpp"



class BoolList {
public:

     BoolList(bool fill, bool growable, int length);

    void  empty(int capacity, bool growable);

    void  generate(FunctionType generator, bool growable, int length);

    void  of(Iterable<bool> elements, bool growable);

    int length();

    bool [](int index);

    void []=(int index, bool value);

    void fillRange(int end, bool fill, int start);

    Iterator<bool> iterator();

private:
    static const int _entryShift;

    static const int _bitsPerEntry;

    static const int _entrySignBitIndex;

    int _length;

    Uint32List _data;


    void  _(Uint32List _data, int _length);

    void  _selectType(bool growable, int length);

    void _setBit(int index, bool value);

    static int _lengthInWords(int bitLength);

};

class _GrowableBoolList : BoolList {
public:

    void  length(int length);

private:
    static const int _growthFactor;


    void  _withCapacity(int capacity, int length);

     _GrowableBoolList(int length);

    void _expand(int length);

    void _shrink(int length);

};

class _NonGrowableBoolList : BoolList {
public:

private:

    void  _withCapacity(int capacity, int length);

     _NonGrowableBoolList(int length);

};

class _BoolListIterator {
public:

    bool current();

    bool moveNext();

private:
    bool _current;

    int _pos;

    int _length;

    BoolList _boolList;


     _BoolListIterator(BoolList _boolList);

};

#endif