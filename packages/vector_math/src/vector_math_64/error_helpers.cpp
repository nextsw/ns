#include "error_helpers.hpp"
double relativeError(Object calculated, Object correct) {
    if (is<num>(calculated) && is<num>(correct)) {
        auto diff = (calculated - correct)->abs()->toDouble();
        return diff / correct;
    }
    return calculated->relativeError(correct);
}

double absoluteError(Object calculated, Object correct) {
    if (is<num>(calculated) && is<num>(correct)) {
        auto diff = (calculated - correct)->abs()->toDouble();
        return diff;
    }
    return calculated->absoluteError(correct);
}
