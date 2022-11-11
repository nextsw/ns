#ifndef DART_SPIRV_SRC_TRANSPILER
#define DART_SPIRV_SRC_TRANSPILER
#include <base.hpp>

#include <dart/core/core.hpp>

String _fragParamName;

String _colorVariableName;

String _glslESColorName;

String _glslFragCoord;

String _mainFunctionName;


class _TranspilerCls : public ObjectCls {
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


    virtual void transpile();

    virtual TranspileException failure(String why);

    virtual void collectDeps(Set<int> collectedDeps, int id);

    virtual void writeFunctionAndDeps(Set<int> visited, int function);

    virtual void writeHeader();

    virtual int resolveId(int id);

    virtual String resolveName(int id);

    virtual String resolveType(int type);

    virtual String resolveResult(int name);

    virtual int readWord();

    virtual void parseHeader();

    virtual String readStringLiteral();

    virtual void ref(int id);

    virtual void addToCurrentBlock(_Instruction inst);

    virtual void parseInstruction();

    virtual void typeCast();

    virtual void opExtInstImport();

    virtual void opExtInst();

    virtual void opMemoryModel();

    virtual void opEntryPoint();

    virtual void opExecutionMode();

    virtual void opCapability();

    virtual void opTypeVoid();

    virtual void opTypeBool();

    virtual void opTypeInt();

    virtual void opTypeFloat();

    virtual void opTypeVector();

    virtual void opTypeMatrix();

    virtual void opTypeImage();

    virtual void opTypeSampledImage();

    virtual void opTypePointer();

    virtual void opTypeFunction();

    virtual void opConstantTrue();

    virtual void opConstantFalse();

    virtual void opConstant();

    virtual void opConstantComposite();

    virtual void opFunction();

    virtual void opFunctionParameter();

    virtual void opFunctionEnd();

    virtual void opFunctionCall();

    virtual void opVariable();

    virtual void opLoad();

    virtual void opSelect();

    virtual void opStore();

    virtual void opAccessChain();

    virtual void opDecorate();

    virtual void opVectorShuffle();

    virtual void opCompositeConstruct();

    virtual void opCompositeExtract();

    virtual void opImageSampleImplicitLod();

    virtual void opLabel();

    virtual void opBranch();

    virtual void opBranchConditional();

    virtual void opLoopMerge();

    virtual void opSelectionMerge();

    virtual void opReturn();

    virtual void opReturnValue();

    virtual void parseUnaryOperator(_Operator op);

    virtual void parseOperatorInst(_Operator op);

    virtual void parseBuiltinFunction(String functionName);

    virtual void parseGLSLInst(int id, int type);

private:

     _TranspilerCls(Uint32List spirv, TargetLanguage target);
};
using _Transpiler = std::shared_ptr<_TranspilerCls>;


#endif