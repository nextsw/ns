#include "symbol.hpp"
bool SymbolCls::==(Object other) {
    return is<Symbol>(other) && _name == other->_name;
}

String SymbolCls::getName(Symbol symbol) {
    return symbol->_name;
}
