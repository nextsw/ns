#include "enum.hpp"
int Enum::compareByIndex<T extends Enum>(T value1, T value2) {
    return value1.index - value2.index;
}

int Enum::compareByName<T extends Enum>(T value1, T value2) {
    return value1.name.compareTo(value2.name);
}

String EnumName::name() {
    return _name;
}

T EnumByName::byName(String name) {
    for (auto value : this) {
        if (value._name == name)         {
            return value;
        }
    }
    ;
}

Map<String, T> EnumByName::asNameMap() {
    return ;
}
