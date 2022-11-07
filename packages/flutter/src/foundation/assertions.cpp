#include "assertions.hpp"
PartialStackFrame::PartialStackFrame(String className, String method, Pattern package) {
    {
        assert(className != nullptr);
        assert(method != nullptr);
        assert(package != nullptr);
    }
}

bool PartialStackFrame::matches(StackFrame stackFrame) {
    String stackFramePackage = "${stackFrame.packageScheme}:${stackFrame.package}/${stackFrame.packagePath}";
    if (kIsWeb) {
        return package.allMatches(stackFramePackage).isNotEmpty && stackFrame.method == (method.startsWith("_")? "[$method]" : method);
    }
    return package.allMatches(stackFramePackage).isNotEmpty && stackFrame.method == method && stackFrame.className == className;
}

RepetitiveStackFrameFilter::RepetitiveStackFrameFilter(List<PartialStackFrame> frames, String replacement) {
    {
        assert(frames != nullptr);
        assert(replacement != nullptr);
    }
}

int RepetitiveStackFrameFilter::numFrames() {
    return frames.length;
}

void RepetitiveStackFrameFilter::filter(List<String> reasons, List<StackFrame> stackFrames) {
    for (;  < stackFrames.length - numFrames; index = 1) {
        if (_matchesFrames(stackFrames.skip(index).take(numFrames).toList())) {
            reasons.setRange(index, index + numFrames, _replacements);
            index = numFrames - 1;
        }
    }
}

List<String> RepetitiveStackFrameFilter::_replacements() {
    return <String>filled(numFrames, replacement);
}

bool RepetitiveStackFrameFilter::_matchesFrames(List<StackFrame> stackFrames) {
    if (stackFrames.length < numFrames) {
        return false;
    }
    for (;  < stackFrames.length; index++) {
        if (!frames[index].matches(stackFrames[index])) {
            return false;
        }
    }
    return true;
}

List<Object> _ErrorDiagnostic::value() {
    return super.value!;
}

String _ErrorDiagnostic::valueToString(TextTreeConfiguration parentConfiguration) {
    return value.join();
}

_ErrorDiagnostic::_ErrorDiagnostic(DiagnosticLevel level, String message, DiagnosticsTreeStyle style) {
    {
        assert(message != nullptr);
        super(nullptr, false, false, nullptr, style, level);
    }
}

void _ErrorDiagnostic::_fromParts(DiagnosticLevel level, List<Object> messageParts, DiagnosticsTreeStyle style)

ErrorDescription::ErrorDescription(Unknown) {
    {
        super(DiagnosticLevel.info);
    }
}

void ErrorDescription::_fromParts(Unknown)

ErrorSummary::ErrorSummary(Unknown) {
    {
        super(DiagnosticLevel.summary);
    }
}

void ErrorSummary::_fromParts(Unknown)

ErrorHint::ErrorHint(Unknown) {
    {
        super(DiagnosticLevel.hint);
    }
}

void ErrorHint::_fromParts(Unknown)

ErrorSpacer::ErrorSpacer() {
    {
        super("", nullptr"", false);
    }
}

FlutterErrorDetails::FlutterErrorDetails(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter) {
    {
        assert(exception != nullptr);
    }
}

FlutterErrorDetails FlutterErrorDetails::copyWith(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter) {
    return FlutterErrorDetails(context ?? this.context, exception ?? this.exception, informationCollector ?? this.informationCollector, library ?? this.library, silent ?? this.silent, stack ?? this.stack, stackFilter ?? this.stackFilter);
}

