#include "inherited_model.hpp"
template<typename T> InheritedModelElement<T> InheritedModelCls<T>::createElement() {
    return <T>make<InheritedModelElementCls>(this);
}

template<typename T> bool InheritedModelCls<T>::isSupportedAspect(Object aspect) {
    return true;
}

template<typename T> T InheritedModelCls<T>::inheritFromtemplate<typename T : InheritedModel<Object>> (Object aspect, BuildContext context) {
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
        T value = ((T)context->dependOnInheritedElement(modelaspect));
        if (model == lastModel) {
            return value;
        }
    }
    assert(false);
    return nullptr;
}

template<typename T> void InheritedModelCls<T>::_findModelstemplate<typename T : InheritedModel<Object>> (Object aspect, BuildContext context, List<InheritedElement> results) {
    InheritedElement model = context-><T>getElementForInheritedWidgetOfExactType();
    if (model == nullptr) {
        return;
    }
    results->add(model);
    assert(model->widget is T);
    T modelWidget = ((T)model->widget);
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

template<typename T> void InheritedModelElementCls<T>::updateDependencies(Object aspect, Element dependent) {
    Set<T> dependencies = ((Set<T>)getDependencies(dependent));
    if (dependencies != nullptr && dependencies->isEmpty) {
        return;
    }
    if (aspect == nullptr) {
        setDependencies(dependent, <T>make<HashSetCls>());
    } else {
        assert(aspect is T);
            auto _c1 = (dependencies ?? <T>make<HashSetCls>());    _c1.add(((T)aspect));setDependencies(dependent, _c1);
    }
}

template<typename T> void InheritedModelElementCls<T>::notifyDependent(Element dependent, InheritedModel<T> oldWidget) {
    Set<T> dependencies = ((Set<T>)getDependencies(dependent));
    if (dependencies == nullptr) {
        return;
    }
    if (dependencies->isEmpty || (((InheritedModel<T>)widget))->updateShouldNotifyDependent(oldWidget, dependencies)) {
        dependent->didChangeDependencies();
    }
}
