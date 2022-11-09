#ifndef BASE_H
#define BASE_H
#include <memory>

template<class _Tp, class ..._Args>
std::shared_ptr<_Tp> make(_Args&& ...__args)
{
    return _VSTD::allocate_shared<_Tp>(allocator<_Tp>(), _VSTD::forward<_Args>(__args)...);
}


#endif

#ifdef CORE_LIST
#ifndef CORE_LIST_MAKE
#define CORE_LIST_MAKE


template<typename T>
List makeList();

#endif
#endif