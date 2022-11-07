#include "instructions.hpp"
_BlockContext _BlockContext::child(int continueBlock, int loopHeader, int loopMerge, int merge) {
    return _BlockContext(out, indent + 1, merge ?? this.merge, continueBlock ?? this.continueBlock, loopHeader ?? this.loopHeader, loopMerge ?? this.loopMerge);
}

void _BlockContext::writeIndent() {
    out.write("  " * indent);
}

_Transpiler _Block::transpiler() {
    return function.transpiler;
}

bool _Block::hasSelectionStructure() {
    return mergeBlock != 0 && continueBlock == 0;
}

bool _Block::hasLoopStructure() {
    return continueBlock != 0;
}

void _Block::write(_BlockContext ctx) {
    for (_Instruction inst : instructions) {
        if (inst is _Store) {
            _Variable v = function.variables[inst.pointer];
            if (v != nullptr && inst.shouldDeclare && v.liftToBlock != 0) {
                function.block(v.liftToBlock).loopInitializer = inst;
                continue;
            }
        }
        if (!inst.isResult) {
            ctx.writeIndent();
            inst.write(transpiler, ctx.out);
            ctx.out.writeln(";");
        } else         {
            if (inst.refCount > 1) {
            ctx.writeIndent();
            String typeString = transpiler.resolveType(inst.type);
            String nameString = transpiler.resolveName(inst.id);
            ctx.out.write("$typeString $nameString = ");
            inst.write(transpiler, ctx.out);
            ctx.out.writeln(";");
        }
;
        }    }
    if (hasSelectionStructure) {
        _writeSelectionStructure(ctx);
    } else     {
        if (hasLoopStructure) {
        _writeLoopStructure(ctx);
    }
;
    }    if (mergeBlock != 0) {
        function.block(mergeBlock).write(ctx);
    } else     {
        if (branch != 0) {
        if (branch == ctx.merge) {
            return;
        }
        if (branch == ctx.continueBlock) {
            if (ctx.merge != ctx.loopMerge) {
                ctx.writeIndent();
                ctx.out.writeln("continue;");
            }
            return;
        }
        if (branch == ctx.loopMerge) {
            ctx.writeIndent();
            ctx.out.writeln("break;");
        }
        function.block(branch).write(ctx);
    }
;
    }}

void _Block::_add(_Instruction i) {
    instructions.add(i);
}

void _Block::_writeContinue(_BlockContext ctx) {
    List<_CompoundAssignment> assignments = instructions.<_CompoundAssignment>whereType().toList();
    if (assignments.isEmpty) {
        ;
    }
    if (assignments.length > 1) {
        ;
    }
    assignments[0].write(transpiler, ctx.out);
}

void _Block::_preprocess() {
    if (scanned) {
        return;
    }
    scanned = true;
    if (hasLoopStructure) {
        int conditionId = condition;
        if (condition == 0) {
            _Block branchBlock = function.block(branch);
            if (!branchBlock._isSimple() || branchBlock.condition == 0) {
                ;
            }
            conditionId = branchBlock.condition;
        }
        List<_Variable> deps = function.variableDeps(conditionId);
        if (deps.length != 1) {
            ;
        }
        deps[0].liftToBlock = id;
    }
    if (branch != 0) {
        function.block(branch)._preprocess();
    }
    if (condition != 0) {
        if (truthyBlock != 0) {
            function.block(truthyBlock)._preprocess();
        }
        if (falseyBlock != 0) {
            function.block(falseyBlock)._preprocess();
        }
    }
    if (mergeBlock != 0) {
        function.block(mergeBlock)._preprocess();
    }
}

void _Block::_writeSelectionStructure(_BlockContext ctx) {
    _BlockContext childCtx = ctx.child(mergeBlock);
    ctx.writeIndent();
    String conditionString = transpiler.resolveResult(condition);
    ctx.out.writeln("if ($conditionString) {");
    function.block(truthyBlock).write(childCtx);
    if (falseyBlock != 0 && falseyBlock != mergeBlock) {
        ctx.writeIndent();
        ctx.out.writeln("} else {");
        function.block(falseyBlock).write(childCtx);
    }
    ctx.writeIndent();
    ctx.out.writeln("}");
}

void _Block::_writeLoopStructure(_BlockContext ctx) {
    _BlockContext childCtx = ctx.child(mergeBlock, continueBlock, id, mergeBlock);
    String conditionString;
    int loopBody = 0;
    if (condition != 0) {
        conditionString = transpiler.resolveResult(condition);
        if (truthyBlock == mergeBlock) {
            conditionString = "!" + conditionString;
            loopBody = falseyBlock;
        } else         {
            if (falseyBlock == mergeBlock) {
            loopBody = truthyBlock;
        }
;
        }    } else {
        _Block branchBlock = function.block(branch);
        if (!branchBlock._isSimple() || branchBlock.condition == 0) {
            ;
        }
        conditionString = transpiler.resolveResult(branchBlock.condition);
        if (branchBlock.truthyBlock == mergeBlock) {
            conditionString = "!" + conditionString;
            loopBody = branchBlock.falseyBlock;
        } else         {
            if (branchBlock.falseyBlock == mergeBlock) {
            loopBody = branchBlock.truthyBlock;
        }
;
        }    }
    if (loopBody == 0) {
        ;
    }
    ctx.writeIndent();
    ctx.out.write("for(");
    loopInitializer!.write(transpiler, ctx.out);
    ctx.out.write("; ");
    ctx.out.write(conditionString);
    ctx.out.write("; ");
    function.block(continueBlock)._writeContinue(ctx);
    ctx.out.writeln(") {");
    function.block(loopBody).write(childCtx);
    ctx.writeIndent();
    ctx.out.writeln("}");
}

