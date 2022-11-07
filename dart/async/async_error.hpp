#ifndef ASYNC_ERROR_H
#define ASYNC_ERROR_H
#include <memory>




class AsyncError {
public:
    Object error;

    StackTrace stackTrace;


     AsyncError(Object error, StackTrace stackTrace);

    static StackTrace defaultStackTrace(Object error);

    String toString();

private:

};

#endif