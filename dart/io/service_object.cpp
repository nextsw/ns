#include "service_object.hpp"
int _ServiceObjectCls::_serviceId() {
    if (__serviceId == 0) {
        __serviceId = _nextServiceId++;
    }
    return __serviceId;
}

String _ServiceObjectCls::_servicePath() {
    return __s("%s$%s;");
}

String _ServiceObjectCls::_serviceType(bool ref) {
    if (ref) {
        return __s("@%s;");
    }
    return _serviceTypeName();
}
