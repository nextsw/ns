#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_CONSOLIDATE_RESPONSE
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_CONSOLIDATE_RESPONSE
#include <base.hpp>
#include <dart/io/io.hpp>
#include <dart/typed_data/typed_data.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/convert/convert.hpp>
#include <dart/io/io.hpp>
#include <dart/typed_data/typed_data.hpp>

Future<Uint8List> consolidateHttpClientResponseBytes(bool autoUncompress, BytesReceivedCallback onBytesReceived, HttpClientResponse response);


class _OutputBufferCls : public ByteConversionSinkBaseCls {
public:

    virtual void add(List<int> chunk);

    virtual void close();

    virtual Uint8List bytes();

private:
    List<List<int>> _chunks;

    int _contentLength;

    Uint8List _bytes;


};
using _OutputBuffer = std::shared_ptr<_OutputBufferCls>;


#endif