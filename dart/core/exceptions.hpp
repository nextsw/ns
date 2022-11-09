#ifndef DART_CORE_EXCEPTIONS
#define DART_CORE_EXCEPTIONS
#include <base.hpp>

#include <dart/core/core.hpp>


class ExceptionCls : public ObjectCls {
public:

     ExceptionCls(auto message);

private:

};
using Exception = std::shared_ptr<ExceptionCls>;

class _ExceptionCls : public ObjectCls {
public:
    dynamic message;


    virtual String toString();

private:

     _ExceptionCls(dynamic message);
};
using _Exception = std::shared_ptr<_ExceptionCls>;

class FormatExceptionCls : public ObjectCls {
public:
    String message;

    dynamic source;

    int offset;


     FormatExceptionCls(String message, int offset, dynamic source);
    virtual String toString();

private:

};
using FormatException = std::shared_ptr<FormatExceptionCls>;

class IntegerDivisionByZeroExceptionCls : public ObjectCls {
public:

    virtual String message();

    virtual StackTrace stackTrace();

     IntegerDivisionByZeroExceptionCls();
    virtual String toString();

private:

};
using IntegerDivisionByZeroException = std::shared_ptr<IntegerDivisionByZeroExceptionCls>;


#endif