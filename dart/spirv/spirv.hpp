#ifndef SPIRV_H
#define SPIRV_H
#include <memory>

#include <convert/convert.hpp>
#include <math/math.hpp>
#include <typed_data/typed_data.hpp>

// Parts
#include "src/constants.hpp"
#include "src/function.hpp"
#include "src/instructions.hpp"
#include "src/transpiler.hpp"
#include "src/types.hpp"


enum TargetLanguage{
    sksl,
    glslES,
    glslES300,
} // end TargetLanguage

class TranspileResult {
public:
    String src;

    TargetLanguage language;

    int uniformFloatCount;

    int samplerCount;


private:

    void  _(TargetLanguage language, int samplerCount, String src, int uniformFloatCount);

};

class TranspileException {
public:
    int op;

    String message;


    String toString();

private:

    void  _(String message, int op);

};
TranspileResult transpile(ByteBuffer spirv, TargetLanguage target);


#endif