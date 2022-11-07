#include "_network_image_io.hpp"
NetworkImage::NetworkImage(Map<String, String> headers, double scale, String url) {
    {
        assert(url != nullptr);
        assert(scale != nullptr);
    }
}

Future<NetworkImage> NetworkImage::obtainKey(ImageConfiguration configuration) {
    return <NetworkImage>SynchronousFuture(this);
}

ImageStreamCompleter NetworkImage::load(DecoderCallback decode, NetworkImage key) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>StreamController();
    return MultiFrameImageStreamCompleter(_loadAsync((, chunkEvents, nullptr, decode), chunkEvents.stream, key.scale, key.url, );
}

ImageStreamCompleter NetworkImage::loadBuffer(DecoderBufferCallback decode, NetworkImage key) {
    StreamController<ImageChunkEvent> chunkEvents = <ImageChunkEvent>StreamController();
    return MultiFrameImageStreamCompleter(_loadAsync((, chunkEvents, decode, nullptr), chunkEvents.stream, key.scale, key.url, );
}

bool NetworkImage::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is NetworkImage && other.url == url && other.scale == scale;
}

int NetworkImage::hashCode() {
    return Object.hash(url, scale);
}

String NetworkImage::toString() {
    return "${objectRuntimeType(this, 'NetworkImage')}("$url", scale: $scale)";
}

HttpClient NetworkImage::_httpClient() {
    HttpClient client = _sharedHttpClient;
    assert(());
    return client;
}

Future<Codec> NetworkImage::_loadAsync(StreamController<ImageChunkEvent> chunkEvents, DecoderBufferCallback decode, DecoderCallback decodeDepreacted, NetworkImage key) {
    ;
}
