#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_MODEL
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_MODEL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "framework.hpp"


template<typename T>
class InheritedModelCls : public InheritedWidgetCls {
public:

     InheritedModelCls(Widget child, Key key);
    virtual InheritedModelElement<T> createElement();

    virtual bool updateShouldNotifyDependent(InheritedModel<T> oldWidget, Set<T> dependencies);
    virtual bool isSupportedAspect(Object aspect);

    template<typename T>
 static T inheritFrom(BuildContext context, Object aspect);

private:

    template<typename T>
 static void _findModels(BuildContext context, Object aspect, List<InheritedElement> results);

};
template<typename T>
using InheritedModel = std::shared_ptr<InheritedModelCls<T>>;

template<typename T>
class InheritedModelElementCls : public InheritedElementCls {
public:

     InheritedModelElementCls(Widget widget);
    virtual void updateDependencies(Element dependent, Object aspect);

    virtual void notifyDependent(InheritedModel<T> oldWidget, Element dependent);

private:

};
template<typename T>
using InheritedModelElement = std::shared_ptr<InheritedModelElementCls<T>>;


#endif