#include "transpiler.hpp"
void _Transpiler::transpile() {
    parseHeader();
    writeHeader();
    while ( < spirv.length) {
        int lastPosition = position;
        parseInstruction();
        assert(position > lastPosition);
    }
    if (uniformDeclarations.isNotEmpty) {
        src.writeln();
        List<int> locations = uniformDeclarations.keys.toList();
        locations.sort();
        for (int location : locations) {
            src.writeln(uniformDeclarations[location]);
        }
    }
    if (samplerSizeDeclarations.isNotEmpty) {
        src.writeln();
        List<int> locations = samplerSizeDeclarations.keys.toList();
        locations.sort();
        for (int location : locations) {
            src.writeln(samplerSizeDeclarations[location]);
        }
    }
    src.writeln();
    Set<int> visited = ;
    writeFunctionAndDeps(visited, entryPoint);
}

TranspileException _Transpiler::failure(String why) {
    return TranspileException._(currentOp, why);
}

void _Transpiler::collectDeps(Set<int> collectedDeps, int id) {
    if (alias.containsKey(id)) {
        id = alias[id]!;
        collectedDeps.add(id);
    }
    _Instruction result = results[id];
    if (result == nullptr) {
        return;
    }
    for (int i : result.deps) {
        if (!collectedDeps.contains(i)) {
            collectedDeps.add(i);
            collectDeps(collectedDeps, i);
        }
    }
}

void _Transpiler::writeFunctionAndDeps(int function, Set<int> visited) {
    if (visited.contains(function)) {
        return;
    }
    visited.add(function);
    _Function f = functions[function]!;
    for (int dep : f.deps) {
        writeFunctionAndDeps(visited, dep);
    }
    f.write(src);
}

void _Transpiler::writeHeader() {
    ;
}

int _Transpiler::resolveId(int id) {
    if (alias.containsKey(id)) {
        return alias[id]!;
    }
    return id;
}

String _Transpiler::resolveName(int id) {
    if (alias.containsKey(id)) {
        return resolveName(alias[id]!);
    }
    if (nameOverloads.containsKey(id)) {
        return nameOverloads[id]!;
    } else     {
        if (constantTrue > 0 && id == constantTrue) {
        return "true";
    } else     {
        if (constantFalse > 0 && id == constantFalse) {
        return "false";
    }
;
    };
    }    if (id == colorOutput) {
        if (target == TargetLanguage.glslES) {
            return _glslESColorName;
        } else {
            return _colorVariableName;
        }
    } else     {
        if (id == entryPoint) {
        return _mainFunctionName;
    } else     {
        if (id == fragCoord && target != TargetLanguage.sksl) {
        return _glslFragCoord;
    }
;
    };
    }    return "i$id";
}

String _Transpiler::resolveType(int type) {
    _Type t = types[type];
    if (t == nullptr) {
        ;
    }
    return _typeName(t, target);
}

String _Transpiler::resolveResult(int name) {
    if (alias.containsKey(name)) {
        return resolveResult(alias[name]!);
    }
    _Instruction res = results[name];
    if (res != nullptr && res.refCount <= 1) {
        StringBuffer buf = StringBuffer();
        buf.write("(");
        res.write(this, buf);
        buf.write(")");
        return buf.toString();
    }
    return resolveName(name);
}

int _Transpiler::readWord() {
    if (nextPosition != 0 && position > nextPosition) {
        ;
    }
    int word = spirv[position];
    position++;
    return word;
}

void _Transpiler::parseHeader() {
    if (spirv[0] != _magicNumber) {
        ;
    }
    position = 5;
}

String _Transpiler::readStringLiteral() {
    List<int> literal = ;
    while ( < nextPosition) {
        int word = readWord();
        for (;  < 4; i++) {
            int octet = (word >> (i * 8)) & 0xFF;
            if (octet == 0) {
                return utf8.decode(literal);
            }
            literal.add(octet);
        }
    }
    ;
}

