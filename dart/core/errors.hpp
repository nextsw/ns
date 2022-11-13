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

class ArgumentErrorCls : public ErrorCls {
public:
    Object invalidValue;

    String name;

    Object message;


     ArgumentErrorCls(Object message, String name);

    virtual void  value(value , String name, Object message);

    virtual void  notNull(String name);

    template<typename T>
 static T checkNotNull(T argument, String name);

    virtual String toString();

private:
    bool _hasValue;


    virtual String _errorName();

    virtual String _errorExplanation();

};
using ArgumentError = std::shared_ptr<ArgumentErrorCls>;

class RangeErrorCls : public ArgumentErrorCls {
public:
    num start;

    num end;


     RangeErrorCls(auto message);

    virtual void  value(num value, String name, String message);

    virtual void  range(num invalidValue, int minValue, int maxValue, String name, String message);

    virtual void  index(int index, Object indexable, String name, String message, int length);
    static int checkValueInInterval(int value, int minValue, int maxValue, String name, String message);

    static int checkValidIndex(int index, Object indexable, String name, int length, String message);

    static int checkValidRange(int start, int end, int length, String startName, String endName, String message);

    static int checkNotNegative(int value, String name, String message);

private:

    virtual String _errorName();

    virtual String _errorExplanation();

};
using RangeError = std::shared_ptr<RangeErrorCls>;

class IndexErrorCls : public ArgumentErrorCls {
public:
    auto  indexable;

    int length;


     IndexErrorCls(int invalidValue, Object indexable, String name, String message, int length);

    virtual int start();

    virtual int end();

private:

    virtual String _errorName();

    virtual String _errorExplanation();

};
using IndexError = std::shared_ptr<IndexErrorCls>;

class FallThroughErrorCls : public ErrorCls {
public:

     FallThroughErrorCls();
    String toString();
private:

    void  _create(String url, int line);
};
using FallThroughError = std::shared_ptr<FallThroughErrorCls>;

class AbstractClassInstantiationErrorCls : public ErrorCls {
public:

     AbstractClassInstantiationErrorCls(String className);

    String toString();
private:
    String _className;


};
using AbstractClassInstantiationError = std::shared_ptr<AbstractClassInstantiationErrorCls>;

class NoSuchMethodErrorCls : public ErrorCls {
public:

    void  withInvocation(Object receiver, Invocation invocation);
     NoSuchMethodErrorCls(Object receiver, Symbol memberName, List<any> positionalArguments, Map<Symbol, Object> namedArguments);
    String toString();
private:

};
using NoSuchMethodError = std::shared_ptr<NoSuchMethodErrorCls>;

class UnsupportedErrorCls : public ErrorCls {
public:
    String message;


     UnsupportedErrorCls(String message);
    virtual String toString();

private:

};
using UnsupportedError = std::shared_ptr<UnsupportedErrorCls>;

class UnimplementedErrorCls : public ErrorCls {
public:
    String message;


     UnimplementedErrorCls(String message);
    virtual String toString();

private:

};
using UnimplementedError = std::shared_ptr<UnimplementedErrorCls>;

class StateErrorCls : public ErrorCls {
public:
    String message;


     StateErrorCls(String message);
    virtual String toString();

private:

};
using StateError = std::shared_ptr<StateErrorCls>;

class ConcurrentModificationErrorCls : public ErrorCls {
public:
    Object modifiedObject;


     ConcurrentModificationErrorCls(Object modifiedObject);
    virtual String toString();

private:

};
using ConcurrentModificationError = std::shared_ptr<ConcurrentModificationErrorCls>;

class OutOfMemoryErrorCls : public ObjectCls {
public:

     OutOfMemoryErrorCls();
    virtual String toString();

    virtual StackTrace stackTrace();

private:

};
using OutOfMemoryError = std::shared_ptr<OutOfMemoryErrorCls>;

class StackOverflowErrorCls : public ObjectCls {
public:

     StackOverflowErrorCls();
    virtual String toString();

    virtual StackTrace stackTrace();

private:

};
using StackOverflowError = std::shared_ptr<StackOverflowErrorCls>;

class CyclicInitializationErrorCls : public ErrorCls {
public:
    String variableName;


     CyclicInitializationErrorCls(String variableName);
    virtual String toString();

private:

};
using CyclicInitializationError = std::shared_ptr<CyclicInitializationErrorCls>;


#endif