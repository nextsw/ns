#ifndef ERRORS_H
#define ERRORS_H
#include <memory>




class LateError : Error {
public:

     LateError(String _message);

    void  fieldADI(String fieldName);

    void  localADI(String localName);

    void  fieldNI(String fieldName);

    void  localNI(String localName);

    void  fieldAI(String fieldName);

    void  localAI(String localName);

    String toString();

private:
    String _message;


};

class ReachabilityError : Error {
public:

     ReachabilityError(String _message);

    String toString();

private:
    String _message;


};

#endif