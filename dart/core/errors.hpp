#ifndef DART_CORE_ERRORS
#define DART_CORE_ERRORS
#include <base.hpp>

#include <dart/core/core.hpp>


class ErrorCls : public ObjectCls {
public:

     ErrorCls();
    static String safeToString(Object object);

    StackTrace stackTrace();
    static Never throwWithStackTrace(Object error, StackTrace stackTrace);

private:

    static String _stringToSafeString(String stringValue);
    static String _objectToString(Object object);
    static Never _throw(Object error, StackTrace stackTrace);
};
using Error = std::shared_ptr<ErrorCls>;

class AssertionErrorCls : public ErrorCls {
public:
    Object message;


     AssertionErrorCls(Object message);
    virtual String toString();

private:

};
using AssertionError = std::shared_ptr<AssertionErrorCls>;

class TypeErrorCls : public ErrorCls {
public:

private:

};
using TypeError = std::shared_ptr<TypeErrorCls>;

class CastErrorCls : public ErrorCls {
public:

private:

};
using CastError = std::shared_ptr<CastErrorCls>;

class NullThrownErrorCls : public ErrorCls {
public:

     NullThrownErrorCls();
    virtual String toString();

private:

};
using NullThrownError = std::shared_ptr<NullThrownErrorCls>;


#endif