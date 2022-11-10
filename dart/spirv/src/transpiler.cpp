#include "transpiler.hpp"
void _TranspilerCls::transpile() {
    parseHeader();
    writeHeader();
    while ( < spirv->length) {
        int lastPosition = position;
        parseInstruction();
        assert(position > lastPosition);
    }
    if (uniformDeclarations->isNotEmpty()) {
        src->writeln();
        List<int> locations = uniformDeclarations->keys()->toList();
        locations->sort([=] (int a,int b)         {
            a - b;
        });
        for (int location : locations) {
            src->writeln(uniformDeclarations[location]);
        }
    }
    if (samplerSizeDeclarations->isNotEmpty()) {
        src->writeln();
        List<int> locations = samplerSizeDeclarations->keys()->toList();
        locations->sort([=] (int a,int b)         {
            a - b;
        });
        for (int location : locations) {
            src->writeln(samplerSizeDeclarations[location]);
        }
    }
    src->writeln();
    Set<int> visited = makeSet();
    writeFunctionAndDeps(visited, entryPoint);
}

TranspileException _TranspilerCls::failure(String why) {
    return TranspileExceptionCls->_(currentOp, why);
}

void _TranspilerCls::collectDeps(Set<int> collectedDeps, int id) {
    if (alias->containsKey(id)) {
        id = alias[id]!;
        collectedDeps->add(id);
    }
    _Instruction result = results[id];
    if (result == nullptr) {
        return;
    }
    for (int i : result->deps) {
        if (!collectedDeps->contains(i)) {
            collectedDeps->add(i);
            collectDeps(collectedDeps, i);
        }
    }
}

void _TranspilerCls::writeFunctionAndDeps(int function, Set<int> visited) {
    if (visited->contains(function)) {
        return;
    }
    visited->add(function);
    _Function f = functions[function]!;
    for (int dep : f->deps) {
        writeFunctionAndDeps(visited, dep);
    }
    f->write(src);
}

void _TranspilerCls::writeHeader() {
    ;
}

int _TranspilerCls::resolveId(int id) {
    if (alias->containsKey(id)) {
        return alias[id]!;
    }
    return id;
}

String _TranspilerCls::resolveName(int id) {
    if (alias->containsKey(id)) {
        return resolveName(alias[id]!);
    }
    if (nameOverloads->containsKey(id)) {
        return nameOverloads[id]!;
    } else     {
        if (constantTrue > 0 && id == constantTrue) {
        return __s("true");
    } else     {
        if (constantFalse > 0 && id == constantFalse) {
        return __s("false");
    }
;
    };
    }    if (id == colorOutput) {
        if (target == TargetLanguageCls::glslES) {
            return _glslESColorName;
        } else {
            return _colorVariableName;
        }
    } else     {
        if (id == entryPoint) {
        return _mainFunctionName;
    } else     {
        if (id == fragCoord && target != TargetLanguageCls::sksl) {
        return _glslFragCoord;
    }
;
    };
    }    return __s("i$id");
}

String _TranspilerCls::resolveType(int type) {
    _Type t = types[type];
    if (t == nullptr) {
        ;
    }
    return _typeName(t, target);
}

String _TranspilerCls::resolveResult(int name) {
    if (alias->containsKey(name)) {
        return resolveResult(alias[name]!);
    }
    _Instruction res = results[name];
    if (res != nullptr && res->refCount <= 1) {
        StringBuffer buf = make<StringBufferCls>();
        buf->write(__s("("));
        res->write(this, buf);
        buf->write(__s(")"));
        return buf->toString();
    }
    return resolveName(name);
}

int _TranspilerCls::readWord() {
    if (nextPosition != 0 && position > nextPosition) {
        ;
    }
    int word = spirv[position];
    position++;
    return word;
}

void _TranspilerCls::parseHeader() {
    if (spirv[0] != _magicNumber) {
        ;
    }
    position = 5;
}

