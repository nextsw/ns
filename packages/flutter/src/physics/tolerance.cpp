#include "tolerance.hpp"
String Tolerance::toString() {
    return "${objectRuntimeType(this, 'Tolerance')}(distance: ±$distance, time: ±$time, velocity: ±$velocity)";
}
