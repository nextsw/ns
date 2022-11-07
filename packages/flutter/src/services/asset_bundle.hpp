#ifndef ASSET_BUNDLE_H
#define ASSET_BUNDLE_H
#include <memory>
#include <typed_data.hpp>
#include <ui.hpp>

#include <async/async.hpp>
#include <convert/convert.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"



class AssetBundle {
public:

    Future<ByteData> load(String key);

    Future<ImmutableBuffer> loadBuffer(String key);

    Future<String> loadString(bool cache, String key);

    Future<T> loadStructuredData<T>(String key, FunctionType parser);

    void evict(String key);

    void clear();

    String toString();

private:

    static String _utf8decode(ByteData data);

};

class NetworkAssetBundle : AssetBundle {
public:

     NetworkAssetBundle(Uri baseUrl);

    Future<ByteData> load(String key);

    Future<T> loadStructuredData<T>(String key, FunctionType parser);

    String toString();

private:
    Uri _baseUrl;

    HttpClient _httpClient;


    Uri _urlFromKey(String key);

};

class CachingAssetBundle : AssetBundle {
public:

    Future<String> loadString(bool cache, String key);

    Future<T> loadStructuredData<T>(String key, FunctionType parser);

    void evict(String key);

    void clear();

    Future<ImmutableBuffer> loadBuffer(String key);

private:
    Map<String, Future<String>> _stringCache;

    Map<String, Future<dynamic>> _structuredDataCache;


};

class PlatformAssetBundle : CachingAssetBundle {
public:

    Future<ByteData> load(String key);

    Future<ImmutableBuffer> loadBuffer(String key);

private:

};
AssetBundle _initRootBundle();

AssetBundle rootBundle;


#endif