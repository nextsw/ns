#ifndef DART_IO_EMBEDDER_CONFIG
#define DART_IO_EMBEDDER_CONFIG
#include <base.hpp>

#include <dart/core/core.hpp>


class _EmbedderConfigCls : public ObjectCls {
public:

private:
    static bool _mayChdir;

    static bool _mayExit;

    static bool _maySetEchoMode;

    static bool _maySetEchoNewlineMode;

    static bool _maySetLineMode;

    static bool _maySleep;


};
using _EmbedderConfig = std::shared_ptr<_EmbedderConfigCls>;


#endif