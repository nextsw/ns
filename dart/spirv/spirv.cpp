#include "spirv.hpp"
String TranspileException::toString() {
    return "$op: $message";
}

TranspileResult transpile(ByteBuffer spirv, TargetLanguage target) {
    _Transpiler t = _Transpiler(spirv.asUint32List(), target);
    t.transpile();
    return TranspileResult._(t.src.toString(), t.uniformFloatCount, t.samplerCount, target);
}
