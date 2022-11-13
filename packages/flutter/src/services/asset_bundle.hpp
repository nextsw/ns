#ifndef PACKAGES_FLUTTER_SRC_SERVICES_ASSET_BUNDLE
#define PACKAGES_FLUTTER_SRC_SERVICES_ASSET_BUNDLE
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/convert/convert.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"


class AssetBundleCls : public ObjectCls {
public:

    virtual Future<ByteData> load(String key);
    virtual Future<ImmutableBuffer> loadBuffer(String key);

    virtual Future<String> loadString(String key, bool cache);

    template<typename T>
 virtual Future<T> loadStructuredData(String key, std::function<Future<T>(String value)> parser);
    virtual void evict(String key);

    virtual void clear();

    virtual String toString();

private:

    static String _utf8decode(ByteData data);

};
using AssetBundle = std::shared_ptr<AssetBundleCls>;

class NetworkAssetBundleCls : public AssetBundleCls {
public:

     NetworkAssetBundleCls(Uri baseUrl);

    virtual Future<ByteData> load(String key);

    template<typename T>
 virtual Future<T> loadStructuredData(String key, std::function<Future<T>(String value)> parser);

    virtual String toString();

private:
    Uri _baseUrl;

    HttpClient _httpClient;


    virtual Uri _urlFromKey(String key);

};
using NetworkAssetBundle = std::shared_ptr<NetworkAssetBundleCls>;

class CachingAssetBundleCls : public AssetBundleCls {
public:

    virtual Future<String> loadString(String key, bool cache);

    template<typename T>
 virtual Future<T> loadStructuredData(String key, std::function<Future<T>(String value)> parser);

    virtual void evict(String key);

    virtual void clear();

    virtual Future<ImmutableBuffer> loadBuffer(String key);

private:
    Map<String, Future<String>> _stringCache;

    Map<String, Future<Object>> _structuredDataCache;


};
using CachingAssetBundle = std::shared_ptr<CachingAssetBundleCls>;

class PlatformAssetBundleCls : public CachingAssetBundleCls {
public:

    virtual Future<ByteData> load(String key);

    virtual Future<ImmutableBuffer> loadBuffer(String key);

private:

};
using PlatformAssetBundle = std::shared_ptr<PlatformAssetBundleCls>;
AssetBundle _initRootBundle();

AssetBundle rootBundle;



#endif