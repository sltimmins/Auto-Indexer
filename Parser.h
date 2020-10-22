//
// Created by Sammy Timmins on 9/21/20.
//

#ifndef INC_20F_AUTO_IDX_PARSER_H
#define INC_20F_AUTO_IDX_PARSER_H

#include <iostream>
#include <fstream>
#include <map>
#include "DSString.h"
#include "DSVector.h"
#include "DSLinkedList.h"
#include "Entry.h"

void addToEntries(int &pageNumber, DSString &word, DSLinkedList<Entry> &entries);
void addChildToIndex(int &pageNumber, Entry &child, DSLinkedList<Entry> &entries);
void addChildToEntry(int &pageNumber, DSString &child, DSString &parent, DSLinkedList<Entry> &entries);
void parse(ifstream& inputFile, DSLinkedList<Entry> &entries);

#endif //INC_20F_AUTO_IDX_PARSER_H
