#include "node.hpp"
int AbstractNode::depth() {
    return _depth;
}

void AbstractNode::redepthChild(AbstractNode child) {
    assert(child.owner == owner);
    if (child._depth <= _depth) {
        child._depth = _depth + 1;
        child.redepthChildren();
    }
}

void AbstractNode::redepthChildren() {
}

Object AbstractNode::owner() {
    return _owner;
}

bool AbstractNode::attached() {
    return _owner != nullptr;
}

void AbstractNode::attach(Object owner) {
    assert(owner != nullptr);
    assert(_owner == nullptr);
    _owner = owner;
}

void AbstractNode::detach() {
    assert(_owner != nullptr);
    _owner = nullptr;
    assert(parent == nullptr || attached == parent!.attached);
}

AbstractNode AbstractNode::parent() {
    return _parent;
}

void AbstractNode::adoptChild(AbstractNode child) {
    assert(child != nullptr);
    assert(child._parent == nullptr);
    assert(());
    child._parent = this;
    if (attached) {
        child.attach(_owner!);
    }
    redepthChild(child);
}

void AbstractNode::dropChild(AbstractNode child) {
    assert(child != nullptr);
    assert(child._parent == this);
    assert(child.attached == attached);
    child._parent = nullptr;
    if (attached) {
        child.detach();
    }
}
