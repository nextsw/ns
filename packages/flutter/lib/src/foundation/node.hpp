#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_NODE
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_NODE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/meta/meta.hpp>


class AbstractNodeCls : public ObjectCls {
public:

    virtual int depth();

    virtual void redepthChild(AbstractNode child);

    virtual void redepthChildren();

    virtual Object owner();

    virtual bool attached();

    virtual void attach(Object owner);

    virtual void detach();

    virtual AbstractNode parent();

    virtual void adoptChild(AbstractNode child);

    virtual void dropChild(AbstractNode child);

private:
    int _depth;

    Object _owner;

    AbstractNode _parent;


};
using AbstractNode = std::shared_ptr<AbstractNodeCls>;


#endif