#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_MODEL
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_MODEL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "framework.hpp"


template<typename T>
class InheritedModelCls : public InheritedWidgetCls {
public:

     InheritedModelCls(Unknown child, Unknown key);
    virtual InheritedModelElement<T> createElement();

    virtual bool updateShouldNotifyDependent(Set<T> dependencies, InheritedModel<T> oldWidget);
    virtual bool isSupportedAspect(Object aspect);

    template<typename T>
 static T inheritFrom(Object aspect, BuildContext context);

private:

    template<typename T>
 static void _findModels(Object aspect, BuildContext context, List<InheritedElement> results);

};
template<typename T>
using InheritedModel = std::shared_ptr<InheritedModelCls<T>>;

template<typename T>
class InheritedModelElementCls : public InheritedElementCls {
public:

     InheritedModelElementCls(InheritedModel<T> widget);
    virtual void updateDependencies(Object aspect, Element dependent);

    virtual void notifyDependent(Element dependent, InheritedModel<T> oldWidget);

private:

};
template<typename T>
using InheritedModelElement = std::shared_ptr<InheritedModelElementCls<T>>;


#endif