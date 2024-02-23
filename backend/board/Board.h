//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_BOARD_H
#define PRACTICE1_EDD_BOARD_H


#include <stack>
#include "../cards/Queue.h"
#include "../cards/LinkedList.h"
#include "../cards/Stack.h"

class Board {
private:
    Queue *queue1;
    Queue *queue2;
    LinkedList *col[7];
    Stack *stacks[4];

public:
    Board();
    void fillBoard();
    void printBoard();
};


#endif //PRACTICE1_EDD_BOARD_H
