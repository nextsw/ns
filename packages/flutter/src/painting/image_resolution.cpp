#include "image_resolution.hpp"
AssetImageCls::AssetImageCls(String assetName, AssetBundle bundle, String package) {
    {
        assert(assetName != nullptr);
    }
}

String AssetImageCls::keyName() {
    return package == nullptr? assetName : __sf("packages/%s/%s", package, assetName);
}

Future<AssetBundleImageKey> AssetImageCls::obtainKey(ImageConfiguration configuration) {
    AssetBundle chosenBundle = bundle | configuration->bundle | rootBundle;
    Completer<AssetBundleImageKey> completer;
    Future<AssetBundleImageKey> result;
    chosenBundle-><Map<String, List<String>>>loadStructuredData(_kAssetManifestFileName, _manifestParser)-><void>then([=] (Map<String, List<String>> manifest) {
        String chosenName = _chooseVariant(keyName(), configuration, manifest == nullptr? nullptr : manifest[keyName()])!;
        double chosenScale = _parseScale(chosenName);
        AssetBundleImageKey key = make<AssetBundleImageKeyCls>(chosenBundle, chosenName, chosenScale);
        if (completer != nullptr) {
            completer->complete(key);
        } else {
            result = <AssetBundleImageKey>make<SynchronousFutureCls>(key);
        }
    })->catchError([=] (Object error,StackTrace stack) {
        assert(completer != nullptr);
        assert(result == nullptr);
        completer!->completeError(error, stack);
    });
    if (result != nullptr) {
        return result!;
    }
    completer = <AssetBundleImageKey>make<CompleterCls>();
    return completer->future();
}

bool AssetImageCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<AssetImage>(other) && other->keyName == keyName() && other->bundle == bundle;
}

int AssetImageCls::hashCode() {
    return ObjectCls->hash(keyName(), bundle);
}

String AssetImageCls::toString() {
    return __sf("%s(bundle: %s, name: "%s")", objectRuntimeType(this, __s("AssetImage")), bundle, keyName());
}

Future<Map<String, List<String>>> AssetImageCls::_manifestParser(String jsonData) {
    if (jsonData == nullptr) {
        return <Map<String, List<String>>>make<SynchronousFutureCls>(nullptr);
    }
    Map<String, dynamic> parsedJson = as<Map<String, dynamic>>(json->decode(jsonData));
    Iterable<String> keys = parsedJson->keys();
    Map<String, List<String>> map1 = make<MapCls<>>();for (String key : keys) {    ;}{    map1.set(key, <String>from(as<List<dynamic>>(parsedJson[key])));}Map<String, List<String>> parsedManifest = list1;
    return <Map<String, List<String>>>make<SynchronousFutureCls>(parsedManifest);
}

String AssetImageCls::_chooseVariant(String main, ImageConfiguration config, List<String> candidates) {
    if (config->devicePixelRatio == nullptr || candidates == nullptr || candidates->isEmpty()) {
        return main;
    }
    SplayTreeMap<double, String> mapping = <double, String>make<SplayTreeMapCls>();
    for (String candidate : candidates) {
        mapping[_parseScale(candidate)] = candidate;
    }
    return _findBestVariant(mapping, config->devicePixelRatio!);
}

String AssetImageCls::_findBestVariant(SplayTreeMap<double, String> candidates, double value) {
    if (candidates->containsKey(value)) {
        return candidates[value]!;
    }
    double lower = candidates->lastKeyBefore(value);
    double upper = candidates->firstKeyAfter(value);
    if (lower == nullptr) {
        return candidates[upper];
    }
    if (upper == nullptr) {
        return candidates[lower];
    }
    if ( < _kLowDprLimit || value > (lower + upper) / 2) {
        return candidates[upper];
    } else {
        return candidates[lower];
    }
}

double AssetImageCls::_parseScale(String key) {
    if (key == assetName) {
        return _naturalResolution;
    }
    Uri assetUri = UriCls->parse(key);
    String directoryPath = __s("");
    if (assetUri->pathSegments()->length() > 1) {
        directoryPath = assetUri->pathSegments()[assetUri->pathSegments()->length() - 2];
    }
    Match match = _extractRatioRegExp->firstMatch(directoryPath);
    if (match != nullptr && match->groupCount() > 0) {
        return double->parse(match->group(1)!);
    }
    return _naturalResolution;
}
