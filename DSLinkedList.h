//
// Created by Sammy Timmins on 9/18/20.
//

#ifndef INC_20F_AUTO_IDX_LINKEDLIST_H
#define INC_20F_AUTO_IDX_LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *previous;

    Node()
    {
        next = nullptr;
        previous = nullptr;
    }

    Node(T data)
    {
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }
};

template <typename T>
class DSLinkedList
{
public:
    DSLinkedList();
    ~DSLinkedList();
    DSLinkedList(const DSLinkedList &copy);
    DSLinkedList& operator=(const DSLinkedList &copy);
    T& operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, DSLinkedList& list);
    void add(const T &toAdd);
    void remove(const T &toRemove);
    T & at(int index) const;
    int search(const T &toFind);
    void print();
    int getSize() const;

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int size;
};

template <typename T>
DSLinkedList<T>::DSLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
DSLinkedList<T>::~DSLinkedList()
{
    if(head != nullptr)
    {
        auto curr = this->head;
        auto currNext = curr->next;

        for(int i = 0; i < size; i++) //looping through the list and deallocating every node
        {
            delete curr;
            curr = currNext;
            if (curr != nullptr) {
                currNext = curr->next;
            }
        }
    }
}

template <typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList &copy)
{
    this->head == nullptr;
    this->tail == nullptr;
    this->size = copy.size;

    auto curr = copy.head;
    while(curr != nullptr) //looping through list and copying the nodes from the list to be copied
    {
        auto currNext = curr->next;
        add(curr->data);
        curr = currNext;
    }
}

template <typename T>
DSLinkedList<T> & DSLinkedList<T>::operator=(const DSLinkedList<T> &copy)
{
    if(*this != copy)
    {
        if(this->head != nullptr) //if the list is not empty it will deallocate what is currently held in the list
        {
            delete this;
        }

        this->head = nullptr;
        this->tail = nullptr;

        auto curr = copy.head;
        while(curr != nullptr) //copies over the nodes from the list to be copied
        {
            add(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

template <typename T>
T& DSLinkedList<T>::operator[](const int index) //accesses a node at a specified index
{
    if(index < size && index >= 0)
    {
        auto curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    } else //range checking
    {
        std::cout << "Out of range" << std::endl;
        exit(1);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, DSLinkedList<T>& list)
{
    auto curr = list.head;
    for(int i = 0; i < list.size; i++)
    {
        os << curr->data << std::endl;
        curr = curr->next;
    }

    return os;
}

template <typename T>
void DSLinkedList<T>::add(const T &toAdd) //adds a node to the end of the list
{
    if(head == nullptr)
    {
        head = new Node<T>(toAdd);
        tail = head;
        ++size;
    } else
    {
        tail->next = new Node<T>(toAdd);
        tail->next->previous = tail;
        tail = tail->next;
        ++size;
    }
}

template <typename T>
void DSLinkedList<T>::remove(const T &toRemove) //removes a node with the specified value
{
    if(head->data == toRemove)
    {
        auto curr = head;
        curr->next->previous == nullptr;
        head = curr->next;
        delete curr;
    } else if(tail->data == toRemove)
    {
        auto curr = tail;
        curr->previous->next = nullptr;
        tail = curr->previous;
        delete curr;
    } else
    {
        auto curr = head;
        while(curr != nullptr)
        {
            if(curr->data == toRemove)
            {
                curr->previous->next = curr->next;
                curr->next->previous = curr->previous;
                delete curr;
            }
            curr = curr->next;
        }
    }
    --size;
}

template <typename T>
T & DSLinkedList<T>::at(int index) const { //accesses a node and returns the value at a specified index
    if(index < size && index >= 0)
    {
        auto curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
   } else
    {
        std::cout << "Out of range" << std::endl;
        exit(1);
    }
}

template <typename T>
int DSLinkedList<T>::search(const T &toFind) //returns the index for a specified node
{
    auto curr = head;
    for(int i = 0; i < size; i++)
    {
        if(curr->data == toFind)
        {
            return i;
        } else
        {
            curr = curr->next;
        }
    }
    return -1;
}

template <typename T>
void DSLinkedList<T>::print()
{
    auto curr = head;
    for(int i = 0; i < size; i++)
    {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}

template <typename T>
int DSLinkedList<T>::getSize() const { //returns the size of the list
    return size;
}

#endif //INC_20F_AUTO_IDX_LINKEDLIST_H
