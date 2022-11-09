#ifndef DART_CONVERT_ENCODING
#define DART_CONVERT_ENCODING
#include <base.hpp>

#include <dart/core/core.hpp>


class EncodingCls : public CodecCls<String, List<int>> {
public:

     EncodingCls();
    virtual Converter<String, List<int>> encoder();
    virtual Converter<List<int>, String> decoder();
    virtual Future<String> decodeStream(Stream<List<int>> byteStream);

    virtual String name();
    static Encoding getByName(String name);

private:
    static Map<String, Encoding> _nameToEncoding;


};
using Encoding = std::shared_ptr<EncodingCls>;


#endif