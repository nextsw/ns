#ifndef SYSTEM_NAVIGATOR_H
#define SYSTEM_NAVIGATOR_H
#include <memory>

#include "system_channels.hpp"



class SystemNavigator {
public:

    static Future<void> pop(bool animated);

    static Future<void> selectSingleEntryHistory();

    static Future<void> selectMultiEntryHistory();

    static Future<void> routeInformationUpdated(String location, bool replace, Object state);

    static Future<void> routeUpdated(String previousRouteName, String routeName);

private:

    void  _();

};

#endif