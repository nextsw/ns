#ifndef DART_SPIRV_SRC_FUNCTION
#define DART_SPIRV_SRC_FUNCTION
#include <base.hpp>

#include <dart/core/core.hpp>


class _VariableCls : public ObjectCls {
public:
    int id;

    int type;

    bool initialized;

    int liftToBlock;


private:

     _VariableCls(int id, int type);
};
using _Variable = std::shared_ptr<_VariableCls>;

class _FunctionCls : public ObjectCls {
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


    virtual _Block addBlock(int id);

    virtual _Block block(int id);

    virtual void declareVariable(int id, int type);

    virtual _Variable variable(int id);

    virtual void declareParam(int id, int paramType);

    virtual List<_Variable> variableDeps(int id);

    virtual void write(StringBuffer out);

private:

     _FunctionCls(int name, _Transpiler transpiler, _FunctionType type);

};
using _Function = std::shared_ptr<_FunctionCls>;


#endif