#include "assertions.hpp"
PartialStackFrameCls::PartialStackFrameCls(String className, String method, Pattern package) {
    {
        assert(className != nullptr);
        assert(method != nullptr);
        assert(package != nullptr);
    }
}

bool PartialStackFrameCls::matches(StackFrame stackFrame) {
    String stackFramePackage = __sf("%s:%s/%s", stackFrame->packageScheme, stackFrame->package, stackFrame->packagePath);
    if (kIsWeb) {
        return package->allMatches(stackFramePackage)->isNotEmpty() && stackFrame->method == (method->startsWith(__s("_"))? __sf("[%s]", method) : method);
    }
    return package->allMatches(stackFramePackage)->isNotEmpty() && stackFrame->method == method && stackFrame->className == className;
}

RepetitiveStackFrameFilterCls::RepetitiveStackFrameFilterCls(List<PartialStackFrame> frames, String replacement) {
    {
        assert(frames != nullptr);
        assert(replacement != nullptr);
    }
}

int RepetitiveStackFrameFilterCls::numFrames() {
    return frames->length();
}

void RepetitiveStackFrameFilterCls::filter(List<StackFrame> stackFrames, List<String> reasons) {
    for (;  < stackFrames->length() - numFrames(); index += 1) {
        if (_matchesFrames(stackFrames->skip(index)->take(numFrames())->toList())) {
            reasons->setRange(index, index + numFrames(), _replacements());
            index += numFrames() - 1;
        }
    }
}

List<String> RepetitiveStackFrameFilterCls::_replacements() {
    return <String>filled(numFrames(), replacement);
}

bool RepetitiveStackFrameFilterCls::_matchesFrames(List<StackFrame> stackFrames) {
    if (stackFrames->length() < numFrames()) {
        return false;
    }
    for (;  < stackFrames->length(); index++) {
        if (!frames[index]->matches(stackFrames[index])) {
            return false;
        }
    }
    return true;
}

List<Object> _ErrorDiagnosticCls::value() {
    return super->value!;
}

String _ErrorDiagnosticCls::valueToString(TextTreeConfiguration parentConfiguration) {
    return value()->join();
}

_ErrorDiagnosticCls::_ErrorDiagnosticCls(String message, DiagnosticLevel level, DiagnosticsTreeStyle style) : DiagnosticsProperty<List<Object>>(nullptr, makeList(ArrayItem)false, false, nullptr, style, level) {
    {
        assert(message != nullptr);
    }
}

void _ErrorDiagnosticCls::_fromParts(List<Object> messageParts, DiagnosticLevel level, DiagnosticsTreeStyle style)

ErrorDescriptionCls::ErrorDescriptionCls(String message) : _ErrorDiagnostic(DiagnosticLevelCls::info) {
}

void ErrorDescriptionCls::_fromParts(String messageParts)

ErrorSummaryCls::ErrorSummaryCls(String message) : _ErrorDiagnostic(DiagnosticLevelCls::summary) {
}

void ErrorSummaryCls::_fromParts(String messageParts)

ErrorHintCls::ErrorHintCls(String message) : _ErrorDiagnostic(DiagnosticLevelCls::hint) {
}

void ErrorHintCls::_fromParts(String messageParts)

ErrorSpacerCls::ErrorSpacerCls() : DiagnosticsProperty<void>(__s(""), nullptr__s(""), false) {
}

FlutterErrorDetailsCls::FlutterErrorDetailsCls(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter) {
    {
        assert(exception != nullptr);
    }
}

FlutterErrorDetails FlutterErrorDetailsCls::copyWith(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter) {
    return make<FlutterErrorDetailsCls>(context | this->context, exception | this->exception, informationCollector | this->informationCollector, library | this->library, silent | this->silent, stack | this->stack, stackFilter | this->stackFilter);
}

String FlutterErrorDetailsCls::exceptionAsString() {
    String longMessage;
    if (is<AssertionError>(exception)) {
        Object message = (as<AssertionError>(as<AssertionErrorCls>(exception)))->message;
        String fullMessage = as<AssertionErrorCls>(exception)->toString();
        if (is<String>(message) && message != fullMessage) {
            if (fullMessage->length() > message->length) {
                int position = fullMessage->lastIndexOf(message);
                if (position == fullMessage->length() - message->length && position > 2 && fullMessage->substring(position - 2, position) == __s(": ")) {
                    String body = fullMessage->substring(0, position - 2);
                    int splitPoint = body->indexOf(__s(" Failed assertion:"));
                    if (splitPoint >= 0) {
                        body = __sf("%s\n%s", body->substring(0, splitPoint), body->substring(splitPoint + 1));
                    }
                    longMessage = __sf("%s\n%s", message->trimRight(), body);
                }
            }
        }
        longMessage |= fullMessage;
    } else {
        if (is<String>(exception)) {
        longMessage = as<String>(as<StringCls>(exception));
    } else {
        if (is<Error>(exception) || is<Exception>(exception)) {
        longMessage = exception->toString();
    } else {
        longMessage = __sf("  %s", exception);
    }
;
    };
    }    longMessage = longMessage->trimRight();
    if (longMessage->isEmpty()) {
        longMessage = __s("  <no message available>");
    }
    return longMessage;
}

