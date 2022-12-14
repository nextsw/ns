#ifndef DART_CORE_WEAK
#define DART_CORE_WEAK
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class ExpandoCls : public ObjectCls {
public:
    String name;


     ExpandoCls(String name);
    virtual String toString();

    T operator[](Object object);
    void operator[]=(Object object, T value);
private:

};
template<typename T>
using Expando = std::shared_ptr<ExpandoCls<T>>;

template<typename T>
class WeakReferenceCls : public ObjectCls {
public:

     WeakReferenceCls(T target);
    virtual T target();
private:

};
template<typename T>
using WeakReference = std::shared_ptr<WeakReferenceCls<T>>;

template<typename T>
class FinalizerCls : public ObjectCls {
public:

     FinalizerCls(std::function<void(T )> callback);
    virtual void attach(Object value, T finalizationToken, Object detach);
    virtual void detach(Object detach);
private:

};
template<typename T>
using Finalizer = std::shared_ptr<FinalizerCls<T>>;


#endif