bool _Block::_isSimple() {
    int statements = 0;
    for (_Instruction inst : instructions) {
        if (!inst.isResult) {
            return false;
        }
        if (inst.refCount > 1) {
            statements++;
        }
    }
    return statements == 0;
}

int _Instruction::type() {
    return 0;
}

int _Instruction::id() {
    return 0;
}

bool _Instruction::isResult() {
    return id != 0;
}

List<int> _Instruction::deps() {
    return ;
}

List<int> _FunctionCall::deps() {
    return args;
}

void _FunctionCall::write(StringBuffer out, _Transpiler t) {
    out.write("$function(");
    for (;  < args.length; i++) {
        out.write(t.resolveResult(args[i]));
        if ( < args.length - 1) {
            out.write(", ");
        }
    }
    out.write(")");
}

void _Return::write(StringBuffer out, _Transpiler t) {
    out.write("return");
}

List<int> _Select::deps() {
    return ;
}

void _Select::write(StringBuffer out, _Transpiler t) {
    String aName = t.resolveResult(a);
    String bName = t.resolveResult(b);
    String conditionName = t.resolveResult(condition);
    out.write("$conditionName ? $aName : $bName");
}

void _CompoundAssignment::write(StringBuffer out, _Transpiler t) {
    String pointerName = t.resolveResult(pointer);
    String objectName = t.resolveResult(object);
    String operatorString = _operatorString(op);
    out.write("$pointerName $operatorString= $objectName");
}

List<int> _Store::deps() {
    return ;
}

void _Store::write(StringBuffer out, _Transpiler t) {
    String pointerName = t.resolveResult(pointer);
    if (selfModifyObject > 0) {
        String objectName = t.resolveResult(selfModifyObject);
        out.write("$pointerName $selfModifyOperator $objectName");
    } else {
        String objectName = t.resolveResult(object);
        if (shouldDeclare) {
            String typeString = t.resolveType(declarationType);
            out.write("$typeString ");
        }
        out.write("$pointerName = $objectName");
    }
}

List<int> _AccessChain::deps() {
    return ;
}

void _AccessChain::write(StringBuffer out, _Transpiler t) {
    out.write(t.resolveResult(base));
    for (;  < indices.length; i++) {
        String indexString = t.resolveResult(indices[i]);
        out.write("[$indexString]");
    }
}

List<int> _VectorShuffle::deps() {
    return ;
}

void _VectorShuffle::write(StringBuffer out, _Transpiler t) {
    String typeString = t.resolveType(type);
    String vectorString = t.resolveName(vector);
    out.write("$typeString(");
    for (;  < indices.length; i++) {
        int index = indices[i];
        out.write("$vectorString[$index]");
        if ( < indices.length - 1) {
            out.write(", ");
        }
    }
    out.write(")");
}

List<int> _CompositeConstruct::deps() {
    return components;
}

void _CompositeConstruct::write(StringBuffer out, _Transpiler t) {
    String typeString = t.resolveType(type);
    out.write("$typeString(");
    for (;  < components.length; i++) {
        out.write(t.resolveResult(components[i]));
        if ( < components.length - 1) {
            out.write(", ");
        }
    }
    out.write(")");
}

List<int> _CompositeExtract::deps() {
    return ;
}

void _CompositeExtract::write(StringBuffer out, _Transpiler t) {
    out.write(t.resolveResult(src));
    for (;  < indices.length; i++) {
        out.write("[${indices[i]}]");
    }
}

List<int> _ImageSampleImplicitLod::deps() {
    return ;
}

void _ImageSampleImplicitLod::write(StringBuffer out, _Transpiler t) {
    String sampledImageString = t.resolveName(sampledImage);
    String coordinateString = t.resolveResult(coordinate);
    if (t.target == TargetLanguage.sksl) {
        out.write("$sampledImageString.eval(${sampledImageString}_size * $coordinateString)");
    } else {
        out.write("texture($sampledImageString, $coordinateString)");
    }
}

List<int> _UnaryOperator::deps() {
    return ;
}

void _UnaryOperator::write(StringBuffer out, _Transpiler t) {
    out.write(_operatorString(op));
    out.write(t.resolveResult(operand));
}

List<int> _ReturnValue::deps() {
    return ;
}

void _ReturnValue::write(StringBuffer out, _Transpiler t) {
    String valueString = t.resolveResult(value);
    out.write("return $valueString");
}

List<int> _BinaryOperator::deps() {
    return ;
}

void _BinaryOperator::write(StringBuffer out, _Transpiler t) {
    String aStr = t.resolveResult(a);
    String bStr = t.resolveResult(b);
    String opString = _operatorString(op);
    out.write("$aStr $opString $bStr");
}

List<int> _BuiltinFunction::deps() {
    return args;
}

void _BuiltinFunction::write(StringBuffer out, _Transpiler t) {
    out.write("$function(");
    for (;  < args.length; i++) {
        out.write(t.resolveResult(args[i]));
        if ( < args.length - 1) {
            out.write(", ");
        }
    }
    out.write(")");
}

List<int> _TypeCast::deps() {
    return ;
}

void _TypeCast::write(StringBuffer out, _Transpiler t) {
    String typeString = t.resolveType(type);
    String valueString = t.resolveResult(value);
    out.write("$typeString($valueString)");
}
