#include "HTMLElement.h"

using namespace std;

HTMLElement::HTMLElement(string _tag, string _textContent)
{
    tag = _tag;
    textContent = _textContent;
}

HTMLElement& HTMLElement::setAttribute(const char*  attr, const char* val)
{
    attributes[attr] = val;
    return *this;
}

void HTMLElement::setSingle(bool _single)
{
    single = _single;
}

HTMLElement& HTMLElement::appendChild(const HTMLElement& child)
{
    contents.push_back(child);

    HTMLElement& justAdded = contents.back();
    justAdded.setParent(this);

    return justAdded;
}

void HTMLElement::generateContents(ostream& stream) const
{
    if(textContent.length())
        stream << textContent;

    for(const HTMLElement& e : contents)
        e.generate(stream);
}

void HTMLElement::generateAttributes(ostream& stream) const
{
    if(!attributes.empty())
        stream << " ";

    for(const auto& [key,value] : attributes)
        stream << key  << "='" << value << "' ";
}

void HTMLElement::generate(ostream& stream) const
{   
    if(tag == "text" || tag == "blank")
    {
        generateContents(stream);
        return;
    }

    stream << "<" << tag;
    generateAttributes(stream);
    stream << ">";

    if(!single)
    {
        generateContents(stream);
        stream << "</" << tag << ">";
    }

    stream << endl;
}

HTMLElement* HTMLElement::getParent() const
{
    return parent;
}

void HTMLElement::setParent(HTMLElement* _parent)
{
    parent = _parent;
}

ostream& operator<<(ostream& stream, const HTMLElement& elem)
{
    elem.generate(stream);
    return stream;
}