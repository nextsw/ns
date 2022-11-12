#include "_network_image_io.hpp"
NetworkImageCls::NetworkImageCls(String url, Map<String, String> headers, double scale) {
    {
        assert(url != nullptr);
        assert(scale != nullptr);
    }
}

Future<NetworkImage> NetworkImageCls::obtainKey(ImageConfiguration configuration) {
    return <NetworkImage>make<SynchronousFutureCls>(this);
}

ImageStreamCompleter NetworkImageCls::load(NetworkImage key, DecoderCallback decode) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>make<StreamControllerCls>();
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(as<NetworkImage>(key), chunkEvents, nullptr, decode), chunkEvents->stream(), key->scale, key->url, [=] () {
        makeList(ArrayItem, ArrayItem);
    });
}

ImageStreamCompleter NetworkImageCls::loadBuffer(NetworkImage key, DecoderBufferCallback decode) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>make<StreamControllerCls>();
    return make<MultiFrameImageStreamCompleterCls>(_loadAsync(as<NetworkImage>(key), chunkEvents, decode, nullptr), chunkEvents->stream(), key->scale, key->url, [=] () {
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
    return __s("%s$%s$%s;");
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

Future<Codec> NetworkImageCls::_loadAsync(NetworkImage key, StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted) {
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
        Uint8List bytes = await consolidateHttpClientResponseBytes(response, [=] (int cumulative,int total) {
    chunkEvents->add(make<ImageChunkEventCls>(cumulative, total));
});
        if (bytes->lengthInBytes == 0) {
            throw make<ExceptionCls>(__s("NetworkImage is an empty file: %s)"));
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
