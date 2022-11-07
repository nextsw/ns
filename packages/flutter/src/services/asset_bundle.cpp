#include "asset_bundle.hpp"
Future<ImmutableBuffer> AssetBundle::loadBuffer(String key) {
    ByteData data = await load(key);
    return ui.ImmutableBuffer.fromUint8List(data.buffer.asUint8List());
}

Future<String> AssetBundle::loadString(bool cache, String key) {
    ByteData data = await load(key);
    if (data == nullptr) {
        ;
    }
    if (data.lengthInBytes < 50 * 1024) {
        return utf8.decode(data.buffer.asUint8List());
    }
    return compute(_utf8decode, data"UTF8 decode for "$key"");
}

void AssetBundle::evict(String key) {
}

void AssetBundle::clear() {
}

String AssetBundle::toString() {
    return "${describeIdentity(this)}()";
}

String AssetBundle::_utf8decode(ByteData data) {
    return utf8.decode(data.buffer.asUint8List());
}

NetworkAssetBundle::NetworkAssetBundle(Uri baseUrl) {
    {
        _baseUrl = baseUrl;
        _httpClient = HttpClient();
    }
}

Future<ByteData> NetworkAssetBundle::load(String key) {
    HttpClientRequest request = await _httpClient.getUrl(_urlFromKey(key));
    HttpClientResponse response = await request.close();
    if (response.statusCode != HttpStatus.ok) {
        ;
    }
    Uint8List bytes = await consolidateHttpClientResponseBytes(response);
    return bytes.buffer.asByteData();
}

Future<T> NetworkAssetBundle::loadStructuredData<T>(String key, FunctionType parser) {
    assert(key != nullptr);
    assert(parser != nullptr);
    return parser(await loadString(key));
}

String NetworkAssetBundle::toString() {
    return "${describeIdentity(this)}($_baseUrl)";
}

Uri NetworkAssetBundle::_urlFromKey(String key) {
    return _baseUrl.resolve(key);
}

Future<String> CachingAssetBundle::loadString(bool cache, String key) {
    if (cache) {
        return _stringCache.putIfAbsent(key, );
    }
    return super.loadString(key);
}

Future<T> CachingAssetBundle::loadStructuredData<T>(String key, FunctionType parser) {
    assert(key != nullptr);
    assert(parser != nullptr);
    if (_structuredDataCache.containsKey(key)) {
        return (;
    }
    Completer<T> completer;
    Future<T> result;
    loadString(keyfalse).<T>then(parser).<void>then();
    if (result != nullptr) {
        return result!;
    }
    completer = <T>Completer();
    _structuredDataCache[key] = completer.future;
    return completer.future;
}

void CachingAssetBundle::evict(String key) {
    _stringCache.remove(key);
    _structuredDataCache.remove(key);
}

void CachingAssetBundle::clear() {
    _stringCache.clear();
    _structuredDataCache.clear();
}

Future<ImmutableBuffer> CachingAssetBundle::loadBuffer(String key) {
    ByteData data = await load(key);
    return ui.ImmutableBuffer.fromUint8List(data.buffer.asUint8List());
}

Future<ByteData> PlatformAssetBundle::load(String key) {
    Uint8List encoded = utf8.encoder.convert(Uri(Uri.encodeFull(key)).path);
    ByteData asset = await ServicesBinding.instance.defaultBinaryMessenger.send("flutter/assets", encoded.buffer.asByteData());
    if (asset == nullptr) {
        ;
    }
    return asset;
}

Future<ImmutableBuffer> PlatformAssetBundle::loadBuffer(String key) {
    if (kIsWeb) {
        ByteData bytes = await load(key);
        return ui.ImmutableBuffer.fromUint8List(bytes.buffer.asUint8List());
    }
    bool debugUsePlatformChannel = false;
    assert(());
    if (debugUsePlatformChannel) {
        ByteData bytes = await load(key);
        return ui.ImmutableBuffer.fromUint8List(bytes.buffer.asUint8List());
    }
    ;
}

AssetBundle _initRootBundle() {
    return PlatformAssetBundle();
}
