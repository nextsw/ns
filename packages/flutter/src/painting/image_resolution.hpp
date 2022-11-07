#ifndef IMAGE_RESOLUTION_H
#define IMAGE_RESOLUTION_H
#include <memory>

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <convert/convert.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "image_provider.hpp"


const String _kAssetManifestFileName;

const double _kLowDprLimit;


class AssetImage : AssetBundleImageProvider {
public:
    String assetName;

    AssetBundle bundle;

    String package;


     AssetImage(String assetName, AssetBundle bundle, String package);

    String keyName();

    Future<AssetBundleImageKey> obtainKey(ImageConfiguration configuration);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static const double _naturalResolution;

    static RegExp _extractRatioRegExp;


    static Future<Map<String, List<String>>> _manifestParser(String jsonData);

    String _chooseVariant(List<String> candidates, ImageConfiguration config, String main);

    String _findBestVariant(SplayTreeMap<double, String> candidates, double value);

    double _parseScale(String key);

};

#endif