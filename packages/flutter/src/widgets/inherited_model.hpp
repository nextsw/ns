#ifndef INHERITED_MODEL_H
#define INHERITED_MODEL_H
#include <memory>

#include <collection/collection.hpp>
#include "framework.hpp"



class InheritedModel<T> : InheritedWidget {
public:

     InheritedModel(Unknown, Unknown);

    InheritedModelElement<T> createElement();

    bool updateShouldNotifyDependent(Set<T> dependencies, InheritedModel<T> oldWidget);

    bool isSupportedAspect(Object aspect);

    static T inheritFrom<T extends InheritedModel<Object>>(Object aspect, BuildContext context);

private:

    static void _findModels<T extends InheritedModel<Object>>(Object aspect, BuildContext context, List<InheritedElement> results);

};

class InheritedModelElement<T> : InheritedElement {
public:

     InheritedModelElement(InheritedModel<T> widget);

    void updateDependencies(Object aspect, Element dependent);

    void notifyDependent(Element dependent, InheritedModel<T> oldWidget);

private:

};

#endif