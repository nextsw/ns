#ifndef DART_CORE_ANNOTATIONS
#define DART_CORE_ANNOTATIONS
#include <base.hpp>

#include <dart/core/core.hpp>


class DeprecatedCls : public ObjectCls {
public:
    String message;


     DeprecatedCls(String message);
    virtual String expires();

    virtual String toString();

private:

};
using Deprecated = std::shared_ptr<DeprecatedCls>;
Deprecated deprecated;


class _OverrideCls : public ObjectCls {
public:

private:

     _OverrideCls();
};
using _Override = std::shared_ptr<_OverrideCls>;
Object override;


class ProvisionalCls : public ObjectCls {
public:

    virtual String message();

     ProvisionalCls(String message);
private:

};
using Provisional = std::shared_ptr<ProvisionalCls>;
Null provisional;

Null proxy;


class pragmaCls : public ObjectCls {
public:
    String name;

    Object options;


     pragmaCls(String name, Object options);
private:

    virtual void  _(String name, Object options);
};
using pragma = std::shared_ptr<pragmaCls>;


#endif