//
// Created by Sammy Timmins on 9/22/20.
//

#ifndef INC_20F_AUTO_IDX_ENTRY_H
#define INC_20F_AUTO_IDX_ENTRY_H

#include <set>
#include "DSString.h"
#include "DSVector.h"
#include "DSLinkedList.h"

class Entry
{
public:
    Entry() = default;
    Entry(const DSString &word);
    ~Entry() = default;
    Entry(const Entry &copy);
    Entry& operator=(const Entry &copy);
    Entry& operator=(const DSString &string);
    bool operator<(const Entry&) const;
    bool operator==(const Entry &);
    friend std::ostream& operator<<(std::ostream&, const Entry&);

    DSString getEntry();
    set<int> getPages();
    void addPage(const int &toAdd);
    DSVector<Entry> getChildren();
    void addChild(const Entry &toAdd);
    char getWordAt(const int i) const;

private:
    DSString word;
    set<int> pages;
    DSVector<Entry> children;
};
#endif //INC_20F_AUTO_IDX_ENTRY_H
