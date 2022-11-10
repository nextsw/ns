#include "instructions.hpp"
_BlockContext _BlockContextCls::child(int continueBlock, int loopHeader, int loopMerge, int merge) {
    return make<_BlockContextCls>(out, indent + 1, merge or this->merge, continueBlock or this->continueBlock, loopHeader or this->loopHeader, loopMerge or this->loopMerge);
}

void _BlockContextCls::writeIndent() {
    out->write(__s("  ") * indent);
}

_Transpiler _BlockCls::transpiler() {
    return function->transpiler;
}

bool _BlockCls::hasSelectionStructure() {
    return mergeBlock != 0 && continueBlock == 0;
}

bool _BlockCls::hasLoopStructure() {
    return continueBlock != 0;
}

void _BlockCls::write(_BlockContext ctx) {
    for (_Instruction inst : instructions) {
        if (is<_Store>(inst)) {
            _Variable v = function->variables[inst->pointer];
            if (v != nullptr && inst->shouldDeclare && v->liftToBlock != 0) {
                function->block(v->liftToBlock)->loopInitializer = inst;
                continue;
            }
        }
        if (!inst->isResult) {
            ctx->writeIndent();
            inst->write(transpiler(), ctx->out);
            ctx->out->writeln(__s(";"));
        } else         {
            if (inst->refCount > 1) {
            ctx->writeIndent();
            String typeString = transpiler()->resolveType(inst->type);
            String nameString = transpiler()->resolveName(inst->id);
            ctx->out->write(__s("$typeString $nameString = "));
            inst->write(transpiler(), ctx->out);
            ctx->out->writeln(__s(";"));
        }
;
        }    }
    if (hasSelectionStructure()) {
        _writeSelectionStructure(ctx);
    } else     {
        if (hasLoopStructure()) {
        _writeLoopStructure(ctx);
    }
;
    }    if (mergeBlock != 0) {
        function->block(mergeBlock)->write(ctx);
    } else     {
        if (branch != 0) {
        if (branch == ctx->merge) {
            return;
        }
        if (branch == ctx->continueBlock) {
            if (ctx->merge != ctx->loopMerge) {
                ctx->writeIndent();
                ctx->out->writeln(__s("continue;"));
            }
            return;
        }
        if (branch == ctx->loopMerge) {
            ctx->writeIndent();
            ctx->out->writeln(__s("break;"));
        }
        function->block(branch)->write(ctx);
    }
;
    }}

void _BlockCls::_add(_Instruction i) {
    instructions->add(i);
}

void _BlockCls::_writeContinue(_BlockContext ctx) {
    List<_CompoundAssignment> assignments = instructions-><_CompoundAssignment>whereType()->toList();
    if (assignments->isEmpty) {
        ;
    }
    if (assignments->length > 1) {
        ;
    }
    assignments[0]->write(transpiler(), ctx->out);
}

void _BlockCls::_preprocess() {
    if (scanned) {
        return;
    }
    scanned = true;
    if (hasLoopStructure()) {
        int conditionId = condition;
        if (condition == 0) {
            _Block branchBlock = function->block(branch);
            if (!branchBlock->_isSimple() || branchBlock->condition == 0) {
                ;
            }
            conditionId = branchBlock->condition;
        }
        List<_Variable> deps = function->variableDeps(conditionId);
        if (deps->length != 1) {
            ;
        }
        deps[0]->liftToBlock = id;
    }
    if (branch != 0) {
        function->block(branch)->_preprocess();
    }
    if (condition != 0) {
        if (truthyBlock != 0) {
            function->block(truthyBlock)->_preprocess();
        }
        if (falseyBlock != 0) {
            function->block(falseyBlock)->_preprocess();
        }
    }
    if (mergeBlock != 0) {
        function->block(mergeBlock)->_preprocess();
    }
}

