#include "asset_bundle.hpp"
Future<ImmutableBuffer> AssetBundleCls::loadBuffer(String key) {
    ByteData data = await load(key);
    return ui->ImmutableBufferCls->fromUint8List(data->buffer->asUint8List());
}

Future<String> AssetBundleCls::loadString(bool cache, String key) {
    ByteData data = await load(key);
    if (data == nullptr) {
        ;
    }
    if (data->lengthInBytes < 50 * 1024) {
        return utf8->decode(data->buffer->asUint8List());
    }
    return compute(_utf8decode, data__s("UTF8 decode for "$key""));
}

void AssetBundleCls::evict(String key) {
}

void AssetBundleCls::clear() {
}

String AssetBundleCls::toString() {
    return __s("${describeIdentity(this)}()");
}

String AssetBundleCls::_utf8decode(ByteData data) {
    return utf8->decode(data->buffer->asUint8List());
}

NetworkAssetBundleCls::NetworkAssetBundleCls(Uri baseUrl) {
    {
        _baseUrl = baseUrl;
        _httpClient = make<HttpClientCls>();
    }
}

Future<ByteData> NetworkAssetBundleCls::load(String key) {
    HttpClientRequest request = await _httpClient->getUrl(_urlFromKey(key));
    HttpClientResponse response = await request->close();
    if (response->statusCode != HttpStatusCls::ok) {
        ;
    }
    Uint8List bytes = await consolidateHttpClientResponseBytes(response);
    return bytes->buffer->asByteData();
}

Future<T> NetworkAssetBundleCls::loadStructuredDatatemplate<typename T> (String key, Future<T> parser(String value) ) {
    assert(key != nullptr);
    assert(parser != nullptr);
    return parser(await loadString(key));
}

String NetworkAssetBundleCls::toString() {
    return __s("${describeIdentity(this)}($_baseUrl)");
}

Uri NetworkAssetBundleCls::_urlFromKey(String key) {
    return _baseUrl->resolve(key);
}

Future<String> CachingAssetBundleCls::loadString(bool cache, String key) {
    if (cache) {
        return _stringCache->putIfAbsent(key, [=] ()         {
            super->loadString(key);
        });
    }
    return super->loadString(key);
}

Future<T> CachingAssetBundleCls::loadStructuredDatatemplate<typename T> (String key, Future<T> parser(String value) ) {
    assert(key != nullptr);
    assert(parser != nullptr);
    if (_structuredDataCache->containsKey(key)) {
        return as<Future<T>>(_structuredDataCache[key]!);
    }
    Completer<T> completer;
    Future<T> result;
    loadString(keyfalse)-><T>then(parser)-><void>then([=] (T value) {
        result = <T>make<SynchronousFutureCls>(value);
        _structuredDataCache[key] = result!;
        if (completer != nullptr) {
            completer->complete(value);
        }
    });
    if (result != nullptr) {
        return result!;
    }
    completer = <T>make<CompleterCls>();
    _structuredDataCache[key] = completer->future;
    return completer->future;
}

void CachingAssetBundleCls::evict(String key) {
    _stringCache->remove(key);
    _structuredDataCache->remove(key);
}

void CachingAssetBundleCls::clear() {
    _stringCache->clear();
    _structuredDataCache->clear();
}

Future<ImmutableBuffer> CachingAssetBundleCls::loadBuffer(String key) {
    ByteData data = await load(key);
    return ui->ImmutableBufferCls->fromUint8List(data->buffer->asUint8List());
}

Future<ByteData> PlatformAssetBundleCls::load(String key) {
    Uint8List encoded = utf8->encoder->convert(make<UriCls>(UriCls->encodeFull(key))->path);
    ByteData asset = await ServicesBindingCls::instance->defaultBinaryMessenger->send(__s("flutter/assets"), encoded->buffer->asByteData());
    if (asset == nullptr) {
        ;
    }
    return asset;
}

Future<ImmutableBuffer> PlatformAssetBundleCls::loadBuffer(String key) {
    if (kIsWeb) {
        ByteData bytes = await load(key);
        return ui->ImmutableBufferCls->fromUint8List(bytes->buffer->asUint8List());
    }
    bool debugUsePlatformChannel = false;
    assert([=] () {
        if (PlatformCls::environment->containsKey(__s("UNIT_TEST_ASSETS"))) {
            debugUsePlatformChannel = true;
        }
        return true;
    }());
    if (debugUsePlatformChannel) {
        ByteData bytes = await load(key);
        return ui->ImmutableBufferCls->fromUint8List(bytes->buffer->asUint8List());
    }
    try {
        return await ui->ImmutableBufferCls->fromAsset(key);
    } catch (Exception null) {
        ;
    };
}

AssetBundle _initRootBundle() {
    return make<PlatformAssetBundleCls>();
}
