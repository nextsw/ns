#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H
#include <memory>




class Category {
public:
    List<String> sections;


     Category(List<String> sections);

private:

};

class DocumentationIcon {
public:
    String url;


     DocumentationIcon(String url);

private:

};

class Summary {
public:
    String text;


     Summary(String text);

private:

};

#endif