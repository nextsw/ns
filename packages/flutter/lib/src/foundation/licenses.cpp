#include "licenses.hpp"
Iterable<LicenseParagraph> LicenseEntryWithLineBreaksCls::paragraphs() {
    int lineStart = 0;
    int currentPosition = 0;
    int lastLineIndent = 0;
    int currentLineIndent = 0;
    int currentParagraphIndentation;
    _LicenseEntryWithLineBreaksParserState state = _LicenseEntryWithLineBreaksParserStateCls::beforeParagraph;
    List<String> lines = makeList();
    List<LicenseParagraph> result = makeList();
    InlineMethod;
    InlineMethod;
    while ( < text->length()) {
        ;
        currentPosition = 1;
    }
    ;
    return result;
}

void LicenseRegistryCls::addLicense(LicenseEntryCollector collector) {
    _collectors = makeList();
    _collectors!->add(collector);
}

Stream<LicenseEntry> LicenseRegistryCls::licenses() {
    if (_collectors == nullptr) {
        return <LicenseEntry>empty();
    }
    StreamController<LicenseEntry> controller;
    controller = <LicenseEntry>make<StreamControllerCls>([=] () {
        for (LicenseEntryCollector collector : _collectors!) {
            await await controller->addStream(collector());
        }
        await await controller->close();
    });
    return controller->stream;
}

void LicenseRegistryCls::reset() {
    _collectors = nullptr;
}
