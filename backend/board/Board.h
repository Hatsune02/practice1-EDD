//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_BOARD_H
#define PRACTICE1_EDD_BOARD_H


#include <stack>
#include "../cards/Queue.h"
#include "../cards/LinkedList.h"

class Board {
private:
    Queue queue1;
    Queue queue2;
    LinkedList col1;
    LinkedList col2;
    LinkedList col3;
    LinkedList col4;
    LinkedList col5;
    LinkedList col6;
    LinkedList col7;
    stack<Card> stack1;
    stack<Card> stack2;
    stack<Card> stack3;
    stack<Card> stack4;

public:
    Board();

};


#endif //PRACTICE1_EDD_BOARD_H
