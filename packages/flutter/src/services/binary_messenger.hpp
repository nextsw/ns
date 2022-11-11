#ifndef PACKAGES_FLUTTER_SRC_SERVICES_BINARY_MESSENGER
#define PACKAGES_FLUTTER_SRC_SERVICES_BINARY_MESSENGER
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/typed_data/typed_data.hpp>
#include <dart/ui/ui.hpp>


class BinaryMessengerCls : public ObjectCls {
public:

     BinaryMessengerCls();
    virtual Future<void> handlePlatformMessage(String channel, ByteData data, PlatformMessageResponseCallback callback);
    virtual Future<ByteData> send(String channel, ByteData message);
    virtual void setMessageHandler(String channel, MessageHandler handler);
private:

};
using BinaryMessenger = std::shared_ptr<BinaryMessengerCls>;


#endif