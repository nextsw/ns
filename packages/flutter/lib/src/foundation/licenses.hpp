#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_LICENSES
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_LICENSES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/meta/meta.hpp>


class LicenseParagraphCls : public ObjectCls {
public:
    String text;

    int indent;

    static int centeredIndent;


     LicenseParagraphCls(int indent, String text);
private:

};
using LicenseParagraph = std::shared_ptr<LicenseParagraphCls>;

class LicenseEntryCls : public ObjectCls {
public:

     LicenseEntryCls();
    virtual Iterable<String> packages();
    virtual Iterable<LicenseParagraph> paragraphs();
private:

};
using LicenseEntry = std::shared_ptr<LicenseEntryCls>;

enum _LicenseEntryWithLineBreaksParserState{
    beforeParagraph,
    inParagraph,
} // end _LicenseEntryWithLineBreaksParserState

class LicenseEntryWithLineBreaksCls : public LicenseEntryCls {
public:
    List<String> packages;

    String text;


     LicenseEntryWithLineBreaksCls(List<String> packages, String text);
    virtual Iterable<LicenseParagraph> paragraphs();

private:

};
using LicenseEntryWithLineBreaks = std::shared_ptr<LicenseEntryWithLineBreaksCls>;

class LicenseRegistryCls : public ObjectCls {
public:

    static void addLicense(LicenseEntryCollector collector);

    static Stream<LicenseEntry> licenses();

    static void reset();

private:
    static List<LicenseEntryCollector> _collectors;


    virtual void  _();
};
using LicenseRegistry = std::shared_ptr<LicenseRegistryCls>;


#endif