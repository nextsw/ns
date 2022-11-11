#include "inherited_model.hpp"
template<typename T>
InheritedModelElement<T> InheritedModelCls<T>::createElement() {
    return <T>make<InheritedModelElementCls>(this);
}

template<typename T>
bool InheritedModelCls<T>::isSupportedAspect(Object aspect) {
    return true;
}

template<typename T>
template<typename T>
T InheritedModelCls<T>::inheritFrom(BuildContext context, Object aspect) {
    if (aspect == nullptr) {
        return context-><T>dependOnInheritedWidgetOfExactType();
    }
    List<InheritedElement> models = makeList();
    <T>_findModels(context, aspect, models);
    if (models->isEmpty) {
        return nullptr;
    }
    InheritedElement lastModel = models->last;
    for (InheritedElement model : models) {
        T value = as<T>(context->dependOnInheritedElement(model, aspect));
        if (model == lastModel) {
            return value;
        }
    }
    assert(false);
    return nullptr;
}

template<typename T>
template<typename T>
void InheritedModelCls<T>::_findModels(BuildContext context, Object aspect, List<InheritedElement> results) {
    InheritedElement model = context-><T>getElementForInheritedWidgetOfExactType();
    if (model == nullptr) {
        return;
    }
    results->add(model);
    assert(is<T>(model->widget));
    T modelWidget = as<T>(model->widget);
    if (modelWidget->isSupportedAspect(aspect)) {
        return;
    }
    Element modelParent;
    model->visitAncestorElements([=] (Element ancestor) {
        modelParent = ancestor;
        return false;
    });
    if (modelParent == nullptr) {
        return;
    }
    <T>_findModels(modelParent!, aspect, results);
}

template<typename T>
void InheritedModelElementCls<T>::updateDependencies(Element dependent, Object aspect) {
    Set<T> dependencies = as<Set<T>>(getDependencies(dependent));
    if (dependencies != nullptr && dependencies->isEmpty) {
        return;
    }
    if (aspect == nullptr) {
        setDependencies(dependent, <T>make<HashSetCls>());
    } else {
        assert(is<T>(aspect));
            auto _c1 = (dependencies | <T>make<HashSetCls>());    _c1.add(as<T>(aspect));setDependencies(dependent, _c1);
    }
}

template<typename T>
void InheritedModelElementCls<T>::notifyDependent(InheritedModel<T> oldWidget, Element dependent) {
    Set<T> dependencies = as<Set<T>>(getDependencies(dependent));
    if (dependencies == nullptr) {
        return;
    }
    if (dependencies->isEmpty || (as<InheritedModel<T>>(widget))->updateShouldNotifyDependent(oldWidget, dependencies)) {
        dependent->didChangeDependencies();
    }
}
