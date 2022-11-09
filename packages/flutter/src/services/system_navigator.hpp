#ifndef PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_NAVIGATOR
#define PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_NAVIGATOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include "system_channels.hpp"


class SystemNavigatorCls : public ObjectCls {
public:

    static Future<void> pop(bool animated);

    static Future<void> selectSingleEntryHistory();

    static Future<void> selectMultiEntryHistory();

    static Future<void> routeInformationUpdated(String location, bool replace, Object state);

    static Future<void> routeUpdated(String previousRouteName, String routeName);

private:

    virtual void  _();
};
using SystemNavigator = std::shared_ptr<SystemNavigatorCls>;


#endif