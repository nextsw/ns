#ifndef BYTE_CONVERSION_H
#define BYTE_CONVERSION_H
#include <memory>




class ByteConversionSink : ChunkedConversionSink<List<int>> {
public:

     ByteConversionSink();

    void  withCallback(FunctionType callback);

    void  from(Sink<List<int>> sink);

    void addSlice(List<int> chunk, int end, bool isLast, int start);

private:

};

class ByteConversionSinkBase : ByteConversionSink {
public:

    void add(List<int> chunk);

    void close();

    void addSlice(List<int> chunk, int end, bool isLast, int start);

private:

};

class _ByteAdapterSink : ByteConversionSinkBase {
public:

    void add(List<int> chunk);

    void close();

private:
    Sink<List<int>> _sink;


     _ByteAdapterSink(Sink<List<int>> _sink);

};

class _ByteCallbackSink : ByteConversionSinkBase {
public:

    void add(Iterable<int> chunk);

    void close();

private:
    static const auto  _INITIAL_BUFFER_SIZE;

    FunctionType _callback;

    List<int> _buffer;

    int _bufferIndex;


     _ByteCallbackSink(FunctionType callback);

    static int _roundToPowerOf2(int v);

};

#endif