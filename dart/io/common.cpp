#include "common.hpp"
bool _isErrorResponse(response ) {
    return is<List>(response) && response[0] != _successResponse;
}

void _exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}

String IOExceptionCls::toString() {
    return __s("IOException");
}

String OSErrorCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write(__s("OS Error"));
    if (message->isNotEmpty()) {
            auto _c1 = sb;    _c1.auto _c2 = write(__s(": "));    _c2.write(message);    _c2;_c1;
        if (errorCode != noErrorCode) {
                    auto _c3 = sb;        _c3.auto _c4 = write(__s(", errno = "));        _c4.write(errorCode->toString());        _c4;_c3;
        }
    } else     {
        if (errorCode != noErrorCode) {
            auto _c5 = sb;    _c5.auto _c6 = write(__s(": errno = "));    _c6.write(errorCode->toString());    _c6;_c5;
    }
;
    }    return sb->toString();
}

_BufferAndStart _ensureFastAndSerializableByteData(List<int> buffer, int start, int end) {
    if (_isDirectIOCapableTypedList(buffer)) {
        return make<_BufferAndStartCls>(buffer, start);
    }
    int length = end - start;
    auto newBuffer = make<Uint8ListCls>(length);
    newBuffer->setRange(0, length, buffer, start);
    return make<_BufferAndStartCls>(newBuffer, 0);
}
