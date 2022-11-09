#include "encoding.hpp"
Future<String> EncodingCls::decodeStream(Stream<List<int>> byteStream) {
    auto _c1 = buffer;_c1.write(stringValue);return decoder->bind(byteStream)->fold(make<StringBufferCls>(), [=] (StringBuffer buffer,String string)     {
        _c1;
    })->then([=] (StringBuffer buffer)     {
        buffer->toString();
    });
}

Encoding EncodingCls::getByName(String name) {
    if (name == nullptr)     {
        return nullptr;
    }
    return _nameToEncoding[name->toLowerCase()];
}
