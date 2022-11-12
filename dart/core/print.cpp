#include "print.hpp"
void print(Object object) {
    String line = __s("%s;");
    auto toZone = printToZone;
    if (toZone == nullptr) {
        printToConsole(line);
    } else {
        toZone(line);
    }
}
