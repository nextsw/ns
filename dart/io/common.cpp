#include "common.hpp"
bool _isErrorResponse(response ) {
    return response is List && response[0] != _successResponse;
}

void _exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}

String IOExceptionCls::toString() {
    return "IOException";
}

String OSErrorCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write("OS Error");
    if (message->isNotEmpty) {
            auto _c1 = sb;    _c1.auto _c2 = write(": ");    _c2.write(message);    _c2;_c1;
        if (errorCode != noErrorCode) {
                    auto _c3 = sb;        _c3.auto _c4 = write(", errno = ");        _c4.write(errorCode->toString());        _c4;_c3;
        }
    } else     {
        if (errorCode != noErrorCode) {
            auto _c5 = sb;    _c5.auto _c6 = write(": errno = ");    _c6.write(errorCode->toString());    _c6;_c5;
    }
;
    }    return sb->toString();
}

_BufferAndStart _ensureFastAndSerializableByteData(List<int> buffer, int end, int start) {
    if (_isDirectIOCapableTypedList(buffer)) {
        return make<_BufferAndStartCls>(buffer, start);
    }
    int length = end - start;
    auto newBuffer = make<Uint8ListCls>(length);
    newBuffer->setRange(0, length, buffer, start);
    return make<_BufferAndStartCls>(newBuffer, 0);
}
