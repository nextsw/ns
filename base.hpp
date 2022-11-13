#ifndef BASE_H
#define BASE_H
#include <memory>
#include <functional>

template<class _Tp, class ..._Args>
std::shared_ptr<_Tp> make(_Args&& ...__args)
{
    return _VSTD::allocate_shared<_Tp>(allocator<_Tp>(), _VSTD::forward<_Args>(__args)...);
}

//std::shared_ptr<B> bp = std::dynamic_pointer_cast<B>(ap);
template<typename T, typename U> bool is(std::shared_ptr<U> a) {
    return std::dynamic_pointer_cast<T>(a) == nullptr;
}

template<typename T, typename U> std::shared_ptr<T> as(std::shared_ptr<U> a) {
    return std::dynamic_pointer_cast<T>(a);
}


template <class Type, class BaseClass>
using CheckType = std::is_base_of<BaseClass, Type>::value;

#endif

#ifdef CORE_LIST
#ifndef CORE_LIST_MAKE
#define CORE_LIST_MAKE


template<typename T>
List makeList();

#endif
#endif

#ifdef DART_CORE_OBJECT
#ifndef DART_CORE_OBJECT_OR

template<class T>
std::shared_ptr<T> operator |(std::shared_ptr<T> a, std::shared_ptr<T> b) { 
    return a == nullptr? b : a;
}

template<class T>
std::shared_ptr<T> operator |=(std::shared_ptr<T> a, std::shared_ptr<T> b) { 
    return a = (a == nullptr? b : a);
}
using any = ObjectCls;


#endif
#endif

#ifdef DART_CORE_STRING
#ifndef DART_CORE_STRING_S

String __s(const char* str) {
    // TODO
    return nullptr;
}

String __sf(String format, ...) {
    //TODO
    return nullptr;
}

#endif
#endif