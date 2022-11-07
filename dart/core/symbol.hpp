#ifndef SYMBOL_H
#define SYMBOL_H
#include <memory>




class Symbol {
public:
    static const Symbol unaryMinus;

    static const Symbol empty;


     Symbol(String name);

    int hashCode();

    bool ==(Object other);

private:

};

#endif