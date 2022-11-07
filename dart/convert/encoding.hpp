#ifndef ENCODING_H
#define ENCODING_H
#include <memory>




class Encoding : Codec<String, List<int>> {
public:

     Encoding();

    Converter<String, List<int>> encoder();

    Converter<List<int>, String> decoder();

    Future<String> decodeStream(Stream<List<int>> byteStream);

    String name();

    static Encoding getByName(String name);

private:
    static Map<String, Encoding> _nameToEncoding;


};

#endif