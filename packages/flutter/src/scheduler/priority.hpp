#ifndef PRIORITY_H
#define PRIORITY_H
#include <memory>

#include <flutter/foundation.hpp>



class Priority {
public:
    static const Priority idle;

    static const Priority animation;

    static const Priority touch;

    static const int kMaxOffset;


    int value();

    Priority +(int offset);

    Priority -(int offset);

private:
    int _value;


    void  _(int _value);

};

#endif