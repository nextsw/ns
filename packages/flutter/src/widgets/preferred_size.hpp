#ifndef PREFERRED_SIZE_H
#define PREFERRED_SIZE_H
#include <memory>

#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"



class PreferredSizeWidget {
public:

    Size preferredSize();

private:

};

class PreferredSize : StatelessWidget {
public:
    Widget child;

    Size preferredSize;


     PreferredSize(Widget child, Unknown, Size preferredSize);

    Widget build(BuildContext context);

private:

};

#endif