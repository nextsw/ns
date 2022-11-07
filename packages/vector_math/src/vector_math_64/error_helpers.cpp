#include "error_helpers.hpp"
double relativeError(dynamic calculated, dynamic correct) {
    if (calculated is num && correct is num) {
        Unknown diff = (calculated - correct).abs().toDouble();
        return diff / correct;
    }
    return calculated.relativeError(correct);
}

double absoluteError(dynamic calculated, dynamic correct) {
    if (calculated is num && correct is num) {
        Unknown diff = (calculated - correct).abs().toDouble();
        return diff;
    }
    return calculated.absoluteError(correct);
}
