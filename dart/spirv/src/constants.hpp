#ifndef DART_SPIRV_SRC_CONSTANTS
#define DART_SPIRV_SRC_CONSTANTS
#include <base.hpp>

#include <dart/core/core.hpp>

int _magicNumber;

int _originLowerLeft;

int _addressingModelLogical;

int _memoryModelGLSL450;

int _capabilityMatrix;

int _capabilityShader;

int _storageClassUniformConstant;

int _storageClassInput;

int _storageClassOutput;

int _storageClassFunction;

int _decorationBuiltIn;

int _decorationLocation;

int _builtinFragCoord;

int _dim2D;

int _opSource;

int _opSourceExtension;

int _opName;

int _opMemberName;

int _opString;

int _opLine;

int _opExtInstImport;

int _opExtInst;

int _opMemoryModel;

int _opEntryPoint;

int _opExecutionMode;

int _opCapability;

int _opTypeVoid;

int _opTypeBool;

int _opTypeInt;

int _opTypeFloat;

int _opTypeVector;

int _opTypeMatrix;

int _opTypeImage;

int _opTypeSampledImage;

int _opTypePointer;

int _opTypeFunction;

int _opConstantTrue;

int _opConstantFalse;

int _opConstant;

int _opConstantComposite;

int _opFunction;

int _opFunctionParameter;

int _opFunctionEnd;

int _opFunctionCall;

int _opVariable;

int _opLoad;

int _opStore;

int _opAccessChain;

int _opDecorate;

int _opVectorShuffle;

int _opCompositeConstruct;

int _opCompositeExtract;

int _opImageSampleImplicitLod;

int _opImageQuerySize;

int _opConvertFToS;

int _opConvertSToF;

int _opFNegate;

int _opFAdd;

int _opFSub;

int _opFMul;

int _opFDiv;

int _opFMod;

int _opVectorTimesScalar;

int _opMatrixTimesScalar;

int _opVectorTimesMatrix;

int _opMatrixTimesVector;

int _opMatrixTimesMatrix;

int _opDot;

int _opFOrdEqual;

int _opFUnordNotEqual;

int _opFOrdLessThan;

int _opFOrdGreaterThan;

int _opFOrdLessThanEqual;

int _opFOrdGreaterThanEqual;

int _opLogicalEqual;

int _opLogicalNotEqual;

int _opLogicalOr;

int _opLogicalAnd;

int _opLogicalNot;

int _opSelect;

int _opLoopMerge;

int _opSelectionMerge;

int _opLabel;

int _opBranch;

int _opBranchConditional;

int _opReturn;

int _opReturnValue;

String _glslStd450;

int _glslStd450FAbs;

int _glslStd450FSign;

int _glslStd450Floor;

int _glslStd450Ceil;

int _glslStd450Fract;

int _glslStd450Radians;

int _glslStd450Degrees;

int _glslStd450Sin;

int _glslStd450Cos;

int _glslStd450Tan;

int _glslStd450Asin;

int _glslStd450Acos;

int _glslStd450Atan;

int _glslStd450Atan2;

int _glslStd450Pow;

int _glslStd450Exp;

int _glslStd450Log;

int _glslStd450Exp2;

int _glslStd450Log2;

int _glslStd450Sqrt;

int _glslStd450InverseSqrt;

int _glslStd450FMin;

int _glslStd450FMax;

int _glslStd450FClamp;

int _glslStd450FMix;

int _glslStd450Step;

int _glslStd450SmoothStep;

int _glslStd450Length;

int _glslStd450Distance;

int _glslStd450Cross;

int _glslStd450Normalize;

int _glslStd450FaceForward;

int _glslStd450Reflect;

Map<int, String> _glslStd450OpNames;

Map<int, int> _glslStd450OpArgc;


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
Set<_Operator> _compoundAssignmentOperators;

Map<_Operator, String> _operatorStrings;

String _operatorString(_Operator op);

bool _isCompoundAssignment(_Operator op);



#endif