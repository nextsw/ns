#ifndef PACKAGES_FLUTTER_SRC_PAINTING_SHADER_WARM_UP
#define PACKAGES_FLUTTER_SRC_PAINTING_SHADER_WARM_UP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "debug.hpp"


class ShaderWarmUpCls : public ObjectCls {
public:

     ShaderWarmUpCls();
    virtual Size size();

    virtual Future<void> warmUpOnCanvas(Canvas canvas);
    virtual Future<void> execute();

private:

};
using ShaderWarmUp = std::shared_ptr<ShaderWarmUpCls>;


#endif