//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_LINKEDLIST_H
#define PRACTICE1_EDD_LINKEDLIST_H
#include "Node.h"
#include "Queue.h"

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();

    void addToFront(Card);
    void moveNodes(Node*&, LinkedList*&);
    void moveCards(string, string,LinkedList* &);
    void moveCardFromDeck(Queue*&);
    static bool validateMove(Node*&, LinkedList*&);
    bool validateModeFromQueue(Card);
    void print();

};


#endif //PRACTICE1_EDD_LINKEDLIST_H
