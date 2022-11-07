#ifndef ASSERTIONS_H
#define ASSERTIONS_H
#include <memory>
#include "basic_types.hpp"
#include "diagnostics.hpp"
#include "stack_frame.hpp"

#include <meta/meta.hpp>
#include "basic_types.hpp"
#include "constants.hpp"
#include "diagnostics.hpp"
#include "print.hpp"
#include "stack_frame.hpp"



class PartialStackFrame {
public:
    static const PartialStackFrame asynchronousSuspension;

    Pattern package;

    String className;

    String method;


     PartialStackFrame(String className, String method, Pattern package);

    bool matches(StackFrame stackFrame);

private:

};

class StackFilter {
public:

     StackFilter();

    void filter(List<String> reasons, List<StackFrame> stackFrames);

private:

};

class RepetitiveStackFrameFilter : StackFilter {
public:
    List<PartialStackFrame> frames;

    String replacement;


     RepetitiveStackFrameFilter(List<PartialStackFrame> frames, String replacement);

    int numFrames();

    void filter(List<String> reasons, List<StackFrame> stackFrames);

private:

    List<String> _replacements();

    bool _matchesFrames(List<StackFrame> stackFrames);

};

class _ErrorDiagnostic : DiagnosticsProperty<List<Object>> {
public:

    List<Object> value();

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

     _ErrorDiagnostic(DiagnosticLevel level, String message, DiagnosticsTreeStyle style);

    void  _fromParts(DiagnosticLevel level, List<Object> messageParts, DiagnosticsTreeStyle style);

};

class ErrorDescription : _ErrorDiagnostic {
public:

     ErrorDescription(Unknown);

private:

    void  _fromParts(Unknown);

};

class ErrorSummary : _ErrorDiagnostic {
public:

     ErrorSummary(Unknown);

private:

    void  _fromParts(Unknown);

};

class ErrorHint : _ErrorDiagnostic {
public:

     ErrorHint(Unknown);

private:

    void  _fromParts(Unknown);

};

class ErrorSpacer : DiagnosticsProperty<void> {
public:

     ErrorSpacer();

private:

};

class FlutterErrorDetails {
public:
    static List<DiagnosticPropertiesTransformer> propertiesTransformers;

    Object exception;

    StackTrace stack;

    String library;

    DiagnosticsNode context;

    IterableFilter<String> stackFilter;

    InformationCollector informationCollector;

    bool silent;


     FlutterErrorDetails(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter);

    FlutterErrorDetails copyWith(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter);

    String exceptionAsString();

    DiagnosticsNode summary();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String toStringShort();

    String toString(DiagnosticLevel minLevel);

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

private:

    Diagnosticable _exceptionToDiagnosticable();

};

class FlutterError : Error {
public:
    List<DiagnosticsNode> diagnostics;

    static FlutterExceptionHandler onError;

    static StackTraceDemangler demangleStackTrace;

    static FlutterExceptionHandler presentError;

    static const int wrapWidth;


     FlutterError(String message);

    void  fromParts(List<DiagnosticsNode> diagnostics);

    String message();

    static void resetErrorCount();

    static void dumpErrorToConsole(FlutterErrorDetails details, bool forceReport);

    static void addDefaultStackFilter(StackFilter filter);

    static Iterable<String> defaultStackFilter(Iterable<String> frames);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String toStringShort();

    String toString(DiagnosticLevel minLevel);

    static void reportError(FlutterErrorDetails details);

private:
    static int _errorCount;

    static List<StackFilter> _stackFilters;


    static StackTrace _defaultStackTraceDemangler(StackTrace stackTrace);

};
void debugPrintStack(String label, int maxFrames, StackTrace stackTrace);


class DiagnosticsStackTrace : DiagnosticsBlock {
public:

     DiagnosticsStackTrace(String name, Unknown, StackTrace stack, IterableFilter<String> stackFilter);

    void  singleFrame(String frame, String name, Unknown);

    bool allowTruncate();

private:

    static List<DiagnosticsNode> _applyStackFilter(StackTrace stack, IterableFilter<String> stackFilter);

    static DiagnosticsNode _createStackFrame(String frame);

};

class _FlutterErrorDetailsNode : DiagnosticableNode<FlutterErrorDetails> {
public:

    DiagnosticPropertiesBuilder builder();

private:

     _FlutterErrorDetailsNode(Unknown, Unknown, Unknown);

};

#endif