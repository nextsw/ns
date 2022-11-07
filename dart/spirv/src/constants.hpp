#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <memory>



const int _magicNumber;

const int _originLowerLeft;

const int _addressingModelLogical;

const int _memoryModelGLSL450;

const int _capabilityMatrix;

const int _capabilityShader;

const int _storageClassUniformConstant;

const int _storageClassInput;

const int _storageClassOutput;

const int _storageClassFunction;

const int _decorationBuiltIn;

const int _decorationLocation;

const int _builtinFragCoord;

const int _dim2D;

const int _opSource;

const int _opSourceExtension;

const int _opName;

const int _opMemberName;

const int _opString;

const int _opLine;

const int _opExtInstImport;

const int _opExtInst;

const int _opMemoryModel;

const int _opEntryPoint;

const int _opExecutionMode;

const int _opCapability;

const int _opTypeVoid;

const int _opTypeBool;

const int _opTypeInt;

const int _opTypeFloat;

const int _opTypeVector;

const int _opTypeMatrix;

const int _opTypeImage;

const int _opTypeSampledImage;

const int _opTypePointer;

const int _opTypeFunction;

const int _opConstantTrue;

const int _opConstantFalse;

const int _opConstant;

const int _opConstantComposite;

const int _opFunction;

const int _opFunctionParameter;

const int _opFunctionEnd;

const int _opFunctionCall;

const int _opVariable;

const int _opLoad;

const int _opStore;

const int _opAccessChain;

const int _opDecorate;

const int _opVectorShuffle;

const int _opCompositeConstruct;

const int _opCompositeExtract;

const int _opImageSampleImplicitLod;

const int _opImageQuerySize;

const int _opConvertFToS;

const int _opConvertSToF;

const int _opFNegate;

const int _opFAdd;

const int _opFSub;

const int _opFMul;

const int _opFDiv;

const int _opFMod;

const int _opVectorTimesScalar;

const int _opMatrixTimesScalar;

const int _opVectorTimesMatrix;

const int _opMatrixTimesVector;

const int _opMatrixTimesMatrix;

const int _opDot;

const int _opFOrdEqual;

const int _opFUnordNotEqual;

const int _opFOrdLessThan;

const int _opFOrdGreaterThan;

const int _opFOrdLessThanEqual;

const int _opFOrdGreaterThanEqual;

const int _opLogicalEqual;

const int _opLogicalNotEqual;

const int _opLogicalOr;

const int _opLogicalAnd;

const int _opLogicalNot;

const int _opSelect;

const int _opLoopMerge;

const int _opSelectionMerge;

const int _opLabel;

const int _opBranch;

const int _opBranchConditional;

const int _opReturn;

const int _opReturnValue;

const String _glslStd450;

const int _glslStd450FAbs;

const int _glslStd450FSign;

const int _glslStd450Floor;

const int _glslStd450Ceil;

const int _glslStd450Fract;

const int _glslStd450Radians;

const int _glslStd450Degrees;

const int _glslStd450Sin;

const int _glslStd450Cos;

const int _glslStd450Tan;

const int _glslStd450Asin;

const int _glslStd450Acos;

const int _glslStd450Atan;

const int _glslStd450Atan2;

const int _glslStd450Pow;

const int _glslStd450Exp;

const int _glslStd450Log;

const int _glslStd450Exp2;

const int _glslStd450Log2;

const int _glslStd450Sqrt;

const int _glslStd450InverseSqrt;

const int _glslStd450FMin;

const int _glslStd450FMax;

const int _glslStd450FClamp;

const int _glslStd450FMix;

const int _glslStd450Step;

const int _glslStd450SmoothStep;

const int _glslStd450Length;

const int _glslStd450Distance;

const int _glslStd450Cross;

const int _glslStd450Normalize;

const int _glslStd450FaceForward;

const int _glslStd450Reflect;

const Map<int, String> _glslStd450OpNames;

const Map<int, int> _glslStd450OpArgc;


enum _Operator{
    addition,
    subtraction,
    division,
    multiplication,
    modulo,
    negation,
    equality,
    inequality,
    and,
    or,
    not,
    lessThan,
    greaterThan,
    lessThanEqual,
    greaterThanEqual,
} // end _Operator
const Set<_Operator> _compoundAssignmentOperators;

const Map<_Operator, String> _operatorStrings;

String _operatorString(_Operator op);

bool _isCompoundAssignment(_Operator op);


#endif