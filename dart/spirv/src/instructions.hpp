#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <memory>




class _BlockContext {
public:
    StringBuffer out;

    int indent;

    int merge;

    int continueBlock;

    int loopHeader;

    int loopMerge;


    _BlockContext child(int continueBlock, int loopHeader, int loopMerge, int merge);

    void writeIndent();

private:

     _BlockContext(int continueBlock, int indent, int loopHeader, int loopMerge, int merge, StringBuffer out);

};

class _Block {
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


    _Transpiler transpiler();

    bool hasSelectionStructure();

    bool hasLoopStructure();

    void write(_BlockContext ctx);

private:

     _Block(_Function function, int id);

    void _add(_Instruction i);

    void _writeContinue(_BlockContext ctx);

    void _preprocess();

    void _writeSelectionStructure(_BlockContext ctx);

    void _writeLoopStructure(_BlockContext ctx);

    bool _isSimple();

};

class _Instruction {
public:
    int refCount;


    int type();

    int id();

    bool isResult();

    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

};

class _FunctionCall : _Instruction {
public:
    int type;

    int id;

    String function;

    List<int> args;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _FunctionCall(List<int> args, String function, int id, int type);

};

class _Return : _Instruction {
public:

    void write(StringBuffer out, _Transpiler t);

private:

};

class _Select : _Instruction {
public:
    int type;

    int id;

    int condition;

    int a;

    int b;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _Select(int a, int b, int condition, int id, int type);

};

class _CompoundAssignment : _Instruction {
public:
    int pointer;

    _Operator op;

    int object;


    void write(StringBuffer out, _Transpiler t);

private:

     _CompoundAssignment(int object, _Operator op, int pointer);

};

class _Store : _Instruction {
public:
    int pointer;

    int object;

    bool shouldDeclare;

    int declarationType;

    int selfModifyObject;

    String selfModifyOperator;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _Store(int declarationType, int object, int pointer, bool shouldDeclare);

};

class _AccessChain : _Instruction {
public:
    int type;

    int id;

    int base;

    List<int> indices;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _AccessChain(int base, int id, List<int> indices, int type);

};

class _VectorShuffle : _Instruction {
public:
    int type;

    int id;

    int vector;

    List<int> indices;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _VectorShuffle(int id, List<int> indices, int type, int vector);

};

class _CompositeConstruct : _Instruction {
public:
    int type;

    int id;

    List<int> components;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _CompositeConstruct(List<int> components, int id, int type);

};

class _CompositeExtract : _Instruction {
public:
    int type;

    int id;

    int src;

    List<int> indices;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _CompositeExtract(int id, List<int> indices, int src, int type);

};

class _ImageSampleImplicitLod : _Instruction {
public:
    int type;

    int id;

    int sampledImage;

    int coordinate;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _ImageSampleImplicitLod(int coordinate, int id, int sampledImage, int type);

};

class _UnaryOperator : _Instruction {
public:
    int type;

    int id;

    _Operator op;

    int operand;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _UnaryOperator(int id, _Operator op, int operand, int type);

};

class _ReturnValue : _Instruction {
public:
    int value;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _ReturnValue(int value);

};

class _BinaryOperator : _Instruction {
public:
    int type;

    int id;

    _Operator op;

    int a;

    int b;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _BinaryOperator(int a, int b, int id, _Operator op, int type);

};

class _BuiltinFunction : _Instruction {
public:
    int type;

    int id;

    String function;

    List<int> args;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _BuiltinFunction(List<int> args, String function, int id, int type);

};

class _TypeCast : _Instruction {
public:
    int type;

    int id;

    int value;


    List<int> deps();

    void write(StringBuffer out, _Transpiler t);

private:

     _TypeCast(int id, int type, int value);

};

#endif