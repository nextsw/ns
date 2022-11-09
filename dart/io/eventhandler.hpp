#ifndef DART_IO_EVENTHANDLER
#define DART_IO_EVENTHANDLER
#include <base.hpp>

#include <dart/core/core.hpp>


class _EventHandlerCls : public ObjectCls {
public:

private:

    extern static void _sendData(int data, SendPort sendPort, Object sender);
};
using _EventHandler = std::shared_ptr<_EventHandlerCls>;


#endif