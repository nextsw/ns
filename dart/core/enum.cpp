#include "enum.hpp"
int EnumCls::compareByIndextemplate<typename T> (T value1, T value2) {
    return value1->index - value2->index;
}

int EnumCls::compareByNametemplate<typename T> (T value1, T value2) {
    return value1->name->compareTo(value2->name);
}

String EnumNameCls::name() {
    return _name;
}

template<typename T> T EnumByNameCls<T>::byName(String name) {
    for (auto value : this) {
        if (value->_name == name)         {
            return value;
        }
    }
    ;
}

template<typename T> Map<String, T> EnumByNameCls<T>::asNameMap() {
    return list1;
}
