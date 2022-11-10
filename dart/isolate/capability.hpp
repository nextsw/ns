#ifndef DART_ISOLATE_CAPABILITY
#define DART_ISOLATE_CAPABILITY
#include <base.hpp>

#include <dart/core/core.hpp>


class CapabilityCls : public ObjectCls {
public:

     CapabilityCls();
private:

};
using Capability = std::shared_ptr<CapabilityCls>;


#endif