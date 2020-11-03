//
// Created by Sammy Timmins on 9/16/20.
//

#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

#include <iostream>

template <typename T>
class DSVector
{
public:
    DSVector();
    ~DSVector();
    DSVector(const DSVector& copy);
    DSVector&operator=(const DSVector &copy);
    void push_back(const T& toAdd);
    void pop_back();
    T & at(const int index) const;
    T& operator[](const int index);
    void remove(const int index);
    void reassign(const int index, const T& change);
    int search(const T& toFind);
    int getSize() const;
    void print();
    void clear();

private:
    T *data;
    int size;
};

template <typename T>
DSVector<T>::DSVector()
{
    data = nullptr;
    size = 0;
}

template <typename T>
DSVector<T>::~DSVector()
{
    delete [] data;
}

template <typename T>
DSVector<T>::DSVector(const DSVector &copy)
{
    size = copy.size;
    data = new T[size];

    for(int i = 0; i < size; i++) //loops through and copies the contents of the vector to be copied
    {
        data[i] = copy.data[i];
    }
}

template <typename T>
DSVector<T> & DSVector<T>::operator=(const DSVector<T> &copy)
{
    if(size != 0) //if the vector is not empty it will deallocate the memory storing the previous values
    {
        delete [] data;
    }

    size = copy.size;
    data = new T[size];

    for(int i = 0; i < size; i++) //loops through copy vector and copies over all values to the new one
    {
        data[i] = copy.data[i];
    }
    return *this;
}

template <typename T>
void DSVector<T>::push_back(const T &toAdd) //adds the value to the end of the array
{
    T *temp;
    temp = new T[size];

    for(int i = 0; i < size; i++) //copies values in current vector to a temp vector
    {
        temp[i] = data[i];
    }

    delete [] data; //deallocates the memory of the previous vector
    size += 1;
    data = new T[size];

    for(int i = 0; i < size - 1; i++) //copies the values back into the resized array
    {
        data[i] = temp[i];
    }
    data[size - 1] = toAdd; //adds the value to the end
    delete [] temp;
}

template <typename T>
void DSVector<T>::pop_back() //removes the value from the last index
{
    T *temp;
    temp = new T[size];
    for(int i = 0; i < size; i++) //copies the values from the vector to a temp vector
    {
        temp[i] = data[i];
    }

    delete [] data; //deallocates the memory for the vector
    size -= 1;
    data = new T[size];

    for(int i = 0; i < size; i++) //copies the values back into the vector from the temp vector
    {
        data[i] = temp[i];
    }
    delete [] temp;
}

template <typename T>
T & DSVector<T>::at(const int index) const { //accesses the data at the specified index
    if(index < size && index >= 0)
    {
        return data[index];
    } else
    {
        std::cout << "Index out of range for vector" << std::endl;
        exit(1);
    }
}

template <typename T>
T& DSVector<T>::operator[](const int index) //returns the value at the specified index
{
    if(index < size && index >= 0)
    {
        return data[index];
    } else //range checking
    {
        std::cout << "Index out of range for vector" << std::endl;
        exit(1);
    }
}

template <typename T>
void DSVector<T>::remove(const int index) //removes the specified index
{
    if(index < size && index >= 0)
    {
        T *temp;
        temp = new T[size];
        for(int i = 0; i < size; i++) //copies data from vector to temp vector
        {
            temp[i] = data[i];
        }

        delete [] data; //deallocates memory for vector
        size -= 1;
        data = new T[size];

        for(int i = 0; i < index; i++) //copies the data to the index to be removed
        {
            data[i] = temp[i];
        }
        for(int i = index + 1; i < size + 1; i++) //copies the data from after the index to be removed
        {
            data[i - 1] = temp[i];
        }
        delete [] temp;
    } else //range checking
    {
        std::cout << "Index out of range for vector" << std::endl;
        exit(1);
    }
}

template <typename T>
void DSVector<T>::reassign(const int index, const T &change) //changes the value at the specified index
{
    if(index < size && index >= 0)
    {
        data[index] = change;
    } else //range checking
    {
        std::cout << "Index out of range for vector" << std::endl;
        exit(1);
    }
}

template <typename T>
int DSVector<T>::search(const T &toFind) //returns the index for the specified value
{
    for(int i = 0; i < size; i++)
    {
        if(data[i] == toFind)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
int DSVector<T>::getSize() const { //returns the size of the vector
    return size;
}

template <typename T>
void DSVector<T>::print()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << data[i] << std::endl;
    }
}

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
