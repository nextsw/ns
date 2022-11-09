#ifndef PACKAGES_META_META
#define PACKAGES_META_META
#include <base.hpp>

#include <dart/core/core.hpp>
#include "meta_meta.hpp"

_AlwaysThrows alwaysThrows;

_Checked checked;

_DoNotStore doNotStore;

_Experimental experimental;

_Factory factory;

Immutable immutable;

_Internal internal;

_IsTest isTest;

_IsTestGroup isTestGroup;

_Literal literal;

_MustCallSuper mustCallSuper;

_NonVirtual nonVirtual;

_OptionalTypeArgs optionalTypeArgs;

_Protected protected;

Required required;

_Sealed sealed;

UseResult useResult;

_Virtual virtual;

_VisibleForOverriding visibleForOverriding;

_VisibleForTesting visibleForTesting;


class ImmutableCls : public ObjectCls {
public:
    String reason;


     ImmutableCls(String reason);
private:

};
using Immutable = std::shared_ptr<ImmutableCls>;

class RequiredCls : public ObjectCls {
public:
    String reason;


     RequiredCls(String reason);
private:

};
using Required = std::shared_ptr<RequiredCls>;

class UseResultCls : public ObjectCls {
public:
    String reason;

    String parameterDefined;


     UseResultCls(String reason);

    virtual void  unless(String parameterDefined, String reason);
private:

};
using UseResult = std::shared_ptr<UseResultCls>;

class _AlwaysThrowsCls : public ObjectCls {
public:

private:

     _AlwaysThrowsCls();
};
using _AlwaysThrows = std::shared_ptr<_AlwaysThrowsCls>;

class _CheckedCls : public ObjectCls {
public:

private:

     _CheckedCls();
};
using _Checked = std::shared_ptr<_CheckedCls>;

class _DoNotStoreCls : public ObjectCls {
public:

private:

     _DoNotStoreCls();
};
using _DoNotStore = std::shared_ptr<_DoNotStoreCls>;

class _ExperimentalCls : public ObjectCls {
public:

private:

     _ExperimentalCls();
};
using _Experimental = std::shared_ptr<_ExperimentalCls>;

class _FactoryCls : public ObjectCls {
public:

private:

     _FactoryCls();
};
using _Factory = std::shared_ptr<_FactoryCls>;

class _InternalCls : public ObjectCls {
public:

private:

     _InternalCls();
};
using _Internal = std::shared_ptr<_InternalCls>;

class _IsTestCls : public ObjectCls {
public:

private:

     _IsTestCls();
};
using _IsTest = std::shared_ptr<_IsTestCls>;

class _IsTestGroupCls : public ObjectCls {
public:

private:

     _IsTestGroupCls();
};
using _IsTestGroup = std::shared_ptr<_IsTestGroupCls>;

class _LiteralCls : public ObjectCls {
public:

private:

     _LiteralCls();
};
using _Literal = std::shared_ptr<_LiteralCls>;

class _MustCallSuperCls : public ObjectCls {
public:

private:

     _MustCallSuperCls();
};
using _MustCallSuper = std::shared_ptr<_MustCallSuperCls>;

class _NonVirtualCls : public ObjectCls {
public:

private:

     _NonVirtualCls();
};
using _NonVirtual = std::shared_ptr<_NonVirtualCls>;

class _OptionalTypeArgsCls : public ObjectCls {
public:

private:

     _OptionalTypeArgsCls();
};
using _OptionalTypeArgs = std::shared_ptr<_OptionalTypeArgsCls>;

class _ProtectedCls : public ObjectCls {
public:

private:

     _ProtectedCls();
};
using _Protected = std::shared_ptr<_ProtectedCls>;

class _SealedCls : public ObjectCls {
public:

private:

     _SealedCls();
};
using _Sealed = std::shared_ptr<_SealedCls>;

class _VirtualCls : public ObjectCls {
public:

private:

     _VirtualCls();
};
using _Virtual = std::shared_ptr<_VirtualCls>;

class _VisibleForOverridingCls : public ObjectCls {
public:

private:

     _VisibleForOverridingCls();
};
using _VisibleForOverriding = std::shared_ptr<_VisibleForOverridingCls>;

class _VisibleForTestingCls : public ObjectCls {
public:

private:

     _VisibleForTestingCls();
};
using _VisibleForTesting = std::shared_ptr<_VisibleForTestingCls>;


#endif