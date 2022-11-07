#include "num.hpp"
num num::parse(String input, FunctionType onError) {
    num result = tryParse(input);
    if (result != nullptr)     {
        return result;
    }
    if (onError == nullptr)     {
        ;
    }
    return onError(input);
}

num num::tryParse(String input) {
    String source = input.trim();
    return int.tryParse(source) ?? double.tryParse(source);
}
