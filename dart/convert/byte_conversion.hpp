#ifndef DART_CONVERT_BYTE_CONVERSION
#define DART_CONVERT_BYTE_CONVERSION
#include <base.hpp>

#include <dart/core/core.hpp>


class ByteConversionSinkCls : public ChunkedConversionSinkCls<List<int>> {
public:

     ByteConversionSinkCls();
    virtual void  withCallback(void callback(List<int> accumulated) ) override;
    virtual void  from(Sink<List<int>> sink);
    virtual void addSlice(List<int> chunk, int end, bool isLast, int start);
private:

};
using ByteConversionSink = std::shared_ptr<ByteConversionSinkCls>;

class ByteConversionSinkBaseCls : public ByteConversionSinkCls {
public:

    virtual void add(List<int> chunk);
    virtual void close();
    virtual void addSlice(List<int> chunk, int end, bool isLast, int start);

private:

};
using ByteConversionSinkBase = std::shared_ptr<ByteConversionSinkBaseCls>;

class _ByteAdapterSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void add(List<int> chunk);

    virtual void close();

private:
    Sink<List<int>> _sink;


     _ByteAdapterSinkCls(Sink<List<int>> _sink);
};
using _ByteAdapterSink = std::shared_ptr<_ByteAdapterSinkCls>;

class _ByteCallbackSinkCls : public ByteConversionSinkBaseCls {
public:

    virtual void add(Iterable<int> chunk);

    virtual void close();

private:
    static auto  _INITIAL_BUFFER_SIZE;

    void Function(List<int> ) _callback;

    List<int> _buffer;

    int _bufferIndex;


     _ByteCallbackSinkCls(void callback(List<int> accumulated) );

    static int _roundToPowerOf2(int v);

};
using _ByteCallbackSink = std::shared_ptr<_ByteCallbackSinkCls>;


#endif