#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <memory>




class Exception {
public:

     Exception(auto message);

private:

};

class _Exception {
public:
    dynamic message;


    String toString();

private:

     _Exception(dynamic message);

};

class FormatException {
public:
    String message;

    dynamic source;

    int offset;


     FormatException(String message, int offset, dynamic source);

    String toString();

private:

};

class IntegerDivisionByZeroException {
public:

    String message();

    StackTrace stackTrace();

     IntegerDivisionByZeroException();

    String toString();

private:

};

#endif