String FlutterErrorDetails::exceptionAsString() {
    String longMessage;
    if (exception is AssertionError) {
        Object message = (().message;
        String fullMessage = exception.toString();
        if (message is String && message != fullMessage) {
            if (fullMessage.length > message.length) {
                int position = fullMessage.lastIndexOf(message);
                if (position == fullMessage.length - message.length && position > 2 && fullMessage.substring(position - 2, position) == ": ") {
                    String body = fullMessage.substring(0, position - 2);
                    int splitPoint = body.indexOf(" Failed assertion:");
                    if (splitPoint >= 0) {
                        body = "${body.substring(0, splitPoint)}\n${body.substring(splitPoint + 1)}";
                    }
                    longMessage = "${message.trimRight()}\n$body";
                }
            }
        }
        longMessage = fullMessage;
    } else     {
        if (exception is String) {
        longMessage = (;
    } else     {
        if (exception is Error || exception is Exception) {
        longMessage = exception.toString();
    } else {
        longMessage = "  $exception";
    }
;
    };
    }    longMessage = longMessage.trimRight();
    if (longMessage.isEmpty) {
        longMessage = "  <no message available>";
    }
    return longMessage;
}

DiagnosticsNode FlutterErrorDetails::summary() {
    ;
    if (kReleaseMode) {
        return DiagnosticsNode.message(formatException());
    }
    Diagnosticable diagnosticable = _exceptionToDiagnosticable();
    DiagnosticsNode summary;
    if (diagnosticable != nullptr) {
        DiagnosticPropertiesBuilder builder = DiagnosticPropertiesBuilder();
        debugFillProperties(builder);
        summary = builder.properties.<DiagnosticsNode>cast().firstWhere();
    }
    return summary ?? ErrorSummary(formatException());
}

void FlutterErrorDetails::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    DiagnosticsNode verb = ErrorDescription("thrown${ context != null ? ErrorDescription(" $context") : ""}");
    Diagnosticable diagnosticable = _exceptionToDiagnosticable();
    if (exception is NullThrownError) {
        properties.add(ErrorDescription("The null value was $verb."));
    } else     {
        if (exception is num) {
        properties.add(ErrorDescription("The number $exception was $verb."));
    } else {
        DiagnosticsNode errorName;
        if (exception is AssertionError) {
            errorName = ErrorDescription("assertion");
        } else         {
            if (exception is String) {
            errorName = ErrorDescription("message");
        } else         {
            if (exception is Error || exception is Exception) {
            errorName = ErrorDescription("${exception.runtimeType}");
        } else {
            errorName = ErrorDescription("${exception.runtimeType} object");
        }
;
        };
        }        properties.add(ErrorDescription("The following $errorName was $verb:"));
        if (diagnosticable != nullptr) {
            diagnosticable.debugFillProperties(properties);
        } else {
            String prefix = "${exception.runtimeType}: ";
            String message = exceptionAsString();
            if (message.startsWith(prefix)) {
                message = message.substring(prefix.length);
            }
            properties.add(ErrorSummary(message));
        }
    }
;
    }    if (stack != nullptr) {
        if (exception is AssertionError && diagnosticable == nullptr) {
            List<StackFrame> stackFrames = StackFrame.fromStackTrace(FlutterError.demangleStackTrace(stack!)).skipWhile().toList();
            bool ourFault = stackFrames.length >= 2 && stackFrames[0].package == "flutter" && stackFrames[1].package == "flutter";
            if (ourFault) {
                properties.add(ErrorSpacer());
                properties.add(ErrorHint("Either the assertion indicates an error in the framework itself, or we should provide substantially more information in this error message to help you determine and fix the underlying cause.\nIn either case, please report this assertion by filing a bug on GitHub:\n  https://github.com/flutter/flutter/issues/new?template=2_bug.md"));
            }
        }
        properties.add(ErrorSpacer());
        properties.add(DiagnosticsStackTrace("When the exception was thrown, this was the stack", stackstackFilter));
    }
    if (informationCollector != nullptr) {
        properties.add(ErrorSpacer());
        informationCollector!().forEach(properties.add);
    }
}

String FlutterErrorDetails::toStringShort() {
    return library != nullptr? "Exception caught by $library" : "Exception caught";
}

String FlutterErrorDetails::toString(DiagnosticLevel minLevel) {
    return toDiagnosticsNode(DiagnosticsTreeStyle.error).toStringDeep(minLevel);
}

DiagnosticsNode FlutterErrorDetails::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return _FlutterErrorDetailsNode(name, this, style);
}

