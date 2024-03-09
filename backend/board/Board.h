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

    //Copia de seguridad
    LinkedList *backupCol[7];
    Stack *backupStacks[4];
    Queue *backupQueue1;
    Queue *backupQueue2;
    bool canUndo;

public:
    Board();
    void fillBoard();
    void printBoard();
    void play();
    void moveCardsFromList(string, int, int, string, string);
    void moveCardFromQueueToStack();
    void moveCardFromListToStack(int, string);
    static int validateNum(const string&);
    void undo();
    void makeBackup();
    void peekNext(string);
    void peekPrev(string);
};


#endif //PRACTICE1_EDD_BOARD_H
