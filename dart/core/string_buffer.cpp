#include "string_buffer.hpp"
bool StringBuffer::isEmpty() {
    return length == 0;
}

bool StringBuffer::isNotEmpty() {
    return !isEmpty;
}
