#include <iostream>
#include "backend/cards/Deck.h"
using namespace std;

int main() {
    Deck *d = new Deck();

    d->print();

    return 0;
}
