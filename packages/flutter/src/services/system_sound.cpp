#include "system_sound.hpp"
Future<void> SystemSoundCls::play(SystemSoundType type) {
    await await SystemChannelsCls::platform-><void>invokeMethod("SystemSound.play", type->toString());
}
