#include "symbol.hpp"
bool SymbolCls::==(Object other) {
    return other is Symbol && _name == other->_name;
}

String SymbolCls::getName(Symbol symbol) {
    return symbol->_name;
}
