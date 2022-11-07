#ifndef FUNCTION_H
#define FUNCTION_H
#include <memory>




class _Variable {
public:
    int id;

    int type;

    bool initialized;

    int liftToBlock;


private:

     _Variable(int id, int type);

};

class _Function {
public:
    _Transpiler transpiler;

    int name;

    _FunctionType type;

    List<int> params;

    _Block entry;

    int declaredParams;

    Map<int, _Block> blocks;

    List<int> deps;

    Map<int, _Variable> variables;


    _Block addBlock(int id);

    _Block block(int id);

    void declareVariable(int id, int type);

    _Variable variable(int id);

    void declareParam(int id, int paramType);

    List<_Variable> variableDeps(int id);

    void write(StringBuffer out);

private:

     _Function(int name, _Transpiler transpiler, _FunctionType type);

};

#endif