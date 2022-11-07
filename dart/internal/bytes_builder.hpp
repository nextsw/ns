#ifndef BYTES_BUILDER_H
#define BYTES_BUILDER_H
#include <memory>




class BytesBuilder {
public:

     BytesBuilder(bool copy);

    void add(List<int> bytes);

    void addByte(int byte);

    Uint8List takeBytes();

    Uint8List toBytes();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    void clear();

private:

};

class _CopyingBytesBuilder {
public:

    void add(List<int> bytes);

    void addByte(int byte);

    Uint8List takeBytes();

    Uint8List toBytes();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    void clear();

private:
    static const int _initSize;

    static auto  _emptyList;

    int _length;

    Uint8List _buffer;


     _CopyingBytesBuilder();

    void _grow(int required);

    void _clear();

    static int _pow2roundup(int x);

};

class _BytesBuilder {
public:

    void add(List<int> bytes);

    void addByte(int byte);

    Uint8List takeBytes();

    Uint8List toBytes();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    void clear();

private:
    int _length;

    List<Uint8List> _chunks;


    void _clear();

};

#endif