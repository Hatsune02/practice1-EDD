//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_QUEUE_H
#define PRACTICE1_EDD_QUEUE_H
#include "Node.h"

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue();
    void getInto(Card);
    Card takeOut();
    bool isEmpty() const;
};


#endif //PRACTICE1_EDD_QUEUE_H
