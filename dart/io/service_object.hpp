#ifndef SERVICE_OBJECT_H
#define SERVICE_OBJECT_H
#include <memory>



int _nextServiceId;


class _ServiceObject {
public:

private:
    int __serviceId;


    int _serviceId();

    Map _toJSON(bool ref);

    String _servicePath();

    String _serviceTypePath();

    String _serviceTypeName();

    String _serviceType(bool ref);

};

#endif