//
// Created by dog on 23/02/24.
//

#ifndef PRACTICE1_EDD_STACK_H
#define PRACTICE1_EDD_STACK_H


#include "Node.h"
#include "Queue.h"

class Stack {
private:
    Node* top;
public:
    Stack();
    void push(Card);
    Card pop();
    void print();
    bool validatePush(Card);
    void pushFromQueue(Queue*&);
    bool verifyFullStack();
};


#endif //PRACTICE1_EDD_STACK_H
