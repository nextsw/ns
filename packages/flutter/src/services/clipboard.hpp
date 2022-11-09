#ifndef PACKAGES_FLUTTER_SRC_SERVICES_CLIPBOARD
#define PACKAGES_FLUTTER_SRC_SERVICES_CLIPBOARD
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "system_channels.hpp"


class ClipboardDataCls : public ObjectCls {
public:
    String text;


     ClipboardDataCls(String text);
private:

};
using ClipboardData = std::shared_ptr<ClipboardDataCls>;

class ClipboardCls : public ObjectCls {
public:
    static String kTextPlain;


    static Future<void> setData(ClipboardData data);

    static Future<ClipboardData> getData(String format);

    static Future<bool> hasStrings();

private:

    virtual void  _();
};
using Clipboard = std::shared_ptr<ClipboardCls>;


#endif