#ifndef DART_IO_SERVICE_OBJECT
#define DART_IO_SERVICE_OBJECT
#include <base.hpp>

#include <dart/core/core.hpp>

int _nextServiceId;


class _ServiceObjectCls : public ObjectCls {
public:

private:
    int __serviceId;


    virtual int _serviceId();

    virtual Map _toJSON(bool ref);
    virtual String _servicePath();

    virtual String _serviceTypePath();
    virtual String _serviceTypeName();
    virtual String _serviceType(bool ref);

};
using _ServiceObject = std::shared_ptr<_ServiceObjectCls>;


#endif