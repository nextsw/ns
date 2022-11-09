#ifndef DART_UI_ISOLATE_NAME_SERVER
#define DART_UI_ISOLATE_NAME_SERVER
#include <base.hpp>

#include <dart/core/core.hpp>


class IsolateNameServerCls : public ObjectCls {
public:

    static SendPort lookupPortByName(String name);

    static bool registerPortWithName(String name, SendPort port);

    static bool removePortNameMapping(String name);

private:

    virtual void  _();

    static SendPort _lookupPortByName(String name);
    static bool _registerPortWithName(String name, SendPort port);
    static bool _removePortNameMapping(String name);
};
using IsolateNameServer = std::shared_ptr<IsolateNameServerCls>;


#endif