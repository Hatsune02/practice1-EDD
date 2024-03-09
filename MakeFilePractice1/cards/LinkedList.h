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
    LinkedList(const LinkedList&);
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

    Node* getTail();
    Node* getHead();

    Node* getNodePosition(int);
    bool showCard(int,int);
};


#endif //PRACTICE1_EDD_LINKEDLIST_H
