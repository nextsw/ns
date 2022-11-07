#ifndef EMBEDDER_CONFIG_H
#define EMBEDDER_CONFIG_H
#include <memory>




class _EmbedderConfig {
public:

private:
    static bool _mayChdir;

    static bool _mayExit;

    static bool _maySetEchoMode;

    static bool _maySetEchoNewlineMode;

    static bool _maySetLineMode;

    static bool _maySleep;


};

#endif