//
// Created by Sammy Timmins on 9/1/20.
//
#include "DSString.h"

DSString::DSString() //default constructor
{
    data = new char[1];
    length = 0;
    capacity = 1;
}

DSString::DSString(const char *word) //constructor is passed a char* array
{
    capacity = strlen(word) + 1;
    length = strlen(word);
    data = new char[capacity];
    strcpy(data, word);
}

DSString::DSString(const DSString &copy) //copy constructor
{
    capacity = strlen(copy.data) + 1;
    length = strlen(copy.data);
    data = new char[capacity];
    strcpy(data, copy.data);
}

DSString::~DSString() //destructor
{
    delete [] data;
}

DSString &DSString::operator=(const DSString &copy) { //= operator overload for when DSString set to another DSString
    if(this != &copy)
    {
        if(this->data != nullptr) //ensures no memory leak occurs in the case of reassignment
        {
            delete [] this->data;
            this->data = nullptr;
        }

        this->capacity = copy.capacity;
        this->length = copy.length;
        this->data = new char[copy.capacity];
        strcpy(data, copy.data);
    }

    return *this;
}

DSString &DSString::operator=(const char *word) { //= operator overload for when DSString set to char*

    delete [] data;
    data = nullptr;

    capacity = strlen(word) + 1;
    length = strlen(word);
    data = new char[capacity];
    strcpy(data, word);

    return *this;
}

DSString DSString::operator+(const DSString &copy) const {//+ operator overloaded to add DSStrings together
    DSString newString;
    newString.length = this->length + copy.length;
    newString.capacity = this->capacity + copy.capacity - 1;
    newString.data = new char[newString.capacity];
    strcpy(newString.data, this->data);
    newString.data = strcat(newString.data, copy.data);

    newString.data[newString.capacity - 1] = '\0';

    return newString;
}

DSString DSString::operator+(const char *word) //+ operator overload for when DSString is added to a char*
{
    DSString newString;
    newString.length = this->length + strlen(word);
    newString.capacity = this->capacity + strlen(word);
    newString.data = new char[newString.capacity];
    strcpy(newString.data, this->data);
    newString.data = strcat(newString.data, word);
    newString.data[newString.capacity - 1] = '\0';

    return newString;
}

DSString& DSString::operator+(const char character) //+ operator overload for when DSString is added to a char
{
    char *temp = new char[capacity];
    length += 1;
    capacity += 1;

    for(int i = 0; i < capacity - 1; i++)
    {
        temp[i] = data[i];
    }

    delete [] data;
    data = new char[capacity];

    for(int i = 0; i < length; i++)
    {
        data[i] = temp[i];
    }
    data[length - 1] = character;
    data[capacity - 1] = '\0';
    delete [] temp;

    return *this;
}

bool DSString::operator==(const char *word){ //equality operator overload to compare a DSString to a char*
    if(strcmp(data, word) == 0)
    {
        return true;
    } else{
        return false;
    }
}

bool DSString::operator==(const DSString &compare) { //equality operator overload to comapre a DSString to another DSString
    if(strcmp(data, compare.data) == 0)
    {
        return true;
    } else{
        return false;
    }
}

bool DSString::operator>(const DSString &compare) { //> operator overload to compare a DSString to a DSString
    if(strcmp(data, compare.data) > 0)
    {
        return true;
    } else{
        return false;
    }
}

bool DSString::operator<(const DSString &compare) const{ //< operator overload to compare a DSString to a DSString
    if(strcmp(data, compare.data) < 0)
    {
        return true;
    } else{
        return false;
    }
}

char& DSString::operator[](const int x) const { //[] operator overload to access a single char in a DSString
    return data[x];
}

ostream& operator<<(ostream& os, const DSString& word) //outstream operator for DSString objects
{
    int outputLength = strlen(word.data);
    for(int i = 0; i < outputLength; i++)
    {
        os << word.data[i];
    }
    return os;
}

void DSString::print() //print function to display the data held in DSString
{
    int printLength = strlen(data);
    for(int i = 0; i < printLength; i++)
    {
        cout << data[i];
    }
    cout << endl;
}

int DSString::getCapacity() //returns capacity
{
    return capacity;
}

int DSString::getLength() const //returns length
{
    return length;
}

char* DSString::getString() //returns the data string
{
    return data;
}

DSString DSString::substr(int pos, int npos) const //returns a DSString of the indexes passed to it
{
    DSString toReturn;
    char *temp = new char[npos - pos + 1];
    int j = 0;

    for(int i = pos; i < npos; i++)
    {
        temp[j] = this->data[i];
        j++;
    }

    temp[j] = '\0';
    toReturn = temp;
    delete [] temp;
    return toReturn;
}

char* DSString::c_str() //converts the DSString to a cstring
{
    return data;
}

int DSString::dsstoi()
{
    return stoi(data);
}

float DSString::dsstof()
{
    return stof(data);
}
