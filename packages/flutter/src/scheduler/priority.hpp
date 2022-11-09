#ifndef PACKAGES_FLUTTER_SRC_SCHEDULER_PRIORITY
#define PACKAGES_FLUTTER_SRC_SCHEDULER_PRIORITY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>


class PriorityCls : public ObjectCls {
public:
    static Priority idle;

    static Priority animation;

    static Priority touch;

    static int kMaxOffset;


    virtual int value();

    virtual Priority operator+(int offset);

    virtual Priority operator-(int offset);

private:
    int _value;


    virtual void  _(int _value);
};
using Priority = std::shared_ptr<PriorityCls>;


#endif