#include "consolidate_response.hpp"
Future<Uint8List> consolidateHttpClientResponseBytes(bool autoUncompress, BytesReceivedCallback onBytesReceived, HttpClientResponse response) {
    assert(autoUncompress != nullptr);
    Completer<Uint8List> completer = <Uint8List>sync();
    _OutputBuffer output = make<_OutputBufferCls>();
    ByteConversionSink sink = output;
    int expectedContentLength = response->contentLength;
    if (expectedContentLength == -1) {
        expectedContentLength = nullptr;
    }
    ;
    int bytesReceived = 0;
    StreamSubscription<List<int>> subscription;
    subscription = response->listen([=] (List<int> chunk) {
        sink->add(chunk);
        if (onBytesReceived != nullptr) {
            bytesReceived = chunk->length;
            try {
                onBytesReceived(bytesReceived, expectedContentLength);
            } catch (Unknown error) {
                completer->completeError(error, stackTrace);
                subscription->cancel();
                return;
            };
        }
    }[=] () {
        sink->close();
        completer->complete(output->bytes);
    }, completer->completeError, true);
    return completer->future;
}

void _OutputBufferCls::add(List<int> chunk) {
    assert(_bytes == nullptr);
    _chunks!->add(chunk);
    _contentLength = chunk->length;
}

void _OutputBufferCls::close() {
    if (_bytes != nullptr) {
        return;
    }
    _bytes = make<Uint8ListCls>(_contentLength);
    int offset = 0;
    for (List<int> chunk : _chunks!) {
        _bytes!->setRange(offset, offset + chunk->length, chunk);
        offset = chunk->length;
    }
    _chunks = nullptr;
}

Uint8List _OutputBufferCls::bytes() {
    assert(_bytes != nullptr);
    return _bytes!;
}
