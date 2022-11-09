#ifndef PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_SOUND
#define PACKAGES_FLUTTER_SRC_SERVICES_SYSTEM_SOUND
#include <base.hpp>

#include <dart/core/core.hpp>
#include "system_channels.hpp"


enum SystemSoundType{
    click,
    alert,
} // end SystemSoundType

class SystemSoundCls : public ObjectCls {
public:

    static Future<void> play(SystemSoundType type);

private:

    virtual void  _();
};
using SystemSound = std::shared_ptr<SystemSoundCls>;


#endif