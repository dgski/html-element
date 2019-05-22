#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../HTMLElement.h"
#include <sstream>
#include <iostream>
#include <string>

TEST_CASE("Element is generated with proper tag")
{
    shared_ptr<HTMLElement> div = make_HTMLElement("div");
    stringstream ss;
    ss << *div;

    REQUIRE(ss.str() == "<div></div>");
}

TEST_CASE("Single Element is generated properly")
{
    shared_ptr<HTMLElement> img = make_HTMLElement("img");
    img->setSingle(true);
    stringstream ss;
    ss << *img;

    REQUIRE(ss.str() == "<img>");
}

TEST_CASE("Text Element is generated properly")
{
    shared_ptr<TextElement> text = make_TextElement("This is some text");
    stringstream ss;
    ss << *text;

    REQUIRE(ss.str() == "This is some text");
}

TEST_CASE("Element is generated with proper attributes")
{
    shared_ptr<HTMLElement> a = make_HTMLElement("a");
    a
        ->setAttribute("href","www.test.com")
        ->setAttribute("class","link");
    a->setSingle(true);
    stringstream ss;
    ss << *a;

    REQUIRE(ss.str() == "<a href='www.test.com' class='link' >");
}

TEST_CASE("Setting Parent Element works properly")
{
    shared_ptr<HTMLElement> b = make_HTMLElement("b");
    shared_ptr<TextElement> text = make_TextElement("I am Ironman.");
    text->setParent(b.get());

    REQUIRE(text->getParent() == b.get());
}