DiagnosticsNode FlutterErrorDetailsCls::summary() {
    InlineMethod;
    if (kReleaseMode) {
        return DiagnosticsNodeCls->message(formatException());
    }
    Diagnosticable diagnosticable = _exceptionToDiagnosticable();
    DiagnosticsNode summary;
    if (diagnosticable != nullptr) {
        DiagnosticPropertiesBuilder builder = make<DiagnosticPropertiesBuilderCls>();
        debugFillProperties(builder);
        summary = builder->properties-><DiagnosticsNode>cast()->firstWhere([=] (DiagnosticsNode node) {
            node!->level == DiagnosticLevelCls::summary;
        }, [=] () {
            nullptr;
        });
    }
    return summary | make<ErrorSummaryCls>(formatException());
}

void FlutterErrorDetailsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    DiagnosticsNode verb = make<ErrorDescriptionCls>(__sf("thrown%s", context != nullptr? make<ErrorDescriptionCls>(__sf(" %s", context)) : __s("")));
    Diagnosticable diagnosticable = _exceptionToDiagnosticable();
    if (is<NullThrownError>(exception)) {
        properties->add(make<ErrorDescriptionCls>(__sf("The null value was %s.", verb)));
    } else {
        if (is<num>(exception)) {
        properties->add(make<ErrorDescriptionCls>(__sf("The number %s was %s.", as<numCls>(exception), verb)));
    } else {
        DiagnosticsNode errorName;
        if (is<AssertionError>(exception)) {
            errorName = make<ErrorDescriptionCls>(__s("assertion"));
        } else {
            if (is<String>(exception)) {
            errorName = make<ErrorDescriptionCls>(__s("message"));
        } else {
            if (is<Error>(exception) || is<Exception>(exception)) {
            errorName = make<ErrorDescriptionCls>(__sf("%s", exception->runtimeType()));
        } else {
            errorName = make<ErrorDescriptionCls>(__sf("%s object", exception->runtimeType()));
        }
;
        };
        }        properties->add(make<ErrorDescriptionCls>(__sf("The following %s was %s:", errorName, verb)));
        if (diagnosticable != nullptr) {
            diagnosticable->debugFillProperties(properties);
        } else {
            String prefix = __sf("%s: ", exception->runtimeType());
            String message = exceptionAsString();
            if (message->startsWith(prefix)) {
                message = message->substring(prefix->length());
            }
            properties->add(make<ErrorSummaryCls>(message));
        }
    }
;
    }    if (stack != nullptr) {
        if (is<AssertionError>(exception) && diagnosticable == nullptr) {
            List<StackFrame> stackFrames = StackFrameCls->fromStackTrace(FlutterErrorCls->demangleStackTrace(stack!))->skipWhile([=] (StackFrame frame) {
    frame->packageScheme == __s("dart");
})->toList();
            bool ourFault = stackFrames->length() >= 2 && stackFrames[0]->package == __s("flutter") && stackFrames[1]->package == __s("flutter");
            if (ourFault) {
                properties->add(make<ErrorSpacerCls>());
                properties->add(make<ErrorHintCls>(__s("Either the assertion indicates an error in the framework itself, or we should provide substantially more information in this error message to help you determine and fix the underlying cause.\nIn either case, please report this assertion by filing a bug on GitHub:\n  https://github.com/flutter/flutter/issues/new?template=2_bug.md")));
            }
        }
        properties->add(make<ErrorSpacerCls>());
        properties->add(make<DiagnosticsStackTraceCls>(__s("When the exception was thrown, this was the stack"), stack, stackFilter));
    }
    if (informationCollector != nullptr) {
        properties->add(make<ErrorSpacerCls>());
        informationCollector!()->forEach(properties->add);
    }
}

String FlutterErrorDetailsCls::toStringShort() {
    return library != nullptr? __sf("Exception caught by %s", library) : __s("Exception caught");
}

String FlutterErrorDetailsCls::toString(DiagnosticLevel minLevel) {
    return toDiagnosticsNode(DiagnosticsTreeStyleCls::error)->toStringDeep(minLevel);
}

DiagnosticsNode FlutterErrorDetailsCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<_FlutterErrorDetailsNodeCls>(name, this, style);
}

