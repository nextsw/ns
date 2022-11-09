#ifndef PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_RESOLUTION
#define PACKAGES_FLUTTER_SRC_PAINTING_IMAGE_RESOLUTION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/convert/convert.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "image_provider.hpp"

String _kAssetManifestFileName;

double _kLowDprLimit;


class AssetImageCls : public AssetBundleImageProviderCls {
public:
    String assetName;

    AssetBundle bundle;

    String package;


     AssetImageCls(String assetName, AssetBundle bundle, String package);

    virtual String keyName();

    virtual Future<AssetBundleImageKey> obtainKey(ImageConfiguration configuration);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static double _naturalResolution;

    static RegExp _extractRatioRegExp;


    static Future<Map<String, List<String>>> _manifestParser(String jsonData);

    virtual String _chooseVariant(List<String> candidates, ImageConfiguration config, String main);

    virtual String _findBestVariant(SplayTreeMap<double, String> candidates, double value);

    virtual double _parseScale(String key);

};
using AssetImage = std::shared_ptr<AssetImageCls>;


#endif