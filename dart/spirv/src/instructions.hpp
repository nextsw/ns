#ifndef DART_SPIRV_SRC_INSTRUCTIONS
#define DART_SPIRV_SRC_INSTRUCTIONS
#include <base.hpp>

#include <dart/core/core.hpp>


class _BlockContextCls : public ObjectCls {
public:
    StringBuffer out;

    int indent;

    int merge;

    int continueBlock;

    int loopHeader;

    int loopMerge;


    virtual _BlockContext child(int continueBlock, int loopHeader, int loopMerge, int merge);

    virtual void writeIndent();

private:

     _BlockContextCls(int continueBlock, int indent, int loopHeader, int loopMerge, int merge, StringBuffer out);
};
using _BlockContext = std::shared_ptr<_BlockContextCls>;

class _BlockCls : public ObjectCls {
public:
    int id;

    _Function function;

    List<_Instruction> instructions;

    int branch;

    int mergeBlock;

    int condition;

    int truthyBlock;

    int falseyBlock;

    _Store loopInitializer;

    int continueBlock;

    bool scanned;


    virtual _Transpiler transpiler();

    virtual bool hasSelectionStructure();

    virtual bool hasLoopStructure();

    virtual void write(_BlockContext ctx);

private:

     _BlockCls(int id, _Function function);
    virtual void _add(_Instruction i);

    virtual void _writeContinue(_BlockContext ctx);

    virtual void _preprocess();

    virtual void _writeSelectionStructure(_BlockContext ctx);

    virtual void _writeLoopStructure(_BlockContext ctx);

    virtual bool _isSimple();

};
using _Block = std::shared_ptr<_BlockCls>;

class _InstructionCls : public ObjectCls {
public:
    int refCount;


    virtual int type();

    virtual int id();

    virtual bool isResult();

    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);
private:

};
using _Instruction = std::shared_ptr<_InstructionCls>;

class _FunctionCallCls : public _InstructionCls {
public:
    int type;

    int id;

    String function;

    List<int> args;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _FunctionCallCls(int type, int id, String function, List<int> args);
};
using _FunctionCall = std::shared_ptr<_FunctionCallCls>;

class _ReturnCls : public _InstructionCls {
public:

    virtual void write(_Transpiler t, StringBuffer out);

private:

};
using _Return = std::shared_ptr<_ReturnCls>;

class _SelectCls : public _InstructionCls {
public:
    int type;

    int id;

    int condition;

    int a;

    int b;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _SelectCls(int type, int id, int condition, int a, int b);
};
using _Select = std::shared_ptr<_SelectCls>;

class _CompoundAssignmentCls : public _InstructionCls {
public:
    int pointer;

    _Operator op;

    int object;


    virtual void write(_Transpiler t, StringBuffer out);

private:

     _CompoundAssignmentCls(int pointer, _Operator op, int object);
};
using _CompoundAssignment = std::shared_ptr<_CompoundAssignmentCls>;

class _StoreCls : public _InstructionCls {
public:
    int pointer;

    int object;

    bool shouldDeclare;

    int declarationType;

    int selfModifyObject;

    String selfModifyOperator;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _StoreCls(int pointer, int object, int declarationType, bool shouldDeclare);
};
using _Store = std::shared_ptr<_StoreCls>;

class _AccessChainCls : public _InstructionCls {
public:
    int type;

    int id;

    int base;

    List<int> indices;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _AccessChainCls(int type, int id, int base, List<int> indices);
};
using _AccessChain = std::shared_ptr<_AccessChainCls>;

class _VectorShuffleCls : public _InstructionCls {
public:
    int type;

    int id;

    int vector;

    List<int> indices;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _VectorShuffleCls(int type, int id, int vector, List<int> indices);
};
using _VectorShuffle = std::shared_ptr<_VectorShuffleCls>;

class _CompositeConstructCls : public _InstructionCls {
public:
    int type;

    int id;

    List<int> components;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _CompositeConstructCls(int type, int id, List<int> components);
};
using _CompositeConstruct = std::shared_ptr<_CompositeConstructCls>;

class _CompositeExtractCls : public _InstructionCls {
public:
    int type;

    int id;

    int src;

    List<int> indices;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _CompositeExtractCls(int type, int id, int src, List<int> indices);
};
using _CompositeExtract = std::shared_ptr<_CompositeExtractCls>;

class _ImageSampleImplicitLodCls : public _InstructionCls {
public:
    int type;

    int id;

    int sampledImage;

    int coordinate;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _ImageSampleImplicitLodCls(int type, int id, int sampledImage, int coordinate);
};
using _ImageSampleImplicitLod = std::shared_ptr<_ImageSampleImplicitLodCls>;

class _UnaryOperatorCls : public _InstructionCls {
public:
    int type;

    int id;

    _Operator op;

    int operand;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _UnaryOperatorCls(int type, int id, _Operator op, int operand);
};
using _UnaryOperator = std::shared_ptr<_UnaryOperatorCls>;

class _ReturnValueCls : public _InstructionCls {
public:
    int value;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _ReturnValueCls(int value);
};
using _ReturnValue = std::shared_ptr<_ReturnValueCls>;

class _BinaryOperatorCls : public _InstructionCls {
public:
    int type;

    int id;

    _Operator op;

    int a;

    int b;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _BinaryOperatorCls(int type, int id, _Operator op, int a, int b);
};
using _BinaryOperator = std::shared_ptr<_BinaryOperatorCls>;

class _BuiltinFunctionCls : public _InstructionCls {
public:
    int type;

    int id;

    String function;

    List<int> args;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _BuiltinFunctionCls(int type, int id, String function, List<int> args);
};
using _BuiltinFunction = std::shared_ptr<_BuiltinFunctionCls>;

class _TypeCastCls : public _InstructionCls {
public:
    int type;

    int id;

    int value;


    virtual List<int> deps();

    virtual void write(_Transpiler t, StringBuffer out);

private:

     _TypeCastCls(int type, int id, int value);
};
using _TypeCast = std::shared_ptr<_TypeCastCls>;


#endif