#ifndef LERP_H
#define LERP_H
#include <memory>



double lerpDouble(num a, num b, double t);

double _lerpDouble(double a, double b, double t);

double _lerpInt(int a, int b, double t);

int _clampInt(int max, int min, int value);


#endif