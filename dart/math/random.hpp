#ifndef DART_MATH_RANDOM
#define DART_MATH_RANDOM
#include <base.hpp>

#include <dart/core/core.hpp>


class RandomCls : public ObjectCls {
public:

    extern  RandomCls(int seed);
    extern void  secure();
    virtual int nextInt(int max);
    virtual double nextDouble();
    virtual bool nextBool();
private:

};
using Random = std::shared_ptr<RandomCls>;


#endif