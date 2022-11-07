#ifndef UTILITIES_H
#define UTILITIES_H
#include <memory>



double degrees(double radians);

double radians(double degrees);

double mix(double a, double max, double min);

double smoothStep(double amount, double edge0, double edge1);

double catmullRom(double amount, double edge0, double edge1, double edge2, double edge3);


#endif