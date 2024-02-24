#include <iostream>

#include "backend/board/Board.h"

using namespace std;

int main() {
    Board *b = new Board();

    b->play();

    return 0;
}
