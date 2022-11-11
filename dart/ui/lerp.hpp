#ifndef DART_UI_LERP
#define DART_UI_LERP
#include <base.hpp>

#include <dart/core/core.hpp>

double lerpDouble(num a, num b, double t);

double _lerpDouble(double a, double b, double t);

double _lerpInt(int a, int b, double t);

int _clampInt(int value, int min, int max);



#endif