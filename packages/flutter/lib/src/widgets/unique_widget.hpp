#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_UNIQUE_WIDGET
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_UNIQUE_WIDGET
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"


template<typename T : State<StatefulWidget>> class UniqueWidgetCls : public StatefulWidgetCls {
public:

     UniqueWidgetCls(GlobalKey<T> key);

    virtual T createState() override;
    virtual T currentState();

private:

};
template<typename T : State<StatefulWidget>> using UniqueWidget = std::shared_ptr<UniqueWidgetCls<T : State<StatefulWidget>>>;


#endif