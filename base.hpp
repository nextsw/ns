#ifndef BASE_H
#define BASE_H
#include <memory>

template<class _Tp, class ..._Args>
std::shared_ptr<_Tp> make(_Args&& ...__args)
{
    return _VSTD::allocate_shared<_Tp>(allocator<_Tp>(), _VSTD::forward<_Args>(__args)...);
}


//https://stackoverflow.com/questions/1515399/can-you-make-custom-operators-in-c

#define define const struct
#define operator(ReturnType, OperatorName, FirstOperandType, SecondOperandType) OperatorName ## _ {} OperatorName; template <typename T> struct OperatorName ## Proxy{public:OperatorName ## Proxy(const T& t) : t_(t){}const T& t_;static ReturnType _ ## OperatorName ## _(const FirstOperandType a, const SecondOperandType b);};template <typename T> OperatorName ## Proxy<T> operator<(const T& lhs, const OperatorName ## _& rhs){return OperatorName ## Proxy<T>(lhs);}ReturnType operator>(const OperatorName ## Proxy<FirstOperandType>& lhs, const SecondOperandType& rhs){return OperatorName ## Proxy<FirstOperandType>::_ ## OperatorName ## _(lhs.t_, rhs);}template <typename T> inline ReturnType OperatorName ## Proxy<T>::_ ## OperatorName ## _(const FirstOperandType a, const SecondOperandType b)

define operator(bool, myOr, bool, bool) { // Arguments are the return type, the name of the operator, the left operand type and the right operand type, respectively
    return a || b;
}

#define or <myOr>


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

define operator(std::shared_ptr, myOr, std::shared_ptr, std::shared_ptr) { // Arguments are the return type, the name of the operator, the left operand type and the right operand type, respectively
    return a == nullptr? b : a;
}


#endif
#endif

#ifdef DART_CORE_STRING
#ifndef DART_CORE_STRING_S

String __s(const char* str) {
    // TODO
    return nullptr;
}

#endif
#endif