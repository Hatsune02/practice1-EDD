//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_LINKEDLIST_H
#define PRACTICE1_EDD_LINKEDLIST_H
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();

    void addToFront(Card);
    Card removeFront();
    void moveNodes(Node*&, LinkedList*&);
    void moveCards(string, string,LinkedList* &);
    void moveCardFromDeck(Queue*&);
    static bool validateMove(Node*&, LinkedList*&);
    bool validateMoveFromQueue(Card);
    void print();
    void moveCardsToStack(Stack*&);
    Card firstCard();
};


#endif //PRACTICE1_EDD_LINKEDLIST_H
