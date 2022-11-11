#include "selection_container.hpp"
SelectionContainerCls::SelectionContainerCls(Widget child, SelectionContainerDelegate delegate, Unknown key, SelectionRegistrar registrar) {
    {
        assert(delegate != nullptr);
        assert(child != nullptr);
    }
}

void SelectionContainerCls::disabled(Widget child, Unknown key)

SelectionRegistrar SelectionContainerCls::maybeOf(BuildContext context) {
    SelectionRegistrarScope scope = context-><SelectionRegistrarScope>dependOnInheritedWidgetOfExactType();
    return scope?->registrar;
}

State<SelectionContainer> SelectionContainerCls::createState() {
    return make<_SelectionContainerStateCls>();
}

bool SelectionContainerCls::_disabled() {
    return delegate == nullptr;
}

void _SelectionContainerStateCls::initState() {
    super->initState();
    if (!widget->_disabled) {
        widget->delegate!->_selectionContainerContext = context;
        if (widget->registrar != nullptr) {
            registrar = widget->registrar;
        }
    }
}

void _SelectionContainerStateCls::didUpdateWidget(SelectionContainer oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->delegate != widget->delegate) {
        if (!oldWidget->_disabled()) {
            oldWidget->delegate!->_selectionContainerContext = nullptr;
            _listeners->forEach(oldWidget->delegate!->removeListener);
        }
        if (!widget->_disabled) {
            widget->delegate!->_selectionContainerContext = context;
            _listeners->forEach(widget->delegate!->addListener);
        }
        if (oldWidget->delegate?->value != widget->delegate?->value) {
            for (VoidCallback listener : _listeners) {
                listener();
            }
        }
    }
    if (widget->_disabled) {
        registrar = nullptr;
    } else {
        if (widget->registrar != nullptr) {
        registrar = widget->registrar;
    }
;
    }    assert(!widget->_disabled || registrar == nullptr);
}

void _SelectionContainerStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    if (widget->registrar == nullptr && !widget->_disabled) {
        registrar = SelectionContainerCls->maybeOf(context);
    }
    assert(!widget->_disabled || registrar == nullptr);
}

void _SelectionContainerStateCls::addListener(VoidCallback listener) {
    assert(!widget->_disabled);
    widget->delegate!->addListener(listener);
    _listeners->add(listener);
}

void _SelectionContainerStateCls::removeListener(VoidCallback listener) {
    widget->delegate?->removeListener(listener);
    _listeners->remove(listener);
}

void _SelectionContainerStateCls::pushHandleLayers(LayerLink startHandle, LayerLink endHandle) {
    assert(!widget->_disabled);
    widget->delegate!->pushHandleLayers(startHandle, endHandle);
}

SelectedContent _SelectionContainerStateCls::getSelectedContent() {
    assert(!widget->_disabled);
    return widget->delegate!->getSelectedContent();
}

SelectionResult _SelectionContainerStateCls::dispatchSelectionEvent(SelectionEvent event) {
    assert(!widget->_disabled);
    return widget->delegate!->dispatchSelectionEvent(event);
}

SelectionGeometry _SelectionContainerStateCls::value() {
    if (widget->_disabled) {
        return _disabledGeometry;
    }
    return widget->delegate!->value;
}

Matrix4 _SelectionContainerStateCls::getTransformTo(RenderObject ancestor) {
    assert(!widget->_disabled);
    return context->findRenderObject()!->getTransformTo(ancestor);
}

Size _SelectionContainerStateCls::size() {
    return (as<RenderBox>(context->findRenderObject()!))->size();
}

void _SelectionContainerStateCls::dispose() {
    if (!widget->_disabled) {
        widget->delegate!->_selectionContainerContext = nullptr;
        _listeners->forEach(widget->delegate!->removeListener);
    }
    super->dispose();
}

Widget _SelectionContainerStateCls::build(BuildContext context) {
    if (widget->_disabled) {
        return SelectionRegistrarScopeCls->_disabled(widget->child);
    }
    return make<SelectionRegistrarScopeCls>(widget->delegate!, widget->child);
}

SelectionRegistrarScopeCls::SelectionRegistrarScopeCls(Unknown child, Unknown key, SelectionRegistrar registrar) {
    {
        assert(registrar != nullptr);
    }
}

bool SelectionRegistrarScopeCls::updateShouldNotify(SelectionRegistrarScope oldWidget) {
    return oldWidget->registrar != registrar;
}

void SelectionRegistrarScopeCls::_disabled(Unknown child)

Matrix4 SelectionContainerDelegateCls::getTransformFrom(Selectable child) {
    assert(_selectionContainerContext?->findRenderObject() != nullptr, __s("getTransformFrom cannot be called before SelectionContainer is laid out."));
    return child->getTransformTo(as<RenderBox>(_selectionContainerContext!->findRenderObject()!));
}

Matrix4 SelectionContainerDelegateCls::getTransformTo(RenderObject ancestor) {
    assert(_selectionContainerContext?->findRenderObject() != nullptr, __s("getTransformTo cannot be called before SelectionContainer is laid out."));
    RenderBox box = as<RenderBox>(_selectionContainerContext!->findRenderObject()!);
    return box->getTransformTo(ancestor);
}

Size SelectionContainerDelegateCls::containerSize() {
    assert(_selectionContainerContext?->findRenderObject() != nullptr, __s("containerSize cannot be called before SelectionContainer is laid out."));
    RenderBox box = as<RenderBox>(_selectionContainerContext!->findRenderObject()!);
    return box->size();
}
