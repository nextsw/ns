#include "selection_container.hpp"
SelectionContainer::SelectionContainer(Widget child, SelectionContainerDelegate delegate, Unknown, SelectionRegistrar registrar) {
    {
        assert(delegate != nullptr);
        assert(child != nullptr);
    }
}

void SelectionContainer::disabled(Widget child, Unknown)

SelectionRegistrar SelectionContainer::maybeOf(BuildContext context) {
    SelectionRegistrarScope scope = context.<SelectionRegistrarScope>dependOnInheritedWidgetOfExactType();
    return scope?.registrar;
}

State<SelectionContainer> SelectionContainer::createState() {
    return _SelectionContainerState();
}

bool SelectionContainer::_disabled() {
    return delegate == nullptr;
}

void _SelectionContainerState::initState() {
    super.initState();
    if (!widget._disabled) {
        widget.delegate!._selectionContainerContext = context;
        if (widget.registrar != nullptr) {
            registrar = widget.registrar;
        }
    }
}

void _SelectionContainerState::didUpdateWidget(SelectionContainer oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.delegate != widget.delegate) {
        if (!oldWidget._disabled) {
            oldWidget.delegate!._selectionContainerContext = nullptr;
            _listeners.forEach(oldWidget.delegate!.removeListener);
        }
        if (!widget._disabled) {
            widget.delegate!._selectionContainerContext = context;
            _listeners.forEach(widget.delegate!.addListener);
        }
        if (oldWidget.delegate?.value != widget.delegate?.value) {
            for (VoidCallback listener : _listeners) {
                listener();
            }
        }
    }
    if (widget._disabled) {
        registrar = nullptr;
    } else     {
        if (widget.registrar != nullptr) {
        registrar = widget.registrar;
    }
;
    }    assert(!widget._disabled || registrar == nullptr);
}

void _SelectionContainerState::didChangeDependencies() {
    super.didChangeDependencies();
    if (widget.registrar == nullptr && !widget._disabled) {
        registrar = SelectionContainer.maybeOf(context);
    }
    assert(!widget._disabled || registrar == nullptr);
}

void _SelectionContainerState::addListener(VoidCallback listener) {
    assert(!widget._disabled);
    widget.delegate!.addListener(listener);
    _listeners.add(listener);
}

void _SelectionContainerState::removeListener(VoidCallback listener) {
    widget.delegate?.removeListener(listener);
    _listeners.remove(listener);
}

void _SelectionContainerState::pushHandleLayers(LayerLink endHandle, LayerLink startHandle) {
    assert(!widget._disabled);
    widget.delegate!.pushHandleLayers(startHandle, endHandle);
}

SelectedContent _SelectionContainerState::getSelectedContent() {
    assert(!widget._disabled);
    return widget.delegate!.getSelectedContent();
}

SelectionResult _SelectionContainerState::dispatchSelectionEvent(SelectionEvent event) {
    assert(!widget._disabled);
    return widget.delegate!.dispatchSelectionEvent(event);
}

SelectionGeometry _SelectionContainerState::value() {
    if (widget._disabled) {
        return _disabledGeometry;
    }
    return widget.delegate!.value;
}

Matrix4 _SelectionContainerState::getTransformTo(RenderObject ancestor) {
    assert(!widget._disabled);
    return context.findRenderObject()!.getTransformTo(ancestor);
}

Size _SelectionContainerState::size() {
    return (().size;
}

void _SelectionContainerState::dispose() {
    if (!widget._disabled) {
        widget.delegate!._selectionContainerContext = nullptr;
        _listeners.forEach(widget.delegate!.removeListener);
    }
    super.dispose();
}

Widget _SelectionContainerState::build(BuildContext context) {
    if (widget._disabled) {
        return SelectionRegistrarScope._disabled(widget.child);
    }
    return SelectionRegistrarScope(widget.delegate!, widget.child);
}

SelectionRegistrarScope::SelectionRegistrarScope(Unknown, Unknown, SelectionRegistrar registrar) {
    {
        assert(registrar != nullptr);
    }
}

bool SelectionRegistrarScope::updateShouldNotify(SelectionRegistrarScope oldWidget) {
    return oldWidget.registrar != registrar;
}

void SelectionRegistrarScope::_disabled(Unknown)

Matrix4 SelectionContainerDelegate::getTransformFrom(Selectable child) {
    assert(_selectionContainerContext?.findRenderObject() != nullptr, "getTransformFrom cannot be called before SelectionContainer is laid out.");
    return child.getTransformTo(();
}

Matrix4 SelectionContainerDelegate::getTransformTo(RenderObject ancestor) {
    assert(_selectionContainerContext?.findRenderObject() != nullptr, "getTransformTo cannot be called before SelectionContainer is laid out.");
    RenderBox box = (;
    return box.getTransformTo(ancestor);
}

Size SelectionContainerDelegate::containerSize() {
    assert(_selectionContainerContext?.findRenderObject() != nullptr, "containerSize cannot be called before SelectionContainer is laid out.");
    RenderBox box = (;
    return box.size;
}
