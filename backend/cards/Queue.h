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
    Card takeOutRear();
    Card getCard();
    void moveCards(Queue*&);
    void print(bool);
};


#endif //PRACTICE1_EDD_QUEUE_H
