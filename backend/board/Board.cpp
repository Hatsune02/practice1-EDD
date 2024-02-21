//
// Created by dog on 20/02/24.
//

#include "Board.h"
#include <stack>
#include "../cards/Queue.h"
#include "../cards/LinkedList.h"

Board::Board() {
    this->queue1 = new Queue();
}