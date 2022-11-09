#include "tolerance.hpp"
String ToleranceCls::toString() {
    return "${objectRuntimeType(this, 'Tolerance')}(distance: ±$distance, time: ±$time, velocity: ±$velocity)";
}
