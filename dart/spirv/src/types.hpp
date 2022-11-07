#ifndef TYPES_H
#define TYPES_H
#include <memory>




enum _Type{
    _void,
    _bool,
    _int,
    float,
    float2,
    float3,
    float4,
    float2x2,
    float3x3,
    float4x4,
    sampledImage,
} // end _Type

class _FunctionType {
public:
    int returnType;

    List<int> params;


private:

     _FunctionType(List<int> params, int returnType);

};
String _typeName(_Type t, TargetLanguage target);

const Map<_Type, String> _skslTypeNames;

const Map<_Type, String> _glslTypeNames;

const Map<_Type, int> _typeFloatCounts;


#endif