void _Transpiler::ref(int id) {
    int a = alias[id];
    if (a != nullptr) {
        ref(a);
        return;
    }
    results[id]?.refCount++;
}

void _Transpiler::addToCurrentBlock(_Instruction inst) {
    if (inst.isResult) {
        results[inst.id] = inst;
    }
    currentBlock!._add(inst);
}

void _Transpiler::parseInstruction() {
    int word = readWord();
    currentOp = word & 0xFFFF;
    nextPosition = position + (word >> 16) - 1;
    ;
    position = nextPosition;
}

void _Transpiler::typeCast() {
    int type = readWord();
    int name = readWord();
    int value = readWord();
    ref(value);
    addToCurrentBlock(_TypeCast(type, name, value));
}

void _Transpiler::opExtInstImport() {
    glslExtImport = readWord();
    String ext = readStringLiteral();
    if (ext != _glslStd450) {
        ;
    }
}

void _Transpiler::opExtInst() {
    int type = readWord();
    int id = readWord();
    int set = readWord();
    if (set != glslExtImport) {
        ;
    }
    parseGLSLInst(id, type);
}

void _Transpiler::opMemoryModel() {
    if (readWord() != _addressingModelLogical) {
        ;
    }
    if (readWord() != _memoryModelGLSL450) {
        ;
    }
}

void _Transpiler::opEntryPoint() {
    position++;
    entryPoint = readWord();
}

void _Transpiler::opExecutionMode() {
    position++;
    int executionMode = readWord();
    if (executionMode != _originLowerLeft) {
        ;
    }
}

void _Transpiler::opCapability() {
    int capability = readWord();
    ;
}

void _Transpiler::opTypeVoid() {
    types[readWord()] = _Type._void;
}

void _Transpiler::opTypeBool() {
    types[readWord()] = _Type._bool;
}

void _Transpiler::opTypeInt() {
    int id = readWord();
    types[id] = _Type._int;
    intType = id;
    int width = readWord();
    if (width != 32) {
        ;
    }
}

void _Transpiler::opTypeFloat() {
    int id = readWord();
    types[id] = _Type.float;
    floatType = id;
    int width = readWord();
    if (width != 32) {
        ;
    }
}

void _Transpiler::opTypeVector() {
    int id = readWord();
    _Type t;
    int componentType = readWord();
    if (componentType != floatType) {
        ;
    }
    int componentCount = readWord();
    ;
    types[id] = t;
}

void _Transpiler::opTypeMatrix() {
    int id = readWord();
    _Type t;
    int columnType = readWord();
    int columnCount = readWord();
    _Type expected = _Type.float2;
    ;
    if (types[columnType] != expected) {
        ;
    }
    types[id] = t;
}

void _Transpiler::opTypeImage() {
    if (imageType != 0) {
        ;
    }
    int id = readWord();
    int sampledType = readWord();
    if (types[sampledType] != _Type.float) {
        ;
    }
    int dimensionality = readWord();
    if (dimensionality != _dim2D) {
        ;
    }
    int depth = readWord();
    if (depth != 0) {
        ;
    }
    int arrayed = readWord();
    if (arrayed != 0) {
        ;
    }
    int multisampled = readWord();
    if (multisampled != 0) {
        ;
    }
    int sampled = readWord();
    if (sampled != 1) {
        ;
    }
    imageType = id;
}

void _Transpiler::opTypeSampledImage() {
    if (sampledImageType != 0) {
        ;
    }
    if (imageType == 0) {
        ;
    }
    int id = readWord();
    int imgType = readWord();
    if (imgType != imageType) {
        ;
    }
    sampledImageType = id;
    types[id] = _Type.sampledImage;
}

void _Transpiler::opTypePointer() {
    int id = readWord();
    position++;
    _Type t = types[readWord()];
    if (t == nullptr) {
        ;
    }
    types[id] = t;
}

