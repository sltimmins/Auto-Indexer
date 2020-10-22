//
// Created by Sammy Timmins on 9/16/20.
//
#include "catch.hpp"
#include "DSLinkedList.h"
#include "DSString.h"

TEST_CASE("DSLinkedList Class Primitive Data Types", "[DSLinkedList]")
{
    DSLinkedList<int> integers;
    DSLinkedList<char> characters;
    DSLinkedList<float> floats;
    DSLinkedList<double> doubles;
    DSLinkedList<long> longs;
    DSLinkedList<bool> booleans;

    integers.add(0);
    integers.add(10);
    integers.add(-1);
    integers.add(-10);
    integers.add(1.5);

    characters.add('A');
    characters.add('a');
    characters.add('\n');
    characters.add('\0');
    characters.add('1');
    characters.add(',');
    characters.add(' ');

    floats.add(0.1);
    floats.add(.0001);
    floats.add(1.01);
    floats.add(10);
    floats.add(0);
    floats.add(-.01);
    floats.add(-1.01);

    doubles.add(0);
    doubles.add(1);
    doubles.add(-1);
    doubles.add(-10);
    doubles.add(1.5);
    doubles.add(-1.5);

    longs.add(0);
    longs.add(1);
    longs.add(-1);
    longs.add(-10);
    longs.add(1.5);

    booleans.add(true);
    booleans.add(false);
    booleans.add(1);
    booleans.add(0);

    SECTION("add() on int")
    {
        REQUIRE((integers[0] == 0));
        REQUIRE((integers.at(1) == 10));
        REQUIRE((integers.at(2) == -1));
        REQUIRE((integers[3] == -10));
        REQUIRE((integers[1] != integers[3]));
        REQUIRE((integers[4] == 1));
    }

    SECTION("add() on char")
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

    SECTION("add() on float")
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

    SECTION("add() on double")
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

    SECTION("add() on long")
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

    SECTION("add() on bool")
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

    SECTION(".add() on primitives")
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
        characters.remove('\n');
        REQUIRE((characters[2] == '\0'));
        longs.remove(-1);
        REQUIRE((longs[2] == -10));
        booleans.remove(true);
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
        DSLinkedList<int> integersCopy(integers);
        REQUIRE((integersCopy[2] == -1));
        DSLinkedList<char> charactersCopy(characters);
        REQUIRE((charactersCopy[2] == '\n'));
        DSLinkedList<float> floatsCopy(floats);
        REQUIRE((floatsCopy[2] == Approx(1.01)));
        DSLinkedList<double> doublesCopy(doubles);
        REQUIRE((doublesCopy[2] == -1));
        DSLinkedList<long> longsCopy(longs);
        REQUIRE((longsCopy[2] == -1));
        DSLinkedList<bool> booleansCopy(booleans);
        REQUIRE((booleans[2]));
    }

    SECTION("Overloaded assignment operator on primitives")
    {
        DSLinkedList<int> integersCopy = integers;
        REQUIRE((integersCopy[2] == -1));
        DSLinkedList<char> charactersCopy = characters;
        REQUIRE((charactersCopy[2] == '\n'));
        DSLinkedList<float> floatsCopy = floats;
        REQUIRE((floatsCopy[2] == Approx(1.01)));
        DSLinkedList<double> doublesCopy = doubles;
        REQUIRE((doublesCopy[2] == -1));
        DSLinkedList<long> longsCopy = longs;
        REQUIRE((longsCopy[2] == -1));
        DSLinkedList<bool> booleansCopy = booleans ;
        REQUIRE((booleans[2]));
    }
}

TEST_CASE("LinkedList Class Object Types", "[LinkedList]")
{
    DSLinkedList<std::string> strings;
    DSLinkedList<DSString> DSStrings;

    strings.add("Hello");
    strings.add("there");
    strings.add(" ");
    strings.add("\n");

    DSStrings.add("Hello");
    DSStrings.add("there");
    DSStrings.add(" ");
    DSStrings.add("\n");

    SECTION("add on strings")
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

    SECTION("add on DSStrings")
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
        strings.remove("Hello");
        REQUIRE((strings[0] == "there"));
        DSStrings.remove("Hello");
        REQUIRE((DSStrings[0] == "there"));
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
        DSLinkedList<std::string> stringsCopy(strings);
        REQUIRE((stringsCopy[2] == " "));
        DSLinkedList<DSString> DSStringCopy(DSStrings);
        REQUIRE((DSStringCopy[1] == "there"));
    }

    SECTION("Overloaded assignment operator on objects")
    {
        DSLinkedList<std::string> stringsCopy = strings;
        REQUIRE((stringsCopy[2] == " "));
        DSLinkedList<DSString> DSStringCopy = DSStrings;
        REQUIRE((DSStringCopy[1] == "there"));
    }
}