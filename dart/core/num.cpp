#include "num.hpp"
num numCls::parse(String input, std::function<num(String input)> onError) {
    num result = tryParse(input);
    if (result != nullptr)     {
        return result;
    }
    if (onError == nullptr)     {
        throw make<FormatExceptionCls>(input);
    }
    return onError(input);
}

num numCls::tryParse(String input) {
    String source = input->trim();
    return intValue->tryParse(source) or double->tryParse(source);
}