void _Transpiler::opTypeFunction() {
    int id = readWord();
    int returnType = readWord();
    int paramCount = nextPosition - position;
    List<int> params = <int>filled(paramCount, 0);
    for (;  < paramCount; i++) {
        params[i] = readWord();
    }
    functionTypes[id] = _FunctionType(returnType, params);
}

void _Transpiler::opConstantTrue() {
    position++;
    constantTrue = readWord();
}

void _Transpiler::opConstantFalse() {
    position++;
    constantFalse = readWord();
}

void _Transpiler::opConstant() {
    int type = readWord();
    String id = resolveName(readWord());
    int value = readWord();
    String valueString = "$value";
    if (types[type] == _Type.float) {
        double v = Int32List.fromList().buffer.asByteData().getFloat32(0, Endian.little);
        valueString = "$v";
    }
    String typeName = resolveType(type);
    src.writeln("const $typeName $id = $valueString;");
}

void _Transpiler::opConstantComposite() {
    String type = resolveType(readWord());
    String id = resolveName(readWord());
    src.write("const $type $id = $type(");
    int count = nextPosition - position;
    for (;  < count; i++) {
        src.write(resolveName(readWord()));
        if ( < count - 1) {
            src.write(", ");
        }
    }
    src.writeln(");");
}

void _Transpiler::opFunction() {
    int returnType = readWord();
    int id = readWord();
    position++;
    int typeIndex = readWord();
    _FunctionType functionType = functionTypes[typeIndex];
    if (functionType == nullptr) {
        ;
    }
    if (returnType != functionType.returnType) {
        ;
    }
    _Function f = _Function(this, functionType, id);
    functions[id] = f;
    currentFunction = f;
}

void _Transpiler::opFunctionParameter() {
    int type = readWord();
    int id = readWord();
    _Function f = currentFunction!;
    f.declareParam(id, type);
}

void _Transpiler::opFunctionEnd() {
    currentFunction = nullptr;
    currentBlock = nullptr;
}

void _Transpiler::opFunctionCall() {
    int type = readWord();
    int name = readWord();
    int functionId = readWord();
    String functionName = resolveName(functionId);
    currentFunction!.deps.add(functionId);
    List<int> args = <int>filled(nextPosition - position, 0);
    for (;  < args.length; i++) {
        int id = readWord();
        ref(id);
        args[i] = id;
    }
    addToCurrentBlock(_FunctionCall(type, name, functionName, args));
}

void _Transpiler::opVariable() {
    int typeId = readWord();
    String type = resolveType(typeId);
    int id = readWord();
    String name = resolveName(id);
    int storageClass = readWord();
    ;
}

void _Transpiler::opLoad() {
    position++;
    int id = readWord();
    int pointer = readWord();
    alias[id] = pointer;
}

void _Transpiler::opSelect() {
    int type = readWord();
    int name = readWord();
    int condition = readWord();
    int a = readWord();
    int b = readWord();
    ref(condition);
    ref(a);
    ref(b);
    addToCurrentBlock(_Select(type, name, condition, a, b));
}

void _Transpiler::opStore() {
    int pointer = readWord();
    int object = readWord();
    ref(object);
    _Variable v = currentFunction!.variable(pointer);
    if (v != nullptr && !v.initialized) {
        addToCurrentBlock(_Store(pointer, objecttrue, v.type));
        v.initialized = true;
        return;
    }
    _Instruction objInstruction = results[object];
    if (objInstruction is _BinaryOperator && resolveId(objInstruction.a) == pointer && _isCompoundAssignment(objInstruction.op)) {
        addToCurrentBlock(_CompoundAssignment(pointer, objInstruction.op, objInstruction.b));
        return;
    }
    addToCurrentBlock(_Store(pointer, object));
}

void _Transpiler::opAccessChain() {
    int type = readWord();
    int id = readWord();
    int base = readWord();
    ref(base);
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices.length; i++) {
        int id = readWord();
        ref(id);
        indices[i] = id;
    }
    addToCurrentBlock(_AccessChain(type, id, base, indices));
}

