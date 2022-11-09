#ifndef DART_INTERNAL_ERRORS
#define DART_INTERNAL_ERRORS
#include <base.hpp>

#include <dart/core/core.hpp>


class LateErrorCls : public ErrorCls {
public:

     LateErrorCls(String _message);
    virtual void  fieldADI(String fieldName);

    virtual void  localADI(String localName);

    virtual void  fieldNI(String fieldName);

    virtual void  localNI(String localName);

    virtual void  fieldAI(String fieldName);

    virtual void  localAI(String localName);

    virtual String toString();

private:
    String _message;


};
using LateError = std::shared_ptr<LateErrorCls>;

class ReachabilityErrorCls : public ErrorCls {
public:

     ReachabilityErrorCls(String _message);
    virtual String toString();

private:
    String _message;


};
using ReachabilityError = std::shared_ptr<ReachabilityErrorCls>;


#endif