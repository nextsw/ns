#include "isolate_name_server.hpp"
SendPort IsolateNameServer::lookupPortByName(String name) {
    assert(name != nullptr, "'name' cannot be null.");
    return _lookupPortByName(name);
}

bool IsolateNameServer::registerPortWithName(String name, SendPort port) {
    assert(port != nullptr, "'port' cannot be null.");
    assert(name != nullptr, "'name' cannot be null.");
    return _registerPortWithName(port, name);
}

bool IsolateNameServer::removePortNameMapping(String name) {
    assert(name != nullptr, "'name' cannot be null.");
    return _removePortNameMapping(name);
}

void IsolateNameServer::_() {
    return ;
}