Diagnosticable FlutterErrorDetailsCls::_exceptionToDiagnosticable() {
    Object exception = this->exception;
    if (is<FlutterError>(exception)) {
        return as<FlutterErrorCls>(exception);
    }
    if (is<AssertionError>(exception) && is<FlutterError>(exception->message)) {
        return as<FlutterError>(exception->message!);
    }
    return nullptr;
}

FlutterErrorCls::FlutterErrorCls(String message) {
    {
        List<String> lines = message->split(__s("\n"));
            List<DiagnosticsNode> list1 = make<ListCls<>>();    list1.add(ArrayItem);    for (auto _x1 : lines->skip(1)-><DiagnosticsNode>map([=] (String line) {                make<ErrorDescriptionCls>(line);            })) {    {        list1.add(_x1);    }return FlutterErrorCls->fromParts(list1);
    }
}

void FlutterErrorCls::fromParts(List<DiagnosticsNode> diagnostics) {
    assert(diagnostics->first->level == DiagnosticLevelCls::summary, FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)));
    assert([=] () {
        Iterable<DiagnosticsNode> summaries = diagnostics->where([=] (DiagnosticsNode node) {
    node->level == DiagnosticLevelCls::summary;
});
        if (summaries->length() > 1) {
            List<DiagnosticsNode> message = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
            int i = 1;
            for (DiagnosticsNode summary : summaries) {
                message->add(<DiagnosticsNode>make<DiagnosticsPropertyCls>(__sf("Summary %s", i), summary, true));
                i += 1;
            }
            message->add(make<ErrorDescriptionCls>(__s("\nThis error should still help you solve your problem, however please also report this malformed error in the framework by filing a bug on GitHub:\n  https://github.com/flutter/flutter/issues/new?template=2_bug.md")));
            throw FlutterErrorCls->fromParts(message);
        }
        return true;
    }());
}

String FlutterErrorCls::message() {
    return toString();
}

void FlutterErrorCls::resetErrorCount() {
    _errorCount = 0;
}

void FlutterErrorCls::dumpErrorToConsole(FlutterErrorDetails details, bool forceReport) {
    assert(details != nullptr);
    assert(details->exception != nullptr);
    bool isInDebugMode = false;
    assert([=] () {
        isInDebugMode = true;
        return true;
    }());
    bool reportError = isInDebugMode || details->silent != true;
    if (!reportError && !forceReport) {
        return;
    }
    if (_errorCount == 0 || forceReport) {
        if (isInDebugMode) {
            debugPrint(make<TextTreeRendererCls>(wrapWidth, 5)->render(details->toDiagnosticsNode(DiagnosticsTreeStyleCls::error))->trimRight());
        } else {
            debugPrintStack(details->stack, details->exception->toString(), 100);
        }
    } else {
        debugPrint(__sf("Another exception was thrown: %s", details->summary()));
    }
    _errorCount += 1;
}

void FlutterErrorCls::addDefaultStackFilter(StackFilter filter) {
    _stackFilters->add(filter);
}

Iterable<String> FlutterErrorCls::defaultStackFilter(Iterable<String> frames) {
    Map<String, int> map1 = make<MapCls<>>();map1.set(__s("dart:async-patch"), 0);map1.set(__s("dart:async"), 0);map1.set(__s("package:stack_trace"), 0);map1.set(__s("class _AssertionError"), 0);map1.set(__s("class _FakeAsync"), 0);map1.set(__s("class _FrameCallbackEntry"), 0);map1.set(__s("class _Timer"), 0);map1.set(__s("class _RawReceivePortImpl"), 0);Map<String, int> removedPackagesAndClasses = list1;
    int skipped = 0;
    List<StackFrame> parsedFrames = StackFrameCls->fromStackString(frames->join(__s("\n")));
    for (;  < parsedFrames->length(); index += 1) {
        StackFrame frame = parsedFrames[index];
        String className = __sf("class %s", frame->className);
        String package = __sf("%s:%s", frame->packageScheme, frame->package);
        if (removedPackagesAndClasses->containsKey(className)) {
            skipped += 1;
            removedPackagesAndClasses->update(className, [=] (int value) {
                value + 1;
            });
            parsedFrames->removeAt(index);
            index -= 1;
        } else {
            if (removedPackagesAndClasses->containsKey(package)) {
            skipped += 1;
            removedPackagesAndClasses->update(package, [=] (int value) {
                value + 1;
            });
            parsedFrames->removeAt(index);
            index -= 1;
        }
;
        }    }
    List<String> reasons = <String>filled(parsedFrames->length(), nullptr);
    for (StackFilter filter : _stackFilters) {
        filter->filter(parsedFrames, reasons);
    }
    List<String> result = makeList();
    for (;  < parsedFrames->length(); index += 1) {
        int start = index;
        while ( < reasons->length() - 1 && reasons[index] != nullptr && reasons[index + 1] == reasons[index]) {
            index++;
        }
        String suffix = __s("");
        if (reasons[index] != nullptr) {
            if (index != start) {
                suffix = __sf(" (%s frames)", index - start + 2);
            } else {
                suffix = __s(" (1 frame)");
            }
        }
        String resultLine = __sf("%s%s", reasons[index] | parsedFrames[index]->source, suffix);
        result->add(resultLine);
    }
    auto _c2 = List<String> list3 = make<ListCls<>>();for (MapEntry<String, int> entry : removedPackagesAndClasses->entries()) {    ;}{    list3.add(ArrayItem);}list3;_c2.sort();List<String> where = _c2;
    if (skipped == 1) {
        result->add(__sf("(elided one frame from %s)", where->single()));
    } else {
        if (skipped > 1) {
        if (where->length() > 1) {
            where[where->length() - 1] = __sf("and %s", where->last);
        }
        if (where->length() > 2) {
            result->add(__sf("(elided %s frames from %s)", skipped, where->join(__s(", "))));
        } else {
            result->add(__sf("(elided %s frames from %s)", skipped, where->join(__s(" "))));
        }
    }
;
    }    return result;
}

void FlutterErrorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    diagnostics->forEach(properties->add);
}

String FlutterErrorCls::toStringShort() {
    return __s("FlutterError");
}

String FlutterErrorCls::toString(DiagnosticLevel minLevel) {
    if (kReleaseMode) {
        Iterable<_ErrorDiagnostic> errors = diagnostics-><_ErrorDiagnostic>whereType();
        return errors->isNotEmpty()? errors->first()->valueToString() : toStringShort();
    }
    TextTreeRenderer renderer = make<TextTreeRendererCls>(4000000000);
    return diagnostics->map([=] (DiagnosticsNode node) {
        renderer->render(node)->trimRight();
    })->join(__s("\n"));
}

void FlutterErrorCls::reportError(FlutterErrorDetails details) {
    assert(details != nullptr);
    assert(details->exception != nullptr);
    onError?->call(details);
}

StackTrace FlutterErrorCls::_defaultStackTraceDemangler(StackTrace stackTrace) {
    return stackTrace;
}

void debugPrintStack(String label, int maxFrames, StackTrace stackTrace) {
    if (label != nullptr) {
        debugPrint(label);
    }
    if (stackTrace == nullptr) {
        stackTrace = StackTraceCls::current;
    } else {
        stackTrace = FlutterErrorCls->demangleStackTrace(stackTrace);
    }
    Iterable<String> lines = stackTrace->toString()->trimRight()->split(__s("\n"));
    if (kIsWeb && lines->isNotEmpty()) {
        lines = lines->skipWhile([=] (String line) {
            return line->contains(__s("StackTrace.current")) || line->contains(__s("dart-sdk/lib/_internal")) || line->contains(__s("dart:sdk_internal"));
        });
    }
    if (maxFrames != nullptr) {
        lines = lines->take(maxFrames);
    }
    debugPrint(FlutterErrorCls->defaultStackFilter(lines)->join(__s("\n")));
}

DiagnosticsStackTraceCls::DiagnosticsStackTraceCls(String name, StackTrace stack, Unknown showSeparator, IterableFilter<String> stackFilter) : DiagnosticsBlock(name, stack, _applyStackFilter(stack, stackFilter), DiagnosticsTreeStyleCls::flat, true) {
}

void DiagnosticsStackTraceCls::singleFrame(String name, String frame, Unknown showSeparator)

bool DiagnosticsStackTraceCls::allowTruncate() {
    return false;
}

List<DiagnosticsNode> DiagnosticsStackTraceCls::_applyStackFilter(StackTrace stack, IterableFilter<String> stackFilter) {
    if (stack == nullptr) {
        return makeList();
    }
    IterableFilter<String> filter = stackFilter | FlutterErrorCls::defaultStackFilter;
    Iterable<String> frames = filter(__sf("%s", FlutterErrorCls->demangleStackTrace(stack))->trimRight()->split(__s("\n")));
    return frames-><DiagnosticsNode>map(_createStackFrame)->toList();
}

DiagnosticsNode DiagnosticsStackTraceCls::_createStackFrame(String frame) {
    return DiagnosticsNodeCls->message(frame, false);
}

DiagnosticPropertiesBuilder _FlutterErrorDetailsNodeCls::builder() {
    DiagnosticPropertiesBuilder builder = super->builder;
    if (builder == nullptr) {
        return nullptr;
    }
    Iterable<DiagnosticsNode> properties = builder->properties;
    for (DiagnosticPropertiesTransformer transformer : FlutterErrorDetailsCls::propertiesTransformers) {
        properties = transformer(properties);
    }
    return DiagnosticPropertiesBuilderCls->fromProperties(properties->toList());
}