Diagnosticable FlutterErrorDetails::_exceptionToDiagnosticable() {
    Object exception = this.exception;
    if (exception is FlutterError) {
        return exception;
    }
    if (exception is AssertionError && exception.message is FlutterError) {
        return (;
    }
    return nullptr;
}

FlutterError::FlutterError(String message) {
    {
        List<String> lines = message.split("\n");
        return FlutterError.fromParts();
    }
}

void FlutterError::fromParts(List<DiagnosticsNode> diagnostics) {
    assert(diagnostics.first.level == DiagnosticLevel.summary, FlutterError.fromParts());
    assert(());
}

String FlutterError::message() {
    return toString();
}

void FlutterError::resetErrorCount() {
    _errorCount = 0;
}

void FlutterError::dumpErrorToConsole(FlutterErrorDetails details, bool forceReport) {
    assert(details != nullptr);
    assert(details.exception != nullptr);
    bool isInDebugMode = false;
    assert(());
    bool reportError = isInDebugMode || details.silent != true;
    if (!reportError && !forceReport) {
        return;
    }
    if (_errorCount == 0 || forceReport) {
        if (isInDebugMode) {
            debugPrint(TextTreeRenderer(wrapWidth, 5).render(details.toDiagnosticsNode(DiagnosticsTreeStyle.error)).trimRight());
        } else {
            debugPrintStack(details.stack, details.exception.toString(), 100);
        }
    } else {
        debugPrint("Another exception was thrown: ${details.summary}");
    }
    _errorCount = 1;
}

void FlutterError::addDefaultStackFilter(StackFilter filter) {
    _stackFilters.add(filter);
}

Iterable<String> FlutterError::defaultStackFilter(Iterable<String> frames) {
    Map<String, int> removedPackagesAndClasses = ;
    int skipped = 0;
    List<StackFrame> parsedFrames = StackFrame.fromStackString(frames.join("\n"));
    for (;  < parsedFrames.length; index = 1) {
        StackFrame frame = parsedFrames[index];
        String className = "class ${frame.className}";
        String package = "${frame.packageScheme}:${frame.package}";
        if (removedPackagesAndClasses.containsKey(className)) {
            skipped = 1;
            removedPackagesAndClasses.update(className, );
            parsedFrames.removeAt(index);
            index = 1;
        } else         {
            if (removedPackagesAndClasses.containsKey(package)) {
            skipped = 1;
            removedPackagesAndClasses.update(package, );
            parsedFrames.removeAt(index);
            index = 1;
        }
;
        }    }
    List<String> reasons = <String>filled(parsedFrames.length, nullptr);
    for (StackFilter filter : _stackFilters) {
        filter.filter(parsedFrames, reasons);
    }
    List<String> result = ;
    for (;  < parsedFrames.length; index = 1) {
        int start = index;
        while ( < reasons.length - 1 && reasons[index] != nullptr && reasons[index + 1] == reasons[index]) {
            index++;
        }
        String suffix = "";
        if (reasons[index] != nullptr) {
            if (index != start) {
                suffix = " (${index - start + 2} frames)";
            } else {
                suffix = " (1 frame)";
            }
        }
        String resultLine = "${reasons[index] ?? parsedFrames[index].source}$suffix";
        result.add(resultLine);
    }
    List<String> where = ;
    if (skipped == 1) {
        result.add("(elided one frame from ${where.single})");
    } else     {
        if (skipped > 1) {
        if (where.length > 1) {
            where[where.length - 1] = "and ${where.last}";
        }
        if (where.length > 2) {
            result.add("(elided $skipped frames from ${where.join(", ")})");
        } else {
            result.add("(elided $skipped frames from ${where.join(" ")})");
        }
    }
;
    }    return result;
}

void FlutterError::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    diagnostics.forEach(properties.add);
}

String FlutterError::toStringShort() {
    return "FlutterError";
}

String FlutterError::toString(DiagnosticLevel minLevel) {
    if (kReleaseMode) {
        Iterable<_ErrorDiagnostic> errors = diagnostics.<_ErrorDiagnostic>whereType();
        return errors.isNotEmpty? errors.first.valueToString() : toStringShort();
    }
    TextTreeRenderer renderer = TextTreeRenderer(4000000000);
    return diagnostics.map().join("\n");
}

void FlutterError::reportError(FlutterErrorDetails details) {
    assert(details != nullptr);
    assert(details.exception != nullptr);
    onError?.call(details);
}

StackTrace FlutterError::_defaultStackTraceDemangler(StackTrace stackTrace) {
    return stackTrace;
}

void debugPrintStack(String label, int maxFrames, StackTrace stackTrace) {
    if (label != nullptr) {
        debugPrint(label);
    }
    if (stackTrace == nullptr) {
        stackTrace = StackTrace.current;
    } else {
        stackTrace = FlutterError.demangleStackTrace(stackTrace);
    }
    Iterable<String> lines = stackTrace.toString().trimRight().split("\n");
    if (kIsWeb && lines.isNotEmpty) {
        lines = lines.skipWhile();
    }
    if (maxFrames != nullptr) {
        lines = lines.take(maxFrames);
    }
    debugPrint(FlutterError.defaultStackFilter(lines).join("\n"));
}

DiagnosticsStackTrace::DiagnosticsStackTrace(String name, Unknown, StackTrace stack, IterableFilter<String> stackFilter) {
    {
        super(name, stack, _applyStackFilter(stack, stackFilter), DiagnosticsTreeStyle.flat, true);
    }
}

void DiagnosticsStackTrace::singleFrame(String frame, String name, Unknown)

bool DiagnosticsStackTrace::allowTruncate() {
    return false;
}

List<DiagnosticsNode> DiagnosticsStackTrace::_applyStackFilter(StackTrace stack, IterableFilter<String> stackFilter) {
    if (stack == nullptr) {
        return ;
    }
    IterableFilter<String> filter = stackFilter ?? FlutterError.defaultStackFilter;
    Iterable<String> frames = filter("${FlutterError.demangleStackTrace(stack)}".trimRight().split("\n"));
    return frames.<DiagnosticsNode>map(_createStackFrame).toList();
}

DiagnosticsNode DiagnosticsStackTrace::_createStackFrame(String frame) {
    return DiagnosticsNode.message(framefalse);
}

DiagnosticPropertiesBuilder _FlutterErrorDetailsNode::builder() {
    DiagnosticPropertiesBuilder builder = super.builder;
    if (builder == nullptr) {
        return nullptr;
    }
    Iterable<DiagnosticsNode> properties = builder.properties;
    for (DiagnosticPropertiesTransformer transformer : FlutterErrorDetails.propertiesTransformers) {
        properties = transformer(properties);
    }
    return DiagnosticPropertiesBuilder.fromProperties(properties.toList());
}
