#include "spirv.hpp"
String TranspileExceptionCls::toString() {
    return __s("$op: $message");
}

TranspileResult transpile(ByteBuffer spirv, TargetLanguage target) {
    _Transpiler t = make<_TranspilerCls>(spirv->asUint32List(), target);
    t->transpile();
    return TranspileResultCls->_(t->src->toString(), t->uniformFloatCount, t->samplerCount, target);
}
