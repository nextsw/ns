#ifndef FUNCTION_H
#define FUNCTION_H
#include <memory>




class Function {
public:

    external static void  apply(FunctionType function, Map<Symbol, dynamic> namedArguments, List<dynamic> positionalArguments);

    int hashCode();

    bool ==(Object other);

private:

};

#endif