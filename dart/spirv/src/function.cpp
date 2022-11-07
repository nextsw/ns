#include "function.hpp"
_Block _Function::addBlock(int id) {
    _Block b = _Block(id, this);
    blocks[id] = b;
    entry = b;
    return b;
}

_Block _Function::block(int id) {
    return blocks[id]!;
}

void _Function::declareVariable(int id, int type) {
    variables[id] = _Variable(id, type);
}

_Variable _Function::variable(int id) {
    return variables[id];
}

void _Function::declareParam(int id, int paramType) {
    int i = declaredParams;
    if (paramType != type.params[i]) {
        ;
    }
    params[i] = id;
    declaredParams++;
}

List<_Variable> _Function::variableDeps(int id) {
    _Instruction result = transpiler.results[id];
    if (result == nullptr) {
        return ;
    }
    Set<int> deps = ;
    transpiler.collectDeps(deps, id);
    return deps.where(variables.containsKey).map().toList();
}

void _Function::write(StringBuffer out) {
    if (declaredParams != params.length) {
        ;
    }
    if (entry == nullptr) {
        ;
    }
    String returnTypeString = transpiler.resolveType(type.returnType);
    if (transpiler.target == TargetLanguage.sksl && name == transpiler.entryPoint) {
        returnTypeString = "half4";
    }
    String nameString = transpiler.resolveName(name);
    out.write("$returnTypeString $nameString(");
    if (transpiler.target == TargetLanguage.sksl && name == transpiler.entryPoint) {
        String fragParam = "float2 $_fragParamName";
        out.write(fragParam);
    }
    for (;  < params.length; i++) {
        String typeString = transpiler.resolveType(type.params[i]);
        String nameString = transpiler.resolveName(params[i]);
        out.write("$typeString $nameString");
        if ( < params.length - 1) {
            out.write(", ");
        }
    }
    out.writeln(") {");
    if (transpiler.target == TargetLanguage.sksl && name == transpiler.entryPoint) {
        if (transpiler.fragCoord > 0) {
            String fragName = transpiler.resolveName(transpiler.fragCoord);
            out.writeln("  float4 $fragName = float4($_fragParamName, 0, 0);");
        }
        out.writeln("  float4 $_colorVariableName;");
    }
    entry?._preprocess();
    entry?.write(_BlockContext(out, 1));
    if (transpiler.target == TargetLanguage.sksl && name == transpiler.entryPoint) {
        out.writeln("  return $_colorVariableName;");
    }
    out.writeln("}");
    out.writeln();
}

_Function::_Function(int name, _Transpiler transpiler, _FunctionType type) {
    {
        params = <int>filled(type.params.length, 0);
    }
}
