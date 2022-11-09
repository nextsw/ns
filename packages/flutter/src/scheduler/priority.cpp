#include "priority.hpp"
int PriorityCls::value() {
    return _value;
}

Priority PriorityCls::+(int offset) {
    if (offset->abs() > kMaxOffset) {
        offset = kMaxOffset * offset->sign;
    }
    return PriorityCls->_(_value + offset);
}

Priority PriorityCls::-(int offset) {
    return this + (-offset);
}
