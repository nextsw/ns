#ifndef SYMBOL_H
#define SYMBOL_H
#include <memory>




class Symbol {
public:

    external  Symbol(String name);

    void  unvalidated(String _name);

    bool ==(Object other);

    external int hashCode();

    external void  toString();

    static String getName(Symbol symbol);

    external static String computeUnmangledName(Symbol symbol);

private:
    String _name;


};

#endif