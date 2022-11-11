#include "_network_image_io.hpp"
NetworkImageCls::NetworkImageCls(Map<String, String> headers, double scale, String url) {
    {
        assert(url != nullptr);
        assert(scale != nullptr);
    }
}

Future<NetworkImage> NetworkImageCls::obtainKey(ImageConfiguration configuration) {
    return <NetworkImage>make<SynchronousFutureCls>(this);
}

ImageStreamCompleter NetworkImageCls::load(DecoderCallback decode, NetworkImage key) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>make<StreamControllerCls>();
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(as<NetworkImage>(key), chunkEvents, nullptr, decode), chunkEvents->stream(), key->scale, key->url, [=] ()     {
        makeList(ArrayItem, ArrayItem);
    });
}

ImageStreamCompleter NetworkImageCls::loadBuffer(DecoderBufferCallback decode, NetworkImage key) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>make<StreamControllerCls>();
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(as<NetworkImage>(key), chunkEvents, decode, nullptr), chunkEvents->stream(), key->scale, key->url, [=] ()     {
        makeList(ArrayItem, ArrayItem);
    });
}

bool NetworkImageCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<NetworkImage>(other) && other->url == url && other->scale == scale;
}

int NetworkImageCls::hashCode() {
    return ObjectCls->hash(url, scale);
}

String NetworkImageCls::toString() {
    return __s("${objectRuntimeType(this, 'NetworkImage')}("$url", scale: $scale)");
}

HttpClient NetworkImageCls::_httpClient() {
    HttpClient client = _sharedHttpClient;
    assert([=] () {
        if (debugNetworkImageHttpClientProvider != nullptr) {
            client = debugNetworkImageHttpClientProvider!();
        }
        return true;
    }());
    return client;
}

Future<Codec> NetworkImageCls::_loadAsync(StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted, NetworkImage key) {
    try {
        assert(key == this);
        Uri resolved = UriCls::base->resolve(key->url);
        HttpClientRequest request = await _httpClient()->getUrl(resolved);
        headers?->forEach([=] (String name,String value) {
            request->headers->add(name, value);
        });
        HttpClientResponse response = await request->close();
        if (response->statusCode != HttpStatusCls::ok) {
            await await response-><List<int>>drain(makeList());
            throw image_provider->make<NetworkImageLoadExceptionCls>(response->statusCode, resolved);
        }
        Uint8List bytes = await consolidateHttpClientResponseBytes(response[=] (int cumulative,int total) {
    chunkEvents->add(make<ImageChunkEventCls>(cumulative, total));
});
        if (bytes->lengthInBytes == 0) {
            throw make<ExceptionCls>(__s("NetworkImage is an empty file: $resolved"));
        }
        if (decode != nullptr) {
            ImmutableBuffer buffer = await ui->ImmutableBufferCls->fromUint8List(bytes);
            return decode(buffer);
        } else {
            assert(decodeDepreacted != nullptr);
            return decodeDepreacted!(bytes);
        }
    } catch (Unknown e) {
        scheduleMicrotask([=] () {
            PaintingBindingCls::instance->imageCache->evict(key);
        });
        throw;
    } finally {
        chunkEvents->close();
    };
}
