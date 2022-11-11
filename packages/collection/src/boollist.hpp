#ifndef PACKAGES_COLLECTION_SRC_BOOLLIST
#define PACKAGES_COLLECTION_SRC_BOOLLIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/typed_data/typed_data.hpp>
#include "unmodifiable_wrappers.hpp"


class BoolListCls : public ObjectCls {
public:

     BoolListCls(bool fill, bool growable, int length);

    virtual void  empty(int capacity, bool growable);

    virtual void  generate(std::function<bool(int )> generator, bool growable, int length);

    virtual void  of(Iterable<bool> elements, bool growable);

    virtual int length();

    virtual bool operator[](int index);

    virtual void operator[]=(int index, bool value);

    virtual void fillRange(int end, bool fill, int start);

    virtual Iterator<bool> iterator();

private:
    static int _entryShift;

    static int _bitsPerEntry;

    static int _entrySignBitIndex;

    int _length;

    Uint32List _data;


    virtual void  _(Uint32List _data, int _length);
    virtual void  _selectType(bool growable, int length);

    virtual void _setBit(int index, bool value);

    static int _lengthInWords(int bitLength);

};
using BoolList = std::shared_ptr<BoolListCls>;

class _GrowableBoolListCls : public BoolListCls {
public:

    virtual void  length(int length);

private:
    static int _growthFactor;


    virtual void  _withCapacity(int capacity, int length);

     _GrowableBoolListCls(int length);

    virtual void _expand(int length);

    virtual void _shrink(int length);

};
using _GrowableBoolList = std::shared_ptr<_GrowableBoolListCls>;

class _NonGrowableBoolListCls : public BoolListCls {
public:

private:

    virtual void  _withCapacity(int capacity, int length);

     _NonGrowableBoolListCls(int length);

};
using _NonGrowableBoolList = std::shared_ptr<_NonGrowableBoolListCls>;

class _BoolListIteratorCls : public ObjectCls {
public:

    virtual bool current();

    virtual bool moveNext();

private:
    bool _current;

    int _pos;

    int _length;

    BoolList _boolList;


     _BoolListIteratorCls(BoolList _boolList);

};
using _BoolListIterator = std::shared_ptr<_BoolListIteratorCls>;


#endif