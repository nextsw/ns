#ifndef DART_INTERNAL_ITERABLE
#define DART_INTERNAL_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T> class EfficientLengthIterableCls : public IterableCls<T> {
public:

     EfficientLengthIterableCls();
    virtual int length() override;
private:

};
template<typename T> using EfficientLengthIterable = std::shared_ptr<EfficientLengthIterableCls<T>>;


#endif