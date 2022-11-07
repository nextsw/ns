#include "image_resolution.hpp"
AssetImage::AssetImage(String assetName, AssetBundle bundle, String package) {
    {
        assert(assetName != nullptr);
    }
}

String AssetImage::keyName() {
    return package == nullptr? assetName : "packages/$package/$assetName";
}

Future<AssetBundleImageKey> AssetImage::obtainKey(ImageConfiguration configuration) {
    AssetBundle chosenBundle = bundle ?? configuration.bundle ?? rootBundle;
    Completer<AssetBundleImageKey> completer;
    Future<AssetBundleImageKey> result;
    chosenBundle.<Map<String, List<String>>>loadStructuredData(_kAssetManifestFileName, _manifestParser).<void>then().catchError();
    if (result != nullptr) {
        return result!;
    }
    completer = <AssetBundleImageKey>Completer();
    return completer.future;
}

bool AssetImage::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is AssetImage && other.keyName == keyName && other.bundle == bundle;
}

int AssetImage::hashCode() {
    return Object.hash(keyName, bundle);
}

String AssetImage::toString() {
    return "${objectRuntimeType(this, 'AssetImage')}(bundle: $bundle, name: "$keyName")";
}

Future<Map<String, List<String>>> AssetImage::_manifestParser(String jsonData) {
    if (jsonData == nullptr) {
        return <Map<String, List<String>>>SynchronousFuture(nullptr);
    }
    Map<String, dynamic> parsedJson = (;
    Iterable<String> keys = parsedJson.keys;
    Map<String, List<String>> parsedManifest = ;
    return <Map<String, List<String>>>SynchronousFuture(parsedManifest);
}

String AssetImage::_chooseVariant(List<String> candidates, ImageConfiguration config, String main) {
    if (config.devicePixelRatio == nullptr || candidates == nullptr || candidates.isEmpty) {
        return main;
    }
    SplayTreeMap<double, String> mapping = <double, String>SplayTreeMap();
    for (String candidate : candidates) {
        mapping[_parseScale(candidate)] = candidate;
    }
    return _findBestVariant(mapping, config.devicePixelRatio!);
}

String AssetImage::_findBestVariant(SplayTreeMap<double, String> candidates, double value) {
    if (candidates.containsKey(value)) {
        return candidates[value]!;
    }
    double lower = candidates.lastKeyBefore(value);
    double upper = candidates.firstKeyAfter(value);
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

double AssetImage::_parseScale(String key) {
    if (key == assetName) {
        return _naturalResolution;
    }
    Uri assetUri = Uri.parse(key);
    String directoryPath = "";
    if (assetUri.pathSegments.length > 1) {
        directoryPath = assetUri.pathSegments[assetUri.pathSegments.length - 2];
    }
    Match match = _extractRatioRegExp.firstMatch(directoryPath);
    if (match != nullptr && match.groupCount > 0) {
        return double.parse(match.group(1)!);
    }
    return _naturalResolution;
}
