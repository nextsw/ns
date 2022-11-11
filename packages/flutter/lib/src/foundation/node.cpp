#include "node.hpp"
int AbstractNodeCls::depth() {
    return _depth;
}

void AbstractNodeCls::redepthChild(AbstractNode child) {
    assert(child->owner() == owner());
    if (child->_depth <= _depth) {
        child->_depth = _depth + 1;
        child->redepthChildren();
    }
}

void AbstractNodeCls::redepthChildren() {
}

Object AbstractNodeCls::owner() {
    return _owner;
}

bool AbstractNodeCls::attached() {
    return _owner != nullptr;
}

void AbstractNodeCls::attach(Object owner) {
    assert(owner != nullptr);
    assert(_owner == nullptr);
    _owner = owner;
}

void AbstractNodeCls::detach() {
    assert(_owner != nullptr);
    _owner = nullptr;
    assert(parent() == nullptr || attached() == parent()!->attached());
}

AbstractNode AbstractNodeCls::parent() {
    return _parent;
}

void AbstractNodeCls::adoptChild(AbstractNode child) {
    assert(child != nullptr);
    assert(child->_parent == nullptr);
    assert([=] () {
        AbstractNode node = this;
        while (node->parent() != nullptr) {
            node = node->parent()!;
        }
        assert(node != child);
        return true;
    }());
    child->_parent = this;
    if (attached()) {
        child->attach(_owner!);
    }
    redepthChild(child);
}

void AbstractNodeCls::dropChild(AbstractNode child) {
    assert(child != nullptr);
    assert(child->_parent == this);
    assert(child->attached() == attached());
    child->_parent = nullptr;
    if (attached()) {
        child->detach();
    }
}
