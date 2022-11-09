#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_STACK_FRAME
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_STACK_FRAME
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/meta/meta.hpp>
#include "constants.hpp"
#include "object.hpp"


class StackFrameCls : public ObjectCls {
public:
    static StackFrame asynchronousSuspension;

    static StackFrame stackOverFlowElision;

    String source;

    int number;

    String packageScheme;

    String package;

    String packagePath;

    int line;

    int column;

    String className;

    String method;

    bool isConstructor;


     StackFrameCls(String className, int column, bool isConstructor, int line, String method, int number, String package, String packagePath, String packageScheme, String source);

    static List<StackFrame> fromStackTrace(StackTrace stack);

    static List<StackFrame> fromStackString(String stack);

    static StackFrame fromStackTraceLine(String line);

    virtual int hashCode();

    virtual bool operator==(Object other);

    virtual String toString();

private:
    static RegExp _webNonDebugFramePattern;


    static StackFrame _parseWebFrame(String line);

    static StackFrame _parseWebDebugFrame(String line);

    static StackFrame _parseWebNonDebugFrame(String line);

};
using StackFrame = std::shared_ptr<StackFrameCls>;


#endif