#include "symbol.hpp"
bool Symbol::==(Object other) {
    return other is Symbol && _name == other._name;
}

String Symbol::getName(Symbol symbol) {
    return symbol._name;
}
