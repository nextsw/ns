#include "tolerance.hpp"
String ToleranceCls::toString() {
    return __sf("%s(distance: ±%s, time: ±%s, velocity: ±%s)", objectRuntimeType(this, __s("Tolerance")), distance, time, velocity);
}
