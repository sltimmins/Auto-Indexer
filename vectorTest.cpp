//
// Created by Sammy Timmins on 9/16/20.
//

#include <string>

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("Vector Class Primitive Data Types", "[vector]")
{
    DSVector<int> integers;
    DSVector<char> characters;
    DSVector<float> floats;
    DSVector<double> doubles;
    DSVector<long> longs;
    DSVector<bool> booleans;

    integers.push_back(0);
    integers.push_back(10);
    integers.push_back(-1);
    integers.push_back(-10);
    integers.push_back(1.5);

    characters.push_back('A');
    characters.push_back('a');
    characters.push_back('\n');
    characters.push_back('\0');
    characters.push_back('1');
    characters.push_back(',');
    characters.push_back(' ');

    floats.push_back(0.1);
    floats.push_back(.0001);
    floats.push_back(1.01);
    floats.push_back(10);
    floats.push_back(0);
    floats.push_back(-.01);
    floats.push_back(-1.01);

    doubles.push_back(0);
    doubles.push_back(1);
    doubles.push_back(-1);
    doubles.push_back(-10);
    doubles.push_back(1.5);
    doubles.push_back(-1.5);

    longs.push_back(0);
    longs.push_back(1);
    longs.push_back(-1);
    longs.push_back(-10);
    longs.push_back(1.5);

    booleans.push_back(true);
    booleans.push_back(false);
    booleans.push_back(1);
    booleans.push_back(0);

    SECTION("push_back on int")
    {
        REQUIRE((integers[0] == 0));
        REQUIRE((integers.at(1) == 10));
        REQUIRE((integers.at(2) == -1));
        REQUIRE((integers[3] == -10));
        REQUIRE((integers[1] != integers[3]));
        REQUIRE((integers[4] == 1));
    }

    SECTION("push_back on char")
    {
        REQUIRE((characters[0] == 'A'));
        REQUIRE((characters.at(1) == 'a'));
        REQUIRE((characters[0] != characters[1]));
        REQUIRE((characters.at(2) == '\n'));
        REQUIRE((characters[3] == '\0'));
        REQUIRE((characters[4] == '1'));
        REQUIRE((characters.at(4) == '1'));
        REQUIRE((characters[5] == ','));
        REQUIRE((characters.at(5) == ','));
        REQUIRE((characters[6] == ' '));
        REQUIRE((characters.at(6) == ' '));
    }

    SECTION("push_back on float")
    {
        REQUIRE((floats[0] == Approx(0.1)));
        REQUIRE((floats.at(1) == Approx(0.0001)));
        REQUIRE((floats[2] == Approx(1.01)));
        REQUIRE((floats.at(2) == Approx(1.01)));
        REQUIRE((floats[3] == 10));
        REQUIRE((floats.at(3) == 10));
        REQUIRE((floats[4] == 0));
        REQUIRE((floats.at(4) == 0));
        REQUIRE((floats[5] == Approx(-0.01)));
        REQUIRE((floats.at(5) == Approx(-0.01)));
        REQUIRE((floats[6] == Approx(-1.01)));
        REQUIRE((floats.at(6) == Approx(-1.01)));
    }

    SECTION("push_back on double")
    {
        REQUIRE((doubles[0] == 0));
        REQUIRE((doubles.at(0) == 0));
        REQUIRE((doubles[1] == 1));
        REQUIRE((doubles.at(1) == 1));
        REQUIRE((doubles[2] == -1));
        REQUIRE((doubles.at(2) == -1));
        REQUIRE((doubles[3] == -10));
        REQUIRE((doubles.at(3) == -10));
        REQUIRE((doubles.at(4) == 1.5));
        REQUIRE((doubles[5] == -1.5));
    }

    SECTION("push_back on long")
    {
        REQUIRE((longs[0] == 0));
        REQUIRE((longs.at(0) == 0));
        REQUIRE((longs[1] == 1));
        REQUIRE((longs.at(1) == 1));
        REQUIRE((longs[2] == -1));
        REQUIRE((longs.at(2) == -1));
        REQUIRE((longs[3] == -10));
        REQUIRE((longs.at(3) == -10));
        REQUIRE((longs[4] == 1));
        REQUIRE((longs.at(4) == 1));
    }

    SECTION("push_back on bool")
    {
        REQUIRE(booleans[0]);
        REQUIRE(booleans.at(0));
        REQUIRE(!booleans[1]);
        REQUIRE(!booleans.at(1));
        REQUIRE(booleans[2]);
        REQUIRE(booleans.at(2));
        REQUIRE(!booleans[3]);
        REQUIRE(!booleans.at(3));

    }

    SECTION("pop_back on primitives")
    {
        integers.pop_back();
        REQUIRE((integers.getSize() == 4));
        characters.pop_back();
        REQUIRE((characters.getSize() == 6));
        floats.pop_back();
        REQUIRE((floats.getSize() == 6));
        doubles.pop_back();
        REQUIRE((doubles.getSize() == 5));
    }

    SECTION("[] operator for primitives")
    {
        REQUIRE((integers[0] == 0));
        REQUIRE((characters[0] == 'A'));
        REQUIRE((characters[2] == '\n'));
        REQUIRE((floats[0] == Approx(0.1)));
        REQUIRE((doubles[0] == 0));
        REQUIRE((longs[0] == 0));
        REQUIRE(booleans[0]);
    }

    SECTION(".at() on primitives")
    {
        REQUIRE((integers.at(1) == 10));
        REQUIRE((characters.at(1) == 'a'));
        REQUIRE((floats.at(1) == Approx(0.0001)));
        REQUIRE((doubles.at(0) == 0));
        REQUIRE((longs.at(0) == 0));
        REQUIRE(booleans.at(0));
    }

    SECTION("remove() on primitives")
    {
        floats.remove(2);
        REQUIRE((floats.at(2) == 10));
        characters.remove(2);
        REQUIRE((characters[2] == '\0'));
        longs.remove(1);
        REQUIRE((longs[1] == -1));
        booleans.remove(1);
        REQUIRE((booleans[1]));
    }

    SECTION("reassign() on primitives")
    {
        integers.reassign(0, -1);
        REQUIRE((integers[0] == -1));
        integers.reassign(0, 1);
        REQUIRE((integers[0] == 1));
        characters.reassign(0, 'a');
        REQUIRE((characters[0] == 'a'));
        floats.reassign(0, 1.1);
        REQUIRE((floats[0] == Approx(1.1)));
        floats.reassign(0, -1.0);
        REQUIRE((floats[0] == -1.0));
        booleans.reassign(0, false);
        REQUIRE((!booleans[0]));
    }

    SECTION(".search() on primitives")
    {
        REQUIRE((integers.search(10) == 1));
        REQUIRE((integers.search(11) == -1));
        REQUIRE((characters.search('A') == 0));
        REQUIRE((characters.search('b') == -1));
        REQUIRE((booleans.search(true) == 0));
    }

    SECTION("getSize() on primitives")
    {
        REQUIRE((integers.getSize() == 5));
        REQUIRE((characters.getSize() == 7));
        REQUIRE((floats.getSize() == 7));
        REQUIRE((doubles.getSize() == 6));
        REQUIRE((longs.getSize() == 5));
        REQUIRE((booleans.getSize() == 4));
    }

    SECTION("Copy constructor on primitives")
    {
        DSVector<int> integersCopy(integers);
        REQUIRE((integersCopy[2] == -1));
        DSVector<char> charactersCopy(characters);
        REQUIRE((charactersCopy[2] == '\n'));
        DSVector<float> floatsCopy(floats);
        REQUIRE((floatsCopy[2] == Approx(1.01)));
        DSVector<double> doublesCopy(doubles);
        REQUIRE((doublesCopy[2] == -1));
        DSVector<long> longsCopy(longs);
        REQUIRE((longsCopy[2] == -1));
        DSVector<bool> booleansCopy(booleans);
        REQUIRE((booleans[2]));
    }

    SECTION("Overloaded assignment operator on primitives")
    {
        DSVector<int> integersCopy = integers;
        REQUIRE((integersCopy[2] == -1));
        DSVector<char> charactersCopy = characters;
        REQUIRE((charactersCopy[2] == '\n'));
        DSVector<float> floatsCopy = floats;
        REQUIRE((floatsCopy[2] == Approx(1.01)));
        DSVector<double> doublesCopy = doubles;
        REQUIRE((doublesCopy[2] == -1));
        DSVector<long> longsCopy = longs;
        REQUIRE((longsCopy[2] == -1));
        DSVector<bool> booleansCopy = booleans ;
        REQUIRE((booleans[2]));
    }
}

