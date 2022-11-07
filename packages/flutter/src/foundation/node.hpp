#ifndef NODE_H
#define NODE_H
#include <memory>

#include <meta/meta.hpp>



class AbstractNode {
public:

    int depth();

    void redepthChild(AbstractNode child);

    void redepthChildren();

    Object owner();

    bool attached();

    void attach(Object owner);

    void detach();

    AbstractNode parent();

    void adoptChild(AbstractNode child);

    void dropChild(AbstractNode child);

private:
    int _depth;

    Object _owner;

    AbstractNode _parent;


};

#endif