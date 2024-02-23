//
// Created by dog on 23/02/24.
//

#ifndef PRACTICE1_EDD_STACK_H
#define PRACTICE1_EDD_STACK_H


#include "Node.h"

class Stack {
private:
    Node* top;
public:
    Stack();
    void push(Card);
    void print();
    bool validatePush(Card);
};


#endif //PRACTICE1_EDD_STACK_H
