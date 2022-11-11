#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SPACER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SPACER
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"


class SpacerCls : public StatelessWidgetCls {
public:
    int flex;


     SpacerCls(int flex, Key key);

    virtual Widget build(BuildContext context);

private:

};
using Spacer = std::shared_ptr<SpacerCls>;


#endif