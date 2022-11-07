#include "service_object.hpp"
int _ServiceObject::_serviceId() {
    if (__serviceId == 0)     {
        __serviceId = _nextServiceId++;
    }
    return __serviceId;
}

String _ServiceObject::_servicePath() {
    return "$_serviceTypePath/$_serviceId";
}

String _ServiceObject::_serviceType(bool ref) {
    if (ref)     {
        return "@$_serviceTypeName";
    }
    return _serviceTypeName;
}
