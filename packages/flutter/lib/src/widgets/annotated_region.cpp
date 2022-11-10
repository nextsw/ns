#include "annotated_region.hpp"
template<typename T> AnnotatedRegionCls<T>::AnnotatedRegionCls(Widget child, Unknown key, bool sized, T value) {
    {
        assert(value != nullptr);
        assert(child != nullptr);
    }
}

template<typename T> RenderObject AnnotatedRegionCls<T>::createRenderObject(BuildContext context) {
    return <T>make<RenderAnnotatedRegionCls>(value, sized);
}

template<typename T> void AnnotatedRegionCls<T>::updateRenderObject(BuildContext context, RenderAnnotatedRegion<T> renderObject) {
    auto _c1 = renderObject;_c1.value = auto _c2 = value;_c2.sized = sized;_c2;_c1;
}
