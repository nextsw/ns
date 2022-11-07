#include "system_sound.hpp"
Future<void> SystemSound::play(SystemSoundType type) {
    await await SystemChannels.platform.<void>invokeMethod("SystemSound.play", type.toString());
}
