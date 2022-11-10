#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISPOSABLE_BUILD_CONTEXT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISPOSABLE_BUILD_CONTEXT
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"


template<typename T> class DisposableBuildContextCls : public ObjectCls {
public:

     DisposableBuildContextCls(T _state);

    virtual BuildContext context();

    virtual void dispose();

private:
    T _state;


    virtual bool _debugValidate();

};
template<typename T> using DisposableBuildContext = std::shared_ptr<DisposableBuildContextCls<T>>;


#endif