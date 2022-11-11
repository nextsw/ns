#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_ASSERTIONS
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_ASSERTIONS
#include <base.hpp>
#include "basic_types.hpp"
#include "diagnostics.hpp"
#include "stack_frame.hpp"

#include <dart/core/core.hpp>
#include <packages/meta/meta.hpp>
#include "basic_types.hpp"
#include "constants.hpp"
#include "diagnostics.hpp"
#include "print.hpp"
#include "stack_frame.hpp"


class PartialStackFrameCls : public ObjectCls {
public:
    static PartialStackFrame asynchronousSuspension;

    Pattern package;

    String className;

    String method;


     PartialStackFrameCls(String className, String method, Pattern package);

    virtual bool matches(StackFrame stackFrame);

private:

};
using PartialStackFrame = std::shared_ptr<PartialStackFrameCls>;

class StackFilterCls : public ObjectCls {
public:

     StackFilterCls();
    virtual void filter(List<StackFrame> stackFrames, List<String> reasons);
private:

};
using StackFilter = std::shared_ptr<StackFilterCls>;

class RepetitiveStackFrameFilterCls : public StackFilterCls {
public:
    List<PartialStackFrame> frames;

    String replacement;


     RepetitiveStackFrameFilterCls(List<PartialStackFrame> frames, String replacement);

    virtual int numFrames();

    virtual void filter(List<StackFrame> stackFrames, List<String> reasons);

private:

    virtual List<String> _replacements();

    virtual bool _matchesFrames(List<StackFrame> stackFrames);

};
using RepetitiveStackFrameFilter = std::shared_ptr<RepetitiveStackFrameFilterCls>;

class _ErrorDiagnosticCls : public DiagnosticsPropertyCls<List<Object>> {
public:

    virtual List<Object> value();

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

     _ErrorDiagnosticCls(String message, DiagnosticLevel level, DiagnosticsTreeStyle style);

    virtual void  _fromParts(List<Object> messageParts, DiagnosticLevel level, DiagnosticsTreeStyle style);

};
using _ErrorDiagnostic = std::shared_ptr<_ErrorDiagnosticCls>;

class ErrorDescriptionCls : public _ErrorDiagnosticCls {
public:

     ErrorDescriptionCls(Unknown message);

private:

    virtual void  _fromParts(Unknown messageParts);

};
using ErrorDescription = std::shared_ptr<ErrorDescriptionCls>;

class ErrorSummaryCls : public _ErrorDiagnosticCls {
public:

     ErrorSummaryCls(Unknown message);

private:

    virtual void  _fromParts(Unknown messageParts);

};
using ErrorSummary = std::shared_ptr<ErrorSummaryCls>;

class ErrorHintCls : public _ErrorDiagnosticCls {
public:

     ErrorHintCls(Unknown message);

private:

    virtual void  _fromParts(Unknown messageParts);

};
using ErrorHint = std::shared_ptr<ErrorHintCls>;

class ErrorSpacerCls : public DiagnosticsPropertyCls<void> {
public:

     ErrorSpacerCls();

private:

};
using ErrorSpacer = std::shared_ptr<ErrorSpacerCls>;

class FlutterErrorDetailsCls : public ObjectCls {
public:
    static List<DiagnosticPropertiesTransformer> propertiesTransformers;

    Object exception;

    StackTrace stack;

    String library;

    DiagnosticsNode context;

    IterableFilter<String> stackFilter;

    InformationCollector informationCollector;

    bool silent;


     FlutterErrorDetailsCls(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter);

    virtual FlutterErrorDetails copyWith(DiagnosticsNode context, Object exception, InformationCollector informationCollector, String library, bool silent, StackTrace stack, IterableFilter<String> stackFilter);

    virtual String exceptionAsString();

    virtual DiagnosticsNode summary();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String toStringShort();

    virtual String toString(DiagnosticLevel minLevel);

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

private:

    virtual Diagnosticable _exceptionToDiagnosticable();

};
using FlutterErrorDetails = std::shared_ptr<FlutterErrorDetailsCls>;

class FlutterErrorCls : public ErrorCls {
public:
    List<DiagnosticsNode> diagnostics;

    static FlutterExceptionHandler onError;

    static StackTraceDemangler demangleStackTrace;

    static FlutterExceptionHandler presentError;

    static int wrapWidth;


     FlutterErrorCls(String message);

    virtual void  fromParts(List<DiagnosticsNode> diagnostics);

    virtual String message();

    static void resetErrorCount();

    static void dumpErrorToConsole(FlutterErrorDetails details, bool forceReport);

    static void addDefaultStackFilter(StackFilter filter);

    static Iterable<String> defaultStackFilter(Iterable<String> frames);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String toStringShort();

    virtual String toString(DiagnosticLevel minLevel);

    static void reportError(FlutterErrorDetails details);

private:
    static int _errorCount;

    static List<StackFilter> _stackFilters;


    static StackTrace _defaultStackTraceDemangler(StackTrace stackTrace);

};
using FlutterError = std::shared_ptr<FlutterErrorCls>;
void debugPrintStack(String label, int maxFrames, StackTrace stackTrace);


class DiagnosticsStackTraceCls : public DiagnosticsBlockCls {
public:

     DiagnosticsStackTraceCls(String name, StackTrace stack, bool showSeparator, IterableFilter<String> stackFilter);

    virtual void  singleFrame(String name, String frame, bool showSeparator);

    virtual bool allowTruncate();

private:

    static List<DiagnosticsNode> _applyStackFilter(StackTrace stack, IterableFilter<String> stackFilter);

    static DiagnosticsNode _createStackFrame(String frame);

};
using DiagnosticsStackTrace = std::shared_ptr<DiagnosticsStackTraceCls>;

class _FlutterErrorDetailsNodeCls : public DiagnosticableNodeCls<FlutterErrorDetails> {
public:

    virtual DiagnosticPropertiesBuilder builder();

private:

     _FlutterErrorDetailsNodeCls(String name, Unknown style, T value);
};
using _FlutterErrorDetailsNode = std::shared_ptr<_FlutterErrorDetailsNodeCls>;


#endif