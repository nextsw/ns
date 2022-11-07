#include "common.hpp"
bool _isErrorResponse(response ) {
    return response is List && response[0] != _successResponse;
}

void _exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}

String IOException::toString() {
    return "IOException";
}

String OSError::toString() {
    StringBuffer sb = StringBuffer();
    sb.write("OS Error");
    if (message.isNotEmpty) {
        ;
        if (errorCode != noErrorCode) {
            ;
        }
    } else     {
        if (errorCode != noErrorCode) {
        ;
    }
;
    }    return sb.toString();
}

_BufferAndStart _ensureFastAndSerializableByteData(List<int> buffer, int end, int start) {
    if (_isDirectIOCapableTypedList(buffer)) {
        return _BufferAndStart(buffer, start);
    }
    int length = end - start;
    auto newBuffer = Uint8List(length);
    newBuffer.setRange(0, length, buffer, start);
    return _BufferAndStart(newBuffer, 0);
}
