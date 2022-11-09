#ifndef DART_INTERNAL_BYTES_BUILDER
#define DART_INTERNAL_BYTES_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>


class BytesBuilderCls : public ObjectCls {
public:

     BytesBuilderCls(bool copy);

    virtual void add(List<int> bytes);
    virtual void addByte(int byte);
    virtual Uint8List takeBytes();
    virtual Uint8List toBytes();
    virtual int length();
    virtual bool isEmpty();
    virtual bool isNotEmpty();
    virtual void clear();
private:

};
using BytesBuilder = std::shared_ptr<BytesBuilderCls>;

class _CopyingBytesBuilderCls : public ObjectCls {
public:

    virtual void add(List<int> bytes);

    virtual void addByte(int byte);

    virtual Uint8List takeBytes();

    virtual Uint8List toBytes();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual void clear();

private:
    static int _initSize;

    static auto  _emptyList;

    int _length;

    Uint8List _buffer;


     _CopyingBytesBuilderCls();

    virtual void _grow(int required);

    virtual void _clear();

    static int _pow2roundup(int x);

};
using _CopyingBytesBuilder = std::shared_ptr<_CopyingBytesBuilderCls>;

class _BytesBuilderCls : public ObjectCls {
public:

    virtual void add(List<int> bytes);

    virtual void addByte(int byte);

    virtual Uint8List takeBytes();

    virtual Uint8List toBytes();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual void clear();

private:
    int _length;

    List<Uint8List> _chunks;


    virtual void _clear();

};
using _BytesBuilder = std::shared_ptr<_BytesBuilderCls>;


#endif