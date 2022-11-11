#ifndef DART_SPIRV_SPIRV
#define DART_SPIRV_SPIRV
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/convert/convert.hpp>
#include <dart/math/math.hpp>
#include <dart/typed_data/typed_data.hpp>


enum TargetLanguage{
    sksl,
    glslES,
    glslES300,
} // end TargetLanguage

class TranspileResultCls : public ObjectCls {
public:
    String src;

    TargetLanguage language;

    int uniformFloatCount;

    int samplerCount;


private:

    virtual void  _(String src, int uniformFloatCount, int samplerCount, TargetLanguage language);
};
using TranspileResult = std::shared_ptr<TranspileResultCls>;

class TranspileExceptionCls : public ObjectCls {
public:
    int op;

    String message;


    virtual String toString();

private:

    virtual void  _(int op, String message);
};
using TranspileException = std::shared_ptr<TranspileExceptionCls>;
TranspileResult transpile(ByteBuffer spirv, TargetLanguage target);


// Parts
#include "src/constants.hpp"
#include "src/function.hpp"
#include "src/instructions.hpp"
#include "src/transpiler.hpp"
#include "src/types.hpp"

#endif