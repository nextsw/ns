#include "annotated_region.hpp"
AnnotatedRegion::AnnotatedRegion(Widget child, Unknown, bool sized, T value) {
    {
        assert(value != nullptr);
        assert(child != nullptr);
    }
}

RenderObject AnnotatedRegion::createRenderObject(BuildContext context) {
    return <T>RenderAnnotatedRegion(value, sized);
}

void AnnotatedRegion::updateRenderObject(BuildContext context, RenderAnnotatedRegion<T> renderObject) {
    ;
}
