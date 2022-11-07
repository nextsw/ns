#ifndef META_H
#define META_H
#include <memory>

#include "meta_meta.hpp"


const _AlwaysThrows alwaysThrows;

const _Checked checked;

const _DoNotStore doNotStore;

const _Experimental experimental;

const _Factory factory;

const Immutable immutable;

const _Internal internal;

const _IsTest isTest;

const _IsTestGroup isTestGroup;

const _Literal literal;

const _MustCallSuper mustCallSuper;

const _NonVirtual nonVirtual;

const _OptionalTypeArgs optionalTypeArgs;

const _Protected protected;

const Required required;

const _Sealed sealed;

const UseResult useResult;

const _Virtual virtual;

const _VisibleForOverriding visibleForOverriding;

const _VisibleForTesting visibleForTesting;


class Immutable {
public:
    String reason;


     Immutable(String reason);

private:

};

class Required {
public:
    String reason;


     Required(String reason);

private:

};

class UseResult {
public:
    String reason;

    String parameterDefined;


     UseResult(String reason);

    void  unless(String parameterDefined, String reason);

private:

};

class _AlwaysThrows {
public:

private:

     _AlwaysThrows();

};

class _Checked {
public:

private:

     _Checked();

};

class _DoNotStore {
public:

private:

     _DoNotStore();

};

class _Experimental {
public:

private:

     _Experimental();

};

class _Factory {
public:

private:

     _Factory();

};

class _Internal {
public:

private:

     _Internal();

};

class _IsTest {
public:

private:

     _IsTest();

};

class _IsTestGroup {
public:

private:

     _IsTestGroup();

};

class _Literal {
public:

private:

     _Literal();

};

class _MustCallSuper {
public:

private:

     _MustCallSuper();

};

class _NonVirtual {
public:

private:

     _NonVirtual();

};

class _OptionalTypeArgs {
public:

private:

     _OptionalTypeArgs();

};

class _Protected {
public:

private:

     _Protected();

};

class _Sealed {
public:

private:

     _Sealed();

};

class _Virtual {
public:

private:

     _Virtual();

};

class _VisibleForOverriding {
public:

private:

     _VisibleForOverriding();

};

class _VisibleForTesting {
public:

private:

     _VisibleForTesting();

};

#endif