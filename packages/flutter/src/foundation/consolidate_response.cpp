#include "consolidate_response.hpp"
Future<Uint8List> consolidateHttpClientResponseBytes(bool autoUncompress, BytesReceivedCallback onBytesReceived, HttpClientResponse response) {
    assert(autoUncompress != nullptr);
    Completer<Uint8List> completer = <Uint8List>sync();
    _OutputBuffer output = _OutputBuffer();
    ByteConversionSink sink = output;
    int expectedContentLength = response.contentLength;
    if (expectedContentLength == -1) {
        expectedContentLength = nullptr;
    }
    ;
    int bytesReceived = 0;
    StreamSubscription<List<int>> subscription;
    subscription = response.listen(, completer.completeError, true);
    return completer.future;
}

void _OutputBuffer::add(List<int> chunk) {
    assert(_bytes == nullptr);
    _chunks!.add(chunk);
    _contentLength = chunk.length;
}

void _OutputBuffer::close() {
    if (_bytes != nullptr) {
        return;
    }
    _bytes = Uint8List(_contentLength);
    int offset = 0;
    for (List<int> chunk : _chunks!) {
        _bytes!.setRange(offset, offset + chunk.length, chunk);
        offset = chunk.length;
    }
    _chunks = nullptr;
}

Uint8List _OutputBuffer::bytes() {
    assert(_bytes != nullptr);
    return _bytes!;
}
