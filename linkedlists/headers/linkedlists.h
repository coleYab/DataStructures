#ifndef __LINKED_LISTS__
#define __LINKED_LISTS__

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

template <typename T>
struct Node
{
    /* data */
    T value;
    Node *next;

    Node(T val, Node *n_next)
    {
        value = val;
        next = n_next;
    }
};



template <typename T>
class LinkedLists
{
protected:
    Node *head;
    int length;
public:
    LinkedLists<T> (vector<T> &initializer = vector<T> ())
    {
        if (initiaizer.size() == 0)
            head == nullptr, length = 0;
        for (T values: initializer)
        {
            this->push_back(values);
        }
    }
    

    void push_back(T value)
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node<T> (value);
        this->length += 1;    
    }


    ~LinkedLists();
};

#endif