#include "priority.hpp"
int Priority::value() {
    return _value;
}

Priority Priority::+(int offset) {
    if (offset.abs() > kMaxOffset) {
        offset = kMaxOffset * offset.sign;
    }
    return Priority._(_value + offset);
}

Priority Priority::-(int offset) {
    return this + (-offset);
}
