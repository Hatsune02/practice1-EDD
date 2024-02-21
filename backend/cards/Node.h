//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_NODE_H
#define PRACTICE1_EDD_NODE_H
#include "Card.h"

class Node {

public:
    Card card = Card(nullptr, nullptr, 0, 0);
    Node *next;
    Node *prev;
};


#endif //PRACTICE1_EDD_NODE_H
