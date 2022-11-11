#ifndef DART_IO_PLATFORM_IMPL
#define DART_IO_PLATFORM_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>


class _PlatformCls : public ObjectCls {
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
    static std::function<String()> _localeClosure;

    static auto _environmentCache;

    static String _cachedOSVersion;


    static int _numberOfProcessors();
    static String _pathSeparator();
    static String _operatingSystem();
    static void  _operatingSystemVersion();
    static void  _localHostname();
    static void  _executable();
    static void  _resolvedExecutable();
    static void  _environment();
    static List<String> _executableArguments();
    static String _packageConfig();
    static String _version();
    static String _localeName();
    static Uri _script();
};
using _Platform = std::shared_ptr<_PlatformCls>;

template<typename V>
class _CaseInsensitiveStringMapCls : public MapBaseCls<String, V> {
public:

    virtual bool containsKey(Object key);

    virtual bool containsValue(Object value);

    virtual V operator[](Object key);

    virtual void operator[]=(String key, V value);

    virtual V putIfAbsent(std::function<V()> ifAbsent, String key);

    virtual void addAll(Map<String, V> other);

    virtual V remove(Object key);

    virtual void clear();

    virtual void forEach(std::function<void(String key, V value)> f);

    virtual Iterable<String> keys();

    virtual Iterable<V> values();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<MapEntry<String, V>> entries();

    template<typename K2, typename V2>
 virtual Map<K2, V2> map(std::function<MapEntry<K2, V2>(String key, V value)> transform);

    virtual V update(std::function<V()> ifAbsent, String key, std::function<V(V value)> update);

    virtual void updateAll(std::function<V(String key, V value)> update);

    virtual void removeWhere(std::function<bool(String key, V value)> test);

    virtual String toString();

private:
    Map<String, V> _map;


};
template<typename V>
using _CaseInsensitiveStringMap = std::shared_ptr<_CaseInsensitiveStringMapCls<V>>;


#endif