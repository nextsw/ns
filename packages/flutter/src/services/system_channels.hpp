#ifndef SYSTEM_CHANNELS_H
#define SYSTEM_CHANNELS_H
#include <memory>
#include "platform_channel.hpp"

#include <ui/ui.hpp>
#include "message_codecs.hpp"
#include "platform_channel.hpp"



class SystemChannels {
public:
    static const MethodChannel navigation;

    static const MethodChannel platform;

    static const MethodChannel textInput;

    static const BasicMessageChannel<Object> keyEvent;

    static const BasicMessageChannel<String> lifecycle;

    static const BasicMessageChannel<Object> system;

    static const BasicMessageChannel<Object> accessibility;

    static const MethodChannel platform_views;

    static const MethodChannel skia;

    static const MethodChannel mouseCursor;

    static const MethodChannel restoration;

    static const MethodChannel deferredComponent;

    static const MethodChannel localization;

    static const MethodChannel menu;


private:

    void  _();

};

#endif