String _TranspilerCls::readStringLiteral() {
    List<int> literal = makeList();
    while ( < nextPosition) {
        int word = readWord();
        for (;  < 4; i++) {
            int octet = (word >> (i * 8)) & 0xFF;
            if (octet == 0) {
                return utf8->decode(literal);
            }
            literal->add(octet);
        }
    }
    ;
}

void _TranspilerCls::ref(int id) {
    int a = alias[id];
    if (a != nullptr) {
        ref(a);
        return;
    }
    results[id]?->refCount++;
}

void _TranspilerCls::addToCurrentBlock(_Instruction inst) {
    if (inst->isResult) {
        results[inst->id] = inst;
    }
    currentBlock!->_add(inst);
}

void _TranspilerCls::parseInstruction() {
    int word = readWord();
    currentOp = word & 0xFFFF;
    nextPosition = position + (word >> 16) - 1;
    ;
    position = nextPosition;
}

void _TranspilerCls::typeCast() {
    int type = readWord();
    int name = readWord();
    int value = readWord();
    ref(value);
    addToCurrentBlock(make<_TypeCastCls>(type, name, value));
}

void _TranspilerCls::opExtInstImport() {
    glslExtImport = readWord();
    String ext = readStringLiteral();
    if (ext != _glslStd450) {
        ;
    }
}

void _TranspilerCls::opExtInst() {
    int type = readWord();
    int id = readWord();
    int set = readWord();
    if (set != glslExtImport) {
        ;
    }
    parseGLSLInst(id, type);
}

void _TranspilerCls::opMemoryModel() {
    if (readWord() != _addressingModelLogical) {
        ;
    }
    if (readWord() != _memoryModelGLSL450) {
        ;
    }
}

void _TranspilerCls::opEntryPoint() {
    position++;
    entryPoint = readWord();
}

void _TranspilerCls::opExecutionMode() {
    position++;
    int executionMode = readWord();
    if (executionMode != _originLowerLeft) {
        ;
    }
}

void _TranspilerCls::opCapability() {
    int capability = readWord();
    ;
}

void _TranspilerCls::opTypeVoid() {
    types[readWord()] = _TypeCls::_void;
}

void _TranspilerCls::opTypeBool() {
    types[readWord()] = _TypeCls::_bool;
}

void _TranspilerCls::opTypeInt() {
    int id = readWord();
    types[id] = _TypeCls::_int;
    intType = id;
    int width = readWord();
    if (width != 32) {
        ;
    }
}

void _TranspilerCls::opTypeFloat() {
    int id = readWord();
    types[id] = _TypeCls::float;
    floatType = id;
    int width = readWord();
    if (width != 32) {
        ;
    }
}

