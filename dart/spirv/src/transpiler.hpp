#ifndef TRANSPILER_H
#define TRANSPILER_H
#include <memory>



const String _fragParamName;

const String _colorVariableName;

const String _glslESColorName;

const String _glslFragCoord;

const String _mainFunctionName;


class _Transpiler {
public:
    Uint32List spirv;

    TargetLanguage target;

    StringBuffer src;

    Map<int, String> uniformDeclarations;

    Map<int, String> samplerSizeDeclarations;

    Map<int, _Type> types;

    Map<int, _FunctionType> functionTypes;

    Map<int, _Function> functions;

    Map<int, int> locations;

    Map<int, int> alias;

    Map<int, String> nameOverloads;

    Map<int, _Instruction> results;

    int constantTrue;

    int constantFalse;

    int position;

    int nextPosition;

    int currentOp;

    int glslExtImport;

    int entryPoint;

    int intType;

    int floatType;

    int imageType;

    int sampledImageType;

    _Function currentFunction;

    int declaredParams;

    _Block currentBlock;

    int colorOutput;

    int fragCoord;

    int uniformFloatCount;

    int samplerCount;


    void transpile();

    TranspileException failure(String why);

    void collectDeps(Set<int> collectedDeps, int id);

    void writeFunctionAndDeps(int function, Set<int> visited);

    void writeHeader();

    int resolveId(int id);

    String resolveName(int id);

    String resolveType(int type);

    String resolveResult(int name);

    int readWord();

    void parseHeader();

    String readStringLiteral();

    void ref(int id);

    void addToCurrentBlock(_Instruction inst);

    void parseInstruction();

    void typeCast();

    void opExtInstImport();

    void opExtInst();

    void opMemoryModel();

    void opEntryPoint();

    void opExecutionMode();

    void opCapability();

    void opTypeVoid();

    void opTypeBool();

    void opTypeInt();

    void opTypeFloat();

    void opTypeVector();

    void opTypeMatrix();

    void opTypeImage();

    void opTypeSampledImage();

    void opTypePointer();

    void opTypeFunction();

    void opConstantTrue();

    void opConstantFalse();

    void opConstant();

    void opConstantComposite();

    void opFunction();

    void opFunctionParameter();

    void opFunctionEnd();

    void opFunctionCall();

    void opVariable();

    void opLoad();

    void opSelect();

    void opStore();

    void opAccessChain();

    void opDecorate();

    void opVectorShuffle();

    void opCompositeConstruct();

    void opCompositeExtract();

    void opImageSampleImplicitLod();

    void opLabel();

    void opBranch();

    void opBranchConditional();

    void opLoopMerge();

    void opSelectionMerge();

    void opReturn();

    void opReturnValue();

    void parseUnaryOperator(_Operator op);

    void parseOperatorInst(_Operator op);

    void parseBuiltinFunction(String functionName);

    void parseGLSLInst(int id, int type);

private:

     _Transpiler(Uint32List spirv, TargetLanguage target);

};

#endif