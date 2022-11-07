#ifndef _NETWORK_IMAGE_IO_H
#define _NETWORK_IMAGE_IO_H
#include <memory>

#include <async/async.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "image_provider.hpp"
#include "image_stream.hpp"



class NetworkImage : ImageProvider<NetworkImage> {
public:
    String url;

    double scale;

    Map<String, String> headers;


     NetworkImage(Map<String, String> headers, double scale, String url);

    Future<NetworkImage> obtainKey(ImageConfiguration configuration);

    ImageStreamCompleter load(DecoderCallback decode, NetworkImage key);

    ImageStreamCompleter loadBuffer(DecoderBufferCallback decode, NetworkImage key);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static HttpClient _sharedHttpClient;


    static HttpClient _httpClient();

    Future<Codec> _loadAsync(StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted, NetworkImage key);

};

#endif