void _TranspilerCls::opTypeVector() {
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

void _TranspilerCls::opTypeMatrix() {
    int id = readWord();
    _Type t;
    int columnType = readWord();
    int columnCount = readWord();
    _Type expected = _TypeCls::float2;
    ;
    if (types[columnType] != expected) {
        ;
    }
    types[id] = t;
}

void _TranspilerCls::opTypeImage() {
    if (imageType != 0) {
        ;
    }
    int id = readWord();
    int sampledType = readWord();
    if (types[sampledType] != _TypeCls::float) {
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

void _TranspilerCls::opTypeSampledImage() {
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
    types[id] = _TypeCls::sampledImage;
}

void _TranspilerCls::opTypePointer() {
    int id = readWord();
    position++;
    _Type t = types[readWord()];
    if (t == nullptr) {
        ;
    }
    types[id] = t;
}

void _TranspilerCls::opTypeFunction() {
    int id = readWord();
    int returnType = readWord();
    int paramCount = nextPosition - position;
    List<int> params = <int>filled(paramCount, 0);
    for (;  < paramCount; i++) {
        params[i] = readWord();
    }
    functionTypes[id] = make<_FunctionTypeCls>(returnType, params);
}

void _TranspilerCls::opConstantTrue() {
    position++;
    constantTrue = readWord();
}

void _TranspilerCls::opConstantFalse() {
    position++;
    constantFalse = readWord();
}

void _TranspilerCls::opConstant() {
    int type = readWord();
    String id = resolveName(readWord());
    int value = readWord();
    String valueString = __s("$value");
    if (types[type] == _TypeCls::float) {
        double v = Int32ListCls->fromList(makeList(ArrayItem))->buffer->asByteData()->getFloat32(0, EndianCls::little);
        valueString = __s("$v");
    }
    String typeName = resolveType(type);
    src->writeln(__s("const $typeName $id = $valueString;"));
}

void _TranspilerCls::opConstantComposite() {
    String type = resolveType(readWord());
    String id = resolveName(readWord());
    src->write(__s("const $type $id = $type("));
    int count = nextPosition - position;
    for (;  < count; i++) {
        src->write(resolveName(readWord()));
        if ( < count - 1) {
            src->write(__s(", "));
        }
    }
    src->writeln(__s(");"));
}

void _TranspilerCls::opFunction() {
    int returnType = readWord();
    int id = readWord();
    position++;
    int typeIndex = readWord();
    _FunctionType functionType = functionTypes[typeIndex];
    if (functionType == nullptr) {
        ;
    }
    if (returnType != functionType->returnType) {
        ;
    }
    _Function f = make<_FunctionCls>(this, functionType, id);
    functions[id] = f;
    currentFunction = f;
}

void _TranspilerCls::opFunctionParameter() {
    int type = readWord();
    int id = readWord();
    _Function f = currentFunction!;
    f->declareParam(id, type);
}

void _TranspilerCls::opFunctionEnd() {
    currentFunction = nullptr;
    currentBlock = nullptr;
}

void _TranspilerCls::opFunctionCall() {
    int type = readWord();
    int name = readWord();
    int functionId = readWord();
    String functionName = resolveName(functionId);
    currentFunction!->deps->add(functionId);
    List<int> args = <int>filled(nextPosition - position, 0);
    for (;  < args->length; i++) {
        int id = readWord();
        ref(id);
        args[i] = id;
    }
    addToCurrentBlock(make<_FunctionCallCls>(type, name, functionName, args));
}

void _TranspilerCls::opVariable() {
    int typeId = readWord();
    String type = resolveType(typeId);
    int id = readWord();
    String name = resolveName(id);
    int storageClass = readWord();
    ;
}

void _TranspilerCls::opLoad() {
    position++;
    int id = readWord();
    int pointer = readWord();
    alias[id] = pointer;
}

void _TranspilerCls::opSelect() {
    int type = readWord();
    int name = readWord();
    int condition = readWord();
    int a = readWord();
    int b = readWord();
    ref(condition);
    ref(a);
    ref(b);
    addToCurrentBlock(make<_SelectCls>(type, name, condition, a, b));
}

void _TranspilerCls::opStore() {
    int pointer = readWord();
    int object = readWord();
    ref(object);
    _Variable v = currentFunction!->variable(pointer);
    if (v != nullptr && !v->initialized) {
        addToCurrentBlock(make<_StoreCls>(pointer, objecttrue, v->type));
        v->initialized = true;
        return;
    }
    _Instruction objInstruction = results[object];
    if (is<_BinaryOperator>(objInstruction) && resolveId(objInstruction->a) == pointer && _isCompoundAssignment(objInstruction->op)) {
        addToCurrentBlock(make<_CompoundAssignmentCls>(pointer, objInstruction->op, objInstruction->b));
        return;
    }
    addToCurrentBlock(make<_StoreCls>(pointer, object));
}

void _TranspilerCls::opAccessChain() {
    int type = readWord();
    int id = readWord();
    int base = readWord();
    ref(base);
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices->length; i++) {
        int id = readWord();
        ref(id);
        indices[i] = id;
    }
    addToCurrentBlock(make<_AccessChainCls>(type, id, base, indices));
}

void _TranspilerCls::opDecorate() {
    int target = readWord();
    int decoration = readWord();
    ;
}

void _TranspilerCls::opVectorShuffle() {
    int type = readWord();
    int name = readWord();
    int vector = readWord();
    position++;
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices->length; i++) {
        ref(vector);
        int id = readWord();
        indices[i] = id;
    }
    addToCurrentBlock(make<_VectorShuffleCls>(type, name, vector, indices));
}

void _TranspilerCls::opCompositeConstruct() {
    int type = readWord();
    int name = readWord();
    List<int> components = <int>filled(nextPosition - position, 0);
    for (;  < components->length; i++) {
        int id = readWord();
        ref(id);
        components[i] = id;
    }
    addToCurrentBlock(make<_CompositeConstructCls>(type, name, components));
}

void _TranspilerCls::opCompositeExtract() {
    int type = readWord();
    int name = readWord();
    int src = readWord();
    ref(src);
    List<int> indices = <int>filled(nextPosition - position, 0);
    for (;  < indices->length; i++) {
        int index = readWord();
        indices[i] = index;
    }
    addToCurrentBlock(make<_CompositeExtractCls>(type, name, src, indices));
}

void _TranspilerCls::opImageSampleImplicitLod() {
    int type = readWord();
    int name = readWord();
    int sampledImage = readWord();
    int coordinate = readWord();
    ref(coordinate);
    addToCurrentBlock(make<_ImageSampleImplicitLodCls>(type, name, sampledImage, coordinate));
}

void _TranspilerCls::opLabel() {
    int id = readWord();
    currentBlock = currentFunction!->addBlock(id);
}

void _TranspilerCls::opBranch() {
    currentBlock!->branch = readWord();
    currentBlock = nullptr;
}

void _TranspilerCls::opBranchConditional() {
    _Block b = currentBlock!;
    b->condition = readWord();
    b->truthyBlock = readWord();
    b->falseyBlock = readWord();
}

void _TranspilerCls::opLoopMerge() {
    _Block b = currentBlock!;
    b->mergeBlock = readWord();
    b->continueBlock = readWord();
}

void _TranspilerCls::opSelectionMerge() {
    currentBlock!->mergeBlock = readWord();
}

void _TranspilerCls::opReturn() {
    if (currentFunction!->name == entryPoint) {
        return;
    } else {
        addToCurrentBlock(make<_ReturnCls>());
    }
}

void _TranspilerCls::opReturnValue() {
    int value = readWord();
    ref(value);
    addToCurrentBlock(make<_ReturnValueCls>(value));
}

void _TranspilerCls::parseUnaryOperator(_Operator op) {
    int type = readWord();
    int name = readWord();
    int operand = readWord();
    ref(operand);
    addToCurrentBlock(make<_UnaryOperatorCls>(type, name, op, operand));
}

void _TranspilerCls::parseOperatorInst(_Operator op) {
    int type = readWord();
    int name = readWord();
    int a = readWord();
    int b = readWord();
    ref(a);
    ref(b);
    addToCurrentBlock(make<_BinaryOperatorCls>(type, name, op, a, b));
}

void _TranspilerCls::parseBuiltinFunction(String functionName) {
    int type = readWord();
    int name = readWord();
    List<int> args = <int>filled(nextPosition - position, 0);
    for (;  < args->length; i++) {
        int id = readWord();
        ref(id);
        args[i] = id;
    }
    addToCurrentBlock(make<_BuiltinFunctionCls>(type, name, functionName, args));
}

void _TranspilerCls::parseGLSLInst(int id, int type) {
    int inst = readWord();
    if (inst == _glslStd450Atan2 && target == TargetLanguageCls::sksl) {
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
    addToCurrentBlock(make<_BuiltinFunctionCls>(type, id, opName, args));
}
