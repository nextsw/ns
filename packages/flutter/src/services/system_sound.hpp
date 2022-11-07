#ifndef SYSTEM_SOUND_H
#define SYSTEM_SOUND_H
#include <memory>

#include "system_channels.hpp"



enum SystemSoundType{
    click,
    alert,
} // end SystemSoundType

class SystemSound {
public:

    static Future<void> play(SystemSoundType type);

private:

    void  _();

};

#endif