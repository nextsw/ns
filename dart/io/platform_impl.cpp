#include "platform_impl.hpp"
String _PlatformCls::localeName() {
    Unknown result = (_localeClosure == nullptr)? _localeName() : _localeClosure!();
    if (is<OSError>(result)) {
        throw as<OSErrorCls>(result);
    }
    return result;
}

int _PlatformCls::numberOfProcessors() {
    return _numberOfProcessors();
}

String _PlatformCls::pathSeparator() {
    return _pathSeparator();
}

String _PlatformCls::operatingSystem() {
    return _operatingSystem();
}

Uri _PlatformCls::script() {
    return _script();
}

String _PlatformCls::operatingSystemVersion() {
    if (_cachedOSVersion == nullptr) {
        auto result = _operatingSystemVersion();
        if (is<OSError>(result)) {
            throw as<OSErrorCls>(result);
        }
        _cachedOSVersion = result;
    }
    return _cachedOSVersion!;
}

String _PlatformCls::localHostname() {
    auto result = _localHostname();
    if (is<OSError>(result)) {
        throw as<OSErrorCls>(result);
    }
    return result;
}

List<String> _PlatformCls::executableArguments() {
    return _executableArguments();
}

Map<String, String> _PlatformCls::environment() {
    if (_environmentCache == nullptr) {
        auto env = _environment();
        if (!is<OSError>(env)) {
            auto isWindows = operatingSystem == __s("windows");
            auto result = isWindows? <String>make<_CaseInsensitiveStringMapCls>() : <String, String>make<MapCls>();
            for (auto str : as<OSErrorCls>(env)) {
                if (str == nullptr) {
                    continue;
                }
                auto equalsIndex = str->indexOf(__s("="));
                if (equalsIndex > 0) {
                    result[str->substring(0, equalsIndex)] = str->substring(equalsIndex + 1);
                }
            }
            _environmentCache = <String, String>make<UnmodifiableMapViewCls>(result);
        } else {
            _environmentCache = env;
        }
    }
    if (is<OSError>(_environmentCache)) {
        throw as<OSErrorCls>(_environmentCache);
    } else {
        return _environmentCache!;
    }
}

String _PlatformCls::version() {
    return _version();
}

template<typename V>
bool _CaseInsensitiveStringMapCls<V>::containsKey(Object key) {
    return is<String>(key) && _map->containsKey(key->toUpperCase());
}

template<typename V>
bool _CaseInsensitiveStringMapCls<V>::containsValue(Object value) {
    return _map->containsValue(value);
}

template<typename V>
V _CaseInsensitiveStringMapCls<V>::[](Object key) {
    return is<String>(key)? _map[key->toUpperCase()] : nullptr;
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::[]=(String key, V value) {
    _map[key->toUpperCase()] = value;
}

template<typename V>
V _CaseInsensitiveStringMapCls<V>::putIfAbsent(String key, std::function<V()> ifAbsent) {
    return _map->putIfAbsent(key->toUpperCase(), ifAbsent);
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::addAll(Map<String, V> other) {
    other->forEach([=] (Unknown  key,Unknown  value) {
        this[key->toUpperCase()] = value;
    });
}

template<typename V>
V _CaseInsensitiveStringMapCls<V>::remove(Object key) {
    return is<String>(key)? _map->remove(key->toUpperCase()) : nullptr;
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::clear() {
    _map->clear();
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::forEach(std::function<void(String key, V value)> f) {
    _map->forEach(f);
}

template<typename V>
Iterable<String> _CaseInsensitiveStringMapCls<V>::keys() {
    return _map->keys();
}

template<typename V>
Iterable<V> _CaseInsensitiveStringMapCls<V>::values() {
    return _map->values();
}

template<typename V>
int _CaseInsensitiveStringMapCls<V>::length() {
    return _map->length();
}

template<typename V>
bool _CaseInsensitiveStringMapCls<V>::isEmpty() {
    return _map->isEmpty();
}

template<typename V>
bool _CaseInsensitiveStringMapCls<V>::isNotEmpty() {
    return _map->isNotEmpty();
}

template<typename V>
Iterable<MapEntry<String, V>> _CaseInsensitiveStringMapCls<V>::entries() {
    return _map->entries();
}

template<typename V>
template<typename K2, typename V2>
Map<K2, V2> _CaseInsensitiveStringMapCls<V>::map(std::function<MapEntry<K2, V2>(String key, V value)> transform) {
    return _map->map(transform);
}

template<typename V>
V _CaseInsensitiveStringMapCls<V>::update(String key, std::function<V(V value)> update, std::function<V()> ifAbsent) {
    return _map->update(key->toUpperCase(), update, ifAbsent);
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::updateAll(std::function<V(String key, V value)> update) {
    _map->updateAll(update);
}

template<typename V>
void _CaseInsensitiveStringMapCls<V>::removeWhere(std::function<bool(String key, V value)> test) {
    _map->removeWhere(test);
}

template<typename V>
String _CaseInsensitiveStringMapCls<V>::toString() {
    return _map->toString();
}
