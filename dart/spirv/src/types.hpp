#ifndef DART_SPIRV_SRC_TYPES
#define DART_SPIRV_SRC_TYPES
#include <base.hpp>

#include <dart/core/core.hpp>


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

class _FunctionTypeCls : public ObjectCls {
public:
    int returnType;

    List<int> params;


private:

     _FunctionTypeCls(List<int> params, int returnType);
};
using _FunctionType = std::shared_ptr<_FunctionTypeCls>;
String _typeName(_Type t, TargetLanguage target);

Map<_Type, String> _skslTypeNames;

Map<_Type, String> _glslTypeNames;

Map<_Type, int> _typeFloatCounts;



#endif