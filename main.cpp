#include <iostream>

#include "backend/board/Board.h"

using namespace std;

int main() {
    Board *b = new Board();

    b->fillBoard();

    return 0;
}
