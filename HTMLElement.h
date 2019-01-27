#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class HTMLElement
{
    string tag;
    string textContent; // For Text Elements
    HTMLElement* parent =  nullptr;
    list<HTMLElement> contents;
    map<string,string> attributes;
    bool single = false; // single tag ex: <br>

    void generateContents(ostream& stream) const;
    void generateAttributes(ostream& stream) const;
    void setParent(HTMLElement* _parent);
public:
    HTMLElement(string _tag, string _textContent = "");
    HTMLElement& setAttribute(const char* attr, const char* val);
    void setSingle(bool _single);
    HTMLElement& appendChild(const HTMLElement& child);
    HTMLElement* getParent() const;
    void generate(ostream& stream) const;
};

HTMLElement TextElement(string content); // For Simpler Interface

ostream& operator<<(ostream& stream, const HTMLElement& elem);

#pragma once