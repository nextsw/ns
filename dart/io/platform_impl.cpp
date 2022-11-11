#include "platform_impl.hpp"
String _PlatformCls::localeName() {
    Unknown result = (_localeClosure == nullptr)? _localeName() : _localeClosure!();
    if (is<OSError>(result)) {
        ;
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
            ;
        }
        _cachedOSVersion = result;
    }
    return _cachedOSVersion!;
}

String _PlatformCls::localHostname() {
    auto result = _localHostname();
    if (is<OSError>(result)) {
        ;
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
        ;
    } else {
        return _environmentCache!;
    }
}

String _PlatformCls::version() {
    return _version();
}

template<typename V> bool _CaseInsensitiveStringMapCls<V>::containsKey(Object key) {
    return is<String>(key) && _map->containsKey(key->toUpperCase());
}

template<typename V> bool _CaseInsensitiveStringMapCls<V>::containsValue(Object value) {
    return _map->containsValue(value);
}

template<typename V> V _CaseInsensitiveStringMapCls<V>::[](Object key) {
    return is<String>(key)? _map[key->toUpperCase()] : nullptr;
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::[]=(String key, V value) {
    _map[key->toUpperCase()] = value;
}

template<typename V> V _CaseInsensitiveStringMapCls<V>::putIfAbsent(V ifAbsent() , String key) {
    return _map->putIfAbsent(key->toUpperCase(), ifAbsent);
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::addAll(Map<String, V> other) {
    other->forEach([=] (Unknown  key,Unknown  value)     {
        this[key->toUpperCase()] = value;
    });
}

template<typename V> V _CaseInsensitiveStringMapCls<V>::remove(Object key) {
    return is<String>(key)? _map->remove(key->toUpperCase()) : nullptr;
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::clear() {
    _map->clear();
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::forEach(void f(String key, V value) ) {
    _map->forEach(f);
}

template<typename V> Iterable<String> _CaseInsensitiveStringMapCls<V>::keys() {
    return _map->keys;
}

template<typename V> Iterable<V> _CaseInsensitiveStringMapCls<V>::values() {
    return _map->values;
}

template<typename V> int _CaseInsensitiveStringMapCls<V>::length() {
    return _map->length;
}

template<typename V> bool _CaseInsensitiveStringMapCls<V>::isEmpty() {
    return _map->isEmpty();
}

template<typename V> bool _CaseInsensitiveStringMapCls<V>::isNotEmpty() {
    return _map->isNotEmpty();
}

template<typename V> Iterable<MapEntry<String, V>> _CaseInsensitiveStringMapCls<V>::entries() {
    return _map->entries;
}

template<typename V> Map<K2, V2> _CaseInsensitiveStringMapCls<V>::maptemplate<typename K2, typename V2> (MapEntry<K2, V2> transform(String key, V value) ) {
    return _map->map(transform);
}

template<typename V> V _CaseInsensitiveStringMapCls<V>::update(V ifAbsent() , String key, V update(V value) ) {
    return _map->update(key->toUpperCase(), updateifAbsent);
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::updateAll(V update(String key, V value) ) {
    _map->updateAll(update);
}

template<typename V> void _CaseInsensitiveStringMapCls<V>::removeWhere(bool test(String key, V value) ) {
    _map->removeWhere(test);
}

template<typename V> String _CaseInsensitiveStringMapCls<V>::toString() {
    return _map->toString();
}
