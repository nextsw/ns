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
    static String Function() _localeClosure;

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

    virtual V putIfAbsent(V ifAbsent() , String key);

    virtual void addAll(Map<String, V> other);

    virtual V remove(Object key);

    virtual void clear();

    virtual void forEach(void f(String key, V value) );

    virtual Iterable<String> keys();

    virtual Iterable<V> values();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<MapEntry<String, V>> entries();

    template<typename K2, typename V2>
 virtual Map<K2, V2> map(MapEntry<K2, V2> transform(String key, V value) );

    virtual V update(V ifAbsent() , String key, V update(V value) );

    virtual void updateAll(V update(String key, V value) );

    virtual void removeWhere(bool test(String key, V value) );

    virtual String toString();

private:
    Map<String, V> _map;


};
template<typename V>
using _CaseInsensitiveStringMap = std::shared_ptr<_CaseInsensitiveStringMapCls<V>>;


#endif