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
    Object message;


    virtual String toString();

private:

     _ExceptionCls(Object message);
};
using _Exception = std::shared_ptr<_ExceptionCls>;

class FormatExceptionCls : public ObjectCls {
public:
    String message;

    Object source;

    int offset;


     FormatExceptionCls(String message, Object source, int offset);
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