#include "num.hpp"
num numCls::parse(String input, num onError(String input) ) {
    num result = tryParse(input);
    if (result != nullptr)     {
        return result;
    }
    if (onError == nullptr)     {
        ;
    }
    return onError(input);
}

num numCls::tryParse(String input) {
    String source = input->trim();
    return intValue->tryParse(source) or double->tryParse(source);
}
