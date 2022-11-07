#ifndef PROCESS_H
#define PROCESS_H
#include <memory>




class _ProcessUtils {
public:

private:

    external static Never _exit(int status);

    external static void _setExitCode(int status);

    external static int _getExitCode();

    external static void _sleep(int millis);

    external static int _pid(Process process);

    external static Stream<ProcessSignal> _watchSignal(ProcessSignal signal);

};
Never exit(int code);

void exitCode(int code);

int exitCode();

void sleep(Duration duration);

int pid();


class ProcessInfo {
public:

    external static int currentRss();

    external static int maxRss();

private:

};

class ProcessStartMode {
public:
    static const auto  normal;

    static const auto  inheritStdio;

    static const auto  detached;

    static const auto  detachedWithStdio;


    static List<ProcessStartMode> values();

    String toString();

private:
    int _mode;


    void  _internal(int _mode);

};

class Process {
public:

    Future<int> exitCode();

    external static Future<Process> start(List<String> arguments, Map<String, String> environment, String executable, bool includeParentEnvironment, ProcessStartMode mode, bool runInShell, String workingDirectory);

    external static Future<ProcessResult> run(List<String> arguments, Map<String, String> environment, String executable, bool includeParentEnvironment, bool runInShell, Encoding stderrEncoding, Encoding stdoutEncoding, String workingDirectory);

    external static ProcessResult runSync(List<String> arguments, Map<String, String> environment, String executable, bool includeParentEnvironment, bool runInShell, Encoding stderrEncoding, Encoding stdoutEncoding, String workingDirectory);

    external static bool killPid(int pid, ProcessSignal signal);

    Stream<List<int>> stdout();

    Stream<List<int>> stderr();

    IOSink stdin();

    int pid();

    bool kill(ProcessSignal signal);

private:

};

class ProcessResult {
public:
    int exitCode;

    auto  stdout;

    auto  stderr;

    int pid;


     ProcessResult(int exitCode, int pid, Unknown stderr, Unknown stdout);

private:

};

class ProcessSignal {
public:
    static const ProcessSignal sighup;

    static const ProcessSignal sigint;

    static const ProcessSignal sigquit;

    static const ProcessSignal sigill;

    static const ProcessSignal sigtrap;

    static const ProcessSignal sigabrt;

    static const ProcessSignal sigbus;

    static const ProcessSignal sigfpe;

    static const ProcessSignal sigkill;

    static const ProcessSignal sigusr1;

    static const ProcessSignal sigsegv;

    static const ProcessSignal sigusr2;

    static const ProcessSignal sigpipe;

    static const ProcessSignal sigalrm;

    static const ProcessSignal sigterm;

    static const ProcessSignal sigchld;

    static const ProcessSignal sigcont;

    static const ProcessSignal sigstop;

    static const ProcessSignal sigtstp;

    static const ProcessSignal sigttin;

    static const ProcessSignal sigttou;

    static const ProcessSignal sigurg;

    static const ProcessSignal sigxcpu;

    static const ProcessSignal sigxfsz;

    static const ProcessSignal sigvtalrm;

    static const ProcessSignal sigprof;

    static const ProcessSignal sigwinch;

    static const ProcessSignal sigpoll;

    static const ProcessSignal sigsys;


    String toString();

    Stream<ProcessSignal> watch();

private:
    int _signalNumber;

    String _name;


    void  _(String _name, int _signalNumber);

};

class SignalException {
public:
    String message;

    auto  osError;


     SignalException(String message, Unknown osError);

    String toString();

private:

};

class ProcessException {
public:
    String executable;

    List<String> arguments;

    String message;

    int errorCode;


     ProcessException(List<String> arguments, int errorCode, String executable, String message);

    String toString();

private:

};

#endif