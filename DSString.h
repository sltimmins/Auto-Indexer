//
// Created by Sammy Timmins on 8/31/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class DSString
{
public:
    DSString();
    DSString(const char *);
    ~DSString();
    DSString(const DSString &copy);
    DSString& operator=(const DSString&);
    DSString&operator=(const char*);
    DSString operator+(const DSString&) const;
    DSString operator+(const char*);
    DSString& operator+(const char);
    bool operator==(const char*);
    bool operator==(const DSString&);
    bool operator>(const DSString&);
    bool operator<(const DSString&) const;
    char& operator[](const int) const;
    friend std::ostream& operator<<(std::ostream&, const DSString&);

    void print();
    int getLength() const;
    int getCapacity();
    char* getString();
    DSString substr(int pos, int npos) const;
    char* c_str();
    int dsstoi();
    float dsstof();

private:
    char* data;
    int length;
    int capacity;
};


#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H