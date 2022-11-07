#include "encoding.hpp"
Future<String> Encoding::decodeStream(Stream<List<int>> byteStream) {
    return decoder.bind(byteStream).fold(StringBuffer(), ).then();
}

Encoding Encoding::getByName(String name) {
    if (name == nullptr)     {
        return nullptr;
    }
    return _nameToEncoding[name.toLowerCase()];
}
