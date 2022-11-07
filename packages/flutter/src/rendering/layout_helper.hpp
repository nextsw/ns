#ifndef LAYOUT_HELPER_H
#define LAYOUT_HELPER_H
#include <memory>

#include <ui/ui.hpp>
#include "box.hpp"



class ChildLayoutHelper {
public:

    static Size dryLayoutChild(RenderBox child, BoxConstraints constraints);

    static Size layoutChild(RenderBox child, BoxConstraints constraints);

private:

    void  _();

};

#endif