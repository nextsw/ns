#include "service_object.hpp"
int _ServiceObjectCls::_serviceId() {
    if (__serviceId == 0) {
        __serviceId = _nextServiceId++;
    }
    return __serviceId;
}

String _ServiceObjectCls::_servicePath() {
    return __sf("%s/%s", _serviceTypePath(), _serviceId());
}

String _ServiceObjectCls::_serviceType(bool ref) {
    if (ref) {
        return __sf("@%s", _serviceTypeName());
    }
    return _serviceTypeName();
}
