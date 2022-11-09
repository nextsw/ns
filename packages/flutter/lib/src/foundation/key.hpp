#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_KEY
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_KEY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/meta/meta.hpp>
#include "diagnostics.hpp"


class KeyCls : public ObjectCls {
public:

     KeyCls(String value);
    virtual void  empty();
private:

};
using Key = std::shared_ptr<KeyCls>;

class LocalKeyCls : public KeyCls {
public:

     LocalKeyCls();

private:

};
using LocalKey = std::shared_ptr<LocalKeyCls>;

class UniqueKeyCls : public LocalKeyCls {
public:

     UniqueKeyCls();
    virtual String toString();

private:

};
using UniqueKey = std::shared_ptr<UniqueKeyCls>;

template<typename T> class ValueKeyCls : public LocalKeyCls {
public:
    T value;


     ValueKeyCls(T value);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
template<typename T> using ValueKey = std::shared_ptr<ValueKeyCls<T>>;

template<typename T> class _TypeLiteralCls : public ObjectCls {
public:

    virtual Type type();

private:

};
template<typename T> using _TypeLiteral = std::shared_ptr<_TypeLiteralCls<T>>;


#endif