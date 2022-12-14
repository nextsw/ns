#include "isolate_name_server.hpp"
SendPort IsolateNameServerCls::lookupPortByName(String name) {
    assert(name != nullptr, __s("'name' cannot be null."));
    return _lookupPortByName(name);
}

bool IsolateNameServerCls::registerPortWithName(SendPort port, String name) {
    assert(port != nullptr, __s("'port' cannot be null."));
    assert(name != nullptr, __s("'name' cannot be null."));
    return _registerPortWithName(port, name);
}

bool IsolateNameServerCls::removePortNameMapping(String name) {
    assert(name != nullptr, __s("'name' cannot be null."));
    return _removePortNameMapping(name);
}

void IsolateNameServerCls::_() {
    return throw make<UnsupportedErrorCls>(__s("Namespace"));
}
