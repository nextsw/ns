#ifndef PACKAGES_FLUTTER_SRC_PAINTING__NETWORK_IMAGE_IO
#define PACKAGES_FLUTTER_SRC_PAINTING__NETWORK_IMAGE_IO
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "image_provider.hpp"
#include "image_stream.hpp"


class NetworkImageCls : public ImageProviderCls<NetworkImage> {
public:
    String url;

    double scale;

    Map<String, String> headers;


     NetworkImageCls(String url, Map<String, String> headers, double scale);

    virtual Future<NetworkImage> obtainKey(ImageConfiguration configuration);

    virtual ImageStreamCompleter load(NetworkImage key, DecoderCallback decode);

    virtual ImageStreamCompleter loadBuffer(NetworkImage key, DecoderBufferCallback decode);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static HttpClient _sharedHttpClient;


    static HttpClient _httpClient();

    virtual Future<Codec> _loadAsync(NetworkImage key, StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted);

};
using NetworkImage = std::shared_ptr<NetworkImageCls>;


#endif