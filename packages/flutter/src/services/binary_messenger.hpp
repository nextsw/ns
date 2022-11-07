#ifndef BINARY_MESSENGER_H
#define BINARY_MESSENGER_H
#include <memory>
#include <typed_data.hpp>
#include <ui.hpp>

#include <typed_data/typed_data.hpp>
#include <ui/ui.hpp>



class BinaryMessenger {
public:

     BinaryMessenger();

    Future<void> handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData data);

    Future<ByteData> send(String channel, ByteData message);

    void setMessageHandler(String channel, MessageHandler handler);

private:

};

#endif