void _BlockCls::_writeSelectionStructure(_BlockContext ctx) {
    _BlockContext childCtx = ctx->child(mergeBlock);
    ctx->writeIndent();
    String conditionString = transpiler()->resolveResult(condition);
    ctx->out->writeln(__s("if ($conditionString) {"));
    function->block(truthyBlock)->write(childCtx);
    if (falseyBlock != 0 && falseyBlock != mergeBlock) {
        ctx->writeIndent();
        ctx->out->writeln(__s("} else {"));
        function->block(falseyBlock)->write(childCtx);
    }
    ctx->writeIndent();
    ctx->out->writeln(__s("}"));
}

void _BlockCls::_writeLoopStructure(_BlockContext ctx) {
    _BlockContext childCtx = ctx->child(mergeBlock, continueBlock, id, mergeBlock);
    String conditionString;
    int loopBody = 0;
    if (condition != 0) {
        conditionString = transpiler()->resolveResult(condition);
        if (truthyBlock == mergeBlock) {
            conditionString = __s("!") + conditionString;
            loopBody = falseyBlock;
        } else         {
            if (falseyBlock == mergeBlock) {
            loopBody = truthyBlock;
        }
;
        }    } else {
        _Block branchBlock = function->block(branch);
        if (!branchBlock->_isSimple() || branchBlock->condition == 0) {
            ;
        }
        conditionString = transpiler()->resolveResult(branchBlock->condition);
        if (branchBlock->truthyBlock == mergeBlock) {
            conditionString = __s("!") + conditionString;
            loopBody = branchBlock->falseyBlock;
        } else         {
            if (branchBlock->falseyBlock == mergeBlock) {
            loopBody = branchBlock->truthyBlock;
        }
;
        }    }
    if (loopBody == 0) {
        ;
    }
    ctx->writeIndent();
    ctx->out->write(__s("for("));
    loopInitializer!->write(transpiler(), ctx->out);
    ctx->out->write(__s("; "));
    ctx->out->write(conditionString);
    ctx->out->write(__s("; "));
    function->block(continueBlock)->_writeContinue(ctx);
    ctx->out->writeln(__s(") {"));
    function->block(loopBody)->write(childCtx);
    ctx->writeIndent();
    ctx->out->writeln(__s("}"));
}

bool _BlockCls::_isSimple() {
    int statements = 0;
    for (_Instruction inst : instructions) {
        if (!inst->isResult) {
            return false;
        }
        if (inst->refCount > 1) {
            statements++;
        }
    }
    return statements == 0;
}

int _InstructionCls::type() {
    return 0;
}

int _InstructionCls::id() {
    return 0;
}

bool _InstructionCls::isResult() {
    return id() != 0;
}

List<int> _InstructionCls::deps() {
    return makeList();
}

List<int> _FunctionCallCls::deps() {
    return args;
}

void _FunctionCallCls::write(StringBuffer out, _Transpiler t) {
    out->write(__s("$function("));
    for (;  < args->length(); i++) {
        out->write(t->resolveResult(args[i]));
        if ( < args->length() - 1) {
            out->write(__s(", "));
        }
    }
    out->write(__s(")"));
}

void _ReturnCls::write(StringBuffer out, _Transpiler t) {
    out->write(__s("return"));
}

List<int> _SelectCls::deps() {
    return makeList(ArrayItem, ArrayItem, ArrayItem);
}

void _SelectCls::write(StringBuffer out, _Transpiler t) {
    String aName = t->resolveResult(a);
    String bName = t->resolveResult(b);
    String conditionName = t->resolveResult(condition);
    out->write(__s("$conditionName ? $aName : $bName"));
}

void _CompoundAssignmentCls::write(StringBuffer out, _Transpiler t) {
    String pointerName = t->resolveResult(pointer);
    String objectName = t->resolveResult(object);
    String operatorString = _operatorString(op);
    out->write(__s("$pointerName $operatorString= $objectName"));
}

List<int> _StoreCls::deps() {
    return makeList(ArrayItem, ArrayItem);
}

void _StoreCls::write(StringBuffer out, _Transpiler t) {
    String pointerName = t->resolveResult(pointer);
    if (selfModifyObject > 0) {
        String objectName = t->resolveResult(selfModifyObject);
        out->write(__s("$pointerName $selfModifyOperator $objectName"));
    } else {
        String objectName = t->resolveResult(object);
        if (shouldDeclare) {
            String typeString = t->resolveType(declarationType);
            out->write(__s("$typeString "));
        }
        out->write(__s("$pointerName = $objectName"));
    }
}

