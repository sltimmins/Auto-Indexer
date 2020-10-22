//
// Created by Sammy Timmins on 9/23/20.
//
#include "Entry.h"

Entry::Entry(const DSString &word)
{
    this->word = word;
}

Entry::Entry(const Entry &copy)
{
    this->word = copy.word;
    this->pages = copy.pages;
    this->children = copy.children;
}

Entry& Entry::operator=(const Entry &copy)
{
    this->word = copy.word;
    this->pages = copy.pages;
    this->children = copy.children;
}

Entry& Entry::operator=(const DSString &string) //assigns the string to the entry's word
{
    int size = string.getLength();
    int charsToExclude = 0;
    for(int i = size - 1; i >= 0; i--) //removes trailing punctuation from the string being added
    {
        if(!isalpha(string[i]))
        {
            ++charsToExclude;
        } else{
            break;
        }
    }
    word = string.substr(0, size - charsToExclude);
}

bool Entry::operator<(const Entry &toCompare) const //compares the words of the entry
{
    return word < toCompare.word;
}

bool Entry::operator==(const Entry &compare) //comapres the words of the entry
{
    return this->word == compare.word;
}

ostream& operator<<(ostream& os, const Entry& entry) //outputs and formats the output.txt
{
    int outputLength = entry.word.getLength(); //used to control wrapping at 50 chars
    os << entry.word << ": ";
    set<int>::iterator itr;
    for(itr = entry.pages.begin(); itr != entry.pages.end(); ++itr)
    {
        if(next(itr) != entry.pages.end())
        {
            os << *itr << ", ";
            outputLength += to_string(*itr).length() + 1;
            if((outputLength += to_string(*next(itr)).length()) >= 50) //if the ouput for the line has reached 50 chars
            {
                os << endl << "    ";
                outputLength = 0;
            }
        } else
        {
            os << *itr; //outputs the final page number without a comma
        }
    }

    for(int i = 0; i < entry.children.getSize(); i++) //recursively calls outstream function for the children
    {
        os << endl;
        os << "    " << entry.children.at(i);
    }

    return os;
}

DSString Entry::getEntry()
{
    return word;
}

set<int> Entry::getPages()
{
    return pages;
}

void Entry::addPage(const int &toAdd)
{
    pages.insert(toAdd);
}

DSVector<Entry> Entry::getChildren()
{
    return children;
}

void Entry::addChild(const Entry &toAdd)
{
    children.push_back(toAdd);
}

char Entry::getWordAt(const int i) const //accesses the entry at a certain character
{
    return word[i];
}

