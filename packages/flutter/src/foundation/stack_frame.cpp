#include "stack_frame.hpp"
StackFrame::StackFrame(String className, int column, bool isConstructor, int line, String method, int number, String package, String packagePath, String packageScheme, String source) {
    {
        assert(number != nullptr);
        assert(column != nullptr);
        assert(line != nullptr);
        assert(method != nullptr);
        assert(packageScheme != nullptr);
        assert(package != nullptr);
        assert(packagePath != nullptr);
        assert(className != nullptr);
        assert(isConstructor != nullptr);
        assert(source != nullptr);
    }
}

List<StackFrame> StackFrame::fromStackTrace(StackTrace stack) {
    assert(stack != nullptr);
    return fromStackString(stack.toString());
}

List<StackFrame> StackFrame::fromStackString(String stack) {
    assert(stack != nullptr);
    return stack.trim().split("\n").where().map(fromStackTraceLine).<StackFrame>whereType().toList();
}

StackFrame StackFrame::fromStackTraceLine(String line) {
    assert(line != nullptr);
    if (line == "<asynchronous suspension>") {
        return asynchronousSuspension;
    } else     {
        if (line == "...") {
        return stackOverFlowElision;
    }
;
    }    assert(line != "===== asynchronous gap ===========================", "Got a stack frame from package:stack_trace, where a vm or web frame was expected. This can happen if FlutterError.demangleStackTrace was not set in an environment that propagates non-standard stack traces to the framework, such as during tests.");
    if (!line.startsWith("#")) {
        return _parseWebFrame(line);
    }
    RegExp parser = RegExp("^#(\d+) +(.+) \((.+?):?(\d+){0,1}:?(\d+){0,1}\)$");
    Match match = parser.firstMatch(line);
    assert(match != nullptr, "Expected $line to match $parser.");
    match = match!;
    bool isConstructor = false;
    String className = "";
    String method = match.group(2)!.replaceAll(".<anonymous closure>", "");
    if (method.startsWith("new")) {
        List<String> methodParts = method.split(" ");
        className = methodParts.length > 1? method.split(" ")[1] : "<unknown>";
        method = "";
        if (className.contains(".")) {
            List<String> parts = className.split(".");
            className = parts[0];
            method = parts[1];
        }
        isConstructor = true;
    } else     {
        if (method.contains(".")) {
        List<String> parts = method.split(".");
        className = parts[0];
        method = parts[1];
    }
;
    }    Uri packageUri = Uri.parse(match.group(3)!);
    String package = "<unknown>";
    String packagePath = packageUri.path;
    if (packageUri.scheme == "dart" || packageUri.scheme == "package") {
        package = packageUri.pathSegments[0];
        packagePath = packageUri.path.replaceFirst("${packageUri.pathSegments[0]}/", "");
    }
    return StackFrame(int.parse(match.group(1)!), className, method, packageUri.scheme, package, packagePath, match.group(4) == nullptr? -1 : int.parse(match.group(4)!), match.group(5) == nullptr? -1 : int.parse(match.group(5)!), isConstructor, line);
}

int StackFrame::hashCode() {
    return Object.hash(number, package, line, column, className, method, source);
}

bool StackFrame::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is StackFrame && other.number == number && other.package == package && other.line == line && other.column == column && other.className == className && other.method == method && other.source == source;
}

String StackFrame::toString() {
    return "${objectRuntimeType(this, 'StackFrame')}(#$number, $packageScheme:$package/$packagePath:$line:$column, className: $className, method: $method)";
}

StackFrame StackFrame::_parseWebFrame(String line) {
    if (kDebugMode) {
        return _parseWebDebugFrame(line);
    } else {
        return _parseWebNonDebugFrame(line);
    }
}

StackFrame StackFrame::_parseWebDebugFrame(String line) {
    bool hasPackage = line.startsWith("package");
    RegExp parser = hasPackage? RegExp("^(package.+) (\d+):(\d+)\s+(.+)$") : RegExp("^(.+) (\d+):(\d+)\s+(.+)$");
    Match match = parser.firstMatch(line);
    assert(match != nullptr, "Expected $line to match $parser.");
    match = match!;
    String package = "<unknown>";
    String packageScheme = "<unknown>";
    String packagePath = "<unknown>";
    if (hasPackage) {
        packageScheme = "package";
        Uri packageUri = Uri.parse(match.group(1)!);
        package = packageUri.pathSegments[0];
        packagePath = packageUri.path.replaceFirst("${packageUri.pathSegments[0]}/", "");
    }
    return StackFrame(-1, packageScheme, package, packagePath, int.parse(match.group(2)!), int.parse(match.group(3)!), "<unknown>", match.group(4)!, line);
}

StackFrame StackFrame::_parseWebNonDebugFrame(String line) {
    Match match = _webNonDebugFramePattern.firstMatch(line);
    if (match == nullptr) {
        return nullptr;
    }
    List<String> classAndMethod = match.group(1)!.split(".");
    String className = classAndMethod.length > 1? classAndMethod.first : "<unknown>";
    String method = classAndMethod.length > 1? classAndMethod.skip(1).join(".") : classAndMethod.single;
    return StackFrame(-1, "<unknown>", "<unknown>", "<unknown>", -1, -1, className, method, line);
}