void _Transpiler::opDecorate() {
    int target = readWord();
    int decoration = readWord();
    ;
}

void _Transpiler::opVectorShuffle() {
    int type = readWord();
    int name = readWord();
    int vector = readWord();
    position++;
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices.length; i++) {
        ref(vector);
        int id = readWord();
        indices[i] = id;
    }
    addToCurrentBlock(_VectorShuffle(type, name, vector, indices));
}

void _Transpiler::opCompositeConstruct() {
    int type = readWord();
    int name = readWord();
    List<int> components = <int>filled(nextPosition - position, 0);
    for (;  < components.length; i++) {
        int id = readWord();
        ref(id);
        components[i] = id;
    }
    addToCurrentBlock(_CompositeConstruct(type, name, components));
}

void _Transpiler::opCompositeExtract() {
    int type = readWord();
    int name = readWord();
    int src = readWord();
    ref(src);
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices.length; i++) {
        int index = readWord();
        indices[i] = index;
    }
    addToCurrentBlock(_CompositeExtract(type, name, src, indices));
}

void _Transpiler::opImageSampleImplicitLod() {
    int type = readWord();
    int name = readWord();
    int sampledImage = readWord();
    int coordinate = readWord();
    ref(coordinate);
    addToCurrentBlock(_ImageSampleImplicitLod(type, name, sampledImage, coordinate));
}

void _Transpiler::opLabel() {
    int id = readWord();
    currentBlock = currentFunction!.addBlock(id);
}

void _Transpiler::opBranch() {
    currentBlock!.branch = readWord();
    currentBlock = nullptr;
}

void _Transpiler::opBranchConditional() {
    _Block b = currentBlock!;
    b.condition = readWord();
    b.truthyBlock = readWord();
    b.falseyBlock = readWord();
}

void _Transpiler::opLoopMerge() {
    _Block b = currentBlock!;
    b.mergeBlock = readWord();
    b.continueBlock = readWord();
}

void _Transpiler::opSelectionMerge() {
    currentBlock!.mergeBlock = readWord();
}

void _Transpiler::opReturn() {
    if (currentFunction!.name == entryPoint) {
        return;
    } else {
        addToCurrentBlock(_Return());
    }
}

void _Transpiler::opReturnValue() {
    int value = readWord();
    ref(value);
    addToCurrentBlock(_ReturnValue(value));
}

void _Transpiler::parseUnaryOperator(_Operator op) {
    int type = readWord();
    int name = readWord();
    int operand = readWord();
    ref(operand);
    addToCurrentBlock(_UnaryOperator(type, name, op, operand));
}

void _Transpiler::parseOperatorInst(_Operator op) {
    int type = readWord();
    int name = readWord();
    int a = readWord();
    int b = readWord();
    ref(a);
    ref(b);
    addToCurrentBlock(_BinaryOperator(type, name, op, a, b));
}

void _Transpiler::parseBuiltinFunction(String functionName) {
    int type = readWord();
    int name = readWord();
    List<int> args = <int>filled(nextPosition - position, 0);
    for (;  < args.length; i++) {
        int id = readWord();
        ref(id);
        args[i] = id;
    }
    addToCurrentBlock(_BuiltinFunction(type, name, functionName, args));
}

void _Transpiler::parseGLSLInst(int id, int type) {
    int inst = readWord();
    if (inst == _glslStd450Atan2 && target == TargetLanguage.sksl) {
        inst = _glslStd450Atan;
    }
    String opName = _glslStd450OpNames[inst];
    if (opName == nullptr) {
        ;
    }
    int argc = _glslStd450OpArgc[inst]!;
    List<int> args = <int>filled(argc, 0);
    for (;  < argc; i++) {
        int id = readWord();
        ref(id);
        args[i] = id;
    }
    addToCurrentBlock(_BuiltinFunction(type, id, opName, args));
}
