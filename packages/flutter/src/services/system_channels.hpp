#ifndef PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_CHANNELS
#define PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_CHANNELS
#include <base.hpp>
#include "platform_channel.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "message_codecs.hpp"
#include "platform_channel.hpp"


class SystemChannelsCls : public ObjectCls {
public:
    static MethodChannel navigation;

    static MethodChannel platform;

    static MethodChannel textInput;

    static BasicMessageChannel<Object> keyEvent;

    static BasicMessageChannel<String> lifecycle;

    static BasicMessageChannel<Object> system;

    static BasicMessageChannel<Object> accessibility;

    static MethodChannel platform_views;

    static MethodChannel skia;

    static MethodChannel mouseCursor;

    static MethodChannel restoration;

    static MethodChannel deferredComponent;

    static MethodChannel localization;

    static MethodChannel menu;


private:

    virtual void  _();
};
using SystemChannels = std::shared_ptr<SystemChannelsCls>;


#endif