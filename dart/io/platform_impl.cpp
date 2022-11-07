#include "platform_impl.hpp"
String _Platform::localeName() {
    Unknown result = (_localeClosure == nullptr)? _localeName() : _localeClosure!();
    if (result is OSError) {
        ;
    }
    return result;
}

int _Platform::numberOfProcessors() {
    return _numberOfProcessors();
}

String _Platform::pathSeparator() {
    return _pathSeparator();
}

String _Platform::operatingSystem() {
    return _operatingSystem();
}

Uri _Platform::script() {
    return _script();
}

String _Platform::operatingSystemVersion() {
    if (_cachedOSVersion == nullptr) {
        auto result = _operatingSystemVersion();
        if (result is OSError) {
            ;
        }
        _cachedOSVersion = result;
    }
    return _cachedOSVersion!;
}

String _Platform::localHostname() {
    auto result = _localHostname();
    if (result is OSError) {
        ;
    }
    return result;
}

List<String> _Platform::executableArguments() {
    return _executableArguments();
}

Map<String, String> _Platform::environment() {
    if (_environmentCache == nullptr) {
        auto env = _environment();
        if (env is! OSError) {
            auto isWindows = operatingSystem == "windows";
            auto result = isWindows? <String>_CaseInsensitiveStringMap() : <String, String>Map();
            for (auto str : env) {
                if (str == nullptr) {
                    continue;
                }
                auto equalsIndex = str.indexOf("=");
                if (equalsIndex > 0) {
                    result[str.substring(0, equalsIndex)] = str.substring(equalsIndex + 1);
                }
            }
            _environmentCache = <String, String>UnmodifiableMapView(result);
        } else {
            _environmentCache = env;
        }
    }
    if (_environmentCache is OSError) {
        ;
    } else {
        return _environmentCache!;
    }
}

String _Platform::version() {
    return _version();
}

bool _CaseInsensitiveStringMap::containsKey(Object key) {
    return key is String && _map.containsKey(key.toUpperCase());
}

bool _CaseInsensitiveStringMap::containsValue(Object value) {
    return _map.containsValue(value);
}

V _CaseInsensitiveStringMap::[](Object key) {
    return key is String? _map[key.toUpperCase()] : nullptr;
}

void _CaseInsensitiveStringMap::[]=(String key, V value) {
    _map[key.toUpperCase()] = value;
}

V _CaseInsensitiveStringMap::putIfAbsent(FunctionType ifAbsent, String key) {
    return _map.putIfAbsent(key.toUpperCase(), ifAbsent);
}

void _CaseInsensitiveStringMap::addAll(Map<String, V> other) {
    other.forEach();
}

V _CaseInsensitiveStringMap::remove(Object key) {
    return key is String? _map.remove(key.toUpperCase()) : nullptr;
}

void _CaseInsensitiveStringMap::clear() {
    _map.clear();
}

void _CaseInsensitiveStringMap::forEach(FunctionType f) {
    _map.forEach(f);
}

Iterable<String> _CaseInsensitiveStringMap::keys() {
    return _map.keys;
}

Iterable<V> _CaseInsensitiveStringMap::values() {
    return _map.values;
}

int _CaseInsensitiveStringMap::length() {
    return _map.length;
}

bool _CaseInsensitiveStringMap::isEmpty() {
    return _map.isEmpty;
}

bool _CaseInsensitiveStringMap::isNotEmpty() {
    return _map.isNotEmpty;
}

Iterable<MapEntry<String, V>> _CaseInsensitiveStringMap::entries() {
    return _map.entries;
}

Map<K2, V2> _CaseInsensitiveStringMap::map<K2, V2>(FunctionType transform) {
    return _map.map(transform);
}

V _CaseInsensitiveStringMap::update(FunctionType ifAbsent, String key, FunctionType update) {
    return _map.update(key.toUpperCase(), updateifAbsent);
}

void _CaseInsensitiveStringMap::updateAll(FunctionType update) {
    _map.updateAll(update);
}

void _CaseInsensitiveStringMap::removeWhere(FunctionType test) {
    _map.removeWhere(test);
}

String _CaseInsensitiveStringMap::toString() {
    return _map.toString();
}
