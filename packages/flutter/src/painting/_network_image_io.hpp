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


     NetworkImageCls(Map<String, String> headers, double scale, String url);

    virtual Future<NetworkImage> obtainKey(ImageConfiguration configuration);

    virtual ImageStreamCompleter load(DecoderCallback decode, NetworkImage key);

    virtual ImageStreamCompleter loadBuffer(DecoderBufferCallback decode, NetworkImage key);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static HttpClient _sharedHttpClient;


    static HttpClient _httpClient();

    virtual Future<Codec> _loadAsync(StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted, NetworkImage key);

};
using NetworkImage = std::shared_ptr<NetworkImageCls>;


#endif