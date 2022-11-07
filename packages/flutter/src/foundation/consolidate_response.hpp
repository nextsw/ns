#ifndef CONSOLIDATE_RESPONSE_H
#define CONSOLIDATE_RESPONSE_H
#include <memory>
#include <io.hpp>
#include <typed_data.hpp>

#include <async/async.hpp>
#include <convert/convert.hpp>
#include <io/io.hpp>
#include <typed_data/typed_data.hpp>


Future<Uint8List> consolidateHttpClientResponseBytes(bool autoUncompress, BytesReceivedCallback onBytesReceived, HttpClientResponse response);


class _OutputBuffer : ByteConversionSinkBase {
public:

    void add(List<int> chunk);

    void close();

    Uint8List bytes();

private:
    List<List<int>> _chunks;

    int _contentLength;

    Uint8List _bytes;


};

#endif