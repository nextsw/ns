#include "licenses.hpp"
Iterable<LicenseParagraph> LicenseEntryWithLineBreaks::paragraphs() {
    int lineStart = 0;
    int currentPosition = 0;
    int lastLineIndent = 0;
    int currentLineIndent = 0;
    int currentParagraphIndentation;
    _LicenseEntryWithLineBreaksParserState state = _LicenseEntryWithLineBreaksParserState.beforeParagraph;
    List<String> lines = ;
    List<LicenseParagraph> result = ;
    ;
    ;
    while ( < text.length) {
        ;
        currentPosition = 1;
    }
    ;
    return result;
}

void LicenseRegistry::addLicense(LicenseEntryCollector collector) {
    _collectors = ;
    _collectors!.add(collector);
}

Stream<LicenseEntry> LicenseRegistry::licenses() {
    if (_collectors == nullptr) {
        return const <LicenseEntry>empty();
    }
    StreamController<LicenseEntry> controller;
    controller = <LicenseEntry>StreamController();
    return controller.stream;
}

void LicenseRegistry::reset() {
    _collectors = nullptr;
}
