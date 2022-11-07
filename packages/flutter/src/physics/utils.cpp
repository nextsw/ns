#include "utils.hpp"
bool nearEqual(double a, double b, double epsilon) {
    assert(epsilon != nullptr);
    assert(epsilon >= 0.0);
    if (a == nullptr || b == nullptr) {
        return a == b;
    }
    return (a > (b - epsilon)) && ( < (b + epsilon)) || a == b;
}

bool nearZero(double a, double epsilon) {
    return nearEqual(a, 0.0, epsilon);
}
