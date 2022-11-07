#ifndef ERRORS_H
#define ERRORS_H
#include <memory>




class Error {
public:

     Error();

    static String safeToString(Object object);

    external StackTrace stackTrace();

    static Never throwWithStackTrace(Object error, StackTrace stackTrace);

private:

    external static String _stringToSafeString(String string);

    external static String _objectToString(Object object);

    external static Never _throw(Object error, StackTrace stackTrace);

};

class AssertionError : Error {
public:
    Object message;


     AssertionError(Object message);

    String toString();

private:

};

class TypeError : Error {
public:

private:

};

class CastError : Error {
public:

private:

};

class NullThrownError : Error {
public:

     NullThrownError();

    String toString();

private:

};

#endif