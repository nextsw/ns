#include "function.hpp"
_Block _FunctionCls::addBlock(int id) {
    _Block b = make<_BlockCls>(id, this);
    blocks[id] = b;
    entry = b;
    return b;
}

_Block _FunctionCls::block(int id) {
    return blocks[id]!;
}

void _FunctionCls::declareVariable(int id, int type) {
    variables[id] = make<_VariableCls>(id, type);
}

_Variable _FunctionCls::variable(int id) {
    return variables[id];
}

void _FunctionCls::declareParam(int id, int paramType) {
    int i = declaredParams;
    if (paramType != type->params[i]) {
        ;
    }
    params[i] = id;
    declaredParams++;
}

List<_Variable> _FunctionCls::variableDeps(int id) {
    _Instruction result = transpiler->results[id];
    if (result == nullptr) {
        return makeList();
    }
    Set<int> deps = makeSet();
    transpiler->collectDeps(deps, id);
    return deps->where(variables->containsKey)->map([=] (int id)     {
        variables[id]!;
    })->toList();
}

void _FunctionCls::write(StringBuffer out) {
    if (declaredParams != params->length) {
        ;
    }
    if (entry == nullptr) {
        ;
    }
    String returnTypeString = transpiler->resolveType(type->returnType);
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        returnTypeString = "half4";
    }
    String nameString = transpiler->resolveName(name);
    out->write("$returnTypeString $nameString(");
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        String fragParam = "float2 $_fragParamName";
        out->write(fragParam);
    }
    for (;  < params->length; i++) {
        String typeString = transpiler->resolveType(type->params[i]);
        String nameString = transpiler->resolveName(params[i]);
        out->write("$typeString $nameString");
        if ( < params->length - 1) {
            out->write(", ");
        }
    }
    out->writeln(") {");
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        if (transpiler->fragCoord > 0) {
            String fragName = transpiler->resolveName(transpiler->fragCoord);
            out->writeln("  float4 $fragName = float4($_fragParamName, 0, 0);");
        }
        out->writeln("  float4 $_colorVariableName;");
    }
    entry?->_preprocess();
    entry?->write(make<_BlockContextCls>(out, 1));
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        out->writeln("  return $_colorVariableName;");
    }
    out->writeln("}");
    out->writeln();
}

_FunctionCls::_FunctionCls(int name, _Transpiler transpiler, _FunctionType type) {
    {
        params = <int>filled(type->params->length, 0);
    }
}
