//
// Created by Sammy Timmins on 9/22/20.
//

#include <map>
#include "Parser.h"
#include "DSString.h"
#include "Entry.h"

void addToEntries(int &pageNumber, DSString &word, DSLinkedList<Entry> &entries) //adds a word that is not a sub entry to the index
{
    Entry indexed;
    indexed = word;
    int index = entries.search(indexed);
    if(index == -1) //if entry is not already in the entries vector it adds it
    {
        indexed.addPage(pageNumber);
        entries.add(indexed);
    } else //if entries is in the entries vector it adds the page number to the entry
    {
        entries[index].addPage(pageNumber);
    }
}

void addChildToIndex(int &pageNumber, Entry &child, DSLinkedList<Entry> &entries)
{
    child.addPage(pageNumber);
    entries.add(child);
}

void addChildToEntry(int &pageNumber, DSString &word, DSString &parent, DSLinkedList<Entry> &entries) //adds a subentry to the index
{
    Entry indexed, child;
    indexed = parent;
    child = word;
    int index = entries.search(indexed);
    if(index == -1) //if entry is not already in the entries vector it adds it
    {
        int checkChild = entries.search(child);
        if(checkChild == -1) //if the child has not been added to the index yet
        {
            addChildToIndex(pageNumber, child, entries);
        }
        else //if the child has been added to the index
        {
            entries[checkChild].addPage(pageNumber);
        }
        indexed.addChild(child);
        entries.add(indexed);
    } else //if entries is in the entries vector it adds the page number to the entry
    {
        int checkChild = entries.search(child);
        if(checkChild == -1) //if the child has not been added as an entry yet
        {
            addChildToIndex(pageNumber, child, entries);
            checkChild = entries.search(child);
        }
        else //if the child has been added as an entry
        {
            entries[checkChild].addPage(pageNumber);
        }
        entries[index].addChild(entries[checkChild]);
    }
}

void parse(ifstream &inputFile, DSLinkedList<Entry> &entries)
{
    char buffer[80];
    DSString pageNumberString;
    int pageNumber;

    while(inputFile.getline(buffer, 80)) //repeats until end of file
    {
        DSString line = buffer;
        if(line[0] == '<')
        {
            pageNumberString = "";
            for(int i = 1; line[i] != '>'; i++) //grabs the page number from between the <>
            {
                pageNumberString = pageNumberString + line[i];
            }
            pageNumber = pageNumberString.dsstoi();
        }
        else
        {
            for(int i = 0; i < line.getLength();)
            {
                DSString word, parent;
                if(line[i] != '[') //checks if first in line is a phrase
                {
                    while((line[i] != ' ') && (line[i] != '(') && (i != line.getLength())) //adds characters to word until the end of the word
                    {
                        word = word + tolower(line[i]);
                        ++i;
                    }

                    if((line[i] == ' ') || (i == line.getLength())) //adds indexed word that is not a sub entry to the entries vector
                    {
                        addToEntries(pageNumber, word, entries);
                        ++i;
                    } else if (line[i] == '(')
                    {
                        if(line[i + 1] != '[') //handles if the parent is a phrase or keyword
                        {
                            ++i;
                        }
                        else
                        {
                            i += 2;
                        }
                        while(line[i] != ')')
                        {
                            parent = parent + line[i];
                            ++i;
                        }
                        addChildToEntry(pageNumber, word, parent, entries);
                    }
                } else if(line[i] == '[') //if the the thing to be indexed is a phrase
                {
                    ++i;
                    while((line[i] != ']'))
                    {
                        word = word + tolower(line[i]);
                        ++i;
                    }
                    if((line[i] == ']') && (line[i + 1] == '(')) //if the indexed phrase is a child of a parent entry
                    {
                        if(line[i + 2] != '[') //handles if the parent is a phrase or a keyword
                        {
                            i += 2;
                        }
                        else
                        {
                            i += 3;
                        }
                        while(line[i] != ')')
                        {
                            parent = parent + line[i];
                            ++i;
                        }
                        addChildToEntry(pageNumber, word, parent, entries);
                    }
                    else if(line[i] == ']') //if the phrase is not a sub entry
                    {
                        addToEntries(pageNumber, word, entries);
                        ++i;
                    }
                }
            }
        }
    }
}
