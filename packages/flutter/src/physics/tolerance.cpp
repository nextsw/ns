#include "tolerance.hpp"
String ToleranceCls::toString() {
    return __s("${objectRuntimeType(this, 'Tolerance')}(distance: ±$distance, time: ±$time, velocity: ±$velocity)");
}
