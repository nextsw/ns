#ifndef DART_IO_EVENTHANDLER
#define DART_IO_EVENTHANDLER
#include <base.hpp>

#include <dart/core/core.hpp>


class _EventHandlerCls : public ObjectCls {
public:

private:

    static void _sendData(Object sender, SendPort sendPort, int data);
};
using _EventHandler = std::shared_ptr<_EventHandlerCls>;


#endif