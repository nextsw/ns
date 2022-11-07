#ifndef LICENSES_H
#define LICENSES_H
#include <memory>

#include <async/async.hpp>
#include <meta/meta.hpp>



class LicenseParagraph {
public:
    String text;

    int indent;

    static const int centeredIndent;


     LicenseParagraph(int indent, String text);

private:

};

class LicenseEntry {
public:

     LicenseEntry();

    Iterable<String> packages();

    Iterable<LicenseParagraph> paragraphs();

private:

};

enum _LicenseEntryWithLineBreaksParserState{
    beforeParagraph,
    inParagraph,
} // end _LicenseEntryWithLineBreaksParserState

class LicenseEntryWithLineBreaks : LicenseEntry {
public:
    List<String> packages;

    String text;


     LicenseEntryWithLineBreaks(List<String> packages, String text);

    Iterable<LicenseParagraph> paragraphs();

private:

};

class LicenseRegistry {
public:

    static void addLicense(LicenseEntryCollector collector);

    static Stream<LicenseEntry> licenses();

    static void reset();

private:
    static List<LicenseEntryCollector> _collectors;


    void  _();

};

#endif