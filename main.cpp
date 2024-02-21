#include <iostream>
#include "backend/cards/Deck.h"
#include "backend/cards/Queue.h"
using namespace std;

int main() {
    Deck *d = new Deck();

    d->print();

    return 0;
}
