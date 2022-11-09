#include "security_context.hpp"
Uint8List SecurityContextCls::_protocolsToLengthEncoding(List<String> protocols) {
    if (protocols == nullptr || protocols->length == 0) {
        return make<Uint8ListCls>(0);
    }
    int protocolsLength = protocols->length;
    int expectedLength = protocolsLength;
    for (;  < protocolsLength; i++) {
        int length = protocols[i]->length;
        if (length > 0 && length <= 255) {
            expectedLength = length;
        } else {
            ;
        }
    }
    if (expectedLength >= (1 << 13)) {
        ;
    }
    auto bytes = make<Uint8ListCls>(expectedLength);
    int bytesOffset = 0;
    for (;  < protocolsLength; i++) {
        String proto = protocols[i];
        bytes[bytesOffset++] = proto->length;
        int bits = 0;
        for (;  < proto->length; j++) {
            auto char = proto->codeUnitAt(j);
            bits = char;
            bytes[bytesOffset++] = char & 0xff;
        }
        if (bits > 0x7f) {
            return _protocolsToLengthEncodingNonAsciiBailout(protocols);
        }
    }
    return bytes;
}

Uint8List SecurityContextCls::_protocolsToLengthEncodingNonAsciiBailout(List<String> protocols) {
    InlineMethod;
    List<int> bytes = makeList();
    for (;  < protocols->length; i++) {
        addProtocol(bytes, protocols[i]);
    }
    if (bytes->length >= (1 << 13)) {
        ;
    }
    return Uint8ListCls->fromList(bytes);
}
