#ifndef ANNOTATED_REGION_H
#define ANNOTATED_REGION_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"



class AnnotatedRegion<T extends Object> : SingleChildRenderObjectWidget {
public:
    T value;

    bool sized;


     AnnotatedRegion(Widget child, Unknown, bool sized, T value);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAnnotatedRegion<T> renderObject);

private:

};

#endif