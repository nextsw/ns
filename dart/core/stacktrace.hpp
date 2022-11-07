#ifndef STACKTRACE_H
#define STACKTRACE_H
#include <memory>




class StackTrace {
public:
    static const auto  empty;


     StackTrace();

    void  fromString(String stackTraceString);

    external static StackTrace current();

    String toString();

private:

};

class _StringStackTrace {
public:

    String toString();

private:
    String _stackTrace;


     _StringStackTrace(String _stackTrace);

};

#endif