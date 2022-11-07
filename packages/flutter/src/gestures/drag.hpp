#ifndef DRAG_H
#define DRAG_H
#include <memory>
#include "drag_details.hpp"

#include "drag_details.hpp"



class Drag {
public:

    void update(DragUpdateDetails details);

    void end(DragEndDetails details);

    void cancel();

private:

};

#endif