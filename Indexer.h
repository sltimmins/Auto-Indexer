//
// Created by Sammy Timmins on 9/21/20.
//

#ifndef INC_20F_AUTO_IDX_INDEXER_H
#define INC_20F_AUTO_IDX_INDEXER_H

#include <iostream>
#include <fstream>
#include <map>
#include "DSString.h"
#include "DSVector.h"
#include "DSLinkedList.h"
#include "Entry.h"
#include "Parser.h"

void write(set<Entry> &index, ofstream &outputFile) //outputs the index
{
    char header, checkHeader;
    set<Entry>::iterator itr;
    for(itr = next(index.begin()); itr != index.end(); ++itr)
    {
        checkHeader = itr->getWordAt(0); //used to set the header for the index correctly
        if(header != checkHeader) //changes the header when the next words begin
        {
            header = checkHeader;
            outputFile << "[" << char(toupper(header)) << "]" << endl;
        }
        outputFile << *itr << endl;
    }
}

void runIndexer(ifstream &inputFile, ofstream &outputFile)
{
    DSLinkedList<Entry> entries;
    set<Entry> index;

    parse(inputFile, entries); //parses the input text file into entries list and also handles children cases

    for(int i = 0; i < entries.getSize(); i++) //converts the list to a set
    {
        index.insert(entries[i]);
    }

    write(index, outputFile); //writes the set to the output file in the correct format
}

#endif //INC_20F_AUTO_IDX_INDEXER_H
