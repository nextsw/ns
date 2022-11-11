#include "utilities.hpp"
double degrees(double radians) {
    return radians * radians2Degrees;
}

double radians(double degrees) {
    return degrees * degrees2Radians;
}

double mix(double min, double max, double a) {
    return min + a * (max - min);
}

double smoothStep(double edge0, double edge1, double amount) {
    Unknown t = ((amount - edge0) / (edge1 - edge0))->clamp(0.0, 1.0)->toDouble();
    return t * t * (3.0 - 2.0 * t);
}

double catmullRom(double edge0, double edge1, double edge2, double edge3, double amount) {
    return 0.5 * ((2.0 * edge1) + (-edge0 + edge2) * amount + (2.0 * edge0 - 5.0 * edge1 + 4.0 * edge2 - edge3) * (amount * amount) + (-edge0 + 3.0 * edge1 - 3.0 * edge2 + edge3) * (amount * amount * amount));
}
