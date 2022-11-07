#ifndef SHADER_WARM_UP_H
#define SHADER_WARM_UP_H
#include <memory>

#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "debug.hpp"



class ShaderWarmUp {
public:

     ShaderWarmUp();

    Size size();

    Future<void> warmUpOnCanvas(Canvas canvas);

    Future<void> execute();

private:

};

#endif