List<int> _AccessChainCls::deps() {
    return list1;
}

void _AccessChainCls::write(StringBuffer out, _Transpiler t) {
    List<int> list1 = make<ListCls<>>();list1.add(ArrayItem);for (auto _x1 : indices) {{    list1.add(_x1);}out->write(t->resolveResult(base));
    for (;  < indices->length(); i++) {
        String indexString = t->resolveResult(indices[i]);
        out->write(__s("[$indexString]"));
    }
}

List<int> _VectorShuffleCls::deps() {
    return makeList(ArrayItem);
}

void _VectorShuffleCls::write(StringBuffer out, _Transpiler t) {
    String typeString = t->resolveType(type);
    String vectorString = t->resolveName(vector);
    out->write(__s("$typeString("));
    for (;  < indices->length(); i++) {
        int index = indices[i];
        out->write(__s("$vectorString[$index]"));
        if ( < indices->length() - 1) {
            out->write(__s(", "));
        }
    }
    out->write(__s(")"));
}

List<int> _CompositeConstructCls::deps() {
    return components;
}

void _CompositeConstructCls::write(StringBuffer out, _Transpiler t) {
    String typeString = t->resolveType(type);
    out->write(__s("$typeString("));
    for (;  < components->length(); i++) {
        out->write(t->resolveResult(components[i]));
        if ( < components->length() - 1) {
            out->write(__s(", "));
        }
    }
    out->write(__s(")"));
}

List<int> _CompositeExtractCls::deps() {
    return makeList(ArrayItem);
}

void _CompositeExtractCls::write(StringBuffer out, _Transpiler t) {
    out->write(t->resolveResult(src));
    for (;  < indices->length(); i++) {
        out->write(__s("[${indices[i]}]"));
    }
}

List<int> _ImageSampleImplicitLodCls::deps() {
    return makeList(ArrayItem);
}

void _ImageSampleImplicitLodCls::write(StringBuffer out, _Transpiler t) {
    String sampledImageString = t->resolveName(sampledImage);
    String coordinateString = t->resolveResult(coordinate);
    if (t->target == TargetLanguageCls::sksl) {
        out->write(__s("$sampledImageString.eval(${sampledImageString}_size * $coordinateString)"));
    } else {
        out->write(__s("texture($sampledImageString, $coordinateString)"));
    }
}

List<int> _UnaryOperatorCls::deps() {
    return makeList(ArrayItem);
}

void _UnaryOperatorCls::write(StringBuffer out, _Transpiler t) {
    out->write(_operatorString(op));
    out->write(t->resolveResult(operand));
}

List<int> _ReturnValueCls::deps() {
    return makeList(ArrayItem);
}

void _ReturnValueCls::write(StringBuffer out, _Transpiler t) {
    String valueString = t->resolveResult(value);
    out->write(__s("return $valueString"));
}

List<int> _BinaryOperatorCls::deps() {
    return makeList(ArrayItem, ArrayItem);
}

void _BinaryOperatorCls::write(StringBuffer out, _Transpiler t) {
    String aStr = t->resolveResult(a);
    String bStr = t->resolveResult(b);
    String opString = _operatorString(op);
    out->write(__s("$aStr $opString $bStr"));
}

List<int> _BuiltinFunctionCls::deps() {
    return args;
}

void _BuiltinFunctionCls::write(StringBuffer out, _Transpiler t) {
    out->write(__s("$function("));
    for (;  < args->length(); i++) {
        out->write(t->resolveResult(args[i]));
        if ( < args->length() - 1) {
            out->write(__s(", "));
        }
    }
    out->write(__s(")"));
}

List<int> _TypeCastCls::deps() {
    return makeList(ArrayItem);
}

void _TypeCastCls::write(StringBuffer out, _Transpiler t) {
    String typeString = t->resolveType(type);
    String valueString = t->resolveResult(value);
    out->write(__s("$typeString($valueString)"));
}
