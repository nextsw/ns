#include "inherited_model.hpp"
InheritedModelElement<T> InheritedModel::createElement() {
    return <T>InheritedModelElement(this);
}

bool InheritedModel::isSupportedAspect(Object aspect) {
    return true;
}

T InheritedModel::inheritFrom<T extends InheritedModel<Object>>(Object aspect, BuildContext context) {
    if (aspect == nullptr) {
        return context.<T>dependOnInheritedWidgetOfExactType();
    }
    List<InheritedElement> models = ;
    <T>_findModels(context, aspect, models);
    if (models.isEmpty) {
        return nullptr;
    }
    InheritedElement lastModel = models.last;
    for (InheritedElement model : models) {
        T value = (;
        if (model == lastModel) {
            return value;
        }
    }
    assert(false);
    return nullptr;
}

void InheritedModel::_findModels<T extends InheritedModel<Object>>(Object aspect, BuildContext context, List<InheritedElement> results) {
    InheritedElement model = context.<T>getElementForInheritedWidgetOfExactType();
    if (model == nullptr) {
        return;
    }
    results.add(model);
    assert(model.widget is T);
    T modelWidget = (;
    if (modelWidget.isSupportedAspect(aspect)) {
        return;
    }
    Element modelParent;
    model.visitAncestorElements();
    if (modelParent == nullptr) {
        return;
    }
    <T>_findModels(modelParent!, aspect, results);
}

void InheritedModelElement::updateDependencies(Object aspect, Element dependent) {
    Set<T> dependencies = (;
    if (dependencies != nullptr && dependencies.isEmpty) {
        return;
    }
    if (aspect == nullptr) {
        setDependencies(dependent, <T>HashSet());
    } else {
        assert(aspect is T);
        setDependencies(dependent, );
    }
}

void InheritedModelElement::notifyDependent(Element dependent, InheritedModel<T> oldWidget) {
    Set<T> dependencies = (;
    if (dependencies == nullptr) {
        return;
    }
    if (dependencies.isEmpty || (().updateShouldNotifyDependent(oldWidget, dependencies)) {
        dependent.didChangeDependencies();
    }
}
