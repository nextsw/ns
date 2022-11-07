#ifndef PLATFORM_IMPL_H
#define PLATFORM_IMPL_H
#include <memory>




class _Platform {
public:
    static String executable;

    static String resolvedExecutable;

    static String packageConfig;


    static String localeName();

    static int numberOfProcessors();

    static String pathSeparator();

    static String operatingSystem();

    static Uri script();

    static String operatingSystemVersion();

    static String localHostname();

    static List<String> executableArguments();

    static Map<String, String> environment();

    static String version();

private:
    static FunctionType _localeClosure;

    static auto _environmentCache;

    static String _cachedOSVersion;


    external static int _numberOfProcessors();

    external static String _pathSeparator();

    external static String _operatingSystem();

    external static void  _operatingSystemVersion();

    external static void  _localHostname();

    external static void  _executable();

    external static void  _resolvedExecutable();

    external static void  _environment();

    external static List<String> _executableArguments();

    external static String _packageConfig();

    external static String _version();

    external static String _localeName();

    external static Uri _script();

};

class _CaseInsensitiveStringMap<V> : MapBase<String, V> {
public:

    bool containsKey(Object key);

    bool containsValue(Object value);

    V [](Object key);

    void []=(String key, V value);

    V putIfAbsent(FunctionType ifAbsent, String key);

    void addAll(Map<String, V> other);

    V remove(Object key);

    void clear();

    void forEach(FunctionType f);

    Iterable<String> keys();

    Iterable<V> values();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    Iterable<MapEntry<String, V>> entries();

    Map<K2, V2> map<K2, V2>(FunctionType transform);

    V update(FunctionType ifAbsent, String key, FunctionType update);

    void updateAll(FunctionType update);

    void removeWhere(FunctionType test);

    String toString();

private:
    Map<String, V> _map;


};

#endif