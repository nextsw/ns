#include "function.hpp"
_Block _FunctionCls::addBlock(int id) {
    _Block b = make<_BlockCls>(id, this);
    blocks[id] = b;
    entry |= b;
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
        throw TranspileExceptionCls->_(_opFunctionParameter, __sf("type mismatch for param %s of function %s", i, name));
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
    return deps->where(variables->containsKey)->map([=] (int id) {
        variables[id]!;
    })->toList();
}

void _FunctionCls::write(StringBuffer out) {
    if (declaredParams != params->length()) {
        throw transpiler->failure(__sf("not all parameters declared for function %s", name));
    }
    if (entry == nullptr) {
        throw transpiler->failure(__sf("function %s has no entry block", name));
    }
    String returnTypeString = transpiler->resolveType(type->returnType);
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        returnTypeString = __s("half4");
    }
    String nameString = transpiler->resolveName(name);
    out->write(__sf("%s %s(", returnTypeString, nameString));
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        String fragParam = __sf("float2 %s", _fragParamName);
        out->write(fragParam);
    }
    for (;  < params->length(); i++) {
        String typeString = transpiler->resolveType(type->params[i]);
        String nameString = transpiler->resolveName(params[i]);
        out->write(__sf("%s %s", typeString, nameString));
        if ( < params->length() - 1) {
            out->write(__s(", "));
        }
    }
    out->writeln(__s(") {"));
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        if (transpiler->fragCoord > 0) {
            String fragName = transpiler->resolveName(transpiler->fragCoord);
            out->writeln(__sf("  float4 %s = float4(%s, 0, 0);", fragName, _fragParamName));
        }
        out->writeln(__sf("  float4 %s;", _colorVariableName));
    }
    entry?->_preprocess();
    entry?->write(make<_BlockContextCls>(out, 1));
    if (transpiler->target == TargetLanguageCls::sksl && name == transpiler->entryPoint) {
        out->writeln(__sf("  return %s;", _colorVariableName));
    }
    out->writeln(__s("}"));
    out->writeln();
}

_FunctionCls::_FunctionCls(_Transpiler transpiler, _FunctionType type, int name) {
    {
        params = <int>filled(type->params->length(), 0);
    }
}
