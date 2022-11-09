#include "isolate_name_server.hpp"
SendPort IsolateNameServerCls::lookupPortByName(String name) {
    assert(name != nullptr, "'name' cannot be null.");
    return _lookupPortByName(name);
}

bool IsolateNameServerCls::registerPortWithName(String name, SendPort port) {
    assert(port != nullptr, "'port' cannot be null.");
    assert(name != nullptr, "'name' cannot be null.");
    return _registerPortWithName(port, name);
}

bool IsolateNameServerCls::removePortNameMapping(String name) {
    assert(name != nullptr, "'name' cannot be null.");
    return _removePortNameMapping(name);
}

void IsolateNameServerCls::_() {
    return ;
}