TEST_CASE("Vector Class Object Types", "[vector]")
{
    DSVector<std::string> strings;
    DSVector<DSString> DSStrings;

    strings.push_back("Hello");
    strings.push_back("there");
    strings.push_back(" ");
    strings.push_back("\n");

    DSStrings.push_back("Hello");
    DSStrings.push_back("there");
    DSStrings.push_back(" ");
    DSStrings.push_back("\n");

    SECTION("push_back on strings")
    {
        REQUIRE((strings[0] == "Hello"));
        REQUIRE((strings.at(0) == "Hello"));
        REQUIRE((strings[1] == "there"));
        REQUIRE((strings.at(1) == "there"));
        REQUIRE((strings[2] == " "));
        REQUIRE((strings.at(2) == " "));
        REQUIRE((strings[3] == "\n"));
        REQUIRE((strings.at(3) == "\n"));
    }

    SECTION("push_back on DSStrings")
    {
        REQUIRE((DSStrings[0] == "Hello"));
        REQUIRE((DSStrings.at(0) == "Hello"));
        REQUIRE((DSStrings[1] == "there"));
        REQUIRE((DSStrings.at(1) == "there"));
        REQUIRE((DSStrings[2] == " "));
        REQUIRE((DSStrings.at(2) == " "));
        REQUIRE((DSStrings[3] == "\n"));
        REQUIRE((DSStrings.at(3) == "\n"));
    }

    SECTION("pop_back on objects")
    {
        strings.pop_back();
        REQUIRE((strings.getSize() == 3));
        DSStrings.pop_back();
        REQUIRE((DSStrings.getSize() == 3));
    }

    SECTION("[] operator for objects")
    {
        REQUIRE((strings[0] == "Hello"));
        REQUIRE((strings[1] == "there"));
        REQUIRE((strings[2] == " "));
        REQUIRE((strings[3] == "\n"));
        REQUIRE((DSStrings[0] == "Hello"));
        REQUIRE((DSStrings[1] == "there"));
        REQUIRE((DSStrings[2] == " "));
        REQUIRE((DSStrings[3] == "\n"));
    }

    SECTION(".at() for objects")
    {
        REQUIRE((strings.at(0) == "Hello"));
        REQUIRE((strings.at(1) == "there"));
        REQUIRE((strings.at(2) == " "));
        REQUIRE((strings.at(3) == "\n"));
        REQUIRE((DSStrings.at(0) == "Hello"));
        REQUIRE((DSStrings.at(1) == "there"));
        REQUIRE((DSStrings.at(2) == " "));
        REQUIRE((DSStrings.at(3) == "\n"));
    }

    SECTION(".remove() for objects")
    {
        strings.remove(0);
        REQUIRE((strings[0] == "there"));
        DSStrings.remove(0);
        REQUIRE((DSStrings[0] == "there"));
    }

    SECTION(".reassign() for objects")
    {
        strings.reassign(0, "Howdy");
        REQUIRE((strings[0] == "Howdy"));
        strings.reassign(3, "Hello there");
        REQUIRE((strings[3] == "Hello there"));
        DSStrings.reassign(0, "Howdy");
        REQUIRE((DSStrings[0] == "Howdy"));
        DSStrings.reassign(3, "Hello there");
        REQUIRE((DSStrings[3] == "Hello there"));
    }

    SECTION(".search() for objects")
    {
        REQUIRE((strings.search("there") == 1));
        REQUIRE((strings.search("hello") == -1));
        REQUIRE((DSStrings.search("there") == 1));
        REQUIRE((DSStrings.search("hello") == -1));
    }

    SECTION("getSize() for objects")
    {
        REQUIRE((strings.getSize() == 4));
        REQUIRE((DSStrings.getSize() == 4));
    }

    SECTION("Copy constructor on objects")
    {
        DSVector<std::string> stringsCopy(strings);
        REQUIRE((stringsCopy[2] == " "));
        DSVector<DSString> DSStringCopy(DSStrings);
        REQUIRE((DSStringCopy[1] == "there"));
    }

    SECTION("Overloaded assignment operator on objects")
    {
        DSVector<std::string> stringsCopy = strings;
        REQUIRE((stringsCopy[2] == " "));
        DSVector<DSString> DSStringCopy = DSStrings;
        REQUIRE((DSStringCopy[1] == "there"));
    }
}

