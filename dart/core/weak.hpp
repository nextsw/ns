#ifndef DART_CORE_WEAK
#define DART_CORE_WEAK
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T : Object> class ExpandoCls : public ObjectCls {
public:
    String name;


    extern  ExpandoCls(String name);
    virtual String toString();

    extern T operator[](Object object);
    extern void operator[]=(Object object, T value);
private:

};
template<typename T : Object> using Expando = std::shared_ptr<ExpandoCls<T : Object>>;

template<typename T : Object> class WeakReferenceCls : public ObjectCls {
public:

    extern  WeakReferenceCls(T target);
    virtual T target();
private:

};
template<typename T : Object> using WeakReference = std::shared_ptr<WeakReferenceCls<T : Object>>;

template<typename T> class FinalizerCls : public ObjectCls {
public:

    extern  FinalizerCls(void callback(T ) );
    virtual void attach(Object detach, T finalizationToken, Object value);
    virtual void detach(Object detach);
private:

};
template<typename T> using Finalizer = std::shared_ptr<FinalizerCls<T>>;


#endif