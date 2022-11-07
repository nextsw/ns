#include "print.hpp"
void print(Object object) {
    String line = "$object";
    auto toZone = printToZone;
    if (toZone == nullptr) {
        printToConsole(line);
    } else {
        toZone(line);
    }
}
