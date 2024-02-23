//
// Created by dog on 20/02/24.
//

#ifndef PRACTICE1_EDD_DECK_H
#define PRACTICE1_EDD_DECK_H
#include <string>
#include "Card.h"
using namespace std;

class Deck {
private:
    Card *cards;

public:
    Deck();
    Card* getDeck();
    void fillDeck();
    void mixDeck();
    void print();
};


#endif //PRACTICE1_EDD_DECK_H
