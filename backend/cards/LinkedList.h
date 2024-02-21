//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_LINKEDLIST_H
#define PRACTICE1_EDD_LINKEDLIST_H
#include "Node.h"

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();

    void addToFront(Card);
    void addToBack(Card);
    void removeFront();
    void removeBack();
    void print();

};


#endif //PRACTICE1_EDD_LINKEDLIST_H
